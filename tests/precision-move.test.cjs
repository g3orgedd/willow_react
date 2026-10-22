const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const test = require('node:test');
const vm = require('node:vm');

const root = path.join(__dirname, '..');
const read = (...segments) => fs.readFileSync(path.join(root, ...segments), 'utf8');

const component = read('src', 'components', 'CanvasWorkspace.tsx');
const canvasUi = read('public', 'modules', '10-canvas-ui.js');
const rendering = read('public', 'modules', '30-rendering.js');
const i18n = read('public', 'modules', '05-i18n.js');
const styles = read('public', 'styles.css');
const core = read('public', 'modules', '00-core.js');
const moveStepRuntime = () => [
  'const DEFAULT_MOVE_STEP = 0.1;',
  core.match(/const MOVE_STEP_OPTIONS = \[[^\]]+\];/)[0],
  extractFunction(core, 'normalizeMoveStep'),
  extractFunction(canvasUi, 'getMoveStepDelta'),
].join('\n');
const plain = (value) => JSON.parse(JSON.stringify(value));

function extractBalancedBlock(source, marker) {
  const markerIndex = source.indexOf(marker);
  assert.ok(markerIndex >= 0, `${marker} must exist`);
  const blockStart = source.indexOf('{', markerIndex + marker.length);
  assert.ok(blockStart >= 0, `${marker} must have a block`);
  let depth = 0;
  for (let index = blockStart; index < source.length; index += 1) {
    if (source[index] === '{') depth += 1;
    if (source[index] !== '}') continue;
    depth -= 1;
    if (depth === 0) return source.slice(markerIndex, index + 1);
  }
  assert.fail(`${marker} block must be balanced`);
}

function extractFunction(source, name) {
  const marker = `function ${name}(`;
  const markerIndex = source.indexOf(marker);
  assert.ok(markerIndex >= 0, `${name} must exist`);
  const parametersStart = source.indexOf('(', markerIndex);
  let parameterDepth = 0;
  let parametersEnd = -1;
  for (let index = parametersStart; index < source.length; index += 1) {
    if (source[index] === '(') parameterDepth += 1;
    if (source[index] !== ')') continue;
    parameterDepth -= 1;
    if (parameterDepth === 0) {
      parametersEnd = index;
      break;
    }
  }
  assert.ok(parametersEnd >= 0, `${name} parameters must be balanced`);
  const bodyStart = source.indexOf('{', parametersEnd);
  let bodyDepth = 0;
  for (let index = bodyStart; index < source.length; index += 1) {
    if (source[index] === '{') bodyDepth += 1;
    if (source[index] !== '}') continue;
    bodyDepth -= 1;
    if (bodyDepth === 0) return source.slice(markerIndex, index + 1);
  }
  assert.fail(`${name} body must be balanced`);
}

function extractElement(source, marker, closingTag) {
  const markerIndex = source.indexOf(marker);
  assert.ok(markerIndex >= 0, `${marker} must exist`);
  const elementStart = source.lastIndexOf('<', markerIndex);
  const elementEnd = source.indexOf(closingTag, markerIndex);
  assert.ok(elementStart >= 0 && elementEnd >= 0, `${marker} must have a closing tag`);
  return source.slice(elementStart, elementEnd + closingTag.length);
}

