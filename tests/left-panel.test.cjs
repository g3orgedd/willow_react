const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

const root = path.join(__dirname, '..');
const read = (...segments) => fs.readFileSync(path.join(root, ...segments), 'utf8');

const component = read('src', 'components', 'LeftPanel.tsx');
const core = read('public', 'modules', '00-core.js');
const i18n = read('public', 'modules', '05-i18n.js');
const ui = read('public', 'modules', '10-canvas-ui.js');
const rendering = read('public', 'modules', '30-rendering.js');
const styles = read('public', 'styles.css');

function assertSourceMatch(source, pattern, message = `Expected source to match ${pattern}`) {
  assert.ok(pattern.test(source), message);
}

function assertSourceLacks(source, pattern, message = `Expected source not to match ${pattern}`) {
  assert.ok(!pattern.test(source), message);
}

function countMatches(source, pattern) {
  const flags = pattern.flags.includes('g') ? pattern.flags : `${pattern.flags}g`;
  return Array.from(source.matchAll(new RegExp(pattern.source, flags))).length;
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
  assert.ok(markerIndex >= 0, `function ${name} must exist`);
  const parametersStart = source.indexOf('(', markerIndex);
  let parametersDepth = 0;
  let parametersEnd = -1;
  for (let index = parametersStart; index < source.length; index += 1) {
    if (source[index] === '(') parametersDepth += 1;
    if (source[index] !== ')') continue;
    parametersDepth -= 1;
    if (parametersDepth === 0) {
      parametersEnd = index;
      break;
    }
  }
  assert.ok(parametersEnd >= 0, `function ${name} parameters must be balanced`);

  const bodyStart = source.indexOf('{', parametersEnd);
  assert.ok(bodyStart >= 0, `function ${name} must have a body`);
  let bodyDepth = 0;
  for (let index = bodyStart; index < source.length; index += 1) {
    if (source[index] === '{') bodyDepth += 1;
    if (source[index] !== '}') continue;
    bodyDepth -= 1;
    if (bodyDepth === 0) return source.slice(markerIndex, index + 1);
  }
  assert.fail(`function ${name} body must be balanced`);
}

function loadTranslations() {
  const context = { console };
  context.globalThis = context;
  vm.createContext(context);
  vm.runInContext(i18n, context, { filename: 'public/modules/05-i18n.js' });
  return context;
}

