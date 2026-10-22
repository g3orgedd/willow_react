# Совпадение текста Glyph и ClariSoft при разных XRes/YRes — 22.10.2026

## Результат

Расхождение устранено в production и заново собранном EXE. **Все 20 новых файлов, реально сохранённых из веб-версии и EXE, приняты оригинальными Load/Validate/Validate2 и открыты в самом ClariSoft: Ready, без ошибок и несохранённых изменений.** Все десять пар web/EXE совпали по native свойствам. Прежние шесть незавершённых GUI-проверок также завершены: исходная матрица теперь имеет 18/18 открытий.

Проверены 80 полей. У всех **76 текстовых полей** совпали размеры оригинального CalculateSize и actual renderer; **76 сравнений original Draw с реальным worker PNG дали ноль отличающихся пикселей**. Все 48 печатных текстовых Path совпали по шести коэффициентам преобразования, размеру cell и округлённому положению.

[Машинная сводка native-проверки](../xml-fix-20261022/exports-resolution-final/verification-summary.json) · [GUI20 и сохранность файлов](completion-summary.json) · [GUI20: отдельные наблюдения](gui-final/results.json) · [завершение прежних шести](GUI_PRIOR_SIX.md).

Новая сборка версии 2.3.1:

[Glyph Studio.exe](<C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/desktop-release-resolution-fix-20261022/win-unpacked/Glyph Studio.exe>)

ASAR SHA-256: `a29577512aa370ee07f99197500859fddf02790b368fba5e9cd775b60b58753f`. До и после проверки совпали 26 файлов source/dist/HTTP/ASAR. Предыдущие сборки и исходные доказательства не перезаписывались.

## Причина и исправление

ClariSoft editor передаёт текстовому компоненту capabilities выбранного кодера/формата. Сохранённые `SubHeader/XRes/YRes` являются отдельными свойствами файла и не подменяют их. Glyph ранее использовал разрешение из файла как разрешение font renderer: при source .12/.24 текст измерялся 88×96 вместо native 86×47 для Arial/ABC. Теперь для DataFlex 6320 renderer получает целевые 1200/1200, а исходные .12/.24 сохраняются в XML. Аналогично исправлены обратное отношение осей, значения меньше целевого разрешения и дробные отношения.

Три production-изменения:

- `04-native-text-preview.js`: единый выбор target resolution для метрик, кеша, физического масштаба и округления координат. Для неизвестного профиля явно остаётся file-resolution fallback. При поворотах 90/270 локальные оси масштаба меняются местами: получается native порядок «поворот в dots → перевод по глобальным осям».
- `electron/font-renderer.ps1`: удалено дополнительное растяжение bitmap/outline по XRes/YRes. В оригинальном TrueType font builder размер glyph raster определяется capsY; capsX участвует в последующем переводе ширины в физический размер.
- `00-core.js`: capabilities содержат обе оси; доказанный профиль DataFlex 6230(32mm) использует .08/.08, то есть request800/800. Остальные настройки документа, включая Image*/Max*, не приравниваются к этим значениям.

Независимое исследование: [resolution-preview-20261022/README.md](../resolution-preview-20261022/README.md). Оно содержит свежие C/ASM, 24 CalculateSize/Draw пробы, 48 placement-проб и отдельные 8 Resolution Adjust проб. Установленные ClariSoft EXE/DLL не патчились.

## Реальные сохранения и GUI

Каждая строка ниже сохранена через production Save/download в HTTP без preload и в настоящем packaged EXE с отдельным профилем. Затем каждый физический CIFF открыт оригинальным ClariSoft. Полные пути в заголовках, Ready, disabled Save и отсутствие диалогов записаны в `gui-final/*.txt`.

| Сценарий | Исходные XRes/YRes | Native target | Web GUI | EXE GUI |
|---|---|---|---|---|
| normal, три шрифта | .12/.12 | .12/.12 | Ready | Ready |
| anisotropic-yres | .12/.24 | .12/.12 | Ready | Ready |
| anisotropic-xres | .24/.12 | .12/.12 | Ready | Ready |
| lower-yres | .12/.06 | .12/.12 | Ready | Ready |
| lower-xres | .06/.12 | .12/.12 | Ready | Ready |
| fractional-rotation90 | .09/.135 | .12/.12 | Ready | Ready |
| fractional-rotation270 | .135/.09 | .12/.12 | Ready | Ready |
| DataFlex 6230(32mm) | .08/.08 | .08/.08 | Ready | Ready |
| Party, GTIN2 | .12/.12 | .12/.12 | Ready | Ready |
| Party + BOX_COUNTER, GTIN | .12/.12 | .12/.12 | Ready | Ready |

