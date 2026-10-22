const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');

const root = path.join(__dirname, '..');
const read = (...segments) => fs.readFileSync(path.join(root, ...segments), 'utf8');

const component = read('src', 'components', 'RightPanel.tsx');
const core = read('public', 'modules', '00-core.js');
const ui = read('public', 'modules', '10-canvas-ui.js');
const rendering = read('public', 'modules', '30-rendering.js');
const editor = read('public', 'modules', '40-editor.js');
const runtime = `${ui}\n${rendering}\n${editor}`;
const styles = read('public', 'styles.css');

function assertSourceMatch(source, pattern, message = `Expected source to match ${pattern}`) {
  assert.ok(pattern.test(source), message);
}

function assertSourceLacks(source, pattern, message = `Expected source not to match ${pattern}`) {
  assert.ok(!pattern.test(source), message);
}

function assertCssRuleIncludes(selector, declaration, message) {
  const selectorIndex = styles.indexOf(selector);
  const blockStart = styles.indexOf('{', selectorIndex);
  const blockEnd = styles.indexOf('}', blockStart);
  assert.ok(selectorIndex >= 0 && blockStart > selectorIndex && blockEnd > blockStart, `${selector} CSS rule must exist`);
  assertSourceMatch(styles.slice(blockStart + 1, blockEnd), declaration, message);
}

function readCssNumericDeclaration(selector, property) {
  const selectorIndex = styles.indexOf(selector);
  const blockStart = styles.indexOf('{', selectorIndex);
  const blockEnd = styles.indexOf('}', blockStart);
  assert.ok(selectorIndex >= 0 && blockStart > selectorIndex && blockEnd > blockStart, `${selector} CSS rule must exist`);
  const declaration = new RegExp(`${property.replace('-', '\\-')}\\s*:\\s*(-?\\d+)`).exec(
    styles.slice(blockStart + 1, blockEnd)
  );
  assert.ok(declaration, `${selector} must declare a numeric ${property}`);
  return Number(declaration[1]);
}

function assertRuntimeVisibilityWiring(reference) {
  const pattern = new RegExp(
    `(?:${reference}[\\s\\S]{0,220}(?:classList|aria-hidden|hidden|visible)|` +
      `(?:classList|aria-hidden|hidden|visible)[\\s\\S]{0,220}${reference})`,
    'i'
  );
  assertSourceMatch(runtime, pattern, `${reference} must be updated by the Inspector state synchronizer`);
}

