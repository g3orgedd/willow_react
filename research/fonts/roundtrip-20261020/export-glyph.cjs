// Export through the real editor's Save dialog and Electron download handler.
const { app, BrowserWindow, ipcMain, protocol, net } = require('electron');
const fs = require('node:fs');
const path = require('node:path');
const { pathToFileURL } = require('node:url');
const root = path.resolve(__dirname, '../../..');
const output = __dirname;
const printerRaster = process.argv.includes('--printer-raster');
const { createFontCatalogService, createFontRendererService } = require(path.join(root, 'electron/fonts.cjs'));
const filename = path.join(output, 'glyph-font-check.ciff');
app.setPath('userData', path.join(output, 'electron-profile'));
app.disableHardwareAcceleration();
protocol.registerSchemesAsPrivileged([{ scheme: 'glyph', privileges: { standard: true, secure: true, supportFetchAPI: true, corsEnabled: true } }]);
const renderer = createFontRendererService();
const errors = [];
const timeout = setTimeout(() => { renderer.dispose(); console.error('Glyph export timed out.'); app.exit(1); }, 45000);
app.whenReady().then(async () => {
  const catalog = createFontCatalogService();
  ipcMain.handle('glyph:list-fonts', () => catalog.list());
  ipcMain.handle('glyph:render-font', async (_event, request) => {
    const result = await renderer.render(request);
    return printerRaster ? { ...result, outlinePath: null } : result;
  });
  ipcMain.handle('glyph:get-log-info', () => null);
  ipcMain.handle('glyph:flush-logs', () => null);
  ipcMain.on('glyph:log', (_event, payload) => {
    if (payload.level === 'ERROR' || payload.level === 'FATAL') errors.push(payload);
  });
  protocol.handle('glyph', request => {
    const relative = decodeURIComponent(new URL(request.url).pathname).replace(/^\/+/, '') || 'index.html';
    const target = path.resolve(root, 'dist', relative);
    if (!target.startsWith(path.join(root, 'dist') + path.sep)) throw new Error('Invalid fixture path.');
    return net.fetch(pathToFileURL(target).toString());
  });
  const window = new BrowserWindow({ show: false, width: 1440, height: 1100, webPreferences: {
    preload: path.join(root, 'electron/preload.cjs'), contextIsolation: true, sandbox: true, offscreen: true,
  } });
  const downloaded = new Promise((resolve, reject) => {
    window.webContents.session.once('will-download', (_event, item) => {
      item.setSavePath(filename);
      item.once('done', (_event, status) => status === 'completed' ? resolve() : reject(new Error('Download ' + status)));
    });
  });
  await window.loadURL('glyph://app/index.html');
  const result = await window.webContents.executeJavaScript(`(async () => {
    const deadline = Date.now() + 20000;
    while (!globalThis.__GLYPH_CIFF_RUNTIME_READY__ || !textFontCatalog.ready || !stage) {
      if (Date.now() > deadline) throw new Error('Runtime did not initialize.');
      await new Promise(resolve => setTimeout(resolve, 25));
    }
    loadXml(buildEmptyTemplateXml('DataFlex 6320(53mm)', 'Continuous', 53, 70), { source: 'font-save-check', title: 'glyph-font-check', markDirty: false });
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
      select.value = test.face;
      select.dispatchEvent(new Event('change', { bubbles: true }));
      if (test.bold) applyTextFontChange([field], { bold: true });
    }
    const now = new Date();
    await ensureNativeTextGeometry(state.fields, now);
    renderAll();
    await Promise.all(Array.from(nativeTextPreviewPending.values()));
    renderAll();
    // Freeze preview values only while recording the exact saved payload; the
    // file retains normal dynamic date/time/counter types.
    const recorded = state.fields.map(field => {
      const previewText = makePreviewText(field, now);
      const entry = requestNativeTextPreview(field, previewText);
      if (!entry) throw new Error('Native bitmap is not ready for ' + field.name);
      return { name: field.name, type: field.fldType, face: getEffectiveTextFontFamily(field), pitch: getEffectiveTextPitch(field),
        xMag: field.text.xMag || 100, bold: !!field.text.bold, italic: !!field.text.italic,
        orientation: field.orientation, geom: { ...field.geom }, previewText, bitmap: 'glyph-' + field.name + '.png', dataUrl: entry.dataUrl,
        bitmapWidth: entry.width, bitmapHeight: entry.height,
        nodeClass: field._konva.findOne('.PreviewValue').getClassName(),
        nodeNative: !!field._konva.findOne('.PreviewValue')._ciffPreviewTextStyle?.native,
        nodeImageMatches: field._konva.findOne('.PreviewValue').image?.()?.src === entry.dataUrl };
    });
    // Render the actual preview nodes at printer resolution, including their
    // field/group positioning and rotations, without selection or rulers.
    const holder = document.createElement('div'); document.body.appendChild(holder);
    const paperStage = new Konva.Stage({ container: holder, width: 636, height: 840 });
    const paper = new Konva.Layer({ imageSmoothingEnabled: false }); paperStage.add(paper);
    paper.add(new Konva.Rect({ width: 636, height: 840, fill: '#fff', listening: false }));
    const objects = new Konva.Group({ scaleX: 12 / getPixelsPerMm(), scaleY: 12 / getPixelsPerMm() }); paper.add(objects);
    state.fields.forEach(field => objects.add(field._konva.clone({ draggable: false })));
    paper.draw();
    const layoutDataUrl = paperStage.toDataURL({ pixelRatio: 1, imageSmoothingEnabled: false });
    const layout4xDataUrl = paperStage.toDataURL({ pixelRatio: 4, imageSmoothingEnabled: false }); paperStage.destroy(); holder.remove();
    setSelectedNames([]); renderAll(); setZoom(100);
    openSaveTemplateModal(); elSaveTemplateName.value = 'glyph-font-check';
    await saveTemplateFromDialog();
    if (!elSaveTemplateModal.classList.contains('hidden')) throw new Error('Save was blocked.');
    return { now: now.toISOString(), xRes: 0.12, widthMm: 53, heightMm: 70, fields: recorded, layoutDataUrl, layout4xDataUrl };
  })()`);
  await downloaded;
  for (const field of result.fields) {
    fs.writeFileSync(path.join(output, field.bitmap), Buffer.from(field.dataUrl.split(',')[1], 'base64'));
    delete field.dataUrl;
  }
  fs.writeFileSync(path.join(output, 'glyph-layout.png'), Buffer.from(result.layoutDataUrl.split(',')[1], 'base64'));
  fs.writeFileSync(path.join(output, 'glyph-layout-4x.png'), Buffer.from(result.layout4xDataUrl.split(',')[1], 'base64'));
  delete result.layoutDataUrl;
  delete result.layout4xDataUrl;
  fs.writeFileSync(path.join(output, 'expected.json'), JSON.stringify({ ...result, filename, errors }, null, 2));
  fs.writeFileSync(path.join(output, 'glyph-editor.png'), (await window.webContents.capturePage()).toPNG());
  if (errors.length) throw new Error(JSON.stringify(errors));
  console.log(JSON.stringify({ filename, fields: result.fields.length, now: result.now }));
  renderer.dispose(); clearTimeout(timeout); window.destroy(); app.exit(0);
}).catch(error => { console.error(error.stack || error); renderer.dispose(); clearTimeout(timeout); app.exit(1); });