Файлы, настоящие screenshots Glyph и expected snapshots: [exports-resolution-final](../xml-fix-20261022/exports-resolution-final). Для просмотра: [web .12/.24](../xml-fix-20261022/exports-resolution-final/web-anisotropic-yres-editor.png), [EXE .12/.24](../xml-fix-20261022/exports-resolution-final/exe-anisotropic-yres-editor.png), [web 6230](../xml-fix-20261022/exports-resolution-final/web-profile6230-editor.png), [EXE 6230](../xml-fix-20261022/exports-resolution-final/exe-profile6230-editor.png).

Все 76 текстовых полей сравнивались строго, включая скрытые helper-поля. Для 4 Party-файлов отдельно совпали порядок объектов/тегов, максимальные длины, Pitch10 и SN padding. Четыре DataMatrix сохранили native размеры. Исключений для anisotropic в новом `verify-resolution.ps1` нет.

Дополнительно в **обоих actual renderer** проверены контролируемые non-square capabilities: .12/.24, .24/.12, .125/.125, .08/.12, все четыре поворота, отрицательные и дробные dot origins. Это отдельный API/fallback-тест, а не объявление нового физического принтера. Итоги: 96/96 affine-проверок и 144/144 сравнений native/worker raster. Источник каждого expected — оригинальный компонент; старый worker не использовался как эталон. Доказательства: [affine-verification.json](../xml-fix-20261022/exports-resolution-final/affine-verification.json), [custom-raster-verification.json](../xml-fix-20261022/exports-resolution-final/custom-raster-verification.json).

## GUI, восстановление и снимки

Первое свежее web-normal AX-наблюдение вернуло Ready/disabled Save, но без необязательного window.title. Повторное чтение того же процесса подтвердило полный путь; исходный результат сохранён в `priorObservations`. Файл не пересохранялся. Остальные 19 наблюдений прошли штатно. ClariSoft допускает один процесс: чистые проверочные документы закрывались Alt+F4 через Computer Use, затем оригинальный EXE запускался с очередным filename.

В конце **снова открыт пользовательский `Downloads/Party (Date+Par)NEW2.ciff`**, Ready, disabled Save, профиль DataFlex6530(53mm), zoom500%. [Подтверждение](user-document-restored.json), [сырой AX](user-document-restored.txt). Файл не сохранялся и сохранил SHA-256. Все 38 CIFF двух итоговых матриц также неизменны: [completion-summary.json](completion-summary.json).

Захват GUI ClariSoft снова вернул `FrameArrived timed out: timed out waiting on channel`. Поэтому подлинных снимков ClariSoft нет; original Draw PNG обозначают рендер компонента, не окно программы. Строгое пиксельное равенство доказано для принтерского однобитного растра. Сглаженный векторный экран Glyph проверен по native данным контура, размерам, положению и affine transform; он не объявляется попиксельной копией растрового экрана ClariSoft на любом zoom.

## Проверки и границы результата

Связанный набор — 73/73, включая реальные Windows/native метрики, source-metadata preservation, кеш и quarter-turn transforms. Полный набор: **506 тестов, 496 успешных, те же 10 существовавших ранее статических UI failures**. [Полный лог](full-suite.log). TypeScript/Vite и упаковка EXE прошли: [build.log](build.log), [packaging.log](packaging.log).

Воспроизводимые scripts: [export-resolution.cjs](../xml-fix-20261022/export-resolution.cjs), [verify-resolution.ps1](../xml-fix-20261022/verify-resolution.ps1), [fingerprint-resolution.cjs](../xml-fix-20261022/fingerprint-resolution.cjs). Контроль результатов не разрешает анизотропные расхождения и не меняет source CIFF.

Результат относится к показанным профилям/полям и предпросмотру редактора. Отдельная стадия печатного converter (`CS Resolution Adjust`, включая особое поведение TTSize0) исследована и описана в native-отчёте; все фазы полного printer conversion, любой неизвестный профиль и физическая печать не объявляются проверенными. Прежнее расхождение 6 метрик не оставлено как допуск: в новой матрице оно устранено и проверяется на точное равенство.
