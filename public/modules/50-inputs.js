// ---------- Snap helpers ----------
function snapPoint(xPx, yPx) {
  const stepPx = mmToPx(SNAP_MM);
  return { x: Math.round(xPx / stepPx) * stepPx, y: Math.round(yPx / stepPx) * stepPx };
}

function pxGeomToInternal(xPx, yPx, wPx, hPx) {
  let xMm = pxToMm(xPx);
  let yMm = pxToMm(yPx);
  let wMm = pxToMm(wPx);
  let hMm = pxToMm(hPx);

  if (elToggleSnap.checked) {
    xMm = Math.round(xMm / SNAP_MM) * SNAP_MM;
    yMm = Math.round(yMm / SNAP_MM) * SNAP_MM;
    wMm = Math.round(wMm / SNAP_MM) * SNAP_MM;
    hMm = Math.round(hMm / SNAP_MM) * SNAP_MM;
  }
  return { x: mmToInternal(xMm), y: mmToInternal(yMm), w: mmToInternal(wMm), h: mmToInternal(hMm) };
}

function getAlignmentBoxPoints(box, axis) {
  if (axis === "x") {
    return [
      { type: "left", value: box.x },
      { type: "centerX", value: box.x + box.width / 2 },
      { type: "right", value: box.x + box.width }
    ];
  }

  return [
    { type: "top", value: box.y },
    { type: "centerY", value: box.y + box.height / 2 },
    { type: "bottom", value: box.y + box.height }
  ];
}

function findClosestAlignmentSnap(movingBox, targetBoxes, axis) {
  const movingPoints = getAlignmentBoxPoints(movingBox, axis);
  let best = null;

  targetBoxes.forEach((targetBox) => {
    const targetPoints = getAlignmentBoxPoints(targetBox, axis);
    movingPoints.forEach((movingPoint) => {
      targetPoints.forEach((targetPoint) => {
        const delta = targetPoint.value - movingPoint.value;
        const distance = Math.abs(delta);
        if (distance > ALIGNMENT_SNAP_THRESHOLD_PX) return;
        if (best && distance >= best.distance) return;
        best = {
          delta,
          distance,
          guide: targetPoint.value,
          movingType: movingPoint.type,
          targetType: targetPoint.type
        };
      });
    });
  });

  return best;
}

function clearAlignmentGuides() {
  if (!alignmentGuideGroup) return;
  alignmentGuideGroup.destroyChildren();
  alignmentGuideGroup.visible(false);
  uiLayer?.batchDraw();
}

function drawAlignmentGuides(guides) {
  if (!alignmentGuideGroup) return;

  alignmentGuideGroup.destroyChildren();
  const hasVertical = Number.isFinite(guides?.x);
  const hasHorizontal = Number.isFinite(guides?.y);

  if (!hasVertical && !hasHorizontal) {
    alignmentGuideGroup.visible(false);
    uiLayer?.batchDraw();
    return;
  }

  const viewportLeft = -stage.x();
  const viewportTop = -stage.y();
  const viewportRight = viewportLeft + stage.width();
  const viewportBottom = viewportTop + stage.height();
  const guideAttrs = {
    stroke: "#4fc3ff",
    strokeWidth: 1,
    dash: [5, 5],
    listening: false,
    strokeScaleEnabled: false
  };

  if (hasVertical) {
    alignmentGuideGroup.add(new Konva.Line({
      ...guideAttrs,
      points: [guides.x, viewportTop, guides.x, viewportBottom]
    }));
  }

  if (hasHorizontal) {
    alignmentGuideGroup.add(new Konva.Line({
      ...guideAttrs,
      points: [viewportLeft, guides.y, viewportRight, guides.y]
    }));
  }

  alignmentGuideGroup.visible(true);
  uiLayer?.batchDraw();
}

