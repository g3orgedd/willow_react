const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');
const { ComparatorDomParser } = require('./helpers/ciff-production-harness.cjs');

function loadTabCloseHelpers() {
  const filename = path.join(__dirname, '..', 'public', 'modules', '70-template-tabs.js');
  const source = fs.readFileSync(filename, 'utf8');
  const start = source.indexOf('function getTemplateTabCloseIds');
  const end = source.indexOf('function cloneTemplateTabValue');
  assert.ok(start >= 0 && end > start, 'tab-close helpers must remain extractable');
  const context = {};
  context.globalThis = context;
  vm.createContext(context);
  vm.runInContext(
    `${source.slice(start, end)}\n` +
    'globalThis.getTemplateTabCloseIds = getTemplateTabCloseIds;\n' +
    'globalThis.getNextActiveTemplateTabIdAfterClose = getNextActiveTemplateTabIdAfterClose;',
    context,
    { filename },
  );
  return context;
}

function loadTabMigrationHelpers() {
  const filename = path.join(__dirname, '..', 'public', 'modules', '70-template-tabs.js');
  const source = fs.readFileSync(filename, 'utf8');
  const start = source.indexOf('function cloneTemplateTabValue');
  const end = source.indexOf('function createTemplateTabId');
  assert.ok(start >= 0 && end > start, 'tab migration helpers must remain extractable');
  const capabilities = {
    'DataFlex 6330(53mm)': { maxImageWidth: 5333, maxImageHeight: 7500, xRes: 0.12 },
  };
  const context = {
    DOMParser: ComparatorDomParser,
    structuredClone: (value) => JSON.parse(JSON.stringify(value)),
    getKnownPrinterCapabilities: (model) => capabilities[model] || null,
  };
  context.globalThis = context;
  vm.createContext(context);
  vm.runInContext(
    'const TEMPLATE_TABS_STORAGE_VERSION = 4;\n' +
    'const TEMPLATE_TABS_LEGACY_STORAGE_VERSION = 1;\n' +
    'const TEMPLATE_TABS_CIFF_MODEL_LEGACY_STORAGE_VERSION = 2;\n' +
    `${source.slice(start, end)}\n` +
    'globalThis.migrateStoredTemplateTabsPayload = migrateStoredTemplateTabsPayload;',
    context,
    { filename },
  );
  return context;
}

function snapshot(subImage, designedFor = 'DataFlex 6330(53mm) - Continuous') {
  return JSON.stringify({
    docMeta: { designedFor, printerModel: designedFor.replace(/\s+-\s+Continuous$/, '') },
    subImage,
  });
}

function storedTabPayload({ version = 1, line1 = '<?xml version="1.0" encoding="UTF-16"?>', line2, editorSnapshot, undo = [], redo = [], isDirty = false }) {
  return {
    version,
    activeTabId: '1',
    tabs: [{
      id: '1',
      title: 'Template',
      isDirty,
      savedFingerprint: 'legacy-fingerprint',
      templateState: {
        raw: { line1, line2 },
        editorSnapshot,
        history: { undo, redo },
      },
    }],
  };
}

const tabs = ['1', '2', '3', '4', '5'].map((id) => ({ id }));

test('tab close actions are calculated relative to the selected tab', () => {
  const api = loadTabCloseHelpers();
  assert.deepEqual(Array.from(api.getTemplateTabCloseIds('close', '3', tabs)), ['3']);
  assert.deepEqual(Array.from(api.getTemplateTabCloseIds('close-others', '3', tabs)), ['1', '2', '4', '5']);
  assert.deepEqual(Array.from(api.getTemplateTabCloseIds('close-right', '3', tabs)), ['4', '5']);
  assert.deepEqual(Array.from(api.getTemplateTabCloseIds('close-all', '3', tabs)), ['1', '2', '3', '4', '5']);
});

test('closing the active tab prefers the nearest tab to the right', () => {
  const api = loadTabCloseHelpers();
  assert.equal(api.getNextActiveTemplateTabIdAfterClose(tabs, '3', ['3']), '4');
  assert.equal(api.getNextActiveTemplateTabIdAfterClose(tabs, '5', ['5']), '4');
});

