# Reverse engineering формирования полей ClariSoft

Результат исследования 17.10.2026. Основной документ:
**[FIELD_FORMATION_SPEC.md](FIELD_FORMATION_SPEC.md)**.

Дополнение с общей последовательностью XML, расширенными таблицами условий
и сравнением моделей: **[XML_FORMATION_AND_PRINTERS.md](XML_FORMATION_AND_PRINTERS.md)**.
В нём 54 новые COM-пробы на реальных профилях DataFlex и разбор всех 417 CIFF
из пользовательской папки. Для сравнения 8/12 dots/mm выполнен публичный native
Resize с оригинальными capabilities. Установлено также условие появления
`SubHeader/@PrinterType` при изменении только `Header/@DesignedFor`.

Восстановлена цепочка от компонентов создания полей до записи CIFF:
базовые COM-модели, Data/Object, вычисление CurrentDataValue/CalculatedData,
ветви текста/Barcode/Graphic, геометрия DataMatrix, условные преобразования под
принтер и место ClSt перед сериализацией. Сохранены декомпиляции C и адресный ASM.

Это исследовательские материалы и отдельные переносимые правила. Production-код
сохранения и интерфейс Glyph этой работой не изменялись.

## Что сохранено

| Материал | Содержимое |
|---|---|
| [FIELD_FORMATION_SPEC.md](FIELD_FORMATION_SPEC.md) | Этапы, адреса, условия записи, типы источников, ограничения подтверждения |
| [SERIALIZATION_MAP.md](SERIALIZATION_MAP.md) | 42 XML writer-а, 311 мест записи, 27 Barcode subtype-ов |
| [serialization-map.json](serialization-map.json) | Машиночитаемые 309 констант тегов, XML write sites, Barcode masks |
| [inventory.json](inventory.json) | Исходные файлы, размеры, image base, SHA-256 |
| `decompiled/<module>/FUN_<address>.c/.asm` | Декомпиляции и исходные инструкции, которые разрешают неоднозначность C |
| `metadata/*.typelib.json` | Встроенные COM-интерфейсы, enum, параметры, 32-bit vtable slots и GUID |
| `metadata/live-vtables.json` | Сопоставление действующих методов COM с адресами функций DLL |
| `metadata/field-type-ids.json` | Наблюдаемые GetFieldTypeID; неподдерживаемые имена сохранены отдельно |
| `oracle-cases.json` | Явные входы 142 native-сценариев модели |
| `oracle/*.ciff`, `oracle/results.json` | 137 CIFF от оригинального writer-а и 5 ожидаемых E_ACCESSDENIED |
| [dm-resize-results.json](dm-resize-results.json) | 6 выполнений оригинального DataMatrix Resize |
| [native-clst-crosscheck.json](native-clst-crosscheck.json) | 4 совпадения полного оригинального COM-генератора с восстановленной сборкой ClSt |
| [XML_FORMATION_AND_PRINTERS.md](XML_FORMATION_AND_PRINTERS.md) | Сводный порядок XML, условия optional-параметров, различия DataFlex и ограничения проверки |
| [native-printer-capabilities.json](native-printer-capabilities.json) | 65 отображаемых имён Videojet, 41 внутренний профиль из XMLFILE/203 установленного драйвера |
| [printer-profile-verification.json](printer-profile-verification.json) | 54 успешных новых COM-пробы, проверка SHA-256 прежних декомпиляций, native DM matrix |
| [template-corpus.json](template-corpus.json) | 417 исходных файлов: 415 разобранных XML, 4 предупреждения кодировки, 2 неразобранных файла |
| [reference-rules.cjs](reference-rules.cjs) | Перенос фильтра CalcData, MSXML newline normalization и DataMatrix Resize |

Декомпилированы необходимые функции `CLARiSOFT.exe`, `CiffMgr.dll`,
`CiffHelper.dll`, семи компонентов полей и обоих `CLCiffConversion_*`.
Для converter DLL экспортирована вся секция .text; для остальных — функции
модели/сериализации, целевые входы и их зависимости. Прочие DLL из CLARICOM
учитываются по фактической роли; наличие установленной DLL не означает, что
в этой работе восстановлен весь её аппаратный протокол или UI.

## Самые существенные выводы

1. XML serializer не вычисляет поля заново. Он пишет подготовленные COM-свойства,
   соблюдая defaults и доступные версии интерфейсов.
2. Семейство Field, строка FldType, CLSID, внутренний DataType и XML DataType
   независимы. Их смешение создаёт неверные вложенные структуры.
3. Data/Object сортируются по Index при добавлении. Повторные Index и FieldName
   заменяют прежние элементы. Field writer перечисляет текущую коллекцию.
4. ClSt берёт **ICiffField.CalculatedData**, поэтому разрешение источников и
   обновление данных должны происходить до его формирования.
