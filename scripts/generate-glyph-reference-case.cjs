#!/usr/bin/env node

const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

const {
  compareCiffBuffers,
  formatReport,
} = require('./compare-ciff-structure.cjs');

const PROJECT_ROOT = path.join(__dirname, '..');
const DEFAULT_REFERENCE = path.join(
  PROJECT_ROOT,
  'tests',
  'fixtures',
  'clarisoft',
  'Clarisoft_test_1.ciff',
);
const DEFAULT_OUTPUT = path.join(
  PROJECT_ROOT,
  'tests',
  'output',
  'Glyph_test_1.generated.ciff',
);
const DEFAULT_REPORT = path.join(
  PROJECT_ROOT,
  'tests',
  'output',
  'Glyph_test_1.generated.diff.txt',
);

function createElementStub() {
  return {
    addEventListener: () => {},
    appendChild: () => {},
    classList: { add: () => {}, remove: () => {}, toggle: () => {} },
    dataset: {},
    querySelector: () => null,
    querySelectorAll: () => [],
    setAttribute: () => {},
    style: {},
  };
}

function loadProductionGenerator() {
  const context = {
    console,
    glyphSystemTickCount: () => 0,
    window: {
      clearInterval: () => {},
      setInterval: () => 0,
      setTimeout: (callback) => callback(),
    },
    document: {
      body: { appendChild: () => {}, classList: { add: () => {}, remove: () => {} } },
      createElement: createElementStub,
      getElementById: () => null,
      querySelector: () => null,
      querySelectorAll: () => [],
    },
    appLogger: {
      action: () => {},
      file: () => {},
      log: () => {},
      state: () => {},
    },
    t: (key) => key,
    openNotificationModal: () => {},
    mmToInternal: (value) => Math.round(Number(value) * 100),
    internalToMm: (value) => Number(value) / 100,
    mmToPx: (value) => Number(value),
    pxToMm: (value) => Number(value),
    getCanvasInternalWidth: () => 5333,
    getCanvasInternalHeight: () => 7500,
    constrainFieldPositionInternal: (_field, x, y) => ({ x, y }),
    constrainCurrentFieldPositionsInternal: () => {},
    setSelectedNames: () => {},
    renderAll: () => {},
    renderObjects: () => {},
    renderUI: () => {},
    refreshCanvasPreviews: () => {},
    refreshFieldCanvasPreview: () => {},
    updateUndoRedoButtons: () => {},
    getSelectedNames: () => [],
    markActiveTemplateTabDirty: () => {},
  };
  context.globalThis = context;
  vm.createContext(context);

  for (const relativePath of [
    'public/modules/00-core.js',
    'public/modules/01-ciff-compatibility.js',
    'public/modules/clst/encryption.js',
    'public/modules/clst/tag-data.js',
    'public/modules/clst/calculated-data.js',
    'public/modules/clst/version-info.js',
    'public/modules/20-xml-load.js',
    'public/modules/30-rendering.js',
    'public/modules/40-editor.js',
    'public/modules/45-template-preset.js',
    'public/modules/60-history-save.js',
  ]) {
    const filename = path.join(PROJECT_ROOT, relativePath);
    vm.runInContext(fs.readFileSync(filename, 'utf8'), context, { filename });
  }

  return vm.runInContext(`({
    createDefaultTemplatePresetDraft,
    normalizeTemplatePresetDraft,
    generateTemplatePreset,
    buildFieldXmlOneLine,
    encodeUtf16leWithBom
  })`, context);
}

function createReferenceDraft(api) {
  const draft = api.createDefaultTemplatePresetDraft();
  draft.creationKind = 'preset-builder';
  draft.dataSourceMode = 'server-full';
  draft.base.printerModel = 'DataFlex 6330(53mm)';
  draft.base.printMode = 'Continuous';
  draft.base.widthMm = 39.17;
  draft.base.heightMm = 28.92;
  draft.dataMatrix.symbolSize = '22X22';
  draft.dataMatrix.snValue = '0000000000000';
  draft.dataMatrix.moduleSize = 0.5;

  for (const [key, field] of Object.entries(draft.fields)) {
    field.enabled = ['productDate', 'expirationDate', 'party', 'team', 'rNum'].includes(key);
  }
  return draft;
}

function serializeGeneratedPreset(api, result) {
  if (!result?.ok) {
    const details = (result?.issues || []).map((issue) => issue.code).join(', ');
    throw new Error(`Reference preset generation failed: ${details || 'unknown validation error'}`);
  }

  // Serialize the generated design first, then use the actual save pipeline
  // to derive ClSt from its final structure and prepared CalculatedData.
  const parts = String(result.xml).split(/\r?\n/);
  const declaration = parts.shift();
  const imageDesign = parts.join('');
  const fieldXml = result.fields.map((field) => api.buildFieldXmlOneLine(field)).join('');
  const design = imageDesign.replace('</SubImage>', `${fieldXml}</SubImage>`);
  if (design === imageDesign) throw new Error('Generated template has no SubImage closing tag.');
  const { createProductionCiffRuntime } = require('../tests/helpers/ciff-production-harness.cjs');
  const source = Buffer.concat([Buffer.from([0xFF, 0xFE]), Buffer.from(`${declaration}\r\n${design}\r\n`, 'utf16le')]);
  const runtime = createProductionCiffRuntime(source);
  const saved = runtime.save(new Date(2026, 7, 29, 21, 22));
  if (!saved.prepared.validation.ok) throw new Error(JSON.stringify(saved.prepared.validation));
  return saved.bytes;
}

function generateReferenceCase(options = {}) {
  const api = loadProductionGenerator();
  const result = api.generateTemplatePreset(createReferenceDraft(api));
  const generatedBytes = serializeGeneratedPreset(api, result);
  const referencePath = path.resolve(options.referencePath || DEFAULT_REFERENCE);
  const outputPath = path.resolve(options.outputPath || DEFAULT_OUTPUT);
  const reportPath = path.resolve(options.reportPath || DEFAULT_REPORT);
  const referenceBytes = fs.readFileSync(referencePath);
  const comparison = compareCiffBuffers(
    referenceBytes,
    generatedBytes,
    referencePath,
    outputPath,
  );

  if (options.write !== false) {
    fs.mkdirSync(path.dirname(outputPath), { recursive: true });
    fs.writeFileSync(outputPath, generatedBytes);
    fs.writeFileSync(reportPath, formatReport(comparison), 'utf8');
  }

  return {
    result,
    generatedBytes,
    comparison,
    outputPath,
    reportPath,
  };
}

if (require.main === module) {
  const generated = generateReferenceCase();
  process.stdout.write(`${JSON.stringify({
    output: generated.outputPath,
    report: generated.reportPath,
    fields: generated.result.fields.map((field) => field.name),
    summary: generated.comparison.summary,
    totalDifferences: generated.comparison.diffs.length,
  }, null, 2)}\n`);
}

module.exports = {
  createReferenceDraft,
  generateReferenceCase,
  loadProductionGenerator,
  serializeGeneratedPreset,
};
