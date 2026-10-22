const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

function loadPartyProfileApi() {
  const notifications = [];
  const context = {
    console,
    document: { getElementById: () => null, querySelectorAll: () => [], querySelector: () => null },
    window: { clearInterval: () => {}, setInterval: () => 0 },
    mmToInternal: (value) => Math.round(Number(value) * 100),
    internalToMm: (value) => Number(value) / 100,
    getCanvasInternalWidth: () => 5333,
    getCanvasInternalHeight: () => 7500,
    findHiddenFieldEditingPlacementInternal: (field, occupied) => ({ ...field.geom, x: 5500, y: occupied.length * 500 }),
    guessDataType: (type) => type === 'Barcode' ? 5 : 0,
    normalizeOrientation: (value) => [0, 90, 180, 270].includes(Number(value)) ? Number(value) : 0,
    t: (key) => key,
    openNotificationModal: (...args) => notifications.push(args),
    refreshFieldCanvasPreview: () => {},
  };
  context.globalThis = context;
  vm.createContext(context);
  for (const filename of ['00-core.js', 'clst/tag-data.js', 'clst/calculated-data.js', '30-rendering.js', '40-editor.js']) {
    vm.runInContext(fs.readFileSync(path.join(__dirname, '..', 'public/modules', filename), 'utf8'), context, { filename });
  }
  vm.runInContext('findHiddenFieldEditingPlacementInternal = (field, occupied) => ({ ...field.geom, x: 5500, y: occupied.length * 500 });', context);
  const api = vm.runInContext(`({ state, DM_COMPOSITIONS, DM_HELPER_SPECS, FIELD_CATALOG,
    getPartyCodeComposition, getDataMatrixFieldComposition, getDataMatrixComposition,
    createBaseField, createFixedTextField, createServerVariableField,
    applyDmProfile, applyDmComposition, applyDataMatrixProfileSettings, validateDmProfile,
    ensureDataMatrixCompositionCompatible, configureDataMatrixUserField,
    setEditableTextFieldValue, applyFixedTextEntryMode, synchronizeDataMatrixEditorState })`, context);
  return { ...api, notifications };
}

function createParty(api, withBoxCounter = false, legacy = false, name = 'Field00', gtinFieldName = 'GTIN2') {
  const profile = api.getPartyCodeComposition(withBoxCounter, gtinFieldName);
  const helpers = profile.requiredSegments.map((source) => {
    const spec = profile.helperSpecs[source];
    return (spec.mode === 'user' ? api.createServerVariableField : api.createFixedTextField)({
      name: legacy && source === 'C4' ? 'C5' : source,
      value: spec.defaultValue, maxChars: spec.maxChars, pitch: spec.pitch, printed: false,
    });
  });
  const barcode = api.createBaseField({ name, fldType: 'Barcode', barcode: { quietMargin: 0,
    dataMatrix: { symbolSize: '22X22', moduleSize: 0.42, segments: helpers.map((field, index) => ({
      index, srcField: field.name, defaultValue: field.data.defaultValue, dataType: 5,
    })) } } });
  api.state.fields = [barcode, ...helpers];
  api.state.fieldByName = new Map(api.state.fields.map((field) => [field.name, field]));
  api.synchronizeDataMatrixEditorState(barcode);
  return { barcode, helpers };
}

test('party recipes are independent of symbol dimensions and preserve standard marking constants', () => {
  const api = loadPartyProfileApi();
  assert.deepEqual(Array.from(api.getPartyCodeComposition().requiredSegments), ['C1', 'GTIN2', 'C3', 'PRODUCT_DATE', 'C2', 'SN']);
  assert.deepEqual(Array.from(api.getPartyCodeComposition(true).requiredSegments), ['C1', 'GTIN2', 'C3', 'PRODUCT_DATE', 'C2', 'SN', 'C4', 'BOX_COUNTER']);
  assert.equal(api.DM_COMPOSITIONS.short.fixedFields.C2, '21');
  assert.equal(api.DM_COMPOSITIONS.short.fixedFields.C3, '~d02993');
  assert.equal(api.DM_COMPOSITIONS.long.fixedFields.C4, '~d02992');
  assert.equal(api.DM_HELPER_SPECS.SN.maxChars, 6);
  assert.equal(api.getDataMatrixComposition('36X36'), 'long');
  const { barcode } = createParty(api);
  assert.equal(api.getDataMatrixFieldComposition(barcode, '36X36'), 'party');
});