5. Счётчик preview может использовать StartValue, а не сохранённый CurrVal.
   Padding динамического текста зависит также от DataIsStatic.
6. BcH — отдельное свойство Barcode.Height. Согласование его с W/H/ModuleSize
   происходит в обработчике типа; writer не исправляет это соотношение.
7. Original DataMatrix Resize квантует module по XRes. Для requested1000,
   SymbolSize22×22, XRes0.12 и без quiet margins получаются module42 и W/H/BcH924.
8. Обычный savetostring не запускает ClSt, а savetostring2 с соответствующим
   параметром и обычный save запускают. Этот порядок проверен по коду и COM.

## Воспроизведение

Запускать из корня workspace. PowerShell должен быть **32-битным**, потому что
установленные компоненты ClariSoft — x86. Все результаты пишутся в research.
Пробам не требуется открывать интерфейс ClariSoft и подключать принтер.

```powershell
python research/ciff-fields/inventory.py
python research/ciff-fields/dump_typelibs.py
python research/ciff-fields/make_oracle_cases.py
& C:\Windows\SysWOW64\WindowsPowerShell\v1.0\powershell.exe -NoProfile -ExecutionPolicy Bypass -File research/ciff-fields/oracle-cases.ps1
& C:\Windows\SysWOW64\WindowsPowerShell\v1.0\powershell.exe -NoProfile -ExecutionPolicy Bypass -File research/ciff-fields/oracle-dm-resize.ps1
node --test research/ciff-fields/reference-rules.test.cjs
node research/ciff-fields/verify-native-clst.cjs
```

Новые printer-пробы:

```powershell
python research/ciff-fields/extract_printer_caps.py
python research/ciff-fields/audit_template_corpus.py
& C:\Windows\SysWOW64\WindowsPowerShell\v1.0\powershell.exe -NoProfile -ExecutionPolicy Bypass -File research/ciff-fields/oracle-printer-profiles.ps1
python research/ciff-fields/verify_printer_profiles.py
```

`CiffPrinterNative.cs` вызывает дополнительные публичные COM-методы.
В printer-пробах text CalculateSize фиксируется отдельно от W/H: размещение
приложением не эмулируется. Новые CIFF диагностические, без ClSt и без проверки
на физическом принтере. В папке `printer-oracle` сохранены входные capabilities
и выходы трёх серий; resource XML можно повторно извлечь указанным скриптом.

Скрипты vtable, helper, converter и type ID запускаются тем же x86 PowerShell:
`probe-vtables.ps1`, `probe-helper.ps1`, `probe-conversions.ps1`, `probe-type-ids.ps1`.
`CiffNative.cs` — типизированные обёртки действующих COM-методов. В отдельной
DM-пробе есть вызов внутренней функции по RVA; перед ним строго проверяется
SHA-256 DLL. Заглушка предоставляет только заданные XRes/YRes, что отмечено в отчёте.

`ghidra/ExportFieldPipeline.java` поддерживает экспорт диапазона адресов,
root functions с зависимостями и всей секции .text. Для root-режима требуются
`metadata/<module>.roots.txt`; сигнатуры основных компонентных методов
применяются из `metadata/<module>.methods.tsv`.
`build_serialization_map.py` восстанавливает индекс из PE и декомпиляций.
`extract_renderer_vtables.py` добавляет к корневым функциям найденные через RTTI
методы полиморфных Barcode helpers.

Python-зависимости (`pefile`, `capstone`, `unicorn`, `comtypes`) размещаются в
игнорируемой `research/clst/tools`. Копии бинарников, проекты Ghidra и логи также
игнорируются; исходные установленные файлы не патчились.

## Что подтверждено и что ещё требует проверки

142 сценария дали ожидаемые результаты: **137 успешных XML и 5 отказов**
при изменении свойств без нужного состояния модели. Все 7 исследовательских
Node-тестов прошли. Проверка полного ClSt — 4/4, native DataMatrix Resize — 6/6.

Декомпиляция не восстанавливает оригинальные имена всех локальных переменных и
структур. Грубые ошибки type propagation в C проверяются по ASM и поведению DLL.
Предупреждения decompiler-а не превращаются в подтверждённую семантику автоматически.
Для двух вспомогательных функций с FPU/SSE-ветвями (`450261D0`, `4542E330`)
Ghidra не выдала C; их ASM сохранён. Основные цитируемые функции формирования
полей и XML writer-ы экспортированы в C и ASM.

Внешние БД, произвольные encryption/checksum COM-компоненты, все шрифты/скрипты,
все профили capabilities и все download-преобразования в динамических пробах
не проверялись. Печатная совместимость требует физического Videojet.
Полный перенос всех native renderer/converter в независимый Glyph — отдельная
работа; этот отчёт не утверждает, что такой перенос уже сделан.
