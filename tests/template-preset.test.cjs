const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

function baseField(config = {}) {
  const userEntered = !!config.userEntered;
  return {
    name: config.name,
    fldType: config.fldType || 'FixedText',
    printed: config.printed !== false,
    geom: config.geom || { x: 200, y: 200, w: 1200, h: 400 },
    calcData: config.value || '',
    data: {
      defaultValue: config.value || '',
      maxChars: config.maxChars ?? null,
      userEnterData: userEntered ? (config.value || '') : '',
      textEntryMode: userEntered ? 'user' : 'fixed',
      offsetRef: config.offsetRef || null,
    },
    text: { pitch: config.pitch || 10 },
    barcode: config.barcode || null,
  };
}

function loadPresetModule() {
  const helperNames = Object.freeze({
    C1: 'C1',
    GTIN: 'GTIN',
    C2: 'C2',
    SN: 'SN',
    C3: 'C3',
    KRIPTO: 'KRIPTO',
    C4: 'C4',
    KRIPTO2: 'KRIPTO2',
  });
  const helperSpecs = Object.freeze({
    [helperNames.C1]: { mode: 'fixed', maxChars: 4, pitch: 10 },
    [helperNames.GTIN]: { mode: 'user', maxChars: 14, pitch: 10 },
    [helperNames.C2]: { mode: 'fixed', maxChars: 2, pitch: 10 },
    [helperNames.SN]: { mode: 'user', maxChars: 6, pitch: 10 },
    [helperNames.C3]: { mode: 'fixed', maxChars: 7, pitch: 10 },
    [helperNames.KRIPTO]: { mode: 'user', maxChars: 4, pitch: 10 },
    [helperNames.C4]: { mode: 'fixed', maxChars: 7, pitch: 10 },
    [helperNames.KRIPTO2]: { mode: 'user', maxChars: 44, pitch: 10 },
  });
  const printerTargets = [
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
  ];
  const context = {
    console,
    EMPTY_TEMPLATE_PRINTER_MODELS: ['6530', '6420', '6330', '6320'],
    TEMPLATE_TARGET_PRINTER_MODELS: printerTargets,
    DEFAULT_TEMPLATE_TARGET_PRINTER_MODEL: printerTargets[0],
    EMPTY_TEMPLATE_PRINT_MODES: ['Intermittent', 'Continuous'],
    normalizeTemplateTargetPrinterModel: (value) => printerTargets.includes(String(value))
      ? String(value)
      : printerTargets[0],
    getTemplateMaxImageWidthInternal: (value) => String(value).includes('(32mm)')
      ? 3200
      : String(value).includes('(107mm)') ? 10667 : 5333,
    getTemplateMaxImageHeightInternal: () => 7500,
    DATA_MATRIX_SYMBOLS: [{ name: '22X22' }, { name: '32X32' }, { name: '36X36' }],
    DATA_MATRIX_SYMBOLS_BY_NAME: new Map([['22X22', {}], ['32X32', {}], ['36X36', {}]]),
    DM_HELPER_NAMES: helperNames,
    DM_HELPER_SPECS: helperSpecs,
    getDataMatrixHelperMaxChars: (name, value) => {
      if (name === helperNames.SN && [6, 13].includes(String(value ?? '').length)) return String(value).length;
      return helperSpecs[name]?.maxChars ?? null;
    },
    DM_COMPOSITIONS: {
      short: {
        requiredSegments: [helperNames.C1, 'GTIN', helperNames.C2, 'SN', helperNames.C3, 'KRIPTO'],
        fixedFields: { [helperNames.C1]: '~101', [helperNames.C2]: '21', [helperNames.C3]: '~d02993' },
        disallowedFields: ['C4', 'KRIPTO2'],
      },
      long: {
        requiredSegments: [helperNames.C1, 'GTIN', helperNames.C2, 'SN', helperNames.C3, 'KRIPTO', 'C4', 'KRIPTO2'],
        fixedFields: { [helperNames.C1]: '~101', [helperNames.C2]: '21', [helperNames.C3]: '~d02991', C4: '~d02992' },
      },
    },
    FIELD_CATALOG: {
      PARTY: { value: '00000' }, TEAM: { value: '00' }, R_NUM: { value: '00000' },
      PRODUCT_DATE: { value: '0000000000' }, EXPIRATION_DATE: { value: '0000000000' },
      PACKING_DATE: { value: '0000000000' },
    },
    normalizeDataMatrixSymbolSizeValue: (value, fallback) => String(value || fallback || '').toUpperCase(),
    getDataMatrixComposition: (value) => Math.max(...String(value).split('X').map(Number)) >= 32 ? 'long' : 'short',
    mmToInternal: (value) => Math.round(value * 100),
    internalToMm: (value) => Number(value) / 100,
    normalizeEmptyTemplateDimensionMm: (value, maxInternal, fallbackInternal) => {
      const fallbackMm = Number(fallbackInternal) / 100;
      const maxMm = Number(maxInternal) / 100;
      let next = Number(value);
      if (!Number.isFinite(next) || next <= 0) next = fallbackMm;
      return Number(Math.max(0.01, Math.min(maxMm, next)).toFixed(2));
    },
    getStoredTextFieldValue: (field) => field?.data?.userEnterData || field?.data?.defaultValue || '',
    getClarisoftTextFieldWidthInternal: (value, pitch) => Math.max(1, String(value).length * pitch * 10),
    getClarisoftTextFieldHeightInternal: (pitch) => Math.max(1, pitch * 40),
    getNextClarisoftFieldName: (existingNames = []) => {
      const names = new Set(Array.from(existingNames, String));
      let index = 0;
      while (names.has(`Field${String(index).padStart(2, '0')}`)) index += 1;
      return `Field${String(index).padStart(2, '0')}`;
    },
    synchronizeDataMatrixDerivedState: (field, fieldByName) => {
      const segments = field?.barcode?.dataMatrix?.segments || [];
      segments.forEach((segment, index) => {
        segment.index = index;
        segment.defaultValue = context.getStoredTextFieldValue(fieldByName.get(segment.srcField));
      });
      field.calcData = segments.map((segment) => segment.defaultValue).join('');
      return true;
    },
    createBaseField: (config) => baseField(config),
    createFixedTextField: (config) => baseField({ ...config, userEntered: false }),
    createServerVariableField: (config) => baseField({ ...config, userEntered: true }),
    createPrinterInputField: (config) => baseField({ ...config, userEntered: true }),
    createCurrentDateField: (config) => baseField({ ...config, fldType: 'DateText', value: `${config.format}|${config.separator}` }),
    createOffsetDateField: (config, offsetRef) => baseField({ ...config, fldType: 'OffsetDateText', value: `${config.format}|${config.separator}`, offsetRef }),
    createCurrentTimeField: (config) => baseField({ ...config, fldType: 'TimeText', value: `${config.format}|${config.separator}` }),
    syncDataMatrixGeomToModuleSize: (field) => {
      const side = Number(field.barcode.dataMatrix.symbolSize.split('X')[0]) * field.barcode.dataMatrix.moduleSize;
      field.geom.w = Math.round(side * 100);
      field.geom.h = Math.round(side * 100);
    },
    updateDataMatrixBcHFromSettings: (field) => {
      const rows = Number(field.barcode.dataMatrix.symbolSize.split('X')[0]);
      const bcH = Math.round(rows * field.barcode.dataMatrix.moduleSize * 100);
      field.barcode.bcH = bcH;
      return bcH;
    },
    getComputedDateOffsetCurrent: ({ default: value }) => ({ ...value }),
    getEffectiveTextPitch: (field) => field.text?.pitch || 10,
    getFieldRenderedBoundsInternal: (field) => {
      const value = field.data?.userEnterData || field.data?.defaultValue || field.calcData || '';
      const pitch = field.text?.pitch || 10;
      return {
        x: field.geom.x,
        y: field.geom.y,
        w: Math.max(1, String(value).length * pitch * 10),
        h: Math.max(1, pitch * 40),
      };
    },
    CLARISOFT_TEXT_FIELD_HEIGHT_MM_PER_PITCH: 0.4,
    buildEmptyTemplateXml: (_model, _mode, width, height) => `<empty width="${width}" height="${height}"/>`,
    state: {
      fields: [],
      fieldByName: new Map(),
      dateOffsets: [],
      dateOffsetsLoaded: false,
      dateOffsetsDirty: false,
      subImage: { width: 1100, height: 1100, usedSizeDirty: false },
      validation: { invalidPrintableFieldNames: [] },
    },
    createTemplateInNewTab: () => ({}),
    setSelectedNames: () => {},
    syncUsedImageSizeFromPrintableFields: () => {
      const printed = context.state.fields.filter((field) => field.printed);
      context.state.subImage.width = Math.max(...printed.map((field) => field.geom.x + field.geom.w));
      context.state.subImage.height = Math.max(...printed.map((field) => field.geom.y + field.geom.h));
      context.state.subImage.usedSizeDirty = false;
    },
    pushHistory: (initial) => {
      context.historyWasInitial = initial;
      context.historySawUsedSizeDirty = context.state.subImage.usedSizeDirty;
    },
    renderAll: () => {},
    markActiveTemplateTabDirty: () => {},
    onTemplateLoadedIntoActiveTab: () => {},
    document: { querySelectorAll: () => [], querySelector: () => null },
  };
  context.globalThis = context;
  vm.createContext(context);
  const filename = path.join(__dirname, '..', 'public', 'modules', '45-template-preset.js');
  vm.runInContext(fs.readFileSync(filename, 'utf8'), context, { filename });
  return context;
}