function snapGroupToElementAlignment(group) {
  if (!elToggleAlign?.checked || !group) {
    clearAlignmentGuides();
    return false;
  }

  const movingBox = group.getClientRect({ relativeTo: objLayer });
  const targetBoxes = state.fields
    .map((field) => field._konva)
    .filter((node) => node && node !== group && node.getLayer())
    .map((node) => node.getClientRect({ relativeTo: objLayer }))
    .filter((box) => Number.isFinite(box.x) && Number.isFinite(box.y) && box.width > 0 && box.height > 0);

  if (!targetBoxes.length) {
    clearAlignmentGuides();
    return false;
  }

  const snapX = findClosestAlignmentSnap(movingBox, targetBoxes, "x");
  const snapY = findClosestAlignmentSnap(movingBox, targetBoxes, "y");
  const nextPosition = { x: group.x(), y: group.y() };

  if (snapX) nextPosition.x += snapX.delta;
  if (snapY) nextPosition.y += snapY.delta;
  if (snapX || snapY) group.position(nextPosition);

  drawAlignmentGuides({
    x: snapX?.guide,
    y: snapY?.guide
  });

  return !!(snapX || snapY);
}

// ---------- Inputs ----------
function setControlAriaLabel(control, label) {
  if (!control || typeof control.setAttribute !== "function") return;
  if (!control.hasAttribute("aria-label")) control.setAttribute("aria-label", label);
}

function getControlValueTooltip(control) {
  if (!control) return "";
  if (control.tagName === "SELECT") return getSelectDisplayLabel(control);
  if (control.type === "checkbox" || control.type === "radio") return "";
  return String(control.value ?? "");
}

function syncControlValueTooltip(control) {
  if (!control || typeof control.setAttribute !== "function") return;
  const tooltip = getControlValueTooltip(control).trim();
  if (tooltip) control.setAttribute("title", tooltip);
  else control.removeAttribute("title");

  const customSelectButton = control._customSelectButton;
  if (!customSelectButton) return;
  if (tooltip) customSelectButton.setAttribute("title", tooltip);
  else customSelectButton.removeAttribute("title");
}

function enableControlValueTooltip(control) {
  if (!control || control.dataset?.valueTooltipEnabled === "1") {
    syncControlValueTooltip(control);
    return;
  }

  control.dataset.valueTooltipEnabled = "1";
  control.addEventListener("input", () => syncControlValueTooltip(control));
  control.addEventListener("change", () => syncControlValueTooltip(control));
  syncControlValueTooltip(control);
}

function fieldRow(label, inputEl) {
  const row = document.createElement("div");
  row.className = "fieldRow";
  const lab = document.createElement("label");
  lab.textContent = label;
  setControlAriaLabel(inputEl, label);
  enableControlValueTooltip(inputEl);
  row.appendChild(lab);
  row.appendChild(inputEl);
  return row;
}

function labeledMini(label, el) {
  const wrap = document.createElement("div");
  wrap.style.display = "flex";
  wrap.style.flexDirection = "column";
  wrap.style.gap = "6px";
  const lab = document.createElement("div");
  lab.className = "muted";
  lab.textContent = label;
  wrap.appendChild(lab);
  setControlAriaLabel(el, label);
  enableControlValueTooltip(el);
  wrap.appendChild(el);
  return wrap;
}

let activeCustomSelect = null;
let customSelectListenersInstalled = false;

function getSelectDisplayLabel(selectEl) {
  return selectEl.selectedOptions?.[0]?.textContent || selectEl.options?.[selectEl.selectedIndex]?.textContent || "";
}

function getCustomSelectMenu() {
  let menu = document.getElementById("customSelectMenu");
  if (menu) return menu;

  menu = document.createElement("div");
  menu.id = "customSelectMenu";
  menu.className = "customSelectMenu";
  menu.setAttribute("role", "listbox");
  menu.hidden = true;
  document.body.appendChild(menu);
  return menu;
}

function closeCustomSelect() {
  if (!activeCustomSelect) return;
  const { root, button } = activeCustomSelect;
  root?.classList.remove("is-open");
  button?.setAttribute("aria-expanded", "false");
  const menu = getCustomSelectMenu();
  menu.hidden = true;
  menu.innerHTML = "";
  activeCustomSelect = null;
}

