'use strict';

const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const test = require('node:test');
const vm = require('node:vm');

const projectRoot = path.resolve(__dirname, '..');
const helperPath = path.join(projectRoot, 'public/modules/clst/calculated-data.js');

function createRuntime(globals = {}) {
  const context = vm.createContext({ ...globals });
  vm.runInContext(fs.readFileSync(helperPath, 'utf8'), context, { filename: helperPath });
  return context;
}

function nativeField(definition) {
  const object = definition.objects[0];
  const properties = object.properties ?? {};
  return {
    name: definition.name,
    fldType: 'FixedText',
    data: {
      dataType: properties.ClearStyleDataType ?? 0,
      defaultValue: properties.DefaultData ?? '',
      staticAttr: object.static ? '1' : '0',
      hasVarText: object.type === 3,
      userEnterData: properties.VariableTextUserEnteredData,
      fixedLen: properties.FixedLength === 1,
      maxChars: properties.MaximumCharacters,
      padChar: properties.FixedLengthPadCharacter,
      padMode: properties.FixedLengthPadMode,
      srcField: properties.SourceFieldName,
      startChar: properties.StartCharacter,
      noOfChars: properties.NumberOfCharacters,
      selectMode: properties.SelectMode,
    },
  };
}

function utf16Text(units) {
  return String.fromCharCode(...(units ?? []));
}

test('prepared values match original COM ResolveField reference cases', () => {
  const runtime = createRuntime();
  const evidenceRoot = path.join(projectRoot, 'research/clst/implementation-2026-10-21');
  const inputs = JSON.parse(fs.readFileSync(path.join(evidenceRoot, 'native-resolved-inputs.json'), 'utf8'));
  const native = JSON.parse(fs.readFileSync(path.join(evidenceRoot, 'native-resolved-results.json'), 'utf8'));
  let verified = 0;
  for (const input of inputs) {
    const expected = native.cases.find((entry) => entry.name === input.name);
    assert.equal(expected?.status, 'ok', input.name);
    const fields = input.fields.map(nativeField);
    const snapshot = runtime.prepareCiffCalculatedData(fields, new Date('2026-10-21T12:34:56Z'));
    for (const field of fields) {
      const original = expected.fields.find((entry) => entry.name === field.name);
      assert.ok(original, `${input.name}/${field.name}`);
      assert.equal(snapshot.get(field), utf16Text(original.calculatedDataUnits), `${input.name}/${field.name}`);
      verified += 1;
    }
  }
  assert.equal(inputs.length, 10);
  assert.equal(verified, 15);
});

test('DataMatrix joins ordered resolved pieces and preserves original Defaults', () => {
  const runtime = createRuntime();
  const source = { name: 'SOURCE', fldType: 'FixedText', calcData: 'ABCDE', data: { defaultValue: 'ABCDE' } };
  const matrix = {
    name: 'DM', fldType: 'Barcode', calcData: 'old', barcode: { dataMatrix: { segments: [
      { index: 2, srcField: 'SOURCE', startChar: 1, noOfChars: 2, selectMode: 1, dataType: 5, defaultValue: 'old-suffix' },
      { index: 0, dataType: 0, staticAttr: '0', fixedLen: true, maxChars: 5, padChar: '0', padMode: 'Right', defaultValue: 'AB' },
      { index: 1, srcField: 'SOURCE', startChar: 1, noOfChars: 3, dataType: 5, defaultValue: 'old-partial' },
    ] } },
  };
  const snapshot = runtime.prepareCiffCalculatedData([matrix, source]);
  assert.equal(snapshot.get(matrix), '000ABBCDCD');
  assert.deepEqual(Array.from(runtime.resolveCiffDataMatrixSegmentValues(matrix, new Date(), {
    fieldByName: new Map([['SOURCE', source]]), calculatedData: snapshot,
  })), ['000AB', 'BCD', 'CD']);
  assert.equal(matrix.barcode.dataMatrix.segments[1].defaultValue, 'AB');
  assert.equal(matrix.calcData, 'old');
});

