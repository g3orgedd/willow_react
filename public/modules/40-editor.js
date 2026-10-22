// ---------- Properties builders ----------
const PRINT_SWITCH_ANIMATION_MS = 220;
const X_MAG_MIN = 3;
const X_MAG_MAX = 500;

function inputMaxCharacters(value, onChange) {
  const currentValue = Number.isSafeInteger(value) && value >= 0 ? String(value) : "";
  let input;

  input = inputText(currentValue, (rawValue) => {
    const normalizedValue = rawValue.trim();
    if (normalizedValue === "") {
      onChange(null);
      return;
    }

    const nextValue = Number(normalizedValue);
    if (!Number.isSafeInteger(nextValue) || nextValue < 0) {
      input.value = currentValue;
      return;
    }

    onChange(nextValue);
  }, { type: "number" });

  input.min = "0";
  input.step = "1";
  input.placeholder = "Not specified";
  return input;
}

function getFieldVisualSizeInternal(field, orientationValue = field?.orientation) {
  const orientation = normalizeOrientation(orientationValue);
  const w = Number(field?.geom?.w ?? 0);
  const h = Number(field?.geom?.h ?? 0);
  return (orientation === 90 || orientation === 270)
    ? { w: h, h: w }
    : { w, h };
}

function getFieldVisualBoundsInternal(field, orientationValue = field?.orientation) {
  const size = getFieldVisualSizeInternal(field, orientationValue);
  const x = Number(field?.geom?.x ?? 0);
  const y = Number(field?.geom?.y ?? 0);
  return {
    x,
    y,
    w: size.w,
    h: size.h,
    cx: x + size.w / 2,
    cy: y + size.h / 2
  };
}

function getFieldsVisualBoundsInternal(fields) {
  const bounds = fields.map((field) => getFieldVisualBoundsInternal(field));
  const minX = Math.min(...bounds.map((box) => box.x));
  const minY = Math.min(...bounds.map((box) => box.y));
  const maxX = Math.max(...bounds.map((box) => box.x + box.w));
  const maxY = Math.max(...bounds.map((box) => box.y + box.h));
  return {
    x: minX,
    y: minY,
    w: maxX - minX,
    h: maxY - minY,
    cx: (minX + maxX) / 2,
    cy: (minY + maxY) / 2
  };
}

function rotatePointAroundPivotInternal(point, pivot, deltaRotation) {
  const dx = point.x - pivot.x;
  const dy = point.y - pivot.y;
  const angle = normalizeOrientation(deltaRotation);

  if (angle === 90) return { x: pivot.x - dy, y: pivot.y + dx };
  if (angle === 180) return { x: pivot.x - dx, y: pivot.y - dy };
  if (angle === 270) return { x: pivot.x + dy, y: pivot.y - dx };
  return { x: point.x, y: point.y };
}

function getMultiRotationDelta(fields, targetRotation, hasMixedRotation, firstRotation) {
  if (hasMixedRotation) return targetRotation;
  const delta = ((targetRotation - firstRotation) % 360 + 360) % 360;
  return ALLOWED_ORIENTATIONS.includes(delta) ? delta : 0;
}

function applyMultiFieldRotation(fields, targetRotation, hasMixedRotation, firstRotation) {
  if (!fields.length) return false;

  const normalizedTarget = normalizeOrientation(targetRotation);
  const deltaRotation = getMultiRotationDelta(fields, normalizedTarget, hasMixedRotation, firstRotation);
  const shouldUpdateOrientation = fields.some((field) => normalizeOrientation(field.orientation) !== normalizedTarget);
  if (deltaRotation === 0 && !shouldUpdateOrientation) return false;

  const groupBounds = getFieldsVisualBoundsInternal(fields);
  const pivot = { x: groupBounds.cx, y: groupBounds.cy };

  fields.forEach((field) => {
    const currentBounds = getFieldVisualBoundsInternal(field);
    const rotatedCenter = rotatePointAroundPivotInternal(
      { x: currentBounds.cx, y: currentBounds.cy },
      pivot,
      deltaRotation
    );
    const nextSize = getFieldVisualSizeInternal(field, normalizedTarget);

    field.geom.x = Math.round(rotatedCenter.x - nextSize.w / 2);
    field.geom.y = Math.round(rotatedCenter.y - nextSize.h / 2);
    field.orientation = normalizedTarget;
  });

  constrainCurrentFieldPositionsInternal(fields);

  return true;
}

function supportsFontSizeEditing(field) {
  return !!field?.text && field.fldType !== "Barcode";
}

function normalizeFontSizeValue(value) {
  const next = Math.round(Number(value));
  return Number.isFinite(next) ? Math.max(1, next) : null;
}

function applyTextPitchChange(field, value) {
  const pitch = normalizeFontSizeValue(value);
  if (!field?.text || !field?.geom || pitch == null) return null;
  field.text.pitch = pitch;
  if (globalThis.glyphFonts?.render && typeof requestNativeTextPreview === 'function') {
    field._nativeTextGeometryDirty = true;
    requestNativeTextPreview(field, makePreviewText(field));
    return pitch;
  }
  field.geom.h = typeof getClarisoftTextFieldHeightInternal === "function"
    ? getClarisoftTextFieldHeightInternal(pitch)
    : Math.max(1, mmToInternal(pitch * CLARISOFT_TEXT_FIELD_HEIGHT_MM_PER_PITCH));
  if (typeof getFieldRenderedBoundsInternal === "function") {
    const bounds = getFieldRenderedBoundsInternal(field, new Date(), { forceFresh: true });
    if (bounds && [bounds.x, bounds.y, bounds.w, bounds.h].every(Number.isFinite)) {
      field.geom.w = Math.max(1, Math.ceil(bounds.x + bounds.w - field.geom.x));
      field.geom.h = Math.max(field.geom.h, Math.ceil(bounds.y + bounds.h - field.geom.y));
    }
  }
  return pitch;
}

function applyTextResizeTransform(field, beforeText, scaleX, scaleY) {
  if (!supportsFontSizeEditing(field) || !field.geom) return null;
  const basePitch = normalizeFontSizeValue(beforeText?.pitch ?? getEffectiveTextPitch(field, 10));
  if (basePitch == null) return null;
  const baseXMag = Number.isFinite(Number(beforeText?.xMag))
    ? Number(beforeText.xMag)
    : (Number(field.text.xMag) || 100);
  const normalizedScaleX = Math.max(0.01, Math.abs(Number(scaleX) || 1));
  const normalizedScaleY = Math.max(0.01, Math.abs(Number(scaleY) || 1));
  const pitch = Math.max(1, Math.round(basePitch * normalizedScaleY));
  const xMag = clamp(X_MAG_MIN, X_MAG_MAX, Math.round(baseXMag * normalizedScaleX / normalizedScaleY));

  field.text.pitch = pitch;
  field.text.xMag = xMag;
  if (globalThis.glyphFonts?.render && typeof requestNativeTextPreview === 'function') {
    field._nativeTextGeometryDirty = true;
    requestNativeTextPreview(field, makePreviewText(field));
    return { pitch, xMag };
  }
  field.geom.h = typeof getClarisoftTextFieldHeightInternal === "function"
    ? getClarisoftTextFieldHeightInternal(pitch)
    : Math.max(1, mmToInternal(pitch * CLARISOFT_TEXT_FIELD_HEIGHT_MM_PER_PITCH));
  if (typeof getFieldRenderedBoundsInternal === "function") {
    const bounds = getFieldRenderedBoundsInternal(field, new Date(), { forceFresh: true });
    if (bounds && [bounds.x, bounds.y, bounds.w, bounds.h].every(Number.isFinite)) {
      field.geom.w = Math.max(1, Math.ceil(bounds.x + bounds.w - field.geom.x));
      field.geom.h = Math.max(field.geom.h, Math.ceil(bounds.y + bounds.h - field.geom.y));
    }
  }
  return { pitch, xMag };
}

function getMultiFontSizeValue(fields) {
  const sizes = fields
    .map((field) => normalizeFontSizeValue(getEffectiveTextPitch(field, 10)))
    .filter((value) => value != null);
  const firstSize = sizes[0] ?? null;
  return {
    value: firstSize,
    mixed: sizes.some((size) => size !== firstSize)
  };
}

function createMultiFontSizeInput(fields) {
  const current = getMultiFontSizeValue(fields);
  const inp = inputNumber(current.value ?? 1, (nextValue) => {
    const nextSize = normalizeFontSizeValue(nextValue);
    if (nextSize == null) return;
    if (lastEmitted === nextSize && fields.every((field) => normalizeFontSizeValue(getEffectiveTextPitch(field, 10)) === nextSize)) return;

    lastEmitted = nextSize;
    inp.value = String(nextSize);
    pushHistory();
    fields.forEach((field) => applyTextPitchChange(field, nextSize));
    renderObjects();
    renderUI();
  }, { step: 1, integer: true, min: 1, live: true });
  inp.value = current.mixed || current.value == null ? "" : String(current.value);
  if (current.mixed) inp.placeholder = t("common.mixed");

  let lastEmitted = current.mixed ? null : current.value;
  return inp;
}

function getTextFieldFontStyle(field) {
  return field.text?.bold ? (field.text.italic ? 'bold italic' : 'bold') : (field.text?.italic ? 'italic' : 'normal');
}

function applyTextFontChange(fields, change) {
  const targets = fields.filter(supportsFontSizeEditing);
  if (!targets.length) return false;
  const changed = targets.some((field) => Object.entries(change).some(([key, value]) => {
    const current = key === 'face' ? getEffectiveTextFontFamily(field) : Boolean(field.text[key]);
    return current !== value;
  }));
  if (!changed) return false;
  pushHistory();
  targets.forEach((field) => {
    if (change.face && getEffectiveTextFontFamily(field) !== change.face && globalThis.glyphFonts?.render) {
      field._nativeTextFontDirty = true;
    }
    Object.assign(field.text, change);
    const storedPitch = field.text.pitch;
    applyTextPitchChange(field, getEffectiveTextPitch(field, 13));
    field.text.pitch = storedPitch;
  });
  if (state.subImage) state.subImage.usedSizeDirty = true;
  renderObjects();
  renderUI();
  renderSelectionPanels();
  return true;
}

function appendTextFontControls(wrap, fields) {
  const targets = fields.filter(supportsFontSizeEditing);
  if (!targets.length) return;
  const faces = targets.map(getEffectiveTextFontFamily);
  const mixedFace = faces.some((face) => face !== faces[0]);
  const options = getAvailableTextFontFamilies().map((face) => ({ value: face, label: face }));
  faces.forEach((face) => {
    if (!options.some((option) => option.value === face)) {
      options.push({ value: face, label: `${face} (${t('field.fontUnavailable')})` });
    }
  });
  if (mixedFace) options.unshift({ value: '', label: t('common.mixed') });
  const faceSelect = createMaterialSelect(options, mixedFace ? '' : faces[0], (face) => {
    if (face && isTextFontAvailable(face)) applyTextFontChange(targets, { face });
  });
  faceSelect.dataset.fontFaceSelect = '1';
  appendInspectorItem(wrap, 'text', fieldRow(t('field.fontFamily'), faceSelect), { fullWidth: true });
  if (faces.some((face) => !isTextFontAvailable(face))) {
    const note = document.createElement('div');
    note.className = 'note';
    note.textContent = t('field.fontUnavailablePreview');
    appendInspectorItem(wrap, 'text', note, { fullWidth: true });
  }
  const styles = targets.map(getTextFieldFontStyle);
  const mixedStyle = styles.some((style) => style !== styles[0]);
  const styleOptions = [
    { value: 'normal', label: t('field.fontRegular') },
    { value: 'bold', label: t('field.fontBold') },
    { value: 'italic', label: t('field.fontItalic') },
    { value: 'bold italic', label: t('field.fontBoldItalic') },
  ];
  if (mixedStyle) styleOptions.unshift({ value: '', label: t('common.mixed') });
  appendInspectorItem(wrap, 'text', fieldRow(t('field.fontStyle'), createMaterialSelect(
    styleOptions, mixedStyle ? '' : styles[0], (style) => {
      if (style) applyTextFontChange(targets, { bold: style.includes('bold'), italic: style.includes('italic') });
    }
  )), { fullWidth: true });
}

