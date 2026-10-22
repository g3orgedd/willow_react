'use strict';
const fs = require('node:fs');
const path = require('node:path');
const assert = require('node:assert/strict');
const reference = require('../reference-generator.cjs');
const composition = JSON.parse(fs.readFileSync(path.join(__dirname, 'optional-composition-results.json'), 'utf8'));
const splitCases = fs.readFileSync(path.join(__dirname, 'splitpath-cases.jsonl'), 'utf8')
  .replace(/^\uFEFF/, '').trim().split(/\r?\n/).map((line) => JSON.parse(line));
for (const entry of splitCases) {
  assert.equal(reference.metadataName(entry.sourcePath), entry.metadataPlaintext,
    `native split mismatch: ${JSON.stringify(entry.sourcePath)}`);
}
for (const entry of composition.cases) {
  const generated = reference.generateClStReference(entry.input);
  for (const key of ['fileMetadata', 'metadataFragment', 'metadataLengthFragment',
    'normalIntermediate', 'intermediate', 'clStVersionInfo']) {
    assert.equal(generated[key], entry[key], `${key}: ${JSON.stringify(entry.input)}`);
  }
}
const report = { nativeSplitCases: splitCases.length, nativeCompositionCases: composition.cases.length,
  allMatched: true, method: 'reference JavaScript compared with native x86 split and cipher composition' };
fs.writeFileSync(path.join(__dirname, 'reference-comparison-report.json'), `${JSON.stringify(report, null, 2)}\n`);
process.stdout.write(`${JSON.stringify(report)}\n`);
