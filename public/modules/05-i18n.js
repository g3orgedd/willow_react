/* UI i18n dictionary and helpers.
   This module is intentionally standalone: adding it does not translate the app
   until it is loaded and existing UI strings are replaced with t("key").

   Keep technical CIFF/XML values untranslated: Field types, tag names,
   SymbolSize values, printer modes, and date/time format tokens.
*/

const UI_DEFAULT_LANGUAGE = "en";
const UI_LANGUAGE_STORAGE_KEY = "willowXml.uiLanguage";
const UI_LANGUAGES = [
  { code: "en", label: "English", shortLabel: "EN" },
  { code: "ru", label: "Русский", shortLabel: "RU" }
];

const UI_TRANSLATIONS = {
  en: {
    "app.title": "Willow XML CIFF Editor",

    "topbar.create": "Create",
    "topbar.open": "Open",
    "topbar.save": "Save",
    "topbar.undo": "Undo",
    "topbar.redo": "Redo",
    "topbar.pan": "Pan",
    "topbar.grid": "Grid",
    "topbar.snap": "Snap",
    "topbar.align": "Align",
    "topbar.alignShort": "Align",
    "topbar.zoom": "Zoom",

    "panel.tools.title": "Add object",
    "panel.fields.title": "Fields",
    "panel.fields.filter": "Filter fields",
    "panel.fields.all": "All",
    "panel.printed.title": "Printed",
    "panel.printed.subtitle": "Fields",
    "panel.hidden.title": "Hidden",
    "panel.hidden.subtitle": "Fields",
    "panel.search.placeholder": "Search fields",
    "panel.showHidden": "Show hidden fields",
    "panel.hideHidden": "Hide hidden fields",

    "tool.datamatrix": "DataMatrix",
    "tool.text": "Text",
    "tool.date": "Date",
    "tool.time": "Time",
    "tool.offset": "Offset",
    "tool.counter": "Counter",

    "tab.object": "Object",
    "tab.template": "Template",
    "tab.datamatrix": "DataMatrix",
    "tab.offsets": "Offsets",
    "tab.advanced": "Advanced",
    "tab.settings": "Settings",

    "object.title": "Selected object",
    "object.empty": "No object selected",
    "object.emptyHint": "Select an object on the canvas or in the field list.",
    "object.delete": "Delete selected",

    "field.name": "Name",
    "field.printed": "Printed",
    "field.type": "Type",
    "field.x": "X (mm)",
    "field.y": "Y (mm)",
    "field.width": "Width (mm)",
    "field.height": "Height (mm)",
    "field.orientation": "Orientation",
    "field.rotation": "Rotation",
    "field.value": "Value",
    "field.fontSize": "Font size",
    "field.xMag": "XMag (%)",
    "field.maxCharacters": "Max characters",
    "field.printOutput": "Print output",
    "field.fixedText": "Fixed Text",
    "field.userEnteredText": "User Entered Text",
    "field.dateType": "Date type",
    "field.currentDate": "Current Date",
    "field.calculatedDate": "Calculated Date",
    "field.dateFormat": "Date format",
    "field.timeFormat": "Time format",
    "field.separator": "Separator",
    "field.offset": "Offset",

    "counter.digits": "Digits",
    "counter.start": "Start",
    "counter.end": "End",
    "counter.step": "Step",
    "counter.maxValue": "Maximum value for {digits} digits: {value}",

    "datamatrix.title": "DataMatrix",
    "datamatrix.empty": "No DataMatrix object found.",
    "datamatrix.emptyHint": "Create a new DataMatrix or select an existing one.",
    "datamatrix.quietMargin": "QuietMargin",
    "datamatrix.moduleSize": "Module size",
    "datamatrix.symbolSize": "Symbol size",
    "datamatrix.profile": "Profile",
    "datamatrix.applyProfile": "Apply profile",
    "datamatrix.segments": "Segments",
    "datamatrix.addSegment": "Add segment",
    "datamatrix.validationOk": "Profile matches the current SymbolSize.",

    "template.size.title": "Template size",
    "template.printer.title": "Printer settings",
    "template.width": "Width (mm)",
    "template.height": "Height (mm)",
    "template.printerModel": "Printer model",
    "template.printMode": "Print mode",
    "template.sizeLimit": "Limit: {maxWidth} x {maxHeight} mm | Used: {usedWidth} x {usedHeight} mm",
    "template.designedFor": "Header DesignedFor: {value}",

    "offsets.title": "Date offsets",
    "offsets.subtitle": "Manage reusable calculated dates.",
    "offsets.add": "Add offset",
    "offsets.empty": "No DateOffset entries in file.",
    "offsets.current": "Current offset: {date}",
    "offsets.year": "Year",
    "offsets.month": "Month",
    "offsets.day": "Day",

    "validation.title": "Validation",
    "validation.empty": "Validation checks will appear here.",

    "settings.title": "System settings",
    "settings.functionality": "Functionality",
    "settings.changelog": "Changes",
    "advanced.title": "Advanced settings",
    "advanced.hiddenFields": "Hidden fields",
    "advanced.offsets": "Offsets",
    "advanced.dataMatrixDescription": "Code profile and segments",
    "advanced.offsetsDescription": "Calculated template dates",
    "advanced.hiddenFieldsDescription": "Values of non-printed fields",
    "advanced.dataMatrixHint": "Edit the selected DataMatrix profile and segments.",
    "advanced.hiddenEditor": "Hidden field editor",
    "advanced.hiddenEditorHint": "Edit values for non-printed fields.",
    "language.label": "Language",
    "language.en": "English",
    "language.ru": "Russian",
    "theme.label": "Theme",
    "theme.system": "System",
    "theme.light": "Light",
    "theme.dark": "Dark",
    "grid.size": "Grid size",
    "tabs.label": "Open templates",
    "tabs.untitled": "Untitled template",
    "tabs.unsaved": "Unsaved changes",
    "tabs.close": "Close {title}",
    "tabs.add": "Create template in new tab",

    "dialog.createTemplate.title": "Create template",
    "dialog.createTemplate.subtitle": "Choose printer model, print mode, and substrate size.",
    "dialog.createTemplate.sizeHint": "For 53 mm print heads the supported range is 53.33 by 75.00 mm.",
    "dialog.dataMatrix.title": "Add DataMatrix",
    "dialog.dataMatrix.subtitle": "Select the symbol size and serial number length.",
    "dialog.dataMatrix.selectSymbolSize": "Select symbol size",
    "dialog.dataMatrix.snValue": "SN value",
    "dialog.dataMatrix.selectSnValue": "Select SN value",
    "dialog.dataMatrix.selectionRequired": "Select the symbol size and SN value.",
    "dialog.saveTemplate.title": "Save template",
    "dialog.saveTemplate.subtitle": "Enter a template name to save it to this device.",
    "dialog.saveTemplate.name": "Template name",
    "dialog.saveTemplate.nameRequired": "Enter a template name.",
    "dialog.closeTab.title": "Close \"{title}\"?",
    "dialog.closeTab.message": "This template has unsaved changes. If you close it without saving, the information will be lost.",
    "dialog.closeTab.closeWithoutSaving": "Close without saving",
    "dialog.textField.title": "Add text field",
    "dialog.textField.subtitle": "Add a regular fixed text field or select one or more ready-made fields.",
    "dialog.textField.fixedTitle": "Fixed text",
    "dialog.textField.fixedDescription": "Create the same editable fixed text field as before.",
    "dialog.textField.presetsTitle": "Ready-made fields",
    "dialog.textField.presetsDescription": "Select several fields to add them in one vertical stack.",
    "dialog.textField.selectValue": "Select value",
    "dialog.textField.userType": "User entered",
    "dialog.textField.fixedType": "Fixed",
    "dialog.textField.printed": "Printed",
    "dialog.textField.notPrinted": "Not printed",
    "dialog.textField.max": "Max",
    "dialog.textField.add": "Add",
    "dialog.textField.selectionRequired": "Select at least one ready-made field.",
    "dialog.textField.variantRequired": "Select a value for {name}.",
    "dialog.textField.alreadyExists": "This field already exists in the template.",
    "dialog.notification.title": "Notice",
    "dialog.notification.openFileFirst": "Open a CIFF file first.",
    "dialog.replaceTemplate.title": "Replace current template?",
    "dialog.replaceTemplate.message": "The current template will be replaced. Continue?",
    "dialog.fieldName.empty": "Field name cannot be empty.",
    "dialog.fieldName.duplicate": "Field \"{name}\" already exists.",
    "dialog.fileOpenError.title": "Unable to open file",
    "dialog.fileOpenError.message": "The selected file could not be opened. Make sure it is a valid CIFF or XML file.",
    "dialog.documentation.functionalityTitle": "Application functionality",
    "dialog.documentation.changelogTitle": "Latest changes",
    "dialog.cancel": "Cancel",
    "dialog.continue": "Continue",
    "dialog.close": "Close",
    "dialog.create": "Create",
    "dialog.save": "Save",

    "mobile.panels": "Panels",
    "mobile.panelsHint": "Tools and settings",

    "status.openFile": "Open a CIFF file (.ciff/.xml).",
    "status.noTemplate": "Open or create a template.",
    "status.nothingSelected": "Nothing selected.",
    "status.selected": "Selected",
    "status.selectedMultiple": "Selected multiple: {count} items",
    "placement.hint": "Click or tap the template to place the new element. Press Esc to cancel.",

    "common.mixed": "Mixed",
    "common.none": "(none)",
    "common.select": "Select",
    "common.delete": "Delete",
    "number.increase": "Increase value",
    "number.decrease": "Decrease value",

    "separator.none": "No separator",
    "separator.space": "Space ( )",
    "separator.colon": "Colon (:)",
    "separator.dot": "Dot (.)",
    "separator.comma": "Comma (,)",
    "separator.dash": "Dash (-)",
    "separator.backslash": "Backslash (\\)"
  },

  ru: {
    "app.title": "Willow XML CIFF Editor",

    "topbar.create": "Создать",
    "topbar.open": "Открыть",
    "topbar.save": "Сохранить",
    "topbar.undo": "Отменить",
    "topbar.redo": "Повторить",
    "topbar.pan": "Перемещение",
    "topbar.grid": "Сетка",
    "topbar.snap": "Привязка",
    "topbar.align": "Выравнивать",
    "topbar.alignShort": "Выравн.",
    "topbar.zoom": "Масштаб",

    "panel.tools.title": "Добавить объект",
    "panel.fields.title": "Поля",
    "panel.fields.filter": "Фильтр полей",
    "panel.fields.all": "Все",
    "panel.printed.title": "Печатные",
    "panel.printed.subtitle": "Поля",
    "panel.hidden.title": "Скрытые",
    "panel.hidden.subtitle": "Поля",
    "panel.search.placeholder": "Поиск полей",
    "panel.showHidden": "Показать скрытые поля",
    "panel.hideHidden": "Скрыть скрытые поля",

    "tool.datamatrix": "DataMatrix",
    "tool.text": "Текст",
    "tool.date": "Дата",
    "tool.time": "Время",
    "tool.offset": "Смещение",
    "tool.counter": "Счётчик",

    "tab.object": "Объект",
    "tab.template": "Шаблон",
    "tab.datamatrix": "DataMatrix",
    "tab.offsets": "Смещения",
    "tab.advanced": "Дополнительно",
    "tab.settings": "Настройки",

    "object.title": "Выбранный объект",
    "object.empty": "Объект не выбран",
    "object.emptyHint": "Выберите объект на холсте или в списке полей.",
    "object.delete": "Удалить выбранное",

    "field.name": "Имя",
    "field.printed": "Печатается",
    "field.type": "Тип",
    "field.x": "X (мм)",
    "field.y": "Y (мм)",
    "field.width": "Ширина (мм)",
    "field.height": "Высота (мм)",
    "field.orientation": "Ориентация",
    "field.rotation": "Поворот",
    "field.value": "Значение",
    "field.fontSize": "Размер шрифта",
    "field.xMag": "XMag (%)",
    "field.maxCharacters": "Макс. символов",
    "field.printOutput": "Печать объекта",
    "field.fixedText": "Фиксированный текст",
    "field.userEnteredText": "Вводимый текст",
    "field.dateType": "Тип даты",
    "field.currentDate": "Текущая дата",
    "field.calculatedDate": "Расчётная дата",
    "field.dateFormat": "Формат даты",
    "field.timeFormat": "Формат времени",
    "field.separator": "Сепаратор",
    "field.offset": "Смещение",

    "counter.digits": "Разрядов",
    "counter.start": "Начало",
    "counter.end": "Конец",
    "counter.step": "Шаг",
    "counter.maxValue": "Максимальное значение для {digits} разрядов: {value}",

    "datamatrix.title": "DataMatrix",
    "datamatrix.empty": "Объект DataMatrix не найден.",
    "datamatrix.emptyHint": "Создайте новый DataMatrix или выберите существующий.",
    "datamatrix.quietMargin": "QuietMargin",
    "datamatrix.moduleSize": "Размер модуля",
    "datamatrix.symbolSize": "Размер символа",
    "datamatrix.profile": "Профиль",
    "datamatrix.applyProfile": "Применить профиль",
    "datamatrix.segments": "Сегменты",
    "datamatrix.addSegment": "Добавить сегмент",
    "datamatrix.validationOk": "Профиль соответствует текущему SymbolSize.",

    "template.size.title": "Размер шаблона",
    "template.printer.title": "Настройки принтера",
    "template.width": "Ширина (мм)",
    "template.height": "Высота (мм)",
    "template.printerModel": "Модель принтера",
    "template.printMode": "Режим печати",
    "template.sizeLimit": "Лимит: {maxWidth} x {maxHeight} мм | Используется: {usedWidth} x {usedHeight} мм",
    "template.designedFor": "Header DesignedFor: {value}",

    "offsets.title": "Смещения дат",
    "offsets.subtitle": "Управление расчётными датами.",
    "offsets.add": "Добавить смещение",
    "offsets.empty": "В файле нет DateOffset.",
    "offsets.current": "Текущее смещение: {date}",
    "offsets.year": "Год",
    "offsets.month": "Месяц",
    "offsets.day": "День",

    "validation.title": "Проверка",
    "validation.empty": "Здесь появятся результаты проверки.",

    "settings.title": "Системные настройки",
    "settings.functionality": "Функционал",
    "settings.changelog": "Изменения",
    "advanced.title": "Дополнительные настройки",
    "advanced.hiddenFields": "Скрытые поля",
    "advanced.offsets": "Смещения",
    "advanced.dataMatrixDescription": "Профиль и сегменты кода",
    "advanced.offsetsDescription": "Расчётные даты шаблона",
    "advanced.hiddenFieldsDescription": "Значения непечатаемых полей",
    "advanced.dataMatrixHint": "Редактирование профиля и сегментов выбранного DataMatrix.",
    "advanced.hiddenEditor": "Редактор скрытых полей",
    "advanced.hiddenEditorHint": "Редактирование значений непечатаемых полей.",
    "language.label": "Язык",
    "language.en": "Английский",
    "language.ru": "Русский",
    "theme.label": "Тема",
    "theme.system": "Системная",
    "theme.light": "Светлая",
    "theme.dark": "Тёмная",
    "grid.size": "Размер сетки",
    "tabs.label": "Открытые шаблоны",
    "tabs.untitled": "Новый шаблон",
    "tabs.unsaved": "Несохранённые изменения",
    "tabs.close": "Закрыть {title}",
    "tabs.add": "Создать шаблон в новой вкладке",

    "dialog.createTemplate.title": "Создать шаблон",
    "dialog.createTemplate.subtitle": "Выберите модель принтера, режим печати и размер области.",
    "dialog.createTemplate.sizeHint": "Для голов 53 мм доступен диапазон 53.33 на 75.00 мм.",
    "dialog.dataMatrix.title": "Добавить DataMatrix",
    "dialog.dataMatrix.subtitle": "Выберите размер символа и длину серийного номера.",
    "dialog.dataMatrix.selectSymbolSize": "Выберите размер символа",
    "dialog.dataMatrix.snValue": "Значение SN",
    "dialog.dataMatrix.selectSnValue": "Выберите значение SN",
    "dialog.dataMatrix.selectionRequired": "Выберите размер символа и значение SN.",
    "dialog.saveTemplate.title": "Сохранить шаблон",
    "dialog.saveTemplate.subtitle": "Введите название шаблона, чтобы сохранить его на устройство.",
    "dialog.saveTemplate.name": "Название шаблона",
    "dialog.saveTemplate.nameRequired": "Введите название шаблона.",
    "dialog.closeTab.title": "Закрыть «{title}»?",
    "dialog.closeTab.message": "В шаблоне есть несохранённые изменения. Если закрыть его без сохранения, информация будет утеряна.",
    "dialog.closeTab.closeWithoutSaving": "Закрыть без сохранения",
    "dialog.textField.title": "Добавить текстовое поле",
    "dialog.textField.subtitle": "Добавьте обычный фиксированный текст или выберите одно или несколько готовых полей.",
    "dialog.textField.fixedTitle": "Фиксированный текст",
    "dialog.textField.fixedDescription": "Создать такое же редактируемое текстовое поле, как раньше.",
    "dialog.textField.presetsTitle": "Готовые поля",
    "dialog.textField.presetsDescription": "Выберите несколько полей, чтобы добавить их одной вертикальной группой.",
    "dialog.textField.selectValue": "Выберите значение",
    "dialog.textField.userType": "Вводимый текст",
    "dialog.textField.fixedType": "Фиксированный текст",
    "dialog.textField.printed": "Печатается",
    "dialog.textField.notPrinted": "Не печатается",
    "dialog.textField.max": "Макс.",
    "dialog.textField.add": "Добавить",
    "dialog.textField.selectionRequired": "Выберите хотя бы одно готовое поле.",
    "dialog.textField.variantRequired": "Выберите значение для поля {name}.",
    "dialog.textField.alreadyExists": "Это поле уже существует в шаблоне.",
    "dialog.notification.title": "Уведомление",
    "dialog.notification.openFileFirst": "Сначала откройте CIFF-файл.",
    "dialog.replaceTemplate.title": "Заменить текущий шаблон?",
    "dialog.replaceTemplate.message": "Текущий шаблон будет заменён. Продолжить?",
    "dialog.fieldName.empty": "Имя поля не может быть пустым.",
    "dialog.fieldName.duplicate": "Поле «{name}» уже существует.",
    "dialog.fileOpenError.title": "Не удалось открыть файл",
    "dialog.fileOpenError.message": "Выбранный файл не удалось открыть. Убедитесь, что это корректный файл CIFF или XML.",
    "dialog.documentation.functionalityTitle": "Функционал приложения",
    "dialog.documentation.changelogTitle": "Последние изменения",
    "dialog.cancel": "Отмена",
    "dialog.continue": "Продолжить",
    "dialog.close": "Закрыть",
    "dialog.create": "Создать",
    "dialog.save": "Сохранить",

    "mobile.panels": "Панели",
    "mobile.panelsHint": "Инструменты и настройки",

    "status.openFile": "Откройте CIFF-файл (.ciff/.xml).",
    "status.noTemplate": "Откройте или создайте шаблон.",
    "status.nothingSelected": "Ничего не выбрано.",
    "status.selected": "Выбрано",
    "status.selectedMultiple": "Выбрано несколько: {count}",
    "placement.hint": "Нажмите на шаблон, чтобы разместить новый элемент. Esc — отмена.",

    "common.mixed": "Разные значения",
    "common.none": "(нет)",
    "common.select": "Выбрать",
    "common.delete": "Удалить",
    "number.increase": "Увеличить значение",
    "number.decrease": "Уменьшить значение",

    "separator.none": "Без сепаратора",
    "separator.space": "Пробел ( )",
    "separator.colon": "Двоеточие (:)",
    "separator.dot": "Точка (.)",
    "separator.comma": "Запятая (,)",
    "separator.dash": "Тире (-)",
    "separator.backslash": "Обратный слэш (\\)"
  }
};

