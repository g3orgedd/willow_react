const test = require('node:test');
const assert = require('node:assert/strict');
const path = require('node:path');
const { spawn, execFile } = require('node:child_process');
const { EventEmitter } = require('node:events');
const { PassThrough } = require('node:stream');
const { promisify } = require('node:util');
const { createFontRendererService } = require('../electron/fonts.cjs');

function workerFixture() {
  let respond;
  return {
    answer(value) { respond(value); },
    spawn() {
      const child = new EventEmitter();
      child.stdin = new PassThrough(); child.stdout = new PassThrough(); child.stderr = new PassThrough();
      child.kill = () => { child.emit('exit', 0); return true; };
      child.stdin.once('data', (chunk) => {
        const request = JSON.parse(chunk.toString());
        respond = (outlinePath) => child.stdout.write(JSON.stringify({ id: request.id, result: {
          dataUrl: 'data:image/png;base64,AAAA', width: 20, height: 10, outlinePath,
        } }) + '\n');
      });
      process.nextTick(() => child.stdout.write('{"ready":true}\n'));
      return child;
    },
  };
}
const tick = () => new Promise((resolve) => setImmediate(resolve));

test('native IPC preserves real and empty vector paths and accepts the raster fallback', async () => {
  for (const value of ['M0 0L2.25 0Q3 1 2 2C1 3 0 3 0 0Z', '', null, undefined]) {
    const worker = workerFixture();
    const renderer = createFontRendererService({ platform: 'win32', spawn: worker.spawn });
    try {
      const rendering = renderer.render({ text: 'AB' });
      await tick(); worker.answer(value);
      assert.equal((await rendering).outlinePath, value);
    } finally { renderer.dispose(); }
  }
});

test('native IPC rejects invalid or oversized outline responses before exposing them to the canvas', async () => {
  for (const value of [123, 'MNaN 0Z', '<path/>', 'Z'.repeat(8 * 1024 * 1024 + 1)]) {
    const worker = workerFixture();
    const renderer = createFontRendererService({ platform: 'win32', spawn: worker.spawn });
    try {
      const rendering = renderer.render({ text: 'AB' });
      const checked = assert.rejects(rendering, /invalid text outline/);
      await tick(); worker.answer(value); await checked;
    } finally { renderer.dispose(); }
  }
});

test('native curve decoding handles signed FIXED, line/quadratic/cubic contours, baseline and X scaling',
  { skip: process.platform !== 'win32' }, async () => {
    const script = path.join(__dirname, '..', 'research', 'fonts', 'vector-preview', 'verify-curves.ps1');
    const { stdout } = await promisify(execFile)('powershell.exe', [
      '-NoLogo', '-NoProfile', '-NonInteractive', '-ExecutionPolicy', 'Bypass', '-File', script,
    ], { windowsHide: true, timeout: 20000 });
    const result = JSON.parse(stdout.replace(/^\uFEFF/, '').trim());
    assert.ok(Object.values(result).every((value) => value === true));
  });

test('Windows outlines are scalable curves while square-resolution printer bitmaps and CIFF metrics stay identical',
  { skip: process.platform !== 'win32' }, async () => {
    const baselinePath = path.join(__dirname, '..', 'research', 'fonts', 'vector-preview', 'font-renderer-before.ps1');
    const baseline = createFontRendererService({ spawn(file, args, options) {
      const original = args.slice(); original[original.length - 1] = baselinePath;
      return spawn(file, original, options);
    } });
    const current = createFontRendererService();
    const requests = ['Arial', 'Courier New', 'Times New Roman', 'OCRB', 'Tahoma'].flatMap((face) => [
      { face, text: 'ABOQy0123 Привет', pitch: 13 },
      { face, text: 'ABOQy0123 Привет', pitch: 13, bold: true, xMag: 150 },
    ]);
    requests.push({ text: '', pitch: 13 }, { text: '   ', pitch: 13 },
      { text: 'A\u0301 Привет ABC', charSpace: 1 }, { text: 'A😀B', xRes: 1200, yRes: 1200 },
      { text: 'A&B', pitch: 13 }, { text: 'A&&B', pitch: 13 }, { text: 'A\tB', pitch: 13 },
      { text: 'Привет, мир! 123', pitch: 13 });
    try {
      for (const request of requests) {
        const [before, result] = await Promise.all([baseline.render(request), current.render(request)]);
        const { outlinePath, ...unchanged } = result;
        assert.deepEqual(unchanged, before, JSON.stringify(request));
        assert.equal(typeof outlinePath, 'string');
        if (!request.text.trim()) assert.equal(outlinePath, '');
        else {
          assert.match(outlinePath, /^M[\s\S]*Z$/);
          assert.match(outlinePath, /[QC]/, 'the result contains font curves, rather than a pixel contour');
          if (!/[&\t,]/.test(request.text)) assert.match(outlinePath, /\d\.\d/, 'unhinted outline coordinates retain subpixel font geometry');
        }
      }
    } finally { baseline.dispose(); current.dispose(); }
  });

test('native vector glyph positions retain the GDI intercharacter gap beyond the ScriptPlace advance widths',
  { skip: process.platform !== 'win32' }, async () => {
    const renderer = createFontRendererService();
    function bounds(source) {
      const points = source.match(/-?\d+(?:\.\d+)?/g).map(Number);
      const xs = points.filter((_, index) => index % 2 === 0);
      return { left: Math.min(...xs), right: Math.max(...xs) };
    }
    try {
      const base = await renderer.render({ text: 'IIII', face: 'Arial', pitch: 13 });
      const normal = bounds(base.outlinePath);
      for (const charSpace of [1, 50]) {
        const result = await renderer.render({ text: 'IIII', face: 'Arial', pitch: 13, charSpace });
        const spaced = bounds(result.outlinePath);
        assert.equal(spaced.left, normal.left);
        assert.ok(Math.abs(spaced.right - normal.right - 3 * charSpace) < 0.001,
          'each of the three intercharacter gaps includes the DC character extra');
        assert.equal(result.width - base.width, 6 * charSpace,
          'the original ClariSoft field width calculation remains independent of the visible glyph gaps');
      }
    } finally { renderer.dispose(); }
  });
