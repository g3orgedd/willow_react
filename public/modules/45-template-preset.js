/* Pure template-preset model, generator, layout and builder UI. */
const TEMPLATE_PRESET_FIELD_ORDER = [
  ["party", "PARTY"],
  ["team", "TEAM"],
  ["productDate", "PRODUCT_DATE"],
  ["expirationDate", "EXPIRATION_DATE"],
  ["rNum", "R_NUM"],
  ["packingDate", "PACKING_DATE"],
  ["time", "TIME"]
];
const TEMPLATE_PRESET_DATE_KEYS = ["productDate", "expirationDate", "packingDate"];
const TEMPLATE_PRESET_DEFAULT_PRINT_MODE = "Continuous";
const TEMPLATE_PRESET_PRINTER_FIELD_KEYS = new Set(["productDate", "expirationDate", "time"]);

function isTemplatePresetFieldAvailable(key, sourceMode) {
  return sourceMode === "server-dm-printer-rest"
    ? TEMPLATE_PRESET_PRINTER_FIELD_KEYS.has(key)
    : key !== "time";
}

function getTemplatePresetFieldName(key, sourceMode, fallbackName = "") {
  if (sourceMode === "server-dm-printer-rest") {
    if (key === "productDate") return "PROD_DATE";
    if (key === "expirationDate") return "EXP_DATE";
  }
  return fallbackName;
}

function createDefaultTemplatePresetDraft() {
  const dateField = (generation, days = 0) => ({
    enabled: false,
    generation,
    format: "dd/MM/yy",
    separator: ".",
    locale: "en",
    offset: { years: 0, months: 0, days }
  });
  const textField = (value, maxChars) => ({
    enabled: false,
    generation: "printer-input",
    defaultValue: value,
    maxChars
  });
  return {
    version: 1,
    creationKind: null,
    base: { printerModel: "6530", printMode: TEMPLATE_PRESET_DEFAULT_PRINT_MODE, widthMm: 53.33, heightMm: 75 },
    dataSourceMode: null,
    dataMatrix: { symbolSize: "22X22", snValue: "000000", moduleSize: 0.5 },
    fields: {
      party: textField("00000", null),
      team: textField("00", null),
      rNum: textField("00000", null),
      productDate: dateField("printer-current"),
      expirationDate: dateField("printer-offset", 30),
      packingDate: dateField("printer-current"),
      time: { enabled: false, format: "HH:mm", separator: ":" }
    }
  };
}

function normalizeTemplatePresetDraft(raw = {}) {
  const defaults = createDefaultTemplatePresetDraft();
  const draft = {
    ...defaults,
    ...raw,
    base: { ...defaults.base, ...(raw.base || {}) },
    dataMatrix: { ...defaults.dataMatrix, ...(raw.dataMatrix || {}) },
    fields: {}
  };
  Object.keys(defaults.fields).forEach((key) => {
    draft.fields[key] = {
      ...defaults.fields[key],
      ...(raw.fields?.[key] || {}),
      ...(defaults.fields[key].offset ? { offset: { ...defaults.fields[key].offset, ...(raw.fields?.[key]?.offset || {}) } } : {})
    };
  });
  draft.base.printerModel = EMPTY_TEMPLATE_PRINTER_MODELS.includes(String(draft.base.printerModel))
    ? String(draft.base.printerModel) : EMPTY_TEMPLATE_PRINTER_MODELS[0];
  draft.base.printMode = EMPTY_TEMPLATE_PRINT_MODES.includes(String(draft.base.printMode))
    ? String(draft.base.printMode) : TEMPLATE_PRESET_DEFAULT_PRINT_MODE;
  draft.base.widthMm = Number(draft.base.widthMm);
  draft.base.heightMm = Number(draft.base.heightMm);
  draft.dataMatrix.symbolSize = normalizeDataMatrixSymbolSizeValue(draft.dataMatrix.symbolSize, "");
  draft.dataMatrix.snValue = draft.dataMatrix.snValue === "0000000000000" ? "0000000000000" : "000000";
  draft.dataMatrix.moduleSize = Number(draft.dataMatrix.moduleSize);
  if (draft.dataSourceMode === "server-full") {
    TEMPLATE_PRESET_DATE_KEYS.forEach((key) => { draft.fields[key].generation = "server"; });
    ["party", "team", "rNum"].forEach((key) => { draft.fields[key].generation = "server"; });
    draft.fields.time.enabled = false;
  } else if (draft.dataSourceMode === "server-dm-printer-rest") {
    ["party", "team", "rNum", "packingDate"].forEach((key) => { draft.fields[key].enabled = false; });
  }
  return draft;
}