function readyDraft(api) {
  const draft = api.createDefaultTemplatePresetDraft();
  draft.creationKind = 'preset-builder';
  draft.dataSourceMode = 'server-dm-printer-rest';
  return draft;
}

test('new template defaults to Continuous print mode', () => {
  const api = loadPresetModule();
  assert.equal(api.createDefaultTemplatePresetDraft().base.printMode, 'Continuous');
  assert.equal(api.createDefaultTemplatePresetDraft().base.printerModel, 'DataFlex 6530(53mm)');
});

test('32 mm printer presets reject widths above 32 mm', () => {
  const api = loadPresetModule();
  const draft = api.createDefaultTemplatePresetDraft();
  draft.creationKind = 'empty';
  draft.base.printerModel = 'DataFlex 6320(32mm)';
  draft.base.widthMm = 32.01;

  assert.ok(api.validateTemplatePresetDraft(draft).some((issue) => issue.code === 'invalidWidth'));
  draft.base.widthMm = 32;
  assert.equal(api.validateTemplatePresetDraft(draft).some((issue) => issue.code === 'invalidWidth'), false);
});

test('new-template printer changes synchronize the head-width axis in every direction', () => {
  const api = loadPresetModule();
  let draft = api.createDefaultTemplatePresetDraft();
  draft.creationKind = 'empty';
  draft.base.heightMm = 41.25;
  const transitions = [
    ['DataFlex 6330(32mm)', 32],
    ['DataFlex 6330(53mm)', 53.33],
    ['DataFlex 6530(107mm)', 106.67],
    ['DataFlex 6530(53mm)', 53.33],
    ['DataFlex 6320(32mm)', 32],
    ['DataFlex 6420(107mm)', 106.67],
    ['DataFlex 6210(32mm)', 32],
  ];

  for (const [printerModel, widthMm] of transitions) {
    draft = api.synchronizeTemplatePresetDraftPrinter(draft, printerModel);
    assert.equal(draft.base.printerModel, printerModel, printerModel);
    assert.equal(draft.base.widthMm, widthMm, printerModel);
    assert.equal(draft.base.heightMm, 41.25, printerModel);
    assert.equal(
      api.buildEmptyTemplateXml(draft.base.printerModel, draft.base.printMode, draft.base.widthMm, draft.base.heightMm),
      `<empty width="${widthMm}" height="41.25"/>`,
      printerModel,
    );
  }
});

