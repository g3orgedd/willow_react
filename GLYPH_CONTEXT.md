# GLYPH — MASTER CONTEXT EXPORT

## XRes/YRes: расхождение устранено и GUI завершён — 22.10.2026

Актуальный итог: `research/xml-anisotropic-20261022/README.md`.
Nativeproof: `research/resolution-preview-20261022/README.md`: freshEXE C/ASM,
24field metrics+48placement+8ResolutionAdjust probes. Editor берёт coder/format
capabilities, SubHeader X/Y не подменяют их. Native TT raster строится по capsY;
дополнительного bitmap X/Y aspect scaling нет. Rotation делается в dots, затем
деление по глобальным capsX/Y; signed-f32 rounding подтверждено native pixels.

Production changed только00-core/04-native-text-preview/font-renderer.ps1:
knownprofile target-res, source metadata сохраняются, quarterturn local axes
swap, workerSX=1. DataFlex6230(32mm) actual mappingIndependence .08/.08 исправлен;
остальные неподтверждённые UI-only models не получают выдуманный nativebinding.
Unknownprofile имеет explicitfile-resolutionfallback. Full printpipeline отдельно:
CSResolutionAdjust срабатывает лишьеслиОБА target/filefactor!=1; TTSize0 Pitch
можетмасштабироваться. Это не render resolution и не повод переписыватьвесьXML.

Итоговая новая сборка2.3.1: desktop-release-resolution-fix-20261022/win-unpacked.
ASAR a29577512aa370ee07f99197500859fddf02790b368fba5e9cd775b60b58753f,
26source/dist/HTTP/ASAR identical before/after. Новый actualSave suite20CIFF
находится в research/xml-fix-20261022/exports-resolution-final (старые не трогать).
20/20 Load/Validate/Validate2,80fieldproperties,76/76metrics+native/workerraster
exact,10/10pairs,48actualPath affine,96customPath affine,144customraster exact.
НЕТanisotropicexemption вновомverify-resolution.ps1. Старые6unequal устранены.

ВСЕ20новыхCIFFоткрыты вGUIClariSoft,Ready/clean/noerror. Старыеоставшиеся6
тожеоткрыты: прежняяматрица18/18completed. GUIproofиcompletion-summary.json
вxml-anisotropic-20261022. ПослеGUI пользовательский Downloads/Party (Date+Par)NEW2.ciff
ВОССТАНОВЛЕН открытым,Ready,disabledSave,500%,DataFlex6530(53mm),hashunchanged.
Все38CIFFunchanged. Предыдущаязаписьниже«ClariSoft оставлен тестовым»историческая.
CaptureClariSoftсноваFrameArrivedtimeout; GUI PNGнет, originalDraw не screenshot.
Nativeprinterrasterpixel-exact; сглаженныйvectorэкран проверен поPath/affine,
необъявлятьего1bppпопиксельнойкопиейGUIнакаждомzoom. Physicalprintнет.
Tests73/73focused; full506=496pass+теже10oldstaticUI failures. Build+packagingpass.

## Исправления XML по аудиту — 22.10.2026

Production исправлен по CIFF_XML_COMPARISON_2026-10-21.md. Итоговый отчёт:
`research/xml-fix-20261022/README.md`, финальные файлы только `exports-final/`.
Image*=max(0,right/bottom) только Displayed,90/270swapWH,empty/allhidden0×0;
no-op import сохраняет исходные объявленные Image*. Max* независимы, literal0
сохраняется, missing наследует Image своей оси. Line branch расширяет MaxWidth.
RSS10..14 имеют native1000 height adjustment; DM15 не затронут.
Units hmm/0 поддержаны; dots/unknown отклоняются до state mutation.
Обязательные Image и явно некорректные Max проверяются public import preflight.
YRes разделён с XRes в worker/cache/metric conversion и сохраняется в tabs/history.
Native omission/default rules уточнены, meaningful empty props сохранены;
DM rebuild сохраняет source Object metadata через stable sourceObjectIndex.
Preview/native measurement используют тот же CalcData snapshot, что XML/ClSt:
SN10нулей+FixedLen12 теперь254×47dots как native вместо230×47; ввод остаётся10.

После последней правки build+packaging прошли. EXE:
`desktop-release-xml-fix-20261022/win-unpacked/Glyph Studio.exe`,version2.3.1.
26source/dist/HTTP/ASAR fingerprints совпали. Actual web9+EXE9 Save/download,
original ClariSoft Load/Validate/Validate2 18/18,70fields,9/9pairproperties equal.
Normal resolution text metrics60/60 equal;6anisotropic metrics unequal из-за
real square target caps явно раскрыты; полной printer conversion parity нет.
В GUI проверены12/18 файлов Ready/clean; на13-м Computer Use перестал адресовать
window id даже после refresh. Остальные6 GUI не завершены. ClariSoft оставлен
на xml-web-anisotropic-yres.ciff; исходный пользовательский
`Downloads/Party (Date+Par)NEW2.ciff` обратно не открыт из-за helper failure.
Пользователь сам сохранил его перед продолжением; hash после его сохранения
совпал в post-gui-hashes.json, все18finalCIFF также неизменны. Не сравнивать
с более ранним baseline до самостоятельного сохранения пользователя.
Скриншоты ClariSoft capture timeout: новых GUI PNG нет, native Draw не screenshot.
Детали: `research/xml-fix-20261022/GUI_VERIFICATION.md` и gui-final/results.json.
Полный npm test501:491pass,те же10 старых статических UI failures; лог
`full-suite-post-preview-fix.log`. Прежние failing-before Party artifacts сохранены.
Это исправления доказанных случаев, не все27barcode/RichText/calendars/page transforms.

## Выбор GTIN партионного кода — 22.10.2026

На шаге «Настройки DataMatrix» для party-code добавлен выбор GTIN / GTIN2.
`partyCode.gtinFieldName` нормализуется в GTIN либо GTIN2 (default, включая
старые drafts). Выбранное имя используется в helper-поле, SrcField и сводке;
оба варианта имеют 14 нулей, max14 и прежние параметры пользовательского ввода.
Распознавание party/party-box, валидация и смена SymbolSize поддерживают GTIN;
обычные marking-коды с KRIPTO/KRIPTO2 остаются short/long. Счётчик независим.
Проверено: 49 связанных тестов, XML save/reopen обоих имён с/без счётчика,
TypeScript/Vite build; полный набор463/473 с прежними10 UI-failures.
В браузере проверены defaultGTIN2, выборGTIN, переходы назад/вперёд,
скрытие в обычном режиме, сводка и создание/Save GTIN+box.
Скриншот: `tests/output/party-gtin-selector.png`.

## Аудит формирования XML и размеров — 21.10.2026

Текущий отчёт: `CIFF_XML_COMPARISON_2026-10-21.md`; доказательства:
`research/xml-formation-audit-20261021/README.md`. Production не менялся.
Свежие104 функции C/ASM EXE/CiffMgr/CLPrintPreview;73 оригинальных COM-сценария
(67successful+6expected errors),23 production-harness сценария Glyph.
15hashes установленных ранее исследованных модулей совпали; OCX4.4.0.7 проверен отдельно.

CONFIRMED: editor фон/сетка `00E2D699` использует MaxImage* напрямую.
App aggregate `00E6600F/00E61D8E` = max(0,right/bottom) только Displayed!=0,
90/270swapWH; `00E67CDB` пишет Image*. Empty/allhidden =>0x0.
CiffMgr load/save сам этого не делает, AutoSize1 его не запускает.
Нативный новый AddSubImage(w,h) первоначально задаёт обе пары(w,h), даже пустой.
Missing Image* =>STG_E_OLDFORMAT; missing Max* наследует Image* своей оси.
PrintPreview paper `3F412CE9`: Max*, при0fallbackImage* по оси, затем caps;
BestFit `3F418143`: Image*. Подпись ImageSize через CountBlackDots получает Max*.
Image* может менять BestFit zoom без изменения Font/XYWH. Не объединять эти пути.

Glyph обычные bounds совпадают, но empty сохраняет прежний Image*, validator
требует положительные размеры. YRes сохраняется raw, preview передаёт обе оси=XRes.
U_HMM0=0.01mm; native U_DOTS1 отдельный, Glyph Units не моделирует.
AutoSize/whole-page rotation/mirror/inverse raw-preserved не равны render-поддержке.
New writer покрывает subset native properties; no-op import обычно сохраняет
расширения, DM structureDirty rebuild может потерять немоделируемые Object properties.
Пустые/default узлы отличать от semantic gaps; LoggedField empty и Not Logged
разные COM-состояния, print impactunknown. UI dateLocale не равен Locale/Calendar;
native RU-RU probe всё равноOct, добавление одного Locale не доказано как решение.
Уточнение прежней FIELD_FORMATION_SPEC: SubCnt включается при Used!=0(+0x7C),
не по непосредственной проверке NoOfChars. Pitch10Party — запрос пользователя.
GUI capture дважды timeout; свежих скриншотов/физической печати этот аудит не содержит.

## Партионный код в конструкторе — 21.10.2026

