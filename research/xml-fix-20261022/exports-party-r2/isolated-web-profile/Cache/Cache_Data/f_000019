// ---------- File read ----------
async function readFileSmart(file) {
  const buf = await file.arrayBuffer();
  const u8 = new Uint8Array(buf);
  const hasUtf16leBom = u8.length >= 2 && u8[0] === 0xFF && u8[1] === 0xFE;
  const hasUtf16beBom = u8.length >= 2 && u8[0] === 0xFE && u8[1] === 0xFF;

  let encoding = "utf-8";
  let text;
  if (hasUtf16leBom) {
    encoding = "utf-16le-bom";
    text = new TextDecoder("utf-16le").decode(buf);
  } else if (hasUtf16beBom) {
    encoding = "utf-16be-bom";
    text = new TextDecoder("utf-16be").decode(buf);
  } else {
    let zeros = 0;
    for (let i = 1; i < Math.min(u8.length, 2000); i += 2) if (u8[i] === 0) zeros++;
    if (zeros > 50) {
      encoding = "utf-16le-detected";
      text = new TextDecoder("utf-16le").decode(buf);
    } else {
      text = new TextDecoder("utf-8").decode(buf);
    }
  }

  appLogger.file("FILE_READ_COMPLETED", "Файл шаблона прочитан в память.", {
    file: {
      name: file.name,
      sizeBytes: file.size,
      mimeType: file.type || null,
      lastModified: file.lastModified ? new Date(file.lastModified).toISOString() : null
    },
    decoding: {
      encoding,
      characterCount: text.length,
      hasUtf16leBom,
      hasUtf16beBom
    }
  });
  return text;
}

function normalizeEmptyTemplateDimensionMm(value, maxInternal, fallbackInternal) {
  const fallbackMm = internalToMm(fallbackInternal);
  const maxMm = internalToMm(maxInternal);
  let next = Number(value);

  if (!Number.isFinite(next)) next = fallbackMm;
  if (next <= 0) next = fallbackMm;

  return Number(Math.max(0.01, Math.min(maxMm, next)).toFixed(2));
}

function getDirectChildText(parent, tagName) {
  if (!parent) return "";
  const child = [...parent.children].find((el) => el.tagName === tagName);
  return child?.textContent ?? "";
}

function findDirectChildTagContentRange(xml, tagName) {
  const re = /<[^>]+>/g;
  let depth = 0;
  let targetStart = null;
  let match;

  while ((match = re.exec(xml))) {
    const token = match[0];
    if (/^<\?/.test(token) || /^<!/.test(token)) continue;

    const isClosing = /^<\//.test(token);
    const isSelfClosing = /\/>$/.test(token);
    const nameMatch = token.match(/^<\/?\s*([^\s/>]+)/);
    if (!nameMatch) continue;

    const name = nameMatch[1];

    if (isClosing) {
      if (name === tagName && targetStart != null && depth === 1) {
        return { start: targetStart, end: match.index };
      }
      depth = Math.max(0, depth - 1);
      continue;
    }

    if (depth === 0 && name === tagName) {
      if (isSelfClosing) return null;
      targetStart = re.lastIndex;
    }

    if (!isSelfClosing) depth += 1;
  }

  return null;
}

function getEmptyTemplateDimensionsFromDialog() {
  const printerModel = normalizeTemplateTargetPrinterModel(elNewTemplatePrinterModel?.value);
  const maxWidthInternal = getTemplateMaxImageWidthInternal(printerModel);
  const maxHeightInternal = getTemplateMaxImageHeightInternal(printerModel);
  return {
    widthMm: normalizeEmptyTemplateDimensionMm(elNewTemplateWidth?.value, maxWidthInternal, maxWidthInternal),
    heightMm: normalizeEmptyTemplateDimensionMm(elNewTemplateHeight?.value, maxHeightInternal, maxHeightInternal)
  };
}

