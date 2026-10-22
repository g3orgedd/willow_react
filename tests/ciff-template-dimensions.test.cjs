const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

const { createProductionCiffRuntime, decodeCiffBytes } = require('./helpers/ciff-production-harness.cjs');

const MODULES = path.join(__dirname, '..', 'public', 'modules');
const FIXTURE = path.join(__dirname, 'fixtures', 'ciff', '16x16_1.5Y.ciff');
const fixtureBytes = fs.readFileSync(FIXTURE);
const fixtureText = decodeCiffBytes(fixtureBytes);

// Use the real registry/constants instead of reproducing printer limits or unit conversions.
const coreContext = vm.createContext({
  document: { getElementById: () => null, querySelectorAll: () => [] },
});
vm.runInContext(fs.readFileSync(path.join(MODULES, '00-core.js'), 'utf8'), coreContext);
const core = vm.runInContext(`({
  INTERNAL_PER_MM, MM_TO_PX_BASE, GRID_MM, PRINTER_CAPABILITIES,
  TEMPLATE_TARGET_PRINTER_MODELS, EMPTY_TEMPLATE_PRINT_MODES, EMPTY_TEMPLATE_SUBIMAGE,
  normalizePrinterModel, normalizeTemplateTargetPrinterModel, getKnownPrinterCapabilities,
  getPrinterCapabilities, getTemplateMaxImageWidthInternal, getTemplateMaxImageHeightInternal
})`, coreContext);

function encode(text) {
  return Buffer.concat([Buffer.from([0xff, 0xfe]), Buffer.from(text, 'utf16le')]);
}

function syntheticXml({
  width = 2000, height = 3000, imageWidth = 2516, imageHeight = 2558,
  model = 'DataFlex 6330(53mm)', mode = 'Continuous', orientation = 0, fields = '',
} = {}) {
  const tag = (name, value) => value === null ? '' : `<${name}>${value}</${name}>`;
  return '<?xml version="1.0" encoding="UTF-16"?>\r\n' +
    `<ImageDesign Version="23" xml:space="default"><Header DesignedFor="${model} - ${mode}"/>` +
    '<SubImage ImageReference="1"><SubHeader FormatName="Default" PrinterFormatName="Default">' +
    tag('ImageWidth', imageWidth) + tag('ImageHeight', imageHeight) +
    tag('MaxImageWidth', width) + tag('MaxImageHeight', height) +
    `<XRes>0.120000</XRes><CurrentOrientation>${orientation}</CurrentOrientation>` +
    `<ImageRotation>${orientation}</ImageRotation></SubHeader>${fields}</SubImage>` +
    '<GenericSettings><ImageMapping><Map SubIMageRef="1">1</Map></ImageMapping></GenericSettings></ImageDesign>\r\n';
}

function loadRuntime(input = fixtureBytes) {
  const runtime = createProductionCiffRuntime(typeof input === 'string' ? encode(input) : input);
  const { context, state } = runtime;
  const grid = [];
  class DrawNode {
    constructor(attrs) { this.attrs = attrs; }
  }
  Object.assign(context, core, {
    zoomPct: 100,
    clamp: (min, max, value) => Math.max(min, Math.min(max, value)),
    elZoomRange: { min: '25', max: '400', value: '100', setAttribute() {} },
    elZoomLabel: { textContent: '100%' },
    elStatusLeft: { textContent: '' },
    elToggleGrid: { checked: true },
    gridLayer: { destroyChildren: () => { grid.length = 0; }, add: (node) => grid.push(node), draw() {} },
    stage: { position() {}, x: () => 20, y: () => 20 },
  });
  context.window.Konva = { Rect: DrawNode, Line: DrawNode };
  vm.runInContext(fs.readFileSync(path.join(MODULES, '10-canvas-ui.js'), 'utf8'), context);
  // The shared compatibility harness stubs geometry validation. Restore the
  // production validators in a separate scope to include actual save eligibility.
  const validation = vm.runInContext(`(() => {
    ${fs.readFileSync(path.join(MODULES, '30-rendering.js'), 'utf8')}
    return { validatePrintableFieldsInsideArea, validateHardwareFieldsInsideArea };
  })()`, context);
  // Keep production load, grid, conversions and save paths; omit unrelated DOM/Konva rendering.
  Object.assign(context, {
    pushHistory: () => {}, renderAll: () => {}, renderObjects: () => {},
    renderRulers: () => {}, renderUI: () => {}, clearPendingCanvasPlacement: () => {},
    setSelectedNames: () => {},
    ...validation,
  });
  assert.equal(context.loadXml(runtime.sourceText, { source: 'file', markDirty: false }), true);
  return { ...runtime, grid, state };
}

