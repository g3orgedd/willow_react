const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

function loadTemplateTargetConfig() {
  const context = {
    console,
    escapeAttr: (value) => String(value),
    mmToInternal: (value) => Math.round(Number(value) * 100),
    internalToMm: (value) => Number(value) / 100,
    pushHistory: () => {
      if (context.state?.subImage) context.state.subImage.usedSizeDirty = true;
    },
    renderAll: () => {},
    document: {
      getElementById: () => null,
      querySelectorAll: () => [],
    },
  };
  context.globalThis = context;
  vm.createContext(context);

  const filename = path.join(__dirname, '..', 'public', 'modules', '00-core.js');
  vm.runInContext(fs.readFileSync(filename, 'utf8'), context, { filename });
  const compatibilityFilename = path.join(__dirname, '..', 'public', 'modules', '01-ciff-compatibility.js');
  vm.runInContext(fs.readFileSync(compatibilityFilename, 'utf8'), context, { filename: compatibilityFilename });
  for (const moduleName of ['encryption', 'tag-data', 'version-info']) {
    const filename = path.join(__dirname, '..', 'public/modules/clst', moduleName + '.js');
    vm.runInContext(fs.readFileSync(filename, 'utf8'), context, { filename });
  }
  vm.runInContext(`
    globalThis.getCanvasInternalWidth = () => Number(state.subImage.workspaceWidth || state.subImage.maxWidth || state.subImage.width || 0);
    globalThis.getCanvasInternalHeight = () => Number(state.subImage.workspaceHeight || state.subImage.maxHeight || state.subImage.height || 0);
  `, context);
  const loadFilename = path.join(__dirname, '..', 'public', 'modules', '20-xml-load.js');
  vm.runInContext(fs.readFileSync(loadFilename, 'utf8'), context, { filename: loadFilename });
  const renderingFilename = path.join(__dirname, '..', 'public', 'modules', '30-rendering.js');
  vm.runInContext(fs.readFileSync(renderingFilename, 'utf8'), context, { filename: renderingFilename });
  context.renderAll = () => {};
  return vm.runInContext(`({
    models: [...TEMPLATE_TARGET_PRINTER_MODELS],
    printerModelOptions: getPrinterModelSelectOptions,
    maxWidthFor: getTemplateMaxImageWidthInternal,
    maxHeightFor: getTemplateMaxImageHeightInternal,
    hardwareFor: getKnownPrinterCapabilities,
    buildEmptyTemplateXml,
    repairLoadedKnownPrinterProfile,
    initializeTemplateWorkspaceDimensions,
    updateTemplateSize,
    updateTemplateTarget,
    getTemplateHardwareLimitStatus,
    validateTemplateSizeInsideHardware,
    getTemplateSizePanelModel,
    decodeClStVersionInfo,
    state
  })`, context);
}

function loadCanvasDimensionConfig(subImage = { width: 2000, height: 1200, maxWidth: 5333, maxHeight: 7500 }) {
  const context = {
    console,
    window: { Konva: {} },
    state: {
      subImage,
    },
    ALLOWED_ORIENTATIONS: [0, 90, 180, 270],
  };
  context.globalThis = context;
  vm.createContext(context);
  const filename = path.join(__dirname, '..', 'public', 'modules', '10-canvas-ui.js');
  vm.runInContext(fs.readFileSync(filename, 'utf8'), context, { filename });
  return vm.runInContext(`({
    canvasWidth: getCanvasInternalWidth,
    canvasHeight: getCanvasInternalHeight
  })`, context);
}

