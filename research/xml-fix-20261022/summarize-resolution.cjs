const fs = require('node:fs');
const path = require('node:path');
const crypto = require('node:crypto');
const assert = require('node:assert/strict');
const output = path.resolve(process.argv[2] || path.join(__dirname, 'exports-resolution-final'));
const read = filename => JSON.parse(fs.readFileSync(filename, 'utf8').replace(/^\uFEFF/, ''));
const sha256 = filename => crypto.createHash('sha256').update(fs.readFileSync(filename)).digest('hex');
const native = read(path.join(output, 'native-validation.json'));
const affine = read(path.join(output, 'affine-verification.json'));
const custom = read(path.join(output, 'custom-raster-verification.json'));
const pairs = read(path.join(output, 'web-exe-comparison.json'));
const parties = read(path.join(output, 'party-properties-summary.json'));
const exportManifest = read(path.join(output, 'export-results-both.json'));
const fingerprints = read(path.join(__dirname, 'runtime-fingerprints-resolution.json'));
const afterFingerprints = read(path.join(__dirname, 'runtime-fingerprints-resolution-after.json'));
assert.equal(fingerprints.allIdentical, true); assert.equal(afterFingerprints.allIdentical, true);
assert.equal(fingerprints.archiveSha256, afterFingerprints.archiveSha256);
assert.equal(native.cases.length, 20); assert.ok(native.cases.every(row => row.status === 'ok'));
assert.equal(affine.passed, true); assert.equal(custom.failed, 0);
assert.equal(pairs.pairs, 10); assert.equal(pairs.allNativePropertiesIdentical, true);
const fields = native.cases.flatMap(row => row.fields);
const downloads = native.cases.map(row => {
  const expected = read(row.expectedFile), currentSha256 = sha256(row.file);
  assert.equal(currentSha256.toUpperCase(), row.sourceSha256);
  assert.equal(row.sourceSha256After, row.sourceSha256);
  return { mode: row.mode, caseId: row.caseId, file: row.file, sha256: currentSha256,
    sourceXRes: expected.expectedResolution.xRes, sourceYRes: expected.expectedResolution.yRes,
    actualRequest: expected.preSave.fields.filter(field => field.type !== 'Barcode').map(field => ({ name: field.name, xRes: field.nativeRequest.xRes, yRes: field.nativeRequest.yRes })),
    designedFor: row.designedFor, coder: row.coder, capsXRes: row.xResolution, capsYRes: row.yResolution,
    image: row.images[0].dimensions, nativeStatus: row.status, expectedFile: row.expectedFile,
    provenance: { actualLocation: expected.actualLocation, transport: expected.transport,
      savePath: expected.savePath, actualExeProcess: expected.actualExeProcess || null,
      completedDownloadEvents: expected.completedDownloadEvents, saveStartedAt: expected.saveStartedAt, saveEndedAt: expected.saveEndedAt } };
});
const report = { finishedAt: new Date().toISOString(), status: 'pass', sourceVersion: fingerprints.sourceVersion,
  output, executable: exportManifest.exe, archiveSha256: fingerprints.archiveSha256,
  contract: 'Selected real coder capabilities control text CalculateSize/Draw, dot rounding, physical cell and Path scales. Source SubHeader XRes/YRes remain independently preserved file metadata. No X/Y bitmap aspect correction; quarter-turn Path local axes follow native global-axis scale times bitmap rotation.',
  counts: { actualSavedFiles: native.cases.length, realLoadedFields: fields.length,
    exactNativeTextMetrics: fields.filter(field => field.metricComparison?.equal).length,
    exactOriginalDrawWorkerRasters: fields.filter(field => field.draw?.pixelComparison.different === 0).length,
    exactPrintedTextPathTransforms: affine.counts.realSavedPass, exactControlledPathTransforms: affine.counts.customPass,
    exactControlledWorkerRasters: custom.passed, webExeSemanticPairs: pairs.pairs, partyCases: Array.isArray(parties) ? parties.length : parties.cases?.length ?? parties.results?.length },
  covered: ['Real HTTP Save/download and real isolated packaged-EXE Save/download',
    'Normal6320, file ratios2 and0.5 in both directions, non-integer ratios with90/270rotation and non-dot-aligned origins',
    'Real6230(32mm) Continuous with800/800 native request and original Independence(32mm) Continuous capabilities',
    'PartyGTIN2 and PartyGTIN+BOX_COUNTER, maximum lengths, font10, ordered native objects, SNFixedLenpadding',
    'Controlled custom cap axes .12/.24, .24/.12, .125/.125 with all four orientations and signed origins;24metric references also .08/.12 and three font families'],
  limits: ['Original Draw PNGs are original COM renders and are not ClariSoft GUI screenshots.',
    'One-bit native/worker printer rasters are compared exactly. Antialiased vector screen ink is verified through native Path data and all six transforms, not asserted pixel-identical to the one-bit printer bitmap.',
    'Custom anisotropic-capability fallback/API tests do not claim a registered physical printer with those capabilities.',
    'GUI open/Ready results are recorded separately by root; no physical printer run or exhaustive all-printer/barcode coverage is claimed.'],
  sourceFingerprints: { before: path.join(__dirname, 'runtime-fingerprints-resolution.json'), after: path.join(__dirname, 'runtime-fingerprints-resolution-after.json'), identicalFiles: fingerprints.files.length },
  evidence: ['native-validation.json', 'affine-verification.json', 'custom-raster-verification.json', 'web-exe-comparison.json', 'party-properties-summary.json', 'gui-queue-both.json'], downloads };
fs.writeFileSync(path.join(output, 'verification-summary.json'), JSON.stringify(report, null, 2));
console.log(JSON.stringify({ status: report.status, archiveSha256: report.archiveSha256, counts: report.counts }));