function physicalMm(runtime) {
  const { context } = runtime;
  return [
    context.internalToMm(context.getCanvasInternalWidth()),
    context.internalToMm(context.getCanvasInternalHeight()),
  ];
}

test('attached CIFF loads as 16 x 16 mm while its 25.16 x 25.58 mm Image bounds remain separate', () => {
  const runtime = loadRuntime();
  assert.equal(core.INTERNAL_PER_MM, 100);
  assert.deepEqual(physicalMm(runtime), [16, 16]);
  assert.equal(runtime.state.subImage.width, 2516);
  assert.equal(runtime.state.subImage.height, 2558);
  assert.equal(runtime.state.subImage.maxWidth, 1600);
  assert.equal(runtime.state.subImage.maxHeight, 1600);
  assert.match(runtime.context.elStatusLeft.textContent, /Overall size: 16\.00 x 16\.00 mm/);
  assert.match(runtime.context.elStatusLeft.textContent, /Used area: 25\.16 x 25\.58 mm/);
  assert.deepEqual(
    [runtime.context.getHardwareAreaBoundsInternal().w, runtime.context.getHardwareAreaBoundsInternal().h],
    [3200, 7500],
  );
  const panel = runtime.context.getTemplateSizePanelModel();
  assert.deepEqual([panel.currentWidthMm, panel.currentHeightMm, panel.maxWidthMm, panel.maxHeightMm], [16, 16, 32, 75]);
});

test('MaxImage sizes survive different heads, print modes, and 0/90/180/270 degree orientation metadata', () => {
  const cases = [
    [1600, 1600, 'DataFlex 6320(32mm)'],
    [2000, 3000, 'DataFlex 6330(53mm)'],
    [3000, 2000, 'DataFlex 6530(107mm)'],
    [3200, 1200, 'DataFlex 6330(32mm)'],
    [5300, 4200, 'DataFlex 6530(53mm)'],
    [2000, 3000, 'Custom Printer(107mm)'],
  ];
  for (const [width, height, model] of cases) {
    for (const mode of ['Continuous', 'Intermittent']) {
      for (const orientation of [0, 90, 180, 270]) {
        const runtime = loadRuntime(syntheticXml({ width, height, model, mode, orientation }));
        assert.deepEqual(physicalMm(runtime), [width / 100, height / 100], `${model}, ${mode}, ${orientation}`);
        assert.equal(runtime.state.subImage.orientation, orientation);
      }
    }
  }
});

test('missing MaxImage dimensions inherit source Image per axis while explicit zero stays zero', () => {
  const missing = loadRuntime(syntheticXml({ width: null, height: null, imageWidth: 2100, imageHeight: 3100 }));
  assert.deepEqual(physicalMm(missing), [21, 31]);
  const zero = loadRuntime(syntheticXml({ width: 0, height: 0, imageWidth: 2100, imageHeight: 3100 }));
  assert.deepEqual(physicalMm(zero), [0, 0]);
  assert.equal(zero.state.subImage.maxWidth, 0);
  assert.equal(zero.state.subImage.maxHeight, 0);
  const saved = zero.save();
  assert.equal(saved.prepared.validation.ok, true, JSON.stringify(saved.prepared.validation));
  assert.deepEqual(physicalMm(loadRuntime(saved.bytes)), [0, 0]);
  const mixed = loadRuntime(syntheticXml({ width: 1600, height: null, imageWidth: 2516, imageHeight: 3000 }));
  assert.deepEqual(physicalMm(mixed), [16, 30]);
});

