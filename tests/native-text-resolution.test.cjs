const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');
const { createFontRendererService } = require('../electron/fonts.cjs');

const root = path.join(__dirname, '..');
const tick = () => new Promise((resolve) => setImmediate(resolve));
const plain = (value) => JSON.parse(JSON.stringify(value));

function load() {
  const requests = [];
  class Node { constructor(options) { this.options = options; } }
  const context = { console,
    document: { getElementById: () => null, querySelectorAll: () => [] },
    glyphFonts: { render: (request) => new Promise((resolve) => requests.push({ request, resolve })) },
    getEffectiveTextFontFamily: (field) => field.text.face,
    getEffectiveTextPitch: (field) => field.text.pitch,
    makePreviewText: (field) => field.data.defaultValue,
    Konva: { Path: Node, Image: Node },
    mmToPx: (mm) => mm * 12,
    requestAnimationFrame() {},
    Image: class { async decode() {} },
  };
  vm.createContext(context);
  for (const name of ['00-core.js', '04-native-text-preview.js']) {
    const filename = path.join(root, 'public/modules', name);
    vm.runInContext(fs.readFileSync(filename, 'utf8'), context, { filename });
  }
  context.state = vm.runInContext('state', context);
  context.state.xmlDoc = {};
  const field = { name: 'TEXT', fldType: 'FixedText', orientation: 0,
    text: { face: 'Arial', pitch: 10 }, data: { defaultValue: 'TEXT' },
    geom: { x: 173, y: 211, w: 892, h: 392 } };
  context.state.fields = [field];
  context.state.docMeta.printerModel = 'DataFlex 6330(53mm)';
  return { context, field, requests };
}

test('known target capabilities drive rendering while imported XRes/YRes and no-op geometry stay unchanged', async () => {
  const { context, field, requests } = load();
  context.state.subImage.xRes = 0.09;
  context.state.subImage.yRes = 0.135;
  const before = plain({ subImage: context.state.subImage, geom: field.geom });
  context.requestNativeTextPreview(field, 'TEXT');
  assert.equal(requests[0].request.xRes, 1200);
  assert.equal(requests[0].request.yRes, 1200);
  requests[0].resolve({ width: 107, height: 47, outlinePath: '', dataUrl: '' });
  await tick();
  assert.deepEqual(plain({ subImage: context.state.subImage, geom: field.geom }), before);
  const originalKey = context.getNativeTextCacheKey(field, 'TEXT');
  context.state.subImage.xRes = 0.24;
  context.state.subImage.yRes = 0.06;
  assert.equal(context.getNativeTextCacheKey(field, 'TEXT'), originalKey);
  context.state.docMeta.printMode = 'Intermittent';
  assert.equal(context.getNativeTextCacheKey(field, 'TEXT'), originalKey,
    'both native DataFlex modes have the same rendering resolution');
  context.state.docMeta.printerModel = 'DataFlex 6230(32mm)';
  const request = context.getNativeTextRequest(field, 'TEXT');
  assert.equal(request.xRes, 800);
  assert.equal(request.yRes, 800);
  assert.notEqual(context.getNativeTextCacheKey(field, 'TEXT'), originalKey);
});

test('6230 uses the native Independence resolution for newly measured fields', async () => {
  const { context, field, requests } = load();
  context.state.docMeta.printerModel = 'DataFlex 6230(32mm)';
  field._nativeTextGeometryDirty = true;
  context.requestNativeTextPreview(field, 'TEXT');
  requests[0].resolve({ width: 70, height: 31, outlinePath: '', dataUrl: '' });
  await tick();
  assert.equal(field.geom.w, 875);
  assert.equal(field.geom.h, 388);
  assert.equal(context.getKnownPrinterCapabilities('DataFlex 6230(32mm)').xResText, '0.080000');
});

test('unregistered printers retain an explicit independent source-resolution fallback', () => {
  const { context, field } = load();
  context.state.docMeta.printerModel = 'Unregistered custom printer';
  context.state.subImage.xRes = 0.09;
  context.state.subImage.yRes = 0.135;
  assert.deepEqual(plain(context.getNativeTextRenderResolution()),
    { xRes: 0.09, yRes: 0.135, source: 'file-resolution-fallback' });
  assert.equal(context.getNativeTextRequest(field, 'TEXT').yRes, 1350);
  context.state.subImage.yRes = null;
  assert.equal(context.getNativeTextRequest(field, 'TEXT').yRes, 900);
});