function createPresetIssue(code, field, severity = "error", details = null) {
  return { code, field, severity, messageKey: `builder.validation.${code}`, details };
}

function validateTemplatePresetDraft(input, options = {}) {
  const draft = normalizeTemplatePresetDraft(input);
  const issues = [];
  if (!["preset-builder", "empty"].includes(draft.creationKind)) issues.push(createPresetIssue("creationKindRequired", "creationKind"));
  if (!EMPTY_TEMPLATE_PRINTER_MODELS.includes(draft.base.printerModel)) issues.push(createPresetIssue("printerRequired", "base.printerModel"));
  if (!EMPTY_TEMPLATE_PRINT_MODES.includes(draft.base.printMode)) issues.push(createPresetIssue("printModeRequired", "base.printMode"));
  if (!(draft.base.widthMm > 0 && draft.base.widthMm <= 53.33)) issues.push(createPresetIssue("invalidWidth", "base.widthMm"));
  if (!(draft.base.heightMm > 0 && draft.base.heightMm <= 75)) issues.push(createPresetIssue("invalidHeight", "base.heightMm"));
  if (draft.creationKind === "empty") return issues;
  if (!["server-full", "server-dm-printer-rest"].includes(draft.dataSourceMode)) issues.push(createPresetIssue("sourceRequired", "dataSourceMode"));
  if (!DATA_MATRIX_SYMBOLS_BY_NAME.has(draft.dataMatrix.symbolSize)) issues.push(createPresetIssue("symbolRequired", "dataMatrix.symbolSize"));
  if (!["000000", "0000000000000"].includes(draft.dataMatrix.snValue)) issues.push(createPresetIssue("snRequired", "dataMatrix.snValue"));
  if (!(draft.dataMatrix.moduleSize > 0)) issues.push(createPresetIssue("invalidModuleSize", "dataMatrix.moduleSize"));
  TEMPLATE_PRESET_DATE_KEYS.forEach((key) => {
    const field = draft.fields[key];
    if (field.enabled && field.generation === "printer-offset") {
      const values = [field.offset?.years, field.offset?.months, field.offset?.days];
      if (values.some((value) => !Number.isFinite(Number(value)))) issues.push(createPresetIssue("offsetRequired", `fields.${key}.offset`));
    }
  });
  if (options.layout?.overflowFieldNames?.length) {
    issues.push(createPresetIssue("layoutOverflow", "layout", "error", options.layout.overflowFieldNames));
  }
  return issues;
}

function createPresetHelperField(name, value, maxChars, userEntered) {
  const factory = userEntered ? createServerVariableField : createFixedTextField;
  return factory({
    name,
    value,
    maxChars,
    printed: false,
    pitch: 8,
    geom: { x: 0, y: 0, w: mmToInternal(12), h: mmToInternal(3.2) }
  });
}

function createDataMatrixHelperFields(config) {
  const composition = DM_COMPOSITIONS[getDataMatrixComposition(config.symbolSize)];
  const values = {
    ...composition.fixedFields,
    GTIN: "0".repeat(14),
    SN: config.snValue,
    KRIPTO: "0".repeat(4),
    KRIPTO2: "0".repeat(44)
  };
  const maxChars = { "\u04211": 4, GTIN: 14, "\u04212": 2, SN: config.snValue.length, "\u04213": 7, KRIPTO: 4, C4: 7, KRIPTO2: 44 };
  const userFields = new Set(["GTIN", "SN", "KRIPTO", "KRIPTO2"]);
  return composition.requiredSegments.map((name) => createPresetHelperField(name, values[name] || "", maxChars[name], userFields.has(name)));
}