test('bulk close keeps an active tab that is not being closed', () => {
  const api = loadTabCloseHelpers();
  assert.equal(api.getNextActiveTemplateTabIdAfterClose(tabs, '3', ['4', '5']), '3');
  assert.equal(api.getNextActiveTemplateTabIdAfterClose(tabs, '3', ['1', '2', '4', '5']), '3');
});

test('bulk close searches right and then left around a removed active tab', () => {
  const api = loadTabCloseHelpers();
  assert.equal(api.getNextActiveTemplateTabIdAfterClose(tabs, '3', ['2', '3', '4']), '5');
  assert.equal(api.getNextActiveTemplateTabIdAfterClose(tabs, '3', ['3', '4', '5']), '2');
  assert.equal(api.getNextActiveTemplateTabIdAfterClose(tabs, '3', tabs.map((tab) => tab.id)), null);
});

test('impossible menu operations yield an empty target list', () => {
  const api = loadTabCloseHelpers();
  assert.deepEqual(Array.from(api.getTemplateTabCloseIds('close-right', '5', tabs)), []);
  assert.deepEqual(Array.from(api.getTemplateTabCloseIds('close-others', '1', [{ id: '1' }])), []);
  assert.deepEqual(Array.from(api.getTemplateTabCloseIds('close', 'missing', tabs)), []);
});

test('v1 persisted tabs retain an unsaved physical resize in Max and preserve Image bounds', () => {
  const api = loadTabMigrationHelpers();
  const raw = '<Header DesignedFor="DataFlex 6330(53mm) - Continuous"></Header><SubImage>' +
    '<SubHeader><ImageWidth>2000</ImageWidth><ImageHeight>2000</ImageHeight>' +
    '<MaxImageWidth>5333</MaxImageWidth><MaxImageHeight>7500</MaxImageHeight></SubHeader></SubImage>';
  const initial = snapshot({ width: 2000, height: 2000, maxWidth: 5333, maxHeight: 7500, xRes: 0.12 });
  const resized = snapshot({ width: 2000, height: 2000, maxWidth: 3000, maxHeight: 1500, xRes: 0.12 });

  const migrated = api.migrateStoredTemplateTabsPayload(storedTabPayload({
    line2: raw,
    editorSnapshot: resized,
    undo: [initial],
    redo: [resized],
  }));
  const current = JSON.parse(migrated.tabs[0].templateState.editorSnapshot);
  const undo = JSON.parse(migrated.tabs[0].templateState.history.undo[0]);
  const redo = JSON.parse(migrated.tabs[0].templateState.history.redo[0]);

  assert.equal(migrated.version, 4);
  assert.deepEqual(current.subImage, { width: 2000, height: 2000, maxWidth: 3000, maxHeight: 1500, workspaceWidth: 3000, workspaceHeight: 1500, xRes: 0.12, yRes: null });
  assert.deepEqual(undo.subImage, { width: 2000, height: 2000, maxWidth: 5333, maxHeight: 7500, workspaceWidth: 5333, workspaceHeight: 7500, xRes: 0.12, yRes: null });
  assert.deepEqual(redo.subImage, current.subImage);
  assert.equal(migrated.tabs[0].isDirty, true);
  assert.equal(migrated.tabs[0].savedFingerprint, null);
});

test('v1 imported physical dimensions stay authoritative without printer profile substitution', () => {
  const api = loadTabMigrationHelpers();
  const raw = '<Header DesignedFor="DataFlex 6330(53mm) - Continuous"></Header><SubImage>' +
    '<SubHeader><ImageWidth>2967</ImageWidth><ImageHeight>1160</ImageHeight>' +
    '<MaxImageWidth>3200</MaxImageWidth><MaxImageHeight>1200</MaxImageHeight></SubHeader></SubImage>';
  const imported = snapshot({ width: 2967, height: 1160, maxWidth: 3200, maxHeight: 1200, xRes: 0 });

  const migrated = api.migrateStoredTemplateTabsPayload(storedTabPayload({ line2: raw, editorSnapshot: imported }));
  const current = JSON.parse(migrated.tabs[0].templateState.editorSnapshot);

  assert.deepEqual(current.subImage, { width: 2967, height: 1160, maxWidth: 3200, maxHeight: 1200, workspaceWidth: 3200, workspaceHeight: 1200, xRes: 0, yRes: null });
  assert.equal(migrated.tabs[0].isDirty, false);
});

