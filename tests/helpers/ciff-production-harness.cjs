const crypto = require('node:crypto');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

const { parseXml } = require('../../scripts/compare-ciff-structure.cjs');

const PROJECT_ROOT = path.join(__dirname, '..', '..');
const COMPATIBILITY_MODULE = path.join(PROJECT_ROOT, 'public', 'modules', '01-ciff-compatibility.js');
const FONTS_MODULE = path.join(PROJECT_ROOT, 'public', 'modules', '02-fonts.js');
const CLST_ENCRYPTION_MODULE = path.join(PROJECT_ROOT, 'public', 'modules', 'clst', 'encryption.js');
const CLST_TAG_DATA_MODULE = path.join(PROJECT_ROOT, 'public', 'modules', 'clst', 'tag-data.js');
const CLST_VERSION_INFO_MODULE = path.join(PROJECT_ROOT, 'public', 'modules', 'clst', 'version-info.js');
const XML_LOAD_MODULE = path.join(PROJECT_ROOT, 'public', 'modules', '20-xml-load.js');
const RENDERING_MODULE = path.join(PROJECT_ROOT, 'public', 'modules', '30-rendering.js');
const SAVE_MODULE = path.join(PROJECT_ROOT, 'public', 'modules', '60-history-save.js');

const DATA_MATRIX_SYMBOLS_BY_NAME = new Map([
  ['20X20', { name: '20X20', symbolRows: 20, symbolCols: 20, dataCodewords: 22 }],
  ['22X22', { name: '22X22', symbolRows: 22, symbolCols: 22, dataCodewords: 30 }],
  ['36X36', { name: '36X36', symbolRows: 36, symbolCols: 36, dataCodewords: 86 }],
]);
const DATA_MATRIX_SYMBOLS = Array.from(DATA_MATRIX_SYMBOLS_BY_NAME.values());
const DATA_MATRIX_MODULE_SIZES = Array.from(
  { length: 60 },
  (_, index) => Number((((index + 1) / 12)).toFixed(2)),
);
const DM_HELPER_NAMES = Object.freeze({
  C1: 'C1',
  GTIN: 'GTIN',
  C2: 'C2',
  SN: 'SN',
  C3: 'C3',
  KRIPTO: 'KRIPTO',
  C4: 'C4',
  KRIPTO2: 'KRIPTO2',
});
const DM_HELPER_MAX_CHARS = Object.freeze({
  C1: 4,
  GTIN: 14,
  C2: 2,
  C3: 7,
  KRIPTO: 4,
  C4: 7,
  KRIPTO2: 44,
});

function sha256(bytes) {
  return crypto.createHash('sha256').update(bytes).digest('hex').toUpperCase();
}

function elementChildren(node) {
  return (node?.children || []).filter((child) => child.type === 'element');
}

function descendantElements(node) {
  const result = [];
  elementChildren(node).forEach((child) => {
    result.push(child, ...descendantElements(child));
  });
  return result;
}

function textContent(node) {
  return (node?.children || []).map((child) => {
    if (child.type === 'text' || child.type === 'cdata') return child.value;
    if (child.type === 'element') return textContent(child);
    return '';
  }).join('');
}

function selectNodes(scopeNode, selector, includeScopeChildren = false) {
  const parts = String(selector).split('>').map((part) => part.trim()).filter(Boolean);
  if (!parts.length) return [];

  let candidates;
  let index;
  if (parts[0] === ':scope') {
    candidates = [scopeNode];
    index = 1;
  } else {
    const searchable = includeScopeChildren
      ? elementChildren(scopeNode).flatMap((child) => [child, ...descendantElements(child)])
      : descendantElements(scopeNode);
    candidates = searchable.filter((node) => node.name === parts[0]);
    index = 1;
  }

  for (; index < parts.length; index += 1) {
    const name = parts[index];
    candidates = candidates.flatMap((node) => elementChildren(node).filter((child) => child.name === name));
  }
  return candidates;
}

class CiffElement {
  constructor(node) {
    this.node = node;
  }

  get tagName() {
    return this.node.name;
  }

  get children() {
    return elementChildren(this.node).map((node) => new CiffElement(node));
  }

  get textContent() {
    return textContent(this.node);
  }

  getAttribute(name) {
    return this.node.attributes.find((attribute) => attribute.name === name)?.value ?? null;
  }

  querySelector(selector) {
    return this.querySelectorAll(selector)[0] ?? null;
  }

  querySelectorAll(selector) {
    return selectNodes(this.node, selector, false).map((node) => new CiffElement(node));
  }

