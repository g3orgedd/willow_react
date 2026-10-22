# Условия формирования полей CIFF: установленный ClariSoft и Glyph 2.3.0

Дата проверки: 21.10.2026. Это часть отчёта об XML, посвящённая `Field`, `Data/Object`, источникам данных, тексту, датам, счётчикам и DataMatrix. Размеры `SubHeader/ImageWidth`, `ImageHeight`, `MaxImageWidth`, `MaxImageHeight` рассмотрены в отдельной части основного отчёта.

## Основание и границы проверки

Сопоставлены восстановленные C/ASM оригинальных функций `CiffMgr.dll` и текущие функции `public/modules/60-history-save.js`. SHA-256 всех 15 установленных модулей совпали с ранее декомпилированными: [binary-hashes.json](binary-hashes.json). Поэтому прежняя декомпиляция относится именно к установленным бинарным файлам, а не к другой версии ClariSoft.

Повторно выполнены 35 сценариев через оригинальные 32-битные COM-интерфейсы: 33 сформировали CIFF; два ожидаемо вернули `E_ACCESSDENIED` при попытке задать параметры дополнения до включения `FixedLength`. Входные свойства — [cases.json](cases.json), воспроизводимый запуск — [probe-field-conditions.ps1](probe-field-conditions.ps1), результаты — [native/results.json](native/results.json), каждый исходный native XML находится рядом. Для текущего Glyph использованы девять проб его настоящих фабрик и сериализатора: [new-field-probes.json](../glyph/new-field-probes.json). Это проверки компонентов и исходного кода; в этой части не утверждается проверка диалогов/снимков GUI или физической печати.

Команда воспроизведения из корня репозитория:

```powershell
& 'C:\Windows\SysWOW64\WindowsPowerShell\v1.0\powershell.exe' -NoProfile -ExecutionPolicy Bypass -File research/xml-formation-audit-20261021/fields/probe-field-conditions.ps1
```

Разделение двух путей Glyph принципиально:

* **Новое поле**: `buildFieldXmlOneLine` (строка 1681) создаёт XML из ограниченной модели Glyph.
* **Импортированное поле**: `patchExistingFieldBlockNonInvasive` и вспомогательные lossless-патчи изменяют исходный XML. Неизвестные или не изменённые свойства в основном сохраняются. Недостаток нового генератора не означает автоматической потери того же тега при обычном открытии и сохранении существующего CIFF.

Под «отличием XML» ниже не подразумевается доказанная ошибка печати. Явно записанный native default обычно означает то же значение, что его отсутствие. Отдельно отмечены изменения состояния и возможности, которых нет в модели Glyph. Полная спецификация всех закрытых принтерных расширений и всех возможных CIFF этой работой не заявляется; перечень найденных writer-ветвей — [SERIALIZATION_MAP.md](../../ciff-fields/SERIALIZATION_MAP.md).

## Главные результаты