function createDataMatrixField(config, fieldMap) {
  const composition = DM_COMPOSITIONS[getDataMatrixComposition(config.symbolSize)];
  const segments = composition.requiredSegments.map((name, index) => ({
    index,
    srcField: name,
    defaultValue: getStoredTextFieldValue(fieldMap.get(name)),
    dataType: 5
  }));
  const field = createBaseField({
    name: "FieldDM",
    fldType: "Barcode",
    printed: true,
    geom: { x: 0, y: 0, w: mmToInternal(12), h: mmToInternal(12) },
    barcode: {
      clsid: "{7A4AA4CF-F5CD-11D4-8DAE-0050DAFE8A9F}",
      quietMargin: 0,
      bcH: mmToInternal(12),
      dataMatrix: { moduleSize: config.moduleSize, symbolSize: config.symbolSize, segments }
    }
  });
  syncDataMatrixGeomToModuleSize(field);
  return field;
}

function createPresetDateOffset(fieldName, offset) {
  const normalized = {
    y: Number(offset?.years) || 0,
    m: Number(offset?.months) || 0,
    d: Number(offset?.days) || 0
  };
  return { name: `${fieldName}_OFFSET`, default: normalized, current: getComputedDateOffsetCurrent({ default: normalized }) };
}

function createPresetAdditionalField(key, name, config, sourceMode, dateOffsets) {
  const catalog = FIELD_CATALOG[name];
  if (key === "time") {
    return createCurrentTimeField({ name, printed: true, format: config.format, separator: config.separator });
  }
  if (TEMPLATE_PRESET_DATE_KEYS.includes(key) && sourceMode === "server-dm-printer-rest") {
    if (config.generation === "printer-offset") {
      const offset = createPresetDateOffset(name, config.offset);
      dateOffsets.push(offset);
      return createOffsetDateField({ name, printed: true, format: config.format, separator: config.separator, locale: config.locale }, offset.name);
    }
    if (config.generation === "printer-current") {
      return createCurrentDateField({ name, printed: true, format: config.format, separator: config.separator, locale: config.locale });
    }
  }
  const fieldConfig = { name, printed: true, value: catalog?.value || config.defaultValue || "", maxChars: config.maxChars ?? catalog?.maxChars };
  return sourceMode === "server-full"
    ? createServerVariableField(fieldConfig)
    : createPrinterInputField(fieldConfig);
}

function calculatePresetLayout(config, fields) {
  const margin = mmToInternal(2);
  const gap = mmToInternal(1);
  const maxWidth = mmToInternal(config.widthMm);
  const maxHeight = mmToInternal(config.heightMm);
  const dm = fields.find((field) => field.barcode?.dataMatrix);
  const hiddenFields = fields.filter((field) => !field.printed);
  const printedText = fields.filter((field) => field.printed && field !== dm);
  const geometryByFieldName = {};
  const overflowFieldNames = [];
  const hiddenColumnX = maxWidth + mmToInternal(1.5);
  let hiddenY = mmToInternal(1);
  hiddenFields.forEach((field) => {
    geometryByFieldName[field.name] = { ...field.geom, x: hiddenColumnX, y: hiddenY };
    hiddenY += field.geom.h + gap;
  });
  if (dm) geometryByFieldName[dm.name] = { ...dm.geom, x: margin, y: margin };
  let x = dm ? margin + dm.geom.w + gap : margin;
  let y = margin;
  const stackWidth = Math.max(mmToInternal(12), maxWidth - x - margin);
  if (x + stackWidth > maxWidth && dm) {
    x = margin;
    y = margin + dm.geom.h + gap;
  }
  printedText.forEach((field) => {
    const pitch = getEffectiveTextPitch(field, 10);
    const h = mmToInternal(pitch * CLARISOFT_TEXT_FIELD_HEIGHT_MM_PER_PITCH);
    const geom = { x, y, w: Math.max(mmToInternal(8), Math.min(stackWidth, maxWidth - x - margin)), h };
    geometryByFieldName[field.name] = geom;
    if (geom.x < 0 || geom.y < 0 || geom.x + geom.w > maxWidth || geom.y + geom.h > maxHeight) overflowFieldNames.push(field.name);
    y += h + gap;
  });
  if (dm && (margin + dm.geom.w > maxWidth || margin + dm.geom.h > maxHeight)) overflowFieldNames.unshift(dm.name);
  return { geometryByFieldName, overflowFieldNames: [...new Set(overflowFieldNames)] };
}

