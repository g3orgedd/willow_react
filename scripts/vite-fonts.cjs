const { createFontCatalogService, createFontRendererService, normalizeRenderRequest } = require('../electron/fonts.cjs');
const path = require('node:path');

const MAX_BODY_BYTES = 128 * 1024;
const LOCAL_HOSTS = new Set(['localhost', '127.0.0.1', '[::1]', '::1']);

function isLoopbackAddress(address) {
  const value = String(address || '').toLowerCase().replace(/^::ffff:/, '');
  if (value === '::1') return true;
  const octets = value.split('.');
  return octets.length === 4 && octets[0] === '127' && octets.every((part) => /^\d{1,3}$/.test(part) && Number(part) <= 255);
}

function localRequestOrigin(request) {
  try {
    const scheme = request.socket?.encrypted ? 'https' : 'http';
    const host = request.headers.host;
    if (typeof host !== 'string' || /[\s/@\\]/.test(host)) return null;
    const url = new URL(`${scheme}://${host}`);
    return LOCAL_HOSTS.has(url.hostname.toLowerCase()) ? url.origin : null;
  } catch { return null; }
}

function sendJson(response, status, value) {
  response.statusCode = status;
  response.setHeader('Content-Type', 'application/json; charset=utf-8');
  response.setHeader('Cache-Control', 'no-store');
  response.setHeader('X-Content-Type-Options', 'nosniff');
  response.end(JSON.stringify(value));
}

function readJsonBody(request) {
  return new Promise((resolve, reject) => {
    let size = 0;
    const chunks = [];
    let failed = false;
    const fail = (status, message) => {
      if (failed) return;
      failed = true;
      reject(Object.assign(new Error(message), { status }));
    };
    request.on('data', (chunk) => {
      if (failed) return;
      const buffer = Buffer.isBuffer(chunk) ? chunk : Buffer.from(chunk);
      size += buffer.length;
      if (size > MAX_BODY_BYTES) return fail(413, 'The font request is too large.');
      chunks.push(buffer);
    });
    request.on('end', () => {
      if (failed) return;
      try { resolve(JSON.parse(Buffer.concat(chunks).toString('utf8'))); }
      catch { fail(400, 'The font request must contain valid JSON.'); }
    });
    request.on('error', () => fail(400, 'The font request could not be read.'));
    request.on('aborted', () => fail(400, 'The font request was interrupted.'));
  });
}

function createViteFontBridge(options = {}) {
  const catalog = options.catalog ?? createFontCatalogService();
  const renderer = options.renderer ?? createFontRendererService({ watchSource: true });
  let disposed = false;

  async function middleware(request, response, next) {
    const pathname = String(request.url || '').split('?')[0];
    if (!pathname.startsWith('/__glyph_fonts/')) return next();
    const origin = localRequestOrigin(request);
    if (!isLoopbackAddress(request.socket?.remoteAddress) || !origin) {
      sendJson(response, 403, { error: 'Native font services are available on this computer only.' });
      return;
    }
    if (disposed) {
      sendJson(response, 503, { error: 'Native font services are unavailable.' });
      return;
    }
    if (pathname !== '/__glyph_fonts/list' && pathname !== '/__glyph_fonts/render') {
      sendJson(response, 404, { error: 'Unknown native font endpoint.' });
      return;
    }
    const expectedMethod = pathname.endsWith('/list') ? 'GET' : 'POST';
    if (request.method !== expectedMethod) {
      response.setHeader('Allow', expectedMethod);
      sendJson(response, 405, { error: 'Unsupported native font request method.' });
      return;
    }
    if ((request.headers.origin && request.headers.origin !== origin) ||
        (expectedMethod === 'POST' && request.headers.origin !== origin)) {
      sendJson(response, 403, { error: 'The native font request must use the same origin.' });
      return;
    }
    if (expectedMethod === 'GET') {
      try {
        const result = await catalog.list();
        if (!Array.isArray(result?.families)) throw new Error('Invalid native font catalog.');
        sendJson(response, 200, result);
      } catch {
        sendJson(response, 503, { error: 'The Windows font catalog is unavailable.' });
      }
      return;
    }
    if (!/^application\/json(?:\s*;|\s*$)/i.test(String(request.headers['content-type'] || ''))) {
      sendJson(response, 415, { error: 'Native font rendering requires application/json.' });
      request.resume();
      return;
    }
    if (Number(request.headers['content-length']) > MAX_BODY_BYTES) {
      sendJson(response, 413, { error: 'The font request is too large.' });
      request.resume();
      return;
    }
    let payload;
    try { payload = normalizeRenderRequest(await readJsonBody(request)); }
    catch (error) {
      sendJson(response, error.status || 400, { error: error.message });
      return;
    }
    try {
      const result = await renderer.render(payload);
      sendJson(response, 200, result);
    } catch {
      sendJson(response, 503, { error: 'Windows native font rendering is unavailable.' });
    }
  }

  function dispose() {
    if (disposed) return;
    disposed = true;
    renderer.dispose();
  }
  return { middleware, dispose };
}

function createViteFontPlugin(options = {}) {
  let bridge;
  let close;
  return {
    name: 'glyph-local-native-fonts',
    apply: 'serve',
    configureServer(server) {
      bridge = createViteFontBridge(options);
      server.middlewares.use(bridge.middleware);
      const sources = [__filename, path.join(__dirname, '../electron/fonts.cjs'), path.join(__dirname, '../electron/font-renderer.ps1')];
      const normalize = (filename) => process.platform === 'win32' ? path.resolve(filename).toLowerCase() : path.resolve(filename);
      const watched = new Set(sources.map(normalize));
      const changed = (filename) => {
        if (!watched.has(normalize(filename))) return;
        // CJS helpers are loaded by createRequire, so Vite cannot discover
        // these dependencies from its normal config import graph.
        server.restart().catch((error) => server.config.logger.error(String(error)));
      };
      server.watcher?.add(sources);
      server.watcher?.on('change', changed);
      close = () => {
        server.watcher?.off('change', changed);
        bridge.dispose();
      };
      server.httpServer?.once('close', close);
    },
    closeBundle() { close?.(); },
  };
}

module.exports = { createViteFontBridge, createViteFontPlugin, isLoopbackAddress };
