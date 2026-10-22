const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const crypto = require('node:crypto');
const { spawn } = require('node:child_process');
const { createFontRendererService } = require('../../../electron/fonts.cjs');

const directory = __dirname;
const baseline = createFontRendererService({ spawn(file, args, options) {
  const previous = args.slice();
  previous[previous.length - 1] = path.join(directory, 'font-renderer-before.ps1');
  return spawn(file, previous, options);
} });
const current = createFontRendererService();
const digest = (value) => crypto.createHash('sha256').update(value).digest('hex');
const cases = [];
for (const face of ['Arial', 'Courier New', 'Times New Roman', 'OCRB', 'Tahoma']) {
  for (const text of ['ABCD012345 OQy', 'Привет, мир! 123']) {
    for (const bold of [false, true]) {
      for (const xMag of [100, 150]) cases.push({ text, face, pitch: 13, bold, xMag });
    }
  }
}
cases.push(
  { text: '', face: 'Arial', pitch: 13 },
  { text: '   ', face: 'Arial', pitch: 13 },
  { text: 'AB OQy', face: 'Arial', pitch: 6 },
  { text: 'AB OQy', face: 'Arial', pitch: 13, charSpace: 1 },
  { text: 'AB OQy', face: 'Arial', pitch: 13, charSpace: 50 },
  { text: 'Привет ABC', face: 'Arial', pitch: 13, charSpace: 1 },
  { text: 'A\u0301 e\u0308 O', face: 'Arial', pitch: 13 },
  { text: 'A😀B', face: 'Arial', pitch: 13 },
  { text: 'שלום AB', face: 'Arial', pitch: 13, charSpace: 1 },
  { text: 'ABCD012345', face: 'Arial', pitch: 13, xRes: 800, yRes: 1200 },
  { text: 'ABCD012345', face: 'Arial', pitch: 13, xRes: 1200, yRes: 800 },
  { text: 'A&B', face: 'Arial', pitch: 13 },
  { text: 'A&&B', face: 'Arial', pitch: 13 },
  { text: 'A\tB', face: 'Arial', pitch: 13 },
);

(async () => {
  const report = [];
  try {
    for (let index = 0; index < cases.length; index++) {
      const request = cases[index];
      const [before, result] = await Promise.all([baseline.render(request), current.render(request)]);
      const { outlinePath, ...unchanged } = result;
      assert.deepEqual(unchanged, before, `native bitmap/metadata changed for case ${index}`);
      assert.equal(typeof outlinePath, 'string', `missing vector outline for case ${index}`);
      assert.match(outlinePath, /^[MLQCZ0-9. \-]*$/, `invalid SVG path for case ${index}`);
      if (!request.text.trim()) assert.equal(outlinePath, '');
      else assert.match(outlinePath, /^M[\s\S]*Z$/);
      const item = { request, width: result.width, height: result.height,
        pngSha256: digest(result.dataUrl), outlineLength: outlinePath.length, outlineSha256: digest(outlinePath),
        pngAndMetricsUnchanged: true };
      report.push(item);
      if (index % 4 === 0 || index >= 40) {
        const name = `sample-${String(index).padStart(2, '0')}`;
        fs.writeFileSync(path.join(directory, name + '.svg'),
          `<svg xmlns="http://www.w3.org/2000/svg" width="${result.width * 4}" height="${result.height * 4}" viewBox="0 0 ${result.width} ${result.height}"><rect width="100%" height="100%" fill="white"/><path d="${outlinePath}" fill="black" fill-rule="nonzero"/></svg>`);
        fs.writeFileSync(path.join(directory, name + '-bitmap.png'), Buffer.from(result.dataUrl.split(',')[1], 'base64'));
      }
    }
    fs.writeFileSync(path.join(directory, 'native-comparison.json'), JSON.stringify({ count: report.length, cases: report }, null, 2));
    console.log(JSON.stringify({ cases: report.length, nativeBitmapAndMetricsUnchanged: true, outlinesAvailable: true }));
  } finally { baseline.dispose(); current.dispose(); }
})().catch((error) => { console.error(error); process.exitCode = 1; });
