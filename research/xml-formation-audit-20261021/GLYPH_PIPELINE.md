# Glyph 2.3.0: текущее формирование CIFF и геометрия

Аудит исходного кода на 21.10.2026. Production-файлы не изменялись. Версия и SHA-256 прочитанных модулей — [source-manifest.json](glyph/source-manifest.json). Повторяемый запуск: `node research/xml-formation-audit-20261021/glyph/probe-current-glyph.cjs` из корня проекта. Результаты: 12 сценариев размеров, 9 новых полей и 2 сценария метаданных. Это исполнение настоящих production parser/save/geometry через существующий Node harness; сторонние DOM/Konva-операции подменены. Метрики текста в геометрических сценариях берутся из сохранённых номинальных W/H. Это **не** визуальное сравнение ClariSoft, EXE или браузера и не запуск GDI.

## 1. Три разных пути, которые нельзя смешивать

1. **Новый документ/поле.** `buildEmptyTemplateXml` создаёт каркас, а `buildFieldXmlOneLine` полностью создаёт новое поле по модели. Непредставленные в модели native-свойства здесь не появляются.
2. **Импорт и сохранение.** Сохраняется исходная XML-строка. `patchXmlLosslessV2Mutating` меняет известные участки, оставляя большинство неизвестных атрибутов/узлов, их порядок и написание. Поэтому неподдерживаемое свойство может сохраняться в файле, хотя не используется предпросмотром.
3. **Изменение структуры.** В частности, изменение набора DataMatrix-сегментов включает `structureDirty`: весь список `<Object>` перестраивается. Расширения прежних объектов, которых нет в модели/генераторе, тогда теряются. Редактирование только значения обычно патчит объект на месте.

Код: [новый документ, 20:206](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/20-xml-load.js:206), [подготовка сохранения, 60:350](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/60-history-save.js:350), [patch существующего поля, 60:1550](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/60-history-save.js:1550), [новое поле, 60:1681](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/60-history-save.js:1681), [перестройка DM, 60:2490](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/60-history-save.js:2490).

Импортируется для редактирования первый `SubImage`; остальные сохраняются в исходном XML. В обычном текстовом поле модель редактирует первый `Data/Object`; наличие нескольких объектов отмечено отдельно, исходные остальные объекты сохраняются. Это ограничение поддержки, а не обещание полного native object model. Для DataMatrix отдельно читаются все сегменты. [20:433](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/20-xml-load.js:433), [20:447](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/20-xml-load.js:447), [20:560](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/20-xml-load.js:560).

## 2. Image* и MaxImage*: фактический контракт Glyph

В Glyph одна внутренняя единица всегда трактуется как 0,01 мм. Это соответствует обычному native `Header/Units=0` (`U_HMM`), но не охватывает весь формат: typelib ClariSoft допускает также `Units=1` (`U_DOTS`), где координаты и размеры заданы точками, а физические размеры зависят от разрешения. `parseHeader` не читает `Header/Units`; `INTERNAL_PER_MM=100` зафиксирован в core, а native-text preview преобразует координаты/W/H делением на100. Следовательно, отдельной модели и ветки рендера для U_DOTS у Glyph сейчас нет. Исходный `<Units>1</Units>` при lossless save остаётся в raw XML, но сохранение узла не означает корректную интерпретацию предпросмотра или отредактированной геометрии. В выполненных геометрических пробах использовалась обычная миллиметровая интерпретация; U_DOTS дополнительно не проверялся.

Источники: [native enum U_HMM/U_DOTS, typelib:1536](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/research/ciff-fields/metadata/CiffMgr.dll.typelib.json:1536), [core unit constant, 00:14](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/00-core.js:14), [parseHeader, 20:390](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/20-xml-load.js:390), [native preview conversion, 04:143](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/04-native-text-preview.js:143), [Header patch, 60:621](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/60-history-save.js:621).

Область белого листа/сетки выбирается **по каждой оси отдельно**: положительный `MaxImage*` → положительный `Image*` → размер известного профиля принтера. W/H полей, разрешение, поворот страницы и масштаб окна не определяют размер листа. При известном принтере отсутствующие/невалидные Max* затем заполняются этим результатом; корректные исходные значения, отличающиеся от аппаратного максимума, сохраняются.

Код: [resolveTemplateWorkspaceDimensions, 20:274](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/20-xml-load.js:274), [repairLoadedKnownPrinterProfile, 20:228](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/20-xml-load.js:228), [getCanvasInternalWidth/Height, 10:2022](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/10-canvas-ui.js:2022), [renderGrid, 30:798](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/30-rendering.js:798).

