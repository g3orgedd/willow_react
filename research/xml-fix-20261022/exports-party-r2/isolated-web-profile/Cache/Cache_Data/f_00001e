// ---------- Undo/Redo ----------
function pushHistory(initial = false, snapshotOverride = null) {
  const snap = snapshotOverride ?? snapshotState();
  if (!initial) history.undo.push(snap);
  else { history.undo = [snap]; history.redo = []; }
  history.redo = [];
  if (!initial && state.validation) {
    state.validation = {
      ...state.validation,
      structuralErrors: []
    };
  }
  if (!initial && state.subImage) state.subImage.usedSizeDirty = true;
  updateUndoRedoButtons();
  if (!initial && typeof markActiveTemplateTabDirty === "function") markActiveTemplateTabDirty();
  appLogger.log("application", "HISTORY_SNAPSHOT_CREATED", initial
    ? "Создан начальный снимок истории шаблона."
    : "Создан снимок истории перед изменением.", {
    initial,
    undoDepth: history.undo.length,
    redoDepth: history.redo.length,
    selectedNames: getSelectedNames(),
    fieldCount: state.fields.length
  }, "DEBUG", "renderer-history");
}

function snapshotState() {
  return JSON.stringify({
    sourceXml: { line1: state.line1, line2: state.line2 },
    docMeta: state.docMeta,
    subImage: state.subImage,
    dateOffsets: state.dateOffsets,
    dateOffsetsLoaded: state.dateOffsetsLoaded,
    dateOffsetsDirty: state.dateOffsetsDirty,
    fields: state.fields.map(f => ({
      sourceName: f.sourceName ?? null,
      name: f.name,
      fldType: f.fldType,
      printed: f.printed,
      geom: f.geom,
      orientation: normalizeOrientation(f.orientation),
      ln: f.ln,
      calcData: f.calcData,
      data: f.data,
      text: f.text,
      barcode: f.barcode,
      ...(f._nativeTextGeometryDirty ? { _nativeTextGeometryDirty: true } : {}),
      ...(f._nativeTextFontDirty ? { _nativeTextFontDirty: true } : {})
    })),
    selectedName: state.selectedName,
    selectedNames: getSelectedNames(),
    showHiddenOnCanvas: state.showHiddenOnCanvas,
    gridMm: state.gridMm,
    validation: state.validation
  });
}

function restoreFromSnapshot(json, options = {}) {
  const obj = JSON.parse(json);
  if (obj.sourceXml && (state.line1 !== obj.sourceXml.line1 || state.line2 !== obj.sourceXml.line2)) {
    state.line1 = obj.sourceXml.line1;
    state.line2 = obj.sourceXml.line2;
    state.xmlText = `${state.line1}\n${state.line2}`;
    if (typeof DOMParser === "function") state.xmlDoc = new DOMParser().parseFromString(state.xmlText, "text/xml");
  }
  state.docMeta = obj.docMeta;
  state.subImage = obj.subImage;
  state.dateOffsets = (obj.dateOffsets || []).map((offset) => ({
    ...offset,
    sourceName: offset?.sourceName !== undefined ? offset.sourceName : offset?.name
  }));
  state.dateOffsetsLoaded = !!obj.dateOffsetsLoaded;
  state.dateOffsetsDirty = !!obj.dateOffsetsDirty;
  state.selectedName = obj.selectedName;
  state.selectedNames = Array.isArray(obj.selectedNames)
    ? obj.selectedNames.slice()
    : (obj.selectedName ? [obj.selectedName] : []);
  state.showHiddenOnCanvas = obj.showHiddenOnCanvas;
  state.gridMm = GRID_SIZE_OPTIONS.includes(Number(obj.gridMm)) ? Number(obj.gridMm) : state.gridMm;
  const snapshotValidation = obj.validation && typeof obj.validation === "object"
    ? obj.validation
    : {};
  state.validation = {
    ...snapshotValidation,
    invalidPrintableFieldNames: Array.isArray(snapshotValidation.invalidPrintableFieldNames)
      ? snapshotValidation.invalidPrintableFieldNames
      : [],
    invalidHardwareFieldNames: Array.isArray(snapshotValidation.invalidHardwareFieldNames)
      ? snapshotValidation.invalidHardwareFieldNames
      : [],
    structuralErrors: Array.isArray(snapshotValidation.structuralErrors)
      ? snapshotValidation.structuralErrors
      : []
  };

  state.fields = (obj.fields || []).map(f => ({
    ...f,
    orientation: normalizeOrientation(f.orientation),
    sourceName: f.sourceName !== undefined ? f.sourceName : f.name,
    _konva: null
  }));
  state.fields.forEach((field) => {
    const dataMatrix = field.barcode?.dataMatrix;
    if (!dataMatrix || typeof dataMatrix.structureDirty === "boolean") return;
    dataMatrix.structureDirty = inferRestoredDataMatrixStructureDirty(field);
  });
  state.fields.forEach((field) => {
    if (field.fldType === "CounterText") normalizeCounterField(field, { preserveCurrent: true });
  });
  state.fieldByName = new Map(state.fields.map(f => [f.name, f]));
  setSelectedNames(state.selectedNames, state.selectedName);

  if (options.render !== false) {
    renderAll();
    updateUndoRedoButtons();
  }
}

function inferRestoredDataMatrixStructureDirty(field) {
  const dataMatrix = field?.barcode?.dataMatrix;
  if (!dataMatrix || !Array.isArray(dataMatrix.segments)) return false;

  const sourceName = field.sourceName ?? field.name;
  const sourceField = extractFieldBlockInSubImage(state.line2, sourceName);
  if (!sourceField) return true;
  const sourceData = extractBlock(sourceField.block, "<Data>", "</Data>");
  if (!sourceData) return true;

  const sourceSegments = listDirectChildElementRangesLossless(sourceData.block, "Object")
    .map((range) => sourceData.block.slice(range.start, range.end))
    .map((objectBlock, position) => {
      const openTag = objectBlock.match(/^<Object\b[^>]*>/)?.[0] || "";
      const rawIndex = getXmlAttributeValue(openTag, "Index");
      const parsedIndex = rawIndex == null ? position : toInt(rawIndex, position);
      const sourceTag = objectBlock.match(/<SrcField\b[^>]*>/)?.[0] || "";
      return {
        order: parsedIndex,
        position,
        srcField: sourceTag ? String(getXmlAttributeValue(sourceTag, "SrcFieldName") ?? "") : null
      };
    })
    .sort((left, right) => (left.order - right.order) || (left.position - right.position));

  if (sourceSegments.length !== dataMatrix.segments.length) return true;
  return sourceSegments.some((sourceSegment, index) => (
    sourceSegment.srcField !== (dataMatrix.segments[index]?.srcField ?? null)
  ));
}

function undo() {
  if (history.undo.length <= 1) return;
  const before = {
    undoDepth: history.undo.length,
    redoDepth: history.redo.length,
    selectedNames: getSelectedNames()
  };
  const current = snapshotState();
  const prev = history.undo.pop();
  history.redo.push(current);
  restoreFromSnapshot(prev);
  if (typeof markActiveTemplateTabDirty === "function") markActiveTemplateTabDirty();
  appLogger.action("UNDO_COMPLETED", "Отменено последнее изменение шаблона.", {
    before,
    after: {
      undoDepth: history.undo.length,
      redoDepth: history.redo.length,
      selectedNames: getSelectedNames()
    }
  });
  appLogger.state("APPLICATION_STATE_AFTER_UNDO", "Состояние после Undo.");
}
function redo() {
  if (!history.redo.length) return;
  const before = {
    undoDepth: history.undo.length,
    redoDepth: history.redo.length,
    selectedNames: getSelectedNames()
  };
  const next = history.redo.pop();
  history.undo.push(snapshotState());
  restoreFromSnapshot(next);
  if (typeof markActiveTemplateTabDirty === "function") markActiveTemplateTabDirty();
  appLogger.action("REDO_COMPLETED", "Повторено ранее отменённое изменение шаблона.", {
    before,
    after: {
      undoDepth: history.undo.length,
      redoDepth: history.redo.length,
      selectedNames: getSelectedNames()
    }
  });
  appLogger.state("APPLICATION_STATE_AFTER_REDO", "Состояние после Redo.");
}
function updateUndoRedoButtons() {
  $("btnUndo").disabled = history.undo.length <= 1;
  $("btnRedo").disabled = history.redo.length === 0;
}