function positionCustomSelectMenu(selectEl) {
  const root = selectEl._customSelectRoot;
  const button = selectEl._customSelectButton;
  if (!root || !button) return;

  const menu = getCustomSelectMenu();
  const rect = button.getBoundingClientRect();
  const gap = 4;
  const viewportGap = 8;
  const width = Math.max(rect.width, 120);
  const below = window.innerHeight - rect.bottom - gap - viewportGap;
  const above = rect.top - gap - viewportGap;
  const openAbove = below < 180 && above > below;
  const maxHeight = Math.max(120, Math.min(280, openAbove ? above : below));
  const left = Math.max(viewportGap, Math.min(rect.left, window.innerWidth - width - viewportGap));
  const top = openAbove
    ? Math.max(viewportGap, rect.top - gap - maxHeight)
    : Math.min(rect.bottom + gap, window.innerHeight - viewportGap - maxHeight);

  menu.style.width = `${Math.round(width)}px`;
  menu.style.maxHeight = `${Math.round(maxHeight)}px`;
  menu.style.left = `${Math.round(left)}px`;
  menu.style.top = `${Math.round(top)}px`;
}

function syncCustomSelectControl(selectEl) {
  const root = selectEl?._customSelectRoot;
  const button = selectEl?._customSelectButton;
  const valueEl = selectEl?._customSelectValue;
  if (!root || !button || !valueEl) return;

  valueEl.textContent = getSelectDisplayLabel(selectEl);
  button.disabled = !!selectEl.disabled;
  if (selectEl.getAttribute("aria-label")) button.setAttribute("aria-label", selectEl.getAttribute("aria-label"));
  button.setAttribute("aria-disabled", String(!!selectEl.disabled));
  root.classList.toggle("is-disabled", !!selectEl.disabled);
  syncControlValueTooltip(selectEl);
}

function buildCustomSelectMenu(selectEl) {
  const menu = getCustomSelectMenu();
  menu.innerHTML = "";

  Array.from(selectEl.options).forEach((option) => {
    const optionButton = document.createElement("button");
    optionButton.type = "button";
    optionButton.className = "customSelectOption";
    optionButton.setAttribute("role", "option");
    optionButton.setAttribute("aria-selected", String(option.selected));
    optionButton.textContent = option.textContent;
    if (option.selected) optionButton.classList.add("is-active");

    optionButton.addEventListener("click", (event) => {
      event.preventDefault();
      event.stopPropagation();
      if (selectEl.disabled) return;

      const previousValue = selectEl.value;
      selectEl.value = option.value;
      syncCustomSelectControl(selectEl);
      closeCustomSelect();
      if (selectEl.value !== previousValue) {
        selectEl.dispatchEvent(new Event("change", { bubbles: true }));
      }
    });

    menu.appendChild(optionButton);
  });
}

function openCustomSelect(selectEl) {
  if (!selectEl || selectEl.disabled) return;
  if (activeCustomSelect?.selectEl === selectEl) {
    closeCustomSelect();
    return;
  }

  closeCustomSelect();
  buildCustomSelectMenu(selectEl);
  activeCustomSelect = {
    selectEl,
    root: selectEl._customSelectRoot,
    button: selectEl._customSelectButton
  };

  activeCustomSelect.root.classList.add("is-open");
  activeCustomSelect.button.setAttribute("aria-expanded", "true");
  const menu = getCustomSelectMenu();
  menu.hidden = false;
  positionCustomSelectMenu(selectEl);
}

function ensureCustomSelectListeners() {
  if (customSelectListenersInstalled) return;
  customSelectListenersInstalled = true;

  document.addEventListener("pointerdown", (event) => {
    if (!activeCustomSelect) return;
    const menu = getCustomSelectMenu();
    if (activeCustomSelect.root.contains(event.target) || menu.contains(event.target)) return;
    closeCustomSelect();
  }, true);

  document.addEventListener("keydown", (event) => {
    if (event.key === "Escape") closeCustomSelect();
  });

  window.addEventListener("resize", closeCustomSelect);
  document.addEventListener("scroll", () => {
    if (activeCustomSelect?.selectEl) positionCustomSelectMenu(activeCustomSelect.selectEl);
  }, true);
}

