const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');
const { createProductionCiffRuntime } = require('./helpers/ciff-production-harness.cjs');

const nativePreviewFile = path.join(__dirname, '../public/modules/04-native-text-preview.js');
const fixture = path.join(__dirname, 'fixtures/conservative/constant-text.ciff');
const outline = 'M1 6 L5 0 Q7 0 9 6 L7 6 L6 4 L4 4 L3 6 Z M4.5 3 L5.5 3 L5 1 Z';
const tick = () => new Promise((resolve) => setImmediate(resolve));
const plain = (value) => JSON.parse(JSON.stringify(value));

function makeField(fldType = 'FixedText') {
  return { name: fldType, fldType, orientation: 0,
    text: { face: 'Arial', pitch: 13, xMag: 100 },
    data: { defaultValue: 'AB' }, geom: { x: 123, y: 234, w: 1000, h: 400 } };
}

function install(context, fields = context.state.fields) {
  const requests = [];
  const nodes = [];
  const images = [];
  let zoom = 1;
  context.state.fields = fields;
  context.state.subImage.xRes = 0.12;
  context.glyphFonts = { render: (request) => new Promise((resolve, reject) => requests.push({ request, resolve, reject })) };
  context.Image = class {
    constructor() { images.push(this); }
    async decode() { this.decoded = true; }
  };
  class Node {
    constructor(options) { this.options = options; nodes.push(this); }
    x() { return this.options.x || 0; }
    y() { return this.options.y || 0; }
    scaleX() { return this.options.scaleX ?? 1; }
    scaleY() { return this.options.scaleY ?? 1; }
    getSelfRect() { return { x: 1, y: 0, width: 8, height: 6 }; }
  }
  context.Konva = {
    Path: class extends Node { getClassName() { return 'Path'; } },
    Image: class extends Node { getClassName() { return 'Image'; } },
  };
  context.mmToPx = (mm) => mm * 12 * zoom;
  context.requestAnimationFrame = () => {};
  context.console = { warn() {} };
  vm.runInContext(fs.readFileSync(nativePreviewFile, 'utf8'), context, { filename: nativePreviewFile });
  return { context, requests, nodes, images, zoom(value) { zoom = value; } };
}

function load(fields = [makeField()]) {
  const context = {
    state: { xmlDoc: {}, fields, subImage: { xRes: 0.12 } },
    getEffectiveTextFontFamily: (field) => field.text.face || 'Arial',
    getEffectiveTextPitch: (field) => field.text.pitch || 13,
    makePreviewText: (field) => field.data.defaultValue,
  };
  vm.createContext(context);
  return install(context, fields);
}

async function resolvePreview(api, field, extra = { outlinePath: outline }) {
  api.context.requestNativeTextPreview(field, 'AB');
  api.requests.at(-1).resolve({
    width: 120, height: 48, dataUrl: 'data:image/png;base64,dGVzdA==',
    fontFamily: 32, trueType: true, ...extra,
  });
  await tick();
  return api.context.makeNativeTextPreviewNode(field, 'AB');
}

test('all five text types display the native outline as a path without creating or decoding a raster image', async () => {
  for (const type of ['FixedText', 'DateText', 'OffsetDateText', 'TimeText', 'CounterText']) {
    const field = makeField(type);
    const api = load([field]);
    const node = await resolvePreview(api, field);
    assert.equal(node.getClassName(), 'Path', type);
    assert.equal(node.options.data, outline);
    assert.equal(node.options.image, undefined);
    assert.equal(api.images.length, 0, `${type} must not decode a bitmap for a vector preview`);
    assert.equal(node._ciffPreviewTextStyle.native, true);
    assert.equal(node._ciffPreviewTextStyle.vector, true);
    assert.deepEqual(plain(node.getSelfRect()), { x: 0, y: 0, width: 120, height: 48 });
    assert.deepEqual(plain(node._ciffPreviewTextStyle.measuredTextBounds), { x: 0, y: 0, width: 120, height: 48 });
  }
});