1. **Glyph пишет больше необязательных нулевых/пустых тегов, чем native writer.** Для нового поля всегда появляются пустые `CalcData`, `Default` и `LoggedField`; для явно заданных default-параметров могут появиться `Ln=0`, `MaxNoOfChars=0`, `Static=1`, `Parse=0`, default-параметры шрифта, дополнения, ссылки и счётчика. Большинство таких различий — отсутствие native canonical omission, а не установленная причина расхождения предпросмотра.
2. **`LoggedField` требует отдельного решения.** Native writer опускает его именно для строки `Not Logged`; для пустой строки/NULL он пишет пустой узел. Glyph всегда выбирает пустой узел для нового поля, хотя эта настройка не представлена в интерфейсе. Это разные состояния COM-модели; влияние на предпросмотр/печать не доказано. Импортированный `LoggedField` lossless-путь сохраняет.
3. **`Static`, `VarText`, `FixedLen`, `MaxNoOfChars` — независимые настройки.** Нельзя выводить одну из другой или из имени тега. Текущий Glyph уже не включает `FixedLen` только по имени поля: это исправление не нужно объявлять новым дефектом. Партионные рецепты отдельно устанавливают нужные настройки.
4. **Новый генератор описывает подмножество native полей.** Общие флаги рендеринга, расширенная локаль/календарь/шифрование, operator prompt/list-data, расширенные/связанные счётчики и многочисленные barcode/graphic-ветви не имеют полного нового writer в Glyph. При импортированном поле исходный XML часто сохраняется, однако это не равнозначно поддержке создания, редактирования и воспроизведения поведения.
5. **Настройки шрифта 10 и DataMatrix 22X22/QuietMargin=0 в новых рецептах — выбранные настройки Glyph.** Их отличие от native defaults (Pitch13, Auto, QuietMargin1) не доказывает ошибку: пользователь явно просил Pitch10. При одинаковых значениях XML native defaults можно опускать без изменения размера.
6. **Локализация даты не сведена к одной причине.** В Glyph `dateLocale` управляет собственной таблицей названий месяцев, а новый writer не переводит его в native `Locale/Calendar`. Свежая COM-проба с явно записанным `RU-RU` всё равно получила `Oct`. Следовательно, утверждать, что добавление одного `<Locale>RU-RU</Locale>` решит совпадение, нельзя.

## Общая оболочка `Field`

Оригинальная функция: [`CiffMgr.dll!68128924`](../../ciff-fields/decompiled/CiffMgr.dll/FUN_68128924.c). Порядок native детей: `FldType`, `CLSID`, `Displayed`, `X`, `Y`, `W`, `H`, `Ln`, `Orientation`, `OverrideThis`, `Inverse`, `Mirror`, `RenderMode`, `CalcData`, `LoggedField`, расширения, `Data`, `Clip`, `Text/Barcode/Graphic`. Не каждое поле содержит каждого ребёнка.

| Свойство / сценарий | Условие оригинального writer | Текущий Glyph и значение отличия |
|---|---|---|
| `Field/@Name` | Всегда, из имени модели | Совпадает. Имя само по себе не активирует FixedLen/VarText/прочие настройки. |
| `Field/@TXField` | Если поддержан extension-интерфейс и флаг включён | Новый writer не моделирует; исходный атрибут сохраняется lossless. |
| `FldType` | Только непустая строка (`68128924`, строка 76) | Новое поле всегда пишет выбранный тип. Для обычных созданных типов это соответствует нужной модели. Пустой native служебный тип не является обязательным образцом для новых пользовательских полей. |
| `CLSID` | Если отличается от default text CLSID `{BB0561B2-C54F-11D4-A995-00010212D541}` | Glyph пишет CLSID для нового DM; у нового обычного текста опускает. Обобщённого выбора native family/CLSID нет. В DM порядок Glyph `Displayed → CLSID`, native `CLSID → Displayed`; чувствительность загрузчика к этому порядку не установлена. |
| `Displayed` | Если значение не `1` | Glyph пишет `0` у скрытого поля и ничего у печатного: совпадение для поддержанной boolean-модели. |
| `X/Y/W/H` | Всегда, в том числе нули | Glyph пишет всегда. Вычисление значений — отдельный вопрос, наличие этих тегов корректно. |
| `Ln` | Только ненулевой `FieldLine` | Glyph пишет при `f.ln != null`, поэтому явный `0` тоже попадает в новый XML. Canonical-различие; пробы `neutral-explicit-defaults` и Glyph `lineZero`. |
| `Orientation` | Только ненулевой угол | Совпадает для поддержанных углов. |
| `OverrideThis`, `Inverse`, `Mirror` | Каждый только при ненулевом флаге | Новый генератор их не записывает; импортированный XML сохраняет. Для нового такого эффекта нет полной модели/управления. Нельзя добавлять их всем полям «для совместимости». |
| `RenderMode` | Только ненулевой enum, сериализуется native строковым представлением | Новая генерация не поддерживает. Режим влияет на способ native рендеринга; без проверки конкретного режима нельзя заменять его общим default. |
| `CalcData` | Сначала удаляются XML-недопустимые controls; узел создаётся только если после этого строка непустая (`68128924`, строки 163–173; фильтр `68124340`) | Новый writer пишет узел даже для пустой строки. Сам фильтр Glyph уже реализован. Для непустых поддержанных значений его наличие соответствует native. Пустой узел отличается canonical XML, но не доказывает неправильную геометрию. |
| `LoggedField` | Не писать только при точном значении `Not Logged`; пустое/NULL пишется (`68128924`, строки 179–187) | Новый writer всегда `<LoggedField></LoggedField>`. Это не native default omission: состояние поля отличается. Назначение/эффект конкретного значения на печать в этой работе не доказаны. Исходные значения импортированного поля сохраняются. |
| `Origin`, `MarkSet` | Extension: ненулевой origin / непустая mark-set строка | Нет полного нового writer; импорт сохраняет. |
| `Data` | Если получена коллекция объектов; допускается пустой `Data/` | Glyph создаёт объект данных у нового текста и сегменты у DM. Это выбор создаваемого поля, а не правило, что всякий native Field обязан иметь непустой Data. |
| `Clip` | При наличии непустых clipping rectangles | Новый writer не моделирует; исходный блок сохраняется. |
| `Text`, `Barcode`, `Graphic` | По внутреннему семейству field, а не только строке FldType | Glyph полноценно создаёт свои текстовые типы и DM. Нельзя считать произвольный native barcode/graphic новым текстом. |

