// Runs the actual local website without preload, IPC, or access to browser tabs.
// node_modules/electron/dist/electron.exe research/fonts/verify-web-fonts.cjs
const { app, BrowserWindow } = require('electron');
const fs = require('node:fs');
const path = require('node:path');

const root = path.resolve(__dirname, '../..');
const origin = process.argv.find((value) => value.startsWith('--url='))?.slice(6) || 'http://127.0.0.1:5173';
const outputArgument = process.argv.find((value) => value.startsWith('--output='));
const output = outputArgument ? path.resolve(outputArgument.slice(9)) : path.join(root, 'tests/output/font-vector-web');
fs.mkdirSync(output, { recursive: true });
app.setPath('userData', path.join(output, 'isolated-electron-profile'));
app.disableHardwareAcceleration();
let window;
const consoleMessages = [];
const json = (name, value) => fs.writeFileSync(path.join(output, name), JSON.stringify(value, null, 2));
const writeImage = (name, value) => fs.writeFileSync(path.join(output, name), Buffer.from(value.split(',')[1], 'base64'));
const timeout = setTimeout(() => { json('failure.json', { error: 'Web font verification timed out.', consoleMessages }); app.exit(1); }, 60000);

async function diagnoseEndpoint(url) {
  try {
    const response = await fetch(url + '/__glyph_fonts/render', {
      method: 'POST', headers: { Origin: url, 'Content-Type': 'application/json' },
      body: JSON.stringify({ text: 'Abc 012345 АБВГД', face: 'Arial', pitch: 6, xRes: 1200, yRes: 1200 }),
      signal: AbortSignal.timeout(20000),
    });
    const contentType = response.headers.get('content-type');
    const body = await response.json();
    return { url, status: response.status, contentType, width: body.width, height: body.height,
      outlineAvailable: typeof body.outlinePath === 'string', outlineLength: body.outlinePath?.length,
      error: body.error || null };
  } catch (error) { return { url, error: error.message }; }
}