  getElementsByTagName(name) {
    return this.querySelectorAll(name);
  }
}

class CiffDocument {
  constructor(root) {
    this.node = { type: 'document', children: [root] };
  }

  querySelector(selector) {
    return this.querySelectorAll(selector)[0] ?? null;
  }

  querySelectorAll(selector) {
    return selectNodes(this.node, selector, true).map((node) => new CiffElement(node));
  }

  getElementsByTagName(name) {
    return this.querySelectorAll(name);
  }
}

class CiffParserErrorDocument {
  constructor(error) {
    this.errorElement = { textContent: error instanceof Error ? error.message : String(error) };
  }

  querySelector(selector) {
    return selector === 'parsererror' ? this.errorElement : null;
  }

  querySelectorAll(selector) {
    return selector === 'parsererror' ? [this.errorElement] : [];
  }

  getElementsByTagName(name) {
    return this.querySelectorAll(name);
  }
}

class ComparatorDomParser {
  parseFromString(xml) {
    try {
      return new CiffDocument(parseXml(String(xml)));
    } catch (error) {
      return new CiffParserErrorDocument(error);
    }
  }
}

function normalizeDataMatrixModuleSizeValue(value) {
  let size = Number.parseFloat(String(value ?? ''));
  if (!Number.isFinite(size)) size = 0.5;
  if (size > 5) size /= 100;
  size = Math.max(DATA_MATRIX_MODULE_SIZES[0], Math.min(DATA_MATRIX_MODULE_SIZES.at(-1), size));

  let nearest = DATA_MATRIX_MODULE_SIZES[0];
  DATA_MATRIX_MODULE_SIZES.forEach((option) => {
    if (Math.abs(option - size) < Math.abs(nearest - size)) nearest = option;
  });
  return Number(nearest.toFixed(2));
}

function normalizeDataMatrixSymbolSizeValue(value, fallback = 'Auto') {
  const raw = String(value ?? '').trim();
  if (!raw) return fallback;
  const normalized = raw.toUpperCase();
  if (normalized === 'AUTO') return 'Auto';
  return DATA_MATRIX_SYMBOLS_BY_NAME.get(normalized)?.name ?? normalized;
}

function getTextEntryMode(field) {
  const explicit = String(field?.data?.textEntryMode ?? '').trim().toLowerCase();
  if (explicit === 'user' || explicit === 'fixed') return explicit;
  if (field?.data?.hasVarText) return 'user';
  if (
    field?.fldType === 'FixedText' &&
    field?.data?.staticAttr === '0' &&
    (((field.data.userEnterData ?? '') !== '') || ((field.data.mask ?? '') !== ''))
  ) return 'user';
  return 'fixed';
}

function isUserEnteredTextField(field) {
  return field?.fldType === 'FixedText' && getTextEntryMode(field) === 'user';
}

function wantsVarTextStructure(field) {
  if (!field?.data) return false;
  if (field.fldType === 'FixedText') return isUserEnteredTextField(field);
  return ((field.data.userEnterData ?? '') !== '') || ((field.data.mask ?? '') !== '');
}

function getStoredTextFieldValue(field) {
  if (!field) return '';
  if (isUserEnteredTextField(field)) {
    return field.data.userEnterData || field.data.defaultValue || field.calcData || '';
  }
  return field.calcData || field.data?.defaultValue || field.data?.userEnterData || '';
}

function synchronizeAllDataMatrixDerivedState(fields, fieldByName = null) {
  const list = Array.isArray(fields) ? fields : [];
  const lookup = fieldByName || new Map(list.map((field) => [field.name, field]));
  let changed = false;

  list.forEach((field) => {
    const segments = field?.barcode?.dataMatrix?.segments;
    if (!Array.isArray(segments)) return;
    segments.forEach((segment, index) => {
      if (segment.index !== index) {
        segment.index = index;
        changed = true;
      }
      const source = segment.srcField ? lookup.get(segment.srcField) : null;
      const value = String(source ? getStoredTextFieldValue(source) : (segment.defaultValue ?? ''));
      if (String(segment.defaultValue ?? '') !== value) {
        segment.defaultValue = value;
        changed = true;
      }
    });
    const calcData = segments.map((segment) => String(segment.defaultValue ?? '')).join('');
    if (String(field.calcData ?? '') !== calcData) {
      field.calcData = calcData;
      changed = true;
    }
  });
  return changed;
}

function normalizeTextPitchValue(value) {
  if (value == null || value === '') return null;
  const next = Math.round(Number(value));
  return Number.isFinite(next) && next > 0 ? next : null;
}