function syncNewTemplatePrinterWidthLimit() {
  const printerModel = normalizeTemplateTargetPrinterModel(elNewTemplatePrinterModel?.value);
  const maxWidthInternal = getTemplateMaxImageWidthInternal(printerModel);
  const maxHeightInternal = getTemplateMaxImageHeightInternal(printerModel);
  const maxWidthMm = internalToMm(maxWidthInternal);
  const maxHeightMm = internalToMm(maxHeightInternal);
  const widthMm = normalizeEmptyTemplateDimensionMm(elNewTemplateWidth?.value, maxWidthInternal, maxWidthInternal);
  const heightMm = normalizeEmptyTemplateDimensionMm(elNewTemplateHeight?.value, maxHeightInternal, maxHeightInternal);
  if (elNewTemplateWidth) {
    elNewTemplateWidth.max = maxWidthMm.toFixed(2);
    elNewTemplateWidth.value = widthMm.toFixed(2);
  }
  if (elNewTemplateHeight) {
    elNewTemplateHeight.max = maxHeightMm.toFixed(2);
    elNewTemplateHeight.value = heightMm.toFixed(2);
  }
  const sizeHint = elNewTemplateModal?.querySelector('[data-builder-step="1"] > .note');
  if (sizeHint) {
    const sizeHintKey = maxWidthInternal === TEMPLATE_32MM_MAX_IMAGE_WIDTH
      ? "dialog.createTemplate.sizeHint32"
      : maxWidthInternal === TEMPLATE_107MM_MAX_IMAGE_WIDTH
        ? "dialog.createTemplate.sizeHint107"
        : "dialog.createTemplate.sizeHint";
    sizeHint.textContent = t(sizeHintKey);
  }
  return { printerModel, maxWidthInternal, maxHeightInternal, widthMm, heightMm };
}

function populateMaterialSelect(el, items, currentValue) {
  if (!el) return;
  populateSelectOptions(el, items, currentValue);
  if (typeof enhanceSelectControl === "function") enhanceSelectControl(el);
}

function populateNewTemplateOptions() {
  if (!elNewTemplatePrinterModel || !elNewTemplatePrintMode) return;

  const currentModel = normalizeTemplateTargetPrinterModel(elNewTemplatePrinterModel.value);
  const currentMode = EMPTY_TEMPLATE_PRINT_MODES.includes(elNewTemplatePrintMode.value)
    ? elNewTemplatePrintMode.value
    : EMPTY_TEMPLATE_PRINT_MODES[0];
  const { widthMm, heightMm } = getEmptyTemplateDimensionsFromDialog();

  populateMaterialSelect(
    elNewTemplatePrinterModel,
    getPrinterModelSelectOptions(currentModel),
    currentModel
  );
  populateMaterialSelect(
    elNewTemplatePrintMode,
    EMPTY_TEMPLATE_PRINT_MODES.map((mode) => ({ value: mode, label: mode })),
    currentMode
  );
  if (elNewTemplateWidth) elNewTemplateWidth.value = widthMm.toFixed(2);
  if (elNewTemplateHeight) elNewTemplateHeight.value = heightMm.toFixed(2);
  syncNewTemplatePrinterWidthLimit();
}

function openNewTemplateModal() {
  if (!elNewTemplateModal) return;
  if (typeof resetTemplateBuilder === "function") resetTemplateBuilder();
  else populateNewTemplateOptions();
  elNewTemplateModal.classList.remove("hidden");
  elNewTemplateModal.setAttribute("aria-hidden", "false");
  document.body.classList.add("modal-open");
}

function closeNewTemplateModal() {
  if (!elNewTemplateModal) return;
  elNewTemplateModal.classList.add("hidden");
  elNewTemplateModal.setAttribute("aria-hidden", "true");
  document.body.classList.remove("modal-open");
}

function createNewTemplateFromDialog() {
  const printerModel = normalizeTemplateTargetPrinterModel(elNewTemplatePrinterModel?.value);
  const printMode = EMPTY_TEMPLATE_PRINT_MODES.includes(elNewTemplatePrintMode?.value)
    ? elNewTemplatePrintMode.value
    : EMPTY_TEMPLATE_PRINT_MODES[0];
  const { widthMm, heightMm } = getEmptyTemplateDimensionsFromDialog();
  appLogger.action("NEW_TEMPLATE_CONFIRMED", "Пользователь подтвердил создание нового шаблона.", {
    printerModel,
    printMode,
    widthMillimeters: widthMm,
    heightMillimeters: heightMm
  });

  if (elNewTemplateWidth) elNewTemplateWidth.value = widthMm.toFixed(2);
  if (elNewTemplateHeight) elNewTemplateHeight.value = heightMm.toFixed(2);

  closeNewTemplateModal();
  const xml = buildEmptyTemplateXml(printerModel, printMode, widthMm, heightMm);
  if (typeof createTemplateInNewTab === "function") {
    createTemplateInNewTab(xml, null, { markDirty: true, source: "created" });
    return;
  }
  loadXml(xml, { markDirty: true, source: "created" });
}