const INSPECTOR_PROPERTY_SECTION_ORDER = ["basic", "geometry", "content", "text", "datamatrix"];

function markInspectorItem(element, group, options = {}) {
  if (!element) return element;
  element.dataset.inspectorGroup = group;
  if (options.fullWidth) element.classList.add("fieldRow--fullWidth");
  return element;
}

function appendInspectorItem(container, group, element, options = {}) {
  container.appendChild(markInspectorItem(element, group, options));
  return element;
}

function buildInspectorSections(...propertyGroups) {
  const itemsBySection = new Map();
  propertyGroups.filter(Boolean).forEach((group) => {
    Array.from(group.children).forEach((item) => {
      const sectionName = item.dataset.inspectorGroup || "basic";
      if (!itemsBySection.has(sectionName)) itemsBySection.set(sectionName, []);
      itemsBySection.get(sectionName).push(item);
    });
  });

  const sectionList = document.createElement("div");
  sectionList.className = "inspectorSectionList";
  const sectionNames = [
    ...INSPECTOR_PROPERTY_SECTION_ORDER,
    ...Array.from(itemsBySection.keys()).filter((name) => !INSPECTOR_PROPERTY_SECTION_ORDER.includes(name))
  ];

  sectionNames.forEach((sectionName) => {
    const items = itemsBySection.get(sectionName);
    if (!items?.length) return;

    const section = document.createElement("section");
    section.className = `inspectorSection inspectorSection--${sectionName}`;

    const title = document.createElement("div");
    title.className = "inspectorSection__title";
    title.textContent = t(`inspector.section.${sectionName}`);

    const grid = document.createElement("div");
    grid.className = "inspectorSection__grid";
    items.forEach((item) => grid.appendChild(item));

    section.appendChild(title);
    section.appendChild(grid);
    sectionList.appendChild(section);
  });

  return sectionList;
}

function buildObjectInspectorProps(field) {
  const typeProps = field.fldType === "Barcode" && field.barcode?.dataMatrix
    ? buildBarcodeProps(field)
    : buildTextLikeProps(field);
  return buildInspectorSections(buildCommonProps(field), typeProps);
}

function buildMultiSelectionInspectorProps(fields) {
  return buildInspectorSections(buildMultiSelectionProps(fields));
}

function buildMultiSelectionProps(fields) {
  const wrap = document.createElement("div");
  wrap.className = "form";

  const fontFields = fields.filter(supportsFontSizeEditing);

  const rotations = fields.map((field) => normalizeOrientation(field.orientation));
  const firstRotation = rotations[0] ?? 0;
  const hasMixedRotation = rotations.some((rotation) => rotation !== firstRotation);
  const rotationOptions = hasMixedRotation
    ? [{ value: "", label: t("common.mixed") }, ...ALLOWED_ORIENTATIONS.map((deg) => ({ value: String(deg), label: `${deg}\u00B0` }))]
    : ALLOWED_ORIENTATIONS.map((deg) => ({ value: String(deg), label: `${deg}\u00B0` }));

  appendInspectorItem(wrap, "geometry", fieldRow(t("field.rotation"), createMaterialSelect(
    rotationOptions,
    hasMixedRotation ? "" : String(firstRotation),
    (nextValue) => {
      if (nextValue === "") return;
      const nextRotation = normalizeOrientation(nextValue);
      const shouldChange = hasMixedRotation || rotations.some((rotation) => rotation !== nextRotation);
      if (!shouldChange) return;

      pushHistory();
      if (!applyMultiFieldRotation(fields, nextRotation, hasMixedRotation, firstRotation)) return;
      renderObjects();
      renderUI();
      renderSelectionPanels();
    }
  )), { fullWidth: true });

  if (fontFields.length) {
    appendTextFontControls(wrap, fontFields);
    appendInspectorItem(wrap, "text", fieldRow(t("field.fontSize"), createMultiFontSizeInput(fontFields)), { fullWidth: true });
  }

  return wrap;
}

function buildCommonProps(f) {
  const wrap = document.createElement("div");
  wrap.className = "form";
  const isDataMatrix = f.fldType === "Barcode" && Boolean(f.barcode?.dataMatrix);

  appendInspectorItem(wrap, "basic", fieldRow(t("field.name"), createFieldNameInput(f)), { fullWidth: true });
  if (!isDataMatrix) {
    appendInspectorItem(wrap, "basic", fieldRow(t("field.maxCharacters"), inputMaxCharacters(f.data?.maxChars, (value) => {
      if (f.data.maxChars === value) return;
      pushHistory();
      f.data.maxChars = value;
      renderUI();
    })), { fullWidth: true });
    const typeControl = f.fldType === "FixedText"
      ? buildFixedTextEntryModeSelect(f)
      : inputText(f.fldType, () => {}, { disabled: true });
    appendInspectorItem(wrap, "basic", fieldRow(t("field.type"), typeControl), { fullWidth: true });
  }

  appendInspectorItem(wrap, "geometry", fieldRow(t("field.x"), inputNumber(internalToMm(f.geom.x), (v) => {
    pushHistory();
    setFieldPositionInternal(f, mmToInternal(v), f.geom.y);
    renderAll();
  })));
  appendInspectorItem(wrap, "geometry", fieldRow(t("field.y"), inputNumber(internalToMm(f.geom.y), (v) => {
    pushHistory();
    setFieldPositionInternal(f, f.geom.x, mmToInternal(v));
    renderAll();
  })));
  appendInspectorItem(wrap, "geometry", fieldRow(t("field.width"), inputNumber(internalToMm(f.geom.w), (v) => {
    pushHistory();
    f.geom.w = Math.max(1, mmToInternal(v));
    constrainCurrentFieldPositionsInternal([f], { forceFreshTextBounds: true });
    renderAll();
  }, { min: 0.01 })));
  appendInspectorItem(wrap, "geometry", fieldRow(t("field.height"), inputNumber(internalToMm(f.geom.h), (v) => {
    pushHistory();
    f.geom.h = Math.max(1, mmToInternal(v));
    constrainCurrentFieldPositionsInternal([f], { forceFreshTextBounds: true });
    renderAll();
  }, { min: 0.01 })));
  appendInspectorItem(wrap, "geometry", fieldRow(t("field.rotation"), selectOrientation(f.orientation, (v) => {
    pushHistory();
    f.orientation = v;
    constrainCurrentFieldPositionsInternal([f]);
    renderAll();
  })));
  return wrap;
}

function createFieldNameInput(field) {
  let input = null;
  input = inputText(field.name, (value) => renameField(field, value, input));
  return input;
}

function buildFixedTextEntryModeSelect(field) {
  const currentMode = getTextEntryMode(field);
  return createMaterialSelect([
    { value: "fixed", label: t("field.fixedText") },
    { value: "user", label: t("field.userEnteredText") }
  ], currentMode, (nextValue) => {
    pushHistory();
    applyFixedTextEntryMode(field, nextValue);
    renderAll();
  });
}

function applyFixedTextEntryMode(field, nextModeRaw) {
  if (!field || field.fldType !== "FixedText") return;
  const nextMode = nextModeRaw === "user" ? "user" : "fixed";
  const currentValue = getStoredTextFieldValue(field);

  field.data.textEntryMode = nextMode;
  field.data.hasVarText = nextMode === "user";
  const maxChars = Number(field.data.maxChars);
  field.data.fixedLen = nextMode === "user" && Number.isSafeInteger(maxChars) && maxChars >= 0;
  field.data.defaultValue = currentValue;
  field.calcData = currentValue;

  if (nextMode === "user") {
    field.data.staticAttr = "0";
    field.data.userEnterData = currentValue;
    synchronizeDependentDataMatrices(field.name);
    return;
  }

  field.data.staticAttr = null;
  field.data.userEnterData = "";
  field.data.mask = "";
  synchronizeDependentDataMatrices(field.name);
}

function setEditableTextFieldValue(field, nextValueRaw) {
  if (!field) return;
  const nextValue = String(nextValueRaw ?? "");

  if (field.fldType !== "FixedText") {
    field.data.userEnterData = nextValue;
    field.data.defaultValue = field.data.defaultValue || nextValue;
    field.calcData = nextValue;
    synchronizeDependentDataMatrices(field.name);
    return;
  }

  field.data.defaultValue = nextValue;
  field.calcData = nextValue;

  if (isUserEnteredTextField(field)) {
    field.data.textEntryMode = "user";
    field.data.hasVarText = true;
    field.data.staticAttr = "0";
    field.data.userEnterData = nextValue;
    synchronizeDependentDataMatrices(field.name);
    return;
  }

  field.data.textEntryMode = "fixed";
  field.data.hasVarText = false;
  field.data.staticAttr = null;
  field.data.userEnterData = "";
  synchronizeDependentDataMatrices(field.name);
}

function synchronizeDependentDataMatrices(sourceName = null) {
  state.fields.forEach((candidate) => {
    const dm = candidate.barcode?.dataMatrix;
    if (!dm) return;
    if (sourceName && !dm.segments.some((segment) => segment.srcField === sourceName)) return;
    synchronizeDataMatrixEditorState(candidate);
  });
}

function synchronizeDataMatrixEditorState(field, now = new Date()) {
  const changed = synchronizeDataMatrixDerivedState(field, state.fieldByName);
  if (normalizeDataMatrixSymbolSizeValue(field?.barcode?.dataMatrix?.symbolSize) === "Auto") {
    syncDataMatrixGeomToModuleSize(field, now);
  }
  return changed;
}

function isCanvasEditableTextField(field) {
  return field?.fldType === "FixedText";
}

function startCanvasTextFieldValueEditing(field) {
  if (!isCanvasEditableTextField(field)) return false;

  // A double click follows two regular click events, each of which rebuilds
  // the inspector. Select the field first, then resolve the current input.
  selectField(field.name, { additive: false, toggle: false });
  renderUI();

  const valueInput = Array.from(
    elPropsPanel?.querySelectorAll?.("[data-field-value-input='1']") ?? []
  ).find((input) => input.dataset.fieldName === field.name);
  if (!valueInput || valueInput.disabled || valueInput.readOnly) return false;

  valueInput.focus({ preventScroll: true });
  valueInput.select();
  return true;
}

function createEditableTextFieldValueInput(field, displayValue) {
  let editSessionStarted = false;

  const applyValue = (nextValueRaw) => {
    const nextValue = String(nextValueRaw ?? "");
    if (nextValue === String(getStoredTextFieldValue(field))) return false;

    if (!editSessionStarted) {
      pushHistory();
      editSessionStarted = true;
    }

    setEditableTextFieldValue(field, nextValue);
    if (globalThis.glyphFonts?.render) field._nativeTextGeometryDirty = true;
    if (state.subImage) state.subImage.usedSizeDirty = true;
    if (typeof schedulePersistActiveTemplateTab === "function") schedulePersistActiveTemplateTab();
    // Keep the inspector DOM intact so focus, caret position and IME
    // composition survive while Konva and dependent DataMatrices refresh.
    renderObjects();
    renderUI();
    return true;
  };

  const input = inputText(displayValue, (nextValue) => {
    applyValue(nextValue);
    editSessionStarted = false;
  });
  input.addEventListener("input", () => applyValue(input.value));
  input.addEventListener("blur", () => {
    editSessionStarted = false;
  });
  return input;
}

