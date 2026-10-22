const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');
const assert = require('node:assert/strict');
const crypto = require('node:crypto');
const root = path.resolve(__dirname, '../..');
const output = path.join(__dirname, 'exported-web');
const { ComparatorDomParser } = require(path.join(root, 'tests/helpers/ciff-production-harness.cjs'));
const { collectSourceEvidence } = require(path.join(root, 'scripts/inspect-clst.cjs'));
const loaded = JSON.parse(fs.readFileSync(path.join(output, 'native-validation.json'), 'utf8'));
const rendered = JSON.parse(fs.readFileSync(path.join(output, 'native-components.json'), 'utf8'));
const inputs = JSON.parse(fs.readFileSync(path.join(output, 'native-inputs.json'), 'utf8').replace(/^\uFEFF/, ''));
const ctx = vm.createContext({});
for (const file of ['encryption', 'tag-data', 'version-info']) vm.runInContext(fs.readFileSync(path.join(root, `public/modules/clst/${file}.js`), 'utf8'), ctx);
const api = vm.runInContext('({ decodeClStVersionInfo, buildClStVersionInfoDebugInfo })', ctx);
const units = value => String.fromCharCode(...value);
const sha256 = file => crypto.createHash('sha256').update(fs.readFileSync(file)).digest('hex').toUpperCase();
const text = (node, selector) => node?.querySelector(selector)?.textContent ?? null;
const properties = field => {
  const object = field.querySelector(':scope > Data > Object');
  return {
    name: field.getAttribute('Name'), type: text(field, ':scope > FldType'),
    displayed: text(field, ':scope > Displayed') ?? '1', maxChars: text(object, ':scope > MaxNoOfChars'),
    default: text(object, ':scope > Default'), userEnterData: text(object, ':scope > VarText > UserEnterData'),
    fixedLen: Boolean(object?.querySelector(':scope > FixedLen')), staticAttr: object?.getAttribute('Static') ?? null,
    pitch: text(field, ':scope > Text > Font > Pitch'), xMag: text(field, ':scope > Text > Font > XMag') ?? '100',
    calcData: text(field, ':scope > CalcData'),
  };
};
const results = [];
for (const row of loaded.cases) {
  assert.equal(row.status, 'ok'); assert.equal(row.validate, '00000000'); assert.equal(row.validate2, '00000000');
  assert.equal(row.sourceSha256, row.sourceSha256After);
  const input = inputs.find(item => item.file === row.file);
  assert.equal(sha256(input.originalSource), row.sourceSha256);
  const xml = fs.readFileSync(row.file).subarray(2).toString('utf16le');
  const sourceDom = new ComparatorDomParser().parseFromString(xml);
  const nativeDom = new ComparatorDomParser().parseFromString(row.regeneratedXml);
  const sourceFields = sourceDom.querySelectorAll('ImageDesign > SubImage > Field');
  const nativeFields = nativeDom.querySelectorAll('ImageDesign > SubImage > Field');
  const expectedOrder = ['C1', 'GTIN2', 'C3', 'PRODUCT_DATE', 'C2', 'SN'];
  const withBox = row.name.includes('with-box-counter');
  if (withBox) expectedOrder.push('C4', 'BOX_COUNTER');
  const barcode = sourceFields.find(field => text(field, ':scope > FldType') === 'Barcode');
  const nativeBarcode = nativeFields.find(field => field.getAttribute('Name') === barcode.getAttribute('Name'));
  const sourceSegments = barcode.querySelectorAll(':scope > Data > Object').map(object => object.querySelector(':scope > SrcField')?.getAttribute('SrcFieldName'));
  const nativeSegments = nativeBarcode.querySelectorAll(':scope > Data > Object').map(object => object.querySelector(':scope > SrcField')?.getAttribute('SrcFieldName'));
  assert.deepEqual(sourceSegments, expectedOrder); assert.deepEqual(nativeSegments, expectedOrder);
  assert.equal(sourceFields.length, withBox ? 9 : 7);
  assert.deepEqual(sourceFields.map(field => field.getAttribute('Name')), row.loadedFields.map(field => field.name));
  assert.deepEqual(sourceFields.map(field => field.getAttribute('Name')), nativeFields.map(field => field.getAttribute('Name')));
  for (let index = 0; index < sourceFields.length; index++) {
    const expected = properties(sourceFields[index]);
    const native = properties(nativeFields[index]);
    assert.deepEqual(native, expected, row.name + ':' + expected.name + ': native XML properties changed');
    assert.equal(units(row.loadedFields[index].calculatedDataUnits), expected.calcData);
    assert.equal(units(row.afterNativeResolve[index].calculatedDataUnits), expected.calcData);
  }
  const byName = new Map(sourceFields.map(field => [field.getAttribute('Name'), properties(field)]));
  for (const [name, maxChars, initial] of [['GTIN2', '14', '0'.repeat(14)], ['PRODUCT_DATE', '6', '000000'], ['SN', '12', '0'.repeat(10)], ...(withBox ? [['BOX_COUNTER', '5', '00000']] : [])]) {
    const field = byName.get(name);
    assert.equal(field.type, 'FixedText'); assert.equal(field.displayed, '0'); assert.equal(field.maxChars, maxChars);
    assert.equal(field.default, initial); assert.equal(field.userEnterData, initial); assert.equal(field.fixedLen, true); assert.equal(field.staticAttr, '0');
  }
  assert.equal(byName.get('SN').calcData, '0'.repeat(10) + '  ');
  for (const [name, value] of [['C1', '~101'], ['C2', '10'], ['C3', '11'], ...(withBox ? [['C4', '21']] : [])]) assert.equal(byName.get(name).default, value);
  assert.equal(text(barcode, ':scope > CalcData'), '~101' + '0'.repeat(14) + '11' + '000000' + '10' + '0'.repeat(10) + '  ' + (withBox ? '2100000' : ''));
  const evidence = collectSourceEvidence(xml);
  const sourceGroups = [{ fields: row.loadedFields.map(field => ({ name: field.name, calculatedData: units(field.calculatedDataUnits) })) }];
  for (const token of [row.loadedToken, row.regeneratedToken]) {
    const decoded = api.decodeClStVersionInfo(token, { fieldCount: row.loadedFields.length, sourcePath: row.file });
    const rebuilt = api.buildClStVersionInfoDebugInfo({ dateOffsets: Array(evidence.counts.dateOffsetCount).fill({}), subImages: sourceGroups }, new Date('2026-10-21T00:00:00Z'), {
      mask: decoded.maskHex, includeFileMetadata: decoded.includeFileMetadata, sourcePath: row.file,
    });
    assert.equal(rebuilt.clStVersionInfo, token);
  }
  const components = rendered.cases.find(item => item.file === row.file);
  assert.equal(components.sourceSHA256, components.sourceSHA256After);
  const drawGeometryAdjustments = [];
  for (const field of components.fields) {
    assert.equal(field.status, 'ok'); assert.ok(fs.existsSync(field.bitmap));
    assert.deepEqual(field.before, field.afterUpdate); assert.deepEqual(field.before, field.afterSize);
    for (const key of ['name', 'type', 'x', 'y', 'orientation', 'calcData']) assert.equal(field.afterDraw[key], field.before[key]);
    if (field.before.w !== field.afterDraw.w || field.before.h !== field.afterDraw.h) drawGeometryAdjustments.push({
      name: field.name, printed: byName.get(field.name).displayed !== '0', before: { w: field.before.w, h: field.before.h },
      afterDraw: { w: field.afterDraw.w, h: field.afterDraw.h }, widthDots: field.widthDots, heightDots: field.heightDots,
    });
    if (field.font) {
      assert.equal(field.font.face, 'Arial'); assert.equal(String(field.font.pitch), byName.get(field.name).pitch); assert.equal(String(field.font.xMag), byName.get(field.name).xMag);
    }
  }
  const nativeDm = components.fields.find(field => field.name === barcode.getAttribute('Name'));
  assert.equal(nativeDm.widthDots, 132); assert.equal(nativeDm.heightDots, 132);
  results.push({ name: row.name, fieldCount: sourceFields.length, segmentOrder: expectedOrder, originalLoaderAccepted: true,
    validate: row.validate, validate2: row.validate2, loadedPropertiesExact: true, nativeResolveCalculatedDataExact: true,
    serialDefaultLength: 10, serialMaximumLength: 12, serialCalcData: byName.get('SN').calcData,
    originalAndNativeRegeneratedTokenRecompositionExact: true, componentUpdateSizeDrawFields: components.fields.length,
    updateAndCalculatePreserveStoredGeometry: true, drawPreservesPositionAndData: true, drawGeometryAdjustments,
    barcodeDots: { width: nativeDm.widthDots, height: nativeDm.heightDots },
    sourceSHA256: row.sourceSha256, originalDownloadUnchanged: true });
}
const dll = 'C:/Program Files (x86)/CLARICOM/Data/CiffMgr.dll';
const summary = { date: '2026-10-21', method: 'Original installed 32-bit COM loader, two validators, ResolveField, native XML serialization, text/small-barcode CalculateSize and Draw. This is not a GUI screenshot or physical printer test.',
  ciffManager: { file: dll, sha256: sha256(dll) }, cases: results, accepted: results.length };
fs.writeFileSync(path.join(output, 'native-verification-summary.json'), JSON.stringify(summary, null, 2) + '\n');
console.log(JSON.stringify({ accepted: results.length, sourceOrderPropertiesAndPaddingExact: true, originalDownloadHashesUnchanged: true, originalNativeComponentFields: rendered.cases.flatMap(item => item.fields).length }));