function generateTemplatePreset(input) {
  const draft = normalizeTemplatePresetDraft(input);
  const initialIssues = validateTemplatePresetDraft(draft);
  if (initialIssues.some((issue) => issue.severity === "error")) {
    return { ok: false, draft, issues: initialIssues, warnings: [], fields: [], dateOffsets: [], layout: null, xml: "" };
  }
  const helperFields = createDataMatrixHelperFields(draft.dataMatrix);
  const fieldMap = new Map(helperFields.map((field) => [field.name, field]));
  const dmField = createDataMatrixField(draft.dataMatrix, fieldMap);
  const dateOffsets = [];
  const additionalFields = TEMPLATE_PRESET_FIELD_ORDER
    .filter(([key]) => isTemplatePresetFieldAvailable(key, draft.dataSourceMode) && draft.fields[key]?.enabled)
    .map(([key, name]) => createPresetAdditionalField(
      key,
      getTemplatePresetFieldName(key, draft.dataSourceMode, name),
      draft.fields[key],
      draft.dataSourceMode,
      dateOffsets
    ));
  const fields = [...helperFields, dmField, ...additionalFields];
  const layout = calculatePresetLayout(draft.base, fields);
  fields.forEach((field) => {
    const geom = layout.geometryByFieldName[field.name];
    if (geom) field.geom = { ...geom };
    if (field.barcode) field.barcode.bcH = field.geom.h;
  });
  const issues = validateTemplatePresetDraft(draft, { layout });
  const xml = buildEmptyTemplateXml(draft.base.printerModel, draft.base.printMode, draft.base.widthMm, draft.base.heightMm);
  return {
    ok: !issues.some((issue) => issue.severity === "error"),
    draft,
    issues,
    warnings: issues.filter((issue) => issue.severity === "warning"),
    fields,
    dateOffsets,
    layout,
    xml
  };
}

function commitGeneratedTemplatePreset(result, options = {}) {
  if (!result?.ok) return false;
  const missingOffsets = result.fields
    .filter((field) => field.fldType === "OffsetDateText")
    .filter((field) => !result.dateOffsets.some((offset) => offset.name === field.data.offsetRef));
  if (missingOffsets.length) return false;
  const tab = createTemplateInNewTab(result.xml, options.title || null, {
    markDirty: true,
    source: "preset-builder",
    reuseEmpty: options.reuseEmpty
  });
  if (!tab) return false;
  state.fields = result.fields.map((field) => ({ ...field, geom: { ...field.geom }, _konva: null }));
  state.fieldByName = new Map(state.fields.map((field) => [field.name, field]));
  state.dateOffsets = result.dateOffsets.map((offset) => ({ ...offset, default: { ...offset.default }, current: { ...offset.current } }));
  state.dateOffsetsLoaded = state.dateOffsets.length > 0;
  state.dateOffsetsDirty = state.dateOffsets.length > 0;
  const dm = state.fields.find((field) => field.barcode?.dataMatrix);
  setSelectedNames(dm ? [dm.name] : []);
  state.validation = { invalidPrintableFieldNames: [] };
  pushHistory(true);
  renderAll();
  markActiveTemplateTabDirty();
  onTemplateLoadedIntoActiveTab({ markDirty: true, source: "preset-builder" });
  return true;
}

