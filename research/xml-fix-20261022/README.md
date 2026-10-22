# Проверка исправленного Glyph → CIFF → ClariSoft — 22.10.2026

**Обновление после этого этапа:** расхождение XRes/YRes устранено, прежние шесть GUI-открытий завершены, дополнительно строго проверены и открыты в ClariSoft 20 новых CIFF из web/EXE. Пользовательский документ снова открыт без изменений. Актуальная сборка и итог: [xml-anisotropic-20261022/README.md](../xml-anisotropic-20261022/README.md). Числа и ограничение anisotropic ниже относятся к исторической матрице `exports-final`; новые доказательства находятся отдельно в `exports-resolution-final`.

## Итог финальной проверки

**18 реальных сохранений:** 9 из plain HTTP веб-версии и9 из настоящего заново собранного packaged EXE. Все18 файлов приняты original ICiffManager filename loader, Validate и Validate2. Все9 пар web/EXE совпали по параметрам исходной модели ClariSoft. Физические CIFF не переписывались во время проверки.

Текущая версия приложения2.3.1. Новый EXE:

[Glyph Studio.exe](<C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/desktop-release-xml-fix-20261022/win-unpacked/Glyph Studio.exe>)

Отдельный каталог сборки сохраняет имеющиеся приложения/сборки. Пользовательский установленный Glyph не был тестовым процессом; тестовый EXE использовал отдельный profile.

## Как доказано происхождение файлов

[runtime-fingerprints-final.json](runtime-fingerprints-final.json) до запуска подтвердил26 одинаковых модулей между production source, dist, HTTP и ASAR, включая20-xml-load.js,30-rendering.js,04-native-text-preview.js,60-history-save.js и Electron backend. Version source и packaged=2.3.1.

SHA-256 финального ASAR:

`d11df61c0b73bdc84ab8960434d9cb2a2f0ed31818812fe24f58e5174acc315a`

[export-web-exe.cjs](export-web-exe.cjs) использовал:

- настоящую HTTP-страницу http://127.0.0.1:5173/ без Electron preload/IPC; Vite отдавал тот же production source;
- отдельный процесс packaged Glyph Studio.exe с glyph://app/, его main/preload/worker и isolated userDataDir;
- production preset API для Party/Party-box и fixture preparation внутри реального renderer для остальных сценариев;
- настоящую кнопку Save диалога → production saveTemplateFromDialog/downloadCiff → физический browser download.

Это не Node-эмуляция сериализатора и не подмена EXE распакованным harness. PID/arguments/profile/log base, executable/ASAR SHA-256, download events, preSave/postSave состояние, native request/metrics и реальные PNG редакторов находятся в каждом expected JSON. Финальный запуск полностью завершился без recovery: [export-results-both.json](exports-final/export-results-both.json).

## Размеры в обоих путях

Все значения ниже — внутренние U_HMM единицы:100=1мм. Рабочая область намеренно16×24мм, меньше аппаратного предела DataFlex6320(53mm).

| Сценарий | ImageWidth×ImageHeight | MaxImageWidth×MaxImageHeight | Web | EXE |
|---|---:|---:|---|---|
| normal,3 шрифта и изменение X | 1033×1808 | 1600×2400 | Принят | Принят |
| no-op import с явно сохранённым Image777×888 | 777×888 | 1600×2400 | Принят | Принят |
| поле90° с изменением X/Y | 1392×1967 | 1600×2400 | Принят | Принят |
| скрытый выброс X9000/Y10000 | 1033×1808 | 1600×2400 | Принят | Принят |
| все поля скрыты | 0×0 | 1600×2400 | Принят | Принят |
| удалены последние печатные поля | 0×0 | 1600×2400 | Принят | Принят |
| XRes0.12/YRes0.24, без изменения геометрии | 1033×1808 | 1600×2400 | Принят | Принят |
| Party, GTIN2, без счётчика | 1300×1300 | 1600×2400 | Принят | Принят |
| Party-box, GTIN, с BOX_COUNTER | 1300×1300 | 1600×2400 | Принят | Принят |

