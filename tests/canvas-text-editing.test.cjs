const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

function extractFunctionBlock(source, startMarker, endMarker, description) {
  const start = source.indexOf(startMarker);
  const end = source.indexOf(endMarker, start);
  assert.ok(start >= 0 && end > start, `${description} must remain extractable`);
  return source.slice(start, end);
}

function loadCanvasEditingStarter(inputs) {
  const filename = path.join(__dirname, '..', 'public', 'modules', '40-editor.js');
  const source = fs.readFileSync(filename, 'utf8');
  const calls = [];
  const context = {
    elPropsPanel: {
      querySelectorAll: (selector) => {
        calls.push(['query', selector]);
        return inputs;
      },
    },
    selectField: (...args) => calls.push(['selectField', ...args]),
    renderUI: () => calls.push(['renderUI']),
  };
  context.globalThis = context;
  vm.createContext(context);
  const block = extractFunctionBlock(
    source,
    'function isCanvasEditableTextField',
    'function createPanelActionButton',
    'canvas text editing starter',
  );
  vm.runInContext(`${block}\nglobalThis.startCanvasTextFieldValueEditing = startCanvasTextFieldValueEditing;`, context, { filename });
  return { start: context.startCanvasTextFieldValueEditing, calls };
}

function loadCanvasEditingInstaller() {
  const filename = path.join(__dirname, '..', 'public', 'modules', '30-rendering.js');
  const source = fs.readFileSync(filename, 'utf8');
  const starts = [];
  const context = {
    isMobilePanMode: false,
    startCanvasTextFieldValueEditing: (field) => starts.push(field),
  };
  context.globalThis = context;
  vm.createContext(context);
  const block = extractFunctionBlock(
    source,
    'function installCanvasTextFieldValueEditing',
    'function makeFieldGroup',
    'canvas double-click installer',
  );
  vm.runInContext(`${block}\nglobalThis.installCanvasTextFieldValueEditing = installCanvasTextFieldValueEditing;`, context, { filename });
  return { install: context.installCanvasTextFieldValueEditing, starts };
}

function loadLiveTextValueInput(field) {
  const filename = path.join(__dirname, '..', 'public', 'modules', '40-editor.js');
  const source = fs.readFileSync(filename, 'utf8');
  const calls = [];
  const state = { subImage: { usedSizeDirty: false } };
  const listeners = new Map();
  const input = {
    value: '',
    addEventListener(type, listener) {
      const current = listeners.get(type) || [];
      current.push(listener);
      listeners.set(type, current);
    },
    emit(type) {
      for (const listener of listeners.get(type) || []) listener({ type, target: this });
    },
  };
  const context = {
    inputText: (value, onChange) => {
      input.value = String(value ?? '');
      input.addEventListener('change', () => onChange(input.value));
      return input;
    },
    getStoredTextFieldValue: (target) => target.value,
    pushHistory: () => calls.push(['history', field.value]),
    setEditableTextFieldValue: (target, value) => {
      calls.push(['set', value]);
      target.value = value;
    },
    state,
    schedulePersistActiveTemplateTab: () => calls.push(['persist']),
    renderObjects: () => {
      calls.push(['renderObjects', state.subImage.usedSizeDirty]);
      state.subImage.usedSizeDirty = false;
    },
    renderUI: () => calls.push(['renderUI']),
  };
  context.globalThis = context;
  vm.createContext(context);
  const block = extractFunctionBlock(
    source,
    'function createEditableTextFieldValueInput',
    'function createPanelActionButton',
    'live text value input',
  );
  vm.runInContext(`${block}\nglobalThis.createEditableTextFieldValueInput = createEditableTextFieldValueInput;`, context, { filename });
  return {
    input: context.createEditableTextFieldValueInput(field, field.value),
    calls,
  };
}

function createValueInput(fieldName, options = {}) {
  return {
    dataset: { fieldName },
    disabled: Boolean(options.disabled),
    readOnly: Boolean(options.readOnly),
    focusOptions: null,
    selectCount: 0,
    focus(nextOptions) {
      this.focusOptions = nextOptions;
    },
    select() {
      this.selectCount += 1;
    },
  };
}

test('double-click editing selects the current FixedText value input', () => {
  const otherInput = createValueInput('OtherField');
  const valueInput = createValueInput('Field00');
  const api = loadCanvasEditingStarter([otherInput, valueInput]);
  const field = { name: 'Field00', fldType: 'FixedText' };

  assert.equal(api.start(field), true);
  assert.deepEqual(
    JSON.parse(JSON.stringify(api.calls[0])),
    ['selectField', field.name, { additive: false, toggle: false }],
  );
  assert.deepEqual(api.calls[1], ['renderUI']);
  assert.deepEqual(api.calls[2], ['query', "[data-field-value-input='1']"]);
  assert.deepEqual(JSON.parse(JSON.stringify(valueInput.focusOptions)), { preventScroll: true });
  assert.equal(valueInput.selectCount, 1);
  assert.equal(otherInput.selectCount, 0);
});

