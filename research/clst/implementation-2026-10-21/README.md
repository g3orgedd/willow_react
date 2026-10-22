# Формирование ClStVersionInfo по алгоритму Clarisoft

21 октября 2026 года production-генератор Glyph и путь сохранения исправлены по установленной `CiffMgr.dll` 4.5.0.0. Готовая константа пустого шаблона удалена. Пустой документ получает вычисленный токен длиной 72 символа; непустой документ использует текущие CalculatedData выбранных полей.

Источник — `C:\Program Files (x86)\CLARICOM\Data\CiffMgr.dll`, PE32 x86, 550400 байт, SHA256 `F1A3C15E39657C5D8B2A0391660BBA2809702B5B83E368C41584ABDD2955124B`. Математический алгоритм и адреса функций приведены в [CLARISOFT_CLST_ALGORITHM.md](../../../CLARISOFT_CLST_ALGORITHM.md). Его историческая таблица отличий относится к состоянию до этой реализации.

## Изменения в программе

| Узел | Текущее поведение |
| --- | --- |
| Выбор полей | 1–3 попытки MSVCRT rand с reseed на каждом вызове; повторные индексы допускаются; доступны первые 32 поля без фильтрации типа и скрытости |
| Источник времени RNG | Electron получает системный uptime через проверенный IPC; браузер использует performance.now; тесты могут передать tickCounts, nextMod или маску |
| Значения полей | Один подготовленный raw CalculatedData snapshot для сериализации, проверки согласованности и ClSt |
| Несколько SubImage | Поля всех подизображений входят в сквозной порядок конечного XML; заглушки UnsupportedClStField удалены |
| Пустой шаблон | Маска 0 и обычная композиция E; никакой готовой строки или профильного токена в production нет |
| Сохранение | ClSt пересчитывается для конечной структуры документа; старое произвольное значение не используется как fallback |
| Optional filename | Распознаётся по исходному токену и имени .ciff; флаг сохраняется в состоянии вкладки; Save As записывает новое имя |
| Преобразование E | Добавлены native-ограничения ключа до первого NUL и максимум 14 UTF16 единиц, расшифровка и проверка структуры |
| SrcField | Поддержаны StartChar, NoOfChars, SelectMode, включая выбор справа; параметры сохраняются в модели и новом XML |
| FixedLen | Нестатические значения дополняются по PadChar/PadMode; длинные значения не обрезаются; отсутствующий PadChar означает пробел, пустой PadChar означает NUL |

XML получает отдельную фильтрацию U+0000–001F, кроме TAB/LF/CR. ClSt читает значения до этой фильтрации. При подготовке обычных model properties учитывается native-усечение на NUL; само преобразование E обрабатывает полный BSTR, включая NUL. При импорте CiffMgr превращает CR/CRLF в LF, включая CR из XML character references. Glyph повторяет это для импортированного CalculatedData всех SubImage. Новые raw значения редактора не проходят такую нормализацию перед ClSt.

Сохранение замораживает дату и время и вычисляет поддерживаемые динамические значения один раз. DataMatrix, поле-источник, XML CalcData и ClSt используют один и тот же результат. Старый предварительный synchronizeAllDataMatrixDerivedState больше не перезаписывает сохранённый CalcData неподдерживаемого календарного формата его строкой формата.

## Проверка оригинальной DLL

Проверки используют исходные COM-классы без изменения DLL. Нативные результаты и выходные файлы остаются в этой папке.

- 206 исходных x86-исполнений преобразования E совпали с production, включая ограничения ключей и UTF16.
- 438 исполнений оригинального пути GetTickCount → srand → rand → remainder совпали с production RNG при тех же injected ticks.
- 13 полных original COM-генераций совпали с production при фактических native масках и исходных CalculatedData. Проверены 0, 1, 2, 3, 31, 32 и 33 поля, пустые значения, несколько SubImage, скрытые и графические поля, controls и суррогатные пары.
- 39 токенов, сформированных production core в основных и optional режимах, приняты оригинальными ICiffManager.load, Validate и Validate2. Все 13 намеренно повреждённых контрольных файлов отвергнуты с HRESULT `80040241`.
- Все **43 из 43** файлов, полученных через полный production prepare/save, загружены и приняты оригинальной DLL. Результаты находятся в [saved-native-verification.json](saved-native-verification.json). Для каждого проверены загруженные CalculatedData, соответствие токена исходному raw snapshot и повторная сборка токена, заново сгенерированного DLL.
- Отдельные native ResolveField-пробы подтверждают частичные ссылки, padding, пустой операторский ввод, статические значения и отсутствие обрезки длинных строк. Для составного DataMatrix с partial SrcField/padding и для прямого динамического TimeText выполняется также native ResolveField после загрузки готового Glyph CIFF.
- Пять отдельных [проб XML-импорта](native-import-results.json) подтверждают нормализацию CR из character references в CalculatedData, Default и UserEnterData. Браузерный DOM сам по себе не воспроизводит эту особенность CiffMgr; нормализация добавлена в importer Glyph явно.

