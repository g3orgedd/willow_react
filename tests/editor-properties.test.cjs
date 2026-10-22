const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

function loadBuildCommonProps() {
  const filename = path.join(__dirname, '..', 'public', 'modules', '40-editor.js');
  const source = fs.readFileSync(filename, 'utf8');
  const start = source.indexOf('function buildCommonProps');
  const end = source.indexOf('function createFieldNameInput');
  assert.ok(start >= 0 && end > start, 'common properties builder must remain extractable');

  const document = {
    createElement: (tagName) => ({
      tagName,
      children: [],
      appendChild(child) {
        this.children.push(child);
        return child;
      },
    }),
  };
  const fieldRow = (label, control) => {
    const classes = new Set();
    return {
      label,
      control,
      dataset: {},
      classList: {
        add: (...names) => names.forEach((name) => classes.add(name)),
        contains: (name) => classes.has(name),
      },
    };
  };
  const context = {
    document,
    appendInspectorItem: (container, group, element, options = {}) => {
      element.dataset.inspectorGroup = group;
      if (options.fullWidth) element.classList.add('fieldRow--fullWidth');
      container.appendChild(element);
      return element;
    },
    createPrintControlCard: () => ({ kind: 'print-control' }),
    createDeleteControlButton: () => ({ kind: 'delete-control' }),
    createPropsDivider: () => ({ kind: 'divider' }),
    fieldRow,
    t: (key) => key,
    createFieldNameInput: () => ({ kind: 'name' }),
    buildFixedTextEntryModeSelect: () => ({ kind: 'fixed-text-mode' }),
    inputText: () => ({ kind: 'text' }),
    inputMaxCharacters: () => ({ kind: 'max-characters' }),
    inputNumber: () => ({ kind: 'number' }),
    selectOrientation: () => ({ kind: 'orientation' }),
    internalToMm: (value) => value,
    mmToInternal: (value) => value,
    pushHistory: () => {},
    renderUI: () => {},
    renderAll: () => {},
    setFieldPositionInternal: () => {},
    constrainCurrentFieldPositionsInternal: () => {},
  };
  context.globalThis = context;
  vm.createContext(context);
  vm.runInContext(`${source.slice(start, end)}\nglobalThis.buildCommonProps = buildCommonProps;`, context, { filename });
  return context.buildCommonProps;
}

function makeField(overrides = {}) {
  return {
    fldType: 'FixedText',
    name: 'Field00',
    data: { maxChars: null },
    geom: { x: 0, y: 0, w: 100, h: 100 },
    orientation: 0,
    ...overrides,
  };
}

function propertyLabels(panel) {
  return panel.children.map((child) => child.label).filter(Boolean);
}

test('DataMatrix common properties omit type and maximum characters', () => {
  const buildCommonProps = loadBuildCommonProps();
  const panel = buildCommonProps(makeField({
    fldType: 'Barcode',
    barcode: { dataMatrix: { symbolSize: '22X22' } },
  }));

  assert.deepEqual(propertyLabels(panel).sort(), [
    'field.name',
    'field.rotation',
    'field.x',
    'field.y',
    'field.width',
    'field.height',
  ].sort());
  assert.equal(
    panel.children.find((child) => child.label === 'field.name').classList.contains('fieldRow--fullWidth'),
    true,
    'DataMatrix name must span the full Basic section width'
  );
});

test('non-DataMatrix fields retain type and maximum characters', () => {
  const buildCommonProps = loadBuildCommonProps();
  const panel = buildCommonProps(makeField());

  assert.deepEqual(propertyLabels(panel).sort(), [
    'field.name',
    'field.rotation',
    'field.type',
    'field.maxCharacters',
    'field.x',
    'field.y',
    'field.width',
    'field.height',
  ].sort());
  assert.deepEqual(propertyLabels(panel).slice(0, 3), [
    'field.name',
    'field.maxCharacters',
    'field.type',
  ]);
  assert.equal(
    panel.children.find((child) => child.label === 'field.type').classList.contains('fieldRow--fullWidth'),
    true,
    'Type must span the full Basic section width'
  );
  assert.equal(
    panel.children.find((child) => child.label === 'field.name').classList.contains('fieldRow--fullWidth'),
    true,
    'Field names must span the full Basic section width'
  );
  assert.equal(
    panel.children.find((child) => child.label === 'field.maxCharacters').classList.contains('fieldRow--fullWidth'),
    true,
    'Maximum characters must span a separate full-width row'
  );
});

test('Object and Template properties keep dedicated contextual inspector hosts', () => {
  const component = fs.readFileSync(path.join(__dirname, '..', 'src', 'components', 'RightPanel.tsx'), 'utf8');
  const styles = fs.readFileSync(path.join(__dirname, '..', 'public', 'styles.css'), 'utf8');

  assert.match(component, /id="inspectorObjectContext"[^>]*className="[^"]*\binspectorContext\b/);
  assert.match(component, /id="propsPanel" className="[^"]*\binspectorFieldPanel\b/);
  assert.match(component, /id="inspectorTemplateContext"[^>]*className="[^"]*\binspectorContext\b/);
  assert.match(component, /id="templateSizePanel" className="[^"]*\binspectorSection__content\b/);
  assert.match(component, /id="templateTargetPanel" className="[^"]*\binspectorSection__content\b/);
  assert.match(component, /id="templateAdvancedSection" className="[^"]*\binspectorDisclosure\b/);

  assert.doesNotMatch(component, /className="tabs"|\bdata-tab=|id="tab-(?:object|template|advanced|settings)"/);
  assert.match(styles, /\.inspectorFieldPanel > \.form\s*\{[^}]*grid-template-columns:\s*repeat\(2,/s);
  assert.match(styles, /\.inspectorFieldPanel \.fieldRow\s*\{[^}]*grid-template-columns:\s*1fr;/s);
});

