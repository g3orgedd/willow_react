# Аудит XML Glyph / ClariSoft — 21.10.2026

Основной результат: [CIFF_XML_COMPARISON_2026-10-21.md](C:/Users/GigaGeorge/Desktop/willow-react-vite-test_1.4.0/CIFF_XML_COMPARISON_2026-10-21.md).

Работа выполнена по запросу отчёта **до исправлений**. Production-код и пользовательские CIFF не изменялись. Перечень28 исходных файлов и их SHA-256 до/после: [production-before.json](production-before.json), [production-after.json](production-after.json); AllUnchanged=true. Документация и исследовательские артефакты добавлены отдельно.

## Части исследования

| Материал | Содержание |
|---|---|
| [DIMENSIONS_CLARISOFT.md](dimensions/DIMENSIONS_CLARISOFT.md) | Оригинальные getter/setter, loader/writer, app aggregate, фон/сетка, containment, CLPrintPreview paper extent/Best Fit/CountBlackDots |
| [FIELD_CONDITIONS.md](fields/FIELD_CONDITIONS.md) | Условия Field/Data/Object/Text/Font/VarText/SrcField/SrcData/CounterText/DataMatrix, сопоставление с новым/импортированным Glyph |
| [GLYPH_PIPELINE.md](GLYPH_PIPELINE.md) | Текущий код Glyph2.3.0 с file:line ссылками, импорт/новое поле/structureDirty, geometry и validation |
| [DIFFERENCES_CANDIDATES.md](DIFFERENCES_CANDIDATES.md) | Вспомогательный реестр кандидатов; окончательная оценка находится в основном отчёте |
| [GUI_EVIDENCE_LIMIT.md](GUI_EVIDENCE_LIMIT.md) | Два timeout захвата окна; свежих скриншотов нет; открытый пользовательский документ не менялся |

## Доказательства

- [fields/binary-hashes.json](fields/binary-hashes.json): 15/15 установленных файлов совпадают с предыдущей декомпиляцией.
- [dimensions/installed-binary-hashes.json](dimensions/installed-binary-hashes.json): EXE4.5.1.0, CiffMgr4.5.0.0, CiffHelper4.4.0.7, дополнительно CLPrintPreview.ocx4.4.0.7.
- [dimensions/evidence-manifest.json](dimensions/evidence-manifest.json): 104 свежие функции с C/ASM — EXE77, CiffMgr12, CLPrintPreview15. Текст функций в dimensions/decompiled; логи Ghidra рядом.
- [dimensions/native-dimension-probes.json](dimensions/native-dimension-probes.json): 38 сценариев, 34 успешных, 4 ожидаемых STG_E_OLDFORMAT при отсутствующих Image*. Входы/выходы CIFF рядом.
- [fields/native/results.json](fields/native/results.json): 35 сценариев, 33 CIFF, 2 ожидаемых E_ACCESSDENIED для padding до включения FixedLength. Входные свойства в [fields/cases.json](fields/cases.json).
- [glyph/dimension-probes.json](glyph/dimension-probes.json): 12 production-harness сценариев.
- [glyph/new-field-probes.json](glyph/new-field-probes.json): 9 настоящих фабрик/новых XML-полей; Date/Time показаны до общей save-подготовки.
- [glyph/metadata-probes.json](glyph/metadata-probes.json): 2 production import/save сценария.
- [glyph/source-manifest.json](glyph/source-manifest.json): 17 SHA-256 модулей, использованных при аудите Glyph.

Итого **73 оригинальных COM-сценария** (67 успешных и6 ожидаемых отказов) и **23 сценария Glyph**. Это проверки модели/кода; они не называются GUI screenshot comparison, запуском нового packaged EXE или физической печатью.

## Воспроизведение

Из корня репозитория, с установленными оригинальными32-битными COM-компонентами:

```powershell
& 'C:/Windows/SysWOW64/WindowsPowerShell/v1.0/powershell.exe' -NoProfile -ExecutionPolicy Bypass -File research/xml-formation-audit-20261021/dimensions/probe-dimensions.ps1
& 'C:/Windows/SysWOW64/WindowsPowerShell/v1.0/powershell.exe' -NoProfile -ExecutionPolicy Bypass -File research/xml-formation-audit-20261021/fields/probe-field-conditions.ps1
node research/xml-formation-audit-20261021/glyph/probe-current-glyph.cjs
```

Запуски записывают исследовательские outputs в своих каталогах, не пользовательские Party.ciff/Party1.ciff. Числа в отчёте относятся к сохранённым результатам21.10.2026; дата/время/ClSt при повторном запуске могут отличаться.

Повторный Ghidra export описан в [dimensions/REPRODUCE.ps1](dimensions/REPRODUCE.ps1). Перед его запуском прочитать файл: он использует установленные пути Ghidra/JDK, существующие research-проекты и копию OCX. Не открывать один Ghidra project одновременно двумя процессами.

## Важные уточнения к прежним отчётам

1. Image* — сохранённые свойства модели; CiffMgr save не обязан рассчитывать bbox. Вызов app aggregate — отдельный этап.
2. Editor использует Max*. Print Preview paper extent использует Max* с нулевым fallback на Image* и capabilities; **Best Fit использует Image***.
3. AutoSize1 не запускает пересчёт в native Load/save. Описанный app aggregate не проверяет AutoSize.
4. Native aggregate без печатных полей даёт0×0; Glyph сохраняет прежний Image*. Это отличие не доказывает, что исходный пустой AddSubImage уже обязан иметь0×0.
5. SubCnt включается в writer при Used!=0, не по прямой проверке NumberOfCharacters. NoOfChars записывается внутри уже включённого SubCnt.
6. Для U_HMM одна координатная единица=0,01мм. U_DOTS — отдельный native режим; Glyph не моделирует его.
7. Старые выводы о hardcoded ClSt и неправильном fallback Pitch отсутствующего Font не описывают текущее состояние Glyph2.3.0.

Не восстановлены полностью hardware clipping после всех conversions, все варианты capabilities/календарей/внешних компонентов и физическое принятие сценариев Videojet. Эти границы явно сохранены в основном отчёте.
