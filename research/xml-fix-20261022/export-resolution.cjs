// Research fixtures in the real HTTP renderer and a real packaged EXE.
// Saving is the production Save dialog button -> downloadCiff -> physical download.
// This is not an emulated serializer and does not touch the user's app/profile.
const { app, BrowserWindow } = require('electron');
const fs = require('node:fs');
const originalFs = require('original-fs');
const path = require('node:path');
const net = require('node:net');
const crypto = require('node:crypto');
const { spawn } = require('node:child_process');

const root = path.resolve(__dirname, '../..');
const arg = (name, fallback) => process.argv.find(value => value.startsWith('--' + name + '='))?.slice(name.length + 3) ?? fallback;
const output = path.resolve(arg('output', path.join(__dirname, 'exports-resolution-final')));
const exe = path.resolve(arg('exe', path.join(root, 'desktop-release-resolution-fix-20261022/win-unpacked/Glyph Studio.exe')));
const webUrl = arg('web-url', 'http://127.0.0.1:5173/');
const requestedMode = arg('mode', 'both');
const suite = arg('suite', 'all');
const dimensionCaseIds = ['normal', 'no-op-import', 'rotation', 'hidden-outlier', 'all-hidden', 'last-field-deleted', 'anisotropic-yres',
  'anisotropic-xres', 'lower-yres', 'lower-xres', 'fractional-rotation90', 'fractional-rotation270', 'profile6230'];
const partyCaseIds = ['party-gtin2', 'party-box-gtin'];
const resolutionCaseIds = ['normal', 'anisotropic-yres', 'anisotropic-xres', 'lower-yres', 'lower-xres',
  'fractional-rotation90', 'fractional-rotation270', 'profile6230', ...partyCaseIds];
const caseIds = suite === 'party' ? partyCaseIds : suite === 'all' ? [...dimensionCaseIds, ...partyCaseIds]
  : suite === 'resolution' ? resolutionCaseIds : dimensionCaseIds;
const pause = ms => new Promise(resolve => setTimeout(resolve, ms));
const hash = bytes => crypto.createHash('sha256').update(bytes).digest('hex');
const writeJson = (name, value) => fs.writeFileSync(path.join(output, name), JSON.stringify(value, null, 2));
fs.mkdirSync(output, { recursive: true });
app.setPath('userData', path.join(output, 'isolated-web-profile'));
app.disableHardwareAcceleration();
app.on('window-all-closed', () => {});
let webWindow, exeChild, cdp, browserCdp;