function buildEmptyTemplateXml(printerModel, printMode, imageWidthMm, imageHeightMm) {
  const model = normalizeTemplateTargetPrinterModel(printerModel);
  const mode = EMPTY_TEMPLATE_PRINT_MODES.includes(String(printMode))
    ? String(printMode)
    : EMPTY_TEMPLATE_PRINT_MODES[0];
  const capabilities = getPrinterCapabilities(model);
  const maxWidthInternal = capabilities?.maxImageWidth ?? getTemplateMaxImageWidthInternal(model);
  const maxHeightInternal = capabilities?.maxImageHeight ?? getTemplateMaxImageHeightInternal(model);
  const xRes = capabilities?.xResText ?? Number(capabilities?.xRes ?? EMPTY_TEMPLATE_SUBIMAGE.xRes).toFixed(6);
  const designedFor = buildDesignedForLabel(model, mode);
  const widthMm = normalizeEmptyTemplateDimensionMm(imageWidthMm, maxWidthInternal, maxWidthInternal);
  const heightMm = normalizeEmptyTemplateDimensionMm(imageHeightMm, maxHeightInternal, maxHeightInternal);
  const imageWidth = Math.min(maxWidthInternal, mmToInternal(widthMm));
  const imageHeight = Math.min(maxHeightInternal, mmToInternal(heightMm));
  const clStVersionInfo = resolveClStVersionInfo({ designedFor });

  return (
    `<?xml version="1.0" encoding="UTF-16"?>\r\n` +
    `<ImageDesign Version="23" xml:space="default"><Header DesignedFor="${escapeAttr(designedFor)}"><ClStVersionInfo>${clStVersionInfo}</ClStVersionInfo></Header><SubImage ImageReference="1"><SubHeader FormatName="Default" PrinterFormatName="Default"><ImageWidth>${imageWidth}</ImageWidth><ImageHeight>${imageHeight}</ImageHeight><MaxImageWidth>${imageWidth}</MaxImageWidth><MaxImageHeight>${imageHeight}</MaxImageHeight><XRes>${xRes}</XRes><CurrentOrientation>${EMPTY_TEMPLATE_SUBIMAGE.currentOrientation}</CurrentOrientation></SubHeader></SubImage><GenericSettings><ImageMapping><Map SubIMageRef="1">1</Map></ImageMapping></GenericSettings></ImageDesign>`
  );
}

function repairLoadedKnownPrinterProfile() {
  const printerModel = String(state.docMeta?.printerModel ?? "").trim();
  if (!TEMPLATE_TARGET_PRINTER_MODELS.includes(printerModel)) {
    return { changed: false, printerModel, knownProfile: false, changes: [] };
  }

  const capabilities = PRINTER_CAPABILITIES[printerModel];
  if (!capabilities) {
    return { changed: false, printerModel, knownProfile: false, changes: [] };
  }

  const changes = [];
  const preservedDifferences = [];
  const fillInvalidCapability = (key, value, allowZero = false) => {
    const sourceValue = state.subImage[key];
    if (Number.isFinite(sourceValue) && (allowZero ? sourceValue >= 0 : sourceValue > 0)) {
      if (sourceValue !== Number(value)) {
        preservedDifferences.push({ key, sourceValue, capabilityValue: Number(value) });
      }
      return;
    }
    state.subImage[key] = value;
    changes.push(key);
  };
  const dimensions = resolveTemplateWorkspaceDimensions(state.subImage, capabilities);
  fillInvalidCapability("maxWidth", dimensions.width, true);
  fillInvalidCapability("maxHeight", dimensions.height, true);
  fillInvalidCapability("xRes", capabilities.xRes);

  return {
    changed: changes.length > 0,
    printerModel,
    knownProfile: true,
    changes,
    preservedDifferences
  };
}

function parseCiffDimensionUnits(value) {
  const text = String(value ?? "").trim();
  if (!/^\d+$/.test(text)) return null;
  const units = Number(text);
  return Number.isSafeInteger(units) && units >= 0 ? units : null;
}

function resolveTemplateWorkspaceDimensions(subImage, capabilities = null) {
  // MaxImage* is the document's configured physical area, which can be smaller
  // than the head. Image* describes used content (even outside that area).
  // Only missing/invalid values fall back per axis; an explicit MaxImage*=0
  // remains zero in the ClariSoft editor (print preview has a different rule).
  // field geometry, DPI, orientation and viewport scale never determine size.
  return {
    width: parseCiffDimensionUnits(subImage?.maxWidth) ??
      parseCiffDimensionUnits(subImage?.width) ?? parseCiffDimensionUnits(capabilities?.maxImageWidth) ?? 0,
    height: parseCiffDimensionUnits(subImage?.maxHeight) ??
      parseCiffDimensionUnits(subImage?.height) ?? parseCiffDimensionUnits(capabilities?.maxImageHeight) ?? 0
  };
}

