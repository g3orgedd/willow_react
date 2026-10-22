const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

const {
  analyzeCiffBuffer,
  compareCiffBuffers,
  codePoints,
} = require('../scripts/compare-ciff-structure.cjs');
const {
  createProductionCiffRuntime,
  sha256,
} = require('./helpers/ciff-production-harness.cjs');

const FIXTURE = path.join(__dirname, 'fixtures', 'clarisoft', 'Clarisoft_test_1.ciff');
const FIXTURE_SHA256 = '5221DC212883631146E4D26E2BB5AF3D38E440D0EA458C73BF4B18E5175BB63D';
const NO_OP_SAVE_SHA256 = FIXTURE_SHA256;
const X_EDIT_SHA256 = 'DD4149E525FEEAC845820188A30CF56BD9EC158ED6A6A2888D2FA58D7764A6BE';
const X_EDIT_PATH = '/ImageDesign/SubImage[ImageReference="1"]/Field[Name="PRODUCT_DATE"]/X';
const SAVE_NOW = new Date(2026, 7, 20, 12, 0, 0, 0);

function fixtureBytes() {
  return fs.readFileSync(FIXTURE);
}

function plain(value) {
  return JSON.parse(JSON.stringify(value));
}

function fieldGeometry(runtime) {
  return Array.from(runtime.state.fields, (field) => ({ name: field.name, ...plain(field.geom) }));
}

function saveWithImportedSelection(runtime) {
  // These byte-preservation tests deliberately retain this static fixture's
  // recorded native selection. Native RNG behavior is covered separately.
  runtime.context.__importedToken = runtime.state.docMeta.clStVersionInfo;
  const mask = vm.runInContext('decodeClStVersionInfo(__importedToken).mask', runtime.context);
  return runtime.save(SAVE_NOW, { clstOptions: { mask } });
}

function saveWithProductDateX(x) {
  const source = fixtureBytes();
  const runtime = createProductionCiffRuntime(source);
  runtime.state.fieldByName.get('PRODUCT_DATE').geom.x = x;
  return { source, runtime, saved: saveWithImportedSelection(runtime) };
}

test('real ClariSoft fixture keeps its immutable byte anchor and CIFF envelope', () => {
  const bytes = fixtureBytes();
  const analysis = analyzeCiffBuffer(bytes, FIXTURE);

  assert.equal(bytes.length, 12914);
  assert.equal(sha256(bytes), FIXTURE_SHA256);
  assert.equal(analysis.bom, 'FF FE');
  assert.equal(analysis.encoding, 'UTF-16LE');
  assert.equal(analysis.declarationEncoding, 'UTF-16');
  assert.equal(analysis.crlfCount, 2);
  assert.equal(analysis.twoLineLayout, true);
  assert.equal(analysis.finalCrLf, true);
});

test('production parser reads ClariSoft header and SubHeader metadata', () => {
  const { state } = createProductionCiffRuntime(fixtureBytes());

  assert.deepEqual(plain(state.docMeta), {
    version: '23',
    designedFor: 'DataFlex 6330(53mm) - Continuous',
    clStVersionInfo: 'PyOA!LMe37jF5gGD_OEeQJPAIR3Et2HVCOk4RKDB93Hl9AjBVgIOzL2x64vRUW8LPDPLLM!BMqKMGRFtEFE14tJB8QHyE4c51D13SR5m2JC4C!HReJIzNMv7EaRC14TVSJX1Ti6D_S6QHLuGOoN2BIHtEKkTPwVMq4RaLNP4UrOELUSs51e139EUN1QgGBt63L0QEVRvKL!22pG2THF14PjEMl1UuEIqUQj16i9A2K4l7S_GUrLALTBXKI78',
    printerModel: 'DataFlex 6330(53mm)',
    printMode: 'Continuous',
    units: 0,
    sourceFileName: '',
    clStIncludeFileMetadata: false,
  });
  assert.deepEqual(plain(state.subImage), {
    imageReference: '1',
    width: 3917,
    height: 2892,
    maxWidth: 5333,
    maxHeight: 7500,
    xRes: 0.12,
    yRes: null,
    printerType: 'DataFlex 6330(53mm)',
    orientation: 0,
    usedSizeDirty: false,
  });
});