Свежие показательные native пробы: [FieldLine](native/common-FieldLine.ciff), [Displayed](native/common-FieldDisplayed.ciff), [OverrideThis](native/common-OverrideThis.ciff), [CalcData](native/common-CalculatedData.ciff), [`LoggedField` empty](native/logged-0.ciff), [`Not Logged`](native/logged-2.ciff).

Для одного и того же нейтрального состояния native сформировал:

```xml
<Field Name="Field00"><FldType>FixedText</FldType><X>0</X><Y>0</Y><W>0</W><H>0</H><Data><Object Static="0" Reference=""><DataType>0</DataType></Object></Data><Text><Font/></Text></Field>
```

Отсутствуют `Ln=0`, пустые `CalcData/Default`, `LoggedField` для `Not Logged`, `MaxNoOfChars=0`, default-параметры шрифта. Это выданный оригинальной DLL [neutral-explicit-defaults.ciff](native/neutral-explicit-defaults.ciff), а не вручную исправленный XML.

## `Data/Object`: атрибуты и общие дети

Оригинальная функция: [`68126560`](../../ciff-fields/decompiled/CiffMgr.dll/FUN_68126560.c). Порядок атрибутов native: `Index`, `Static`, `Parse`, `EqRef`, extension `Param`, `Reference`. Порядок обычных детей: `DataType → Locale → Calendar → Encryption → MaxNoOfChars → Default → FixedLen → специальные данные → источник`.

