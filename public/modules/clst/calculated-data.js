// Resolve once for a save, then use the same raw UTF-16 value for ClSt and
// CalcData. XML filtering belongs after this snapshot, not in the ClSt input.
function getCiffPreparedCalculatedData(field, values) {
  if (!values || typeof values.has !== "function" || typeof values.get !== "function") return undefined;
  if (values.has(field)) return values.get(field);
  if (field?.name != null && values.has(field.name)) return values.get(field.name);
  return undefined;
}

function getCiffCalculatedDataLookupField(lookup, name) {
  if (!lookup || !name) return null;
  if (typeof lookup.get === "function") return lookup.get(name) ?? null;
  if (Array.isArray(lookup)) return lookup.find((field) => field?.name === name) ?? null;
  return lookup[name] ?? null;
}

function getCiffStoredCalculatedData(field) {
  if (field && Object.prototype.hasOwnProperty.call(field, "calcData") && field.calcData != null) {
    return String(field.calcData).split("\0", 1)[0];
  }
  if (field?.data?.defaultValue != null) return String(field.data.defaultValue).split("\0", 1)[0];
  return null;
}

// CiffHelper!40805870: zero-based UTF-16 selection; count 0 means the rest.
// SelectMode != 0 measures the starting offset from the right-hand side.
function selectCiffSourceFieldData(value, source = {}) {
  const text = String(value ?? "");
  const start = Math.max(0, Math.trunc(Number(source.startChar ?? source.startCharacter) || 0));
  if (start >= text.length) return "";
  const requested = Math.max(0, Math.trunc(Number(source.noOfChars ?? source.numberOfCharacters) || 0));
  const count = Math.min(requested || text.length, text.length - start);
  const mode = source.selectMode ?? source.selectionMode ?? 0;
  const fromRight = mode === "Right" || (Number.isFinite(Number(mode)) && Number(mode) !== 0);
  const offset = fromRight ? text.length - start - count : start;
  return text.slice(offset, offset + count);
}

// CiffHelper!4080E4BE pads only nonstatic fixed/user text. MaximumCharacters
// does not truncate long values. Native "Right" aligns the text on the right.
function padCiffFixedLengthData(value, data = {}) {
  const text = String(value ?? "");
  if (data.fixedLen !== true || String(data.staticAttr ?? "1") !== "0") return text;
  const length = Math.max(0, Math.trunc(Number(data.maxChars) || 0));
  if (length <= text.length) return text;
  const rawPad = data.padChar ?? data.fixedLenPadChar ?? " ";
  const pad = typeof rawPad === "number"
    ? String.fromCharCode(rawPad & 0xFFFF)
    : (String(rawPad).slice(0, 1) || "\0");
  const mode = data.padMode ?? data.fixedLenPadMode ?? 0;
  const rightAligned = mode === "Right" || (Number.isFinite(Number(mode)) && Number(mode) !== 0);
  const padding = pad.repeat(length - text.length);
  // This native padding branch passes through NUL-terminated std::wstring
  // copying before converting back to BSTR (unlike the ClSt transform itself).
  const copiedText = text.split("\0", 1)[0];
  return (rightAligned ? padding + copiedText : copiedText + padding).split("\0", 1)[0];
}

function resolveCiffFixedDataValue(data, fallback = null) {
  const isVariable = data?.hasVarText === true || data?.textEntryMode === "user";
  const nonstatic = String(data?.staticAttr ?? "1") === "0";
  const value = (isVariable && nonstatic && data.userEnterData != null
    ? String(data.userEnterData)
    : String(data?.defaultValue ?? fallback ?? "")).split("\0", 1)[0];
  return padCiffFixedLengthData(value, data);
}

