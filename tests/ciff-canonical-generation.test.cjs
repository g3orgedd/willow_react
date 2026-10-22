const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

const CYRILLIC_C1 = '\u04211';
const CYRILLIC_C2 = '\u04212';
const LATIN_C1 = 'C1';
const LATIN_C2 = 'C2';
const LATIN_C3 = 'C3';
const CYRILLIC_C3 = '\u04213';
const DATA_MATRIX_CLSID = '{7A4AA4CF-F5CD-11D4-8DAE-0050DAFE8A9F}';

function loadCanonicalCiffApi() {
  const context = {
    console,
    glyphSystemTickCount: () => 0,
    window: {
      setInterval: () => 0,
      clearInterval: () => {},
      setTimeout: (callback) => callback(),
    },
    document: {
      getElementById: (id) => (['btnUndo', 'btnRedo'].includes(id) ? { disabled: false } : null),
      querySelectorAll: () => [],
      querySelector: () => null,
      createElement: () => ({
        appendChild: () => {},
        addEventListener: () => {},
        classList: { add: () => {}, remove: () => {}, toggle: () => {} },
        dataset: {},
        querySelector: () => null,
        querySelectorAll: () => [],
        setAttribute: () => {},
        style: {},
      }),
      body: { appendChild: () => {} },
    },
    appLogger: {
      action: () => {},
      file: () => {},
      log: () => {},
      state: () => {},
    },
    t: (key) => key,
    openNotificationModal: () => {},
    mmToInternal: (value) => Math.round(Number(value) * 100),
    mmToPx: (value) => Number(value) * 12,
    pxToMm: (value) => Number(value) / 12,
    internalToMm: (value) => Number(value) / 100,
    getCanvasInternalWidth: () => 5333,
    getCanvasInternalHeight: () => 7500,
    constrainFieldPositionInternal: (field, x, y) => ({ x, y }),
    constrainCurrentFieldPositionsInternal: () => {},
    findHiddenFieldEditingPlacementInternal: (field, occupiedFields = []) => ({
      ...field.geom,
      x: 5500,
      y: 500 + occupiedFields.filter((item) => item && !item.printed).length * 500,
    }),
    setSelectedNames: () => {},
    renderAll: () => {},
    renderObjects: () => {},
    renderUI: () => {},
    refreshCanvasPreviews: () => {},
    refreshFieldCanvasPreview: () => {},
    updateUndoRedoButtons: () => {},
    getSelectedNames: () => [],
    markActiveTemplateTabDirty: () => {},
    normalizeTimeFormat: (value) => String(value ?? ''),
  };
  context.globalThis = context;
  vm.createContext(context);

  for (const relativePath of [
    'public/modules/00-core.js',
    'public/modules/01-ciff-compatibility.js',
    'public/modules/clst/encryption.js',
    'public/modules/clst/tag-data.js',
    'public/modules/clst/calculated-data.js',
    'public/modules/clst/version-info.js',
    'public/modules/30-rendering.js',
    'public/modules/40-editor.js',
    'public/modules/45-template-preset.js',
    'public/modules/60-history-save.js',
  ]) {
    const filename = path.join(__dirname, '..', relativePath);
    vm.runInContext(fs.readFileSync(filename, 'utf8'), context, { filename });
  }
  vm.runInContext('renderAll = () => {};', context);

  return vm.runInContext(`({
    DM_COMPOSITIONS,
    DM_HELPER_NAMES,
    DM_LEGACY_HELPER_NAMES,
    DM_HELPER_SPECS,
    buildDataMatrixCalcData,
    synchronizeDataMatrixDerivedState,
    synchronizeAllDataMatrixDerivedState,
    validateDataMatrixDerivedState,
    validateDataMatrixSourceConsistency: typeof validateDataMatrixSourceConsistency === "function"
      ? validateDataMatrixSourceConsistency
      : null,
    getNextClarisoftFieldName,
    buildFieldXmlOneLine,
    patchFieldsLosslessV2,
    restoreFromSnapshot,
    inferRestoredDataMatrixStructureDirty,
    createDataMatrixHelperFields,
    createDataMatrixField,
    createBaseField,
    createFixedTextField,
    createServerVariableField,
    createCurrentDateField,
    createOffsetDateField,
    ensureCalculatedDateOffset,
    createCurrentTimeField,
    getEffectiveTextPitch,
    calculateDataMatrixBcH,
    updateDataMatrixBcHFromSettings,
    applyDataMatrixProfileSettings,
    getDataMatrixEffectiveSymbolInfo,
    getDataMatrixResizeMetrics,
    syncDataMatrixGeomToModuleSize,
    synchronizeDataMatrixEditorState,
    setEditableTextFieldValue,
    setFieldPositionInternal,
    snapshotState,
    pushHistory,
    undo,
    redo,
    history,
    applyDmComposition,
    state
  })`, context);
}

function createTextSource(name, value, userEntered = false, maxChars = null) {
  return {
    sourceName: null,
    name,
    fldType: 'FixedText',
    printed: false,
    geom: { x: 5500, y: 500, w: 1000, h: 392 },
    ln: 1,
    orientation: 0,
    calcData: value,
    data: {
      dataType: 0,
      defaultValue: value,
      maxChars,
      fixedLen: false,
      staticAttr: userEntered ? '0' : null,
      parseAttr: null,
      hasVarText: userEntered,
      textEntryMode: userEntered ? 'user' : 'fixed',
      userEnterData: userEntered ? value : '',
      mask: '',
      offsetRef: null,
      counter: {},
    },
    text: { pitch: 10, xMag: null },
    barcode: null,
    _konva: null,
  };
}

function createShortProfileModel(api) {
  const sourceFields = [
    createTextSource(LATIN_C1, '~101', false, 4),
    createTextSource('GTIN', '0'.repeat(14), true, 14),
    createTextSource(LATIN_C2, '21', false, 2),
    createTextSource('SN', '0'.repeat(13), true, 13),
    createTextSource(LATIN_C3, '~d02993', false, 7),
    createTextSource('KRIPTO', '0'.repeat(4), true, 4),
  ];
  const fieldByName = new Map(sourceFields.map((field) => [field.name, field]));
  const segments = sourceFields.map((field, index) => ({
    index,
    srcField: field.name,
    defaultValue: index === 4 ? '~d02991' : 'stale',
    dataType: 5,
  }));
  const dmField = {
    sourceName: null,
    name: 'Field00',
    fldType: 'Barcode',
    printed: true,
    geom: { x: 500, y: 500, w: 1100, h: 1100 },
    ln: 1,
    orientation: 0,
    calcData: '',
    data: {
      dataType: 5,
      defaultValue: '',
      maxChars: null,
      fixedLen: false,
      staticAttr: null,
      parseAttr: null,
      hasVarText: false,
      textEntryMode: null,
      userEnterData: '',
      mask: '',
      offsetRef: null,
      counter: {},
    },
    text: null,
    barcode: {
      clsid: DATA_MATRIX_CLSID,
      quietMargin: 0,
      bcH: 2540,
      dataMatrix: { moduleSize: 0.5, symbolSize: '22X22', segments },
    },
    _konva: null,
  };
  return { dmField, sourceFields, fieldByName };
}