app.whenReady().then(async () => {
  const endpoints = await Promise.all(['http://127.0.0.1:5173', 'http://localhost:5173', 'http://[::1]:5173'].map(diagnoseEndpoint));
  json('initial-endpoint-diagnosis.json', { capturedAt: new Date().toISOString(), endpoints });
  window = new BrowserWindow({ show: false, width: 1600, height: 1100,
    webPreferences: { contextIsolation: true, sandbox: true, nodeIntegration: false, offscreen: true } });
  window.webContents.on('console-message', (_event, details, message) => {
    const value = typeof details === 'object' ? details : { level: details, message };
    if (value.level === 'error' || Number(value.level) >= 3) consoleMessages.push(value);
  });
  await window.loadURL(origin);
  const initial = await window.webContents.executeJavaScript(`(async () => {
    const deadline = Date.now() + 25000;
    while (!globalThis.__GLYPH_CIFF_RUNTIME_READY__ || !textFontCatalog.ready || !stage) {
      if (Date.now() > deadline) throw new Error('Local web runtime did not initialize.');
      await new Promise(resolve => setTimeout(resolve, 30));
    }
    const response = await fetch('/__glyph_fonts/render', { method: 'POST',
      headers: { 'Content-Type': 'application/json' }, body: JSON.stringify({ text: 'Web vector QA', face: 'Arial', pitch: 6 }) });
    const result = await response.json();
    return { url: location.href, noElectronPreload: typeof glyphLogger === 'undefined',
      bridgeUsesHttp: typeof glyphFonts?.render === 'function' && String(glyphFonts.render).includes('/__glyph_fonts/render'),
      catalogCount: getAvailableTextFontFamilies().length, httpStatus: response.status,
      outlineAvailable: typeof result.outlinePath === 'string', outlineLength: result.outlinePath?.length,
      responseWidth: result.width, responseHeight: result.height };
  })()`);
  json('initial-web-diagnosis.json', initial);

  const result = await window.webContents.executeJavaScript(`(async () => {
    const checks = [];
    const check = (name, ok, actual) => checks.push({ name, ok: !!ok, ...(actual === undefined ? {} : { actual }) });
    check('No Electron preload bridge', typeof glyphLogger === 'undefined');
    check('Native font calls use HTTP', String(glyphFonts.render).includes('/__glyph_fonts/render'));
    const xml = buildEmptyTemplateXml('DataFlex 6320(53mm)', 'Continuous', 53, 70);
    if (!loadXml(xml, { source: 'isolated-web-font-QA', title: 'Web font preview QA', markDirty: false })) throw new Error('Could not create the isolated QA template.');
    const types = ['FixedText', 'DateText', 'OffsetDateText', 'TimeText', 'CounterText'];
    state.fields = types.map((fldType, index) => {
      const value = fldType === 'FixedText' ? 'Abc 012345 АБВГД' : fldType === 'TimeText' ? 'HH:mm' : fldType === 'CounterText' ? '0001' : 'dd/MM/yy';
      const field = createBaseField({ name: 'WebFont' + index, fldType, pitch: 6, value,
        geom: { x: 100, y: 100 + index * 650, w: 1000, h: 300 } });
      field.text.face = ['Arial', 'Times New Roman', 'Courier New', 'Tahoma', 'Segoe UI'][index];
      if (fldType === 'OffsetDateText') ensureCalculatedDateOffset(field, { createNew: true });
      if (fldType === 'CounterText') normalizeCounterField(field);
      return field;
    });
    const matrix = createBaseField({ name: 'WebDataMatrix', fldType: 'Barcode', printed: true, ln: 1,
      geom: { x: 100, y: 3800, w: 1100, h: 1100 }, barcode: {
        clsid: '{7A4AA4CF-F5CD-11D4-8DAE-0050DAFE8A9F}', quietMargin: 0, bcH: 1100,
        dataMatrix: { moduleSize: 0.5, symbolSize: '22X22', structureDirty: true,
          segments: [{ index: 0, srcField: null, defaultValue: 'WEBQA123', dataType: 5 }] }
      } });
    state.fields.push(matrix);
    state.fieldByName = new Map(state.fields.map(field => [field.name, field]));
    syncDataMatrixGeomToModuleSize(matrix);
    synchronizeDataMatrixDerivedState(matrix, state.fieldByName);
    updateDataMatrixBcHFromSettings(matrix);
    const editTime = new Date(); editTime.setSeconds(0, 0);
    renderAll();
    await ensureNativeTextGeometry(state.fields.filter(field => field.fldType !== 'Barcode'), editTime);
    renderObjects();
    const first = state.fields[0];
    selectField(first.name); renderSelectionPanels();
    const selector = document.querySelector('[data-font-face-select]');
    check('All text fields expose the font selector', !!selector);
    selector.value = 'Arial Narrow'; selector.dispatchEvent(new Event('change', { bubbles: true }));
    await ensureNativeTextGeometry(state.fields.filter(field => field.fldType !== 'Barcode'), editTime);
    renderObjects();
    check('Web font selection changes the model', state.fields[0].text.face === 'Arial Narrow');
    const saved = patchXmlLosslessV2({ now: editTime });
    const geometry = state.fields.map(field => ({ name: field.name, ...field.geom }));
    const keys = state.fields.filter(field => field.fldType !== 'Barcode').map(field => getNativeTextCacheKey(field, makePreviewText(field, editTime)));
    const zoomChecks = [];
    for (const zoom of [50, 100, 133, 400]) {
      setZoom(zoom); renderObjects();
      const classes = state.fields.filter(field => field.fldType !== 'Barcode').map(field => field._konva?.findOne('.PreviewValue')?.getClassName());
      const currentGeometry = state.fields.map(field => ({ name: field.name, ...field.geom }));
      const sameKeys = state.fields.filter(field => field.fldType !== 'Barcode').every((field, index) => getNativeTextCacheKey(field, makePreviewText(field, editTime)) === keys[index]);
      const sameGeometry = JSON.stringify(currentGeometry) === JSON.stringify(geometry);
      const sameSaved = patchXmlLosslessV2({ now: editTime }) === saved;
      zoomChecks.push({ zoom, classes, sameKeys, sameGeometry, sameSaved });
      check('All five web text types use vectors at ' + zoom + '%', classes.length === 5 && classes.every(value => value === 'Path'), classes);
      check('Zoom keeps native geometry and CIFF at ' + zoom + '%', sameKeys && sameGeometry && sameSaved);
    }
    renderAll();
    await new Promise(resolve => setTimeout(resolve, 100));
    const firstCurrent = state.fields[0];
    const entry = requestNativeTextPreview(firstCurrent, makePreviewText(firstCurrent, editTime));
    const node = firstCurrent._konva?.findOne('.PreviewValue');
    check('Web cache contains native vector outlines', typeof entry?.outlinePath === 'string' && entry.outlinePath.length > 0);
    const dm = state.fields.find(field => field.fldType === 'Barcode');
    const dmNode = dm._konva?.findOne('.PreviewValue');
    const dmChildren = dmNode?.getChildren?.() || [];
    check('DataMatrix still uses module rectangles', dmNode?.getClassName() === 'Group' && dmChildren.length > 0 && dmChildren.every(child => child.getClassName() === 'Rect'));
    const proofContainer = document.createElement('div');
    const proof = new Konva.Stage({ container: proofContainer, width: Math.max(1, entry.width * 4), height: Math.max(1, entry.height * 4) });
    const proofLayer = new Konva.Layer({ imageSmoothingEnabled: false }); proof.add(proofLayer);
    proofLayer.add(new Konva.Rect({ width: proof.width(), height: proof.height(), fill: '#fff' }));
    const proofNode = node.clone({ x: 0, y: 0, scaleX: 4, scaleY: 4 }); proofLayer.add(proofNode); proofLayer.draw();
    const vectorDataUrl = proof.toDataURL({ pixelRatio: 1, imageSmoothingEnabled: false });
    const pixels = proofLayer.getCanvas().getContext().getImageData(0, 0, proof.width(), proof.height()).data;
    let edgePixels = 0;
    for (let i = 0; i < pixels.length; i += 4) if (pixels[i] > 0 && pixels[i] < 255) edgePixels++;
    check('Actual web preview has antialiased edges at 4x native size', edgePixels > 0, edgePixels);
    proof.destroy();
    const dmW = Math.ceil(mmToPx(dm.geom.w / 100)); const dmH = Math.ceil(mmToPx(dm.geom.h / 100));
    const dmProof = new Konva.Stage({ container: document.createElement('div'), width: dmW, height: dmH });
    const dmLayer = new Konva.Layer({ imageSmoothingEnabled: false }); dmProof.add(dmLayer);
    dmLayer.add(new Konva.Rect({ width: dmW, height: dmH, fill: '#fff' }));
    dmLayer.add(dmNode.clone()); dmLayer.draw();
    const dmDataUrl = dmProof.toDataURL({ pixelRatio: 1, imageSmoothingEnabled: false });
    const dmPixels = dmLayer.getCanvas().getContext().getImageData(0, 0, dmW, dmH).data;
    let dmEdgePixels = 0;
    for (let i = 0; i < dmPixels.length; i += 4) if (dmPixels[i] !== 17 && dmPixels[i] !== 255) dmEdgePixels++;
    check('DataMatrix module edges remain crisp', dmEdgePixels === 0, dmEdgePixels);
    dmProof.destroy();
    return { passed: checks.every(check => check.ok), checks, zoomChecks, installedFontCount: getAvailableTextFontFamilies().length,
      fields: state.fields.map(field => ({ name: field.name, type: field.fldType, face: field.text?.face, geom: field.geom,
        preview: field._konva?.findOne('.PreviewValue')?.getClassName() })), edgePixels, dmEdgePixels, vectorDataUrl, dmDataUrl };
  })()`);
  const { vectorDataUrl, dmDataUrl, ...summary } = result;
  json('web-results.json', { ...summary, initial, consoleMessages });
  writeImage('web-vector-400.png', vectorDataUrl);
  writeImage('web-datamatrix-400.png', dmDataUrl);
  fs.writeFileSync(path.join(output, 'web-editor-400.png'), (await window.webContents.capturePage()).toPNG());
  console.log(JSON.stringify({ passed: result.passed, initial, checks: result.checks, fields: result.fields }));
  window.destroy(); clearTimeout(timeout); app.exit(result.passed ? 0 : 1);
}).catch((error) => {
  json('failure.json', { error: error.stack || error.message, consoleMessages });
  console.error(error.stack || error);
  window?.destroy(); clearTimeout(timeout); app.exit(1);
});
