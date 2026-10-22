const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const test = require('node:test');
const vm = require('node:vm');

const read = (name) => fs.readFileSync(path.join(__dirname, '../public/modules', name), 'utf8');
const ui = read('10-canvas-ui.js');
const inputs = read('50-inputs.js');

function eventTarget() {
  const handlers = new Map();
  return {
    addEventListener(type, handler) {
      if (!handlers.has(type)) handlers.set(type, []);
      handlers.get(type).push(handler);
    },
    dispatch(type, event = {}) {
      for (const handler of handlers.get(type) || []) handler(event);
    },
  };
}

test('host resize coalesces layout events, keeps stage geometry, and avoids resize feedback', () => {
  const window = Object.assign(eventTarget(), { visualViewport: eventTarget() });
  const frames = [];
  const hostRect = { width: 320, height: 350 };
  let stageSize = { width: 320, height: 350 };
  let resizeCount = 0;
  let drawCount = 0;
  let rulerCount = 0;
  let observer;
  const stage = {
    x: 37, y: -18, scale: 1.4,
    size(value) { if (value) { stageSize = value; resizeCount++; } return stageSize; },
    batchDraw() { drawCount++; },
  };
  const host = { getBoundingClientRect: () => hostRect };
  const context = vm.createContext({
    window, stage, elCanvasHost: host,
    requestAnimationFrame: (callback) => { frames.push(callback); return frames.length; },
    renderRulers: () => { rulerCount++; },
    ResizeObserver: class {
      constructor(callback) { this.callback = callback; observer = this; }
      observe(target) { assert.equal(target, host); }
    },
  });
  vm.runInContext(ui.slice(ui.indexOf('let canvasResizeFrame'), ui.indexOf('function refreshCanvasSizeAfterPanelMove()')), context);
  context.initCanvasHostResize();
  observer.callback();
  window.dispatch('resize');
  window.visualViewport.dispatch('resize');
  assert.equal(frames.length, 1);
  frames.shift()();
  assert.equal(resizeCount, 0);
  assert.equal(rulerCount, 1, 'same-size window/DPR changes still refresh rulers');

  hostRect.height = 275;
  observer.callback();
  observer.callback();
  assert.equal(frames.length, 1);
  frames.shift()();
  assert.equal(stageSize.height, 275);
  assert.equal(resizeCount, 1);
  assert.equal(drawCount, 1);
  observer.callback();
  frames.shift()();
  assert.equal(resizeCount, 1, 'unchanged observer notification must not resize again');
  assert.equal(rulerCount, 2);
  assert.deepEqual([stage.x, stage.y, stage.scale], [37, -18, 1.4]);

  hostRect.height = 0;
  observer.callback();
  frames.shift()();
  assert.equal(stageSize.height, 275, 'a temporarily hidden host must not zero the stage');
});

function positionMenu(rect, viewport = {}, preferredHeight = 240) {
  const style = {};
  const menu = {
    style,
    get offsetHeight() { return Math.min(preferredHeight, Number.parseFloat(style.maxHeight) || 0); },
  };
  const window = { innerWidth: 1280, innerHeight: 720, ...viewport };
  const context = vm.createContext({ window, getCustomSelectMenu: () => menu });
  vm.runInContext(inputs.slice(inputs.indexOf('function positionCustomSelectMenu('), inputs.indexOf('function syncCustomSelectControl(')), context);
  context.positionCustomSelectMenu({ _customSelectRoot: {}, _customSelectButton: { getBoundingClientRect: () => rect } });
  return Object.fromEntries(Object.entries(style).map(([key, value]) => [key, Number.parseFloat(value)]));
}

test('select menus stay inside narrow and visual viewports while preserving desktop sizing', () => {
  const desktop = positionMenu({ left: 1080, top: 90, bottom: 134, width: 70 });
  assert.equal(desktop.width, 120);
  assert.equal(desktop.left, 1080);
  assert.equal(desktop.top, 138);
  const phone = positionMenu({ left: 20, top: 250, bottom: 294, width: 380 }, { innerWidth: 320, innerHeight: 568 });
  assert.equal(phone.width, 304);
  assert.equal(phone.left, 8);
  assert.ok(phone.left + phone.width <= 312);
  assert.ok(phone.top + phone.maxHeight <= 560);
  const visual = positionMenu({ left: 16, top: 340, bottom: 384, width: 300 }, {
    visualViewport: { offsetLeft: 20, offsetTop: 200, width: 240, height: 210 },
  });
  assert.equal(visual.left, 28);
  assert.equal(visual.width, 224);
  assert.ok(visual.top >= 208);
  assert.ok(visual.top + visual.maxHeight <= 402);
  const shortAbove = positionMenu({ left: 90, top: 670, bottom: 714, width: 220 }, {}, 90);
  assert.equal(shortAbove.top, 576, 'short menus keep their four-pixel anchor gap above');
});