test('LeftPanel exposes an objects-first shell while preserving the legacy runtime IDs', () => {
  const requiredIds = [
    'leftPanel',
    'leftPanelExpanded',
    'fieldBrowserTitle',
    'btnToggleFieldSearch',
    'leftPanelSearch',
    'fieldSearch',
    'btnCloseFieldSearch',
    'btnShowHiddenOnCanvas',
    'fieldsList',
    'leftPanelAddSectionTitle',
    'btnCollapseLeftPanel',
    'btnAddObjectCollapsed',
    'btnExpandLeftPanel',
    'leftAddObjectPopover',
  ];

  for (const id of requiredIds) {
    assert.equal(countMatches(component, new RegExp(`id=["']${id}["']`)), 1, `${id} must exist exactly once`);
  }

  assertSourceMatch(component, /id=["']fieldBrowserTitle["'][^>]*>\s*Objects\s*</, 'Objects must be the panel heading');
  assertSourceMatch(component, /id=["']leftPanel["'][^>]*aria-labelledby=["']fieldBrowserTitle["']/, 'The panel must be named by its heading');
  assertSourceMatch(component, /className=["'][^"']*leftPanelTabs[^"']*["'][^>]*role=["']tablist["']/, 'Printed and Hidden must be one tab control');
  assertSourceMatch(component, /data-field-filter=["']printed["'][^>]*aria-selected=["']true["']/, 'Printed must be the initial tab');
  assertSourceMatch(component, /data-field-filter=["']hidden["'][^>]*aria-selected=["']false["']/, 'Hidden must share the same tab control');
  assertSourceMatch(component, /id=["']fieldsList["'][^>]*role=["']list["']/, 'The shared object list must expose list semantics');
  assertSourceLacks(component, /id=["']fields(?:Printed|Hidden)["']/, 'Printed and Hidden must not create duplicate object lists');
  const headerActionsStart = component.indexOf('className="leftPanel__headerActions"');
  const headerEnd = component.indexOf('</header>', headerActionsStart);
  const collapseButtonIndex = component.indexOf('id="btnCollapseLeftPanel"');
  assert.ok(collapseButtonIndex > headerActionsStart && collapseButtonIndex < headerEnd, 'Collapse must live in the top header actions');
  const headerSource = component.slice(headerActionsStart, headerEnd);
  assertSourceLacks(headerSource, /id=["']btnAddObject["']|add_24dp\.svg/, 'The expanded header must not retain an Add button');
  assert.equal(countMatches(component, /id=["']btnAddObject["']/), 0, 'Only the compact rail may expose a plus trigger');
  assertSourceLacks(component, /className=["']leftPanel__footer["']/, 'The collapse button must not leave a footer control behind');

  for (const id of [
    'fieldsList',
    'fieldSearch',
    'leftPanel',
    'leftPanelSearch',
    'btnCollapseLeftPanel',
    'btnExpandLeftPanel',
  ]) {
    assertSourceMatch(core, new RegExp(`\\$\\(["']${id}["']\\)`), `${id} must retain an eager runtime reference`);
  }
  assertSourceMatch(
    `${ui}\n${rendering}`,
    /\$\(["']btnShowHiddenOnCanvas["']\)/,
    'btnShowHiddenOnCanvas must retain its existing runtime lookup'
  );
});

test('LeftPanel header mirrors the Inspector header shell and controls', () => {
  assertSourceMatch(
    styles,
    /\.leftPanel__header\s*\{[^}]*position:\s*sticky;[^}]*top:\s*0;[^}]*z-index:\s*4;[^}]*min-height:\s*78px;[^}]*padding:\s*17px;[^}]*border-bottom:\s*1px solid[^}]*background:\s*color-mix\([^}]*surface-container[^}]*96%/s,
    'Left header must use the Inspector header geometry, divider, and surface'
  );
  assertSourceMatch(
    styles,
    /\.leftPanel__headerActions \.leftPanelIconButton\s*\{[^}]*border-color:\s*transparent;[^}]*border-radius:\s*var\(--app-radius-xxl\);[^}]*color:\s*var\(--md-sys-color-on-surface-variant\);/s,
    'Left header buttons must match Inspector header controls'
  );
  assertSourceLacks(
    styles,
    /@media\s*\(max-width:\s*480px\)[\s\S]*?\.leftPanel__header\s*\{[^}]*min-height:\s*52px;/s,
    'Mobile must not restore the former compact left-only header design'
  );
});

test('the permanent Add section and collapsed proxy popover remain separate surfaces', () => {
  const asideStartIndex = component.indexOf('<aside');
  const addSectionIndex = component.search(/className=["'][^"']*\bleftPanel__addSection\b[^"']*["']/);
  const listIndex = component.indexOf('id="fieldsList"');
  const asideEndIndex = component.indexOf('</aside>', asideStartIndex);
  const popoverIndex = component.indexOf('id="leftAddObjectPopover"');
  assert.ok(addSectionIndex > listIndex && addSectionIndex < asideEndIndex, 'The Add section must be docked after the list and inside the panel');
  assert.ok(popoverIndex > asideEndIndex, 'The collapsed Add popover must remain outside the panel shell');

  const addSectionSource = component.slice(addSectionIndex, asideEndIndex);
  const popoverSource = component.slice(popoverIndex);
  const addButtonIds = [
    'addDataMatrix',
    'addFixedText',
    'addDateText',
    'addTimeText',
    'addOffsetDateText',
    'addCounterText',
  ];

  for (const id of addButtonIds) {
    assert.equal(countMatches(component, new RegExp(`id=["']${id}["']`)), 1, `${id} must be preserved exactly once`);
    assertSourceMatch(addSectionSource, new RegExp(`id=["']${id}["']`), `${id} must be inside the permanent Add section`);
    assert.equal(
      countMatches(component, new RegExp(`data-add-object-target=["']${id}["']`)),
      1,
      `${id} must have exactly one ID-free proxy in the collapsed popover`
    );
    assertSourceMatch(
      popoverSource,
      new RegExp(`data-add-object-target=["']${id}["']`),
      `${id} must be represented by a proxy in the collapsed popover`
    );
    assertSourceMatch(ui, new RegExp(`\\$\\(["']${id}["']\\)\\.addEventListener\\(["']click["']`), `${id} must keep its existing click wiring`);
  }

  assertSourceLacks(
    popoverSource,
    new RegExp(`id=["'](?:${addButtonIds.join('|')})["']`),
    'Collapsed proxies must not duplicate the canonical creation-button IDs'
  );
  assertSourceMatch(component, /id=["']btnAddObjectCollapsed["'][^>]*aria-controls=["']leftAddObjectPopover["']/, 'The compact rail trigger must own the separate popover');
  assertSourceMatch(addSectionSource, /className=["'][^"']*toolgrid[^"']*leftPanelAddGrid[^"']*["']/, 'The canonical tools must share the permanent presentation grid');
  assertSourceMatch(popoverSource, /className=["'][^"']*toolgrid[^"']*leftPanelAddGrid[^"']*["']/, 'The proxy tools must share the popover presentation grid');
  const addSectionStyles = extractBalancedBlock(styles, '.leftPanel__addSection', 'permanent Add section styles');
  assertSourceMatch(addSectionStyles, /position:\s*static;/, 'The permanent Add section must stay in normal panel flow');
  assertSourceMatch(addSectionStyles, /flex:\s*0\s+0\s+auto;/, 'Expanded Add controls must remain a fixed-height bottom section');
  assertSourceMatch(styles, /\.leftPanel__addSection[^,{]*\.leftPanelAddGrid[^}]*\{[^}]*grid-template-columns:\s*repeat\(3,\s*minmax\(0,\s*1fr\)\);/s, 'The docked tools must use a compact three-column grid');
  assertSourceMatch(styles, /\.leftPanelAddPopover\s*\{[^}]*position:\s*fixed;/s, 'The collapsed Add surface must remain an anchored overlay');
  assertSourceMatch(
    styles,
    /(?:\.leftPanelAddPopover[^,{]*\.leftPanelAddGrid|\.leftPanelAddGrid\.toolgrid)\s*\{[^}]*grid-template-columns:\s*repeat\(2,\s*minmax\(0,\s*1fr\)\);/s,
    'The collapsed popover tools must keep their two-column layout'
  );
});

test('left-panel search preserves its query on Escape and clears it only through the close button', () => {
  const init = extractFunction(ui, 'initLeftPanelUi');
  const searchState = extractFunction(ui, 'setLeftPanelSearchOpen');
  const closeStart = init.indexOf('elBtnCloseFieldSearch');
  const collapseStart = init.indexOf('elBtnCollapseLeftPanel', closeStart);
  const closeHandler = init.slice(closeStart, collapseStart);
  const escapeStart = init.indexOf('window.addEventListener("keydown"');
  const resizeStart = init.indexOf('window.addEventListener("resize"', escapeStart);
  const escapeHandler = init.slice(escapeStart, resizeStart);

  assertSourceMatch(ui, /function\s+initLeftPanelUi\s*\(/, 'The focused left-panel initializer must exist');
  assertSourceMatch(ui, /\binitLeftPanelUi\s*\(\s*\)\s*;/, 'The left-panel initializer must run during UI startup');
  assertSourceMatch(searchState, /if\s*\(options\.clear\)\s*\{[\s\S]*?elSearch\.value\s*=\s*["']["'][\s\S]*?renderFieldLists\s*\(\s*\)/, 'Clear must be an explicit search option');
  assertSourceMatch(closeHandler, /setLeftPanelSearchOpen\(\s*false\s*,\s*\{[^}]*clear:\s*true[^}]*restoreFocus:\s*true[^}]*\}\s*\)/, 'The close button must clear and close search');
  assertSourceMatch(escapeHandler, /if\s*\(leftPanelSearchOpen\)[\s\S]*?setLeftPanelSearchOpen\(\s*false\s*,\s*\{[^}]*restoreFocus:\s*true[^}]*\}\s*\)/, 'Escape must close an open search');
  assertSourceLacks(escapeHandler, /clear\s*:/, 'Escape must preserve a non-empty search query');
  assertSourceMatch(ui, /elSearch\.addEventListener\(["']input["']\s*,[\s\S]{0,180}syncLeftPanelSearchQueryState\s*\(\s*\)[\s\S]{0,100}renderFieldLists\s*\(\s*\)/, 'The existing fieldSearch input must drive filtering');
});

test('collapsed Add proxies delegate to canonical buttons and dismiss the popover', () => {
  const init = extractFunction(ui, 'initLeftPanelUi');
  const proxyHandlerStart = init.indexOf('elLeftAddObjectPopover?.addEventListener("click"');
  const outsideHandlerStart = init.indexOf('document.addEventListener("pointerdown"', proxyHandlerStart);
  const proxyHandler = init.slice(proxyHandlerStart, outsideHandlerStart);

  assertSourceMatch(
    init,
    /elBtnAddObjectCollapsed\??\.addEventListener\(["']click["'][\s\S]{0,320}openLeftAddObjectPopover\(elBtnAddObjectCollapsed\)/,
    'Only the compact rail plus button must open the adaptive Add surface as a popover'
  );
  assertSourceLacks(init, /elBtnAddObject\??\.addEventListener\(["']click["']/, 'Expanded desktop must not depend on an Add trigger');
  assert.ok(proxyHandlerStart >= 0 && outsideHandlerStart > proxyHandlerStart, 'The popover must delegate proxy clicks before outside-click handling');
  assertSourceMatch(proxyHandler, /closest\??\.\(["']\.toolButton["']\)/, 'Proxy actions must be resolved through event delegation');
  assertSourceMatch(proxyHandler, /dataset\.addObjectTarget/, 'The delegated action must read its canonical target ID');
  assertSourceMatch(
    proxyHandler,
    /(?:\$\(\s*targetId\s*\)|document\.getElementById\(\s*targetId\s*\))\??\.click\(\s*\)/,
    'A proxy action must invoke the matching canonical creation button'
  );
  assertSourceMatch(proxyHandler, /closeLeftAddObjectPopover\(\s*\{\s*restoreFocus:\s*false\s*\}\s*\)/, 'Choosing a proxy must close the Add object popover');
  assertSourceMatch(
    init,
    /document\.addEventListener\(["']pointerdown["'][\s\S]{0,520}!clickedTrigger\s*&&\s*!elLeftAddObjectPopover\.contains\(event\.target\)[\s\S]{0,120}closeLeftAddObjectPopover/,
    'A pointer press outside both trigger and popover must close it'
  );
  assertSourceMatch(
    init,
    /event\.key\s*!==\s*["']Escape["'][\s\S]{0,260}!elLeftAddObjectPopover\??\.classList\.contains\(["']hidden["']\)[\s\S]{0,180}closeLeftAddObjectPopover\(\s*\)/,
    'Escape must close the Add object popover first'
  );
  assertSourceMatch(init, /window\.addEventListener\(["']resize["']\s*,\s*\(\)\s*=>\s*closeLeftAddObjectPopover/, 'Viewport changes must dismiss the anchored popover');
});

test('desktop collapse uses localStorage and the existing canvas resize pipeline', () => {
  const readPreference = extractFunction(ui, 'readLeftPanelCollapsedPreference');
  const persistPreference = extractFunction(ui, 'persistLeftPanelCollapsedPreference');
  const applyState = extractFunction(ui, 'applyLeftPanelCollapsedState');
  const init = extractFunction(ui, 'initLeftPanelUi');

  assertSourceMatch(ui, /const\s+LEFT_PANEL_COLLAPSED_STORAGE_KEY\s*=\s*["']glyphXml\.leftPanelCollapsed["']/, 'The requested preference key must remain stable');
  assertSourceMatch(readPreference, /window\.localStorage\??\.getItem\(LEFT_PANEL_COLLAPSED_STORAGE_KEY\)/, 'Collapse state must restore from localStorage');
  assertSourceMatch(persistPreference, /window\.localStorage\??\.setItem\(LEFT_PANEL_COLLAPSED_STORAGE_KEY\s*,/, 'Collapse state must persist to localStorage');
  assertSourceLacks(`${readPreference}\n${persistPreference}`, /sessionStorage/, 'Left-panel preference must not be mixed with session-scoped Inspector state');
  assertSourceMatch(ui, /function\s+isLeftPanelCollapseAvailable\s*\(\)[\s\S]{0,180}\(min-width:\s*1121px\)/, 'Desktop collapse must be unavailable below the existing breakpoint');
  assertSourceMatch(applyState, /classList\.toggle\(["']leftPanel--collapsed["']\s*,\s*collapsed\)/, 'The panel must expose its collapsed visual state');
  assertSourceMatch(applyState, /data-left-panel-collapsed/, 'The app grid must receive the collapsed state');
  assertSourceMatch(applyState, /refreshCanvasSizeAfterPanelMove\s*\(\s*\)/, 'Collapse must reuse the existing Konva/ruler resize path');
  assertSourceMatch(ui, /function\s+refreshCanvasSizeAfterPanelMove\s*\(/, 'The shared panel-move resize helper must remain available');
  assertSourceMatch(init, /matchMedia\??\.\(["']\(min-width:\s*1121px\)["']\)[\s\S]{0,220}applyLeftPanelCollapsedState/, 'Breakpoint changes must reapply the effective state');
});

test('field rendering keeps one filtered list with localized human labels and type icons', () => {
  const presentation = extractFunction(rendering, 'getFieldListPresentation');
  const renderLists = extractFunction(rendering, 'renderFieldLists');

  assertSourceMatch(renderLists, /activeFieldFilter\s*===\s*["']printed["']\s*&&\s*field\.printed/, 'Printed filtering must keep using field.printed');
  assertSourceMatch(renderLists, /activeFieldFilter\s*===\s*["']hidden["']\s*&&\s*!field\.printed/, 'Hidden filtering must use the same list');
  assertSourceMatch(renderLists, /elSearch\.value[\s\S]{0,500}field\.name\.toLowerCase\(\)\.includes\(q\)/, 'The existing query must filter either active tab');
  assertSourceMatch(renderLists, /data-field-filter-count/, 'Both tab counts must be refreshed');
  assertSourceMatch(renderLists, /elFieldsList\.innerHTML\s*=\s*["']["']/, 'Only the shared fieldsList may be rebuilt');

  const expectedPresentations = [
    ['Barcode', 'datamatrix_24dp.svg', 'tool.datamatrix'],
    ['FixedText', 'text_fields_24dp.svg', 'field.fixedText'],
    ['DateText', 'calendar_month_24dp.svg', 'tool.date'],
    ['OffsetDateText', 'calendar_month_24dp.svg', 'field.offsetDate'],
    ['TimeText', 'clock_loader_24dp.svg', 'tool.time'],
    ['CounterText', 'decimal_increase_24dp.svg', 'tool.counter'],
  ];
  for (const [type, icon, key] of expectedPresentations) {
    assertSourceMatch(presentation, new RegExp(type), `${type} must have a sidebar presentation`);
    assertSourceMatch(presentation, new RegExp(icon.replace('.', '\\.')), `${type} must use ${icon}`);
    assertSourceMatch(presentation, new RegExp(`["']${key.replace('.', '\\.')}["']`), `${type} must use the ${key} translation`);
  }
  assertSourceMatch(presentation, /field\.barcode\.dataMatrix\.symbolSize/, 'DataMatrix size must come from existing field state');
  assertSourceMatch(presentation, /×/, 'DataMatrix dimensions must use a human-readable multiplication sign');
});

test('list rows use sibling buttons and one shared object menu for ellipsis and right click', () => {
  const makeListItem = extractFunction(rendering, 'makeListItem');
  const selectForMenu = extractFunction(rendering, 'selectFieldForListMenu');
  const menuClickStart = makeListItem.indexOf('menuButton.addEventListener("click"');
  const contextStart = makeListItem.indexOf('item.addEventListener("contextmenu"');
  const menuClick = makeListItem.slice(menuClickStart, contextStart);
  const contextMenu = makeListItem.slice(contextStart);

  assertSourceMatch(makeListItem, /const\s+item\s*=\s*document\.createElement\(["']div["']\)/, 'A row wrapper must not be a button');
  assertSourceMatch(makeListItem, /const\s+selectButton\s*=\s*document\.createElement\(["']button["']\)/, 'Selection must remain a native button');
  assertSourceMatch(makeListItem, /const\s+menuButton\s*=\s*document\.createElement\(["']button["']\)/, 'The ellipsis must be a separate native button');
  assertSourceMatch(makeListItem, /item\.appendChild\(selectButton\)[\s\S]{0,100}item\.appendChild\(menuButton\)/, 'Selection and ellipsis controls must be siblings');
  assertSourceLacks(makeListItem, /selectButton\.appendChild\(menuButton\)/, 'The row must never nest one button inside another');
  assertSourceLacks(makeListItem, /\bbadge\b/, 'Printed/Hidden badges must not be recreated per row');
  assertSourceMatch(makeListItem, /more_vert_24dp\.svg/, 'Each row must use the supplied overflow icon');

  assertSourceMatch(selectForMenu, /if\s*\(isFieldSelected\(field\.name\)\)\s*return\s+false/, 'Existing multi-selection must be retained');
  assertSourceMatch(selectForMenu, /setSelectedNames\(\[field\.name\],\s*field\.name\)/, 'An unselected context target must be selected first');
  assertSourceMatch(menuClick, /selectFieldForListMenu\(field\)[\s\S]{0,220}openInspectorObjectMenuAt\(/, 'Ellipsis must select first and open the shared object menu');
  assertSourceMatch(contextMenu, /event\.preventDefault\(\)/, 'Right click must suppress the browser menu');
  assertSourceMatch(contextMenu, /selectFieldForListMenu\(field\)[\s\S]{0,240}openInspectorObjectMenuAt\(event\.clientX,\s*event\.clientY/, 'Right click must select first and open the same menu at the pointer');
  assert.equal(countMatches(makeListItem, /openInspectorObjectMenuAt\s*\(/), 2, 'Both row entry points must reuse the shared Inspector menu');
});

test('new left-panel strings exist in both dictionaries and are wired to static controls', () => {
  const translations = loadTranslations();
  const requiredKeys = [
    'panel.tools.title',
    'panel.fields.title',
    'panel.fields.filter',
    'panel.printed.title',
    'panel.hidden.title',
    'panel.search.placeholder',
    'panel.closeSearch',
    'panel.collapse',
    'panel.expand',
    'panel.objectActions',
    'field.fixedText',
    'field.userEnteredText',
    'field.offsetDate',
  ];

  for (const language of ['en', 'ru']) {
    const dictionary = translations.UI_TRANSLATIONS[language];
    for (const key of requiredKeys) {
      assert.equal(typeof dictionary[key], 'string', `${language} must define ${key}`);
      assert.ok(dictionary[key].trim(), `${language}.${key} must not be empty`);
    }
  }

  assert.equal(translations.translateUi('panel.fields.title', {}, 'en'), 'Objects');
  assert.equal(translations.translateUi('panel.fields.title', {}, 'ru'), 'Объекты');
  assert.equal(translations.translateUi('panel.objectActions', { name: 'Field01' }, 'en'), 'Actions for Field01');
  assert.equal(translations.translateUi('panel.objectActions', { name: 'Field01' }, 'ru'), 'Действия для Field01');

  const expectedTargets = [
    ['#leftPanelAddSectionTitle', 'panel.tools.title'],
    ['#leftAddObjectPopoverTitle', 'panel.tools.title'],
    ['#btnAddObjectCollapsed', 'panel.tools.title'],
    ['#fieldBrowserTitle', 'panel.fields.title'],
    ['#fieldSearch', 'panel.search.placeholder'],
    ['#btnCloseFieldSearch', 'panel.closeSearch'],
    ['#btnCollapseLeftPanel', 'panel.collapse'],
    ['#btnExpandLeftPanel', 'panel.expand'],
  ];
  const translationTargets = translations.UI_TRANSLATION_TARGETS;
  const hasSelectorForKey = (selector, key) => translationTargets.some((target) => (
    target.key === key
    && target.selector.split(',').map((part) => part.trim()).includes(selector)
  ));
  for (const [selector, key] of expectedTargets) {
    assert.ok(hasSelectorForKey(selector, key), `${selector} must be translated with ${key}`);
  }

  const addTranslations = [
    ['addDataMatrix', 'tool.datamatrix'],
    ['addFixedText', 'tool.text'],
    ['addDateText', 'tool.date'],
    ['addTimeText', 'tool.time'],
    ['addOffsetDateText', 'tool.offset'],
    ['addCounterText', 'tool.counter'],
  ];
  for (const [id, key] of addTranslations) {
    assert.ok(hasSelectorForKey(`#${id} span`, key), `The permanent ${id} label must use ${key}`);
    assert.ok(
      hasSelectorForKey(`[data-add-object-target='${id}'] span`, key),
      `The collapsed ${id} proxy label must use ${key}`
    );
  }
  assert.ok(
    !translationTargets.some((target) => target.selector.split(',').map((part) => part.trim()).includes('#btnAddObject')),
    'Translations must not target a removed expanded Add trigger'
  );
});

test('CSS fixes the desktop panel at 288px, uses a 52–56px rail, and ignores collapse on narrow layouts', () => {
  const expanded = /--app-panel-left:\s*(\d+)px;/.exec(styles);
  const collapsed = /--app-panel-left-collapsed:\s*(\d+)px;/.exec(styles);
  assert.ok(expanded, 'Expanded panel width token must exist');
  assert.ok(collapsed, 'Collapsed panel width token must exist');
  assert.equal(Number(expanded[1]), 288, 'Expanded panel must use the requested 288px width');
  assert.ok(Number(collapsed[1]) >= 52 && Number(collapsed[1]) <= 56, 'Collapsed rail must stay within 52–56px');

  const leftPanelStyles = styles.slice(styles.indexOf('/* Objects-first left panel'));
  const desktop = extractBalancedBlock(leftPanelStyles, '@media (min-width: 1121px)', 'desktop left-panel media query');
  assertSourceMatch(desktop, /app--leftPanelCollapsed[\s\S]{0,260}--app-left-track:\s*minmax\([\s\S]{0,180}--app-panel-left-collapsed/, 'Collapsed desktop state must release the grid track');
  assertSourceMatch(desktop, /#leftPanel:is\([^)]*data-collapsed=["']true["'][^)]*\)[\s\S]{0,220}border-radius:/, 'The compact rail must have its own visible shell');
  assertSourceMatch(desktop, /\.listItem__main,[\s\S]{0,100}\.listItem__menu\s*\{\s*display:\s*none;/, 'Collapsed rows must keep only type icons');
  assertSourceMatch(
    desktop,
    /#leftPanel:is\([^)]*data-collapsed=["']true["'][^)]*\) \.leftPanel__addSection\s*\{[^}]*display:\s*none;/s,
    'The permanent Add section must be hidden while the separate collapsed popover is available'
  );

  assertSourceMatch(styles, /\.leftPanel__list\.list\s*\{[^}]*min-height:\s*0;[^}]*flex:\s*1\s+1\s+(?:auto|0);[^}]*overflow-y:\s*auto;/s, 'Only the object list must consume and scroll through remaining panel height');

  const narrow = extractBalancedBlock(leftPanelStyles, '@media (max-width: 1120px)', 'narrow left-panel media query');
  assertSourceMatch(narrow, /#leftPanel \.leftPanel__expanded\s*\{[^}]*display:\s*flex\s*!important;[^}]*opacity:\s*1\s*!important;[^}]*visibility:\s*visible\s*!important;/s, 'Narrow layouts must force the expanded panel content');
  assertSourceMatch(narrow, /\.leftPanel__collapsedActions,[\s\S]{0,140}\.leftPanel__expandButton\s*\{[^}]*display:\s*none\s*!important;/s, 'Desktop rail controls must stay out of the mobile drawer');

  const mobile = extractBalancedBlock(leftPanelStyles, '@media (max-width: 960px)', 'mobile left-panel media query');
  assertSourceMatch(mobile, /\.mobilePanelMenu #leftPanel \.leftPanel__list\s*\{[^}]*flex:\s*0\s+0\s+auto;[^}]*overflow:\s*visible;/s, 'The mobile drawer must grow with the object list instead of nesting a scroll viewport');
  assertSourceLacks(
    mobile,
    /\.mobilePanelMenu #leftPanel \.leftPanel__addSection\s*\{[^}]*(?:display:\s*none|position:\s*fixed)/s,
    'Mobile must inherit the visible, static Add section rather than the collapsed desktop state'
  );
});

test('Expanded left-panel content uses the same symmetric inset as inspectorBody', () => {
  assertSourceMatch(
    styles,
    /\.leftPanel\s*\{[^}]*--left-panel-inline-padding:\s*12px;/s,
    'The expanded panel must expose the same 12px desktop inset as inspectorBody'
  );
  assertSourceMatch(
    styles,
    /\.leftPanel__list\.list\s*\{[^}]*margin:\s*0;[^}]*padding:\s*10px\s+var\(--left-panel-inline-padding\)\s+16px;/s,
    'The object list must use inspectorBody-style vertical and horizontal padding'
  );
  assertSourceMatch(
    styles,
    /\.leftPanelSearch\s*\{[^}]*margin:\s*0\s+var\(--left-panel-inline-padding\);/s,
    'Search must align to the shared panel inset'
  );
  assertSourceMatch(
    styles,
    /\.leftPanel__filterRow\s*\{[^}]*padding:\s*0\s+var\(--left-panel-inline-padding\)\s+8px;/s,
    'Filter tabs must align to the shared panel inset'
  );
  assertSourceMatch(
    styles,
    /\.leftPanel__addSection\s*\{[^}]*padding:\s*10px\s+var\(--left-panel-inline-padding\)\s+12px;/s,
    'The Add section must align to the shared panel inset'
  );

  const leftPanelStyles = styles.slice(styles.indexOf('/* Objects-first left panel'));
  const phone = extractBalancedBlock(leftPanelStyles, '@media (max-width: 480px)', 'left-panel phone media query');
  assertSourceMatch(
    phone,
    /\.leftPanel\s*\{[^}]*--left-panel-inline-padding:\s*10px;/s,
    'The left panel must match the inspector 10px compact inset on phones'
  );
});
