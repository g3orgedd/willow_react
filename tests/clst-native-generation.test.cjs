'use strict';
const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

const ROOT = path.resolve(__dirname, '..');
const NOW = new Date('2026-10-21T12:00:00Z');

function loadApi(extra = {}) {
  const context = vm.createContext({ glyphSystemTickCount: () => 0, ...extra });
  for (const name of ['encryption', 'tag-data', 'version-info']) {
    const filename = path.join(ROOT, `public/modules/clst/${name}.js`);
    vm.runInContext(fs.readFileSync(filename, 'utf8'), context, { filename });
  }
  return vm.runInContext(`({
    CEncryption, encryptClStText, decryptClStText, isClStEncodedText,
    randomClStIndexFromTick, createClStSelectionMask, resolveClstTagData,
    buildClStVersionInfoDebugInfo, generateClStVersionInfo,
    normalizeClStFileMetadata, clStFileMetadataMatchesSource,
    decodeClStVersionInfo, isValidClStVersionInfoSyntax, recognizeClStFileMetadataMode
  })`, context);
}

function template(values) {
  return { dateOffsets: [], subImages: [{ fields: values.map((calculatedData, index) => ({ name: `F${index}`, calculatedData })) }] };
}

test('production E matches all 204 independently executed DLL vectors and reverses UTF-16 including NUL', () => {
  const api = loadApi();
  const cases = JSON.parse(fs.readFileSync(path.join(ROOT, 'research/clst/native/oracle-comparison-cases.json'), 'utf8'));
  assert.equal(cases.length, 204);
  for (const item of cases) {
    assert.equal(api.encryptClStText(item.input, item.key), item.native, item.kind);
    assert.equal(api.decryptClStText(item.native, item.key), item.input, item.kind);
  }
  assert.throws(() => new api.CEncryption('\0ignored'), /non-empty/);
});

test('native selection reseeds on every call, permits repeats and selects bit 31 without resolving field types', () => {
  const api = loadApi();
  assert.equal(api.randomClStIndexFromTick(0, 100), 38);
  assert.equal(api.randomClStIndexFromTick(1, 100), 41);
  const five = api.createClStSelectionMask(template(['a', 'b', 'c', 'd', 'e']).subImages[0].fields, NOW, {
    tickCounts: [0, 0, 0, 0],
    resolveTagData: () => { throw new Error('Selection must not inspect types or values.'); },
  });
  assert.equal(five.attempts, 3);
  assert.equal(five.maskHex, '00000008');
  const draws = [2, 31, 0, 31];
  const bounds = [];
  const info = api.buildClStVersionInfoDebugInfo(template(Array(33).fill('x')), NOW, {
    nextMod: (bound) => { bounds.push(bound); return draws.shift(); },
  });
  assert.deepEqual(bounds, [3, 32, 32, 32]);
  assert.equal(info.maskHex, '80000001');
  assert.deepEqual(Array.from(info.selectedFieldIndices), [0, 31]);
  assert.equal(info.tagData, 'xx');
  assert.throws(() => api.createClStSelectionMask([{}, {}], NOW, { tickCounts: [0] }), /enough/);
});

test('native selection boundaries cover F0/1/2/3/31/32/33 with injectable ticks', () => {
  const api = loadApi();
  for (const count of [0, 1, 2, 3, 31, 32, 33]) {
    let calls = 0;
    const info = api.buildClStVersionInfoDebugInfo(template(Array(count).fill('')), NOW, {
      getTickCount: () => { calls += 1; return 0; },
    });
    const expectedAttempts = count ? 1 + (38 % Math.min(count, 3)) : 0;
    assert.equal(calls, count ? 1 + expectedAttempts : 0);
    assert.equal(info.attempts, expectedAttempts);
    assert.equal(info.mask, count ? (1 << (38 % Math.min(count, 32))) >>> 0 : 0);
    assert.equal(info.clStVersionInfo.length, 72);
  }
});

