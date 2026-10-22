const TAG_DATA_KEY = "TagData";
const VERSION_INFO_KEY = "TpyRcNeyeK";

function splitClStWindowsPath(value) {
  let source = String(value ?? "").split("\0", 1)[0];
  if (source[1] === ":") source = source.slice(2);
  const leaf = source.split(/[\\/]/).pop();
  const dot = leaf.lastIndexOf(".");
  const name = dot < 0 ? leaf : leaf.slice(0, dot);
  const extension = dot < 0 ? "" : leaf.slice(dot);
  if (name.length > 255 || extension.length > 255) {
    throw new Error("ClSt filename or extension exceeds the native 255 UTF-16 unit buffer.");
  }
  return { name, extension };
}

function normalizeClStFileMetadata(sourcePath) {
  let parts = splitClStWindowsPath(sourcePath);
  if (parts.extension === ".new") parts = splitClStWindowsPath(parts.name);
  return parts.name.slice(0, 100) + parts.extension;
}

function lowerClStAscii(value) {
  // The analyzed default CRT locale lowercases ASCII A-Z here.
  return value.replace(/[A-Z]/g, (character) => character.toLowerCase());
}

function clStFileMetadataMatchesSource(fileMetadata, sourcePath) {
  if (sourcePath == null || String(sourcePath).length === 0) return false;
  try {
    const current = splitClStWindowsPath(sourcePath);
    const encoded = splitClStWindowsPath(fileMetadata);
    return lowerClStAscii(current.extension) === ".ciff" &&
      lowerClStAscii(current.extension) === lowerClStAscii(encoded.extension) &&
      lowerClStAscii(current.name.slice(0, 100)) === lowerClStAscii(encoded.name.slice(0, 100));
  } catch {
    return false;
  }
}

function decodeClStCore(core, structureKey, fieldCount) {
  if (core.length < 24 || core.length > 84) throw new Error("ClSt core has an invalid length.");
  const maskHex = decryptClStText(core.slice(0, 24), structureKey);
  if (!/^[0-9A-F]{8}$/.test(maskHex)) throw new Error("ClSt mask is not eight uppercase hexadecimal digits.");
  const mask = parseInt(maskHex, 16) >>> 0;
  const selectedFieldIndices = getClStSelectedFieldIndices(mask);
  if (selectedFieldIndices.length > 3) throw new Error("ClSt mask contains more than three selected fields.");
  if (fieldCount != null) validateClStSelectionMask(mask, fieldCount);
  const tagData = decryptClStText(core.slice(24), TAG_DATA_KEY);
  if (tagData.length > 20 || (mask === 0 && tagData.length !== 0)) {
    throw new Error("ClSt selected payload does not match its selection mask.");
  }
  return { mask, maskHex, selectedFieldIndices, tagData, core };
}

function decodeClStVersionInfo(value, options = {}) {
  if (typeof value !== "string" || value.length < 72 || value.length % 9 !== 0) {
    throw new Error("ClStVersionInfo must contain complete nested encoded UTF-16 triples.");
  }
  const fieldCount = options.fieldCount;
  if (fieldCount != null && (!Number.isSafeInteger(fieldCount) || fieldCount < 0)) {
    throw new Error("ClSt fieldCount must be a nonnegative integer.");
  }
  const structureKey = buildClStStructureKey(options.dateOffsetCount ?? 0, options.subImageCount ?? 0, fieldCount ?? 0);
  const intermediate = decryptClStText(value, VERSION_INFO_KEY);
  const sourcePath = options.sourcePath ?? options.sourceName;
  let optional = null;
  // The validator first tries the optional filename envelope. Its first eight
  // decoded characters are a lowercase hexadecimal encoded-file-block length.
  if (intermediate.length >= 48) {
    try {
      const lengthHex = decryptClStText(intermediate.slice(0, 24), structureKey);
      if (/^[0-9a-f]{8}$/.test(lengthHex)) {
        const fileBlockLength = parseInt(lengthHex, 16);
        if (fileBlockLength > 5 && fileBlockLength + 24 < intermediate.length) {
          const fileMetadata = decryptClStText(intermediate.slice(24, 24 + fileBlockLength), TAG_DATA_KEY);
          const core = decodeClStCore(intermediate.slice(24 + fileBlockLength), structureKey, fieldCount);
          const fileNameMatchesSource = clStFileMetadataMatchesSource(fileMetadata, sourcePath);
          optional = { ...core, intermediate, includeFileMetadata: true, fileMetadata, fileBlockLength, fileNameMatchesSource };
        }
      }
    } catch {
      // A normal mask such as 00000008 can look like a filename length.
      // Failed optional candidates must still be interpreted as a main core.
    }
  }
  if (optional) {
    if (options.requireFileNameMatch && !optional.fileNameMatchesSource) {
      throw new Error("ClSt filename metadata does not match this .ciff source.");
    }
    return optional;
  }
  const core = decodeClStCore(intermediate, structureKey, fieldCount);
  return { ...core, intermediate, includeFileMetadata: false, fileMetadata: null, fileBlockLength: 0, fileNameMatchesSource: false };
}

