'use strict';

const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const {
  loadProductionGenerator,
  serializeGeneratedPreset,
} = require('../scripts/generate-glyph-reference-case.cjs');
const {
  createProductionCiffRuntime,
  decodeCiffBytes,
  sha256,
} = require('./helpers/ciff-production-harness.cjs');
const {
  collectSourceEvidence,
  decryptClStText,
  inspectCoreLayout,
} = require('../scripts/inspect-clst.cjs');

const NOW = new Date(2026, 9, 21, 12, 34, 56);
const PLAIN_ORDER = ['C1', 'GTIN2', 'C3', 'PRODUCT_DATE', 'C2', 'SN'];
const DEFAULTS = {
  C1: '~101', GTIN: '0'.repeat(14), GTIN2: '0'.repeat(14), C3: '11', PRODUCT_DATE: '0'.repeat(6),
  C2: '10', SN: '0'.repeat(10), C4: '21', BOX_COUNTER: '0'.repeat(5),
};
const USER_FIELDS = { GTIN2: 14, PRODUCT_DATE: 6, SN: 12, BOX_COUNTER: 5 };

function expectedOrder(withBoxCounter, gtinFieldName = 'GTIN2') {
  const order = PLAIN_ORDER.map(name => name === 'GTIN2' ? gtinFieldName : name);
  return withBoxCounter ? [...order, 'C4', 'BOX_COUNTER'] : order;
}

function createBatch(withBoxCounter, configure = () => {}) {
  const api = loadProductionGenerator();
  const draft = api.createDefaultTemplatePresetDraft();
  draft.creationKind = 'preset-builder';
  draft.dataSourceMode = 'party-code';
  draft.partyCode = { withBoxCounter };
  configure(draft);
  const result = api.generateTemplatePreset(draft);
  assert.equal(result.ok, true, JSON.stringify(result.issues));
  return { api, draft, result };
}

function matrix(fields) {
  const matrices = fields.filter(field => field.fldType === 'Barcode' && field.barcode?.dataMatrix);
  assert.equal(matrices.length, 1);
  return matrices[0];
}

function segmentNames(field) {
  return Array.from(field.barcode.dataMatrix.segments, segment => segment.srcField);
}

function readSaved(bytes) {
  const runtime = createProductionCiffRuntime(bytes);
  const xml = decodeCiffBytes(bytes);
  const doc = new runtime.context.DOMParser().parseFromString(xml, 'text/xml');
  const fields = new Map(doc.querySelectorAll('SubImage > Field').map(field => [field.getAttribute('Name'), field]));
  return { runtime, xml, doc, fields };
}

function assertValidClSt(xml) {
  const evidence = collectSourceEvidence(xml);
  const decoded = inspectCoreLayout(decryptClStText(evidence.token, 'TpyRcNeyeK'), evidence);
  assert.equal(decoded.consistent, true);
  assert.equal(decoded.matchesSelectedCalcData, true);
}

