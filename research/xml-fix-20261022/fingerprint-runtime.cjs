// Read-only proof that HTTP and packaged EXE use the production freeze.
const fs = require('node:fs');
const path = require('node:path');
const crypto = require('node:crypto');
const asar = require('@electron/asar');
const root = path.resolve(__dirname, '../..');
const archive = path.join(root, 'desktop-release-xml-fix-20261022/win-unpacked/resources/app.asar');
const hash = bytes => crypto.createHash('sha256').update(bytes).digest('hex');
const walk = directory => fs.readdirSync(directory, { withFileTypes: true }).flatMap(entry =>
  entry.isDirectory() ? walk(path.join(directory, entry.name)) : [path.join(directory, entry.name)]);
(async () => {
  const files = walk(path.join(root, 'public/modules')).filter(file => file.endsWith('.js'));
  const rows = [];
  for (const filename of files) {
    const relative = path.relative(path.join(root, 'public'), filename).replaceAll('\\', '/');
    const source = fs.readFileSync(filename);
    const dist = fs.readFileSync(path.join(root, 'dist', relative));
    const packaged = asar.extractFile(archive, path.normalize('dist/' + relative));
    const response = await fetch('http://127.0.0.1:5173/' + relative, { cache: 'no-store', signal: AbortSignal.timeout(5000) });
    if (!response.ok) throw new Error('HTTP source not available: ' + relative);
    const http = Buffer.from(await response.arrayBuffer());
    rows.push({ source: path.relative(root, filename).replaceAll('\\', '/'), archiveEntry: 'dist/' + relative,
      sourceSha256: hash(source), distSha256: hash(dist), archiveSha256: hash(packaged), httpSha256: hash(http),
      identical: source.equals(dist) && source.equals(packaged) && source.equals(http) });
  }
  for (const filename of walk(path.join(root, 'electron')).filter(file => /\.(cjs|ps1)$/.test(file))) {
    const relative = path.relative(root, filename).replaceAll('\\', '/');
    const source = fs.readFileSync(filename), packaged = asar.extractFile(archive, path.normalize(relative));
    rows.push({ source: relative, archiveEntry: relative, sourceSha256: hash(source), archiveSha256: hash(packaged), identical: source.equals(packaged) });
  }
  const report = { capturedAt: new Date().toISOString(), sourceVersion: JSON.parse(fs.readFileSync(path.join(root, 'package.json'))).version,
    packagedVersion: JSON.parse(asar.extractFile(archive, 'package.json')).version, archive, archiveSha256: hash(fs.readFileSync(archive)),
    files: rows, allIdentical: rows.every(row => row.identical) };
  const reportPath = process.argv[2] ? path.resolve(process.argv[2]) : path.join(__dirname, 'runtime-fingerprints.json');
  fs.writeFileSync(reportPath, JSON.stringify(report, null, 2));
  console.log(JSON.stringify({ files: rows.length, allIdentical: report.allIdentical, sourceVersion: report.sourceVersion, packagedVersion: report.packagedVersion, archiveSha256: report.archiveSha256 }));
  if (!report.allIdentical || report.sourceVersion !== report.packagedVersion) process.exitCode = 1;
})().catch(error => { console.error(error.stack); process.exitCode = 1; });