`ImageWidth/Height` — сохранённый размер использованного содержимого. Он **не обязан быть равен Max*** и текущий валидатор не требует `Image* <= MaxImage*`. При сохранении без изменения печатной геометрии сохраняются исходные Image*, даже если они больше Max* или отличаются от пересчитанных границ. После изменения печатных координат/размеров/поворота/видимости/набора полей Image* пересчитываются. Изменение только скрытого поля на расчёт не влияет.

Расчёт использует номинальные прямоугольники `geom`, а не точные чёрные пиксели или outlines: ширина = `ceil(max(x + rotatedWidth))`, высота = `ceil(max(y + rotatedHeight))`; при 90/270 W и H меняются местами. Начало отсчёта — (0,0); минимальная координата не вычитается. Учитываются только `printed !== false` (`Displayed=0` исключён). При наличии печатных полей минимум результата — 1. Если печатных полей не осталось, используется прежний размер Image*, поэтому удаление последнего поля само по себе не обнуляет Image*.

Код: [сравнение с исходной геометрией, 30:277](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/30-rendering.js:277), [calculateImageBounds, 30:402](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/30-rendering.js:402), [syncUsedImageSizeFromPrintableFields, 30:443](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/30-rendering.js:443), [patchSubHeaderLossless, 60:792](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/60-history-save.js:792).

Проверка выхода за область использует уже rendered bounds текста, если доступны native/Konva-метрики. Это другой прямоугольник, чем используемый для Image*. Печатное поле за Max* допускается при неизменном импорте: должны совпадать исходная область и геометрия самого поля. Сдвиг такого поля лишает исключения. Независимая аппаратная проверка использует пределы профиля принтера, а не Max*. Скрытые поля не проверяются как печатные. Canvas не обрезает объекты по границе белого листа; скрытые показываются по соответствующей настройке/выделению.

Код: [rendered bounds, 30:172](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/30-rendering.js:172), [проверка области, 30:460](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/30-rendering.js:460), [аппаратная проверка, 30:490](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/30-rendering.js:490), [рендер/видимость, 30:828](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/30-rendering.js:828).

### Выполненные размерные сценарии

Все значения таблицы — CIFF units, то есть 100 = 1 мм. Полный XML, validation и состояние — [dimension-probes.json](glyph/dimension-probes.json); вход/выход каждого сценария рядом отдельными CIFF.

| Вход / действие | Белый лист Glyph | Image* при сохранении | Результат |
|---|---:|---:|---|
| Image600×700, Max2000×3000, без изменений | 2000×3000 | 600×700 | Исходные Image* сохранены |
| То же; печатный A сдвинут вправо на100 | 2000×3000 | 700×600 | Max* не изменены |
| Image2500×2600, Max1600², печатное поле за областью, без изменений | 1600² | 2500×2600 | Сохранение разрешено |
| То же; x поля увеличен на1 | 1600² | prepared2501×2600 | Сохранение запрещено; модель возвращена |
| Скрытое поле в x9000,y10000 сдвинуто на1 | 2000×3000 | Исходные600×700 | Скрытый выброс игнорируется |
| Последнее печатное поле удалено | 2000×3000 | Прежние600×700 | Сработал fallback |
| A с ориентацией90°, x увеличен на1 | 2000×3000 | 501×700 | W/H поменялись местами |
| Max* отсутствуют, Image2100×3100 | 2100×3100 | 2100×3100 | Max* вставлены как2100×3100 |
| Все четыре размера отсутствуют | 5333×7500 из профиля | 0×0 | Preview возможен, save отвергает Image0 |
| CurrentOrientation90 + ImageRotation90 | 2000×3000 | 600×700 | Размер/поворот листа не применены |
| AutoSize1 | 2000×3000 | 600×700 | AutoSize сохранён, но не управляет preview |
| Печатное поле с отрицательным x отредактировано | 2000×3000 | prepared1×600 | Save запрещён |

## 3. Header/SubHeader: новое, импортированное и отредактированное