const UI_TRANSLATION_TARGETS = [
  { selector: "title", key: "app.title" },

  { selector: "#btnNewTemplate span", key: "topbar.create" },
  { selector: "#btnNewTemplate", key: "dialog.createTemplate.title", attr: "aria-label" },
  { selector: "#btnNewTemplate", key: "dialog.createTemplate.title", attr: "title" },
  { selector: "#btnOpenFile span", key: "topbar.open" },
  { selector: "#btnOpenFile", key: "topbar.open", attr: "aria-label" },
  { selector: "#btnOpenFile", key: "topbar.open", attr: "title" },
  { selector: "#btnSave span", key: "topbar.save" },
  { selector: "#btnSave", key: "topbar.save", attr: "aria-label" },
  { selector: "#btnSave", key: "topbar.save", attr: "title" },
  { selector: "#btnUndo", key: "topbar.undo", attr: "aria-label" },
  { selector: "#btnUndo", key: "topbar.undo", attr: "title" },
  { selector: "#btnRedo", key: "topbar.redo", attr: "aria-label" },
  { selector: "#btnRedo", key: "topbar.redo", attr: "title" },
  { selector: "#btnPanMode span", key: "topbar.pan" },
  { selector: "#btnPanMode", key: "topbar.pan", attr: "aria-label" },
  { selector: "#btnPanMode", key: "topbar.pan", attr: "title" },
  { selector: "label[for='toggleGrid'] span", key: "topbar.grid" },
  { selector: "label[for='toggleSnap'] span", key: "topbar.snap" },
  { selector: "#toggleAlign + .utilityToggle__label .utilityToggle__full", key: "topbar.align" },
  { selector: "#toggleAlign + .utilityToggle__label .utilityToggle__short", key: "topbar.alignShort" },
  { selector: "label[for='zoomRange']", key: "topbar.zoom" },

  { selector: ".toolgrid", key: "panel.tools.title", attr: "aria-label" },
  { selector: "#fieldBrowserTitle", key: "panel.fields.title" },
  { selector: ".fieldFilter", key: "panel.fields.filter", attr: "aria-label" },
  { selector: "[data-field-filter-label='printed']", key: "panel.printed.title" },
  { selector: "[data-field-filter-label='hidden']", key: "panel.hidden.title" },

  { selector: "#addDataMatrix span", key: "tool.datamatrix" },
  { selector: "#addFixedText span", key: "tool.text" },
  { selector: "#addDateText span", key: "tool.date" },
  { selector: "#addTimeText span", key: "tool.time" },
  { selector: "#addOffsetDateText span", key: "tool.offset" },
  { selector: "#addCounterText span", key: "tool.counter" },

  { selector: "#fieldSearch", key: "panel.search.placeholder", attr: "placeholder" },
  { selector: "#searchField", key: "panel.search.placeholder" },
  { selector: "#btnShowHiddenOnCanvas", key: "panel.showHidden", attr: "aria-label" },
  { selector: "#btnShowHiddenOnCanvas", key: "panel.showHidden", attr: "title" },

  { selector: "#object_tab", key: "tab.object" },
  { selector: "#template_tab", key: "tab.template" },
  { selector: "#advanced_tab", key: "tab.advanced" },
  { selector: "#settings_tab", key: "tab.settings" },

  { selector: "#tab-object > .panel__title", key: "object.title" },
  { selector: "#btnDelete", key: "object.delete" },
  { selector: "#tab-template .sectionBlock:nth-of-type(1) .panel__title", key: "template.size.title" },
  { selector: "#tab-template .sectionBlock:nth-of-type(2) .panel__title", key: "template.printer.title" },
  { selector: "#tab-advanced > .panel__title", key: "advanced.title" },
  { selector: "#addOffset", key: "offsets.add", attr: "aria-label" },
  { selector: "#addOffset", key: "offsets.add", attr: "title" },
  { selector: "#btnOpenDataMatrixEditor span", key: "datamatrix.title" },
  { selector: "#btnOpenOffsetsEditor span", key: "advanced.offsets" },
  { selector: "#btnOpenHiddenFieldsEditor span", key: "advanced.hiddenFields" },
  { selector: "#dataMatrixEditorDescription", key: "advanced.dataMatrixDescription" },
  { selector: "#offsetsEditorDescription", key: "advanced.offsetsDescription" },
  { selector: "#hiddenFieldsEditorDescription", key: "advanced.hiddenFieldsDescription" },
  { selector: "#dataMatrixEditorModalTitle", key: "datamatrix.title" },
  { selector: "#dataMatrixEditorModalSubtitle", key: "advanced.dataMatrixHint" },
  { selector: "#offsetsEditorModalTitle", key: "offsets.title" },
  { selector: "#offsetsEditorModalSubtitle", key: "offsets.subtitle" },
  { selector: "#hiddenFieldsEditorModalTitle", key: "advanced.hiddenFields" },
  { selector: "#hiddenFieldsEditorModalSubtitle", key: "advanced.hiddenEditorHint" },
  { selector: "#btnCloseDataMatrixEditor", key: "dialog.close" },
  { selector: "#btnCloseOffsetsEditor", key: "dialog.close" },
  { selector: "#btnCloseHiddenFieldsEditor", key: "dialog.close" },
  { selector: "#tab-settings > .panel__title", key: "settings.title" },
  { selector: "label[for='uiLanguageSelect']", key: "language.label" },
  { selector: "label[for='uiThemeSelect']", key: "theme.label" },
  { selector: "label[for='gridSizeSelect']", key: "grid.size" },
  { selector: "#templateTabs", key: "tabs.label", attr: "aria-label" },
  { selector: "#btnAddTemplateTab", key: "tabs.add", attr: "aria-label" },
  { selector: "#btnAddTemplateTab", key: "tabs.add", attr: "title" },
  { selector: "#btnOpenFunctionality", key: "settings.functionality" },
  { selector: "#btnOpenChangelog", key: "settings.changelog" },

  { selector: "#mobilePanelMenuToggle", key: "mobile.panels", attr: "aria-label" },
  { selector: "#mobilePanelMenuToggle", key: "mobile.panels", attr: "title" },
  { selector: "#mobilePanelMenu", key: "mobile.panels", attr: "aria-label" },
  { selector: "#mobilePanelMenu .panel__title", key: "mobile.panels" },
  { selector: "#mobilePanelMenu .muted", key: "mobile.panelsHint" },
  { selector: "#mobilePanelMenuClose", key: "dialog.close", attr: "aria-label" },
  { selector: "#mobilePanelMenuClose", key: "dialog.close", attr: "title" },

  { selector: "#newTemplateTitle", key: "dialog.createTemplate.title" },
  { selector: "#newTemplateModal .modal__subtitle", key: "dialog.createTemplate.subtitle" },
  { selector: "label[for='newTemplatePrinterModel']", key: "template.printerModel" },
  { selector: "label[for='newTemplatePrintMode']", key: "template.printMode" },
  { selector: "label[for='newTemplateWidth']", key: "template.width" },
  { selector: "label[for='newTemplateHeight']", key: "template.height" },
  { selector: "#newTemplateModal .note", key: "dialog.createTemplate.sizeHint" },
  { selector: "#btnCancelNewTemplate", key: "dialog.cancel" },
  { selector: "#btnCreateNewTemplate", key: "dialog.create" },
  { selector: "#dataMatrixModalTitle", key: "dialog.dataMatrix.title" },
  { selector: "#dataMatrixModalSubtitle", key: "dialog.dataMatrix.subtitle" },
  { selector: "label[for='newDataMatrixSymbolSize']", key: "datamatrix.symbolSize" },
  { selector: "#newDataMatrixSymbolSize option[value='']", key: "dialog.dataMatrix.selectSymbolSize" },
  { selector: "label[for='newDataMatrixSnValue']", key: "dialog.dataMatrix.snValue" },
  { selector: "#newDataMatrixSnValue option[value='']", key: "dialog.dataMatrix.selectSnValue" },
  { selector: "#btnCancelDataMatrix", key: "dialog.cancel" },
  { selector: "#btnConfirmDataMatrix", key: "dialog.textField.add" },
  { selector: "#saveTemplateTitle", key: "dialog.saveTemplate.title" },
  { selector: "#saveTemplateSubtitle", key: "dialog.saveTemplate.subtitle" },
  { selector: "label[for='saveTemplateName']", key: "dialog.saveTemplate.name" },
  { selector: "#btnCancelSaveTemplate", key: "dialog.cancel" },
  { selector: "#btnConfirmSaveTemplate", key: "dialog.save" },
  { selector: "#btnCancelCloseTab", key: "dialog.cancel" },
  { selector: "#btnCloseTabWithoutSaving", key: "dialog.closeTab.closeWithoutSaving" },
  { selector: "#btnSaveAndCloseTab", key: "dialog.save" },
  { selector: "#textFieldModalTitle", key: "dialog.textField.title" },
  { selector: "#textFieldModalSubtitle", key: "dialog.textField.subtitle" },
  { selector: "#textFieldModeFixedTitle", key: "dialog.textField.fixedTitle" },
  { selector: "#textFieldModeFixedDescription", key: "dialog.textField.fixedDescription" },
  { selector: "#textFieldModePresetsTitle", key: "dialog.textField.presetsTitle" },
  { selector: "#textFieldModePresetsDescription", key: "dialog.textField.presetsDescription" },
  { selector: ".textPresetCard__variant option[value='']", key: "dialog.textField.selectValue" },
  { selector: ".textPresetTypeUser", key: "dialog.textField.userType" },
  { selector: ".textPresetTypeFixed", key: "dialog.textField.fixedType" },
  { selector: ".textPresetPrintPrinted", key: "dialog.textField.printed" },
  { selector: ".textPresetPrintHidden", key: "dialog.textField.notPrinted" },
  { selector: ".textPresetMaxLabel", key: "dialog.textField.max" },
  { selector: "#btnCancelTextField", key: "dialog.cancel" },
  { selector: "#btnConfirmTextField", key: "dialog.textField.add" },
  { selector: "#confirmationModalTitle", key: "dialog.replaceTemplate.title" },
  { selector: "#confirmationModalMessage", key: "dialog.replaceTemplate.message" },
  { selector: "#btnCancelConfirmation", key: "dialog.cancel" },
  { selector: "#btnConfirmConfirmation", key: "dialog.continue" },
  { selector: "#btnCloseNotification", key: "dialog.close" },
  { selector: "#btnCloseDocumentation", key: "dialog.close" },
  { selector: ".customNumber__button--up", key: "number.increase", attr: "aria-label" },
  { selector: ".customNumber__button--down", key: "number.decrease", attr: "aria-label" }
];