Тип dataSourceMode `party-code` выбирается на шаге источника данных конструктора.
Вариант `partyCode.withBoxCounter` задаётся на следующем шаге «Настройки DataMatrix»
кнопками «Без счётчика / Со счётчиком», видимыми только для партионного кода;
прежний чекбокс на шаге источника удалён. По умолчанию — без счётчика.
Рецепт: C1(~101), GTIN2(14 нулей), C3(11), PRODUCT_DATE(6
нулей), C2(10), SN(10 нулей); со счётчиком — дополнительно C4(21), BOX_COUNTER(5
нулей). GTIN2/PRODUCT_DATE/SN/BOX_COUNTER — FixedText+VarText, max14/6/12/5.
SN10 — начальное значение при максимуме12, как в обоих пользовательских CIFF;
FixedLen добавляет два пробела в CalculatedData. BOX_COUNTER не CounterText.
Источники скрыты; печатный PRODUCT_DATE повторно использует существующее поле.
По последующей просьбе пользователя все теги новых партионных шаблонов создаются
с Pitch10/XMag100: размеры3 и сжатие SN из исходных fixtures больше не копируются.
Импорт существующих CIFF сохраняет их исходные параметры.
Новые party/party-box композиции не меняют short/long; размер символа не меняет
партионные сегменты. Импорт исходного Party.ciff сохраняет barcodeC4/helperC5,
новая генерация использует barcodeField00/helperC4. FIELD_CATALOG и готовые
карточки дополнены GTIN2 и BOX_COUNTER. Исходные файлы не изменялись.
Артефакты — `research/party-template-20261021`, fixtures — `tests/fixtures/party`.
Оба варианта реально созданы/скачаны через production web UI (отдельный origin
5174), приняты original ICiffManager.load/Validate/Validate2. Это COM-проверка,
не screenshot/GUI-проверка ClariSoft и не физическая печать. Новые15 регрессий
проходят; полный набор454/464, те же10 старых статических UI-failures; buildpass.

## Формирование ClSt приведено к DLL — 21.10.2026

Production ClSt теперь использует native MSVCRT selection: 1–3 попытки среди
первых 32 полей без фильтрации типов, с reseed на каждом вызове. В Electron
используется системный uptime через preload; в обычном браузере — monotonic
uptime страницы. Сохранение берёт все SubImage в конечном XML-порядке.
Для первого SubImage один raw CalculatedData snapshot используется XML writer,
валидатором и ClSt; остальные сохраняют текущие значения из XML с учётом XML
нормализации переводов строк. Добавлены partial SrcField и native FixedLen padding.
Controls фильтруются только при записи XML; ClSt получает исходный snapshot.

EMPTY_TEMPLATE_CLST_VERSION_INFO и профильный 252-символьный fallback удалены.
Пустой шаблон вычисляет 72-символьный результат основного алгоритма. Каждый save
регенерирует токен, вместо сохранения произвольного старого значения. Добавлены
optional filename envelope, распознавание режима по исходному .ciff и Save As,
native ограничения ключа до NUL/14 UTF16 единиц и декодирование структуры.

Отчёт и воспроизводимые оригинальные COM/Unicorn проверки находятся в
`research/clst/implementation-2026-10-21/README.md`. Проверяется не только cipher:
готовые production CIFF принимает original ICiffManager.load + Validate/Validate2,
испорченные контрольные токены оригинальная DLL отвергает. Старое сравнение в
`CLARISOFT_CLST_ALGORITHM.md` описывает состояние до этих исправлений.
Неподдерживаемые native календарные форматы, custom locales и сложные источники
не угадываются: сохраняется их готовый CalcData. Полный resolver всех типов и
физическое принятие файлов Videojet по-прежнему не доказаны.

## Шрифты и нативный предпросмотр — 20.10.2026

Запрос сравнения скриншотов: заново сняты настоящие полный web-предпросмотр
и packaged EXE (1440×1100, read-only reopening, по 10 Path-полей), файлы
`research/fonts/vector-roundtrip-20261020/{web,exe}-vector-editor-full.png`.
Захват окна ClariSoft снова вернул timeout после одной документированной
повторной попытки; установленный Glyph Screenshots также не открыл targetable
окно и не создал нового снимка. Подробности — `GUI_CAPTURE.md` в той же папке.
Скриншотов ClariSoft нет; нельзя выдавать native Draw/layout PNG за такие кадры.
Галерея `web-exe-screenshots/index.html` — лишь частичный результат, не полное
визуальное сравнение с ClariSoft. Причина сбоя захвата неизвестна; блокировка
рабочего стола не доказана. Исходный backup восстановлен clean, 500%, normalwindow;
оба тестовых CIFF и backup сохранили SHA-256.

Повторная проверка после перехода на векторы: реальные Save/download из web
и из настоящего packaged `Glyph Studio.exe` (CDP, изолированный профиль), затем
оба physical CIFF открыты в GUI ClariSoft. Полный результат:
`research/fonts/vector-roundtrip-20261020/README.md`. По 10/10 полей совпали
все font/XYWH/rotation параметры, actual Path selfRect и шесть коэффициентов
transform (<1e-6 printerdot). GUI FieldOrder подтвердил 10/10 X/Y для обоих.
Оба CIFF 9958bytes/SHA D6046CD29CCB5200FE80726B4EB22734EF9D236307573018457D30953D0A367E,
то есть побайтно равны и друг другу, и прошлому printer-preview fixture.
Original Draw printerPNGs совпали для одинакового текста; clock web23:23→23:29
проверен отдельным current-payload reference, не подменяя исходный snapshot.
Контуры и 1bpp ink bounds различаются до 1 printerdot (0.08333мм) из-за
hinting/coverage, при точных cell/geometry; не утверждать pixel-identical
векторного экрана и GUI ClariSoft. Screenshot/GUI font-size dialogs остались
недоступны helper; шрифты/размеры подтверждены nativeкомпонентами. Backup
пользователя снова открыт clean. EXE evidence capture сделан read-only reopen
после успешного Save; provenance/recovery явно отмечены в expected-exe.json.

Веб-исправление после повторной жалобы: старый тестовый Vite, оставленный
агентом на `127.0.0.1:5173`, перехватывал запросы перед новым пользовательским
Vite на `0.0.0.0:5173`. Старый PS-worker отдавал PNG без outlinePath. Старый
тестовый сервер штатно остановлен через его exec-session; запросы localhost
и 127.0.0.1 теперь получают контуры. Для проверок использовать существующий
dev-сервер либо другой порт, не оставлять второй сервер на 5173.
Vite теперь отслеживает PS и два CJS-модуля, штатно перезапускается при их
изменении и очищает только их require.cache. `watchSource:true` версионирует
worker/cache по PS-source; desktop/asar не проверяют исходник на каждом render.
Настоящая веб-проверка без preload/IPC: `research/fonts/verify-web-fonts.cjs`,
16 проверок всех пяти текстовых типов/zoom50–400%/неизменности CIFF/чёткости
DataMatrix прошли; итоговые артефакты `tests/output/font-vector-web-final/`.

После жалобы на пиксельность экранный текст переведён с готового принтерского
bitmap на `Konva.Path` с контурами выбранного Windows-шрифта. Worker возвращает
`outlinePath` в координатах принтерских точек через `GetGlyphOutlineW`; canvas
заново рисует кривые при каждом zoom. Размеры/метрики и исходный PNG по-прежнему
считает тот же native GDI-код; CIFF и printer-dot X/Y не меняются. Пустой контур
означает пустой вектор, отсутствующий контур — bitmap fallback.
Сам GUI ClariSoft действительно кеширует bitmap: точная цепочка сохранена в
`research/fonts/vector-preview-20261020/CLARISOFT_EDITOR_RENDER.md`.
Гладкий экранный вектор Glyph — улучшение отображения; нельзя утверждать
нулевое попиксельное отличие этого вектора от 1bpp-принтерского растра.
Проверки frontend: `tests/native-text-vector-preview.test.cjs` и настоящий
Electron runtime в `research/fonts/verify-editor.cjs`; PNG для сравнения
масштаба 4× находятся в `tests/output/font-vector-preview/`.

Проверка реально сохранённого Glyph CIFF добавлена в
`research/fonts/roundtrip-20261020/README.md`. Штатный ICiffManager.load +
UpdateData/CalculateSize/Draw загрузили все 10 полей (5 текстовых типов,
7 семейств, Bold, XMag150, повороты0/90/180/270): Face/Pitch/XMag/X/Y/W/H
и bitmap совпали. Полная композиция Glyph и original Draw совпала с нулём
pixel differences при12dots/mm и4× увеличении. CIFF также открыт в самом
ClariSoft: подтверждены полный путь в заголовке, Ready/DataFlex6320(53mm)
и все 10 имён/координат в Tools→Field Order. GUI evidence фиксируется отдельно
в `research/fonts/roundtrip-20261020/GUI_VERIFICATION.md`; bitmap-композиции
не являются screenshot окна. Исходный Untitled* предварительно сохранён
в `user-untitled-backup.ciff` в той же папке.
После проверки backup снова открыт в ClariSoft без несохранённых изменений;
оба файла сохранили SHA-256. GUI Font/Pitch/W/H не прочитаны из-за Computer Use
cached-state error, эти значения подтверждены исходными COM-компонентами.
Исправлены повторное native-измерение при явной смене date/time format,
offset/counterconfig и отрисовка на printer-dot координатах: rawCIFFXY
сохраняются, nativeimage offset учитывает float32 round(X*resolution) и поворот.

`research/fonts/README.md` содержит новое исследование установленного ClariSoft,
COM-эталоны CalculateSize/Draw и PNG для сравнения. CONFIRMED: имя шрифта —
`Text/Font/Face`, `Family` — классификация GDI. У отсутствующего Pitch native default13.
У 18 проверенных DataFlex profiles UseTTFFonts=1, UseZFBF=0; девять имён в capabilities
не ограничивают выбор. Диалог ChooseFontW использует flags0x149, без CF_TTONLY.
Доступны установленные экранные шрифты Windows.

Glyph теперь загружает/сохраняет Face, Family, PitchResolution, YMag, TTSize,
TxtDir, CharSpace, Bold/Italic с сохранением неизвестного XML. Выбор шрифта
доступен для всех текстовых типов и группового выделения. Нативный GDI worker
`electron/font-renderer.ps1` создаёт native bitmap и векторные контуры;
frontend `04-native-text-preview.js` кеширует их независимо от zoom/позиции
и показывает контуры для обычного экранного текста.
Для явной смены шрифта размеры обновляются после измерения; сохранение дожидается
измерения и защищено от переключения вкладки. No-op import сохраняет source geometry.
Electron IPC и локальный Vite middleware используют общий worker; статический
веб-хостинг и другие ОС остаются на браузерном fallback. Complex-script/RTL,
ZFBF/UBF и физическая печать требуют отдельных проверок; не обобщать сравнение
обычных TrueType образцов на все эти пути.