test('all printer and printhead variants are available with matching width limits', () => {
  const config = loadTemplateTargetConfig();

  assert.deepEqual(Array.from(config.models), [
    'DataFlex 6530(53mm)',
    'DataFlex 6530(107mm)',
    'DataFlex 6420(53mm)',
    'DataFlex 6420(107mm)',
    'DataFlex 6330(32mm)',
    'DataFlex 6330(53mm)',
    'DataFlex 6320(32mm)',
    'DataFlex 6320(53mm)',
    'DataFlex 6230(32mm)',
    'DataFlex 6210(32mm)',
  ]);
  assert.equal(config.maxWidthFor('DataFlex 6530(107mm)'), 10667);
  assert.equal(config.maxWidthFor('DataFlex 6420(107mm)'), 10667);
  assert.equal(config.maxWidthFor('DataFlex 6330(32mm)'), 3200);
  assert.ok(config.models.includes('DataFlex 6320(32mm)'));
  assert.ok(config.models.includes('DataFlex 6230(32mm)'));
  assert.ok(config.models.includes('DataFlex 6210(32mm)'));
  assert.equal(config.maxWidthFor('DataFlex 6320(32mm)'), 3200);
  assert.equal(config.maxWidthFor('DataFlex 6230(32mm)'), 3200);
  assert.equal(config.maxWidthFor('DataFlex 6320(53mm)'), 5333);
  assert.equal(config.maxHeightFor('DataFlex 6330(53mm)'), 7500);
});

test('printer dropdown labels add readable spacing without changing stored model values', () => {
  const config = loadTemplateTargetConfig();
  const options = Array.from(config.printerModelOptions('DataFlex 6330(53mm)'), (option) => ({
    value: option.value,
    label: option.label,
    groupLabel: option.groupLabel ?? null,
    menuLabel: option.menuLabel ?? null,
  }));
  const selected = options.find((option) => option.value === 'DataFlex 6330(53mm)');

  assert.deepEqual(selected, {
    value: 'DataFlex 6330(53mm)',
    label: 'DataFlex 6330 (53 mm)',
    groupLabel: '53 mm',
    menuLabel: 'DataFlex 6330',
  });

  assert.deepEqual(options.map(({ groupLabel, menuLabel }) => [groupLabel, menuLabel]), [
    ['32 mm', 'DataFlex 6330'],
    ['32 mm', 'DataFlex 6320'],
    ['32 mm', 'DataFlex 6230'],
    ['32 mm', 'DataFlex 6210'],
    ['53 mm', 'DataFlex 6530'],
    ['53 mm', 'DataFlex 6420'],
    ['53 mm', 'DataFlex 6330'],
    ['53 mm', 'DataFlex 6320'],
    ['107 mm', 'DataFlex 6530'],
    ['107 mm', 'DataFlex 6420'],
  ]);

  const unknownOptions = Array.from(config.printerModelOptions('Vendor Printer(53mm)'), (option) => ({
    value: option.value,
    groupLabel: option.groupLabel ?? null,
  }));
  assert.deepEqual(unknownOptions[0], { value: 'Vendor Printer(53mm)', groupLabel: null });
  assert.equal(unknownOptions.filter((option) => option.value === 'Vendor Printer(53mm)').length, 1);

  const xml = config.buildEmptyTemplateXml(selected.value, 'Continuous', 20, 20);
  assert.match(xml, /DesignedFor="DataFlex 6330\(53mm\) - Continuous"/);
  assert.doesNotMatch(xml, /DesignedFor="DataFlex 6330 \(53 mm\) - Continuous"/);
});

test('new 107 mm templates preserve the printer target and expanded width in XML', () => {
  const config = loadTemplateTargetConfig();
  const xml = config.buildEmptyTemplateXml('DataFlex 6530(107mm)', 'Continuous', 107, 75);

  assert.match(xml, /DesignedFor="DataFlex 6530\(107mm\) - Continuous"/);
  assert.match(xml, /<ImageWidth>10667<\/ImageWidth>/);
  assert.match(xml, /<MaxImageWidth>10667<\/MaxImageWidth>/);
});

test('new empty templates generate a zero-mask ClStVersionInfo through the native path', () => {
  const config = loadTemplateTargetConfig();
  const xml = config.buildEmptyTemplateXml('DataFlex 6330(53mm)', 'Continuous', 20, 20);
  const value = xml.match(/<ClStVersionInfo>([^<]*)<\/ClStVersionInfo>/)?.[1];

  assert.equal(value.length, 72);
  const decoded = config.decodeClStVersionInfo(value, { fieldCount: 0 });
  assert.equal(decoded.maskHex, '00000000');
  assert.equal(decoded.tagData, '');
  assert.equal(decoded.includeFileMetadata, false);
});