test('new-template printer changes clamp only an invalid secondary axis', () => {
  const api = loadPresetModule();
  const draft = api.createDefaultTemplatePresetDraft();
  draft.base.heightMm = 120;

  const synchronized = api.synchronizeTemplatePresetDraftPrinter(draft, 'DataFlex 6530(107mm)');

  assert.equal(synchronized.base.widthMm, 106.67);
  assert.equal(synchronized.base.heightMm, 75);
});

test('committing a generated template recalculates Image dimensions from its final fields', () => {
  const api = loadPresetModule();
  const result = api.generateTemplatePreset(readyDraft(api));
  const printed = result.fields.filter((field) => field.printed);
  const expectedWidth = Math.max(...printed.map((field) => field.geom.x + field.geom.w));
  const expectedHeight = Math.max(...printed.map((field) => field.geom.y + field.geom.h));

  assert.equal(api.commitGeneratedTemplatePreset(result), true);
  assert.equal(api.state.subImage.width, expectedWidth);
  assert.equal(api.state.subImage.height, expectedHeight);
  assert.equal(api.state.subImage.usedSizeDirty, false);
  assert.equal(api.historyWasInitial, true);
  assert.equal(api.historySawUsedSizeDirty, false);
});

test('short DataMatrix has six ordered segments and no long-only fields', () => {
  const api = loadPresetModule();
  const result = api.generateTemplatePreset(readyDraft(api));
  assert.equal(result.ok, true);
  const dm = result.fields.find((field) => field.barcode);
  assert.deepEqual(Array.from(dm.barcode.dataMatrix.segments, (segment) => segment.srcField), ['C1', 'GTIN', 'C2', 'SN', 'C3', 'KRIPTO']);
  assert.equal(result.fields.some((field) => field.name === 'C4'), false);
  assert.equal(result.fields.some((field) => field.name === 'KRIPTO2'), false);
  assert.equal(result.fields.find((field) => field.name === 'GTIN').data.maxChars, 14);
  assert.equal(result.fields.find((field) => field.name === 'SN').data.maxChars, 6);
  assert.equal(result.fields.find((field) => field.name === 'KRIPTO').data.maxChars, 4);
  assert.equal(dm.barcode.bcH, 1100);
});

