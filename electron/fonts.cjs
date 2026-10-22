const { execFile, spawn } = require("node:child_process");
const { createHash } = require("node:crypto");
const fs = require("node:fs");
const os = require("node:os");
const readline = require("node:readline");
const path = require("node:path");

// Use GDI rather than InstalledFontCollection: ClariSoft can also expose the
// Windows raster families, which GDI+ deliberately omits.
const ENUMERATE_WINDOWS_FONTS_SCRIPT = String.raw`
$ErrorActionPreference = 'Stop'
[Console]::OutputEncoding = New-Object System.Text.UTF8Encoding($false)
Add-Type -TypeDefinition @'
using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
public static class GlyphWindowsFonts {
    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Unicode)]
    public struct LOGFONT {
        public int height, width, escapement, orientation, weight;
        public byte italic, underline, strikeOut, charSet, outPrecision, clipPrecision, quality, pitchAndFamily;
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 32)] public string faceName;
    }
    private delegate int EnumFontProc(IntPtr logFont, IntPtr textMetric, uint fontType, IntPtr data);
    [DllImport("user32.dll")] private static extern IntPtr GetDC(IntPtr window);
    [DllImport("user32.dll")] private static extern int ReleaseDC(IntPtr window, IntPtr dc);
    [DllImport("gdi32.dll", CharSet = CharSet.Unicode)]
    private static extern int EnumFontFamiliesEx(IntPtr dc, ref LOGFONT font, EnumFontProc callback, IntPtr data, uint flags);
    public static string[] Enumerate() {
        var names = new SortedSet<string>(StringComparer.OrdinalIgnoreCase);
        IntPtr dc = GetDC(IntPtr.Zero);
        if (dc == IntPtr.Zero) throw new InvalidOperationException("Cannot obtain the Windows font device context.");
        try {
            var font = new LOGFONT { charSet = 1, faceName = "" };
            EnumFontProc callback = delegate(IntPtr logFont, IntPtr metric, uint kind, IntPtr data) {
                var entry = (LOGFONT)Marshal.PtrToStructure(logFont, typeof(LOGFONT));
                if (!String.IsNullOrWhiteSpace(entry.faceName) && !entry.faceName.StartsWith("@")) names.Add(entry.faceName);
                return 1;
            };
            EnumFontFamiliesEx(dc, ref font, callback, IntPtr.Zero, 0);
            GC.KeepAlive(callback);
            var result = new string[names.Count];
            names.CopyTo(result);
            return result;
        } finally { ReleaseDC(IntPtr.Zero, dc); }
    }
}
'@
ConvertTo-Json -InputObject @([GlyphWindowsFonts]::Enumerate()) -Compress
`;

function normalizeFontFamilies(values) {
  if (!Array.isArray(values)) throw new TypeError("The Windows font catalog must be an array.");
  const unique = new Map();
  for (const value of values) {
    if (typeof value !== "string") continue;
    const family = value.trim();
    if (!family || family.startsWith("@") || /[\x00-\x1f]/.test(family)) continue;
    const key = family.toLowerCase();
    if (!unique.has(key)) unique.set(key, family);
  }
  return Array.from(unique.values()).sort((a, b) => a.localeCompare(b, "en", { sensitivity: "base" }));
}

function createFontCatalogService(options = {}) {
  const platform = options.platform ?? process.platform;
  const runFile = options.execFile ?? execFile;
  const windowsDirectory = options.windowsDirectory ?? process.env.SystemRoot ?? "C:\\Windows";
  let pending = null;

  async function list() {
    if (platform !== "win32") return { families: [] };
    if (!pending) {
      const powershell = path.win32.join(windowsDirectory, "System32", "WindowsPowerShell", "v1.0", "powershell.exe");
      const encodedScript = Buffer.from(ENUMERATE_WINDOWS_FONTS_SCRIPT, "utf16le").toString("base64");
      pending = new Promise((resolve, reject) => {
        runFile(powershell, ["-NoLogo", "-NoProfile", "-NonInteractive", "-EncodedCommand", encodedScript], {
          windowsHide: true,
          encoding: "utf8",
          timeout: 20000,
          maxBuffer: 2 * 1024 * 1024,
        }, (error, stdout) => {
          if (error) return reject(error);
          try {
            const families = normalizeFontFamilies(JSON.parse(String(stdout).replace(/^\uFEFF/, "").trim()));
            if (!families.length) throw new Error("Windows returned an empty font catalog.");
            resolve(families);
          } catch (parseError) { reject(parseError); }
        });
      }).catch((error) => {
        pending = null;
        throw error;
      });
    }
    return { families: (await pending).slice() };
  }

  return Object.freeze({ list });
}