function canResolveCiffDynamicData(field) {
  const data = field?.data ?? {};
  const expectedType = { TimeText: 1, DateText: 2, OffsetDateText: 3 }[field?.fldType];
  if (expectedType == null || Number(data.dataType) !== expectedType) return false;
  // The editor formatter covers its ordinary date/time presets. Native custom
  // calendars, cl: format specifiers and arbitrary locales need their stored
  // CalculatedData until the corresponding resolver has been reconstructed.
  if (String(data.calendar ?? "") !== "") return false;
  const locale = String(data.locale ?? "").toLowerCase();
  if (locale && !["en", "ru", "en-us", "ru-ru"].includes(locale)) return false;
  const format = String(data.defaultValue ?? "").replace(/'/g, "");
  const tokens = expectedType === 1 ? /HH|hh|h|mm|m|ss|s/g : /yyyy|yy|MMM|MM|dd/g;
  if (!tokens.test(format)) return false;
  tokens.lastIndex = 0;
  return !/[A-Za-z\u0080-\uFFFF]/.test(format.replace(tokens, ""));
}

function resolveCiffDataMatrixSegmentValues(field, now = new Date(), options = {}) {
  const segments = field?.barcode?.dataMatrix?.segments;
  if (!Array.isArray(segments)) return null;
  const segmentCache = options._ciffDataMatrixSegmentCache ?? options.calculatedData?.dataMatrixSegmentValues;
  if (segmentCache?.has(field)) return segmentCache.get(field);
  const lookup = options.fieldByName ?? (typeof state !== "undefined" ? state?.fieldByName : null);
  const ordered = segments.map((segment, order) => ({ segment, order })).sort((a, b) => {
    const aIndex = Number.isFinite(Number(a.segment?.index)) ? Number(a.segment.index) : a.order;
    const bIndex = Number.isFinite(Number(b.segment?.index)) ? Number(b.segment.index) : b.order;
    return (aIndex - bIndex) || (a.order - b.order);
  });
  const values = [];
  for (const { segment } of ordered) {
    const source = segment?.srcField;
    const sourceName = typeof source === "object" && source
      ? String(source.name ?? source.srcFieldName ?? "")
      : String(source ?? "");
    if (sourceName) {
      const sourceField = getCiffCalculatedDataLookupField(lookup, sourceName);
      const value = sourceField ? resolveCiffCalculatedData(sourceField, now, options) : null;
      if (value == null) {
        if (options.strictSource === true) return null;
        values.push(String(segment.defaultValue ?? "").split("\0", 1)[0]);
      } else {
        values.push(selectCiffSourceFieldData(value, typeof source === "object" ? source : segment));
      }
      continue;
    }
    const type = segment?.dataType == null ? 0 : Number(segment.dataType);
    if ([1, 2, 3].includes(type)) {
      const resolver = options.resolveDynamicValue ?? (typeof getDynamicFieldValue === "function" ? getDynamicFieldValue : null);
      const dynamicField = { fldType: { 1: "TimeText", 2: "DateText", 3: "OffsetDateText" }[type], data: segment };
      const value = resolver && canResolveCiffDynamicData(dynamicField)
        ? resolver(dynamicField, now)
        : segment.currentDataValue;
      if (value == null) {
        if (segmentCache) segmentCache.set(field, null);
        return null;
      }
      values.push(String(value).split("\0", 1)[0]);
      continue;
    }
    // External/equipment/unknown segments retain their stored current/default
    // string; local formatting of an unsupported source would invent data.
    values.push(type === 0
      ? resolveCiffFixedDataValue(segment)
      : String(segment?.currentDataValue ?? segment?.defaultValue ?? "").split("\0", 1)[0]);
  }
  if (segmentCache) segmentCache.set(field, values);
  return values;
}

function resolveCiffCalculatedData(field, now = new Date(), options = {}) {
  if (!field) return null;
  const prepared = getCiffPreparedCalculatedData(field, options.calculatedData);
  if (prepared !== undefined) return prepared == null ? null : String(prepared);
  for (const key of ["calculatedData", "CalculatedData"]) {
    if (Object.prototype.hasOwnProperty.call(field, key)) return field[key] == null ? null : String(field[key]);
  }
  if (!["FixedText", "TimeText", "DateText", "OffsetDateText", "CounterText", "Barcode"].includes(field.fldType)) {
    return Object.prototype.hasOwnProperty.call(field, "calcData") && field.calcData != null
      ? String(field.calcData).split("\0", 1)[0]
      : null;
  }
  const cache = options._ciffCalculatedDataCache;
  if (cache?.has(field)) return cache.get(field);
  const visiting = options._ciffCalculatedDataVisiting ?? new Set();
  if (visiting.has(field)) return getCiffStoredCalculatedData(field);
  visiting.add(field);
  const nestedOptions = { ...options, _ciffCalculatedDataVisiting: visiting };
  let value;
  const data = field.data ?? {};
  const dataType = data.dataType == null ? null : Number(data.dataType);
  try {
    if (field.fldType === "Barcode" && field.barcode?.dataMatrix) {
      const values = resolveCiffDataMatrixSegmentValues(field, now, nestedOptions);
      value = values == null ? getCiffStoredCalculatedData(field) : values.join("");
    } else if ((dataType != null && ![0, 1, 2, 3, 4, 5].includes(dataType)) ||
        data.srcData || data.encryption || data.hasMultipleDataObjects) {
      value = getCiffStoredCalculatedData(field);
    } else if (dataType === 5 && data.srcField) {
      const source = data.srcField;
      const name = typeof source === "object" ? source.name ?? source.srcFieldName : source;
      const lookup = options.fieldByName ?? (typeof state !== "undefined" ? state?.fieldByName : null);
      const sourceField = getCiffCalculatedDataLookupField(lookup, name);
      const sourceValue = sourceField ? resolveCiffCalculatedData(sourceField, now, nestedOptions) : null;
      value = sourceValue == null
        ? getCiffStoredCalculatedData(field)
        : selectCiffSourceFieldData(sourceValue, typeof source === "object" ? source : data);
    } else if (["TimeText", "DateText", "OffsetDateText"].includes(field.fldType)) {
      const resolver = options.resolveDynamicValue ?? (typeof getDynamicFieldValue === "function" ? getDynamicFieldValue : null);
      value = resolver && canResolveCiffDynamicData(field) ? resolver(field, now) : getCiffStoredCalculatedData(field);
    } else if (field.fldType === "FixedText" && (dataType == null || dataType === 0)) {
      // Existing static previews remain lossless. Nonstatic data is resolved
      // from Default/UserEnterData before the native fixed-length step.
      const fallback = typeof getStoredTextFieldValue === "function"
        ? getStoredTextFieldValue(field)
        : (field.calcData || data.defaultValue || "");
      value = String(data.staticAttr ?? "1") === "0"
        ? resolveCiffFixedDataValue(data, fallback)
        : String(fallback ?? "");
    } else {
      value = getCiffStoredCalculatedData(field);
    }
  } finally {
    visiting.delete(field);
  }
  // Native data/field property setters use NUL-terminated string copies. This
  // normalization belongs to the model adapter; E can still encrypt NUL in an
  // explicitly supplied prepared CalculatedData value.
  value = value == null ? null : String(value).split("\0", 1)[0];
  if (cache) cache.set(field, value);
  return value;
}

function prepareCiffCalculatedData(fields, now = new Date(), options = {}) {
  const orderedFields = Array.isArray(fields) ? fields : [];
  const values = new Map();
  Object.defineProperty(values, "dataMatrixSegmentValues", { value: new Map() });
  const fieldByName = options.fieldByName ?? new Map(orderedFields.map((field) => [field.name, field]));
  const resolverOptions = {
    ...options, fieldByName, _ciffCalculatedDataCache: values,
    _ciffCalculatedDataVisiting: new Set(), _ciffDataMatrixSegmentCache: values.dataMatrixSegmentValues,
  };
  for (const field of orderedFields) values.set(field, resolveCiffCalculatedData(field, now, resolverOptions));
  return values;
}

// CiffMgr!68124340/6812451F strips these controls after generating ClSt.
function filterCiffCalculatedDataForXml(value) {
  return String(value ?? "").replace(/[\u0000-\u0008\u000B\u000C\u000E-\u001F]/g, "");
}

var CIFF_CALCULATED_DATA_READY = true;