test('RightPanel exposes selection-driven contexts instead of the legacy 2x2 tab matrix', () => {
  const ids = [
    'inspectorPanel',
    'inspectorNoTemplate',
    'inspectorObjectContext',
    'inspectorTemplateContext',
    'inspectorTemplateSections',
    'propsPanel',
    'templateSizePanel',
    'templateTargetPanel',
  ];
  for (const id of ids) {
    assertSourceMatch(component, new RegExp(`id="${id}"`), `${id} must exist in RightPanel`);
    assertSourceMatch(core, new RegExp(`\\$\\("${id}"\\)`), `${id} must have a runtime DOM reference`);
  }

  assertSourceLacks(component, /className="tabs"|\bdata-tab=|id="tab-(?:object|template|advanced|settings)"/, 'RightPanel must not render the legacy 2x2 tab matrix');
  assertSourceLacks(runtime, /querySelectorAll\(["']\.tab["']\)|\btabview--active\b|\.dataset\.tab\b/, 'Runtime must not query or activate legacy Inspector tabs');

  for (const reference of [
    'elInspectorNoTemplate',
    'elInspectorObjectContext',
    'elInspectorTemplateContext',
    'elInspectorTemplateSections',
  ]) {
    assertRuntimeVisibilityWiring(reference);
  }
});

test('Template workspace owns Grid while application settings stay in a popup', () => {
  const templateStart = component.indexOf('id="inspectorTemplateContext"');
  const settingsStart = component.indexOf('id="inspectorAppSettings"');
  const asideEnd = component.indexOf('</aside>');
  assert.ok(templateStart >= 0 && settingsStart > templateStart, 'Template and settings contexts must be ordered');

  const templateSource = component.slice(templateStart, settingsStart);
  const settingsSource = component.slice(settingsStart);
  assertSourceMatch(templateSource, /id="templateWorkspaceSection"[\s\S]*id="gridSizeSelect"/, 'Grid must live in the Template workspace section');
  assertSourceLacks(settingsSource, /id="gridSizeSelect"/, 'Application settings must not own Grid');
  assert.ok(settingsStart > asideEnd, 'Application settings must be a popup outside the scrolling Inspector');
  assertSourceMatch(settingsSource, /role="dialog"/, 'Application settings popup must expose dialog semantics');
  assertSourceMatch(settingsSource, /id="uiLanguageSelect"/);
  assertSourceMatch(settingsSource, /id="uiThemeSelect"/);

  assertSourceMatch(ui, /elBtnInspectorAppSettings\??\.addEventListener\(["']click["']/, 'Settings trigger must handle click');
  assertSourceMatch(runtime, /elInspectorAppSettings[\s\S]{0,220}(?:classList|hidden)/, 'Settings popup visibility must be managed');
  assertSourceMatch(runtime, /elBtnInspectorAppSettings[\s\S]{0,220}aria-expanded/, 'Settings trigger must synchronize aria-expanded');
});

test('Template printer controls are stacked in two full-width rows', () => {
  const targetPanelStart = rendering.indexOf('function renderTemplateTargetPanel');
  const targetPanelEnd = rendering.indexOf('\n}', targetPanelStart);
  assert.ok(targetPanelStart >= 0 && targetPanelEnd > targetPanelStart, 'Template target renderer must exist');
  assertSourceMatch(
    rendering.slice(targetPanelStart, targetPanelEnd),
    /wrap\.className\s*=\s*["']inspectorSection__grid inspectorSection__grid--singleColumn["']/,
    'Printer model and print mode must use the single-column grid modifier'
  );
  assertCssRuleIncludes(
    '.inspectorSection__grid.inspectorSection__grid--singleColumn',
    /grid-template-columns:\s*minmax\(0,\s*1fr\);/,
    'Single-column Inspector sections must span the available width'
  );
});

test('Inspector collapse is accessible and persisted for the browser session', () => {
  assertSourceMatch(component, /id="btnInspectorCollapse"[^>]*aria-expanded="true"/);
  assertSourceMatch(component, /id="btnInspectorExpand"[^>]*aria-expanded="false"/);
  assertSourceMatch(component, /id="btnInspectorExpand"[^>]*className="[^"]*\binspectorCollapsedRail\b/);

  assertSourceMatch(ui, /(?:window\.)?sessionStorage\??\.getItem\(\s*INSPECTOR_COLLAPSED_STORAGE_KEY\s*\)/, 'Collapse preference must be restored from sessionStorage');
  assertSourceMatch(ui, /(?:window\.)?sessionStorage\??\.setItem\(\s*INSPECTOR_COLLAPSED_STORAGE_KEY\s*,/, 'Collapse preference must be saved to sessionStorage');
  assertSourceMatch(ui, /elBtnInspectorCollapse\??\.addEventListener\(["']click["']/, 'Collapse button must handle click');
  assertSourceMatch(ui, /elBtnInspectorExpand\??\.addEventListener\(["']click["']/, 'Collapsed rail must handle click');
  assertSourceMatch(
    ui,
    /elInspectorPanel[\s\S]{0,180}(?:classList\.toggle\(["'](?:inspector--collapsed|is-collapsed)["']|setAttribute\(["']data-collapsed["'])/,
    'Inspector root must expose a collapsed styling state'
  );

  assertSourceMatch(styles, /\.inspectorCollapsedRail\s*\{[^}]*display:\s*none;/s);
  assertCssRuleIncludes(
    '#inspectorPanel .inspectorCollapsedRail',
    /display:\s*(?:flex|grid|block|inline-flex);/,
    'Desktop Inspector must keep its collapsed rail mounted for animation'
  );
  assertCssRuleIncludes(
    '#inspectorPanel.inspector--collapsed .inspectorExpanded',
    /opacity:\s*0;/,
    'Collapsed Inspector must fade its expanded content'
  );
  assertCssRuleIncludes(
    '#inspectorPanel.inspector--collapsed .inspectorCollapsedRail',
    /opacity:\s*1;/,
    'Collapsed Inspector must fade in its compact rail'
  );
  assertSourceMatch(
    styles,
    /\.inspectorIconButton\s*\{[^}]*width:\s*36px;[^}]*min-width:\s*36px;[^}]*height:\s*36px;[^}]*min-height:\s*36px;/s,
    'Expanded Inspector header buttons must use the compact 36px size'
  );
  assertSourceMatch(
    styles,
    /\.inspectorCollapsedRail__chevron\s*\{[^}]*width:\s*36px;[^}]*height:\s*36px;[^}]*flex:\s*0\s*0\s*36px;/s,
    'Collapsed and expanded Inspector arrow buttons must use the same 36px size'
  );
  assertSourceMatch(
    styles,
    /\.app\s*\{[^}]*transition:\s*grid-template-columns\s*240ms\s*cubic-bezier\(0\.2,\s*0,\s*0,\s*1\);/s,
    'Inspector width must use the template-builder reveal timing and easing'
  );
  assertSourceMatch(
    styles,
    /\.app:has\(> #inspectorPanel\[data-collapsed="true"\]\)\s*\{[^}]*grid-template-columns:[^;]*minmax\(var\(--inspector-collapsed-width,\s*52px\),\s*var\(--inspector-collapsed-width,\s*52px\)\);/s,
    'Expanded and collapsed Inspector tracks must use compatible minmax values for interpolation'
  );
  assertSourceMatch(
    styles,
    /#inspectorPanel \.inspectorExpanded\s*\{[^}]*opacity:\s*1;[^}]*transform:\s*translateX\(0\);[^}]*opacity\s*180ms\s*ease[^}]*transform\s*240ms\s*cubic-bezier\(0\.2,\s*0,\s*0,\s*1\)/s,
    'Expanded Inspector content must reuse the template-builder fade and movement'
  );
});

test('Object actions open from both the header trigger and a canvas context menu', () => {
  assertSourceMatch(component, /id="btnInspectorObjectMenu"[^>]*aria-haspopup="menu"[^>]*aria-expanded="false"/);
  assertSourceMatch(component, /id="inspectorObjectMenu"[^>]*role="menu"/);
  assertSourceMatch(component, /id="btnInspectorTogglePrint"[^>]*role="menuitemcheckbox"[^>]*aria-checked="false"/);
  assertSourceMatch(component, /id="btnDelete"[^>]*role="menuitem"/);

  assertSourceMatch(runtime, /elBtnInspectorObjectMenu\??\.addEventListener\(["']click["']/, 'Header object menu trigger must handle click');
  assertSourceMatch(runtime, /elBtnInspectorTogglePrint\??\.addEventListener\(["']click["']/, 'Print menu item must handle click');
  const contextMenuIndex = runtime.search(/(?:\.on|addEventListener)\(["']contextmenu["']/);
  assert.ok(contextMenuIndex >= 0, 'Canvas objects must handle the contextmenu event');
  assertSourceMatch(runtime.slice(contextMenuIndex, contextMenuIndex + 900), /preventDefault(?:\?\.)?\(\)/, 'Canvas context menu must suppress the browser menu');
  assertSourceMatch(runtime, /elInspectorObjectMenu[\s\S]{0,260}(?:classList|hidden)/, 'Object menu visibility must be managed');

  for (const iconName of ['check_box_24dp.svg', 'check_box_outline_blank_24dp.svg', 'delete_24dp.svg']) {
    assert.ok(
      fs.existsSync(path.join(root, 'public', 'resourses', 'Icons', iconName)),
      `${iconName} must be available from the public icon directory`
    );
    assertSourceMatch(styles, new RegExp(`url\\(["']?/resourses/Icons/${iconName.replace('.', '\\.')}["']?\\)`));
  }
  assertSourceMatch(
    component,
    /id="btnInspectorTogglePrint"[\s\S]{0,220}inspectorMenuItem__icon--printState[\s\S]{0,120}id="inspectorPrintLabel"/,
    'Print-state icon must precede its label'
  );
  assertSourceMatch(
    styles,
    /\.inspectorMenuItem\[role="menuitemcheckbox"\]\s*\{[^}]*justify-content:\s*flex-start;[^}]*gap:\s*10px;/s,
    'Print action content must be aligned to the left'
  );
  assertSourceMatch(component, /id="btnDelete"[\s\S]{0,260}inspectorMenuItem__icon--delete/);
  assertSourceLacks(styles, /aria-checked="true"[^}]*content:\s*["']✓["']/s, 'Print action must not retain the text check glyph');
  assertSourceMatch(
    styles,
    /\.inspectorMenuItem__icon--printState\s*\{[^}]*check_box_outline_blank_24dp\.svg[^}]*\}/s,
    'Non-printing fields must use the empty checkbox icon'
  );
  assertSourceMatch(
    styles,
    /aria-checked="true"[^}]*\.inspectorMenuItem__icon--printState\s*\{[^}]*check_box_24dp\.svg[^}]*\}/s,
    'Printing fields must use the checked checkbox icon'
  );
  assertSourceMatch(read('public', 'modules', '05-i18n.js'), /selector:\s*"#inspectorDeleteLabel",\s*key:\s*"object\.delete"/);
});

test('Inspector header stays visible while its body scrolls on desktop and mobile', () => {
  assertSourceMatch(styles, /\.inspectorHeader\s*\{[^}]*position:\s*sticky;[^}]*top:\s*0;/s, 'Inspector header must be sticky');
  assertSourceMatch(styles, /\.inspectorBody\s*\{[^}]*min-height:\s*0;[^}]*overflow-y:\s*auto;/s, 'Inspector body must own vertical scrolling');
  assertSourceMatch(styles, /\.inspectorExpanded\s*\{[^}]*min-height:\s*0;/s);
  assertSourceMatch(styles, /\.inspectorPopover\s*\{[^}]*position:\s*fixed;/s, 'Inspector popovers must escape the scroll container');
  assertSourceMatch(
    styles,
    /@media\s*\(max-width:\s*960px\)[\s\S]*\.mobilePanelMenu [^{\n]*\.inspectorBody\s*\{[^}]*(?:overflow|max-height):/s,
    'Mobile drawer must override Inspector body overflow or height'
  );
});

test('Zoom control uses a compact editor-toolbar width independent from the Inspector', () => {
  assertSourceMatch(
    styles,
    /\.zoom\s*\{[^}]*width:\s*248px;[^}]*min-width:\s*224px;[^}]*flex:\s*0\s+1\s+248px;/s,
    'Desktop zoom control must stay compact while retaining a flexible slider'
  );
  assertSourceLacks(
    styles,
    /\.zoom\s*\{[^}]*(?:width|min-width|flex):\s*var\(--app-panel-right\)/s,
    'Zoom control must no longer inherit the Inspector width'
  );
});

test('Expanded Inspector matches the compact left-panel width', () => {
  assertSourceMatch(
    styles,
    /--app-panel-left:\s*288px;[\s\S]{0,120}--app-panel-right:\s*288px;/,
    'Left and right panel width tokens must both be 288px'
  );
  assertSourceMatch(
    styles,
    /--app-right-track:\s*minmax\(280px,\s*var\(--app-panel-right\)\);/,
    'The app grid must not retain the former 336px Inspector minimum'
  );
  assertSourceMatch(
    styles,
    /\.inspector\s*\{[^}]*--inspector-expanded-width:\s*var\(--app-panel-right\);/s,
    'Inspector content must reuse the shared right-panel width token'
  );
});

test('Inspector sections share one symmetric horizontal content inset', () => {
  assertCssRuleIncludes(
    '.inspectorBody',
    /padding:\s*10px\s+var\(--inspector-inline-padding\)\s+16px;/,
    'Inspector body must own the shared left and right padding'
  );
  assertSourceMatch(
    styles,
    /\.inspectorSection\s*\{[^}]*padding:\s*12px\s+0\s+14px;/s,
    'Property sections must not add a second horizontal inset'
  );
  assertCssRuleIncludes('.inspectorSection__title', /padding-inline:\s*0;/);
  assertCssRuleIncludes('.inspectorDisclosure__summary', /padding:\s*2px\s+0;/);
  assertCssRuleIncludes('.inspectorDisclosure__body', /padding:\s*0\s+0\s+10px;/);
  assertSourceMatch(
    styles,
    /\.inspector \.inspectorFieldPanel \.fieldRow label,[\s\S]{0,180}padding:\s*0;/,
    'Labels must align with controls instead of adding their own inline padding'
  );
});

test('Inspector omits the divider after the last section', () => {
  assertCssRuleIncludes(
    '.inspectorSectionList > :last-child',
    /border-bottom:\s*0;/,
    'The final Inspector block must not render a bottom divider'
  );
  assertCssRuleIncludes(
    '.inspectorDisclosure',
    /border-bottom:\s*0;/,
    'The Advanced disclosure must not render a bottom divider'
  );
});

test('Inspector navigation controls use the supplied SVG assets', () => {
  const iconNames = [
    'settings_24dp.svg',
    'arrow_back_24dp.svg',
    'arrow_forward_24dp.svg',
    'more_vert_24dp.svg',
  ];

  for (const iconName of iconNames) {
    assertSourceMatch(
      component,
      new RegExp(`src=["'](?:/resourses/Icons/)?${iconName.replace('.', '\\.')}["']`),
      `RightPanel must render ${iconName} instead of a text glyph`
    );
    assert.ok(
      fs.existsSync(path.join(root, 'public', 'resourses', 'Icons', iconName)),
      `${iconName} must be available from the public icon directory`
    );
  }

  assertSourceLacks(
    component,
    /id="btnInspectorAppSettings"[\s\S]{0,220}>\s*⚙\s*</,
    'The settings button must not retain the old text glyph'
  );
  assertSourceLacks(
    component,
    /id="btnInspector(?:Collapse|Expand)"[\s\S]{0,220}>\s*[‹›←→]\s*</,
    'Inspector navigation buttons must not retain text arrows'
  );
  assertSourceLacks(
    component,
    /id="btnInspectorObjectMenu"[\s\S]{0,220}>\s*⋮\s*</,
    'The object actions button must not retain the old text glyph'
  );
});

test('Inspector disclosure arrows use centered down and up SVG assets', () => {
  const disclosureIcons = ['arrow_drop_down.svg', 'arrow_drop_up.svg'];
  for (const iconName of disclosureIcons) {
    assert.ok(
      fs.existsSync(path.join(root, 'public', 'resourses', 'Icons', iconName)),
      `${iconName} must be available from the public icon directory`
    );
    assertSourceMatch(styles, new RegExp(`url\\(["']?/resourses/Icons/${iconName.replace('.', '\\.')}["']?\\)`));
  }

  assertSourceLacks(styles, /\.inspectorDisclosure__summary::after\s*\{[^}]*content:\s*["']›["']/s);
  assertSourceMatch(
    styles,
    /\.inspectorDisclosure__summary::after\s*\{[^}]*width:\s*32px;[^}]*height:\s*32px;[^}]*mask-position:\s*center;[^}]*mask-size:\s*24px 24px;/s,
    'Disclosure icon must be centered as a 24px mask in a fixed 32px area'
  );
  assertSourceMatch(
    styles,
    /\.inspectorDisclosure__summary\s*\{[^}]*font-size:\s*1rem;/s,
    'Disclosure title must use a 1rem font size'
  );
});

test('Custom select menu is layered above Inspector popovers', () => {
  const selectMenuZIndex = readCssNumericDeclaration('.customSelectMenu', 'z-index');
  const inspectorPopoverZIndex = readCssNumericDeclaration('.inspectorPopover', 'z-index');

  assert.ok(
    selectMenuZIndex > inspectorPopoverZIndex,
    `.customSelectMenu z-index (${selectMenuZIndex}) must exceed .inspectorPopover z-index (${inspectorPopoverZIndex})`
  );
});