test('a zero Max axis checks edited and new printable fields while retaining the unchanged import policy', () => {
  const fields = '<Field Name="A"><FldType>FixedText</FldType><X>0</X><Y>0</Y><W>100</W><H>100</H>' +
    '<Data><Object><DataType>0</DataType><Default>A</Default></Object></Data><Text><Font/></Text></Field>';
  const runtime = loadRuntime(syntheticXml({ width: 0, height: 1000, fields }));
  const { context, state } = runtime;
  assert.deepEqual(Array.from(context.validatePrintableFieldsInsideArea().invalidPrintableFieldNames), []);
  state.fields[0].geom.x = 1;
  assert.deepEqual(Array.from(context.validatePrintableFieldsInsideArea().invalidPrintableFieldNames), ['A']);
  state.fields[0].geom.x = 0;
  state.fields.push({ ...state.fields[0], name: 'New', sourceName: null, geom: { ...state.fields[0].geom } });
  assert.deepEqual(Array.from(context.validatePrintableFieldsInsideArea().invalidPrintableFieldNames), ['New']);
});

test('zero Image dimensions inherited by missing Max are not replaced with printer limits', () => {
  const runtime = loadRuntime(syntheticXml({ width: null, height: null, imageWidth: 0, imageHeight: 0 }));
  assert.deepEqual(physicalMm(runtime), [0, 0]);
  const unknown = loadRuntime(syntheticXml({ width: null, height: null, imageWidth: 2300, imageHeight: 4100, model: 'Custom Printer' }));
  assert.deepEqual(physicalMm(unknown), [23, 41]);
});

test('missing or invalid mandatory Image and explicitly invalid Max reject before replacing the current document', () => {
  const runtime = loadRuntime();
  const { context, state } = runtime;
  const before = JSON.stringify({ xml: state.xmlText, meta: state.docMeta, subImage: state.subImage });
  const notifications = [];
  let placementCleared = false;
  context.openNotificationModal = (...args) => notifications.push(args);
  context.clearPendingCanvasPlacement = () => { placementCleared = true; };
  for (const invalid of [null, '', 'nonsense', 'Infinity', '1600junk', '1e3', 1.5, '9007199254740992', -100]) {
    const xml = syntheticXml({ imageWidth: invalid });
    assert.equal(context.loadXml(xml, { source: 'file' }), false, `ImageWidth=${invalid}`);
    assert.equal(JSON.stringify({ xml: state.xmlText, meta: state.docMeta, subImage: state.subImage }), before);
  }
  for (const invalid of ['', 'nonsense', 'Infinity', '1600junk', '1e3', 1.5, '9007199254740992', -100]) {
    assert.equal(context.loadXml(syntheticXml({ width: invalid }), { source: 'file' }), false, `MaxImageWidth=${invalid}`);
  }
  assert.equal(placementCleared, false);
  assert.ok(notifications.every(([message]) => message === 'dialog.fileOpenError.invalidDimensions'));
});

test('native hmm Units loads; dots and unknown Units fail before document or pending placement changes', () => {
  const runtime = loadRuntime();
  const { context, state } = runtime;
  for (const units of ['hmm', '0', '']) {
    const xml = syntheticXml().replace('/><SubImage', `><Units>${units}</Units></Header><SubImage`);
    assert.equal(context.loadXml(xml, { source: 'file' }), true, `Units=${units}`);
    assert.equal(state.docMeta.units, 0);
  }
  const before = JSON.stringify({ xml: state.xmlText, meta: state.docMeta, subImage: state.subImage });
  let placementCleared = false;
  const notifications = [];
  context.openNotificationModal = (...args) => notifications.push(args);
  context.clearPendingCanvasPlacement = () => { placementCleared = true; };
  for (const units of ['dots', '1', 'unknown']) {
    const xml = syntheticXml().replace('/><SubImage', `><Units>${units}</Units></Header><SubImage`);
    assert.equal(context.loadXml(xml, { source: 'file' }), false);
    assert.equal(JSON.stringify({ xml: state.xmlText, meta: state.docMeta, subImage: state.subImage }), before);
  }
  assert.equal(placementCleared, false);
  assert.ok(notifications.every(([message]) => message === 'dialog.fileOpenError.unsupportedUnits'));
});