let currentUiLanguage = getSavedUiLanguage();
const uiLanguageChangeListeners = new Set();

function normalizeUiLanguage(language) {
  const code = String(language ?? "").toLowerCase();
  return UI_LANGUAGES.some((item) => item.code === code) ? code : UI_DEFAULT_LANGUAGE;
}

function getSavedUiLanguage() {
  try {
    return normalizeUiLanguage(globalThis.localStorage?.getItem(UI_LANGUAGE_STORAGE_KEY));
  } catch {
    return UI_DEFAULT_LANGUAGE;
  }
}

function saveUiLanguage(language) {
  const nextLanguage = normalizeUiLanguage(language);
  try {
    globalThis.localStorage?.setItem(UI_LANGUAGE_STORAGE_KEY, nextLanguage);
  } catch {
    // localStorage can be unavailable in restricted contexts.
  }
  return nextLanguage;
}

function getCurrentUiLanguage() {
  return currentUiLanguage;
}

function onUiLanguageChange(listener) {
  if (typeof listener !== "function") return () => {};
  uiLanguageChangeListeners.add(listener);
  return () => uiLanguageChangeListeners.delete(listener);
}

function formatUiTranslation(template, params = {}) {
  return String(template).replace(/\{(\w+)\}/g, (match, key) => (
    Object.prototype.hasOwnProperty.call(params, key) ? String(params[key]) : match
  ));
}