test('v2 migration recovers source Max dimensions after an old printer profile repair', () => {
  const api = loadTabMigrationHelpers();
  const raw = '<Header DesignedFor="DataFlex 6330(53mm) - Continuous"></Header><SubImage>' +
    '<SubHeader><ImageWidth>2967</ImageWidth><ImageHeight>1160</ImageHeight>' +
    '<MaxImageWidth>3200</MaxImageWidth><MaxImageHeight>1200</MaxImageHeight></SubHeader></SubImage>';
  const repaired = snapshot({ width: 2967, height: 1160, maxWidth: 5333, maxHeight: 7500, xRes: 0.12 });

  const migrated = api.migrateStoredTemplateTabsPayload(storedTabPayload({
    version: 2,
    line2: raw,
    editorSnapshot: repaired,
    undo: [repaired]
  }));
  const current = JSON.parse(migrated.tabs[0].templateState.editorSnapshot);
  const undo = JSON.parse(migrated.tabs[0].templateState.history.undo[0]);

  assert.equal(migrated.version, 4);
  assert.deepEqual(current.subImage, { width: 2967, height: 1160, maxWidth: 3200, maxHeight: 1200, workspaceWidth: 3200, workspaceHeight: 1200, xRes: 0.12, yRes: null });
  assert.deepEqual(undo.subImage, current.subImage);
  assert.equal(migrated.tabs[0].isDirty, false);
});

test('v1 unknown printer tabs restore physical dimensions from the source', () => {
  const api = loadTabMigrationHelpers();
  const designedFor = 'Custom Printer(53mm) - Continuous';
  const raw = `<Header DesignedFor="${designedFor}"></Header><SubImage>` +
    '<SubHeader><ImageWidth>2400</ImageWidth><ImageHeight>1000</ImageHeight>' +
    '<MaxImageWidth>4100</MaxImageWidth><MaxImageHeight>6200</MaxImageHeight></SubHeader></SubImage>';
  const imported = snapshot(
    { width: 2400, height: 1000, maxWidth: 4100, maxHeight: 6200, xRes: 0.1 },
    designedFor,
  );

  const migrated = api.migrateStoredTemplateTabsPayload(storedTabPayload({ line2: raw, editorSnapshot: imported }));
  const current = JSON.parse(migrated.tabs[0].templateState.editorSnapshot);

  assert.equal(migrated.version, 4);
  assert.deepEqual(current.subImage, { width: 2400, height: 1000, maxWidth: 4100, maxHeight: 6200, workspaceWidth: 4100, workspaceHeight: 6200, xRes: 0.1, yRes: null });
  assert.equal(migrated.tabs[0].isDirty, false);
  assert.equal(migrated.tabs[0].savedFingerprint, api.createPersistedTemplateFingerprint(migrated.tabs[0].templateState));
});

