const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');
const { createProductionCiffRuntime } = require('./helpers/ciff-production-harness.cjs');

// These fixtures were captured from the installed CiffMgr.dll original machine
// code and COM classes. Recreate them with the scripts beside the JSON files.
const root = path.resolve(__dirname, '..');
const evidence = path.join(root, 'research/clst/implementation-2026-10-21');
const read = file => JSON.parse(fs.readFileSync(path.join(evidence, file), 'utf8'));
const context = vm.createContext({});
for (const file of ['encryption', 'tag-data', 'version-info']) {
  vm.runInContext(fs.readFileSync(path.join(root, `public/modules/clst/${file}.js`), 'utf8'), context);
}
const api = vm.runInContext('({ encryptClStText, randomClStIndexFromTick, buildClStVersionInfoDebugInfo, decodeClStVersionInfo })', context);
const fromUnits = values => String.fromCharCode(...(values ?? []));

test('production transform matches 206 executions of original installed DLL instructions', () => {
  for (const [index, row] of read('native-machine-cases.json').cipher.entries()) {
    assert.equal(api.encryptClStText(row.input, row.key), row.native, `native cipher case ${index}`);
  }
});

test('production reseeded selection RNG matches 438 executions of original MSVCRT path', () => {
  for (const row of read('native-machine-cases.json').randomIndex) {
    assert.equal(api.randomClStIndexFromTick(row.tick, row.bound), row.native);
  }
});

test('complete core matches actual COM generator across native collections and UTF16 edges', () => {
  const inputs = read('native-inputs.json');
  for (const row of read('native-com-results.json').cases) {
    assert.equal(row.status, 'ok');
    const definition = inputs.find(input => input.name === row.name);
    const subImages = definition.subImages.map(() => ({ fields: [] }));
    for (const field of row.before) subImages[field.subImageIndex - 1].fields.push({ name: field.name, calculatedData: fromUnits(field.calculatedDataUnits) });
    const nativeMask = api.decodeClStVersionInfo(row.nativeToken, { fieldCount: row.before.length }).maskHex;
    const result = api.buildClStVersionInfoDebugInfo({ dateOffsets: [], subImages }, new Date('2026-10-21T00:00:00Z'), { mask: nativeMask });
    assert.equal(result.clStVersionInfo, row.nativeToken, row.name);
  }
});

test('prepared source selection and padding match original COM reload and ResolveField', () => {
  for (const row of read('native-resolved-reloaded.json').cases) {
    const filename = path.join(evidence, `resolved-${row.name}.ciff`);
    const runtime = createProductionCiffRuntime(fs.readFileSync(filename), { sourcePath: filename });
    runtime.state.docMeta.designedFor = 'DataFlex 6320(53mm) - Continuous';
    runtime.state.docMeta.printerModel = 'DataFlex 6320(53mm)';
    runtime.state.docMeta.printMode = 'Continuous';
    const saved = runtime.save(new Date('2026-10-21T12:34:56+03:00'), { clstOptions: { mask: '1' } });
    assert.equal(saved.prepared.validation.ok, true, row.name);
    const actual = new Map(Array.from(saved.prepared.calculatedData, ([field, value]) => [field.name, value ?? '']));
    for (const field of row.after) {
      assert.equal(actual.get(field.name), fromUnits(field.calculatedDataUnits), `${row.name}:${field.name}`);
    }
  }
});

test('imported CalcData, Default and UserEnterData match original DLL character-reference normalization', () => {
  for (const row of read('native-import-results.json').cases) {
    const filename = path.join(evidence, `source-${row.name}.ciff`);
    const runtime = createProductionCiffRuntime(fs.readFileSync(filename), { sourcePath: filename });
    for (const field of row.before.filter(field => field.subImageIndex === 1)) {
      assert.equal(runtime.state.fields[field.index - 1].calcData, fromUnits(field.calculatedDataUnits), `${row.name}:CalcData`);
    }
    for (const item of row.properties.filter(item => item.subImage === 1)) {
      const data = runtime.state.fields[item.field - 1].data;
      assert.equal(data.defaultValue, fromUnits(item.defaultUnits), `${row.name}:Default`);
      if (item.userUnits != null) assert.equal(data.userEnterData, fromUnits(item.userUnits), `${row.name}:UserEnterData`);
    }
  }
});

test('production save regenerates tokens already accepted by original COM load and both validators', () => {
  const native = read('saved-native-validation.json').cases;
  const saved = read('save-pipeline-results.json').cases;
  assert.equal(saved.length, 43);
  for (const row of saved) {
    assert.equal(row.status, 'ok');
    const original = native.find(item => item.name === row.name);
    assert.equal(original.status, 'ok');
    assert.equal(original.validate, '00000000');
    assert.equal(original.validate2, '00000000');
    const bytes = fs.readFileSync(path.join(evidence, path.win32.basename(row.file)));
    const runtime = createProductionCiffRuntime(bytes, { sourcePath: row.file, getTickCount: () => 0 });
    if (row.name === 'changed-control-data') {
      const raw = fromUnits(row.rawCalculatedData[0].units);
      runtime.state.fields[0].data.defaultValue = raw;
      runtime.state.fields[0].calcData = raw;
    }
    const output = runtime.save(new Date(row.now), { sourcePath: row.file, clstOptions: { mask: row.mask } });
    assert.equal(output.prepared.validation.ok, true, row.name);
    const token = output.bytes.subarray(2).toString('utf16le').match(/<ClStVersionInfo>([\s\S]*?)<\/ClStVersionInfo>/)?.[1];
    assert.equal(token, original.loadedToken, row.name);
  }
});
