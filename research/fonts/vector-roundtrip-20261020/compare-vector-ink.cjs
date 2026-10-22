// Compare smooth contour bounds with their native printer-cell reference.
// This is a geometry check, not an assertion that antialiased pixels equal 1bpp.
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');
const { execFileSync } = require('node:child_process');
const sandbox = { console, setTimeout, clearTimeout };
vm.runInNewContext(fs.readFileSync(path.join(__dirname, '../../../public/libs/konva.min.js'), 'utf8'), sandbox);
const mode = process.argv[2];
if (!['web', 'exe'].includes(mode)) throw new Error('Expected web or exe.');
const expected = JSON.parse(fs.readFileSync(path.join(__dirname, `expected-${mode}.json`), 'utf8'));
const raster = JSON.parse(execFileSync('powershell.exe', ['-NoLogo', '-NoProfile', '-ExecutionPolicy', 'Bypass', '-File', path.join(__dirname, 'read-ink-bounds.ps1'), '-Mode', mode], { windowsHide: true, encoding: 'utf8' }).replace(/^\uFEFF/, ''));
function rotate(box, width, height, degrees) {
  const { left, top, right, bottom } = box;
  if (degrees === 90) return { left: height - bottom, top: left, right: height - top, bottom: right };
  if (degrees === 180) return { left: width - right, top: height - bottom, right: width - left, bottom: height - top };
  if (degrees === 270) return { left: top, top: width - right, right: bottom, bottom: width - left };
  return { left, top, right, bottom };
}
const resolution = Math.fround(expected.xRes);
const dot = value => { const scaled = Math.fround(Math.fround(value) * resolution); return Math.trunc(Math.fround(scaled + (scaled < 0 ? -0.5 : 0.5))); };
const fields = expected.fields.map(field => {
  const probe = new sandbox.Konva.Path({ data: field.outlinePath });
  const bounds = probe.getSelfRect();
  const vectorBounds = { left: bounds.x, top: bounds.y, right: bounds.x + bounds.width, bottom: bounds.y + bounds.height };
  const printerBounds = raster.find(item => item.name === field.name);
  const differences = Object.fromEntries(['left', 'top', 'right', 'bottom'].map(side => [side, vectorBounds[side] - printerBounds[side]]));
  const rotated = rotate(vectorBounds, field.bitmapWidth, field.bitmapHeight, field.orientation);
  const origin = { x: dot(field.geom.x), y: dot(field.geom.y) };
  const absoluteVectorBounds = { left: origin.x + rotated.left, top: origin.y + rotated.top, right: origin.x + rotated.right, bottom: origin.y + rotated.bottom };
  return { name: field.name, face: field.face, orientation: field.orientation, cellWidth: field.bitmapWidth, cellHeight: field.bitmapHeight,
    vectorBounds, printerBounds, differences, maximumEdgeDifferenceDots: Math.max(...Object.values(differences).map(Math.abs)), origin, absoluteVectorBounds };
});
const maximumEdgeDifferenceDots = Math.max(...fields.map(field => field.maximumEdgeDifferenceDots));
const report = { mode, method: 'Actual preview outline in native cell coordinates vs captured printer bitmap pixel-coverage bounds; rotations use the same native cell and printer-dot anchor. Different antialiasing/hinting is expected.',
  printerDotsPerMm: expected.xRes * 100, maximumEdgeDifferenceDots, maximumEdgeDifferenceMm: maximumEdgeDifferenceDots / (expected.xRes * 100), fields };
fs.writeFileSync(path.join(__dirname, `vector-ink-${mode}.json`), JSON.stringify(report, null, 2));
console.log(JSON.stringify({ mode, fields: fields.length, maximumEdgeDifferenceDots, maximumEdgeDifferenceMm: report.maximumEdgeDifferenceMm }));