for (const gtinFieldName of ['GTIN2', 'GTIN']) {
for (const withBoxCounter of [false, true]) {
  test(`changing party ${gtinFieldName} ${withBoxCounter ? 'with box counter' : 'without counter'} symbol keeps sources and user input limits`, () => {
    const api = loadPartyProfileApi();
    const { barcode, helpers } = createParty(api, withBoxCounter, false, 'Field00', gtinFieldName);
    const sourcesBefore = JSON.stringify(barcode.barcode.dataMatrix.segments);
    const helpersBefore = JSON.stringify(helpers);
    assert.equal(api.applyDataMatrixProfileSettings(barcode, '36X36'), true);
    assert.equal(barcode.barcode.dataMatrix.symbolSize, '36X36');
    assert.equal(JSON.stringify(barcode.barcode.dataMatrix.segments), sourcesBefore);
    assert.equal(JSON.stringify(helpers), helpersBefore);
    assert.equal(api.state.fieldByName.get('SN').data.maxChars, 12);
    assert.equal(api.state.fieldByName.get('PRODUCT_DATE').data.maxChars, 6);
    assert.equal(api.state.fieldByName.has('KRIPTO'), false);
    assert.equal(api.state.fieldByName.has(gtinFieldName === 'GTIN' ? 'GTIN2' : 'GTIN'), false);
    assert.deepEqual(Array.from(api.validateDmProfile(barcode, '36X36')), []);
    if (withBoxCounter) assert.equal(api.state.fieldByName.get('BOX_COUNTER').data.maxChars, 5);
  });
}
}

test('reapplying the party composition preserves the selected GTIN source and marking constants', () => {
  for (const withBoxCounter of [false, true]) {
    const api = loadPartyProfileApi();
    const { barcode } = createParty(api, withBoxCounter, false, 'Field00', 'GTIN');
    const order = Array.from(barcode.barcode.dataMatrix.segments, segment => segment.srcField);
    const composition = withBoxCounter ? 'party-box' : 'party';
    assert.equal(api.getDataMatrixFieldComposition(barcode), composition);
    assert.equal(api.applyDmComposition(barcode, composition), true);
    assert.deepEqual(Array.from(barcode.barcode.dataMatrix.segments, segment => segment.srcField), order);
    assert.equal(api.state.fieldByName.has('GTIN2'), false);
    assert.equal(api.state.fieldByName.get('GTIN').data.maxChars, 14);
    assert.deepEqual(Array.from(api.validateDmProfile(barcode, '22X22')), []);
    assert.equal(api.DM_COMPOSITIONS.short.fixedFields.C2, '21');
    assert.equal(api.DM_COMPOSITIONS.short.fixedFields.C3, '~d02993');
  }
});

test('a marking code with an added production date retains its marking composition', () => {
  const api = loadPartyProfileApi();
  for (const [symbolSize, composition] of [['22X22', 'short'], ['36X36', 'long']]) {
    const sources = [...api.DM_COMPOSITIONS[composition].requiredSegments, 'PRODUCT_DATE'];
    const barcode = api.createBaseField({ name: 'Field00', fldType: 'Barcode', barcode: { dataMatrix: {
      symbolSize, segments: sources.map(srcField => ({ srcField })),
    } } });
    assert.equal(api.getDataMatrixFieldComposition(barcode), composition);
  }
});

