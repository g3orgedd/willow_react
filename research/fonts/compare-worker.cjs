const fs = require('node:fs');
const path = require('node:path');
const { execFileSync } = require('node:child_process');
const { createFontRendererService } = require('../../electron/fonts.cjs');

(async () => {
  const readJson = (name) => JSON.parse(fs.readFileSync(path.join(__dirname, name), 'utf8').replace(/^\uFEFF/, ''));
  const oracle = readJson('oracle-results.json');
  const renderer = createFontRendererService();
  const manifest = [];
  const variants = [];
  try {
    for (const field of oracle.fields) {
      const output = await renderer.render({ text: 'Abc 0123456789 АБВГД абвгд', face: field.face, pitch: field.pitch });
      const filename = `worker-${field.path}`;
      fs.writeFileSync(path.join(__dirname, filename), Buffer.from(output.dataUrl.split(',')[1], 'base64'));
      manifest.push({ face: field.face, pitch: field.pitch, reference: field.path, candidate: filename });
    }
    const settings = {
      normal: {}, bold: { bold: true }, italic: { italic: true }, xmag150: { xMag: 150 },
      ymag150: { yMag: 150 }, spacing1: { charSpace: 1 }, spacing50: { charSpace: 50 },
      pitchresolution10: { pitchResolution: 10 }, ttsize0: {},
    };
    for (const [name, parameters] of Object.entries(settings)) {
      const output = await renderer.render({ text: 'Abc 0123456789 АБВГД абвгд', face: 'Arial', pitch: 13, ...parameters });
      const filename = `worker-variant-${name}.png`;
      fs.writeFileSync(path.join(__dirname, filename), Buffer.from(output.dataUrl.split(',')[1], 'base64'));
      variants.push({ face: 'Arial', pitch: 13, variant: name, reference: `variant_${name}.png`, candidate: filename });
    }
  } finally { renderer.dispose(); }
  fs.writeFileSync(path.join(__dirname, 'worker-comparison-manifest.json'), JSON.stringify(manifest, null, 2));
  fs.writeFileSync(path.join(__dirname, 'worker-variant-manifest.json'), JSON.stringify(variants, null, 2));
  execFileSync('powershell.exe', ['-NoProfile', '-NonInteractive', '-ExecutionPolicy', 'Bypass', '-File', path.join(__dirname, 'compare-worker.ps1')], { stdio: 'inherit', windowsHide: true });
  execFileSync('powershell.exe', ['-NoProfile', '-NonInteractive', '-ExecutionPolicy', 'Bypass', '-File', path.join(__dirname, 'compare-worker.ps1'), '-Manifest', 'worker-variant-manifest.json', '-Report', 'worker-variant-comparison.json'], { stdio: 'inherit', windowsHide: true });
})().catch((error) => { console.error(error); process.exitCode = 1; });
