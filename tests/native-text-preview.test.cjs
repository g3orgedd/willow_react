const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

function field(name = 'A', face = 'Arial') {
  return { name, fldType: 'FixedText', text: { face, pitch: 10, xMag: 100 },
    geom: { x: 100, y: 200, w: 777, h: 333 }, data: { defaultValue: 'AB' } };
}
function load(fields = [field()]) {
  const requests = [];
  const refreshes = [];
  const warnings = [];
  const context = {
    state: { xmlDoc: {}, fields, subImage: { xRes: 0.12, usedSizeDirty: false } },
    console: { warn: (...args) => warnings.push(args) },
    glyphFonts: { render: (request) => new Promise((resolve, reject) => requests.push({ request, resolve, reject })) },
    getEffectiveTextFontFamily: (target) => target.text.face || 'Arial',
    getEffectiveTextPitch: (target) => target.text.pitch ?? target.text.defaultPitch ?? 13,
    makePreviewText: (target) => target.data.defaultValue,
    Image: class { async decode() {} },
    Konva: { Image: class { constructor(options) { this.options = options; } } },
    mmToPx: (mm) => mm * 12,
    requestAnimationFrame: (callback) => refreshes.push(callback),
    renderObjects() {}, renderUI() {},
  };
  vm.createContext(context);
  const filename = path.join(__dirname, '..', 'public', 'modules', '04-native-text-preview.js');
  vm.runInContext(fs.readFileSync(filename, 'utf8'), context, { filename });
  return { context, requests, refreshes, warnings };
}
const tick = () => new Promise((resolve) => setImmediate(resolve));
function resolve(request, width = 120, height = 48) {
  request.resolve({ width, height, dataUrl: 'data:image/png;base64,dGVzdA==' });
}

test('native bitmap cache deduplicates identical content and remains independent of position and zoom', async () => {
  const target = field();
  const { context, requests } = load([target]);
  const originalGeometry = { ...target.geom };
  assert.equal(context.requestNativeTextPreview(target, 'AB'), null);
  context.requestNativeTextPreview(target, 'AB');
  assert.equal(requests.length, 1);
  resolve(requests[0]);
  await tick();
  assert.deepEqual(target.geom, originalGeometry, 'merely previewing an imported field must not alter its saved geometry');
  const first = context.makeNativeTextPreviewNode(target, 'AB');
  assert.equal(first.options.width, 120);
  assert.equal(first.options.height, 48);
  assert.equal(first._ciffPreviewTextStyle.native, true);
  target.geom.x = 800;
  target.geom.y = 700;
  context.mmToPx = (mm) => mm * 24;
  const second = context.makeNativeTextPreviewNode(target, 'AB');
  assert.equal(second.options.width, 240);
  assert.equal(second.options.height, 96);
  assert.equal(second.options.image, first.options.image);
  assert.equal(requests.length, 1, 'zooming and moving reuse the same printer-resolution pixels');
});

test('an old font response cannot overwrite geometry after the field changes font', async () => {
  const target = field();
  target._nativeTextGeometryDirty = true;
  const { context, requests } = load([target]);
  context.requestNativeTextPreview(target, 'AB');
  target.text.face = 'Courier New';
  context.requestNativeTextPreview(target, 'AB');
  assert.equal(requests.length, 2);
  resolve(requests[0], 20, 10);
  await tick();
  assert.equal(target.geom.w, 777);
  assert.equal(target.geom.h, 333);
  assert.equal(target._nativeTextGeometryDirty, true);
  resolve(requests[1], 144, 60);
  await tick();
  assert.equal(target.geom.w, 1200);
  assert.equal(target.geom.h, 500);
  assert.equal(target.geom.x, 100);
  assert.equal(target.geom.y, 200);
  assert.equal(target._nativeTextGeometryDirty, undefined);
});