test('v1/v2 clean CIFF model migration refreshes its fingerprint without marking the tab dirty', () => {
  const api = loadTabMigrationHelpers();
  const raw = '<ImageDesign><Header DesignedFor="DataFlex 6330(53mm) - Continuous">' +
    '<DateOffset Name="offset0"><DefaultOffset><Day>1</Day></DefaultOffset><CurrentOffset><Day>21</Day><Month>8</Month><Year>2026</Year></CurrentOffset></DateOffset>' +
    '</Header><SubImage><SubHeader><ImageWidth>2000</ImageWidth><ImageHeight>2000</ImageHeight>' +
    '<MaxImageWidth>5333</MaxImageWidth><MaxImageHeight>7500</MaxImageHeight></SubHeader>' +
    '<Field Name="Field00"><FldType>Barcode</FldType><Data><Object><DataType>5</DataType><Default><![CDATA[value]]></Default><SrcField SrcFieldName="GTIN"/></Object></Data></Field>' +
    '</SubImage></ImageDesign>';
  const legacySnapshot = JSON.stringify({
    docMeta: {
      designedFor: 'DataFlex 6330(53mm) - Continuous',
      printerModel: 'DataFlex 6330(53mm)'
    },
    subImage: { width: 2000, height: 2000, maxWidth: 5333, maxHeight: 7500, xRes: 0.12 },
    dateOffsets: [{
      name: 'offset0',
      default: { y: 0, m: 0, d: 1 },
      current: { y: 2026, m: 8, d: 21 }
    }],
    fields: [{
      name: 'Field00',
      fldType: 'Barcode',
      barcode: {
        dataMatrix: {
          symbolSize: '22X22',
          segments: [{ index: 0, dataType: 5, defaultValue: 'value', srcField: 'GTIN' }]
        }
      }
    }]
  });

  for (const version of [1, 2]) {
    const migrated = api.migrateStoredTemplateTabsPayload(storedTabPayload({
      version,
      line2: raw,
      editorSnapshot: legacySnapshot,
      undo: [legacySnapshot]
    }));
    const tab = migrated.tabs[0];
    const current = JSON.parse(tab.templateState.editorSnapshot);
    const fingerprint = JSON.parse(tab.savedFingerprint);
    const undo = JSON.parse(tab.templateState.history.undo[0]);

    assert.equal(migrated.version, 4);
    assert.equal(tab.isDirty, false);
    assert.equal(current.fields[0].sourceName, 'Field00');
    assert.equal(current.fields[0].barcode.dataMatrix.structureDirty, false);
    assert.equal(current.dateOffsets[0].sourceName, 'offset0');
    assert.equal(undo.fields[0].barcode.dataMatrix.structureDirty, false);
    assert.equal(fingerprint.editorState.fields[0].barcode.dataMatrix.structureDirty, false);
    assert.equal(fingerprint.editorState.dateOffsets[0].sourceName, 'offset0');
  }
});

test('v1 empty tabs remain clean and reusable during storage migration', () => {
  const api = loadTabMigrationHelpers();
  const empty = snapshot({ width: 0, height: 0, maxWidth: 0, maxHeight: 0, xRes: 0 });

  const migrated = api.migrateStoredTemplateTabsPayload(storedTabPayload({
    line2: '',
    editorSnapshot: empty,
  }));
  const current = JSON.parse(migrated.tabs[0].templateState.editorSnapshot);

  assert.equal(migrated.version, 4);
  assert.deepEqual(current.subImage, { width: 0, height: 0, maxWidth: 0, maxHeight: 0, xRes: 0 });
  assert.equal(migrated.tabs[0].isDirty, false);
  assert.equal(migrated.tabs[0].savedFingerprint, 'legacy-fingerprint');
});

test('v3 migration attaches raw XML to legacy history while retaining each existing source baseline', () => {
  const api = loadTabMigrationHelpers();
  const legacy = snapshot({ width: 2000, height: 2000 });
  const line1 = '<?xml version="1.0" encoding="UTF-16"?>';
  const line2 = '<ImageDesign><SubImage><Field Name="Saved" Vendor="keep"/></SubImage></ImageDesign>';
  const oldSource = { line1, line2: '<ImageDesign><SubImage><Field Name="BeforeRename"/></SubImage></ImageDesign>' };
  const recorded = JSON.stringify({ ...JSON.parse(legacy), sourceXml: oldSource });
  const original = storedTabPayload({ version: 3, line1, line2, editorSnapshot: legacy, undo: [legacy, recorded], redo: [legacy] });
  const migrated = api.migrateStoredTemplateTabsPayload(original);
  const tab = migrated.tabs[0];

  for (const value of [tab.templateState.editorSnapshot, tab.templateState.history.undo[0], tab.templateState.history.redo[0]]) {
    assert.deepEqual(JSON.parse(value).sourceXml, { line1, line2 });
  }
  assert.equal(tab.templateState.history.undo[1], recorded);
  assert.equal(tab.savedFingerprint, original.tabs[0].savedFingerprint);
  assert.equal(tab.isDirty, false);
  assert.equal(original.tabs[0].templateState.history.undo[0], legacy, 'migration must not alter its input');
});