function enhanceSelectControl(selectEl) {
  if (!selectEl || selectEl.dataset.customSelectEnhanced === "1") {
    syncCustomSelectControl(selectEl);
    return selectEl;
  }
  if (!selectEl.parentNode) return selectEl;

  ensureCustomSelectListeners();

  const root = document.createElement("div");
  root.className = "customSelect";
  selectEl.parentNode.insertBefore(root, selectEl);
  root.appendChild(selectEl);

  const button = document.createElement("button");
  button.type = "button";
  button.className = "select customSelect__button";
  button.setAttribute("aria-haspopup", "listbox");
  button.setAttribute("aria-expanded", "false");

  const valueEl = document.createElement("span");
  valueEl.className = "customSelect__value";
  button.appendChild(valueEl);
  root.appendChild(button);

  selectEl.dataset.customSelectEnhanced = "1";
  selectEl.classList.add("customSelect__native");
  selectEl.tabIndex = -1;
  selectEl.setAttribute("aria-hidden", "true");
  selectEl._customSelectRoot = root;
  selectEl._customSelectButton = button;
  selectEl._customSelectValue = valueEl;

  button.addEventListener("click", (event) => {
    event.preventDefault();
    event.stopPropagation();
    openCustomSelect(selectEl);
  });

  button.addEventListener("keydown", (event) => {
    if (event.key !== "Enter" && event.key !== " " && event.key !== "ArrowDown") return;
    event.preventDefault();
    openCustomSelect(selectEl);
  });

  selectEl.addEventListener("change", () => syncCustomSelectControl(selectEl));
  syncCustomSelectControl(selectEl);
  return selectEl;
}

function enhanceSelectControls(root = document) {
  const scope = root && typeof root.querySelectorAll === "function" ? root : document;
  if (scope.matches?.("select.select")) enhanceSelectControl(scope);
  scope.querySelectorAll("select.select").forEach((selectEl) => enhanceSelectControl(selectEl));
}

function scheduleEnhanceSelectControl(selectEl) {
  const enhance = () => enhanceSelectControl(selectEl);
  if (typeof requestAnimationFrame === "function") requestAnimationFrame(enhance);
  else setTimeout(enhance, 0);
}

function stepCustomNumberControl(inputEl, direction) {
  if (!inputEl || inputEl.disabled || inputEl.readOnly) return;
  const previousValue = inputEl.value;

  try {
    if (direction > 0) inputEl.stepUp();
    else inputEl.stepDown();
  } catch {
    return;
  }

  inputEl.focus({ preventScroll: true });
  if (inputEl.value === previousValue) return;
  inputEl.dispatchEvent(new Event("input", { bubbles: true }));
  inputEl.dispatchEvent(new Event("change", { bubbles: true }));
}

function syncCustomNumberControl(inputEl) {
  const buttons = inputEl?._customNumberButtons;
  if (!buttons) return;
  const disabled = !!inputEl.disabled || !!inputEl.readOnly;
  buttons.forEach((button) => { button.disabled = disabled; });
}

function enhanceNumberControl(inputEl) {
  if (!inputEl || inputEl.type !== "number") return inputEl;
  if (inputEl.dataset.customNumberEnhanced === "1") {
    syncCustomNumberControl(inputEl);
    return inputEl;
  }
  if (!inputEl.parentNode) return inputEl;

  const root = document.createElement("div");
  root.className = "customNumber";
  inputEl.parentNode.insertBefore(root, inputEl);
  root.appendChild(inputEl);

  const controls = document.createElement("div");
  controls.className = "customNumber__controls";
  const buttons = [
    { direction: 1, className: "customNumber__button--up", label: t("number.increase") },
    { direction: -1, className: "customNumber__button--down", label: t("number.decrease") }
  ].map((item) => {
    const button = document.createElement("button");
    button.type = "button";
    button.className = `customNumber__button ${item.className}`;
    button.setAttribute("aria-label", item.label);

    const icon = document.createElement("span");
    icon.className = "customNumber__icon";
    icon.setAttribute("aria-hidden", "true");
    button.appendChild(icon);
    button.addEventListener("click", () => stepCustomNumberControl(inputEl, item.direction));
    controls.appendChild(button);
    return button;
  });

  root.appendChild(controls);
  inputEl.dataset.customNumberEnhanced = "1";
  inputEl._customNumberRoot = root;
  inputEl._customNumberButtons = buttons;
  syncCustomNumberControl(inputEl);
  return inputEl;
}

