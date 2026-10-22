// Research only: independent original Draw geometry versus actual Konva.Path.
const fs = require('node:fs');
const path = require('node:path');
const output = path.resolve(process.argv[2] || path.join(__dirname, 'exports-resolution-final'));
const read = filename => JSON.parse(fs.readFileSync(filename, 'utf8').replace(/^\uFEFF/, ''));
function positionDot(coordinate, resolution) {
  const scaled = Math.fround(Math.fround(coordinate) * Math.fround(resolution));
  return Math.trunc(Math.fround(scaled + (scaled < 0 ? -0.5 : 0.5)));
}
function check(field, native, capsX, capsY, label) {
  const failures = [], node = field.node;
  if (!node || node.className !== 'Path' || !node.native || !node.vector || !node.dataMatchesOutline) {
    return { label, failures: ['Actual native vector Path evidence missing'], passed: false };
  }
  const w = native.widthDots, h = native.heightDots, angle = field.orientation || 0;
  const dx = positionDot(field.geom.x, capsX), dy = positionDot(field.geom.y, capsY);
  const anchor = native.anchor || { x: dx, y: dy };
  if (anchor.x !== dx || anchor.y !== dy) failures.push({ property: 'independent-original-anchor', actual: anchor, expected: { x: dx, y: dy } });
  if (field.nativeDotAnchor?.x !== dx || field.nativeDotAnchor?.y !== dy) failures.push({ property: 'actual-renderer-rounded-anchor', actual: field.nativeDotAnchor, expected: { x: dx, y: dy } });
  const originX = node.fieldGroup.absoluteMatrix[4] - node.fieldGroup.x;
  const originY = node.fieldGroup.absoluteMatrix[5] - node.fieldGroup.y;
  const scaleX = 100 * capsX / node.pixelsPerMm, scaleY = 100 * capsY / node.pixelsPerMm;
  // Screen physical axes map independently into the global printer axes.
  const matrix = node.absoluteMatrix.map((value, i) => (value - (i === 4 ? originX : i === 5 ? originY : 0)) * (i % 2 ? scaleY : scaleX));
  const expectedMatrix = ({ 0: [1, 0, 0, 1, dx, dy], 90: [0, 1, -1, 0, dx + h, dy],
    180: [-1, 0, 0, -1, dx + w, dy + h], 270: [0, -1, 1, 0, dx, dy + w] })[angle];
  for (let i = 0; i < 6; i++) if (Math.abs(matrix[i] - expectedMatrix[i]) > 1e-6) failures.push({ property: `six-coefficient-transform[${i}]`, actual: matrix[i], expected: expectedMatrix[i] });
  const cell = { x: (node.cellWorldBounds.x - originX) * scaleX, y: (node.cellWorldBounds.y - originY) * scaleY,
    width: node.cellWorldBounds.width * scaleX, height: node.cellWorldBounds.height * scaleY };
  const rotated = angle === 90 || angle === 270;
  const expectedCell = { x: dx, y: dy, width: rotated ? h : w, height: rotated ? w : h };
  for (const key of Object.keys(expectedCell)) if (Math.abs(cell[key] - expectedCell[key]) > 1e-6) failures.push({ property: `printer-cell.${key}`, actual: cell[key], expected: expectedCell[key] });
  if (node.selfRect.width !== w || node.selfRect.height !== h) failures.push({ property: 'unrotated-cell', actual: node.selfRect, expected: { width: w, height: h } });
  if (field.nativeMetrics.width !== w || field.nativeMetrics.height !== h) failures.push({ property: 'native-metric', actual: field.nativeMetrics, expected: { width: w, height: h } });
  return { label, passed: failures.length === 0, capsX, capsY, angle, ciffGeometry: field.geom,
    expectedPrinterAnchor: { x: dx, y: dy }, actualPrinterAnchor: field.nativeDotAnchor, actualMatrix: matrix, expectedMatrix,
    actualPrinterCell: cell, expectedPrinterCell: expectedCell, failures };
}
const real = [], custom = [];
const native = read(path.join(output, 'native-validation.json'));
for (const row of native.cases) {
  if (row.status !== 'ok') throw new Error('Strict native validation failed: ' + row.name);
  const expected = read(row.expectedFile);
  for (const field of expected.preSave.fields.filter(field => field.printed && field.type !== 'Barcode')) {
    const nativeField = row.fields.find(candidate => candidate.before.name === field.name);
    real.push(check(field, { ...nativeField, anchor: nativeField.draw.anchor }, row.xResolution, row.yResolution, row.name + '/' + field.name));
  }
}
for (const mode of ['web', 'exe']) {
  const capture = read(path.join(output, 'custom-position-' + mode + '.json'));
  for (const field of capture.captures) {
    const r = field.reference, rotated = r.orientation === 90 || r.orientation === 270;
    const widthDots = rotated ? r.result.height : r.result.width, heightDots = rotated ? r.result.width : r.result.height;
    const checked = check(field, { widthDots, heightDots, anchor: { x: r.result.bestX, y: r.result.bestY } }, r.capsX, r.capsY, mode + '/' + r.prefix);
    if (r.result.differentPixels !== 0 || r.result.bestDifference !== 0) checked.failures.push({ property: 'original-Draw-position-proof', actual: r.result });
    if (field.geom.w !== r.modelW || field.geom.h !== r.modelH) checked.failures.push({ property: 'original-model-WH', actual: field.geom, expected: { w: r.modelW, h: r.modelH } });
    checked.passed = checked.failures.length === 0;
    custom.push(checked);
  }
}
const report = { at: new Date().toISOString(), method: 'Actual renderer six Path transform coefficients, global-axis scaling, signed float32 rounded anchors, full cell bounds against independent original native Draw/EXE model.',
  limits: ['Custom anisotropic profiles are controlled unknown-printer fallback proofs, separate from registered-printer physical saves.', 'Antialiased vector ink is not asserted pixel-identical to one-bit printer raster. Printer raster equality is checked separately.'],
  realSavedCases: real, customPositionCases: custom, counts: { realSavedFields: real.length, realSavedPass: real.filter(row => row.passed).length,
    customFields: custom.length, customPass: custom.filter(row => row.passed).length }, passed: [...real, ...custom].every(row => row.passed) };
fs.writeFileSync(path.join(output, 'affine-verification.json'), JSON.stringify(report, null, 2));
console.log(JSON.stringify({ ...report.counts, passed: report.passed }));
if (!report.passed) process.exitCode = 1;