test('a response for a previous tab does not mutate its detached fields or an unrelated current tab', async () => {
  const previous = field('Previous');
  previous._nativeTextGeometryDirty = true;
  const { context, requests } = load([previous]);
  context.requestNativeTextPreview(previous, 'AB');
  const current = field('Current', 'Times New Roman');
  current._nativeTextGeometryDirty = true;
  context.state.fields = [current];
  context.state.xmlDoc = {};
  resolve(requests[0]);
  await tick();
  for (const target of [previous, current]) {
    assert.equal(target.geom.w, 777);
    assert.equal(target._nativeTextGeometryDirty, true);
  }
});

test('save preparation waits for the current font when it changes during a pending native measurement', async () => {
  const target = field();
  target._nativeTextGeometryDirty = true;
  const { context, requests } = load([target]);
  let completed = false;
  const saving = context.ensureNativeTextGeometry([target]).then(() => { completed = true; });
  assert.equal(requests.length, 1);
  target.text.face = 'Courier New';
  resolve(requests[0], 20, 10);
  await tick();
  assert.equal(completed, false);
  assert.equal(target._nativeTextGeometryDirty, true);
  assert.equal(requests.length, 2, 'the changed font must be measured before save continues');
  assert.equal(requests[1].request.face, 'Courier New');
  resolve(requests[1], 144, 60);
  await saving;
  assert.equal(target._nativeTextGeometryDirty, undefined);
  assert.equal(target.geom.w, 1200);
  assert.equal(target.geom.h, 500);
});

test('native measurement failure rejects save preparation and retains pending geometry for retry', async () => {
  const target = field();
  target._nativeTextGeometryDirty = true;
  const { context, requests } = load([target]);
  const saving = context.ensureNativeTextGeometry([target]);
  const rejection = assert.rejects(saving, /font.*measured|measurement|native/i);
  requests[0].reject(new Error('measurement unavailable'));
  await rejection;
  assert.equal(target._nativeTextGeometryDirty, true);
  assert.equal(target.geom.w, 777);
  const retry = context.ensureNativeTextGeometry([target]);
  assert.equal(requests.length, 2);
  resolve(requests[1]);
  await retry;
  assert.equal(target._nativeTextGeometryDirty, undefined);
});

test('a cached measurement synchronizes each edited field without re-requesting or moving it', async () => {
  const first = field('First');
  const second = field('Second');
  second.geom.x = 250;
  const { context, requests } = load([first, second]);
  context.requestNativeTextPreview(first, 'AB');
  resolve(requests[0]);
  await tick();
  second._nativeTextGeometryDirty = true;
  await context.ensureNativeTextGeometry([second]);
  assert.equal(second.geom.w, 1000);
  assert.equal(second.geom.h, 400);
  assert.equal(second.geom.x, 250);
  assert.equal(second.geom.y, 200);
  assert.equal(second._nativeTextGeometryDirty, undefined);
  assert.equal(context.state.subImage.usedSizeDirty, true);
  assert.equal(requests.length, 1);
});

test('explicit face changes update the native font classification without changing imported no-op metadata', async () => {
  const target = field('A', 'Courier New');
  target.text.family = 'Roman';
  target.text.ttSize = 2;
  target._nativeTextFontDirty = true;
  target._nativeTextGeometryDirty = true;
  const { context, requests } = load([target]);
  context.requestNativeTextPreview(target, 'AB');
  requests[0].resolve({ width: 120, height: 48, fontFamily: 48, trueType: true, dataUrl: 'data:image/png;base64,dGVzdA==' });
  await tick();
  assert.equal(target.text.family, 'Modern');
  assert.equal(target.text.ttSize, 1);
  assert.equal(target._nativeTextFontDirty, undefined);
  const untouched = field('Imported', 'Courier New');
  untouched.text.family = 'OpaqueSourceClassification';
  context.requestNativeTextPreview(untouched, 'AB');
  assert.equal(untouched.text.family, 'OpaqueSourceClassification');
});