test('empty generation applies to every printer profile without a copied token', () => {
  const config = loadTemplateTargetConfig();
  for (const model of config.models) {
    const xml = config.buildEmptyTemplateXml(model, 'Continuous', 20, 20);
    const value = xml.match(/<ClStVersionInfo>([^<]*)<\/ClStVersionInfo>/)?.[1];
    assert.equal(value.length, 72, model);
    const decoded = config.decodeClStVersionInfo(value, { fieldCount: 0 });
    assert.equal(decoded.mask, 0, model);
    assert.equal(decoded.tagData, '', model);
  }
});

test('new 32 mm templates preserve the full printer target and width limit in XML', () => {
  const config = loadTemplateTargetConfig();
  const xml = config.buildEmptyTemplateXml('DataFlex 6320(32mm)', 'Continuous', 53.33, 75);

  assert.match(xml, /DesignedFor="DataFlex 6320\(32mm\) - Continuous"/);
  assert.match(xml, /<ImageWidth>3200<\/ImageWidth>/);
  assert.match(xml, /<MaxImageWidth>3200<\/MaxImageWidth>/);
});

test('new 53 mm template writes the requested physical area separately from printer capabilities', () => {
  const config = loadTemplateTargetConfig();
  const xml = config.buildEmptyTemplateXml('DataFlex 6330(53mm)', 'Continuous', 32, 12);

  assert.match(xml, /DesignedFor="DataFlex 6330\(53mm\) - Continuous"/);
  assert.match(xml, /<SubImage ImageReference="1">/);
  assert.match(xml, /<SubHeader FormatName="Default" PrinterFormatName="Default">/);
  assert.match(xml, /<ImageWidth>3200<\/ImageWidth>/);
  assert.match(xml, /<ImageHeight>1200<\/ImageHeight>/);
  assert.match(xml, /<MaxImageWidth>3200<\/MaxImageWidth>/);
  assert.match(xml, /<MaxImageHeight>1200<\/MaxImageHeight>/);
  assert.equal(config.hardwareFor('DataFlex 6330(53mm)').maxImageWidth, 5333);
  assert.equal(config.hardwareFor('DataFlex 6330(53mm)').maxImageHeight, 7500);
  assert.match(xml, /<XRes>0\.120000<\/XRes>/);
  assert.match(xml, /<ImageMapping><Map SubIMageRef="1">1<\/Map><\/ImageMapping>/);
});

test('new 20 x 20 mm template records its physical area and keeps the 53 mm hardware profile', () => {
  const config = loadTemplateTargetConfig();
  const xml = config.buildEmptyTemplateXml('DataFlex 6330(53mm)', 'Continuous', 20, 20);

  assert.match(xml, /<ImageWidth>2000<\/ImageWidth>/);
  assert.match(xml, /<ImageHeight>2000<\/ImageHeight>/);
  assert.match(xml, /<MaxImageWidth>2000<\/MaxImageWidth>/);
  assert.match(xml, /<MaxImageHeight>2000<\/MaxImageHeight>/);
  assert.equal(config.hardwareFor('DataFlex 6330(53mm)').maxImageWidth, 5333);
  assert.equal(config.hardwareFor('DataFlex 6330(53mm)').maxImageHeight, 7500);
});

test('resizing changes workspace and CIFF MaxImage area without changing used Image or hardware limits', () => {
  const config = loadTemplateTargetConfig();
  config.state.xmlDoc = {};
  config.state.docMeta.printerModel = 'DataFlex 6330(53mm)';
  Object.assign(config.state.subImage, {
    width: 2000,
    height: 2000,
    maxWidth: 2000,
    maxHeight: 2000,
    xRes: 0.12,
  });

  config.updateTemplateSize(30, 15);

  assert.equal(config.state.subImage.width, 2000);
  assert.equal(config.state.subImage.height, 2000);
  assert.equal(config.state.subImage.workspaceWidth, 3000);
  assert.equal(config.state.subImage.workspaceHeight, 1500);
  assert.equal(config.state.subImage.maxWidth, 3000);
  assert.equal(config.state.subImage.maxHeight, 1500);
  assert.equal(config.getTemplateHardwareLimitStatus().maxWidth, 5333);
  assert.equal(config.getTemplateHardwareLimitStatus().maxHeight, 7500);
});