test('Precision Move markup is one flat D-pad with direction-only controls', () => {
  assert.match(component, /id="precisionMovePanel"[^>]*role="group"[^>]*aria-hidden="true"/);
  assert.equal((component.match(/data-precision-move=/g) || []).length, 4);
  assert.equal((component.match(/className="precisionMoveStep"/g) || []).length, 1);
  assert.match(component, /<select id="precisionMoveStep" className="select" aria-label="Move step \(mm\)"/);

  const directions = [
    ['Up', 'up', '0', '-0.1', 'arrow_upward_24dp.svg'],
    ['Left', 'left', '-0.1', '0', 'arrow_back_24dp.svg'],
    ['Right', 'right', '0.1', '0', 'arrow_forward_24dp.svg'],
    ['Down', 'down', '0', '0.1', 'arrow_downward_24dp.svg'],
  ];

  for (const [id, direction, dx, dy, icon] of directions) {
    const button = extractElement(component, `className="precisionMoveButton precisionMoveButton--${direction}"`, '</button>');
    assert.match(button, new RegExp(`id="precisionMove${id}"`));
    assert.match(button, new RegExp(`data-precision-move="${direction}"`));
    assert.doesNotMatch(button, /data-move-d[xy]/);
    assert.match(button, new RegExp(icon.replace('.', '\\.')));
    assert.match(button, /type="button"/);
    assert.match(button, /aria-label=/);
    assert.match(button, /disabled/);
  }

  assert.doesNotMatch(component, /precisionMovePanel[\s\S]*precisionMove(Group|Card|Wrapper)/);
});

test('Precision Move CSS uses a framed, aligned grid with comfortably sized controls', () => {
  const panel = extractBalancedBlock(styles, '.precisionMovePanel {');
  const visible = extractBalancedBlock(styles, '.precisionMovePanel.is-visible {');
  const button = extractBalancedBlock(styles, '.precisionMoveButton {');
  const hover = extractBalancedBlock(styles, '.precisionMoveButton:hover:not(:disabled) {');
  const pressed = extractBalancedBlock(styles, '.precisionMoveButton:active:not(:disabled),');
  const focus = extractBalancedBlock(styles, '.precisionMoveButton:focus-visible {');
  const disabled = extractBalancedBlock(styles, '.precisionMoveButton:disabled {');
  const step = extractBalancedBlock(styles, '.precisionMoveStep {');

  assert.match(panel, /right:\s*16px/);
  assert.match(panel, /bottom:\s*16px/);
  assert.match(panel, /grid-template-columns:\s*repeat\(3, 40px\)/);
  assert.match(panel, /grid-template-rows:\s*repeat\(3, 40px\)/);
  assert.match(panel, /gap:\s*2px/);
  assert.match(panel, /padding:\s*8px/);
  assert.match(panel, /border:\s*1px solid/);
  assert.match(panel, /border-radius:\s*18px/);
  assert.match(panel, /background:\s*color-mix\([^;]*surface-container-high/);
  assert.match(panel, /box-shadow:\s*var\(--app-shadow-1\)/);
  assert.match(panel, /transform:\s*translateY\(5px\) scale\(0\.98\)/);
  assert.doesNotMatch(panel, /backdrop-filter/);
  assert.match(visible, /pointer-events:\s*auto/);
  assert.match(visible, /transform:\s*translateY\(0\) scale\(1\)/);

  assert.match(button, /width:\s*40px/);
  assert.match(button, /height:\s*40px/);
  assert.match(button, /border:\s*0/);
  assert.match(button, /background:\s*transparent/);
  assert.match(hover, /on-surface\) 9%/);
  assert.match(pressed, /primary-container\) 50%/);
  assert.match(pressed, /transform:\s*scale\(0\.95\)/);
  assert.doesNotMatch(pressed, /translateY/);
  assert.match(focus, /outline:\s*2px solid/);
  assert.match(focus, /outline-offset:\s*1px/);
  assert.match(disabled, /opacity:\s*0\.36/);
  assert.match(disabled, /pointer-events:\s*none/);
  assert.match(step, /grid-column:\s*2/);
  assert.match(step, /grid-row:\s*2/);
  assert.match(step, /font-size:\s*0\.75rem/);
  assert.doesNotMatch(step, /pointer-events:\s*none/);

  assert.doesNotMatch(styles, /\.precisionMoveButton--(?:left|right) img\s*\{[^}]*rotate/s);
});

