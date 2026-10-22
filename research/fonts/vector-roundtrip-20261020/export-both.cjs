// Actual website + actual packaged Glyph Studio.exe, both through the real
// Save dialog -> saveTemplateFromDialog -> downloadCiff -> browser download.
const { app, BrowserWindow } = require('electron');
const fs = require('node:fs');
const originalFs = require('original-fs');
const path = require('node:path');
const net = require('node:net');
const crypto = require('node:crypto');
const { spawn } = require('node:child_process');

const root = path.resolve(__dirname, '../../..');
const output = __dirname;
const exe = path.join(root, 'desktop-release-vector-fonts-20261020/win-unpacked/Glyph Studio.exe');
const webUrl = 'http://127.0.0.1:5173';
const profile = path.join(output, 'isolated-exe-profile');
app.setPath('userData', path.join(output, 'isolated-web-profile'));
app.disableHardwareAcceleration();
app.on('window-all-closed', () => {});
let webWindow;
let exeChild;
let cdp;
let browserCdp;
const writeJson = (name, value) => fs.writeFileSync(path.join(output, name), JSON.stringify(value, null, 2));
const sha256 = (value) => crypto.createHash('sha256').update(value).digest('hex');
const pause = (ms) => new Promise((resolve) => setTimeout(resolve, ms));
const scriptTimeout = setTimeout(() => { fail(new Error('Both real save paths timed out.')); }, 100000);

const cases = [
  { name: 'TNR_Text', type: 'FixedText', face: 'Times New Roman', pitch: 6, x: 123, y: 234, value: 'Abc 0123 АБВГ' },
  { name: 'Arial_Bold', type: 'FixedText', face: 'Arial', pitch: 13, x: 377, y: 900, value: 'Bold 012 АБВ', bold: true },
  { name: 'Courier_XMag', type: 'FixedText', face: 'Courier New', pitch: 9, x: 111, y: 1701, value: 'Wide 0123', xMag: 150 },
  { name: 'Tahoma_Date', type: 'DateText', face: 'Tahoma', pitch: 8, x: 197, y: 2403, value: 'dd/MM/yy' },
  { name: 'Segoe_Offset', type: 'OffsetDateText', face: 'Segoe UI', pitch: 7, x: 213, y: 3107, value: 'dd/MM/yy' },
  { name: 'Narrow_Time', type: 'TimeText', face: 'Arial Narrow', pitch: 10, x: 319, y: 3811, value: 'HH:mm' },
  { name: 'OCRB_Counter', type: 'CounterText', face: 'OCRB', pitch: 11, x: 421, y: 4517, value: '0001' },
  { name: 'TNR_Rot90', type: 'FixedText', face: 'Times New Roman', pitch: 6, x: 3801, y: 801, value: 'Rot 90', rotation: 90 },
  { name: 'Courier_Rot180', type: 'FixedText', face: 'Courier New', pitch: 8, x: 1801, y: 5203, value: 'Rot 180', rotation: 180 },
  { name: 'Tahoma_Rot270', type: 'FixedText', face: 'Tahoma', pitch: 6, x: 4003, y: 3001, value: 'Rot 270', rotation: 270 },
];