test('prepared CalculatedData accepts unknown, graphic, hidden and empty fields without type filtering', () => {
  const api = loadApi({ getStoredTextFieldValue: () => 'incorrect fallback' });
  const fields = [
    { fldType: 'Graphic', calculatedData: '' },
    { fldType: 'VendorType', CalculatedData: 'RAW\u0001' },
    { fldType: 'FixedText', printed: false, calculatedData: 'HIDDEN' },
  ];
  const info = api.buildClStVersionInfoDebugInfo({ subImages: [{ fields }] }, NOW, { mask: 7 });
  assert.equal(info.tagData, 'RAW\u0001HIDDEN');
  assert.equal(api.resolveClstTagData({ fldType: 'Vendor', calcData: '' }, NOW), '');
  const prepared = new Map([[fields[0], 'BY-OBJECT'], ['SECOND', 'BY-NAME']]);
  assert.equal(api.resolveClstTagData(fields[0], NOW, { calculatedData: prepared }), 'BY-OBJECT');
  assert.equal(api.resolveClstTagData({ name: 'SECOND', calculatedData: 'unused' }, NOW, { calculatedData: prepared }), 'BY-NAME');
  const unresolved = api.buildClStVersionInfoDebugInfo({ subImages: [{ fields: [{ fldType: 'Unknown' }, fields[2]] }] }, NOW, { mask: 1 });
  assert.equal(unresolved.clStVersionInfo, null);
  assert.equal(unresolved.maskHex, '00000001');
  assert.deepEqual(Array.from(unresolved.unresolvedSelectedFieldIndices), [0]);
});

test('prepared helper is used before legacy type-specific preview fallbacks', () => {
  const api = loadApi({ resolveCiffCalculatedData: () => 'prepared helper', getTimeTextValue: () => 'incorrect time' });
  assert.equal(api.resolveClstTagData({ fldType: 'TimeText', data: {} }, NOW), 'prepared helper');
  assert.equal(api.resolveClstTagData({ fldType: 'TimeText', calculatedData: '' }, NOW), '');
  assert.equal(api.resolveClstTagData({ fldType: 'Unknown', data: { defaultValue: 'unverified default' } }, NOW), null);
});

test('empty main path, collection-order payload and UTF-16 truncation match saved native compositions', () => {
  const api = loadApi();
  const cases = JSON.parse(fs.readFileSync(path.join(ROOT, 'research/clst/native/composition-results.json'), 'utf8')).cases;
  for (const item of cases) {
    const fieldCount = parseInt(item.counterKey.slice(4), 10);
    const fieldValues = item.fieldValues || Array(fieldCount).fill('');
    if (!item.fieldValues && fieldCount > 0) fieldValues[0] = item.selectedPayload;
    const model = template(fieldValues);
    model.dateOffsets = Array(item.dateOffsetCount ?? parseInt(item.counterKey.slice(0, 2), 10)).fill({});
    const info = api.buildClStVersionInfoDebugInfo(model, NOW, { mask: item.maskHex });
    assert.equal(info.clStVersionInfo, item.clStVersionInfo, item.description);
  }
  const acrossSubImages = { subImages: [{ fields: [{ calculatedData: 'FIRST-' }] }, { fields: [{ calculatedData: 'SECOND' }] }] };
  const joined = api.buildClStVersionInfoDebugInfo(acrossSubImages, NOW, { mask: 3 });
  assert.equal(joined.tagData, 'FIRST-SECOND');
  assert.equal(api.decodeClStVersionInfo(joined.clStVersionInfo, { fieldCount: 2 }).mask, 3);
  const splitSurrogate = api.buildClStVersionInfoDebugInfo(template(['1'.repeat(19), '😀Z']), NOW, { mask: 3 });
  assert.equal(splitSurrogate.tagData.charCodeAt(19), 0xD83D);
});