test('32X32 uses the long composition and preserves the selected SymbolSize', () => {
  const api = loadPresetModule();
  const draft = readyDraft(api);
  draft.dataMatrix.symbolSize = '32X32';
  draft.dataMatrix.snValue = '0000000000000';
  const result = api.generateTemplatePreset(draft);
  const dm = result.fields.find((field) => field.barcode);
  assert.equal(result.ok, true);
  assert.equal(dm.barcode.dataMatrix.symbolSize, '32X32');
  assert.deepEqual(Array.from(dm.barcode.dataMatrix.segments, (segment) => segment.srcField), ['C1', 'GTIN', 'C2', 'SN', 'C3', 'KRIPTO', 'C4', 'KRIPTO2']);
  assert.equal(result.fields.find((field) => field.name === 'SN').data.maxChars, 13);
  assert.equal(result.fields.find((field) => field.name === 'KRIPTO2').data.maxChars, 44);
});

test('hidden DataMatrix fields are stacked outside the template without overlap', () => {
  const api = loadPresetModule();
  const draft = readyDraft(api);
  draft.dataMatrix.symbolSize = '32X32';
  const result = api.generateTemplatePreset(draft);
  const hiddenFields = result.fields.filter((field) => !field.printed);
  const templateWidth = api.mmToInternal(draft.base.widthMm);

  assert.equal(hiddenFields.length, 8);
  hiddenFields.forEach((field, index) => {
    assert.ok(field.geom.x > templateWidth);
    if (index === 0) return;
    const previous = hiddenFields[index - 1];
    assert.equal(field.geom.x, previous.geom.x);
    assert.ok(field.geom.y >= previous.geom.y + previous.geom.h);
  });
});

test('printer offset date creates a deterministic dedicated DateOffset', () => {
  const api = loadPresetModule();
  const draft = readyDraft(api);
  draft.fields.expirationDate.enabled = true;
  const result = api.generateTemplatePreset(draft);
  const date = result.fields.find((field) => field.name === 'EXP_DATE');
  assert.equal(date.fldType, 'OffsetDateText');
  assert.equal(date.data.offsetRef, 'EXP_DATE_OFFSET');
  assert.deepEqual(JSON.parse(JSON.stringify(result.dateOffsets[0].default)), { y: 0, m: 0, d: 30 });
});