| Свойство | Новый Glyph | Импорт/последующий patch |
|---|---|---|
| ImageDesign/@Version | Всегда23 | Исходная версия сохраняется; проверяется непустота, не соответствие supported/native версии |
| Header/@DesignedFor | Из точного профиля+режима | Меняется при выборе модели/режима |
| Header/ClStVersionInfo | Начальная генерация | Перегенерируется при save из единого preparedCalculatedData; текущий pipeline 21.10, не старый RNG fallback |
| Header неизвестные атрибуты/дети, даты native | Не создаются | В основном сохраняются сырым XML, не моделируются/не обновляются |
| SubHeader FormatName/PrinterFormatName | Default/Default | Сохраняются; при отсутствующем SubHeader создаются Default/Default |
| ImageWidth/Height, MaxWidth/Height, XRes, CurrentOrientation | Выводятся всегда | Обязательны для save Glyph; отсутствующие вставляются; эквивалентное числовое написание сохраняется |
| YRes | Не создаётся | Исходный узел сохраняется, но **не читается и не используется** в preview |
| AutoSize, ImageRotation, ImageMirror, ImageInverse, LastUpdated | Не создаются | Сохраняются сырым XML, не управляют whole-page preview Glyph |
| SubHeader/@PrinterType | Не создаётся | Исходное значение сохраняется даже после смены Header/@DesignedFor |
| GenericSettings/ImageMapping | Создаётся | Отсутствующий mapping не добавляется без явного изменения ImageReference |

Код: [20:206](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/20-xml-load.js:206), [parseHeader/SubHeader, 20:390](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/20-xml-load.js:390), [Header patch, 60:621](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/60-history-save.js:621), [required SubHeader, 60:875](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/60-history-save.js:875), [структурный validator, 60:1778](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/60-history-save.js:1778), [смена принтера, 30:3180](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/30-rendering.js:3180).

YRes имеет отдельное практическое последствие: `getNativeTextRequest` передаёт native renderer и xRes, и yRes, равные XRes×10000. Native renderer умеет принимать разные разрешения, но XML YRes до него не доходит. Это подтверждённый пробел модели/предпросмотра для анизотропного разрешения; точная видимая разница требует native paired measurement. [04:9](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/04-native-text-preview.js:9), [GDI, font-renderer.ps1:297](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/electron/font-renderer.ps1:297).

Свежий [metadata-probes.json](glyph/metadata-probes.json) подтверждает сохранение Version24, Header/@Units/@DesignedWith/@OverrideAll/неизвестного ребёнка, SubHeader/@PrinterType="Other Printer", YRes0.24, AutoSize1, ImageMirror1, ImageInverse1 и LastUpdated. После выбора другого DataFlex и Intermittent меняется DesignedFor; эти сырые свойства остаются. Это **не** потеря при no-op import, но эти свойства не являются полноценно поддерживаемыми редактируемыми параметрами Glyph.

## 4. Условия формирования полей

| Узел / свойство | Новый field в Glyph | Импортированный field |
|---|---|---|
| FldType, X/Y/W/H | Всегда | Меняются известные прямые узлы; расширения с одноимёнными узлами не затрагиваются |
| Displayed | Только0 для скрытых | Включение печати удаляет исходный0; другие исходные значения сохраняются |
| Ln | Если не null, включая0 | Отсутствие сохраняется; явный0 сохраняется |
| Orientation | Только ненулевой | Исходный0 сохраняется |
| CalcData | Всегда, в том числе пустой CDATA | Непустой вставляется; уже существующий пустой сохраняется |
| LoggedField | Всегда пустой | Исходный узел/его отсутствие не переписывается |
| CLSID | Создаётся для DM; текст — без CLSID | Импортированный CLSID сохраняется |
| Object Static/Parse/Reference | Из модели; Reference по умолчанию пустая строка | Меняются только известные модельные свойства, неизвестные attrs сохраняются |
| DataType / Default | Всегда | Патч первого Object; DM — каждый сегмент |
| MaxNoOfChars | Если не null, включая0 | Независимо от FixedLen; нулевой исходный узел сохраняется |
| FixedLen | Только при явном fixedLen=true | Независим от MaxNoOfChars; PadChar/PadMode читаются и могут выводиться |
| VarText | При режиме user / соответствующем желании модели | Переключение fixed↔user меняет структуру; UserEnterData/Mask меняются только в VarText |
| Mask | Только непустая | Сохраняется/редактируется внутри VarText |
| UserEnterData | Всегда внутри нового VarText, включая пустое | Патч существующего VarText |
| SrcData | FixedText + DataType6 + srcData | Поддержан консервативный patch ConnStr/SrcSQL |
| SrcField | Если есть srcField; StartChar/NoOfChars/SelectMode — каждый если не null | Читаются; часть свойств и неизвестные расширения сохраняются исходным XML |
| OffsetDate | OffsetDateText+DataType3+непустой offsetRef | Синхронизируется при смене Current↔Calculated |
| CounterText/SubCnt | По FldTypeCounterText; Significance и пять параметров | Патч уже существующей структуры параметров |
| Locale/Calendar | В новом writer не выводятся | Читаются в модель, исходные узлы сохраняются, но writer их не обновляет по dateLocale UI |
| Clip, OverrideThis, Inverse, Mirror, RenderMode, Encryption, EqRef, Param, другие расширения | Нет полного генератора/редактора | Большинство сохраняются сырым XML; их semantics не воспроизводятся полностью |