test('production parser preserves field order and exact Cyrillic/Latin names', () => {
  const { state } = createProductionCiffRuntime(fixtureBytes());
  const names = Array.from(state.fields, (field) => field.name);

  assert.deepEqual(names, [
    'Field00',
    'PRODUCT_DATE',
    'EXPIRATION_DATE',
    'PARTY',
    'TEAM',
    'R_NUM',
    '\u04211',
    'GTIN',
    '\u04212',
    'SN',
    'C3',
    'KRIPTO',
  ]);
  assert.deepEqual(codePoints(names[6]), ['U+0421', 'U+0031']);
  assert.deepEqual(codePoints(names[8]), ['U+0421', 'U+0032']);
  assert.deepEqual(codePoints(names[10]), ['U+0043', 'U+0033']);
});

test('production parser reconstructs the ordered DataMatrix model without marking it dirty', () => {
  const { state } = createProductionCiffRuntime(fixtureBytes());
  const field = state.fieldByName.get('Field00');

  assert.deepEqual(plain({
    name: field.name,
    fldType: field.fldType,
    geom: field.geom,
    calcData: field.calcData,
    clsid: field.barcode.clsid,
    bcH: field.barcode.bcH,
    quietMargin: field.barcode.quietMargin,
    moduleSize: field.barcode.dataMatrix.moduleSize,
    symbolSize: field.barcode.dataMatrix.symbolSize,
    structureDirty: field.barcode.dataMatrix.structureDirty,
    segments: field.barcode.dataMatrix.segments,
  }), {
    name: 'Field00',
    fldType: 'Barcode',
    geom: { x: 500, y: 500, w: 1100, h: 1100 },
    calcData: '~10100000000000000210000000000000~d029930000',
    clsid: '{7A4AA4CF-F5CD-11D4-8DAE-0050DAFE8A9F}',
    bcH: 2540,
    quietMargin: 0,
    moduleSize: 0.5,
    symbolSize: '22X22',
    structureDirty: false,
    segments: [
      { index: 0, srcField: '\u04211', defaultValue: '~101', dataType: 5 },
      { index: 1, srcField: 'GTIN', defaultValue: '00000000000000', dataType: 5 },
      { index: 2, srcField: '\u04212', defaultValue: '21', dataType: 5 },
      { index: 3, srcField: 'SN', defaultValue: '0000000000000', dataType: 5 },
      { index: 4, srcField: 'C3', defaultValue: '~d02993', dataType: 5 },
      { index: 5, srcField: 'KRIPTO', defaultValue: '0000', dataType: 5 },
    ].map((segment) => ({
      ...segment,
      sourceObjectIndex: segment.index,
      startChar: null,
      noOfChars: null,
      selectMode: null,
      staticAttr: null,
      fixedLen: false,
      maxChars: null,
      padChar: null,
      padMode: null,
      hasVarText: false,
      userEnterData: null,
      offsetRef: null,
      dateLocale: null,
      calendar: null,
      locale: null,
      encryption: null,
    })),
  });
});

test('production no-op with the imported native selection is byte-identical and preserves ClariSoft BcH', () => {
  const source = fixtureBytes();
  const runtime = createProductionCiffRuntime(source);
  const { state } = runtime;
  const saved = saveWithImportedSelection(runtime);

  assert.equal(saved.prepared.validation.ok, true, plain(saved.prepared.validation));
  assert.deepEqual(plain(saved.prepared.validation), {
    invalidPrintableFieldNames: [],
    invalidHardwareFieldNames: [],
    structuralErrors: [],
    ok: true,
  });
  assert.equal(saved.bytes.equals(source), true);
  assert.equal(saved.bytes.length, 12914);
  assert.equal(saved.sha256, NO_OP_SAVE_SHA256);
  assert.equal(state.fieldByName.get('Field00').barcode.bcH, 2540);
  assert.equal(createProductionCiffRuntime(saved.bytes).state.fieldByName.get('Field00').barcode.bcH, 2540);
});