function drawerHarness() {
  const document = Object.assign(eventTarget(), { activeElement: null });
  const elements = new Map();
  class Element {
    constructor(id, { focusable = false, hidden = false, classes = [], tagName = 'BUTTON' } = {}) {
      Object.assign(this, eventTarget(), { id, focusable, hidden, tagName, inert: false, children: [], parentNode: null, tabIndex: focusable ? 0 : -1 });
      this.classes = new Set(classes);
      this.classList = {
        contains: (value) => this.classes.has(value),
        toggle: (value, enabled) => enabled ? this.classes.add(value) : this.classes.delete(value),
      };
      this.attributes = new Map();
      elements.set(id, this);
    }
    get nextSibling() {
      const siblings = this.parentNode?.children || [];
      return siblings[siblings.indexOf(this) + 1] || null;
    }
    appendChild(child) { this.insertBefore(child, null); }
    insertBefore(child, before) {
      if (child.parentNode) child.parentNode.children.splice(child.parentNode.children.indexOf(child), 1);
      const index = before ? this.children.indexOf(before) : this.children.length;
      assert.ok(index >= 0, 'original panel anchor still belongs to its parent');
      this.children.splice(index, 0, child);
      child.parentNode = this;
    }
    getClientRects() {
      let node = this;
      while (node) { if (node.hidden || node.classes.has('hidden')) return []; node = node.parentNode; }
      return [{}];
    }
    closest(selector) {
      let node = this;
      while (node) {
        if ((selector === '[inert]' && node.inert) || (selector === 'button' && node.focusable)
          || (selector.startsWith('.') && node.classes.has(selector.slice(1)))) return node;
        node = node.parentNode;
      }
      return null;
    }
    querySelectorAll(selector) {
      return this.children.flatMap((child) => [
        ...(child.focusable && (child.tagName !== 'SUMMARY' || selector.includes('summary')) ? [child] : []),
        ...child.querySelectorAll(selector),
      ]);
    }
    setAttribute(key, value) { this.attributes.set(key, value); }
    focus(options) { document.activeElement = this; document.lastFocusOptions = options; }
  }
  const body = new Element('body');
  const topbar = new Element('topbar');
  const app = new Element('app');
  const canvas = new Element('canvas');
  const right = new Element('right');
  const left = new Element('left');
  const menu = new Element('mobilePanelMenu', { hidden: true });
  const overlay = new Element('mobilePanelMenuOverlay', { hidden: true });
  const toggle = new Element('mobilePanelMenuToggle', { focusable: true });
  const close = new Element('mobilePanelMenuClose', { focusable: true });
  const rightSlot = new Element('mobileRightPanelSlot');
  const leftSlot = new Element('mobileLeftPanelSlot');
  const property = new Element('property', { focusable: true });
  const advanced = new Element('advanced', { focusable: true, tagName: 'SUMMARY' });
  const object = new Element('object', { focusable: true });
  const portal = new Element('inspectorAppSettings', { hidden: true });
  const setting = new Element('setting', { focusable: true });
  const modal = new Element('modal', { hidden: true });
  const modalAction = new Element('modalAction', { focusable: true });
  for (const node of [topbar, app, menu, overlay, modal]) body.appendChild(node);
  topbar.appendChild(toggle);
  for (const node of [left, canvas, right, portal]) app.appendChild(node);
  for (const node of [close, rightSlot, leftSlot]) menu.appendChild(node);
  right.appendChild(property); right.appendChild(advanced); left.appendChild(object); portal.appendChild(setting); modal.appendChild(modalAction);
  document.body = body;
  document.querySelector = (selector) => ({ '.topbar': topbar, '.canvasWrap': canvas, '.panel--right': right, '.panel--left': left }[selector]);
  document.querySelectorAll = (selector) => selector === '.modal' ? [modal] : [];
  const mobileQuery = Object.assign(eventTarget(), { matches: true });
  const context = vm.createContext({
    document, window: { matchMedia: () => mobileQuery }, $: (id) => elements.get(id),
    refreshCanvasSizeAfterPanelMove() {}, scheduleCanvasHostResize() {},
    closeCustomSelect() {}, closeInspectorObjectMenu() {}, closeLeftAddObjectPopover() {},
    closeInspectorAppSettings() { portal.hidden = true; },
  });
  vm.runInContext(ui.slice(ui.indexOf('function initMobilePanelMenu()'), ui.indexOf('function activateInspectorTab(')), context);
  context.initMobilePanelMenu();
  toggle.focus();
  const key = (value, shiftKey = false) => {
    const event = { key: value, shiftKey, prevented: false, preventDefault() { this.prevented = true; } };
    document.dispatch('keydown', event);
    return event;
  };
  return { document, topbar, app, canvas, right, left, menu, toggle, close, property, advanced, object, portal, setting, modal, modalAction, mobileQuery, key };
}

