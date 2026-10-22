const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

class FakeClassList {
  constructor(owner) {
    this.owner = owner;
  }

  values() {
    return new Set(String(this.owner.className || '').split(/\s+/).filter(Boolean));
  }

  write(values) {
    this.owner.className = [...values].join(' ');
  }

  add(...names) {
    const values = this.values();
    names.forEach((name) => values.add(name));
    this.write(values);
  }

  remove(...names) {
    const values = this.values();
    names.forEach((name) => values.delete(name));
    this.write(values);
  }

  toggle(name, force) {
    const values = this.values();
    const enabled = force == null ? !values.has(name) : Boolean(force);
    if (enabled) values.add(name);
    else values.delete(name);
    this.write(values);
    return enabled;
  }

  contains(name) {
    return this.values().has(name);
  }
}

class FakeEvent {
  constructor(type, options = {}) {
    this.type = type;
    this.bubbles = Boolean(options.bubbles);
    this.defaultPrevented = false;
    this.propagationStopped = false;
    this.target = null;
    this.currentTarget = null;
  }

  preventDefault() {
    this.defaultPrevented = true;
  }

  stopPropagation() {
    this.propagationStopped = true;
  }
}

class FakeElement {
  constructor(tagName) {
    this.tagName = String(tagName).toUpperCase();
    this.children = [];
    this.parentNode = null;
    this.parentElement = null;
    this.dataset = {};
    this.attributes = new Map();
    this.className = '';
    this.classList = new FakeClassList(this);
    this.textContent = '';
    this.value = '';
    this.selected = false;
    this.disabled = false;
    this.hidden = false;
    this._listeners = new Map();
    this._innerHTML = '';
  }

  appendChild(child) {
    child.parentNode = this;
    child.parentElement = this;
    this.children.push(child);
    return child;
  }

  set innerHTML(value) {
    this._innerHTML = String(value);
    if (value === '') {
      this.children.forEach((child) => {
        child.parentNode = null;
        child.parentElement = null;
      });
      this.children = [];
    }
  }

  get innerHTML() {
    return this._innerHTML;
  }

  setAttribute(name, value) {
    this.attributes.set(String(name), String(value));
  }

  getAttribute(name) {
    return this.attributes.get(String(name)) ?? null;
  }

  removeAttribute(name) {
    this.attributes.delete(String(name));
  }

  addEventListener(type, listener) {
    const listeners = this._listeners.get(type) || [];
    listeners.push(listener);
    this._listeners.set(type, listeners);
  }

  dispatchEvent(event) {
    event.target ||= this;
    event.currentTarget = this;
    for (const listener of this._listeners.get(event.type) || []) listener.call(this, event);
    return !event.defaultPrevented;
  }

  listenerCount(type) {
    return (this._listeners.get(type) || []).length;
  }
}

function findById(root, id) {
  if (root.id === id) return root;
  for (const child of root.children) {
    const found = findById(child, id);
    if (found) return found;
  }
  return null;
}

function loadGroupedSelectFunctions() {
  const document = {
    body: new FakeElement('body'),
    createElement: (tagName) => new FakeElement(tagName),
    getElementById(id) {
      return findById(this.body, id);
    },
  };
  const context = { document, Event: FakeEvent };
  context.globalThis = context;
  vm.createContext(context);

  const coreFilename = path.join(__dirname, '..', 'public', 'modules', '00-core.js');
  const coreSource = fs.readFileSync(coreFilename, 'utf8');
  const populateStart = coreSource.indexOf('function populateSelectOptions');
  const populateEnd = coreSource.indexOf('function normalizeTemplateTargetPrinterModel');
  assert.ok(populateStart >= 0 && populateEnd > populateStart, 'select population helper must remain extractable');
  vm.runInContext(coreSource.slice(populateStart, populateEnd), context, { filename: coreFilename });

  const inputsFilename = path.join(__dirname, '..', 'public', 'modules', '50-inputs.js');
  const inputsSource = fs.readFileSync(inputsFilename, 'utf8');
  const menuStart = inputsSource.indexOf('let activeCustomSelect = null;');
  const menuEnd = inputsSource.indexOf('function openCustomSelect');
  assert.ok(menuStart >= 0 && menuEnd > menuStart, 'custom select menu builder must remain extractable');
  vm.runInContext(inputsSource.slice(menuStart, menuEnd), context, { filename: inputsFilename });

  return {
    document,
    populateSelectOptions: context.populateSelectOptions,
    buildCustomSelectMenu: context.buildCustomSelectMenu,
  };
}

test('grouped custom select keeps semantic groups, compact labels, and raw values', () => {
  const api = loadGroupedSelectFunctions();
  const select = api.document.createElement('select');
  const initialValue = 'DataFlex 6330(32mm)';
  const nextValue = 'DataFlex 6330(53mm)';
  const items = [
    {
      value: initialValue,
      label: 'DataFlex 6330 (32 mm)',
      groupLabel: '32 mm',
      menuLabel: 'DataFlex 6330',
    },
    {
      value: 'DataFlex 6530(53mm)',
      label: 'DataFlex 6530 (53 mm)',
      groupLabel: '53 mm',
      menuLabel: 'DataFlex 6530',
    },
    {
      value: nextValue,
      label: 'DataFlex 6330 (53 mm)',
      groupLabel: '53 mm',
      menuLabel: 'DataFlex 6330',
    },
  ];

  api.populateSelectOptions(select, items, initialValue);
  assert.deepEqual(select.children.map((group) => group.label), ['32 mm', '53 mm']);

  let changeCount = 0;
  let lastChangeEvent = null;
  select.addEventListener('change', (event) => {
    changeCount += 1;
    lastChangeEvent = event;
  });

  api.buildCustomSelectMenu(select);
  const menu = api.document.getElementById('customSelectMenu');
  assert.ok(menu, 'custom listbox must be created');
  assert.equal(menu.getAttribute('role'), 'listbox');

  const groups = menu.children;
  assert.deepEqual(groups.map((group) => group.getAttribute('aria-label')), ['32 mm', '53 mm']);
  for (const group of groups) {
    assert.equal(group.tagName, 'DIV');
    assert.equal(group.getAttribute('role'), 'group');
    assert.equal(group.listenerCount('click'), 0, 'group containers must not be interactive');

    const heading = group.children[0];
    assert.equal(heading.tagName, 'DIV');
    assert.equal(heading.className, 'customSelectGroup__label');
    assert.equal(heading.getAttribute('aria-hidden'), 'true');
    assert.equal(heading.listenerCount('click'), 0, 'group headings must not be interactive');
  }

  const optionButtons = groups.flatMap((group) => group.children.slice(1));
  assert.equal(optionButtons.length, items.length);
  optionButtons.forEach((button) => {
    assert.equal(button.tagName, 'BUTTON');
    assert.equal(button.getAttribute('role'), 'option');
  });
  assert.deepEqual(
    optionButtons.map((button) => button.textContent),
    ['DataFlex 6330', 'DataFlex 6530', 'DataFlex 6330'],
    'the visible menu uses compact labels',
  );

  const targetButton = optionButtons.find((button) => button.getAttribute('aria-label') === 'DataFlex 6330 (53 mm)');
  assert.ok(targetButton, 'formatted accessible label must identify the target option');
  targetButton.dispatchEvent(new FakeEvent('click'));

  assert.equal(select.value, nextValue, 'selection must retain the exact raw CIFF model value');
  assert.equal(changeCount, 1, 'one selection must dispatch exactly one change event');
  assert.equal(lastChangeEvent?.bubbles, true);
});