test('ordered comparator reports no differences after preserving the imported selection of a static fixture', () => {
  const source = fixtureBytes();
  const saved = saveWithImportedSelection(createProductionCiffRuntime(source));
  const comparison = compareCiffBuffers(source, saved.bytes, {
    expected: FIXTURE,
    actual: '<production-no-op-save>',
  });

  assert.deepEqual(comparison.summary, {});
  assert.deepEqual(comparison.diffs, []);
  assert.equal(comparison.actual.twoLineLayout, true);
  assert.equal(comparison.actual.finalCrLf, true);
});

test('production load preserves imported geometry until explicit dot geometry sync', () => {
  const source = fixtureBytes();
  const sourceText = source.subarray(2).toString('utf16le')
    .replace('<W>1100</W><H>1100</H>', '<W>924</W><H>924</H>')
    .replace('<ModuleSize>50</ModuleSize>', '<ModuleSize>42</ModuleSize>');
  const staleBytes = Buffer.concat([Buffer.from([0xff, 0xfe]), Buffer.from(sourceText, 'utf16le')]);
  const runtime = createProductionCiffRuntime(staleBytes);

  assert.equal(runtime.state.fieldByName.get('Field00').barcode.bcH, 2540);
  assert.equal(runtime.state.fieldByName.get('Field00').barcode.dataMatrix.moduleSize, 0.42);
  assert.equal(runtime.state.fieldByName.get('Field00').geom.w, 924);
  assert.equal(runtime.state.fieldByName.get('Field00').geom.h, 924);
  runtime.context.syncDataMatrixGeomToModuleSize(runtime.state.fieldByName.get('Field00'));
  assert.equal(runtime.state.fieldByName.get('Field00').geom.w, 917);
  assert.equal(runtime.state.fieldByName.get('Field00').geom.h, 917);
  assert.equal(runtime.state.fieldByName.get('Field00').barcode.bcH, 2540);
  const saved = saveWithImportedSelection(runtime);
  const reparsed = createProductionCiffRuntime(saved.bytes);
  const savedText = saved.bytes.subarray(2).toString('utf16le');

  assert.match(savedText, /<W>917<\/W><H>917<\/H>[\s\S]*?<Barcode><BcH>2540<\/BcH>/);
  assert.match(savedText, /<ModuleSize>42<\/ModuleSize><SymbolSize>22X22<\/SymbolSize>/);
  assert.equal(runtime.state.fieldByName.get('Field00').barcode.bcH, 2540);
  assert.equal(reparsed.state.fieldByName.get('Field00').barcode.bcH, 2540);
});

test('production round-trip preserves an imported non-snapped ModuleSize and BcH', () => {
  const source = fixtureBytes();
  const sourceText = source.subarray(2).toString('utf16le')
    .replace('<W>1100</W><H>1100</H>', '<W>880</W><H>880</H>')
    .replace('<ModuleSize>50</ModuleSize>', '<ModuleSize>40</ModuleSize>');
  const bytes = Buffer.concat([Buffer.from([0xff, 0xfe]), Buffer.from(sourceText, 'utf16le')]);
  const runtime = createProductionCiffRuntime(bytes);

  assert.equal(runtime.state.fieldByName.get('Field00').barcode.dataMatrix.moduleSize, 0.4);
  const saved = saveWithImportedSelection(runtime);
  const savedText = saved.bytes.subarray(2).toString('utf16le');
  assert.match(savedText, /<BcH>2540<\/BcH>/);
  assert.match(savedText, /<ModuleSize>40<\/ModuleSize><SymbolSize>22X22<\/SymbolSize>/);
});