test('imported canvas uses the configured MaxImage area rather than the used Image bounds', () => {
  const canvas = loadCanvasDimensionConfig();

  assert.equal(canvas.canvasWidth(), 5333);
  assert.equal(canvas.canvasHeight(), 7500);
});

test('explicit editor workspace overrides the raw document dimensions', () => {
  const canvas = loadCanvasDimensionConfig({
    width: 2516,
    height: 2558,
    maxWidth: 5333,
    maxHeight: 7500,
    workspaceWidth: 2000,
    workspaceHeight: 2000,
  });

  assert.equal(canvas.canvasWidth(), 2000);
  assert.equal(canvas.canvasHeight(), 2000);
});

test('missing Image dimensions still use the imported MaxImage area', () => {
  const canvas = loadCanvasDimensionConfig({ width: 0, height: null, maxWidth: 5333, maxHeight: 7500 });

  assert.equal(canvas.canvasWidth(), 5333);
  assert.equal(canvas.canvasHeight(), 7500);
});

test('an imported template restores its workspace from MaxImage and preserves separate used Image dimensions', () => {
  const config = loadTemplateTargetConfig();
  Object.assign(config.state.subImage, {
    width: 2516,
    height: 2558,
    maxWidth: 5333,
    maxHeight: 7500,
    workspaceWidth: 0,
    workspaceHeight: 0,
  });

  const workspace = config.initializeTemplateWorkspaceDimensions({ source: 'file' });

  assert.deepEqual(JSON.parse(JSON.stringify(workspace)), { width: 5333, height: 7500, source: 'file' });
  assert.equal(config.state.subImage.workspaceWidth, 5333);
  assert.equal(config.state.subImage.workspaceHeight, 7500);
  assert.equal(config.state.subImage.width, 2516);
  assert.equal(config.state.subImage.height, 2558);
});

test('newly created templates retain their requested editor workspace', () => {
  const config = loadTemplateTargetConfig();
  Object.assign(config.state.subImage, {
    width: 2000,
    height: 2000,
    maxWidth: 2000,
    maxHeight: 2000,
    workspaceWidth: 0,
    workspaceHeight: 0,
  });

  config.initializeTemplateWorkspaceDimensions({ source: 'created' });

  assert.equal(config.state.subImage.workspaceWidth, 2000);
  assert.equal(config.state.subImage.workspaceHeight, 2000);
});

test('known imported target preserves physical area and repairs only invalid resolution', () => {
  const config = loadTemplateTargetConfig();
  config.state.docMeta.printerModel = 'DataFlex 6330(53mm)';
  Object.assign(config.state.subImage, {
    width: 2967,
    height: 1160,
    maxWidth: 3200,
    maxHeight: 1200,
    xRes: 0,
  });

  const result = config.repairLoadedKnownPrinterProfile();

  assert.equal(result.changed, true);
  assert.deepEqual(Array.from(result.changes), ['xRes']);
  assert.equal(config.state.subImage.width, 2967);
  assert.equal(config.state.subImage.height, 1160);
  assert.equal(config.state.subImage.maxWidth, 3200);
  assert.equal(config.state.subImage.maxHeight, 1200);
  assert.equal(config.state.subImage.xRes, 0.12);
  assert.deepEqual(Array.from(result.preservedDifferences), []);

  const workspace = config.initializeTemplateWorkspaceDimensions({ source: 'file' });
  assert.deepEqual(JSON.parse(JSON.stringify(workspace)), {
    width: 3200,
    height: 1200,
    source: 'file',
  });
  assert.equal(config.state.subImage.maxWidth, 3200);
  assert.equal(config.state.subImage.maxHeight, 1200);
});

