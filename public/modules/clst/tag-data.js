function getClStLookupField(fieldByName, name) {
  if (!fieldByName || !name) return null;
  if (typeof fieldByName.get === "function") return fieldByName.get(name) ?? null;
  if (Array.isArray(fieldByName)) return fieldByName.find((field) => field?.name === name) ?? null;
  return fieldByName[name] ?? null;
}

function getClStDefaultFieldLookup() {
  return typeof state !== "undefined" ? state?.fieldByName : null;
}

function stringifyClStRuntimeValue(value) {
  return value == null ? null : String(value);
}

function getDataMatrixRuntimeSegmentValues(field, now = new Date(), options = {}) {
  const dataMatrix = field?.barcode?.dataMatrix;
  if (!dataMatrix || !Array.isArray(dataMatrix.segments)) return null;

  const fieldByName = options.fieldByName ?? getClStDefaultFieldLookup();
  const strictSource = options.strictSource === true;
  const resolveFieldValue = typeof options.resolveFieldValue === "function"
    ? options.resolveFieldValue
    : (sourceField) => (
        typeof getFieldDisplayValue === "function"
          ? getFieldDisplayValue(sourceField, now)
          : null
      );
  const orderedSegments = dataMatrix.segments
    .map((segment, sourceOrder) => ({ segment, sourceOrder }))
    .sort((a, b) => {
      const aIndex = Number.isFinite(Number(a.segment?.index)) ? Number(a.segment.index) : a.sourceOrder;
      const bIndex = Number.isFinite(Number(b.segment?.index)) ? Number(b.segment.index) : b.sourceOrder;
      return (aIndex - bIndex) || (a.sourceOrder - b.sourceOrder);
    });

  const values = [];
  for (const { segment } of orderedSegments) {
    const sourceName = String(segment?.srcField ?? "");
    if (!sourceName) {
      values.push(String(segment?.defaultValue ?? ""));
      continue;
    }

    const sourceField = getClStLookupField(fieldByName, sourceName);
    if (!sourceField) {
      if (strictSource) return null;
      values.push(String(segment?.defaultValue ?? ""));
      continue;
    }

    const resolvedValue = resolveFieldValue(sourceField, now);
    if (resolvedValue == null) {
      if (strictSource) return null;
      values.push(String(segment?.defaultValue ?? ""));
      continue;
    }
    values.push(String(resolvedValue));
  }

  return values;
}

function getDataMatrixLogicalValue(field, now = new Date(), options = {}) {
  const values = getDataMatrixRuntimeSegmentValues(field, now, options);
  return values == null ? null : values.join("");
}