const BUILDER_COPY = {
  en: {
    choose: "Choose how to create a template.", base: "Template settings", source: "Data source", dm: "DataMatrix settings",
    fields: "Additional fields", summary: "Review and create", back: "Back", next: "Next", create: "Create", cancel: "Cancel",
    empty: "Blank template", preset: "Template builder", server: "Server", printer: "Printer",
    overflow: "Objects do not fit: {names}. Increase the template size or reduce the field set.",
    required: "Complete the required settings before continuing.", composition: "Segments: {segments}",
    kindEmpty: "Blank template", kindEmptyDescription: "Create an empty template for manual editing.",
    kindPreset: "Template builder", kindPresetDescription: "Create a template with DataMatrix and fields.",
    sourceServerFull: "All data from server", sourceServerFullDescription: "DataMatrix and every selected variable field are supplied by the server.",
    sourcePrinterRest: "Only DataMatrix from server", sourcePrinterRestDescription: "The server supplies DataMatrix; dates, time and operator fields are generated on the printer.",
    fieldDateMode: "Date mode", dateCurrent: "Current date", dateCalculated: "Calculated date",
    fieldFormat: "Format", fieldSeparator: "Separator", offsetYears: "Years", offsetMonths: "Months", offsetDays: "Days",
    dmSymbol: "Symbol size", dmSn: "SN value", dmModuleSize: "Module size"
  },
  ru: {
    choose: "Выберите способ создания шаблона.", base: "Настройки шаблона", source: "Источник данных", dm: "Настройки DataMatrix",
    fields: "Дополнительные поля", summary: "Проверка и создание", back: "Назад", next: "Далее", create: "Создать", cancel: "Отмена",
    empty: "Пустой шаблон", preset: "Конструктор", server: "Сервер", printer: "Принтер",
    overflow: "Не помещаются объекты: {names}. Увеличьте шаблон или сократите набор полей.",
    required: "Заполните обязательные настройки.", composition: "Сегменты: {segments}",
    kindEmpty: "Пустой шаблон", kindEmptyDescription: "Создать пустой шаблон для ручного редактирования.",
    kindPreset: "Конструктор шаблона", kindPresetDescription: "Создать готовый с DataMatrix и полями.",
    sourceServerFull: "Все данные с сервера", sourceServerFullDescription: "DataMatrix и все выбранные переменные поля передаются сервером.",
    sourcePrinterRest: "Только DataMatrix с сервера", sourcePrinterRestDescription: "Сервер передаёт DataMatrix, а даты, время и операторские поля формируются принтером.",
    fieldDateMode: "Режим даты", dateCurrent: "Текущая дата", dateCalculated: "Расчётная дата",
    fieldFormat: "Формат", fieldSeparator: "Сепаратор", offsetYears: "Годы", offsetMonths: "Месяцы", offsetDays: "Дни",
    dmSymbol: "Размер символа", dmSn: "Значение SN", dmModuleSize: "Размер модуля"
  }
};
const BUILDER_I18N_KEYS = {
  "builder.kind.empty": "kindEmpty",
  "builder.kind.emptyDescription": "kindEmptyDescription",
  "builder.kind.preset": "kindPreset",
  "builder.kind.presetDescription": "kindPresetDescription",
  "builder.source.serverFull": "sourceServerFull",
  "builder.source.serverFullDescription": "sourceServerFullDescription",
  "builder.source.printerRest": "sourcePrinterRest",
  "builder.source.printerRestDescription": "sourcePrinterRestDescription",
  "builder.field.dateMode": "fieldDateMode",
  "builder.date.current": "dateCurrent",
  "builder.date.calculated": "dateCalculated",
  "builder.field.format": "fieldFormat",
  "builder.field.separator": "fieldSeparator",
  "builder.offset.years": "offsetYears",
  "builder.offset.months": "offsetMonths",
  "builder.offset.days": "offsetDays",
  "builder.dm.symbol": "dmSymbol",
  "builder.dm.sn": "dmSn",
  "builder.dm.moduleSize": "dmModuleSize"
};

let templateBuilderDraft = createDefaultTemplatePresetDraft();
let templateBuilderStep = 0;

function builderCopy(key, values = {}) {
  const lang = typeof getCurrentUiLanguage === "function" ? getCurrentUiLanguage() : "en";
  let text = BUILDER_COPY[lang]?.[key] || BUILDER_COPY.en[key] || key;
  Object.entries(values).forEach(([name, value]) => { text = text.replace(`{${name}}`, String(value)); });
  return text;
}