function createPanelActionButton(tagName, label, onClick) {
  const btn = document.createElement("button");
  btn.type = "button";
  btn.className = "btn btn--small";
  if (tagName === "md-filled-tonal-button") btn.classList.add("btn--tonal");
  else if (tagName === "md-text-button") btn.classList.add("btn--text");
  else if (tagName === "md-outlined-button") btn.classList.add("btn--ghost");
  btn.textContent = label;
  btn.addEventListener("click", onClick);
  return btn;
}

function buildTextLikeProps(f) {
  const wrap = document.createElement("div");
  wrap.className = "form";
  appendTextFontControls(wrap, [f]);

  const displayValue = getFieldDisplayValue(f);
  const isDynamicPreviewField = f.fldType === "TimeText" || f.fldType === "DateText" || f.fldType === "OffsetDateText" || f.fldType === "CounterText";
  const valueInput = isDynamicPreviewField
    ? inputText(displayValue, () => {}, { readOnly: true })
    : createEditableTextFieldValueInput(f, displayValue);

  if (isDynamicPreviewField) {
    valueInput.dataset.dynamicPreviewValue = "1";
  } else {
    valueInput.dataset.fieldValueInput = "1";
    valueInput.dataset.fieldName = f.name;
  }
  const valueRow = fieldRow(t("field.value"), valueInput);
  appendInspectorItem(wrap, "content", valueRow, { fullWidth: true });
  const valueCount = document.createElement("span");
  valueCount.className = "fieldValueCharacterCount";
  const updateValueCount = () => {
    const count = Array.from(String(valueInput.value ?? "")).length;
    valueCount.textContent = `(${count})`;
    valueCount.setAttribute("aria-label", t("field.characterCount", { count }));
  };
  valueInput._updateCharacterCount = updateValueCount;
  valueInput.addEventListener("input", updateValueCount);
  valueInput.addEventListener("change", updateValueCount);
  updateValueCount();
  valueRow.querySelector("label")?.appendChild(valueCount);

  if (f.fldType === "CounterText") {
    const counter = f.data.counter ?? {};
    const noOfChars = Math.max(1, Math.round(parseCounterNumber(counter.noOfChars, 4) ?? 4));
    const maxValue = getCounterMaxValue(noOfChars);

    appendInspectorItem(wrap, "content", fieldRow(t("counter.digits"), inputNumber(noOfChars, (v) => {
      applyCounterFieldChange(f, (next) => {
        next.noOfChars = Math.max(1, Math.round(v));
      });
    }, { step: 1, integer: true, min: 1 })));

    appendInspectorItem(wrap, "content", fieldRow(t("counter.start"), inputNumber(parseCounterNumber(counter.startVal, 1) ?? 1, (v) => {
      applyCounterFieldChange(f, (next) => {
        next.startVal = String(Math.max(0, Math.round(v)));
      });
    }, { step: 1, integer: true, min: 0, max: maxValue })));

    appendInspectorItem(wrap, "content", fieldRow(t("counter.end"), inputNumber(parseCounterNumber(counter.endVal, maxValue) ?? maxValue, (v) => {
      applyCounterFieldChange(f, (next) => {
        next.endVal = String(Math.max(0, Math.round(v)));
      });
    }, { step: 1, integer: true, min: 0, max: maxValue })));

    appendInspectorItem(wrap, "content", fieldRow(t("counter.step"), inputNumber(parseCounterNumber(counter.stepSize, 1) ?? 1, (v) => {
      applyCounterFieldChange(f, (next) => {
        next.stepSize = Math.max(1, Math.round(v));
      });
    }, { step: 1, integer: true, min: 1 })));

    const note = document.createElement("div");
    note.className = "note";
    note.textContent = t("counter.maxValue", { digits: noOfChars, value: formatCounterValue(maxValue, noOfChars) });
    appendInspectorItem(wrap, "content", note, { fullWidth: true });

    appendInspectorItem(wrap, "text", fieldRow(t("field.fontSize"), inputNumber(getEffectiveTextPitch(f, 10), (v) => {
      pushHistory();
      applyTextPitchChange(f, v);
      refreshFieldCanvasPreview(f);
    }, { step: 1, integer: true, min: 1, live: true })));

    appendInspectorItem(wrap, "text", fieldRow(t("field.xMag"), inputNumber(f.text.xMag ?? 100, (v) => {
      pushHistory();
      f.text.xMag = clamp(X_MAG_MIN, X_MAG_MAX, Math.round(v));
      if (globalThis.glyphFonts?.render) f._nativeTextGeometryDirty = true;
      refreshFieldCanvasPreview(f);
    }, { step: 1, integer: true, min: X_MAG_MIN, max: X_MAG_MAX, live: true })));

    return wrap;
  }

  if (f.fldType === "DateText" || f.fldType === "TimeText" || f.fldType === "OffsetDateText") {
    let formatInput;

    if (f.fldType === "DateText" || f.fldType === "OffsetDateText") {
      const dateTypeValue = f.fldType === "OffsetDateText" ? "calculated" : "current";
      const dateTypeSelect = createMaterialSelect([
        { value: "current", label: t("field.currentDate") },
        { value: "calculated", label: t("field.calculatedDate") }
      ], dateTypeValue, (nextValue) => {
        const nextType = nextValue === "calculated" ? "OffsetDateText" : "DateText";
        if (nextType === f.fldType) return;
        pushHistory();
        f.fldType = nextType;
        f.data.dataType = guessDataType(nextType);
        if (nextType === "OffsetDateText") ensureCalculatedDateOffset(f);
        renderAll();
      });
      appendInspectorItem(wrap, "content", fieldRow(t("field.dateType"), dateTypeSelect), { fullWidth: true });
    }

    if (f.fldType === "TimeText") {
      formatInput = selectStringOptions(getTimeFormatPreset(f.data.defaultValue || ""), TIME_TEXT_FORMATS, (v) => {
        pushHistory();
        f.data.defaultValue = buildTimeTemplateFormat(v, getTimeSeparator(f.data.defaultValue || ""));
        refreshSelectedDynamicFieldPreview();
      });
    } else {
      formatInput = selectDateFormat(
        getDateFormatPreset(f.data.defaultValue || ""),
        f.data.dateLocale || inferDateLocale(f.fldType, f.data.defaultValue, f.calcData),
        (formatValue, locale) => {
          pushHistory();
          f.data.defaultValue = buildDateTemplateFormat(formatValue, getDateSeparator(f.data.defaultValue || ""));
          f.data.dateLocale = locale;
          refreshSelectedDynamicFieldPreview();
        }
      );
    }

    appendInspectorItem(wrap, "content", fieldRow(f.fldType === "TimeText" ? t("field.timeFormat") : t("field.dateFormat"), formatInput), { fullWidth: true });

    if (f.fldType === "TimeText") {
      appendInspectorItem(wrap, "content", fieldRow(t("field.separator"), selectTimeSeparator(getTimeSeparator(f.data.defaultValue || ""), (v) => {
        pushHistory();
        f.data.defaultValue = buildTimeTemplateFormat(getTimeFormatPreset(f.data.defaultValue || ""), v);
        refreshSelectedDynamicFieldPreview();
      })), { fullWidth: true });
    }

    if (f.fldType === "DateText" || f.fldType === "OffsetDateText") {
      appendInspectorItem(wrap, "content", fieldRow(t("field.separator"), selectDateSeparator(getDateSeparator(f.data.defaultValue || ""), (v) => {
        pushHistory();
        f.data.defaultValue = buildDateTemplateFormat(getDateFormatPreset(f.data.defaultValue || ""), v);
        refreshSelectedDynamicFieldPreview();
      })), { fullWidth: true });
    }

    if (f.fldType === "OffsetDateText") {
      appendInspectorItem(wrap, "content", fieldRow(t("field.offset"), selectOffsetName(f.data.offsetRef, (v) => {
        pushHistory();
        f.data.offsetRef = v || null;
        refreshSelectedDynamicFieldPreview();
      })), { fullWidth: true });
    }
  }

  appendInspectorItem(wrap, "text", fieldRow(t("field.fontSize"), inputNumber(getEffectiveTextPitch(f, 10), (v) => {
    pushHistory();
    applyTextPitchChange(f, v);
    refreshFieldCanvasPreview(f);
  }, { step: 1, integer: true, min: 1, live: true })));

  appendInspectorItem(wrap, "text", fieldRow(t("field.xMag"), inputNumber(f.text.xMag ?? 100, (v) => {
    pushHistory();
    f.text.xMag = clamp(X_MAG_MIN, X_MAG_MAX, Math.round(v));
    if (globalThis.glyphFonts?.render) f._nativeTextGeometryDirty = true;
    refreshFieldCanvasPreview(f);
  }, { step: 1, integer: true, min: X_MAG_MIN, max: X_MAG_MAX, live: true })));

  return wrap;
}

function buildBarcodeProps(f) {
  const wrap = document.createElement("div");
  wrap.className = "form";

  appendInspectorItem(wrap, "datamatrix", fieldRow(t("datamatrix.quietMargin"), inputNumber(f.barcode.quietMargin ?? 0, (v) => {
    const nextQuietMargin = Math.max(0, Math.round(v));
    if (f.barcode.quietMargin === nextQuietMargin) return;
    pushHistory();
    f.barcode.quietMargin = nextQuietMargin;
    syncDataMatrixGeomToModuleSize(f);
    constrainCurrentFieldPositionsInternal([f]);
    renderAll();
  })));

  appendInspectorItem(wrap, "datamatrix", fieldRow(t("datamatrix.symbolSize"), selectSymbolSize(f.barcode.dataMatrix.symbolSize, (v) => {
    const nextSymbolSize = normalizeDataMatrixSymbolSizeValue(v, "22X22");
    const nextComposition = getDataMatrixFieldComposition(f, nextSymbolSize);
    if (!ensureDataMatrixCompositionCompatible(f, nextComposition)) {
      renderUI();
      return;
    }
    const historySnapshot = snapshotState();
    if (!applyDataMatrixProfileSettings(f, nextSymbolSize, { notifyOnConflict: false })) {
      renderUI();
      return;
    }
    pushHistory(false, historySnapshot);
    constrainCurrentFieldPositionsInternal([f]);
    renderAll();
  })));

  appendInspectorItem(wrap, "datamatrix", fieldRow(t("datamatrix.moduleSize"), selectDataMatrixModuleSize(f.barcode.dataMatrix.moduleSize, (v) => {
    pushHistory();
    f.barcode.dataMatrix.moduleSize = normalizeDataMatrixModuleSizeValue(v);
    syncDataMatrixGeomToModuleSize(f);
    updateDataMatrixBcHFromSettings(f);
    constrainCurrentFieldPositionsInternal([f]);
    renderAll();
  })));

  return wrap;
}