function describeGeometry(field, entry, node, now) {
  const raw = new Konva.Path({ data: entry.outlinePath, fill: '#000' });
  const ink = raw.getClientRect({ skipTransform: true, skipShadow: true, skipStroke: true }); raw.destroy();
  const absolute = node.getAbsoluteTransform();
  const corners = [[ink.x, ink.y], [ink.x + ink.width, ink.y], [ink.x, ink.y + ink.height], [ink.x + ink.width, ink.y + ink.height]].map(([x,y]) => absolute.point({ x,y }));
  const xs = corners.map(point => point.x), ys = corners.map(point => point.y);
  const transform = (target) => target ? { className: target.getClassName(), x: target.x(), y: target.y(),
    scaleX: target.scaleX(), scaleY: target.scaleY(), rotation: target.rotation(),
    absoluteMatrix: target.getAbsoluteTransform().getMatrix() } : null;
  return {
    nativeRequest: { ...entry.request },
    nativeMetrics: { width: entry.width, height: entry.height, advanceWidth: entry.advanceWidth, fontHeight: entry.fontHeight,
      baseline: entry.baseline, offsetX: entry.offsetX, offsetY: entry.offsetY, fontFamily: entry.fontFamily, trueType: entry.trueType },
    sourceText: { ...field.text },
    effectiveText: { family: entry.fontFamily, pitchResolution: entry.request.pitchResolution, xMag: entry.request.xMag,
      yMag: entry.request.yMag, charSpace: entry.request.charSpace, ttSize: field.text.ttSize ?? 1,
      txtDir: field.text.txtDir ?? 0, boldWeight: field.text.boldWeight ?? 1, gdiWeight: field.text.bold ? 900 : 400 },
    outlineInkBounds: { ...ink },
    nodeGeometry: { ...transform(node), selfRect: node.getSelfRect(), parent: transform(node.getParent()), fieldGroup: transform(field._konva),
      inkWorldBounds: { x: Math.min(...xs), y: Math.min(...ys), width: Math.max(...xs)-Math.min(...xs), height: Math.max(...ys)-Math.min(...ys) },
      cellWorldBounds: node.getClientRect({ skipShadow: true, skipStroke: true }), pixelsPerMm: getPixelsPerMm() },
    fieldPhysicalBounds: getFieldRenderedBoundsInternal(field, now, { forceFresh: true }),
    nativeDotAnchor: { x: getNativeTextPositionDot(field.geom.x, entry.request.xRes), y: getNativeTextPositionDot(field.geom.y, entry.request.yRes) },
  };
}