Таким образом, пустое использованное изображение не превращает рабочий лист в0×0; скрытые источники не увеличивают Image*, а no-op import не теряет исходные объявленные Image*. Поворот учитывается при вычислении дальней границы. Max* не приравнивается автоматически к Image* или аппаратному максимуму.

## Шрифты, геометрия и данные

[native-validation.json](exports-final/native-validation.json) содержит18/18 status=ok, ноль ошибок/несоответствий. Оригинальные32-битные COM-компоненты прочитали70 полей:66 текстовых и4 DataMatrix.

Проверено:

- порядок/имена полей, Displayed, X/Y/W/H, Orientation и сохранённый CalculatedData;
-12 native font properties текстовых полей против состояния actual renderer с учётом native defaults: Face, Pitch, XMag/YMag, Bold/Italic, Family, BoldWeight, TTSize, TxtDir, CharSpace, PitchResolution;
- native text CalculateSize для обычного resolution:60/60 текстовых случаев совпали с actual Glyph native metrics;
-4 DataMatrix22×22:132×132dots и геометрия1100×1100 до прибавления X/Y;
- независимые native getters Image*/Max*/XRes/YRes;
- неизменность SHA-256 всех18 физических файлов после original load/component checks.

[web-exe-comparison.json](exports-final/web-exe-comparison.json) подтверждает9/9 совпавших web/EXE пар по всем записанным native параметрам. Побайтовое равенство файлов не требуется: ClSt содержит случайность.

### Party и исправление ширины SN

[party-properties-summary.json](exports-final/party-properties-summary.json) подтверждает4/4:

- выбор GTIN2 без счётчика и GTIN со счётчиком, в том числе в actual EXE;
- точный порядок SrcField/Data/Object;
- GTIN max14, PRODUCT_DATE max6, SN max12 и BOX_COUNTER max5;
- FixedText+VarText, Static0, FixedLen и исходные Default/UserEnterData;
- единый Pitch10/XMag100 у всех helper-полей;
- SN Default/UserEnterData остаётся10нулей; CalculatedData —10нулей+2пробела;
- concat actual DM preview segment values совпадает с сохранённым и original native payload;
- native canonical writer сохраняет выбранные semantic properties.

В промежуточной сборке SN preview измерял10 raw символов и давал230×47dots. Original ClariSoft CalculateSize использовал строку с padding и давал254×47dots. После дополнительного production-исправления **actual web и EXE preview теперь дают254×47dots**, как оригинальный компонент. Старые failing-before файлы сохранены отдельно в exports-party-r2 и описаны в [VERIFICATION_STAGE1.md](VERIFICATION_STAGE1.md); они не подменены успешными итогами.

## Анизотропное разрешение: точная граница результата

В двух финальных anisotropic случаях YRes0.24 сохранён в CIFF и прочитан оригинальным SubImage getter, actual renderer передал xRes1200/yRes2400. Font/XYWH/CalcData и четыре размера совпали с файлом.

Оригинальный CalculateSize в этой проверке использует реальные target-printer capabilities с квадратным разрешением. Поэтому его dot-metrics отличаются от anisotropic renderer:

| Поле | Renderer XRes0.12/YRes0.24 | Original component с target capabilities |
|---|---:|---:|
| Arial10 | 88×96 | 86×47 |
| Times13 | 83×125 | 84×62 |
| Courier8 | 102×73 | 100×37 |

Эти6 отдельных метрик явно записаны как equal=false с объяснением scope. Это не скрыто под утверждением полного совпадения печатного preview после всех conversions. Проверены сохранение свойства, загрузка и параметры модели; вся printer conversion здесь не объявляется эквивалентной.

## GUI и снимки

18 PNG в exports-final — настоящие captures web/packaged-EXE редакторов. Они не являются снимками ClariSoft. Например:

- [web normal](exports-final/web-normal-editor.png), [EXE normal](exports-final/exe-normal-editor.png);
- [web Party-box](exports-final/web-party-box-gtin-editor.png), [EXE Party-box](exports-final/exe-party-box-gtin-editor.png).