function initializeTemplateWorkspaceDimensions(options = {}) {
  const source = String(options.source ?? "").trim().toLowerCase();
  const knownCapabilities = typeof getKnownPrinterCapabilities === "function"
    ? getKnownPrinterCapabilities(state.docMeta?.printerModel)
    : null;
  const dimensions = resolveTemplateWorkspaceDimensions(state.subImage, knownCapabilities);
  state.subImage.workspaceWidth = dimensions.width;
  state.subImage.workspaceHeight = dimensions.height;

  return {
    width: state.subImage.workspaceWidth,
    height: state.subImage.workspaceHeight,
    source
  };
}

function parseCiffMeasurementUnits(value) {
  const text = String(value ?? "").trim().toLowerCase();
  // Original CiffMgr string table 681601A8: U_HMM="hmm", U_DOTS="dots".
  // Numeric aliases also make previously generated documents explicit.
  if (text === "" || text === "hmm" || text === "0") return 0;
  if (text === "dots" || text === "1") return 1;
  return null;
}

function getCiffGeometryLoadError(doc) {
  const unitsText = getDirectChildText(doc?.querySelector("ImageDesign > Header"), "Units").trim();
  const units = parseCiffMeasurementUnits(unitsText);
  const subHeaders = [...(doc?.querySelectorAll("ImageDesign > SubImage > SubHeader") ?? [])];
  const invalidDimensions = !subHeaders.length || subHeaders.some((header) => (
    parseCiffDimensionUnits(getDirectChildText(header, "ImageWidth")) == null ||
    parseCiffDimensionUnits(getDirectChildText(header, "ImageHeight")) == null ||
    ["MaxImageWidth", "MaxImageHeight"].some((tag) => {
      const node = header.querySelector(`:scope > ${tag}`);
      return node != null && parseCiffDimensionUnits(node.textContent) == null;
    })
  ));
  if (units === 0 && !invalidDimensions) return null;
  return {
    key: units !== 0 ? "dialog.fileOpenError.unsupportedUnits" : "dialog.fileOpenError.invalidDimensions",
    units: unitsText || "hmm",
    invalidDimensions
  };
}

function validateCiffGeometryForLoad(doc, options = {}) {
  const error = getCiffGeometryLoadError(doc);
  if (!error) return true;
  appLogger.file("TEMPLATE_UNSUPPORTED_GEOMETRY", "Шаблон содержит неподдерживаемые единицы или некорректные обязательные размеры.", {
    source: options.source || "unknown", units: error.units, invalidDimensions: error.invalidDimensions
  }, "ERROR");
  openNotificationModal(t(error.key), t("dialog.fileOpenError.title"));
  return false;
}