function directChildTagNames(xml) {
  const firstClose = xml.indexOf('>');
  const lastOpen = xml.lastIndexOf('</');
  const inner = xml.slice(firstClose + 1, lastOpen);
  const names = [];
  const tags = /<\/?([A-Za-z][A-Za-z0-9]*)\b[^>]*>/g;
  let depth = 0;
  let match;
  while ((match = tags.exec(inner))) {
    const token = match[0];
    const closing = token.startsWith('</');
    const selfClosing = token.endsWith('/>');
    if (closing) {
      depth -= 1;
      continue;
    }
    if (depth === 0) names.push(match[1]);
    if (!selfClosing) depth += 1;
  }
  return names;
}

function wrapFields(fieldsXml) {
  return `<ImageDesign Version="23"><SubImage ImageReference="1"><SubHeader><ImageWidth>4000</ImageWidth><ImageHeight>3000</ImageHeight><MaxImageWidth>5333</MaxImageWidth><MaxImageHeight>7500</MaxImageHeight><XRes>0.120000</XRes><CurrentOrientation>0</CurrentOrientation></SubHeader>${fieldsXml}</SubImage></ImageDesign>`;
}

function importedDataMatrixField(structureDirty) {
  return {
    sourceName: 'ImportedDM',
    name: 'ImportedDM',
    fldType: 'Barcode',
    printed: true,
    geom: { x: 100, y: 200, w: 1100, h: 1100 },
    ln: 1,
    orientation: 0,
    calcData: 'new-value',
    data: { dataType: 5, defaultValue: '', counter: {} },
    text: null,
    barcode: {
      clsid: DATA_MATRIX_CLSID,
      quietMargin: 0,
      bcH: 2540,
      dataMatrix: {
        moduleSize: 0.5,
        symbolSize: '22X22',
        structureDirty,
        segments: [{ index: 0, dataType: 5, defaultValue: 'new-value', srcField: 'LEGACY_SOURCE' }],
      },
    },
    _konva: null,
  };
}

function importedDataMatrixBlock() {
  return '<Field Name="ImportedDM"><FldType>Barcode</FldType><CLSID>{7A4AA4CF-F5CD-11D4-8DAE-0050DAFE8A9F}</CLSID><X>100</X><Y>200</Y><W>1100</W><H>1100</H><Ln>1</Ln><CalcData><![CDATA[old-value]]></CalcData><LoggedField></LoggedField><Data><Object LegacyFlag="keep" Reference="legacy"><DataType>5</DataType><VendorBefore Code="opaque"/><Default><![CDATA[old-value]]></Default><VendorAfter>opaque</VendorAfter><SrcField SrcFieldName="LEGACY_SOURCE"/></Object></Data><Barcode><BcH>2540</BcH><HR><HRFont/></HR><QuietMargin>0</QuietMargin><DataMatrix><ModuleSize>50</ModuleSize><SymbolSize>22X22</SymbolSize></DataMatrix></Barcode></Field>';
}

function getFieldBlock(xml, name) {
  const escapedName = String(name).replace(/[.*+?^${}()|[\]\\]/g, '\\$&');
  return xml.match(new RegExp(`<Field Name="${escapedName}">[\\s\\S]*?<\\/Field>`))?.[0] ?? null;
}

test('short DM composition uses Latin C1, C2 and C3 only', () => {
  const api = loadCanonicalCiffApi();
  const names = Array.from(api.DM_COMPOSITIONS.short.requiredSegments);

  assert.deepEqual(names, [LATIN_C1, 'GTIN', LATIN_C2, 'SN', LATIN_C3, 'KRIPTO']);
  assert.deepEqual([...names[0]].map((char) => char.codePointAt(0)), [0x0043, 0x0031]);
  assert.deepEqual([...names[2]].map((char) => char.codePointAt(0)), [0x0043, 0x0032]);
  assert.deepEqual([...names[4]].map((char) => char.codePointAt(0)), [0x0043, 0x0033]);
  for (const legacyName of [CYRILLIC_C1, CYRILLIC_C2, CYRILLIC_C3]) {
    assert.equal(Object.values(api.DM_HELPER_NAMES).includes(legacyName), false);
  }
});

test('derived DM synchronization updates every segment Default and aggregate CalcData', () => {
  const api = loadCanonicalCiffApi();
  const { dmField, sourceFields, fieldByName } = createShortProfileModel(api);
  const expectedValues = sourceFields.map((field) => field.data.defaultValue);
  const expectedCalcData = '~10100000000000000210000000000000~d029930000';

  assert.equal(expectedValues.join(''), expectedCalcData);
  assert.equal(api.buildDataMatrixCalcData(dmField, fieldByName), expectedCalcData);
  assert.equal(api.synchronizeDataMatrixDerivedState(dmField, fieldByName), true);
  assert.deepEqual(
    Array.from(dmField.barcode.dataMatrix.segments, (segment) => segment.defaultValue),
    expectedValues,
  );
  assert.equal(dmField.calcData, expectedCalcData);
  assert.deepEqual(Array.from(api.validateDataMatrixDerivedState(dmField, fieldByName)), []);
});

test('all-DM synchronization updates dependent barcodes after a helper edit', () => {
  const api = loadCanonicalCiffApi();
  const first = createShortProfileModel(api);
  const second = createShortProfileModel(api);
  second.dmField.name = 'Field01';
  first.fieldByName.get('SN').data.userEnterData = 'ABC123';
  first.fieldByName.get('SN').data.defaultValue = 'ABC123';
  first.fieldByName.get('SN').calcData = 'ABC123';

  api.synchronizeAllDataMatrixDerivedState(
    [...first.sourceFields, first.dmField, second.dmField],
    first.fieldByName,
  );

  for (const dmField of [first.dmField, second.dmField]) {
    assert.equal(dmField.barcode.dataMatrix.segments[3].defaultValue, 'ABC123');
    assert.equal(dmField.calcData.includes('ABC123'), true);
  }
});

test('derived-state validator reports stale segment defaults and stale CalcData', () => {
  const api = loadCanonicalCiffApi();
  const { dmField, fieldByName } = createShortProfileModel(api);
  api.synchronizeDataMatrixDerivedState(dmField, fieldByName);

  dmField.barcode.dataMatrix.segments[4].defaultValue = '~d02991';
  dmField.calcData = 'stale';
  const issues = Array.from(api.validateDataMatrixDerivedState(dmField, fieldByName));

  assert.ok(issues.length >= 2, issues);
  assert.ok(issues.some((issue) => issue.code === 'segment-default' && issue.sourceName === LATIN_C3), issues);
  assert.ok(issues.some((issue) => issue.code === 'calc-data'), issues);
});

test('mixed short and long DataMatrix compositions are rejected before shared helpers mutate', () => {
  const api = loadCanonicalCiffApi();
  const { dmField: shortDm, sourceFields } = createShortProfileModel(api);
  shortDm.barcode.dataMatrix.symbolSize = '22X22';
  api.synchronizeDataMatrixDerivedState(shortDm, new Map(sourceFields.map((field) => [field.name, field])));

  api.state.fields = [shortDm, ...sourceFields];
  api.state.fieldByName = new Map(api.state.fields.map((field) => [field.name, field]));

  const longCandidate = {
    ...shortDm,
    name: 'Field01',
    barcode: {
      ...shortDm.barcode,
      dataMatrix: {
        ...shortDm.barcode.dataMatrix,
        symbolSize: '36X36',
        segments: []
      }
    }
  };
  const c3Before = api.state.fieldByName.get(LATIN_C3).data.defaultValue;
  const namesBefore = api.state.fields.map((field) => field.name);

  assert.equal(api.applyDmComposition(longCandidate, 'long', { notifyOnConflict: false }), false);
  assert.equal(api.state.fieldByName.get(LATIN_C3).data.defaultValue, c3Before);
  assert.deepEqual(api.state.fields.map((field) => field.name), namesBefore);
  assert.equal(api.state.fieldByName.has('C4'), false);
  assert.deepEqual(longCandidate.barcode.dataMatrix.segments, []);
});

