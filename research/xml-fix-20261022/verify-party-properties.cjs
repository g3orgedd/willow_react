const fs = require('node:fs');
const path = require('node:path');
const assert = require('node:assert/strict');
const crypto = require('node:crypto');
const root = path.resolve(__dirname, '../..');
const { ComparatorDomParser } = require(path.join(root, 'tests/helpers/ciff-production-harness.cjs'));
const output = path.resolve(process.argv[2] || path.join(__dirname, 'exports-party'));
const loaded = JSON.parse(fs.readFileSync(path.join(output, 'native-validation.json'), 'utf8').replace(/^\uFEFF/, ''));
const text = (node, selector) => node?.querySelector(selector)?.textContent ?? null;
const fromUnits = units => String.fromCharCode(...units);
const sha256 = filename => crypto.createHash('sha256').update(fs.readFileSync(filename)).digest('hex').toUpperCase();
function props(field) {
  const object = field.querySelector(':scope > Data > Object');
  return {
    name: field.getAttribute('Name'), type: text(field, ':scope > FldType'),
    displayed: text(field, ':scope > Displayed') ?? '1',
    maxChars: text(object, ':scope > MaxNoOfChars'), defaultValue: text(object, ':scope > Default'),
    userEnterData: text(object, ':scope > VarText > UserEnterData'), fixedLen: Boolean(object?.querySelector(':scope > FixedLen')),
    dataType: text(object, ':scope > DataType'), staticAttr: object?.getAttribute('Static') ?? '1',
    face: text(field, ':scope > Text > Font > Face') ?? 'Arial',
    pitch: text(field, ':scope > Text > Font > Pitch') ?? '13',
    xMag: text(field, ':scope > Text > Font > XMag') ?? '100',
    calculatedData: text(field, ':scope > CalcData') ?? ''
  };
}
const results = [];
for (const row of loaded.cases.filter(row => row.caseId.startsWith('party-'))) {
  const narrowSnPreviewGap = row.status === 'mismatch' && row.comparisonErrors.length === 1
    && row.comparisonErrors[0].startsWith('SN.Native metrics mismatch:');
  assert.ok(row.status === 'ok' || narrowSnPreviewGap, row.name + ': native check has errors beyond the separately reported SN preview gap');
  assert.equal(row.validate, '00000000'); assert.equal(row.validate2, '00000000');
  assert.equal(row.sourceSha256, row.sourceSha256After);
  assert.equal(sha256(row.file), row.sourceSha256);
  const source = fs.readFileSync(row.file).subarray(2).toString('utf16le');
  const sourceDoc = new ComparatorDomParser().parseFromString(source);
  const nativeDoc = new ComparatorDomParser().parseFromString(row.nativeCanonicalXml);
  const fields = sourceDoc.querySelectorAll('ImageDesign > SubImage > Field');
  const nativeFields = nativeDoc.querySelectorAll('ImageDesign > SubImage > Field');
  const byName = new Map(fields.map(field => [field.getAttribute('Name'), props(field)]));
  const withBox = row.caseId === 'party-box-gtin';
  const gtin = withBox ? 'GTIN' : 'GTIN2';
  const order = ['C1', gtin, 'C3', 'PRODUCT_DATE', 'C2', 'SN', ...(withBox ? ['C4', 'BOX_COUNTER'] : [])];
  const barcode = fields.find(field => text(field, ':scope > FldType') === 'Barcode');
  const nativeBarcode = nativeFields.find(field => field.getAttribute('Name') === barcode.getAttribute('Name'));
  const segmentNames = field => field.querySelectorAll(':scope > Data > Object')
    .map(object => object.querySelector(':scope > SrcField')?.getAttribute('SrcFieldName'));
  assert.deepEqual(segmentNames(barcode), order);
  assert.deepEqual(segmentNames(nativeBarcode), order);
  assert.equal(fields.length, withBox ? 9 : 7);
  assert.deepEqual(fields.map(field => field.getAttribute('Name')), nativeFields.map(field => field.getAttribute('Name')));
  for (let index = 0; index < fields.length; index++) {
    assert.deepEqual(props(fields[index]), props(nativeFields[index]), row.name + ': properties changed in native canonical writer');
    const nativeValue = row.afterNativeResolve.find(field => field.name === fields[index].getAttribute('Name'));
    assert.equal(fromUnits(nativeValue.calculatedDataUnits), text(fields[index], ':scope > CalcData') ?? '');
  }
  for (const [name, max, initial] of [[gtin, 14, '0'.repeat(14)], ['PRODUCT_DATE', 6, '000000'], ['SN', 12, '0'.repeat(10)], ...(withBox ? [['BOX_COUNTER', 5, '00000']] : [])]) {
    const field = byName.get(name);
    assert.equal(field.type, 'FixedText'); assert.equal(field.displayed, '0');
    assert.equal(field.dataType, '0'); assert.equal(field.maxChars, String(max)); assert.equal(field.staticAttr, '0');
    assert.equal(field.defaultValue, initial); assert.equal(field.userEnterData, initial); assert.equal(field.fixedLen, true);
  }
  for (const name of order) {
    assert.equal(byName.get(name).pitch, '10'); assert.equal(byName.get(name).xMag, '100');
    assert.equal(byName.get(name).face, 'Arial'); assert.equal(byName.get(name).displayed, '0');
  }
  assert.equal(byName.get('SN').calculatedData, '0'.repeat(10) + '  ');
  const expectedPayload = '~101' + '0'.repeat(14) + '11' + '000000' + '10' + '0'.repeat(10) + '  ' + (withBox ? '2100000' : '');
  assert.equal(text(barcode, ':scope > CalcData'), expectedPayload);
  const rendererEvidence = JSON.parse(fs.readFileSync(row.expectedFile, 'utf8'));
  const previewBarcode = rendererEvidence.preSave.fields.find(field => field.type === 'Barcode');
  if (Array.isArray(previewBarcode?.dataMatrixPreviewSegmentValues)) {
    assert.equal(previewBarcode.dataMatrixPreviewSegmentValues.join(''), expectedPayload, row.name + ': actual DM preview payload differs from saved/native payload');
  }
  const measuredBarcode = row.fields.find(field => field.before.type === 'Barcode');
  assert.equal(measuredBarcode.widthDots, 132); assert.equal(measuredBarcode.heightDots, 132);
  results.push({
    name: row.name, caseId: row.caseId, originalLoaderAccepted: true, validate: row.validate, validate2: row.validate2,
    fields: fields.length, gtinFieldName: gtin, segmentOrder: order, allHelperFontPitch: 10,
    fixedLengthPaddingExact: true, nativeResolvedValuesExact: true, nativeCanonicalPropertiesExact: true,
    allPreviewMetricsExact: !narrowSnPreviewGap, previewMetricDifferences: narrowSnPreviewGap ? row.comparisonErrors : [],
    image: { width: row.images[0].dimensions.ImageWidth, height: row.images[0].dimensions.ImageHeight },
    max: { width: row.images[0].dimensions.MaxImageWidth, height: row.images[0].dimensions.MaxImageHeight },
    dataMatrixDots: { width: measuredBarcode.widthDots, height: measuredBarcode.heightDots },
    unchangedSha256: row.sourceSha256
  });
}
fs.writeFileSync(path.join(output, 'party-properties-summary.json'), JSON.stringify({ verifiedAt: new Date().toISOString(), cases: results }, null, 2));
console.log(JSON.stringify({ verified: results.length, exactSourceNativeProperties: true, orderAndPaddingExact: true }));
