const fs = require('node:fs');
const path = require('node:path');
const assert = require('node:assert/strict');
const crypto = require('node:crypto');
const output = path.resolve(process.argv[2] || path.join(__dirname, 'exports-final'));
const report = JSON.parse(fs.readFileSync(path.join(output, 'native-validation.json'), 'utf8').replace(/^\uFEFF/, ''));
const hash = filename => crypto.createHash('sha256').update(fs.readFileSync(filename)).digest('hex').toUpperCase();
const semantic = row => ({
  designedFor: row.designedFor, coder: row.coder, validate: row.validate, validate2: row.validate2,
  images: row.images.map(image => image.dimensions),
  fields: row.fields.map(field => ({ common: field.before, font: field.font,
    widthDots: field.widthDots, heightDots: field.heightDots, metricComparison: field.metricComparison }))
});
const results = [];
for (const web of report.cases.filter(row => row.mode === 'web')) {
  const exe = report.cases.find(row => row.mode === 'exe' && row.caseId === web.caseId);
  assert.ok(exe, 'Missing EXE pair: ' + web.caseId);
  assert.equal(web.status, 'ok', web.name + ': strict original native check failed');
  assert.equal(exe.status, 'ok', exe.name + ': strict original native check failed');
  assert.deepEqual(semantic(web), semantic(exe), 'Native semantic difference between web and packaged EXE: ' + web.caseId);
  for (const row of [web, exe]) {
    assert.equal(row.sourceSha256, row.sourceSha256After);
    assert.equal(hash(row.file), row.sourceSha256);
  }
  results.push({ caseId: web.caseId, nativePropertiesIdentical: true, sourceHashesUnchanged: true,
    web: web.file, exe: exe.file, sourceBytesIdentical: web.sourceSha256 === exe.sourceSha256,
    compared: 'Loaded dimensions/resolution, field order/Displayed/XYWH/Orientation/CalculatedData, 12 native font properties and CalculateSize; ClSt random bytes are not required to match.' });
}
const summary = { comparedAt: new Date().toISOString(), pairs: results.length,
  allNativePropertiesIdentical: true, cases: results };
fs.writeFileSync(path.join(output, 'web-exe-comparison.json'), JSON.stringify(summary, null, 2));
console.log(JSON.stringify({ pairs: results.length, allNativePropertiesIdentical: true, originalDownloadsUnchanged: true }));