## XML и различия принтеров — дополнение 17.10.2026

Сводный отчёт: `research/ciff-fields/XML_FORMATION_AND_PRINTERS.md`.
SHA-256 всех 15 ранее декомпилированных модулей совпадают с установленными.
Из `CLZipherBCP2.dll / XMLFILE / 203` извлечены 65 отображаемых имён Videojet
и 41 внутренний профиль. Выполнены 54 новые COM-пробы с реальными capabilities:
18 create/update/size/DM-resize, 18 замен DesignedFor, 18 согласованных замен
metadata файла и подизображения. Код Glyph и пользовательские шаблоны не менялись.

CONFIRMED: `SubImage.PrinterType` — отдельное свойство. Writer `6812C2CA`
выводит `SubHeader/@PrinterType`, если оно непустое и отличается от DesignedFor.
После загрузки CIFF смена только DesignedFor оставляет прежний PrinterType
подизображения; native-пробы получили атрибут со старой моделью. Согласованная
смена обоих свойств убирает атрибут, но всё ещё не пересчитывает XRes/геометрию.

CONFIRMED для этой установленной версии: 6320/6420 53 мм в одинаковом режиме
используют общий Zodiac profile, 6330 — Forrester, 6530 — Nimitz. У 6230 есть
реальный Independence(32mm) profile, 8 dots/mm; само имя 6230 НЕ доказывает
опечатку. У исследуемых 6320/6330/6420/6530 — 12 dots/mm. Native публичный Resize
для requested1000, DM22×22, QuietMargins0 дал Module38/W836/BcH836 у 6230,
Module42/W924/BcH924 у остальных. XML Field у 16 профилей 12 dots/mm совпал
в проверенном сценарии с исключением только runtime TimeText CalcData.

CONFIRMED по C/ASM: необязательная conversion `CS Field Order` сортирует по
(FieldLine, X), стабильно для равных ключей. Прямой writer перечисляет текущую
коллекцию; правило insertion order не распространяется на все conversion пути.

В папке Templates VideoJet 417 CIFF / 322 уникальных SHA-256; 415 XML разобраны,
у четырёх UTF-16LE байты при declaration UTF-8, два musli-файла не разобрались.
Есть смешанное происхождение файлов, поэтому частоты тегов не доказывают
причинное правило принтера. Физическая печать и все download-пути UNKNOWN.
Полный UI create/save не подтверждён из-за ошибок Computer Use; новые пробы COM.

## Формирование полей ClariSoft — 17.10.2026

В `research/ciff-fields/FIELD_FORMATION_SPEC.md` и `README.md` сохранено новое
исследование цепочки создания полей, расчёта данных/размеров и CIFF-сериализации.
Декомпилированы необходимые функции main EXE, CiffMgr, CiffHelper, семи компонентов
полей и двух converter DLL. Получены 137 native CIFF и 5 ожидаемых отказов свойств,
6 прямых native DataMatrix Resize и 4 совпадения полного COM ClSt с восстановленным
генератором. Production-код Glyph в этой работе не менялся.

CONFIRMED: ClSt collector `68118A19` читает `ICiffField.CalculatedData` (+0x98),
а не неизвестную дополнительную строку. XML CalcData пишется из того же свойства
с фильтрацией control chars; генерация ClSt проходит до этой фильтрации.
Внутренний EDataType и XML ClearStyleDataType — разные таблицы.
Native Field collection сохраняет insertion order, а Data Object сортируются
по Index; повторные имена/индексы заменяют элементы. Условные layout-conversion
этапы могут менять коллекции до записи, поэтому эти правила не заменяют анализ
конкретного printer/download пути. Точная печатная совместимость остаётся UNKNOWN.

## Обновление ClStVersionInfo — 05.10.2026

CONFIRMED для установленной `CiffMgr.dll` 4.5.0.0: преобразование `68117D03`
восстановлено и проверено выполнением оригинального машинного кода в Unicorn.
Существующая реализация `public/modules/clst/encryption.js` совпала на 3 прежних
контрольных векторах и 200 дополнительных примерах с ключами длиной 1–14.
Основной pipeline, optional-блок имени файла и основной путь для нуля полей
описаны в `research/clst/README.md`; там же генератор, декодер и native-доказательства.

Уточнения к старым разделам ниже: при флаге 0 содержимое ключа не участвует
во входах сети, влияет только его длина; поэтому изменение DDSSFF само по себе
не меняет токен. В генераторе нет особой неизвестной ветки для нуля полей:
нулевая маска и отсутствие TagData дают 72-символьный основной результат.
Готовая `EMPTY_TEMPLATE_CLST_VERSION_INFO` в Glyph взята из непустого CIFF
с маской 1 и 20-символьным DataMatrix payload, а не восстановлена для пустого.
Production пока выбирает первое поддерживаемое поле вместо native RNG и не
собирает optional-метаданные. Production-сохранение в этом исследовании не менялось.
Физическое принятие новых вариантов Videojet остаётся UNKNOWN.

## Уточнение размеров — 19.09.2026

CONFIRMED для приложенного `16x16_1.5Y.ciff`: `MaxImageWidth/Height=1600/1600`
задают рабочую область 16 × 16 мм; `ImageWidth/Height=2516/2558` описывают
границы содержимого, включая `Field02` за пределами этой области. Поэтому
старое утверждение ниже, что `MaxImage*` всегда равны аппаратным пределам,
нельзя использовать при определении физического размера документа.

Текущий контракт редактора: валидные `MaxImage*` → физический размер;
при их отсутствии — `Image*` по соответствующей оси, затем известный профиль.
Размеры головки берутся отдельно из `PRINTER_CAPABILITIES`; zoom и viewport
не меняют размеры CIFF. Изменение размера и создание шаблона записывают его
область в `MaxImage*`, смена принтера сохраняет её. Подробности и границы
проверки: `CIFF_TEMPLATE_DIMENSIONS.md`.

## Состояние знаний на 29.08.2026

Этот документ предназначен для переноса всего контекста проекта **Glyph** в другой аккаунт ChatGPT/Codex.

Главное правило для нового ассистента:

> Не начинать исследование CIFF и `ClStVersionInfo` заново. Сначала использовать подтверждённые ниже результаты. Новые выводы отделять на **CONFIRMED / INFERRED / UNKNOWN**.

---

# 1. Что такое Glyph

**Glyph** — разрабатываемый редактор и генератор шаблонов **CIFF/XML для Videojet**, создаваемый как независимая альтернатива работе через ClariSoft.

Главная цель проекта:

* создавать новые CIFF-шаблоны;
* открывать существующие CIFF;
* редактировать их визуально;
* сохранять обратно;
* генерировать шаблоны без обязательного открытия/пересохранения в ClariSoft;
* обеспечивать реальную совместимость с терминалами и принтерами Videojet.

Критерий успеха:

> CIFF из Glyph должен не просто быть XML-valid. Он должен приниматься терминалом и физическим принтером Videojet так же, как CIFF, созданный ClariSoft.

ClariSoft используется как **reference implementation / oracle**.

Основные принтеры:

* Videojet DataFlex 6320;
* DataFlex 6330;
* DataFlex 6530;
* в текущем коде также присутствует 6420;
* исторически встречался e3230;
* ошибочное `6230` в `DesignedFor` уже встречалось и рассматривалось как возможная причина несовместимости.

Исходный архитектурный курс проекта:

* React;
* TypeScript;
* Vite;
* Electron;
* Konva / react-konva для canvas;
* Material Design 3 → Material 3 Expressive.

В доступном текущем snapshot также есть модульные JS-файлы вроде:

* `00-core.js`
* `20-xml-load.js`
* `40-editor.js`
* `60-history-save.js`

Проект проходил несколько рефакторингов, поэтому текущий код нельзя автоматически считать окончательной архитектурой.

---

# 2. Основная философия разработки

## 2.1 ClariSoft важнее теории

Если:

* документация;
* старый вывод;
* предположение;
* текущая реализация Glyph

противоречат рабочему файлу ClariSoft и фактической проверке на Videojet —

**доверять рабочему файлу и принтеру.**

---

# 3. Lossless CIFF editing

Одна из главных архитектурных идей Glyph — **non-invasive / lossless editing**.

Для существующего файла предпочтительно:

1. открыть оригинальный CIFF;
2. сохранить оригинальную XML-структуру;
3. изменить только параметры, реально изменённые пользователем;
4. не регенерировать весь `<Field>` без необходимости;
5. не добавлять optional nodes только потому, что Glyph умеет их создавать.

Подтверждённые требования:

* патчить существующие XML blocks;
* сохранять исходный порядок элементов, если нет причины его менять;
* сохранять неизвестные Glyph узлы;
* не удалять неизвестные атрибуты;
* не вставлять автоматически:

  * `VarText`
  * `FixedLen`
  * `MaxNoOfChars`
* сохранять optional structures максимально losslessly.

Формат файла:

* XML encoding: **UTF-16 LE**;
* BOM;
* CRLF;
* исторически ClariSoft CIFF обычно сохранялся как XML declaration + практически весь `<ImageDesign>` одной длинной строкой;
* нельзя без причины pretty-print'ить XML.

Текущий код уже использует подход patch existing field вместо полной регенерации.

---

# 4. Базовая структура CIFF

Типичная структура:

