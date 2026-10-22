const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

function makeField(type, value) {
  return {
    name: 'A', fldType: type, printed: true,
    text: { face: 'Arial', pitch: 10, xMag: 100 },
    geom: { x: 123, y: 234, w: 999, h: 333 },
    data: { defaultValue: value, dateLocale: 'en', offsetRef: null, counter: {} },
    previewValue: value, _konva: {},
  };
}

function load(field) {
  const requests = [];
  const context = {
    state: { xmlDoc: {}, fields: [field], selectedName: field.name,
      fieldByName: new Map([[field.name, field]]), dateOffsets: [],
      subImage: { xRes: 0.12, usedSizeDirty: false } },
    console,
    glyphFonts: { async render(request) {
      requests.push(request);
      return { width: request.text.length * 12, height: 48, dataUrl: 'data:image/png;base64,dGVzdA==' };
    } },
    getEffectiveTextFontFamily: (target) => target.text.face,
    getEffectiveTextPitch: (target) => target.text.pitch,
    Image: class { async decode() {} },
    requestAnimationFrame() {},
    clamp: (min, max, value) => Math.max(min, Math.min(max, value)),
    document: { activeElement: null },
    elPropsPanel: { querySelector: () => null },
    objLayer: { batchDraw() {} },
    pushHistory() {}, renderSelectionPanels() {},
  };
  vm.createContext(context);
  for (const filename of ['04-native-text-preview.js', '30-rendering.js']) {
    const fullPath = path.join(__dirname, '../public/modules', filename);
    vm.runInContext(fs.readFileSync(fullPath, 'utf8'), context, { filename: fullPath });
  }
  context.makePreviewText = (target) => target.fldType === 'CounterText' ? target.calcData : target.previewValue;
  context.getDynamicFieldValue = context.makePreviewText;
  context.shouldRenderFieldOnCanvas = () => true;
  context.renderSelectionPanels = () => {};
  context.refreshSelectionBoundsForField = () => {};
  context.updatePrintableValidation = () => {};
  context.syncPrintableAreaErrorsOnCanvas = () => {};
  context.rebuildFieldPreviewNode = (target) => {
    context.trackNativeDynamicTextGeometry(target);
    context.requestNativeTextPreview(target, context.makePreviewText(target));
    return true;
  };
  return { context, requests };
}

for (const type of ['DateText', 'OffsetDateText', 'TimeText']) {
  test(`${type}: changing the format recalculates saved geometry before save without moving the text`, async () => {
    const field = makeField(type, type === 'TimeText' ? 'HH:mm' : 'dd/MM/yy');
    const { context, requests } = load(field);
    context.trackNativeDynamicTextGeometry(field);
    field.data.defaultValue = type === 'TimeText' ? 'HH:mm:ss' : 'dd MMM yyyy';
    field.previewValue = type === 'TimeText' ? '12:34:56' : '20 Oct 2026';
    context.refreshSelectedDynamicFieldPreview();
    assert.equal(field._nativeTextGeometryDirty, true);
    await context.ensureNativeTextGeometry([field]);
    assert.equal(field._nativeTextGeometryDirty, undefined);
    assert.equal(field.geom.w, field.previewValue.length * 100);
    assert.equal(field.geom.h, 400);
    assert.equal(field.geom.x, 123);
    assert.equal(field.geom.y, 234);
    assert.equal(requests.at(-1).text, field.previewValue);
  });
}

test('ordinary live clock ticks keep imported geometry intact and do not mark the document dirty', async () => {
  const field = makeField('TimeText', 'HH:mm');
  field.previewValue = '12:34';
  const { context } = load(field);
  context.trackNativeDynamicTextGeometry(field);
  field.previewValue = '12:35';
  context.refreshSelectedDynamicFieldPreview();
  await new Promise((resolve) => setImmediate(resolve));
  await context.ensureNativeTextGeometry([field]);
  assert.deepEqual(field.geom, { x: 123, y: 234, w: 999, h: 333 });
  assert.equal(field._nativeTextGeometryDirty, undefined);
  assert.equal(context.state.subImage.usedSizeDirty, false);
});

test('counter digit edits resize the saved field after native measurement and retain its position', async () => {
  const field = makeField('CounterText', '0001');
  field.data.counter = { noOfChars: 4, startVal: '1', endVal: '9999', stepSize: 1 };
  field.calcData = '0001';
  const { context, requests } = load(field);
  context.applyCounterFieldChange(field, (counter) => { counter.noOfChars = 8; });
  assert.equal(field._nativeTextGeometryDirty, true);
  await context.ensureNativeTextGeometry([field]);
  assert.equal(field.calcData, '00000001');
  assert.equal(field.geom.w, 800);
  assert.equal(field.geom.h, 400);
  assert.equal(field.geom.x, 123);
  assert.equal(field.geom.y, 234);
  assert.equal(requests.at(-1).text, '00000001');
});

test('changing an offset delta remeasures the date while unchanged imports only establish their baseline', () => {
  const field = makeField('OffsetDateText', 'dd MMM yyyy');
  field.data.offsetRef = 'SellBy';
  const { context } = load(field);
  context.state.dateOffsets = [{ name: 'SellBy', delta: { y: 0, m: 0, d: 1 } }];
  assert.equal(context.trackNativeDynamicTextGeometry(field), false);
  assert.equal(context.trackNativeDynamicTextGeometry(field), false);
  context.state.dateOffsets[0].delta.d = 30;
  assert.equal(context.trackNativeDynamicTextGeometry(field), true);
  assert.equal(field._nativeTextGeometryDirty, true);
});