Полный production save запускается через существующий Node harness: используются реальные parser, resolver, serializer и save-функции Glyph, заглушки DOM/UI и отключённые проверки геометрии. Это проверка сформированных байтов и работы оригинального COM-генератора и валидаторов. Она не является взаимодействием с GUI или физическим принтером.

## Тесты проекта

Связанный набор ClSt, CIFF и размеров принтеров проходит **257 из 257** проверок; полный вывод сохранён в [clst-ciff-tests.log](clst-ciff-tests.log). TypeScript и Vite build проходят: [build.log](build.log).

Общий `npm test` также запускает статические UI-проверки: 439 из 449 проходят. В нём остаются 10 ошибок в editor-workspace, inspector-navigation, left-panel и topbar: их ожидания не соответствуют текущим CSS/JSX. Эти UI-исходники в данной работе не менялись. Полный журнал — [project-tests.log](project-tests.log).

Ключевые регрессии закрепляют пустой токен, несколько установленных битов, бит 31, предел 32, все SubImage, optional Save As, ремонт некорректного загруженного значения, raw controls, NUL, UTF16-усечение, XML newline normalization, partial SrcField и padding. Отдельный тест проверяет единственный вызов динамического форматтера для поля, DataMatrix и ClSt.

Строгая побайтная проверка статического ClariSoft fixture сохранена: тест передаёт фактическую импортированную маску. Политика случайного выбора по умолчанию больше не обязана повторять маску старого сохранения.

## Воспроизведение

Команды выполняются из корня проекта. COM-скрипты требуют 32-битный Windows PowerShell и зарегистрированную исследуемую DLL. Их wrapper проверяет нужные интерфейсы; конкретные команды и хеши исходников фиксирует итоговый manifest в этой папке.

```powershell
node research/clst/implementation-2026-10-21/run-final-verification.cjs
node --test tests/clst*.test.cjs tests/ciff*.test.cjs tests/template-target-width.test.cjs
npm run build
python research/clst/implementation-2026-10-21/verify-native-machine.py
node research/clst/implementation-2026-10-21/save-through-production.cjs
& 'C:\Windows\SysWOW64\WindowsPowerShell\v1.0\powershell.exe' -NoProfile -ExecutionPolicy Bypass -File research\clst\implementation-2026-10-21\validate-production-files.ps1 -InputFile research\clst\implementation-2026-10-21\saved-production-inputs.json -OutputFile research\clst\implementation-2026-10-21\saved-native-validation.json
node research/clst/implementation-2026-10-21/verify-saved-native.cjs
```

[final-manifest.json](final-manifest.json) фиксирует все команды и их exit codes, исходную DLL, хеши production-файлов до и после проверки и итоговые количества. Исполнение проверяется на неизменных исходниках.

`tests/clst-dll-equivalence.test.cjs` повторяет сравнения production с сохранёнными результатами оригинальных машинных инструкций и COM. Он не выдаёт чтение JSON за новое исполнение DLL. Полное свежее исполнение выполняют перечисленные native-скрипты и итоговый runner.

## Границы соответствия

**CONFIRMED:** основной ClSt pipeline, empty path, selection RNG, transform, optional filename mode и проверенные варианты production save соответствуют этой DLL. При одинаковых входных CalculatedData и маске получаются побайтно одинаковые токены.

**UNKNOWN:** полная эквивалентность предшествующего расчёта произвольных native календарей, локалей, внешних источников и сложных runtime-счётчиков. Glyph сохраняет готовый CalcData тех путей, которые он не умеет надёжно пересчитать. Он не подставляет текст неизвестного формата вместо runtime-значения. Это ограничение resolver, а не недостающая ветка шифрования ClSt.

В браузере без Electron недоступен GetTickCount ОС: используется монотонное время страницы с тем же MSVCRT-шагом и reseed. Случайный выбор конкретной другой сессии Clarisoft не воспроизводится по одному XML; для такого сравнения нужна её маска или ticks.

Приёмка физическим Videojet и поведение других сборок Clarisoft/firmware не проверялись.