test('Object and Template inspector contexts use the concise shared Properties title', () => {
  const i18n = fs.readFileSync(path.join(__dirname, '..', 'public', 'modules', '05-i18n.js'), 'utf8');

  assert.equal((i18n.match(/"inspector\.objectTitle": "Properties"/g) || []).length, 1);
  assert.equal((i18n.match(/"inspector\.templateTitle": "Properties"/g) || []).length, 1);
  assert.equal((i18n.match(/"inspector\.objectTitle": "Свойства"/g) || []).length, 1);
  assert.equal((i18n.match(/"inspector\.templateTitle": "Свойства"/g) || []).length, 1);
});

test('Object value field spans the full inspector width', () => {
  const editor = fs.readFileSync(path.join(__dirname, '..', 'public', 'modules', '40-editor.js'), 'utf8');
  const styles = fs.readFileSync(path.join(__dirname, '..', 'public', 'styles.css'), 'utf8');
  const start = editor.indexOf('function buildTextLikeProps');
  const end = editor.indexOf('function buildBarcodeProps', start);
  assert.ok(start >= 0 && end > start, 'text-like property builder must remain extractable');
  const textProps = editor.slice(start, end);

  assert.match(editor, /if \(options\.fullWidth\) element\.classList\.add\("fieldRow--fullWidth"\)/);
  assert.match(textProps, /const valueRow = fieldRow\(t\("field\.value"\), valueInput\);\s*appendInspectorItem\(wrap, "content", valueRow, \{ fullWidth: true \}\)/);
  assert.ok(
    textProps.indexOf('t("field.value")') < textProps.lastIndexOf('t("field.fontSize")') &&
      textProps.lastIndexOf('t("field.fontSize")') < textProps.lastIndexOf('t("field.xMag")'),
    'Value must precede Font size and XMag in the property grid'
  );
  const fullWidthRuleStart = styles.indexOf('.inspector .fieldRow--fullWidth');
  assert.ok(fullWidthRuleStart >= 0, 'Inspector must style full-width property rows');
  assert.match(styles.slice(fullWidthRuleStart, fullWidthRuleStart + 360), /grid-column:\s*1\s*\/\s*-1;/);
});

test('Multi-selection rotation and font size controls span the full inspector width', () => {
  const editor = fs.readFileSync(path.join(__dirname, '..', 'public', 'modules', '40-editor.js'), 'utf8');
  const start = editor.indexOf('function buildMultiSelectionProps');
  const end = editor.indexOf('function buildCommonProps', start);
  assert.ok(start >= 0 && end > start, 'multi-selection property builder must remain extractable');
  const multiProps = editor.slice(start, end);

  assert.match(multiProps, /appendInspectorItem\(wrap, "geometry", fieldRow\(t\("field\.rotation"\),[\s\S]*?\)\), \{ fullWidth: true \}\);/);
  assert.match(multiProps, /appendInspectorItem\(wrap, "text", fieldRow\(t\("field\.fontSize"\), createMultiFontSizeInput\(fontFields\)\), \{ fullWidth: true \}\);/);
});

test('DataMatrix modal and template builder share the segmented SN length control', () => {
  const dataMatrixModal = fs.readFileSync(path.join(__dirname, '..', 'src', 'components', 'DataMatrixModal.tsx'), 'utf8');
  const templateModal = fs.readFileSync(path.join(__dirname, '..', 'src', 'components', 'NewTemplateModal.tsx'), 'utf8');
  const styles = fs.readFileSync(path.join(__dirname, '..', 'public', 'styles.css'), 'utf8');
  const editor = fs.readFileSync(path.join(__dirname, '..', 'public', 'modules', '40-editor.js'), 'utf8');
  const ui = fs.readFileSync(path.join(__dirname, '..', 'public', 'modules', '10-canvas-ui.js'), 'utf8');

  assert.match(dataMatrixModal, /id="newDataMatrixSnValue" type="hidden" defaultValue="000000"/);
  assert.doesNotMatch(dataMatrixModal, /<select id="newDataMatrixSnValue"/);
  assert.match(dataMatrixModal, /className="fieldFilter snLengthSelector"/);
  assert.match(dataMatrixModal, /data-dm-sn-length="6" aria-pressed="true"/);
  assert.match(dataMatrixModal, /data-dm-sn-length="13" aria-pressed="false"/);
  assert.match(templateModal, /className="fieldFilter snLengthSelector"/);
  assert.match(styles, /\.snLengthSelector\s*\{[^}]*height:\s*44px;/s);
  assert.match(editor, /querySelectorAll\("\[data-dm-sn-length\]"\)/);
  assert.match(ui, /button\.dataset\.dmSnLength === "13" \? "0000000000000" : "000000"/);
});

test('template size hint is spaced from the height field', () => {
  const templateModal = fs.readFileSync(path.join(__dirname, '..', 'src', 'components', 'NewTemplateModal.tsx'), 'utf8');
  const styles = fs.readFileSync(path.join(__dirname, '..', 'public', 'styles.css'), 'utf8');

  assert.match(templateModal, /className="note builderSizeHint"/);
  assert.match(styles, /\.builderSizeHint\s*\{[^}]*margin-top:\s*16px;/s);
});