function buildDataMatrixPanel(f) {
  const dm = f.barcode.dataMatrix;
  const wrap = document.createElement("div");
  wrap.className = "dmEditor";

  const profileSection = document.createElement("section");
  profileSection.className = "dmEditor__profileSection";
  const profileTitle = document.createElement("h3");
  profileTitle.className = "dmEditor__sectionTitle";
  profileTitle.textContent = t("datamatrix.profile");
  const profileRow = document.createElement("div");
  profileRow.className = "dmEditor__profileRow";

  const profileSelect = createMaterialSelect([
    { value: "", label: t("common.none") },
    { value: "22X22", label: "22X22" },
    { value: "36X36", label: "36X36" }
  ], "", () => {});
  profileSelect.setAttribute("aria-label", t("datamatrix.profile"));
  profileRow.appendChild(profileSelect);

  const applyBtn = createPanelActionButton("md-filled-tonal-button", t("datamatrix.applyProfile"), () => {
    const p = profileSelect.value;
    if (!p) return;
    if (!ensureDataMatrixCompositionCompatible(f, getDataMatrixFieldComposition(f, p))) return;
    const historySnapshot = snapshotState();
    if (!applyDataMatrixProfileSettings(f, p, { notifyOnConflict: false })) return;
    pushHistory(false, historySnapshot);
    constrainCurrentFieldPositionsInternal([f]);
    renderAll();
  });
  profileRow.appendChild(applyBtn);
  profileSection.appendChild(profileTitle);
  profileSection.appendChild(profileRow);
  wrap.appendChild(profileSection);

  const val = validateDmProfile(f, dm.symbolSize);
  const status = document.createElement("div");
  status.className = `dmValidationStatus dmValidationStatus--${val.length ? "error" : "ok"}`;
  status.setAttribute("role", "status");
  const statusIcon = document.createElement("span");
  statusIcon.className = "dmValidationStatus__icon";
  statusIcon.setAttribute("aria-hidden", "true");
  statusIcon.textContent = val.length ? "!" : "";
  const vbody = document.createElement("div");
  vbody.className = "dmValidationStatus__message";
  vbody.textContent = val.length ? val.join("\n") : t("datamatrix.validationOk");
  status.appendChild(statusIcon);
  status.appendChild(vbody);
  wrap.appendChild(status);

  const segSection = document.createElement("section");
  segSection.className = "dmSegments";

  const segHead = document.createElement("div");
  segHead.className = "dmSegments__header";
  const segTitle = document.createElement("h3");
  segTitle.className = "dmEditor__sectionTitle";
  segTitle.textContent = t("datamatrix.segments");
  const segCount = document.createElement("span");
  segCount.className = "dmSegments__count";
  segCount.textContent = String(dm.segments.length);
  const segAddBtn = createPanelActionButton("md-filled-tonal-button", t("datamatrix.addSegment"), () => {
    pushHistory();
    dm.segments.push({ index: dm.segments.length, srcField: null, defaultValue: "", dataType: 5 });
    normalizeDmSegments(dm);
    dm.structureDirty = true;
    synchronizeDataMatrixEditorState(f);
    renderAll();
  });
  const addIcon = document.createElement("img");
  addIcon.className = "iconButton__icon";
  addIcon.src = "./resourses/Icons/add_24dp.svg";
  addIcon.alt = "";
  addIcon.setAttribute("aria-hidden", "true");
  segAddBtn.prepend(addIcon);
  segHead.appendChild(segTitle);
  segHead.appendChild(segCount);
  segHead.appendChild(segAddBtn);
  segSection.appendChild(segHead);

  const segWrap = document.createElement("div");
  segWrap.className = "dmSegments__list";

  dm.segments.forEach((s, idx) => {
    const row = document.createElement("div");
    row.className = "dmSegmentItem";
    row.innerHTML = `
      <div class="dmSegmentItem__head">
        <div class="dmSegmentItem__index">#${idx}</div>
        <div class="dmSegmentItem__actions">
          <div class="dmSegmentItem__reorder">
            <button class="btn btn--ghost dmSegmentItem__action" type="button" data-act="up">
              <img class="topbarAction__icon" src="./resourses/Icons/arrow_upward_24dp.svg" alt="" aria-hidden="true"/>
            </button>
            <button class="btn btn--ghost dmSegmentItem__action" type="button" data-act="down">
              <img class="topbarAction__icon" src="./resourses/Icons/arrow_downward_24dp.svg" alt="" aria-hidden="true"/>
            </button>
          </div>
          <button class="btn btn--danger dmSegmentItem__action" type="button" data-act="del">
            <img class="topbarAction__icon" src="./resourses/Icons/delete_24dp.svg" alt="" aria-hidden="true"/>
          </button>
        </div>
      </div>
    `;

    const grid = document.createElement("div");
    grid.className = "dmSegmentItem__grid";

    const srcSel = createMaterialSelect(
      [{ value: "", label: t("common.none") }, ...state.fields.map((ff) => ({ value: ff.name, label: ff.name }))],
      s.srcField ?? "",
      (nextValue) => {
        pushHistory();
        s.srcField = nextValue || null;
        dm.structureDirty = true;
        synchronizeDataMatrixEditorState(f);
        renderAll();
      }
    );

    const defInp = inputText(s.defaultValue || "", (nextValue) => {
      pushHistory();
      s.defaultValue = nextValue;
      synchronizeDataMatrixEditorState(f);
      refreshCanvasPreviews();
    });

    srcSel.setAttribute("aria-label", `SrcFieldName #${idx}`);
    defInp.setAttribute("aria-label", `Default #${idx}`);
    defInp.classList.add("dmSegmentItem__defaultInput");
    grid.appendChild(labeledMini("SrcFieldName", srcSel));
    grid.appendChild(labeledMini("Default", defInp));
    row.appendChild(grid);

    row.querySelectorAll("button[data-act]").forEach((b) => {
      const actionLabels = {
        up: "datamatrix.moveSegmentUp",
        down: "datamatrix.moveSegmentDown",
        del: "datamatrix.deleteSegment"
      };
      b.setAttribute("aria-label", t(actionLabels[b.dataset.act]));
      b.disabled = (b.dataset.act === "up" && idx === 0) ||
        (b.dataset.act === "down" && idx === dm.segments.length - 1);
      b.addEventListener("click", () => {
        const act = b.dataset.act;
        pushHistory();
        if (act === "del") dm.segments.splice(idx, 1);
        if (act === "up" && idx > 0) [dm.segments[idx - 1], dm.segments[idx]] = [dm.segments[idx], dm.segments[idx - 1]];
        if (act === "down" && idx < dm.segments.length - 1) [dm.segments[idx + 1], dm.segments[idx]] = [dm.segments[idx], dm.segments[idx + 1]];
        normalizeDmSegments(dm);
        dm.structureDirty = true;
        synchronizeDataMatrixEditorState(f);
        renderAll();
      });
    });

    segWrap.appendChild(row);
  });

  segSection.appendChild(segWrap);
  wrap.appendChild(segSection);

  return wrap;
}

function renderHiddenEditor() {
  const count = document.getElementById("hiddenFieldsCount");
  if (!state.xmlDoc) {
    if (count) count.textContent = "0";
    elHiddenEditor.innerHTML = "";
    return;
  }

  const hidden = state.fields.filter((f) => !f.printed);
  if (count) count.textContent = String(hidden.length);
  elHiddenEditor.innerHTML = "";

  if (hidden.length === 0) {
    const empty = document.createElement("div");
    empty.className = "muted hiddenFieldsEditor__empty";
    empty.textContent = t("hiddenFields.empty");
    elHiddenEditor.appendChild(empty);
    return;
  }

  hidden.forEach((f) => {
    const item = document.createElement("div");
    item.className = "hiddenFieldItem";

    const head = document.createElement("div");
    head.className = "hiddenFieldItem__header";
    const info = document.createElement("div");
    info.className = "hiddenFieldItem__identity";
    const title = document.createElement("div");
    title.className = "hiddenFieldItem__title";
    title.textContent = f.name;
    const meta = document.createElement("div");
    meta.className = "hiddenFieldItem__meta";
    meta.textContent = `${getFieldSubtypeLabel(f)} · Displayed=0`;
    info.appendChild(title);
    info.appendChild(meta);

    const selectBtn = createPanelActionButton("md-text-button", t("common.select"), () => {
      selectField(f.name);
      renderAll();
    });
    selectBtn.classList.add("hiddenFieldItem__select");
    selectBtn.setAttribute("aria-label", `${t("common.select")}: ${f.name}`);

    head.appendChild(info);
    head.appendChild(selectBtn);

    const inpVal = inputText(getStoredTextFieldValue(f), (nextValue) => {
      pushHistory();
      setEditableTextFieldValue(f, nextValue);
      refreshCanvasPreviews();
    });

    inpVal.setAttribute("aria-label", `${t("field.value")}: ${f.name}`);
    const value = labeledMini(t("field.value"), inpVal);
    value.classList.add("hiddenFieldItem__value");

    item.appendChild(head);
    item.appendChild(value);
    elHiddenEditor.appendChild(item);
  });
}

function beginDateOffsetsModalResize() {
  const card = elOffsetsEditor.closest(".dateOffsetsModal");
  if (!card || typeof card.animate !== "function") return () => {};

  // Start from the visible size even if the previous resize is still running.
  const previousHeight = card.getBoundingClientRect().height;
  card.getAnimations().filter((animation) => animation.id === "date-offsets-resize")
    .forEach((animation) => animation.cancel());
  if (!previousHeight || window.matchMedia("(prefers-reduced-motion: reduce)").matches) return () => {};

  return () => {
    const nextHeight = card.getBoundingClientRect().height;
    if (Math.abs(nextHeight - previousHeight) < 0.5) return;
    const animation = card.animate(
      [{ height: `${previousHeight}px` }, { height: `${nextHeight}px` }],
      { duration: 200, easing: "ease" }
    );
    animation.id = "date-offsets-resize";
  };
}