```xml
<?xml version="1.0" encoding="UTF-16"?>
<ImageDesign Version="23" xml:space="default">

  <Header DesignedFor="...">
    <ClStVersionInfo>...</ClStVersionInfo>
    <DateOffset ... />
    ...
  </Header>

  <SubImage ...>

    <SubHeader ...>
      <ImageWidth>...</ImageWidth>
      <ImageHeight>...</ImageHeight>
      <MaxImageWidth>...</MaxImageWidth>
      <MaxImageHeight>...</MaxImageHeight>
      <XRes>...</XRes>
      <CurrentOrientation>...</CurrentOrientation>
    </SubHeader>

    <Field Name="...">
      ...
    </Field>

  </SubImage>

  <GenericSettings>
    <ImageMapping>
      ...
    </ImageMapping>
  </GenericSettings>

</ImageDesign>
```

Но:

> Не считать каждый тег этого skeleton обязательным для любого CIFF.

Рабочие ClariSoft-файлы могут отличаться по optional attributes/nodes.

Например, текущий Glyph генерирует:

```xml
<SubImage ImageReference="1">
```

но в реальных файлах встречается и просто:

```xml
<SubImage>
```

То же касается `FormatName`, `LoggedField` и некоторых других optional structures.

---

# 5. `DesignedFor`

Очень важное compatibility metadata.

Пример:

```text
DataFlex 6320(53mm) - Continuous
```

или:

```text
DataFlex 6320(53mm) - Intermittent
```

Значение зависит от:

* модели;
* ширины головы;
* режима Continuous / Intermittent.

Известный старый баг:

Glyph мог сформировать `6230`, тогда как рабочий ClariSoft-файл был для `6320`.

Это потенциально критично.

---

# 6. Смена модели принтера

Подтверждённое UX/CIFF правило:

Если пользователь меняет модель принтера, **не изменять автоматически существующий физический размер шаблона**, если он укладывается в возможности нового принтера.

Пример:

```text
текущий шаблон: 20 × 30 мм
новый принтер: DataFlex 6330 / 53 mm
```

Результат должен оставаться:

```text
20 × 30 мм
```

Нужно изменить:

* `Header DesignedFor`;
* printer capability;
* `MaxImageWidth`;
* `MaxImageHeight`;
* ограничения UI.

Не нужно превращать его автоматически, например, в:

```text
53 × 75 мм
```

Это было отдельным требованием для вкладки «Шаблон».

---

# 7. `ImageWidth` / `ImageHeight`

## CONFIRMED

Это **размер фактически используемой области SubImage**, а не размер DataMatrix и не аппаратный максимум принтера.

Их нужно отделять от:

```xml
<MaxImageWidth>
<MaxImageHeight>
```

Основная модель вычисления:

```text
ImageWidth  ≈ max(X + W)
ImageHeight ≈ max(Y + H)
```

по объектам, которые ClariSoft считает частью image bounds.

Нельзя:

* брать размер одного DataMatrix;
* хардкодить конкретные размеры;
* автоматически приравнивать Image dimensions к printer limits.

---

# 8. Эталон `clarisoft_fix6`

Очень важный regression fixture.

В эталонном ClariSoft-файле:

```text
ImageWidth  = 2516
ImageHeight = 2558
```

Glyph в одном из вариантов генерировал:

```text
ImageWidth  = 1100
ImageHeight = 1100
```

то есть фактически считал размер по одному DataMatrix.

В ClariSoft-файле дополнительный объект с координатами примерно:

```text
X = 2483
W = 33
```

давал:

```text
2483 + 33 = 2516
```

и аналогично по Y/H получался `2558`.

Поэтому:

> `2516 × 2558` — regression expected result для этого fixture, но НЕ универсальная константа.

---

# 9. `MaxImageWidth` / `MaxImageHeight`

Это **hardware / printer capability limits**.

Они зависят от:

* модели;
* головы;
* режима;
* возможно printer profile/capabilities.

Их нельзя путать с текущей рабочей областью.

Известное часто встречавшееся значение для 53 mm:

```text
MaxImageWidth = 5333
```

Для некоторых Continuous-профилей встречалось:

```text
MaxImageHeight = 7500
```

Но это **не универсальная пара для любого Videojet 53 mm**.

Например, сохранённый рабочий CIFF:

```text
DesignedFor = DataFlex 6530(53mm) - Intermittent

ImageWidth     = 4942
ImageHeight    = 1509
MaxImageWidth  = 5333
MaxImageHeight = 2000
```

Следовательно:

> Нужна централизованная таблица printer capabilities, а не один `5333 × 7500` для всего.

Точная полная capability matrix по моделям/головам/modes ещё не зафиксирована.

---

# 10. Текущий баг генерации нового пустого шаблона

В текущем `buildEmptyTemplateXml()` есть потенциально неправильная логика:

```js
<ImageWidth>${overallWidth}</ImageWidth>
<ImageHeight>${overallHeight}</ImageHeight>
<MaxImageWidth>${overallWidth}</MaxImageWidth>
<MaxImageHeight>${overallHeight}</MaxImageHeight>
```

То есть hardware maximum приравнивается к текущему размеру шаблона.

Это противоречит уже установленной семантике.

Должно быть концептуально:

```text
ImageWidth/ImageHeight = current template / content bounds

MaxImageWidth/MaxImageHeight =
    printer-profile hardware capability
```

---

# 11. DataMatrix

Glyph работает с DataMatrix ECC200.

Основные исследовавшиеся размеры:

* 20×20;
* 22×22;
* 36×36.

Ключевые параметры:

```xml
<BcH>
<ModuleSize>
<SymbolSize>
<QuietMargin>
<CLSID>
```

Известный CLSID DataMatrix:

```text
{7A4AA4CF-F5CD-11D4-8DAE-0050DAFE8A9F}
```

---

# 12. `ModuleSize`

`ModuleSize` — размер одного модуля DataMatrix во внутренних координатах CIFF.

Типичные исследованные значения:

```text
42
50
58
```

В XML может использоваться представление, нормализуемое Glyph.

Нельзя выводить совместимость только из одного `ModuleSize`: в нескольких сравнительных файлах он совпадал, а шаблон всё равно не работал.

---

# 13. `BcH` — подтверждённый алгоритм

Один из наиболее хорошо установленных алгоритмов Glyph/ClariSoft.

```text
BcH = numberOfRows × ModuleSizeInternal
```

Для квадратного DataMatrix:

```text
BcH = symbolSize × moduleSize
```

Примеры:

```text
22 × 42 = 924
22 × 50 = 1100
22 × 58 = 1276
36 × 50 = 1800
```

НЕЛЬЗЯ рассчитывать `BcH`:

* через `<Field><H>`;
* через `<Field><W>`;
* по bounding rectangle;
* с Quiet Zone;
* по визуальному размеру Konva object.

Пересчитывать при:

* создании DataMatrix;
* изменении ModuleSize;
* изменении SymbolSize;
* resize, если resize меняет module size;
* загрузке/нормализации;
* сохранении;
* CIFF serialization.

### Важная оговорка по старым заметкам

В старом анализе `clarisoft_fix6` была записана пара:

```text
ClariSoft BcH = 924
Glyph BcH    = 1100
```

а в другом месте тех же заметок было указано совпадение `ModuleSize=50`.

Это логически конфликтует с формулой:

```text
22 × 50 = 1100
```

Поэтому конкретный `ModuleSize` именно этой версии `clarisoft_fix6` нужно при необходимости перечитать из файла.

**Формула BcH подтверждена несколькими fixtures; противоречивую старую запись не использовать как математическое доказательство.**

---

# 14. Текущий потенциальный баг BcH в source

При создании Barcode текущий код первоначально делает примерно:

```js
bcH: field.geom.h
```

а serializer способен использовать:

```js
f.barcode.bcH ?? f.geom.h
```

Это опасно.

Перед сохранением должна существовать единая normalization function:

```text
normalizeBcH(field)
```

которая гарантирует:

```text
BcH = parsedSymbolRows × internalModuleSize
```

---

# 15. DataMatrix 22×22

Исторически профиль маркировки состоял из:

```text
C1
GTIN
C2
SN
C3
KRIPTO
```

Известные служебные значения:

```text
C1 = ~101
C2 = 21
C3 = ~d02993
```

Для обычного 22×22 не должны самопроизвольно добавляться:

```text
C4
KRIPTO2
```

Это части расширенного профиля.

Особенно внимательно относиться к:

```text
C
```

латинской и

```text
С
```

кириллической.

В старых шаблонах эта путаница реально встречалась.

---

# 16. DataMatrix 36×36

Для расширенного профиля добавлялись:

```text
C4
KRIPTO2
```

Из исследованных вариантов:

```text
C3 = ~d02991
C4 = ~d02992
```

Также рабочий 36×36 fixture содержал дополнительные поля/теги вроде:

```text
PRODUCT_DATE / PD
EXPIRATION_DATE / ED
PARTY / PAR
TIME / TM
R_NUM
PACKING_DATE / PACKD
```

Главный эталон:

```text
Only Code 2 2.08 - test x3 y14 36x36 PD ED PAR TM R_NUM PACKD(1).ciff
```

Пользователь физически подтвердил, что он работает.

ВАЖНО:

```text
Only Code 2 2.08 - test x3 y14 36x36 PD ED PAR TM R_NUM PACKD.ciff
```

без `(1)` был признан ошибочным.

Не использовать его как reference.

---

# 17. DataMatrix data objects

У Barcode может быть несколько:

```xml
<Data>
  <Object ...>
     ...
     <SrcField SrcFieldName="..."/>
  </Object>

  <Object Index="1" ...>
     ...
  </Object>
</Data>
```

Порядок segments имеет значение для результирующего содержимого DataMatrix.

При изменении количества/порядка segments допустимо перестраивать `<Data>...</Data>`, даже если остальной Field сохраняется losslessly.

---

# 18. `CalcData`

`CalcData` нельзя считать декоративным полем.

Особое внимание:

* пустой `CalcData` у Barcode;
* отличие от ClariSoft reference;
* неправильное составление DM payload;
* несогласованность с linked `SrcField`.

В старом сравнении `Glyph_test_1` одним из подозрительных отличий был пустой DataMatrix `CalcData`.