test('Clarisoft field allocator shares one FieldNN namespace and fills the first gap', () => {
  const api = loadCanonicalCiffApi();

  assert.equal(api.getNextClarisoftFieldName([]), 'Field00');
  assert.equal(api.getNextClarisoftFieldName(['Field00', 'Field02', 'FieldDM00']), 'Field01');
  assert.equal(api.getNextClarisoftFieldName(['Field00', 'Field01', 'Field02']), 'Field03');
});

test('explicit profile application migrates legacy Cyrillic C1, C2 and C3 without a load-time rename', () => {
  const api = loadCanonicalCiffApi();
  const { dmField, sourceFields } = createShortProfileModel(api);
  const aliases = new Map([
    [LATIN_C1, CYRILLIC_C1],
    [LATIN_C2, CYRILLIC_C2],
    [LATIN_C3, CYRILLIC_C3],
  ]);
  sourceFields.forEach((field) => {
    const legacyName = aliases.get(field.name);
    if (!legacyName) return;
    field.name = legacyName;
    field.sourceName = legacyName;
  });
  dmField.sourceName = 'FieldDM00';
  dmField.barcode.dataMatrix.structureDirty = false;
  dmField.barcode.dataMatrix.segments.forEach((segment) => {
    segment.srcField = aliases.get(segment.srcField) ?? segment.srcField;
  });
  const importedSibling = JSON.parse(JSON.stringify(dmField));
  importedSibling.name = 'ImportedSibling';
  importedSibling.sourceName = 'ImportedSibling';
  importedSibling.barcode.dataMatrix.structureDirty = false;
  api.state.fields = [...sourceFields, dmField, importedSibling];
  api.state.fieldByName = new Map(api.state.fields.map((field) => [field.name, field]));

  for (const canonicalName of aliases.keys()) assert.equal(api.state.fieldByName.has(canonicalName), false);
  assert.equal(api.applyDmComposition(dmField, 'short'), true);
  for (const [canonicalName, legacyName] of aliases) {
    const field = sourceFields.find((candidate) => candidate.name === canonicalName);
    assert.ok(field, canonicalName);
    assert.equal(field.sourceName, legacyName, 'the original XML identity remains available for lossless patching');
    assert.equal(api.state.fieldByName.has(legacyName), false);
    assert.equal(api.state.fieldByName.get(canonicalName), field);
  }
  assert.deepEqual(
    Array.from(dmField.barcode.dataMatrix.segments, (segment) => segment.srcField),
    [LATIN_C1, 'GTIN', LATIN_C2, 'SN', LATIN_C3, 'KRIPTO'],
  );
  assert.equal(dmField.barcode.dataMatrix.structureDirty, true);
  assert.deepEqual(
    Array.from(importedSibling.barcode.dataMatrix.segments, (segment) => segment.srcField),
    [LATIN_C1, 'GTIN', LATIN_C2, 'SN', LATIN_C3, 'KRIPTO'],
  );
  assert.equal(importedSibling.barcode.dataMatrix.structureDirty, false, 'a SrcField rename stays non-invasive for sibling imports');
});

test('new Barcode serializer emits the exact Clarisoft direct-child order', () => {
  const api = loadCanonicalCiffApi();
  const { dmField, sourceFields, fieldByName } = createShortProfileModel(api);
  api.state.fields = [...sourceFields, dmField];
  api.state.fieldByName = fieldByName;
  api.synchronizeDataMatrixDerivedState(dmField, fieldByName);

  const xml = api.buildFieldXmlOneLine(dmField);
  assert.deepEqual(directChildTagNames(xml), [
    'FldType', 'CLSID', 'X', 'Y', 'W', 'H', 'Ln', 'CalcData', 'Data', 'Barcode',
  ]);
  assert.ok(xml.includes(`<CLSID>${DATA_MATRIX_CLSID}</CLSID>`));
  assert.match(xml, /<CalcData><!\[CDATA\[~10100000000000000210000000000000~d029930000\]\]><\/CalcData>/);
});

test('canonical helper models emit exact C1-C4 MaxNoOfChars and omit default XMag', () => {
  const api = loadCanonicalCiffApi();
  const helpers = Array.from(api.createDataMatrixHelperFields({
    symbolSize: '36X36',
    snValue: '0'.repeat(6),
    moduleSize: 0.5,
  }));
  const expectedNames = [LATIN_C1, 'GTIN', LATIN_C2, 'SN', LATIN_C3, 'KRIPTO', 'C4', 'KRIPTO2'];
  const expectedMaxByName = new Map([
    [LATIN_C1, 4],
    ['GTIN', 14],
    [LATIN_C2, 2],
    ['SN', 6],
    [LATIN_C3, 7],
    ['KRIPTO', 4],
    ['C4', 7],
    ['KRIPTO2', 44],
  ]);
  const fieldsByName = new Map(helpers.map((field) => [field.name, field]));
  const userEnteredNames = new Set(['GTIN', 'SN', 'KRIPTO', 'KRIPTO2']);

  assert.deepEqual(helpers.map((field) => field.name), expectedNames);
  for (const field of helpers) {
    assert.equal(field.text?.xMag ?? null, null, field.name);
    const xml = api.buildFieldXmlOneLine(field);
    assert.doesNotMatch(xml, /<XMag>/, field.name);
    const expectedMax = expectedMaxByName.get(field.name) ?? null;
    assert.equal(field.data.maxChars ?? null, expectedMax, field.name);
    if (expectedMax == null) {
      assert.doesNotMatch(xml, /<MaxNoOfChars>/, field.name);
    } else {
      assert.match(xml, new RegExp(`<MaxNoOfChars>${expectedMax}<\\/MaxNoOfChars>`), field.name);
      if (userEnteredNames.has(field.name)) assert.match(xml, /<\/Default><FixedLen\/>/, field.name);
      else assert.doesNotMatch(xml, /<FixedLen\/>/, field.name);
      assert.equal(field.data.fixedLen, userEnteredNames.has(field.name), field.name);
    }
  }
  for (const [name, maxChars] of expectedMaxByName) {
    assert.equal(fieldsByName.get(name).data.maxChars, maxChars);
  }
  const staleC1 = fieldsByName.get(LATIN_C1);
  staleC1.data.maxChars = null;
  assert.doesNotMatch(api.buildFieldXmlOneLine(staleC1), /<MaxNoOfChars>/);
  assert.equal(staleC1.data.maxChars, null);
});