// ---------- XML load / parse ----------
function loadXml(xmlText, options = {}) {
  // keep original line ending for diagnostics, but we will OUTPUT CRLF always
  const hasCRLF = /\r\n/.test(xmlText);

  // split to 2 lines in a robust way
  const { line1, line2 } = splitTwoLines(xmlText);

  const parser = new DOMParser();
  const doc = parser.parseFromString(line1 + "\n" + line2, "text/xml");
  const parseError = doc.querySelector("parsererror");
  if (parseError) {
    appLogger.file("TEMPLATE_PARSE_FAILED", "Не удалось разобрать CIFF/XML-шаблон.", {
      source: options.source || "unknown",
      title: options.title || null,
      characterCount: String(xmlText || "").length,
      parserMessage: parseError.textContent?.slice(0, 1000) || null
    }, "ERROR");
    openNotificationModal(
      t("dialog.fileOpenError.message"),
      t("dialog.fileOpenError.title")
    );
    return false;
  }

  // The editor's geometry, drag controls and barcode modules use U_HMM.
  // Reject U_DOTS before touching the current document rather than silently
  // interpreting printer dots as hundredths of a millimetre.
  if (!validateCiffGeometryForLoad(doc, options)) return false;

  if (typeof clearPendingCanvasPlacement === "function") {
    clearPendingCanvasPlacement({ restoreStatus: false });
  }

  state.lineEnding = "\r\n";
  state.line1 = line1;
  state.line2 = line2;
  state.xmlText = line1 + "\n" + line2; // internal store (we'll output CRLF later)
  state.xmlDoc = doc;

  parseHeader(doc, options);
  parseSubHeader(doc);
  parseFields(doc);
  initializeTemplateWorkspaceDimensions(options);
  const compatibilityRepair = repairLoadedKnownPrinterProfile();
  if (compatibilityRepair.changed) {
    options = { ...options, markDirty: true, compatibilityRepair };
  }
  setSelectedNames([]);

  pushHistory(true);

  stage.position({ x: 20, y: 20 });
  setZoom(100);

  renderAll();

  elStatusLeft.textContent =
    `Loaded: ${state.docMeta.designedFor} 
    | Overall size: ${internalToMm(getCanvasInternalWidth()).toFixed(2)} x ${internalToMm(getCanvasInternalHeight()).toFixed(2)} mm 
    | Used area: ${internalToMm(getUsedImageInternalWidth()).toFixed(2)} x ${internalToMm(getUsedImageInternalHeight()).toFixed(2)} mm` +
    ` | InputEOL=${hasCRLF ? 'CRLF' : 'LF'}`;

  if (typeof onTemplateLoadedIntoActiveTab === "function") {
    onTemplateLoadedIntoActiveTab(options);
  }
  appLogger.file("TEMPLATE_LOADED", "Шаблон успешно загружен в редактор.", {
    source: options.source || "unknown",
    title: options.title || null,
    markDirty: options.markDirty !== false,
    input: {
      characterCount: String(xmlText || "").length,
      lineEnding: hasCRLF ? "CRLF" : "LF"
    },
    document: {
      designedFor: state.docMeta.designedFor,
      printerModel: state.docMeta.printerModel,
      printMode: state.docMeta.printMode,
      widthMillimeters: Number(internalToMm(getCanvasInternalWidth()).toFixed(2)),
      heightMillimeters: Number(internalToMm(getCanvasInternalHeight()).toFixed(2)),
      compatibilityRepair,
      fieldCount: state.fields.length,
      printedFieldCount: state.fields.filter((field) => field.printed).length,
      hiddenFieldCount: state.fields.filter((field) => !field.printed).length,
      dateOffsetCount: state.dateOffsets.length
    }
  });
  appLogger.state("APPLICATION_STATE_AFTER_TEMPLATE_LOAD", "Состояние после загрузки шаблона.", {
    source: options.source || "unknown",
    title: options.title || null
  });
  return true;
}

function parseHeader(doc, options = {}) {
  const root = doc.querySelector("ImageDesign");
  state.docMeta.version = root?.getAttribute("Version") ?? null;

  const header = doc.querySelector("ImageDesign > Header");
  state.docMeta.units = parseCiffMeasurementUnits(getDirectChildText(header, "Units"));
  const designedFor = String(header?.getAttribute("DesignedFor") ?? "").trim();
  const targetMatch = designedFor.match(/^(.*?)(?:\s*-\s*(Intermittent|Continuous))$/i);
  state.docMeta.designedFor = designedFor;
  state.docMeta.clStVersionInfo = getDirectChildText(header, "ClStVersionInfo");
  state.docMeta.sourceFileName = String(options.sourceFileName ?? options.sourcePath ??
    (options.source === "file" ? options.title : "") ?? "");
  state.docMeta.clStIncludeFileMetadata = recognizeClStFileMetadataMode(
    state.docMeta.clStVersionInfo, state.docMeta.sourceFileName
  );
  state.docMeta.printerModel = targetMatch ? targetMatch[1].trim() : designedFor;
  state.docMeta.printMode = targetMatch ? normalizePrintMode(targetMatch[2]) : "";

  state.dateOffsets = [];
  header?.querySelectorAll(":scope > DateOffset").forEach(node => {
    const name = node.getAttribute("Name") || "";
    const def = node.querySelector(":scope > DefaultOffset");
    const cur = node.querySelector(":scope > CurrentOffset");

    state.dateOffsets.push({
      sourceName: name,
      name,
      default: {
        y: toInt(getDirectChildText(def, "Year"), 0),
        m: toInt(getDirectChildText(def, "Month"), 0),
        d: toInt(getDirectChildText(def, "Day"), 0)
      },
      current: cur ? {
        y: toInt(getDirectChildText(cur, "Year"), 0),
        m: toInt(getDirectChildText(cur, "Month"), 0),
        d: toInt(getDirectChildText(cur, "Day"), 0)
      } : null
    });
  });

  state.dateOffsetsLoaded = state.dateOffsets.length > 0;
  state.dateOffsetsDirty = false;
}