function getEffectiveTextPitch(field, fallback = 10) {
  const explicit = normalizeTextPitchValue(field?.text?.pitch);
  const height = Number(field?.geom?.h);
  const inferred = Number.isFinite(height) && height > 0 ? Math.round((height / 100) / 0.4) : null;
  if (explicit == null) return normalizeTextPitchValue(field?.text?.defaultPitch) ?? (inferred > 0 ? inferred : fallback);
  return explicit;
}

function getDataMatrixHelperMaxChars(name, value = null) {
  if (name === DM_HELPER_NAMES.SN) {
    const selectedLength = String(value ?? '').length;
    if (selectedLength === 6 || selectedLength === 13) return selectedLength;
  }
  return DM_HELPER_MAX_CHARS[name] ?? null;
}

function makeInitialState() {
  return {
    xmlDoc: null,
    xmlText: '',
    line1: '',
    line2: '',
    lineEnding: '\r\n',
    docMeta: {
      version: null,
      designedFor: '',
      clStVersionInfo: '',
      printerModel: '',
      printMode: '',
    },
    subImage: {
      imageReference: '1',
      width: 0,
      height: 0,
      maxWidth: 0,
      maxHeight: 0,
      xRes: 0,
      orientation: 0,
      usedSizeDirty: false,
    },
    dateOffsets: [],
    dateOffsetsLoaded: false,
    dateOffsetsDirty: false,
    fields: [],
    fieldByName: new Map(),
    validation: {
      invalidPrintableFieldNames: [],
      invalidHardwareFieldNames: [],
      structuralErrors: [],
    },
  };
}

function decodeCiffBytes(bytes) {
  const input = Buffer.from(bytes);
  if (input[0] !== 0xff || input[1] !== 0xfe) {
    throw new Error('Regression harness expects a UTF-16LE CIFF with an FF FE BOM.');
  }
  return input.subarray(2).toString('utf16le');
}

