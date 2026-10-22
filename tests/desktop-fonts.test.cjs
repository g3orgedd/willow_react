const test = require('node:test');
const assert = require('node:assert/strict');
const { createFontCatalogService, normalizeFontFamilies, normalizeRenderRequest, createFontRendererService } = require('../electron/fonts.cjs');
const { EventEmitter } = require('node:events');
const { PassThrough } = require('node:stream');
const fs = require('node:fs');
const os = require('node:os');
const path = require('node:path');

test('font catalog preserves GDI raster and Unicode names while removing aliases and duplicates', () => {
  assert.deepEqual(normalizeFontFamilies([
    'Arial', 'arial', ' Arial ', '@Arial', 'Terminal', 'System', 'Шрифт', '', null, 'bad\0font',
  ]), ['Arial', 'System', 'Terminal', 'Шрифт']);
});

test('Windows enumeration is hidden, cached across concurrent calls, and isolated from caller mutations', async () => {
  let calls = 0;
  let complete;
  const service = createFontCatalogService({
    platform: 'win32',
    windowsDirectory: 'C:\\Windows',
    execFile(file, args, options, callback) {
      calls += 1;
      assert.equal(file, 'C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe');
      assert.equal(options.windowsHide, true);
      assert.equal(options.timeout, 20000);
      assert.ok(args.includes('-NonInteractive'));
      const script = Buffer.from(args.at(-1), 'base64').toString('utf16le');
      assert.match(script, /EnumFontFamiliesEx/);
      complete = callback;
    },
  });
  const first = service.list();
  const second = service.list();
  assert.equal(calls, 1);
  complete(null, '["Arial","Terminal","@Arial"]');
  const [a, b] = await Promise.all([first, second]);
  assert.deepEqual(a, { families: ['Arial', 'Terminal'] });
  a.families.length = 0;
  assert.deepEqual(b, { families: ['Arial', 'Terminal'] });
  assert.deepEqual(await service.list(), b);
  assert.equal(calls, 1);
});

test('font enumeration errors are visible and permit a later retry', async () => {
  let calls = 0;
  const service = createFontCatalogService({
    platform: 'win32',
    execFile(_file, _args, _options, callback) {
      calls += 1;
      callback(calls === 1 ? new Error('GDI failure') : null, '["Arial"]');
    },
  });
  await assert.rejects(service.list(), /GDI failure/);
  assert.deepEqual(await service.list(), { families: ['Arial'] });
  assert.equal(calls, 2);
});

test('unsupported platforms report no catalog without launching a helper', async () => {
  const service = createFontCatalogService({ platform: 'linux', execFile() { assert.fail('unexpected helper'); } });
  assert.deepEqual(await service.list(), { families: [] });
});

test('malformed or empty native catalogs are rejected instead of claiming installed fallback fonts', async () => {
  for (const stdout of ['not JSON', '{}', '[]']) {
    const service = createFontCatalogService({
      platform: 'win32', execFile(_file, _args, _options, callback) { callback(null, stdout); },
    });
    await assert.rejects(service.list());
  }
});

test('native rendering validates sizes and sends text as data without interpolating PowerShell source', () => {
  const request = normalizeRenderRequest({ text: '$(Remove-Item *) `" Привет', face: 'Arial', pitch: 13 });
  assert.equal(request.text, '$(Remove-Item *) `" Привет');
  assert.equal(request.xRes, 1200);
  assert.equal(request.yRes, 1200);
  assert.equal(request.pitchResolution, 1);
  for (const invalid of [
    { text: 'x'.repeat(4097) }, { text: 'nul\0' }, { face: '' }, { pitch: 0 },
    { xMag: Infinity }, { xRes: 0.12 }, { charSpace: 'bad' }, { pitchResolution: 0 },
  ]) assert.throws(() => normalizeRenderRequest(invalid));
});

function fakeRenderer({ autoReady = true } = {}) {
  const workers = [];
  const requests = [];
  const spawn = (_file, args, options) => {
    assert.equal(options.windowsHide, true);
    assert.ok(args.includes('-File'));
    const child = new EventEmitter();
    child.scriptContents = fs.readFileSync(args.at(-1), 'utf8');
    child.stdin = new PassThrough();
    child.stdout = new PassThrough();
    child.stderr = new PassThrough();
    child.kill = () => { child.killed = true; child.emit('exit', 0); return true; };
    let input = '';
    child.stdin.on('data', (chunk) => {
      input += chunk.toString();
      let newline;
      while ((newline = input.indexOf('\n')) >= 0) {
        const request = JSON.parse(input.slice(0, newline)); input = input.slice(newline + 1);
        requests.push({ child, request });
      }
    });
    workers.push(child);
    if (autoReady) process.nextTick(() => child.stdout.write('{"ready":true}\n'));
    return child;
  };
  return { spawn, workers, requests };
}

const nextTick = () => new Promise((resolve) => setImmediate(resolve));
function answer(entry, width = 12) {
  entry.child.stdout.write(JSON.stringify({ id: entry.request.id, result: {
    dataUrl: 'data:image/png;base64,AAAA', width, height: 7,
    advanceWidth: width, fontHeight: 7, baseline: 6, offsetX: 0, offsetY: 0,
  } }) + '\n');
}