test('an independent source YRes survives load, no-op save, reopen and print-mode changes', () => {
  const xml = syntheticXml().replace('<XRes>0.120000</XRes>', '<XRes>0.120000</XRes><YRes>0.080000</YRes>');
  const runtime = loadRuntime(xml);
  assert.equal(runtime.state.subImage.xRes, 0.12);
  assert.equal(runtime.state.subImage.yRes, 0.08);
  runtime.context.updateTemplateTarget('DataFlex 6330(53mm)', 'Intermittent');
  assert.equal(runtime.state.subImage.yRes, 0.08);
  const saved = runtime.save();
  assert.equal(saved.prepared.validation.ok, true, JSON.stringify(saved.prepared.validation));
  const reopened = loadRuntime(saved.bytes);
  assert.equal(reopened.state.subImage.xRes, 0.12);
  assert.equal(reopened.state.subImage.yRes, 0.08);
  assert.deepEqual(physicalMm(reopened), [20, 30]);
});

test('changing object bounds and used-image bounds never resizes the physical workspace', () => {
  const runtime = loadRuntime();
  runtime.state.fields.forEach((field) => {
    field.geom.x += 10000;
    field.geom.y += 20000;
  });
  runtime.state.subImage.width = 90000;
  runtime.state.subImage.height = 80000;
  runtime.context.initializeTemplateWorkspaceDimensions({ source: 'file' });
  assert.deepEqual(physicalMm(runtime), [16, 16]);
  runtime.state.fields = [];
  runtime.state.subImage.width = 0;
  runtime.state.subImage.height = 0;
  runtime.context.initializeTemplateWorkspaceDimensions({ source: 'file' });
  assert.deepEqual(physicalMm(runtime), [16, 16]);
});

test('unknown printer capabilities do not turn document dimensions into hardware limits', () => {
  const runtime = loadRuntime(syntheticXml({ width: 1600, height: 1600, model: 'Custom Printer(107mm)' }));
  const { context } = runtime;
  assert.deepEqual(physicalMm(runtime), [16, 16]);
  const panel = context.getTemplateSizePanelModel();
  assert.equal(panel.maxWidthMm, null);
  assert.equal(panel.maxHeightMm, null);
  assert.deepEqual([context.getHardwareAreaBoundsInternal().w, context.getHardwareAreaBoundsInternal().h], [0, 0]);
  context.updateTemplateSize(20, 30);
  assert.deepEqual(physicalMm(runtime), [20, 30]);
  assert.equal(context.getTemplateHardwareLimitStatus().exceeded, false);
  const saved = runtime.save();
  assert.equal(saved.prepared.validation.ok, true, JSON.stringify(saved.prepared.validation));
  assert.deepEqual(physicalMm(loadRuntime(saved.bytes)), [20, 30]);
});

test('save and reopen preserve the attached file physical dimensions and source geometry', () => {
  const runtime = loadRuntime();
  const beforeGeometry = JSON.stringify(runtime.state.fields.map(({ name, geom, orientation }) => ({ name, geom, orientation })));
  const result = runtime.save();
  assert.equal(result.prepared.validation.ok, true, JSON.stringify(result.prepared.validation));
  const reopened = loadRuntime(result.bytes);
  assert.deepEqual(physicalMm(reopened), [16, 16]);
  assert.equal(reopened.state.subImage.width, 2516);
  assert.equal(reopened.state.subImage.height, 2558);
  assert.equal(JSON.stringify(reopened.state.fields.map(({ name, geom, orientation }) => ({ name, geom, orientation }))), beforeGeometry);
});

test('unchanged imported overflow remains saveable but editing overflow geometry or shrinking requires containment', () => {
  const runtime = loadRuntime();
  const { context, state } = runtime;
  const dot = state.fieldByName.get('Field02');
  assert.equal(dot.printed, true);
  assert.ok(dot.geom.x > 1600 && dot.geom.y > 1600);
  assert.deepEqual(Array.from(context.validatePrintableFieldsInsideArea().invalidPrintableFieldNames), []);

  dot.geom.x += 1;
  assert.ok(context.validatePrintableFieldsInsideArea().invalidPrintableFieldNames.includes('Field02'));
  assert.equal(runtime.save().prepared.validation.ok, false);
  // Save preparation restores model snapshots, so reacquire the field afterwards.
  state.fieldByName.get('Field02').geom.x -= 1;
  assert.deepEqual(Array.from(context.validatePrintableFieldsInsideArea().invalidPrintableFieldNames), []);

  const within = state.fields.find((field) => field.printed && field.name !== 'Field02');
  const originalX = within.geom.x;
  within.geom.x = 1700;
  assert.ok(context.validatePrintableFieldsInsideArea().invalidPrintableFieldNames.includes(within.name));
  within.geom.x = originalX;
  context.updateTemplateSize(15, 15);
  assert.ok(context.validatePrintableFieldsInsideArea().invalidPrintableFieldNames.includes('Field02'));
  assert.equal(runtime.save().prepared.validation.ok, false);
});