function renderOffsetsEditor() {
  const finishResize = beginDateOffsetsModalResize();
  const count = document.getElementById("dateOffsetsCount");
  if (count) count.textContent = String(state.xmlDoc ? state.dateOffsets.length : 0);
  if (!state.xmlDoc) { elOffsetsEditor.innerHTML = ""; return; }
  elOffsetsEditor.innerHTML = "";

  if (!state.dateOffsetsLoaded && state.dateOffsets.length === 0) {
    const note = document.createElement("div");
    note.className = "muted dateOffsetsEditor__empty";
    note.textContent = t("offsets.empty");
    elOffsetsEditor.appendChild(note);
    finishResize();
    return;
  }

  state.dateOffsets.forEach((o, idx) => {
    const item = document.createElement("div");
    item.className = "dateOffsetItem";

    const head = document.createElement("div");
    head.className = "dateOffsetItem__header";
    const nameInput = inputText(o.name, (value) => {
      if (value === o.name) return;
      pushHistory();
      if (!renameDateOffset(o, value)) {
        renderOffsetsEditor();
        renderSelectionPanels();
        return;
      }
      renderAll();
    });
    nameInput.classList.add("dateOffsetItem__name");
    nameInput.setAttribute("aria-label", t("offsets.name"));

    const delBtn = createPanelActionButton("md-outlined-button", "", () => {
      pushHistory();
      state.dateOffsets.splice(idx, 1);
      state.dateOffsetsDirty = true;
      renderOffsetsEditor();
      renderSelectionPanels();
      refreshCanvasPreviews();
    });
    delBtn.classList.add("btn--danger", "dateOffsetItem__delete");
    delBtn.setAttribute("aria-label", `${t("offsets.delete")}: ${o.name}`);
    const deleteIcon = document.createElement("img");
    deleteIcon.className = "iconButton__icon";
    deleteIcon.src = "./resourses/Icons/delete_24dp.svg";
    deleteIcon.alt = "";
    deleteIcon.setAttribute("aria-hidden", "true");
    delBtn.appendChild(deleteIcon);

    head.appendChild(nameInput);
    head.appendChild(delBtn);
    item.appendChild(head);

    const grid = document.createElement("div");
    grid.className = "dateOffsetItem__grid";

    const inY = mkNum(o.default.y ?? 0, (v) => {
      pushHistory();
      o.default.y = Math.round(v);
      o.current = getComputedDateOffsetCurrent(o);
      state.dateOffsetsDirty = true;
      renderOffsetsEditor();
      renderSelectionPanels();
      refreshCanvasPreviews();
    });
    const inM = mkNum(o.default.m ?? 0, (v) => {
      pushHistory();
      o.default.m = Math.round(v);
      o.current = getComputedDateOffsetCurrent(o);
      state.dateOffsetsDirty = true;
      renderOffsetsEditor();
      renderSelectionPanels();
      refreshCanvasPreviews();
    });
    const inD = mkNum(o.default.d ?? 0, (v) => {
      pushHistory();
      o.default.d = Math.round(v);
      o.current = getComputedDateOffsetCurrent(o);
      state.dateOffsetsDirty = true;
      renderOffsetsEditor();
      renderSelectionPanels();
      refreshCanvasPreviews();
    });

    grid.appendChild(labeledMini(t("offsets.year"), inY));
    grid.appendChild(labeledMini(t("offsets.month"), inM));
    grid.appendChild(labeledMini(t("offsets.day"), inD));

    item.appendChild(grid);

    const current = getComputedDateOffsetCurrent(o);
    const result = document.createElement("div");
    result.className = "dateOffsetItem__result";
    const resultLabel = document.createElement("span");
    resultLabel.className = "dateOffsetItem__resultLabel";
    resultLabel.textContent = t("offsets.calculatedDate");
    const calendarIcon = document.createElement("img");
    calendarIcon.className = "iconButton__icon";
    calendarIcon.src = "./resourses/Icons/calendar_month_24dp.svg";
    calendarIcon.alt = "";
    calendarIcon.setAttribute("aria-hidden", "true");
    resultLabel.prepend(calendarIcon);
    const resultValue = document.createElement("span");
    resultValue.className = "dateOffsetItem__resultValue";
    resultValue.textContent = `${pad2(current.d)}.${pad2(current.m)}.${String(current.y)}`;
    result.appendChild(resultLabel);
    result.appendChild(resultValue);
    item.appendChild(result);

    elOffsetsEditor.appendChild(item);
  });
  finishResize();
}

// ---------- Selection / ops ----------
function selectField(name, opts = {}) {
  const additive = !!opts.additive;
  const toggle = !!opts.toggle;

  if (!name) {
    if (!additive) setSelectedNames([]);
    renderSelectionPanels();
    renderFieldLists();
    return;
  }

  if (state.fieldByName.has(name)) activateInspectorTab("object");

  if (!additive) {
    setSelectedNames([name], name);
    renderSelectionPanels();
    renderFieldLists();
    return;
  }

  let names = getSelectedNames();
  if (toggle && names.includes(name)) names = names.filter((item) => item !== name);
  else if (!names.includes(name)) names.push(name);

  setSelectedNames(names, name);
  renderSelectionPanels();
  renderFieldLists();
}

function restoreRejectedFieldName(input, previousName, message) {
  if (!input) {
    renderSelectionPanels();
    openNotificationModal(message);
    return;
  }

  input.value = previousName;

  // Let the change event finish before moving focus into the application modal.
  window.setTimeout(() => {
    openNotificationModal(message, t("dialog.notification.title"), {
      onClose: () => {
        if (!input.isConnected) return;
        input.focus({ preventScroll: true });
        input.select();
      }
    });
  }, 0);
}

function renameField(field, nextNameRaw, input = null) {
  if (!field) return;

  const prevName = field.name;
  const nextName = (nextNameRaw ?? "").trim();

  if (!nextName) {
    restoreRejectedFieldName(input, prevName, t("dialog.fieldName.empty"));
    return;
  }
  if (nextName === prevName) return;

  const hasConflict = state.fields.some(f => f !== field && f.name === nextName);
  if (hasConflict) {
    restoreRejectedFieldName(input, prevName, t("dialog.fieldName.duplicate", { name: nextName }));
    return;
  }

  pushHistory();

  field.name = nextName;

  state.fieldByName.delete(prevName);
  state.fieldByName.set(nextName, field);

  if (state.selectedName === prevName) state.selectedName = nextName;
  if (Array.isArray(state.selectedNames)) {
    state.selectedNames = state.selectedNames.map((name) => name === prevName ? nextName : name);
  }

  state.fields.forEach(f => {
    const dm = f.barcode?.dataMatrix;
    if (!dm) return;
    dm.segments.forEach(s => {
      if (s.srcField === prevName) {
        s.srcField = nextName;
      }
    });
    synchronizeDataMatrixEditorState(f);
  });

  renderAll();
}

function getNextDateOffsetName() {
  const existing = new Set(state.dateOffsets.map((offset) => offset.name));
  let index = 0;
  while (existing.has(`offset${index}`)) index += 1;
  return `offset${index}`;
}

function createDateOffset(name = null, defaultOffset = null) {
  const nextName = name || getNextDateOffsetName();
  const offset = {
    sourceName: null,
    name: nextName,
    default: {
      y: toInt(defaultOffset?.y, 0),
      m: toInt(defaultOffset?.m, 0),
      d: toInt(defaultOffset?.d, 0)
    },
    current: getComputedDateOffsetCurrent({ default: defaultOffset || { y: 0, m: 0, d: 0 } })
  };

  state.dateOffsets.push(offset);
  state.dateOffsetsLoaded = true;
  state.dateOffsetsDirty = true;
  return offset;
}

function renameDateOffset(offset, nextNameRaw) {
  if (!offset) return false;

  const prevName = offset.name;
  const nextName = String(nextNameRaw ?? "").trim();

  if (!nextName) {
    alert("Offset name cannot be empty.");
    return false;
  }
  if (nextName === prevName) return true;

  const hasConflict = state.dateOffsets.some((item) => item !== offset && item.name === nextName);
  if (hasConflict) {
    alert(`Offset "${nextName}" already exists.`);
    return false;
  }

  offset.name = nextName;
  state.dateOffsetsDirty = true;

  state.fields.forEach((field) => {
    if (field.fldType !== "OffsetDateText") return;
    if (field.data.offsetRef === prevName) field.data.offsetRef = nextName;
  });

  return true;
}

function ensureCalculatedDateOffset(field, options = {}) {
  if (!field) return null;

  if (options.createNew) {
    const created = createDateOffset();
    field.data.offsetRef = created.name;
    return created;
  }

  const existing = state.dateOffsets.find((offset) => offset.name === field.data.offsetRef);
  if (existing) return existing;
  // Never silently bind an unresolved named reference to an unrelated offset.
  if (field.data.offsetRef) return null;

  const created = createDateOffset();
  field.data.offsetRef = created.name;
  return created;
}

function deleteSelected() {
  const names = getSelectedNames();
  if (!names.length) return;
  const removedFields = names
    .map((name) => state.fieldByName.get(name))
    .filter(Boolean)
    .map((field) => ({
      name: field.name,
      type: field.fldType,
      printed: !!field.printed,
      geometry: { ...field.geom }
    }));

  pushHistory();

  const removed = new Set(names);
  state.fields = state.fields.filter((field) => !removed.has(field.name));
  names.forEach((name) => state.fieldByName.delete(name));

  // clear references in DM segments
  state.fields.forEach((field) => {
    const dm = field.barcode?.dataMatrix;
    if (!dm) return;
    dm.segments.forEach((segment) => {
      if (removed.has(segment.srcField)) {
        segment.srcField = null;
        dm.structureDirty = true;
      }
    });
    synchronizeDataMatrixEditorState(field);
  });

  setSelectedNames([]);
  renderAll();
  appLogger.action("FIELDS_DELETED", "Выбранные поля удалены из шаблона.", {
    count: removedFields.length,
    fields: removedFields,
    remainingFieldCount: state.fields.length
  });
  appLogger.state("APPLICATION_STATE_AFTER_FIELD_DELETE", "Состояние после удаления полей.");
}

const FIELD_CATALOG = {
  GTIN: { id: "gtin", name: "GTIN", value: "00000000000000", mode: "user", maxChars: 14, printed: false },
  GTIN2: { id: "gtin2", name: "GTIN2", value: "00000000000000", mode: "user", maxChars: 14, printed: false },
  BOX_COUNTER: { id: "box_counter", name: "BOX_COUNTER", value: "00000", mode: "user", maxChars: 5, printed: false },
  KRIPTO: { id: "kripto", name: "KRIPTO", value: "0000", mode: "user", maxChars: 4, printed: false },
  KRIPTO2: { id: "kripto2", name: "KRIPTO2", value: "0".repeat(44), mode: "user", maxChars: 44, printed: false },
  SN: { id: "sn", name: "SN", values: ["000000", "0000000000000"], mode: "user", maxChars: null, printed: false },
  C1: { id: "c1", name: "C1", value: "~101", mode: "fixed", maxChars: 4, printed: false },
  C2: { id: "c2", name: "C2", value: "21", mode: "fixed", maxChars: 2, printed: false },
  C3: { id: "c3", name: "C3", values: ["~d02991", "~d02993"], mode: "fixed", maxChars: 7, printed: false },
  C4: { id: "c4", name: "C4", value: "~d02992", mode: "fixed", maxChars: 7, printed: false },
  PRODUCT_DATE: { id: "product_date", name: "PRODUCT_DATE", value: "0000000000", mode: "user", maxChars: null, printed: true },
  PACKING_DATE: { id: "packing_date", name: "PACKING_DATE", value: "0000000000", mode: "user", maxChars: null, printed: true },
  EXPIRATION_DATE: { id: "expiration_date", name: "EXPIRATION_DATE", value: "0000000000", mode: "user", maxChars: null, printed: true },
  PARTY: { id: "party", name: "PARTY", value: "00000000", mode: "user", maxChars: null, printed: true },
  R_NUM: { id: "r_num", name: "R_NUM", value: "000", mode: "user", maxChars: null, printed: true },
  TEAM: { id: "team", name: "TEAM", value: "00", mode: "user", maxChars: null, printed: true },
  TIME: { id: "time", name: "TIME", value: "", mode: "printer-time", maxChars: null, printed: true }
};
const TEXT_FIELD_PRESETS = Object.values(FIELD_CATALOG).filter((preset) => preset.id !== "time");

function getTextFieldPresetCheckboxes() {
  if (!elTextFieldModal) return [];
  return Array.from(elTextFieldModal.querySelectorAll("[data-text-preset]"));
}

function getTextFieldPresetValueControl(presetId) {
  return elTextFieldModal?.querySelector(`[data-text-preset-value="${presetId}"]`) ?? null;
}

function getSelectedTextFieldPresets() {
  return getTextFieldPresetCheckboxes()
    .filter((checkbox) => checkbox.checked && !checkbox.disabled)
    .map((checkbox) => TEXT_FIELD_PRESETS.find((preset) => preset.id === checkbox.dataset.textPreset))
    .filter(Boolean);
}

function setTextFieldPresetError(message = "") {
  if (elTextFieldPresetError) elTextFieldPresetError.textContent = message;
}

