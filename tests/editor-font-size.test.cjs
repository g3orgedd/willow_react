const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

function loadFontSizeHelpers() {
  const filename = path.join(__dirname, '..', 'public', 'modules', '40-editor.js');
  const source = fs.readFileSync(filename, 'utf8');
  const start = source.indexOf('function normalizeFontSizeValue');
  const end = source.indexOf('function getMultiFontSizeValue');
  assert.ok(start >= 0 && end > start, 'font-size helpers must remain extractable');
  const context = {
    CLARISOFT_TEXT_FIELD_HEIGHT_MM_PER_PITCH: 0.4,
    mmToInternal: (value) => Math.round(value * 100),
    getFieldRenderedBoundsInternal: (field) => ({
      x: field.geom.x,
      y: field.geom.y,
      w: field.text.pitch * 200 * (field.text.xMag / 100),
      h: field.text.pitch * 40,
    }),
    getEffectiveTextPitch: (field) => field.text.pitch,
    supportsFontSizeEditing: (field) => !!field?.text && field.fldType !== 'Barcode',
    clamp: (min, max, value) => Math.max(min, Math.min(max, value)),
    X_MAG_MIN: 3,
    X_MAG_MAX: 500,
  };
  context.globalThis = context;
  vm.createContext(context);
  vm.runInContext(`${source.slice(start, end)}\nglobalThis.applyTextPitchChange = applyTextPitchChange;`, context, { filename });
  return context;
}

test('manual font-size changes update pitch and model geometry without moving the field', () => {
  const api = loadFontSizeHelpers();
  const field = {
    text: { pitch: 3, xMag: 100 },
    geom: { x: 50, y: 75, w: 600, h: 120 },
  };

  assert.equal(api.applyTextPitchChange(field, 10), 10);
  assert.equal(field.text.pitch, 10);
  assert.deepEqual(JSON.parse(JSON.stringify(field.geom)), { x: 50, y: 75, w: 2000, h: 400 });
});

test('manual oversized font values are retained for normal overflow validation', () => {
  const api = loadFontSizeHelpers();
  const field = {
    text: { pitch: 5, xMag: 100 },
    geom: { x: 100, y: 200, w: 1000, h: 200 },
  };

  assert.equal(api.applyTextPitchChange(field, 12), 12);
  assert.equal(field.text.pitch, 12);
  assert.equal(field.geom.w, 2400);
  assert.equal(field.geom.h, 480);
  assert.equal(field.geom.x, 100);
  assert.equal(field.geom.y, 200);
});

test('canvas resize normalizes transformer scale into pitch, xMag and real geometry', () => {
  const api = loadFontSizeHelpers();
  const field = {
    fldType: 'FixedText',
    text: { pitch: 5, xMag: 100 },
    geom: { x: 100, y: 200, w: 1000, h: 200 },
  };

  assert.deepEqual(
    JSON.parse(JSON.stringify(api.applyTextResizeTransform(field, { pitch: 5, xMag: 100 }, 1.5, 2))),
    { pitch: 10, xMag: 75 },
  );
  assert.equal(field.text.pitch, 10);
  assert.equal(field.text.xMag, 75);
  assert.equal(field.geom.w, 1500);
  assert.equal(field.geom.h, 400);
});

test('horizontal canvas resize changes xMag without reverting an auto-fit pitch', () => {
  const api = loadFontSizeHelpers();
  const field = {
    fldType: 'DateText',
    text: { pitch: 5, xMag: 100 },
    geom: { x: 0, y: 0, w: 1000, h: 200 },
  };

  api.applyTextResizeTransform(field, { pitch: 5, xMag: 100 }, 1.4, 1);
  assert.equal(field.text.pitch, 5);
  assert.equal(field.text.xMag, 140);
  assert.equal(field.geom.w, 1400);
  assert.equal(field.geom.h, 200);
});