test('DataMatrix-only mode exposes only renamed dates and time', () => {
  const api = loadPresetModule();
  const draft = readyDraft(api);
  Object.values(draft.fields).forEach((field) => { field.enabled = true; });
  const result = api.generateTemplatePreset(draft);
  const printedNames = result.fields.filter((field) => field.printed && !field.barcode).map((field) => field.name);
  assert.deepEqual(Array.from(printedNames), ['PROD_DATE', 'EXP_DATE', 'TIME']);
  assert.equal(result.fields.some((field) => ['PARTY', 'TEAM', 'R_NUM', 'PACKING_DATE'].includes(field.name)), false);
});

test('server-full mode emits canonical Clarisoft field order', () => {
  const api = loadPresetModule();
  const draft = readyDraft(api);
  draft.dataSourceMode = 'server-full';
  Object.values(draft.fields).forEach((field) => { field.enabled = true; });
  const result = api.generateTemplatePreset(draft);
  const printedNames = result.fields.filter((field) => field.printed && !field.barcode).map((field) => field.name);
  assert.deepEqual(Array.from(printedNames), ['PRODUCT_DATE', 'EXPIRATION_DATE', 'PARTY', 'TEAM', 'R_NUM', 'PACKING_DATE']);
  assert.deepEqual(Array.from(result.fields, (field) => field.name), [
    'Field00',
    'PRODUCT_DATE',
    'EXPIRATION_DATE',
    'PARTY',
    'TEAM',
    'R_NUM',
    'PACKING_DATE',
    'C1',
    'GTIN',
    'C2',
    'SN',
    'C3',
    'KRIPTO',
  ]);
});

test('layout reports fields that do not fit before commit', () => {
  const api = loadPresetModule();
  const draft = readyDraft(api);
  draft.base.widthMm = 10;
  draft.base.heightMm = 10;
  Object.values(draft.fields).forEach((field) => { field.enabled = true; });
  const result = api.generateTemplatePreset(draft);
  assert.equal(result.ok, false);
  assert.ok(result.layout.overflowFieldNames.length > 0);
  assert.ok(result.issues.some((issue) => issue.code === 'layoutOverflow'));
});

function enableFields(draft, keys) {
  Object.entries(draft.fields).forEach(([key, field]) => { field.enabled = keys.includes(key); });
}

function assertPrintedFieldsDoNotOverlap(result) {
  const printed = result.fields.filter((field) => field.printed);
  for (let index = 0; index < printed.length; index += 1) {
    const first = printed[index].geom;
    for (let otherIndex = index + 1; otherIndex < printed.length; otherIndex += 1) {
      const second = printed[otherIndex].geom;
      const overlaps = first.x < second.x + second.w && first.x + first.w > second.x &&
        first.y < second.y + second.h && first.y + first.h > second.y;
      assert.equal(overlaps, false, `${printed[index].name} overlaps ${printed[otherIndex].name}`);
    }
  }
}

test('20 x 20 template keeps the standard size when one additional field already fits', () => {
  const api = loadPresetModule();
  const draft = readyDraft(api);
  draft.dataSourceMode = 'server-full';
  draft.base.widthMm = 20;
  draft.base.heightMm = 20;
  enableFields(draft, ['productDate']);

  const result = api.generateTemplatePreset(draft);
  const field = result.fields.find((item) => item.name === 'PRODUCT_DATE');
  assert.equal(result.ok, true);
  assert.equal(result.layout.adapted, false);
  assert.equal(field.text.pitch, 10);
  assertPrintedFieldsDoNotOverlap(result);
});