test('save snapshot freezes runtime data once across repeated DataMatrix sources', () => {
  let calls = 0;
  const runtime = createRuntime({ getDynamicFieldValue: (_field, now) => { calls += 1; return `T${now.getUTCMinutes()}`; } });
  const clock = { name: 'CLOCK', fldType: 'TimeText', calcData: 'old', data: { dataType: 1, defaultValue: 'HH:mm' } };
  const matrix = { name: 'DM', fldType: 'Barcode', barcode: { dataMatrix: { segments: [
    { index: 0, srcField: 'CLOCK', dataType: 5 }, { index: 1, srcField: 'CLOCK', dataType: 5 },
  ] } } };
  const snapshot = runtime.prepareCiffCalculatedData([matrix, clock], new Date('2026-10-21T12:34:00Z'));
  assert.equal(calls, 1);
  assert.equal(snapshot.get(matrix), 'T34T34');
  assert.equal(snapshot.get(clock), 'T34');
  assert.equal(runtime.resolveCiffCalculatedData(clock, new Date('2026-10-21T12:35:00Z'), { calculatedData: snapshot }), 'T34');
  assert.equal(calls, 1);
  assert.equal(clock.calcData, 'old');
});

test('direct date/time DataMatrix segments share prepared values with later validation', () => {
  let calls = 0;
  const runtime = createRuntime({ getDynamicFieldValue: (field, now) => {
    calls += 1;
    return `${field.fldType}:${now.getUTCMinutes()}:${field.data.offsetRef ?? ''}`;
  } });
  const matrix = { name: 'DM', fldType: 'Barcode', calcData: 'old', barcode: { dataMatrix: { segments: [
    { index: 0, dataType: 1, defaultValue: "HH':'mm" },
    { index: 1, dataType: 3, defaultValue: "dd'/'MM", offsetRef: 'EXPIRY' },
  ] } } };
  const snapshot = runtime.prepareCiffCalculatedData([matrix], new Date('2026-10-21T12:34:00Z'));
  assert.equal(snapshot.get(matrix), 'TimeText:34:OffsetDateText:34:EXPIRY');
  assert.equal(calls, 2);
  assert.deepEqual(Array.from(runtime.resolveCiffDataMatrixSegmentValues(matrix, new Date('2026-10-21T12:35:00Z'), {
    calculatedData: snapshot,
  })), ['TimeText:34:', 'OffsetDateText:34:EXPIRY']);
  assert.equal(calls, 2);
});

test('external and unsupported fields preserve raw stored values including empty strings', () => {
  const runtime = createRuntime({ getDynamicFieldValue: () => { throw new Error('External data must not be reformatted.'); } });
  const external = { name: 'DB', fldType: 'DateText', calcData: '', data: { dataType: 6, defaultValue: 'format', srcData: {} } };
  const graphic = { name: 'GFX', fldType: 'StaticGraphic', calcData: 'RAW\u0001VALUE' };
  const barcode = { name: 'EAN', fldType: 'Barcode', calcData: '1234567890123' };
  const snapshot = runtime.prepareCiffCalculatedData([external, graphic, barcode]);
  assert.equal(snapshot.get(external), '');
  assert.equal(snapshot.get(graphic), 'RAW\u0001VALUE');
  assert.equal(snapshot.get(barcode), '1234567890123');
  assert.equal(runtime.resolveCiffCalculatedData({ fldType: 'PluginField', data: { defaultValue: 'CONFIG' } }), null);
});

test('unsupported native calendars and mismatched temporal data retain the stored calculation', () => {
  const runtime = createRuntime({ getDynamicFieldValue: () => { throw new Error('Unsupported native format must remain stored.'); } });
  const cases = [
    { fldType: 'DateText', calcData: '109', data: { dataType: 2, defaultValue: "cl:jj''" } },
    { fldType: 'OffsetDateText', calcData: '19 APR', data: { dataType: 3, defaultValue: "dd' 'cl:MMM" } },
    { fldType: 'TimeText', calcData: 'UseBy', data: { dataType: 0, defaultValue: 'UseBy' } },
    { fldType: 'DateText', calcData: 'SAVED', data: { dataType: 2, defaultValue: 'dd.MM.yy', calendar: 'CAL_HEBREW' } },
    { fldType: 'DateText', calcData: 'STORED', data: { dataType: 2, defaultValue: 'dd MMM', locale: 'FR-FR' } },
  ];
  const values = runtime.prepareCiffCalculatedData(cases);
  assert.deepEqual(cases.map((field) => values.get(field)), ['109', '19 APR', 'UseBy', 'SAVED', 'STORED']);
});

