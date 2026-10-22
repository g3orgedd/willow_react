const { contextBridge, ipcRenderer } = require("electron");

const ALLOWED_LOG_CATEGORIES = new Set(["application", "actions", "files", "state", "errors"]);
const ALLOWED_LOG_LEVELS = new Set(["TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL"]);

// ClariSoft reseeds MSVCRT rand from system uptime on every selection draw.
contextBridge.exposeInMainWorld("glyphSystemTickCount", () => {
  const tick = ipcRenderer.sendSync("glyph:get-system-tick-count");
  if (!Number.isFinite(tick)) throw new Error("System uptime is unavailable.");
  return tick >>> 0;
});

contextBridge.exposeInMainWorld("glyphFonts", Object.freeze({
  list() {
    return ipcRenderer.invoke("glyph:list-fonts");
  },
  render(request) {
    return ipcRenderer.invoke("glyph:render-font", request);
  }
}));

function normalizeLogPayload(payload = {}) {
  const category = ALLOWED_LOG_CATEGORIES.has(payload.category) ? payload.category : "application";
  const normalizedLevel = String(payload.level || "INFO").toUpperCase();
  return {
    category,
    level: ALLOWED_LOG_LEVELS.has(normalizedLevel) ? normalizedLevel : "INFO",
    event: String(payload.event || "UNSPECIFIED_RENDERER_EVENT").slice(0, 160),
    message: String(payload.message || "").slice(0, 2000),
    source: String(payload.source || "renderer").slice(0, 160),
    timestamp: payload.timestamp || new Date().toISOString(),
    details: payload.details ?? null
  };
}

contextBridge.exposeInMainWorld("glyphLogger", Object.freeze({
  log(payload) {
    ipcRenderer.send("glyph:log", normalizeLogPayload(payload));
  },
  getInfo() {
    return ipcRenderer.invoke("glyph:get-log-info");
  },
  flush() {
    return ipcRenderer.invoke("glyph:flush-logs");
  }
}));
