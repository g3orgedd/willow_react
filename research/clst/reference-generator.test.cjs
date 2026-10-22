'use strict';
const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const { encrypt, randomIndexFromTick, createSelectionMask, metadataName, generateClStReference } = require('./reference-generator.cjs');
const { decryptClStText, collectSourceEvidence, inspectCoreLayout, inspectOptionalLayout } = require('../../scripts/inspect-clst.cjs');

test('reference cipher matches all saved independently executed DLL cases, including native key bounds', () => {
  const cases = JSON.parse(fs.readFileSync(path.join(__dirname, 'native/oracle-comparison-cases.json'), 'utf8'));
  assert.equal(cases.length, 204);
  for (const item of cases) assert.equal(encrypt(item.input, item.key), item.native);
});

test('main pipeline matches native transform compositions for zero, empty-string and actual text fields', () => {
  const cases = JSON.parse(fs.readFileSync(path.join(__dirname, 'native/composition-results.json'), 'utf8')).cases;
  for (const item of cases) {
    const fieldCount = parseInt(item.counterKey.slice(4), 10);
    const fieldValues = item.fieldValues || Array(fieldCount).fill('');
    if (!item.fieldValues && fieldCount > 0) fieldValues[0] = item.selectedPayload;
    const output = generateClStReference({
      dateOffsetCount: item.dateOffsetCount ?? parseInt(item.counterKey.slice(0, 2), 10),
      subImageCount: item.subImageCount ?? parseInt(item.counterKey.slice(2, 4), 10),
      fieldValues, mask: item.maskHex,
    });
    assert.equal(output.clStVersionInfo, item.clStVersionInfo, item.description);
    assert.equal(output.intermediate, item.core, item.description);
  }
});

test('tick reseeding reproduces repeated picks rather than advancing a single PRNG', () => {
  assert.equal(randomIndexFromTick(0, 100), 38);
  assert.equal(randomIndexFromTick(1, 100), 41);
  const selection = createSelectionMask(5, (bound) => randomIndexFromTick(0, bound));
  assert.deepEqual(selection, { mask: 8, attempts: 3 });
  assert.equal(generateClStReference({ fieldValues: ['a', 'b', 'c', 'd', 'e'], tickCounts: [0, 0, 0, 0] }).maskHex, '00000008');
  assert.throws(() => generateClStReference({ fieldValues: ['a'], tickCounts: [0] }), /enough/);
});

test('explicit mask preserves native collection order and truncation by UTF-16 units', () => {
  const fields = Array(32).fill('');
  fields[0] = 'A';
  fields[4] = 'B'.repeat(18);
  fields[31] = '😀Z';
  const output = generateClStReference({ fieldValues: fields, mask: '80000011' });
  assert.equal(output.maskHex, '80000011');
  assert.equal(output.tagData, ('A' + 'B'.repeat(18) + '😀Z').slice(0, 20));
  assert.equal(output.tagData.length, 20);
});

test('metadata basename and extension match independently executed native path splitting cases', () => {
  const cases = fs.readFileSync(path.join(__dirname, 'optional/splitpath-cases.jsonl'), 'utf8').trim().split(/\r?\n/).map(JSON.parse);
  assert.ok(cases.length >= 28);
  for (const item of cases) assert.equal(metadataName(item.sourcePath), item.metadataPlaintext, item.sourcePath);
});

test('optional assembly matches native split and cipher compositions at every intermediate step', () => {
  const cases = JSON.parse(fs.readFileSync(path.join(__dirname, 'optional/optional-composition-results.json'), 'utf8')).cases;
  assert.equal(cases.length, 8);
  for (const item of cases) {
    const output = generateClStReference(item.input);
    for (const key of ['fileMetadata', 'metadataFragment', 'metadataLengthFragment', 'normalIntermediate', 'intermediate', 'clStVersionInfo']) {
      assert.equal(output[key], item[key], `${key}: ${item.input.sourcePath}`);
    }
  }
});

test('optional layout can be inspected independently, including filename and inner selection', () => {
  const output = generateClStReference({ fieldValues: ['21:22'], mask: '1', includeFileMetadata: true, sourcePath: 'C:\\labels\\Report.ciff.new' });
  const evidence = collectSourceEvidence('<ImageDesign><Header/><SubImage><Field Name="TIME"><CalcData>21:22</CalcData></Field></SubImage></ImageDesign>');
  const decoded = decryptClStText(output.clStVersionInfo, 'TpyRcNeyeK');
  const optional = inspectOptionalLayout(decoded, evidence);
  assert.equal(optional.plausible, true);
  assert.equal(optional.fileDataWithAssumedKey, 'Report.ciff');
  assert.equal(optional.fileLengthHex, '00000021');
  assert.equal(optional.core.maskHex, '00000001');
  assert.equal(optional.core.tagData, '21:22');
  const main = inspectCoreLayout(decryptClStText(generateClStReference({ fieldValues: [], subImageCount: 1 }).clStVersionInfo, 'TpyRcNeyeK'), { ...evidence, counts: { fieldCount: 0 } });
  assert.equal(main.maskHex, '00000000');
});

test('reference rejects unresolved selected values and masks not produced by the native selection', () => {
  assert.throws(() => generateClStReference({ fieldValues: [null], mask: '1' }), /actual TagData/);
  assert.throws(() => generateClStReference({ fieldValues: ['a'], mask: '0' }), /one to three/);
  assert.throws(() => generateClStReference({ fieldValues: ['a'], mask: '1xyz' }), /hexadecimal/);
  assert.throws(() => generateClStReference({ fieldValues: ['a'], mask: '2' }), /outside/);
  assert.throws(() => generateClStReference({ fieldValues: [], mask: '1' }), /outside/);
});