Это было потенциально критично, хотя позднее эксперимент с `ClStVersionInfo` показал, что не каждое такое отличие обязательно блокирует открытие шаблона.

---

# 19. `FixedLen`

`FixedLen` — **семантический**, а не косметический тег.

Были созданы/reference-файлы:

```text
SN_6_FIXED.ciff
SN_6_NONFIXED.ciff
```

Нельзя:

> добавлять `<FixedLen/>` каждому FixedText автоматически.

Особенно неправильно делать это для постоянных separators вроде:

```text
~101
21
~d02993
```

Для существующего CIFF:

> если `FixedLen` отсутствовал — сохранить отсутствие, пока пользователь не изменил соответствующую семантику.

Для новых variable/user-entered fields вроде:

* GTIN;
* SN;
* KRIPTO;

`FixedLen` используется, когда данные действительно должны иметь фиксированную длину.

Рабочий реальный файл показывает характерную структуру:

```xml
<Object Static="0">
    ...
    <Default>...</Default>
    <FixedLen/>
    <VarText>
        <UserEnterData>...</UserEnterData>
    </VarText>
</Object>
```

при этом constant separators не имеют `FixedLen`.

---

# 20. `VarText` / `Static`

Для user-entered FixedText характерно:

```xml
<Object Static="0">
```

и:

```xml
<VarText>
    <UserEnterData>...</UserEnterData>
</VarText>
```

Текущая логика Glyph определяет user-entered FixedText по:

* сохранённому `textEntryMode`;
* наличию `VarText`;
* либо `Static="0"` + фактический `UserEnterData`/Mask.

Это разумная модель.

Для fixed constant text `VarText` не должен появляться автоматически.

---

# 21. `MaxNoOfChars`

В предыдущих структурных сравнениях пользователь неоднократно требовал:

> `MaxNoOfChars` не учитывать как основную compatibility difference, если задача не посвящена длине поля.

Причина:

ClariSoft и Glyph могут сериализовать разные значения, которые сами по себе не объясняют отказ принтера.

Правило:

* сохранять исходное значение;
* не менять без необходимости;
* при structural diff по умолчанию не считать critical;
* при анализе именно ввода/field length учитывать.

---

# 22. `Pitch`

`Pitch` относится к шрифту/размеру текста.

В большинстве compatibility-анализов:

> `Pitch` исключать.

Не объявлять другой Pitch причиной CIFF incompatibility без прямого доказательства.

---

# 23. `LoggedField`

Семантика полностью не восстановлена.

Известно:

* `<LoggedField></LoggedField>` часто присутствует;
* в некоторых Field отсутствует;
* текущий serializer новых полей имеет тенденцию вставлять его автоматически.

Статус:

**UNKNOWN / LOSSLESS**

Правило:

* если он уже есть — сохранять;
* если его нет — не вставлять автоматически без доказательства;
* не считать его причиной ошибки только по факту отличия.

---

# 24. Date / Time / Offset Date

Glyph поддерживает:

* DateText;
* TimeText;
* OffsetDateText;
* CounterText.

Для OffsetDate существует связь:

```xml
<OffsetDate SrcOffset="..."/>
```

с соответствующим объектом Header:

```xml
<DateOffset Name="...">
```

Validator должен гарантировать:

```text
каждый SrcOffset → существующий Header DateOffset
```

В текущем коде такая проверка уже предусмотрена.

Поддерживались разные date formats и locales, включая EN/RU.

---

# 25. Hidden fields

Общее правило зависит от задачи.

При чистом структурном сравнении пользователь часто просил:

> скрытые поля не учитывать, если они не печатаются и не влияют на исследуемую проблему.

НО:

скрытое поле нельзя безусловно игнорировать при compatibility validation.

Были ситуации, когда hidden field:

* находился за `MaxImageWidth`;
* выходил за допустимые bounds.

Тогда даже hidden geometry могла быть потенциально важна.

Поэтому:

```text
comparison noise policy != save validator policy
```

---

# 26. Как сравнивать Glyph и ClariSoft

Если задача — **structural compatibility**, по умолчанию исключать:

* X/Y;
* W/H, если геометрия не является предметом анализа;
* имена Field;
* `SrcFieldName`;
* `Pitch`;
* `MaxNoOfChars`.

Иногда пользователь отдельно просил исключать:

* hidden fields;
* дополнительный FixedText `"."`.

Но это всегда зависит от конкретной задачи.

При реальном failure investigation сравнивать отдельно:

1. XML hierarchy;
2. child order;
3. missing/extra nodes;
4. Header;
5. DesignedFor;
6. ClStVersionInfo;
7. SubHeader;
8. Image/Max dimensions;
9. Barcode/DataMatrix;
10. CalcData;
11. CLSID;
12. FixedLen/VarText;
13. SrcField relationships;
14. encoding;
15. BOM;
16. CRLF;
17. binary diff.

---

# 27. Приоритет потенциально критичных отличий

Использовавшийся порядок расследования:

1. `DesignedFor`
2. `ClStVersionInfo`
3. `MaxImageWidth / MaxImageHeight`
4. `ImageWidth / ImageHeight`
5. `BcH`
6. `ModuleSize / SymbolSize`
7. `CalcData`
8. `CLSID`
9. `FixedLen`
10. `SrcField`
11. order of nodes — только если чувствительность подтверждена.

---

# 28. Главный принцип A/B testing

НИКОГДА:

> не менять одновременно десять параметров и потом объявлять один причиной.

Правильный тест:

```text
ClariSoft working file
        ↓
change exactly one thing
        ↓
send to terminal/printer
        ↓
record result
```

---

# 29. История ключевых рабочих/нерабочих CIFF

## 29.1 `LUZ_DEFAULT_WORK` vs `LUZ_DEFAULT_NOWORK`

```text
LUZ_DEFAULT_WORK.ciff    → работает
LUZ_DEFAULT_NOWORK.ciff  → после удаления Time перестал открываться
```

Исследование использовалось для понимания чувствительности CIFF к удалению Field.

Одна окончательная причина тогда не была доказана.

---

## 29.2 `22x22_1.ciff` vs `22x22 (31 char)_270days.ciff`

```text
22x22_1.ciff
    Glyph / edited
    → incompatible

22x22 (31 char)_270days.ciff
    ClariSoft
    → работает
```

Из этого расследования выросли проверки:

* Header;
* SubHeader;
* Image bounds;
* DataMatrix;
* optional tags.

---

## 29.3 `ZDRAVAAA` vs `ZDRAVA2`

```text
ZDRAVAAA.ciff → Glyph → не открывается
ZDRAVA2.ciff  → ClariSoft → работает
```

В различных diff обнаруживались:

* geometry hidden DM;
* TEAM за ImageHeight;
* отличия XML order;
* `CLSID`;
* `CalcData`;
* `FixedLen`;
* `ClStVersionInfo`.

Тогда одной подтверждённой причины не было.

Позднейшие эксперименты показали, что `ClStVersionInfo` гораздо важнее, чем изначально считалось.

---

## 29.4 `Clarisoft_test_1` vs `Glyph_test_1`

Эталон:

```text
Clarisoft_test_1.ciff
```

работает.

Glyph equivalent содержал расхождения.

В одном старом анализе отмечались:

* пустой Barcode CalcData;
* C3/С3;
* `~d02991` vs `~d02993`;
* место `CLSID`;
* сильно различающийся ClStVersionInfo;
* BcH;
* лишние MaxNoOfChars;
* XMag;
* Field naming/order.

Но не переносить старый список как доказательство того, что ВСЕ эти отличия вызывают отказ.

---

## 29.5 `NEW_OCH`

```text
NEW_OCH.ciff → Glyph → не работает
22x22 (31 char) - Only Code.ciff → ClariSoft → работает
```

Проверялись:

* BcH;
* ClStVersionInfo;
* DesignedFor;
* FixedLen;
* MaxNoOfChars.

Hidden fields по просьбе пользователя тогда не учитывались.

---

## 29.6 `clarisoft_fix6` vs `glyph_fix6`

Очень важный regression dataset.

Главный установленный баг:

```text
ImageWidth/ImageHeight
```

Glyph рассчитывал не так, как ClariSoft.

Также Glyph добавлял `FixedLen` константам, где ClariSoft его не имел.

Использовался для исправления:

* image bounding box;
* BcH;
* Field serialization.

---

## 29.7 `6330-53-1` vs `6330-53`

```text
6330-53-1 → не работает
6330-53   → работает
```

Эта ветка исследования в итоге привела к глубокому reverse engineering `ClStVersionInfo`.

---

## 29.8 `glyph_fix8`, `glyph_fix10`

Использовались для последовательных regression comparisons против ClariSoft.

В diff по просьбе пользователя исключались:

* coordinates;
* names;
* MaxNoOfChars;
* Pitch;
* иногда extra `"."`.

---

## 29.9 36×36 reference

Использовать:

```text
Only Code 2 2.08 - test x3 y14 36x36 PD ED PAR TM R_NUM PACKD(1).ciff
```

НЕ использовать предыдущий ошибочный вариант.

---

# 30. Ключевой эксперимент `ClStVersionInfo`

Это важнейший практический результат.

Был Glyph CIFF, который принтер/терминал не принимал.

В нём заменили **только**:

```xml
<ClStVersionInfo>...</ClStVersionInfo>
```

на значение из рабочего ClariSoft CIFF.

После этого:

* файл принял терминал;
* файл принял/открыл принтер;
* не понадобилось предварительно открывать его в ClariSoft.

Следовательно:

## CONFIRMED

`ClStVersionInfo` реально участвует в механизме CIFF compatibility/validation.

Это уже не просто гипотеза.

---

# 31. Что НЕ является `ClStVersionInfo`

Не считать его:

* GUID;
* декоративной random string;
* обычным hash всего XML;
* статической версией программы;
* строкой, которую можно просто захардкодить для всех файлов.