function syncTextFieldModalControls() {
  if (!elTextFieldModal) return;
  const presetMode = !!elTextFieldModePresets?.checked;
  elTextFieldPresetList?.classList.toggle("is-inactive", !presetMode);

  TEXT_FIELD_PRESETS.forEach((preset) => {
    const checkbox = elTextFieldModal.querySelector(`[data-text-preset="${preset.id}"]`);
    const row = elTextFieldModal.querySelector(`[data-text-preset-row="${preset.id}"]`);
    const status = elTextFieldModal.querySelector(`[data-text-preset-status="${preset.id}"]`);
    const alreadyExists = state.fieldByName.has(preset.name);

    if (checkbox) {
      checkbox.disabled = alreadyExists;
      if (alreadyExists) checkbox.checked = false;
    }
    row?.classList.toggle("is-disabled", alreadyExists);
    if (status) status.textContent = alreadyExists ? t("dialog.textField.alreadyExists") : "";

    const valueControl = getTextFieldPresetValueControl(preset.id);
    if (valueControl) {
      valueControl.disabled = alreadyExists || !presetMode || !checkbox?.checked;
      if (typeof syncCustomSelectControl === "function") syncCustomSelectControl(valueControl);
    }
  });

  if (!presetMode) {
    setTextFieldPresetError();
    if (elBtnConfirmTextField) elBtnConfirmTextField.disabled = false;
    return;
  }

  const selected = getSelectedTextFieldPresets();
  if (!selected.length) {
    setTextFieldPresetError(t("dialog.textField.selectionRequired"));
    if (elBtnConfirmTextField) elBtnConfirmTextField.disabled = true;
    return;
  }

  const missingVariant = selected.find((preset) => preset.values && !getTextFieldPresetValueControl(preset.id)?.value);
  if (missingVariant) {
    setTextFieldPresetError(t("dialog.textField.variantRequired", { name: missingVariant.name }));
    if (elBtnConfirmTextField) elBtnConfirmTextField.disabled = true;
    return;
  }

  setTextFieldPresetError();
  if (elBtnConfirmTextField) elBtnConfirmTextField.disabled = false;
}

function openTextFieldModal() {
  if (!state.xmlDoc) {
    openNotificationModal(t("dialog.notification.openFileFirst"));
    return;
  }
  if (!elTextFieldModal) return;
  clearPendingCanvasPlacement();

  if (elTextFieldModeFixed) elTextFieldModeFixed.checked = true;
  if (elTextFieldModePresets) elTextFieldModePresets.checked = false;
  getTextFieldPresetCheckboxes().forEach((checkbox) => {
    checkbox.checked = false;
  });
  TEXT_FIELD_PRESETS.forEach((preset) => {
    const valueControl = getTextFieldPresetValueControl(preset.id);
    if (valueControl) valueControl.value = "";
  });

  syncTextFieldModalControls();
  elTextFieldModal.classList.remove("hidden");
  elTextFieldModal.setAttribute("aria-hidden", "false");
  document.body.classList.add("modal-open");
  window.setTimeout(() => elTextFieldModeFixed?.focus(), 0);
}

function closeTextFieldModal() {
  if (!elTextFieldModal) return;
  elTextFieldModal.classList.add("hidden");
  elTextFieldModal.setAttribute("aria-hidden", "true");
  document.body.classList.remove("modal-open");
  setTextFieldPresetError();
}

function resolveTextFieldPresetValue(preset) {
  if (!preset?.values) return String(preset?.value ?? "");
  return String(getTextFieldPresetValueControl(preset.id)?.value ?? "");
}

function createBaseField(config = {}) {
  const fldType = config.fldType || "FixedText";
  const pitch = normalizeTextPitchValue(config.pitch) ?? 10;
  const defaultValue = String(config.value ?? "");
  const defaultGeom = {
    x: mmToInternal(2),
    y: mmToInternal(2),
    w: getClarisoftTextFieldWidthInternal(defaultValue, pitch, config.xMag),
    h: getClarisoftTextFieldHeightInternal(pitch)
  };
  return {
    sourceName: null,
    name: config.name || "Field",
    fldType,
    printed: config.printed !== false,
    geom: config.geom ? { ...config.geom } : defaultGeom,
    ln: config.ln ?? null,
    orientation: 0,
    calcData: defaultValue,
    data: {
      dataType: config.dataType ?? guessDataType(fldType),
      defaultValue,
      maxChars: config.maxChars ?? null,
      // ClariSoft fixtures distinguish user-entered fixed-length data from
      // static text that merely has MaxNoOfChars. Never infer FixedLen from
      // MaxNoOfChars alone.
      fixedLen: config.fixedLen ?? (!!config.userEntered && config.maxChars != null),
      staticAttr: config.staticAttr !== undefined ? config.staticAttr : (fldType === "FixedText" ? null : "0"),
      parseAttr: config.parseAttr !== undefined ? config.parseAttr : (["DateText", "TimeText", "OffsetDateText"].includes(fldType) ? "1" : null),
      referenceAttr: config.referenceAttr !== undefined ? config.referenceAttr : "",
      srcData: config.srcData ? { ...config.srcData } : null,
      hasVarText: !!config.userEntered,
      textEntryMode: fldType === "FixedText" ? (config.userEntered ? "user" : "fixed") : null,
      userEnterData: config.userEntered ? defaultValue : "",
      mask: "",
      offsetRef: config.offsetRef || null,
      dateLocale: config.dateLocale ?? (["DateText", "OffsetDateText"].includes(fldType) ? "en" : null),
      counter: { noOfChars: null, significance: 0, startVal: null, endVal: null, stepSize: null, clrStCntType: "" }
    },
    text: { pitch, xMag: config.xMag ?? null },
    barcode: config.barcode || null,
    ...(globalThis.glyphFonts?.render && fldType !== 'Barcode' ? { _nativeTextGeometryDirty: true } : {}),
    _konva: null
  };
}

function createFixedTextField(config = {}) {
  return createBaseField({ ...config, fldType: "FixedText", userEntered: false });
}

function createServerVariableField(config = {}) {
  return createBaseField({ ...config, fldType: "FixedText", userEntered: true, staticAttr: "0" });
}

function createPrinterInputField(config = {}) {
  return createServerVariableField(config);
}

function createCurrentDateField(config = {}) {
  return createBaseField({ ...config, fldType: "DateText", value: buildDateTemplateFormat(config.format || "dd/MM/yy", config.separator ?? "."), dateLocale: config.locale || "en" });
}

function createOffsetDateField(config = {}, offsetName) {
  return createBaseField({ ...config, fldType: "OffsetDateText", value: buildDateTemplateFormat(config.format || "dd/MM/yy", config.separator ?? "."), dateLocale: config.locale || "en", offsetRef: offsetName });
}

function createCurrentTimeField(config = {}) {
  return createBaseField({ ...config, fldType: "TimeText", value: buildTimeTemplateFormat(config.format || "HH:mm", config.separator ?? ":") });
}

function createTextFieldFromPreset(preset, value, stackIndex, position = null) {
  const isUserEntered = preset.mode === "user";
  const maxChars = getDataMatrixHelperMaxChars(preset.name, value) ?? preset.maxChars ?? null;
  const pitch = 10;
  const geom = {
    x: position?.x ?? mmToInternal(2),
    y: (position?.y ?? mmToInternal(2)) + mmToInternal(stackIndex * 5),
    w: getClarisoftTextFieldWidthInternal(value, pitch),
    h: getClarisoftTextFieldHeightInternal(pitch)
  };
  const field = (isUserEntered ? createServerVariableField : createFixedTextField)({
    name: preset.name, value, printed: preset.printed, maxChars, pitch, geom
  });
  applyNewFieldPlacementToGeom(field.geom, { x: geom.x, y: geom.y }, field);
  return field;
}

function addSelectedTextFieldPresets() {
  const selected = getSelectedTextFieldPresets();
  if (!selected.length) {
    syncTextFieldModalControls();
    return false;
  }

  const resolved = selected.map((preset) => ({ preset, value: resolveTextFieldPresetValue(preset) }));
  const missingVariant = resolved.find(({ preset, value }) => preset.values && !value);
  if (missingVariant) {
    syncTextFieldModalControls();
    return false;
  }

  const creatable = resolved.filter(({ preset }) => !state.fieldByName.has(preset.name));
  if (!creatable.length) {
    syncTextFieldModalControls();
    return false;
  }

  closeTextFieldModal();
  beginCanvasPlacement({
    kind: "textPresets",
    resolved,
    toolButtonId: "addFixedText"
  });
  return true;
}

function addResolvedTextFieldPresetsAt(resolved, position) {
  const creatable = (resolved || []).filter(({ preset }) => !state.fieldByName.has(preset.name));
  if (!creatable.length) return false;

  const stackHeight = mmToInternal(4 + Math.max(0, creatable.length - 1) * 5);
  const stackPosition = {
    x: position.x,
    y: Math.max(0, Math.min(getCanvasInternalHeight() - stackHeight, position.y))
  };
  pushHistory();
  const createdFields = creatable.map(({ preset, value }, index) => (
    createTextFieldFromPreset(preset, value, index, stackPosition)
  ));
  createdFields.forEach((field) => {
    state.fields.push(field);
    state.fieldByName.set(field.name, field);
  });

  const createdNames = createdFields.map((field) => field.name);
  setSelectedNames(createdNames, createdNames[createdNames.length - 1]);
  if (createdNames.length) activateInspectorTab("object");
  renderAll();
  appLogger.action("TEXT_PRESET_FIELDS_ADDED", "Группа готовых текстовых полей добавлена в шаблон.", {
    count: createdFields.length,
    fields: createdFields.map((field) => ({
      name: field.name,
      type: field.fldType,
      printed: !!field.printed,
      geometry: { ...field.geom }
    }))
  });
  appLogger.state("APPLICATION_STATE_AFTER_FIELDS_ADDED", "Состояние после добавления готовых текстовых полей.");
  return true;
}

function confirmTextFieldModal() {
  if (elTextFieldModeFixed?.checked) {
    closeTextFieldModal();
    beginCanvasPlacement({
      kind: "field",
      fldType: "FixedText",
      toolButtonId: "addFixedText"
    });
    return;
  }
  addSelectedTextFieldPresets();
}

function isLargeDataMatrixSymbolSize(symbolSize) {
  return getDataMatrixComposition(symbolSize) === "long";
}

function setDataMatrixModalError(message = "") {
  if (elDataMatrixModalError) elDataMatrixModalError.textContent = message;
}

function syncDataMatrixModalControls() {
  if (!elDataMatrixModal) return;
  const symbolSize = elNewDataMatrixSymbolSize?.value ?? "";
  const snValue = elNewDataMatrixSnValue?.value ?? "";
  const snLength = String(snValue) === "0000000000000" ? "13" : "6";
  elDataMatrixModal.querySelectorAll("[data-dm-sn-length]").forEach((button) => {
    const isActive = button.dataset.dmSnLength === snLength;
    button.classList.toggle("fieldFilter__button--active", isActive);
    button.setAttribute("aria-pressed", String(isActive));
  });
  if (elBtnConfirmDataMatrix) elBtnConfirmDataMatrix.disabled = !symbolSize || !snValue;
  setDataMatrixModalError();
}

function openDataMatrixModal() {
  if (!state.xmlDoc) {
    openNotificationModal(t("dialog.notification.openFileFirst"));
    return;
  }
  if (!elDataMatrixModal) return;
  clearPendingCanvasPlacement();

  if (elNewDataMatrixSymbolSize) {
    elNewDataMatrixSymbolSize.value = "";
    syncCustomSelectControl(elNewDataMatrixSymbolSize);
  }
  if (elNewDataMatrixSnValue) {
    elNewDataMatrixSnValue.value = "000000";
  }
  syncDataMatrixModalControls();
  elDataMatrixModal.classList.remove("hidden");
  elDataMatrixModal.setAttribute("aria-hidden", "false");
  document.body.classList.add("modal-open");
  window.setTimeout(() => elNewDataMatrixSymbolSize?._customSelectButton?.focus(), 0);
}