// Serialized into the real renderer, with its production globals.
async function rendererCase(mode, caseId, originalNormalXml) {
  const until = Date.now() + 30000;
  while (!globalThis.__GLYPH_CIFF_RUNTIME_READY__ || !textFontCatalog.ready || !stage) {
    if (Date.now() > until) throw new Error(mode + ': runtime not ready');
    await new Promise(resolve => setTimeout(resolve, 25));
  }
  if (mode === 'web') {
    if (typeof glyphLogger !== 'undefined' || !String(glyphFonts.render).includes('/__glyph_fonts/render')) throw new Error('Web is not the plain HTTP renderer');
  } else if (typeof glyphLogger === 'undefined' || location.protocol !== 'glyph:') throw new Error('Real EXE protocol/preload missing');
  const is6230 = caseId === 'profile6230';
  const profileName = is6230 ? 'DataFlex 6230(32mm)' : 'DataFlex 6320(53mm)';
  const base = is6230 ? buildEmptyTemplateXml(profileName, 'Continuous', 16, 24)
    : originalNormalXml || buildEmptyTemplateXml(profileName, 'Continuous', 16, 24);
  let source = caseId === 'no-op-import'
    ? base.replace(/<ImageWidth>[^<]*<\/ImageWidth>/, '<ImageWidth>777</ImageWidth>')
      .replace(/<ImageHeight>[^<]*<\/ImageHeight>/, '<ImageHeight>888</ImageHeight>')
    : base;
  const metadataCases = {
    'anisotropic-yres': [0.12, 0.24], 'anisotropic-xres': [0.24, 0.12],
    'lower-yres': [0.12, 0.06], 'lower-xres': [0.06, 0.12],
    'fractional-rotation90': [0.09, 0.135], 'fractional-rotation270': [0.135, 0.09]
  };
  const metadataResolution = metadataCases[caseId];
  if (metadataResolution) {
    source = source.replace(/<XRes>[^<]*<\/XRes>/, '<XRes>' + metadataResolution[0].toFixed(6) + '</XRes>');
    source = /<YRes>/.test(source)
      ? source.replace(/<YRes>[^<]*<\/YRes>/, '<YRes>' + metadataResolution[1].toFixed(6) + '</YRes>')
      : source.replace('</XRes>', '</XRes><YRes>' + metadataResolution[1].toFixed(6) + '</YRes>');
  }
  if (!loadXml(source, { source: 'xml-fix-' + mode, title: 'XML fixture ' + caseId, markDirty: false })) throw new Error('Fixture failed to load');
  const beforeAction = {
    subImage: JSON.parse(JSON.stringify(state.subImage)),
    fields: state.fields.map(field => ({ name: field.name, printed: field.printed, orientation: field.orientation, geom: { ...field.geom } }))
  };
  let builderDraft = null;
  if (caseId.startsWith('party-')) {
    builderDraft = createDefaultTemplatePresetDraft();
    builderDraft.creationKind = 'preset-builder';
    builderDraft.base = { printerModel: 'DataFlex 6320(53mm)', printMode: 'Continuous', widthMm: 16, heightMm: 24 };
    builderDraft.dataSourceMode = 'party-code';
    builderDraft.partyCode = { withBoxCounter: caseId === 'party-box-gtin', gtinFieldName: caseId === 'party-box-gtin' ? 'GTIN' : 'GTIN2' };
    builderDraft.dataMatrix = { symbolSize: '22X22', moduleSize: 0.5, snValue: '0000000000' };
    const generated = generateTemplatePreset(builderDraft);
    if (!generated.ok) throw new Error('Actual preset API rejected party fixture: ' + JSON.stringify(generated.issues));
    if (!commitGeneratedTemplatePreset(generated, { title: 'XML party fixture ' + caseId, reuseEmpty: true })) throw new Error('Actual preset commit failed');
    source = generated.xml;
    builderDraft = generated.draft;
  } else if (caseId === 'normal' || is6230) {
    const specs = [
      { name: 'Arial10', face: 'Arial', pitch: 10, value: 'ABC', x: 100, y: 100 },
      { name: 'Times13', face: 'Times New Roman', pitch: 13, value: '123', x: 150, y: 700 },
      { name: 'Courier8', face: 'Courier New', pitch: 8, value: 'SN01', x: 200, y: 1500, xMag: 125 }
    ];
    state.fields = specs.map(spec => {
      const field = createBaseField({ name: spec.name, fldType: 'FixedText', pitch: spec.pitch, value: spec.value,
        geom: { x: spec.x, y: spec.y, w: 600, h: 300 } });
      field.text.face = spec.face;
      field._nativeTextFontDirty = true;
      if (spec.xMag) field.text.xMag = spec.xMag;
      return field;
    });
    state.fields[0].geom.x += 25;
  } else if (caseId === 'rotation' || caseId.startsWith('fractional-rotation')) {
    state.fields[0].orientation = caseId.endsWith('270') ? 270 : 90;
    // Make the swapped rectangle determine both used-image far edges, while
    // remaining inside the deliberately smaller 16x24mm workspace.
    state.fields[0].geom.x = caseId === 'rotation' ? 1000 : 1001;
    state.fields[0].geom.y = caseId === 'rotation' ? 1250 : 1253;
  } else if (caseId === 'hidden-outlier') {
    const field = createBaseField({ name: 'GTIN2', fldType: 'FixedText', pitch: 10, value: '00000000000000',
      geom: { x: 9000, y: 10000, w: 1000, h: 300 } });
    field.printed = false;
    state.fields.push(field);
  } else if (caseId === 'all-hidden') {
    state.fields.forEach(field => { field.printed = false; });
  } else if (caseId === 'last-field-deleted') {
    state.fields = [];
  }
  state.fieldByName = new Map(state.fields.map(field => [field.name, field]));
  state.subImage.usedSizeDirty = caseId !== 'no-op-import';
  setSelectedNames([]);
  renderAll();
  const now = new Date();
  await ensureNativeTextGeometry(state.fields, now);
  await Promise.all(Array.from(nativeTextPreviewPending.values()));
  setZoom(100); renderAll();
  const snapshotField = field => {
    const value = makePreviewText(field, now);
    const entry = requestNativeTextPreview(field, value);
    const node = field._konva?.findOne('.PreviewValue');
    return {
      name: field.name, type: field.fldType, printed: field.printed, orientation: field.orientation || 0,
      geom: { ...field.geom }, previewText: value, calculatedData: field.calcData, text: { ...field.text },
      data: field.data ? JSON.parse(JSON.stringify(field.data)) : null,
      barcode: field.barcode ? JSON.parse(JSON.stringify(field.barcode)) : null,
      dataMatrixPreviewSegmentValues: field.barcode?.dataMatrix
        ? resolveCiffDataMatrixSegmentValues(field, now, { fieldByName: state.fieldByName }) : null,
      effectiveFont: { face: getEffectiveTextFontFamily(field), pitch: getEffectiveTextPitch(field),
        xMag: Number(field.text?.xMag) || 100, yMag: Number(field.text?.yMag) || 100,
        bold: Boolean(field.text?.bold), italic: Boolean(field.text?.italic) },
      nativeRequest: entry ? { ...entry.request } : null,
      nativeMetrics: entry ? { width: entry.width, height: entry.height, fontFamily: entry.fontFamily } : null,
      workerDataUrl: entry?.dataUrl || null, outlinePath: entry?.outlinePath || null,
      node: node ? { className: node.getClassName(), absoluteMatrix: node.getAbsoluteTransform().getMatrix(),
        selfRect: typeof node.getSelfRect === 'function' ? node.getSelfRect()
          : node.getClientRect({ skipTransform: true, skipShadow: true, skipStroke: true }),
        native: !!node._ciffPreviewTextStyle?.native, vector: !!node._ciffPreviewTextStyle?.vector,
        dataMatchesOutline: node.getClassName() === 'Path' && node.data() === entry?.outlinePath,
        cellWorldBounds: node.getClientRect({ skipShadow: true, skipStroke: true }),
        fieldGroup: { x: field._konva.x(), y: field._konva.y(), absoluteMatrix: field._konva.getAbsoluteTransform().getMatrix() },
        pixelsPerMm: getPixelsPerMm() } : null,
      nativeDotAnchor: entry ? { x: getNativeTextPositionDot(field.geom.x, entry.request.xRes), y: getNativeTextPositionDot(field.geom.y, entry.request.yRes) } : null
    };
  };
  const preSave = { subImage: JSON.parse(JSON.stringify(state.subImage)),
    canvas: { width: getCanvasInternalWidth(), height: getCanvasInternalHeight(), pixelsPerMm: getPixelsPerMm(), zoom: state.zoom },
    fields: state.fields.map(snapshotField) };
  const expectedCapabilityResolution = is6230 ? { xRes: 800, yRes: 800 } : { xRes: 1200, yRes: 1200 };
  if (!preSave.fields.filter(field => field.type !== 'Barcode').every(field => field.nativeRequest?.xRes === expectedCapabilityResolution.xRes && field.nativeRequest?.yRes === expectedCapabilityResolution.yRes)) {
    throw new Error('Actual font request did not use independently confirmed printer capabilities: ' + JSON.stringify(expectedCapabilityResolution));
  }
  const printable = preSave.fields.filter(field => field.printed);
  const aggregate = {
    width: Math.max(0, ...printable.map(field => field.geom.x + ([90, 270].includes(field.orientation) ? field.geom.h : field.geom.w))),
    height: Math.max(0, ...printable.map(field => field.geom.y + ([90, 270].includes(field.orientation) ? field.geom.w : field.geom.h)))
  };
  const filename = 'xml-' + mode + '-' + caseId;
  const saveStartedAt = new Date().toISOString();
  openSaveTemplateModal();
  elSaveTemplateName.value = filename;
  document.getElementById('btnConfirmSaveTemplate').click();
  const saveDeadline = Date.now() + 30000;
  do {
    if (Date.now() > saveDeadline) throw new Error('Save timed out: ' + JSON.stringify(state.validation));
    await new Promise(resolve => setTimeout(resolve, 25));
  } while (saveTemplateFromDialog.pending);
  if (!elSaveTemplateModal.classList.contains('hidden')) throw new Error('Save was blocked: ' + JSON.stringify(state.validation));
  renderAll();
  const expectedImage = caseId === 'no-op-import' ? { width: 777, height: 888 } : aggregate;
  if (state.subImage.width !== expectedImage.width || state.subImage.height !== expectedImage.height) {
    throw new Error('Wrong saved Image*: ' + JSON.stringify({ caseId, expectedImage, actual: state.subImage }));
  }
  if (state.subImage.maxWidth !== 1600 || state.subImage.maxHeight !== 2400) throw new Error('Workspace Max* changed unexpectedly');
  const savedXml = state.line1 + '\r\n' + state.line2;
  const savedXRes = Number(savedXml.match(/<XRes>([^<]*)<\/XRes>/)?.[1]);
  const savedYRes = Number(savedXml.match(/<YRes>([^<]*)<\/YRes>/)?.[1] ?? savedXRes);
  if (metadataResolution && (savedXRes !== metadataResolution[0] || savedYRes !== metadataResolution[1])) throw new Error('Source XRes/YRes metadata was not preserved in actual save');
  return {
    mode, caseId, filename: filename + '.ciff', actualLocation: location.href,
    transport: mode === 'web' ? 'HTTP Vite without preload/IPC' : 'Packaged glyph:// main/preload/IPC',
    fixtureConstruction: 'Research fixture prepared inside actual renderer; production Save dialog button clicked',
    sourceXml: source, builderDraft, beforeAction, preSave, aggregate, expectedImage, expectedMax: { width: 1600, height: 2400 },
    postSave: { subImage: JSON.parse(JSON.stringify(state.subImage)), fields: state.fields.map(snapshotField), validation: state.validation },
    expectedResolution: { xRes: savedXRes, yRes: savedYRes }, expectedCapabilityResolution,
    xmlAfterSave: savedXml,
    saveStartedAt, saveEndedAt: new Date().toISOString()
  };
}