for (const gtinFieldName of ['GTIN2', 'GTIN']) {
for (const withBoxCounter of [false, true]) {
  const variant = `${gtinFieldName} ${withBoxCounter ? 'with box counter' : 'without box counter'}`;
  const order = expectedOrder(withBoxCounter, gtinFieldName);
  const userFields = { ...USER_FIELDS };
  if (gtinFieldName === 'GTIN') {
    delete userFields.GTIN2;
    userFields.GTIN = 14;
  }

  test(`party preset ${variant} uses its own ordered recipe and operator fields`, () => {
    const { result } = createBatch(withBoxCounter, draft => { draft.partyCode.gtinFieldName = gtinFieldName; });
    const dm = matrix(result.fields);
    assert.deepEqual(segmentNames(dm), order);
    assert.deepEqual(Array.from(dm.barcode.dataMatrix.segments, segment => segment.index), order.map((_, index) => index));
    assert.equal(result.fields.length, order.length + 1);
    assert.ok(result.fields.filter(field => field !== dm).every(field => field.printed === false));
    assert.equal(result.fields.some(field => [gtinFieldName === 'GTIN' ? 'GTIN2' : 'GTIN', 'KRIPTO', 'KRIPTO2'].includes(field.name)), false);
    assert.deepEqual(Array.from(result.dateOffsets), []);

    for (const name of order) {
      const field = result.fields.find(item => item.name === name);
      assert.ok(field, name);
      assert.equal(field.fldType, 'FixedText', name);
      assert.equal(field.text.pitch, 10, name);
      assert.equal(field.text.xMag, 100, name);
      assert.equal(field.data.defaultValue, DEFAULTS[name], name);
      if (userFields[name]) {
        assert.equal(field.data.textEntryMode, 'user', name);
        assert.equal(field.data.userEnterData, DEFAULTS[name], name);
        assert.equal(field.data.maxChars, userFields[name], name);
        assert.equal(field.data.fixedLen, true, name);
      } else {
        assert.equal(field.data.textEntryMode, 'fixed', name);
        assert.equal(field.data.fixedLen, false, name);
      }
    }
    assert.equal(result.fields.some(field => field.name === 'BOX_COUNTER'), withBoxCounter);
  });

  test(`party preset ${variant} survives real XML save/reopen with ordered links, lengths and ClSt`, () => {
    const { api, result } = createBatch(withBoxCounter, draft => { draft.partyCode.gtinFieldName = gtinFieldName; });
    const bytes = serializeGeneratedPreset(api, result);
    assert.deepEqual(Array.from(bytes.subarray(0, 2)), [0xFF, 0xFE]);
    const saved = readSaved(bytes);
    const dm = matrix(saved.runtime.state.fields);
    assert.deepEqual(segmentNames(dm), order);
    assert.equal(saved.fields.has(gtinFieldName === 'GTIN' ? 'GTIN2' : 'GTIN'), false);
    const xmlDm = saved.fields.get(dm.name);
    const objects = xmlDm.querySelectorAll(':scope > Data > Object');
    assert.deepEqual(objects.map(object => object.querySelector(':scope > SrcField').getAttribute('SrcFieldName')), order);
    assert.deepEqual(objects.map(object => Number(object.getAttribute('Index') ?? 0)), order.map((_, index) => index));
    for (const name of order) {
      assert.equal(saved.fields.get(name).querySelector(':scope > Text > Font > Pitch').textContent, '10', name);
    }

    for (const [name, maxChars] of Object.entries(userFields)) {
      if (name === 'BOX_COUNTER' && !withBoxCounter) continue;
      const field = saved.fields.get(name);
      assert.equal(field.querySelector(':scope > FldType').textContent, 'FixedText', name);
      const object = field.querySelector(':scope > Data > Object');
      assert.equal(object.getAttribute('Static'), '0', name);
      assert.equal(object.querySelector(':scope > MaxNoOfChars').textContent, String(maxChars), name);
      assert.equal(object.querySelector(':scope > Default').textContent, DEFAULTS[name], name);
      assert.equal(object.querySelector(':scope > VarText > UserEnterData').textContent, DEFAULTS[name], name);
      assert.ok(object.querySelector(':scope > FixedLen'), name);
    }

    // Ten entered characters and a 12-character fixed-length slot are distinct:
    // native save pads CalculatedData while keeping operator input unchanged.
    assert.equal(saved.fields.get('SN').querySelector(':scope > CalcData').textContent, '0'.repeat(10) + '  ');
    const expectedPayload = order.map(name => name === 'SN' ? DEFAULTS.SN + '  ' : DEFAULTS[name]).join('');
    assert.equal(xmlDm.querySelector(':scope > CalcData').textContent, expectedPayload);
    assert.equal(objects[5].querySelector(':scope > Default').textContent, DEFAULTS.SN + '  ');
    assertValidClSt(saved.xml);

    const savedAgain = saved.runtime.save(NOW, { clstOptions: { mask: 1 } });
    assert.equal(savedAgain.prepared.validation.ok, true, JSON.stringify(savedAgain.prepared.validation));
    const reopened = readSaved(savedAgain.bytes);
    assert.deepEqual(segmentNames(matrix(reopened.runtime.state.fields)), order);
    assert.equal(reopened.runtime.state.fieldByName.get('SN').data.maxChars, 12);
    assert.equal(reopened.runtime.state.fieldByName.get('PRODUCT_DATE').data.textEntryMode, 'user');
    assertValidClSt(reopened.xml);
  });
}
}

test('party GTIN choice defaults to GTIN2 for existing drafts and normalizes unsupported names', () => {
  const api = loadProductionGenerator();
  assert.equal(api.createDefaultTemplatePresetDraft().partyCode.gtinFieldName, 'GTIN2');
  for (const gtinFieldName of [undefined, null, '', 'OTHER', 'gtin']) {
    const { result } = createBatch(false, draft => { draft.partyCode.gtinFieldName = gtinFieldName; });
    assert.equal(result.draft.partyCode.gtinFieldName, 'GTIN2');
    assert.deepEqual(segmentNames(matrix(result.fields)), PLAIN_ORDER);
  }
});