test('drawer reuses panels, isolates the background, and restores focus without disabling portals', () => {
  const h = drawerHarness();
  assert.equal(h.right.parentNode.id, 'mobileRightPanelSlot');
  assert.equal(h.left.parentNode.id, 'mobileLeftPanelSlot');
  h.toggle.dispatch('click');
  assert.equal(h.document.activeElement, h.close);
  assert.equal(h.topbar.inert, true);
  assert.equal(h.canvas.inert, true);
  assert.equal(h.app.inert, false);
  assert.equal(h.document.body.classList.contains('mobile-panels-open'), true);
  h.key('Tab', true);
  assert.equal(h.document.activeElement, h.object);
  h.portal.hidden = false;
  h.key('Tab');
  assert.equal(h.document.activeElement, h.setting, 'drawer portals participate in keyboard navigation');
  h.key('Escape');
  assert.equal(h.menu.inert, false, 'Escape in a higher popup must not close the drawer');
  h.close.dispatch('click');
  assert.equal(h.portal.hidden, true);
  assert.equal(h.topbar.inert, false);
  assert.equal(h.canvas.inert, false);
  assert.equal(h.document.activeElement, h.toggle);
  assert.equal(h.document.body.classList.contains('mobile-panels-open'), false);
});

test('modal and canvas-placement focus survive drawer close, and breakpoint changes restore original nodes', () => {
  const h = drawerHarness();
  h.toggle.dispatch('click');
  h.modal.hidden = false;
  h.modalAction.focus();
  h.key('Tab');
  assert.equal(h.document.activeElement, h.modalAction);
  h.key('Escape');
  assert.equal(h.menu.inert, false, 'modal Escape is left to the modal handler');
  h.close.dispatch('click');
  assert.equal(h.document.activeElement, h.modalAction);
  h.modal.hidden = true;
  h.toggle.dispatch('click');
  h.property.focus();
  h.document.dispatch('ciff:canvas-placement-started');
  assert.equal(h.document.activeElement, h.property, 'placement dismissal does not focus the toolbar');
  h.toggle.dispatch('click');
  h.mobileQuery.matches = false;
  h.mobileQuery.dispatch('change');
  assert.equal(h.menu.hidden, true);
  assert.equal(h.canvas.inert, false);
  assert.equal(h.document.body.classList.contains('mobile-panels-open'), false);
  assert.deepEqual(h.app.children.map((node) => node.id), ['left', 'canvas', 'right', 'inspectorAppSettings']);
  assert.equal(h.right.parentNode, h.app);
  assert.equal(h.left.parentNode, h.app);
});

test('drawer Tab reaches native disclosure summaries and permits scrolling focused controls into view', () => {
  const h = drawerHarness();
  h.toggle.dispatch('click');
  assert.equal(h.document.lastFocusOptions.preventScroll, true, 'opening preserves the current scroll position');
  h.property.focus();
  h.key('Tab');
  assert.equal(h.document.activeElement, h.advanced);
  assert.equal(h.document.lastFocusOptions, undefined, 'Tab uses native focus scrolling for offscreen fields');
  h.key('Tab');
  assert.equal(h.document.activeElement, h.object);
  assert.equal(h.document.lastFocusOptions, undefined);
  h.close.dispatch('click');
  assert.equal(h.document.activeElement, h.toggle);
  assert.equal(h.document.lastFocusOptions.preventScroll, true, 'closing preserves focus restoration behavior');
});
