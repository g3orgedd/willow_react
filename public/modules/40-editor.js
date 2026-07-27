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

  return true;
}

function supportsFontSizeEditing(field) {
  return !!field?.text && field.fldType !== "Barcode";
}

function normalizeFontSizeValue(value) {
  const next = Math.round(Number(value));
  return Number.isFinite(next) ? Math.max(1, next) : null;
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
  const inp = document.createElement("input");
  inp.className = "input";
  inp.type = "number";
  inp.step = "1";
  inp.min = "1";
  inp.value = current.mixed || current.value == null ? "" : String(current.value);
  if (current.mixed) inp.placeholder = t("common.mixed");

  let lastEmitted = current.mixed ? null : current.value;
  const emit = () => {
    const nextSize = normalizeFontSizeValue(inp.value);
    if (nextSize == null) return;
    if (lastEmitted === nextSize && fields.every((field) => normalizeFontSizeValue(getEffectiveTextPitch(field, 10)) === nextSize)) return;

    lastEmitted = nextSize;
    inp.value = String(nextSize);
    pushHistory();
    fields.forEach((field) => {
      field.text.pitch = nextSize;
    });
    renderObjects();
    renderUI();
  };

  inp.addEventListener("input", emit);
  inp.addEventListener("change", emit);
  return inp;
}

function buildMultiSelectionProps(fields) {
  const wrap = document.createElement("div");
  wrap.className = "form";

  const note = document.createElement("div");
  note.className = "note";
  const fontFields = fields.filter(supportsFontSizeEditing);
  note.innerHTML = `<strong>${t("status.selected")}</strong><br>${t("status.selectedMultiple", { count: fields.length })}`;
  wrap.appendChild(note);
  wrap.appendChild(createDeleteControlButton());

  const rotations = fields.map((field) => normalizeOrientation(field.orientation));
  const firstRotation = rotations[0] ?? 0;
  const hasMixedRotation = rotations.some((rotation) => rotation !== firstRotation);
  const rotationOptions = hasMixedRotation
    ? [{ value: "", label: t("common.mixed") }, ...ALLOWED_ORIENTATIONS.map((deg) => ({ value: String(deg), label: `${deg}\u00B0` }))]
    : ALLOWED_ORIENTATIONS.map((deg) => ({ value: String(deg), label: `${deg}\u00B0` }));

  wrap.appendChild(fieldRow(t("field.rotation"), createMaterialSelect(
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
  )));

  if (fontFields.length) {
    wrap.appendChild(fieldRow(t("field.fontSize"), createMultiFontSizeInput(fontFields)));
  }

  return wrap;
}

function createPrintControlCard(field) {
  const card = document.createElement("div");
  card.className = "printControlCard";

  const copy = document.createElement("div");
  copy.className = "printControlCard__copy";

  const titleRow = document.createElement("div");
  titleRow.className = "printControlCard__titleRow";

  const title = document.createElement("div");
  title.className = "printControlCard__title";
  title.textContent = t("field.printOutput");

  const status = document.createElement("span");
  status.className = "printControlCard__status";

  const description = document.createElement("div");
  description.className = "printControlCard__description";

  const syncPrintState = (isPrinted) => {
    card.dataset.printState = isPrinted ? "printed" : "hidden";
    // status.textContent = isPrinted ? "Printed" : "Hidden";
    // description.textContent = isPrinted
    //   ? "Object is included in the printed output."
    //   : "Object stays in the template, but is excluded from printing.";
  };

  const control = inputCheckbox(field.printed, (value) => {
    pushHistory();
    field.printed = value;
    syncPrintState(value);
    window.setTimeout(renderAll, PRINT_SWITCH_ANIMATION_MS);
  }, { ariaLabel: t("field.printOutput") });

  titleRow.appendChild(title);
  // titleRow.appendChild(status);
  copy.appendChild(titleRow);
  copy.appendChild(description);

  card.appendChild(copy);
  card.appendChild(control);
  syncPrintState(field.printed);

  return card;
}