test('new text, date, time, offset and counter fields use ClariSoft optional-tag signatures', () => {
  const api = loadCanonicalCiffApi();
  const fields = [
    {
      label: 'fixed',
      field: api.createFixedTextField({ name: 'Fixed', value: 'ABC' }),
      objectAttributes: /<Object Reference="">/,
      objectChildren: ['DataType', 'Default'],
      parse: false,
    },
    {
      label: 'user-entered',
      field: api.createServerVariableField({ name: 'User', value: '000' }),
      objectAttributes: /<Object Static="0" Reference="">/,
      objectChildren: ['DataType', 'Default', 'VarText'],
      parse: false,
    },
    {
      label: 'date',
      field: api.createCurrentDateField({ name: 'Date', format: 'dd\/MM\/yy', separator: '.' }),
      objectAttributes: /<Object Static="0" Parse="1" Reference="">/,
      objectChildren: ['DataType', 'Default'],
      parse: true,
    },
    {
      label: 'offset date',
      field: api.createOffsetDateField({ name: 'Offset', format: 'dd\/MM\/yy', separator: '.' }, 'offset0'),
      objectAttributes: /<Object Static="0" Parse="1" Reference="">/,
      objectChildren: ['DataType', 'Default', 'OffsetDate'],
      parse: true,
    },
    {
      label: 'time',
      field: api.createCurrentTimeField({ name: 'Time', format: 'HH:mm', separator: ':' }),
      objectAttributes: /<Object Static="0" Parse="1" Reference="">/,
      objectChildren: ['DataType', 'Default'],
      parse: true,
    },
    {
      label: 'counter',
      field: api.createBaseField({ name: 'Counter', fldType: 'CounterText' }),
      objectAttributes: /<Object Static="0" Reference="">/,
      objectChildren: ['DataType', 'Default', 'CounterText'],
      parse: false,
    },
  ];

  fields.forEach(({ label, field, objectAttributes, objectChildren, parse }) => {
    const xml = api.buildFieldXmlOneLine(field);
    assert.deepEqual(
      directChildTagNames(xml),
      ['FldType', 'X', 'Y', 'W', 'H', 'CalcData', 'Data', 'Text'],
      label,
    );
    const objectXml = xml.match(/<Object\b[^>]*>[\s\S]*?<\/Object>/)?.[0] ?? '';
    assert.match(objectXml, objectAttributes, label);
    assert.deepEqual(directChildTagNames(objectXml), objectChildren, label);
    assert.equal(/\sParse="1"/.test(objectXml), parse, label);
    assert.doesNotMatch(objectXml, /<FixedLen\/>/, label);
    assert.doesNotMatch(xml, /<XMag>/, label);
  });
});

test('generic field factories omit native default Ln zero and retain nonzero lines', () => {
  const api = loadCanonicalCiffApi();
  for (const ln of [undefined, null, 0, 1]) {
    const field = api.createFixedTextField({ name: 'ConfiguredLines', value: 'ABC', ln });
    const xml = api.buildFieldXmlOneLine(field);
    assert.equal(field.ln, ln ?? null);
    if (ln == null || ln === 0) {
      assert.doesNotMatch(xml, /<Ln\b/);
    } else {
      assert.match(xml, new RegExp(`<H>[^<]+<\\/H><Ln>${ln}<\\/Ln><CalcData>`));
    }
  }
});

test('external FixedText factory preserves explicit attributes and source configuration', () => {
  const api = loadCanonicalCiffApi();
  const field = api.createFixedTextField({
    name: 'Description', dataType: 6, value: 'Description??????????????',
    staticAttr: '0', parseAttr: null, referenceAttr: 'ExternalSource', fixedLen: true,
    srcData: { connStr: 'Table containing Index Fields', srcSQL: 'SELECT [Description]\nFROM [JOBS]' },
  });
  const xml = api.buildFieldXmlOneLine(field);
  const objectXml = xml.match(/<Object\b[^>]*>[\s\S]*?<\/Object>/)?.[0] ?? '';
  assert.equal(field.fldType, 'FixedText');
  assert.equal(field.data.dataType, 6);
  assert.match(objectXml, /<Object Static="0" Reference="ExternalSource">/);
  assert.deepEqual(directChildTagNames(objectXml), ['DataType', 'Default', 'FixedLen', 'SrcData']);
  assert.match(objectXml, /<ConnStr><!\[CDATA\[Table containing Index Fields\]\]><\/ConnStr>/);
  assert.match(objectXml, /<SrcSQL><!\[CDATA\[SELECT \[Description\]\nFROM \[JOBS\]\]\]><\/SrcSQL>/);
  assert.doesNotMatch(objectXml, /\sParse=|<OffsetDate\b|<VarText\b/);
  assert.doesNotMatch(xml, /<Ln\b/);
});

test('new Object attributes preserve empty Reference and omit native Parse zero', () => {
  const api = loadCanonicalCiffApi();
  const omitted = api.createBaseField({
    name: 'ExplicitAbsence', fldType: 'DateText', staticAttr: null, parseAttr: null, referenceAttr: null,
  });
  assert.match(api.buildFieldXmlOneLine(omitted), /<Object><DataType>2<\/DataType>/);
  const explicit = api.createFixedTextField({
    name: 'ExplicitValues', staticAttr: '0', parseAttr: '0', referenceAttr: '',
  });
  assert.match(api.buildFieldXmlOneLine(explicit), /<Object Static="0" Reference="">/);
});

test('date editor preserves an existing named offset regardless of Header array order', () => {
  const api = loadCanonicalCiffApi();
  const useBy = { name: 'UseBy', default: { y: 0, m: 0, d: 30 } };
  const sellBy = { name: 'SellBy', default: { y: 0, m: 0, d: 7 } };
  for (const offsets of [[useBy, sellBy], [sellBy, useBy]]) {
    api.state.dateOffsets = offsets;
    api.state.dateOffsetsDirty = false;
    const field = api.createOffsetDateField({ name: 'Expiry', format: 'dd/MM/yy' }, 'SellBy');
    assert.equal(api.ensureCalculatedDateOffset(field), sellBy);
    assert.equal(field.data.offsetRef, 'SellBy');
    assert.equal(api.state.dateOffsets.length, 2);
    assert.equal(api.state.dateOffsetsDirty, false);
  }
});

test('date editor leaves an unresolved explicit offset reference for validation instead of rebinding it', () => {
  const api = loadCanonicalCiffApi();
  const useBy = { name: 'UseBy', default: { y: 0, m: 0, d: 30 } };
  api.state.dateOffsets = [useBy];
  api.state.dateOffsetsDirty = false;
  const field = api.createOffsetDateField({ name: 'Expiry', format: 'dd/MM/yy' }, 'MissingSellBy');
  assert.equal(api.ensureCalculatedDateOffset(field), null);
  assert.equal(field.data.offsetRef, 'MissingSellBy');
  assert.equal(api.state.dateOffsets.length, 1);
  assert.equal(api.state.dateOffsets[0], useBy);
  assert.equal(api.state.dateOffsetsDirty, false);
});

test('date editor creates a dedicated free offset name when the field has no reference', () => {
  const api = loadCanonicalCiffApi();
  const existing = { name: 'offset0', default: { y: 0, m: 0, d: 30 } };
  api.state.dateOffsets = [existing];
  api.state.dateOffsetsDirty = false;
  const field = api.createOffsetDateField({ name: 'Expiry', format: 'dd/MM/yy' }, null);
  const created = api.ensureCalculatedDateOffset(field);
  assert.ok(created);
  assert.notEqual(created, existing);
  assert.equal(created.name, 'offset1');
  assert.equal(created.sourceName, null);
  assert.equal(field.data.offsetRef, 'offset1');
  assert.deepEqual(Array.from(api.state.dateOffsets, (offset) => offset.name), ['offset0', 'offset1']);
  assert.equal(api.state.dateOffsets[0], existing);
  assert.equal(api.state.dateOffsets[1], created);
  assert.equal(api.state.dateOffsetsDirty, true);
});