test('20 x 20 template scales four additional fields to the largest fitting pitch', () => {
  const api = loadPresetModule();
  const draft = readyDraft(api);
  draft.dataSourceMode = 'server-full';
  draft.base.widthMm = 20;
  draft.base.heightMm = 20;
  enableFields(draft, ['productDate', 'expirationDate', 'packingDate', 'rNum']);

  const result = api.generateTemplatePreset(draft);
  const dm = result.fields.find((field) => field.barcode?.dataMatrix);
  const additional = result.fields.filter((field) => field.printed && !field.barcode);
  assert.equal(result.ok, true);
  assert.equal(result.layout.adapted, true);
  assert.equal(result.layout.fieldScale, 0.7);
  assert.ok(additional.every((field) => field.text.pitch === 7));
  assert.equal(dm.geom.w, api.mmToInternal(11));
  assert.equal(dm.geom.h, api.mmToInternal(11));
  assertPrintedFieldsDoNotOverlap(result);

  const largerPitchLayout = api.calculatePresetLayout(draft.base, result.fields, {
    adaptive: true,
    scale: 0.8,
    basePitches: Object.fromEntries(additional.map((field) => [field.name, 10])),
  });
  assert.ok(largerPitchLayout.overflowFieldNames.length > 0);
});

test('large templates retain standard field sizes and increasing size restores them', () => {
  const api = loadPresetModule();
  const draft = readyDraft(api);
  draft.dataSourceMode = 'server-full';
  enableFields(draft, ['productDate', 'expirationDate', 'packingDate', 'rNum']);

  draft.base.widthMm = 20;
  draft.base.heightMm = 20;
  const compact = api.generateTemplatePreset(draft);
  assert.equal(compact.layout.adapted, true);

  draft.base.widthMm = 53.33;
  draft.base.heightMm = 75;
  const large = api.generateTemplatePreset(draft);
  assert.equal(large.ok, true);
  assert.equal(large.layout.adapted, false);
  assert.ok(large.fields.filter((field) => field.printed && !field.barcode).every((field) => field.text.pitch === 10));
});

test('changing the selected field set recalculates size and positions from defaults', () => {
  const api = loadPresetModule();
  const draft = readyDraft(api);
  draft.dataSourceMode = 'server-full';
  draft.base.widthMm = 20;
  draft.base.heightMm = 20;
  enableFields(draft, ['productDate', 'expirationDate', 'packingDate', 'rNum']);
  const compact = api.generateTemplatePreset(draft);
  assert.equal(compact.layout.adapted, true);

  enableFields(draft, ['productDate']);
  const recalculated = api.generateTemplatePreset(draft);
  assert.equal(recalculated.ok, true);
  assert.equal(recalculated.layout.adapted, false);
  assert.equal(recalculated.fields.find((field) => field.name === 'PRODUCT_DATE').text.pitch, 10);
});

test('an impossible combination reports overflow only after reaching the minimum pitch', () => {
  const api = loadPresetModule();
  const draft = readyDraft(api);
  draft.dataSourceMode = 'server-full';
  draft.base.widthMm = 12;
  draft.base.heightMm = 12;
  enableFields(draft, ['productDate']);

  const result = api.generateTemplatePreset(draft);
  assert.equal(result.ok, false);
  assert.equal(result.layout.adapted, true);
  assert.equal(result.layout.pitchByFieldName.PRODUCT_DATE, 1);
  assert.deepEqual(Array.from(result.layout.overflowFieldNames), ['PRODUCT_DATE']);
  assert.ok(result.issues.some((issue) => issue.code === 'layoutOverflow'));
});

test('rendered text bounds participate in adaptive fitting', () => {
  const api = loadPresetModule();
  api.getFieldRenderedBoundsInternal = (field) => {
    const value = field.data?.userEnterData || field.data?.defaultValue || field.calcData || '';
    const pitch = field.text?.pitch || 10;
    return { x: field.geom.x, y: field.geom.y, w: Math.max(1, String(value).length * pitch * 20), h: pitch * 40 };
  };
  const draft = readyDraft(api);
  draft.dataSourceMode = 'server-full';
  draft.base.widthMm = 20;
  draft.base.heightMm = 20;
  enableFields(draft, ['productDate', 'expirationDate', 'packingDate', 'rNum']);

  const result = api.generateTemplatePreset(draft);
  assert.equal(result.ok, true);
  assert.equal(result.layout.adapted, true);
  assert.ok(result.layout.fieldScale < 0.6);
  assertPrintedFieldsDoNotOverlap(result);
});