// ---------- LOSSLESS SAVE (CRLF, 2 lines) ----------
function sanitizeTemplateDownloadName(value) {
  return String(value ?? "")
    .trim()
    .replace(/[\\/:*?"<>|]+/g, "-")
    .replace(/[\u0000-\u001f]+/g, " ")
    .replace(/\s+/g, " ")
    .replace(/^[. ]+|[. ]+$/g, "")
    .trim();
}

function buildTemplateDownloadFilename(value) {
  const name = sanitizeTemplateDownloadName(value);
  if (!name) return "";
  return /\.(ciff|xml)$/i.test(name) ? name : `${name}.ciff`;
}

function openSaveTemplateModal() {
  if (!state.line2 || !state.line1 || !elSaveTemplateModal) return false;
  if (elSaveTemplateName) {
    elSaveTemplateName.value = typeof getActiveTemplateTabSaveName === "function"
      ? getActiveTemplateTabSaveName()
      : "";
    elSaveTemplateName.setCustomValidity("");
    elSaveTemplateName.removeAttribute("aria-invalid");
  }
  elSaveTemplateModal.classList.remove("hidden");
  elSaveTemplateModal.setAttribute("aria-hidden", "false");
  document.body.classList.add("modal-open");
  setTimeout(() => elSaveTemplateName?.focus(), 0);
  return true;
}

function closeSaveTemplateModal(options = {}) {
  if (!elSaveTemplateModal) return;
  if (!options.preservePendingTabClose && typeof cancelPendingTemplateTabCloseAfterSave === "function") {
    cancelPendingTemplateTabCloseAfterSave();
  }
  elSaveTemplateModal.classList.add("hidden");
  elSaveTemplateModal.setAttribute("aria-hidden", "true");
  document.body.classList.toggle("modal-open", Boolean(document.querySelector(".modal:not(.hidden)")));
}

async function saveTemplateFromDialog() {
  if (!elSaveTemplateName) return;
  elSaveTemplateName.setCustomValidity("");
  if (!elSaveTemplateName.reportValidity()) return;

  const filename = buildTemplateDownloadFilename(elSaveTemplateName.value);
  if (!filename) {
    elSaveTemplateName.setCustomValidity(t("dialog.saveTemplate.nameRequired"));
    elSaveTemplateName.setAttribute("aria-invalid", "true");
    elSaveTemplateName.reportValidity();
    return;
  }

  appLogger.file("TEMPLATE_SAVE_CONFIRMED", "Пользователь подтвердил сохранение шаблона.", {
    filename,
    activeTemplateTitle: typeof getActiveTemplateTab === "function" ? getActiveTemplateTab()?.title : null
  });
  if (saveTemplateFromDialog.pending) return;
  saveTemplateFromDialog.pending = true;
  const savingDocument = state.xmlDoc;
  const savingNow = new Date();
  try {
    if (typeof ensureNativeTextGeometry === 'function') await ensureNativeTextGeometry(state.fields, savingNow);
    if (state.xmlDoc !== savingDocument) return;
    if (downloadCiff(filename, savingNow)) {
      if (typeof markActiveTemplateTabSaved === "function") markActiveTemplateTabSaved(filename);
      closeSaveTemplateModal({ preservePendingTabClose: true });
    }
  } catch (error) {
    openNotificationModal(t('field.fontMeasureFailed'));
  } finally {
    saveTemplateFromDialog.pending = false;
  }
}

function downloadCiff(filename = "template.ciff", now = new Date()) {
  if (!state.line2 || !state.line1) return false;
  const normalizedFilename = buildTemplateDownloadFilename(filename) || "template.ciff";
  appLogger.file("TEMPLATE_SAVE_STARTED", "Начата подготовка шаблона к сохранению.", {
    filename: normalizedFilename,
    fieldCount: state.fields.length,
    printedFieldCount: state.fields.filter((field) => field.printed).length,
    hiddenFieldCount: state.fields.filter((field) => !field.printed).length,
    dateOffsetCount: state.dateOffsets.length
  });

  try {
    const prepared = prepareCiffForSave(now, { sourcePath: normalizedFilename });
    if (!prepared.validation.ok) {
      appLogger.file("TEMPLATE_SAVE_BLOCKED", "Сохранение заблокировано проверкой совместимости CIFF.", {
        filename: normalizedFilename,
        validation: prepared.validation
      }, "WARN");
      showCiffSaveCompatibilityError(prepared.validation);
      return false;
    }

    const u16 = encodeUtf16leWithBom(prepared.outputText);
    const blob = new Blob([u16], { type: "application/xml;charset=UTF-16" });
    const a = document.createElement("a");
    a.href = URL.createObjectURL(blob);
    a.download = normalizedFilename;
    document.body.appendChild(a);
    a.click();
    setTimeout(() => {
      URL.revokeObjectURL(a.href);
      a.remove();
    }, 250);
    appLogger.file("TEMPLATE_DOWNLOAD_TRIGGERED", "Файл шаблона подготовлен, передан браузеру и ожидает сохранения на устройство.", {
      filename: normalizedFilename,
      sizeBytes: u16.byteLength,
      encoding: "UTF-16LE with BOM",
      lineEnding: "CRLF",
      fieldCount: state.fields.length,
      selectedNames: getSelectedNames()
    });
    appLogger.state("APPLICATION_STATE_AFTER_SAVE", "Состояние после запуска сохранения шаблона.", {
      filename: normalizedFilename,
      sizeBytes: u16.byteLength
    });
    commitPreparedCiffToState(prepared);
    return true;
  } catch (error) {
    const message = error instanceof Error ? error.message : String(error);
    appLogger.file("TEMPLATE_SAVE_FAILED", "Не удалось сформировать совместимый CIFF-файл.", {
      filename: normalizedFilename,
      error: message
    }, "ERROR");
    showCiffSaveCompatibilityError({
      invalidPrintableFieldNames: [],
      invalidHardwareFieldNames: [],
      structuralErrors: [message]
    });
    return false;
  }
}

// preview: returns {line1,line2}
function patchXmlLosslessV2Preview(options = {}) {
  const sourceSnapshot = snapshotState();
  try {
    return patchXmlLosslessV2PreviewMutating(options);
  } finally {
    restoreFromSnapshot(sourceSnapshot, { render: false });
  }
}

function patchXmlLosslessV2PreviewMutating(options = {}) {
  const now = getFrozenSaveDate(options.now);
  if (!options.skipCapabilitySync) normalizeKnownPrinterCapabilitiesForSave();
  if (!options.skipDateOffsetSync) synchronizeDirtyDateOffsetCurrents(now);
  // Resolve once before serialization; XML and ClSt consume the same raw
  // CalculatedData snapshot, before XML control-character filtering.
  const calculatedData = prepareCiffCalculatedData(state.fields, now, { fieldByName: state.fieldByName });
  state.fields.forEach((field) => {
    const value = calculatedData.get(field);
    if (value != null) field.calcData = value;
    for (const segment of field.barcode?.dataMatrix?.segments || []) {
      const source = segment.srcField ? state.fieldByName.get(segment.srcField) : null;
      if (source && calculatedData.get(source) != null) {
        segment.defaultValue = selectCiffSourceFieldData(calculatedData.get(source), segment);
      }
    }
    if (Number(field.data?.dataType) === 5 && field.data?.srcField) {
      const source = state.fieldByName.get(field.data.srcField);
      if (source && calculatedData.get(source) != null) {
        field.data.defaultValue = selectCiffSourceFieldData(calculatedData.get(source), field.data);
      }
    }
  });

  const line1 = normalizeCiffXmlDeclaration(state.line1);
  let line2 = state.line2;

  // Expand/patch Header before DateOffset handling, but defer ClSt until the
  // final structure is known.
  line2 = patchHeaderMetadataLossless(line2, { now, deferClSt: true });

  // restore mandatory SubImage metadata without rebuilding unknown XML
  line2 = patchSubImageReferenceLossless(line2);

  // patch SubHeader sizes
  line2 = patchSubHeaderLossless(line2, { now });

  // keep ImageMapping synchronized with SubImage ImageReference
  line2 = patchImageMappingLossless(line2);

  // patch DateOffsets only if loaded+dirty
  if (state.dateOffsetsLoaded && state.dateOffsetsDirty) {
    line2 = patchDateOffsetsLosslessV2(line2);
  }

  // patch fields (delete + upsert + insert)
  line2 = patchFieldsLosslessV2(line2, now, calculatedData);

  // ClSt is patched last so its structural counts observe the same DateOffset
  // and Field structure that will be serialized.
  line2 = patchClStVersionInfoForSaveLossless(line2, { ...options, now, calculatedData });

  return { line1, line2, calculatedData };
}

function patchXmlLosslessV2(options = {}) {
  return buildCiffOutputText(patchXmlLosslessV2Preview(options));
}

function prepareCiffForSave(now = new Date(), options = {}) {
  const frozenNow = getFrozenSaveDate(now);
  const sourceSnapshot = snapshotState();
  let validation = null;
  try {
    normalizeKnownPrinterCapabilitiesForSave();
    synchronizeDirtyDateOffsetCurrents(frozenNow);

    const patched = patchXmlLosslessV2PreviewMutating({
      ...options,
      now: frozenNow,
      skipCapabilitySync: true,
      skipDateOffsetSync: true
    });
    validation = validateCiffCompatibility(patched, { now: frozenNow, calculatedData: patched.calculatedData });
    const outputText = buildCiffOutputText(patched);
    const draftStateSnapshot = snapshotState();
    return { ...patched, outputText, validation, now: frozenNow, draftStateSnapshot };
  } finally {
    restoreFromSnapshot(sourceSnapshot, { render: false });
    if (validation) {
      state.validation = {
        ...(state.validation || {}),
        invalidPrintableFieldNames: [...validation.invalidPrintableFieldNames],
        invalidHardwareFieldNames: [...validation.invalidHardwareFieldNames],
        structuralErrors: [...validation.structuralErrors]
      };
    }
  }
}

function commitPreparedCiffToState(prepared) {
  if (!prepared?.line1 || !prepared?.line2) return false;
  if (prepared.draftStateSnapshot) {
    restoreFromSnapshot(prepared.draftStateSnapshot, { render: false });
  }
  state.line1 = prepared.line1;
  state.line2 = prepared.line2;
  state.xmlText = `${prepared.line1}\n${prepared.line2}`;
  state.lineEnding = "\r\n";
  state.dateOffsetsDirty = false;
  state.dateOffsets.forEach((offset) => {
    offset.sourceName = offset.name;
  });
  if (state.subImage) state.subImage.usedSizeDirty = false;
  state.fields.forEach((field) => {
    const newDataStructure = field.sourceName == null || field.barcode?.dataMatrix?.structureDirty === true;
    field.sourceName = field.name;
    if (field.barcode?.dataMatrix) {
      field.barcode.dataMatrix.structureDirty = false;
      if (newDataStructure) field.barcode.dataMatrix.segments.forEach((segment, index) => { segment.sourceObjectIndex = index; });
    }
  });

  if (typeof DOMParser === "function") {
    const doc = new DOMParser().parseFromString(state.xmlText, "text/xml");
    if (!doc.querySelector?.("parsererror")) state.xmlDoc = doc;
  }
  return true;
}

function getFrozenSaveDate(value = new Date()) {
  const date = Object.prototype.toString.call(value) === "[object Date]" ? value : new Date(value);
  if (!Number.isFinite(date.getTime())) throw new Error("Cannot save CIFF with an invalid current date.");
  return date;
}

function getExactKnownPrinterCapabilitiesForSave(printerModel = state.docMeta?.printerModel) {
  const model = String(printerModel ?? "").trim();
  if (typeof PRINTER_CAPABILITIES === "undefined" || !PRINTER_CAPABILITIES) return null;
  return Object.prototype.hasOwnProperty.call(PRINTER_CAPABILITIES, model)
    ? PRINTER_CAPABILITIES[model]
    : null;
}

function normalizeKnownPrinterCapabilitiesForSave() {
  const capabilities = getExactKnownPrinterCapabilitiesForSave();
  if (!capabilities || !state.subImage) return null;
  // MaxImage* stores the document area, not the selected head's limits.
  // An absent Max* inherits Image* in the native reader. Explicit zero is a
  // stored value; screen/hardware fallbacks must never be written over it.
  for (const [maximum, image] of [["maxWidth", "width"], ["maxHeight", "height"]]) {
    if (state.subImage[maximum] == null && state.subImage[image] != null) {
      state.subImage[maximum] = state.subImage[image];
    }
  }
  if (!(Number(state.subImage.xRes) > 0)) {
    state.subImage.xRes = Number(capabilities.xRes);
  }
  return capabilities;
}

function synchronizeDirtyDateOffsetCurrents(now = new Date()) {
  if (!state.dateOffsetsLoaded) return false;
  const hasInvalidCurrent = state.dateOffsets.some((offset) => (
    !isValidCalendarDateParts(normalizeCalendarDatePartsForSave(offset?.current))
  ));
  if (!state.dateOffsetsDirty && !hasInvalidCurrent) return false;
  if (hasInvalidCurrent) state.dateOffsetsDirty = true;
  const frozenNow = getFrozenSaveDate(now);

  state.dateOffsets.forEach((offset) => {
    const current = getComputedDateOffsetCurrent(offset, frozenNow);
    const normalized = normalizeCalendarDatePartsForSave(current);
    if (!isValidCalendarDateParts(normalized)) {
      throw new Error(`DateOffset "${String(offset?.name ?? "")}" produced an invalid CurrentOffset.`);
    }
    offset.current = normalized;
  });
  return true;
}

function normalizeDateOffsetDeltaForSave(value) {
  const result = {};
  for (const key of ["y", "m", "d"]) {
    const number = Number(value?.[key] ?? 0);
    if (!Number.isFinite(number) || !Number.isInteger(number)) {
      throw new Error(`DateOffset DefaultOffset.${key} must be an integer.`);
    }
    result[key] = number;
  }
  return result;
}

function normalizeCalendarDatePartsForSave(value) {
  return {
    y: Number(value?.y),
    m: Number(value?.m),
    d: Number(value?.d)
  };
}

function isValidCalendarDateParts(value) {
  const y = Number(value?.y);
  const m = Number(value?.m);
  const d = Number(value?.d);
  if (!Number.isInteger(y) || !Number.isInteger(m) || !Number.isInteger(d)) return false;
  if (y < 1 || y > 9999 || m < 1 || m > 12 || d < 1 || d > 31) return false;

  const probe = new Date(0);
  probe.setUTCHours(12, 0, 0, 0);
  probe.setUTCFullYear(y, m - 1, d);
  return probe.getUTCFullYear() === y && probe.getUTCMonth() === m - 1 && probe.getUTCDate() === d;
}

function normalizeCiffXmlDeclaration(line1) {
  let declaration = String(line1 ?? "").replace(/^\uFEFF/, "").trim();
  if (!/^<\?xml\b[^?]*\?>$/i.test(declaration)) {
    throw new Error("CIFF XML declaration is missing or invalid.");
  }
  if (/\bencoding\s*=\s*(["'])[^"']*\1/i.test(declaration)) {
    declaration = declaration.replace(/\bencoding\s*=\s*(["'])[^"']*\1/i, 'encoding="UTF-16"');
  } else {
    declaration = declaration.replace(/\?>$/, ' encoding="UTF-16"?>');
  }
  return declaration;
}

function buildCiffOutputText(patched) {
  const line1 = String(patched?.line1 ?? "");
  const line2 = String(patched?.line2 ?? "");
  if (!line1 || !line2) throw new Error("CIFF output is missing the XML declaration or ImageDesign document.");
  if (/[\r\n]/.test(line1)) {
    throw new Error("CIFF XML declaration must occupy a single line.");
  }
  // The envelope uses CRLF. Embedded source whitespace (including SQL/CDATA
  // line breaks) is document data and must not be flattened to force two lines.
  return `${line1}\r\n${line2}\r\n`;
}

function getLocalizedSaveCompatibilityText(key, fallback) {
  if (typeof t !== "function") return fallback;
  const translated = t(key);
  return translated && translated !== key ? translated : fallback;
}

function showCiffSaveCompatibilityError(validation) {
  const details = formatCiffCompatibilityErrors(validation);
  const title = getLocalizedSaveCompatibilityText(
    "dialog.saveCompatibilityError.title",
    "Cannot save template"
  );
  const intro = getLocalizedSaveCompatibilityText(
    "dialog.saveCompatibilityError.message",
    "The template is not compatible with the selected printer configuration."
  );
  if (typeof openNotificationModal === "function") {
    openNotificationModal(details ? `${intro}\n\n${details}` : intro, title);
  }
}

function formatCiffCompatibilityErrors(validation = {}) {
  const sections = [];
  const structuralErrors = Array.isArray(validation.structuralErrors) ? validation.structuralErrors : [];
  const invalidPrintable = Array.isArray(validation.invalidPrintableFieldNames)
    ? validation.invalidPrintableFieldNames
    : [];
  const invalidHardware = Array.isArray(validation.invalidHardwareFieldNames)
    ? validation.invalidHardwareFieldNames
    : [];
  if (structuralErrors.length) sections.push(structuralErrors.map((error) => `- ${error}`).join("\n"));
  if (invalidPrintable.length) {
    sections.push(`Fields outside the printable area:\n${invalidPrintable.map((name) => `- ${name}`).join("\n")}`);
  }
  if (invalidHardware.length) {
    sections.push(`Fields outside printer hardware limits:\n${invalidHardware.map((name) => `- ${name}`).join("\n")}`);
  }
  return sections.join("\n\n");
}

/* ---- split to 2 lines ---- */
function splitTwoLines(xmlText) {
  const match = String(xmlText).replace(/^\uFEFF/, "").match(/^\s*(<\?xml\b[\s\S]*?\?>)\s*([\s\S]*?)\s*$/);
  if (!match) throw new Error("Cannot split XML: missing XML declaration.");
  return { line1: match[1], line2: match[2] };
}

/* ---- Mandatory CIFF metadata patching ---- */
function patchHeaderMetadataLossless(line2, options = {}) {
  const header = extractImageDesignDirectChildBlock(line2, "Header");
  if (!header) throw new Error("Header not found");

  let block = header.block;
  if (/^<Header\b[^>]*\/\s*>$/.test(block)) {
    block = block.replace(/\/\s*>$/, "></Header>");
  }
  const capabilities = getExactKnownPrinterCapabilitiesForSave();
  const sourceDesignedFor = String(state.docMeta?.designedFor ?? "").trim();
  const designedFor = capabilities
    ? buildDesignedForLabel(state.docMeta.printerModel, state.docMeta.printMode)
    : sourceDesignedFor;
  state.docMeta.designedFor = designedFor;

  const openTag = block.match(/^<Header\b[^>]*>/)?.[0];
  if (!openTag) throw new Error("Header opening tag not found");
  block = block.replace(openTag, setOrInsertXmlAttribute(openTag, "DesignedFor", designedFor));

  const lineWithPatchedHeader = line2.slice(0, header.start) + block + line2.slice(header.end);
  if (options.deferClSt) return lineWithPatchedHeader;

  return patchClStVersionInfoForSaveLossless(lineWithPatchedHeader, options);
}

function patchClStVersionInfoForSaveLossless(line2, options = {}) {
  const header = extractImageDesignDirectChildBlock(line2, "Header");
  if (!header) throw new Error("Header not found");
  let block = header.block;

  const originalClStVersionInfo = readClStVersionInfoFromHeaderBlock(block);
  const clStResolution = resolveClStVersionInfoForSave(line2, {
    now: options.now instanceof Date ? options.now : getFrozenSaveDate(options.now),
    designedFor: state.docMeta.designedFor,
    ...options,
    originalClStVersionInfo
  });
  if (clStResolution.shouldPatch) {
    block = patchClStVersionInfoLossless(block, clStResolution.value);
  }
  state.docMeta.clStVersionInfo = clStResolution.value;
  state.docMeta.clStIncludeFileMetadata = clStResolution.includeFileMetadata;
  if (clStResolution.sourcePath) state.docMeta.sourceFileName = clStResolution.sourcePath;

  return line2.slice(0, header.start) + block + line2.slice(header.end);
}

function buildClStTemplateForSave(line2, options = {}) {
  const imageDesign = extractBlock(line2, "<ImageDesign", "</ImageDesign>");
  if (!imageDesign) throw new Error("ImageDesign not found for ClStVersionInfo.");
  const header = findDirectChildElementRangeLossless(imageDesign.block, "Header");
  const headerBlock = header ? imageDesign.block.slice(header.start, header.end) : "";
  const modelByName = new Map((state.fields || []).map((field) => [field.name, field]));
  const snapshot = options.calculatedData;
  const subImages = listDirectChildElementRangesLossless(imageDesign.block, "SubImage").map((range, subImageIndex) => {
    const block = imageDesign.block.slice(range.start, range.end);
    return { fields: listDirectChildElementRangesLossless(block, "Field").map((fieldRange) => {
      const fieldBlock = block.slice(fieldRange.start, fieldRange.end);
      const name = getXmlAttributeValue(fieldBlock.match(/^<Field\b[^>]*>/)?.[0], "Name") ?? "";
      const modelField = subImageIndex === 0 ? modelByName.get(name) : null;
      const calculatedData = modelField && snapshot?.has(modelField)
        ? snapshot.get(modelField)
        // CiffMgr's XML importer also normalizes CR from character references.
        // Prepared editor values above retain their original control characters.
        : (getDirectChildTagTextForValidation(fieldBlock.replace(/\r\n?/g, "\n"), "CalcData") ?? "")
          .replace(/\r\n?/g, "\n");
      return { name, fldType: getDirectChildTagTextForValidation(fieldBlock, "FldType"), calculatedData };
    }) };
  });
  return {
    dateOffsets: Array.from({ length: listDirectChildElementRangesLossless(headerBlock, "DateOffset").length }, () => ({})),
    subImages
  };
}

function resolveClStVersionInfoForSave(line2, options = {}) {
  const template = buildClStTemplateForSave(line2, options);
  const original = options.originalClStVersionInfo ?? state.docMeta?.clStVersionInfo ?? "";
  const originalSourcePath = state.docMeta?.sourceFileName || "";
  const includeFileMetadata = state.docMeta?.clStIncludeFileMetadata === true ||
    recognizeClStFileMetadataMode(original, originalSourcePath);
  const sourcePath = options.sourcePath ?? originalSourcePath;
  const debugInfo = buildClStVersionInfoDebugInfo(template, options.now, {
    ...(options.clstOptions || {}),
    includeFileMetadata,
    sourcePath
  });
  if (debugInfo.clStVersionInfo == null) {
    throw new Error("Cannot calculate ClStVersionInfo: selected Field CalculatedData is unavailable.");
  }
  return { value: debugInfo.clStVersionInfo, shouldPatch: true, generated: true,
    includeFileMetadata, sourcePath, debugInfo };
}

function readClStVersionInfoFromHeaderBlock(headerBlock) {
  const ranges = listDirectChildElementRangesLossless(headerBlock, "ClStVersionInfo");
  if (ranges.length !== 1 || ranges[0].selfClosing) return "";
  const range = findDirectChildElementRangeLossless(headerBlock, "ClStVersionInfo");
  if (!range || range.selfClosing) return "";
  const sourceXml = headerBlock.slice(range.openEnd, range.closeStart);
  if (hasNestedClStVersionInfoMarkup(sourceXml)) return "";
  return decodeClStVersionInfoXmlText(sourceXml);
}

function hasNestedClStVersionInfoMarkup(value) {
  const withoutCdata = String(value ?? "").replace(/<!\[CDATA\[[\s\S]*?\]\]>/g, "");
  return /<[^>]*>/.test(withoutCdata);
}

function decodeClStVersionInfoXmlText(value) {
  const source = String(value ?? "");
  const expression = /<!\[CDATA\[([\s\S]*?)\]\]>/g;
  let result = "";
  let cursor = 0;
  let match;

  while ((match = expression.exec(source))) {
    result += decodeXmlEntities(source.slice(cursor, match.index));
    result += match[1];
    cursor = expression.lastIndex;
  }
  return result + decodeXmlEntities(source.slice(cursor));
}

function patchClStVersionInfoLossless(headerBlock, value) {
  const tagName = "ClStVersionInfo";
  const text = String(value ?? "");
  const escapedText = escapeHtml(text);
  const directRanges = listDirectChildElementRangesLossless(headerBlock, tagName);

  if (directRanges.length > 1) {
    let repairedHeader = headerBlock;
    [...directRanges].reverse().forEach((directRange) => {
      repairedHeader = repairedHeader.slice(0, directRange.start) + repairedHeader.slice(directRange.end);
    });
    return patchClStVersionInfoLossless(repairedHeader, text);
  }

  const range = findDirectChildElementRangeLossless(headerBlock, tagName);

  if (!range) {
    const openEnd = headerBlock.indexOf(">");
    if (openEnd < 0) throw new Error("Header opening tag not found while writing ClStVersionInfo");
    const xml = `<${tagName}>${escapedText}</${tagName}>`;
    return headerBlock.slice(0, openEnd + 1) + xml + headerBlock.slice(openEnd + 1);
  }

  if (range.selfClosing) {
    const openTag = headerBlock.slice(range.start, range.end).replace(/\/\s*>$/, ">");
    const replacement = `${openTag}${escapedText}</${tagName}>`;
    return headerBlock.slice(0, range.start) + replacement + headerBlock.slice(range.end);
  }

  const sourceXml = headerBlock.slice(range.openEnd, range.closeStart);
  const sourceText = decodeXmlTextForValidation(sourceXml);
  if (sourceText === text && isUsableClStVersionInfo(sourceXml)) return headerBlock;
  return headerBlock.slice(0, range.openEnd) + escapedText + headerBlock.slice(range.closeStart);
}

function patchSubImageReferenceLossless(line2) {
  const subImageOpen = line2.match(/<SubImage\b[^>]*>/)?.[0];
  if (!subImageOpen) throw new Error("SubImage not found");

  const imageReference = String(state.subImage?.imageReference ?? "1");
  state.subImage.imageReference = imageReference;
  const sourceReference = getXmlAttributeValue(subImageOpen, "ImageReference");
  if (sourceReference == null && imageReference === "1") return line2;
  if (sourceReference === String(state.subImage?.imageReference)) return line2;
  return line2.replace(subImageOpen, setOrInsertXmlAttribute(subImageOpen, "ImageReference", imageReference));
}

function patchSubHeaderLossless(line2, options = {}) {
  const geometryChanged = typeof hasPrintableGeometryChangedFromSourceXml === "function"
    && hasPrintableGeometryChangedFromSourceXml(state.fields) === true;
  if ((state.subImage?.usedSizeDirty || geometryChanged) && typeof syncUsedImageSizeFromPrintableFields === "function") {
    syncUsedImageSizeFromPrintableFields(getFrozenSaveDate(options.now), { forceFresh: true });
  }

  const sub = extractBlock(line2, "<SubImage", "</SubImage>");
  if (!sub) throw new Error("SubImage not found");
  let subBlock = sub.block;
  let sh = extractBlock(subBlock, "<SubHeader", "</SubHeader>");

  if (!sh) {
    const subOpen = subBlock.match(/^<SubImage\b[^>]*>/)?.[0];
    if (!subOpen) throw new Error("SubImage opening tag not found");
    subBlock = subBlock.replace(subOpen, subOpen + buildRequiredSubHeaderXml());
  } else {
    let block = sh.block;
    const openTag = block.match(/^<SubHeader\b[^>]*>/)?.[0];
    if (!openTag) throw new Error("SubHeader opening tag not found");
    const values = getRequiredSubHeaderValues();
    for (const tag of Object.keys(values)) {
      const sourceValue = getDirectChildTagTextForValidation(block, tag);
      if (sourceValue != null && Number(sourceValue) === Number(values[tag])) continue;
      block = upsertDirectChildTagInOrder(block, tag, values[tag], Object.keys(values));
    }
    if (Object.prototype.hasOwnProperty.call(state.subImage || {}, "yRes") && state.subImage.yRes == null) {
      const yRes = findDirectChildElementRangeLossless(block, "YRes");
      if (yRes) block = block.slice(0, yRes.start) + block.slice(yRes.end);
    }
    subBlock = subBlock.slice(0, sh.start) + block + subBlock.slice(sh.end);
  }

  return line2.slice(0, sub.start) + subBlock + line2.slice(sub.end);
}

function patchImageMappingLossless(line2) {
  const imageReference = String(state.subImage?.imageReference ?? "1");
  const sourceOpen = state.line2.match(/<SubImage\b[^>]*>/)?.[0];
  const sourceReference = getXmlAttributeValue(sourceOpen, "ImageReference") ?? "1";
  // Mapping is optional on imported documents. Only an explicit reference edit
  // requires synchronizing it; new templates already contain their mapping.
  if (sourceReference === imageReference) return line2;
  const imageDesign = extractBlock(line2, "<ImageDesign", "</ImageDesign>");
  if (!imageDesign) throw new Error("ImageDesign root not found");
  let rootBlock = imageDesign.block;
  let genericSettings = extractBlock(rootBlock, "<GenericSettings", "</GenericSettings>");

  if (!genericSettings) {
    rootBlock = insertBeforeClosingTag(
      rootBlock,
      "</ImageDesign>",
      `<GenericSettings>${buildImageMappingXml(imageReference)}</GenericSettings>`
    );
  } else {
    let settingsBlock = genericSettings.block;
    const imageMapping = extractBlock(settingsBlock, "<ImageMapping", "</ImageMapping>");
    if (!imageMapping) {
      settingsBlock = insertBeforeClosingTag(settingsBlock, "</GenericSettings>", buildImageMappingXml(imageReference));
    } else {
      let mappingBlock = imageMapping.block;
      const mapBlocks = mappingBlock.match(/<Map\b[^>]*>[\s\S]*?<\/Map>/g) || [];
      const mapBlock = mapBlocks.find((candidate) => {
        const candidateOpen = candidate.match(/^<Map\b[^>]*>/)?.[0];
        const attributeReference = String(getXmlAttributeValue(candidateOpen, "SubIMageRef") ?? "").trim();
        const valueReference = decodeXmlEntities(candidate.replace(/^<Map\b[^>]*>|<\/Map>$/g, "").trim());
        return attributeReference === imageReference || valueReference === imageReference;
      });
      if (!mapBlock) {
        mappingBlock = insertBeforeClosingTag(mappingBlock, "</ImageMapping>", buildImageMapXml(imageReference));
      } else {
        const mapOpen = mapBlock.match(/^<Map\b[^>]*>/)?.[0];
        if (!mapOpen) throw new Error("ImageMapping Map opening tag not found");
        const patchedMapOpen = setOrInsertXmlAttribute(mapOpen, "SubIMageRef", imageReference);
        const patchedMap = mapBlock
          .replace(mapOpen, patchedMapOpen)
          .replace(/(<Map\b[^>]*>)[\s\S]*?(<\/Map>)/, (match, open, close) => open + escapeHtml(imageReference) + close);
        mappingBlock = mappingBlock.replace(mapBlock, patchedMap);
      }
      settingsBlock = settingsBlock.slice(0, imageMapping.start) + mappingBlock + settingsBlock.slice(imageMapping.end);
    }
    rootBlock = rootBlock.slice(0, genericSettings.start) + settingsBlock + rootBlock.slice(genericSettings.end);
  }

  return line2.slice(0, imageDesign.start) + rootBlock + line2.slice(imageDesign.end);
}

function getRequiredSubHeaderValues() {
  const capabilities = getExactKnownPrinterCapabilitiesForSave();
  const sourceXRes = Number(state.subImage?.xRes);
  const xRes = sourceXRes > 0
    ? formatCiffXRes(sourceXRes)
    : (capabilities?.xResText ?? formatCiffXRes(capabilities?.xRes));
  return {
    ImageWidth: String(state.subImage?.width ?? ""),
    ImageHeight: String(state.subImage?.height ?? ""),
    MaxImageWidth: String(state.subImage?.maxWidth ?? state.subImage?.width ?? ""),
    MaxImageHeight: String(state.subImage?.maxHeight ?? state.subImage?.height ?? ""),
    XRes: xRes,
    ...(state.subImage?.yRes != null ? { YRes: formatCiffXRes(state.subImage.yRes) } : {}),
    CurrentOrientation: String(state.subImage?.orientation ?? 0)
  };
}

function formatCiffXRes(value) {
  const number = Number(value);
  return Number.isFinite(number) && number > 0 ? number.toFixed(6) : String(value ?? 0);
}

function buildRequiredSubHeaderXml() {
  const values = getRequiredSubHeaderValues();
  const children = Object.entries(values).map(([tag, value]) => `<${tag}>${escapeHtml(value)}</${tag}>`).join("");
  return `<SubHeader FormatName="Default" PrinterFormatName="Default">${children}</SubHeader>`;
}

function setOrInsertXmlAttribute(openTag, attributeName, value) {
  const escapedName = escapeReg(attributeName);
  const expression = new RegExp(`(\\s${escapedName}\\s*=\\s*)(["'])([\\s\\S]*?)\\2`, "i");
  if (expression.test(openTag)) {
    return openTag.replace(expression, (match, prefix, quote) => `${prefix}${quote}${escapeAttrForQuote(value, quote)}${quote}`);
  }
  return openTag.replace(/\s*>$/, ` ${attributeName}="${escapeAttr(value)}">`);
}

function getXmlAttributeValue(openTag, attributeName) {
  const expression = new RegExp(`\\s${escapeReg(attributeName)}\\s*=\\s*(["'])([\\s\\S]*?)\\1`, "i");
  const match = String(openTag ?? "").match(expression);
  return match ? decodeXmlEntities(match[2]) : null;
}

function ensureNonEmptyXmlAttribute(openTag, attributeName, fallback) {
  const current = getXmlAttributeValue(openTag, attributeName);
  return current && current.trim() ? openTag : setOrInsertXmlAttribute(openTag, attributeName, fallback);
}

function upsertDirectChildTagInOrder(block, tag, value, tagOrder) {
  const openEnd = block.indexOf(">");
  const closeStart = block.lastIndexOf("</");
  if (openEnd < 0 || closeStart <= openEnd) throw new Error(`Invalid parent block while writing ${tag}.`);
  const inner = block.slice(openEnd + 1, closeStart);
  const range = typeof findDirectChildTagContentRange === "function"
    ? findDirectChildTagContentRange(inner, tag)
    : findSimpleDirectChildTagContentRange(inner, tag);
  if (range) {
    const start = openEnd + 1 + range.start;
    const end = openEnd + 1 + range.end;
    return block.slice(0, start) + escapeHtml(value) + block.slice(end);
  }

  const currentIndex = tagOrder.indexOf(tag);
  let insertAt = closeStart;
  for (const nextTag of tagOrder.slice(currentIndex + 1)) {
    const nextMatch = new RegExp(`<${escapeReg(nextTag)}(?:\\s[^>]*)?>`).exec(block.slice(openEnd + 1, closeStart));
    if (nextMatch) {
      insertAt = openEnd + 1 + nextMatch.index;
      break;
    }
  }
  const xml = `<${tag}>${escapeHtml(value)}</${tag}>`;
  return block.slice(0, insertAt) + xml + block.slice(insertAt);
}

function findSimpleDirectChildTagContentRange(inner, tag) {
  const expression = new RegExp(`<${escapeReg(tag)}(?:\\s[^>]*)?>([\\s\\S]*?)<\\/${escapeReg(tag)}>`);
  const match = expression.exec(inner);
  if (!match) return null;
  const openLength = match[0].indexOf(">") + 1;
  return {
    start: match.index + openLength,
    end: match.index + openLength + match[1].length
  };
}

function buildImageMapXml(imageReference) {
  return `<Map SubIMageRef="${escapeAttr(imageReference)}">${escapeHtml(imageReference)}</Map>`;
}

function buildImageMappingXml(imageReference) {
  return `<ImageMapping>${buildImageMapXml(imageReference)}</ImageMapping>`;
}

/* ---- DateOffsets patch (only when dirty) ---- */
function patchDateOffsetsLosslessV2(line2) {
  const header = extractImageDesignDirectChildBlock(line2, "Header");
  if (!header) throw new Error("Header not found");

  let h = header.block;
  const pendingOffsets = state.dateOffsets.map((offset) => ({ offset, matched: false }));

  const parts = [];
  let cursor = 0;
  // Header extensions and CDATA may use the same tag names. Only direct
  // DateOffset children belong to the editable offset collection.
  for (const range of listDirectChildElementRangesLossless(h, "DateOffset")) {
    const block = h.slice(range.start, range.end);
    const openTag = block.match(/^<DateOffset\b[^>]*>/)?.[0] || "";
    const sourceName = getXmlAttributeValue(openTag, "Name");
    const match = pendingOffsets.find((entry) => (
      !entry.matched &&
      String(entry.offset?.sourceName ?? entry.offset?.name ?? "") === String(sourceName ?? "")
    ));

    parts.push(h.slice(cursor, range.start));
    // An imported offset that is no longer present in state was deleted by the user.
    if (match) {
      match.matched = true;
      parts.push(patchExistingDateOffsetBlockLossless(block, match.offset));
    }
    cursor = range.end;
  }
  parts.push(h.slice(cursor));
  h = parts.join("");

  // New (or renamed) offsets have no source block whose opaque XML can be retained.
  const offsetsStr = pendingOffsets
    .filter((entry) => !entry.matched)
    .map((entry) => buildDateOffsetXml(entry.offset))
    .join("");
  h = insertBeforeClosingTag(h, "</Header>", offsetsStr);

  return line2.slice(0, header.start) + h + line2.slice(header.end);
}

function patchExistingDateOffsetBlockLossless(block, offset) {
  const defaultOffset = normalizeDateOffsetDeltaForSave(offset?.default);
  const current = normalizeCalendarDatePartsForSave(offset?.current);
  if (!isValidCalendarDateParts(current)) {
    throw new Error(`DateOffset "${String(offset?.name ?? "")}" has an invalid CurrentOffset.`);
  }

  let next = patchDateOffsetNameLossless(block, offset?.name);
  next = patchDateOffsetChildBlockLossless(
    next,
    "DefaultOffset",
    defaultOffset,
    false,
    buildDefaultOffsetXml(defaultOffset)
  );
  next = patchDateOffsetChildBlockLossless(
    next,
    "CurrentOffset",
    current,
    true,
    buildCurrentOffsetXml(current)
  );
  return next;
}

function patchDateOffsetNameLossless(block, name) {
  const openTag = String(block ?? "").match(/^<DateOffset\b[^>]*>/)?.[0] || "";
  if (!openTag) return block;
  const escapedName = escapeAttr(name);
  const nameExpression = /(\sName\s*=\s*)(["'])([\s\S]*?)\2/i;
  const nextOpenTag = nameExpression.test(openTag)
    ? openTag.replace(nameExpression, (_match, prefix, quote) => {
      const value = quote === "'" ? escapedName.replace(/'/g, "&apos;") : escapedName;
      return `${prefix}${quote}${value}${quote}`;
    })
    : openTag.replace(/>$/, ` Name="${escapedName}">`);
  return nextOpenTag === openTag ? block : nextOpenTag + block.slice(openTag.length);
}

function patchDateOffsetChildBlockLossless(parentBlock, tagName, values, requireAllParts, canonicalXml) {
  const childOrder = ["DefaultOffset", "CurrentOffset"];
  const range = findDirectChildElementRangeLossless(parentBlock, tagName);
  if (!range) {
    return insertDirectChildElementInOrderLossless(parentBlock, tagName, canonicalXml, childOrder);
  }

  let childBlock = parentBlock.slice(range.start, range.end);
  if (range.selfClosing) {
    childBlock = childBlock.replace(/\/\s*>$/, ">") + `</${tagName}>`;
  }

  const valueByTag = {
    Day: values.d,
    Month: values.m,
    Year: values.y
  };
  const partOrder = ["Day", "Month", "Year"];
  partOrder.forEach((partTag) => {
    const existingPart = findDirectChildElementRangeLossless(childBlock, partTag);
    // Keep the source representation of zero values when present; omit only absent optional zero parts.
    if (!requireAllParts && !existingPart && !valueByTag[partTag]) return;
    childBlock = setDirectChildElementTextLossless(
      childBlock,
      partTag,
      valueByTag[partTag],
      partOrder
    );
  });

  return parentBlock.slice(0, range.start) + childBlock + parentBlock.slice(range.end);
}

function findDirectChildElementRangeLossless(parentBlock, tagName) {
  const openEnd = String(parentBlock ?? "").indexOf(">");
  const closeStart = String(parentBlock ?? "").lastIndexOf("</");
  if (openEnd < 0 || closeStart <= openEnd) return null;

  const inner = parentBlock.slice(openEnd + 1, closeStart);
  const tokenExpression = /<!\[CDATA\[[\s\S]*?\]\]>|<!--[\s\S]*?-->|<\?[\s\S]*?\?>|<![^>]*>|<[^>]+>/g;
  let depth = 0;
  let target = null;
  let tokenMatch;

  while ((tokenMatch = tokenExpression.exec(inner))) {
    const token = tokenMatch[0];
    if (/^<\?|^<!/.test(token)) continue;

    const name = token.match(/^<\/?\s*([^\s/>]+)/)?.[1];
    if (!name) continue;
    const isClosing = /^<\//.test(token);
    const isSelfClosing = /\/\s*>$/.test(token);
    const tokenStart = openEnd + 1 + tokenMatch.index;
    const tokenEnd = openEnd + 1 + tokenExpression.lastIndex;

    if (isClosing) {
      if (target && depth === 1 && name === tagName) {
        return {
          start: target.start,
          openEnd: target.openEnd,
          closeStart: tokenStart,
          end: tokenEnd,
          selfClosing: false
        };
      }
      depth = Math.max(0, depth - 1);
      continue;
    }

    if (depth === 0 && name === tagName) {
      if (isSelfClosing) {
        return {
          start: tokenStart,
          openEnd: tokenEnd,
          closeStart: tokenEnd,
          end: tokenEnd,
          selfClosing: true
        };
      }
      target = { start: tokenStart, openEnd: tokenEnd };
    }
    if (!isSelfClosing) depth += 1;
  }

  return null;
}

function setDirectChildElementTextLossless(parentBlock, tagName, value, tagOrder) {
  const range = findDirectChildElementRangeLossless(parentBlock, tagName);
  const escapedValue = escapeHtml(value);
  if (range) {
    if (range.selfClosing) {
      if (Number(value) === 0) return parentBlock;
      const openTag = parentBlock.slice(range.start, range.end).replace(/\/\s*>$/, ">");
      const replacement = `${openTag}${escapedValue}</${tagName}>`;
      return parentBlock.slice(0, range.start) + replacement + parentBlock.slice(range.end);
    }
    if (hasEquivalentDateOffsetPartValue(parentBlock.slice(range.openEnd, range.closeStart), value)) {
      return parentBlock;
    }
    return parentBlock.slice(0, range.openEnd) + escapedValue + parentBlock.slice(range.closeStart);
  }

  return insertDirectChildElementInOrderLossless(
    parentBlock,
    tagName,
    `<${tagName}>${escapedValue}</${tagName}>`,
    tagOrder
  );
}

function setDataMatrixBcHInFieldBlockLossless(fieldBlock, bcH) {
  return setBarcodeDirectChildTextLossless(fieldBlock, "BcH", String(bcH));
}

function setBarcodeDirectChildTextLossless(fieldBlock, tagName, value) {
  const barcodeRange = findDirectChildElementRangeLossless(fieldBlock, "Barcode");
  if (!barcodeRange || barcodeRange.selfClosing) return fieldBlock;

  const barcodeBlock = fieldBlock.slice(barcodeRange.start, barcodeRange.end);
  const sourceValue = getDirectChildTagTextForValidation(barcodeBlock, tagName);
  if (sourceValue != null && String(sourceValue) === String(value)) {
    return fieldBlock;
  }
  const patchedBarcode = setDirectChildElementTextLossless(
    barcodeBlock,
    tagName,
    String(value),
    ["BcH", "HR", "QuietMargin", "DataMatrix"]
  );
  return fieldBlock.slice(0, barcodeRange.start) + patchedBarcode + fieldBlock.slice(barcodeRange.end);
}

function patchFirstDataObjectLossless(fieldBlock, patchObject) {
  const dataRange = findDirectChildElementRangeLossless(fieldBlock, "Data");
  if (!dataRange || dataRange.selfClosing) return fieldBlock;

  let dataBlock = fieldBlock.slice(dataRange.start, dataRange.end);
  const objectRange = findDirectChildElementRangeLossless(dataBlock, "Object");
  if (!objectRange || objectRange.selfClosing) return fieldBlock;

  const objectBlock = dataBlock.slice(objectRange.start, objectRange.end);
  const patchedObject = patchObject(objectBlock);
  if (patchedObject === objectBlock) return fieldBlock;

  dataBlock = dataBlock.slice(0, objectRange.start) + patchedObject + dataBlock.slice(objectRange.end);
  return fieldBlock.slice(0, dataRange.start) + dataBlock + fieldBlock.slice(dataRange.end);
}

const TEXT_DATA_OBJECT_CHILD_ORDER = [
  "DataType", "Locale", "Calendar", "Encryption", "MaxNoOfChars", "Default", "FixedLen",
  "PriceData", "Checksum", "SrcField", "SrcData", "VarText", "OffsetDate", "CounterText"
];

const CIFF_FIELD_CHILD_ORDER = [
  "FldType", "CLSID", "Displayed", "X", "Y", "W", "H", "Ln", "Orientation",
  "OverrideThis", "Inverse", "Mirror", "RenderMode", "CalcData", "LoggedField",
  "Origin", "MarkSet", "Data", "Clip", "Text", "Barcode", "Graphic"
];

function patchDirectChildBlockLossless(block, tag, patch) {
  const range = findDirectChildElementRangeLossless(block, tag);
  if (!range || range.selfClosing) return block;
  const child = block.slice(range.start, range.end);
  const next = patch(child);
  return next === child ? block : block.slice(0, range.start) + next + block.slice(range.end);
}

function readXmlScalarTextLossless(inner) {
  return (String(inner).match(/<!\[CDATA\[[\s\S]*?\]\]>|<!--[\s\S]*?-->|<[^>]+>|[^<]+/g) || [])
    .map(token => token.startsWith("<![CDATA[") ? token.slice(9, -3)
      : token.startsWith("<") ? "" : decodeXmlEntities(token))
    .join("").replace(/\r\n?/g, "\n");
}

function patchDirectChildScalarLossless(block, tag, value, options = {}) {
  if (value == null) return block;
  const range = findDirectChildElementRangeLossless(block, tag);
  const text = String(value);
  const encoded = options.cdata ? wrapCdata(text) : escapeHtml(text);
  if (!range) {
    return options.insert ? insertDirectChildElementInOrderLossless(
      block, tag, `<${tag}>${encoded}</${tag}>`, options.order || CIFF_FIELD_CHILD_ORDER
    ) : block;
  }
  const source = range.selfClosing ? "" : readXmlScalarTextLossless(block.slice(range.openEnd, range.closeStart));
  if (source === text.replace(/\r\n?/g, "\n") || (
    typeof value === "number" && source.trim() !== "" && Number(source) === value
  )) return block;
  if (range.selfClosing) {
    const open = block.slice(range.start, range.end).replace(/\/\s*>$/, ">");
    return block.slice(0, range.start) + `${open}${encoded}</${tag}>` + block.slice(range.end);
  }
  return block.slice(0, range.openEnd) + encoded + block.slice(range.closeStart);
}

const CIFF_TEXT_FONT_CHILD_ORDER = [
  "Face", "Family", "Pitch", "PitchResolution", "XMag", "YMag", "TTSize", "TxtDir", "CharSpace"
];
const CIFF_TEXT_STYLE_CHILD_ORDER = [
  "Font", "Bold", "Italic", "DblSpace", "Block", "Escapement", "FixedWidth", "MultiStroke"
];

function patchTextFontLossless(fieldBlock, text = {}) {
  const properties = [
    ["Face", "face"], ["Family", "family"], ["Pitch", "pitch"],
    ["PitchResolution", "pitchResolution"], ["XMag", "xMag"], ["YMag", "yMag"],
    ["TTSize", "ttSize"], ["TxtDir", "txtDir"], ["CharSpace", "charSpace"]
  ];
  const hasFontValues = properties.some(([, key]) => text[key] != null);
  const hasStyleValues = text.bold != null || text.italic != null;
  const textRange = findDirectChildElementRangeLossless(fieldBlock, "Text");
  if (!textRange && !hasFontValues && !hasStyleValues) return fieldBlock;

  let textBlock = textRange ? fieldBlock.slice(textRange.start, textRange.end) : "<Text/>";
  if (/\/\s*>$/.test(textBlock)) {
    if (!hasFontValues && !hasStyleValues) return fieldBlock;
    textBlock = textBlock.replace(/\/\s*>$/, "></Text>");
  }
  const fontRange = findDirectChildElementRangeLossless(textBlock, "Font");
  if (fontRange || hasFontValues) {
    let fontBlock = fontRange ? textBlock.slice(fontRange.start, fontRange.end) : "<Font/>";
    if (/\/\s*>$/.test(fontBlock) && hasFontValues) {
      fontBlock = fontBlock.replace(/\/\s*>$/, "></Font>");
    }
    for (const [tag, key] of properties) {
      fontBlock = patchDirectChildScalarLossless(fontBlock, tag, text[key], {
        cdata: tag === "Face", insert: true, order: CIFF_TEXT_FONT_CHILD_ORDER
      });
    }
    textBlock = fontRange
      ? textBlock.slice(0, fontRange.start) + fontBlock + textBlock.slice(fontRange.end)
      : insertDirectChildElementInOrderLossless(textBlock, "Font", fontBlock, CIFF_TEXT_STYLE_CHILD_ORDER);
  }
  for (const [tag, key] of [["Bold", "bold"], ["Italic", "italic"]]) {
    if (text[key] == null) continue;
    const value = typeof text[key] === "boolean" ? Number(text[key]) : text[key];
    textBlock = patchDirectChildScalarLossless(textBlock, tag, value, {
      insert: Number(value) !== 0, order: CIFF_TEXT_STYLE_CHILD_ORDER
    });
  }
  // Weight is an independent native property; retain it when changing typeface.
  if (text.boldWeight != null) {
    textBlock = patchDirectChildBlockLossless(textBlock, "Bold", (boldBlock) => {
      const open = boldBlock.match(/^<Bold\b[^>]*>/)?.[0];
      if (!open || getXmlAttributeValue(open, "Weight") === String(text.boldWeight)) return boldBlock;
      return setOrInsertXmlAttribute(open, "Weight", String(text.boldWeight)) + boldBlock.slice(open.length);
    });
  }
  return textRange
    ? fieldBlock.slice(0, textRange.start) + textBlock + fieldBlock.slice(textRange.end)
    : insertDirectChildElementInOrderLossless(fieldBlock, "Text", textBlock, CIFF_FIELD_CHILD_ORDER);
}

function patchOptionalObjectAttributesLossless(objectBlock, data) {
  const open = objectBlock.match(/^<Object\b[^>]*>/)?.[0];
  if (!open) return objectBlock;
  let next = open;
  for (const [name, property] of [["Static", "staticAttr"], ["Parse", "parseAttr"], ["Reference", "referenceAttr"]]) {
    const value = data[property];
    if (value === undefined || getXmlAttributeValue(next, name) === value) continue;
    next = value == null
      ? next.replace(new RegExp(`\\s${name}\\s*=\\s*(["'])[\\s\\S]*?\\1`), "")
      : setOrInsertXmlAttribute(next, name, String(value));
  }
  return next + objectBlock.slice(open.length);
}

function getCiffNativeObjectPropertyValue(key, value) {
  if (value == null) return null;
  const text = String(value);
  if (key === "locale" && text === "EN-GB") return null;
  if (key === "calendar" && (Number(value) === 1 || text === "CAL_GREGORIAN")) return null;
  if (key === "encryption" && text === "") return null;
  return text;
}

function buildCiffNativeObjectPropertiesXml(data) {
  return [["Locale", "locale"], ["Calendar", "calendar"], ["Encryption", "encryption"]]
    .map(([tag, key]) => {
      const value = getCiffNativeObjectPropertyValue(key, data?.[key]);
      return value == null ? "" : `<${tag}>${escapeHtml(value)}</${tag}>`;
    }).join("");
}

function patchCiffNativeObjectPropertiesLossless(objectBlock, data) {
  for (const [tag, key] of [["Locale", "locale"], ["Calendar", "calendar"], ["Encryption", "encryption"]]) {
    // undefined means an older/partial model that does not edit this property.
    if (data?.[key] === undefined) continue;
    const range = findDirectChildElementRangeLossless(objectBlock, tag);
    const source = range ? (range.selfClosing ? "" : readXmlScalarTextLossless(objectBlock.slice(range.openEnd, range.closeStart))) : null;
    if (source === (data[key] == null ? null : String(data[key]))) continue;
    const value = getCiffNativeObjectPropertyValue(key, data[key]);
    if (value == null) {
      if (range) objectBlock = objectBlock.slice(0, range.start) + objectBlock.slice(range.end);
    } else {
      objectBlock = patchDirectChildScalarLossless(objectBlock, tag, value, { insert: true, order: TEXT_DATA_OBJECT_CHILD_ORDER });
    }
  }
  return objectBlock;
}

function buildSourceDataXml(source) {
  if (!source) return "";
  return `<SrcData>` +
    (String(source.connStr ?? "") !== "" ? `<ConnStr>${wrapCdata(source.connStr)}</ConnStr>` : "") +
    `<SrcSQL>${wrapCdata(source.srcSQL ?? "")}</SrcSQL>` +
    `</SrcData>`;
}

function patchSourceDataLossless(objectBlock, source) {
  if (source === undefined) return objectBlock;
  const range = findDirectChildElementRangeLossless(objectBlock, "SrcData");
  if (source == null) return range
    ? objectBlock.slice(0, range.start) + objectBlock.slice(range.end) : objectBlock;
  if (!range) {
    const xml = buildSourceDataXml(source);
    return xml ? insertDirectChildElementInOrderLossless(objectBlock, "SrcData", xml, TEXT_DATA_OBJECT_CHILD_ORDER) : objectBlock;
  }
  let srcBlock = objectBlock.slice(range.start, range.end);
  const originalSourceBlock = srcBlock;
  if (range.selfClosing) {
    // The imported empty container is retained until an actual source edit.
    if (source.connStr == null && source.srcSQL == null) return objectBlock;
    srcBlock = srcBlock.replace(/\/\s*>$/, ">") + "</SrcData>";
  }
  for (const [tag, key] of [["ConnStr", "connStr"], ["SrcSQL", "srcSQL"]]) {
    const child = findDirectChildElementRangeLossless(srcBlock, tag);
    const sourceValue = child ? (child.selfClosing ? "" : readXmlScalarTextLossless(srcBlock.slice(child.openEnd, child.closeStart))) : null;
    if (source[key] === undefined || sourceValue === source[key]) continue;
    // Native SrcSQL is present even for an empty query; ConnStr is optional.
    const value = key === "srcSQL" ? String(source[key] ?? "") : source[key];
    if ((value == null || value === "") && key === "connStr") {
      if (child) srcBlock = srcBlock.slice(0, child.start) + srcBlock.slice(child.end);
    } else {
      srcBlock = patchDirectChildScalarLossless(srcBlock, tag, value, { cdata: true, insert: true, order: ["ConnStr", "SrcSQL"] });
    }
  }
  if (srcBlock !== originalSourceBlock && !findDirectChildElementRangeLossless(srcBlock, "SrcSQL")) {
    srcBlock = patchDirectChildScalarLossless(srcBlock, "SrcSQL", "", { cdata: true, insert: true, order: ["ConnStr", "SrcSQL"] });
  }
  return objectBlock.slice(0, range.start) + srcBlock + objectBlock.slice(range.end);
}

function patchOffsetDateReferenceLossless(block, field, sourceFldType) {
  return patchFirstDataObjectLossless(block, (objectBlock) => {
    const range = findDirectChildElementRangeLossless(objectBlock, "OffsetDate");
    const sourceReference = range ? getXmlAttributeValue(objectBlock.slice(range.start, range.openEnd), "SrcOffset") : null;
    if (field.fldType === "OffsetDateText" && field.data.offsetRef) {
      if (!range) return insertDirectChildElementInOrderLossless(
        objectBlock, "OffsetDate", `<OffsetDate SrcOffset="${escapeAttr(field.data.offsetRef)}"/>`, TEXT_DATA_OBJECT_CHILD_ORDER
      );
      const open = objectBlock.slice(range.start, range.openEnd);
      const next = getXmlAttributeValue(open, "SrcOffset") === field.data.offsetRef
        ? open : setOrInsertXmlAttribute(open, "SrcOffset", field.data.offsetRef);
      return objectBlock.slice(0, range.start) + next + objectBlock.slice(range.openEnd);
    }
    // A source extension is left alone unless the user changes its reference
    // or switches an offset date to a current date.
    if (range && (sourceFldType !== field.fldType || (sourceReference != null && field.data.offsetRef == null))) {
      return objectBlock.slice(0, range.start) + objectBlock.slice(range.end);
    }
    return objectBlock;
  });
}

function setMaxNoOfCharsInFirstDataObjectLossless(fieldBlock, maxChars) {
  return patchFirstDataObjectLossless(fieldBlock, (objectBlock) => {
    const range = findDirectChildElementRangeLossless(objectBlock, "MaxNoOfChars");
    const sourceText = range && !range.selfClosing
      ? decodeXmlTextForValidation(objectBlock.slice(range.openEnd, range.closeStart))
      : null;
    const sourceIsNumeric = hasNumericMaxNoOfChars(sourceText);

    if (!hasNumericMaxNoOfChars(maxChars)) {
      // Preserve malformed/unknown source content during a no-op parse. A valid
      // source value becoming null is an explicit removal from the editor.
      if (!range || !sourceIsNumeric) return objectBlock;
      return objectBlock.slice(0, range.start) + objectBlock.slice(range.end);
    }

    const normalized = String(Number(maxChars));
    if (range && sourceIsNumeric && Number(sourceText) === Number(maxChars)) return objectBlock;
    if (range) {
      if (range.selfClosing) {
        const openTag = objectBlock.slice(range.start, range.end).replace(/\/\s*>$/, ">");
        const replacement = `${openTag}${normalized}</MaxNoOfChars>`;
        return objectBlock.slice(0, range.start) + replacement + objectBlock.slice(range.end);
      }
      return objectBlock.slice(0, range.openEnd) + normalized + objectBlock.slice(range.closeStart);
    }
    return insertDirectChildElementInOrderLossless(
      objectBlock,
      "MaxNoOfChars",
      `<MaxNoOfChars>${normalized}</MaxNoOfChars>`,
      TEXT_DATA_OBJECT_CHILD_ORDER
    );
  });
}

function setFixedLenInFirstDataObjectLossless(fieldBlock, wantFixedLen) {
  return patchFirstDataObjectLossless(fieldBlock, (objectBlock) => {
    const range = findDirectChildElementRangeLossless(objectBlock, "FixedLen");
    if (wantFixedLen) {
      if (range) return objectBlock;
      return insertDirectChildElementInOrderLossless(
        objectBlock,
        "FixedLen",
        "<FixedLen/>",
        TEXT_DATA_OBJECT_CHILD_ORDER
      );
    }
    return range
      ? objectBlock.slice(0, range.start) + objectBlock.slice(range.end)
      : objectBlock;
  });
}

function hasNumericMaxNoOfChars(value) {
  if (value == null || String(value).trim() === "") return false;
  const numericValue = Number(value);
  return Number.isSafeInteger(numericValue) && numericValue >= 0;
}

function resolveDataMatrixBcHForSave(field, now = new Date(), moduleSize = null) {
  const rawBcH = field?.barcode?.bcH;
  if (rawBcH != null) {
    const storedBcH = Number(rawBcH);
    if (String(rawBcH).trim() !== "" && Number.isFinite(storedBcH)) {
      return Math.round(storedBcH);
    }
    throw new Error(`DataMatrix "${field?.name ?? ""}" has an invalid BcH value.`);
  }

  const calculatedBcH = calculateDataMatrixBcH(field, moduleSize, now);
  if (calculatedBcH != null) {
    field.barcode.bcH = calculatedBcH;
    return calculatedBcH;
  }
  throw new Error(`DataMatrix "${field?.name ?? ""}" requires a calculable BcH value.`);
}

function hasEquivalentDataMatrixModuleSize(fieldBlock, moduleSize) {
  const dataMatrix = extractBlock(fieldBlock, "<DataMatrix", "</DataMatrix>");
  if (!dataMatrix) return false;
  const sourceValue = getFirstTagTextForValidation(dataMatrix.block, "ModuleSize");
  const sourceModuleSize = parseDataMatrixModuleSizeValue(sourceValue, null);
  const modelModuleSize = parseDataMatrixModuleSizeValue(moduleSize, null);
  return (
    sourceValue != null && sourceModuleSize != null && modelModuleSize != null &&
    Math.abs(sourceModuleSize - modelModuleSize) < 1e-9
  );
}

function hasEquivalentDataMatrixSymbolSize(fieldBlock, symbolSize) {
  const dataMatrix = extractBlock(fieldBlock, "<DataMatrix", "</DataMatrix>");
  if (!dataMatrix) return false;
  const sourceValue = getFirstTagTextForValidation(dataMatrix.block, "SymbolSize");
  if (sourceValue == null) return false;
  return normalizeDataMatrixSymbolSizeValue(sourceValue, "22X22") ===
    normalizeDataMatrixSymbolSizeValue(symbolSize, "22X22");
}

function hasEquivalentDateOffsetPartValue(xmlText, value) {
  const trimmed = String(xmlText ?? "").trim();
  const decoded = decodeXmlTextForValidation(trimmed).trim();
  return /^[+-]?\d+$/.test(decoded) && Number(decoded) === Number(value);
}

function insertDirectChildElementInOrderLossless(parentBlock, tagName, xml, tagOrder) {
  const closeStart = parentBlock.lastIndexOf("</");
  if (closeStart < 0) throw new Error(`Invalid parent block while writing ${tagName}.`);

  const currentIndex = tagOrder.indexOf(tagName);
  let insertAt = closeStart;
  for (const nextTag of tagOrder.slice(currentIndex + 1)) {
    const nextRange = findDirectChildElementRangeLossless(parentBlock, nextTag);
    if (nextRange) {
      insertAt = nextRange.start;
      break;
    }
  }
  return parentBlock.slice(0, insertAt) + xml + parentBlock.slice(insertAt);
}

function buildDateOffsetXml(o) {
  const defaultOffset = normalizeDateOffsetDeltaForSave(o?.default);
  const current = normalizeCalendarDatePartsForSave(o?.current);
  if (!isValidCalendarDateParts(current)) {
    throw new Error(`DateOffset "${String(o?.name ?? "")}" has an invalid CurrentOffset.`);
  }

  return `<DateOffset Name="${escapeAttr(o.name)}">${buildDefaultOffsetXml(defaultOffset)}${buildCurrentOffsetXml(current)}</DateOffset>`;
}

function buildDefaultOffsetXml(defaultOffset) {
  return `<DefaultOffset>` +
    (defaultOffset.d ? `<Day>${defaultOffset.d}</Day>` : ``) +
    (defaultOffset.m ? `<Month>${defaultOffset.m}</Month>` : ``) +
    (defaultOffset.y ? `<Year>${defaultOffset.y}</Year>` : ``) +
    `</DefaultOffset>`;
}

function buildCurrentOffsetXml(current) {
  return `<CurrentOffset><Day>${current.d}</Day><Month>${current.m}</Month><Year>${current.y}</Year></CurrentOffset>`;
}

/* ---- Fields patch (delete + upsert + insert) ---- */
function patchFieldsLosslessV2(line2, now = new Date(), calculatedData = null) {
  const sub = extractBlock(line2, "<SubImage", "</SubImage>");
  if (!sub) throw new Error("SubImage not found");

  const bySourceName = new Map(state.fields.filter(f => f.sourceName != null).map(f => [f.sourceName, f]));
  const patchedFields = new Set();
  let s = "";
  let cursor = 0;
  // Walk immutable source ranges in XML order. Renames cannot shadow another
  // field, and unknown siblings stay exactly where they were loaded.
  for (const range of listDirectChildElementRangesLossless(sub.block, "Field")) {
    s += sub.block.slice(cursor, range.start);
    const block = sub.block.slice(range.start, range.end);
    const sourceName = getXmlAttributeValue(block.match(/^<Field\b[^>]*>/)?.[0], "Name");
    const field = bySourceName.get(sourceName);
    if (field) {
      s += patchExistingFieldBlockNonInvasive(block, field, now, calculatedData);
      patchedFields.add(field);
    }
    cursor = range.end;
  }
  s += sub.block.slice(cursor);
  // New fields follow their creation/insertion order, independently of names.
  for (const field of state.fields) {
    if (!patchedFields.has(field)) s = insertBeforeClosingTag(s, "</SubImage>", buildFieldXmlOneLine(field, now, calculatedData));
  }

  return line2.slice(0, sub.start) + s + line2.slice(sub.end);
}

function updateExistingFieldBlockNonInvasive(subImageBlock, f, lookupName = f.sourceName || f.name, now = new Date()) {
  const found = extractFieldBlockInSubImage(subImageBlock, lookupName);
  if (!found) return subImageBlock;

  const block = patchExistingFieldBlockNonInvasive(found.block, f, now);
  return subImageBlock.slice(0, found.start) + block + subImageBlock.slice(found.end);
}

function patchExistingFieldBlockNonInvasive(block, f, now = new Date(), calculatedData = null) {
  const sourceFldType = getDirectChildTagTextForValidation(block, "FldType");

  // Only direct Field children belong to field geometry; extensions may have
  // their own X, W, Default, etc. Preserve unchanged source spelling.
  block = replaceFieldNameAttr(block, f.name);
  block = patchDirectChildScalarLossless(block, "FldType", f.fldType);
  for (const [tag, key] of [["X", "x"], ["Y", "y"], ["W", "w"], ["H", "h"]]) {
    block = patchDirectChildScalarLossless(block, tag, f.geom[key]);
  }
  if (f.ln != null) block = patchDirectChildScalarLossless(block, "Ln", f.ln, { insert: true });
  block = setOrRemoveOrientation(block, normalizeOrientation(f.orientation));

  // Displayed: we allow structural add/remove (Clarisoft expects this)
  block = setOrRemoveDisplayed(block, !f.printed);

  const rawCalculatedData = getCiffPreparedCalculatedData(f, calculatedData) ?? f.calcData ?? "";
  const xmlCalculatedData = filterCiffCalculatedDataForXml(rawCalculatedData);
  block = patchDirectChildScalarLossless(block, "CalcData", xmlCalculatedData, { cdata: true, insert: !!xmlCalculatedData });
  if (f.loggedField !== undefined) {
    const logged = findDirectChildElementRangeLossless(block, "LoggedField");
    if (f.loggedField === "Not Logged") {
      if (logged) block = block.slice(0, logged.start) + block.slice(logged.end);
    } else {
      block = patchDirectChildScalarLossless(block, "LoggedField", f.loggedField ?? "", { insert: true });
    }
  }

  const isDM = f.fldType === "Barcode" && f.barcode?.dataMatrix;

  if (isDM) {
    const effectiveModuleSize = getDataMatrixEffectiveModuleSize(f, null, now);
    const bcH = resolveDataMatrixBcHForSave(f, now, effectiveModuleSize);
    block = setDataMatrixBcHInFieldBlockLossless(block, bcH);

    // Preserve an absent optional tag until the user supplies a value. Once
    // supplied, upsert it in ClariSoft child order.
    if (f.barcode.quietMargin != null) {
      block = setBarcodeDirectChildTextLossless(block, "QuietMargin", String(f.barcode.quietMargin));
    }

    // Preserve the source spelling during a no-op round-trip. Explicit model
    // changes still patch the existing DataMatrix values canonically.
    if (!hasEquivalentDataMatrixModuleSize(block, effectiveModuleSize)) {
      block = replaceTagTextWithinIfExists(block, "DataMatrix", "ModuleSize", serializeDataMatrixModuleSize(effectiveModuleSize));
    }
    if (!hasEquivalentDataMatrixSymbolSize(block, f.barcode.dataMatrix.symbolSize)) {
      block = replaceTagTextWithinIfExists(block, "DataMatrix", "SymbolSize", normalizeDataMatrixSymbolSizeValue(f.barcode.dataMatrix.symbolSize, "22X22"));
    }

    // Preserve imported Object attributes/children until the user explicitly
    // changes the segment structure. Value-only source updates are patched in place.
    block = f.barcode.dataMatrix.structureDirty
      ? rebuildDataObjectsForDataMatrix(block, f.barcode.dataMatrix.segments)
      : patchDataMatrixObjectsNonInvasive(block, f.barcode.dataMatrix.segments);

    // Field patching never touches Header/ClStVersionInfo; Header resolution is centralized above.

  } else {
    if (f.fldType === "CounterText") normalizeCounterField(f, { preserveCurrent: true });

    block = patchFirstDataObjectLossless(block, (objectBlock) => {
      objectBlock = patchDirectChildScalarLossless(objectBlock, "DataType", f.data.dataType);
      objectBlock = patchDirectChildScalarLossless(objectBlock, "Default", f.data.defaultValue ?? "", { cdata: true });
      objectBlock = patchOptionalObjectAttributesLossless(objectBlock, f.data);
      objectBlock = patchCiffNativeObjectPropertiesLossless(objectBlock, f.data);
      return patchSourceDataLossless(objectBlock, f.data.srcData);
    });

    if (f.fldType === "FixedText") {
      block = syncTextEntryModeStructure(block, f);
    }

    // UserEnterData/Mask: patch after structure sync.
    block = patchVarTextOnlyIfExists(block, f);

    // MaxNoOfChars and FixedLen are independent in ClariSoft output. Patch the
    // edited model values while preserving unchanged source spelling/presence.
    block = setMaxNoOfCharsInFirstDataObjectLossless(block, f.data.maxChars);
    block = setFixedLenInFirstDataObjectLossless(block, f.data.fixedLen === true);

    if (f.fldType === "CounterText") {
      block = patchFirstDataObjectLossless(block, objectBlock => (
        patchDirectChildBlockLossless(objectBlock, "CounterText", counterBlock => (
          patchDirectChildBlockLossless(counterBlock, "SubCnt", subCount => {
            const counter = f.data.counter || {};
            for (const [tag, key, cdata] of [
              ["NoOfChars", "noOfChars", false], ["StartVal", "startVal", true],
              ["EndVal", "endVal", true], ["StepSize", "stepSize", false], ["ClrStCntType", "clrStCntType", false]
            ]) subCount = patchDirectChildScalarLossless(subCount, tag, counter[key], { cdata });
            return replaceAttrIfExists(subCount, "SubCnt", "Significance", String(counter.significance ?? 0));
          })
        ))
      ));
    }

    // OffsetDate: keep structure in sync when switching Current Date <-> Calculated Date
    block = patchOffsetDateReferenceLossless(block, f, sourceFldType);

    block = patchTextFontLossless(block, f.text);
  }

  return block;
}

// Rules for newly created text data. Imported XML uses the conservative patch
// path above, so optional source properties are never replaced by defaults.
function getCiffTextSerializationRules(field) {
  const data = field.data;
  const dataType = data.dataType ?? guessDataType(field.fldType);
  return {
    dataType,
    staticAttr: data.staticAttr,
    parseAttr: data.parseAttr,
    referenceAttr: data.referenceAttr === undefined ? "" : data.referenceAttr,
    includeFixedLen: data.fixedLen === true,
    includeVarText: wantsVarTextStructure(field),
    includeSrcData: field.fldType === "FixedText" && Number(dataType) === 6 && data.srcData != null,
    includeOffsetDate: field.fldType === "OffsetDateText" && Number(dataType) === 3 && !!data.offsetRef,
    includeCounter: field.fldType === "CounterText"
  };
}

/* ---- Build NEW field XML (Clarisoft-compatible child order) ---- */
function buildCiffSrcFieldXml(data) {
  if (!data?.srcField) return "";
  const children = [["StartChar", data.startChar], ["NoOfChars", data.noOfChars], ["SelectMode", data.selectMode]]
    .filter(([, value]) => value != null && Number(value) !== 0)
    .map(([tag, value]) => `<${tag}>${escapeAttr(String(value))}</${tag}>`).join("");
  const open = `<SrcField SrcFieldName="${escapeAttr(data.srcField)}"`;
  return children ? `${open}>${children}</SrcField>` : `${open}/>`;
}

function buildCiffFixedLenXml(data) {
  const character = data?.padChar == null ? null : typeof data.padChar === "number"
    ? String.fromCharCode(data.padChar & 0xFFFF) : String(data.padChar);
  const padChar = character == null || character === " " ? "" : `<PadChar>${wrapCdata(character)}</PadChar>`;
  const mode = data?.padMode;
  const padMode = mode == null || Number(mode) === 0 || mode === "Left" ? ""
    : `<PadMode>${escapeAttr(String(Number(mode) === 1 ? "Right" : mode))}</PadMode>`;
  const children = padChar + padMode;
  return children ? `<FixedLen>${children}</FixedLen>` : "<FixedLen/>";
}

function buildCiffObjectAttributesXml(data = {}, index = 0) {
  const reference = data.referenceAttr === undefined ? "" : data.referenceAttr;
  return (index !== 0 ? ` Index="${escapeAttr(String(index))}"` : "") +
    (data.staticAttr != null && Number(data.staticAttr) !== 1 ? ` Static="${escapeAttr(String(data.staticAttr))}"` : "") +
    (data.parseAttr != null && Number(data.parseAttr) !== 0 ? ` Parse="${escapeAttr(String(data.parseAttr))}"` : "") +
    (reference != null ? ` Reference="${escapeAttr(String(reference))}"` : "");
}

function buildCiffDefaultXml(value) {
  return String(value ?? "") !== "" ? `<Default>${wrapCdata(value)}</Default>` : "";
}

function buildCiffVarTextXml(data = {}) {
  const mask = String(data.mask ?? "") !== "" ? `<Mask>${wrapCdata(data.mask)}</Mask>` : "";
  const value = data.userEnterData ?? data.defaultValue ?? "";
  const userEnterData = String(value) !== "" ? `<UserEnterData>${wrapCdata(value)}</UserEnterData>` : "";
  return mask || userEnterData ? `<VarText>${mask}${userEnterData}</VarText>` : "<VarText/>";
}

function buildCiffCounterXml(data = {}) {
  const counter = data.counter || {};
  const chars = counter.noOfChars ?? 4;
  const start = counter.startVal ?? "1";
  const end = counter.endVal ?? String(getCounterMaxValue(chars));
  const step = counter.stepSize ?? 1;
  return `<CounterText><SubCnt Significance="${escapeAttr(String(counter.significance ?? 0))}">` +
    `<NoOfChars>${escapeHtml(String(chars))}</NoOfChars>` +
    (String(start) !== "0" ? `<StartVal>${wrapCdata(start)}</StartVal>` : "") +
    (String(end) !== "9999" ? `<EndVal>${wrapCdata(end)}</EndVal>` : "") +
    (Number(step) !== 1 ? `<StepSize>${escapeHtml(String(step))}</StepSize>` : "") +
    `<ClrStCntType>${escapeHtml(String(counter.clrStCntType ?? ""))}</ClrStCntType></SubCnt></CounterText>`;
}

function buildCiffDataMatrixObjectXml(segment, index) {
  const max = segment.maxChars != null && Number(segment.maxChars) !== 0
    ? `<MaxNoOfChars>${escapeHtml(String(segment.maxChars))}</MaxNoOfChars>` : "";
  return `<Object${buildCiffObjectAttributesXml(segment, index)}><DataType>${segment.dataType ?? 5}</DataType>` +
    buildCiffNativeObjectPropertiesXml(segment) + max + buildCiffDefaultXml(segment.defaultValue) +
    (segment.fixedLen === true ? buildCiffFixedLenXml(segment) : "") +
    buildCiffSrcFieldXml(segment) +
    (segment.srcData ? buildSourceDataXml(segment.srcData) : "") +
    (segment.hasVarText ? buildCiffVarTextXml(segment) : "") +
    (segment.offsetRef ? `<OffsetDate SrcOffset="${escapeAttr(segment.offsetRef)}"/>` : "") +
    `</Object>`;
}

function getCiffNewTextProperties(field) {
  const text = { ...(field.text || {}), pitch: getEffectiveTextPitch(field, 10) };
  const defaults = { face: "Arial", family: 32, pitch: 13, pitchResolution: 1, xMag: 100, yMag: 100, ttSize: 1, txtDir: 0, charSpace: 0 };
  for (const [key, value] of Object.entries(defaults)) {
    if (text[key] == null) continue;
    if (typeof value === "number" ? Number(text[key]) === value : text[key] === value) delete text[key];
  }
  if (text.family === "Swiss") delete text.family;
  if (text.txtDir === "LeftToRight") delete text.txtDir;
  return text;
}

function buildFieldXmlOneLine(f, now = new Date(), calculatedData = null) {
  if (f.fldType === "CounterText") normalizeCounterField(f, { preserveCurrent: true });
  const name = escapeAttr(f.name);
  const open = `<Field Name="${name}"><FldType>${f.fldType}</FldType>`;
  const displayed = f.printed ? `` : `<Displayed>0</Displayed>`;
  const geometry =
    `<X>${f.geom.x}</X><Y>${f.geom.y}</Y><W>${f.geom.w}</W><H>${f.geom.h}</H>` +
    (f.ln != null && Number(f.ln) !== 0 ? `<Ln>${f.ln}</Ln>` : ``) +
    (normalizeOrientation(f.orientation) ? `<Orientation>${normalizeOrientation(f.orientation)}</Orientation>` : ``);
  const calculatedValue = filterCiffCalculatedDataForXml(getCiffPreparedCalculatedData(f, calculatedData) ?? f.calcData ?? "");
  const calcData = calculatedValue ? `<CalcData>${wrapCdata(calculatedValue)}</CalcData>` : "";
  // Native default is "Not Logged". An explicitly requested empty state is
  // different and must still be represented by an empty element.
  const logged = f.loggedField === undefined || f.loggedField === "Not Logged" ? ""
    : `<LoggedField>${escapeHtml(String(f.loggedField ?? ""))}</LoggedField>`;

  if (f.fldType === "Barcode" && f.barcode?.dataMatrix) {
    const effectiveModuleSize = getDataMatrixEffectiveModuleSize(f, null, now);
    const bcH = resolveDataMatrixBcHForSave(f, now, effectiveModuleSize);
    const dataObjects = f.barcode.dataMatrix.segments.map(buildCiffDataMatrixObjectXml).join("");
    const quiet = f.barcode.quietMargin ?? 0;
    const moduleSize = serializeDataMatrixModuleSize(effectiveModuleSize);
    const symbolSize = normalizeDataMatrixSymbolSizeValue(f.barcode.dataMatrix.symbolSize, "22X22");

    const barcode =
      open +
      `<CLSID>${f.barcode.clsid ?? "{7A4AA4CF-F5CD-11D4-8DAE-0050DAFE8A9F}"}</CLSID>` +
      displayed + geometry + calcData +
      logged +
      `<Data>${dataObjects}</Data>` +
      `<Barcode><BcH>${bcH}</BcH><HR><HRFont/></HR>` +
      (Number(quiet) !== 1 ? `<QuietMargin>${quiet}</QuietMargin>` : "") +
      `<DataMatrix>` + (Number(moduleSize) !== 100 ? `<ModuleSize>${moduleSize}</ModuleSize>` : "") +
      (symbolSize !== "Auto" ? `<SymbolSize>${symbolSize}</SymbolSize>` : "") + `</DataMatrix>` +
      `</Barcode>`;

    return barcode + `</Field>`;
  }

  const base = open + displayed + geometry + calcData;

  const rules = getCiffTextSerializationRules(f);
  const attrs = buildCiffObjectAttributesXml(rules);

  // The serializer is generic: recipe factories may populate MaxNoOfChars,
  // but a field name such as "GTIN" must not silently activate a profile.
  const maxChars = f.data.maxChars;
  const max = maxChars != null && Number(maxChars) !== 0 ? `<MaxNoOfChars>${maxChars}</MaxNoOfChars>` : ``;
  const fixedLen = rules.includeFixedLen ? buildCiffFixedLenXml(f.data) : ``;

  const wantVarText = rules.includeVarText;
  const varText = wantVarText ? buildCiffVarTextXml(f.data) : ``;

  const offsetDate = rules.includeOffsetDate
    ? `<OffsetDate SrcOffset="${escapeAttr(f.data.offsetRef)}"/>`
    : ``;
  const srcData = rules.includeSrcData ? buildSourceDataXml(f.data.srcData) : ``;

  const counter = rules.includeCounter ? buildCiffCounterXml(f.data) : ``;

  const data =
    logged +
    `<Data><Object${attrs}><DataType>${rules.dataType}</DataType>` +
      buildCiffNativeObjectPropertiesXml(f.data) +
      `${max}${buildCiffDefaultXml(f.data.defaultValue)}${fixedLen}${varText}${srcData}${buildCiffSrcFieldXml(f.data)}${offsetDate}${counter}` +
    `</Object></Data>`;

  const text = patchTextFontLossless("<Field><Text><Font/></Text></Field>", getCiffNewTextProperties(f))
    .replace(/^<Field>|<\/Field>$/g, "");

  return base + data + text + `</Field>`;
}

/* ---- Pre-save CIFF compatibility validation ---- */
function validateCiffCompatibility(patched, options = {}) {
  const now = getFrozenSaveDate(options.now);
  const line1 = String(patched?.line1 ?? "");
  const line2 = String(patched?.line2 ?? "");
  const structuralErrors = [];

  if (!/^<\?xml\b[^?]*\bencoding\s*=\s*(["'])UTF-16\1[^?]*\?>$/i.test(line1)) {
    addUniqueValidationError(structuralErrors, 'XML declaration must specify encoding="UTF-16".');
  }
  if (/[\r\n]/.test(line1)) {
    addUniqueValidationError(structuralErrors, "CIFF XML declaration must occupy a single line.");
  }

  const parseError = getCiffXmlParseError(line1, line2);
  if (parseError) addUniqueValidationError(structuralErrors, `Generated XML is not well formed: ${parseError}`);

  const rootOpen = line2.match(/^\s*<ImageDesign\b[^>]*>/)?.[0] ?? null;
  if (!rootOpen || !/<\/ImageDesign>\s*$/.test(line2)) {
    addUniqueValidationError(structuralErrors, "ImageDesign root is missing.");
  } else if (!String(getXmlAttributeValue(rootOpen, "Version") ?? "").trim()) {
    addUniqueValidationError(structuralErrors, "ImageDesign Version is missing.");
  }

  const header = extractImageDesignDirectChildBlock(line2, "Header");
  if (!header) {
    addUniqueValidationError(structuralErrors, "Header is missing.");
  } else {
    const headerOpen = header.block.match(/^<Header\b[^>]*>/)?.[0];
    const designedFor = String(getXmlAttributeValue(headerOpen, "DesignedFor") ?? "").trim();
    if (!designedFor) {
      addUniqueValidationError(structuralErrors, "Header DesignedFor is missing.");
    }
    const unitsText = getDirectChildTagTextForValidation(header.block, "Units");
    const units = typeof parseCiffMeasurementUnits === "function"
      ? parseCiffMeasurementUnits(unitsText)
      : (unitsText == null || String(unitsText).trim() === "" || ["0", "hmm"].includes(String(unitsText).trim().toLowerCase()) ? 0 : null);
    if (units !== 0 || (state.docMeta?.units != null && state.docMeta.units !== 0)) {
      addUniqueValidationError(structuralErrors, "Only CIFF hundredths-of-millimetre coordinates (Units=0) are supported.");
    }
    {
      const clStRanges = listDirectChildElementRangesLossless(header.block, "ClStVersionInfo");
      if (clStRanges.length !== 1 || !isUsableClStVersionInfo(readClStVersionInfoFromHeaderBlock(header.block))) {
        addUniqueValidationError(structuralErrors, "Header ClStVersionInfo is missing or invalid.");
      }
    }
  }

  const subImage = extractBlock(line2, "<SubImage", "</SubImage>");
  let imageReference = "";
  let dimensions = null;
  if (!subImage) {
    addUniqueValidationError(structuralErrors, "SubImage is missing.");
  } else {
    const subImageOpen = subImage.block.match(/^<SubImage\b[^>]*>/)?.[0];
    imageReference = String(getXmlAttributeValue(subImageOpen, "ImageReference") ?? "").trim();
    const subHeader = extractBlock(subImage.block, "<SubHeader", "</SubHeader>");
    if (!subHeader) {
      addUniqueValidationError(structuralErrors, "SubHeader is missing.");
    } else {
      dimensions = validateSubHeaderCompatibility(subHeader.block, structuralErrors);
    }
  }

  validateImageMappingCompatibility(line2, imageReference, structuralErrors);
  validateDateOffsetCompatibility(line2, structuralErrors);
  validateDataMatrixSourceConsistency(line2, structuralErrors, { now, calculatedData: options.calculatedData });
  if (typeof getTemplateHardwareLimitValidationErrors === "function") {
    getTemplateHardwareLimitValidationErrors().forEach((error) => {
      addUniqueValidationError(structuralErrors, error);
    });
  }

  const printableResult = typeof validatePrintableFieldsInsideArea === "function"
    ? validatePrintableFieldsInsideArea(now, { forceFresh: true })
    : null;
  const invalidPrintableFieldNames = readValidationNames(
    printableResult,
    "invalidPrintableFieldNames"
  );

  const hardwareResult = typeof validateHardwareFieldsInsideArea === "function"
    ? validateHardwareFieldsInsideArea(now, { forceFresh: true })
    : null;
  const invalidHardwareFieldNames = readValidationNames(
    hardwareResult,
    "invalidHardwareFieldNames"
  );
  if (typeof validateHardwareFieldsInsideArea !== "function") {
    addUniqueValidationError(structuralErrors, "Hardware bounds validation is unavailable.");
  }

  const validation = {
    invalidPrintableFieldNames,
    invalidHardwareFieldNames,
    structuralErrors,
    ok: !invalidPrintableFieldNames.length && !invalidHardwareFieldNames.length && !structuralErrors.length
  };
  state.validation = {
    ...(state.validation || {}),
    invalidPrintableFieldNames,
    invalidHardwareFieldNames,
    structuralErrors
  };
  return validation;
}

function validateSubHeaderCompatibility(block, errors) {
  const names = {
    width: "ImageWidth",
    height: "ImageHeight",
    maxWidth: "MaxImageWidth",
    maxHeight: "MaxImageHeight"
  };
  const result = {};
  for (const [key, tag] of Object.entries(names)) {
    const raw = getDirectChildTagTextForValidation(block, tag);
    const value = parseStrictInteger(raw);
    if (!Number.isInteger(value) || value < 0) {
      addUniqueValidationError(errors, `${tag} must be a non-negative integer.`);
    }
    result[key] = value;
  }

  const xResRaw = getDirectChildTagTextForValidation(block, "XRes");
  result.xRes = parseStrictNumber(xResRaw);
  if (!Number.isFinite(result.xRes) || result.xRes <= 0) {
    addUniqueValidationError(errors, "XRes must be a positive number.");
  }
  const yResRaw = getDirectChildTagTextForValidation(block, "YRes");
  result.yRes = yResRaw == null ? result.xRes : parseStrictNumber(yResRaw);
  if (!Number.isFinite(result.yRes) || result.yRes <= 0) {
    addUniqueValidationError(errors, "YRes must be a positive number when supplied.");
  }

  const orientationRaw = getDirectChildTagTextForValidation(block, "CurrentOrientation");
  result.orientation = parseStrictInteger(orientationRaw);
  const allowedOrientations = typeof ALLOWED_ORIENTATIONS !== "undefined"
    ? ALLOWED_ORIENTATIONS
    : [0, 90, 180, 270];
  if (!allowedOrientations.includes(result.orientation)) {
    addUniqueValidationError(errors, "CurrentOrientation is invalid.");
  }

  // Do not infer a containment rule from MaxImage*. The oracle corpus contains
  // printer-accepted ClariSoft files whose ImageWidth exceeds MaxImageWidth.
  // Physical bounds are checked separately against the selected hardware head.
  return result;
}

function validateImageMappingCompatibility(line2, imageReference, errors) {
  const genericSettings = extractBlock(line2, "<GenericSettings", "</GenericSettings>");
  const imageMapping = genericSettings
    ? extractBlock(genericSettings.block, "<ImageMapping", "</ImageMapping>")
    : null;
  if (!imageMapping || !imageReference) return;

  const mapBlocks = imageMapping.block.match(/<Map\b[^>]*>[\s\S]*?<\/Map>/g) || [];
  const hasMatchingMap = mapBlocks.some((mapBlock) => {
    const open = mapBlock.match(/^<Map\b[^>]*>/)?.[0];
    const attributeReference = String(getXmlAttributeValue(open, "SubIMageRef") ?? "").trim();
    const valueReference = decodeXmlEntities(mapBlock.replace(/^<Map\b[^>]*>|<\/Map>$/g, "").trim());
    return !!imageReference && attributeReference === imageReference && valueReference === imageReference;
  });
  if (!hasMatchingMap) {
    addUniqueValidationError(errors, "ImageMapping does not reference the active SubImage.");
  }
}

function validateDateOffsetCompatibility(line2, errors) {
  const names = new Set();
  const directBlocks = (block, tag) => listDirectChildElementRangesLossless(block, tag)
    .map((range) => block.slice(range.start, range.end));
  const header = extractImageDesignDirectChildBlock(line2, "Header");
  const blocks = directBlocks(header?.block ?? "", "DateOffset");

  blocks.forEach((block) => {
    const open = block.match(/^<DateOffset\b[^>]*>/)?.[0];
    const name = String(getXmlAttributeValue(open, "Name") ?? "").trim();
    if (!name) {
      addUniqueValidationError(errors, "DateOffset Name is missing.");
    } else if (names.has(name)) {
      addUniqueValidationError(errors, `Duplicate DateOffset Name: ${name}.`);
    } else {
      names.add(name);
    }

    const defaultOffset = directBlocks(block, "DefaultOffset")[0];
    if (!defaultOffset) {
      addUniqueValidationError(errors, `DateOffset "${name || "?"}" has no DefaultOffset.`);
    } else {
      for (const tag of ["Year", "Month", "Day"]) {
        const raw = getDirectChildTagTextForValidation(defaultOffset, tag);
        if (raw != null && !Number.isInteger(parseStrictInteger(raw))) {
          addUniqueValidationError(errors, `DateOffset "${name || "?"}" has an invalid DefaultOffset ${tag}.`);
        }
      }
    }

    const currentOffset = directBlocks(block, "CurrentOffset")[0];
    if (!currentOffset) {
      addUniqueValidationError(errors, `DateOffset "${name || "?"}" has no CurrentOffset.`);
      return;
    }
    const current = {
      y: parseStrictInteger(getDirectChildTagTextForValidation(currentOffset, "Year")),
      m: parseStrictInteger(getDirectChildTagTextForValidation(currentOffset, "Month")),
      d: parseStrictInteger(getDirectChildTagTextForValidation(currentOffset, "Day"))
    };
    if (!isValidCalendarDateParts(current)) {
      addUniqueValidationError(errors, `DateOffset "${name || "?"}" has an invalid CurrentOffset calendar date.`);
    }
  });

  // References are configuration only at Field/Data/Object/OffsetDate. Tag-like
  // SQL text or extension metadata must neither create nor resolve a reference.
  const imageDesign = extractBlock(line2, "<ImageDesign", "</ImageDesign>");
  const offsetDateTags = directBlocks(imageDesign?.block ?? "", "SubImage")
    .flatMap((block) => directBlocks(block, "Field"))
    .flatMap((block) => directBlocks(block, "Data"))
    .flatMap((block) => directBlocks(block, "Object"))
    .flatMap((block) => directBlocks(block, "OffsetDate"))
    .map((block) => block.match(/^<OffsetDate\b[^>]*>/)?.[0] ?? "");
  offsetDateTags.forEach((tag) => {
    const reference = String(getXmlAttributeValue(tag, "SrcOffset") ?? "").trim();
    if (!reference || !names.has(reference)) {
      addUniqueValidationError(errors, `Missing DateOffset target: ${reference || "(empty)"}.`);
    }
  });
}

function validateDataMatrixSourceReferences(line2, errors, options = {}) {
  validateDataMatrixSourceConsistency(line2, errors, options);
}

function validateDataMatrixSourceConsistency(line2, errors, options = {}) {
  const fieldNames = new Set();
  const subImageBlock = extractBlock(line2, "<SubImage", "</SubImage>")?.block || "";
  const fieldBlocks = listDirectChildElementRangesLossless(subImageBlock, "Field")
    .map((range) => subImageBlock.slice(range.start, range.end));
  const fieldsByName = new Map();
  fieldBlocks.forEach((block) => {
    const openTag = block.match(/^<Field\b[^>]*>/)?.[0] || "";
    const name = String(getXmlAttributeValue(openTag, "Name") ?? "").trim();
    if (!name) {
      addUniqueValidationError(errors, "Field Name is missing.");
    } else if (fieldNames.has(name)) {
      addUniqueValidationError(errors, `Duplicate Field Name: ${name}.`);
    } else {
      fieldNames.add(name);
      fieldsByName.set(name, block);
    }
  });

  const newFieldNames = new Set((state.fields || [])
    .filter((field) => field?.sourceName == null)
    .map((field) => field.name));
  fieldsByName.forEach((block, fieldName) => {
    if (getDirectChildTagTextForValidation(block, "FldType") !== "Barcode") return;
    const modelField = state.fieldByName?.get?.(fieldName) || (state.fields || []).find(field => field.name === fieldName) || null;
    const dataBlock = extractBlock(block, "<Data>", "</Data>")?.block || "";
    const objects = listDirectChildElementRangesLossless(dataBlock, "Object")
      .map((range) => dataBlock.slice(range.start, range.end));
    const segmentValues = [];
    const strictCanonical = newFieldNames.has(fieldName);

    objects.forEach((objectBlock, index) => {
      const objectOpen = objectBlock.match(/^<Object\b[^>]*>/)?.[0] || "";
      const indexValue = getXmlAttributeValue(objectOpen, "Index");
      if (strictCanonical) {
        if (index === 0 && indexValue != null) {
          addUniqueValidationError(errors, `DataMatrix "${fieldName}" first Object must not have Index.`);
        }
        if (index > 0 && String(indexValue ?? "") !== String(index)) {
          addUniqueValidationError(errors, `DataMatrix "${fieldName}" Object #${index} must have Index="${index}".`);
        }
      }

      const defaultValue = getFirstTagTextForValidation(objectBlock, "Default") ?? "";
      segmentValues.push(defaultValue);
      const sourceTag = objectBlock.match(/<SrcField\b[^>]*>/)?.[0] || null;
      if (!sourceTag) return;
      const reference = String(getXmlAttributeValue(sourceTag, "SrcFieldName") ?? "").trim();
      const sourceBlock = fieldsByName.get(reference);
      if (!reference || !sourceBlock) {
        addUniqueValidationError(errors, `Missing DataMatrix SrcField target: ${reference || "(empty)"}.`);
        return;
      }
      const sourceField = state.fieldByName?.get?.(reference);
      const sourceValue = sourceField && options.calculatedData?.has(sourceField)
        ? options.calculatedData.get(sourceField)
        : getFieldSourceValueForValidation(sourceBlock);
      const sourceSelection = {
        startChar: getFirstTagTextForValidation(objectBlock, "StartChar"),
        noOfChars: getFirstTagTextForValidation(objectBlock, "NoOfChars"),
        selectMode: getFirstTagTextForValidation(objectBlock, "SelectMode")
      };
      const expectedDefault = filterCiffCalculatedDataForXml(selectCiffSourceFieldData(sourceValue, sourceSelection));
      if (defaultValue !== expectedDefault) {
        addUniqueValidationError(
          errors,
          `DataMatrix "${fieldName}" Default for SrcField "${reference}" is "${defaultValue}", expected "${expectedDefault}".`
        );
      }
    });

    if (!modelField?.barcode?.dataMatrix && !/<DataMatrix\b/.test(block)) return;
    const actualCalcData = getDirectChildTagTextForValidation(block, "CalcData") ?? "";
    const currentSegmentValues = modelField?.barcode?.dataMatrix
      ? resolveCiffDataMatrixSegmentValues(modelField, options.now, {
          fieldByName: state.fieldByName, calculatedData: options.calculatedData
        })
      : null;
    const preparedCurrent = modelField && options.calculatedData?.has(modelField)
      ? options.calculatedData.get(modelField)
      : null;
    const expectedCalcData = filterCiffCalculatedDataForXml(currentSegmentValues == null && preparedCurrent != null
      ? preparedCurrent : (currentSegmentValues ?? segmentValues).join(""));
    if (actualCalcData !== expectedCalcData) {
      addUniqueValidationError(errors, `DataMatrix "${fieldName}" CalcData is inconsistent with its ordered Data Objects.`);
    }

    if (!String(getDirectChildTagTextForValidation(block, "CLSID") ?? "").trim()) {
      addUniqueValidationError(errors, `DataMatrix "${fieldName}" CLSID is missing.`);
    }
    const actualBcH = getFirstTagTextForValidation(block, "BcH");
    if (actualBcH == null) {
      addUniqueValidationError(errors, `DataMatrix "${fieldName}" BcH is missing.`);
    } else {
      const numericBcH = Number(actualBcH);
      const modelBcH = modelField?.barcode?.bcH;
      if (!Number.isFinite(numericBcH)) {
        addUniqueValidationError(errors, `DataMatrix "${fieldName}" BcH is not numeric.`);
      } else if (
        modelBcH != null && String(modelBcH).trim() !== "" &&
        Number.isFinite(Number(modelBcH)) && numericBcH !== Math.round(Number(modelBcH))
      ) {
        addUniqueValidationError(errors, `DataMatrix "${fieldName}" BcH does not match the editor model.`);
      }
    }

    if (strictCanonical) {
      const expectedChildren = [
        "FldType", "CLSID",
        ...(modelField?.printed === false ? ["Displayed"] : []),
        "X", "Y", "W", "H",
        ...(modelField?.ln != null && Number(modelField.ln) !== 0 ? ["Ln"] : []),
        ...(normalizeOrientation(modelField?.orientation) ? ["Orientation"] : []),
        ...(expectedCalcData !== "" ? ["CalcData"] : []),
        ...(modelField?.loggedField !== undefined && modelField.loggedField !== "Not Logged" ? ["LoggedField"] : []),
        "Data", "Barcode"
      ];
      const actualChildren = getDirectChildTagNamesForValidation(block);
      if (JSON.stringify(actualChildren) !== JSON.stringify(expectedChildren)) {
        addUniqueValidationError(errors, `DataMatrix "${fieldName}" does not use the canonical ClariSoft child order.`);
      }
    }
  });
}

function getFieldSourceValueForValidation(fieldBlock) {
  const userEnter = getFirstTagTextForValidation(fieldBlock, "UserEnterData");
  if (userEnter != null) return userEnter;
  const calcData = getDirectChildTagTextForValidation(fieldBlock, "CalcData");
  if (calcData != null) return calcData;
  return getFirstTagTextForValidation(fieldBlock, "Default") ?? "";
}

function getFirstTagTextForValidation(block, tag) {
  const expression = new RegExp(`<${tag}(?:\\s[^>]*)?>([\\s\\S]*?)<\\/${tag}>`);
  const match = expression.exec(String(block ?? ""));
  return match ? decodeXmlTextForValidation(match[1]) : null;
}

function getDirectChildTagNamesForValidation(block) {
  const openEnd = String(block ?? "").indexOf(">");
  const closeStart = String(block ?? "").lastIndexOf("</");
  if (openEnd < 0 || closeStart <= openEnd) return [];
  const inner = block.slice(openEnd + 1, closeStart);
  const tokens = inner.match(/<!\[CDATA\[[\s\S]*?\]\]>|<!--[\s\S]*?-->|<[^>]+>/g) || [];
  const names = [];
  let depth = 0;
  tokens.forEach((token) => {
    if (token.startsWith("<!")) return;
    if (/^<\//.test(token)) {
      depth = Math.max(0, depth - 1);
      return;
    }
    const name = token.match(/^<\s*([^\s/>]+)/)?.[1];
    if (!name) return;
    if (depth === 0) names.push(name);
    if (!/\/\s*>$/.test(token)) depth += 1;
  });
  return names;
}

function getDirectChildTagTextForValidation(block, tag) {
  const openEnd = String(block ?? "").indexOf(">");
  const closeStart = String(block ?? "").lastIndexOf("</");
  if (openEnd < 0 || closeStart <= openEnd) return null;
  const inner = block.slice(openEnd + 1, closeStart);
  const range = typeof findDirectChildTagContentRange === "function"
    ? findDirectChildTagContentRange(inner, tag)
    : findSimpleDirectChildTagContentRange(inner, tag);
  return range ? decodeXmlTextForValidation(inner.slice(range.start, range.end)) : null;
}

function decodeXmlTextForValidation(value) {
  const trimmed = String(value ?? "").trim();
  const expression = /<!\[CDATA\[([\s\S]*?)\]\]>/g;
  let result = "";
  let cursor = 0;
  let foundCdata = false;
  let match;
  while ((match = expression.exec(trimmed))) {
    foundCdata = true;
    result += decodeXmlEntities(trimmed.slice(cursor, match.index));
    result += match[1];
    cursor = expression.lastIndex;
  }
  if (!foundCdata) return decodeXmlEntities(trimmed);
  return result + decodeXmlEntities(trimmed.slice(cursor));
}

function parseStrictInteger(value) {
  const text = String(value ?? "").trim();
  return /^[+-]?\d+$/.test(text) ? Number(text) : NaN;
}

function parseStrictNumber(value) {
  const text = String(value ?? "").trim();
  return /^[+-]?(?:\d+(?:\.\d*)?|\.\d+)$/.test(text) ? Number(text) : NaN;
}

function decodeXmlEntities(value) {
  return String(value ?? "")
    .replace(/&#x([0-9a-f]+);/gi, (match, code) => String.fromCodePoint(parseInt(code, 16)))
    .replace(/&#(\d+);/g, (match, code) => String.fromCodePoint(parseInt(code, 10)))
    .replace(/&quot;/g, '"')
    .replace(/&apos;/g, "'")
    .replace(/&lt;/g, "<")
    .replace(/&gt;/g, ">")
    .replace(/&amp;/g, "&");
}

function getCiffXmlParseError(line1, line2) {
  if (typeof DOMParser !== "function") return null;
  try {
    const doc = new DOMParser().parseFromString(`${line1}\n${line2}`, "application/xml");
    const parserError = doc.querySelector?.("parsererror") || doc.getElementsByTagName?.("parsererror")?.[0];
    return parserError ? String(parserError.textContent || "XML parser error").trim() : null;
  } catch (error) {
    return error instanceof Error ? error.message : String(error);
  }
}

function readValidationNames(result, key) {
  const value = Array.isArray(result) ? result : result?.[key];
  const fallback = state.validation?.[key];
  const names = Array.isArray(value) ? value : (Array.isArray(fallback) ? fallback : []);
  return [...new Set(names.map((name) => String(name)))];
}

function addUniqueValidationError(errors, message) {
  if (message && !errors.includes(message)) errors.push(message);
}

/* ---- Backward-compatible lightweight DateOffset reference check ---- */
function validateOffsetsInText(line2) {
  const offsetNames = new Set();
  const reOff = /<DateOffset\b[^>]*\bName="([^"]+)"/g;
  let m;
  while ((m = reOff.exec(line2)) !== null) offsetNames.add(m[1]);

  const refs = new Set();
  const reRef = /<OffsetDate\b[^>]*\bSrcOffset="([^"]+)"/g;
  while ((m = reRef.exec(line2)) !== null) refs.add(m[1]);

  const missing = [];
  for (const r of refs) if (!offsetNames.has(r)) missing.push(r);
  return missing;
}

/* ----------------- Low-level string ops ----------------- */

function extractBlock(s, openStartsWith, closeTag) {
  const tagName = String(openStartsWith ?? "").match(/^<\s*([^\s/>]+)/)?.[1];
  if (!tagName) return null;
  const range = findElementRangeLossless(s, tagName);
  return range
    ? { start: range.start, end: range.end, block: s.slice(range.start, range.end) }
    : null;
}

function extractImageDesignDirectChildBlock(line2, tagName) {
  const imageDesign = extractBlock(line2, "<ImageDesign", "</ImageDesign>");
  if (!imageDesign) return null;
  const range = findDirectChildElementRangeLossless(imageDesign.block, tagName);
  if (!range) return null;
  return {
    start: imageDesign.start + range.start,
    end: imageDesign.start + range.end,
    block: imageDesign.block.slice(range.start, range.end)
  };
}

function findElementRangeLossless(xml, tagName, fromIndex = 0) {
  const input = String(xml ?? "");
  const tokenExpression = /<!\[CDATA\[[\s\S]*?\]\]>|<!--[\s\S]*?-->|<\?[\s\S]*?\?>|<![^>]*>|<[^>]+>/g;
  tokenExpression.lastIndex = Math.max(0, fromIndex);
  let start = -1;
  let targetDepth = 0;
  let match;
  while ((match = tokenExpression.exec(input))) {
    const token = match[0];
    if (/^<\?|^<!/.test(token)) continue;
    const name = token.match(/^<\/?\s*([^\s/>]+)/)?.[1];
    if (name !== tagName) continue;
    const closing = /^<\//.test(token);
    const selfClosing = /\/\s*>$/.test(token);
    if (start < 0) {
      if (closing) continue;
      start = match.index;
      if (selfClosing) return { start, end: tokenExpression.lastIndex, selfClosing: true };
      targetDepth = 1;
      continue;
    }
    if (closing) {
      targetDepth -= 1;
      if (targetDepth === 0) return { start, end: tokenExpression.lastIndex, selfClosing: false };
    } else if (!selfClosing) {
      targetDepth += 1;
    }
  }
  return null;
}

function insertBeforeClosingTag(block, closingTag, insertStr) {
  const pos = block.lastIndexOf(closingTag);
  if (pos < 0) throw new Error(`closingTag not found: ${closingTag}`);
  return block.slice(0, pos) + insertStr + block.slice(pos);
}

function listFieldNamesInBlock(subImageBlock) {
  const set = new Set();
  listDirectChildElementRangesLossless(subImageBlock, "Field").forEach((range) => {
    const block = subImageBlock.slice(range.start, range.end);
    const openTag = block.match(/^<Field\b[^>]*>/)?.[0];
    const name = getXmlAttributeValue(openTag, "Name");
    if (name != null) set.add(name);
  });
  return set;
}

function hasFieldBlock(subImageBlock, name) {
  return !!extractFieldBlockInSubImage(subImageBlock, name);
}

function removeFieldBlock(subImageBlock, name) {
  const found = extractFieldBlockInSubImage(subImageBlock, name);
  return found
    ? subImageBlock.slice(0, found.start) + subImageBlock.slice(found.end)
    : subImageBlock;
}

function extractFieldBlockInSubImage(subImageBlock, fieldName) {
  const input = String(subImageBlock ?? "");
  const isSubImageRoot = /^\s*<SubImage\b/.test(input);
  const nestedSubImage = isSubImageRoot ? null : extractBlock(input, "<SubImage", "</SubImage>");
  const scope = nestedSubImage?.block ?? input;
  const offset = nestedSubImage?.start ?? 0;
  for (const range of listDirectChildElementRangesLossless(scope, "Field")) {
    const block = scope.slice(range.start, range.end);
    const openTag = block.match(/^<Field\b[^>]*>/)?.[0];
    if (getXmlAttributeValue(openTag, "Name") === String(fieldName ?? "")) {
      return { start: offset + range.start, end: offset + range.end, block };
    }
  }
  return null;
}

function listDirectChildElementRangesLossless(parentBlock, tagName) {
  const input = String(parentBlock ?? "");
  const openEnd = input.indexOf(">");
  const closeStart = input.lastIndexOf("</");
  if (openEnd < 0 || closeStart <= openEnd) return [];

  const inner = input.slice(openEnd + 1, closeStart);
  const tokenExpression = /<!\[CDATA\[[\s\S]*?\]\]>|<!--[\s\S]*?-->|<\?[\s\S]*?\?>|<![^>]*>|<[^>]+>/g;
  const ranges = [];
  let depth = 0;
  let target = null;
  let tokenMatch;
  while ((tokenMatch = tokenExpression.exec(inner))) {
    const token = tokenMatch[0];
    if (/^<\?|^<!/.test(token)) continue;
    const name = token.match(/^<\/?\s*([^\s/>]+)/)?.[1];
    if (!name) continue;
    const closing = /^<\//.test(token);
    const selfClosing = /\/\s*>$/.test(token);
    const tokenStart = openEnd + 1 + tokenMatch.index;
    const tokenEnd = openEnd + 1 + tokenExpression.lastIndex;
    if (closing) {
      if (target && depth === 1 && name === tagName) {
        ranges.push({ start: target.start, end: tokenEnd, selfClosing: false });
        target = null;
      }
      depth = Math.max(0, depth - 1);
      continue;
    }
    if (depth === 0 && name === tagName) {
      if (selfClosing) ranges.push({ start: tokenStart, end: tokenEnd, selfClosing: true });
      else target = { start: tokenStart };
    }
    if (!selfClosing) depth += 1;
  }
  return ranges;
}

function replaceTagTextIfExists(block, tag, newText) {
  const re = new RegExp(`(<${tag}>)([\\s\\S]*?)(</${tag}>)`);
  if (!re.test(block)) return block;
  return block.replace(re, (match, open, oldText, close) => open + newText + close);
}

function replaceDirectChildTagTextIfExists(block, tag, newText) {
  const openEnd = block.indexOf(">");
  const closeStart = block.lastIndexOf("</");
  if (openEnd < 0 || closeStart <= openEnd) return block;

  const inner = block.slice(openEnd + 1, closeStart);
  const range = findDirectChildTagContentRange(inner, tag);
  if (!range) return block;

  const start = openEnd + 1 + range.start;
  const end = openEnd + 1 + range.end;
  return block.slice(0, start) + newText + block.slice(end);
}

function replaceFieldNameAttr(block, newName) {
  return block.replace(
    /(<Field\b[^>]*\bName\s*=\s*)(["'])([\s\S]*?)\2/,
    (match, prefix, quote) => `${prefix}${quote}${escapeAttrForQuote(newName, quote)}${quote}`
  );
}

function replaceTagTextWithinIfExists(block, parentTag, tag, newText) {
  const parent = extractBlock(block, `<${parentTag}`, `</${parentTag}>`);
  if (!parent) return block;
  const inner = parent.block;
  const patchedInner = replaceTagTextIfExists(inner, tag, newText);
  return block.slice(0, parent.start) + patchedInner + block.slice(parent.end);
}

function replaceFirstCdataIfExists(block, tag, newCdataText) {
  const re = new RegExp(`(<${tag}\\b[^>]*>)([\\s\\S]*?)(</${tag}>)`);
  if (!re.test(block)) return block;
  return block.replace(re, (match, open, inner, close) => open + wrapCdata(newCdataText) + close);
}

function setOrInsertCdataTag(block, tag, cdataText, afterAnchor) {
  // if tag exists: patch CDATA
  if (new RegExp(`<${tag}\\b`).test(block)) {
    return block.replace(
      new RegExp(`(<${tag}\\b[^>]*>)([\\s\\S]*?)(</${tag}>)`),
      (match, open, inner, close) => open + wrapCdata(cdataText) + close
    );
  }
  // insert tag after anchor if anchor exists
  const pos = block.indexOf(afterAnchor);
  if (pos < 0) return block;
  return block.slice(0, pos + afterAnchor.length) + `<${tag}>${wrapCdata(cdataText)}</${tag}>` + block.slice(pos + afterAnchor.length);
}

function patchVarTextOnlyIfExists(block, f) {
  return patchFirstDataObjectLossless(block, objectBlock => (
    patchDirectChildBlockLossless(objectBlock, "VarText", varText => {
      varText = patchDirectChildScalarLossless(varText, "UserEnterData", f.data.userEnterData ?? "", { cdata: true });
      return patchDirectChildScalarLossless(varText, "Mask", f.data.mask ?? "", { cdata: true });
    })
  ));
}

function syncTextEntryModeStructure(block, f) {
  if (f.fldType !== "FixedText") return block;

  const wantVarText = wantsVarTextStructure(f);
  let hasVarText = false;
  patchFirstDataObjectLossless(block, objectBlock => {
    hasVarText = !!findDirectChildElementRangeLossless(objectBlock, "VarText");
    return objectBlock;
  });
  if (wantVarText && hasVarText) return block;

  if (!wantVarText) {
    if (!hasVarText) return block;
    return patchFirstDataObjectLossless(block, (objectBlock) => {
      const range = findDirectChildElementRangeLossless(objectBlock, "VarText");
      return range
        ? objectBlock.slice(0, range.start) + objectBlock.slice(range.end)
        : objectBlock;
    });
  }

  const mask = (f.data.mask ?? "") !== "" ? `<Mask>${wrapCdata(f.data.mask)}</Mask>` : ``;
  const userEnterValue = f.data.userEnterData ?? f.data.defaultValue ?? "";
  return patchFirstDataObjectLossless(block, (objectBlock) => insertDirectChildElementInOrderLossless(
    objectBlock,
    "VarText",
    buildCiffVarTextXml(f.data),
    TEXT_DATA_OBJECT_CHILD_ORDER
  ));
}

function setOrRemoveObjectStaticAttr(block, valueOrNull) {
  const match = block.match(/<Object\b[^>]*>/);
  if (!match) return block;

  const openTag = match[0];
  let nextOpenTag = openTag;

  const staticExpression = /\sStatic\s*=\s*(["'])[\s\S]*?\1/;
  if (valueOrNull == null) nextOpenTag = nextOpenTag.replace(staticExpression, "");
  else nextOpenTag = setOrInsertXmlAttribute(nextOpenTag, "Static", String(valueOrNull));

  if (nextOpenTag === openTag) return block;
  return block.replace(openTag, nextOpenTag);
}

function replaceAttrIfExists(block, tag, attr, newVal) {
  const re = new RegExp(`(<${tag}\\b[^>]*\\b${attr}\\s*=\\s*)(["'])([\\s\\S]*?)\\2`);
  if (!re.test(block)) return block;
  return block.replace(re, (match, prefix, quote) => `${prefix}${quote}${escapeAttrForQuote(newVal, quote)}${quote}`);
}

function setOrRemoveDisplayed(block, wantDisplayed0) {
  if (wantDisplayed0) return patchDirectChildScalarLossless(block, "Displayed", 0, { insert: true });
  const range = findDirectChildElementRangeLossless(block, "Displayed");
  return range && !range.selfClosing && readXmlScalarTextLossless(block.slice(range.openEnd, range.closeStart)).trim() === "0"
    ? block.slice(0, range.start) + block.slice(range.end) : block;
}

function setOrRemoveOrientation(block, orientation) {
  return patchDirectChildScalarLossless(block, "Orientation", orientation, { insert: orientation !== 0 });
}

function rebuildDataObjectsForDataMatrix(fieldBlock, segments) {
  const data = findDirectChildElementRangeLossless(fieldBlock, "Data");
  if (!data) return fieldBlock;
  let sourceData = fieldBlock.slice(data.start, data.end);
  if (data.selfClosing) sourceData = sourceData.replace(/\/\s*>$/, ">") + "</Data>";
  const ranges = listDirectChildElementRangesLossless(sourceData, "Object");
  const original = ranges.map((range, position) => {
    const block = sourceData.slice(range.start, range.end);
    const source = findDirectChildElementRangeLossless(block, "SrcField");
    return {
      block, position,
      srcField: source ? getXmlAttributeValue(block.slice(source.start, source.openEnd), "SrcFieldName") : null,
      dataType: getDirectChildTagTextForValidation(block, "DataType"),
      defaultValue: getDirectChildTagTextForValidation(block, "Default") ?? ""
    };
  });
  const used = new Set();
  const objects = segments.map((segment, index) => {
    // The parser retains immutable source identity across reorders, deletions,
    // cloning and history. A new segment never consumes another's metadata.
    const identity = segment.sourceObjectIndex;
    let source = Number.isInteger(identity) && identity >= 0 ? original[identity] : null;
    if (source && used.has(source.position)) source = null;
    if (identity === undefined) {
      // Compatibility with snapshots created before sourceObjectIndex existed:
      // attach only an unambiguous matching source, never merely a new position.
      const matching = original.filter((item) => !used.has(item.position) &&
        item.srcField === (segment.srcField ?? null) && Number(item.dataType) === Number(segment.dataType ?? 5) &&
        (item.srcField != null || item.defaultValue === String(segment.defaultValue ?? "")));
      if (matching.length === 1) source = matching[0];
    }
    if (!source) return buildCiffDataMatrixObjectXml(segment, index);
    used.add(source.position);
    let block = patchCiffDataMatrixObjectLossless(source.block, segment);
    const open = block.match(/^<Object\b[^>]*>/)?.[0];
    if (!open) return block;
    const sourceIndex = getXmlAttributeValue(open, "Index");
    let next = open;
    if (index === 0) {
      if (sourceIndex != null && Number(sourceIndex) !== 0) next = open.replace(/\sIndex\s*=\s*(["'])[\s\S]*?\1/i, "");
    } else if (Number(sourceIndex) !== index || sourceIndex == null) {
      next = setOrInsertXmlAttribute(open, "Index", index);
    }
    return next + block.slice(open.length);
  });
  // Preserve Data attributes, comments and opaque siblings while replacing
  // only Object slots. Extra segments are appended within the same container.
  let newData = "";
  let cursor = 0;
  ranges.forEach((range, index) => {
    newData += sourceData.slice(cursor, range.start) + (objects[index] ?? "");
    cursor = range.end;
  });
  newData += sourceData.slice(cursor);
  if (objects.length > ranges.length) newData = insertBeforeClosingTag(newData, "</Data>", objects.slice(ranges.length).join(""));
  return fieldBlock.slice(0, data.start) + newData + fieldBlock.slice(data.end);
}

/* ---------- Encoding ---------- */
function encodeUtf16leWithBom(str) {
  const buf = new ArrayBuffer(2 + str.length * 2);
  const view = new DataView(buf);
  view.setUint16(0, 0xFEFF, true); // BOM
  for (let i = 0; i < str.length; i++) view.setUint16(2 + i * 2, str.charCodeAt(i), true);
  return buf;
}

/* ---------- Utils ---------- */
function toInt(v, fallback = 0) {
  if (v == null) return fallback;
  const n = parseInt(String(v).trim(), 10);
  return Number.isFinite(n) ? n : fallback;
}
function toFloat(v, fallback = 0) {
  if (v == null) return fallback;
  const n = parseFloat(String(v).trim());
  return Number.isFinite(n) ? n : fallback;
}
function normalizeOrientation(v) {
  const n = toInt(v, 0);
  return ALLOWED_ORIENTATIONS.includes(n) ? n : 0;
}

function applyFieldOrientation(group, width, height, orientationValue) {
  const orientation = normalizeOrientation(orientationValue);
  group.rotation(orientation);

  // Keep rotated content inside the same local field box.
  // Konva/canvas positive rotation is clockwise, so translation differs for 90/270.
  if (orientation === 90) {
    group.x(height);
    group.y(0);
    return;
  }
  if (orientation === 180) {
    group.x(width);
    group.y(height);
    return;
  }
  if (orientation === 270) {
    group.x(0);
    group.y(width);
    return;
  }

  group.x(0);
  group.y(0);
}

function clamp(min, max, v) { return Math.max(min, Math.min(max, v)); }
function uniqueName(base, existing) {
  let i = 0;
  while (true) {
    const name = `${base}${String(i).padStart(2, "0")}`;
    if (!existing.includes(name)) return name;
    i++;
  }
}
function guessDataType(fldType) {
  switch (fldType) {
    case "TimeText": return 1;
    case "DateText": return 2;
    case "OffsetDateText": return 3;
    case "CounterText": return 4;
    case "Barcode": return 5;
    default: return 0;
  }
}

function selectOrientation(value, onChange) {
  const normalizedValue = normalizeOrientation(value);
  return createMaterialSelect(
    ALLOWED_ORIENTATIONS.map((deg) => ({ value: String(deg), label: `${deg}\u00B0` })),
    String(normalizedValue),
    (nextValue) => onChange(normalizeOrientation(nextValue))
  );
}

function patchDataMatrixObjectsNonInvasive(fieldBlock, segments) {
  const data = findDirectChildElementRangeLossless(fieldBlock, "Data");
  if (!data) return fieldBlock;
  const dataBlock = fieldBlock.slice(data.start, data.end);
  let patchedData = dataBlock;
  const objectRanges = listDirectChildElementRangesLossless(dataBlock, "Object");
  for (let objectIndex = objectRanges.length - 1; objectIndex >= 0; objectIndex -= 1) {
    const range = objectRanges[objectIndex];
    const segment = segments.find((item) => item.sourceObjectIndex === objectIndex) ??
      (segments[objectIndex]?.sourceObjectIndex == null ? segments[objectIndex] : null);
    if (!segment) continue;
    const objectBlock = dataBlock.slice(range.start, range.end);
    const next = patchCiffDataMatrixObjectLossless(objectBlock, segment);
    patchedData = patchedData.slice(0, range.start) + next + patchedData.slice(range.end);
  }
  return fieldBlock.slice(0, data.start) + patchedData + fieldBlock.slice(data.end);
}

function patchCiffNativeOptionalScalarLossless(block, tag, value, options = {}) {
  if (value === undefined) return block;
  const range = findDirectChildElementRangeLossless(block, tag);
  const source = range ? (range.selfClosing ? "" : readXmlScalarTextLossless(block.slice(range.openEnd, range.closeStart))) : null;
  if (tag === "MaxNoOfChars" && value == null && range && !hasNumericMaxNoOfChars(source)) return block;
  if (source === (value == null ? null : String(value)) ||
    (range && typeof value === "number" && source !== "" && Number(source) === value)) return block;
  if (value == null || options.omit?.(value)) {
    return range ? block.slice(0, range.start) + block.slice(range.end) : block;
  }
  return patchDirectChildScalarLossless(block, tag, value, {
    ...options, insert: true, order: options.order || TEXT_DATA_OBJECT_CHILD_ORDER
  });
}

function patchCiffSrcFieldLossless(objectBlock, segment) {
  if (segment.srcField === undefined) return objectBlock;
  const range = findDirectChildElementRangeLossless(objectBlock, "SrcField");
  if (!segment.srcField) return range ? objectBlock.slice(0, range.start) + objectBlock.slice(range.end) : objectBlock;
  if (!range) return insertDirectChildElementInOrderLossless(
    objectBlock, "SrcField", buildCiffSrcFieldXml(segment), TEXT_DATA_OBJECT_CHILD_ORDER
  );
  let source = objectBlock.slice(range.start, range.end);
  const open = source.slice(0, range.openEnd - range.start);
  if (getXmlAttributeValue(open, "SrcFieldName") !== segment.srcField) {
    source = setOrInsertXmlAttribute(open, "SrcFieldName", segment.srcField) + source.slice(open.length);
  }
  const properties = [["StartChar", "startChar"], ["NoOfChars", "noOfChars"], ["SelectMode", "selectMode"]];
  if (/\/\s*>$/.test(source) && properties.some(([, key]) => segment[key] != null && Number(segment[key]) !== 0)) {
    source = source.replace(/\/\s*>$/, ">") + "</SrcField>";
  }
  if (!/\/\s*>$/.test(source)) {
    for (const [tag, key] of properties) source = patchCiffNativeOptionalScalarLossless(source, tag, segment[key], {
      omit: value => Number(value) === 0, order: ["StartChar", "NoOfChars", "SelectMode"]
    });
  }
  return objectBlock.slice(0, range.start) + source + objectBlock.slice(range.end);
}

function patchCiffDataMatrixObjectLossless(objectBlock, segment) {
  if (/\/\s*>$/.test(objectBlock)) objectBlock = objectBlock.replace(/\/\s*>$/, ">") + "</Object>";
  objectBlock = patchDirectChildScalarLossless(objectBlock, "DataType", segment.dataType ?? 5, { insert: true, order: TEXT_DATA_OBJECT_CHILD_ORDER });
  objectBlock = patchCiffNativeOptionalScalarLossless(objectBlock, "Default", segment.defaultValue, {
    cdata: true, omit: value => String(value) === ""
  });
  objectBlock = patchOptionalObjectAttributesLossless(objectBlock, segment);
  objectBlock = patchCiffNativeObjectPropertiesLossless(objectBlock, segment);
  objectBlock = patchCiffNativeOptionalScalarLossless(objectBlock, "MaxNoOfChars", segment.maxChars, { omit: value => Number(value) === 0 });
  const fixedLen = findDirectChildElementRangeLossless(objectBlock, "FixedLen");
  if (segment.fixedLen === true && !fixedLen) objectBlock = insertDirectChildElementInOrderLossless(
    objectBlock, "FixedLen", buildCiffFixedLenXml(segment), TEXT_DATA_OBJECT_CHILD_ORDER
  );
  if (segment.fixedLen === false && fixedLen) objectBlock = objectBlock.slice(0, fixedLen.start) + objectBlock.slice(fixedLen.end);
  objectBlock = patchCiffSrcFieldLossless(objectBlock, segment);
  objectBlock = patchSourceDataLossless(objectBlock, segment.srcData);
  return objectBlock;
}
function pad2(x){ return String(x ?? 0).padStart(2,"0"); }
function escapeHtml(s) {
  return String(s ?? "").replace(/[&<>"']/g, (c) => ({'&':'&amp;','<':'&lt;','>':'&gt;','"':'&quot;',"'":'&#39;'}[c]));
}
function escapeHtmlAttr(s){ return escapeHtml(s).replace(/"/g,'&quot;'); }
function escapeReg(s) { return String(s).replace(/[.*+?^${}()|[\]\\]/g, "\\$&"); }
function wrapCdata(value) {
  // XML forbids the CDATA terminator inside one section. Adjacent sections
  // preserve the exact logical value while keeping the document well formed.
  return `<![CDATA[${filterCiffCalculatedDataForXml(value).replace(/\]\]>/g, "]]]]><![CDATA[>")}]]>`;
}
function escapeAttr(s) {
  return String(s ?? "")
    .replace(/&/g,"&amp;")
    .replace(/"/g,"&quot;")
    .replace(/</g,"&lt;")
    .replace(/>/g,"&gt;");
}
function escapeAttrForQuote(value, quote) {
  const escaped = escapeAttr(value);
  return quote === "'" ? escaped.replace(/'/g, "&apos;") : escaped;
}