test('changing 6330 from 32 mm to 53 mm preserves a 20 x 30 mm template', () => {
  const config = loadTemplateTargetConfig();
  config.state.xmlDoc = {};
  Object.assign(config.state.docMeta, {
    printerModel: 'DataFlex 6330(32mm)',
    printMode: 'Continuous',
    designedFor: 'DataFlex 6330(32mm) - Continuous',
  });
  Object.assign(config.state.subImage, {
    width: 2000,
    height: 3000,
    maxWidth: 2000,
    maxHeight: 3000,
    workspaceWidth: 2000,
    workspaceHeight: 3000,
    xRes: 0.12,
    usedSizeDirty: false,
  });

  config.updateTemplateTarget('DataFlex 6330(53mm)', 'Continuous');

  assert.equal(config.state.subImage.workspaceWidth, 2000);
  assert.equal(config.state.subImage.workspaceHeight, 3000);
  assert.equal(config.state.subImage.width, 2000);
  assert.equal(config.state.subImage.height, 3000);
  assert.equal(config.state.subImage.maxWidth, 2000);
  assert.equal(config.state.subImage.maxHeight, 3000);
  assert.equal(config.getTemplateHardwareLimitStatus().maxWidth, 5333);
  assert.equal(config.getTemplateHardwareLimitStatus().maxHeight, 7500);
  assert.equal(config.state.subImage.usedSizeDirty, false);
  assert.equal(config.state.docMeta.designedFor, 'DataFlex 6330(53mm) - Continuous');
});

test('changing printer profiles repeatedly preserves a 32 x 50 mm template', () => {
  const config = loadTemplateTargetConfig();
  config.state.xmlDoc = {};
  Object.assign(config.state.docMeta, {
    printerModel: 'DataFlex 6330(32mm)',
    printMode: 'Continuous',
    designedFor: 'DataFlex 6330(32mm) - Continuous',
  });
  Object.assign(config.state.subImage, {
    width: 3200,
    height: 5000,
    maxWidth: 3200,
    maxHeight: 5000,
    workspaceWidth: 3200,
    workspaceHeight: 5000,
    xRes: 0.12,
    usedSizeDirty: false,
  });
  const cases = [
    ['DataFlex 6530(107mm)', 10667],
    ['DataFlex 6420(53mm)', 5333],
    ['DataFlex 6330(53mm)', 5333],
  ];

  for (const [model, maxWidth] of cases) {
    config.updateTemplateTarget(model, 'Continuous');
    assert.equal(config.state.subImage.workspaceWidth, 3200, model);
    assert.equal(config.state.subImage.workspaceHeight, 5000, model);
    assert.equal(config.state.subImage.width, 3200, model);
    assert.equal(config.state.subImage.height, 5000, model);
    assert.equal(config.state.subImage.maxWidth, 3200, model);
    assert.equal(config.state.subImage.maxHeight, 5000, model);
    assert.equal(config.getTemplateHardwareLimitStatus().maxWidth, maxWidth, model);
    assert.equal(config.getTemplateHardwareLimitStatus().maxHeight, 7500, model);
    assert.equal(config.state.docMeta.designedFor, `${model} - Continuous`);
  }
});

test('changing to a narrower printer keeps an oversized template and reports the hardware overflow', () => {
  const config = loadTemplateTargetConfig();
  config.state.xmlDoc = {};
  Object.assign(config.state.docMeta, {
    printerModel: 'DataFlex 6330(53mm)',
    printMode: 'Continuous',
    designedFor: 'DataFlex 6330(53mm) - Continuous',
  });
  Object.assign(config.state.subImage, {
    width: 5300,
    height: 4000,
    maxWidth: 5300,
    maxHeight: 4000,
    workspaceWidth: 5300,
    workspaceHeight: 4000,
    xRes: 0.12,
    usedSizeDirty: false,
  });

  config.updateTemplateTarget('DataFlex 6330(32mm)', 'Continuous');

  assert.equal(config.state.subImage.workspaceWidth, 5300);
  assert.equal(config.state.subImage.workspaceHeight, 4000);
  assert.equal(config.state.subImage.maxWidth, 5300);
  assert.equal(config.state.subImage.maxHeight, 4000);
  assert.deepEqual(JSON.parse(JSON.stringify(config.getTemplateHardwareLimitStatus())), {
    width: 5300,
    height: 4000,
    maxWidth: 3200,
    maxHeight: 7500,
    widthExceeded: true,
    heightExceeded: false,
    exceeded: true,
  });
  const validation = config.validateTemplateSizeInsideHardware();
  assert.ok(validation.structuralErrors.some((message) => message.includes('53.00 x 40.00 mm')));
  assert.ok(validation.structuralErrors.some((message) => message.includes('32.00 x 75.00 mm')));
  assert.deepEqual(JSON.parse(JSON.stringify(config.getTemplateSizePanelModel())), {
    currentWidthMm: 53,
    currentHeightMm: 40,
    maxWidthMm: 32,
    maxHeightMm: 75,
    limitStatus: {
      width: 5300,
      height: 4000,
      maxWidth: 3200,
      maxHeight: 7500,
      widthExceeded: true,
      heightExceeded: false,
      exceeded: true,
    },
  });

  config.updateTemplateSize(53, 35, { changedDimension: 'height' });
  assert.equal(config.state.subImage.workspaceWidth, 5300);
  assert.equal(config.state.subImage.workspaceHeight, 3500);
  assert.equal(config.state.subImage.maxWidth, 5300);
  assert.equal(config.state.subImage.maxHeight, 3500);
});

