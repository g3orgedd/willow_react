// Run after npm run build:
// node_modules/electron/dist/electron.exe research/fonts/verify-editor.cjs
const { app, BrowserWindow, ipcMain, protocol, net } = require('electron');
const fs = require('node:fs');
const path = require('node:path');
const { pathToFileURL } = require('node:url');
const root = path.resolve(__dirname, '../..');
const asarArgument = process.argv.find(value => value.startsWith('--asar='));
const appBase = asarArgument ? path.resolve(asarArgument.slice('--asar='.length)) : root;
const { createFontCatalogService, createFontRendererService } = require(path.join(appBase, 'electron/fonts.cjs'));
const outputArgument = process.argv.find(value => value.startsWith('--output='));
const output = outputArgument ? path.resolve(outputArgument.slice('--output='.length)) : path.join(root, 'tests/output/font-preview');
fs.mkdirSync(output, { recursive: true });
app.setPath('userData', path.join(output, 'electron-profile'));
app.disableHardwareAcceleration();
protocol.registerSchemesAsPrivileged([{ scheme: 'glyph', privileges: { standard: true, secure: true, supportFetchAPI: true, corsEnabled: true } }]);
const renderer = createFontRendererService();
const errors = [];
const timeout = setTimeout(() => { console.error('Editor verification timed out.'); renderer.dispose(); app.exit(1); }, 45000);
app.whenReady().then(async () => {
  const catalog = createFontCatalogService();
  ipcMain.handle('glyph:list-fonts', () => catalog.list());
  ipcMain.handle('glyph:render-font', (_event, request) => renderer.render(request));
  ipcMain.handle('glyph:get-log-info', () => null);
  ipcMain.handle('glyph:flush-logs', () => null);
  ipcMain.on('glyph:log', (_event, payload) => {
    if (payload.level === 'ERROR' || payload.level === 'FATAL') errors.push(payload);
  });
  protocol.handle('glyph', request => {
    const relative = decodeURIComponent(new URL(request.url).pathname).replace(/^\/+/, '') || 'index.html';
    const target = path.resolve(appBase, 'dist', relative);
    if (!target.startsWith(path.join(appBase, 'dist') + path.sep)) throw new Error('Invalid fixture path.');
    return net.fetch(pathToFileURL(target).toString());
  });
  const window = new BrowserWindow({ show: false, width: 1440, height: 1000, webPreferences: {
    preload: path.join(appBase, 'electron/preload.cjs'), contextIsolation: true, sandbox: true, offscreen: true,
  } });
  await window.loadURL('glyph://app/index.html');
  const result = await window.webContents.executeJavaScript(`(async () => {
    const deadline = Date.now() + 20000;
    while (!globalThis.__GLYPH_CIFF_RUNTIME_READY__ || !textFontCatalog.ready || !stage) {
      if (Date.now() > deadline) throw new Error('Runtime did not initialize.');
      await new Promise(resolve => setTimeout(resolve, 30));
    }
    const check = (value, message) => { if (!value) throw new Error(message); };
    const previewClass = field => {
      const node = field?._konva?.findOne('.PreviewValue');
      check(!!node, 'Missing preview for ' + field?.name + ': ' + JSON.stringify({
        isCurrentField: state.fields.includes(field),
        parent: field?._konva?.getParent()?.getClassName(),
        currentNode: state.fields.find(item => item.name === field?.name)?._konva?.findOne('.PreviewValue')?.getClassName(),
      }));
      return node.getClassName();
    };
    const faces = getAvailableTextFontFamilies();
    check(faces.includes('Arial') && faces.includes('Times New Roman'), 'Windows fonts not loaded.');
    const xml = buildEmptyTemplateXml('DataFlex 6320(53mm)', 'Continuous', 53, 70);
    check(loadXml(xml, { source: 'font-verification', title: 'Fonts', markDirty: false }), 'Empty document failed.');
    const types = ['FixedText', 'DateText', 'OffsetDateText', 'TimeText', 'CounterText'];
    state.fields = types.map((fldType, index) => {
      const value = fldType === 'FixedText' ? 'Abc 012345 АБВГД' : fldType === 'TimeText' ? 'HH:mm' : fldType === 'CounterText' ? '0001' : 'dd/MM/yy';
      const field = createBaseField({ name: 'Font' + index, fldType, pitch: 6, value,
        geom: { x: 100, y: 100 + index * 800, w: 1000, h: 300 } });
      if (fldType === 'OffsetDateText') ensureCalculatedDateOffset(field, { createNew: true });
      if (fldType === 'CounterText') normalizeCounterField(field);
      return field;
    });
    state.fieldByName = new Map(state.fields.map(field => [field.name, field]));
    renderAll();
    const editTime = new Date('2026-10-20T12:34:00');
    await ensureNativeTextGeometry(state.fields, editTime);
    renderObjects();
    let first = state.fields[0];
    selectField(first.name);
    renderSelectionPanels();
    const family = document.querySelector('[data-font-face-select]');
    check(!!family, 'Font selector is missing.');
    family.value = 'Times New Roman';
    family.dispatchEvent(new Event('change', { bubbles: true }));
    await ensureNativeTextGeometry(state.fields, editTime);
    renderObjects();
    check(first.text.face === 'Times New Roman', 'UI selection did not reach the model.');
    check(first.text.family === 'Roman', 'The font family classification did not follow the selected typeface.');
    check(previewClass(first) === 'Path', 'Native vector outline is not used.');
    const saved = patchXmlLosslessV2({ now: editTime });
    check(saved.includes('<Face><![CDATA[Times New Roman]]></Face>'), 'Font was not serialized.');
    check(!saved.includes('fontFaceSelect'), 'UI state leaked into XML.');
    first = state.fields[0];
    renderObjects();
    const firstBefore = { ...first.geom };
    const fontBeforeZoom = getNativeTextCacheKey(first, makePreviewText(first, editTime));
    for (const zoom of [25, 100, 133, 200, 400]) {
      first = state.fields[0];
      setZoom(zoom);
      check(JSON.stringify(first.geom) === JSON.stringify(firstBefore), 'Zoom changed physical text geometry.');
      check(fontBeforeZoom === getNativeTextCacheKey(first, makePreviewText(first, editTime)), 'Zoom changed native font key.');
      check(previewClass(first) === 'Path', 'Zoom replaced the vector with a bitmap.');
      check(patchXmlLosslessV2({ now: editTime }) === saved, 'Zoom changed saved CIFF bytes.');
    }
    applyTextFontChange(state.fields, { face: 'Courier New', bold: true, italic: false });
    await ensureNativeTextGeometry(state.fields, editTime);
    check(state.fields.every(field => field.text.face === 'Courier New' && field.text.bold), 'Multi-selection font edit failed.');
    const after = patchXmlLosslessV2({ now: editTime });
    const reloaded = loadXml(after, { source: 'font-reopen', markDirty: false });
    check(reloaded && state.fields.every(field => field.text.face === 'Courier New'), 'Font did not survive reopen.');
    state.fields.forEach((field, index) => {
      field.text.face = ['Arial', 'Times New Roman', 'Courier New', 'Tahoma', 'Segoe UI'][index];
      field.text.bold = false;
      field._nativeTextGeometryDirty = true;
    });
    await ensureNativeTextGeometry(state.fields, editTime);
    setZoom(125);
    renderAll();
    selectField(state.fields[0].name);
    renderSelectionPanels();
    await new Promise(resolve => setTimeout(resolve, 150));
    check(state.fields.every(field => previewClass(field) === 'Path'), 'A text type still uses a bitmap.');
    return { installedFontCount: faces.length, fields: state.fields.map(field => ({
      type: field.fldType, face: field.text.face, geom: field.geom,
      nativePreview: previewClass(field),
    })), uiSelection: true, groupSelection: true, saveReopen: true, zoomGeometryStable: true };
  })()`);
  fs.writeFileSync(path.join(output, 'editor-results.json'), JSON.stringify({ ...result, errors }, null, 2));
  fs.writeFileSync(path.join(output, 'editor-preview.png'), (await window.webContents.capturePage()).toPNG());
  const visual = await window.webContents.executeJavaScript(`(async () => {
    const field = state.fields[0];
    const entry = requestNativeTextPreview(field, makePreviewText(field));
    if (typeof entry?.outlinePath !== 'string') throw new Error('No outline for visual verification.');
    const container = document.createElement('div');
    const proof = new Konva.Stage({ container, width: entry.width * 4, height: entry.height * 4 });
    const layer = new Konva.Layer({ imageSmoothingEnabled: false });
    proof.add(layer);
    const paper = () => new Konva.Rect({ width: entry.width * 4, height: entry.height * 4, fill: '#fff' });
    layer.add(paper());
    layer.add(new Konva.Path({ data: entry.outlinePath, fill: '#000', scaleX: 4, scaleY: 4 }));
    layer.draw();
    const vectorDataUrl = proof.toDataURL({ pixelRatio: 1, imageSmoothingEnabled: false });
    const pixels = layer.getCanvas().getContext().getImageData(0, 0, entry.width * 4, entry.height * 4).data;
    let edgePixels = 0;
    for (let i = 0; i < pixels.length; i += 4) if (pixels[i] > 0 && pixels[i] < 255) edgePixels++;
    if (!edgePixels) throw new Error('Vector curves have no antialiased edge pixels.');
    layer.destroyChildren();
    layer.add(paper());
    const bitmap = new Image(); bitmap.src = entry.dataUrl; await bitmap.decode();
    layer.add(new Konva.Image({ image: bitmap, width: entry.width * 4, height: entry.height * 4 }));
    layer.draw();
    const rasterDataUrl = proof.toDataURL({ pixelRatio: 1, imageSmoothingEnabled: false });
    proof.destroy();
    setZoom(400);
    await new Promise(resolve => setTimeout(resolve, 150));
    return { vectorDataUrl, rasterDataUrl, edgePixels };
  })()`);
  for (const [name, value] of [['vector-400.png', visual.vectorDataUrl], ['printer-raster-400.png', visual.rasterDataUrl]]) {
    fs.writeFileSync(path.join(output, name), Buffer.from(value.split(',')[1], 'base64'));
  }
  fs.writeFileSync(path.join(output, 'editor-preview-400.png'), (await window.webContents.capturePage()).toPNG());
  fs.writeFileSync(path.join(output, 'vector-visual-results.json'), JSON.stringify({ antialiasedEdgePixels: visual.edgePixels }, null, 2));
  if (errors.length) throw new Error('Renderer logged errors: ' + JSON.stringify(errors));
  console.log(JSON.stringify(result));
  renderer.dispose();
  clearTimeout(timeout);
  window.destroy();
  app.exit(0);
}).catch(error => {
  console.error(error.stack || error);
  renderer.dispose(); clearTimeout(timeout); app.exit(1);
});