function resolveClstTagData(field, now = new Date(), options = {}) {
  if (!field) return null;
  // ClariSoft reads the prepared ICiffField.CalculatedData without filtering
  // field types. Preserve an explicit empty value as well as raw control chars.
  const prepared = options.calculatedData;
  if (prepared && typeof prepared.has === "function" && typeof prepared.get === "function") {
    if (prepared.has(field)) return stringifyClStRuntimeValue(prepared.get(field));
    if (field.name != null && prepared.has(field.name)) return stringifyClStRuntimeValue(prepared.get(field.name));
  }
  if (Object.prototype.hasOwnProperty.call(field, "calculatedData")) {
    return stringifyClStRuntimeValue(field.calculatedData);
  }
  if (Object.prototype.hasOwnProperty.call(field, "CalculatedData")) {
    return stringifyClStRuntimeValue(field.CalculatedData);
  }
  if (!["FixedText", "TimeText", "DateText", "OffsetDateText", "CounterText", "Barcode"].includes(field.fldType)) {
    return Object.prototype.hasOwnProperty.call(field, "calcData")
      ? stringifyClStRuntimeValue(field.calcData)
      : null;
  }
  if (typeof resolveCiffCalculatedData === "function") {
    return stringifyClStRuntimeValue(resolveCiffCalculatedData(field, now, options));
  }
  const seen = options.seen instanceof Set ? options.seen : new Set();
  if (seen.has(field)) return null;
  const nextSeen = new Set(seen);
  nextSeen.add(field);

  switch (field.fldType) {
    case "FixedText":
      return typeof getStoredTextFieldValue === "function"
        ? stringifyClStRuntimeValue(getStoredTextFieldValue(field))
        : null;
    case "TimeText":
      return typeof getTimeTextValue === "function"
        ? stringifyClStRuntimeValue(getTimeTextValue(field, now))
        : null;
    case "DateText":
    case "OffsetDateText":
      return typeof getDateTextValue === "function"
        ? stringifyClStRuntimeValue(getDateTextValue(field, now))
        : null;
    case "CounterText":
      if (typeof getFieldDisplayValue === "function") {
        return stringifyClStRuntimeValue(getFieldDisplayValue(field, now));
      }
      return typeof getStoredTextFieldValue === "function"
        ? stringifyClStRuntimeValue(getStoredTextFieldValue(field))
        : null;
    case "Barcode":
      return getDataMatrixLogicalValue(field, now, {
        fieldByName: options.fieldByName ?? getClStDefaultFieldLookup(),
        strictSource: true,
        resolveFieldValue: (sourceField) => resolveClstTagData(sourceField, now, {
          ...options,
          seen: nextSeen
        })
      });
    default:
      return Object.prototype.hasOwnProperty.call(field, "calcData")
        ? stringifyClStRuntimeValue(field.calcData)
        : null;
  }
}

function buildClStTemplateFromState(editorState) {
  const source = editorState || {};
  const subImages = Array.isArray(source.subImages)
    ? source.subImages.map((subImage) => ({
        ...subImage,
        fields: Array.isArray(subImage?.fields) ? subImage.fields : []
      }))
    : (source.subImage
        ? [{ ...source.subImage, fields: Array.isArray(source.fields) ? source.fields : [] }]
        : []);
  return {
    dateOffsets: Array.isArray(source.dateOffsets) ? source.dateOffsets : [],
    subImages,
    fieldByName: source.fieldByName ?? null
  };
}

function getClStFieldsInCiffOrder(template) {
  if (Array.isArray(template?.subImages)) {
    return template.subImages.flatMap((subImage) => (
      Array.isArray(subImage?.fields) ? subImage.fields : []
    ));
  }
  return Array.isArray(template?.fields) ? template.fields : [];
}

function inspectClStTemplateStructure(template) {
  const fields = getClStFieldsInCiffOrder(template);
  return {
    dateOffsetCount: Array.isArray(template?.dateOffsets)
      ? template.dateOffsets.length
      : Math.max(0, Math.trunc(Number(template?.dateOffsetCount) || 0)),
    subImageCount: Array.isArray(template?.subImages)
      ? template.subImages.length
      : Math.max(0, Math.trunc(Number(template?.subImageCount) || 0)),
    fieldCount: fields.length,
    fields
  };
}

function createClStMaskForSelectedIndex(selectedIndex) {
  if (!Number.isInteger(selectedIndex) || selectedIndex < 0 || selectedIndex >= 32) return 0;
  return (1 << selectedIndex) >>> 0;
}

function formatClStMaskHex(mask) {
  return (Number(mask) >>> 0).toString(16).toUpperCase().padStart(8, "0");
}

function getClStMonotonicTickCount() {
  if (typeof globalThis.glyphSystemTickCount === "function") return globalThis.glyphSystemTickCount();
  // A web-only fallback has runtime uptime rather than Windows system uptime.
  // Desktop/save adapters can supply the actual monotonic GetTickCount source.
  if (typeof globalThis.performance?.now === "function") return Math.floor(globalThis.performance.now());
  throw new Error("ClSt selection requires a monotonic getTickCount provider.");
}