test('v1 and v2 history migrations attach the source XML without changing existing per-snapshot sources', () => {
  const api = loadTabMigrationHelpers();
  const line1 = '<?xml version="1.0" encoding="UTF-16"?>';
  const line2 = '<ImageDesign><SubImage/></ImageDesign>';
  const legacy = snapshot({ width: 2000, height: 2000 });
  for (const version of [1, 2]) {
    const migrated = api.migrateStoredTemplateTabsPayload(storedTabPayload({
      version, line1, line2, editorSnapshot: legacy, undo: [legacy], redo: [legacy],
    }));
    const state = migrated.tabs[0].templateState;
    for (const value of [state.editorSnapshot, state.history.undo[0], state.history.redo[0]]) {
      assert.deepEqual(JSON.parse(value).sourceXml, { line1, line2 });
    }
  }
});

test('source XML snapshot bookkeeping does not mark an unchanged saved tab dirty', () => {
  const api = loadTabMigrationHelpers();
  const filename = path.join(__dirname, '..', 'public', 'modules', '70-template-tabs.js');
  const source = fs.readFileSync(filename, 'utf8');
  const start = source.indexOf('function createCurrentTemplateContentFingerprint');
  const end = source.indexOf('function captureCurrentTemplateView', start);
  const raw = { line1: '<?xml version="1.0" encoding="UTF-16"?>', line2: '<ImageDesign><SubImage/></ImageDesign>' };
  const editor = {
    docMeta: {}, subImage: {}, dateOffsets: [], dateOffsetsLoaded: false, dateOffsetsDirty: false,
    fields: [], gridMm: 1,
  };
  api.state = { ...raw, xmlDoc: {} };
  api.snapshotState = () => JSON.stringify({ sourceXml: raw, ...editor });
  vm.runInContext(source.slice(start, end), api, { filename });

  const legacyFingerprint = api.createPersistedTemplateFingerprint({ raw, editorSnapshot: JSON.stringify(editor) });
  assert.equal(api.createCurrentTemplateContentFingerprint(), legacyFingerprint);
  api.state.line2 = '<ImageDesign><SubImage ImageReference="2"/></ImageDesign>';
  assert.notEqual(api.createCurrentTemplateContentFingerprint(), legacyFingerprint, 'real raw XML changes must still mark the tab dirty');
});

test('capturing a tab upgrades legacy history and preserves newer history sources', () => {
  const api = loadTabMigrationHelpers();
  const filename = path.join(__dirname, '..', 'public', 'modules', '70-template-tabs.js');
  const source = fs.readFileSync(filename, 'utf8');
  const start = source.indexOf('function captureCurrentTemplateState');
  const end = source.indexOf('function captureActiveTemplateTab', start);
  const raw = { line1: '<?xml version="1.0" encoding="UTF-16"?>', line2: '<ImageDesign><SubImage/></ImageDesign>' };
  const legacy = snapshot({ width: 2000, height: 2000 });
  const recorded = JSON.stringify({ ...JSON.parse(legacy), sourceXml: { ...raw, line2: '<ImageDesign/>' } });
  api.state = { ...raw, xmlText: raw.line1 + '\n' + raw.line2 };
  api.history = { undo: [legacy, recorded], redo: [legacy] };
  api.snapshotState = () => legacy;
  api.captureCurrentTemplateView = () => ({});
  vm.runInContext(source.slice(start, end), api, { filename });
  const captured = api.captureCurrentTemplateState();

  assert.deepEqual(JSON.parse(captured.history.undo[0]).sourceXml, raw);
  assert.deepEqual(JSON.parse(captured.history.redo[0]).sourceXml, raw);
  assert.equal(captured.history.undo[1], recorded);
  assert.equal(api.history.undo[0], legacy);
});