function createDeleteControlButton() {
  const btn = document.createElement("button");
  btn.type = "button";
  btn.className = "btn btn--danger deleteControlCard";
  btn.textContent = t("object.delete");
  btn.setAttribute("aria-label", t("object.delete"));
  btn.addEventListener("click", () => deleteSelected());
  return btn;
}

function createPropsDivider() {
  const divider = document.createElement("div");
  divider.className = "hr1";
  return divider;
}

function buildCommonProps(f) {
  const wrap = document.createElement("div");
  wrap.className = "form";

  wrap.appendChild(createPrintControlCard(f));
  wrap.appendChild(createDeleteControlButton());
  wrap.appendChild(createPropsDivider());
  wrap.appendChild(fieldRow(t("field.name"), createFieldNameInput(f)));
  if (f.fldType === "FixedText") {
    wrap.appendChild(fieldRow(t("field.type"), buildFixedTextEntryModeSelect(f)));
  } else {
    wrap.appendChild(fieldRow(t("field.type"), inputText(f.fldType, () => {}, { disabled: true })));
  }
  wrap.appendChild(fieldRow(t("field.maxCharacters"), inputMaxCharacters(f.data?.maxChars, (value) => {
    if (f.data.maxChars === value) return;
    pushHistory();
    f.data.maxChars = value;
    renderUI();
  })));

  wrap.appendChild(fieldRow(t("field.x"), inputNumber(internalToMm(f.geom.x), (v) => { pushHistory(); f.geom.x = mmToInternal(v); renderAll(); })));
  wrap.appendChild(fieldRow(t("field.y"), inputNumber(internalToMm(f.geom.y), (v) => { pushHistory(); f.geom.y = mmToInternal(v); renderAll(); })));
  wrap.appendChild(fieldRow(t("field.width"), inputNumber(internalToMm(f.geom.w), (v) => { pushHistory(); f.geom.w = mmToInternal(v); renderAll(); })));
  wrap.appendChild(fieldRow(t("field.height"), inputNumber(internalToMm(f.geom.h), (v) => { pushHistory(); f.geom.h = mmToInternal(v); renderAll(); })));
  wrap.appendChild(fieldRow(t("field.rotation"), selectOrientation(f.orientation, (v) => {
    pushHistory();
    f.orientation = v;
    renderObjects();
    renderUI();
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
  field.data.defaultValue = currentValue;
  field.calcData = currentValue;

  if (nextMode === "user") {
    field.data.staticAttr = "0";
    field.data.userEnterData = currentValue;
    return;
  }

  field.data.staticAttr = null;
  field.data.userEnterData = "";
  field.data.mask = "";
}

function setEditableTextFieldValue(field, nextValueRaw) {
  if (!field) return;
  const nextValue = String(nextValueRaw ?? "");

  if (field.fldType !== "FixedText") {
    field.data.userEnterData = nextValue;
    field.data.defaultValue = field.data.defaultValue || nextValue;
    field.calcData = nextValue;
    return;
  }

  field.data.defaultValue = nextValue;
  field.calcData = nextValue;

  if (isUserEnteredTextField(field)) {
    field.data.textEntryMode = "user";
    field.data.hasVarText = true;
    field.data.staticAttr = "0";
    field.data.userEnterData = nextValue;
    return;
  }

  field.data.textEntryMode = "fixed";
  field.data.hasVarText = false;
  field.data.staticAttr = null;
  field.data.userEnterData = "";
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

  const displayValue = getFieldDisplayValue(f);
  const isDynamicPreviewField = f.fldType === "TimeText" || f.fldType === "DateText" || f.fldType === "OffsetDateText" || f.fldType === "CounterText";
  const valueInput = isDynamicPreviewField
    ? inputText(displayValue, () => {}, { readOnly: true })
    : inputText(displayValue, (v) => {
        pushHistory();
        setEditableTextFieldValue(f, v);
        renderObjects();
        renderUI();
        renderSelectionPanels();
      });

  if (isDynamicPreviewField) valueInput.dataset.dynamicPreviewValue = "1";
  wrap.appendChild(fieldRow(t("field.value"), valueInput));

  if (f.fldType === "CounterText") {
    const counter = f.data.counter ?? {};
    const noOfChars = Math.max(1, Math.round(parseCounterNumber(counter.noOfChars, 4) ?? 4));
    const maxValue = getCounterMaxValue(noOfChars);

    wrap.appendChild(fieldRow(t("counter.digits"), inputNumber(noOfChars, (v) => {
      applyCounterFieldChange(f, (next) => {
        next.noOfChars = Math.max(1, Math.round(v));
      });
    }, { step: 1, integer: true, min: 1 })));

    wrap.appendChild(fieldRow(t("counter.start"), inputNumber(parseCounterNumber(counter.startVal, 1) ?? 1, (v) => {
      applyCounterFieldChange(f, (next) => {
        next.startVal = String(Math.max(0, Math.round(v)));
      });
    }, { step: 1, integer: true, min: 0, max: maxValue })));

    wrap.appendChild(fieldRow(t("counter.end"), inputNumber(parseCounterNumber(counter.endVal, maxValue) ?? maxValue, (v) => {
      applyCounterFieldChange(f, (next) => {
        next.endVal = String(Math.max(0, Math.round(v)));
      });
    }, { step: 1, integer: true, min: 0, max: maxValue })));

    wrap.appendChild(fieldRow(t("counter.step"), inputNumber(parseCounterNumber(counter.stepSize, 1) ?? 1, (v) => {
      applyCounterFieldChange(f, (next) => {
        next.stepSize = Math.max(1, Math.round(v));
      });
    }, { step: 1, integer: true, min: 1 })));

    const note = document.createElement("div");
    note.className = "note";
    note.textContent = t("counter.maxValue", { digits: noOfChars, value: formatCounterValue(maxValue, noOfChars) });
    wrap.appendChild(note);

    const hr = document.createElement("div");
    hr.className = "hr";
    wrap.appendChild(hr);

    wrap.appendChild(fieldRow(t("field.fontSize"), inputNumber(getEffectiveTextPitch(f, 10), (v) => {
      pushHistory();
      f.text.pitch = Math.max(1, Math.round(v));
      refreshFieldCanvasPreview(f);
    }, { step: 1, integer: true, min: 1, live: true })));

    wrap.appendChild(fieldRow(t("field.xMag"), inputNumber(f.text.xMag ?? 100, (v) => {
      pushHistory();
      f.text.xMag = clamp(X_MAG_MIN, X_MAG_MAX, Math.round(v));
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
      wrap.appendChild(fieldRow(t("field.dateType"), dateTypeSelect));
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

    wrap.appendChild(fieldRow(f.fldType === "TimeText" ? t("field.timeFormat") : t("field.dateFormat"), formatInput));

    if (f.fldType === "TimeText") {
      wrap.appendChild(fieldRow(t("field.separator"), selectTimeSeparator(getTimeSeparator(f.data.defaultValue || ""), (v) => {
        pushHistory();
        f.data.defaultValue = buildTimeTemplateFormat(getTimeFormatPreset(f.data.defaultValue || ""), v);
        refreshSelectedDynamicFieldPreview();
      })));
    }

    if (f.fldType === "DateText" || f.fldType === "OffsetDateText") {
      wrap.appendChild(fieldRow(t("field.separator"), selectDateSeparator(getDateSeparator(f.data.defaultValue || ""), (v) => {
        pushHistory();
        f.data.defaultValue = buildDateTemplateFormat(getDateFormatPreset(f.data.defaultValue || ""), v);
        refreshSelectedDynamicFieldPreview();
      })));
    }

    if (f.fldType === "OffsetDateText") {
      wrap.appendChild(fieldRow(t("field.offset"), selectOffsetName(f.data.offsetRef, (v) => {
        pushHistory();
        f.data.offsetRef = v || null;
        refreshSelectedDynamicFieldPreview();
      })));
    }
  }

  wrap.appendChild(fieldRow(t("field.fontSize"), inputNumber(getEffectiveTextPitch(f, 10), (v) => {
    pushHistory();
    f.text.pitch = Math.max(1, Math.round(v));
    refreshFieldCanvasPreview(f);
  }, { step: 1, integer: true, min: 1, live: true })));

  wrap.appendChild(fieldRow(t("field.xMag"), inputNumber(f.text.xMag ?? 100, (v) => {
    pushHistory();
    f.text.xMag = clamp(X_MAG_MIN, X_MAG_MAX, Math.round(v));
    refreshFieldCanvasPreview(f);
  }, { step: 1, integer: true, min: X_MAG_MIN, max: X_MAG_MAX, live: true })));

  return wrap;
}

function buildBarcodeProps(f) {
  const wrap = document.createElement("div");
  wrap.className = "form";

  wrap.appendChild(fieldRow(t("datamatrix.quietMargin"), inputNumber(f.barcode.quietMargin ?? 0, (v) => {
    pushHistory();
    f.barcode.quietMargin = Math.max(0, Math.round(v));
  })));

  wrap.appendChild(fieldRow(t("datamatrix.symbolSize"), selectSymbolSize(f.barcode.dataMatrix.symbolSize, (v) => {
    pushHistory();
    const nextSymbolSize = normalizeDataMatrixSymbolSizeValue(v, "22X22");
    applyDmProfile(f, nextSymbolSize);
    syncDataMatrixGeomToModuleSize(f);
    renderAll();
  })));

  wrap.appendChild(fieldRow(t("datamatrix.moduleSize"), selectDataMatrixModuleSize(f.barcode.dataMatrix.moduleSize, (v) => {
    pushHistory();
    f.barcode.dataMatrix.moduleSize = normalizeDataMatrixModuleSizeValue(v);
    syncDataMatrixGeomToModuleSize(f);
    renderAll();
  })));

  return wrap;
}

function buildDataMatrixPanel(f) {
  const dm = f.barcode.dataMatrix;
  const wrap = document.createElement("div");
  wrap.className = "form";

  const profileSelect = createMaterialSelect([
    { value: "", label: t("common.none") },
    { value: "22X22", label: "22X22" },
    { value: "36X36", label: "36X36" }
  ], "", () => {});
  wrap.appendChild(fieldRow(t("datamatrix.profile"), profileSelect));

  const applyBtn = createPanelActionButton("md-filled-tonal-button", t("datamatrix.applyProfile"), () => {
    const p = profileSelect.value;
    if (!p) return;
    pushHistory();
    applyDmProfile(f, p);
    syncDataMatrixGeomToModuleSize(f);
    renderAll();
  });
  wrap.appendChild(applyBtn);

  const val = validateDmProfile(f, dm.symbolSize);
  const vcard = document.createElement("div");
  vcard.className = "card";
  vcard.innerHTML = `<div class="card__head"><div class="card__title">${t("validation.title")}</div><div class="pill">${val.length ? "!" : "OK"}</div></div>`;
  const vbody = document.createElement("div");
  vbody.className = "muted";
  vbody.style.whiteSpace = "pre-wrap";
  vbody.textContent = val.length ? val.map((x) => "- " + x).join("\n") : t("datamatrix.validationOk");
  vcard.appendChild(vbody);
  wrap.appendChild(vcard);

  const segCard = document.createElement("div");
  segCard.className = "card";

  const segHead = document.createElement("div");
  segHead.className = "card__head";
  const segTitle = document.createElement("div");
  segTitle.className = "card__title";
  segTitle.textContent = t("datamatrix.segments");
  const segActions = document.createElement("div");
  segActions.className = "smallRow";
  const segAddBtn = createPanelActionButton("md-filled-tonal-button", t("datamatrix.addSegment"), () => {
    pushHistory();
    dm.segments.push({ index: dm.segments.length, srcField: null, defaultValue: "", dataType: 5 });
    normalizeDmSegments(dm);
    renderAll();
  });
  segActions.appendChild(segAddBtn);
  segHead.appendChild(segTitle);
  segHead.appendChild(segActions);
  segCard.appendChild(segHead);

  const segWrap = document.createElement("div");
  segWrap.style.display = "flex";
  segWrap.style.flexDirection = "column";
  segWrap.style.gap = "8px";

  dm.segments.forEach((s, idx) => {
    const row = document.createElement("div");
    row.className = "card dmSegmentCard";
    row.style.padding = "15px";
    row.innerHTML = `
      <div class="card__head" style="margin-bottom:6px">
        <div class="card__title">#${idx}</div>
        <div class="smallRow">
          <button class="btn btn--ghost btn--small" type="button" aria-label="Move segment up" data-act="up">
            <img class="topbarAction__icon" src="./resourses/Icons/arrow_upward_24dp.svg" alt="" aria-hidden="true"/>
          </button>
          <button class="btn btn--ghost btn--small" type="button" aria-label="Move segment down" data-act="down">
            <img class="topbarAction__icon" src="./resourses/Icons/arrow_downward_24dp.svg" alt="" aria-hidden="true"/>
          </button>
          <button class="btn btn--danger btn--small" type="button" aria-label="Delete segment" data-act="del">
            <img class="topbarAction__icon" src="./resourses/Icons/delete_24dp.svg" alt="" aria-hidden="true"/>
          </button>
        </div>
      </div>
    `;

    const grid = document.createElement("div");
    grid.className = "card__grid dmSegmentGrid";

    const srcSel = createMaterialSelect(
      [{ value: "", label: "(none)" }, ...state.fields.map((ff) => ({ value: ff.name, label: ff.name }))],
      s.srcField ?? "",
      (nextValue) => { pushHistory(); s.srcField = nextValue || null; renderAll(); }
    );

    const defInp = inputText(s.defaultValue || "", (nextValue) => {
      pushHistory();
      s.defaultValue = nextValue;
      refreshCanvasPreviews();
    });

    grid.appendChild(labeledMini("SrcFieldName", srcSel));
    grid.appendChild(labeledMini("Default", defInp));
    row.appendChild(grid);

    row.querySelectorAll("button[data-act]").forEach((b) => {
      b.addEventListener("click", () => {
        const act = b.dataset.act;
        pushHistory();
        if (act === "del") dm.segments.splice(idx, 1);
        if (act === "up" && idx > 0) [dm.segments[idx - 1], dm.segments[idx]] = [dm.segments[idx], dm.segments[idx - 1]];
        if (act === "down" && idx < dm.segments.length - 1) [dm.segments[idx + 1], dm.segments[idx]] = [dm.segments[idx], dm.segments[idx + 1]];
        normalizeDmSegments(dm);
        renderAll();
      });
    });

    segWrap.appendChild(row);
  });

  segCard.appendChild(segWrap);
  wrap.appendChild(segCard);

  return wrap;
}

function renderHiddenEditor() {
  if (!state.xmlDoc) { elHiddenEditor.innerHTML = ""; return; }

  const hidden = state.fields.filter((f) => !f.printed);
  elHiddenEditor.innerHTML = "";

  hidden.forEach((f) => {
    const card = document.createElement("div");
    card.className = "card";

    const head = document.createElement("div");
    head.className = "card__head";
    const info = document.createElement("div");
    const title = document.createElement("div");
    title.className = "card__title";
    title.textContent = f.name;
    const meta = document.createElement("div");
    meta.className = "card__meta";
    meta.textContent = `${getFieldSubtypeLabel(f)} - Displayed=0`;
    info.appendChild(title);
    info.appendChild(meta);

    const actions = document.createElement("div");
    actions.className = "smallRow";
    const selectBtn = createPanelActionButton("md-text-button", t("common.select"), () => {
      selectField(f.name);
      renderAll();
    });
    actions.appendChild(selectBtn);

    head.appendChild(info);
    head.appendChild(actions);

    const grid = document.createElement("div");
    grid.className = "card__grid";

    const inpVal = inputText(getStoredTextFieldValue(f), (nextValue) => {
      pushHistory();
      setEditableTextFieldValue(f, nextValue);
      refreshCanvasPreviews();
    });

    grid.appendChild(labeledMini(t("field.value"), inpVal));

    card.appendChild(head);
    card.appendChild(grid);
    elHiddenEditor.appendChild(card);
  });
}

function renderOffsetsEditor() {
  if (!state.xmlDoc) { elOffsetsEditor.innerHTML = ""; return; }
  elOffsetsEditor.innerHTML = "";

  if (!state.dateOffsetsLoaded && state.dateOffsets.length === 0) {
    const note = document.createElement("div");
    note.className = "muted";
    note.textContent = t("offsets.empty");
    elOffsetsEditor.appendChild(note);
    return;
  }

  state.dateOffsets.forEach((o, idx) => {
    const card = document.createElement("div");
    card.className = "card";

    const head = document.createElement("div");
    head.className = "card__head";
    const titleWrap = document.createElement("div");
    titleWrap.className = "dateOffsetName";
    titleWrap.appendChild(inputText(o.name, (value) => {
      if (value === o.name) return;
      pushHistory();
      if (!renameDateOffset(o, value)) {
        renderOffsetsEditor();
        renderSelectionPanels();
        return;
      }
      renderAll();
    }));

    const actions = document.createElement("div");
    actions.className = "smallRow";
    const delBtn = createPanelActionButton("md-outlined-button", t("common.delete"), () => {
      pushHistory();
      state.dateOffsets.splice(idx, 1);
      state.dateOffsetsDirty = true;
      renderOffsetsEditor();
      renderSelectionPanels();
      refreshCanvasPreviews();
    });
    actions.appendChild(delBtn);

    head.appendChild(titleWrap);
    head.appendChild(actions);
    card.appendChild(head);
    card.appendChild(document.createElement("div")).className = "hr";

    const grid = document.createElement("div");
    grid.className = "card__grid";

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

    card.appendChild(grid);

    const current = getComputedDateOffsetCurrent(o);
    const note = document.createElement("div");
    note.className = "note";
    note.textContent = t("offsets.current", { date: `${pad2(current.d)}.${pad2(current.m)}.${String(current.y)}` });
    card.appendChild(note);

    elOffsetsEditor.appendChild(card);
  });
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
      if (s.srcField === prevName) s.srcField = nextName;
    });
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
  if (state.dateOffsets.length) {
    field.data.offsetRef = state.dateOffsets[0].name;
    return state.dateOffsets[0];
  }

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
      if (removed.has(segment.srcField)) segment.srcField = null;
    });
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
  KRIPTO: { id: "kripto", name: "KRIPTO", value: "0000", mode: "user", maxChars: 4, printed: false },
  KRIPTO2: { id: "kripto2", name: "KRIPTO2", value: "0".repeat(44), mode: "user", maxChars: 44, printed: false },
  SN: { id: "sn", name: "SN", values: ["000000", "0000000000000"], mode: "user", maxCharsFromValue: true, printed: false },
  "\u04211": { id: "c1", name: "\u04211", value: "~101", mode: "fixed", maxChars: 4, printed: false },
  "\u04212": { id: "c2", name: "\u04212", value: "21", mode: "fixed", maxChars: 2, printed: false },
  "\u04213": { id: "c3", name: "\u04213", values: ["~d02991", "~d02993"], mode: "fixed", maxChars: 7, printed: false },
  C4: { id: "c4", name: "C4", value: "~d02992", mode: "fixed", maxChars: 7, printed: false },
  PRODUCT_DATE: { id: "product_date", name: "PRODUCT_DATE", value: "0000000000", mode: "user", maxChars: null, printed: true },
  PACKING_DATE: { id: "packing_date", name: "PACKING_DATE", value: "0000000000", mode: "user", maxChars: null, printed: true },
  EXPIRATION_DATE: { id: "expiration_date", name: "EXPIRATION_DATE", value: "0000000000", mode: "user", maxChars: null, printed: true },
  PARTY: { id: "party", name: "PARTY", value: "00000", mode: "user", maxChars: null, printed: true },
  R_NUM: { id: "r_num", name: "R_NUM", value: "00000", mode: "user", maxChars: null, printed: true },
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
  return {
    sourceName: null,
    name: config.name || "Field",
    fldType,
    printed: config.printed !== false,
    geom: config.geom ? { ...config.geom } : { x: mmToInternal(2), y: mmToInternal(2), w: mmToInternal(12), h: mmToInternal(4) },
    ln: 1,
    orientation: 0,
    calcData: config.value || "",
    data: {
      dataType: config.dataType ?? guessDataType(fldType),
      defaultValue: config.value || "",
      maxChars: config.maxChars ?? null,
      fixedLen: false,
      staticAttr: config.staticAttr ?? (fldType === "FixedText" ? null : "0"),
      parseAttr: config.parseAttr ?? (["DateText", "TimeText", "OffsetDateText"].includes(fldType) ? "1" : null),
      hasVarText: !!config.userEntered,
      textEntryMode: fldType === "FixedText" ? (config.userEntered ? "user" : "fixed") : null,
      userEnterData: config.userEntered ? (config.value || "") : "",
      mask: "",
      offsetRef: config.offsetRef || null,
      dateLocale: config.dateLocale ?? (["DateText", "OffsetDateText"].includes(fldType) ? "en" : null),
      counter: { noOfChars: null, significance: 0, startVal: null, endVal: null, stepSize: null, clrStCntType: "" }
    },
    text: { pitch: config.pitch ?? 10, xMag: 100 },
    barcode: config.barcode || null,
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
  const maxChars = preset.maxCharsFromValue ? value.length : preset.maxChars;
  const geom = {
    x: position?.x ?? mmToInternal(2),
    y: (position?.y ?? mmToInternal(2)) + mmToInternal(stackIndex * 5),
    w: mmToInternal(12),
    h: mmToInternal(4)
  };
  applyNewFieldPlacementToGeom(geom, { x: geom.x, y: geom.y });

  return (isUserEntered ? createServerVariableField : createFixedTextField)({
    name: preset.name, value, printed: preset.printed, maxChars, geom
  });
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
    elNewDataMatrixSnValue.value = "";
    syncCustomSelectControl(elNewDataMatrixSnValue);
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

  const currentValue = getStoredTextFieldValue(field);
  const nextValue = options.forceValue || !currentValue ? String(fallbackValue) : currentValue;
  field.printed = false;
  field.fldType = "FixedText";
  field.calcData = nextValue;
  field.data.dataType = 0;
  field.data.defaultValue = nextValue;
  field.data.maxChars = maxChars;
  field.data.fixedLen = false;
  field.data.staticAttr = "0";
  field.data.parseAttr = null;
  field.data.hasVarText = true;
  field.data.textEntryMode = "user";
  field.data.userEnterData = nextValue;
  field.data.mask = "";
  return field;
}

function applyNewFieldPlacementToGeom(geom, position) {
  if (!geom || !position) return geom;

  let x = Number(position.x);
  let y = Number(position.y);
  if (!Number.isFinite(x) || !Number.isFinite(y)) return geom;

  if (elToggleSnap?.checked) {
    const snapStep = Math.max(1, mmToInternal(SNAP_MM));
    x = Math.round(x / snapStep) * snapStep;
    y = Math.round(y / snapStep) * snapStep;
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

  pushHistory();

  const existingNames = state.fields.map(f => f.name);
  const base = fldType === "Barcode" ? "FieldDM" : "Field";
  const name = uniqueName(base, existingNames);

  const geom = { x: mmToInternal(2), y: mmToInternal(2), w: mmToInternal(12), h: mmToInternal(4) };
  if (fldType === "Barcode") { geom.w = mmToInternal(12); geom.h = mmToInternal(12); }

  const field = createBaseField({ name, fldType, geom });
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
      bcH: field.geom.h,
      dataMatrix: { moduleSize: 0.50, symbolSize, segments: [] }
    };
    applyDmComposition(field, composition, { purgeDisallowedFields: false });
    field.barcode.dataMatrix.symbolSize = symbolSize;

    configureDataMatrixUserField("GTIN", "0".repeat(14), 14);
    configureDataMatrixUserField("SN", snValue, snValue.length, { forceValue: true });
    configureDataMatrixUserField("KRIPTO", "0".repeat(4), 4);
    if (composition === "long") configureDataMatrixUserField("KRIPTO2", "0".repeat(44), 44);

    field.barcode.dataMatrix.segments.forEach((segment) => {
      const sourceField = state.fieldByName.get(segment.srcField);
      if (sourceField) segment.defaultValue = getStoredTextFieldValue(sourceField);
    });
    syncDataMatrixGeomToModuleSize(field);
  }

  applyNewFieldPlacementToGeom(field.geom, options.position);
  state.fields.push(field);
  state.fieldByName.set(field.name, field);

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
  const composition = DM_PROFILES[symbolSize]
    ? getDataMatrixComposition(DM_PROFILES[symbolSize].symbolSize)
    : getDataMatrixComposition(symbolSize);
  if (dmField?.barcode?.dataMatrix) dmField.barcode.dataMatrix.symbolSize = symbolSize;
  applyDmComposition(dmField, composition, options);
}

function applyDmComposition(dmField, compositionName, options = {}) {
  const profile = DM_COMPOSITIONS[compositionName];
  if (!profile) return;
  const dm = dmField.barcode?.dataMatrix;
  if (!dm) return;
  const actualSymbolSize = dm.symbolSize;

  if (profile.disallowedFields?.length) {
    dm.segments = dm.segments.filter(s => !profile.disallowedFields.includes(s.srcField));
    if (options.purgeDisallowedFields !== false) purgeFieldsFromTemplate(profile.disallowedFields);
  }

  profile.requiredSegments.forEach((fname) => ensureFieldExists(fname, profile.fixedFields?.[fname] ?? null));

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
}

function validateDmProfile(dmField, symbolSize) {
  const p = DM_COMPOSITIONS[getDataMatrixComposition(symbolSize)];
  if (!p) return [];
  const dm = dmField.barcode?.dataMatrix;
  if (!dm) return ["No DataMatrix node."];

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
  return errors;
}

function purgeFieldsFromTemplate(names) {
  const namesToRemove = [...new Set((names || []).filter(Boolean))];
  if (!namesToRemove.length) return;

  const removed = new Set(namesToRemove);
  state.fields = state.fields.filter(f => !removed.has(f.name));
  namesToRemove.forEach(name => state.fieldByName.delete(name));

  state.fields.forEach(f => {
    const dm = f.barcode?.dataMatrix;
    if (!dm) return;
    dm.segments = dm.segments.filter(s => !removed.has(s.srcField));
    normalizeDmSegments(dm);
  });

  if (state.selectedName && removed.has(state.selectedName)) state.selectedName = null;
  if (Array.isArray(state.selectedNames)) {
    state.selectedNames = state.selectedNames.filter((name) => !removed.has(name));
  }
  setSelectedNames(state.selectedNames, state.selectedName);
}

function getAutoHiddenFieldGeom() {
  const columnXmm = internalToMm(getCanvasInternalWidth() || mmToInternal(32.67)) + 1.5;
  const baseYmm = 1.0;
  const gapYmm = 1.0;
  const widthMm = 10;
  const heightMm = 3;
  let nextYmm = baseYmm;

  state.fields
    .filter((field) => !field.printed && Math.abs(internalToMm(field.geom.x) - columnXmm) <= 2)
    .forEach((field) => {
      const fieldBottomMm = internalToMm(field.geom.y) + internalToMm(field.geom.h) + gapYmm;
      if (fieldBottomMm > nextYmm) nextYmm = fieldBottomMm;
    });

  return {
    x: mmToInternal(columnXmm),
    y: mmToInternal(nextYmm),
    w: mmToInternal(widthMm),
    h: mmToInternal(heightMm)
  };
}

function ensureFieldExists(name, fixedValueOrNull) {
  if (state.fieldByName.has(name)) return;

  const geom = getAutoHiddenFieldGeom();
  const autoValue = fixedValueOrNull ?? (name === "GTIN" ? "00000000000000" : "");
  const f = {
    sourceName: null,
    name,
    fldType: "FixedText",
    printed: false,
    geom,
    ln: 1,
    orientation: 0,
    calcData: autoValue,
    data: {
      dataType: 0,
      defaultValue: autoValue,
      maxChars: autoValue ? autoValue.length : null,
      fixedLen: false,
      staticAttr: null,
      parseAttr: null,
      hasVarText: false,
      textEntryMode: "fixed",
      userEnterData: "",
      mask: "",
      offsetRef: null,
      counter: { noOfChars: null, significance: 0 }
    },
    text: { pitch: 8, xMag: 100 },
    barcode: null,
    _konva: null
  };

  state.fields.push(f);
  state.fieldByName.set(name, f);
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
globalThis.applyDmComposition = applyDmComposition;