test('FixedLen follows the text-entry model instead of MaxNoOfChars alone', () => {
  const api = loadCanonicalCiffApi();
  const field = api.createServerVariableField({
    name: 'GTIN',
    value: '0'.repeat(14),
    maxChars: 14,
    printed: false,
  });
  const generated = api.buildFieldXmlOneLine(field);

  assert.match(
    generated,
    /<MaxNoOfChars>14<\/MaxNoOfChars><Default><!\[CDATA\[00000000000000\]\]><\/Default><FixedLen\/><VarText>/,
  );
  assert.equal(field.data.fixedLen, true);

  field.sourceName = 'GTIN';
  field.data.fixedLen = false;
  api.state.fields = [field];
  api.state.fieldByName = new Map([[field.name, field]]);
  const patched = api.patchFieldsLosslessV2(wrapFields(generated.replace('<FixedLen/>', '')));
  const fieldBlock = getFieldBlock(patched, field.name);

  assert.doesNotMatch(fieldBlock, /<FixedLen\/>/);
  assert.match(fieldBlock, /<MaxNoOfChars>14<\/MaxNoOfChars>/);
  assert.equal(field.data.fixedLen, false);

  const staticField = api.createFixedTextField({ name: 'C1', value: '~101', maxChars: 4 });
  const staticXml = api.buildFieldXmlOneLine(staticField);
  assert.match(staticXml, /<MaxNoOfChars>4<\/MaxNoOfChars>/);
  assert.doesNotMatch(staticXml, /<FixedLen\/>/);
});

test('an imported MaxNoOfChars edit is upserted without inventing FixedLen', () => {
  const api = loadCanonicalCiffApi();
  const field = api.createFixedTextField({ name: 'LIMITED', value: 'ABC' });
  const sourceXml = api.buildFieldXmlOneLine(field);
  field.sourceName = field.name;
  field.data.maxChars = 7;
  api.state.fields = [field];
  api.state.fieldByName = new Map([[field.name, field]]);

  const patched = api.patchFieldsLosslessV2(wrapFields(sourceXml));
  const fieldBlock = getFieldBlock(patched, field.name);
  assert.match(fieldBlock, /<DataType>0<\/DataType><MaxNoOfChars>7<\/MaxNoOfChars><Default>/);
  assert.doesNotMatch(fieldBlock, /<FixedLen\/>/);
});

test('lossless field matching decodes XML entities and replacement names treat dollar tokens literally', () => {
  const api = loadCanonicalCiffApi();
  const field = api.createFixedTextField({ name: 'A&B', value: 'opaque' });
  const sourceXml = api.buildFieldXmlOneLine(field)
    .replace('Name="A&amp;B"', "Name='A&amp;B' VendorAttr='keep'")
    .replace('<Data>', '<VendorBefore>keep</VendorBefore><Data>');
  field.sourceName = 'A&B';
  field.name = "A'$&B";
  api.state.fields = [field];
  api.state.fieldByName = new Map([[field.name, field]]);

  const patched = api.patchFieldsLosslessV2(wrapFields(sourceXml));
  assert.match(patched, /<Field Name='A&apos;\$&amp;B' VendorAttr='keep'>/);
  assert.match(patched, /<VendorBefore>keep<\/VendorBefore>/);
  assert.equal((patched.match(/<Field\b/g) || []).length, 1);
});

test('VarText opaque XML survives value edits and CDATA terminators are split safely', () => {
  const api = loadCanonicalCiffApi();
  const field = api.createServerVariableField({ name: 'USER', value: 'old', maxChars: 8 });
  const sourceXml = api.buildFieldXmlOneLine(field)
    .replace('<VarText>', '<VarText VendorAttr="keep"><VendorBefore>keep-before</VendorBefore>')
    .replace('</VarText>', '<VendorAfter>keep-after</VendorAfter></VarText>');
  field.sourceName = field.name;
  field.calcData = 'a]]>b';
  field.data.defaultValue = 'a]]>b';
  field.data.userEnterData = 'a]]>b';
  api.state.fields = [field];
  api.state.fieldByName = new Map([[field.name, field]]);

  const patched = api.patchFieldsLosslessV2(wrapFields(sourceXml));
  assert.match(patched, /<VarText VendorAttr="keep"><VendorBefore>keep-before<\/VendorBefore>/);
  assert.match(patched, /<VendorAfter>keep-after<\/VendorAfter><\/VarText>/);
  assert.ok(patched.includes('<![CDATA[a]]]]><![CDATA[>b]]>'));
  assert.equal((patched.match(/<VarText\b/g) || []).length, 1);
});

test('explicit Pitch wins over a conflicting geometry inference', () => {
  const api = loadCanonicalCiffApi();
  assert.equal(api.getEffectiveTextPitch({ text: { pitch: 10 }, geom: { h: 133 } }, 10), 10);
  assert.equal(api.getEffectiveTextPitch({ text: { pitch: null }, geom: { h: 133 } }, 10), 3);
});

test('generic new DataMatrix literals validate without activating a recipe profile', () => {
  const api = loadCanonicalCiffApi();
  const { dmField } = createShortProfileModel(api);
  dmField.barcode.dataMatrix.segments = [
    { index: 0, dataType: 5, defaultValue: 'literal-A', srcField: null },
    { index: 1, dataType: 5, defaultValue: 'literal-B', srcField: null },
  ];
  dmField.calcData = 'literal-Aliteral-B';
  api.state.fields = [dmField];
  api.state.fieldByName = new Map([[dmField.name, dmField]]);
  const xml = api.buildFieldXmlOneLine(dmField);
  const errors = [];

  api.validateDataMatrixSourceConsistency(wrapFields(xml), errors);
  assert.deepEqual(errors, []);
});

test('an explicit QuietMargin edit upserts a previously absent optional tag', () => {
  const api = loadCanonicalCiffApi();
  const field = importedDataMatrixField(false);
  field.barcode.quietMargin = 3;
  api.state.fields = [field];
  api.state.fieldByName = new Map([[field.name, field]]);
  const sourceXml = importedDataMatrixBlock().replace('<QuietMargin>0</QuietMargin>', '');

  const patched = api.patchFieldsLosslessV2(wrapFields(sourceXml));
  const fieldBlock = getFieldBlock(patched, field.name);
  assert.match(fieldBlock, /<HR><HRFont\/><\/HR><QuietMargin>3<\/QuietMargin><DataMatrix>/);
});

test('DataMatrix BcH is derived from symbol rows and effective module size', () => {
  const api = loadCanonicalCiffApi();
  const { dmField, sourceFields, fieldByName } = createShortProfileModel(api);
  api.state.fields = [...sourceFields, dmField];
  api.state.fieldByName = fieldByName;

  const cases = [
    { symbolSize: '22X22', moduleSize: 0.33, expected: 726 },
    { symbolSize: '22X22', moduleSize: 0.42, expected: 924 },
    { symbolSize: '22X22', moduleSize: 0.50, expected: 1100 },
    { symbolSize: '22X22', moduleSize: 0.58, expected: 1276 },
    { symbolSize: '22X22', moduleSize: 0.67, expected: 1474 },
    { symbolSize: '24X24', moduleSize: 0.50, expected: 1200 },
    { symbolSize: '26X26', moduleSize: 0.33, expected: 858 },
    { symbolSize: '36X36', moduleSize: 0.50, expected: 1800 },
    { symbolSize: '12X26', moduleSize: 0.40, expected: 480 },
  ];
  for (const scenario of cases) {
    dmField.barcode.dataMatrix.symbolSize = scenario.symbolSize;
    dmField.barcode.dataMatrix.moduleSize = scenario.moduleSize;
    assert.equal(api.calculateDataMatrixBcH(dmField), scenario.expected, JSON.stringify(scenario));
    assert.equal(
      api.calculateDataMatrixBcH(scenario.symbolSize, scenario.moduleSize * 100),
      scenario.expected,
      `CIFF-native ${JSON.stringify(scenario)}`,
    );
  }
});