function translateUi(key, params = {}, language = currentUiLanguage) {
  const currentLanguage = normalizeUiLanguage(language);
  const fallbackDictionary = UI_TRANSLATIONS[UI_DEFAULT_LANGUAGE] || {};
  const dictionary = UI_TRANSLATIONS[currentLanguage] || fallbackDictionary;
  const template = dictionary[key] ?? fallbackDictionary[key] ?? key;
  return formatUiTranslation(template, params);
}

function translateUiElement(target, language = currentUiLanguage) {
  const nodes = Array.from(document.querySelectorAll(target.selector));
  nodes.forEach((node) => {
    const value = translateUi(target.key, target.params || {}, language);
    if (target.attr) node.setAttribute(target.attr, value);
    else node.textContent = value;
  });
}

function applyUiTranslations(root = document, language = currentUiLanguage) {
  if (!root || typeof root.querySelectorAll !== "function") return;
  document.documentElement.lang = language;
  document.title = translateUi("app.title", {}, language);
  UI_TRANSLATION_TARGETS.forEach((target) => translateUiElement(target, language));

  const propsEmpty = document.querySelector("#propsEmpty");
  if (propsEmpty) {
    propsEmpty.innerHTML = `${translateUi("object.empty", {}, language)}<br>${translateUi("object.emptyHint", {}, language)}`;
  }
  const dmEmpty = document.querySelector("#dmEmpty");
  if (dmEmpty) {
    dmEmpty.innerHTML = `${translateUi("datamatrix.empty", {}, language)}<br>${translateUi("datamatrix.emptyHint", {}, language)}`;
  }
}

