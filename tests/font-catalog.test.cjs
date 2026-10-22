const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

function load(options = {}) {
  const calls = [];
  const context = {
    location: { hostname: options.hostname ?? 'localhost' },
    console: { warn() {} },
    fetch: async (url, init) => { calls.push({ url, init }); return options.fetch(url, init); },
    ...(options.glyphFonts ? { glyphFonts: options.glyphFonts } : {}),
  };
  vm.createContext(context);
  const filename = path.join(__dirname, '..', 'public', 'modules', '03-font-catalog.js');
  vm.runInContext(fs.readFileSync(filename, 'utf8'), context, { filename });
  return { context, calls };
}
function response(value, contentType = 'application/json', ok = true) {
  return { ok, headers: { get: () => contentType }, json: async () => value };
}

test('localhost browser startup connects the Vite native bridge and uses it for bitmap rendering', async () => {
  const { context, calls } = load({ fetch: (url) => response(url.endsWith('/list')
    ? { families: ['Courier New', 'Arial', 'arial'] } : { width: 120, height: 48, dataUrl: 'data:image/png;base64,AA==' }) });
  const first = context.initTextFontCatalog();
  assert.equal(first, context.initTextFontCatalog());
  await first;
  assert.deepEqual(Array.from(context.getAvailableTextFontFamilies()), ['Arial', 'Courier New']);
  assert.equal(calls.length, 1);
  const catalog = await context.glyphFonts.list();
  catalog.families.length = 0;
  assert.equal((await context.glyphFonts.list()).families.length, 3, 'the adapter returns an isolated catalog copy');
  const result = await context.glyphFonts.render({ text: 'AB', face: 'Arial', pitch: 10 });
  assert.equal(result.width, 120);
  assert.equal(calls[1].url, '/__glyph_fonts/render');
  assert.equal(calls[1].init.method, 'POST');
  assert.equal(calls[1].init.credentials, 'same-origin');
  assert.equal(JSON.parse(calls[1].init.body).face, 'Arial');
});

test('a remote website never probes the local native service', async () => {
  const { context, calls } = load({ hostname: 'glyph.example', fetch: () => assert.fail('unexpected font network call') });
  await context.initTextFontCatalog();
  assert.equal(calls.length, 0);
  assert.equal(context.glyphFonts, undefined);
  assert.deepEqual(Array.from(context.getAvailableTextFontFamilies()), ['Arial']);
});

test('missing middleware, HTML fallback and empty native catalogs retain the browser font path', async () => {
  for (const result of [response(null, 'text/html'), response({}, 'application/json', false), response({ families: [] })]) {
    const { context } = load({ hostname: '127.0.0.1', fetch: () => result });
    await context.initTextFontCatalog();
    assert.equal(context.glyphFonts, undefined);
    assert.deepEqual(Array.from(context.getAvailableTextFontFamilies()), ['Arial']);
  }
});

test('Electron keeps its existing font bridge without calling the dev endpoint', async () => {
  const native = { list: async () => ({ families: ['OCRB', 'Arial'] }), render() {} };
  const { context, calls } = load({ glyphFonts: native, fetch: () => assert.fail('unexpected browser bridge') });
  await context.initTextFontCatalog();
  assert.equal(context.glyphFonts, native);
  assert.equal(calls.length, 0);
  assert.deepEqual(Array.from(context.getAvailableTextFontFamilies()), ['Arial', 'OCRB']);
});

test('local bridge HTTP render failures reject so save cannot treat failed measurements as successful', async () => {
  const { context } = load({ fetch: (url) => url.endsWith('/list')
    ? response({ families: ['Arial'] }) : response({ error: 'unavailable' }, 'application/json', false) });
  await context.initTextFontCatalog();
  await assert.rejects(context.glyphFonts.render({ text: 'AB' }), /unavailable/);
});
