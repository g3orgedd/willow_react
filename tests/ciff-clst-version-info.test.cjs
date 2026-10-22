'use strict';
const test = require('node:test');
const assert = require('node:assert/strict');
const vm = require('node:vm');
const { createProductionCiffRuntime } = require('./helpers/ciff-production-harness.cjs');
const { analyzeCiffBuffer } = require('../scripts/compare-ciff-structure.cjs');
const { generateClStReference } = require('../research/clst/reference-generator.cjs');
const NOW = new Date(2026, 9, 21, 21, 22, 37, 500);
const PRINTER = 'DataFlex 6330(53mm) - Continuous';

function encodeCiff(text) { return Buffer.concat([Buffer.from([0xFF, 0xFE]), Buffer.from(text, 'utf16le')]); }
function decodeCiff(bytes) {
  assert.equal(bytes[0], 0xFF); assert.equal(bytes[1], 0xFE);
  return bytes.subarray(2).toString('utf16le');
}
function readToken(bytes) { return decodeCiff(bytes).match(/<ClStVersionInfo(?:\s[^>]*)?>([\s\S]*?)<\/ClStVersionInfo>/)?.[1] ?? null; }
function fieldXml(name, value, options = {}) {
  const type = options.type ?? 'FixedText';
  return `<Field Name="${name}"><FldType>${type}</FldType>` + (options.hidden ? '<Displayed>0</Displayed>' : '') +
    '<X>100</X><Y>100</Y><W>100</W><H>100</H><Ln>1</Ln>' +
    `<CalcData><![CDATA[${value}]]></CalcData><Data><Object Static="1" Reference="">` +
    `<DataType>${type === 'TimeText' ? 1 : 0}</DataType><Default><![CDATA[${options.defaultValue ?? value}]]></Default></Object></Data>` +
    '<Text><Font><Pitch>8</Pitch></Font></Text></Field>';
}
function sourceCiff(subImages = [['alpha']], headerMarkup = '<ClStVersionInfo>INVALID_LOADED_VALUE</ClStVersionInfo>') {
  const images = subImages.map((fields, index) => `<SubImage ImageReference="${index + 1}">` +
    '<SubHeader FormatName="Default" PrinterFormatName="Default"><ImageWidth>1000</ImageWidth>' +
    '<ImageHeight>1000</ImageHeight><MaxImageWidth>5333</MaxImageWidth><MaxImageHeight>7500</MaxImageHeight>' +
    '<XRes>0.120000</XRes><CurrentOrientation>0</CurrentOrientation></SubHeader>' +
    fields.map((value, fieldIndex) => typeof value === 'string' ? fieldXml(`S${index}F${fieldIndex}`, value) :
      fieldXml(value.name ?? `S${index}F${fieldIndex}`, value.value, value)).join('') + '</SubImage>').join('');
  return encodeCiff('<?xml version="1.0" encoding="UTF-16"?>\r\n' +
    `<ImageDesign Version="23" xml:space="default"><Header DesignedFor="${PRINTER}">${headerMarkup}</Header>` + images +
    '<GenericSettings><ImageMapping><Map SubIMageRef="1">1</Map></ImageMapping></GenericSettings></ImageDesign>\r\n');
}
function inspectToken(runtime, token) {
  runtime.context.__tokenToInspect = token;
  return vm.runInContext('decodeClStVersionInfo(__tokenToInspect)', runtime.context);
}
function saveWithMask(runtime, mask, options = {}) {
  const saved = runtime.save(NOW, { ...options, clstOptions: { ...(options.clstOptions || {}), mask } });
  assert.equal(saved.prepared.validation.ok, true, JSON.stringify(saved.prepared.validation));
  return saved;
}