test('legacy tab migration removes invented Ln only where the direct source field omitted it', () => {
  const api = loadTabMigrationHelpers();
  const line2 = '<ImageDesign><SubImage>' +
    '<Field Name="Absent"><Vendor><Ln>1</Ln></Vendor></Field>' +
    '<Field Name="Zero"><Ln>0</Ln></Field><Field Name="One"><Ln>1</Ln></Field>' +
    '</SubImage></ImageDesign>';
  const editor = {
    docMeta: {}, subImage: {}, dateOffsets: [], dateOffsetsLoaded: false, dateOffsetsDirty: false, gridMm: 1,
    fields: [
      { sourceName: 'Absent', name: 'Absent', ln: 1 },
      { sourceName: 'Zero', name: 'Zero', ln: 0 },
      { sourceName: 'One', name: 'One', ln: 1 },
      { sourceName: null, name: 'New', ln: 1 },
    ],
  };
  const legacy = JSON.stringify(editor);
  const intentional = JSON.stringify({ ...editor, sourceXml: { line1: '<?xml version="1.0" encoding="UTF-16"?>', line2 } });
  for (const version of [1, 2, 3]) {
    const migrated = api.migrateStoredTemplateTabsPayload(storedTabPayload({
      version, line2, editorSnapshot: legacy, undo: [legacy, intentional], redo: [legacy],
    }));
    const tab = migrated.tabs[0];
    for (const value of [tab.templateState.editorSnapshot, tab.templateState.history.undo[0], tab.templateState.history.redo[0]]) {
      assert.deepEqual(JSON.parse(value).fields.map(field => field.ln), [null, 0, 1, 1]);
    }
    assert.equal(tab.templateState.history.undo[1], intentional, 'new source-aware snapshots preserve explicit Ln edits');
    assert.equal(tab.isDirty, false);
    assert.equal(tab.savedFingerprint, api.createPersistedTemplateFingerprint(tab.templateState));
  }
});

function dimensionSource(width = 1600, height = 1600) {
  return '<ImageDesign><Header DesignedFor="DataFlex 6320(32mm) - Continuous"/>' +
    '<SubImage><SubHeader><ImageWidth>2516</ImageWidth><ImageHeight>2558</ImageHeight>' +
    `<MaxImageWidth>${width}</MaxImageWidth><MaxImageHeight>${height}</MaxImageHeight>` +
    '</SubHeader></SubImage></ImageDesign>';
}

test('v3 migration persists an Image fallback instead of retaining a stale profile repair', () => {
  const api = loadTabMigrationHelpers();
  const raw = dimensionSource().replace(/<MaxImage(?:Width|Height)>[^<]*<\/MaxImage(?:Width|Height)>/g, '');
  const imported = snapshot({ width: 2516, height: 2558, maxWidth: 5333, maxHeight: 7500, workspaceWidth: 2516, workspaceHeight: 2558 });
  const migrated = api.migrateStoredTemplateTabsPayload(storedTabPayload({ version: 3, line2: raw, editorSnapshot: imported }));
  const dimensions = JSON.parse(migrated.tabs[0].templateState.editorSnapshot).subImage;
  assert.deepEqual([dimensions.workspaceWidth, dimensions.workspaceHeight], [2516, 2558]);
  assert.deepEqual([dimensions.maxWidth, dimensions.maxHeight], [2516, 2558]);
});

