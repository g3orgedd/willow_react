#!/usr/bin/env node
'use strict';

// Reproducible audit of production Glyph policy against the recovered reference.
// This script does NOT start ClariSoft, execute its DLL, or drive either GUI.
// Direct generator cases inject resolveTagData so that field-value resolution
// cannot be mistaken for a verified equivalent of native CalculatedData.
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');
const crypto = require('node:crypto');
const assert = require('node:assert/strict');
const { spawnSync } = require('node:child_process');

const PROJECT_ROOT = path.resolve(__dirname, '../../..');
const { generateClStReference } = require('../reference-generator.cjs');
const { createProductionCiffRuntime } = require(path.join(PROJECT_ROOT, 'tests/helpers/ciff-production-harness.cjs'));
const NOW = new Date('2026-10-20T12:00:00.000Z');
const OUTPUT_PATH = path.join(__dirname, 'glyph-comparison.json');
const TEST_LOG_PATH = path.join(__dirname, 'glyph-tests.log');

const sourceFiles = [
  ['production', 'public/modules/01-ciff-compatibility.js'],
  ['production', 'public/modules/00-core.js'],
  ['production', 'public/modules/20-xml-load.js'],
  ['production', 'public/modules/30-rendering.js'],
  ['production', 'public/modules/60-history-save.js'],
  ['production', 'public/modules/clst/encryption.js'],
  ['production', 'public/modules/clst/tag-data.js'],
  ['production', 'public/modules/clst/version-info.js'],
  ['production-loader', 'src/domain/ciffEditorModules.ts'],
  ['reference', 'research/clst/reference-generator.cjs'],
  ['test-harness', 'tests/helpers/ciff-production-harness.cjs'],
  ['audit-script', 'research/clst/comparison-2026-10-20/glyph-comparison.cjs'],
];

function sha256(bytes) {
  return crypto.createHash('sha256').update(bytes).digest('hex').toUpperCase();
}

function loadProductionGenerator() {
  const context = vm.createContext({ console });
  for (const relativePath of [
    'public/modules/clst/encryption.js',
    'public/modules/clst/tag-data.js',
    'public/modules/clst/version-info.js',
  ]) {
    const filename = path.join(PROJECT_ROOT, relativePath);
    vm.runInContext(fs.readFileSync(filename, 'utf8'), context, { filename });
  }
  return vm.runInContext('({ buildClStVersionInfoDebugInfo, encryptClStText })', context);
}

const production = loadProductionGenerator();

function runProduction(fieldValues) {
  const fields = fieldValues.map((value, index) => ({ name: `F${index}`, auditValue: value }));
  const info = production.buildClStVersionInfoDebugInfo({
    dateOffsets: [],
    subImages: [{ fields }],
  }, NOW, { resolveTagData: (field) => field.auditValue });
  return { ...info, tokenLength: info.clStVersionInfo?.length ?? null };
}

function runReference(fieldValues, mask, extra = {}) {
  const info = generateClStReference({
    dateOffsetCount: 0,
    subImageCount: 1,
    fieldValues,
    ...(mask == null ? {} : { mask }),
    ...extra,
  });
  return { ...info, tokenLength: info.clStVersionInfo.length };
}

function encodeCiff(text) {
  return Buffer.concat([Buffer.from([0xFF, 0xFE]), Buffer.from(text, 'utf16le')]);
}

function emptyCiff(token) {
  const tokenElement = token == null ? '' : `<ClStVersionInfo>${token}</ClStVersionInfo>`;
  return '<?xml version="1.0" encoding="UTF-16"?>\r\n' +
    '<ImageDesign Version="23" xml:space="default">' +
    `<Header DesignedFor="DataFlex 6330(53mm) - Continuous">${tokenElement}</Header>` +
    '<SubImage ImageReference="1"><SubHeader FormatName="Default" PrinterFormatName="Default">' +
    '<ImageWidth>1000</ImageWidth><ImageHeight>1000</ImageHeight>' +
    '<MaxImageWidth>5333</MaxImageWidth><MaxImageHeight>7500</MaxImageHeight>' +
    '<XRes>0.120000</XRes><CurrentOrientation>0</CurrentOrientation></SubHeader></SubImage>' +
    '<GenericSettings><ImageMapping><Map SubIMageRef="1">1</Map></ImageMapping></GenericSettings>' +
    '</ImageDesign>\r\n';
}

function runEmptySave(token) {
  // This uses the repository's Node production harness, with its DOM/UI stubs
  // and disabled geometry validators. It is not an Electron or UI execution.
  const runtime = createProductionCiffRuntime(encodeCiff(emptyCiff(token)));
  const saved = runtime.save(NOW);
  const text = saved.bytes.subarray(2).toString('utf16le');
  const value = text.match(/<ClStVersionInfo(?:\s[^>]*)?>([\s\S]*?)<\/ClStVersionInfo>/)?.[1] ?? null;
  assert.equal(saved.prepared.validation.ok, true, JSON.stringify(saved.prepared.validation));
  return {
    method: 'tests/helpers/ciff-production-harness.cjs: createProductionCiffRuntime().save()',
    inputToken: token,
    clStVersionInfo: value,
    tokenLength: value?.length ?? null,
    validation: saved.prepared.validation,
    outputSha256: sha256(saved.bytes),
  };
}

