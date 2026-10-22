const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const test = require('node:test');
const vm = require('node:vm');

const root = path.join(__dirname, '..');
const read = (...segments) => fs.readFileSync(path.join(root, ...segments), 'utf8');

const component = read('src', 'components', 'TopBar.tsx');
const tabs = read('public', 'modules', '70-template-tabs.js');
const styles = read('public', 'styles.css');

function assertSourceMatch(source, pattern, message = `Expected source to match ${pattern}`) {
  assert.ok(pattern.test(source), message);
}

function assertSourceLacks(source, pattern, message = `Expected source not to match ${pattern}`) {
  assert.ok(!pattern.test(source), message);
}

function extractBalancedBlock(source, marker, label = marker) {
  const markerIndex = source.indexOf(marker);
  assert.ok(markerIndex >= 0, `${label} must exist`);
  const blockStart = source.indexOf('{', markerIndex + marker.length);
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
  const bodyStart = source.indexOf('{', parametersEnd);
  let bodyDepth = 0;
  for (let index = bodyStart; index < source.length; index += 1) {
    if (source[index] === '{') bodyDepth += 1;
    if (source[index] !== '}') continue;
    bodyDepth -= 1;
    if (bodyDepth === 0) return source.slice(markerIndex, index + 1);
  }
  assert.fail(`${name} must have a balanced body`);
}

test('TopBar preserves editor control IDs and removes decorative outer capsules', () => {
  const ids = [
    'btnNewTemplate', 'btnOpenFile', 'btnSave', 'btnUndo', 'btnRedo',
    'toggleGrid', 'toggleSnap', 'toggleAlign', 'zoomOut', 'zoomRange',
    'zoomIn', 'zoomLabel', 'topbarDocumentTitle', 'topbarDocumentDirty',
    'topbarDocumentMeta'
  ];
  for (const id of ids) {
    assert.equal((component.match(new RegExp(`id=["']${id}["']`, 'g')) || []).length, 1, `${id} must exist once`);
  }

  assertSourceMatch(component, /className="brand"/, 'Brand must remain a lightweight inline element');
  assertSourceLacks(component, /className="brand\s+surface-card"/, 'Brand must not be wrapped as a surface card');
  assertSourceLacks(component, /brand__icon|id="logo"|azm_24dp\.svg/, 'Brand icon must be removed completely');
  assertSourceLacks(styles, /\.brand__icon/, 'Brand icon styles must be removed completely');
  assertSourceMatch(component, /className="utilityGroup utilityGroup--history"/, 'Undo and Redo must share a semantic history group');
  assertSourceLacks(component, /className="utilityGroup\s+surface-card"/, 'Undo and Redo must not retain the old capsule');
  assertSourceMatch(component, /className="topbarDivider"/, 'History controls must be followed by a divider');
  assertSourceMatch(component, /<span className="topbarDivider topbarDivider--document" aria-hidden="true" \/>[\s\S]*<div className="topbarDocument"/, 'Primary actions and document information must be visually separated');
});

test('Topbar document info reads the active tab, canonical metadata and existing dirty state', () => {
  const elements = new Map(['topbarDocumentTitle', 'topbarDocumentDirty', 'topbarDocumentMeta'].map((id) => [id, {
    textContent: '', title: '', hidden: false, attributes: {},
    setAttribute(name, value) { this.attributes[name] = String(value); }
  }]));
  const context = {
    document: { getElementById: (id) => elements.get(id) || null },
    EMPTY_TEMPLATE_PRINT_MODES: ['Intermittent', 'Continuous'],
    state: { docMeta: { printerModel: 'DataFlex 6320(32mm)', printMode: 'Continuous', designedFor: '' } },
    tabsState: { activeTabId: 'active', tabs: [{ id: 'active', title: 'NEW_OCH', isDirty: true }] },
    t: (key) => ({ 'tabs.untitled': 'New template', 'tabs.unsaved': 'Unsaved changes' }[key] || key)
  };
  context.globalThis = context;
  vm.createContext(context);
  vm.runInContext([
    extractFunction(tabs, 'getActiveTemplateTab'),
    extractFunction(tabs, 'getTopbarPrinterDetails'),
    extractFunction(tabs, 'updateTopbarDocumentInfo'),
    'globalThis.runTopbarSync = updateTopbarDocumentInfo;'
  ].join('\n'), context);

  context.runTopbarSync();
  assert.equal(elements.get('topbarDocumentTitle').textContent, 'NEW_OCH');
  assert.equal(elements.get('topbarDocumentMeta').textContent, 'DataFlex 6320 · 32 mm · Continuous');
  assert.equal(elements.get('topbarDocumentDirty').hidden, false);
  assert.equal(elements.get('topbarDocumentDirty').attributes['aria-hidden'], 'false');
  assert.equal(elements.get('topbarDocumentDirty').attributes['aria-label'], 'Unsaved changes');

  context.tabsState.tabs[0].isDirty = false;
  context.state.docMeta = { printerModel: 'Vendor Printer', printMode: 'Unknown', designedFor: '' };
  context.runTopbarSync();
  assert.equal(elements.get('topbarDocumentMeta').textContent, 'Vendor Printer', 'Unknown modes must not be invented in the toolbar');
  assert.equal(elements.get('topbarDocumentDirty').hidden, true);
});