test('v3 sessions restore 16 x 16 mm from Max instead of stale 25.16 x 25.58 workspace', () => {
  const api = loadTabMigrationHelpers();
  const originalSnapshot = JSON.stringify({
    docMeta: { printerModel: 'DataFlex 6320(32mm)', designedFor: 'DataFlex 6320(32mm) - Continuous' },
    subImage: { width: 2516, height: 2558, maxWidth: 1600, maxHeight: 1600, workspaceWidth: 2516, workspaceHeight: 2558, orientation: 90 },
    fields: [{ sourceName: null, name: 'Pending', geom: { x: 42, y: 83, w: 100, h: 200 } }],
    selectedName: 'Pending',
  });
  const original = storedTabPayload({ version: 3, line2: dimensionSource(), editorSnapshot: originalSnapshot, undo: [originalSnapshot], redo: [originalSnapshot] });
  original.tabs[0].templateState.view = { zoomPct: 250, stageX: 20, stageY: 30 };
  const migrated = api.migrateStoredTemplateTabsPayload(original);
  const tab = migrated.tabs[0];
  const current = JSON.parse(tab.templateState.editorSnapshot);
  assert.equal(migrated.version, 4);
  assert.equal(current.subImage.workspaceWidth, 1600);
  assert.equal(current.subImage.workspaceHeight, 1600);
  assert.equal(current.subImage.width, 2516);
  assert.equal(current.subImage.height, 2558);
  assert.equal(current.subImage.orientation, 90);
  assert.deepEqual(current.fields, JSON.parse(originalSnapshot).fields);
  assert.equal(current.selectedName, 'Pending');
  assert.deepEqual(tab.templateState.view, original.tabs[0].templateState.view);
  assert.equal(tab.templateState.raw.line2, dimensionSource());
  assert.equal(tab.isDirty, false);
  assert.equal(tab.savedFingerprint, api.createPersistedTemplateFingerprint(tab.templateState));
  for (const branch of ['undo', 'redo']) {
    const entry = JSON.parse(tab.templateState.history[branch][0]);
    assert.equal(entry.subImage.workspaceWidth, 1600);
    assert.equal(entry.subImage.workspaceHeight, 1600);
  }
  assert.equal(original.tabs[0].templateState.editorSnapshot, originalSnapshot);
  assert.deepEqual(api.migrateStoredTemplateTabsPayload(migrated), migrated, 'v4 migration is idempotent');
});

test('v3 migration preserves a distinguishable user resize on each axis and makes it serializable', () => {
  const api = loadTabMigrationHelpers();
  for (const [workspaceWidth, workspaceHeight, expectedWidth, expectedHeight] of [
    [2000, 3000, 2000, 3000],
    [2000, 2558, 2000, 1600],
    [2516, 3000, 1600, 3000],
  ]) {
    const edited = snapshot({ width: 2516, height: 2558, maxWidth: 1600, maxHeight: 1600, workspaceWidth, workspaceHeight });
    const migrated = api.migrateStoredTemplateTabsPayload(storedTabPayload({ version: 3, line2: dimensionSource(), editorSnapshot: edited, isDirty: true }));
    const tab = migrated.tabs[0];
    const current = JSON.parse(tab.templateState.editorSnapshot).subImage;
    assert.equal(current.workspaceWidth, expectedWidth);
    assert.equal(current.workspaceHeight, expectedHeight);
    assert.equal(current.maxWidth, expectedWidth);
    assert.equal(current.maxHeight, expectedHeight);
    assert.equal(current.width, 2516);
    assert.equal(current.height, 2558);
    assert.equal(tab.isDirty, true);
    assert.equal(tab.savedFingerprint, null);
  }
});