function enhanceNumberControls(root = document) {
  const scope = root && typeof root.querySelectorAll === "function" ? root : document;
  if (scope.matches?.("input[type='number']")) enhanceNumberControl(scope);
  scope.querySelectorAll("input[type='number']").forEach((inputEl) => enhanceNumberControl(inputEl));
}

function scheduleEnhanceNumberControl(inputEl) {
  const enhance = () => enhanceNumberControl(inputEl);
  if (typeof requestAnimationFrame === "function") requestAnimationFrame(enhance);
  else setTimeout(enhance, 0);
}

function createMaterialSelect(items, currentValue, onChange, opts = {}) {
  const sel = document.createElement("select");
  sel.className = "select";
  if (opts.disabled) sel.disabled = true;

  const current = String(currentValue ?? "");
  items.forEach((item) => {
    const opt = document.createElement("option");
    const value = String(item.value ?? "");
    const label = String(item.label ?? value);
    opt.value = value;
    opt.textContent = label;
    if (value === current) opt.selected = true;
    sel.appendChild(opt);
  });

  sel.value = current;
  sel.addEventListener("change", () => onChange(sel.value));
  scheduleEnhanceSelectControl(sel);
  return sel;
}

function inputText(value, onChange, opts = {}) {
  const inp = document.createElement("input");
  inp.className = "input";
  inp.value = String(value ?? "");
  inp.type = opts.type || "text";
  if (opts.disabled) inp.disabled = true;
  if (opts.readOnly) {
    inp.readOnly = true;
    inp.setAttribute("readonly", "");
  }
  inp.addEventListener("change", () => onChange(inp.value));
  return inp;
}

function inputNumber(value, onChange, opts = {}) {
  const inp = document.createElement("input");
  inp.className = "input";
  inp.type = "number";
  inp.step = String(opts.step ?? 0.01);
  if (opts.min != null) inp.min = String(opts.min);
  if (opts.max != null) inp.max = String(opts.max);
  inp.value = String(value ?? 0);

  let lastEmitted = null;

  const isInRange = (next) => {
    if (opts.min != null && next < Number(opts.min)) return false;
    if (opts.max != null && next > Number(opts.max)) return false;
    return true;
  };

  const normalizeValue = (commit) => {
    let next = Number(inp.value);
    if (!Number.isFinite(next)) {
      if (!commit) return null;
      next = Number(value ?? 0);
    }
    if (opts.integer) next = Math.round(next);
    if (commit && opts.min != null) next = Math.max(Number(opts.min), next);
    if (commit && opts.max != null) next = Math.min(Number(opts.max), next);
    return next;
  };

  const emit = (commit = true) => {
    const next = normalizeValue(commit);
    if (next == null) return;
    if (!commit && !isInRange(next)) return;
    if (lastEmitted === next) {
      if (commit && String(inp.value) !== String(next)) inp.value = String(next);
      return;
    }
    lastEmitted = next;
    if (commit) inp.value = String(next);
    onChange(next);
  };

  if (opts.live) inp.addEventListener("input", () => emit(false));
  inp.addEventListener("change", () => emit(true));
  scheduleEnhanceNumberControl(inp);
  return inp;
}

function mkNum(value, onChange) {
  return inputNumber(value, onChange, { step: 1, integer: true });
}

function inputCheckbox(value, onChange, opts = {}) {
  const wrap = document.createElement("label");
  wrap.className = "checkboxField";

  if (opts.label) {
    const label = document.createElement("span");
    label.className = "checkboxField__label";
    label.textContent = opts.label;
    wrap.appendChild(label);
  }

  const input = document.createElement("input");
  input.className = "checkboxField__native";
  input.type = "checkbox";
  input.checked = !!value;
  input.disabled = !!opts.disabled;
  input.setAttribute("aria-label", opts.ariaLabel || opts.label || "Toggle");
  input.addEventListener("change", () => onChange(!!input.checked));

  const switchEl = document.createElement("span");
  switchEl.className = "checkboxField__switch";
  switchEl.setAttribute("aria-hidden", "true");

  const handle = document.createElement("span");
  handle.className = "checkboxField__handle";
  switchEl.appendChild(handle);

  wrap.appendChild(input);
  wrap.appendChild(switchEl);
  return wrap;
}