function readTemplateBuilderDraft() {
  const draft = templateBuilderDraft;
  draft.base = {
    printerModel: elNewTemplatePrinterModel?.value,
    printMode: elNewTemplatePrintMode?.value,
    widthMm: Number(elNewTemplateWidth?.value),
    heightMm: Number(elNewTemplateHeight?.value)
  };
  draft.dataMatrix = {
    symbolSize: $("builderSymbolSize")?.value,
    snValue: $("builderSnValue")?.value,
    moduleSize: Number($("builderModuleSize")?.value)
  };
  TEMPLATE_PRESET_FIELD_ORDER.forEach(([key]) => {
    draft.fields[key].enabled = !!document.querySelector(`[data-builder-field="${key}"]`)?.checked;
  });
  TEMPLATE_PRESET_DATE_KEYS.forEach((key) => {
    const generation = document.querySelector(`[data-builder-date-generation="${key}"]`)?.value;
    const formatValue = document.querySelector(`[data-builder-date-format="${key}"]`)?.value || "dd/MM/yy::en";
    const [format, locale] = formatValue.split("::");
    draft.fields[key] = {
      ...draft.fields[key],
      generation,
      format,
      locale: locale || "en",
      separator: document.querySelector(`[data-builder-date-separator="${key}"]`)?.value ?? ".",
      offset: {
        years: Number(document.querySelector(`[data-builder-offset-years="${key}"]`)?.value),
        months: Number(document.querySelector(`[data-builder-offset-months="${key}"]`)?.value),
        days: Number(document.querySelector(`[data-builder-offset-days="${key}"]`)?.value)
      }
    };
  });
  draft.fields.time.format = $("builderTimeFormat")?.value || "HH:mm";
  draft.fields.time.separator = $("builderTimeSeparator")?.value ?? ":";
  templateBuilderDraft = normalizeTemplatePresetDraft(draft);
  return templateBuilderDraft;
}

function setTemplateBuilderRevealState(element, expanded) {
  if (!element) return;
  element.hidden = false;
  element.classList.toggle("is-open", !!expanded);
  element.setAttribute("aria-hidden", String(!expanded));
  if ("inert" in element) element.inert = !expanded;
}

function syncTemplateBuilderConditionalControls() {
  const draft = readTemplateBuilderDraft();
  TEMPLATE_PRESET_FIELD_ORDER.forEach(([key, defaultName]) => {
    const checkbox = document.querySelector(`[data-builder-field="${key}"]`);
    const choice = checkbox?.closest(".builderFieldChoice");
    const available = isTemplatePresetFieldAvailable(key, draft.dataSourceMode);
    if (choice) choice.hidden = !available;
    if (checkbox) {
      checkbox.disabled = !available;
      if (!available) checkbox.checked = false;
    }
    const displayName = getTemplatePresetFieldName(key, draft.dataSourceMode, defaultName);
    const label = document.querySelector(`[data-builder-field-label="${key}"]`);
    const settingsTitle = document.querySelector(`[data-builder-settings-title="${key}"]`);
    if (label) label.textContent = displayName;
    if (settingsTitle) settingsTitle.textContent = displayName;
  });
  TEMPLATE_PRESET_DATE_KEYS.forEach((key) => {
    const settings = document.querySelector(`[data-builder-settings="${key}"]`);
    const enabled = !!draft.fields[key].enabled;
    const serverFull = draft.dataSourceMode === "server-full";
    setTemplateBuilderRevealState(settings, enabled && !serverFull);
    const generation = document.querySelector(`[data-builder-date-generation="${key}"]`);
    if (generation) {
      generation.disabled = false;
      if (!["printer-current", "printer-offset"].includes(generation.value)) {
        generation.value = key === "expirationDate" ? "printer-offset" : "printer-current";
      }
      if (typeof syncCustomSelectControl === "function") syncCustomSelectControl(generation);
    }
    const offset = document.querySelector(`[data-builder-offset="${key}"]`);
    setTemplateBuilderRevealState(offset, enabled && !serverFull && generation?.value === "printer-offset");
  });
  const timeCheckbox = document.querySelector('[data-builder-field="time"]');
  const timeSettings = document.querySelector('[data-builder-settings="time"]');
  setTemplateBuilderRevealState(timeSettings, !!timeCheckbox?.checked && !timeCheckbox?.disabled);
}