test('dimension migration resolves undo and redo from their own XML baseline across saves', () => {
  const api = loadTabMigrationHelpers();
  const line1 = '<?xml version="1.0" encoding="UTF-16"?>';
  const subImage = { width: 2516, height: 2558, maxWidth: 1600, maxHeight: 1600, workspaceWidth: 2516, workspaceHeight: 2558 };
  const previous = JSON.stringify({ subImage, sourceXml: { line1, line2: dimensionSource(2000, 3000) } });
  const current = JSON.stringify({ subImage, sourceXml: { line1, line2: dimensionSource(3000, 2000) } });
  const migrated = api.migrateStoredTemplateTabsPayload(storedTabPayload({ version: 3, line1, line2: dimensionSource(3000, 2000), editorSnapshot: current, undo: [previous], redo: [current] }));
  const state = migrated.tabs[0].templateState;
  assert.equal(JSON.parse(state.editorSnapshot).subImage.workspaceWidth, 3000);
  assert.equal(JSON.parse(state.editorSnapshot).subImage.workspaceHeight, 2000);
  assert.equal(JSON.parse(state.history.undo[0]).subImage.workspaceWidth, 2000);
  assert.equal(JSON.parse(state.history.undo[0]).subImage.workspaceHeight, 3000);
  assert.equal(JSON.parse(state.history.redo[0]).subImage.workspaceWidth, 3000);
  assert.equal(JSON.parse(state.history.redo[0]).subImage.workspaceHeight, 2000);
  assert.equal(JSON.parse(state.history.undo[0]).sourceXml.line2, dimensionSource(2000, 3000));
});

test('v4 tabs recover YRes and literal Max zero from each snapshot source', () => {
  const api = loadTabMigrationHelpers();
  const raw = '<ImageDesign><Header/><SubImage><SubHeader>' +
    '<ImageWidth>600</ImageWidth><ImageHeight>700</ImageHeight>' +
    '<MaxImageWidth>0</MaxImageWidth><MaxImageHeight>2400</MaxImageHeight>' +
    '<XRes>0.12</XRes><YRes>0.24</YRes></SubHeader></SubImage></ImageDesign>';
  const legacy = snapshot({
    width: 600, height: 700, maxWidth: 600, maxHeight: 2400,
    workspaceWidth: 600, workspaceHeight: 2400, xRes: 0.12,
  });
  const earlier = JSON.parse(legacy);
  earlier.sourceXml = { line1: '<?xml version="1.0"?>', line2: raw.replace('0.24', '0.18') };
  const original = storedTabPayload({ version: 4, line2: raw, editorSnapshot: legacy, undo: [JSON.stringify(earlier)] });
  const migrated = api.migrateStoredTemplateTabsPayload(original);
  const current = JSON.parse(migrated.tabs[0].templateState.editorSnapshot);
  const undo = JSON.parse(migrated.tabs[0].templateState.history.undo[0]);
  assert.equal(current.subImage.yRes, 0.24);
  assert.equal(undo.subImage.yRes, 0.18);
  assert.equal(current.subImage.maxWidth, 0);
  assert.equal(current.subImage.workspaceWidth, 0);
  assert.equal(current.docMeta.units, 0);
  assert.equal(migrated.tabs[0].isDirty, false);
  assert.deepEqual(api.migrateStoredTemplateTabsPayload(migrated), migrated);
  assert.equal(JSON.parse(original.tabs[0].templateState.editorSnapshot).subImage.maxWidth, 600);
});

test('geometry metadata migration retains explicit resolution and user workspace changes', () => {
  const api = loadTabMigrationHelpers();
  const raw = '<ImageDesign><Header/><SubImage><SubHeader>' +
    '<ImageWidth>600</ImageWidth><ImageHeight>700</ImageHeight>' +
    '<MaxImageWidth>0</MaxImageWidth><MaxImageHeight>2400</MaxImageHeight>' +
    '<XRes>0.12</XRes><YRes>0.24</YRes></SubHeader></SubImage></ImageDesign>';
  const edited = snapshot({
    width: 600, height: 700, maxWidth: 500, maxHeight: 2400,
    workspaceWidth: 500, workspaceHeight: 2400, xRes: 0.12, yRes: 0.3,
  });
  const migrated = api.migrateStoredTemplateTabsPayload(storedTabPayload({
    version: 4, line2: raw, editorSnapshot: edited, isDirty: true,
  }));
  const current = JSON.parse(migrated.tabs[0].templateState.editorSnapshot);
  assert.equal(current.subImage.yRes, 0.3);
  assert.equal(current.subImage.workspaceWidth, 500);
  assert.equal(current.subImage.maxWidth, 500);
  assert.equal(migrated.tabs[0].isDirty, true);
});