test('pending native geometry survives document snapshots used by tab switching', () => {
  const { createProductionCiffRuntime } = require('./helpers/ciff-production-harness.cjs');
  const runtime = createProductionCiffRuntime(fs.readFileSync(path.join(__dirname, 'fixtures/conservative/constant-text.ciff')));
  const target = runtime.state.fields[0];
  target._nativeTextGeometryDirty = true;
  target._nativeTextFontDirty = true;
  const snapshot = runtime.context.snapshotState();
  runtime.context.restoreFromSnapshot(snapshot, { render: false });
  assert.equal(runtime.state.fields[0]._nativeTextGeometryDirty, true);
  assert.equal(runtime.state.fields[0]._nativeTextFontDirty, true);
});

test('native text coordinates use printer-dot rounding without modifying saved CIFF positions', () => {
  const { context } = load();
  assert.equal(context.getNativeTextPositionDot(123, 1200), 15);
  assert.equal(context.getNativeTextPositionDot(234, 1200), 28);
  assert.equal(context.getNativeTextPositionDot(-123, 1200), -15);
  assert.equal(context.getNativeTextPositionDot(125, 1200), 15);
  const target = field(); target.geom.x = 123; target.geom.y = 234;
  const original = JSON.stringify(target.geom);
  const entry = { request: { xRes: 1200, yRes: 1200 } };
  for (const orientation of [0, 90, 180, 270]) {
    target.orientation = orientation;
    const w = 164, h = 29, nominalW = 164.04, nominalH = 29.04;
    const offset = context.getNativeTextPreviewOffset(target, entry, w, h, nominalW, nominalH);
    const local = orientation === 90 ? { x: nominalH - offset.y - h, y: offset.x }
      : orientation === 180 ? { x: nominalW - offset.x - w, y: nominalH - offset.y - h }
      : orientation === 270 ? { x: offset.y, y: nominalW - offset.x - w }
      : offset;
    assert.ok(Math.abs(target.geom.x * 0.12 + local.x - 15) < 1e-9);
    assert.ok(Math.abs(target.geom.y * 0.12 + local.y - 28) < 1e-9);
    assert.equal(JSON.stringify(target.geom), original);
  }
});

test('unregistered-printer fallback uses independent XRes and YRes for metrics, pixels and saved geometry', async () => {
  const target = field();
  target._nativeTextGeometryDirty = true;
  const { context, requests } = load([target]);
  context.state.subImage.yRes = 0.08;
  context.requestNativeTextPreview(target, 'AB');
  assert.equal(requests[0].request.xRes, 1200);
  assert.equal(requests[0].request.yRes, 800);
  resolve(requests[0], 120, 48);
  await tick();
  assert.equal(target.geom.w, 1000);
  assert.equal(target.geom.h, 600);
  const node = context.makeNativeTextPreviewNode(target, 'AB');
  assert.equal(node.options.width, 120);
  assert.equal(node.options.height, 72);
  assert.equal(target.geom.x, 100);
  assert.equal(target.geom.y, 200);
});

test('unregistered-printer fallback inherits missing YRes and keys an explicit source YRes separately', () => {
  const target = field();
  const { context, requests } = load([target]);
  context.requestNativeTextPreview(target, 'AB');
  assert.equal(requests[0].request.yRes, 1200);
  context.state.subImage.yRes = 0.08;
  context.requestNativeTextPreview(target, 'AB');
  assert.equal(requests.length, 2);
  assert.equal(requests[1].request.yRes, 800);
});

test('native dot offsets round each coordinate with the corresponding resolution', () => {
  const { context } = load();
  const target = field();
  target.geom.x = 123;
  target.geom.y = 234;
  const entry = { request: { xRes: 1200, yRes: 800 } };
  const offset = context.getNativeTextPreviewOffset(target, entry, 120, 72);
  assert.ok(Math.abs(offset.x - 0.24) < 1e-9);
  assert.ok(Math.abs(offset.y - 0.42) < 1e-9);
});
