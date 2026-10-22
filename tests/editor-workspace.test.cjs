const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const test = require('node:test');

const root = path.join(__dirname, '..');
const read = (...segments) => fs.readFileSync(path.join(root, ...segments), 'utf8');

const component = read('src', 'components', 'CanvasWorkspace.tsx');
const canvasUi = read('public', 'modules', '10-canvas-ui.js');
const styles = read('public', 'styles.css');

function extractBalancedBlock(source, marker, label = marker) {
  const markerIndex = source.indexOf(marker);
  assert.ok(markerIndex >= 0, `${label} must exist`);
  const blockStart = source.indexOf('{', markerIndex);
  assert.ok(blockStart >= 0, `${label} must have a block`);
  let depth = 0;
  for (let index = blockStart; index < source.length; index += 1) {
    if (source[index] === '{') depth += 1;
    if (source[index] !== '}') continue;
    depth -= 1;
    if (depth === 0) return source.slice(markerIndex, index + 1);
  }
  assert.fail(`${label} block must be balanced`);
}

function extractBalancedBlocks(source, marker) {
  const blocks = [];
  let offset = 0;
  while (offset < source.length) {
    const markerIndex = source.indexOf(marker, offset);
    if (markerIndex < 0) break;
    const block = extractBalancedBlock(source.slice(markerIndex), marker);
    blocks.push(block);
    offset = markerIndex + block.length;
  }
  return blocks;
}

test('central editor keeps its functional regions while removing the outer card class', () => {
  assert.match(component, /className="canvasWrap editorWorkspace"/);
  assert.doesNotMatch(component, /className="canvasWrap surface-card"/);

  const orderedMarkers = [
    '<TemplateTabs />',
    'className="canvasViewport"',
    'id="rulerTop"',
    'id="rulerLeft"',
    'id="canvasHost"',
    'className="statusbar"',
    'id="statusLeft"',
    'id="statusRight"',
  ];
  let previousIndex = -1;
  for (const marker of orderedMarkers) {
    const index = component.indexOf(marker);
    assert.ok(index > previousIndex, `${marker} must remain in editor order`);
    previousIndex = index;
  }
});

test('only the central workspace is flattened and shared surface cards remain intact', () => {
  const surfaceCard = extractBalancedBlock(styles, '.surface-card {');
  assert.match(surfaceCard, /background:\s*var\(--md-sys-color-surface-container\)/);
  assert.match(surfaceCard, /border:\s*1px solid/);
  assert.match(surfaceCard, /border-radius:\s*var\(--app-radius-md\)/);
  assert.match(surfaceCard, /box-shadow:\s*var\(--app-shadow-1\)/);

  const workspace = extractBalancedBlock(styles, '.canvasWrap {');
  assert.match(workspace, /--editor-radius:\s*0px/);
  assert.match(workspace, /gap:\s*0/);
  assert.match(workspace, /padding:\s*0/);
  assert.match(workspace, /border:\s*0/);
  assert.match(workspace, /border-radius:\s*var\(--editor-radius\)/);
  assert.match(workspace, /background:\s*transparent/);
  assert.match(workspace, /box-shadow:\s*none/);
});

test('tabs use a flat bar with transparent inactive tabs and a tonal active tab', () => {
  const tabs = extractBalancedBlock(styles, '.templateTabs {');
  const tab = extractBalancedBlock(styles, '.templateTab {');
  const activeTab = extractBalancedBlock(styles, '.templateTab.is-active {');
  const tabList = extractBalancedBlock(styles, '.templateTabs__list {');

  assert.match(tabs, /height:\s*var\(--editor-tabs-height\)/);
  assert.match(tabs, /border:\s*0/);
  assert.match(tabs, /border-bottom:\s*1px solid var\(--editor-divider\)/);
  assert.match(tabs, /border-radius:\s*var\(--editor-radius\)/);
  assert.match(tabs, /box-shadow:\s*none/);

  assert.match(tab, /height:\s*38px/);
  assert.match(tab, /border:\s*0/);
  assert.match(tab, /border-radius:\s*12px/);
  assert.match(tab, /background:\s*transparent/);
  assert.match(activeTab, /background:\s*var\(--app-state-selected\)/);

  assert.match(tabList, /overflow-x:\s*auto/);
  assert.match(tabList, /scroll-snap-type:\s*inline mandatory/);
  assert.match(tabList, /cursor:\s*grab/);
});

test('workspace, integrated rulers, and status bar form one rectangular hierarchy', () => {
  const viewport = extractBalancedBlock(styles, '.canvasViewport {');
  const rulerCorner = extractBalancedBlock(styles, '.rulerCorner {');
  const rulerTop = extractBalancedBlock(styles, '.rulerCanvas--top {');
  const rulerLeft = extractBalancedBlock(styles, '.rulerCanvas--left {');
  const statusbar = extractBalancedBlock(styles, '.statusbar {');

  assert.match(viewport, /grid-template-columns:\s*var\(--editor-ruler-left-width\)/);
  assert.match(viewport, /grid-template-rows:\s*var\(--editor-ruler-top-height\)/);
  assert.match(viewport, /border-radius:\s*var\(--editor-radius\)/);
  assert.match(viewport, /border:\s*0/);
  assert.match(viewport, /box-shadow:\s*none/);

  assert.match(rulerCorner, /border-radius:\s*0/);
  assert.match(rulerCorner, /border-right:\s*1px solid var\(--ruler-divider\)/);
  assert.match(rulerCorner, /border-bottom:\s*1px solid var\(--ruler-divider\)/);
  assert.match(rulerTop, /border:\s*0/);
  assert.match(rulerTop, /box-shadow:\s*none/);
  assert.match(rulerLeft, /border:\s*0/);
  assert.match(rulerLeft, /box-shadow:\s*none/);

  assert.match(statusbar, /min-height:\s*var\(--editor-status-height\)/);
  assert.match(statusbar, /padding:\s*0 12px/);
  assert.match(statusbar, /border:\s*0/);
  assert.match(statusbar, /border-top:\s*1px solid var\(--editor-divider\)/);
  assert.match(statusbar, /border-radius:\s*var\(--editor-radius\)/);
  assert.match(statusbar, /box-shadow:\s*none/);
});

test('mobile keeps the flat editor and file drop still targets the workspace', () => {
  const mobile = extractBalancedBlocks(styles, '@media (max-width: 960px)')
    .find((block) => /\.canvasWrap\s*\{[\s\S]*?gap:\s*0/.test(block));
  assert.ok(mobile, 'effective mobile editor overrides must exist');
  assert.match(mobile, /\.canvasWrap\s*\{[^}]*gap:\s*0;[^}]*padding:\s*0;[^}]*border-radius:\s*0;/);
  assert.match(mobile, /\.canvasViewport\s*\{[^}]*grid-template-columns:\s*var\(--editor-ruler-left-width\) minmax\(0, 1fr\);[^}]*grid-template-rows:\s*var\(--editor-ruler-top-height\) minmax\(0, 1fr\);[^}]*border-radius:\s*0;/);
  assert.match(mobile, /\.statusbar\s*\{[^}]*padding:\s*0 8px;[^}]*border-radius:\s*0;/);

  assert.match(canvasUi, /document\.querySelector\("\.canvasWrap"\)/);
  assert.doesNotMatch(canvasUi, /document\.querySelector\("\.canvasWrap\.surface-card"\)/);
  assert.match(styles, /\.canvasWrap\.is-file-dragging::before/);
  assert.match(styles, /\.canvasWrap\.is-file-dragging\s+\.templateDropPrompt/);
});
