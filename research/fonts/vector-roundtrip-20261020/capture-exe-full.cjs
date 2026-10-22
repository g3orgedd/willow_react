// Read-only screenshot of the actual packaged EXE reopening exe-vector.ciff.
// node capture-exe-full.cjs
const fs = require('node:fs');
const path = require('node:path');
const net = require('node:net');
const crypto = require('node:crypto');
const { spawn } = require('node:child_process');
const directory = __dirname;
const root = path.resolve(directory, '../../..');
const exe = path.join(root, 'desktop-release-vector-fonts-20261020/win-unpacked/Glyph Studio.exe');
const profile = path.join(directory, 'isolated-screenshot-exe-profile');
const ciff = path.join(directory, 'exe-vector.ciff');
const hash = bytes => crypto.createHash('sha256').update(bytes).digest('hex');
const before = fs.readFileSync(ciff);
let child;
let client;
const pause = ms => new Promise(resolve => setTimeout(resolve, ms));

async function freePort() {
  return new Promise((resolve, reject) => { const server = net.createServer(); server.once('error', reject);
    server.listen(0, '127.0.0.1', () => { const port = server.address().port; server.close(error => error ? reject(error) : resolve(port)); }); });
}
async function connect(url) {
  const socket = new WebSocket(url); const waiting = new Map(); let next = 0;
  await new Promise((resolve, reject) => { socket.addEventListener('open', resolve, { once: true }); socket.addEventListener('error', reject, { once: true }); });
  socket.addEventListener('message', event => { const message = JSON.parse(event.data); const request = waiting.get(message.id); if (!request) return;
    waiting.delete(message.id); message.error ? request.reject(new Error(JSON.stringify(message.error))) : request.resolve(message.result); });
  socket.addEventListener('close', () => { for (const request of waiting.values()) request.reject(new Error('Owned EXE debugger closed.')); waiting.clear(); });
  return { close: () => socket.close(), send: (method, params = {}) => new Promise((resolve, reject) => {
    if (socket.readyState !== WebSocket.OPEN) return reject(new Error('Owned EXE debugger is closed.'));
    const id = ++next; waiting.set(id, { resolve, reject }); socket.send(JSON.stringify({ id, method, params }));
  }) };
}
async function cleanup() {
  if (client) { try { await client.send('Page.close'); } catch {} client.close(); }
  if (child && child.exitCode == null) await Promise.race([new Promise(resolve => child.once('exit', resolve)), pause(3000)]);
  if (child && child.exitCode == null) child.kill();
}

(async () => {
  const port = await freePort(); fs.mkdirSync(profile, { recursive: true });
  const startedAt = new Date().toISOString();
  child = spawn(exe, ['--remote-debugging-address=127.0.0.1', '--remote-debugging-port=' + port, '--user-data-dir=' + profile, '--disable-gpu'],
    { cwd: path.dirname(exe), windowsHide: true, stdio: 'ignore' });
  let target; const deadline = Date.now() + 25000;
  while (!target) {
    if (Date.now() > deadline || child.exitCode != null) throw new Error('The owned EXE did not start its debugger.');
    try { const targets = await (await fetch('http://127.0.0.1:' + port + '/json/list')).json(); target = targets.find(item => item.type === 'page' && item.url.startsWith('glyph://app/')); } catch {}
    if (!target) await pause(75);
  }
  client = await connect(target.webSocketDebuggerUrl);
  const evaluate = async expression => {
    const response = await client.send('Runtime.evaluate', { expression, awaitPromise: true, returnByValue: true, userGesture: true });
    if (response.exceptionDetails) throw new Error(response.exceptionDetails.exception?.description || JSON.stringify(response.exceptionDetails));
    return response.result.value;
  };
  while (true) {
    if (Date.now() > deadline) throw new Error('The owned EXE renderer did not initialize.');
    try { if (await evaluate(`globalThis.__GLYPH_CIFF_RUNTIME_READY__ === true && typeof glyphLogger !== 'undefined' && textFontCatalog.ready`)) break; } catch (error) { if (!/context.*destroyed|Cannot find context/i.test(error.message)) throw error; }
    await pause(50);
  }
  const logger = await evaluate('glyphLogger.getInfo()');
  if (!path.resolve(logger.baseDir).toLowerCase().startsWith(path.resolve(profile).toLowerCase() + path.sep)) throw new Error('EXE profile isolation failed.');
  await client.send('Emulation.setDeviceMetricsOverride', { width: 1440, height: 1100, deviceScaleFactor: 1, mobile: false, screenWidth: 1440, screenHeight: 1100 });
  const evidence = await evaluate(`(async()=>{
    if(!loadXml(${JSON.stringify(before.subarray(2).toString('utf16le'))},{source:'readonly-exe-screenshot',title:'exe-vector.ciff',markDirty:false}))throw new Error('Cannot reopen CIFF.');
    setZoom(100);setSelectedNames([]);renderAll();
    await Promise.all(Array.from(nativeTextPreviewPending.values()));renderAll();
    await new Promise(resolve=>setTimeout(resolve,150));
    return {url:location.href,width:innerWidth,height:innerHeight,zoom:zoomPct,capturedAt:new Date().toISOString(),
      fields:state.fields.map(field=>({name:field.name,type:field.fldType,face:getEffectiveTextFontFamily(field),geom:{...field.geom},
      preview:field._konva?.findOne('.PreviewValue')?.getClassName(),previewText:makePreviewText(field)}))};
  })()`);
  const screenshot = await client.send('Page.captureScreenshot', { format: 'png', fromSurface: true, captureBeyondViewport: true,
    clip: { x: 0, y: 0, width: 1440, height: 1100, scale: 1 } });
  const filename = path.join(directory, 'exe-vector-editor-full.png'); fs.writeFileSync(filename, Buffer.from(screenshot.data, 'base64'));
  const after = fs.readFileSync(ciff);
  if (!before.equals(after)) throw new Error('Read-only screenshot changed the saved CIFF.');
  fs.writeFileSync(path.join(directory, 'exe-vector-editor-full.json'), JSON.stringify({ ...evidence, filename, ciff, ciffSha256: hash(after),
    method: 'Page.captureScreenshot of the actual packaged EXE after read-only reopen; viewport 1440x1100 via CDP Emulation, no Save, no CIFF write.',
    ownedProcess: { executable: exe, pid: child.pid, startedAt, profile, logBaseDir: logger.baseDir, debuggingPort: port } }, null, 2));
  await cleanup(); console.log(JSON.stringify({ filename, width: evidence.width, height: evidence.height, fields: evidence.fields.length, ciffUnchanged: true }));
})().catch(async error => { console.error(error.stack || error); await cleanup(); process.exitCode = 1; });
