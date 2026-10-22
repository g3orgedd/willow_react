#!/usr/bin/env node

const fs = require('node:fs');
const path = require('node:path');

const {
  compareCiffBuffers,
  formatReport,
} = require('./compare-ciff-structure.cjs');
const {
  createProductionCiffRuntime,
  sha256,
} = require('../tests/helpers/ciff-production-harness.cjs');

const PROJECT_ROOT = path.join(__dirname, '..');
const DEFAULT_REFERENCE_TEXT = path.join(
  PROJECT_ROOT,
  'tests',
  'fixtures',
  'clarisoft',
  'clarisoft_fix6.reference.xml',
);
const DEFAULT_OUTPUT = path.join(
  PROJECT_ROOT,
  'tests',
  'output',
  'clarisoft_fix6.glyph.generated.ciff',
);
const DEFAULT_REPORT = path.join(
  PROJECT_ROOT,
  'tests',
  'output',
  'clarisoft_fix6.glyph.diff.txt',
);
const REFERENCE_SHA256 = '61CDFB349E15D3B95F5828B2EAAA1F7A200C70CECF50C47A74DC613CFD6C16F1';
const LATIN_HELPER_NAMES = new Map([
  ['\u04211', 'C1'],
  ['\u04212', 'C2'],
  ['\u04213', 'C3'],
]);

function encodeReferenceText(text) {
  const normalized = `${String(text).replace(/^\uFEFF/, '').replace(/\r?\n/g, '\r\n').trimEnd()}\r\n`;
  return Buffer.concat([Buffer.from([0xff, 0xfe]), Buffer.from(normalized, 'utf16le')]);
}

function readReferenceBytes(referencePath = DEFAULT_REFERENCE_TEXT) {
  const resolved = path.resolve(referencePath);
  if (/\.ciff$/i.test(resolved)) return fs.readFileSync(resolved);
  return encodeReferenceText(fs.readFileSync(resolved, 'utf8'));
}

function numberTag(xml, tag) {
  const value = String(xml).match(new RegExp(`<${tag}>([+-]?\\d+)<\\/${tag}>`))?.[1];
  return value == null ? null : Number(value);
}

function readImageSize(xml) {
  return {
    width: numberTag(xml, 'ImageWidth'),
    height: numberTag(xml, 'ImageHeight'),
    maxWidth: numberTag(xml, 'MaxImageWidth'),
    maxHeight: numberTag(xml, 'MaxImageHeight'),
  };
}

function readFieldGeometry(xml) {
  return (String(xml).match(/<Field\b[^>]*>[\s\S]*?<\/Field>/g) || []).map((block) => ({
    type: block.match(/<FldType>([\s\S]*?)<\/FldType>/)?.[1] || '',
    printed: !/<Displayed>\s*0\s*<\/Displayed>/.test(block),
    x: numberTag(block, 'X'),
    y: numberTag(block, 'Y'),
    w: numberTag(block, 'W'),
    h: numberTag(block, 'H'),
  }));
}

function geometryMatches(referenceLine, generatedLine) {
  return JSON.stringify(readFieldGeometry(referenceLine)) === JSON.stringify(readFieldGeometry(generatedLine));
}