function exportPage(mode, existing = null) {
  return `(async () => {
    const mode = ${JSON.stringify(mode)};
    const cases = ${JSON.stringify(cases)};
    const existing = ${JSON.stringify(existing)};
    const describeGeometry = ${describeGeometry.toString()};
    const deadline = Date.now() + 25000;
    while (!globalThis.__GLYPH_CIFF_RUNTIME_READY__ || !textFontCatalog.ready || !stage) {
      if (Date.now() > deadline) throw new Error(mode + ': runtime did not initialize.');
      await new Promise(resolve => setTimeout(resolve, 25));
    }
    if (mode === 'web') {
      if (typeof glyphLogger !== 'undefined' || !String(glyphFonts.render).includes('/__glyph_fonts/render')) throw new Error('Web path is not isolated HTTP rendering.');
    } else if (typeof glyphLogger === 'undefined' || location.protocol !== 'glyph:') throw new Error('Actual EXE preload/protocol is missing.');
    if (!loadXml(existing ? existing.xml : buildEmptyTemplateXml('DataFlex 6320(53mm)', 'Continuous', 53, 70), { source: mode + '-vector-save-check', title: mode + '-vector', markDirty: false })) throw new Error('Template failed.');
    if (!existing) {
    state.fields = cases.map(test => {
      const field = createBaseField({ name: test.name, fldType: test.type, pitch: test.pitch, value: test.value,
        geom: { x: test.x, y: test.y, w: 1000, h: 300 } });
      if (test.type === 'OffsetDateText') ensureCalculatedDateOffset(field, { createNew: true });
      if (test.type === 'CounterText') normalizeCounterField(field);
      field.orientation = test.rotation || 0;
      if (test.xMag) field.text.xMag = test.xMag;
      return field;
    });
    state.fieldByName = new Map(state.fields.map(field => [field.name, field]));
    renderAll();
    for (const test of cases) {
      const field = state.fieldByName.get(test.name);
      selectField(field.name); renderSelectionPanels();
      const select = document.querySelector('[data-font-face-select]');
      if (!select) throw new Error('Font selector missing for ' + test.name);
      select.value = test.face; select.dispatchEvent(new Event('change', { bubbles: true }));
      if (test.bold) applyTextFontChange([field], { bold: true });
    }
    }
    const now = new Date();
    await ensureNativeTextGeometry(state.fields, now);
    renderAll();
    await Promise.all(Array.from(nativeTextPreviewPending.values())); renderAll();
    const beforeZoom = patchXmlLosslessV2({ now });
    const geometry = JSON.stringify(state.fields.map(field => ({ name: field.name, ...field.geom })));
    const zoomChecks = [];
    for (const zoom of [50, 100, 133, 400]) {
      setZoom(zoom); renderObjects();
      const classes = state.fields.map(field => field._konva?.findOne('.PreviewValue')?.getClassName());
      const sameGeometry = JSON.stringify(state.fields.map(field => ({ name: field.name, ...field.geom }))) === geometry;
      const sameCiff = patchXmlLosslessV2({ now }) === beforeZoom;
      if (!sameGeometry || !sameCiff || !classes.every(value => value === 'Path')) throw new Error('Zoom changed CIFF/geometry/vector state: ' + mode + ' ' + zoom);
      zoomChecks.push({ zoom, sameGeometry, sameCiff, classes });
    }
    setSelectedNames([]); setZoom(100); renderAll();
    const saveStartedAt = existing ? existing.savedAt : new Date().toISOString();
    if (!existing) {
      openSaveTemplateModal(); elSaveTemplateName.value = mode + '-vector';
      await saveTemplateFromDialog();
      if (!elSaveTemplateModal.classList.contains('hidden')) throw new Error('Save dialog remained open: ' + JSON.stringify(state.validation));
    }
    // The physical download is handled outside this renderer. Repaint the model
    // committed by the real save before collecting preview evidence.
    renderAll();
    await Promise.all(Array.from(nativeTextPreviewPending.values())); renderAll();
    const recorded = [];
    for (const field of state.fields) {
      const previewText = makePreviewText(field, now);
      const entry = requestNativeTextPreview(field, previewText);
      const node = field._konva?.findOne('.PreviewValue');
      if (!entry || typeof entry.outlinePath !== 'string' || node?.getClassName() !== 'Path') throw new Error('A saved field does not have its native vector: ' + field.name);
      const holder = document.createElement('div');
      const proof = new Konva.Stage({ container: holder, width: entry.width * 4, height: entry.height * 4 });
      const layer = new Konva.Layer(); proof.add(layer);
      layer.add(new Konva.Rect({ width: proof.width(), height: proof.height(), fill: '#fff' }));
      layer.add(node.clone({ x: 0, y: 0, scaleX: 4, scaleY: 4 })); layer.draw();
      const vectorDataUrl = proof.toDataURL({ pixelRatio: 1 }); proof.destroy();
      recorded.push({ name: field.name, type: field.fldType, face: getEffectiveTextFontFamily(field), pitch: getEffectiveTextPitch(field),
        xMag: field.text.xMag || 100, bold: !!field.text.bold, italic: !!field.text.italic,
        orientation: field.orientation, geom: { ...field.geom }, previewText,
        text: { ...field.text }, bitmap: mode + '-printer-' + field.name + '.png', bitmapWidth: entry.width, bitmapHeight: entry.height,
        dataUrl: entry.dataUrl, outlinePath: entry.outlinePath, vector: mode + '-vector-' + field.name + '-4x.png', vectorDataUrl,
        nodeClass: node.getClassName(), nodeNative: !!node._ciffPreviewTextStyle?.native, nodeVector: !!node._ciffPreviewTextStyle?.vector,
        nodeDataMatchesOutline: node.data() === entry.outlinePath,
        ...describeGeometry(field, entry, node, now) });
    }
    // Clone the actual positioned/rotated field groups into a 12-dot/mm layout.
    const holder = document.createElement('div');
    const paperStage = new Konva.Stage({ container: holder, width: 636, height: 840 });
    const paper = new Konva.Layer(); paperStage.add(paper);
    paper.add(new Konva.Rect({ width: 636, height: 840, fill: '#fff' }));
    const objects = new Konva.Group({ scaleX: 12 / getPixelsPerMm(), scaleY: 12 / getPixelsPerMm() }); paper.add(objects);
    state.fields.forEach(field => objects.add(field._konva.clone({ draggable: false })));
    paper.draw();
    const layoutDataUrl = paperStage.toDataURL({ pixelRatio: 1 });
    const layout4xDataUrl = paperStage.toDataURL({ pixelRatio: 4 }); paperStage.destroy();
    setZoom(100); renderAll();
    return { mode, actualLocation: location.href, now: now.toISOString(), saveStartedAt, saveEndedAt: new Date().toISOString(),
      xRes: 0.12, widthMm: 53, heightMm: 70, zoomChecks, fields: recorded, layoutDataUrl, layout4xDataUrl,
      fontTransport: mode === 'web' ? 'Vite HTTP without preload/IPC' : 'Actual packaged EXE main/preload IPC',
      rendererClass: state.fields.map(field => field._konva.findOne('.PreviewValue').getClassName()),
      readOnlyCaptureOfExistingDownload: !!existing };
  })()`;
}