test('rectangular DataMatrix geometry uses columns for width and rows for height', () => {
  const api = loadCanonicalCiffApi();
  const { dmField, sourceFields, fieldByName } = createShortProfileModel(api);
  api.state.fields = [...sourceFields, dmField];
  api.state.fieldByName = fieldByName;
  dmField.barcode.dataMatrix.symbolSize = '12X26';
  dmField.barcode.dataMatrix.moduleSize = 0.42;
  dmField.barcode.quietMargin = 0;

  api.syncDataMatrixGeomToModuleSize(dmField);
  assert.equal(dmField.geom.w, 1083);
  assert.equal(dmField.geom.h, 500);
  assert.equal(dmField.barcode.bcH, 2540);
  assert.equal(api.updateDataMatrixBcHFromSettings(dmField), 504);
});

test('explicit DataMatrix options use integer dot geometry and rounded serialized BcH', () => {
  const api = loadCanonicalCiffApi();
  const { dmField, sourceFields, fieldByName } = createShortProfileModel(api);
  api.state.fields = [...sourceFields, dmField];
  api.state.fieldByName = fieldByName;
  dmField.barcode.quietMargin = 0;

  for (const scenario of [
    { moduleSize: 0.42, geometry: 917, bcH: 924 },
    { moduleSize: 0.58, geometry: 1283, bcH: 1276 },
  ]) {
    dmField.barcode.dataMatrix.moduleSize = scenario.moduleSize;
    api.syncDataMatrixGeomToModuleSize(dmField);
    api.updateDataMatrixBcHFromSettings(dmField);
    assert.equal(dmField.geom.w, scenario.geometry, JSON.stringify(scenario));
    assert.equal(dmField.geom.h, scenario.geometry, JSON.stringify(scenario));
    assert.equal(dmField.barcode.bcH, scenario.bcH, JSON.stringify(scenario));
  }
});

test('Auto SymbolSize BcH uses the effectively selected symbol row count', () => {
  const api = loadCanonicalCiffApi();
  const { dmField, sourceFields, fieldByName } = createShortProfileModel(api);
  api.state.fields = [...sourceFields, dmField];
  api.state.fieldByName = fieldByName;
  dmField.barcode.dataMatrix.symbolSize = 'Auto';
  dmField.barcode.dataMatrix.moduleSize = 0.50;

  const symbolInfo = api.getDataMatrixEffectiveSymbolInfo(dmField);
  assert.ok(symbolInfo);
  assert.notEqual(symbolInfo.name, 'Auto');
  assert.equal(api.calculateDataMatrixBcH(dmField), symbolInfo.symbolRows * 50);
});

test('imported Auto SymbolSize updates geometry without changing BcH after a source text edit', () => {
  const api = loadCanonicalCiffApi();
  const { dmField, sourceFields, fieldByName } = createShortProfileModel(api);
  dmField.sourceName = dmField.name;
  api.state.fields = [...sourceFields, dmField];
  api.state.fieldByName = fieldByName;
  dmField.barcode.dataMatrix.symbolSize = 'Auto';
  dmField.barcode.dataMatrix.moduleSize = 0.50;

  api.synchronizeDataMatrixEditorState(dmField);
  const initialRows = api.getDataMatrixEffectiveSymbolInfo(dmField).symbolRows;
  const snField = fieldByName.get('SN');
  snField.data.defaultValue = 'A'.repeat(80);
  snField.data.userEnterData = snField.data.defaultValue;
  snField.calcData = snField.data.defaultValue;

  api.synchronizeDataMatrixEditorState(dmField);
  const expandedRows = api.getDataMatrixEffectiveSymbolInfo(dmField).symbolRows;
  assert.ok(expandedRows > initialRows);
  assert.equal(dmField.barcode.bcH, 2540);
  assert.equal(dmField.geom.h, expandedRows * 50);
});

test('new DataMatrix with an unresolvable symbol cannot serialize BcH as zero', () => {
  const api = loadCanonicalCiffApi();
  const { dmField, sourceFields, fieldByName } = createShortProfileModel(api);
  api.state.fields = [...sourceFields, dmField];
  api.state.fieldByName = fieldByName;
  dmField.barcode.dataMatrix.symbolSize = 'UNSUPPORTED';
  dmField.barcode.bcH = null;

  assert.equal(api.calculateDataMatrixBcH(dmField), null);
  assert.throws(() => api.buildFieldXmlOneLine(dmField), /requires a calculable BcH value/);
});

test('serializer only derives DataMatrix BcH when the stored value is null', () => {
  const api = loadCanonicalCiffApi();
  const { dmField } = createShortProfileModel(api);

  dmField.barcode.bcH = 'invalid';

  assert.throws(() => api.buildFieldXmlOneLine(dmField), /has an invalid BcH value/);
  assert.equal(dmField.barcode.bcH, 'invalid');
});

test('new DataMatrix serializes ModuleSize and BcH from the same effective module size', () => {
  const api = loadCanonicalCiffApi();
  const { dmField, sourceFields, fieldByName } = createShortProfileModel(api);
  api.state.fields = [...sourceFields, dmField];
  api.state.fieldByName = fieldByName;
  dmField.barcode.dataMatrix.moduleSize = null;
  dmField.barcode.bcH = null;
  dmField.geom.w = 924;
  dmField.geom.h = 924;

  const xml = api.buildFieldXmlOneLine(dmField);
  assert.match(xml, /<BcH>924<\/BcH>/);
  assert.match(xml, /<ModuleSize>42<\/ModuleSize>/);
});

test('geometry sync changes DataMatrix geometry without changing imported BcH', () => {
  const api = loadCanonicalCiffApi();
  const { dmField, sourceFields, fieldByName } = createShortProfileModel(api);
  api.state.fields = [...sourceFields, dmField];
  api.state.fieldByName = fieldByName;
  dmField.barcode.dataMatrix.moduleSize = 0.42;
  dmField.barcode.quietMargin = 3;
  dmField.barcode.bcH = 2540;

  api.syncDataMatrixGeomToModuleSize(dmField);
  assert.equal(dmField.geom.h, 1167);
  assert.equal(dmField.barcode.bcH, 2540);
  assert.match(api.buildFieldXmlOneLine(dmField), /<H>1167<\/H>[\s\S]*<BcH>2540<\/BcH>/);
});

test('DataMatrix resize snaps ModuleSize and calculates BcH independently from geom.h', () => {
  const api = loadCanonicalCiffApi();
  const { dmField, sourceFields, fieldByName } = createShortProfileModel(api);
  api.state.fields = [...sourceFields, dmField];
  api.state.fieldByName = fieldByName;
  dmField.barcode.quietMargin = 3;
  const requestedSidePx = (22 + 6) * 0.58 * 12;

  const metrics = api.getDataMatrixResizeMetrics(dmField, requestedSidePx, requestedSidePx);
  assert.equal(metrics.moduleSize, 0.58);
  assert.equal(metrics.bcH, 1276);
  assert.ok(Math.abs(metrics.widthPx - 196) < 1e-9);
  assert.ok(Math.abs(metrics.heightPx - 196) < 1e-9);
  dmField.barcode.dataMatrix.moduleSize = metrics.moduleSize;
  dmField.barcode.bcH = metrics.bcH;
  dmField.geom.w = Math.round((metrics.widthPx / 12) * 100);
  dmField.geom.h = Math.round((metrics.heightPx / 12) * 100);
  assert.equal(dmField.geom.h, 1633);
  assert.notEqual(dmField.barcode.bcH, dmField.geom.h);
});

