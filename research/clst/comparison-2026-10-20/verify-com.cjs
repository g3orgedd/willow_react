'use strict';
const fs = require('node:fs');
const path = require('node:path');
const assert = require('node:assert/strict');
const crypto = require('node:crypto');
const { decryptClStText, collectSourceEvidence } = require('../../../scripts/inspect-clst.cjs');
const { generateClStReference } = require('../reference-generator.cjs');

const input = JSON.parse(fs.readFileSync(path.join(__dirname, 'com-results.json'), 'utf8'));
const cases = input.cases.map((item) => {
  assert.equal(item.status, 'ok', item.name);
  const filename = path.join(__dirname, `${item.name}.ciff`);
  const bytes = fs.readFileSync(filename);
  const source = collectSourceEvidence(bytes.subarray(2).toString('utf16le'));
  assert.equal(source.token, item.token);
  assert.deepEqual(item.fieldValuesBefore, item.fieldValuesAfter, 'Generator should consume prepared CalculatedData.');
  assert.equal(source.counts.subImageCount, item.subImageCount);
  assert.equal(source.counts.fieldCount, item.fieldCount);
  const inner = decryptClStText(item.token, 'TpyRcNeyeK');
  const maskHex = decryptClStText(inner.slice(0, 24), source.structureKey);
  assert.match(maskHex, /^[0-9A-F]{8}$/);
  const mask = parseInt(maskHex, 16) >>> 0;
  const actualPayload = decryptClStText(inner.slice(24), 'TagData');
  const expected = generateClStReference({
    fieldValues: item.fieldValuesBefore,
    dateOffsetCount: source.counts.dateOffsetCount,
    subImageCount: item.subImageCount,
    mask: maskHex,
  });
  assert.equal(item.token, expected.clStVersionInfo, `${item.name}: complete original COM token differs`);
  assert.equal(actualPayload, expected.tagData);
  assert.equal(item.tokenLength, 72 + 9 * actualPayload.length);
  const selectedIndices = Array.from({ length: Math.min(32, item.fieldCount) }, (_, i) => i)
    .filter((i) => (mask >>> i) & 1);
  const selectedStoredXml = selectedIndices.map((i) => source.fieldSnapshots[i].calcData ?? '').join('').slice(0, 20);
  return {
    name: item.name, subImageCount: item.subImageCount, fieldCount: item.fieldCount,
    maskHex, selectedIndices, payload: actualPayload, payloadUtf16Length: actualPayload.length,
    payloadUtf16Words: Array.from({ length: actualPayload.length }, (_, i) => actualPayload.charCodeAt(i).toString(16).padStart(4, '0')),
    selectedStoredXml, payloadMatchesStoredXml: actualPayload === selectedStoredXml,
    tokenLength: item.tokenLength, exactMatch: true,
    ciffSha256: crypto.createHash('sha256').update(bytes).digest('hex'),
  };
});
const oldDir = path.join(__dirname, '..', 'decompiled');
const newDir = path.join(__dirname, 'decompiled');
const functionExports = fs.readdirSync(newDir).filter((name) => name.endsWith('.c')).map((name) => {
  const current = fs.readFileSync(path.join(newDir, name));
  const oldFile = path.join(oldDir, name);
  const sameAsPrevious = fs.existsSync(oldFile) && current.equals(fs.readFileSync(oldFile));
  assert.equal(sameAsPrevious, true, `Ghidra export changed: ${name}`);
  return { file: name, sameAsPrevious, sha256: crypto.createHash('sha256').update(current).digest('hex') };
});
const result = {
  method: 'Complete original COM generator; actual selected mask decoded and supplied to reference. CalculatedData snapshots are read before XML control filtering. RNG distribution is not inferred from these cases.',
  cases, total: cases.length, matched: cases.filter((c) => c.exactMatch).length,
  ghidra: { method: 'Repeated export from the existing read-only project for the binary whose SHA-256 matches the installed DLL.', functionCount: functionExports.length, exports: functionExports },
};
fs.writeFileSync(path.join(__dirname, 'com-verification.json'), JSON.stringify(result, null, 2) + '\n');
process.stdout.write(JSON.stringify({ comCases: result.total, matched: result.matched, ghidraFunctions: functionExports.length,
  selected: cases.map(({name,maskHex,payload,tokenLength,payloadMatchesStoredXml}) => ({name,maskHex,payload,tokenLength,payloadMatchesStoredXml})) }, null, 2) + '\n');