Сам факт random-компонента тоже уже подтверждён reverse engineering.

---

# 32. Старый hardcoded ClSt в Glyph

В текущем исходнике присутствует:

```js
EMPTY_TEMPLATE_CLST_VERSION_INFO = "PyOA!LMe37jF5gGD_..."
```

Это legacy workaround / placeholder.

Не считать его алгоритмом.

Цель:

> полностью убрать зависимость генерации новых файлов от hardcoded working ClariSoft value.

---

# 33. Reverse engineering `ClStVersionInfo`

## Статус на 29.08.2026

**Структурный алгоритм формирования восстановлен в значительной степени.**

Но ещё не следует утверждать, что есть независимый byte-for-byte reimplementation всего proprietary transform.

Основная цепочка:

```text
FUN_6811861c
    ├── FUN_68118879
    ├── FUN_68118e73
    ├── FUN_68118a19
    ├── transform through COM/vtable
    ├── FUN_6811823c
    ├── optional FUN_681182fa
    └── final transform / setter
```

Главный orchestrator:

```text
FUN_6811861c
```

---

# 34. `FUN_68118e73` — RNG

Функция по сути реализует:

```cpp
randomIndex(max)
```

В ней:

```text
GetTickCount()
→ seed PRNG
→ random()
→ result % max
```

То есть случайность реально входит в генерацию.

Важная особенность:

> функция reseed'ит PRNG через `GetTickCount()` при вызове, а не обязательно использует один долговечный random context.

Следствие:

два сохранения одинакового template потенциально способны дать разные internal selection mask и, соответственно, разные `ClStVersionInfo`.

---

# 35. `FUN_68118879` — получение structural counts

Функция заполняет три значения.

Условно:

```text
countA
countB
countC
```

Она:

* получает COM collection/interface;
* получает count;
* проходит верхнеуровневые объекты;
* получает nested collections;
* считает элементы.

В `FUN_6811861c` эти три значения позже преобразуются в строку:

```cpp
"%02ld%02ld%02ld"
```

Причём каждое ограничивается максимумом:

```text
99
```

То есть итоговый block всегда имеет вид:

```text
AABBCC
```

длиной 6 цифр.

Пример наблюдавшейся debug-строки:

```text
000101
```

---

# 36. Генерация random mask

Пусть:

```text
N = один из полученных structural counts
```

Если:

```text
N > 0
```

алгоритм делает примерно:

```text
k = 1 + random(min(N, 3))
```

После чего `k` раз выбирает:

```text
bitIndex = random(min(N, 32))
mask |= (1 << bitIndex)
```

Таким образом:

* mask 32-bit;
* максимум учитываются первые 32 selectable entries;
* обычно выбирается от 1 до 3 indices;
* одинаковый index может попасть несколько раз;
* поэтому фактически установленных bits иногда меньше `k`.

Потом mask сериализуется:

```cpp
"%08X"
```

то есть:

```text
8 uppercase hexadecimal characters
```

Например:

```text
00000001
```

Этот участок виден непосредственно перед вызовом `FUN_68118a19`.

---

# 37. `FUN_68118a19` — выбор строк по mask

Эта функция очень важна.

Концептуально:

```text
collectSelectedStrings(documentCollection, mask)
```

Она:

1. проходит верхнюю collection;
2. получает nested collection каждого объекта;
3. идёт по nested objects;
4. смотрит bit 0 mask;
5. если bit = 1:

   * получает соответствующий object/interface;
   * получает из него BSTR;
   * добавляет BSTR в accumulator;
6. после каждого nested element:

   ```text
   mask >>= 1
   ```
7. продолжает, пока mask не закончилась.

То есть mask определяет, **какие внутренние strings/identifiers попадут в ClSt construction payload**.

Для конкатенации вызывается:

```text
FUN_6811823c
```

которая является обычным BSTR concatenation helper через `VarBstrCat`.

---

# 38. Ограничение selected payload до 20 символов

В конце `FUN_68118a19`:

```text
if length > 20:
    take first 20 characters
```

То есть итог выбранных internal strings:

```text
selectedPayload.length <= 20
```

Это важная часть алгоритма.

---

# 39. `FUN_681181da`

Это не криптография.

По сути helper ownership/move BSTR:

```text
free old destination
destination = source
source = NULL
```

Не тратить время на его reverse engineering.

---

# 40. `FUN_6811823c`

Тоже не криптография.

Функция:

```text
destination += param
```

через:

```text
VarBstrCat
```

---

# 41. Формирование metadata string

После random selection:

```text
maskHex = "%08X" % mask
```

и:

```text
counts6 =
    "%02ld%02ld%02ld" %
       (
           min(countA,99),
           min(countB,99),
           min(countC,99)
       )
```

Далее эти строки отправляются через internal transformation method.

Сам вызов:

```text
object/vtable + 8
```

принимает несколько BSTR/parameters и возвращает новый encoded BSTR.

После него к результату добавляется transform выбранного payload.

---

# 42. Наблюдавшийся промежуточный payload

В live debugging внутри этой цепочки наблюдалась строка:

```text
MWNDu5BBD5YND7UFBSMsIQv26o5UE85GOV_JLmCUgNKn14TPOzS97KM64HYBKOUOpH
```

Это **не итоговый `ClStVersionInfo`**.

Она приходит как промежуточный вход в следующий transform.

В тот же момент целевой/старый BSTR в memory имел вид:

```text
PyOA!LMe37jF5gGD_OEeQJPAIR3Et2HVCOk4RKDB93Hl9AjBVgIOzL2x64vRUW...
```

Дизассемблирование final-stage вызова:

```text
6811881B ...
6811882F push [ebp+08]       ; intermediate MWND...
68118833 call [eax+08]
...
6811883F call [eax+7C]       ; set result
```

---

# 43. Последний результат live debugging: `68117D03`

В самой последней сессии reverse engineering 29 августа было установлено:

> `call [eax+08]`, который получает промежуточную строку `MWNDu5...`, ведёт в функцию около `68117D03`.

В captured arguments наблюдалось примерно:

```text
arg1 = encryption/transform object
arg2 = MWNDu5BBD5YND7UFBSMs...
arg3 = TpyRcNeyeK
arg4 = следующий context/parameter
...
```

`TpyRcNeyeK` следует пока называть:

```text
key-like / transform parameter
```

а не окончательно доказанным «cryptographic key».

Это сейчас **главный следующий RE target**.

Не возвращаться к `FUN_68118a19` и `FUN_68118e73`: их назначение уже достаточно понятно.

Нужно продолжать с:

```text
68117D03
```

и функциями, которые она вызывает.

---

# 44. `FUN_681182fa` — optional file metadata block

В `FUN_6811861c` присутствует optional branch.

Условие зависит от flag внутри generator object.

Эта функция:

1. получает path/name текущего document;
2. разбирает extension;
3. отдельно обрабатывает `.new`;
4. получает basename;
5. ограничивает его размер примерно 100 символами;
6. собирает строку через format:

   ```text
   "%s%s"
   ```
7. пропускает её через internal transform;
8. получает length результата;
9. форматирует length:

   ```cpp
   "%08x"
   ```

   — lower-case hex;
10. снова выполняет transform;
11. конкатенирует полученные blocks с предыдущим accumulator.

Таким образом `ClStVersionInfo` в некоторых режимах может быть связан не только со structural collection metadata, но и с file/path-derived information.

---

# 45. Важное следствие для determinism

Ранее пытались сопоставлять:

```text
XML difference → ClSt difference
```

как будто это hash.

Теперь известно, почему это ненадёжно:

```text
ClStVersionInfo содержит random selection mask.
```

Следовательно:

```text
same logical XML
```

не обязательно означает:

```text
same exact ClStVersionInfo string
```

Поэтому A/B-анализ надо проводить по **decoded structure / invariants**, а не по буквальному равенству строки.

---

# 46. Восстановленный high-level алгоритм `ClStVersionInfo`

Чистый псевдокод без имён Ghidra:

```text
function generateClStVersionInfo(document, context):

    # 1. Собрать structural counters
    countA, countB, selectableCount =
        inspectDocumentCollections(document)

    mask = 0
    selectedPayload = ""

    # 2. Создать random selection mask
    if selectableCount > 0:

        selectionAttempts =
            1 + randomMod(min(selectableCount, 3))

        bitRange =
            min(selectableCount, 32)

        repeat selectionAttempts times:
            bitIndex = randomMod(bitRange)
            mask = mask OR (1 << bitIndex)

        # 3. Собрать данные элементов, выбранных mask
        selectedPayload =
            collectNestedStringsByMask(document, mask)

        # 4. ClariSoft оставляет максимум 20 chars
        selectedPayload =
            first20Chars(selectedPayload)

        # 5. Proprietary transform selected part
        selectedBlock =
            Transform_Selected(
                selectedPayload,
                context.parameters
            )

    else:
        selectedBlock = ""


    # 6. Metadata
    maskHex =
        uppercaseHex(mask, width=8)

    counts6 =
        decimal2(min(countA, 99))
      + decimal2(min(countB, 99))
      + decimal2(min(selectableCount, 99))


    # 7. Transform mask + counters
    metadataBlock =
        Transform_Metadata(
            maskHex,
            counts6,
            context.parameters
        )


    core =
        metadataBlock + selectedBlock


    # 8. Optional file metadata branch
    if context.includeFileMetadata:

        normalizedName =
            deriveFileNameOrPath(document)

        fileBlock =
            Transform_FileMetadata(
                normalizedName,
                context.parameters
            )

        fileLengthHex =
            lowercaseHex(length(fileBlock), width=8)

        lengthBlock =
            Transform_LengthMetadata(
                fileLengthHex,
                counts6,
                context.parameters
            )

        core =
            lengthBlock
          + fileBlock
          + core


    # 9. Final proprietary transform
    result =
        Transform_Final(
            core,
            context.parameters
        )

    setDocumentClStVersionInfo(result)

    return result
```