test('native bitmap worker persists, serializes jobs, deduplicates requests, and caches results', async () => {
  const fake = fakeRenderer();
  const renderer = createFontRendererService({ platform: 'win32', spawn: fake.spawn });
  try {
    const first = renderer.render({ text: 'Привет', face: 'Arial' });
    const duplicate = renderer.render({ text: 'Привет', face: 'Arial' });
    const second = renderer.render({ text: 'Second', face: 'Tahoma' });
    await nextTick();
    assert.equal(fake.workers.length, 1);
    assert.equal(fake.requests.length, 1);
    assert.equal(fake.requests[0].request.payload.text, 'Привет');
    answer(fake.requests[0]);
    const [a, b] = await Promise.all([first, duplicate]);
    assert.deepEqual(a, b);
    a.width = 999;
    await nextTick();
    assert.equal(fake.requests.length, 2);
    answer(fake.requests[1], 20);
    assert.equal((await second).width, 20);
    assert.equal((await renderer.render({ text: 'Привет', face: 'Arial' })).width, 12);
    assert.equal(fake.requests.length, 2);
  } finally { renderer.dispose(); }
});

test('a timed out bitmap worker rejects the request and restarts on a later render', async () => {
  const fake = fakeRenderer();
  const renderer = createFontRendererService({ platform: 'win32', spawn: fake.spawn, timeoutMs: 25 });
  try {
    await assert.rejects(renderer.render({ text: 'Timeout', face: 'Arial' }), /timed out/);
    const retry = renderer.render({ text: 'Retry', face: 'Arial' });
    await nextTick();
    assert.equal(fake.workers.length, 2);
    answer(fake.requests.at(-1));
    assert.equal((await retry).height, 7);
  } finally { renderer.dispose(); }
  await assert.rejects(renderer.render({ text: 'Disposed' }), /disposed/);
});

test('disposing during startup rejects current and queued work without restarting the worker', async () => {
  const fake = fakeRenderer({ autoReady: false });
  const renderer = createFontRendererService({ platform: 'win32', spawn: fake.spawn });
  const first = renderer.render({ text: 'Startup' });
  const queued = renderer.render({ text: 'Queued' });
  const checked = Promise.all([assert.rejects(first, /stopped/), assert.rejects(queued, /disposed/)]);
  await nextTick();
  renderer.dispose();
  await checked;
  assert.equal(fake.workers.length, 1);
});

test('native bitmap metadata is bounded before it is returned over IPC', async () => {
  const fake = fakeRenderer();
  const renderer = createFontRendererService({ platform: 'win32', spawn: fake.spawn });
  try {
    const render = renderer.render({ text: 'Bad metadata' });
    const checked = assert.rejects(render, /invalid bitmap/);
    await nextTick();
    answer(fake.requests[0], -1);
    await checked;
  } finally { renderer.dispose(); }
});

test('development source updates replace the copied worker and cached results even for an identical request', async () => {
  const directory = fs.mkdtempSync(path.join(os.tmpdir(), 'glyph-font-source-test-'));
  const scriptPath = path.join(directory, 'renderer.ps1');
  fs.writeFileSync(scriptPath, 'version-one');
  const fake = fakeRenderer();
  const renderer = createFontRendererService({ platform: 'win32', spawn: fake.spawn, watchSource: true, scriptPath });
  try {
    const first = renderer.render({ text: 'Same request' });
    await nextTick(); answer(fake.requests[0], 12); await first;
    assert.equal((await renderer.render({ text: 'Same request' })).width, 12);
    assert.equal(fake.requests.length, 1);
    fs.writeFileSync(scriptPath, 'version-two');
    const updated = renderer.render({ text: 'Same request' });
    await nextTick();
    assert.equal(fake.workers.length, 2);
    assert.equal(fake.workers[0].killed, true);
    assert.equal(fake.workers[1].scriptContents, 'version-two');
    answer(fake.requests[1], 20);
    assert.equal((await updated).width, 20);
    assert.equal((await renderer.render({ text: 'Same request' })).width, 20);
    assert.equal(fake.requests.length, 2);
  } finally {
    renderer.dispose(); fs.unlinkSync(scriptPath); fs.rmdirSync(directory);
  }
});

test('source updates do not deduplicate new requests onto an older in-flight worker version', async () => {
  const directory = fs.mkdtempSync(path.join(os.tmpdir(), 'glyph-font-source-test-'));
  const scriptPath = path.join(directory, 'renderer.ps1');
  fs.writeFileSync(scriptPath, 'version-one');
  const fake = fakeRenderer();
  const renderer = createFontRendererService({ platform: 'win32', spawn: fake.spawn, watchSource: true, scriptPath });
  try {
    const previous = renderer.render({ text: 'Same request' });
    await nextTick();
    fs.writeFileSync(scriptPath, 'version-two');
    const updated = renderer.render({ text: 'Same request' });
    assert.equal(fake.workers[0].killed, undefined, 'the old active request finishes normally');
    answer(fake.requests[0], 12);
    assert.equal((await previous).width, 12);
    await nextTick();
    assert.equal(fake.requests.length, 2);
    assert.equal(fake.workers[1].scriptContents, 'version-two');
    answer(fake.requests[1], 20);
    assert.equal((await updated).width, 20);
    assert.equal((await renderer.render({ text: 'Same request' })).width, 20);
  } finally {
    renderer.dispose(); fs.unlinkSync(scriptPath); fs.rmdirSync(directory);
  }
});