function isValidClStVersionInfoSyntax(value) {
  try {
    decodeClStVersionInfo(value);
    return true;
  } catch {
    return false;
  }
}

function recognizeClStFileMetadataMode(value, sourcePath) {
  try {
    return decodeClStVersionInfo(value, { sourcePath, requireFileNameMatch: true }).includeFileMetadata;
  } catch {
    return false;
  }
}

function clampClStStructureCount(value) {
  return Math.max(0, Math.min(99, Math.trunc(Number(value) || 0)));
}

function buildClStStructureKey(dateOffsetCount, subImageCount, fieldCount) {
  return String(clampClStStructureCount(dateOffsetCount)).padStart(2, "0") +
    String(clampClStStructureCount(subImageCount)).padStart(2, "0") +
    String(clampClStStructureCount(fieldCount)).padStart(2, "0");
}

function getClStRuntimeNow(now) {
  const runtimeNow = now == null ? new Date() : now;
  if (!runtimeNow || typeof runtimeNow.getTime !== "function" || !Number.isFinite(runtimeNow.getTime())) {
    throw new Error("ClStVersionInfo generation requires a valid Date.");
  }
  return runtimeNow;
}

function buildClStVersionInfoDebugInfo(template, now = new Date(), options = {}) {
  const runtimeNow = getClStRuntimeNow(now);
  const structure = inspectClStTemplateStructure(template);
  const structureKey = buildClStStructureKey(
    structure.dateOffsetCount,
    structure.subImageCount,
    structure.fieldCount
  );
  const fieldByName = options.fieldByName ?? template?.fieldByName ?? null;
  const resolverOptions = { ...options, fieldByName };
  const selection = createClStSelectionMask(structure.fields, runtimeNow, resolverOptions);
  const sourcePath = options.sourcePath ?? options.sourceName ?? template?.sourcePath ?? template?.sourceName;
  const originalToken = options.originalClStVersionInfo ?? template?.clStVersionInfo ?? "";
  const originalSourcePath = options.originalSourcePath ?? options.originalSourceName ?? sourcePath;
  const includeFileMetadata = options.includeFileMetadata ?? template?.includeFileMetadata ??
    recognizeClStFileMetadataMode(originalToken, originalSourcePath);
  const baseInfo = {
    dateOffsetCount: structure.dateOffsetCount,
    subImageCount: structure.subImageCount,
    fieldCount: structure.fieldCount,
    structureKey,
    selectedFieldIndex: selection.selectedFieldIndex,
    selectedFieldIndices: selection.selectedFieldIndices,
    attempts: selection.attempts,
    mask: selection.mask,
    maskHex: selection.maskHex,
    tagData: "",
    fragmentA: "",
    fragmentB: "",
    intermediate: "",
    normalIntermediate: "",
    includeFileMetadata: Boolean(includeFileMetadata),
    fileMetadata: null,
    metadataFragment: "",
    metadataLengthFragment: "",
    unresolvedSelectedFieldIndices: [],
    clStVersionInfo: null
  };

  const resolver = typeof options.resolveTagData === "function" ? options.resolveTagData : resolveClstTagData;
  const selectedValues = [];
  for (const index of selection.selectedFieldIndices) {
    const value = resolver(structure.fields[index], runtimeNow, resolverOptions);
    if (value == null) baseInfo.unresolvedSelectedFieldIndices.push(index);
    else selectedValues.push(String(value));
  }
  if (baseInfo.unresolvedSelectedFieldIndices.length) return baseInfo;
  const tagData = selectedValues.join("").slice(0, 20);

  const fragmentA = encryptClStText(selection.maskHex, structureKey);
  const fragmentB = tagData.length ? encryptClStText(tagData, TAG_DATA_KEY) : "";
  const normalIntermediate = fragmentA + fragmentB;
  let intermediate = normalIntermediate;
  let fileMetadata = null;
  let metadataFragment = "";
  let metadataLengthFragment = "";
  if (includeFileMetadata) {
    if (sourcePath == null) throw new Error("ClSt filename metadata requires sourcePath or sourceName.");
    fileMetadata = normalizeClStFileMetadata(sourcePath);
    metadataFragment = encryptClStText(fileMetadata, TAG_DATA_KEY);
    const lengthHex = metadataFragment.length.toString(16).padStart(8, "0");
    metadataLengthFragment = encryptClStText(lengthHex, structureKey);
    intermediate = metadataLengthFragment + metadataFragment + normalIntermediate;
  }
  const clStVersionInfo = encryptClStText(intermediate, VERSION_INFO_KEY);

  return {
    ...baseInfo,
    tagData,
    fragmentA,
    fragmentB,
    normalIntermediate,
    intermediate,
    fileMetadata,
    metadataFragment,
    metadataLengthFragment,
    clStVersionInfo
  };
}

function generateClStVersionInfo(template, now = new Date(), options = {}) {
  return buildClStVersionInfoDebugInfo(template, now, options).clStVersionInfo;
}

var CLST_VERSION_INFO_READY = true;