---

# 47. `randomMod()`

По восстановленному ClariSoft behavior:

```text
function randomMod(n):
    seed = GetTickCount()
    srand(seed)
    return rand() % n
```

или эквивалент соответствующей CRT/helper реализации.

Для совместимости по distribution желательно воспроизвести этот behavior.

При unit-tests нужен injectable deterministic RNG, чтобы тесты не были flaky.

---

# 48. Что в алгоритме ClSt уже CONFIRMED

### CONFIRMED

* ClSt влияет на acceptance файла.
* Есть structural collection analysis.
* Получаются несколько counters.
* Три counter сериализуются как `"%02ld%02ld%02ld"`.
* Каждый capped at 99.
* Используется random selection.
* mask максимум 32-bit.
* выбирается до 3 random positions/attempts.
* mask форматируется как `"%08X"`.
* mask определяет, какие nested strings берутся.
* strings конкатенируются.
* selected payload обрезается до первых 20 characters.
* существуют несколько internal transforms.
* optional file metadata branch существует.
* длина одного transformed block сериализуется `"%08x"`.
* final encoded result передаётся setter'у COM/document object.
* один из final transforms traced к области `68117D03`.
* observed intermediate payload `MWNDu5...` является входом transform, а не готовым ClSt.

---

# 49. Что по ClSt ещё UNKNOWN

Нельзя пока выдавать за доказанный факт:

1. точный математический algorithm внутри `68117D03`;
2. название cipher/encoding;
3. является ли `TpyRcNeyeK` именно ключом или другим параметром;
4. точная семантика всех COM interfaces;
5. точная семантика `countA/countB/countC`;
6. точные назначения всех object offsets вроде:

   * `+AF4`
   * `+AF8`
   * `+AFC`
   * и offsets, которые Ghidra показывает иначе;
7. является ли file metadata branch обязательным для каждого режима;
8. как именно terminal декодирует/проверяет final string.

Причина осторожности:

Ghidra показывает часть `this` offsets с type confusion, а live disassembly и декомпилированный pseudocode местами дают разные смещения.

Поэтому в собственной реализации использовать:

```text
context.parameterA
context.parameterB
...
```

пока смысл не доказан.

---

# 50. Что НЕ нужно повторно исследовать

Новому аккаунту / Codex не нужно снова выяснять:

* что делает `FUN_68118e73`;
* зачем random mask;
* что `FUN_68118a19` выбирает strings;
* зачем `mask >>= 1`;
* почему максимум 32 bits;
* что selected payload capped at 20 chars;
* что `%08X` — mask;
* что `%02ld%02ld%02ld` — three counters;
* что `FUN_6811823c` — concat helper;
* что `FUN_681181da` — BSTR ownership helper.

Следующий meaningful RE target:

```text
68117D03
```

и вызываемые из неё functions.

---

# 51. Как реализовывать ClSt в Glyph

Не переносить Ghidra C code буквально.

Создать отдельный модуль примерно:

```text
clst/
    inspectDocument.ts
    randomMask.ts
    selectedPayload.ts
    metadata.ts
    transform.ts
    generator.ts
```

или аналогичный engine.

API:

```text
generateClStVersionInfo(ciffModel, printerContext): string
```

Разделить:

```text
1. deterministic structural extraction
2. random selection
3. payload construction
4. proprietary transform
5. final assembly
```

Так можно тестировать каждый этап независимо.

---

# 52. Обязательные tests для ClSt

## Random mask

Проверить:

```text
N = 0
N = 1
N = 2
N = 3
N = 31
N = 32
N > 32
```

## Selected payload

Проверить:

* bit 0;
* bit 1;
* несколько bits;
* mask=0;
* переход между nested collections;
* payload < 20;
* payload = 20;
* payload > 20.

## Metadata

```text
count = 0
count = 1
count = 99
count > 99
```

Должно cap до `99`.

## Integration

Использовать реальные ClariSoft templates.

---

# 53. Current source architecture / state

Текущий code state хранит примерно:

```text
xmlDoc
original xmlText
line1
line2
lineEnding
docMeta:
    version
    designedFor
    clStVersionInfo
    printerModel
    printMode
subImage:
    width
    height
    maxWidth
    maxHeight
    xRes
    orientation
dateOffsets
fields
selectedNames
showHiddenOnCanvas
grid
validation
```

Текущий parser читает:

* Field Name;
* FldType;
* Displayed;
* X/Y/W/H;
* Ln;
* Orientation;
* CalcData;
* DataType;
* Default;
* MaxNoOfChars;
* FixedLen;
* Static;
* Parse;
* VarText;
* UserEnterData;
* Mask;
* Pitch;
* XMag;
* CLSID;
* QuietMargin;
* BcH;
* ModuleSize;
* SymbolSize;
* DataMatrix segments;
* OffsetDate;
* CounterText.

---

# 54. Serializer

Текущий подход для existing Field правильный концептуально:

```text
existing field
→ locate original XML block
→ patch properties
→ preserve rest
```

Он патчит:

* Name;
* FldType;
* X/Y/W/H;
* Ln;
* Orientation;
* Displayed;
* CalcData;
* DM properties;
* Data segment region при необходимости.

Но нужно дополнительно следить, чтобы serializer не создавал лишние optional tags.

---

# 55. Validator перед save

Glyph нужен обязательный pre-save validator.

Проверять:

### XML

* parseable;
* UTF-16LE;
* BOM;
* CRLF.

### Header

* DesignedFor;
* generated/current ClStVersionInfo;
* DateOffset references.

### Printer

* model;
* head;
* mode;
* MaxImageWidth/Height.

### Geometry

* ImageWidth;
* ImageHeight;
* printable bbox;
* hardware bounds;
* suspicious hidden objects.

### DataMatrix

* SymbolSize;
* ModuleSize;
* BcH;
* CLSID;
* CalcData;
* segment order;
* `SrcField`;
* referenced fields exist.

### Fields

* duplicates;
* invalid/missing references;
* fixed vs variable structure;
* optional tags preserved;
* no accidental empty critical values.

Этот validator уже неоднократно планировался как один из главных следующих этапов.

---

# 56. Regression suite

Нужна постоянная fixture library.

## 22×22

* working ClariSoft;
* equivalent Glyph.

## 36×36

Reference с:

* C4;
* KRIPTO2;
* PACKING_DATE.

## FixedLen

```text
SN_6_FIXED
SN_6_NONFIXED
```

## Image bbox

```text
clarisoft_fix6
```

## DesignedFor

Наборы:

* 6320;
* 6330;
* 6530;
* 6420, если поддерживается;
* 32 mm;
* 53 mm;
* Continuous;
* Intermittent.

## ClSt

Несколько ClariSoft files с controlled changes.

---

# 57. Printer capabilities

Нужен единый registry, а не constants в разных UI/functions.

Например концептуально:

```ts
interface PrinterProfile {
    model: string;
    headWidthMm: number;
    printMode: "Continuous" | "Intermittent";
    designedFor: string;
    maxImageWidth: number;
    maxImageHeight: number;
    xRes?: number;
}
```

Все операции должны получать limits отсюда:

* new template;
* printer switch;
* resize validation;
* save;
* CIFF validator;
* UI.

---

# 58. Нельзя хардкодить размеры шаблона в printer profile

Profile должен задавать:

```text
maxWidth/maxHeight
```

но не:

```text
current template width/current template height
```

Это разные понятия.

---

# 59. Автоматическое уменьшение элементов

Была отдельная задача для маленьких templates, например:

```text
20 × 20 mm
```

при большом количестве дополнительных fields.

Требование:

* автоматически уменьшать элементы;
* использовать **максимально возможный**, а не слишком маленький font/size;
* не выбирать font 3, если реально помещается 5–6;
* после automatic layout пользователь должен снова иметь возможность resize через handles.

Был конкретный баг:

> auto-scaled fields после уменьшения нельзя было нормально resize'ить вручную.

Его нельзя вернуть при дальнейших refactors.

---

# 60. Canvas/UI capabilities

В Glyph уже проектировались/реализовывались:

* Zoom;
* Pan;
* 100%;
* Fit;
* Center;
* Grid;
* Snap;
* rulers;
* multi-select;
* alignment;
* resize handles;
* rotation;
* outline;
* field inspector;
* hidden fields;
* search;
* Undo;
* Redo;
* hotkeys.

---

# 61. Tabs

Glyph должен работать как multi-document editor.

Требования:

* несколько CIFF открыты одновременно;
* каждый в своей вкладке;
* при переключении state не теряется;
* сохраняется state canvas/view;
* tabs закрываются независимо;
* была запланирована кнопка:

  ```text
  Закрыть все вкладки
  ```

---

# 62. Drag & Drop

Требование:

* drag CIFF/XML в рабочую область;
* файл открывается в новой вкладке;
* область визуально реагирует;
* `canvasWrap / surface-card`;
* при hover/drop обсуждались blur/highlight эффекты.

---

# 63. UI design

Основной design direction:

* Material Design 3;
* затем Material 3 Expressive;
* профессиональный desktop editor;
* компактный;
* не превращать приложение в consumer/mobile UI;
* сохранять functionality при редизайне.

Обсуждались:

* compact top bar;
* contextual toolbar;
* Fit;
* 100%;
* inspector;
* Object tab;
* Template tab;
* DataMatrix context;
* Settings;
* empty states;
* collapsible Hidden;
* motion/error states.

Историческое изменение:

```text
Validation → Advanced
Advanced → Settings
```

с перераспределением настроек.

Также был дизайн-эксперимент с визуальным языком Nothing / Nothing Brand Reference, но это не должно менять назначение Glyph как инженерного CIFF editor.

---

# 64. Иконка

Концепция:

```text
DataMatrix + glyph tree
```

Основные цвета:

* green;
* graphite;
* white.

DataMatrix должен оставаться визуально узнаваемым.