const expression = (mode, caseId, normal) => '(' + rendererCase.toString() + ')(' +
  [mode, caseId, normal].map(value => JSON.stringify(value)).join(',') + ')';

// Separate custom-capability renderer proof. Unknown-profile fallback supplies
// controlled axes; this does not pretend that a registered printer is anisotropic.
async function rendererCustomCases(mode, referenceCases) {
  const captures = [];
  for (const reference of referenceCases) {
    if (!loadXml(buildEmptyTemplateXml('DataFlex 6320(53mm)', 'Continuous', 16, 24),
      { source: 'resolution-custom-research', title: 'Controlled capability renderer proof', markDirty: false })) throw new Error('Custom fixture load failed');
    state.docMeta.printerModel = 'Controlled unknown-printer research fallback';
    state.subImage.xRes = reference.capsX; state.subImage.yRes = reference.capsY;
    const field = createBaseField({ name: 'PositionText', fldType: 'FixedText', pitch: 10, value: 'TEXT',
      geom: { x: reference.x, y: reference.y, w: reference.modelW, h: reference.modelH } });
    field.orientation = reference.orientation; field.text.face = 'Arial'; field._nativeTextFontDirty = true;
    state.fields = [field]; state.fieldByName = new Map([[field.name, field]]); setSelectedNames([]);
    const now = new Date();
    await ensureNativeTextGeometry(state.fields, now);
    renderAll(); await Promise.all(Array.from(nativeTextPreviewPending.values())); setZoom(100); renderAll();
    const entry = requestNativeTextPreview(field, makePreviewText(field, now));
    const node = field._konva?.findOne('.PreviewValue');
    if (!entry || node?.getClassName() !== 'Path') throw new Error('Missing actual custom native Path');
    const requestResolution = { xRes: Math.round(reference.capsX * 10000), yRes: Math.round(reference.capsY * 10000) };
    if (entry.request.xRes !== requestResolution.xRes || entry.request.yRes !== requestResolution.yRes) throw new Error('Custom axes did not reach the real renderer');
    captures.push({ mode, scope: 'Actual renderer unknown-profile fallback with controlled capability axes; not a registered-printer save',
      reference, actualLocation: location.href, resolutionSelection: getNativeTextRenderResolution(),
      name: field.name, type: field.fldType, geom: { ...field.geom }, orientation: field.orientation, text: { ...field.text },
      nativeRequest: { ...entry.request }, nativeMetrics: { width: entry.width, height: entry.height },
      workerDataUrl: entry.dataUrl, outlinePath: entry.outlinePath,
      node: { className: node.getClassName(), native: !!node._ciffPreviewTextStyle?.native, vector: !!node._ciffPreviewTextStyle?.vector,
        dataMatchesOutline: node.data() === entry.outlinePath, selfRect: node.getSelfRect(),
        absoluteMatrix: node.getAbsoluteTransform().getMatrix(), cellWorldBounds: node.getClientRect({ skipShadow: true, skipStroke: true }),
        fieldGroup: { x: field._konva.x(), y: field._konva.y(), absoluteMatrix: field._konva.getAbsoluteTransform().getMatrix() }, pixelsPerMm: getPixelsPerMm() },
      nativeDotAnchor: { x: getNativeTextPositionDot(field.geom.x, entry.request.xRes), y: getNativeTextPositionDot(field.geom.y, entry.request.yRes) } });
  }
  return captures;
}

