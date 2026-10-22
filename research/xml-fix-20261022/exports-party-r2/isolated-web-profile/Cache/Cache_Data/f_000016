/* UI i18n dictionary and helpers.
   This module is intentionally standalone: adding it does not translate the app
   until it is loaded and existing UI strings are replaced with t("key").

   Keep technical CIFF/XML values untranslated: Field types, tag names,
   SymbolSize values, printer modes, and date/time format tokens.
*/

const UI_DEFAULT_LANGUAGE = "en";
const UI_LANGUAGE_STORAGE_KEY = "glyphXml.uiLanguage";
const UI_LANGUAGES = [
  { code: "en", label: "English", shortLabel: "EN" },
  { code: "ru", label: "Русский", shortLabel: "RU" }
];

const UI_TRANSLATIONS = {
  en: {
    "app.title": "Glyph Studio",

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
    "topbar.zoomReset": "Reset zoom to 100%",

    "canvas.precisionMove": "Precise object movement",
    "canvas.moveUp": "Move selection up by {step} mm",
    "canvas.moveLeft": "Move selection left by {step} mm",
    "canvas.moveRight": "Move selection right by {step} mm",
    "canvas.moveDown": "Move selection down by {step} mm",
    "move.step": "Move step (mm)",
    "move.stepValue": "Move step: {step} mm",

    "panel.tools.title": "Add",
    "panel.fields.title": "Objects",
    "panel.fields.filter": "Filter objects",
    "panel.fields.all": "All",
    "panel.printed.title": "Printed",
    "panel.printed.subtitle": "Fields",
    "panel.hidden.title": "Hidden",
    "panel.hidden.subtitle": "Fields",
    "panel.search.placeholder": "Search objects",
    "panel.showHidden": "Show hidden fields",
    "panel.hideHidden": "Hide hidden fields",
    "panel.closeSearch": "Clear and close search",
    "panel.collapse": "Collapse objects panel",
    "panel.expand": "Expand objects panel",
    "panel.objectActions": "Actions for {name}",

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

    "inspector.title": "Properties",
    "inspector.objectTitle": "Properties",
    "inspector.templateTitle": "Properties",
    "inspector.noTemplate": "No template open",
    "inspector.collapse": "Collapse inspector",
    "inspector.expand": "Expand inspector",
    "inspector.objectActions": "Object actions",
    "inspector.appSettings": "Application settings",
    "inspector.advanced": "Advanced",
    "inspector.section.basic": "Basic",
    "inspector.section.geometry": "Geometry",
    "inspector.section.content": "Content",
    "inspector.section.text": "Text",
    "inspector.section.datamatrix": "DataMatrix",
    "inspector.section.size": "Size",
    "inspector.section.printer": "Printer",
    "inspector.section.workspace": "Workspace",

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
    "field.characterCount": "Characters: {count}",
    "field.fontSize": "Font size",
    "field.fontFamily": "Font",
    "field.fontStyle": "Font style",
    "field.fontRegular": "Regular",
    "field.fontBold": "Bold",
    "field.fontItalic": "Italic",
    "field.fontBoldItalic": "Bold italic",
    "field.fontUnavailable": "not installed",
    "field.fontUnavailablePreview": "Install this font for an accurate preview. Its original name is preserved in the file.",
    "field.fontMeasureFailed": "The selected font could not be measured. Please try saving again.",
    "field.xMag": "XMag (%)",
    "field.maxCharacters": "Max characters",
    "field.printOutput": "Print output",
    "field.fixedText": "Fixed Text",
    "field.userEnteredText": "User Entered Text",
    "field.offsetDate": "Date with offset",
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
    "datamatrix.symbolSize": "Code format",
    "datamatrix.profile": "Profile",
    "datamatrix.applyProfile": "Apply profile",
    "datamatrix.segments": "Segments",
    "datamatrix.addSegment": "Add segment",
    "datamatrix.moveSegmentUp": "Move segment up",
    "datamatrix.moveSegmentDown": "Move segment down",
    "datamatrix.deleteSegment": "Delete segment",
    "datamatrix.validationOk": "Profile matches the current SymbolSize.",

    "template.size.title": "Template size",
    "template.printer.title": "Printer settings",
    "template.width": "Width (mm)",
    "template.height": "Height (mm)",
    "template.printerModel": "Printer model",
    "template.printMode": "Print mode",
    "template.sizeLimit": "Limit: {maxWidth} × {maxHeight} mm\nUsed: {usedWidth} × {usedHeight} mm",
    "template.sizeLimitExceeded": "Template size {width} × {height} mm exceeds the selected printer limit {maxWidth} × {maxHeight} mm.",
    "template.designedFor": "Header DesignedFor: {value}",

    "offsets.title": "Date offsets",
    "offsets.subtitle": "Manage reusable calculated dates.",
    "offsets.add": "Add offset",
    "offsets.empty": "No DateOffset entries in file.",
    "offsets.section": "Offsets",
    "offsets.name": "Offset name",
    "offsets.delete": "Delete offset",
    "offsets.calculatedDate": "Calculated date",
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
    "advanced.offsetEditor": "Date offset editor",
    "advanced.dataMatrixDescription": "Code profile and segments",
    "advanced.dataMatrixProfile": "DataMatrix profile",
    "advanced.offsetsDescription": "Calculated template dates",
    "advanced.hiddenFieldsDescription": "Values of non-printed fields",
    "advanced.dataMatrixHint": "Edit the selected DataMatrix profile and segments.",
    "advanced.hiddenEditor": "Hidden field editor",
    "advanced.hiddenEditorHint": "Edit values for non-printed fields.",
    "hiddenFields.empty": "No hidden fields in this template.",
    "language.label": "Language",
    "language.en": "English",
    "language.ru": "Russian",
    "theme.label": "Theme",
    "theme.system": "System",
    "theme.light": "Light",
    "theme.dark": "Dark",
    "grid.size": "Grid size (mm)",
    "tabs.label": "Open templates",
    "tabs.untitled": "Untitled template",
    "tabs.unsaved": "Unsaved changes",
    "tabs.close": "Close {title}",
    "tabs.add": "Create template in new tab",
    "tabs.manage": "Manage tabs",
    "tabs.menu": "Tab actions",
    "tabs.closeCurrent": "Close current",
    "tabs.closePlain": "Close",
    "tabs.closeOthers": "Close others",
    "tabs.closeRight": "Close tabs to the right",
    "tabs.closeAll": "Close all",

    "dialog.createTemplate.title": "Create template",
    "dialog.createTemplate.subtitle": "Choose printer model, print mode, and substrate size.",
    "dialog.createTemplate.sizeHint": "For 53 mm print heads the supported range is 53.33 by 75.00 mm.",
    "dialog.createTemplate.sizeHint32": "For 32 mm print heads the supported range is 32.00 by 75.00 mm.",
    "dialog.createTemplate.sizeHint107": "For 107 mm print heads the supported range is 106.67 by 75.00 mm.",
    "dialog.dataMatrix.title": "Add DataMatrix",
    "dialog.dataMatrix.subtitle": "Select the code format and serial number length.",
    "dialog.dataMatrix.selectSymbolSize": "Select code format",
    "dialog.dataMatrix.snValue": "SN value",
    "dialog.dataMatrix.selectSnValue": "Select SN value",
    "dialog.dataMatrix.selectionRequired": "Select the code format and SN value.",
    "dialog.dataMatrix.compositionConflictTitle": "Incompatible DataMatrix profiles",
    "dialog.dataMatrix.compositionConflictMessage": "DataMatrix profiles with different service-field compositions cannot share one template. Conflicting fields: {names}.",
    "dialog.saveTemplate.title": "Save template",
    "dialog.saveTemplate.subtitle": "Enter a template name to save it to this device.",
    "dialog.saveTemplate.name": "Template name",
    "dialog.saveTemplate.nameRequired": "Enter a template name.",
    "dialog.closeTab.title": "Close \"{title}\"?",
    "dialog.closeTab.message": "This template has unsaved changes. If you close it without saving, the information will be lost.",
    "dialog.closeTab.closeWithoutSaving": "Close without saving",
    "dialog.closeTabs.title": "There are unsaved changes",
    "dialog.closeTabs.messageOne": "{count} template has unsaved changes.",
    "dialog.closeTabs.message": "{count} templates have unsaved changes.",
    "dialog.closeTabs.saveAllAndClose": "Save all and close",
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
    "dialog.fileOpenError.unsupportedUnits": "This file uses a coordinate unit that Glyph cannot edit reliably. Open it in ClariSoft and save it with millimetre coordinates. The current document has not changed.",
    "dialog.fileOpenError.invalidDimensions": "The file must contain valid, non-negative ImageWidth and ImageHeight values. Any specified MaxImageWidth and MaxImageHeight values must also be non-negative integers. The current document has not changed.",
    "dialog.hiddenFieldSpace.title": "Not enough printer workspace",
    "dialog.hiddenFieldSpace.message": "The service fields could not be placed inside the printer hardware limits: {names}.",
    "dialog.saveCompatibilityError.title": "Cannot save template",
    "dialog.saveCompatibilityError.message": "The CIFF compatibility check failed.",
    "dialog.unsupportedFile.title": "Unsupported file format",
    "dialog.unsupportedFile.message": "Only CIFF or XML template files can be opened.",
    "dropZone.title": "Drop the file to open the template",
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
    "common.mm": "mm",
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
    "app.title": "Glyph Studio",

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
    "topbar.zoomReset": "Вернуть масштаб к 100%",

    "canvas.precisionMove": "Точное перемещение объектов",
    "canvas.moveUp": "Переместить выделение вверх на {step} мм",
    "canvas.moveLeft": "Переместить выделение влево на {step} мм",
    "canvas.moveRight": "Переместить выделение вправо на {step} мм",
    "canvas.moveDown": "Переместить выделение вниз на {step} мм",
    "move.step": "Шаг перемещения (мм)",
    "move.stepValue": "Шаг перемещения: {step} мм",

    "panel.tools.title": "Добавить",
    "panel.fields.title": "Объекты",
    "panel.fields.filter": "Фильтр объектов",
    "panel.fields.all": "Все",
    "panel.printed.title": "Печатные",
    "panel.printed.subtitle": "Поля",
    "panel.hidden.title": "Скрытые",
    "panel.hidden.subtitle": "Поля",
    "panel.search.placeholder": "Поиск объектов",
    "panel.showHidden": "Показать скрытые поля",
    "panel.hideHidden": "Скрыть скрытые поля",
    "panel.closeSearch": "Очистить и закрыть поиск",
    "panel.collapse": "Свернуть панель объектов",
    "panel.expand": "Развернуть панель объектов",
    "panel.objectActions": "Действия для {name}",

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

    "inspector.title": "Свойства",
    "inspector.objectTitle": "Свойства",
    "inspector.templateTitle": "Свойства",
    "inspector.noTemplate": "Шаблон не открыт",
    "inspector.collapse": "Свернуть инспектор",
    "inspector.expand": "Развернуть инспектор",
    "inspector.objectActions": "Действия с объектом",
    "inspector.appSettings": "Настройки приложения",
    "inspector.advanced": "Дополнительно",
    "inspector.section.basic": "Основное",
    "inspector.section.geometry": "Геометрия",
    "inspector.section.content": "Содержимое",
    "inspector.section.text": "Текст",
    "inspector.section.datamatrix": "DataMatrix",
    "inspector.section.size": "Размер",
    "inspector.section.printer": "Принтер",
    "inspector.section.workspace": "Рабочая область",

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
    "field.characterCount": "Символов: {count}",
    "field.fontSize": "Размер шрифта",
    "field.fontFamily": "Шрифт",
    "field.fontStyle": "Начертание",
    "field.fontRegular": "Обычное",
    "field.fontBold": "Полужирное",
    "field.fontItalic": "Курсив",
    "field.fontBoldItalic": "Полужирный курсив",
    "field.fontUnavailable": "не установлен",
    "field.fontUnavailablePreview": "Установите этот шрифт для точного предпросмотра. Его исходное название сохраняется в файле.",
    "field.fontMeasureFailed": "Не удалось рассчитать размер выбранного шрифта. Повторите сохранение.",
    "field.xMag": "XMag (%)",
    "field.maxCharacters": "Макс. символов",
    "field.printOutput": "Печать объекта",
    "field.fixedText": "Фиксированный текст",
    "field.userEnteredText": "Вводимый текст",
    "field.offsetDate": "Дата со смещением",
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
    "datamatrix.symbolSize": "Формат кода",
    "datamatrix.profile": "Профиль",
    "datamatrix.applyProfile": "Применить профиль",
    "datamatrix.segments": "Сегменты",
    "datamatrix.addSegment": "Добавить сегмент",
    "datamatrix.moveSegmentUp": "Переместить сегмент вверх",
    "datamatrix.moveSegmentDown": "Переместить сегмент вниз",
    "datamatrix.deleteSegment": "Удалить сегмент",
    "datamatrix.validationOk": "Профиль соответствует текущему SymbolSize.",

    "template.size.title": "Размер шаблона",
    "template.printer.title": "Настройки принтера",
    "template.width": "Ширина (мм)",
    "template.height": "Высота (мм)",
    "template.printerModel": "Модель принтера",
    "template.printMode": "Режим печати",
    "template.sizeLimit": "Лимит: {maxWidth} × {maxHeight} мм\nИспользуется: {usedWidth} × {usedHeight} мм",
    "template.sizeLimitExceeded": "Размер шаблона {width} × {height} мм превышает лимит выбранного принтера {maxWidth} × {maxHeight} мм.",
    "template.designedFor": "Header DesignedFor: {value}",

    "offsets.title": "Смещения дат",
    "offsets.subtitle": "Управление расчётными датами.",
    "offsets.add": "Добавить смещение",
    "offsets.empty": "В файле нет DateOffset.",
    "offsets.section": "Смещения",
    "offsets.name": "Название смещения",
    "offsets.delete": "Удалить смещение",
    "offsets.calculatedDate": "Расчётная дата",
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
    "advanced.offsetEditor": "Редактор смещения даты",
    "advanced.dataMatrixDescription": "Профиль и сегменты кода",
    "advanced.dataMatrixProfile": "Профиль DataMatrix",
    "advanced.offsetsDescription": "Расчётные даты шаблона",
    "advanced.hiddenFieldsDescription": "Значения непечатаемых полей",
    "advanced.dataMatrixHint": "Редактирование профиля и сегментов выбранного DataMatrix.",
    "advanced.hiddenEditor": "Редактор скрытых полей",
    "advanced.hiddenEditorHint": "Редактирование значений непечатаемых полей.",
    "hiddenFields.empty": "В шаблоне нет скрытых полей.",
    "language.label": "Язык",
    "language.en": "Английский",
    "language.ru": "Русский",
    "theme.label": "Тема",
    "theme.system": "Системная",
    "theme.light": "Светлая",
    "theme.dark": "Тёмная",
    "grid.size": "Размер сетки (мм)",
    "tabs.label": "Открытые шаблоны",
    "tabs.untitled": "Новый шаблон",
    "tabs.unsaved": "Несохранённые изменения",
    "tabs.close": "Закрыть {title}",
    "tabs.add": "Создать шаблон в новой вкладке",
    "tabs.manage": "Управление вкладками",
    "tabs.menu": "Действия с вкладками",
    "tabs.closeCurrent": "Закрыть текущую",
    "tabs.closePlain": "Закрыть",
    "tabs.closeOthers": "Закрыть остальные",
    "tabs.closeRight": "Закрыть вкладки справа",
    "tabs.closeAll": "Закрыть все",

    "dialog.createTemplate.title": "Создать шаблон",
    "dialog.createTemplate.subtitle": "Выберите модель принтера, режим печати и размер области.",
    "dialog.createTemplate.sizeHint": "Для голов 53 мм доступен диапазон 53.33 на 75.00 мм.",
    "dialog.createTemplate.sizeHint32": "Для голов 32 мм доступен диапазон 32.00 на 75.00 мм.",
    "dialog.createTemplate.sizeHint107": "Для голов 107 мм доступен диапазон 106.67 на 75.00 мм.",
    "dialog.dataMatrix.title": "Добавить DataMatrix",
    "dialog.dataMatrix.subtitle": "Выберите формат кода и длину серийного номера.",
    "dialog.dataMatrix.selectSymbolSize": "Выберите формат кода",
    "dialog.dataMatrix.snValue": "Значение SN",
    "dialog.dataMatrix.selectSnValue": "Выберите значение SN",
    "dialog.dataMatrix.selectionRequired": "Выберите формат кода и значение SN.",
    "dialog.dataMatrix.compositionConflictTitle": "Несовместимые профили DataMatrix",
    "dialog.dataMatrix.compositionConflictMessage": "DataMatrix с разными наборами служебных полей нельзя совместно использовать в одном шаблоне. Конфликтующие поля: {names}.",
    "dialog.saveTemplate.title": "Сохранить шаблон",
    "dialog.saveTemplate.subtitle": "Введите название шаблона, чтобы сохранить его на устройство.",
    "dialog.saveTemplate.name": "Название шаблона",
    "dialog.saveTemplate.nameRequired": "Введите название шаблона.",
    "dialog.closeTab.title": "Закрыть «{title}»?",
    "dialog.closeTab.message": "В шаблоне есть несохранённые изменения. Если закрыть его без сохранения, информация будет утеряна.",
    "dialog.closeTab.closeWithoutSaving": "Закрыть без сохранения",
    "dialog.closeTabs.title": "Есть несохранённые изменения",
    "dialog.closeTabs.messageOne": "В {count} шаблоне имеются несохранённые изменения.",
    "dialog.closeTabs.message": "В {count} шаблонах имеются несохранённые изменения.",
    "dialog.closeTabs.saveAllAndClose": "Сохранить все и закрыть",
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
    "dialog.fileOpenError.unsupportedUnits": "В файле используются единицы координат, которые Glyph пока не может корректно редактировать. Откройте его в ClariSoft и сохраните с координатами в миллиметрах. Текущий документ не изменён.",
    "dialog.fileOpenError.invalidDimensions": "Файл должен содержать корректные неотрицательные значения ImageWidth и ImageHeight. Если указаны MaxImageWidth и MaxImageHeight, они также должны быть неотрицательными целыми числами. Текущий документ не изменён.",
    "dialog.hiddenFieldSpace.title": "Недостаточно рабочей области принтера",
    "dialog.hiddenFieldSpace.message": "Служебные поля не удалось разместить в аппаратных границах принтера: {names}.",
    "dialog.saveCompatibilityError.title": "Невозможно сохранить шаблон",
    "dialog.saveCompatibilityError.message": "Шаблон не прошёл проверку совместимости CIFF.",
    "dialog.unsupportedFile.title": "Неподдерживаемый формат файла",
    "dialog.unsupportedFile.message": "Можно открыть только файлы шаблонов CIFF или XML.",
    "dropZone.title": "Отпустите файл, чтобы открыть шаблон",
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
    "common.mm": "мм",
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
  { selector: "#btnOpenFile span", key: "topbar.open" },
  { selector: "#btnOpenFile", key: "topbar.open", attr: "aria-label" },
  { selector: "#btnSave span", key: "topbar.save" },
  { selector: "#btnSave", key: "topbar.save", attr: "aria-label" },
  { selector: ".templateDropPrompt__text", key: "dropZone.title" },
  { selector: "#btnUndo", key: "topbar.undo", attr: "aria-label" },
  { selector: "#btnRedo", key: "topbar.redo", attr: "aria-label" },
  { selector: "#btnPanMode span", key: "topbar.pan" },
  { selector: "#btnPanMode", key: "topbar.pan", attr: "aria-label" },
  { selector: "label[for='toggleGrid'] span", key: "topbar.grid" },
  { selector: "label[for='toggleSnap'] span", key: "topbar.snap" },
  { selector: "#toggleAlign + .utilityToggle__label .utilityToggle__full", key: "topbar.align" },
  { selector: "#toggleAlign + .utilityToggle__label .utilityToggle__short", key: "topbar.alignShort" },
  { selector: "label[for='zoomRange']", key: "topbar.zoom" },

  { selector: "#precisionMovePanel", key: "canvas.precisionMove", attr: "aria-label" },
  { selector: "#zoomLabel", key: "topbar.zoomReset", attr: "aria-label" },
  { selector: "#precisionMoveStep", key: "move.step", attr: "aria-label" },

  { selector: ".toolgrid", key: "panel.tools.title", attr: "aria-label" },
  { selector: "#leftPanelAddSectionTitle", key: "panel.tools.title" },
  { selector: "#leftAddObjectPopoverTitle", key: "panel.tools.title" },
  { selector: "#btnAddObjectCollapsed", key: "panel.tools.title", attr: "aria-label" },
  { selector: "#fieldBrowserTitle", key: "panel.fields.title" },
  { selector: ".fieldFilter--fieldBrowser", key: "panel.fields.filter", attr: "aria-label" },
  { selector: "[data-field-filter-label='printed']", key: "panel.printed.title" },
  { selector: "[data-field-filter-label='hidden']", key: "panel.hidden.title" },

  { selector: "#addDataMatrix span, [data-add-object-target='addDataMatrix'] span", key: "tool.datamatrix" },
  { selector: "#addFixedText span, [data-add-object-target='addFixedText'] span", key: "tool.text" },
  { selector: "#addDateText span, [data-add-object-target='addDateText'] span", key: "tool.date" },
  { selector: "#addTimeText span, [data-add-object-target='addTimeText'] span", key: "tool.time" },
  { selector: "#addOffsetDateText span, [data-add-object-target='addOffsetDateText'] span", key: "tool.offset" },
  { selector: "#addCounterText span, [data-add-object-target='addCounterText'] span", key: "tool.counter" },

  { selector: "#fieldSearch", key: "panel.search.placeholder", attr: "placeholder" },
  { selector: "#searchField", key: "panel.search.placeholder" },
  { selector: "#btnToggleFieldSearch, #btnToggleFieldSearchCollapsed", key: "panel.search.placeholder", attr: "aria-label" },
  { selector: "#btnCloseFieldSearch", key: "panel.closeSearch", attr: "aria-label" },
  { selector: "#btnCollapseLeftPanel", key: "panel.collapse", attr: "aria-label" },
  { selector: "#btnExpandLeftPanel", key: "panel.expand", attr: "aria-label" },
  { selector: "#btnShowHiddenOnCanvas", key: "panel.showHidden", attr: "aria-label" },
  { selector: "#btnShowHiddenOnCanvasCollapsed", key: "panel.showHidden", attr: "aria-label" },

  { selector: "#inspectorPanel", key: "inspector.title", attr: "aria-label" },
  { selector: "#btnInspectorExpand", key: "inspector.expand", attr: "aria-label" },
  { selector: "#inspectorCollapsedLabel", key: "inspector.title" },
  { selector: "#inspectorTitle", key: "inspector.title" },
  { selector: "#inspectorSubtitle", key: "inspector.noTemplate" },
  { selector: "#btnInspectorAppSettings", key: "inspector.appSettings", attr: "aria-label" },
  { selector: "#btnInspectorObjectMenu", key: "inspector.objectActions", attr: "aria-label" },
  { selector: "#btnInspectorCollapse", key: "inspector.collapse", attr: "aria-label" },
  { selector: "#inspectorNoTemplate .inspectorEmptyState__title", key: "inspector.noTemplate" },
  { selector: "#propsEmpty", key: "object.empty" },
  { selector: "#objectAdvancedSection > .inspectorDisclosure__summary", key: "inspector.advanced" },
  { selector: "#templateSizeSectionTitle", key: "inspector.section.size" },
  { selector: "#templatePrinterSectionTitle", key: "inspector.section.printer" },
  { selector: "#templateWorkspaceSectionTitle", key: "inspector.section.workspace" },
  { selector: "#templateAdvancedSection > .inspectorDisclosure__summary", key: "inspector.advanced" },
  { selector: "#inspectorObjectMenu", key: "inspector.objectActions", attr: "aria-label" },
  { selector: "#inspectorPrintLabel", key: "field.printOutput" },
  { selector: "#inspectorDeleteLabel", key: "object.delete" },
  { selector: "#inspectorAppSettingsTitle", key: "inspector.appSettings" },
  { selector: "#addOffset", key: "offsets.add", attr: "aria-label" },
  { selector: "#addOffset span", key: "offsets.add" },
  { selector: "#dateOffsetsSectionTitle", key: "offsets.section" },
  { selector: "#btnOpenDataMatrixEditor span", key: "advanced.dataMatrixProfile" },
  { selector: "#btnOpenOffsetsEditor span", key: "advanced.offsetEditor" },
  { selector: "#btnOpenHiddenFieldsEditor span", key: "advanced.hiddenEditor" },
  { selector: "#dataMatrixEditorModalTitle", key: "datamatrix.title" },
  { selector: "#dataMatrixEditorModalSubtitle", key: "advanced.dataMatrixHint" },
  { selector: "#offsetsEditorModalTitle", key: "offsets.title" },
  { selector: "#offsetsEditorModalSubtitle", key: "offsets.subtitle" },
  { selector: "#hiddenFieldsEditorModalTitle", key: "advanced.hiddenFields" },
  { selector: "#hiddenFieldsEditorModalSubtitle", key: "advanced.hiddenEditorHint" },
  { selector: "#hiddenFieldsSectionTitle", key: "panel.hidden.subtitle" },
  { selector: "#btnCloseDataMatrixEditor", key: "dialog.close", attr: "aria-label" },
  { selector: "#btnCloseOffsetsEditor", key: "dialog.close", attr: "aria-label" },
  { selector: "#btnCloseHiddenFieldsEditor", key: "dialog.close", attr: "aria-label" },
  { selector: "label[for='uiLanguageSelect']", key: "language.label" },
  { selector: "label[for='uiThemeSelect']", key: "theme.label" },
  { selector: "label[for='gridSizeSelect']", key: "grid.size" },
  { selector: "label[for='moveStepSelect']", key: "move.step" },
  { selector: "#templateTabs", key: "tabs.label", attr: "aria-label" },
  { selector: "#btnTemplateTabsMenu", key: "tabs.manage", attr: "aria-label" },
  { selector: "#templateTabMenu", key: "tabs.menu", attr: "aria-label" },
  { selector: "[data-template-tab-menu-label='close']", key: "tabs.closeCurrent" },
  { selector: "[data-template-tab-menu-label='close-others']", key: "tabs.closeOthers" },
  { selector: "[data-template-tab-menu-label='close-right']", key: "tabs.closeRight" },
  { selector: "[data-template-tab-menu-label='close-all']", key: "tabs.closeAll" },
  { selector: "#btnAddTemplateTab", key: "tabs.add", attr: "aria-label" },
  { selector: "#btnOpenFunctionality", key: "settings.functionality" },
  { selector: "#btnOpenChangelog", key: "settings.changelog" },

  { selector: "#mobilePanelMenuToggle", key: "mobile.panels", attr: "aria-label" },
  { selector: "#mobilePanelMenu", key: "mobile.panels", attr: "aria-label" },
  { selector: "#mobilePanelMenu .panel__title", key: "mobile.panels" },
  { selector: "#mobilePanelMenu .muted", key: "mobile.panelsHint" },
  { selector: "#mobilePanelMenuClose", key: "dialog.close", attr: "aria-label" },

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