| Сценарий | Native условие записи | Glyph 2.3.0 / последствие |
|---|---|---|
| Первый/последующие объекты | `Index` только если не 0; коллекция Data сортирует по Index | DM нового Glyph использует порядок массива: 0,1,2… и опускает Index0. Для обычного созданного DM это совпадает; произвольные разреженные/переупорядоченные индексы не моделируются как новая структура. |
| Static | Писать только если `Static != 1` | Glyph пишет, если `staticAttr != null`, включая `1`; отсутствие означает default, не «false». Пустой/статический текст и ввод на принтере нельзя отличать только по FldType. |
| Parse | Писать только если `Parse != 0` | Glyph пишет, если `parseAttr != null`, включая `0`. У Date/Time рецепты явно используют Parse1. |
| EqRef, Param | EqRef ненулевой; Param при поддержанном extension и ненулевом значении | Новые поля Glyph не моделируют. Импорт сохраняет. |
| Reference | Если поддержан соответствующий интерфейс, даже пустая строка | `Reference=""` у новых Glyph полей не является само по себе лишним: native тоже пишет его в исследованных типах. |
| DataType | Всегда, из **ClearStyleDataType** | Glyph пишет. Внутренний `EDataType` и XML DataType — разные enum: нельзя выбирать VarText/SrcField/Counter ветвь по одному числу XML без модели источника. |
| Locale | Если native Locale отличается от `EN-GB` (`68126560`, строки 134–142) | Парсер читает значение, lossless сохраняет исходный тег. Новый builder не сериализует `data.locale`. UI `data.dateLocale` — отдельное значение; его переключение не патчит этот native тег. |
| Calendar | Если значение не native default1 (`68126560`, строки 148–155) | Аналогично: исходный XML сохраняется, полноценного нового writer/редактирования native календаря нет. |
| Encryption | Только непустая строка | В новом writer отсутствует; импортированный блок сохраняется. Это неподдержанный сценарий, а не требование добавлять Encryption всем полям. |
| MaxNoOfChars | Только если значение не 0 (`68126560`, строки 172–177) | Glyph пишет любое ненулевое **или нулевое** значение, если оно не null. `0` в XML отличается canonical omission; значение max само по себе не включает FixedLen. |
| Default | Только непустое значение, CDATA | Новый Glyph пишет даже пустой CDATA. Для непустых значений это соответствует native назначению. |
| FixedLen | Только если явное native FixedLength включено | Glyph пишет при `data.fixedLen === true`: правильная независимость. Наличие MaxNoOfChars, VarText или имени SN/GTIN не требует FixedLen автоматически. |
| FixedLen/PadChar | Только если символ не U+0020 (пробел) | Glyph пишет любой явно заданный `padChar`, включая пробел. Canonical-различие. |
| FixedLen/PadMode | Только если native mode не 0; записывается enum-строка | Glyph пишет любое явно заданное `padMode`, включая0. Следует хранить корректное native представление enum, а не создавать произвольную числовую строку. Для пользовательских imported значений lossless безопаснее перегенерации. |

Нативные независимые комбинации `Static/Parse` видны в [data-flags-0](native/data-flags-0.ciff), [1](native/data-flags-1.ciff), [2](native/data-flags-2.ciff), [3](native/data-flags-3.ciff). В этих пробах одна и та же базовая строка не превращается автоматически в VarText при Static0.

Проба [fixedlen-space-left-defaults](native/fixedlen-space-left-defaults.ciff) с явно заданными PadChar=пробел и PadMode0 выдала `<FixedLen/>`. При этом `MaxNoOfChars6` и `Default ABC` остались. Попытки setter PadCharacter/PadMode до включения FixedLength закономерно отклонены: два `E_ACCESSDENIED` в results — свойства зависимого состояния, а не провал сценария поддержки CIFF.

## Ветвление по источнику данных

В `68126560`, строки 365–430, ветку выбирает внутренний `EDataType`: 0 — без дополнительной структуры; 1 — `SrcField`; 2 — `SrcData`; 3 — `VarText`; 4 — `OffsetDate`; 5 — `CounterText`; 8 — `CLARICOMSSCC`. Это не та же таблица, что сериализованный `ClearStyleDataType`. Атрибуты Static/Parse и FixedLen могут сопровождать разные ветки.