function createProductionCiffRuntime(bytes, options = {}) {
  const state = makeInitialState();
  const context = {
    console,
    glyphSystemTickCount: options.getTickCount ?? (() => 0),
    state,
    history: { undo: [], redo: [] },
    DOMParser: ComparatorDomParser,
    Blob,
    INTERNAL_PER_MM: 100,
    GRID_SIZE_OPTIONS: [1, 3, 5, 10],
    ALLOWED_ORIENTATIONS: [0, 90, 180, 270],
    PRINTER_CAPABILITIES: {
      'DataFlex 6320(32mm)': {
        maxImageWidth: 3200,
        maxImageHeight: 7500,
        xRes: 0.12,
        xResText: '0.120000',
      },
      'DataFlex 6330(53mm)': {
        maxImageWidth: 5333,
        maxImageHeight: 7500,
        xRes: 0.12,
        xResText: '0.120000',
      },
    },
    DATA_MATRIX_SYMBOLS,
    DATA_MATRIX_SYMBOLS_BY_NAME,
    DATA_MATRIX_MODULE_SIZES,
    DM_COMPOSITIONS: {},
    DM_HELPER_NAMES,
    DM_HELPER_SPECS: {},
    appLogger: { file: () => {}, state: () => {}, log: () => {}, action: () => {} },
    normalizePrintMode: (value) => {
      const raw = String(value ?? '').trim().toLowerCase();
      return raw === 'intermittent' ? 'Intermittent' : 'Continuous';
    },
    normalizePrinterModel: (value) => String(value ?? '').trim(),
    buildDesignedForLabel: (model, mode) => `${String(model).trim()} - ${String(mode).trim()}`,
    normalizeDataMatrixModuleSizeValue,
    normalizeDataMatrixSymbolSizeValue,
    serializeDataMatrixModuleSize: (value) => String(Math.round(normalizeDataMatrixModuleSizeValue(value) * 100)),
    normalizeTimeFormat: (value) => String(value ?? '').replace(/'/g, ''),
    DATE_MONTH_NAMES: {
      en: ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'],
      ru: ['янв', 'фев', 'мар', 'апр', 'май', 'июн', 'июл', 'авг', 'сен', 'окт', 'ноя', 'дек'],
    },
    inferDateLocale: (fldType, formatValue, calcData) => {
      if (fldType !== 'DateText' && fldType !== 'OffsetDateText') return null;
      if (!/MMM/.test(String(formatValue ?? '').replace(/'/g, ''))) return 'en';
      return /[\u0410-\u042f\u0430-\u044f\u0401\u0451]/u.test(calcData || '') ? 'ru' : 'en';
    },
    normalizeCounterField: () => {},
    mmToInternal: (value) => Math.round(Number(value) * 100),
    mmToPx: (value) => Number(value) * 12,
    pxToMm: (value) => Number(value) / 12,
    internalToMm: (value) => Number(value) / 100,
    getStoredTextFieldValue,
    getEffectiveTextPitch,
    getDataMatrixHelperMaxChars,
    isUserEnteredTextField,
    wantsVarTextStructure,
    synchronizeAllDataMatrixDerivedState,
    syncUsedImageSizeFromPrintableFields: () => {},
    validatePrintableFieldsInsideArea: () => ({ invalidPrintableFieldNames: [] }),
    validateHardwareFieldsInsideArea: () => ({ invalidHardwareFieldNames: [] }),
    getSelectedNames: () => [],
    setSelectedNames: () => {},
    t: (key) => key,
    openNotificationModal: () => {},
    document: {
      createElement: () => ({ click: () => {}, remove: () => {} }),
      body: { appendChild: () => {} },
      querySelector: () => null,
    },
    window: { devicePixelRatio: 1, setInterval: () => 0 },
    URL: {
      createObjectURL: () => 'blob:test',
      revokeObjectURL: () => {},
    },
    setTimeout: (callback) => callback(),
  };
  context.globalThis = context;
  vm.createContext(context);

  vm.runInContext(fs.readFileSync(COMPATIBILITY_MODULE, 'utf8'), context, { filename: COMPATIBILITY_MODULE });
  vm.runInContext(fs.readFileSync(FONTS_MODULE, 'utf8'), context, { filename: FONTS_MODULE });
  vm.runInContext(fs.readFileSync(CLST_ENCRYPTION_MODULE, 'utf8'), context, { filename: CLST_ENCRYPTION_MODULE });
  vm.runInContext(fs.readFileSync(CLST_TAG_DATA_MODULE, 'utf8'), context, { filename: CLST_TAG_DATA_MODULE });
  const calculatedDataModule = path.join(PROJECT_ROOT, 'public/modules/clst/calculated-data.js');
  vm.runInContext(fs.readFileSync(calculatedDataModule, 'utf8'), context, { filename: calculatedDataModule });
  vm.runInContext(fs.readFileSync(CLST_VERSION_INFO_MODULE, 'utf8'), context, { filename: CLST_VERSION_INFO_MODULE });
  vm.runInContext(fs.readFileSync(XML_LOAD_MODULE, 'utf8'), context, { filename: XML_LOAD_MODULE });
  vm.runInContext(fs.readFileSync(RENDERING_MODULE, 'utf8'), context, { filename: RENDERING_MODULE });
  context.validatePrintableFieldsInsideArea = () => ({ invalidPrintableFieldNames: [] });
  context.validateHardwareFieldsInsideArea = () => ({ invalidHardwareFieldNames: [] });
  vm.runInContext(fs.readFileSync(SAVE_MODULE, 'utf8'), context, { filename: SAVE_MODULE });
  const parserApi = vm.runInContext('({ splitTwoLines, parseHeader, parseSubHeader, parseFields })', context);
  const saveApi = vm.runInContext(`({
    prepareCiffForSave,
    patchXmlLosslessV2Preview,
    buildCiffOutputText,
    encodeUtf16leWithBom,
    commitPreparedCiffToState
  })`, context);

  const sourceText = decodeCiffBytes(bytes);
  const { line1, line2 } = parserApi.splitTwoLines(sourceText);
  const doc = new ComparatorDomParser().parseFromString(`${line1}\n${line2}`, 'text/xml');
  const parseError = doc.querySelector('parsererror');
  if (parseError) throw new Error(parseError.textContent);

  state.line1 = line1;
  state.line2 = line2;
  state.xmlText = `${line1}\n${line2}`;
  state.xmlDoc = doc;
  parserApi.parseHeader(doc, { sourceFileName: options.sourcePath });
  parserApi.parseSubHeader(doc);
  parserApi.parseFields(doc);

  function save(now = new Date(2026, 7, 20, 12, 0, 0, 0), saveOptions = {}) {
    const prepared = saveApi.prepareCiffForSave(now, saveOptions);
    const outputBytes = Buffer.from(new Uint8Array(saveApi.encodeUtf16leWithBom(prepared.outputText)));
    if (prepared.validation.ok) saveApi.commitPreparedCiffToState(prepared);
    return { prepared, bytes: outputBytes, sha256: sha256(outputBytes) };
  }

  return { context, state, parserApi, saveApi, save, sourceText };
}

module.exports = {
  ComparatorDomParser,
  createProductionCiffRuntime,
  decodeCiffBytes,
  sha256,
};