test('quarter-turn paths convert the rotated dot axes and quantized origin independently', async () => {
  const { context, field, requests } = load();
  context.state.docMeta.printerModel = 'Controlled unequal caps';
  const dotWidth = 217, dotHeight = 96;
  for (const [capsX, capsY] of [[0.12, 0.24], [0.24, 0.12], [0.125, 0.08]]) {
    context.getKnownPrinterCapabilities = () => ({ xRes: capsX, yRes: capsY });
    context.requestNativeTextPreview(field, 'TEXT');
    requests.at(-1).resolve({ width: dotWidth, height: dotHeight, outlinePath: 'M0 0L1 0Z', dataUrl: '' });
    await tick();
    for (const [x, y] of [[173, 211], [-173, -211], [4, -4]]) {
      field.geom.x = x; field.geom.y = y;
      for (const orientation of [0, 90, 180, 270]) {
        field.orientation = orientation;
        const options = context.makeNativeTextPreviewNode(field, 'TEXT').options;
        const nominalW = field.geom.w * 0.12, nominalH = field.geom.h * 0.12;
        const originX = context.getNativeTextPositionDot(x, capsX * 10000);
        const originY = context.getNativeTextPositionDot(y, capsY * 10000);
        for (const [u, v] of [[0, 0], [dotWidth, 0], [0, dotHeight], [dotWidth, dotHeight], [13.25, 27.5]]) {
          const localX = options.x + u * options.scaleX;
          const localY = options.y + v * options.scaleY;
          const px = orientation === 90 ? nominalH - localY : orientation === 180 ? nominalW - localX : orientation === 270 ? localY : localX;
          const py = orientation === 90 ? localX : orientation === 180 ? nominalH - localY : orientation === 270 ? nominalW - localX : localY;
          const expectedX = originX + (orientation === 90 ? dotHeight - v : orientation === 180 ? dotWidth - u : orientation === 270 ? v : u);
          const expectedY = originY + (orientation === 90 ? u : orientation === 180 ? dotHeight - v : orientation === 270 ? dotWidth - u : v);
          assert.ok(Math.abs((x * 0.12 + px) * capsX / 0.12 - expectedX) < 1e-9);
          assert.ok(Math.abs((y * 0.12 + py) * capsY / 0.12 - expectedY) < 1e-9);
        }
      }
    }
  }
  assert.equal(context.getNativeTextPositionDot(4, 1250), 1);
  assert.equal(context.getNativeTextPositionDot(-4, 1250), -1);
});

test('Windows font worker matches original COM unequal-capability metrics without horizontal aspect correction',
  { skip: process.platform !== 'win32' }, async () => {
    // Independently captured original CalculateSize/Draw: 24 cases, source
    // research/resolution-preview-20261022/native-field-resolutions/results.json.
    const expected = [
      ['Arial', 10, 0.12, 0.12, 107, 47, 892, 392],
      ['Arial', 10, 0.12, 0.24, 217, 96, 1808, 400],
      ['Arial', 10, 0.24, 0.12, 107, 47, 446, 392],
      ['Arial', 10, 0.08, 0.12, 107, 47, 1338, 392],
      ['Times New Roman', 13, 0.12, 0.12, 140, 62, 1167, 517],
      ['Times New Roman', 13, 0.12, 0.24, 280, 125, 2333, 521],
      ['Times New Roman', 13, 0.24, 0.12, 140, 62, 583, 517],
      ['Times New Roman', 13, 0.08, 0.12, 140, 62, 1750, 517],
      ['Courier New', 8, 0.12, 0.12, 80, 37, 667, 308],
      ['Courier New', 8, 0.12, 0.24, 164, 73, 1367, 304],
      ['Courier New', 8, 0.24, 0.12, 80, 37, 333, 308],
      ['Courier New', 8, 0.08, 0.12, 80, 37, 1000, 308],
    ];
    const renderer = createFontRendererService();
    try {
      for (const [face, pitch, x, y, width, height, modelW, modelH] of expected) {
        const result = await renderer.render({ text: 'TEXT', face, pitch, xRes: x * 10000, yRes: y * 10000 });
        assert.deepEqual([result.width, result.height], [width, height], `${face} ${x}/${y}`);
        assert.deepEqual([Math.round(result.width / x), Math.round(result.height / y)], [modelW, modelH]);
      }
    } finally { renderer.dispose(); }
  });