function normalizeRenderRequest(input) {
  if (!input || typeof input !== "object" || Array.isArray(input)) throw new TypeError("A text rendering request is required.");
  const text = String(input.text ?? "");
  const face = String(input.face ?? "Arial").trim();
  if (text.length > 4096 || /\0/.test(text)) throw new RangeError("Text must contain at most 4096 characters and no NUL characters.");
  if (!face || face.length > 128 || /[\x00-\x1f]/.test(face)) throw new RangeError("Invalid font family.");
  const integer = (key, fallback, min, max) => {
    const value = input[key] == null ? fallback : Number(input[key]);
    if (!Number.isInteger(value) || value < min || value > max) throw new RangeError(`Invalid ${key}.`);
    return value;
  };
  return {
    text, face,
    pitch: integer("pitch", 10, 1, 1000),
    pitchResolution: integer("pitchResolution", 1, 1, 1000),
    bold: input.bold === true,
    italic: input.italic === true,
    xMag: integer("xMag", 100, 1, 1000),
    yMag: integer("yMag", 100, 1, 1000),
    charSpace: integer("charSpace", 0, -10000, 10000),
    xRes: integer("xRes", 1200, 100, 10000),
    yRes: integer("yRes", input.xRes == null ? 1200 : Number(input.xRes), 100, 10000),
  };
}