function randomClStIndexFromTick(tick, bound) {
  if (!Number.isInteger(bound) || bound <= 0) throw new Error("ClSt random bound must be positive.");
  if (!Number.isFinite(Number(tick))) throw new Error("ClSt tick count must be finite.");
  const seededState = (Math.imul(Number(tick) >>> 0, 0x343FD) + 0x269EC3) >>> 0;
  return ((seededState >>> 16) & 0x7FFF) % bound;
}

function getClStSelectedFieldIndices(mask) {
  return Array.from({ length: 32 }, (_, index) => index)
    .filter((index) => (((Number(mask) >>> index) & 1) !== 0));
}

function validateClStSelectionMask(value, fieldCount) {
  if (typeof value === "string" && !/^[0-9a-fA-F]{1,8}$/.test(value)) {
    throw new Error("ClSt mask must contain one to eight hexadecimal digits.");
  }
  const mask = typeof value === "string" ? parseInt(value, 16) : Number(value);
  if (!Number.isInteger(mask) || mask < 0 || mask > 0xFFFFFFFF ||
      (fieldCount < 32 && mask >= 2 ** fieldCount)) {
    throw new Error("ClSt mask selects fields outside the first 32 entries.");
  }
  const indices = getClStSelectedFieldIndices(mask);
  if (fieldCount > 0 && (indices.length === 0 || indices.length > 3)) {
    throw new Error("Native ClSt selection requires one to three set bits.");
  }
  return mask >>> 0;
}

function createClStSelectionMask(fields, now = new Date(), options = {}) {
  const orderedFields = Array.isArray(fields) ? fields : [];
  const selectableCount = Math.min(orderedFields.length, 32);
  let mask = 0;
  let attempts = 0;
  if (options.mask != null) {
    mask = validateClStSelectionMask(options.mask, orderedFields.length);
    attempts = null;
  } else if (orderedFields.length > 0) {
    let tickIndex = 0;
    const getTickCount = typeof options.getTickCount === "function" ? options.getTickCount : getClStMonotonicTickCount;
    const nextMod = typeof options.nextMod === "function" ? options.nextMod : (bound) => {
      if (Array.isArray(options.tickCounts)) {
        if (tickIndex >= options.tickCounts.length) throw new Error("Not enough ClSt tickCounts for native RNG calls.");
        return randomClStIndexFromTick(options.tickCounts[tickIndex++], bound);
      }
      return randomClStIndexFromTick(getTickCount(), bound);
    };
    const draw = (bound) => {
      const result = nextMod(bound);
      if (!Number.isInteger(result) || result < 0 || result >= bound) throw new Error("ClSt nextMod returned an invalid index.");
      return result;
    };
    attempts = 1 + draw(Math.min(orderedFields.length, 3));
    for (let index = 0; index < attempts; index += 1) {
      mask = (mask | (1 << draw(selectableCount))) >>> 0;
    }
  }
  const selectedFieldIndices = getClStSelectedFieldIndices(mask);
  return {
    selectableCount,
    selectedFieldIndex: selectedFieldIndices[0] ?? -1,
    selectedFieldIndices,
    attempts,
    mask,
    maskHex: formatClStMaskHex(mask)
  };
}

function buildClStTagData(fields, mask, now = new Date(), options = {}) {
  const orderedFields = Array.isArray(fields) ? fields : [];
  const resolver = typeof options.resolveTagData === "function"
    ? options.resolveTagData
    : resolveClstTagData;
  const selectableCount = Math.min(orderedFields.length, 32);
  let tagData = "";

  for (let index = 0; index < selectableCount; index += 1) {
    if (((Number(mask) >>> index) & 1) === 0) continue;
    const value = resolver(orderedFields[index], now, options);
    if (value == null) return null;
    tagData += String(value);
  }
  return tagData.slice(0, 20);
}

var CLST_TAG_DATA_READY = true;