test('imported Party C5 reference is accepted and remains unchanged when applying a symbol profile', () => {
  const api = loadPartyProfileApi();
  const { barcode } = createParty(api, true, true, 'C4');
  const before = JSON.stringify(api.state.fields);
  assert.deepEqual(Array.from(api.validateDmProfile(barcode, '22X22')), []);
  assert.equal(api.applyDmProfile(barcode, '36X36'), true);
  barcode.barcode.dataMatrix.symbolSize = '22X22';
  assert.equal(JSON.stringify(api.state.fields), before);
  assert.equal(barcode.barcode.dataMatrix.segments[6].srcField, 'C5');
});

test('editing or reconfiguring party SN retains max 12 and does not convert BOX_COUNTER into CounterText', () => {
  const api = loadPartyProfileApi();
  const { barcode } = createParty(api, true);
  const serial = api.state.fieldByName.get('SN');
  api.setEditableTextFieldValue(serial, 'AB1234567890');
  api.applyFixedTextEntryMode(serial, 'user');
  api.configureDataMatrixUserField('SN', '000000', 6);
  assert.equal(serial.data.maxChars, 12);
  assert.equal(serial.data.userEnterData, 'AB1234567890');
  assert.equal(serial.data.fixedLen, true);
  assert.equal(api.state.fieldByName.get('BOX_COUNTER').fldType, 'FixedText');
  assert.equal(api.state.fieldByName.get('BOX_COUNTER').data.textEntryMode, 'user');
  assert.deepEqual(Array.from(api.validateDmProfile(barcode, '22X22')), []);
});

test('explicit party recipe creates missing helper fields with its own lengths and fixed values', () => {
  const api = loadPartyProfileApi();
  const barcode = api.createBaseField({ name: 'Field00', fldType: 'Barcode', barcode: { dataMatrix: {
    symbolSize: '22X22', segments: [], moduleSize: 0.42,
  } } });
  api.state.fields = [barcode];
  api.state.fieldByName = new Map([[barcode.name, barcode]]);
  assert.equal(api.applyDmComposition(barcode, 'party-box'), true);
  assert.equal(api.state.fieldByName.get('SN').data.maxChars, 12);
  assert.equal(api.state.fieldByName.get('GTIN2').data.maxChars, 14);
  assert.equal(api.state.fieldByName.get('PRODUCT_DATE').data.maxChars, 6);
  assert.equal(api.state.fieldByName.get('BOX_COUNTER').data.maxChars, 5);
  assert.equal(api.state.fieldByName.get('C4').data.maxChars, 2);
  assert.equal(api.state.fieldByName.get('C4').data.defaultValue, '21');
  assert.equal(api.state.fieldByName.get('C3').data.defaultValue, '11');
  assert.deepEqual(Array.from(api.validateDmProfile(barcode, '22X22')), []);
});

test('party variants may share helpers, but conflicting marking recipes are rejected before mutation', () => {
  const api = loadPartyProfileApi();
  const { barcode } = createParty(api, true);
  const normal = api.createBaseField({ name: 'Field01', fldType: 'Barcode', barcode: { dataMatrix: {
    symbolSize: '36X36', segments: barcode.barcode.dataMatrix.segments.slice(0, 6).map((segment) => ({ ...segment })),
  } } });
  api.state.fields.push(normal);
  api.state.fieldByName.set(normal.name, normal);
  assert.equal(api.ensureDataMatrixCompositionCompatible(barcode, 'party-box'), true);
  assert.equal(api.ensureDataMatrixCompositionCompatible(normal, 'party'), true);
  const before = JSON.stringify(api.state.fields);
  assert.equal(api.applyDmComposition(barcode, 'short', { notifyOnConflict: false }), false);
  assert.equal(JSON.stringify(api.state.fields), before);
  assert.equal(api.ensureDataMatrixCompositionCompatible(null, 'long', { notifyOnConflict: false }), false);
});