test('Desktop topbar is compact, single-row and uses stateful segmented toggles', () => {
  assertSourceMatch(styles, /\.topbar\s*\{[^}]*--topbar-gap:\s*16px;[^}]*min-height:\s*66px;[^}]*flex:\s*0\s+0\s+auto;[^}]*justify-content:\s*flex-start;[^}]*gap:\s*var\(--topbar-gap\);[^}]*padding:\s*var\(--app-topbar-padding\)\s+16px;/s);
  assertSourceMatch(styles, /\.topbarDocument\s*\{[^}]*flex:\s*0\s+1\s+380px;[^}]*margin-right:\s*auto;/s, 'Document information must stay next to primary actions while utilities remain right-aligned');
  assertSourceMatch(styles, /\.topbarDivider--document\s*\{[^}]*margin-inline:\s*calc\(8px\s*-\s*var\(--topbar-gap\)\);/s, 'Document divider must keep balanced spacing at responsive topbar gaps');
  assertSourceMatch(styles, /\.topbarAction\s*\{[^}]*min-height:\s*40px;[^}]*border-radius:\s*14px;/s);
  assertSourceMatch(styles, /\.topbar #btnSave\s*\{[^}]*background:\s*var\(--app-state-selected\);[^}]*color:\s*var\(--md-sys-color-on-primary-container\);/s);
  assertSourceMatch(styles, /\.utilityGroup--history\s*\{[^}]*padding:\s*0;[^}]*border:\s*0;[^}]*background:\s*transparent;/s);
  assertSourceMatch(styles, /\.utilityGroup--toggles\s*\{[^}]*padding:\s*3px;[^}]*border-radius:\s*20px;/s);
  assertSourceMatch(styles, /\.utilityToggle input\[type="checkbox"\]\s*\{[^}]*position:\s*absolute;[^}]*width:\s*1px;[^}]*opacity:\s*0;/s);
  assertSourceMatch(styles, /\.utilityToggle:has\(input\[type="checkbox"\]:checked\)\s*\{[^}]*background:\s*var\(--app-state-selected\);[^}]*color:\s*var\(--md-sys-color-on-primary-container\);/s);
  assertSourceLacks(styles, /\.utilityToggle(?::has\([^)]*checked[^)]*\))?::before\s*\{[^}]*content:\s*["']✓["'];/s, 'Selected utility toggles must not render decorative checkmarks');
  assertSourceMatch(styles, /\.zoom\s*\{[^}]*width:\s*248px;[^}]*min-height:\s*46px;[^}]*border-radius:\s*20px;/s);

  const mediumDesktop = extractBalancedBlock(styles, '@media (max-width: 1440px)', '1440px topbar rules');
  assertSourceLacks(mediumDesktop, /\.topbar\s*\{[^}]*flex-direction:\s*column;/s, '1366px desktop must remain one row');
  const compactDesktop = extractBalancedBlock(styles, '@media (max-width: 1280px)', '1280px topbar rules');
  assertSourceMatch(compactDesktop, /\.topbarDocument__meta\s*\{[^}]*display:\s*none;/s, 'Document secondary metadata must be the first content reduced');
});

test('Highlighted application and panel headings use the bundled Playfair Display font', () => {
  assert.ok(fs.existsSync(path.join(root, 'public', 'resourses', 'Fonts', 'PlayfairDisplay.ttf')), 'Playfair Display font file must be bundled');
  assertSourceMatch(styles, /@font-face\s*\{[^}]*font-family:\s*"Playfair Display";[^}]*src:\s*url\("\.\/resourses\/Fonts\/PlayfairDisplay\.ttf"\)\s*format\("truetype"\);/s);
  assertSourceMatch(styles, /\.brand__title,\s*\.leftPanel__title,\s*\.leftPanel__addSectionTitle,\s*\.inspectorHeader__title\s*\{[^}]*font-family:\s*var\(--app-heading-font\);/s);
});

test('Template tab rendering synchronizes the document summary on every title or dirty update', () => {
  const render = extractFunction(tabs, 'renderTemplateTabs');
  assertSourceMatch(render, /updateTopbarDocumentInfo\(\);[\s\S]*if \(!elTemplateTabsList\) return;/, 'Document info must update even without the tabs list');
  assertSourceMatch(tabs, /function markActiveTemplateTabDirty\([\s\S]*tab\.isDirty = true;[\s\S]*renderTemplateTabs\(\);/, 'Existing dirty-state changes must drive the same render path');
});