test('Precision Move labels are localized for the group and all buttons', () => {
  const english = i18n.slice(i18n.indexOf('  en: {'), i18n.indexOf('  ru: {'));
  const russian = i18n.slice(i18n.indexOf('  ru: {'), i18n.indexOf('const UI_TRANSLATION_TARGETS'));
  for (const key of ['precisionMove', 'moveUp', 'moveLeft', 'moveRight', 'moveDown']) {
    assert.match(english, new RegExp(`"canvas\\.${key}"`));
    assert.match(russian, new RegExp(`"canvas\\.${key}"`));
  }
  assert.match(english, /"canvas.moveUp": "[^"\n]*\{step\}/);
  assert.match(russian, /"canvas.moveUp": "[^"\n]*\{step\}/);
});

test('Precision Move visibility and disabled state follow single or multi-selection', () => {
  const panelClasses = new Set();
  const panelAttributes = {};
  const panel = {
    classList: {
      toggle(name, enabled) {
        if (enabled) panelClasses.add(name);
        else panelClasses.delete(name);
      },
    },
    setAttribute(name, value) { panelAttributes[name] = String(value); },
  };
  const buttons = ['up', 'left', 'right', 'down'].map((direction) => ({
    disabled: false, dataset: { precisionMove: direction }, setAttribute() {},
  }));
  let selection = [];
  const context = {
    state: { moveStep: 0.1 },
    t: (key, { step }) => `${key} ${step}`,
    document: { querySelectorAll: () => buttons },
    $: (id) => id === 'precisionMovePanel' ? panel : null,
    getSelectedFields: () => selection,
  };
  context.globalThis = context;
  vm.createContext(context);
  vm.runInContext([
    moveStepRuntime(),
    extractFunction(canvasUi, 'getPrecisionMoveButtons'),
    extractFunction(canvasUi, 'syncPrecisionMoveControls'),
  ].join('\n'), context);

  context.syncPrecisionMoveControls();
  assert.equal(panelClasses.has('is-visible'), false);
  assert.equal(panelAttributes['aria-hidden'], 'true');
  assert.equal(buttons.every((button) => button.disabled), true);

  selection = [{ name: 'A' }, { name: 'B' }];
  context.syncPrecisionMoveControls();
  assert.equal(panelClasses.has('is-visible'), true);
  assert.equal(panelAttributes['aria-hidden'], 'false');
  assert.equal(buttons.every((button) => !button.disabled), true);
});

test('pointer hold keeps the existing immediate move, 320 ms delay, and 72 ms repeat', () => {
  const listeners = new Map();
  const classes = new Set();
  const button = {
    dataset: { precisionMove: 'up' },
    disabled: false,
    classList: {
      add: (name) => classes.add(name),
      remove: (name) => classes.delete(name),
    },
    addEventListener: (name, listener) => listeners.set(name, listener),
    setPointerCapture: () => {},
  };
  const moves = [];
  let delayTimer = null;
  let repeatTimer = null;
  let clearedInterval = false;
  const context = {
    state: { moveStep: 0.1 },
    document: { querySelectorAll: () => [button] },
    moveSelectedFieldsByMm: (dx, dy, options) => {
      moves.push({ dx, dy, options });
      return true;
    },
    window: {
      setTimeout(callback, delay) {
        delayTimer = { callback, delay };
        return delayTimer;
      },
      clearTimeout() {},
      setInterval(callback, delay) {
        repeatTimer = { callback, delay };
        return repeatTimer;
      },
      clearInterval() { clearedInterval = true; },
    },
  };
  context.globalThis = context;
  vm.createContext(context);
  vm.runInContext([
    'const PRECISION_MOVE_REPEAT_DELAY_MS = 320;',
    'const PRECISION_MOVE_REPEAT_INTERVAL_MS = 72;',
    moveStepRuntime(),
    extractFunction(canvasUi, 'getPrecisionMoveButtons'),
    extractFunction(canvasUi, 'getPrecisionMoveButtonDelta'),
    extractFunction(canvasUi, 'moveSelectionFromPrecisionButton'),
    extractFunction(canvasUi, 'initPrecisionMoveControls'),
    'initPrecisionMoveControls();',
  ].join('\n'), context);

  listeners.get('pointerdown')({ button: 0, pointerId: 7, preventDefault() {} });
  assert.deepEqual(plain(moves), [{ dx: 0, dy: -0.1, options: {} }]);
  assert.equal(classes.has('is-pressing'), true);
  assert.equal(delayTimer.delay, 320);

  delayTimer.callback();
  assert.equal(repeatTimer.delay, 72);
  context.state.moveStep = 0.5;
  repeatTimer.callback();
  assert.deepEqual(plain(moves[1]), { dx: 0, dy: -0.5, options: { skipHistory: true } });

  listeners.get('click')({ detail: 1 });
  assert.equal(moves.length, 2, 'pointer click must not duplicate pointerdown movement');
  listeners.get('pointerup')({});
  assert.equal(classes.has('is-pressing'), false);
  assert.equal(clearedInterval, true);

  listeners.get('click')({ detail: 0 });
  assert.deepEqual(plain(moves[2]), { dx: 0, dy: -0.5, options: {} });
});