function isTaskIgnoredDifference(difference) {
  const pathValue = String(difference?.path ?? '');
  if (/^\/bytes\/(?:byteLength|sha256)$/.test(pathValue)) return true;
  if (/\/Header\/ClStVersionInfo$/.test(pathValue)) return true;
  if (/\/Field\[Name="[^"]+"\]\/(?:X|Y|Data\/Object\/MaxNoOfChars|Text\/Font\/Pitch)$/.test(pathValue)) return true;
  if (/@(?:Name|SrcFieldName)$/.test(pathValue)) return true;
  if (difference?.kind === 'field-reference' || difference?.kind === 'field-name-code-points') return true;
  const expectedLatin = LATIN_HELPER_NAMES.get(String(difference?.expected ?? ''));
  return expectedLatin === String(difference?.actual ?? '');
}

function createEquivalentGlyphExport(options = {}) {
  const referencePath = path.resolve(options.referencePath || DEFAULT_REFERENCE_TEXT);
  const outputPath = path.resolve(options.outputPath || DEFAULT_OUTPUT);
  const reportPath = path.resolve(options.reportPath || DEFAULT_REPORT);
  const referenceBytes = readReferenceBytes(referencePath);
  const runtime = createProductionCiffRuntime(referenceBytes);

  runtime.state.fields.forEach((field) => {
    field.name = LATIN_HELPER_NAMES.get(field.name) || field.name;
    field.sourceName = null;
    const segments = field.barcode?.dataMatrix?.segments;
    if (Array.isArray(segments)) {
      segments.forEach((segment) => {
        segment.srcField = LATIN_HELPER_NAMES.get(segment.srcField) || segment.srcField;
      });
      field.barcode.dataMatrix.structureDirty = true;
      field.barcode.bcH = runtime.context.calculateDataMatrixBcH(field);
    }
  });
  runtime.state.fieldByName = new Map(runtime.state.fields.map((field) => [field.name, field]));

  // Start from a genuinely empty SubImage and let the production serializer
  // create every Field from Glyph's model.  1100 reproduces the stale size
  // that previously survived when the DataMatrix was treated as the extent.
  runtime.state.line2 = runtime.state.line2.replace(/<Field\b[^>]*>[\s\S]*?<\/Field>/g, '');
  runtime.state.subImage.width = 1100;
  runtime.state.subImage.height = 1100;
  runtime.state.subImage.usedSizeDirty = true;

  const saved = runtime.save(options.now || new Date(2026, 7, 24, 12, 0, 0, 0));
  const comparison = compareCiffBuffers(referenceBytes, saved.bytes, {
    expected: referencePath,
    actual: outputPath,
  });
  const relevantDifferences = comparison.diffs.filter((difference) => !isTaskIgnoredDifference(difference));
  const referenceSize = readImageSize(runtime.sourceText);
  const generatedSize = readImageSize(saved.prepared.line2);
  const sameGeometry = geometryMatches(runtime.sourceText, saved.prepared.line2);

  const summary = {
    referenceSha256: sha256(referenceBytes),
    generatedSha256: saved.sha256,
    referenceSize,
    generatedSize,
    fieldCount: runtime.state.fields.length,
    sameGeometry,
    relevantDifferenceCount: relevantDifferences.length,
  };

  if (options.write !== false) {
    fs.mkdirSync(path.dirname(outputPath), { recursive: true });
    fs.writeFileSync(outputPath, saved.bytes);
    const report = [
      'Glyph / clarisoft_fix6 geometry regression',
      JSON.stringify(summary, null, 2),
      '',
      'Task-relevant differences after the requested exclusions:',
      relevantDifferences.length ? JSON.stringify(relevantDifferences, null, 2) : 'none',
      '',
      'Full ordered comparison:',
      formatReport(comparison),
    ].join('\n');
    fs.writeFileSync(reportPath, report, 'utf8');
  }

  return {
    ...summary,
    referenceBytes,
    generatedBytes: saved.bytes,
    prepared: saved.prepared,
    comparison,
    relevantDifferences,
    outputPath,
    reportPath,
  };
}

if (require.main === module) {
  const referenceArg = process.argv[2];
  const generated = createEquivalentGlyphExport({ referencePath: referenceArg });
  if (generated.referenceSha256 !== REFERENCE_SHA256) {
    throw new Error(`Unexpected clarisoft_fix6 reference SHA-256: ${generated.referenceSha256}`);
  }
  process.stdout.write(`${JSON.stringify({
    output: generated.outputPath,
    report: generated.reportPath,
    referenceSize: generated.referenceSize,
    generatedSize: generated.generatedSize,
    sameGeometry: generated.sameGeometry,
    relevantDifferenceCount: generated.relevantDifferenceCount,
  }, null, 2)}\n`);
}

module.exports = {
  DEFAULT_REFERENCE_TEXT,
  REFERENCE_SHA256,
  createEquivalentGlyphExport,
  encodeReferenceText,
  readFieldGeometry,
  readImageSize,
};