test('printing the party PRODUCT_DATE reuses its source field instead of adding a second date', () => {
  const { api, result } = createBatch(true, draft => { draft.fields.productDate.enabled = true; });
  const dates = result.fields.filter(field => field.name === 'PRODUCT_DATE');
  assert.equal(dates.length, 1);
  assert.equal(dates[0].printed, true);
  assert.equal(dates[0].fldType, 'FixedText');
  assert.equal(dates[0].data.maxChars, 6);
  assert.equal(dates[0].data.textEntryMode, 'user');
  const saved = readSaved(serializeGeneratedPreset(api, result));
  assert.equal(saved.runtime.state.fields.filter(field => field.name === 'PRODUCT_DATE').length, 1);
  assert.deepEqual(segmentNames(matrix(saved.runtime.state.fields)), expectedOrder(true));
});

test('party normalization cannot leak its recipe into the existing marking presets', () => {
  const api = loadProductionGenerator();
  const defaults = api.createDefaultTemplatePresetDraft();
  defaults.creationKind = 'preset-builder';
  const party = api.normalizeTemplatePresetDraft({ ...defaults, dataSourceMode: 'party-code', partyCode: { withBoxCounter: true } });
  for (const [symbolSize, snLength, expected] of [
    ['22X22', 6, ['C1', 'GTIN', 'C2', 'SN', 'C3', 'KRIPTO']],
    ['36X36', 13, ['C1', 'GTIN', 'C2', 'SN', 'C3', 'KRIPTO', 'C4', 'KRIPTO2']],
  ]) {
    const regular = api.normalizeTemplatePresetDraft({ ...party, dataSourceMode: 'server-full', dataMatrix: { ...party.dataMatrix, symbolSize, snValue: '0'.repeat(snLength) } });
    const result = api.generateTemplatePreset(regular);
    assert.equal(result.ok, true, JSON.stringify(result.issues));
    assert.deepEqual(segmentNames(matrix(result.fields)), expected);
    assert.equal(result.fields.find(field => field.name === 'SN').data.maxChars, snLength);
    assert.equal(result.fields.some(field => ['GTIN2', 'BOX_COUNTER'].includes(field.name)), false);
  }
});

for (const [file, expectedHash, barcodeName, order] of [
  ['Party.ciff', '750E00AFD3269D602EA9A7F2AB40053C92AA594A960868DD712CFFF8E96E5828', 'C4', [...PLAIN_ORDER, 'C5', 'BOX_COUNTER']],
  ['Party1.ciff', 'D9A97615A4833A380EEC733581AE484D6AE70E6C6957CD9AA3380489D121EEC5', 'Field00', PLAIN_ORDER],
]) {
  test(`existing ${file} keeps its original names and composition on import/save`, () => {
    const bytes = fs.readFileSync(path.join(__dirname, 'fixtures', 'party', file));
    assert.equal(sha256(bytes), expectedHash);
    const runtime = createProductionCiffRuntime(bytes);
    const originalNames = Array.from(runtime.state.fields, field => field.name);
    assert.equal(matrix(runtime.state.fields).name, barcodeName);
    assert.deepEqual(segmentNames(matrix(runtime.state.fields)), order);
    assert.equal(runtime.state.fieldByName.get('SN').data.maxChars, 12);
    assert.equal(runtime.state.fieldByName.get('SN').data.userEnterData.length, 10);
    assert.equal(runtime.state.fieldByName.get('PRODUCT_DATE').data.maxChars, 6);
    const saved = runtime.save(NOW, { clstOptions: { mask: 1 } });
    assert.equal(saved.prepared.validation.ok, true, JSON.stringify(saved.prepared.validation));
    const reopened = readSaved(saved.bytes);
    assert.deepEqual(Array.from(reopened.runtime.state.fields, field => field.name), originalNames);
    assert.equal(matrix(reopened.runtime.state.fields).name, barcodeName);
    assert.deepEqual(segmentNames(matrix(reopened.runtime.state.fields)), order);
    assert.equal(reopened.runtime.state.fields.some(field => ['GTIN', 'KRIPTO', 'KRIPTO2'].includes(field.name)), false);
    assertValidClSt(reopened.xml);
  });
}