test('explicit prepared values retain priority and enter the returned snapshot', () => {
  const runtime = createRuntime();
  const field = { name: 'X', fldType: 'FixedText', calculatedData: 'prepared', calcData: 'old', data: { defaultValue: 'default' } };
  assert.equal(runtime.prepareCiffCalculatedData([field]).get(field), 'prepared');
  assert.equal(runtime.prepareCiffCalculatedData([field], new Date(), { calculatedData: new Map([[field, '']]) }).get(field), '');
});

test('source selection counts UTF16 units and safely handles empty or out-of-range selection', () => {
  const runtime = createRuntime();
  const halfSurrogate = runtime.selectCiffSourceFieldData('A\uD83D\uDE00B', { startChar: 1, noOfChars: 1 });
  assert.equal(halfSurrogate.length, 1);
  assert.equal(halfSurrogate.charCodeAt(0), 0xD83D);
  assert.equal(runtime.selectCiffSourceFieldData('ABCDE', { startChar: 9, noOfChars: 2 }), '');
  assert.equal(runtime.selectCiffSourceFieldData('ABCDE', { startChar: 1, noOfChars: 99 }), 'BCDE');
});

test('unavailable source retains saved segment Default without inventing runtime text', () => {
  const runtime = createRuntime();
  const matrix = { fldType: 'Barcode', barcode: { dataMatrix: { segments: [
    { srcField: 'MISSING', dataType: 5, defaultValue: 'SAVED' },
  ] } } };
  assert.equal(runtime.resolveCiffCalculatedData(matrix), 'SAVED');
  assert.equal(runtime.resolveCiffDataMatrixSegmentValues(matrix, new Date(), { strictSource: true }), null);
});

test('native XML filtering retains TAB LF CR while raw ClSt snapshot retains controls', () => {
  const runtime = createRuntime();
  const value = 'AB\u0001C\u001DD\tE\nF\rG\u007FH';
  const field = { name: 'RAW', fldType: 'StaticGraphic', calcData: value };
  const snapshot = runtime.prepareCiffCalculatedData([field]);
  assert.equal(snapshot.get(field), value);
  assert.equal(runtime.filterCiffCalculatedDataForXml(snapshot.get(field)), 'ABCD\tE\nF\rG\u007FH');
  assert.equal(runtime.filterCiffCalculatedDataForXml('A\0B'), 'AB');
});

test('model values use native NUL-terminated property semantics while explicit prepared data remains raw', () => {
  const runtime = createRuntime();
  const field = { name: 'RAW', fldType: 'StaticGraphic', calcData: 'AB\0CD' };
  assert.equal(runtime.prepareCiffCalculatedData([field]).get(field), 'AB');
  assert.equal(runtime.resolveCiffCalculatedData({ calculatedData: 'AB\0CD' }), 'AB\0CD');
  const matrix = { name: 'DM', fldType: 'Barcode', barcode: { dataMatrix: { segments: [
    { index: 0, dataType: 0, defaultValue: 'AB\0CD' }, { index: 1, dataType: 0, defaultValue: 'EF' },
  ] } } };
  assert.equal(runtime.prepareCiffCalculatedData([matrix]).get(matrix), 'ABEF');
  assert.equal(runtime.padCiffFixedLengthData('AB', { staticAttr: '0', fixedLen: true, maxChars: 5, padChar: '' }), 'AB');
  assert.equal(runtime.padCiffFixedLengthData('AB', { staticAttr: '0', fixedLen: true, maxChars: 5 }), 'AB   ');
});
