'use strict';
const fs = require('node:fs');
const path = require('node:path');
const assert = require('node:assert/strict');
const { buildReport } = require('../../scripts/inspect-clst.cjs');
const { generateClStReference } = require('../clst/reference-generator.cjs');
const cases = JSON.parse(fs.readFileSync(path.join(__dirname, 'oracle-cases.json'), 'utf8')).filter((item) => item.generateClSt);
const results = [];
for (const item of cases) {
  const file = path.join(__dirname, 'oracle', `${item.name}.ciff`);
  const report = buildReport([file]);
  const actual = report.files[0];
  assert.equal(actual.mainLayout.consistent, true);
  assert.equal(actual.mainLayout.matchesSelectedCalcData, true);
  const fieldValues = []; // Values come from the public source scanner, not cipher feedback.
  const { collectSourceEvidence } = require('../../scripts/inspect-clst.cjs');
  const xml = fs.readFileSync(file).subarray(2).toString('utf16le');
  const evidence = collectSourceEvidence(xml);
  for (const field of evidence.fieldSnapshots) fieldValues.push(field.calcData ?? '');
  const expected = generateClStReference({ fieldValues, subImageCount: evidence.counts.subImageCount,
    dateOffsetCount: evidence.counts.dateOffsetCount, mask: actual.mainLayout.maskHex });
  assert.equal(expected.clStVersionInfo, actual.token, item.name);
  results.push({ name: item.name, nativeTokenLength: actual.token.length, mask: actual.mainLayout.maskHex, tagData: actual.mainLayout.tagData, exactMatch: true });
}
const report = { method: 'Actual COM generation compared with independently recovered pipeline; native selected mask is supplied explicitly.', cases: results };
fs.writeFileSync(path.join(__dirname, 'native-clst-crosscheck.json'), JSON.stringify(report, null, 2) + '\n');
process.stdout.write(JSON.stringify({ cases: results.length, allMatched: true }) + '\n');