function saveEvidence(mode, result, extra = {}) {
  const image = (filename, dataUrl) => fs.writeFileSync(path.join(output, filename), Buffer.from(dataUrl.split(',')[1], 'base64'));
  for (const field of result.fields) {
    image(field.bitmap, field.dataUrl); delete field.dataUrl;
    image(field.vector, field.vectorDataUrl); delete field.vectorDataUrl;
  }
  image(mode + '-vector-layout.png', result.layoutDataUrl); delete result.layoutDataUrl;
  image(mode + '-vector-layout-4x.png', result.layout4xDataUrl); delete result.layout4xDataUrl;
  const filename = path.join(output, mode + '-vector.ciff');
  const bytes = fs.readFileSync(filename);
  if (bytes[0] !== 0xff || bytes[1] !== 0xfe) throw new Error(mode + ': downloaded file lacks UTF-16LE BOM.');
  const decoded = bytes.subarray(2).toString('utf16le');
  if (!decoded.startsWith('<?xml') || !decoded.includes('\r\n') || !decoded.includes('<ImageDesign')) throw new Error(mode + ': actual download is not CIFF.');
  const expected = { ...result, filename, bytes: bytes.length, sha256: sha256(bytes), encoding: 'UTF-16LE with BOM', ...extra };
  writeJson('expected-' + mode + '.json', expected);
  return { mode, filename, fields: result.fields.length, bytes: bytes.length, sha256: expected.sha256 };
}

async function exportWeb() {
  webWindow = new BrowserWindow({ show: false, width: 1440, height: 1100,
    webPreferences: { sandbox: true, contextIsolation: true, nodeIntegration: false, offscreen: true } });
  const filename = path.join(output, 'web-vector.ciff');
  const download = new Promise((resolve, reject) => {
    webWindow.webContents.session.once('will-download', (_event, item) => {
      item.setSavePath(filename);
      item.once('done', (_event, status) => status === 'completed' ? resolve() : reject(new Error('Web download: ' + status)));
    });
  });
  await webWindow.loadURL(webUrl);
  const result = await webWindow.webContents.executeJavaScript(exportPage('web'));
  await download;
  fs.writeFileSync(path.join(output, 'web-vector-editor.png'), (await webWindow.webContents.capturePage()).toPNG());
  const summary = saveEvidence('web', result, { executable: process.execPath, preload: null, savePath: 'will-download -> setSavePath -> completed' });
  webWindow.destroy(); webWindow = null;
  return summary;
}