function closeDataMatrixModal() {
  if (!elDataMatrixModal) return;
  elDataMatrixModal.classList.add("hidden");
  elDataMatrixModal.setAttribute("aria-hidden", "true");
  document.body.classList.remove("modal-open");
  setDataMatrixModalError();
}

function confirmDataMatrixModal() {
  const symbolSize = elNewDataMatrixSymbolSize?.value ?? "";
  const snValue = elNewDataMatrixSnValue?.value ?? "";
  if (!symbolSize || !snValue) {
    setDataMatrixModalError(t("dialog.dataMatrix.selectionRequired"));
    return;
  }

  closeDataMatrixModal();
  beginCanvasPlacement({
    kind: "field",
    fldType: "Barcode",
    options: { symbolSize, snValue },
    toolButtonId: "addDataMatrix"
  });
}

function configureDataMatrixUserField(name, fallbackValue, maxChars, options = {}) {
  ensureFieldExists(name, null);
  const field = state.fieldByName.get(name);
  if (!field) return null;
  const spec = DM_HELPER_SPECS[name] || null;

  const currentValue = getStoredTextFieldValue(field);
  const nextValue = options.forceValue || !currentValue ? String(fallbackValue) : currentValue;
  field.printed = false;
  field.fldType = "FixedText";
  field.calcData = nextValue;
  field.data.dataType = 0;
  field.data.defaultValue = nextValue;
  const partyHelper = state.fields.some((candidate) => (
    getDataMatrixFieldComposition(candidate).startsWith("party")
    && candidate.barcode?.dataMatrix?.segments?.some((segment) => segment.srcField === name)
  ));
  if (field.sourceName == null && !partyHelper) field.data.maxChars = getDataMatrixHelperMaxChars(name, nextValue);
  field.data.editorMaxChars = maxChars ?? spec?.editorMaxChars ?? null;
  field.data.fixedLen = field.data.maxChars != null;
  field.data.staticAttr = "0";
  field.data.parseAttr = null;
  field.data.hasVarText = true;
  field.data.textEntryMode = "user";
  field.data.userEnterData = nextValue;
  field.data.mask = "";
  synchronizeDependentDataMatrices(name);
  return field;
}

function applyNewFieldPlacementToGeom(geom, position, field = null) {
  if (!geom || !position) return geom;

  let x = Number(position.x);
  let y = Number(position.y);
  if (!Number.isFinite(x) || !Number.isFinite(y)) return geom;

  if (elToggleSnap?.checked) {
    const snapStep = Math.max(1, mmToInternal(SNAP_MM));
    x = Math.round(x / snapStep) * snapStep;
    y = Math.round(y / snapStep) * snapStep;
  }

  if (field) {
    const constrained = constrainFieldPositionInternal(field, x, y);
    geom.x = constrained.x;
    geom.y = constrained.y;
    return geom;
  }

  const maxX = Math.max(0, getCanvasInternalWidth() - geom.w);
  const maxY = Math.max(0, getCanvasInternalHeight() - geom.h);
  geom.x = Math.max(0, Math.min(maxX, x));
  geom.y = Math.max(0, Math.min(maxY, y));
  return geom;
}

function commitCanvasPlacement(request, position) {
  if (!request || !position) return false;
  if (request.kind === "field") {
    addField(request.fldType, { ...(request.options || {}), position });
    return true;
  }
  if (request.kind === "textPresets") {
    return addResolvedTextFieldPresetsAt(request.resolved, position);
  }
  return false;
}

function addField(fldType, options = {}) {
  if (!state.xmlDoc) {
    openNotificationModal(t("dialog.notification.openFileFirst"));
    return;
  }

  if (fldType === "Barcode") {
    const requestedSymbolSize = normalizeDataMatrixSymbolSizeValue(options.symbolSize, "22X22");
    if (!ensureDataMatrixCompositionCompatible(null, getDataMatrixComposition(requestedSymbolSize))) return;
  }

  pushHistory();

  const existingNames = state.fields.map(f => f.name);
  const name = getNextClarisoftFieldName(existingNames);
  const insertionIndex = state.fields.length;

  const geom = { x: mmToInternal(2), y: mmToInternal(2), w: mmToInternal(12), h: mmToInternal(4) };
  if (fldType === "Barcode") { geom.w = mmToInternal(12); geom.h = mmToInternal(12); }

  const field = createBaseField({ name, fldType, geom, ln: fldType === "Barcode" ? 1 : null });
  if (fldType === "CounterText") {
    field.data.counter = { noOfChars: 4, significance: 0, startVal: "1", endVal: "9999", stepSize: 1, clrStCntType: "" };
  }

  if (fldType === "FixedText") { field.calcData = "TEXT"; field.data.defaultValue = "TEXT"; }
  if (fldType === "DateText") { field.data.defaultValue = buildDateTemplateFormat("dd/MM/yy", "."); }
  if (fldType === "OffsetDateText") {
    field.data.defaultValue = buildDateTemplateFormat("dd/MM/yy", ".");
    ensureCalculatedDateOffset(field, { createNew: true });
  }
  if (fldType === "TimeText") { field.data.defaultValue = buildTimeTemplateFormat("HH:mm", ":"); }
  if (fldType === "CounterText") normalizeCounterField(field, { preserveCurrent: false });

  if (fldType === "Barcode") {
    const symbolSize = normalizeDataMatrixSymbolSizeValue(options.symbolSize, "22X22");
    const snValue = options.snValue === "0000000000000" ? "0000000000000" : "000000";
    const composition = getDataMatrixComposition(symbolSize);
    field.barcode = {
      clsid: "{7A4AA4CF-F5CD-11D4-8DAE-0050DAFE8A9F}",
      quietMargin: 0,
      bcH: null,
      dataMatrix: { moduleSize: 0.50, symbolSize, segments: [], structureDirty: true }
    };
    if (!applyDmComposition(field, composition, {
      purgeDisallowedFields: false,
      notifyOnConflict: false
    })) {
      history.undo.pop();
      updateUndoRedoButtons();
      return;
    }
    field.barcode.dataMatrix.symbolSize = symbolSize;

    configureDataMatrixUserField("GTIN", "0".repeat(14), 14);
    configureDataMatrixUserField("SN", snValue, snValue.length, { forceValue: true });
    configureDataMatrixUserField("KRIPTO", "0".repeat(4), 4);
    if (composition === "long") configureDataMatrixUserField("KRIPTO2", "0".repeat(44), 44);

    synchronizeDataMatrixEditorState(field);
    syncDataMatrixGeomToModuleSize(field);
    updateDataMatrixBcHFromSettings(field);
  }

  applyNewFieldPlacementToGeom(field.geom, options.position, field);
  state.fields.splice(insertionIndex, 0, field);
  state.fieldByName.set(field.name, field);
  if (field.barcode?.dataMatrix) synchronizeDataMatrixEditorState(field);

  selectField(field.name);
  renderAll();
  appLogger.action("FIELD_ADDED", "Новое поле добавлено в шаблон.", {
    field: {
      name: field.name,
      type: field.fldType,
      printed: !!field.printed,
      geometryInternal: { ...field.geom },
      geometryMillimeters: {
        x: Number(internalToMm(field.geom.x).toFixed(2)),
        y: Number(internalToMm(field.geom.y).toFixed(2)),
        width: Number(internalToMm(field.geom.w).toFixed(2)),
        height: Number(internalToMm(field.geom.h).toFixed(2))
      },
      orientation: field.orientation,
      dataMatrix: field.barcode?.dataMatrix ? {
        symbolSize: field.barcode.dataMatrix.symbolSize,
        moduleSize: field.barcode.dataMatrix.moduleSize,
        segmentSources: field.barcode.dataMatrix.segments.map((segment) => segment.srcField)
      } : null
    },
    requestedPosition: options.position || null,
    totalFieldCount: state.fields.length
  });
  appLogger.state("APPLICATION_STATE_AFTER_FIELD_ADDED", "Состояние после добавления поля.", {
    fieldName: field.name
  });
}

// ---------- DM profile apply/validate ----------
function applyDmProfile(dmField, profileName, options = {}) {
  const symbolSize = normalizeDataMatrixSymbolSizeValue(profileName, dmField?.barcode?.dataMatrix?.symbolSize || "22X22");
  const composition = getDataMatrixFieldComposition(dmField, symbolSize);
  if (composition === "party" || composition === "party-box") {
    if (!ensureDataMatrixCompositionCompatible(dmField, composition, options)) return false;
    // Symbol size is independent of a batch-code recipe. Preserve imported
    // helpers, order, lengths and legacy C5 references rather than rebuilding.
    dmField.barcode.dataMatrix.symbolSize = symbolSize;
    return true;
  }
  if (!applyDmComposition(dmField, composition, options)) return false;
  if (dmField?.barcode?.dataMatrix) dmField.barcode.dataMatrix.symbolSize = symbolSize;
  return true;
}

function applyDataMatrixProfileSettings(dmField, profileName, options = {}) {
  if (!applyDmProfile(dmField, profileName, options)) return false;
  syncDataMatrixGeomToModuleSize(dmField);
  updateDataMatrixBcHFromSettings(dmField);
  return true;
}

function applyDmComposition(dmField, compositionName, options = {}) {
  let profile = DM_COMPOSITIONS[compositionName];
  if (!profile) return false;
  const dm = dmField.barcode?.dataMatrix;
  if (!dm) return false;
  if (["party", "party-box"].includes(compositionName) && dm.segments.some((segment) => segment.srcField === "GTIN") && !dm.segments.some((segment) => segment.srcField === "GTIN2")) {
    profile = getPartyCodeComposition(compositionName === "party-box", "GTIN");
  }
  const actualSymbolSize = dm.symbolSize;

  // Canonical short and long recipes share helper names, but C3 has a
  // different fixed value. Allowing both compositions to mutate the same
  // helper bundle would silently invalidate whichever DataMatrix was updated
  // first. Until CIFF evidence defines a canonical per-barcode helper naming
  // scheme, reject that ambiguous edit before touching any shared state.
  if (!ensureDataMatrixCompositionCompatible(dmField, compositionName, options)) return false;

  const namesBefore = new Set(state.fields.map((field) => field.name));
  const reusableLegacyNames = new Set(profile.requiredSegments.filter((canonicalName) => {
    const legacyName = DM_LEGACY_HELPER_ALIASES[canonicalName];
    return legacyName && !state.fieldByName.has(canonicalName) && state.fieldByName.has(legacyName);
  }));
  const unavailableNames = profile.requiredSegments.filter((fname) => {
    if (reusableLegacyNames.has(fname)) return false;
    return !ensureFieldExists(fname, profile.fixedFields?.[fname] ?? null, { spec: profile.helperSpecs?.[fname] });
  });
  if (unavailableNames.length) {
    const newlyCreatedNames = state.fields
      .filter((field) => !namesBefore.has(field.name))
      .map((field) => field.name);
    purgeFieldsFromTemplate(newlyCreatedNames);
    openNotificationModal(
      t("dialog.hiddenFieldSpace.message", { names: unavailableNames.join(", ") }),
      t("dialog.hiddenFieldSpace.title")
    );
    return false;
  }

  // Perform legacy alias migration only after every other required helper has
  // been allocated successfully. A SrcFieldName-only rename can be patched
  // non-invasively, so unrelated imported DataMatrix blocks stay lossless.
  if (reusableLegacyNames.size) migrateLegacyDataMatrixHelperNames(profile);

  if (profile.disallowedFields?.length) {
    dm.segments = dm.segments.filter(s => !profile.disallowedFields.includes(s.srcField));
    if (options.purgeDisallowedFields !== false) {
      const referencedByOtherDataMatrices = new Set();
      state.fields.forEach((field) => {
        if (field === dmField) return;
        field.barcode?.dataMatrix?.segments?.forEach((segment) => {
          if (segment.srcField) referencedByOtherDataMatrices.add(segment.srcField);
        });
      });
      purgeFieldsFromTemplate(
        profile.disallowedFields.filter((name) => !referencedByOtherDataMatrices.has(name))
      );
    }
  }

  const newSegs = [];
  profile.requiredSegments.forEach((fname, idx) => {
    const existing = dm.segments.find(s => s.srcField === fname);
    newSegs.push(existing ? { ...existing } : {
      index: idx,
      srcField: fname,
      defaultValue: state.fieldByName.get(fname)?.data.defaultValue ?? "",
      dataType: 5
    });
  });

  dm.segments = newSegs;
  normalizeDmSegments(dm);
  dm.structureDirty = true;

  if (profile.fixedFields) {
    Object.entries(profile.fixedFields).forEach(([fname, value]) => {
      const f = state.fieldByName.get(fname);
      if (!f) return;
      f.printed = false;
      f.fldType = "FixedText";
      f.data.dataType = 0;
      f.data.defaultValue = value;
      f.data.hasVarText = false;
      f.data.textEntryMode = "fixed";
      f.data.staticAttr = null;
      f.data.userEnterData = "";
      f.data.mask = "";
      f.calcData = value;
    });
  }
  dm.symbolSize = actualSymbolSize;
  synchronizeDataMatrixEditorState(dmField);
  return true;
}