test('keyboard and D-pad share all step values and preserve integer coordinates after repeated moves', () => {
  const fields = [{ geom: { x: 1000, y: 1000 } }, { geom: { x: 1200, y: 1400 } }];
  let historyCount = 0;
  let modal = null;
  const context = {
    state: { moveStep: 0.1, gridMm: 10 }, pendingCanvasPlacement: null,
    document: { querySelectorAll: () => modal ? [modal] : [] },
    isEditableEventTarget: (target) => !!target?.editable,
    getSelectedFields: () => fields,
    mmToInternal: (mm) => Math.round(mm * 100),
    constrainFieldsMovementDeltaInternal: (_fields, x, y) => ({ x, y }),
    pushHistory: () => historyCount++,
    renderAfterFieldPositionChange() {},
  };
  vm.createContext(context);
  vm.runInContext([
    moveStepRuntime(), extractFunction(canvasUi, 'getPrecisionMoveButtonDelta'),
    extractFunction(canvasUi, 'moveSelectionFromPrecisionButton'),
    extractFunction(canvasUi, 'handleMoveSelectionKeydown'),
    extractFunction(rendering, 'setFieldPositionInternal'),
    extractFunction(rendering, 'moveSelectedFieldsByMm'),
  ].join('\n'), context);
  for (const step of [0.1, 0.3, 0.5, 0.7, 1, 1.2, 1.5, 2, 2.5, 3, 5, 7, 10]) {
    context.state.moveStep = step;
    const startX = fields[0].geom.x;
    const startY = fields[0].geom.y;
    for (let index = 0; index < 100; index++) {
      assert.equal(context.handleMoveSelectionKeydown({ key: 'ArrowRight', preventDefault() {} }), true);
      context.moveSelectionFromPrecisionButton({ dataset: { precisionMove: 'up' } });
    }
    assert.equal(fields[0].geom.x, startX + step * 10000);
    assert.equal(fields[0].geom.y, startY - step * 10000);
    assert.equal(fields[1].geom.x - fields[0].geom.x, 200);
    assert.equal(fields[1].geom.y - fields[0].geom.y, 400);
    assert.equal(Number.isInteger(fields[0].geom.x), true);
    assert.equal(context.state.gridMm, 10);
  }
  assert.equal(historyCount, 2600);
  for (const options of [{ ctrlKey: true }, { shiftKey: true }, { metaKey: true }, { altKey: true }, { defaultPrevented: true }, { target: { editable: true } }, { target: { closest: () => ({}) } }]) {
    assert.equal(context.handleMoveSelectionKeydown({ key: 'ArrowRight', ...options }), false);
  }
  modal = { getClientRects: () => [{}], closest: () => null };
  assert.equal(context.handleMoveSelectionKeydown({ key: 'ArrowRight' }), false);
  assert.equal(historyCount, 2600);
  modal = { getClientRects: () => [], closest: () => ({}) };
  assert.equal(context.handleMoveSelectionKeydown({ key: 'ArrowRight', preventDefault() {} }), true);
});