const cases = [];
const single = runProduction(['alpha']);
const singleReference = runReference(['alpha'], 1);
assert.equal(single.clStVersionInfo, singleReference.clStVersionInfo);
cases.push({
  id: 'one-field',
  fieldValues: ['alpha'],
  production: single,
  recoveredReference: singleReference,
  tokensEqual: true,
  conclusion: 'One selected field and identical supplied CalculatedData reproduce the main reference path.',
});

const three = runProduction(['alpha', 'beta', 'gamma']);
const threeReference = runReference(['alpha', 'beta', 'gamma'], 6);
assert.equal(three.maskHex, '00000001');
assert.equal(threeReference.maskHex, '00000006');
assert.notEqual(three.clStVersionInfo, threeReference.clStVersionInfo);
cases.push({
  id: 'three-fields-different-permitted-mask',
  fieldValues: ['alpha', 'beta', 'gamma'],
  production: three,
  recoveredReference: threeReference,
  referenceMaskSource: 'Explicit mask 6 selects fields 1 and 2; it is permitted by native 1-3 selection attempts. No native RNG is executed here.',
  tokensEqual: false,
  conclusion: 'Production always selects the first resolvable field, while the native policy permits other fields and multiple bits.',
});

const empty = runProduction([]);
const emptyReference = runReference([]);
const missingTokenSave = runEmptySave(null);
const preservedTokenSave = runEmptySave('PRESERVED_VALUE');
assert.equal(empty.clStVersionInfo, null);
assert.equal(emptyReference.tokenLength, 72);
assert.equal(missingTokenSave.tokenLength, 252);
assert.equal(preservedTokenSave.clStVersionInfo, 'PRESERVED_VALUE');
cases.push({
  id: 'empty-generator-and-save-fallback',
  fieldValues: [],
  productionGenerator: empty,
  recoveredReference: emptyReference,
  productionSaveWithoutInputToken: missingTokenSave,
  productionSaveWithInputToken: preservedTokenSave,
  conclusion: 'Production generator returns null; save repairs a missing token using the 252-character constant or preserves an existing syntactically usable value. The recovered main empty path generates 72 characters.',
});

const appended = runProduction(['alpha', 'beta']);
assert.equal(single.structureKey, '000101');
assert.equal(appended.structureKey, '000102');
assert.equal(single.clStVersionInfo, appended.clStVersionInfo);
cases.push({
  id: 'append-unselected-field-count-changes-token-unchanged',
  before: single,
  after: appended,
  tokensEqual: true,
  conclusion: 'DDSSFF contents change but its length stays six. With key-input flag zero, equal mask and selected value therefore produce the same token.',
});

const optionalReference = runReference(['alpha'], 1, {
  includeFileMetadata: true,
  sourcePath: 'C:\\demo\\Report.ciff.new',
});
assert.equal(optionalReference.fileMetadata, 'Report.ciff');
assert.notEqual(single.clStVersionInfo, optionalReference.clStVersionInfo);
cases.push({
  id: 'optional-filename-block',
  production: single,
  recoveredReference: optionalReference,
  tokensEqual: false,
  conclusion: 'The recovered optional path includes Report.ciff filename metadata; production has no implementation of this branch. This does not claim the native flag is enabled on every save.',
});

const testFiles = [
  'tests/clst-version-info-generation.test.cjs',
  'tests/ciff-clst-version-info.test.cjs',
  'research/clst/reference-generator.test.cjs',
];
const tests = spawnSync(process.execPath, ['--test', ...testFiles], {
  cwd: PROJECT_ROOT,
  encoding: 'utf8',
  env: { ...process.env, FORCE_COLOR: '0' },
});
const testLog = `${tests.stdout ?? ''}${tests.stderr ?? ''}${tests.error ? `\n${tests.error.stack}\n` : ''}`;
fs.writeFileSync(TEST_LOG_PATH, testLog, 'utf8');
assert.equal(tests.status, 0, testLog);

const result = {
  auditDate: '2026-10-20',
  runtime: process.version,
  provenance: {
    directGenerator: 'Production clst JS modules executed in Node vm; field values supplied through an injected resolveTagData callback.',
    recoveredReference: 'research/clst/reference-generator.cjs; an independently tested reconstruction, NOT a live native DLL call in this script.',
    saveCases: 'Production save functions executed through the existing Node harness with DOM/UI stubs and disabled geometry validators.',
    noGuiOrDllExecution: true,
    physicalPrinterAcceptance: 'UNKNOWN',
    frozenNow: NOW.toISOString(),
  },
  sources: sourceFiles.map(([role, relativePath]) => {
    const bytes = fs.readFileSync(path.join(PROJECT_ROOT, relativePath));
    return { role, path: relativePath, size: bytes.length, sha256: sha256(bytes) };
  }),
  cases,
  tests: {
    command: `node --test ${testFiles.join(' ')}`,
    exitCode: tests.status,
    testCount: Number(testLog.match(/(?:# |\u2139 )tests (\d+)/)?.[1] ?? 0),
    passCount: Number(testLog.match(/(?:# |\u2139 )pass (\d+)/)?.[1] ?? 0),
    log: 'glyph-tests.log',
    logSha256: sha256(Buffer.from(testLog, 'utf8')),
  },
};
fs.writeFileSync(OUTPUT_PATH, `${JSON.stringify(result, null, 2)}\n`, 'utf8');
process.stdout.write(`${JSON.stringify({ output: OUTPUT_PATH, cases: cases.length, tests: result.tests }, null, 2)}\n`);