test('changing print mode preserves template, hardware, objects and geometry metadata', () => {
  const config = loadTemplateTargetConfig();
  config.state.xmlDoc = {};
  Object.assign(config.state.docMeta, {
    printerModel: 'DataFlex 6330(53mm)',
    printMode: 'Continuous',
    designedFor: 'DataFlex 6330(53mm) - Continuous',
  });
  Object.assign(config.state.subImage, {
    width: 2000,
    height: 3000,
    maxWidth: 2000,
    maxHeight: 3000,
    workspaceWidth: 2000,
    workspaceHeight: 3000,
    xRes: 0.12,
    usedSizeDirty: false,
  });
  config.state.fields = [{ name: 'unchanged', geom: { x: 100, y: 200, w: 300, h: 400 }, text: { pitch: 12 } }];
  const beforeSubImage = JSON.stringify(config.state.subImage);
  const beforeFields = JSON.stringify(config.state.fields);

  config.updateTemplateTarget('DataFlex 6330(53mm)', 'Intermittent');

  assert.equal(JSON.stringify(config.state.subImage), beforeSubImage);
  assert.equal(JSON.stringify(config.state.fields), beforeFields);
  assert.equal(config.state.docMeta.printMode, 'Intermittent');
  assert.equal(config.state.docMeta.designedFor, 'DataFlex 6330(53mm) - Intermittent');
});

test('target change materializes the document workspace while preserving its MaxImage area', () => {
  const config = loadTemplateTargetConfig();
  config.state.xmlDoc = {};
  Object.assign(config.state.docMeta, {
    printerModel: 'DataFlex 6330(53mm)',
    printMode: 'Continuous',
    designedFor: 'DataFlex 6330(53mm) - Continuous',
  });
  Object.assign(config.state.subImage, {
    width: 2400,
    height: 1000,
    maxWidth: 4100,
    maxHeight: 6200,
    workspaceWidth: undefined,
    workspaceHeight: undefined,
    xRes: 0.1,
    usedSizeDirty: false,
  });

  config.updateTemplateTarget('DataFlex 6530(107mm)', 'Continuous');

  assert.equal(config.state.subImage.workspaceWidth, 4100);
  assert.equal(config.state.subImage.workspaceHeight, 6200);
  assert.equal(config.state.subImage.maxWidth, 4100);
  assert.equal(config.state.subImage.maxHeight, 6200);
  assert.equal(config.getTemplateHardwareLimitStatus().maxWidth, 10667);
  assert.equal(config.getTemplateHardwareLimitStatus().maxHeight, 7500);
});

test('known imported target also preserves a positive source XRes', () => {
  const config = loadTemplateTargetConfig();
  config.state.docMeta.printerModel = 'DataFlex 6330(53mm)';
  Object.assign(config.state.subImage, {
    width: 2400,
    height: 1000,
    maxWidth: 4100,
    maxHeight: 6200,
    xRes: 0.1,
  });

  const result = config.repairLoadedKnownPrinterProfile();

  assert.equal(result.changed, false);
  assert.equal(config.state.subImage.maxWidth, 4100);
  assert.equal(config.state.subImage.maxHeight, 6200);
  assert.equal(config.state.subImage.xRes, 0.1);
  assert.deepEqual(Array.from(result.preservedDifferences, (entry) => entry.key), ['xRes']);
});