function parseSubHeader(doc) {
  const sub = doc.querySelector("ImageDesign > SubImage");
  const sh = sub?.querySelector(":scope > SubHeader");

  state.subImage.imageReference = sub?.getAttribute("ImageReference") ?? "1";
  state.subImage.width = parseCiffDimensionUnits(getDirectChildText(sh, "ImageWidth"));
  state.subImage.height = parseCiffDimensionUnits(getDirectChildText(sh, "ImageHeight"));
  state.subImage.maxWidth = parseCiffDimensionUnits(getDirectChildText(sh, "MaxImageWidth")) ?? state.subImage.width;
  state.subImage.maxHeight = parseCiffDimensionUnits(getDirectChildText(sh, "MaxImageHeight")) ?? state.subImage.height;
  state.subImage.xRes = toFloat(getDirectChildText(sh, "XRes"), 0);
  const yRes = toFloat(getDirectChildText(sh, "YRes"), 0);
  state.subImage.yRes = Number.isFinite(yRes) && yRes > 0 ? yRes : null;
  state.subImage.printerType = String(sh?.getAttribute("PrinterType") ?? state.docMeta.printerModel ?? "").trim();
  state.subImage.orientation = toInt(getDirectChildText(sh, "CurrentOrientation"), 0);
  state.subImage.usedSizeDirty = false;
}

function parseFields(doc) {
  state.fields = [];
  state.fieldByName = new Map();

  const sub = doc.querySelector("ImageDesign > SubImage");
  const fieldNodes = [...(sub?.querySelectorAll(":scope > Field") ?? [])];

  fieldNodes.forEach(node => {
    const f = parseFieldNode(node);
    if (f.fldType === "CounterText") normalizeCounterField(f, { preserveCurrent: true });
    state.fields.push(f);
    state.fieldByName.set(f.name, f);
  });
}

function parseMaxNoOfChars(node) {
  const text = node?.textContent?.trim() ?? "";
  if (!/^\d+$/.test(text)) return null;
  const value = Number(text);
  return Number.isSafeInteger(value) ? value : null;
}