test('resizing persists the physical dimensions in MaxImage so reopening cannot restore the old workspace', () => {
  const runtime = loadRuntime(syntheticXml());
  runtime.context.updateTemplateSize(24, 35);
  assert.deepEqual(physicalMm(runtime), [24, 35]);
  const result = runtime.save();
  assert.equal(result.prepared.validation.ok, true, JSON.stringify(result.prepared.validation));
  const reopened = loadRuntime(result.bytes);
  assert.deepEqual(physicalMm(reopened), [24, 35]);
  assert.deepEqual([reopened.state.subImage.maxWidth, reopened.state.subImage.maxHeight], [2400, 3500]);
});

test('new templates retain requested dimensions after save and reopening as a file', () => {
  const runtime = loadRuntime(syntheticXml());
  for (const [width, height] of [[16, 16], [20, 30], [30, 20]]) {
    const xml = runtime.context.buildEmptyTemplateXml('DataFlex 6330(53mm)', 'Intermittent', width, height);
    const created = loadRuntime(xml);
    assert.deepEqual(physicalMm(created), [width, height]);
    const result = created.save();
    assert.equal(result.prepared.validation.ok, true, JSON.stringify(result.prepared.validation));
    assert.deepEqual(physicalMm(loadRuntime(result.bytes)), [width, height]);
  }
});

test('changing printer or mode preserves physical dimensions through saving and reopening', () => {
  const runtime = loadRuntime(syntheticXml({ width: 2000, height: 3000, model: 'DataFlex 6320(32mm)' }));
  for (const model of ['DataFlex 6330(53mm)', 'DataFlex 6530(107mm)', 'DataFlex 6320(32mm)']) {
    runtime.context.updateTemplateTarget(model, 'Intermittent');
    assert.deepEqual(physicalMm(runtime), [20, 30]);
    assert.deepEqual([runtime.state.subImage.maxWidth, runtime.state.subImage.maxHeight], [2000, 3000]);
    const result = runtime.save();
    assert.equal(result.prepared.validation.ok, true, JSON.stringify(result.prepared.validation));
    assert.deepEqual(physicalMm(loadRuntime(result.bytes)), [20, 30]);
  }
});

test('zoom changes grid pixels and ruler spacing without changing physical dimensions or CIFF units', () => {
  const runtime = loadRuntime(syntheticXml({ width: 2000, height: 3000 }));
  const { context, grid } = runtime;
  const initialDimensions = JSON.stringify(runtime.state.subImage);
  for (const zoom of [25, 100, 250, 400]) {
    context.setZoom(zoom);
    assert.deepEqual(physicalMm(runtime), [20, 30]);
    assert.equal(JSON.stringify(runtime.state.subImage), initialDimensions);
    const pxPerMm = 12 * zoom / 100;
    assert.equal(context.getPixelsPerMm(), pxPerMm);
    assert.deepEqual([grid[0].attrs.width, grid[0].attrs.height], [20 * pxPerMm, 30 * pxPerMm]);
    assert.equal(context.mmToInternal(context.pxToMm(5 * pxPerMm)), 500);
    assert.ok(grid.some(({ attrs }) => attrs.points?.[0] === pxPerMm && attrs.points?.[2] === pxPerMm));

    const ticks = [];
    const drawing = {
      clearRect() {}, createLinearGradient: () => ({ addColorStop() {} }), fillRect() {},
      beginPath() {}, moveTo: (x, y) => ticks.push([x, y]), lineTo() {}, stroke() {},
      measureText: () => ({ width: 10 }), fillText() {},
    };
    context.drawTopRuler(drawing, 600, 24, context.getRulerConfig(), pxPerMm, {});
    assert.ok(ticks.some(([x, y]) => x === Math.round(20 + 10 * pxPerMm) + 0.5 && y === 24), '10 mm ruler tick uses the same physical scale');
  }
});