async function supplementExistingWeb() {
  const expectedFile = path.join(output, 'expected-web.json');
  const expected = JSON.parse(fs.readFileSync(expectedFile, 'utf8'));
  const bytes = fs.readFileSync(path.join(output, 'web-vector.ciff'));
  const originalHash = sha256(bytes);
  webWindow = new BrowserWindow({ show: false, width: 1440, height: 1100,
    webPreferences: { sandbox: true, contextIsolation: true, nodeIntegration: false, offscreen: true } });
  await webWindow.loadURL(webUrl);
  const supplemental = await webWindow.webContents.executeJavaScript(`(async () => {
    const expected = ${JSON.stringify(expected)};
    const describeGeometry = ${describeGeometry.toString()};
    const deadline = Date.now()+25000;
    while (!globalThis.__GLYPH_CIFF_RUNTIME_READY__ || !textFontCatalog.ready || !stage) {
      if(Date.now()>deadline)throw new Error('Supplemental web runtime did not initialize.');
      await new Promise(resolve=>setTimeout(resolve,25));
    }
    loadXml(${JSON.stringify(bytes.subarray(2).toString('utf16le'))}, {source:'saved-web-evidence-readonly',markDirty:false});
    setZoom(100); renderAll();
    for (const saved of expected.fields) requestNativeTextPreview(state.fieldByName.get(saved.name), saved.previewText);
    await Promise.all(Array.from(nativeTextPreviewPending.values())); renderAll();
    return expected.fields.map(saved => {
      const field=state.fieldByName.get(saved.name);
      const entry=requestNativeTextPreview(field,saved.previewText);
      // The recorded saved payload is explicit; no clock/property in the saved
      // CIFF is modified when collecting these additional display measurements.
      const node=makeNativeTextPreviewNode(field,saved.previewText);
      const parent=field._konva.findOne('.PreviewContent');
      parent.add(node);
      const result=describeGeometry(field,entry,node,new Date(expected.now));
      node.destroy();
      return {name:saved.name,...result};
    });
  })()`);
  for (const item of supplemental) Object.assign(expected.fields.find(field => field.name === item.name), item);
  expected.additionalGeometryCapturedAt = new Date().toISOString();
  expected.additionalGeometrySource = 'Same physical saved file, actual web Path API with its recorded saved payload; no resave.';
  writeJson('expected-web.json', expected);
  webWindow.destroy(); webWindow = null;
  if (sha256(fs.readFileSync(path.join(output, 'web-vector.ciff'))) !== originalHash) throw new Error('Read-only supplementary geometry changed the web CIFF.');
  return { mode:'web', filename:path.join(output,'web-vector.ciff'),fields:expected.fields.length,bytes:bytes.length,sha256:originalHash };
}

async function freePort() {
  return new Promise((resolve, reject) => {
    const server = net.createServer(); server.once('error', reject);
    server.listen(0, '127.0.0.1', () => { const port = server.address().port; server.close(error => error ? reject(error) : resolve(port)); });
  });
}

async function connectCdp(url) {
  const socket = new WebSocket(url);
  const pending = new Map(); const listeners = new Map(); let id = 0;
  await new Promise((resolve, reject) => { socket.addEventListener('open', resolve, { once: true }); socket.addEventListener('error', reject, { once: true }); });
  socket.addEventListener('message', (event) => {
    const message = JSON.parse(event.data);
    if (message.id) {
      const request = pending.get(message.id); if (!request) return; pending.delete(message.id);
      message.error ? request.reject(new Error(JSON.stringify(message.error))) : request.resolve(message.result);
    } else for (const listener of listeners.get(message.method) || []) listener(message.params);
  });
  socket.addEventListener('close', () => { for (const request of pending.values()) request.reject(new Error('EXE CDP connection closed.')); pending.clear(); });
  return {
    send(method, params = {}) { return new Promise((resolve, reject) => {
      if (socket.readyState !== WebSocket.OPEN) return reject(new Error('EXE CDP connection is already closed.'));
      const requestId = ++id; pending.set(requestId, { resolve, reject }); socket.send(JSON.stringify({ id: requestId, method, params }));
    }); },
    on(method, listener) { if (!listeners.has(method)) listeners.set(method, []); listeners.get(method).push(listener); },
    close() { socket.close(); },
  };
}