test('zoom scales the same vector coordinates continuously and preserves native measurements and the saved field model', async () => {
  const field = makeField();
  const before = JSON.stringify(field);
  const api = load([field]);
  await resolvePreview(api, field);
  const key = api.context.getNativeTextCacheKey(field, 'AB');
  for (const zoom of [0.25, 0.75, 1, 1.333, 4, 8]) {
    api.zoom(zoom);
    const node = api.context.makeNativeTextPreviewNode(field, 'AB');
    assert.equal(node.options.data, outline, 'zoom must not regenerate or rasterize the outline');
    assert.ok(Math.abs(node.scaleX() - zoom) < 1e-12);
    assert.ok(Math.abs(node.scaleY() - zoom) < 1e-12);
    assert.deepEqual(plain(node.getSelfRect()), { x: 0, y: 0, width: 120, height: 48 });
    assert.equal(api.context.getNativeTextCacheKey(field, 'AB'), key);
    assert.equal(JSON.stringify(field), before);
  }
  assert.equal(api.requests.length, 1, 'screen zoom must reuse the same native outline and font measurement');
  assert.equal(api.images.length, 0);
});

test('rotated vector previews retain printer-dot positioning at fractional and large zoom levels', async () => {
  const field = makeField();
  const api = load([field]);
  await resolvePreview(api, field);
  for (const zoom of [0.5, 1.333, 4]) {
    api.zoom(zoom);
    const nominalWidth = api.context.mmToPx(field.geom.w / 100);
    const nominalHeight = api.context.mmToPx(field.geom.h / 100);
    for (const orientation of [0, 90, 180, 270]) {
      field.orientation = orientation;
      const before = JSON.stringify(field);
      const node = api.context.makeNativeTextPreviewNode(field, 'AB', nominalWidth, nominalHeight);
      const width = node.getSelfRect().width * node.scaleX();
      const height = node.getSelfRect().height * node.scaleY();
      const local = orientation === 90 ? { x: nominalHeight - node.y() - height, y: node.x() }
        : orientation === 180 ? { x: nominalWidth - node.x() - width, y: nominalHeight - node.y() - height }
        : orientation === 270 ? { x: node.y(), y: nominalWidth - node.x() - width }
        : { x: node.x(), y: node.y() };
      assert.ok(Math.abs(api.context.mmToPx(field.geom.x / 100) + local.x - 15 * zoom) < 1e-9, `X at ${orientation} degrees / ${zoom}`);
      assert.ok(Math.abs(api.context.mmToPx(field.geom.y / 100) + local.y - 28 * zoom) < 1e-9, `Y at ${orientation} degrees / ${zoom}`);
      assert.equal(node.options.data, outline);
      assert.equal(JSON.stringify(field), before);
    }
  }
});

test('an empty outline stays an empty vector while an absent outline retains the bitmap compatibility fallback', async () => {
  const blank = makeField();
  const vector = load([blank]);
  const empty = await resolvePreview(vector, blank, { outlinePath: '' });
  assert.equal(empty.getClassName(), 'Path');
  assert.equal(empty.options.data, '');
  assert.equal(vector.images.length, 0);

  const legacyField = makeField();
  const legacy = load([legacyField]);
  const image = await resolvePreview(legacy, legacyField, {});
  assert.equal(image.getClassName(), 'Image');
  assert.equal(legacy.images.length, 1);
  assert.equal(legacy.images[0].decoded, true);
  assert.equal(image._ciffPreviewTextStyle.vector, false);
  assert.equal(image.options.width, 120);
  assert.equal(image.options.height, 48);
});

test('changing only vector display and zoom leaves production CIFF bytes and imported geometry unchanged', async () => {
  const runtime = createProductionCiffRuntime(fs.readFileSync(fixture));
  const before = runtime.save();
  assert.equal(before.prepared.validation.ok, true);
  const field = runtime.state.fields[0];
  const geometry = JSON.stringify(field.geom);
  const text = JSON.stringify(field.text);
  const api = install(runtime.context);
  const value = runtime.context.makePreviewText(field);
  runtime.context.requestNativeTextPreview(field, value);
  api.requests[0].resolve({ width: 120, height: 48, outlinePath: outline, dataUrl: 'unused-vector-bitmap' });
  await tick();
  for (const zoom of [0.5, 1, 2, 8]) {
    api.zoom(zoom);
    const node = runtime.context.makeNativeTextPreviewNode(field, value);
    assert.equal(node.getClassName(), 'Path');
    const selection = runtime.context.getTextPreviewSelectionRect(node, node._ciffPreviewTextStyle);
    assert.ok(Math.abs(selection.width - 120 * zoom) < 1e-9, 'the production selection helper must scale the full native cell once');
    assert.ok(Math.abs(selection.height - 48 * zoom) < 1e-9);
  }
  const after = runtime.save();
  assert.equal(after.prepared.validation.ok, true);
  assert.equal(after.sha256, before.sha256);
  assert.equal(JSON.stringify(field.geom), geometry);
  assert.equal(JSON.stringify(field.text), text);
  assert.equal(api.images.length, 0);
});