function renderTemplateBuilderSummary() {
  const draft = readTemplateBuilderDraft();
  const preview = generateTemplatePreset(draft);
  const summary = $("builderSummary");
  const validation = $("builderValidation");
  if (summary) {
    const selected = TEMPLATE_PRESET_FIELD_ORDER.filter(([key]) => (
      isTemplatePresetFieldAvailable(key, draft.dataSourceMode) && draft.fields[key].enabled
    ));
    summary.innerHTML = `
      <div class="builderSummary__row"><strong>${draft.base.printerModel} / ${draft.base.printMode}</strong><span>${draft.base.widthMm.toFixed(2)} × ${draft.base.heightMm.toFixed(2)} mm</span></div>
      <div class="builderSummary__row"><strong>DataMatrix ${draft.dataMatrix.symbolSize}</strong><span>SN ${draft.dataMatrix.snValue}</span></div>
      <div class="builderSummary__fields">${selected.map(([key, name]) => `<span>${getTemplatePresetFieldName(key, draft.dataSourceMode, name)} · ${draft.dataSourceMode === "server-full" ? builderCopy("server") : builderCopy("printer")}</span>`).join("") || "DataMatrix only"}</div>`;
  }
  if (validation) {
    validation.textContent = preview.layout?.overflowFieldNames?.length
      ? builderCopy("overflow", { names: preview.layout.overflowFieldNames.join(", ") })
      : "";
  }
  return preview;
}

function getTemplateBuilderStepValidity() {
  const draft = readTemplateBuilderDraft();
  if (templateBuilderStep === 0) return !!draft.creationKind;
  if (templateBuilderStep === 1) return draft.base.widthMm > 0 && draft.base.widthMm <= 53.33 && draft.base.heightMm > 0 && draft.base.heightMm <= 75;
  if (templateBuilderStep === 2) return !!draft.dataSourceMode;
  if (templateBuilderStep === 3) return DATA_MATRIX_SYMBOLS_BY_NAME.has(draft.dataMatrix.symbolSize) && draft.dataMatrix.moduleSize > 0;
  if (templateBuilderStep === 5) return renderTemplateBuilderSummary().ok;
  return true;
}

function renderTemplateBuilderStep() {
  const draft = readTemplateBuilderDraft();
  document.querySelectorAll("[data-builder-step]").forEach((element) => {
    element.hidden = Number(element.dataset.builderStep) !== templateBuilderStep;
  });
  document.querySelectorAll("[data-builder-kind]").forEach((element) => element.classList.toggle("is-selected", element.dataset.builderKind === draft.creationKind));
  document.querySelectorAll("[data-builder-source]").forEach((element) => element.classList.toggle("is-selected", element.dataset.builderSource === draft.dataSourceMode));
  document.querySelectorAll("[data-builder-i18n]").forEach((element) => {
    element.textContent = builderCopy(BUILDER_I18N_KEYS[element.dataset.builderI18n] || element.dataset.builderI18n);
  });
  document.querySelectorAll("[data-builder-i18n-option]").forEach((option) => {
    option.textContent = builderCopy(BUILDER_I18N_KEYS[option.dataset.builderI18nOption] || option.dataset.builderI18nOption);
    const select = option.closest("select");
    if (select && typeof syncCustomSelectControl === "function") syncCustomSelectControl(select);
  });
  const titles = ["choose", "base", "source", "dm", "fields", "summary"];
  if ($("templateBuilderSubtitle")) $("templateBuilderSubtitle").textContent = builderCopy(titles[templateBuilderStep]);
  if ($("templateBuilderProgress")) $("templateBuilderProgress").textContent = templateBuilderStep ? `${templateBuilderStep}/${draft.creationKind === "empty" ? 1 : 5}` : "";
  if ($("btnBuilderBack")) $("btnBuilderBack").hidden = templateBuilderStep === 0;
  const isEmptyReady = draft.creationKind === "empty" && templateBuilderStep === 1;
  if ($("btnBuilderNext")) {
    $("btnBuilderNext").hidden = isEmptyReady || templateBuilderStep === 5;
    $("btnBuilderNext").disabled = !getTemplateBuilderStepValidity();
    $("btnBuilderNext").textContent = builderCopy("next");
  }
  if ($("btnCreateNewTemplate")) {
    $("btnCreateNewTemplate").hidden = !(isEmptyReady || templateBuilderStep === 5);
    $("btnCreateNewTemplate").disabled = !getTemplateBuilderStepValidity();
    $("btnCreateNewTemplate").textContent = builderCopy("create");
  }
  if ($("btnBuilderBack")) $("btnBuilderBack").textContent = builderCopy("back");
  if ($("btnCancelNewTemplate")) $("btnCancelNewTemplate").textContent = builderCopy("cancel");
  syncTemplateBuilderConditionalControls();
  if (templateBuilderStep === 5) renderTemplateBuilderSummary();
  window.setTimeout(() => {
    const active = document.querySelector(`[data-builder-step="${templateBuilderStep}"]`);
    active?.querySelector("button:not([disabled]), input:not([disabled]), select:not([disabled])")?.focus();
  }, 0);
}

