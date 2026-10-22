const test = require('node:test');
const assert = require('node:assert/strict');
const { PassThrough } = require('node:stream');
const { EventEmitter } = require('node:events');
const { createViteFontBridge, createViteFontPlugin, isLoopbackAddress } = require('../scripts/vite-fonts.cjs');

function services() {
  const calls = [];
  return {
    calls,
    catalog: { async list() { calls.push('list'); return { families: ['Arial', 'Courier New'] }; } },
    renderer: {
      async render(payload) { calls.push(payload); return { width: 120, height: 48, dataUrl: 'data:image/png;base64,dGVzdA==' }; },
      dispose() { calls.push('dispose'); },
    },
  };
}
async function request(bridge, options = {}) {
  const input = new PassThrough();
  input.method = options.method ?? 'GET';
  input.url = options.url ?? '/__glyph_fonts/list';
  input.socket = { remoteAddress: options.remoteAddress ?? '127.0.0.1' };
  input.headers = {
    host: 'localhost:5173',
    ...(input.method === 'POST' ? { origin: 'http://localhost:5173', 'content-type': 'application/json' } : {}),
    ...options.headers,
  };
  const output = { headers: {}, statusCode: 200, body: '', next: false,
    setHeader(name, value) { this.headers[name.toLowerCase()] = value; },
    end(body) { this.body = body ?? ''; },
  };
  const pending = bridge.middleware(input, output, () => { output.next = true; });
  input.end(options.body ?? '');
  await pending;
  output.json = output.body ? JSON.parse(output.body) : null;
  return output;
}

test('local Vite font endpoints use the native services and validate a render request before dispatch', async () => {
  const dependencies = services();
  const bridge = createViteFontBridge(dependencies);
  const list = await request(bridge);
  assert.equal(list.statusCode, 200);
  assert.deepEqual(list.json.families, ['Arial', 'Courier New']);
  assert.equal(list.headers['cache-control'], 'no-store');
  const bitmap = await request(bridge, {
    method: 'POST', url: '/__glyph_fonts/render', body: JSON.stringify({ text: 'Пример', face: 'Courier New', pitch: 13 }),
  });
  assert.equal(bitmap.statusCode, 200);
  assert.equal(bitmap.json.width, 120);
  assert.equal(dependencies.calls[1].face, 'Courier New');
  assert.equal(dependencies.calls[1].text, 'Пример');
  assert.equal(dependencies.calls[1].xRes, 1200);
  assert.equal(dependencies.calls[1].xMag, 100);
});

test('font middleware rejects remote peers, nonlocal Host names and cross-origin POST requests', async () => {
  const dependencies = services();
  const bridge = createViteFontBridge(dependencies);
  for (const options of [
    { remoteAddress: '192.168.1.23' },
    { headers: { host: 'external.example:5173' } },
    { method: 'POST', url: '/__glyph_fonts/render', headers: { origin: 'https://external.example' }, body: '{}' },
    { method: 'POST', url: '/__glyph_fonts/render', headers: { origin: undefined }, body: '{}' },
  ]) {
    assert.equal((await request(bridge, options)).statusCode, 403);
  }
  assert.equal(dependencies.calls.length, 0);
  assert.equal((await request(bridge, { remoteAddress: '::ffff:127.0.0.1' })).statusCode, 200);
  assert.equal((await request(bridge, { remoteAddress: '::1', headers: { host: '[::1]:5173' } })).statusCode, 200);
  assert.equal(isLoopbackAddress('127.999.0.1'), false);
  assert.equal(isLoopbackAddress('127.1.2.3'), true);
});

test('font middleware rejects invalid methods, content types, malformed JSON and invalid native parameters', async () => {
  const dependencies = services();
  const bridge = createViteFontBridge(dependencies);
  const wrongMethod = await request(bridge, { method: 'PUT' });
  assert.equal(wrongMethod.statusCode, 405);
  assert.equal(wrongMethod.headers.allow, 'GET');
  const render = { method: 'POST', url: '/__glyph_fonts/render' };
  assert.equal((await request(bridge, { ...render, headers: { 'content-type': 'text/plain' }, body: '{}' })).statusCode, 415);
  assert.equal((await request(bridge, { ...render, body: 'not JSON' })).statusCode, 400);
  assert.equal((await request(bridge, { ...render, body: '[]' })).statusCode, 400);
  assert.equal((await request(bridge, { ...render, body: '{"pitch":0}' })).statusCode, 400);
  assert.equal(dependencies.calls.length, 0);
});

test('both declared and streamed request bodies obey the 128 KiB limit', async () => {
  const dependencies = services();
  const bridge = createViteFontBridge(dependencies);
  const render = { method: 'POST', url: '/__glyph_fonts/render' };
  assert.equal((await request(bridge, { ...render, headers: { 'content-length': 131073 }, body: '{}' })).statusCode, 413);
  assert.equal((await request(bridge, { ...render, body: 'x'.repeat(131073) })).statusCode, 413);
  assert.equal(dependencies.calls.length, 0);
});

test('native service failures produce controlled responses and unrelated Vite requests pass through', async () => {
  const dependencies = services();
  dependencies.catalog.list = async () => { throw new Error('private Windows path'); };
  dependencies.renderer.render = async () => { throw new Error('private worker diagnostics'); };
  const bridge = createViteFontBridge(dependencies);
  const list = await request(bridge);
  assert.equal(list.statusCode, 503);
  assert.ok(!list.body.includes('private'));
  const bitmap = await request(bridge, { method: 'POST', url: '/__glyph_fonts/render', body: '{}' });
  assert.equal(bitmap.statusCode, 503);
  assert.ok(!bitmap.body.includes('private'));
  assert.equal((await request(bridge, { url: '/src/main.tsx' })).next, true);
  assert.equal((await request(bridge, { url: '/__glyph_fonts/unknown' })).statusCode, 404);
});

test('Vite server close and plugin teardown dispose the native renderer exactly once', () => {
  const dependencies = services();
  const plugin = createViteFontPlugin(dependencies);
  const server = { httpServer: new EventEmitter(), middlewares: { use() {} } };
  plugin.configureServer(server);
  server.httpServer.emit('close');
  plugin.closeBundle();
  assert.deepEqual(dependencies.calls, ['dispose']);
});

test('Vite watches its native CJS and PowerShell dependencies and removes restart listeners on close', () => {
  const dependencies = services();
  const plugin = createViteFontPlugin(dependencies);
  const watcher = new EventEmitter();
  let watched;
  watcher.add = (sources) => { watched = sources; };
  let restarts = 0;
  const server = {
    httpServer: new EventEmitter(), middlewares: { use() {} }, watcher,
    restart() { restarts += 1; return Promise.resolve(); },
    config: { logger: { error() { assert.fail('unexpected restart error'); } } },
  };
  plugin.configureServer(server);
  assert.equal(watched.length, 3);
  assert.ok(watched.some((filename) => filename.endsWith('font-renderer.ps1')));
  assert.ok(watched.some((filename) => filename.endsWith('fonts.cjs')));
  watcher.emit('change', 'some-unrelated-file.js');
  assert.equal(restarts, 0);
  watched.forEach((filename) => watcher.emit('change', filename));
  assert.equal(restarts, 3);
  server.httpServer.emit('close');
  watcher.emit('change', watched[0]);
  assert.equal(restarts, 3);
  plugin.closeBundle();
  assert.deepEqual(dependencies.calls, ['dispose']);
});
