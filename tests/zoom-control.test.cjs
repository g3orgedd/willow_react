const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const test = require('node:test');
const vm = require('node:vm');

const source = fs.readFileSync(path.join(__dirname, '../public/modules/10-canvas-ui.js'), 'utf8');
const zoomFunctions = source.slice(source.indexOf('function syncZoomSliderUI()'), source.indexOf('function getPixelsPerMm()'));

function createHarness() {
  const attributes = new Map();
  const properties = new Map();
  const calls = [];
  const range = {
    min: '25', max: '400', value: '100',
    parentElement: { style: { setProperty: (key, value) => properties.set(key, value) } },
    setAttribute: (key, value) => attributes.set(key, value),
  };
  const context = vm.createContext({
    zoomPct: 100,
    elZoomRange: range,
    elZoomLabel: { textContent: '100%' },
    clamp: (min, max, value) => Math.max(min, Math.min(max, value)),
    renderGrid: () => calls.push('grid'),
    renderObjects: () => calls.push('objects'),
    renderRulers: () => calls.push('rulers'),
    renderUI: () => calls.push('ui'),
    schedulePersistActiveTemplateTab: () => calls.push('persist'),
  });
  vm.runInContext(zoomFunctions, context);
  return { context, range, attributes, properties, calls };
}

test('zoom changes keep the native value, percentage, track position and render pipeline in sync', () => {
  const { context, range, attributes, properties, calls } = createHarness();
  for (const [value, fraction] of [[25, 0], [100, 0.2], [250, 0.6], [400, 1]]) {
    calls.length = 0;
    context.setZoom(value);
    assert.equal(context.zoomPct, value);
    assert.equal(range.value, String(value));
    assert.equal(context.elZoomLabel.textContent, `${value}%`);
    assert.equal(attributes.get('aria-valuetext'), `${value}%`);
    assert.equal(Number(properties.get('--zoom-slider-fraction')), fraction);
    assert.deepEqual(calls, ['grid', 'objects', 'rulers', 'ui', 'persist']);
  }
});

test('restoring slider presentation reads its current range without changing zoom or rendering', () => {
  const { context, range, attributes, properties, calls } = createHarness();
  range.value = '151';
  context.syncZoomSliderUI();
  assert.equal(attributes.get('aria-valuetext'), '151%');
  assert.equal(Number(properties.get('--zoom-slider-fraction')), (151 - 25) / 375);
  assert.equal(context.zoomPct, 100);
  assert.equal(range.value, '151');
  assert.deepEqual(calls, []);

  range.min = '100';
  range.max = '200';
  context.syncZoomSliderUI();
  assert.equal(Number(properties.get('--zoom-slider-fraction')), 0.51);
  range.max = range.min;
  context.syncZoomSliderUI();
  assert.equal(Number(properties.get('--zoom-slider-fraction')), 0);
});