function saveWorkerCapture(field, prefix) {
  if (!field.workerDataUrl) return;
  const bitmap = prefix + '-worker.png';
  fs.writeFileSync(path.join(output, bitmap), Buffer.from(field.workerDataUrl.split(',')[1], 'base64'));
  delete field.workerDataUrl; field.workerBitmap = bitmap;
}

async function captureCustom(mode, evaluate) {
  const nativeReferences = path.join(root, 'research/resolution-preview-20261022/native-field-resolutions/position-results.json');
  const references = JSON.parse(fs.readFileSync(nativeReferences, 'utf8').replace(/^\uFEFF/, ''));
  if (references.length !== 48 || references.some(row => row.status !== 'ok')) throw new Error('Independent original Draw reference corpus is incomplete');
  const captures = await evaluate('(' + rendererCustomCases.toString() + ')(' + JSON.stringify(mode) + ',' + JSON.stringify(references) + ')');
  for (const field of captures) saveWorkerCapture(field, mode + '-custom-' + field.reference.prefix);
  writeJson('custom-position-' + mode + '.json', { capturedAt: new Date().toISOString(), mode,
    nativeReferenceFile: nativeReferences, nativeReferenceSha256: hash(fs.readFileSync(nativeReferences)),
    scope: 'Controlled fallback renderer against independent original COM custom-capability Draw corpus. No physical CIFF save or GUI screenshot implied.', captures });
  const metricReferencesPath = path.join(path.dirname(nativeReferences), 'results.json');
  const metricReferences = JSON.parse(fs.readFileSync(metricReferencesPath, 'utf8').replace(/^\uFEFF/, ''));
  const metricCaptures = await evaluate('(async references => { const rows=[]; for (const reference of references) {' +
    'const request={text:"TEXT",face:reference.face,pitch:reference.pitch,pitchResolution:1,bold:false,italic:false,xMag:100,yMag:100,charSpace:0,xRes:Math.round(reference.capsX*10000),yRes:Math.round(reference.capsY*10000)};' +
    'const result=await glyphFonts.render(request); rows.push({reference,request,metrics:{width:result.width,height:result.height},workerDataUrl:result.dataUrl,outlinePath:result.outlinePath});}return rows;})(' + JSON.stringify(metricReferences) + ')');
  for (const field of metricCaptures) saveWorkerCapture(field, mode + '-custom-metric-' + field.reference.case + '-' + field.reference.face.replaceAll(' ', '_'));
  writeJson('custom-metrics-' + mode + '.json', { mode, actualTransport: mode === 'web' ? 'HTTP glyphFonts.render service' : 'Actual packaged EXE glyphFonts.render IPC',
    scope: 'Direct worker API requests with controlled caps axes; independent original COM 24 PNG references. No registered anisotropic-printer binding claimed.',
    nativeReferenceFile: metricReferencesPath, nativeReferenceSha256: hash(fs.readFileSync(metricReferencesPath)), captures: metricCaptures });
}