test('new DataMatrix creation initializes calculated BcH instead of default field geometry', () => {
  const api = loadCanonicalCiffApi();
  const helpers = Array.from(api.createDataMatrixHelperFields({
    symbolSize: '22X22',
    snValue: '0'.repeat(13),
    moduleSize: 0.42,
  }));
  const fieldMap = new Map(helpers.map((field) => [field.name, field]));
  const field = api.createDataMatrixField({
    symbolSize: '22X22',
    moduleSize: 0.42,
  }, fieldMap);

  assert.equal(field.geom.h, 917);
  assert.equal(field.barcode.bcH, 924);
  assert.equal(fieldMap.get('GTIN').data.maxChars, 14);
  assert.equal(fieldMap.get('SN').data.maxChars, 13);
  assert.equal(fieldMap.get('KRIPTO').data.maxChars, 4);
  assert.match(api.buildFieldXmlOneLine(field), /<H>917<\/H>[\s\S]*<BcH>924<\/BcH>/);
});

test('XML consistency validator rejects stale DataMatrix Default and CalcData', () => {
  const api = loadCanonicalCiffApi();
  assert.equal(typeof api.validateDataMatrixSourceConsistency, 'function');
  const { dmField, sourceFields, fieldByName } = createShortProfileModel(api);
  api.state.fields = [...sourceFields, dmField];
  api.state.fieldByName = fieldByName;
  api.synchronizeDataMatrixDerivedState(dmField, fieldByName);
  const helpersXml = sourceFields.map((field) => api.buildFieldXmlOneLine(field)).join('');
  const dmXml = api.buildFieldXmlOneLine(dmField);

  const cleanErrors = [];
  api.validateDataMatrixSourceConsistency(wrapFields(`${dmXml}${helpersXml}`), cleanErrors);
  assert.deepEqual(cleanErrors, []);

  const profilePolicyErrors = [];
  api.validateDataMatrixSourceConsistency(
    wrapFields(`${dmXml}${helpersXml.replace('<MaxNoOfChars>4</MaxNoOfChars>', '<MaxNoOfChars>5</MaxNoOfChars>')}`),
    profilePolicyErrors,
  );
  assert.deepEqual(profilePolicyErrors, []);

  const staleDmXml = dmXml
    .replace(dmField.calcData, 'BROKEN-CALC-DATA')
    .replace(
      '<Default><![CDATA[~d02993]]></Default><SrcField SrcFieldName="C3"/>',
      '<Default><![CDATA[~d02991]]></Default><SrcField SrcFieldName="C3"/>',
    );
  const errors = [];
  api.validateDataMatrixSourceConsistency(wrapFields(`${staleDmXml}${helpersXml}`), errors);

  assert.ok(errors.some((message) => /CalcData/i.test(String(message))), errors);
  assert.ok(errors.some((message) => /C3|Default/i.test(String(message))), errors);
});

test('imported DataMatrix value patch preserves unknown Object structure when structureDirty is false', () => {
  const api = loadCanonicalCiffApi();
  const field = importedDataMatrixField(false);
  api.state.fields = [field];
  api.state.fieldByName = new Map([[field.name, field]]);

  const patched = api.patchFieldsLosslessV2(wrapFields(importedDataMatrixBlock()));
  const fieldBlock = getFieldBlock(patched, field.name);
  const objectBlock = fieldBlock.match(/<Object\b[^>]*>[\s\S]*?<\/Object>/)?.[0] ?? null;

  assert.equal(objectBlock, '<Object LegacyFlag="keep" Reference="legacy"><DataType>5</DataType><VendorBefore Code="opaque"/><Default><![CDATA[new-value]]></Default><VendorAfter>opaque</VendorAfter><SrcField SrcFieldName="LEGACY_SOURCE"/></Object>');
  assert.ok(fieldBlock.includes('<CalcData><![CDATA[new-value]]></CalcData>'));
  assert.match(fieldBlock, /<BcH>2540<\/BcH>/);
});

test('lossless save preserves imported BcH for 22X22 ModuleSize 42', () => {
  const api = loadCanonicalCiffApi();
  const field = importedDataMatrixField(false);
  field.geom.w = 924;
  field.geom.h = 924;
  field.barcode.dataMatrix.moduleSize = 0.42;
  field.barcode.bcH = 2540;
  api.state.fields = [field];
  api.state.fieldByName = new Map([[field.name, field]]);
  const sourceBlock = importedDataMatrixBlock()
    .replace('<W>1100</W><H>1100</H>', '<W>924</W><H>924</H>')
    .replace('<ModuleSize>50</ModuleSize>', '<ModuleSize>42</ModuleSize>');

  const patched = api.patchFieldsLosslessV2(wrapFields(sourceBlock));
  const fieldBlock = getFieldBlock(patched, field.name);
  assert.match(fieldBlock, /<W>924<\/W><H>924<\/H>/);
  assert.match(fieldBlock, /<Barcode><BcH>2540<\/BcH>/);
  assert.match(fieldBlock, /<ModuleSize>42<\/ModuleSize><SymbolSize>22X22<\/SymbolSize>/);
});

test('lossless save does not normalize other imported BcH variants', () => {
  const cases = [
    { bcH: 858, moduleSize: 0.33, serializedModuleSize: 33 },
    { bcH: 1200, moduleSize: 0.50, serializedModuleSize: 50 },
  ];

  for (const scenario of cases) {
    const api = loadCanonicalCiffApi();
    const field = importedDataMatrixField(false);
    field.barcode.bcH = scenario.bcH;
    field.barcode.dataMatrix.moduleSize = scenario.moduleSize;
    api.state.fields = [field];
    api.state.fieldByName = new Map([[field.name, field]]);
    const sourceBlock = importedDataMatrixBlock()
      .replace('<BcH>2540</BcH>', `<BcH>${scenario.bcH}</BcH>`)
      .replace('<ModuleSize>50</ModuleSize>', `<ModuleSize>${scenario.serializedModuleSize}</ModuleSize>`);

    const fieldBlock = getFieldBlock(api.patchFieldsLosslessV2(wrapFields(sourceBlock)), field.name);
    assert.match(fieldBlock, new RegExp(`<BcH>${scenario.bcH}<\\/BcH>`));
    assert.match(fieldBlock, new RegExp(`<ModuleSize>${scenario.serializedModuleSize}<\\/ModuleSize>`));
  }
});

test('lossless save inserts a missing BcH before HR', () => {
  const api = loadCanonicalCiffApi();
  const field = importedDataMatrixField(false);
  field.barcode.bcH = null;
  api.state.fields = [field];
  api.state.fieldByName = new Map([[field.name, field]]);
  const sourceBlock = importedDataMatrixBlock().replace('<BcH>2540</BcH>', '');

  const patched = api.patchFieldsLosslessV2(wrapFields(sourceBlock));
  const fieldBlock = getFieldBlock(patched, field.name);
  assert.match(fieldBlock, /<Barcode><BcH>1100<\/BcH><HR>/);
});

