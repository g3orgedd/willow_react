'use strict';
const fs = require('node:fs');
const path = require('node:path');
const reference = require('../reference-generator.cjs');

const cipherCases = JSON.parse(fs.readFileSync(path.join(__dirname, 'oracle-comparison-cases.json'), 'utf8'));
const compositionCases = JSON.parse(fs.readFileSync(path.join(__dirname, 'composition-results.json'), 'utf8')).cases;
const failures = [];
let cipherMatched = 0;
let pipelineMatched = 0;
const pipelineResults = [];

for (const [index, item] of cipherCases.entries()) {
  const output = reference.encrypt(item.input, item.key);
  if (output === item.native) cipherMatched += 1;
  else failures.push({ type: 'cipher', index, input: item.input, key: item.key, native: item.native, reference: output });
}

for (const [index, item] of compositionCases.entries()) {
  const output = reference.generateClStReference(item.input);
  const matched = output.clStVersionInfo === item.clStVersionInfo &&
    output.intermediate === item.core && output.tagData === item.selectedPayload &&
    output.counts6 === item.counterKey;
  if (matched) pipelineMatched += 1;
  else failures.push({ type: 'pipeline', index, native: item, reference: output });
  pipelineResults.push({ description: item.description, fieldCount: item.fieldValues.length,
    maskHex: item.maskHex, selectedPayloadUtf16Length: item.selectedPayloadUtf16Length,
    outputLength: item.length, matched });
}

const report = { method: 'reference generator compared against original CiffMgr.dll x86 transform execution',
  nativeCompositionDoesNotExecuteComDocumentGenerator: true,
  cipherCount: cipherCases.length, cipherMatched,
  pipelineCount: compositionCases.length, pipelineMatched,
  pipelineResults, failures };
fs.writeFileSync(path.join(__dirname, 'reference-comparison-report.json'), JSON.stringify(report, null, 2) + '\n');
console.log(JSON.stringify({ cipherCount: report.cipherCount, cipherMatched,
  pipelineCount: report.pipelineCount, pipelineMatched, failureCount: failures.length }));
if (failures.length) process.exitCode = 1;