Код: [60:1550](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/60-history-save.js:1550), [rules, 60:1648](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/60-history-save.js:1648), [writer, 60:1681](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/60-history-save.js:1681), [импорт Locale/Calendar, 20:567](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/20-xml-load.js:567). Точные девять XML-сэмплов — [new-field-probes.json](glyph/new-field-probes.json). Date/Time sample там показывает factory до `prepareCalculatedData`, поэтому формат в первоначальном CalcData не следует выдавать за итог финального save.

Шрифтовые свойства импортируются как nullable: отсутствующий Pitch остаётся отсутствующим, но effective native default =13. Новый текст получает явный Pitch с fallback10. `patchTextFontLossless` не канонизирует native defaults: при явно заданных Pitch13/XMag100 они будут записаны; при null отсутствие сохраняется. Bold/Italic ненулевые вставляются, существующие нулевые не удаляются. Face пишется в CDATA; неизвестные свойства Font/Text сохраняются. [20:586](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/20-xml-load.js:586), [60:1250](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/60-history-save.js:1250), [60:1750](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/60-history-save.js:1750).

Сохранение из UI сначала ожидает native-измерение dirty-текста и синхронизирует W/H; результат используется XML. При ошибке измерения save не должен продолжаться. Векторные outlines служат показу; XML по-прежнему содержит шрифт/параметры/размер поля, не SVG-контуры. Без native glyphFonts доступен fallback renderer, это отдельный риск совпадения, а не иная версия CIFF writer. [60:241](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/60-history-save.js:241), [04:59](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/04-native-text-preview.js:59), [04:120](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/04-native-text-preview.js:120).

## 5. Теги-поля в рецептах конструктора

Имена `GTIN`, `SN`, `BOX_COUNTER` сами по себе не меняют generic serializer. MaxNoOfChars, FixedLen, VarText задаются фабриками/рецептами, а не догадкой writer по имени.

Для партионного кода рецепт задаёт порядок `C1(~101), GTIN2(14нулей), C3(11), PRODUCT_DATE(6нулей), C2(10), SN(10нулей, максимум12)`; со счётчиком добавляет `C4(21), BOX_COUNTER(5нулей, максимум5)`. PRODUCT_DATE и BOX_COUNTER — user entered text. Их скрытость не отменяет запись Data/VarText или использование в SrcField DataMatrix. По умолчанию helper-поля скрыты; PRODUCT_DATE можно вывести печатным выбором дополнительного поля. У BOX_COUNTER Ln отсутствует, у остальных этого рецепта Ln1. Размер шрифта10 и XMag100 для всех этих helper-полей — **явно запрошенное пользователем поведение**, не несовместимость XML. Общий каталог ручного добавления и конкретный Party-рецепт могут иметь разные стартовые значения/лимиты.

Код: [каталог, 40:1378](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/40-editor.js:1378), [Party helpers, 45:192](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/45-template-preset.js:192), [печатность даты, 45:506](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/45-template-preset.js:506), определения композиции — [01-ciff-compatibility.js](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/01-ciff-compatibility.js).

## 6. Транзакция, history и формат файла

Save фиксирует `now` до асинхронного измерения; одна preparedCalculatedData используется и для XML полей, и для ClSt. При отказе validation модель откатывается; commit выполняется только для успешного save. История содержит исходную XML-строку вместе с моделью, поэтому undo возвращает также baseline для lossless patch и проверки исходной геометрии. Tabs v4 мигрируют старые сохранённые snapshots с учётом этого baseline; независимый размер листа не должен выводиться из derived Image*. [60:27](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/60-history-save.js:27), [60:350](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/60-history-save.js:350), [60:407](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/60-history-save.js:407), [70:114](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/70-template-tabs.js:114).

Выход CIFF: UTF-16LE с BOM, XML declaration UTF-16, внешние переводы строк нормализованы в CRLF; содержимое CDATA/SQL не должно механически сплющиваться. Наличие/отсутствие пустых необязательных узлов и порядок сохранённого импортированного XML отличается от канонического native writer, хотя файл может быть семантически эквивалентен. [60:548](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/60-history-save.js:548), [60:561](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/public/modules/60-history-save.js:561).

Старые выводы до исправлений21.10 о случайном/пустом ClSt, пропуске первого supported field и обязательной подмене Max* аппаратным максимумом **не описывают текущую2.3.0**. Для актуальной native-стороны нужны результаты соседних decomp/COM проб в этом же каталоге, а не механическое переиспользование старого списка ошибок.