function updateUiLanguageControls(language = currentUiLanguage) {
  document.querySelectorAll("[data-ui-language-select]").forEach((select) => {
    select.innerHTML = "";
    UI_LANGUAGES.forEach((item) => {
      const option = document.createElement("option");
      option.value = item.code;
      option.textContent = translateUi(`language.${item.code}`, {}, language);
      select.appendChild(option);
    });
    select.value = language;
    if (typeof enhanceSelectControl === "function") enhanceSelectControl(select);
  });
}

function setUiLanguage(language, opts = {}) {
  const nextLanguage = saveUiLanguage(language);
  if (nextLanguage === currentUiLanguage && !opts.force) return currentUiLanguage;
  currentUiLanguage = nextLanguage;
  applyUiTranslations(document, currentUiLanguage);
  updateUiLanguageControls(currentUiLanguage);
  if (opts.notify !== false) {
    uiLanguageChangeListeners.forEach((listener) => listener(currentUiLanguage));
  }
  return currentUiLanguage;
}

function initUiLanguageControls() {
  document.querySelectorAll("[data-ui-language-select]").forEach((select) => {
    select.addEventListener("change", () => setUiLanguage(select.value));
  });
  setUiLanguage(currentUiLanguage, { force: true, notify: false });
}

globalThis.UI_DEFAULT_LANGUAGE = UI_DEFAULT_LANGUAGE;
globalThis.UI_LANGUAGE_STORAGE_KEY = UI_LANGUAGE_STORAGE_KEY;
globalThis.UI_LANGUAGES = UI_LANGUAGES;
globalThis.UI_TRANSLATIONS = UI_TRANSLATIONS;
globalThis.UI_TRANSLATION_TARGETS = UI_TRANSLATION_TARGETS;
globalThis.normalizeUiLanguage = normalizeUiLanguage;
globalThis.getSavedUiLanguage = getSavedUiLanguage;
globalThis.saveUiLanguage = saveUiLanguage;
globalThis.getCurrentUiLanguage = getCurrentUiLanguage;
globalThis.onUiLanguageChange = onUiLanguageChange;
globalThis.formatUiTranslation = formatUiTranslation;
globalThis.translateUi = translateUi;
globalThis.applyUiTranslations = applyUiTranslations;
globalThis.setUiLanguage = setUiLanguage;
globalThis.initUiLanguageControls = initUiLanguageControls;
globalThis.t = translateUi;