function createFontRendererService(options = {}) {
  const platform = options.platform ?? process.platform;
  const startProcess = options.spawn ?? spawn;
  const windowsDirectory = options.windowsDirectory ?? process.env.SystemRoot ?? "C:\\Windows";
  const timeoutMs = options.timeoutMs ?? 20000;
  const sourcePath = options.scriptPath ?? path.join(__dirname, "font-renderer.ps1");
  const watchSource = options.watchSource === true;
  const cache = new Map();
  const pendingByKey = new Map();
  let worker = null;
  let ready = null;
  let startupRequest = null;
  let activeRequest = null;
  let nextId = 0;
  let queue = Promise.resolve();
  let scriptDirectory = null;
  let scriptVersion = null;
  let currentSource = null;
  let disposed = false;

  function readSource() {
    if (!currentSource || watchSource) {
      const contents = fs.readFileSync(sourcePath);
      const version = createHash("sha256").update(contents).digest("hex");
      if (currentSource?.version !== version) {
        cache.clear();
        currentSource = { version, contents };
      }
    }
    return currentSource;
  }

  function removeScriptDirectory() {
    if (!scriptDirectory) return;
    const directory = scriptDirectory; scriptDirectory = null;
    try { fs.unlinkSync(path.join(directory, "font-renderer.ps1")); fs.rmdirSync(directory); } catch { /* A terminating Windows child can retain its file briefly. */ }
  }

  function stop(error = new Error("The native font renderer stopped.")) {
    const previous = worker;
    worker = null;
    ready = null;
    if (startupRequest) {
      clearTimeout(startupRequest.timer);
      startupRequest.reject(error);
      startupRequest = null;
    }
    if (activeRequest) { activeRequest.reject(error); activeRequest = null; }
    if (previous) previous.kill();
  }

  function start(source) {
    if (disposed) throw new Error("The native font renderer has been disposed.");
    if (ready && scriptVersion === source.version) return ready;
    if (worker) stop(new Error("The native font renderer source was updated."));
    if (!scriptDirectory || scriptVersion !== source.version) {
      removeScriptDirectory();
      scriptDirectory = fs.mkdtempSync(path.join(os.tmpdir(), "glyph-font-renderer-"));
      // External processes cannot read directly from Electron's app.asar.
      fs.writeFileSync(path.join(scriptDirectory, "font-renderer.ps1"), source.contents);
      scriptVersion = source.version;
    }
    const powershell = path.win32.join(windowsDirectory, "System32", "WindowsPowerShell", "v1.0", "powershell.exe");
    const child = startProcess(powershell, ["-NoLogo", "-NoProfile", "-NonInteractive", "-ExecutionPolicy", "Bypass", "-File", path.join(scriptDirectory, "font-renderer.ps1")], {
      windowsHide: true,
      stdio: ["pipe", "pipe", "pipe"],
    });
    worker = child;
    let stderr = "";
    let startupResolve;
    let startupReject;
    const startup = new Promise((resolve, reject) => { startupResolve = resolve; startupReject = reject; });
    const startupTimer = setTimeout(() => {
      const error = new Error("The native font renderer did not start in time.");
      startupReject(error); stop(error);
    }, timeoutMs);
    startupRequest = { timer: startupTimer, reject: startupReject };
    const lines = readline.createInterface({ input: child.stdout, crlfDelay: Infinity });
    lines.on("line", (line) => {
      if (worker !== child) return;
      if (line.length > 24 * 1024 * 1024) { stop(new Error("The native font renderer response exceeded its limit.")); return; }
      let message;
      try { message = JSON.parse(line.replace(/^\uFEFF/, "")); }
      catch { stop(new Error("The native font renderer returned an invalid response.")); return; }
      if (message.ready === true) { clearTimeout(startupTimer); startupRequest = null; startupResolve(); return; }
      const request = activeRequest;
      if (!request || message.id !== request.id) return;
      activeRequest = null;
      if (message.error) request.reject(new Error(String(message.error)));
      else if (!message.result || typeof message.result.dataUrl !== "string" || !message.result.dataUrl.startsWith("data:image/png;base64,") || message.result.dataUrl.length > 24 * 1024 * 1024 || !Number.isInteger(message.result.width) || message.result.width < 1 || message.result.width > 16384 || !Number.isInteger(message.result.height) || message.result.height < 1 || message.result.height > 8192 || message.result.width * message.result.height > 16000000) request.reject(new Error("The native font renderer returned an invalid bitmap."));
      else if (message.result.outlinePath != null && (typeof message.result.outlinePath !== "string" || message.result.outlinePath.length > 8 * 1024 * 1024 || !/^[MLQCZ0-9. \-]*$/.test(message.result.outlinePath))) request.reject(new Error("The native font renderer returned an invalid text outline."));
      else request.resolve(message.result);
    });
    child.stderr.on("data", (chunk) => { stderr = (stderr + chunk.toString("utf8")).slice(-4000); });
    child.stdin.on("error", (error) => {
      clearTimeout(startupTimer); startupReject(error);
      if (worker === child) stop(error);
    });
    child.on("error", (error) => {
      clearTimeout(startupTimer); startupReject(error);
      if (worker === child) stop(error);
    });
    child.on("exit", (code) => {
      clearTimeout(startupTimer);
      const error = new Error(`The native font renderer exited (${code}). ${stderr}`.trim());
      startupReject(error);
      if (worker === child) stop(error);
    });
    ready = startup;
    return ready;
  }

  async function execute(payload, source) {
    await start(source);
    return new Promise((resolve, reject) => {
      const id = ++nextId;
      const timer = setTimeout(() => stop(new Error("The native font renderer timed out.")), timeoutMs);
      activeRequest = {
        id,
        resolve(value) { clearTimeout(timer); resolve(value); },
        reject(error) { clearTimeout(timer); reject(error); },
      };
      worker.stdin.write(`${JSON.stringify({ id, payload })}\n`, "utf8", (error) => {
        if (error) stop(error);
      });
    });
  }

  async function render(input) {
    if (disposed) throw new Error("The native font renderer has been disposed.");
    if (platform !== "win32") throw new Error("Native font rendering requires Windows.");
    const payload = normalizeRenderRequest(input);
    const source = readSource();
    // Development can replace the PowerShell source while this service lives.
    // Keep queued work serialized, but never return a cached or pending result
    // from an earlier worker version for a new render request.
    const key = source.version + ":" + JSON.stringify(payload);
    if (cache.has(key)) {
      const result = cache.get(key); cache.delete(key); cache.set(key, result);
      return { ...result };
    }
    if (pendingByKey.has(key)) return { ...await pendingByKey.get(key) };
    if (pendingByKey.size >= 128) throw new Error("The native font rendering queue is full.");
    const request = queue.then(() => execute(payload, source)).then((result) => {
      cache.set(key, result);
      while (cache.size > 96) cache.delete(cache.keys().next().value);
      return result;
    });
    pendingByKey.set(key, request);
    queue = request.catch(() => {});
    try { return { ...await request }; }
    finally { pendingByKey.delete(key); }
  }

  function dispose() {
    disposed = true;
    stop(); cache.clear();
    removeScriptDirectory();
  }

  return Object.freeze({ render, dispose });
}

module.exports = { createFontCatalogService, normalizeFontFamilies, normalizeRenderRequest, createFontRendererService };