async function exportExe() {
  if (!fs.existsSync(exe)) throw new Error('The requested packaged EXE does not exist: ' + exe);
  const port = await freePort();
  fs.mkdirSync(profile, { recursive: true });
  const startedAt = new Date().toISOString();
  const captureExisting = process.argv.includes('--capture-existing-exe');
  const existingFile = path.join(output, 'exe-vector.ciff');
  const existingBytes = captureExisting ? fs.readFileSync(existingFile) : null;
  const existingHash = existingBytes ? sha256(existingBytes) : null;
  const arguments = ['--remote-debugging-address=127.0.0.1', '--remote-debugging-port=' + port,
    '--user-data-dir=' + profile, '--disable-gpu', '--window-position=-32000,-32000'];
  exeChild = spawn(exe, arguments, { cwd: path.dirname(exe), windowsHide: true, stdio: ['ignore', 'pipe', 'pipe'] });
  const childErrors = [];
  exeChild.stdout.on('data', (chunk) => childErrors.push(chunk.toString().slice(-4000)));
  exeChild.stderr.on('data', (chunk) => childErrors.push(chunk.toString().slice(-4000)));
  let spawnError;
  exeChild.on('error', (error) => { spawnError = error; });
  let target;
  const deadline = Date.now() + 25000;
  while (!target) {
    if (spawnError) throw spawnError;
    if (exeChild.exitCode != null) throw new Error('The isolated EXE exited before CDP: ' + childErrors.join(''));
    if (Date.now() > deadline) throw new Error('The isolated packaged EXE did not expose its CDP page: ' + childErrors.join(''));
    try { const pages = await (await fetch('http://127.0.0.1:' + port + '/json/list', { signal: AbortSignal.timeout(1000) })).json(); target = pages.find(page => page.type === 'page' && page.url.startsWith('glyph://app/')); }
    catch { /* The owned process is still starting its inspector. */ }
    if (!target) await pause(100);
  }
  cdp = await connectCdp(target.webSocketDebuggerUrl);
  try {
    const version = await (await fetch('http://127.0.0.1:' + port + '/json/version')).json();
    if (version.webSocketDebuggerUrl) browserCdp = await connectCdp(version.webSocketDebuggerUrl);
  } catch { /* Electron can expose only a page debugger. */ }
  const evaluate = async (expression) => {
    const response = await cdp.send('Runtime.evaluate', { expression, awaitPromise: true, returnByValue: true, userGesture: true });
    if (response.exceptionDetails) throw new Error(response.exceptionDetails.exception?.description || JSON.stringify(response.exceptionDetails));
    return response.result.value;
  };
  // A target appears before its first navigation has committed. Readiness is a
  // read-only retry; never retry the export/save expression itself.
  const runtimeDeadline = Date.now() + 25000;
  while (true) {
    if (Date.now() > runtimeDeadline) throw new Error('The actual EXE page did not finish its initial navigation.');
    try {
      if (await evaluate(`document.readyState === 'complete' && globalThis.__GLYPH_CIFF_RUNTIME_READY__ === true && typeof glyphLogger !== 'undefined'`)) break;
    } catch (error) {
      if (!/context.*destroyed|Cannot find context/i.test(error.message)) throw error;
    }
    await pause(50);
  }
  const info = await evaluate(`(async () => { const end=Date.now()+15000; while(!globalThis.glyphLogger) {if(Date.now()>end)throw new Error('No EXE preload.');await new Promise(r=>setTimeout(r,20));} return glyphLogger.getInfo(); })()`);
  if (!path.resolve(info.baseDir).toLowerCase().startsWith(path.resolve(profile).toLowerCase() + path.sep)) throw new Error('Packaged EXE did not honor the isolated user-data-dir: ' + info.baseDir);
  let downloadControl = 'Browser.setDownloadBehavior';
  try { await (browserCdp || cdp).send('Browser.setDownloadBehavior', { behavior: 'allow', downloadPath: output, eventsEnabled: true }); }
  catch (error) {
    if (!/wasn.t found|not found|method/i.test(error.message)) throw error;
    downloadControl = 'Page.setDownloadBehavior';
    await cdp.send('Page.setDownloadBehavior', { behavior: 'allow', downloadPath: output });
  }
  const downloads = [];
  const download = new Promise((resolve, reject) => {
    const client = browserCdp || cdp;
    const progress = (event) => {
      if (event.state === 'completed') resolve(event);
      else if (event.state === 'canceled') reject(new Error('The actual EXE download was canceled.'));
    };
    client.on('Browser.downloadWillBegin', (event) => downloads.push(event));
    client.on('Browser.downloadProgress', progress);
    cdp.on('Page.downloadWillBegin', (event) => downloads.push(event));
    cdp.on('Page.downloadProgress', progress);
  });
  const result = await evaluate(exportPage('exe', captureExisting ? {
    xml: existingBytes.subarray(2).toString('utf16le'), savedAt: fs.statSync(existingFile).mtime.toISOString(),
  } : null));
  if (!captureExisting) await Promise.race([download, (async () => {
    const pathToDownload = path.join(output, 'exe-vector.ciff');
    const end = Date.now()+10000;
    while(Date.now()<end) {
      if(fs.existsSync(pathToDownload) && !fs.existsSync(pathToDownload+'.crdownload')) {
        const size=fs.statSync(pathToDownload).size;
        await pause(100);
        if(size>0 && fs.statSync(pathToDownload).size===size) return;
      }
      await pause(50);
    }
    throw new Error('The actual EXE did not complete its physical CIFF download.');
  })()]);
  if (captureExisting && sha256(fs.readFileSync(existingFile)) !== existingHash) throw new Error('Read-only EXE evidence capture changed its downloaded file.');
  const screenshot = await cdp.send('Page.captureScreenshot', { format: 'png', fromSurface: true });
  fs.writeFileSync(path.join(output, 'exe-vector-editor.png'), Buffer.from(screenshot.data, 'base64'));
  const summary = saveEvidence('exe', result, { executable: exe, executableSha256: sha256(fs.readFileSync(exe)),
    applicationArchiveSha256: sha256(originalFs.readFileSync(path.join(path.dirname(exe), 'resources/app.asar'))),
    actualExeProcess: { pid: exeChild.pid, startedAt, arguments, userDataDir: profile, logBaseDir: info.baseDir, debuggingPort: port },
    savePath: 'Browser download triggered by actual EXE saveTemplateFromDialog/downloadCiff', downloadControl, downloads,
    ...(captureExisting ? { evidenceRecovery: 'The real EXE saved this physical CIFF before a research-only ASAR fingerprint error. The same file was reopened read-only in the same packaged EXE to capture preview/metric artifacts; no second save or CIFF edit.',
      originalSaveLog: path.join(profile, 'logs/2026-10-20/file-operations.txt') } : {}) });
  try { await (browserCdp || cdp).send('Browser.close'); }
  catch { try { await cdp.send('Page.close'); } catch { /* The owned window may already have closed its inspector. */ } }
  cdp.close(); cdp = null; browserCdp?.close(); browserCdp = null;
  const child = exeChild;
  if (child.exitCode == null) await Promise.race([new Promise(resolve => child.once('exit', resolve)), pause(5000)]);
  if (child.exitCode == null) child.kill();
  exeChild = null;
  return summary;
}

