// ClariSoft's TrueType selector uses fonts installed on the editing computer.
// Desktop gets the Windows inventory; web preview probes local faces only.
const TEXT_FONT_CANDIDATES = Object.freeze([
  'Arial', 'Arial Black', 'Bahnschrift', 'Calibri', 'Cambria', 'Candara',
  'Century Gothic', 'Comic Sans MS', 'Consolas', 'Constantia', 'Corbel',
  'Courier New', 'Franklin Gothic Medium', 'Garamond', 'Georgia', 'Impact',
  'Lucida Console', 'Lucida Sans Unicode', 'Microsoft Sans Serif',
  'Palatino Linotype', 'Segoe UI', 'Tahoma', 'Times New Roman',
  'Trebuchet MS', 'Verdana',
]);
const textFontCatalog = { families: ['Arial'], ready: false, promise: null };

function normalizeTextFontFamilies(families) {
  const unique = new Map();
  for (const value of families || []) {
    const face = String(value || '').trim();
    if (!face || face.startsWith('@')) continue;
    const key = face.toLocaleLowerCase();
    if (!unique.has(key)) unique.set(key, face);
  }
  return Array.from(unique.values()).sort((a, b) => a.localeCompare(b));
}

function getAvailableTextFontFamilies() {
  return textFontCatalog.families.slice();
}

function isTextFontAvailable(face) {
  return textFontCatalog.families.some((value) => value.toLocaleLowerCase() === String(face).toLocaleLowerCase());
}

async function loadBrowserTextFontFamilies() {
  if (typeof FontFace !== 'function') return ['Arial'];
  const results = await Promise.allSettled(TEXT_FONT_CANDIDATES.map(async (face) => {
    const source = `local(${JSON.stringify(face)})`;
    await new FontFace('GlyphLocalFontProbe', source).load();
    return face;
  }));
  return results.filter((result) => result.status === 'fulfilled').map((result) => result.value);
}

async function connectLocalDevFontService() {
  if (globalThis.glyphFonts?.list || typeof globalThis.fetch !== 'function') return null;
  const hostname = String(globalThis.location?.hostname || '').toLowerCase();
  if (!['localhost', '127.0.0.1', '[::1]', '::1'].includes(hostname)) return null;
  try {
    const response = await fetch('/__glyph_fonts/list', { credentials: 'same-origin', cache: 'no-store' });
    if (!response.ok || !String(response.headers.get('content-type') || '').includes('application/json')) return null;
    const catalog = await response.json();
    if (!Array.isArray(catalog?.families) || !catalog.families.length) return null;
    const bridge = Object.freeze({
      list: async () => ({ families: catalog.families.slice() }),
      render: async (payload) => {
        const bitmap = await fetch('/__glyph_fonts/render', {
          method: 'POST', credentials: 'same-origin',
          headers: { 'Content-Type': 'application/json' }, body: JSON.stringify(payload),
        });
        if (!bitmap.ok) throw new Error('The local native font renderer is unavailable.');
        return bitmap.json();
      },
    });
    globalThis.glyphFonts = bridge;
    return catalog;
  } catch { return null; }
}

function initTextFontCatalog() {
  if (textFontCatalog.promise) return textFontCatalog.promise;
  textFontCatalog.promise = (async () => {
    let families;
    try {
      await connectLocalDevFontService();
      families = globalThis.glyphFonts?.list
        ? (await globalThis.glyphFonts.list()).families
        : await loadBrowserTextFontFamilies();
    } catch (error) {
      console.warn('Could not read installed fonts:', error);
      families = await loadBrowserTextFontFamilies();
    }
    const available = normalizeTextFontFamilies(families);
    textFontCatalog.families = available.length ? available : ['Arial'];
    textFontCatalog.ready = true;
  })();
  return textFontCatalog.promise;
}