---

# 65. Excel → XML workflow

Это отдельный функциональный блок Glyph, не связанный напрямую с CIFF.

Формат:

```xml
<unit_pack>
  <Document>
    <organisation>
      <id_info>
        <LP_info LP_TIN="1500023840">
          <pack_content>
            <pack_code>...</pack_code>
            <cis>...</cis>
          </pack_content>
        </LP_info>
      </id_info>
    </organisation>
  </Document>
</unit_pack>
```

## Режим «Коробы»

`pack_code` берётся из box barcode.

Несколько:

```xml
<cis>
```

формируются из codes.

## Режим «Паллеты»

```text
pack_code = Barcode
cis       = Boxes Barcode
```

Дополнительно:

* удалять crypto parts;
* экспортировать `Boxes Barcode` в Excel;
* без header;
* дробить по 30 000 строк.

---

# 66. Commercial / product context

Цель проекта не только исследовательская.

Если Glyph сможет стабильно генерировать CIFF, которые открываются на поддерживаемых Videojet так же, как ClariSoft, рассматривается возможность коммерческой продажи программы.

Есть потенциальный корпоративный интерес.

Отдельно обсуждались:

* стоимость продукта;
* возможность продажи;
* риски, связанные с Videojet/ClariSoft IP;
* перенос части/всего приложения на C#/C++;
* возможность сохранить существующий интерфейс при переносе backend/CIFF engine.

Финального решения о migration stack нет.

Практически разумная архитектура, обсуждавшаяся как вариант:

```text
existing UI
    ↓
CIFF engine
    ├── parser
    ├── serializer
    ├── printer profiles
    ├── BcH
    ├── bounds
    ├── ClStVersionInfo
    └── validator
```

где engine при необходимости можно позднее вынести в C#/C++ без полной переделки UI.

---

# 67. Что считать подтверждённым на данный момент

## CIFF

CONFIRMED:

```text
ClariSoft = reference generator.
```

CONFIRMED:

```text
XML validity alone is insufficient.
```

CONFIRMED:

```text
lossless editing is safer than full regeneration.
```

CONFIRMED:

```text
ImageWidth/ImageHeight != MaxImageWidth/MaxImageHeight.
```

CONFIRMED:

```text
ImageWidth/ImageHeight describe actual SubImage bounds.
```

CONFIRMED:

```text
MaxImageWidth/MaxImageHeight are printer capability limits.
```

CONFIRMED:

```text
switch printer ≠ resize template.
```

CONFIRMED:

```text
BcH = symbol rows × internal module size.
```

CONFIRMED:

```text
FixedLen must not be blindly added.
```

CONFIRMED:

```text
ClStVersionInfo can decide whether template is accepted.
```

---

# 68. Что ещё необходимо доказать

UNKNOWN / TODO:

* complete printer capability table;
* exact role of `LoggedField`;
* exact child order sensitivity;
* exact ClSt transform inside `68117D03`;
* exact semantics of ClSt structural counters;
* exact meaning of transform context parameters;
* rules for optional file metadata block;
* whether some hidden fields participate in image bounds on every ClariSoft version;
* whether all Videojet firmware versions validate ClSt identically.

---

# 69. Главные текущие технические долги Glyph

1. Убрать hardcoded `ClStVersionInfo`.
2. Завершить transform около `68117D03`.
3. Реализовать собственный `generateClStVersionInfo()`.
4. Централизовать printer capabilities.
5. Не путать image bounds с max limits.
6. Сделать один canonical BcH calculator.
7. Не использовать `geom.h` как fallback BcH перед сохранением.
8. Довести bbox calculation до ClariSoft behavior.
9. Закрепить lossless XML patching.
10. Не добавлять `LoggedField`, `FixedLen`, `VarText`, `MaxNoOfChars` без необходимости.
11. Сделать pre-save validator.
12. Сделать automated canonical diff.
13. Закрепить regression fixtures.
14. Прогнать generated CIFF на реальных 6320/6330/6530 и нужных heads/modes.

---

# 70. Приоритет дальнейшей разработки

## P0 — `ClStVersionInfo`

Продолжать reverse engineering:

```text
68117D03
```

до собственной реализации transform.

## P1 — regression suite

Не менять CIFF serializer без golden tests.

## P2 — printer profiles

Централизовать limits.

## P3 — validator

Блокировать явно некорректный save.

## P4 — lossless robustness

Round-trip:

```text
open → save without edits
```

должен давать максимально минимальный diff.

---

# 71. Golden round-trip test

Обязательный тест:

```text
input = working ClariSoft CIFF
open in Glyph
save without editing
canonicalDiff(input, output)
```

Идеальный результат:

```text
0 semantic changes
```

Разрешённые отличия должны быть строго известны.

Потом:

```text
send output to real terminal/printer
```

---

# 72. Canonical structural diff tool

Стоит сделать отдельный internal tool:

```text
compareCiff(reference, candidate, options)
```

Режимы:

```text
STRICT_BINARY
STRICT_XML
STRUCTURAL
COMPATIBILITY
```

`COMPATIBILITY` должен уметь исключать noise:

```text
coordinates
names
Pitch
MaxNoOfChars
```

но не прятать:

```text
DesignedFor
ClSt
BcH
ModuleSize
SymbolSize
CalcData
CLSID
references
bounds
```

---

# 73. Важное правило для нового ChatGPT/Codex

При следующем обращении пользователя типа:

> «почему этот Glyph CIFF не работает, а ClariSoft работает»

НЕ надо сразу выдавать список всех XML differences.

Алгоритм:

```text
1. Verify reference works.
2. Canonicalize diff.
3. Apply user's comparison exclusions.
4. Separate critical vs cosmetic.
5. Check known invariants.
6. Compare ClStVersionInfo.
7. Run one-variable A/B reasoning.
8. State CONFIRMED / LIKELY / UNKNOWN.
```

---

# 74. Важное правило для `ClStVersionInfo`

Если пользователь продолжит RE:

НЕ предлагать снова:

* сравнивать случайные ClSt strings глазами;
* искать GUID;
* начинать с RTTI `CCiffFile`;
* снова анализировать `FUN_68118a19` с нуля.

Уже известно:

```text
FUN_68118e73 → RNG/index
FUN_68118879 → collection counts
FUN_68118a19 → masked nested-string collector
FUN_6811823c → concat
FUN_681181da → BSTR move
FUN_681182fa → optional file metadata
FUN_6811861c → orchestration
68117D03 → current transform target
```

---

# 75. Short ClSt implementation spec for Codex

Задача Codex:

> Реализовать в Glyph отдельный ClStVersionInfo generation pipeline по восстановленной логике ClariSoft. Не хардкодить готовые строки. Structural extraction, random mask, selected payload, metadata assembly и proprietary transform разделить. Для ещё не восстановленного transform сделать интерфейс/adaptor и tests, но не придумывать алгоритм. После получения реализации `68117D03` заменить adaptor clean-room реализацией.

Core data structures:

```ts
interface ClStStructuralInfo {
    countA: number;
    countB: number;
    selectableCount: number;
    selectableStrings: string[];
}

interface ClStContext {
    transformParameterA: string;
    transformParameterB: string;
    transformParameterC?: string;
    includeFileMetadata: boolean;
    sourcePath?: string;
}

interface RandomSource {
    nextMod(maxExclusive: number): number;
}
```

Core functions:

```text
inspectClStStructure()
createSelectionMask()
collectSelectedPayload()
formatClStMetadata()
buildOptionalFileMetadata()
applyClStTransform()
generateClStVersionInfo()
```

Tests must use deterministic RNG injection.

Production RNG should reproduce ClariSoft tick-seeded behavior as closely as justified by RE.

---

# 76. Bootstrap prompt for a new ChatGPT account

После вставки этого документа в новый аккаунт можно дать следующий prompt:

```text
Это master context моего проекта Glyph.

Считай содержащиеся здесь CONFIRMED факты уже установленными и не начинай соответствующие исследования заново.

Glyph — мой редактор/генератор Videojet CIFF, где ClariSoft является reference implementation.

Главные текущие задачи:
1. закончить reverse engineering ClStVersionInfo с точки 68117D03;
2. реализовать собственный генератор ClSt без hardcoded strings;
3. сохранить lossless CIFF serialization;
4. централизовать printer capabilities;
5. закрепить ImageWidth/ImageHeight и BcH algorithms;
6. сделать validator и regression suite.

При анализе CIFF всегда отделяй:
CONFIRMED
INFERRED
UNKNOWN.

Если я присылаю рабочий ClariSoft и нерабочий Glyph файл:
- ClariSoft считать эталоном;
- выполнять canonical structural diff;
- не считать coordinates/names/Pitch/MaxNoOfChars причиной, если я не прошу их анализировать;
- не менять сразу много параметров;
- использовать A/B reasoning;
- фактический результат на Videojet имеет приоритет над старыми предположениями.

По ClStVersionInfo не возвращайся к нулю:
FUN_68118e73 = RNG/index;
FUN_68118879 = structural counts;
FUN_68118a19 = masked nested-string collection + max 20 chars;
FUN_6811823c = BSTR concat;
FUN_681182fa = optional file/path metadata block;
FUN_6811861c = generator orchestration;
следующий reverse-engineering target = 68117D03 и её callees.

Не придумывай неизвестную криптографию.
Если transform ещё не доказан — так и говори.
```

---

# 77. Главный итог

Glyph уже не находится на стадии:

```text
«почему CIFF вообще не работает?»
```

Большая часть структурных правил уже восстановлена.

Основной технический blocker сейчас:

```text
полное clean-room воспроизведение ClStVersionInfo final transform.
```

После этого архитектурная цель должна быть:

```text
Glyph CIFF
    ↓
terminal accepts
    ↓
Videojet opens
    ↓
no ClariSoft round-trip required
```

Это и есть основной критерий готовности CIFF-engine Glyph.
