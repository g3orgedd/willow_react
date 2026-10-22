const test = require('node:test');
const assert = require('node:assert/strict');

const {
  generateReferenceCase,
} = require('../scripts/generate-glyph-reference-case.cjs');
const {
  analyzeCiffBuffer,
} = require('../scripts/compare-ciff-structure.cjs');
const { collectSourceEvidence, decryptClStText, inspectCoreLayout } = require('../scripts/inspect-clst.cjs');

const ALLOWED_VALUE_DIFFERENCE = /^(?:\/bytes\/(?:byteLength|sha256)|\/ImageDesign\/SubImage\[ImageReference="1"\]\/Field\[Name="[^"]+"\]\/(?:X|Y)|\/ImageDesign\/SubImage\[ImageReference="1"\]\/Field\[Name="Field00"\]\/Barcode\/BcH)$/;
const EXPECTED_HELPER_LENGTH_DIFFERENCES = new Set([
  '/ImageDesign/SubImage[ImageReference="1"]/Field[Name="\u04211"]/Data/Object/MaxNoOfChars',
  '/ImageDesign/SubImage[ImageReference="1"]/Field[Name="GTIN"]/Data/Object/MaxNoOfChars',
  '/ImageDesign/SubImage[ImageReference="1"]/Field[Name="GTIN"]/Data/Object/FixedLen',
  '/ImageDesign/SubImage[ImageReference="1"]/Field[Name="SN"]/Data/Object/MaxNoOfChars',
  '/ImageDesign/SubImage[ImageReference="1"]/Field[Name="SN"]/Data/Object/FixedLen',
  '/ImageDesign/SubImage[ImageReference="1"]/Field[Name="KRIPTO"]/Data/Object/MaxNoOfChars',
  '/ImageDesign/SubImage[ImageReference="1"]/Field[Name="KRIPTO"]/Data/Object/FixedLen',
]);
const EXPECTED_LATIN_HELPER_RENAMES = new Map([
  ['\u04211', 'C1'],
  ['\u04212', 'C2'],
]);

test('production preset generator matches the ClariSoft order with intentional Latin helper names', () => {
  const generated = generateReferenceCase({ write: false });
  const { comparison, result } = generated;

  assert.equal(result.ok, true);
  assert.deepEqual(Array.from(result.fields, (field) => field.name), [
    'Field00',
    'PRODUCT_DATE',
    'EXPIRATION_DATE',
    'PARTY',
    'TEAM',
    'R_NUM',
    'C1',
    'GTIN',
    'C2',
    'SN',
    'C3',
    'KRIPTO',
  ]);

  assert.ok(comparison.diffs.length > 0, 'known layout and helper-name differences remain');
  const evidence = collectSourceEvidence(generated.generatedBytes.subarray(2).toString('utf16le'));
  const clst = inspectCoreLayout(decryptClStText(evidence.token, 'TpyRcNeyeK'), evidence);
  assert.equal(clst.consistent, true);
  assert.equal(clst.matchesSelectedCalcData, true);
  assert.ok(clst.selectedFieldIndices.length >= 1 && clst.selectedFieldIndices.length <= 3);
  comparison.diffs.forEach((difference) => {
    if (/^\/ImageDesign\/SubImage\[ImageReference="1"\]\/Field\[Name="[^"]+"\]\/LoggedField$/.test(difference.path)) {
      // New fields choose the native Not Logged default. The reference fixture
      // explicitly contains a different empty logging state, retained on import.
      assert.equal(difference.category, 'missing');
      assert.equal(difference.expected, 'LoggedField');
      assert.equal(difference.actual, null);
      return;
    }
    if (difference.path === '/ImageDesign/Header/ClStVersionInfo') {
      assert.equal(difference.category, 'value');
      return; // Native random selection can differ from the reference fixture.
    }
    // The draft requests 39.17 x 28.92 mm. Persist that physical area rather
    // than copying the reference's full-head workspace (53.33 x 75 mm).
    const physicalArea = {
      '/ImageDesign/SubImage[ImageReference="1"]/SubHeader/MaxImageWidth': ['5333', '3917'],
      '/ImageDesign/SubImage[ImageReference="1"]/SubHeader/MaxImageHeight': ['7500', '2892'],
    }[difference.path];
    if (physicalArea) {
      assert.equal(difference.category, 'value');
      assert.deepEqual(difference.expected, [{ type: 'text', value: physicalArea[0] }]);
      assert.deepEqual(difference.actual, [{ type: 'text', value: physicalArea[1] }]);
      return;
    }
    const expectedLatinName = EXPECTED_LATIN_HELPER_RENAMES.get(difference.expected);
    if (expectedLatinName) {
      assert.equal(difference.actual, expectedLatinName, `${difference.category}: ${difference.path}`);
      assert.ok(['attribute', 'unicode', 'reference'].includes(difference.category), difference.category);
      assert.match(difference.path, /(?:@(?:Name|SrcFieldName)|\/references\/field-reference#)/);
      return;
    }
    if (EXPECTED_HELPER_LENGTH_DIFFERENCES.has(difference.path)) {
      assert.equal(difference.category, 'extra');
      assert.equal(difference.expected, null);
      assert.ok(['MaxNoOfChars', 'FixedLen'].includes(difference.actual));
      return;
    }
    assert.equal(difference.category, 'value', `${difference.category}: ${difference.path}`);
    assert.match(difference.path, ALLOWED_VALUE_DIFFERENCE);
  });
  const expectedMaxByName = new Map([
    ['C1', 4],
    ['GTIN', 14],
    ['C2', 2],
    ['SN', 13],
    ['C3', 7],
    ['KRIPTO', 4],
  ]);
  const userEnteredNames = new Set(['GTIN', 'SN', 'KRIPTO']);
  for (const [name, maxChars] of expectedMaxByName) {
    assert.equal(result.fields.find((field) => field.name === name).data.maxChars, maxChars, name);
    assert.equal(result.fields.find((field) => field.name === name).data.fixedLen, userEnteredNames.has(name), name);
  }

  const generatedAnalysis = analyzeCiffBuffer(generated.generatedBytes);
  assert.equal(generatedAnalysis.bom, 'FF FE');
  assert.equal(generatedAnalysis.encoding, 'UTF-16LE');
  assert.equal(generatedAnalysis.declarationEncoding, 'UTF-16');
  assert.equal(generatedAnalysis.crlfCount, 2);
  assert.equal(generatedAnalysis.loneLfCount, 0);
  assert.equal(generatedAnalysis.loneCrCount, 0);
  assert.equal(generatedAnalysis.nonEmptyLineCount, 2);
  assert.equal(generatedAnalysis.twoLineLayout, true);
  assert.equal(generatedAnalysis.finalCrLf, true);
});

test('generated reference DataMatrix has synchronized source values and CalcData', () => {
  const { result } = generateReferenceCase({ write: false });
  const barcode = result.fields.find((field) => field.barcode?.dataMatrix);
  const sourceByName = new Map(result.fields.map((field) => [field.name, field]));
  const sourceValue = (field) => field.data?.userEnterData || field.data?.defaultValue || field.calcData || '';

  const segmentValues = barcode.barcode.dataMatrix.segments.map((segment) => {
    const source = sourceByName.get(segment.srcField);
    assert.ok(source, `missing ${segment.srcField}`);
    assert.equal(segment.defaultValue, sourceValue(source));
    return segment.defaultValue;
  });

  assert.equal(barcode.calcData, segmentValues.join(''));
  assert.equal(barcode.calcData, '~10100000000000000210000000000000~d029930000');
});