function parseFieldNode(node) {
  const name = node.getAttribute("Name") || "";
  const fldType = getDirectChildText(node, "FldType") || "FixedText";

  const displayedNode = node.querySelector(":scope > Displayed");
  const printed = !(displayedNode && displayedNode.textContent.trim() === "0");

  const geom = {
    x: toInt(getDirectChildText(node, "X"), 0),
    y: toInt(getDirectChildText(node, "Y"), 0),
    w: toInt(getDirectChildText(node, "W"), 0),
    h: toInt(getDirectChildText(node, "H"), 0)
  };

  const calcData = getDirectChildText(node, "CalcData").replace(/\r\n?/g, "\n");
  // An absent Ln is a distinct source state, not an implicit line count of 1.
  const ln = toInt(getDirectChildText(node, "Ln"), null);
  const orientation = normalizeOrientation(getDirectChildText(node, "Orientation"));

  const objNode = node.querySelector(":scope > Data > Object");
  const dataType = toInt(getDirectChildText(objNode, "DataType"), null);
  const defVal = getDirectChildText(objNode, "Default").replace(/\r\n?/g, "\n");
  const maxChars = parseMaxNoOfChars(objNode?.querySelector(":scope > MaxNoOfChars"));
  const fixedLen = !!objNode?.querySelector(":scope > FixedLen");
  const staticAttr = objNode?.getAttribute("Static") ?? null;
  const parseAttr = objNode?.getAttribute("Parse") ?? null;
  const referenceAttr = objNode?.getAttribute("Reference") ?? null;
  const hasVarText = !!objNode?.querySelector(":scope > VarText");
  const userEnter = (objNode?.querySelector(":scope > VarText > UserEnterData")?.textContent ?? "").replace(/\r\n?/g, "\n");
  const mask = objNode?.querySelector(":scope > VarText > Mask")?.textContent ?? "";
  const srcDataNode = objNode?.querySelector(":scope > SrcData");
  // Keep source configuration separate from the calculated preview. Original
  // CDATA, unknown children and attribute spelling remain in state.line2.
  const srcData = srcDataNode ? {
    connStr: srcDataNode.querySelector(":scope > ConnStr")?.textContent ?? null,
    srcSQL: srcDataNode.querySelector(":scope > SrcSQL")?.textContent ?? null
  } : null;

  const textNode = node.querySelector(":scope > Text");
  const fontNode = textNode?.querySelector(":scope > Font");
  const pitch = toInt(fontNode?.querySelector(":scope > Pitch")?.textContent, null);
  const xMag = toInt(fontNode?.querySelector(":scope > XMag")?.textContent, null);
  const boldNode = textNode?.querySelector(":scope > Bold");
  const italicNode = textNode?.querySelector(":scope > Italic");

  const clsid = getDirectChildText(node, "CLSID");
  const quietMargin = node.querySelector("Barcode > QuietMargin") ? toInt(node.querySelector("Barcode > QuietMargin")?.textContent, 0) : null;
  const bcH = node.querySelector("Barcode > BcH") ? toInt(node.querySelector("Barcode > BcH")?.textContent, null) : null;

  const dmNode = node.querySelector("Barcode > DataMatrix");
  const explicitModuleSize = dmNode?.querySelector("ModuleSize")
    ? parseDataMatrixModuleSizeValue(toFloat(dmNode.querySelector("ModuleSize")?.textContent, 0.5), 0.5)
    : null;
  const dm = dmNode ? {
    moduleSize: explicitModuleSize,
    symbolSize: normalizeDataMatrixSymbolSizeValue(dmNode.querySelector("SymbolSize")?.textContent, "22X22"),
    segments: parseDataMatrixSegments(node),
    structureDirty: false
  } : null;
  const nativeBarcodeType = getNativeBarcodeTypeFromNode(node);

  const offsetRef = objNode?.querySelector(":scope > OffsetDate")?.getAttribute("SrcOffset") ?? null;

  const cntNoChars = objNode?.querySelector(":scope > CounterText > SubCnt > NoOfChars")
    ? toInt(objNode.querySelector(":scope > CounterText > SubCnt > NoOfChars")?.textContent, null)
    : null;
  const cntSignificance = objNode?.querySelector(":scope > CounterText > SubCnt")
    ? toInt(objNode.querySelector(":scope > CounterText > SubCnt")?.getAttribute("Significance"), null)
    : null;
  const cntStartVal = objNode?.querySelector(":scope > CounterText > SubCnt > StartVal")?.textContent ?? null;
  const cntEndVal = objNode?.querySelector(":scope > CounterText > SubCnt > EndVal")?.textContent ?? null;
  const cntStepSize = objNode?.querySelector(":scope > CounterText > SubCnt > StepSize")
    ? toInt(objNode.querySelector(":scope > CounterText > SubCnt > StepSize")?.textContent, null)
    : null;
  const cntClrStCntType = objNode?.querySelector(":scope > CounterText > SubCnt > ClrStCntType")?.textContent ?? "";

  const field = {
    sourceName: name,
    name,
    fldType,
    printed,
    geom,
    ln,
    orientation,
    calcData,

    data: {
      dataType,
      defaultValue: defVal,
      maxChars,
      fixedLen,
      padChar: objNode?.querySelector(":scope > FixedLen > PadChar")?.textContent ?? null,
      padMode: objNode?.querySelector(":scope > FixedLen > PadMode")?.textContent ?? null,
      srcField: objNode?.querySelector(":scope > SrcField")?.getAttribute("SrcFieldName") ?? null,
      startChar: toInt(objNode?.querySelector(":scope > SrcField > StartChar")?.textContent, null),
      noOfChars: toInt(objNode?.querySelector(":scope > SrcField > NoOfChars")?.textContent, null),
      selectMode: objNode?.querySelector(":scope > SrcField > SelectMode")?.textContent ?? null,
      hasMultipleDataObjects: node.querySelectorAll(":scope > Data > Object").length > 1,
      calendar: objNode?.querySelector(":scope > Calendar")?.textContent ?? null,
      locale: objNode?.querySelector(":scope > Locale")?.textContent ?? null,
      encryption: objNode?.querySelector(":scope > Encryption")?.textContent ?? null,
      staticAttr,
      parseAttr,
      referenceAttr,
      srcData,
      hasVarText,
      textEntryMode: (fldType === "FixedText" ? (hasVarText ? "user" : "fixed") : null),
      userEnterData: userEnter,
      mask,
      offsetRef,
      dateLocale: inferDateLocale(fldType, defVal, calcData),
      counter: {
        noOfChars: cntNoChars,
        significance: cntSignificance,
        startVal: cntStartVal,
        endVal: cntEndVal,
        stepSize: cntStepSize,
        clrStCntType: cntClrStCntType
      }
    },

    text: {
      pitch, xMag,
      // An omitted native Pitch means 13 points, regardless of saved geometry.
      // Keep the tag absent in the model for lossless export.
      defaultPitch: 13,
      face: fontNode?.querySelector(":scope > Face")?.textContent ?? null,
      family: fontNode?.querySelector(":scope > Family")?.textContent ?? null,
      pitchResolution: toInt(fontNode?.querySelector(":scope > PitchResolution")?.textContent, null),
      yMag: toInt(fontNode?.querySelector(":scope > YMag")?.textContent, null),
      ttSize: toInt(fontNode?.querySelector(":scope > TTSize")?.textContent, null),
      txtDir: fontNode?.querySelector(":scope > TxtDir")?.textContent ?? null,
      charSpace: toInt(fontNode?.querySelector(":scope > CharSpace")?.textContent, null),
      bold: boldNode ? toInt(boldNode.textContent, 0) : null,
      boldWeight: boldNode?.getAttribute("Weight") ?? null,
      italic: italicNode ? toInt(italicNode.textContent, 0) : null
    },
    barcode: dm || nativeBarcodeType != null ? { clsid, quietMargin, bcH, nativeType: nativeBarcodeType, dataMatrix: dm } : null,

    _konva: null
  };

  if (field.barcode?.dataMatrix && field.barcode.dataMatrix.moduleSize == null) {
    field.barcode.dataMatrix.moduleSize = inferDataMatrixModuleSizeFromGeom(field);
  }

  return field;
}