| Сценарий | Native условие и функция | Glyph / влияние |
|---|---|---|
| Ссылка на другое поле | [`6812B98E`](../../ciff-fields/decompiled/CiffMgr.dll/FUN_6812b98e.c): SrcFieldName всегда; StartChar, NoOfChars, SelectMode — каждый только ненулевой | `buildCiffSrcFieldXml`, строка 1665, пишет любой не-null параметр, включая0. Для zero selection это canonical-различие. Непустые partial-параметры уже учитываются текущим CalcData resolver; старое отсутствие partial не следует перечислять как текущий дефект. |
| Частичная выборка SrcField0 | При SourceFieldName=SRC, Start0, Count0, Mode0 native пишет только `<SrcField SrcFieldName="SRC"/>` | Свежий [partial-source-explicit-zero](native/partial-source-explicit-zero.ciff). Добавлять нулевые selection-теги не требуется. Для nonzero режимов надо использовать native enum-значение и сверять расчёт строки. |
| Данные БД/внешнего источника | [`6812B7E4`](../../ciff-fields/decompiled/CiffMgr.dll/FUN_6812b7e4.c): ConnStr только непустой; SrcSQL пишется даже пустой; параметры partial-selection условные | Glyph `buildSourceDataXml`, строка 1314, проверяет null, а не длину: может добавить пустой ConnStr; при отсутствующем srcSQL может опустить SrcSQL. Для частично заполненной новой модели это структурное расхождение. Импортированный SrcData патч сохраняет дополнительные children. |
| Пустой SrcData | Native выдаёт `<SrcData><SrcSQL><![CDATA[]]></SrcSQL></SrcData>`, без ConnStr/Default | Свежий [source-data-empty](native/source-data-empty.ciff). Нельзя универсально удалять все пустые теги: пустой SrcSQL — исключение. |
| Пользовательский ввод | [`6812D7A8`](../../ciff-fields/decompiled/CiffMgr.dll/FUN_6812d7a8.c): VarText возникает по внутреннему типу3; Prompt, Mask, UserEnterData только непустые | Glyph выбирает VarText по `wantsVarTextStructure`; пишет Mask только непустой, но UserEnterData — всегда, даже пустой. Новый writer поддерживает не все prompt/list/reset параметры. |
| Пустой пользовательский ввод | Native `<VarText/>` допустим; отсутствие UserEnterData не удаляет сам VarText | Свежий [variable-empty-values](native/variable-empty-values.ciff). Пустой UserEnterData Glyph — canonical-различие; VarText при этом нужно сохранить, если источник пользовательский. |
| PromptAtCoder, ResetOnSel | VarText: PromptAtCoder только если не1; ResetOnSel только если не0 | Новый writer Glyph не имеет полного управления ими. Сохранение импортированного блока не равно возможности создавать эквивалентный сценарий prompt/reset. |
| ListData | VarText extension при реальном списке/подключении: отдельная структура со свойствами списка/ConnStr/SourceSQL/элементами | Поддерживается сохранение исходного XML, нового универсального генератора списка нет. Вставлять ListData к обычному UserEnterData не требуется. |
| Дата со смещением | [`6812A724`](../../ciff-fields/decompiled/CiffMgr.dll/FUN_6812a724.c): OffsetDate/SrcOffset — атрибут ссылки на общий offset | Glyph пишет `<OffsetDate SrcOffset="..."/>` для OffsetDateText/DataType3/непустой ссылки: форма базового источника соответствует native. Общая DateOffsets-коллекция и её правила — отдельный уровень документа; к самому OffsetDate этой функцией другие children не добавляются. |
| SSCC/PriceData/Checksum и extensions | Собственные условные ветки, а не дополнения к любому тексту | Нет полного нового builder. Существующие блоки должны сохраняться. Это предел покрытия, не доказанный дефект стандартных FixedText/DM. |

## Текст и шрифты

Native [`6812CCCE`](../../ciff-fields/decompiled/CiffMgr.dll/FUN_6812ccce.c) формирует Text/Font и условные стиль/блочный текст; [`6812D1DE`](../../ciff-fields/decompiled/CiffMgr.dll/FUN_6812d1de.c) записывает свойства шрифта, только если они отличаются от native defaults:

| Native default, который можно опустить | Glyph 2.3.0 |
|---|---|
| Face=`Arial`, Family=32 | `patchTextFontLossless` (1250) пишет непустые свойства, если они заданы в модели, даже default. При импорте отсутствующий исходный default остаётся отсутствующим, пока нет явного нового значения. |
| Pitch=13, PitchResolution=1 | Новый Glyph задаёт эффективный Pitch, обычно10. **Это пользовательский выбор размера**, поэтому Pitch10 обязан быть записан. Удалять его ради совпадения с пустым native Font нельзя. Явный Pitch13 может быть опущен для canonical XML. |
| XMag=100, YMag=100, TTSize=1 | Новая модель часто записывает100 явно. Это не делает буквы больше или меньше при тех же значениях; omission default меняет только форму XML. |
| TxtDir=0, CharSpace=0 | При явном наличии в модели пишутся и нули. |

`Bold`, `Italic`, `DblSpace`, `Block`, `Escapement`, `FixedWidth`, `MultiStroke` имеют собственные условия в native Text writer; не следует создавать все узлы подряд. Новый Glyph умеет Font и Bold/Italic; в импортированном XML прочие свойства сохраняются. Блочный режим в native — самостоятельный флаг, его нельзя выводить только из ненулевой ширины блока.

Свежие пробы: [default Font/](native/neutral-explicit-defaults.ciff), [смена FontName](native/text-FontName.ciff), [FontPitch](native/text-FontPitch.ciff). В native нейтральном сценарии Font пуст, поскольку **неизменённые** Arial/13/100 подразумеваются. Это не bitmap-шрифт: отсутствие тегов описывает default выбранного native шрифта, а не тип отрисовки.

## DateText / TimeText и локализация

Обычные DateText/TimeText — те же Data/Object с Parse1 и соответствующим ClearStyleDataType, `Default` содержит native формат. Наличие DateText не требует VarText и FixedLen. OffsetDate — отдельный источник, а не обязательное дополнение DateText.

В Glyph `getDateTextValue` (`30-rendering.js`, строка 2422) использует собственные `MONTH_NAMES` и `data.dateLocale` (`ru/en`). `buildDateTemplateFormat` формирует формат без встроенной native Locale. Парсер читает `data.locale`/`data.calendar`, но `inferDateLocale` также использует эвристику по формату и Cyrillic в CalcData. Новый `buildFieldXmlOneLine` Locale/Calendar не пишет; lossless-патч эти native теги сохраняет, но переключение UI dateLocale не является их полноценным редактированием.

Свежие native пробы с `Default = dd'/'MMM'/'yyyy`, Parse1:

* [default-date-month](native/default-date-month.ciff): без явной Locale, `CalcData = 21/Oct/2026`.
* [ru-date-month](native/ru-date-month.ciff): после явного задания native `Locale = RU-RU`, XML действительно содержит `<Locale>RU-RU</Locale>`, но оригинальный `ResolveField` всё равно дал `21/Oct/2026`.

**Подтверждено:** новый Glyph не сериализует native Locale/Calendar и использует собственную таблицу месяцев. **Не подтверждено:** какой полный набор native условий/календарных правил нужен в установленном ClariSoft для русского MMM, и решается ли это одним Locale. Поэтому нельзя выдавать пропущенный Locale за уже доказанную единственную причину расхождения. Цифровые dd/MM/yyyy не демонстрируют проблему названий месяцев. Сложные native форматы/календари требуют отдельного сценарного resolver; текущий сохранённый CalcData для неподдержанных форматов не следует заменять угаданным.

Проба фабрики `currentDate` в new-field-probes — XML до общего prepare/save; её форматная CalcData сама по себе не является доказательством ошибочного финального сохранения. Текущий pipeline вычисления CalcData и ClSt исправлен 21.10; прежние известные дефекты ClSt не входят в этот перечень как текущие.

## CounterText

Native CounterText writer [`681261DF`](../../ciff-fields/decompiled/CiffMgr.dll/FUN_681261df.c), SubCnt writer [`6812BB40`](../../ciff-fields/decompiled/CiffMgr.dll/FUN_6812bb40.c).