test('empty CIFF uses the native 72-character path for every loaded token state', () => {
  for (const markup of ['', '<ClStVersionInfo/>', '<ClStVersionInfo>STALE_TOKEN</ClStVersionInfo>']) {
    const runtime = createProductionCiffRuntime(sourceCiff([[]], markup));
    const saved = saveWithMask(runtime, 0);
    assert.equal(readToken(saved.bytes), generateClStReference({ fieldValues: [], subImageCount: 1 }).clStVersionInfo);
    assert.equal(readToken(saved.bytes).length, 72);
    assert.equal(inspectToken(runtime, readToken(saved.bytes)).mask, 0);
  }
});
test('actual save honors an injected native mask and joins multiple selected CalculatedData values', () => {
  const values = ['alpha', 'beta', 'gamma'];
  const runtime = createProductionCiffRuntime(sourceCiff([values]));
  const saved = saveWithMask(runtime, 6);
  const decoded = inspectToken(runtime, readToken(saved.bytes));
  assert.equal(readToken(saved.bytes), generateClStReference({ fieldValues: values, mask: 6 }).clStVersionInfo);
  assert.equal(decoded.maskHex, '00000006'); assert.equal(decoded.tagData, 'betagamma');
  assert.equal(readToken(saved.bytes).length, 153);
  assert.equal(runtime.state.docMeta.clStVersionInfo, readToken(saved.bytes));
});
test('default save reseeds from ticks each call instead of selecting the first field', () => {
  let calls = 0;
  const values = ['alpha', 'beta', 'gamma', 'delta', 'epsilon'];
  const runtime = createProductionCiffRuntime(sourceCiff([values]), { getTickCount: () => { calls += 1; return 0; } });
  const saved = runtime.save(NOW);
  assert.equal(saved.prepared.validation.ok, true, JSON.stringify(saved.prepared.validation));
  assert.equal(readToken(saved.bytes), generateClStReference({ fieldValues: values, tickCounts: [0, 0, 0, 0] }).clStVersionInfo);
  assert.equal(inspectToken(runtime, readToken(saved.bytes)).mask, 8); assert.equal(calls, 4);
});
test('save reads later SubImages in native order, including hidden unknown types', () => {
  const runtime = createProductionCiffRuntime(sourceCiff([['FIRST'], [{ value: 'SECOND-IMAGE', type: 'VendorGraphic', hidden: true }]]));
  const saved = saveWithMask(runtime, 2);
  const decoded = inspectToken(runtime, readToken(saved.bytes));
  assert.equal(decoded.mask, 2); assert.equal(decoded.tagData, 'SECOND-IMAGE');
  assert.equal(readToken(saved.bytes), generateClStReference({ fieldValues: ['FIRST', 'SECOND-IMAGE'], subImageCount: 2, mask: 2 }).clStVersionInfo);
});
test('save preserves unsigned bit 31 when more than 32 fields exist', () => {
  const values = Array.from({ length: 33 }, (_, index) => `VALUE${index}`);
  const runtime = createProductionCiffRuntime(sourceCiff([values]));
  const saved = saveWithMask(runtime, '80000000');
  const decoded = inspectToken(runtime, readToken(saved.bytes));
  assert.equal(decoded.mask, 0x80000000); assert.equal(decoded.tagData, 'VALUE31');
  assert.equal(readToken(saved.bytes), generateClStReference({ fieldValues: values, mask: '80000000' }).clStVersionInfo);
});
test('selected empty CalculatedData of an unknown type is valid and retains its nonzero mask', () => {
  const runtime = createProductionCiffRuntime(sourceCiff([[{ value: '', type: 'VendorGraphic' }]]));
  const saved = saveWithMask(runtime, 1);
  const decoded = inspectToken(runtime, readToken(saved.bytes));
  assert.equal(decoded.mask, 1); assert.equal(decoded.tagData, ''); assert.equal(readToken(saved.bytes).length, 72);
  assert.notEqual(readToken(saved.bytes), generateClStReference({ fieldValues: [] }).clStVersionInfo);
});
test('missing, malformed, nested and duplicate imported tokens regenerate as one valid direct element', async (t) => {
  const variants = new Map([
    ['missing', ''], ['empty', '<ClStVersionInfo></ClStVersionInfo>'], ['self-closing', '<ClStVersionInfo/>'],
    ['whitespace', '<ClStVersionInfo> </ClStVersionInfo>'], ['arbitrary', '<ClStVersionInfo>SOME_EXISTING_VALID_VALUE</ClStVersionInfo>'],
    ['escaped underscore', '<ClStVersionInfo>INVALID\\_VALUE</ClStVersionInfo>'],
    ['nested', '<ClStVersionInfo><Vendor>BAD</Vendor></ClStVersionInfo>'],
    ['duplicate', '<ClStVersionInfo>FIRST</ClStVersionInfo><ClStVersionInfo>SECOND</ClStVersionInfo>'],
  ]);
  for (const [name, markup] of variants) await t.test(name, () => {
    const runtime = createProductionCiffRuntime(sourceCiff([['alpha']], markup));
    const saved = saveWithMask(runtime, 1);
    assert.equal((decodeCiff(saved.bytes).match(/<ClStVersionInfo\b/g) || []).length, 1);
    assert.equal(readToken(saved.bytes), generateClStReference({ fieldValues: ['alpha'], mask: 1 }).clStVersionInfo);
  });
});
test('a syntactically valid imported token is still rebuilt for the selected current value', () => {
  const imported = generateClStReference({ fieldValues: ['old'], mask: 1 }).clStVersionInfo;
  const runtime = createProductionCiffRuntime(sourceCiff([['alpha']], `<ClStVersionInfo>${imported}</ClStVersionInfo>`));
  const saved = saveWithMask(runtime, 1);
  assert.notEqual(readToken(saved.bytes), imported); assert.equal(inspectToken(runtime, readToken(saved.bytes)).tagData, 'alpha');
});
test('time resolves before both XML CalcData and the selected token payload', () => {
  const runtime = createProductionCiffRuntime(sourceCiff([[{ name: 'TIME', value: '00:00', type: 'TimeText', defaultValue: "HH':'mm" }]]));
  const saved = saveWithMask(runtime, 1);
  assert.equal(inspectToken(runtime, readToken(saved.bytes)).tagData, '21:22');
  assert.match(decodeCiff(saved.bytes), /<CalcData><!\[CDATA\[21:22\]\]><\/CalcData>/);
});
test('recognized optional filename mode survives Save As and binds to the new destination', () => {
  const imported = generateClStReference({ fieldValues: ['old'], mask: 1, includeFileMetadata: true, sourcePath: 'C:\\old\\Report.ciff' }).clStVersionInfo;
  const runtime = createProductionCiffRuntime(sourceCiff([['alpha']], `<ClStVersionInfo>${imported}</ClStVersionInfo>`), { sourcePath: 'C:\\labels\\Report.ciff' });
  assert.equal(runtime.state.docMeta.clStIncludeFileMetadata, true);
  const saved = saveWithMask(runtime, 1, { sourcePath: 'D:\\labels\\Renamed.ciff' });
  const decoded = inspectToken(runtime, readToken(saved.bytes));
  assert.equal(decoded.includeFileMetadata, true); assert.equal(decoded.fileMetadata, 'Renamed.ciff'); assert.equal(decoded.tagData, 'alpha');
  const reopened = createProductionCiffRuntime(saved.bytes, { sourcePath: 'D:\\labels\\Renamed.ciff' });
  assert.equal(reopened.state.docMeta.clStIncludeFileMetadata, true);
  assert.equal(inspectToken(reopened, readToken(saveWithMask(reopened, 1).bytes)).includeFileMetadata, true);
});
test('optional token for another filename does not enable the mode', () => {
  const imported = generateClStReference({ fieldValues: ['alpha'], mask: 1, includeFileMetadata: true, sourcePath: 'Report.ciff' }).clStVersionInfo;
  const runtime = createProductionCiffRuntime(sourceCiff([['alpha']], `<ClStVersionInfo>${imported}</ClStVersionInfo>`), { sourcePath: 'Other.ciff' });
  assert.equal(runtime.state.docMeta.clStIncludeFileMetadata, false);
  const saved = saveWithMask(runtime, 1);
  assert.equal(inspectToken(runtime, readToken(saved.bytes)).includeFileMetadata, false); assert.equal(readToken(saved.bytes).length, 117);
});
test('save fails explicitly when selected CalculatedData is unavailable', () => {
  const runtime = createProductionCiffRuntime(sourceCiff([['alpha']]));
  runtime.state.fields[0].fldType = 'VendorType';
  delete runtime.state.fields[0].calcData; delete runtime.state.fields[0].data.defaultValue;
  assert.throws(() => saveWithMask(runtime, 1), /CalculatedData.*unavailable/);
});
test('generated tokens survive UTF-16LE serialization, reparse and another save', () => {
  const runtime = createProductionCiffRuntime(sourceCiff([['alpha', 'beta', 'gamma']]));
  const first = saveWithMask(runtime, 6);
  const reopened = createProductionCiffRuntime(first.bytes);
  const second = saveWithMask(reopened, 6);
  for (const saved of [first, second]) {
    const analysis = analyzeCiffBuffer(saved.bytes);
    assert.equal(analysis.bom, 'FF FE'); assert.equal(analysis.encoding, 'UTF-16LE');
    assert.equal(analysis.declarationEncoding, 'UTF-16'); assert.equal(analysis.twoLineLayout, true);
    assert.equal(analysis.finalCrLf, true); assert.equal(analysis.loneLfCount, 0); assert.equal(analysis.loneCrCount, 0);
  }
  assert.equal(readToken(second.bytes), readToken(first.bytes));
});