function getNativeBarcodeTypeFromNode(node) {
  if (!node?.querySelector) return null;
  const types = [
    ["RSS14", 10], ["RSS14Truncated", 11], ["RSS14Stacked", 12],
    ["RSS14StackedOmni", 13], ["RSSLimited", 14], ["DataMatrix", 15]
  ];
  for (const [tag, type] of types) {
    if (node.querySelector(`:scope > Barcode > ${tag}`)) return type;
  }
  return null;
}

function parseDataMatrixSegments(fieldNode) {
  const objects = [...fieldNode.querySelectorAll("Data > Object")];
  const segs = [];
  objects.forEach((o, i) => {
    const idxAttr = o.getAttribute("Index");
    const idx = idxAttr != null ? toInt(idxAttr, i) : i;
    const src = o.querySelector("SrcField")?.getAttribute("SrcFieldName") ?? null;
    const defVal = (o.querySelector("Default")?.textContent ?? "").replace(/\r\n?/g, "\n");
    const dataType = toInt(o.querySelector("DataType")?.textContent, 5);
    segs.push({ index: idx, sourceObjectIndex: i, srcField: src, defaultValue: defVal, dataType,
      startChar: toInt(o.querySelector(":scope > SrcField > StartChar")?.textContent, null),
      noOfChars: toInt(o.querySelector(":scope > SrcField > NoOfChars")?.textContent, null),
      selectMode: o.querySelector(":scope > SrcField > SelectMode")?.textContent ?? null,
      staticAttr: o.getAttribute("Static"),
      fixedLen: !!o.querySelector(":scope > FixedLen"),
      maxChars: parseMaxNoOfChars(o.querySelector(":scope > MaxNoOfChars")),
      padChar: o.querySelector(":scope > FixedLen > PadChar")?.textContent ?? null,
      padMode: o.querySelector(":scope > FixedLen > PadMode")?.textContent ?? null,
      hasVarText: !!o.querySelector(":scope > VarText"),
      userEnterData: o.querySelector(":scope > VarText > UserEnterData")?.textContent?.replace(/\r\n?/g, "\n") ?? null,
      calendar: o.querySelector(":scope > Calendar")?.textContent ?? null,
      locale: o.querySelector(":scope > Locale")?.textContent ?? null,
      encryption: o.querySelector(":scope > Encryption")?.textContent ?? null,
      offsetRef: o.querySelector(":scope > OffsetDate")?.getAttribute("SrcOffset") ?? null,
      dateLocale: inferDateLocale(dataType === 2 ? "DateText" : dataType === 3 ? "OffsetDateText" : "", defVal, "")
    });
  });
  segs.sort((a,b) => a.index - b.index);
  segs.forEach((s, j) => s.index = j);
  return segs;
}

function inferDataMatrixModuleSizeFromGeom(field) {
  const dm = field?.barcode?.dataMatrix;
  if (!dm) return null;

  const symbolInfo = DATA_MATRIX_SYMBOLS_BY_NAME.get(normalizeDataMatrixSymbolSizeValue(dm.symbolSize, "22X22"));
  if (!symbolInfo) return null;

  const quietModules = Math.max(0, Math.round(Number(field.barcode?.quietMargin ?? 0) || 0));
  const totalCols = symbolInfo.symbolCols + (quietModules * 2);
  const totalRows = symbolInfo.symbolRows + (quietModules * 2);
  const widthModule = totalCols > 0 ? internalToMm(field.geom?.w ?? 0) / totalCols : null;
  const heightModule = totalRows > 0 ? internalToMm(field.geom?.h ?? 0) / totalRows : null;
  const candidates = [widthModule, heightModule].filter((value) => Number.isFinite(value) && value > 0);
  if (!candidates.length) return null;

  return normalizeDataMatrixModuleSizeValue(candidates.reduce((sum, value) => sum + value, 0) / candidates.length);
}