let failed = false;
function fail(error) {
  if (failed) return; failed = true;
  writeJson('export-failure.json', { error: error.stack || error.message, time: new Date().toISOString() });
  console.error(error.stack || error);
  cdp?.close(); browserCdp?.close(); webWindow?.destroy();
  if (exeChild && exeChild.exitCode == null) exeChild.kill();
  clearTimeout(scriptTimeout); app.exit(1);
}

app.whenReady().then(async () => {
  if (!process.argv.includes('--skip-web') && fs.existsSync(path.join(output, 'web-vector.ciff'))) throw new Error('The final web download already exists. Use --skip-web --capture-existing-exe for read-only evidence collection.');
  if (!process.argv.includes('--capture-existing-exe') && fs.existsSync(path.join(output, 'exe-vector.ciff'))) throw new Error('The final EXE download already exists. Use --capture-existing-exe to keep its bytes unchanged.');
  const web = process.argv.includes('--skip-web') ? await supplementExistingWeb() : await exportWeb();
  writeJson('export-progress.json', { web, exe: 'pending' });
  const exe = await exportExe();
  writeJson('export-results.json', { web, exe, completedAt: new Date().toISOString() });
  console.log(JSON.stringify({ web, exe }));
  clearTimeout(scriptTimeout); app.exit(0);
}).catch(fail);