test('all native splitpath and optional-block vectors match production normalization and assembly', () => {
  const api = loadApi();
  const pathCases = fs.readFileSync(path.join(ROOT, 'research/clst/optional/splitpath-cases.jsonl'), 'utf8').trim().split(/\r?\n/).map(JSON.parse);
  for (const item of pathCases) assert.equal(api.normalizeClStFileMetadata(item.sourcePath), item.metadataPlaintext, item.sourcePath);
  const cases = JSON.parse(fs.readFileSync(path.join(ROOT, 'research/clst/optional/optional-composition-results.json'), 'utf8')).cases;
  for (const item of cases) {
    const info = api.buildClStVersionInfoDebugInfo(template(item.input.fieldValues), NOW, item.input);
    for (const key of ['fileMetadata', 'metadataFragment', 'metadataLengthFragment', 'normalIntermediate', 'intermediate', 'clStVersionInfo']) {
      assert.equal(info[key], item[key], `${key}: ${item.input.sourcePath}`);
    }
    assert.equal(api.isValidClStVersionInfoSyntax(info.clStVersionInfo), true);
    const decoded = api.decodeClStVersionInfo(info.clStVersionInfo);
    assert.equal(decoded.fileMetadata, item.fileMetadata);
  }
});

test('optional filename mode is recognized only for its matching .ciff source and preserved on save-as', () => {
  const api = loadApi();
  const model = template(['alpha']);
  const original = api.generateClStVersionInfo(model, NOW, { mask: 1, includeFileMetadata: true, sourcePath: 'C:\\labels\\Report.ciff.new' });
  assert.equal(api.recognizeClStFileMetadataMode(original, 'D:\\other\\REPORT.CIFF'), true);
  assert.equal(api.recognizeClStFileMetadataMode(original, 'Report.ciff.new'), false);
  assert.equal(api.recognizeClStFileMetadataMode(original, 'Other.ciff'), false);
  assert.equal(api.recognizeClStFileMetadataMode(original, ''), false);
  const renamed = api.buildClStVersionInfoDebugInfo(model, NOW, {
    mask: 1, originalClStVersionInfo: original,
    originalSourceName: 'Report.ciff', sourceName: 'Renamed.ciff',
  });
  assert.equal(renamed.includeFileMetadata, true);
  assert.equal(api.decodeClStVersionInfo(renamed.clStVersionInfo).fileMetadata, 'Renamed.ciff');
  const noEnvelope = api.buildClStVersionInfoDebugInfo(model, NOW, {
    mask: 1, originalClStVersionInfo: original, sourceName: 'Report.ciff', includeFileMetadata: false,
  });
  assert.equal(noEnvelope.includeFileMetadata, false);
  assert.equal(noEnvelope.clStVersionInfo.length, 117);
  const ordinary = api.generateClStVersionInfo(template(Array(4).fill('long main payload')), NOW, { mask: 8 });
  assert.equal(api.decodeClStVersionInfo(ordinary, { sourcePath: 'Report.ciff', requireFileNameMatch: true }).includeFileMetadata, false);
  assert.throws(() => api.decodeClStVersionInfo(original, { sourcePath: 'Other.ciff', requireFileNameMatch: true }), /filename metadata/);
});

test('token syntax checks triples, decrypted masks, bounds and nested payload instead of accepting arbitrary strings', () => {
  const api = loadApi();
  const valid = api.generateClStVersionInfo(template(['alpha']), NOW, { mask: 1 });
  assert.equal(api.isValidClStVersionInfoSyntax(valid), true);
  for (const token of ['', 'LOADED_VALUE', valid + 'A', valid.replace(/^./, '_'), '0'.repeat(72), ` ${valid}`]) {
    assert.equal(api.isValidClStVersionInfoSyntax(token), false, token);
  }
  assert.throws(() => api.decodeClStVersionInfo(valid, { fieldCount: 0 }), /outside/);
  assert.throws(() => api.decryptClStText('00_', 'TagData'), /triples/);
  assert.throws(() => api.generateClStVersionInfo(template(['a', 'b']), NOW, { mask: 0 }), /one to three/);
  assert.throws(() => api.generateClStVersionInfo(template([]), NOW, { mask: 1 }), /outside/);
  assert.throws(() => api.generateClStVersionInfo(template(Array(5).fill('')), NOW, { mask: 15 }), /one to three/);
});