test('coordinates, movement endpoint and dependent text edits preserve imported BcH', () => {
  const api = loadCanonicalCiffApi();
  const field = importedDataMatrixField(false);
  const source = createTextSource('LEGACY_SOURCE', 'old-value', true, 9);
  api.state.fields = [field, source];
  api.state.fieldByName = new Map(api.state.fields.map((item) => [item.name, item]));

  field.geom.x = 321;
  field.geom.y = 654;
  assert.equal(field.barcode.bcH, 2540);

  api.setFieldPositionInternal(field, 777, 888, { constrainPrintable: false });
  assert.deepEqual({ x: field.geom.x, y: field.geom.y }, { x: 777, y: 888 });
  assert.equal(field.barcode.bcH, 2540);

  api.setEditableTextFieldValue(source, 'changed-text');
  assert.equal(field.calcData, 'changed-text');
  assert.equal(field.barcode.bcH, 2540);
});

test('explicit DataMatrix settings edits recalculate BcH through the centralized helper', () => {
  const api = loadCanonicalCiffApi();
  const field = importedDataMatrixField(false);

  field.barcode.dataMatrix.moduleSize = 0.42;
  api.syncDataMatrixGeomToModuleSize(field);
  assert.equal(api.updateDataMatrixBcHFromSettings(field), 924);
  assert.equal(field.barcode.bcH, 924);

  field.barcode.dataMatrix.symbolSize = '24X24';
  field.barcode.dataMatrix.moduleSize = 0.50;
  api.syncDataMatrixGeomToModuleSize(field);
  assert.equal(api.updateDataMatrixBcHFromSettings(field), 1200);
  assert.equal(field.barcode.bcH, 1200);
});

test('failed DataMatrix profile application preserves imported BcH', () => {
  const api = loadCanonicalCiffApi();
  const { dmField, sourceFields, fieldByName } = createShortProfileModel(api);
  const conflictingField = {
    ...dmField,
    name: 'OtherDM',
    barcode: {
      ...dmField.barcode,
      dataMatrix: { ...dmField.barcode.dataMatrix, symbolSize: '22X22' }
    }
  };
  api.state.fields = [...sourceFields, dmField, conflictingField];
  api.state.fieldByName = new Map([...fieldByName, [conflictingField.name, conflictingField]]);

  assert.equal(api.applyDataMatrixProfileSettings(dmField, '36X36', { notifyOnConflict: false }), false);
  assert.equal(dmField.barcode.bcH, 2540);
  assert.equal(dmField.barcode.dataMatrix.symbolSize, '22X22');
});

test('Undo and Redo restore imported and explicitly recalculated BcH values', () => {
  const api = loadCanonicalCiffApi();
  const field = importedDataMatrixField(false);
  api.state.line2 = wrapFields(importedDataMatrixBlock());
  api.state.fields = [field];
  api.state.fieldByName = new Map([[field.name, field]]);
  api.pushHistory(true);
  api.pushHistory();

  field.barcode.dataMatrix.moduleSize = 0.42;
  api.syncDataMatrixGeomToModuleSize(field);
  api.updateDataMatrixBcHFromSettings(field);
  assert.equal(field.barcode.bcH, 924);

  api.undo();
  assert.equal(api.state.fieldByName.get(field.name).barcode.bcH, 2540);
  assert.equal(api.state.fieldByName.get(field.name).barcode.dataMatrix.moduleSize, 0.5);

  api.redo();
  assert.equal(api.state.fieldByName.get(field.name).barcode.bcH, 924);
  assert.equal(api.state.fieldByName.get(field.name).barcode.dataMatrix.moduleSize, 0.42);
});

test('restoring a legacy snapshot infers DataMatrix structural edits from raw XML', () => {
  const api = loadCanonicalCiffApi();
  api.state.line2 = wrapFields(importedDataMatrixBlock());

  const matchingField = importedDataMatrixField(undefined);
  delete matchingField.barcode.dataMatrix.structureDirty;
  const baseSnapshot = {
    docMeta: {},
    subImage: {},
    dateOffsets: [],
    dateOffsetsLoaded: false,
    dateOffsetsDirty: false,
    fields: [matchingField],
    selectedName: null,
    selectedNames: [],
    showHiddenOnCanvas: false,
    gridMm: 1,
    validation: {}
  };

  api.restoreFromSnapshot(JSON.stringify(baseSnapshot), { render: false });
  assert.equal(api.state.fields[0].barcode.dataMatrix.structureDirty, false);

  const editedSnapshot = JSON.parse(JSON.stringify(baseSnapshot));
  editedSnapshot.fields[0].barcode.dataMatrix.segments.push({
    index: 1,
    dataType: 5,
    defaultValue: 'added',
    srcField: 'ADDED_SOURCE'
  });
  api.restoreFromSnapshot(JSON.stringify(editedSnapshot), { render: false });
  assert.equal(api.state.fields[0].barcode.dataMatrix.structureDirty, true);
});

test('DataMatrix structure changes preserve metadata of matching source objects', () => {
  const api = loadCanonicalCiffApi();
  const field = importedDataMatrixField(true);
  api.state.fields = [field];
  api.state.fieldByName = new Map([[field.name, field]]);

  const patched = api.patchFieldsLosslessV2(wrapFields(importedDataMatrixBlock()));
  const fieldBlock = getFieldBlock(patched, field.name);
  const dataBlock = fieldBlock.match(/<Data>[\s\S]*?<\/Data>/)?.[0] ?? null;

  assert.equal(dataBlock, '<Data><Object LegacyFlag="keep" Reference="legacy"><DataType>5</DataType><VendorBefore Code="opaque"/><Default><![CDATA[new-value]]></Default><VendorAfter>opaque</VendorAfter><SrcField SrcFieldName="LEGACY_SOURCE"/></Object></Data>');
});

test('no-op patch preserves an imported explicit Orientation zero and the complete field block', () => {
  const api = loadCanonicalCiffApi();
  const originalBlock = '<Field Name="LegacyDate"><FldType>DateText</FldType><X>10</X><Y>20</Y><W>1200</W><H>392</H><Ln>1</Ln><Orientation>0</Orientation><CalcData><![CDATA[20.08.26]]></CalcData><VendorMeta Flag="keep"/><Data><Object Static="0" Parse="1" Legacy="yes"><DataType>2</DataType><Default><![CDATA[dd\'.\'MM\'.\'yy]]></Default></Object></Data><Text><Font><Face>opaque</Face><Pitch>10</Pitch></Font></Text></Field>';
  const field = {
    sourceName: 'LegacyDate',
    name: 'LegacyDate',
    fldType: 'DateText',
    printed: true,
    geom: { x: 10, y: 20, w: 1200, h: 392 },
    ln: 1,
    orientation: 0,
    calcData: '20.08.26',
    data: { dataType: 2, defaultValue: "dd'.'MM'.'yy", maxChars: null, counter: {} },
    text: { pitch: 10, xMag: null },
    barcode: null,
    _konva: null,
  };
  api.state.fields = [field];
  api.state.fieldByName = new Map([[field.name, field]]);

  const patched = api.patchFieldsLosslessV2(wrapFields(originalBlock));
  const fieldBlock = getFieldBlock(patched, field.name);

  assert.equal(fieldBlock, originalBlock);
  assert.match(fieldBlock, /<Ln>1<\/Ln><Orientation>0<\/Orientation>/);
});
