# Проверка XML-исправлений — 22.10.2026

Этот каталог содержит исследовательские проверки. Production-файлы, запущенный пользовательский Glyph, его профиль и пользовательский CIFF не используются как тестовая среда.

## Подготовлено

- verification-baseline.json: текущие процессы, один Vite на0.0.0.0:5173(PID26952), существующие ASAR и их SHA-256. Installed ClariSoft и Glyph Studio пользователя уже открыты; не закрывать их ради сборки.
- export-web-exe.cjs: настоящий HTTP-renderer без preload/IPC и отдельный процесс новой packaged Glyph Studio.exe с isolated profile/CDP. Фикстуры подготавливаются кодом внутри реального renderer; затем нажимается настоящая кнопка Save в диалоге. Физические browser downloads, снимки редактора, параметры preview до Save, состояние после Save и provenance сохраняются в exports.
- verify-native.ps1: original ICiffManager.load(filename), Validate/Validate2, SubImage getters, original text UpdateData/CalculateSize с реальными capabilities. Сравниваются все четыре размера, число/видимость полей, X/Y/W/H, Orientation, CalcData, шрифт и dot-metrics. Проверяется неизменность входных файлов.

На этапе подготовки UI и сборка не запускались. Пройдены node --check и PowerShell parser.

## Матрица в каждом режиме

Во всех случаях MaxImageWidth/Height =1600×2400, то есть16×24мм, меньше аппаратного максимума DataFlex6320(53mm).

| Сценарий | Действие | Ожидаемое Image* |
|---|---|---|
| normal | Три FixedText: Arial10, Times New Roman13, Courier New8/XMag125; явный сдвиг первого поля | max правых/нижних границ печатных полей |
| no-op-import | Исходный normal CIFF с объявленным Image777×888, без изменений полей | 777×888 независимо от текущих границ |
| rotation | Поворот первого поля90°, положениеX1000/Y1250: swapped rectangle определяет дальние края | Пересчёт с W/H swap |
| hidden-outlier | Добавлено скрытое GTIN2 в X9000,Y10000 | Исходный Image normal |
| all-hidden | Все печатные поля скрыты | 0×0 |
| last-field-deleted | Удалены все поля из сохранённого normal | 0×0 |
| anisotropic-yres | Вход normal с XRes0.12/YRes0.24, без изменения полей | Исходный Image normal; YRes0.24 сохраняется, native request использует1200/2400 |

В anisotropic-yres параметры XML/Font/XYWH сравниваются строго. Разница метрик между anisotropic renderer и original CalculateSize с реальными capabilities принтера записывается отдельно и не скрывается как совпадение: проверка не утверждает эквивалентность всех printer conversions.

ClSt случайный; побайтовая идентичность web и EXE не утверждается. Проверяются семантика и параметры. Снимки web/EXE являются снимками редакторов; они не называются скриншотами ClariSoft. Native GUI открытие выполняет root отдельно через Computer Use.

## После подтверждения готовности production

Сначала npm run build. Затем сборка в **новый** каталог, чтобы не очищать используемую desktop-release-local:

```powershell
node node_modules/electron-builder/cli.js --win --dir --config.directories.output=desktop-release-xml-fix-20261022
```

Перед запуском убедиться, что итоговый ASAR содержит новые модули, и сохранить hash. Запуск матрицы из корня проекта:

```powershell
& './node_modules/electron/dist/electron.exe' 'research/xml-fix-20261022/export-web-exe.cjs' --mode=both
& 'C:/Windows/SysWOW64/WindowsPowerShell/v1.0/powershell.exe' -NoProfile -ExecutionPolicy Bypass -File 'research/xml-fix-20261022/verify-native.ps1' -InputFile 'research/xml-fix-20261022/exports/native-inputs-both.json'
```

Параметры exporter:

- --mode=web, --mode=exe, --mode=both
- --suite=dimensions, --suite=party, --suite=all (9cases×2=18 actual saves)
- --output=абсолютный-новый-каталог
- --exe=абсолютный-путь-к-новому-packaged-EXE
- --web-url=http://127.0.0.1:5173/

Физические результаты не перезаписываются. Если первая попытка не завершилась, исходные скачанные файлы и partial progress сохраняются; следующую проверку проводить в новом output-каталоге или отдельном режиме.

## Выявленный дополнительный дефект и повторная финальная проверка

Первичная матрица14 файлов успешно прошла original native validation. Дополнительные4 партионных файла в exports-party-r2 приняты native loader/Validate/Validate2, но обнаружили расхождение ширины скрытого SN: Glyph измерил raw10нулей (230×47dots), original component — CalcData10нулей+2пробела (254×47dots). Это failing-before evidence, оно не перезаписывается и не объявляется полным совпадением preview.

После исправления этого дефекта и новой сборки root запускается единая матрица в **новый** каталог:

```powershell
& './node_modules/electron/dist/electron.exe' 'research/xml-fix-20261022/export-web-exe.cjs' --mode=both --suite=all --output=research/xml-fix-20261022/exports-final
& 'C:/Windows/SysWOW64/WindowsPowerShell/v1.0/powershell.exe' -NoProfile -ExecutionPolicy Bypass -File 'research/xml-fix-20261022/verify-native.ps1' -InputFile 'research/xml-fix-20261022/exports-final/native-inputs-both.json' -OutputFile 'research/xml-fix-20261022/exports-final/native-validation.json'
node research/xml-fix-20261022/verify-party-properties.cjs research/xml-fix-20261022/exports-final
```