test('known imported target preserves explicit zero Max, fills missing Max and repairs invalid resolution', () => {
  const config = loadTemplateTargetConfig();
  config.state.docMeta.printerModel = 'DataFlex 6330(53mm)';
  Object.assign(config.state.subImage, {
    width: 2400,
    height: 1000,
    maxWidth: 0,
    maxHeight: Number.NaN,
    xRes: -1,
  });

  const result = config.repairLoadedKnownPrinterProfile();

  assert.equal(result.changed, true);
  assert.deepEqual(Array.from(result.changes), ['maxHeight', 'xRes']);
  assert.equal(config.state.subImage.maxWidth, 0);
  assert.equal(config.state.subImage.maxHeight, 1000);
  assert.equal(config.state.subImage.xRes, 0.12);
  assert.deepEqual(Array.from(result.preservedDifferences), []);
});

test('changing print mode on a known imported target preserves physical area and source resolution', () => {
  const config = loadTemplateTargetConfig();
  config.state.xmlDoc = {};
  Object.assign(config.state.docMeta, {
    printerModel: 'DataFlex 6330(53mm)',
    printMode: 'Continuous',
    designedFor: 'DataFlex 6330(53mm) - Continuous',
  });
  Object.assign(config.state.subImage, {
    width: 2400,
    height: 1000,
    maxWidth: 4100,
    maxHeight: 6200,
    workspaceWidth: 4100,
    workspaceHeight: 6200,
    xRes: 0.1,
  });

  config.updateTemplateTarget('DataFlex 6330(53mm)', 'Intermittent');

  assert.equal(config.state.docMeta.designedFor, 'DataFlex 6330(53mm) - Intermittent');
  assert.equal(config.state.subImage.maxWidth, 4100);
  assert.equal(config.state.subImage.maxHeight, 6200);
  assert.equal(config.state.subImage.xRes, 0.1);
});

test('unknown imported target preserves physical area and source resolution', () => {
  const config = loadTemplateTargetConfig();
  config.state.docMeta.printerModel = 'Custom Printer(53mm)';
  Object.assign(config.state.subImage, {
    width: 2400,
    height: 1000,
    maxWidth: 4100,
    maxHeight: 6200,
    xRes: 0.1,
  });

  const result = config.repairLoadedKnownPrinterProfile();

  assert.equal(result.changed, false);
  assert.equal(result.knownProfile, false);
  assert.equal(config.state.subImage.maxWidth, 4100);
  assert.equal(config.state.subImage.maxHeight, 6200);
  assert.equal(config.state.subImage.xRes, 0.1);
});

test('changing print mode for an unknown target preserves physical area and source resolution', () => {
  const config = loadTemplateTargetConfig();
  config.state.xmlDoc = {};
  Object.assign(config.state.docMeta, {
    printerModel: 'Custom Printer(53mm)',
    printMode: 'Continuous',
    designedFor: 'Custom Printer(53mm) - Continuous',
  });
  Object.assign(config.state.subImage, {
    width: 2400,
    height: 1000,
    maxWidth: 4100,
    maxHeight: 6200,
    xRes: 0.1,
  });

  config.updateTemplateTarget('Custom Printer(53mm)', 'Intermittent');

  assert.equal(config.state.docMeta.designedFor, 'Custom Printer(53mm) - Intermittent');
  assert.equal(config.state.subImage.maxWidth, 4100);
  assert.equal(config.state.subImage.maxHeight, 6200);
  assert.equal(config.state.subImage.xRes, 0.1);
});

test('changing print mode cannot collapse an unknown template with missing MaxImage area', () => {
  const config = loadTemplateTargetConfig();
  config.state.xmlDoc = {};
  Object.assign(config.state.docMeta, {
    printerModel: 'Custom Printer',
    printMode: 'Continuous',
    designedFor: 'Custom Printer - Continuous',
  });
  Object.assign(config.state.subImage, {
    width: 2400,
    height: 1000,
    maxWidth: 0,
    maxHeight: 0,
    xRes: 0,
  });

  config.updateTemplateTarget('Custom Printer', 'Intermittent');

  assert.equal(config.state.subImage.width, 2400);
  assert.equal(config.state.subImage.height, 1000);
  assert.equal(config.state.subImage.maxWidth, 0);
  assert.equal(config.state.subImage.maxHeight, 0);
});