function selectDataMatrixModuleSize(value, onChange) {
  const current = formatDataMatrixModuleSize(value);
  const options = DATA_MATRIX_MODULE_SIZES.map((option) => formatDataMatrixModuleSize(option));
  if (!options.includes(current)) options.unshift(current);
  return createMaterialSelect(
    options.map((option) => ({ value: option, label: option })),
    current,
    (nextValue) => onChange(normalizeDataMatrixModuleSizeValue(nextValue))
  );
}

function selectSymbolSize(value, onChange) {
  const current = normalizeDataMatrixSymbolSizeValue(value, "22X22");
  const sizes = DATA_MATRIX_SYMBOL_SIZE_OPTIONS.slice();
  if (!sizes.includes(current)) sizes.unshift(current);
  return createMaterialSelect(
    sizes.map((size) => ({ value: size, label: size })),
    current,
    (nextValue) => onChange(normalizeDataMatrixSymbolSizeValue(nextValue, "22X22"))
  );
}

function selectOffsetName(value, onChange) {
  const opts = state.dateOffsets.map(o => o.name);
  return createMaterialSelect(
    [{ value: "", label: "(none)" }, ...opts.map((name) => ({ value: name, label: name }))],
    value ?? "",
    onChange
  );
}

function selectStringOptions(value, options, onChange) {
  const current = value ?? "";
  const list = [];

  if (current && !options.includes(current)) list.push(current);
  options.forEach(opt => { if (!list.includes(opt)) list.push(opt); });
  return createMaterialSelect(
    list.map((option) => ({ value: option, label: option })),
    current,
    onChange
  );
}

function getSupportedSeparatorValue(value, options, fallback) {
  const current = value ?? fallback;
  return options.some(opt => opt.value === current) ? current : fallback;
}

function getSeparatorLabelKey(value) {
  if (value === "") return "separator.none";
  if (value === " ") return "separator.space";
  if (value === ":") return "separator.colon";
  if (value === ".") return "separator.dot";
  if (value === ",") return "separator.comma";
  if (value === "-") return "separator.dash";
  if (value === "\\") return "separator.backslash";
  return null;
}

function localizeSeparatorOptions(options) {
  return options.map((option) => {
    const labelKey = getSeparatorLabelKey(option.value);
    return {
      value: option.value,
      label: labelKey ? t(labelKey) : option.label
    };
  });
}

function selectTimeSeparator(value, onChange) {
  const current = getSupportedSeparatorValue(value, TIME_SEPARATOR_OPTIONS, ":");
  return createMaterialSelect(localizeSeparatorOptions(TIME_SEPARATOR_OPTIONS), current, onChange);
}

function selectDateFormat(value, locale, onChange) {
  const currentFormat = value || "dd/MM/yy";
  const currentLocale = locale || "en";
  const currentValue = `${currentFormat}::${currentLocale}`;
  const options = [];

  if (!DATE_TEXT_FORMAT_OPTIONS.some(opt => opt.value === currentValue)) {
    options.push({ value: currentValue, format: currentFormat, locale: currentLocale, label: currentFormat });
  }
  DATE_TEXT_FORMAT_OPTIONS.forEach(opt => {
    if (!options.some(item => item.value === opt.value)) options.push(opt);
  });
  return createMaterialSelect(options, currentValue, (nextValue) => {
    const selected = options.find(opt => opt.value === nextValue);
    onChange(selected?.format ?? currentFormat, selected?.locale ?? currentLocale);
  });
}

function selectDateSeparator(value, onChange) {
  const current = getSupportedSeparatorValue(value, DATE_SEPARATOR_OPTIONS, ".");
  return createMaterialSelect(localizeSeparatorOptions(DATE_SEPARATOR_OPTIONS), current, onChange);
}

function normalizeTimeFormat(value) {
  return String(value ?? "").replace(/'/g, "");
}