test('move step restores from persisted tab view, falls back safely, and synchronizes the indicator', () => {
  const tabs = read('public', 'modules', '70-template-tabs.js');
  const indicator = {};
  const select = {};
  const context = {
    state: { moveStep: 0.7, gridMm: 3 },
    GRID_SIZE_OPTIONS: [1, 3, 5, 10], GRID_MM: 1,
    zoomPct: 100, stage: null, isMobilePanMode: false,
    elToggleGrid: null, elToggleSnap: null, elToggleAlign: null,
    elGridSizeSelect: null, elZoomRange: null, elZoomLabel: null, elStatusLeft: null,
    $: (id) => ({ precisionMoveStep: indicator, moveStepSelect: select })[id],
    t: (key, { step } = {}) => `${key}: ${step}`,
    document: { querySelectorAll: () => [] }, getSelectedFields: () => [],
    cloneTemplateTabValue: plain, parseTemplateTabXmlDocument: () => ({}),
    restoreFromSnapshot() {}, snapshotState: () => '{}', setMobilePanMode() {},
    renderAll() {}, updateUndoRedoButtons() {},
    clamp: (min, max, value) => Math.max(min, Math.min(max, value)),
    console,
  };
  vm.createContext(context);
  vm.runInContext([
    moveStepRuntime(), extractFunction(canvasUi, 'getPrecisionMoveButtons'),
    extractFunction(canvasUi, 'syncPrecisionMoveControls'),
    extractFunction(tabs, 'captureCurrentTemplateView'),
    extractFunction(tabs, 'restoreTemplateTabState'),
  ].join('\n'), context);
  const saved = JSON.parse(JSON.stringify(context.captureCurrentTemplateView()));
  context.state.moveStep = 0.1;
  assert.equal(context.restoreTemplateTabState({ templateState: { view: saved } }), true);
  assert.equal(context.state.moveStep, 0.7);
  assert.equal(indicator.value, '0.7');
  assert.equal(select.value, '0.7');
  assert.equal(context.state.gridMm, 3);
  for (const value of [undefined, null, '', 'invalid', 0, -1, 0.2, Infinity]) {
    assert.equal(context.restoreTemplateTabState({ templateState: { view: { moveStep: value } } }), true);
    assert.equal(context.state.moveStep, 0.1);
    assert.equal(indicator.value, '0.1');
  }
});

test('single and multi-selection both move exactly 0.1 mm with one history entry', () => {
  const fields = [
    { geom: { x: 100, y: 200 } },
    { geom: { x: 350, y: 475 } },
  ];
  let selected = fields.slice(0, 1);
  let historyCount = 0;
  let renderCount = 0;
  const context = {
    getSelectedFields: () => selected,
    mmToInternal: (value) => Math.round(Number(value) * 100),
    constrainFieldsMovementDeltaInternal: (_fields, dx, dy) => ({ x: dx, y: dy }),
    pushHistory: () => { historyCount += 1; },
    setFieldPositionInternal: (field, x, y) => {
      field.geom.x = x;
      field.geom.y = y;
      return true;
    },
    renderAfterFieldPositionChange: () => { renderCount += 1; },
  };
  context.globalThis = context;
  vm.createContext(context);
  vm.runInContext(extractFunction(rendering, 'moveSelectedFieldsByMm'), context);

  assert.equal(context.moveSelectedFieldsByMm(0.1, 0), true);
  assert.deepEqual(fields[0].geom, { x: 110, y: 200 });
  assert.deepEqual(fields[1].geom, { x: 350, y: 475 });
  assert.equal(historyCount, 1);

  selected = fields;
  assert.equal(context.moveSelectedFieldsByMm(0, -0.1), true);
  assert.deepEqual(fields[0].geom, { x: 110, y: 190 });
  assert.deepEqual(fields[1].geom, { x: 350, y: 465 });
  assert.equal(historyCount, 2, 'multi-selection must create one shared history entry');
  assert.equal(renderCount, 2);

  assert.equal(context.moveSelectedFieldsByMm(0, -0.1, { skipHistory: true }), true);
  assert.equal(historyCount, 2, 'hold repeats must stay in the first Undo entry');
});
