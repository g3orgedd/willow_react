const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');

const {
  analyzeCiffFile,
  compareCiffBuffers,
  compareCiffFiles,
  formatReport,
  parseXml,
} = require('../scripts/compare-ciff-structure.cjs');

const FIXTURE_DIR = path.join(__dirname, 'fixtures', 'clarisoft');
const CLARISOFT_PATH = path.join(FIXTURE_DIR, 'Clarisoft_test_1.ciff');
const GLYPH_PATH = path.join(FIXTURE_DIR, 'Glyph_test_1.ciff');

function utf16Ciff(xml) {
  return Buffer.concat([
    Buffer.from([0xff, 0xfe]),
    Buffer.from(`<?xml version="1.0" encoding="UTF-16"?>\r\n${xml}\r\n`, 'utf16le'),
  ]);
}

test('ordered comparator fixtures remain byte-identical to the supplied files', () => {
  const clarisoft = analyzeCiffFile(CLARISOFT_PATH);
  const glyph = analyzeCiffFile(GLYPH_PATH);

  assert.equal(clarisoft.sha256, '5221DC212883631146E4D26E2BB5AF3D38E440D0EA458C73BF4B18E5175BB63D');
  assert.equal(glyph.sha256, '112420E4053C789F591EFD3AD44BAB9AC7EB76F1E477E14DF4AB5BDA5E1FDC52');
  for (const fixture of [clarisoft, glyph]) {
    assert.equal(fixture.bom, 'FF FE');
    assert.equal(fixture.encoding, 'UTF-16LE');
    assert.equal(fixture.declarationEncoding, 'UTF-16');
    assert.equal(fixture.crlfCount, 2);
    assert.equal(fixture.loneLfCount, 0);
    assert.equal(fixture.loneCrCount, 0);
    assert.equal(fixture.nonEmptyLineCount, 2);
    assert.equal(fixture.twoLineLayout, true);
    assert.equal(fixture.finalCrLf, true);
  }
});

test('real comparison is deterministic and reports ordered fields with code points', () => {
  const first = compareCiffFiles(CLARISOFT_PATH, GLYPH_PATH);
  const second = compareCiffFiles(CLARISOFT_PATH, GLYPH_PATH);
  assert.deepEqual(second, first);
  assert.ok(first.diffs.length > 0);
  assert.ok(first.fields.expected.length > 0);
  assert.ok(first.fields.actual.length > 0);
  first.fields.expected.concat(first.fields.actual).forEach((field) => {
    assert.equal(field.codePoints.length, [...field.name].length);
    assert.ok(field.codePoints.every((point) => /^U\+[0-9A-F]{4,6}$/.test(point)));
    assert.ok(Array.isArray(field.signature.fieldChildren));
    assert.ok(Array.isArray(field.signature.objects));
  });
  const report = formatReport(first);
  assert.match(report, /BYTE ENVELOPE/);
  assert.match(report, /FIELD NAME INVENTORY/);
  assert.match(report, /ORDERED STRUCTURAL DIFF/);
});

test('classifier distinguishes missing, extra, value, order, attribute, unicode and reference differences', () => {
  const confusableFieldName = `${String.fromCodePoint(0x0421)}1`;
  const expected = utf16Ciff(`<ImageDesign Version="23"><Header/><SubImage ImageReference="1"><Field Name="${confusableFieldName}"><FldType>FixedText</FldType><Data><Object><SrcField SrcFieldName="${confusableFieldName}"/></Object></Data><Text><Font><Pitch>8</Pitch><XMag>90</XMag></Font></Text></Field><Field Name="B"><FldType>FixedText</FldType><Data/><Text/></Field><OnlyExpected/></SubImage><ImageMapping><Map SubIMageRef="1">1</Map></ImageMapping></ImageDesign>`);
  const actual = utf16Ciff('<ImageDesign Version="24"><Header Extra="1"/><SubImage><Field Name="B"><Text/><Data/></Field><Field Name="C1"><FldType>FixedText</FldType><Data><Object><SrcField SrcFieldName="MISSING"/></Object></Data><Text><Font><Pitch>10</Pitch></Font></Text></Field><OnlyActual/></SubImage><ImageMapping><Map SubIMageRef="1">1</Map></ImageMapping></ImageDesign>');
  const report = compareCiffBuffers(expected, actual);
  const categories = new Set(report.diffs.map((diff) => diff.category));
  for (const category of ['missing', 'extra', 'value', 'order', 'attribute', 'unicode', 'reference']) {
    assert.equal(categories.has(category), true, `missing category ${category}`);
  }
  assert.ok(report.diffs.some((diff) => diff.category === 'unicode' && diff.details.expectedCodePoints.includes('U+0421')));
  assert.ok(report.diffs.some((diff) => diff.category === 'reference' && diff.kind === 'dangling-reference'));
});

test('fixture copies contain no accidental byte changes', () => {
  assert.equal(fs.statSync(CLARISOFT_PATH).size, 12914);
  assert.equal(fs.statSync(GLYPH_PATH).size, 13256);
});

test('comparison parser rejects a raw CDATA terminator outside a CDATA section', () => {
  assert.throws(
    () => parseXml('<ImageDesign><Value>a]]>b</Value></ImageDesign>'),
    /CDATA terminator outside CDATA/,
  );
  assert.doesNotThrow(
    () => parseXml('<ImageDesign><Value><![CDATA[a]]]]><![CDATA[>b]]></Value></ImageDesign>'),
  );
});