test('production no-op round-trip preserves source ModuleSize and SymbolSize spelling', () => {
  const source = fixtureBytes();
  const sourceText = source.subarray(2).toString('utf16le')
    .replace('<ModuleSize>50</ModuleSize>', '<ModuleSize>0.33</ModuleSize>')
    .replace('<SymbolSize>22X22</SymbolSize>', '<SymbolSize>22x22</SymbolSize>');
  const bytes = Buffer.concat([Buffer.from([0xff, 0xfe]), Buffer.from(sourceText, 'utf16le')]);
  const runtime = createProductionCiffRuntime(bytes);

  assert.equal(runtime.state.fieldByName.get('Field00').barcode.dataMatrix.moduleSize, 0.33);
  assert.equal(runtime.state.fieldByName.get('Field00').barcode.dataMatrix.symbolSize, '22X22');
  const savedText = saveWithImportedSelection(runtime).bytes.subarray(2).toString('utf16le');
  assert.match(savedText, /<BcH>2540<\/BcH>/);
  assert.match(savedText, /<ModuleSize>0\.33<\/ModuleSize><SymbolSize>22x22<\/SymbolSize>/);
});

test('editing a DataMatrix source text field does not change imported BcH', () => {
  const runtime = createProductionCiffRuntime(fixtureBytes());
  const gtin = runtime.state.fieldByName.get('GTIN');
  gtin.data.defaultValue = '12345678901234';
  gtin.data.userEnterData = '12345678901234';
  gtin.calcData = '12345678901234';

  const saved = saveWithImportedSelection(runtime);
  const savedText = saved.bytes.subarray(2).toString('utf16le');
  assert.match(savedText, /<Barcode><BcH>2540<\/BcH>/);
  assert.equal(runtime.state.fieldByName.get('Field00').barcode.bcH, 2540);
  assert.equal(createProductionCiffRuntime(saved.bytes).state.fieldByName.get('Field00').barcode.bcH, 2540);
});

test('one model X edit produces only byte metadata and the ordered X difference', () => {
  const { source, saved } = saveWithProductDateX(999);
  const comparison = compareCiffBuffers(source, saved.bytes);

  assert.equal(saved.prepared.validation.ok, true, plain(saved.prepared.validation));
  assert.equal(saved.bytes.length, 12912);
  assert.equal(saved.sha256, X_EDIT_SHA256);
  assert.deepEqual(comparison.diffs.map((difference) => ({
    category: difference.category,
    kind: difference.kind,
    path: difference.path,
  })), [
    { category: 'value', kind: 'byte-envelope', path: '/bytes/byteLength' },
    { category: 'value', kind: 'byte-envelope', path: '/bytes/sha256' },
    { category: 'value', kind: 'direct-content', path: X_EDIT_PATH },
  ]);
});

test('X-edited output reparses into the same production model except for PRODUCT_DATE.x', () => {
  const { runtime: firstRuntime, saved } = saveWithProductDateX(999);
  const reparsed = createProductionCiffRuntime(saved.bytes);
  const expectedGeometry = fieldGeometry(firstRuntime);

  assert.equal(reparsed.state.fieldByName.get('PRODUCT_DATE').geom.x, 999);
  assert.deepEqual(fieldGeometry(reparsed), expectedGeometry);
  assert.deepEqual(
    Array.from(reparsed.state.fields, (field) => field.sourceName),
    Array.from(firstRuntime.state.fields, (field) => field.sourceName),
  );
});

test('save and reparse with a fixed native selection and clock remain byte-identical', () => {
  const { saved: firstSave } = saveWithProductDateX(999);
  const reparsed = createProductionCiffRuntime(firstSave.bytes);
  const secondSave = saveWithImportedSelection(reparsed);
  const comparison = compareCiffBuffers(firstSave.bytes, secondSave.bytes);

  assert.equal(secondSave.prepared.validation.ok, true, plain(secondSave.prepared.validation));
  assert.equal(secondSave.bytes.equals(firstSave.bytes), true);
  assert.equal(secondSave.bytes.length, 12912);
  assert.equal(secondSave.sha256, X_EDIT_SHA256);
  assert.deepEqual(comparison.diffs, []);
});
