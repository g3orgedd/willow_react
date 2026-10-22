const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

function field(name, fldType = 'FixedText', face = null) {
  return { name, fldType, text: { face, pitch: null, defaultPitch: 13, xMag: 125, bold: null, italic: null },
    geom: { x: 125, y: 300, w: 900, h: 400 }, data: { defaultValue: 'AB', maxChars: 8 } };
}
function load(fields) {
  const history = [];
  const calls = [];
  const context = {
    state: { fields, subImage: { usedSizeDirty: false } },
    glyphFonts: { render() {} },
    requestNativeTextPreview: () => null,
    makePreviewText: (target) => target.data.defaultValue,
    CLARISOFT_TEXT_FIELD_HEIGHT_MM_PER_PITCH: 0.4,
    mmToInternal: (value) => Math.round(value * 100),
    getClarisoftTextFieldHeightInternal: (pitch) => Math.round(pitch * 40),
    getFieldRenderedBoundsInternal: () => null,
    getEffectiveTextPitch: (target) => target.text.pitch ?? target.text.defaultPitch ?? 13,
    getEffectiveTextFontFamily: (target) => target.text.face || 'Arial',
    getAvailableTextFontFamilies: () => ['Arial', 'Courier New', 'Times New Roman'],
    isTextFontAvailable: (face) => ['Arial', 'Courier New', 'Times New Roman'].includes(face),
    pushHistory: () => history.push(JSON.parse(JSON.stringify(fields))),
    renderObjects: () => calls.push('objects'),
    renderUI: () => calls.push('ui'),
    renderSelectionPanels: () => calls.push('selection'),
    createMaterialSelect: (options, value, onChange) => ({ options, value, onChange, dataset: {} }),
    fieldRow: (label, control) => ({ label, control }),
    appendInspectorItem: (wrap, group, item) => wrap.push({ group, ...item }),
    document: { createElement: () => ({}) },
    t: (key) => key,
  };
  vm.createContext(context);
  const filename = path.join(__dirname, '..', 'public', 'modules', '40-editor.js');
  const source = fs.readFileSync(filename, 'utf8');
  vm.runInContext(source.slice(source.indexOf('function supportsFontSizeEditing'),
    source.indexOf('const INSPECTOR_PROPERTY_SECTION_ORDER')), context, { filename });
  return { context, history, calls };
}

test('single font edit preserves position, omitted Pitch, horizontal scale and source data, with one undo snapshot', () => {
  const target = field('A');
  const before = JSON.parse(JSON.stringify(target));
  const { context, history, calls } = load([target]);
  assert.equal(context.applyTextFontChange([target], { face: 'Courier New' }), true);
  assert.equal(target.text.face, 'Courier New');
  assert.equal(target.text.pitch, null, 'a face edit must not insert an omitted native Pitch');
  assert.equal(target.text.xMag, before.text.xMag);
  assert.equal(target.geom.x, before.geom.x);
  assert.equal(target.geom.y, before.geom.y);
  assert.deepEqual(target.geom, before.geom, 'native geometry replaces the model only when the measured bitmap is ready');
  assert.deepEqual(target.data, before.data);
  assert.equal(history.length, 1);
  assert.deepEqual(history[0][0], before);
  assert.equal(context.state.subImage.usedSizeDirty, true);
  assert.equal(target._nativeTextGeometryDirty, true);
  assert.deepEqual(calls, ['objects', 'ui', 'selection']);
  context.state.fields = history.pop();
  assert.deepEqual(context.state.fields[0], before, 'undo restores the original face and XML-presence state');
});

test('a mixed selection changes all text subtypes in one history entry and leaves the barcode intact', () => {
  const fields = ['FixedText', 'DateText', 'OffsetDateText', 'TimeText', 'CounterText', 'Barcode']
    .map((type, index) => field(String(index), type, index % 2 ? 'Times New Roman' : 'Arial'));
  const barcodeBefore = JSON.parse(JSON.stringify(fields.at(-1)));
  const { context, history } = load(fields);
  assert.equal(context.applyTextFontChange(fields, { face: 'Courier New' }), true);
  assert.equal(history.length, 1);
  for (const target of fields.slice(0, -1)) {
    assert.equal(target.text.face, 'Courier New');
    assert.equal(target.text.pitch, null);
    assert.equal(target.geom.x, 125);
    assert.equal(target.geom.y, 300);
  }
  assert.deepEqual(fields.at(-1), barcodeBefore);
  assert.equal(context.applyTextFontChange(fields, { face: 'Courier New' }), false);
  assert.equal(history.length, 1, 'selecting the current face does not add undo noise');
});

test('font controls expose mixed family/style values and selecting one style updates every text field', () => {
  const fields = [field('A', 'FixedText', 'Arial'), field('B', 'CounterText', 'Courier New')];
  fields[1].text.bold = 1;
  const { context, history } = load(fields);
  const controls = [];
  context.appendTextFontControls(controls, fields);
  const family = controls.find((item) => item.label === 'field.fontFamily').control;
  const style = controls.find((item) => item.label === 'field.fontStyle').control;
  assert.equal(family.value, '');
  assert.equal(family.options[0].label, 'common.mixed');
  assert.equal(style.value, '');
  assert.equal(style.options[0].label, 'common.mixed');
  style.onChange('bold italic');
  assert.equal(history.length, 1);
  fields.forEach((target) => {
    assert.equal(target.text.bold, true);
    assert.equal(target.text.italic, true);
  });
});

test('an unavailable imported face remains visible and is not silently replaced by the control', () => {
  const target = field('A', 'TimeText', 'Missing Vendor Font');
  const { context, history } = load([target]);
  const controls = [];
  context.appendTextFontControls(controls, [target]);
  const family = controls.find((item) => item.label === 'field.fontFamily').control;
  assert.equal(family.value, 'Missing Vendor Font');
  assert.ok(family.options.some((option) => option.value === 'Missing Vendor Font'));
  assert.ok(controls.some((item) => item.textContent === 'field.fontUnavailablePreview'));
  family.onChange('Missing Vendor Font');
  assert.equal(history.length, 0);
  assert.equal(target.text.face, 'Missing Vendor Font');
});
