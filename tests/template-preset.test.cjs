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
  const context = {
    console,
    EMPTY_TEMPLATE_PRINTER_MODELS: ['6530', '6420', '6330', '6320'],
    EMPTY_TEMPLATE_PRINT_MODES: ['Intermittent', 'Continuous'],
    DATA_MATRIX_SYMBOLS: [{ name: '22X22' }, { name: '32X32' }, { name: '36X36' }],
    DATA_MATRIX_SYMBOLS_BY_NAME: new Map([['22X22', {}], ['32X32', {}], ['36X36', {}]]),
    DM_COMPOSITIONS: {
      short: {
        requiredSegments: ['С1', 'GTIN', 'С2', 'SN', 'С3', 'KRIPTO'],
        fixedFields: { С1: '~101', С2: '21', С3: '~d02993' },
        disallowedFields: ['C4', 'KRIPTO2'],
      },
      long: {
        requiredSegments: ['С1', 'GTIN', 'С2', 'SN', 'С3', 'KRIPTO', 'C4', 'KRIPTO2'],
        fixedFields: { С1: '~101', С2: '21', С3: '~d02991', C4: '~d02992' },
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
    getStoredTextFieldValue: (field) => field?.data?.userEnterData || field?.data?.defaultValue || '',
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
      field.barcode.bcH = field.geom.h;
    },
    getComputedDateOffsetCurrent: ({ default: value }) => ({ ...value }),
    getEffectiveTextPitch: (field) => field.text?.pitch || 10,
    CLARISOFT_TEXT_FIELD_HEIGHT_MM_PER_PITCH: 0.4,
    buildEmptyTemplateXml: (_model, _mode, width, height) => `<empty width="${width}" height="${height}"/>`,
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
});

test('short DataMatrix has six ordered segments and no long-only fields', () => {
  const api = loadPresetModule();
  const result = api.generateTemplatePreset(readyDraft(api));
  assert.equal(result.ok, true);
  const dm = result.fields.find((field) => field.barcode);
  assert.deepEqual(Array.from(dm.barcode.dataMatrix.segments, (segment) => segment.srcField), ['С1', 'GTIN', 'С2', 'SN', 'С3', 'KRIPTO']);
  assert.equal(result.fields.some((field) => field.name === 'C4'), false);
  assert.equal(result.fields.some((field) => field.name === 'KRIPTO2'), false);
  assert.equal(result.fields.find((field) => field.name === 'SN').data.maxChars, 6);
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
  assert.deepEqual(Array.from(dm.barcode.dataMatrix.segments, (segment) => segment.srcField), ['С1', 'GTIN', 'С2', 'SN', 'С3', 'KRIPTO', 'C4', 'KRIPTO2']);
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

test('server-full mode keeps its existing six field names', () => {
  const api = loadPresetModule();
  const draft = readyDraft(api);
  draft.dataSourceMode = 'server-full';
  Object.values(draft.fields).forEach((field) => { field.enabled = true; });
  const result = api.generateTemplatePreset(draft);
  const printedNames = result.fields.filter((field) => field.printed && !field.barcode).map((field) => field.name);
  assert.deepEqual(Array.from(printedNames), ['PARTY', 'TEAM', 'PRODUCT_DATE', 'EXPIRATION_DATE', 'R_NUM', 'PACKING_DATE']);
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
