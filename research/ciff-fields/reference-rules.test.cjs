'use strict';
const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const { sanitizeCalculatedData, normalizeMsxmlLineEndings, resizeDataMatrix } = require('./reference-rules.cjs');
const { collectSourceEvidence, decryptClStText, inspectCoreLayout } = require('../../scripts/inspect-clst.cjs');
const { generateClStReference } = require('../clst/reference-generator.cjs');
const read = (name) => fs.readFileSync(path.join(__dirname, 'oracle', name + '.ciff')).subarray(2).toString('utf16le');
const cdata = (xml, tag) => xml.match(new RegExp(`<${tag}><!\\[CDATA\\[([\\s\\S]*?)\\]\\]></${tag}>`))?.[1];
const cases = JSON.parse(fs.readFileSync(path.join(__dirname, 'oracle-cases.json'), 'utf8'));

test('every native COM case has the expected success or property-gating rejection', () => {
  const results = JSON.parse(fs.readFileSync(path.join(__dirname, 'oracle/results.json'), 'utf8'));
  assert.equal(results.cases.length, cases.length);
  for (const definition of cases) {
    const item = results.cases.find((record) => record.name === definition.name);
    assert.ok(item, definition.name);
    if (definition.expectedError) {
      assert.equal(item.status, 'error', definition.name);
      assert.ok(item.error.includes(definition.expectedError), item.error);
    } else {
      assert.equal(item.status, 'ok', `${definition.name}: ${item.error}`);
      const bytes = fs.readFileSync(path.join(__dirname, 'oracle', item.file));
      assert.equal(bytes.subarray(0, 2).toString('hex'), 'fffe');
      assert.ok(bytes.subarray(2).toString('utf16le').endsWith('\r\n'));
    }
  }
});

test('calculated-data XML sanitizer matches the real DLL output and preserves allowed whitespace', () => {
  const definition = cases.find((item) => item.name === 'common-CalculatedData');
  assert.equal(cdata(read(definition.name), 'CalcData'), normalizeMsxmlLineEndings(sanitizeCalculatedData(definition.fields[0].properties.CalculatedData)));
});

test('native collections preserve field insertion order, sort Object indices, and replace duplicates', () => {
  assert.deepEqual([...read('field-collection-order').matchAll(/<Field Name="([^"]*)"/g)].map((m) => m[1]), ['Z', 'A', 'M']);
  assert.deepEqual([...read('data-collection-order').matchAll(/<Object Index="(\d+)"/g)].map((m) => Number(m[1])), [1, 5, 9]);
  const duplicateField = read('duplicate-field-name');
  assert.equal([...duplicateField.matchAll(/<Field /g)].length, 1);
  assert.ok(duplicateField.includes('<X>200</X>'));
  assert.equal(cdata(read('duplicate-data-index'), 'Default'), 'second');
});

test('native defaults and conditional XML children are observed independently of Glyph save logic', () => {
  const text = read('field-family-0-defaults');
  assert.ok(text.includes('<X>0</X><Y>0</Y><W>0</W><H>0</H><Data/><Text><Font/></Text>'));
  assert.ok(!text.includes('<Ln>'));
  assert.ok(!text.includes('<LoggedField'));
  assert.ok(read('logged-0').includes('<LoggedField></LoggedField>'));
  assert.ok(!read('logged-2').includes('<LoggedField'));
  assert.ok(read('data-flags-0').includes('<Object Reference="">'));
  assert.ok(read('data-flags-2').includes('<Object Index="2" Static="0" Parse="1" Reference="">'));
  assert.ok(read('block-default').includes('<Block><BlkW>0</BlkW><BlkH>0</BlkH><MinFontSize>0</MinFontSize></Block>'));
});

test('native runtime resolver covers operator text, padding, field references, and preview counters', () => {
  assert.equal(cdata(read('runtime-fixed'), 'CalcData'), 'Hello<&>');
  assert.equal(cdata(read('runtime-user'), 'CalcData'), 'OPERATOR');
  assert.equal(cdata(read('runtime-fixed-pad'), 'CalcData'), '000abc');
  const source = collectSourceEvidence(read('runtime-source-field'));
  assert.deepEqual(source.fieldSnapshots.map((field) => field.calcData), ['ABCDE', 'BCD']);
  assert.match(cdata(read('runtime-time'), 'CalcData'), /^\d{2}:\d{2}$/);
  assert.match(cdata(read('runtime-date'), 'CalcData'), /^\d{2}\/\d{2}\/\d{4}$/);
  assert.equal(cdata(read('runtime-counter'), 'CalcData'), '0000');
  assert.equal(cdata(read('runtime-counter'), 'CurrVal'), '42');
});

test('recovered DataMatrix resize reproduces native geometry, resolution quantization and margins', () => {
  const report = JSON.parse(fs.readFileSync(path.join(__dirname, 'dm-resize-results.json'), 'utf8'));
  assert.equal(report.cases.length, 6);
  for (const item of report.cases) {
    const actual = resizeDataMatrix({ width: item.requestedWidth, height: item.requestedHeight,
      columns: 22, rows: 22, xRes: item.xRes, yRes: item.yRes, quietMargins: item.quietMargins === 1 });
    assert.deepEqual(actual, { moduleSize: item.moduleSize, width: item.width, height: item.height, bcH: item.bcH });
  }
});

test('the full original COM generator agrees with recovered ClSt assembly for four templates', () => {
  for (const item of cases.filter((item) => item.generateClSt)) {
    const source = collectSourceEvidence(read(item.name));
    const core = inspectCoreLayout(decryptClStText(source.token, 'TpyRcNeyeK'), source);
    assert.equal(core.consistent, true);
    assert.equal(core.matchesSelectedCalcData, true);
    const generated = generateClStReference({ fieldValues: source.fieldSnapshots.map((field) => field.calcData ?? ''),
      dateOffsetCount: source.counts.dateOffsetCount, subImageCount: source.counts.subImageCount, mask: core.maskHex });
    assert.equal(generated.clStVersionInfo, source.token, item.name);
  }
});