| Native условие | Glyph / отличие |
|---|---|
| CounterText: Rollover только !=1; PrnPerCnt !=1; ResetOnSel !=0; ParentCounter непустой; RolloverError !=1; PromptWith !=0; ResetSource !=0 | Новый Glyph создаёт упрощённый CounterText, без полного набора этих политик/связей. Импортированные настройки сохраняются, но визуальная/динамическая поддержка требует отдельных проверок. |
| Из коллекции SubCnt пишутся только используемые (`Used != 0`); может быть несколько. В `681261DF`, строка114, читается vtable `+0x7C`; [typelib ICiffSubCounter3](../../ciff-fields/metadata/CiffMgr.dll.typelib.json) определяет offset124 как `get_Used`, не `NumberOfCharacters` (get offset52) | Новый Glyph создаёт один SubCnt. Несколько разрядов/связанные/global counters не полностью представлены новой моделью. |
| SubCnt/Significance всегда; AlphaNum толькоtrue; LeadChar только !=`0`; Global при включении соответствующего флага | Glyph пишет Significance, остальных новых настроек нет. |
| NoOfChars всегда; LeadingChars только !=1 | Glyph пишет NoOfChars; полного управления LeadingChars нет. |
| StartVal только если !=`0`; EndVal только если !=`9999`; StepSize только !=1 | Glyph пишет эти три узла всегда. StartVal1 в новом рецепте — выбранное начальное значение, а не обязательный native default0. При Start0/End9999/Step1 это canonical-различие. |
| CurrVal только непустой; IncableChars только !=`0-9`; Prompt только непустой | Новый writer не отражает эти возможности полностью. |
| ClrStCntType пишется самим native SubCnt writer, включая пустое значение | Пустой ClrStCntType нового Glyph **не следует** объявлять лишним только из-за пустоты: это совпадает с данной native функцией. |

Свежая [counter.ciff](native/counter.ciff) и Glyph `counter` в new-field-probes показывают поддержанный простой сценарий. Это не доказательство эквивалентности всех native политик increment/reset/rollover.

`BOX_COUNTER` из партионного рецепта — **FixedText + VarText**, а не этот CounterText. Максимум5 и пользовательский ввод задаются источником/MaxNoOfChars/FixedLen отдельно. Имя BOX_COUNTER не должно автоматически включать native CounterText.

## DataMatrix и остальные штрихкоды

Native Barcode writer [`68124AFE`](../../ciff-fields/decompiled/CiffMgr.dll/FUN_68124afe.c) и subtype writer [`68124E3D`](../../ciff-fields/decompiled/CiffMgr.dll/FUN_68124e3d.c). Для DataMatrix native subtype15 имеет mask `0x380`; к нему не надо добавлять узлы QR/PDF417/линейных кодов.

| Свойство / сценарий | Native | Glyph / значение отличия |
|---|---|---|
| Mag, MagRnd | Писать, если !=1000 и !=50 соответственно | Новый DM writer Glyph не создаёт ненулевые нестандартные настройки этих свойств; импорт сохраняет. |
| BcH | Всегда; отдельное свойство модели, writer не подставляет H автоматически | Новый Glyph пишет результат своего DM-calculator. Его численное согласование с ModuleSize и геометрией следует проверять отдельно; наличие тега правильно. Старые претензии к старому fallback не переносятся без проверки на текущую реализацию. |
| HR/HRFont | Контейнеры формируются native writer | Пустой `<HR><HRFont/></HR>` у нового Glyph не ошибка только из-за пустоты. |
| QuietMargin | Только если !=1 | Glyph новый DM обычно пишет0: это выбранное отсутствие полей, не лишний default. Если выбрано1, Glyph всё равно пишет1 — canonical-различие. Нельзя удалять QuietMargin0 ради «чистого XML»: omission означает1 и меняет символ/размер. |
| ECCType | Для DM только если !=5 | Новый Glyph опускает: соответствует native default ECC200 для своего сценария. |
| ModuleSize | Для DM только если !=100 | Glyph пишет всегда. Значение100 можно опустить при canonical-сериализации; нестандартное удалять нельзя. Размер модуля влияет на геометрию. |
| SymbolSize | Для DM только если !=0 (Auto) | Glyph пишет выбранный фиксированный размер (обычно22X22). Это настройка сценария, а не ошибка отсутствия Auto. При Auto native может опустить. |
| Состав Data/Object | Native выбирает реальный тип каждого объекта и условно пишет его свойства | Новый Glyph DM создаёт segments с DataType/Default/SrcField, Index по массиву и Reference=""; не поддерживает все независимые native атрибуты и ветви каждого сегмента как новый объект. Импортированные DM объекты патчатся lossless, расширения не следует считать автоматически удалёнными. |
| CheckDigit, XOffSet, BarcodePrinting и другой subtype | Собственные условия по семейству/feature mask | Новый Glyph writer специализируется на DM. Нельзя из существования узла Barcode делать вывод о новом полноценном writer всех27 найденных subtype. |