function resetTemplateBuilder() {
  templateBuilderDraft = createDefaultTemplatePresetDraft();
  templateBuilderStep = 0;
  if (elNewTemplatePrintMode) elNewTemplatePrintMode.value = TEMPLATE_PRESET_DEFAULT_PRINT_MODE;
  populateNewTemplateOptions();
  const symbolSelect = $("builderSymbolSize");
  if (symbolSelect) populateMaterialSelect(symbolSelect, DATA_MATRIX_SYMBOLS.map((item) => ({ value: item.name, label: item.name })), "22X22");
  if ($("builderSnValue")) $("builderSnValue").value = "000000";
  const moduleSizeSelect = $("builderModuleSize");
  if (moduleSizeSelect) {
    populateMaterialSelect(
      moduleSizeSelect,
      DATA_MATRIX_MODULE_SIZES.map((value) => {
        const formatted = formatDataMatrixModuleSize(value);
        return { value: formatted, label: formatted };
      }),
      "0.50"
    );
  }
  document.querySelectorAll("[data-builder-field]").forEach((checkbox) => { checkbox.checked = false; checkbox.disabled = false; });
  renderTemplateBuilderStep();
}

function initTemplatePresetBuilder() {
  const modal = elNewTemplateModal;
  if (!modal || modal.dataset.builderReady === "1") return;
  modal.dataset.builderReady = "1";
  modal.querySelectorAll("[data-builder-kind]").forEach((button) => button.addEventListener("click", () => {
    templateBuilderDraft.creationKind = button.dataset.builderKind;
    renderTemplateBuilderStep();
  }));
  modal.querySelectorAll("[data-builder-source]").forEach((button) => button.addEventListener("click", () => {
    templateBuilderDraft.dataSourceMode = button.dataset.builderSource;
    renderTemplateBuilderStep();
  }));
  modal.querySelectorAll("input, select").forEach((control) => control.addEventListener("change", () => renderTemplateBuilderStep()));
  $("btnBuilderNext")?.addEventListener("click", () => {
    if (!getTemplateBuilderStepValidity()) return;
    templateBuilderStep += 1;
    renderTemplateBuilderStep();
  });
  $("btnBuilderBack")?.addEventListener("click", () => {
    templateBuilderStep = Math.max(0, templateBuilderStep - 1);
    renderTemplateBuilderStep();
  });
  if (typeof onUiLanguageChange === "function") onUiLanguageChange(renderTemplateBuilderStep);
}

function createTemplateFromBuilderDialog() {
  const draft = readTemplateBuilderDraft();
  if (draft.creationKind === "empty") {
    createNewTemplateFromDialog();
    return true;
  }
  const result = generateTemplatePreset(draft);
  if (!result.ok) {
    renderTemplateBuilderSummary();
    return false;
  }
  const committed = commitGeneratedTemplatePreset(result);
  if (committed) closeNewTemplateModal();
  return committed;
}

globalThis.createDefaultTemplatePresetDraft = createDefaultTemplatePresetDraft;
globalThis.normalizeTemplatePresetDraft = normalizeTemplatePresetDraft;
globalThis.validateTemplatePresetDraft = validateTemplatePresetDraft;
globalThis.generateTemplatePreset = generateTemplatePreset;
globalThis.calculatePresetLayout = calculatePresetLayout;
globalThis.commitGeneratedTemplatePreset = commitGeneratedTemplatePreset;
globalThis.createDataMatrixHelperFields = createDataMatrixHelperFields;
globalThis.createDataMatrixField = createDataMatrixField;
globalThis.initTemplatePresetBuilder = initTemplatePresetBuilder;
globalThis.resetTemplateBuilder = resetTemplateBuilder;
globalThis.createTemplateFromBuilderDialog = createTemplateFromBuilderDialog;