function getConflictingDataMatrixFields(dmField, compositionName) {
  return state.fields.filter((field) => {
    if (field === dmField || !field?.barcode?.dataMatrix) return false;
    const otherComposition = getDataMatrixFieldComposition(field);
    if (["party", "party-box"].includes(otherComposition) && ["party", "party-box"].includes(compositionName)) return false;
    return otherComposition !== compositionName;
  });
}

function ensureDataMatrixCompositionCompatible(dmField, compositionName, options = {}) {
  const conflictingDataMatrices = getConflictingDataMatrixFields(dmField, compositionName);
  if (conflictingDataMatrices.length) {
    if (options.notifyOnConflict !== false) {
      openNotificationModal(
        t("dialog.dataMatrix.compositionConflictMessage", {
          names: conflictingDataMatrices.map((field) => field.name).join(", ")
        }),
        t("dialog.dataMatrix.compositionConflictTitle")
      );
    }
    return false;
  }
  return true;
}

function migrateLegacyDataMatrixHelperNames(profile) {
  const aliasesToMigrate = profile?.requiredSegments
    ?.map((canonicalName) => ({ canonicalName, legacyName: DM_LEGACY_HELPER_ALIASES[canonicalName] }))
    .filter(({ canonicalName, legacyName }) => (
      legacyName && !state.fieldByName.has(canonicalName) && state.fieldByName.has(legacyName)
    )) ?? [];
  if (!aliasesToMigrate.length) return false;

  const aliasMap = new Map(aliasesToMigrate.map(({ legacyName, canonicalName }) => [legacyName, canonicalName]));
  aliasesToMigrate.forEach(({ legacyName, canonicalName }) => {
    const legacyField = state.fieldByName.get(legacyName);
    legacyField.name = canonicalName;
    state.fieldByName.delete(legacyName);
    state.fieldByName.set(canonicalName, legacyField);
  });
  if (aliasMap.has(state.selectedName)) state.selectedName = aliasMap.get(state.selectedName);
  if (Array.isArray(state.selectedNames)) {
    state.selectedNames = state.selectedNames.map((name) => aliasMap.get(name) ?? name);
  }

  state.fields.forEach((field) => {
    const dataMatrix = field.barcode?.dataMatrix;
    if (!dataMatrix) return;
    let changed = false;
    dataMatrix.segments.forEach((segment) => {
      const canonicalName = aliasMap.get(segment.srcField);
      if (!canonicalName) return;
      segment.srcField = canonicalName;
      changed = true;
    });
    if (changed) synchronizeDataMatrixEditorState(field);
  });
  return true;
}

function validateDmProfile(dmField, symbolSize) {
  const composition = getDataMatrixFieldComposition(dmField, symbolSize);
  let p = DM_COMPOSITIONS[composition];
  if (!p) return [];
  const dm = dmField.barcode?.dataMatrix;
  if (!dm) return ["No DataMatrix node."];
  if (["party", "party-box"].includes(composition) && dm.segments.some((segment) => segment.srcField === "GTIN") && !dm.segments.some((segment) => segment.srcField === "GTIN2")) {
    p = getPartyCodeComposition(composition === "party-box", "GTIN");
  }
  if (composition === "party-box" && !dm.segments.some((segment) => segment.srcField === "C4") && dm.segments.some((segment) => segment.srcField === "C5")) {
    // The user-provided original calls the barcode C4 and its final helper C5.
    // Accept that reference in place without renaming the imported document.
    p = { ...p, requiredSegments: p.requiredSegments.map((name) => name === "C4" ? "C5" : name),
      fixedFields: Object.fromEntries(Object.entries(p.fixedFields).map(([name, value]) => [name === "C4" ? "C5" : name, value])) };
  }

  const errors = [];
  for (const s of p.requiredSegments) if (!dm.segments.find(x => x.srcField === s)) errors.push(`Missing segment SrcFieldName="${s}"`);
  if (p.disallowedFields) for (const s of p.disallowedFields) if (dm.segments.find(x => x.srcField === s)) errors.push(`Disallowed segment "${s}" for ${symbolSize}`);
  if (p.fixedFields) {
    for (const [fname, value] of Object.entries(p.fixedFields)) {
      const f = state.fieldByName.get(fname);
      if (!f) { errors.push(`Missing fixed field "${fname}"`); continue; }
      if ((f.data.defaultValue ?? "") !== value) errors.push(`Field "${fname}" must be "${value}", got "${f.data.defaultValue ?? ""}"`);
  }
}
  validateDataMatrixDerivedState(dmField, state.fieldByName).forEach((issue) => {
    if (issue.code === "missing-source") errors.push(`Missing segment SrcFieldName="${issue.sourceName}"`);
    if (issue.code === "segment-default") errors.push(`Segment "${issue.sourceName}" Default must be "${issue.expected}", got "${issue.actual}"`);
    if (issue.code === "segment-index") errors.push(`Segment #${issue.index} has Index="${issue.actual}", expected "${issue.expected}"`);
    if (issue.code === "calc-data") errors.push(`DataMatrix CalcData must be "${issue.expected}", got "${issue.actual}"`);
  });
  return errors;
}

function purgeFieldsFromTemplate(names) {
  const namesToRemove = [...new Set((names || []).filter((name) => (
    !!name && state.fieldByName.has(name)
  )))];
  if (!namesToRemove.length) return;

  const removed = new Set(namesToRemove);
  state.fields = state.fields.filter(f => !removed.has(f.name));
  namesToRemove.forEach(name => state.fieldByName.delete(name));

  state.fields.forEach(f => {
    const dm = f.barcode?.dataMatrix;
    if (!dm) return;
    const retainedSegments = dm.segments.filter(s => !removed.has(s.srcField));
    if (retainedSegments.length === dm.segments.length) return;
    dm.segments = retainedSegments;
    normalizeDmSegments(dm);
    dm.structureDirty = true;
    synchronizeDataMatrixEditorState(f);
  });

  if (state.selectedName && removed.has(state.selectedName)) state.selectedName = null;
  if (Array.isArray(state.selectedNames)) {
    state.selectedNames = state.selectedNames.filter((name) => !removed.has(name));
  }
  setSelectedNames(state.selectedNames, state.selectedName);
}

function getAutoHiddenFieldGeom(field = null) {
  const fallbackGeom = { x: 0, y: 0, w: mmToInternal(10), h: getClarisoftTextFieldHeightInternal(10) };
  const candidate = field || {
    name: "__AUTO_HIDDEN__",
    fldType: "FixedText",
    printed: false,
    orientation: 0,
    geom: fallbackGeom,
    calcData: "",
    data: { defaultValue: "", userEnterData: "", textEntryMode: "fixed" },
    text: { pitch: 10, xMag: null },
    barcode: null,
    _konva: null
  };
  if (typeof findHiddenFieldEditingPlacementInternal !== "function") return null;
  return findHiddenFieldEditingPlacementInternal(candidate, state.fields, {
    canvasWidth: getCanvasInternalWidth()
  });
}

function ensureFieldExists(name, fixedValueOrNull, options = {}) {
  if (state.fieldByName.has(name)) return true;

  const spec = options.spec || DM_HELPER_SPECS[name] || FIELD_CATALOG[name] || { mode: fixedValueOrNull == null ? "user" : "fixed", defaultValue: "", maxChars: null, pitch: 10 };
  const autoValue = String(fixedValueOrNull ?? spec.defaultValue ?? spec.value ?? "");
  const pitch = spec.pitch ?? 10;
  const geom = {
    x: 0,
    y: 0,
    w: getClarisoftTextFieldWidthInternal(autoValue, pitch),
    h: getClarisoftTextFieldHeightInternal(pitch)
  };
  const factory = spec.mode === "user" ? createServerVariableField : createFixedTextField;
  const f = factory({
    name,
    ln: 1, // Established DataMatrix helper recipe; generic text keeps Ln optional.
    value: autoValue,
    printed: false,
    maxChars: options.spec?.maxChars ?? getDataMatrixHelperMaxChars(name, autoValue) ?? spec.maxChars ?? null,
    pitch,
    xMag: null,
    geom
  });
  f.data.editorMaxChars = spec.editorMaxChars ?? null;

  const placementGeom = getAutoHiddenFieldGeom(f);
  if (!placementGeom) {
    const errorCode = `hidden-field-space:${name}`;
    state.validation = {
      ...(state.validation || {}),
      invalidPrintableFieldNames: state.validation?.invalidPrintableFieldNames || [],
      invalidHardwareFieldNames: state.validation?.invalidHardwareFieldNames || [],
      structuralErrors: [...new Set([...(state.validation?.structuralErrors || []), errorCode])]
    };
    return false;
  }
  f.geom = placementGeom;
  if (state.validation?.structuralErrors) {
    state.validation.structuralErrors = state.validation.structuralErrors
      .filter((error) => error !== `hidden-field-space:${name}`);
  }

  state.fields.push(f);
  state.fieldByName.set(name, f);
  return true;
}

function normalizeDmSegments(dm) {
  dm.segments = dm.segments.filter(Boolean);
  dm.segments.forEach((s, i) => s.index = i);
}

globalThis.FIELD_CATALOG = FIELD_CATALOG;
globalThis.createBaseField = createBaseField;
globalThis.createFixedTextField = createFixedTextField;
globalThis.createServerVariableField = createServerVariableField;
globalThis.createPrinterInputField = createPrinterInputField;
globalThis.createCurrentDateField = createCurrentDateField;
globalThis.createOffsetDateField = createOffsetDateField;
globalThis.createCurrentTimeField = createCurrentTimeField;
globalThis.applyTextPitchChange = applyTextPitchChange;
globalThis.applyTextResizeTransform = applyTextResizeTransform;
globalThis.applyDmComposition = applyDmComposition;