async function connectCdp(url) {
  const socket = new WebSocket(url);
  const pending = new Map(), listeners = new Map(); let nextId = 0;
  await new Promise((resolve, reject) => {
    socket.addEventListener('open', resolve, { once: true });
    socket.addEventListener('error', reject, { once: true });
  });
  socket.addEventListener('message', event => {
    const message = JSON.parse(event.data);
    if (message.id) {
      const job = pending.get(message.id); if (!job) return;
      pending.delete(message.id);
      message.error ? job.reject(new Error(JSON.stringify(message.error))) : job.resolve(message.result);
    } else for (const listener of listeners.get(message.method) || []) listener(message.params);
  });
  socket.addEventListener('close', () => {
    for (const job of pending.values()) job.reject(new Error('Owned EXE CDP closed'));
    pending.clear();
  });
  return {
    send(method, params = {}) {
      return new Promise((resolve, reject) => {
        const id = ++nextId; pending.set(id, { resolve, reject });
        socket.send(JSON.stringify({ id, method, params }));
      });
    },
    on(method, listener) { if (!listeners.has(method)) listeners.set(method, []); listeners.get(method).push(listener); },
    close() { socket.close(); }
  };
}
async function freePort() {
  return new Promise((resolve, reject) => {
    const server = net.createServer(); server.once('error', reject);
    server.listen(0, '127.0.0.1', () => { const port = server.address().port; server.close(error => error ? reject(error) : resolve(port)); });
  });
}
async function waitPhysical(filename) {
  const end = Date.now() + 15000;
  while (Date.now() < end) {
    if (fs.existsSync(filename) && !fs.existsSync(filename + '.crdownload')) {
      const size = fs.statSync(filename).size;
      await pause(100);
      if (size > 0 && fs.statSync(filename).size === size) return;
    }
    await pause(50);
  }
  throw new Error('Physical download not completed: ' + filename);
}
async function runCases(mode, evaluate, capture, extra, getDownloads) {
  let normal;
  const rows = [];
  for (const caseId of caseIds) {
    const filename = path.join(output, 'xml-' + mode + '-' + caseId + '.ciff');
    if (fs.existsSync(filename)) throw new Error('Do not overwrite existing physical evidence: ' + filename);
    const result = await evaluate(expression(mode, caseId, caseId === 'normal' ? null : normal));
    await waitPhysical(filename);
    const bytes = fs.readFileSync(filename);
    if (bytes[0] !== 0xff || bytes[1] !== 0xfe) throw new Error('Physical save lacks UTF-16LE BOM');
    const xml = bytes.subarray(2).toString('utf16le');
    if (caseId === 'normal') normal = xml;
    const screenshot = mode + '-' + caseId + '-editor.png';
    fs.writeFileSync(path.join(output, screenshot), await capture());
    const evidence = { ...result, file: filename, bytes: bytes.length, sha256: hash(bytes), screenshot,
      completedDownloadEvents: getDownloads(), ...extra };
    for (const stage of ['preSave', 'postSave']) for (const field of evidence[stage].fields) {
      saveWorkerCapture(field, mode + '-' + caseId + '-' + stage + '-' + field.name);
    }
    writeJson(mode + '-' + caseId + '-expected.json', evidence);
    rows.push({ name: mode + '-' + caseId, mode, caseId, file: filename, expectedFile: path.join(output, mode + '-' + caseId + '-expected.json'),
      expectedValidation: '00000000', bytes: bytes.length, sha256: evidence.sha256 });
    writeJson('progress-' + mode + '.json', { cases: rows, next: caseIds[rows.length] || null });
  }
  return rows;
}
async function runWeb() {
  const downloads = [];
  webWindow = new BrowserWindow({ show: false, width: 1440, height: 1100,
    webPreferences: { sandbox: true, contextIsolation: true, nodeIntegration: false, offscreen: true } });
  webWindow.webContents.session.on('will-download', (_event, item) => {
    const filename = item.getFilename();
    if (!/^xml-web-[a-z0-9-]+\.ciff$/.test(filename)) throw new Error('Unexpected test download filename');
    item.setSavePath(path.join(output, filename));
    const row = { event: 'will-download', filename, at: new Date().toISOString() }; downloads.push(row);
    item.once('done', (_event, state) => downloads.push({ event: 'done', filename, state, at: new Date().toISOString() }));
  });
  await webWindow.loadURL(webUrl);
  const rows = await runCases('web', code => webWindow.webContents.executeJavaScript(code, true),
    async () => (await webWindow.webContents.capturePage()).toPNG(),
    { executable: process.execPath, preload: null, savePath: 'Save button -> will-download -> setSavePath -> completed' },
    () => [...downloads]);
  await captureCustom('web', code => webWindow.webContents.executeJavaScript(code, true));
  webWindow.destroy(); webWindow = null;
  return rows;
}
async function runExe() {
  if (!fs.existsSync(exe)) throw new Error('Fresh packaged EXE missing: ' + exe);
  const port = await freePort();
  const profile = path.join(output, 'isolated-exe-profile');
  fs.mkdirSync(profile, { recursive: true });
  const arguments = ['--remote-debugging-address=127.0.0.1', '--remote-debugging-port=' + port,
    '--user-data-dir=' + profile, '--disable-gpu', '--window-position=-32000,-32000'];
  const startedAt = new Date().toISOString();
  const stderr = [];
  exeChild = spawn(exe, arguments, { cwd: path.dirname(exe), windowsHide: true, stdio: ['ignore', 'ignore', 'pipe'] });
  exeChild.stderr.on('data', chunk => stderr.push(chunk.toString().slice(-3000)));
  let target;
  const until = Date.now() + 30000;
  while (!target) {
    if (exeChild.exitCode != null) throw new Error('Fresh EXE exited: ' + stderr.join(''));
    if (Date.now() > until) throw new Error('Fresh EXE CDP unavailable: ' + stderr.join(''));
    try {
      const pages = await (await fetch('http://127.0.0.1:' + port + '/json/list', { signal: AbortSignal.timeout(1000) })).json();
      target = pages.find(page => page.type === 'page' && page.url.startsWith('glyph://app/'));
    } catch {}
    if (!target) await pause(100);
  }
  cdp = await connectCdp(target.webSocketDebuggerUrl);
  const version = await (await fetch('http://127.0.0.1:' + port + '/json/version')).json();
  browserCdp = version.webSocketDebuggerUrl ? await connectCdp(version.webSocketDebuggerUrl) : null;
  const evaluate = async expression => {
    const response = await cdp.send('Runtime.evaluate', { expression, awaitPromise: true, returnByValue: true, userGesture: true });
    if (response.exceptionDetails) throw new Error(response.exceptionDetails.exception?.description || JSON.stringify(response.exceptionDetails));
    return response.result.value;
  };
  const readyDeadline = Date.now() + 30000;
  while (true) {
    try { if (await evaluate("document.readyState === 'complete' && globalThis.__GLYPH_CIFF_RUNTIME_READY__ === true && typeof glyphLogger !== 'undefined'")) break; }
    catch (error) { if (!/context.*destroyed|Cannot find context/i.test(error.message)) throw error; }
    if (Date.now() > readyDeadline) throw new Error('EXE initial navigation not ready');
    await pause(50);
  }
  const logInfo = await evaluate('glyphLogger.getInfo()');
  if (!path.resolve(logInfo.baseDir).toLowerCase().startsWith(path.resolve(profile).toLowerCase() + path.sep)) throw new Error('EXE did not honor isolated profile');
  const downloadClient = browserCdp || cdp;
  let downloadControl = 'Browser.setDownloadBehavior';
  try { await downloadClient.send(downloadControl, { behavior: 'allow', downloadPath: output, eventsEnabled: true }); }
  catch {
    downloadControl = 'Page.setDownloadBehavior';
    await cdp.send(downloadControl, { behavior: 'allow', downloadPath: output });
  }
  const downloads = [];
  for (const method of ['Browser.downloadWillBegin', 'Browser.downloadProgress']) downloadClient.on(method, event => downloads.push({ method, ...event, at: new Date().toISOString() }));
  for (const method of ['Page.downloadWillBegin', 'Page.downloadProgress']) cdp.on(method, event => downloads.push({ method, ...event, at: new Date().toISOString() }));
  const rows = await runCases('exe', evaluate, async () => {
    const result = await cdp.send('Page.captureScreenshot', { format: 'png', fromSurface: true });
    return Buffer.from(result.data, 'base64');
  }, {
    executable: exe, executableSha256: hash(fs.readFileSync(exe)),
    archiveSha256: hash(originalFs.readFileSync(path.join(path.dirname(exe), 'resources/app.asar'))),
    actualExeProcess: { pid: exeChild.pid, startedAt, arguments, userDataDir: profile, logBaseDir: logInfo.baseDir, debuggingPort: port },
    savePath: 'Actual packaged EXE Save button -> browser download', downloadControl
  }, () => [...downloads]);
  await captureCustom('exe', evaluate);
  // Browser.close can terminate Electron without replying to that CDP request.
  // The completed files/evidence must not be held behind research-only cleanup.
  try { await Promise.race([downloadClient.send('Browser.close'), pause(1500)]); }
  catch { try { await Promise.race([cdp.send('Page.close'), pause(500)]); } catch {} }
  cdp.close(); cdp = null; browserCdp?.close(); browserCdp = null;
  if (exeChild.exitCode == null) await Promise.race([new Promise(resolve => exeChild.once('exit', resolve)), pause(5000)]);
  if (exeChild.exitCode == null) exeChild.kill();
  exeChild = null;
  return rows;
}
let failed = false;
const timeout = setTimeout(() => fail(new Error('Real save matrix exceeded five minutes')), 300000);
function fail(error) {
  if (failed) return; failed = true;
  writeJson('export-failure.json', { at: new Date().toISOString(), error: error.stack || String(error) });
  console.error(error.stack || error);
  cdp?.close(); browserCdp?.close(); webWindow?.destroy();
  if (exeChild && exeChild.exitCode == null) exeChild.kill();
  clearTimeout(timeout); app.exit(1);
}
app.whenReady().then(async () => {
  const rows = [];
  if (requestedMode !== 'exe') rows.push(...await runWeb());
  if (requestedMode !== 'web') rows.push(...await runExe());
  writeJson('native-inputs-' + requestedMode + '.json', rows);
  writeJson('gui-queue-' + requestedMode + '.json', rows.map(row => ({ mode: row.mode, caseId: row.caseId, file: row.file,
    basename: path.basename(row.file), sha256: row.sha256, expectedFile: row.expectedFile })));
  writeJson('export-results-' + requestedMode + '.json', { completedAt: new Date().toISOString(), suite, webUrl, exe, cases: rows });
  console.log(JSON.stringify({ cases: rows.length, output, modes: [...new Set(rows.map(row => row.mode))] }));
  clearTimeout(timeout); app.exit(0);
}).catch(fail);