В самом ClariSoft подтверждены 12 открытий итоговых CIFF: обе версии normal, no-op, rotation, hidden-outlier, all-hidden и last-field-deleted. Полный путь, Ready, clean и отсутствие диалогов зафиксированы через Computer Use. На следующем файле helper перестал адресовать окно даже после обновления выбора; оставшиеся шесть имеют COM-проверку, но не завершённую GUI-проверку. Подробности и точка остановки: [GUI_VERIFICATION.md](GUI_VERIFICATION.md). Захват GUI ClariSoft также завершился timeout, поэтому полного визуального сравнения снимков нет.

## Что исправлено в production

- Image* рассчитываются по дальним границам только печатных полей, от нулевой границы; 90/270° меняют местами W/H. Пустая композиция даёт 0×0. Для native RSS типов учтена отдельная добавка высоты. Импорт без изменения печатной геометрии сохраняет объявленные Image*.
- Max* остаются независимой рабочей областью, включая явный ноль; только отсутствующий Max наследует соответствующий Image. Совместимая ветка Line расширяет MaxWidth при необходимости. Импорт проверяет обязательные и явно указанные Max-размеры до изменения текущего документа. U_DOTS отвергается до замены документа вместо трактовки как U_HMM.
- XRes/YRes разделены в запросах, кеше и преобразовании native метрик. Вкладки и история сохраняют YRes и нулевые размеры; прежние снимки вкладок мигрируют с учётом наличия новых свойств.
- Новые поля пропускают доказанные необязательные пустые узлы и native defaults. Значимые пустые FixedLen/VarText/SrcSQL/ClrStCntType сохраняются. Уточнены LoggedField, SrcData и Locale/Calendar/Encryption. При перестроении DataMatrix сохраняются дополнительные атрибуты и неизвестные свойства исходных Object, связанные со стабильным индексом источника.
- Предпросмотр и измерение текста используют тот же рассчитанный текст с FixedLen/partial SrcField, что XML/ClSt; редактируемое исходное значение не дополняется пробелами.

Не заявляется реализация всех native типов, календарей, page transformations или printer conversions. Явные некорректные Max-размеры отклоняются публичным import preflight; внутренний parseSubHeader предполагает уже проверенный документ. Отдельная обработка повреждённого YRes не входит в подтверждённую матрицу.

## Автоматические проверки и сборка

`npm run build` (TypeScript/Vite) и packaging EXE прошли после последней production-правки. Полный `npm test`: **501 тест, 491 пройден, те же 10 существовавших ранее статических UI failures**. Это проверки оформления toolbar/inspector/left panel/font CSS; исправления CIFF не добавили новых failing tests. Полный вывод: [full-suite-post-preview-fix.log](full-suite-post-preview-fix.log).

Связанные регрессии включают bounds/нулевые размеры/повороты/Max и единицы, независимый YRes, native omission semantics и сохранение DM extensions, вкладки/историю, рассчитанный текст. Реальный Windows GDI test подтверждает ширину SN 254×47 dots при десяти исходных символах и FixedLen12.

## Воспроизводимость и сохранность

[VERIFICATION_PLAN.md](VERIFICATION_PLAN.md) содержит команды. Финальная матрица находится только в exports-final. Предыдущие14 файлов в exports и4 failing-before Party в exports-party-r2 не перезаписывались.

Предварительный research-only CDP cleanup hang произошёл после завершённых сохранений старой матрицы; он описан в exports/manifest-recovery.json. В финальном exporter ожидание Browser.close ограничено, полный финальный запуск завершился штатно.

Использованы оригинальные зарегистрированные ClariSoft COM-классы и реальные capabilities. Установленные DLL/EXE не патчились; пользовательские Party.ciff/Party1.ciff и открытый пользовательский документ этим exporter не изменялись. Физический принтер не использовался.

После GUI-этапа [post-gui-hashes.json](post-gui-hashes.json) подтвердил неизменность всех 18 CIFF и пользовательского Party (Date+Par)NEW2.ciff относительно состояния после сохранения самим пользователем. Возврат пользовательского документа в окно ClariSoft не выполнен из-за сбоя helper; текущий проверочный документ указан в GUI_VERIFICATION.md.
