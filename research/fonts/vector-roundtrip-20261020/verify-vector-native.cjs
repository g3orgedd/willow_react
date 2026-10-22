// Research only. Load the two physically downloaded files with the original
// ClariSoft COM server; never reconstruct a field or rewrite either CIFF.
const fs = require('node:fs');
const path = require('node:path');
const crypto = require('node:crypto');
const { execFileSync } = require('node:child_process');
const { createFontRendererService } = require('../../../electron/fonts.cjs');
const output = __dirname;
const powershell = path.join(process.env.SystemRoot || 'C:/Windows', 'SysWOW64/WindowsPowerShell/v1.0/powershell.exe');
const hash = bytes => crypto.createHash('sha256').update(bytes).digest('hex');
const read = name => JSON.parse(fs.readFileSync(path.join(output, name), 'utf8').replace(/^\uFEFF/, ''));
const write = (name, value) => fs.writeFileSync(path.join(output, name), JSON.stringify(value, null, 2));
const familyCodes = { DontCare: 0, Roman: 16, Swiss: 32, Modern: 48, Script: 64, Decorative: 80 };
const bool = value => value === true || value === 1 || value === 'True' || value === 'true';
const fontKeys = ['face', 'pitch', 'xMag', 'bold', 'italic', 'family', 'boldWeight', 'yMag', 'ttSize', 'txtDir', 'charSpace', 'pitchResolution'];
function expectedFont(field) {
  const t = field.text || {};
  const request = field.nativeRequest || field.request || field.renderRequest || {};
  const result = { face: 'Arial', pitch: 13, xMag: 100, bold: false, italic: false,
    family: 32, boldWeight: 1, yMag: 100, ttSize: 1, txtDir: 0, charSpace: 0, pitchResolution: 1 };
  for (const key of fontKeys) {
    // effectiveText.boldWeight is a GDI weight (400), whereas native COM stores
    // an enum (default 1). Preserve the source/COM value for this property.
    for (const source of [field.effectiveText && key !== 'boldWeight' ? field.effectiveText : {}, t, request, field]) if (source[key] != null) result[key] = source[key];
  }
  if (typeof result.family === 'string' && result.family in familyCodes) result.family = familyCodes[result.family];
  if (typeof result.txtDir === 'string') result.txtDir = ({ LeftToRight: 0, RightToLeft: 1, LTR: 0, RTL: 1 })[result.txtDir] ?? result.txtDir;
  result.bold = bool(result.bold); result.italic = bool(result.italic);
  return result;
}
function positionDot(coordinate, resolution) {
  const scaled = Math.fround(Math.fround(coordinate) * Math.fround(resolution));
  return Math.trunc(Math.fround(scaled + (scaled < 0 ? -0.5 : 0.5)));
}
function execute(script, mode) {
  const environment = { ...process.env };
  // A parent PowerShell 7 shell exports its module path; Windows PowerShell 5
  // must initialize its own modules instead of searching the PowerShell 7 ones.
  delete environment.PSModulePath;
  const result = execFileSync(powershell, ['-NoLogo', '-NoProfile', '-NonInteractive', '-ExecutionPolicy', 'Bypass', '-File', path.join(output, script), '-Mode', mode], { env: environment, encoding: 'utf8', windowsHide: true, timeout: 90000, maxBuffer: 4 * 1024 * 1024 });
  process.stdout.write(result);
}
async function check(mode, renderer, reuseNative) {
  const expected = read(`expected-${mode}.json`);
  const sourcePath = path.join(output, `${mode}-vector.ciff`);
  const sourceHash = hash(fs.readFileSync(sourcePath));
  if (!reuseNative) execute('read-native.ps1', mode);
  const native = read(`native-${mode}/read-report.json`);
  const failures = [];
  if (sourceHash.toLowerCase() !== String(expected.sha256).toLowerCase()) failures.push('Source hash differs from the original captured download.');
  if (sourceHash.toLowerCase() !== native.sourceSha256.toLowerCase() || native.sourceSha256 !== native.sourceSha256After) failures.push('Native input source hash differs or changed.');
  if (expected.fields.length !== native.fields.length) failures.push('Field count differs.');
  const rows = [], comparisonInputs = [];
  for (const field of expected.fields) {
    const actual = native.fields.find(item => item.name === field.name);
    if (!actual) { failures.push(`Missing native field ${field.name}`); continue; }
    const wantedFont = expectedFont(field);
    const mismatches = [];
    for (const stage of ['before', 'updated', 'afterSize', 'afterDraw']) {
      for (const key of fontKeys) {
        const found = ['bold', 'italic'].includes(key) ? bool(actual[stage][key]) : actual[stage][key];
        if (found !== wantedFont[key]) mismatches.push({ stage, property: key, expected: wantedFont[key], actual: found });
      }
      for (const key of ['x', 'y', 'w', 'h']) if (actual[stage][key] !== field.geom[key]) mismatches.push({ stage, property: key, expected: field.geom[key], actual: actual[stage][key] });
      for (const key of ['type', 'orientation']) if (actual[stage][key] !== field[key]) mismatches.push({ stage, property: key, expected: field[key], actual: actual[stage][key] });
    }
    const textChanged = field.previewText !== actual.updated.calculatedData;
    const clockAdvanced = textChanged && ['TimeText', 'DateText', 'OffsetDateText'].includes(field.type);
    if (textChanged && !clockAdvanced) mismatches.push({ stage: 'updated', property: 'calculatedData', expected: field.previewText, actual: actual.updated.calculatedData });
    let referenceBitmap = field.bitmap;
    let referenceKind = 'original-captured-printer-bitmap';
    let currentMetrics = null;
    if (clockAdvanced) {
      // Keep the captured preview intact. Independently request the same current
      // payload seen by original UpdateData and label the new reference clearly.
      const n = actual.updated;
      currentMetrics = await renderer.render({ text: n.calculatedData, face: n.face, pitch: n.pitch, pitchResolution: n.pitchResolution,
        xMag: n.xMag, yMag: n.yMag, charSpace: n.charSpace, bold: !!n.bold, italic: !!n.italic,
        xRes: Math.round(native.xResolution * 10000), yRes: Math.round(native.yResolution * 10000) });
      referenceBitmap = `native-${mode}/glyph-current-payload-${field.name}.png`;
      fs.writeFileSync(path.join(output, referenceBitmap), Buffer.from(currentMetrics.dataUrl.split(',')[1], 'base64'));
      referenceKind = 'separate-regenerated-current-runtime-payload';
      write(`native-${mode}/glyph-current-payload-${field.name}.json`, { capturedPreviewText: field.previewText, currentNativeText: n.calculatedData,
        reason: 'Original ClariSoft UpdateData evaluates the system clock when this physical file is opened.',
        request: { ...wantedFont, text: n.calculatedData, xRes: Math.round(native.xResolution * 10000), yRes: Math.round(native.yResolution * 10000) },
        ...Object.fromEntries(Object.entries(currentMetrics).filter(([key]) => key !== 'dataUrl')) });
    }
    const wantedWidth = currentMetrics?.width ?? field.bitmapWidth;
    const wantedHeight = currentMetrics?.height ?? field.bitmapHeight;
    if (actual.widthDots !== wantedWidth || actual.heightDots !== wantedHeight) mismatches.push({ stage: 'CalculateSize', property: 'printerCell', expected: [wantedWidth, wantedHeight], actual: [actual.widthDots, actual.heightDots] });
    if (field.nodeClass !== 'Path' || field.nodeVector !== true || field.nodeNative !== true || typeof field.outlinePath !== 'string') mismatches.push({ stage: 'preview', property: 'vectorPath', expected: 'native Konva.Path', actual: [field.nodeClass, field.nodeNative, field.nodeVector] });
    if (field.nodeDataMatchesOutline === false) mismatches.push({ stage: 'preview', property: 'nodeDataMatchesOutline', expected: true, actual: false });
    const dotX = positionDot(actual.before.x, native.xResolution);
    const dotY = positionDot(actual.before.y, native.yResolution);
    const rotated = field.orientation === 90 || field.orientation === 270;
    let previewPrinterCell = null;
    let previewPrinterTransform = null;
    const ng = field.nodeGeometry;
    if (ng?.cellWorldBounds && ng?.fieldGroup?.absoluteMatrix && ng.pixelsPerMm > 0) {
      const scale = 100 * native.xResolution / ng.pixelsPerMm;
      const originX = ng.fieldGroup.absoluteMatrix[4] - ng.fieldGroup.x;
      const originY = ng.fieldGroup.absoluteMatrix[5] - ng.fieldGroup.y;
      previewPrinterCell = { x: (ng.cellWorldBounds.x - originX) * scale, y: (ng.cellWorldBounds.y - originY) * scale,
        width: ng.cellWorldBounds.width * scale, height: ng.cellWorldBounds.height * scale };
      const wantedCell = { x: dotX, y: dotY, width: rotated ? actual.heightDots : actual.widthDots, height: rotated ? actual.widthDots : actual.heightDots };
      for (const key of ['x', 'y', 'width', 'height']) if (Math.abs(previewPrinterCell[key] - wantedCell[key]) > 1e-6) mismatches.push({ stage: 'vector-preview', property: `printerCell.${key}`, expected: wantedCell[key], actual: previewPrinterCell[key] });
      if (ng.selfRect?.width !== field.bitmapWidth || ng.selfRect?.height !== field.bitmapHeight) mismatches.push({ stage: 'vector-preview', property: 'selfRect', expected: [field.bitmapWidth, field.bitmapHeight], actual: ng.selfRect });
      // An axis-aligned bbox alone cannot distinguish clockwise/anticlockwise
      // text. Verify all six coefficients, including translation and scale.
      previewPrinterTransform = ng.absoluteMatrix.map((v, i) => (v - (i === 4 ? originX : i === 5 ? originY : 0)) * scale);
      const w = actual.widthDots, h = actual.heightDots;
      const nativeTransform = ({ 0: [1, 0, 0, 1, dotX, dotY], 90: [0, 1, -1, 0, dotX + h, dotY],
        180: [-1, 0, 0, -1, dotX + w, dotY + h], 270: [0, -1, 1, 0, dotX, dotY + w] })[field.orientation];
      for (let i = 0; i < 6; i++) if (Math.abs(previewPrinterTransform[i] - nativeTransform[i]) > 1e-6) mismatches.push({ stage: 'vector-preview', property: `printerTransform[${i}]`, expected: nativeTransform[i], actual: previewPrinterTransform[i] });
    } else mismatches.push({ stage: 'vector-preview', property: 'cell-position-evidence', expected: 'actual nodeGeometry in captured preview', actual: ng || null });
    if (field.nativeDotAnchor && (field.nativeDotAnchor.x !== dotX || field.nativeDotAnchor.y !== dotY)) mismatches.push({ stage: 'vector-preview', property: 'nativeDotAnchor', expected: [dotX, dotY], actual: field.nativeDotAnchor });
    rows.push({ name: field.name, type: field.type, expectedFont: wantedFont, mismatches, capturedPreviewText: field.previewText,
      calculatedDataOnLoad: actual.before.calculatedData, currentNativeText: actual.updated.calculatedData, clockAdvanced, referenceKind,
      rawCiffGeometry: field.geom, nativePrinterCell: { x: dotX, y: dotY, width: rotated ? actual.heightDots : actual.widthDots, height: rotated ? actual.widthDots : actual.heightDots, orientation: field.orientation },
      previewPrinterCell, previewPrinterTransform, unrotatedMetrics: { capturedWidth: field.bitmapWidth, capturedHeight: field.bitmapHeight, currentWidth: actual.widthDots, currentHeight: actual.heightDots },
      vectorEvidence: { nodeClass: field.nodeClass, nodeNative: field.nodeNative, nodeVector: field.nodeVector, outlineLength: field.outlinePath.length,
        nodeDataMatchesOutline: field.nodeDataMatchesOutline ?? null,
        outlineSha256: hash(field.outlinePath), request: field.nativeRequest || field.request || field.renderRequest || null,
        metrics: field.nativeMetrics || null, nodeGeometry: field.nodeGeometry || null, outlineInkBounds: field.outlineInkBounds || null,
        fieldPhysicalBounds: field.fieldPhysicalBounds || null, effectiveGdiBoldWeight: field.effectiveText?.boldWeight ?? null },
    });
    comparisonInputs.push({ name: field.name, nativeBitmap: actual.bitmap, referenceBitmap, capturedBitmap: field.bitmap, orientation: field.orientation, payload: actual.updated.calculatedData, clockAdvanced, referenceKind });
  }
  write(`native-${mode}/comparison-input.json`, comparisonInputs);
  execute('compare-bitmaps.ps1', mode);
  const pixels = read(`native-${mode}/bitmap-comparison.json`);
  for (const row of rows) {
    const pixel = pixels.find(item => item.name === row.name);
    row.printerRaster = pixel;
    if (!pixel || pixel.comparison.different !== 0) row.mismatches.push({ stage: 'Draw', property: 'printerRaster', actual: pixel?.comparison });
    if (row.mismatches.length) failures.push(`${row.name}: ${row.mismatches.length} mismatches`);
  }
  const report = { mode, generatedUtc: new Date().toISOString(), sourcePath, sourceSha256: sourceHash,
    originalDownloadSha256: expected.sha256, sourceUnchanged: native.sourceSha256 === native.sourceSha256After,
    capturedPreviewUtc: expected.now, nativeStartedUtc: native.startedUtc, nativeFinishedUtc: native.finishedUtc,
    expectedFontDefaults: { face: 'Arial', pitch: 13, family: 32, pitchResolution: 1, xMag: 100, yMag: 100, ttSize: 1, txtDir: 0, charSpace: 0, boldWeight: 1, bold: false, italic: false },
    sourceMethod: native.method, designedFor: native.designedFor, coder: native.coder,
    resolution: { x: native.xResolution, y: native.yResolution }, nativeFingerprints: native.nativeFingerprints,
    glyphSourceFingerprints: ['electron/fonts.cjs', 'electron/font-renderer.ps1', 'public/modules/04-native-text-preview.js'].map(relative => ({ path: relative, sha256: hash(fs.readFileSync(path.resolve(output, '../../..', relative))) })),
    counts: { fields: rows.length, exactFontGeometryFields: rows.filter(row => !row.mismatches.length).length,
      exactPrinterRasters: rows.filter(row => row.printerRaster.comparison.different === 0).length,
      exactCapturedPrinterRasters: rows.filter(row => !row.clockAdvanced && row.printerRaster.comparison.different === 0).length,
      exactCurrentClockPrinterRasters: rows.filter(row => row.clockAdvanced && row.printerRaster.comparison.different === 0).length,
      clockAdvancedFields: rows.filter(row => row.clockAdvanced).length },
    limitations: ['This verifies original COM loading, native properties and printer raster. It is not a screenshot of the ClariSoft GUI.',
      'Captured vector outline pixels are antialiased; exact vector-screen/printer-raster equality is neither expected nor asserted.',
      'Font cell geometry includes whitespace and baseline. Ink bounds are separate and are not used to resize or reposition text.'],
    fields: rows, failures, passed: failures.length === 0 };
  write(`native-${mode}/verification-report.json`, report);
  return report;
}
(async () => {
  const args = process.argv.slice(2);
  const modes = args.filter(value => ['web', 'exe'].includes(value));
  const renderer = createFontRendererService();
  try {
    const results = [];
    for (const mode of modes.length ? modes : ['web', 'exe']) results.push(await check(mode, renderer, args.includes('--reuse-native')));
    const summary = results.map(result => ({ mode: result.mode, passed: result.passed, sha256: result.sourceSha256, ...result.counts, failures: result.failures }));
    write('native-verification-summary.json', summary);
    console.log(JSON.stringify(summary, null, 2));
    if (results.some(result => !result.passed)) process.exitCode = 1;
  } finally { renderer.dispose(); }
})().catch(error => { console.error(error.stack || error); process.exitCode = 1; });