test('computed text and DataMatrix values do not start direct editing', () => {
  const api = loadCanvasEditingStarter([]);

  assert.equal(api.start({ name: 'Date', fldType: 'DateText' }), false);
  assert.equal(api.start({ name: 'Code', fldType: 'Barcode' }), false);
  assert.deepEqual(api.calls, []);
});

test('canvas installer handles only primary-button double-clicks on FixedText', () => {
  const api = loadCanvasEditingInstaller();
  const handlers = new Map();
  const group = { on: (name, handler) => handlers.set(name, handler) };
  const field = { name: 'Field00', fldType: 'FixedText' };

  assert.equal(api.install(group, field), true);
  assert.equal(typeof handlers.get('dblclick'), 'function');

  let prevented = 0;
  const primaryEvent = {
    evt: { button: 0, preventDefault: () => { prevented += 1; } },
    cancelBubble: false,
  };
  handlers.get('dblclick')(primaryEvent);
  assert.equal(primaryEvent.cancelBubble, true);
  assert.equal(prevented, 1);
  assert.deepEqual(api.starts, [field]);

  handlers.get('dblclick')({ evt: { button: 2 }, cancelBubble: false });
  assert.deepEqual(api.starts, [field]);

  const dynamicGroup = { on: () => assert.fail('dynamic text must not register direct editing') };
  assert.equal(api.install(dynamicGroup, { name: 'Date', fldType: 'DateText' }), false);
});

test('editable inspector values expose a stable canvas-editing hook', () => {
  const filename = path.join(__dirname, '..', 'public', 'modules', '40-editor.js');
  const source = fs.readFileSync(filename, 'utf8');
  const builder = extractFunctionBlock(source, 'function buildTextLikeProps', 'function buildBarcodeProps', 'text property builder');

  assert.match(builder, /valueInput\.dataset\.fieldValueInput = "1"/);
  assert.match(builder, /valueInput\.dataset\.fieldName = f\.name/);
  assert.match(builder, /if \(isDynamicPreviewField\)[\s\S]*?else/);
});

test('text value updates on every input event and records one history snapshot per edit session', () => {
  const field = { name: 'Field00', fldType: 'FixedText', value: 'OLD' };
  const api = loadLiveTextValueInput(field);

  for (const value of ['N', 'NE', 'NEW']) {
    api.input.value = value;
    api.input.emit('input');
    assert.equal(field.value, value);
  }

  assert.deepEqual(api.calls, [
    ['history', 'OLD'],
    ['set', 'N'], ['persist'], ['renderObjects', true], ['renderUI'],
    ['set', 'NE'], ['persist'], ['renderObjects', true], ['renderUI'],
    ['set', 'NEW'], ['persist'], ['renderObjects', true], ['renderUI'],
  ]);

  api.input.emit('change');
  assert.equal(api.calls.filter(([type]) => type === 'history').length, 1);
  assert.equal(api.calls.filter(([type]) => type === 'set').length, 3);

  api.input.value = 'NEXT';
  api.input.emit('input');
  assert.equal(field.value, 'NEXT');
  assert.deepEqual(api.calls.filter(([type]) => type === 'history'), [
    ['history', 'OLD'],
    ['history', 'NEW'],
  ]);
});

test('blur closes a live edit session and unchanged input creates no history or renders', () => {
  const field = { name: 'Field00', fldType: 'FixedText', value: 'SAME' };
  const api = loadLiveTextValueInput(field);

  api.input.emit('input');
  api.input.emit('blur');
  assert.deepEqual(api.calls, []);

  api.input.value = 'FIRST';
  api.input.emit('input');
  api.input.emit('blur');
  api.input.value = 'SECOND';
  api.input.emit('input');

  assert.equal(field.value, 'SECOND');
  assert.deepEqual(api.calls.filter(([type]) => type === 'history'), [
    ['history', 'SAME'],
    ['history', 'FIRST'],
  ]);
});

test('a change event without prior input still applies once and starts one history entry', () => {
  const field = { name: 'Field00', fldType: 'FixedText', value: 'OLD' };
  const api = loadLiveTextValueInput(field);

  api.input.value = 'PASTED';
  api.input.emit('change');
  api.input.emit('blur');

  assert.equal(field.value, 'PASTED');
  assert.deepEqual(api.calls, [
    ['history', 'OLD'],
    ['set', 'PASTED'],
    ['persist'],
    ['renderObjects', true],
    ['renderUI'],
  ]);
});