Свежие native пробы [barcode-subtype-15](native/barcode-subtype-15.ciff), [QuietMargins](native/barcode-QuietMargins.ciff), [DM extensions](native/barcode-datamatrix-extensions.ciff). Полная таблица27 subtype и их масок находится в SERIALIZATION_MAP.

## Что имеет смысл исправлять, а что сохранять

**Смысловые пробелы / требуют отдельного решения:** новое фиксированное пустое LoggedField вместо явного выбора состояния; соответствие UI dateLocale и native календарного сценария; полноценное создание и расчёт расширенных native sources/counters/flags; схема SrcData с различием empty/null и обязательностью SrcSQL; поддержка произвольных barcode/graphic семейств при создании. У каждого пункта нужна отдельная модель/сценарий — универсальная вставка всех найденных тегов небезопасна.

**Canonical XML, без установленного визуального эффекта при равных значениях:** пустые CalcData/Default/UserEnterData, явные Ln0/MaxNoOfChars0/Static1/Parse0, default Font properties, default padding/selection/counter values. Нативный стиль omission можно внедрить отдельно в новый writer, но импортированный XML разумно сохранять: исходное явно записанное значение не следует удалять только ради похожести.

**Уже корректно / не возвращать прежние ошибки:** X/Y/W/H всегда; Displayed0 для скрытых; независимый FixedLen; Reference="" у исследованных объектов; SourceField partial selection и FixedLen padding в текущем CalcData; nonempty CalcData control-filter; общий текущий snapshot CalcData для XML/ClSt; заново вычисляемый ClSt. Pitch10 у новых партионных тегов — выполненное требование пользователя. Этот аудит не менял production и пользовательские CIFF.

## Индекс основных адресов

| Область | Native VA / источник | Текущий Glyph |
|---|---|---|
| Field | `68128924` | `60-history-save.js:1681`, импорт `patchExistingFieldBlockNonInvasive` |
| XML control filtering | `68124340`, `6812451F` | `filterCiffCalculatedDataForXml` |
| Data/Object | `68126560` | `getCiffTextSerializationRules:1648`, `buildFieldXmlOneLine:1681` |
| SourceField | `6812B98E` | `buildCiffSrcFieldXml:1665` |
| SourceData | `6812B7E4` | `buildSourceDataXml:1315`, `patchSourceDataLossless` |
| VarText | `6812D7A8` | `wantsVarTextStructure`, builder `60-history-save.js:1734` |
| OffsetDate | `6812A724` | `60-history-save.js:1737` |
| Counter/SubCnt | `681261DF`, `6812BB40` | `60-history-save.js:1742`, imported first-SubCnt patch |
| Text/Font | `6812CCCE`, `6812D1DE` | `patchTextFontLossless:1250` |
| Barcode/subtype | `68124AFE`, `68124E3D` | DM branch `60-history-save.js:1695` |
| Native source index | [SERIALIZATION_MAP.md](../../ciff-fields/SERIALIZATION_MAP.md) | [source-manifest.json](../glyph/source-manifest.json) |

