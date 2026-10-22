# Первая проверка XML-исправлений — 22.10.2026

Это промежуточные результаты **до дополнительного исправления ширины SN**. Финальная матрица18 файлов должна выполняться отдельно в exports-final; эти исходные доказательства не перезаписываются.

## Исходная сборка и реальные сохранения

runtime-fingerprints.json подтвердил26 одинаковых файлов source/dist/HTTP/ASAR и version2.3.1. ASAR SHA-256:

`47650e3bcd17c585757ff25183c7c68ac063aa01b3d044ac5d6b4769da067d64`

export-web-exe.cjs запустил plain HTTP renderer без preload/IPC и настоящий packaged Glyph Studio.exe в отдельном процессе/профиле. В каждом нажата production-кнопка Save диалога; получены физические CIFF, download events, снимки редактора и preSave/postSave параметры.

## Матрица размеров — 14 CIFF

Оба пути дали одинаковые численные параметры:

| Сценарий | ImageWidth×ImageHeight | MaxImageWidth×MaxImageHeight |
|---|---:|---:|
| normal | 1033×1808 | 1600×2400 |
| no-op-import | 777×888 | 1600×2400 |
| rotation90 | 1392×1967 | 1600×2400 |
| hidden-outlier | 1033×1808 | 1600×2400 |
| all-hidden | 0×0 | 1600×2400 |
| last-field-deleted | 0×0 | 1600×2400 |
| anisotropic-yres | 1033×1808 | 1600×2400 |

Физические файлы и expected JSON находятся в exports. Оригинальные Load/Validate/Validate2 приняли **14/14**. Параметры всех38 полей при native загрузке совпали с renderer: Field order, Displayed, Font, X/Y/W/H, Orientation, CalcData. В обычных12 файлах также совпали native text dot-metrics.

В двух anisotropic случаях XML и оригинальные getter сохранили XRes0.12/YRes0.24; actual native request был1200/2400. Native CalculateSize с реальными square-resolution capabilities принтера дал другие метрики:

| Поле | Actual anisotropic renderer | Original component с capabilities принтера |
|---|---:|---:|
| Arial10 | 88×96dots | 86×47dots |
| Times13 | 83×125dots | 84×62dots |
| Courier8 | 102×73dots | 100×37dots |

Эти отклонения явно записаны в native-validation.json; проверка не утверждает эквивалентность полной print-preview conversion для анизотропного документа.

Research-only CDP Browser.close завис после всех14 завершённых download/capture. native-inputs-recovered.json восстановлен из progress, **без повторного сохранения**. manifest-recovery.json подтверждает неизменность всех14 SHA-256 и cleanup только owned research process. Пользовательский installed Glyph и ClariSoft не останавливались.

## Дополнительные Party/Party-box — выявленный дефект

exports-party — неуспешная исследовательская попытка до первой загрузки: snapshot предполагал Konva.Path, а DataMatrix использует Group. В этом каталоге **0 CIFF**.

После исправления только исследовательского snapshot в exports-party-r2 получены4 реальных файла:

- web/EXE Party с GTIN2 без счётчика;
- web/EXE Party-box с GTIN и BOX_COUNTER.

Оригинальный loader и оба validators приняли **4/4**. Native canonical XML и ResolveField подтвердили порядок сегментов, GTIN/GTIN2, max14/6/12/5, UserEnterData, FixedLen, Pitch10/XMag100 и два пробела SN. DataMatrix22×22 имеет132×132dots, Image1300×1300 при Max1600×2400.

Однако strict native metrics сравнение выявило одинаковое отличие во всех4 файлах:

```text
SN raw Default/UserEnterData: 10 нулей
SN CalculatedData:            10 нулей + 2 пробела
Glyph preview:               230×47dots
ClariSoft CalculateSize:      254×47dots
```

Это **реальный failing-before результат**, не ошибочная форма XML и не расхождение размера DataMatrix. Загрузка Font/XYWH совпадает с сохранёнными параметрами, но Glyph измерял raw ввод вместо полной строки с padding. Результат передан root для production-исправления и повторной новой сборки. party-properties-summary.json отдельно подтверждает source/native semantic properties и оставляет allPreviewMetricsExact=false.

Native GUI открытие выполняется root отдельно. PNG в этих каталогах — настоящие web/EXE editor captures, а не скриншоты ClariSoft.
