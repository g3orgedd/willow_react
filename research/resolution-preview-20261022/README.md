# Разрешение и положение текста ClariSoft: независимые native-пробы

Дата: 22.10.2026. Исследование оригинальных компонентов, без изменения установленных DLL/EXE, production Glyph и пользовательских CIFF. GUI в этих пробах не использовался. Создавались отдельные COM-модели в исследовательских 32-битных процессах; изменённые capabilities существовали только в памяти этих процессов.

## Подтверждённый результат

Для исследованного ClariSoft editor разрешение текста берётся из **capabilities выбранного кодера с применёнными настройками формата**, а не непосредственно из `SubHeader/XRes/YRes`. Один лишь сохранённый `YRes=0.24` при профиле DataFlex с реальными capabilities `0.12/0.12` не делает native текст вдвое выше. Использование XML YRes как входа font renderer Glyph поэтому давало другой текст, хотя XML сохранялся правильно.

Это подтверждают независимые части:

* свежая декомпиляция создания `document+0x160` capabilities;
* **24 оригинальных CalculateSize/Draw сценария** с независимым изменением file-resolution и capabilities-resolution;
* **48 оригинальных Draw-проверок положения** — ноль различающихся чёрных/белых пикселей при точной формуле сдвига;
* **36 проверок вращения bitmap** — ноль различающихся пикселей;
* **8 успешных public Layout.Convert сценариев** отдельного `CS Resolution Adjust` этапа.

Индекс численных результатов и SHA-256 всех120 PNG: [native-field-resolutions/summary.json](native-field-resolutions/summary.json). Это изображения оригинального field component, **не скриншоты ClariSoft**. Полный pipeline печатного preview не подменяется одной фазой converter.

## Источник capabilities в EXE

Свежие C/ASM находятся в [native-editor/decompiled/CLARiSOFT.exe](native-editor/decompiled/CLARiSOFT.exe).

| Функция | Что подтверждено |
|---|---|
| `00E310E9 → 00E353EA` | Из capabilities-file `document+0x1E0` получает Coders (`+0x3C`), выбирает по имени кодера (`collection+0x30`) и устанавливает `document+0x160`. |
| `00E28D47 → 00E3532F` | Читает имя формата из `document+0x15C`, вызывает `coder.GetFormatCapabilities` (`+0x4C0`) и заменяет `document+0x160` объединёнными capabilities кодера/формата. |
| `00E2D699` | Передаёт этот capabilities pointer в per-field Draw/cache-путь `00E60EE2`. |
| `00E867D5` | Инспектированный DC mapping читает разрешение из того же capabilities pointer (`+0x2C/+0x34`), не из SubImage. |

В первых двух функциях нет чтения `ICiffSubImage.XResolution/YResolution` с последующей заменой ими capabilities. Сами эти функции и независимые component-пробы устанавливают выбор разрешения; одни только GetDeviceCaps(screen) не означают повторную растеризацию текста с экранным DPI.

Предыдущий подробный cache/bitmap-путь: [CLARISOFT_EDITOR_RENDER.md](../fonts/vector-preview-20261020/CLARISOFT_EDITOR_RENDER.md). `00E867D5/00E2D699` C/ASM также находятся в [предыдущем размерном исследовании](../xml-formation-audit-20261021/dimensions/decompiled/CLARiSOFT.exe).

## Матрица независимых разрешений

Оригинальный кодер — `Zodiac Continuous`, полученный из извлечённого реального [embedded-capabilities.xml](../ciff-fields/printer-oracle/embedded-capabilities.xml). Исходные оси0.12/0.12 соответствуют12dots/mm. Для controlled-случаев setter-ами `ICapabilitiesCoder.XResolution/YResolution` менялись **только** свойства полученного объекта в памяти. Отдельно задавались `ICiffSubImage` XRes/YRes. Оригинальный компонент получал настоящий file и настоящий caps object.

Текст во всех случаях — `TEXT`; `Face/Pitch`: Arial10, Times New Roman13, Courier New8. Значения ниже не нужно смешивать с другими текстовыми строками из предыдущих web/EXE сценариев.

| File X/Y | Caps X/Y | Arial10 bitmap | Times13 bitmap | Courier8 bitmap | Наблюдение |
|---|---|---:|---:|---:|---|
| .12/.12 | .12/.12 | 107×47 | 140×62 | 80×37 | Базовый профиль |
| .12/.24 | .12/.12 | 107×47 | 140×62 | 80×37 | Изменение только fileY ничего не меняет |
| .24/.12 | .12/.12 | 107×47 | 140×62 | 80×37 | Изменение только fileX ничего не меняет |
| .12/.12 | .12/.24 | 217×96 | 280×125 | 164×73 | Растр символов меняется по capsY |
| .12/.24 | .12/.24 | 217×96 | 280×125 | 164×73 | Те же caps дают тот же результат независимо от fileY |
| .12/.12 | .24/.12 | 107×47 | 140×62 | 80×37 | capsX не растягивает сам glyph raster |
| .24/.12 | .24/.12 | 107×47 | 140×62 | 80×37 | FileX снова не влияет |
| .12/.12 | .08/.12 | 107×47 | 140×62 | 80×37 | Bitmap прежний; меняется перевод его ширины в CIFF |

Каждый из24 сценариев вызвал оригинальные `CalculateSize` и `Draw`; размеры совпали между ними. В [results.json](native-field-resolutions/results.json) сохранены прочитанные обратно обе пары разрешений, размеры bitmap, W/H модели и SHA-256 PNG. Пятнадцать сравнений SHA с исходным bitmap дали полное равенство для file-only и capsX-only изменений; Y-double cases дополнительно видны в той же таблице исходных hash.

Важное следствие: в исследованном **native TrueType** пути нет дополнительного умножения ширины bitmap на `capsX/capsY`. Удвоение capsY увеличило и высоту, и ширину glyph raster. Добавление такой коррекции в font builder Glyph не воспроизводит оригинальный компонент. Это не обобщение на ZFBF/UBF/RTBF и другие font-компоненты.

## Точные формулы и порядок affine-преобразований

### Размер шрифта и geometry

[`CLCSTextBasedField!42425C36`](../ciff-fields/decompiled/CLCSTextBasedField.dll/FUN_42425c36.c), ветвь `param_5=0`, читает `caps.YResolution` (`+0x34`):

```text
deviceRes = signedRound_f32(f32(capsY * 10000))
lfHeight  = -trunc(MulDiv(Pitch, deviceRes, 283) / PitchResolution)
```

XMag имеет отдельный native font-width алгоритм; capsX/capsY aspect-ratio множитель к нему не добавляется. Подробности font builder и XMag: [fonts/README.md](../fonts/README.md).

После получения unrotated text-cell bitmap размер поля в U_HMM переводится по соответствующей capabilities-оси:

```text
W = signedRound_f32(f32(float32(bitmapWidth)  / capsX))
H = signedRound_f32(f32(float32(bitmapHeight) / capsY))
```

Примеры Arial10: caps.12/.12 → bitmap107×47, model892×392; caps.12/.24 → bitmap217×96, model1808×400; caps.24/.12 → bitmap107×47, model446×392. Внутренние `f32` операции важны у границ округления.

### Положение

`42458960` читает **caps** X/Y, выполняет `CVTDQ2PS → MULSS` и вызывает `424264FB`. Последний выбирает `+.5f` либо `-.5f`, выполняет `ADDSS → CVTTSS2SI`:

```text
signedRound_f32(v) = trunc(f32(v + (v < 0 ? -.5f : +.5f)))
offsetX = signedRound_f32(f32(float32(X) * capsX))
offsetY = signedRound_f32(f32(float32(Y) * capsY))
```

`Math.round` без поправки отрицательных половин не эквивалентен: при caps.125 координаты X4/Y−4 дают +1/−1dot. Пробы включают отрицательные значения только как контролируемую проверку native математики, не как разрешение нового размещения за печатной областью Glyph.

Проверка: original `Draw(ignorePosition=false)` сравнивался со **всеми пикселями** original `Draw(ignorePosition=true)`, сдвинутого на ожидаемый offset и обрезанного границами возвращённого bitmap. Все48 случаев дали `differentPixels=0`, включая четыре угла, три XY пары, квадратные/анизотропные caps и намеренно несовпадающие file-resolution. Доказательства: [position-results.json](native-field-resolutions/position-results.json), [NativeResolutionDraw.cs](native-field-resolutions/NativeResolutionDraw.cs).

### Вращение

Original Draw сначала поворачивает bitmap в пространстве printer dots, затем размещает его по двум capabilities-осям. 36 сравнений с точным поворотом исходного bitmap дали ноль отличий.

Для непрерывных координат контура `(u,v)` в unrotated dot-cell `(Pw,Ph)`:

```text
0°:   (u',v') = (u, v)
90°:  (u',v') = (Ph-v, u)
180°: (u',v') = (Pw-u, Ph-v)
270°: (u',v') = (v, Pw-u)

internalX = (offsetX + u') / capsX
internalY = (offsetY + v') / capsY
```

Для индексов центров bitmap pixels вместо `Ph-v`/`Pw-u` используются `Ph-1-v`/`Pw-1-u`. Это разные соглашения координат, не добавочный сдвиг самого поля.

Следовательно, при `capsX != capsY` важен порядок **rotation в dots → деление по capabilities-осям**. Поворот уже анизотропно масштабированных координат обычным parent-group rotation даёт другой результат на90°/270°. Native model W/H при этом остаются unrotated: например217×96dot, W/H1808×400, а returned90° bitmap96×217. Это обнаруженное поведение оригинального компонента.

### Экранный mapping и resampling

В инспектированном `EXE!00E867D5`:

```text
windowExtent = (100,100)
viewportAxis = trunc(screenDPIaxis * 100.0 / f32(capResAxis * 2540.0f) + 0.9)
```

Константа здесь **0.9**, не0.5. Она прочитана из оригинального PE. Это конкретный DC-path, не универсальный коэффициент всех zoom/экранных ветвей GUI.

`00E62F49` считает destination bitmap dimensions целочисленно через viewport/window extents с прибавлением половины знаменателя перед `IDIV`. Если обе destination стороны не меньше source bitmap, используется mapped BitBlt; иначе native создаёт промежуточный bitmap и использует `HALFTONE StretchBlt`. Поэтому совпадение printable bitmap/geometry не означает одинаковых сглаженных пикселей vector-screen Glyph и native screen compositor на любом zoom.

Точные извлечённые ASM и значения констант: [asm-manifest.json](native-field-resolutions/asm-manifest.json), [42458960](native-field-resolutions/CLCSTextBasedField.dll-42458960.asm), [424264FB](native-field-resolutions/CLCSTextBasedField.dll-424264fb.asm), [42458843](native-field-resolutions/CLCSTextBasedField.dll-42458843.asm), [00E62F49](native-field-resolutions/CLARiSOFT.exe-00e62f49.asm). Хэши совпадают с ранее исследованными установленными бинарными файлами.

## Print Preview: отдельный Resolution Adjust

Оригинальный `CLCiffConversion_Layout` вызван через public COM `Initialise → Parameter → Convert` с настоящими caps-file/coder pointers, `CapsFormat=Default`, `ConversionRequestSource=Print Preview` и единственной включённой фазой `CS Resolution Adjust=1`. Инициализация реальным data directory обязательна; без неё предварительный эксперимент возвращал E_FAIL и не использовался как результат преобразования.

Успешная матрица: [layout-resolution-results.json](native-field-resolutions/layout-resolution-results.json). Входы — U_HMM, Pitch10, X/Y173/211, W/H800/350, real target.12/.12.

| File X/Y | TTSize | После Resolution Adjust |
|---|---:|---|
| .12/.12 | 0 или1 | Без изменения |
| .12/.24 | 0 или1 | **Без изменения**, даже сохранённый YRes остаётся.24 |
| .24/.12 | 0 или1 | **Без изменения**, даже сохранённый XRes остаётся.24 |
| .24/.24 | 1 | File X/Y становится.12/.12; Pitch10 и X/Y/W/H сохраняются |
| .24/.24 | 0 | File X/Y становится.12/.12; Pitch10→5; X/Y/W/H сохраняются |

Причина подтверждена C/ASM: [`4541770E`](../ciff-fields/decompiled/CLCiffConversion_Layout.dll/FUN_4541770e.c) вычисляет `factorX = targetX/fileX`, `factorY = targetY/fileY`, но выполняет основной блок **только если оба factor отличаются от1.0**. Константа `45447A24=1.0f`; сравнения находятся в ASM454178A1–454178C2. Нельзя исправлять это в отчёте на более ожидаемое условие «хотя бы одна ось отличается».

[`45417A42`](../ciff-fields/decompiled/CLCiffConversion_Layout.dll/FUN_45417a42.c) передаёт ratios текстовой ветви [`4541FB66`](../ciff-fields/decompiled/CLCiffConversion_Layout.dll/FUN_4541fb66.c). В исследованном U_HMM случае geometry-ветвь по Units не выполняется. Pitch масштабируется с truncation только при `FontTTSize==0` (`get+0x124`); TrueType size1 не изменяется. Прямые размеры/рисование по реальным target caps по-прежнему используют target resolution, даже когда один source-resolution mismatch оставлен converter-ом в XML.

Полный Print Preview дополнительно включает другие conversion-фазы, компоненты и CLPrintPreview OCX. Их существование/порядок описаны в [размерном исследовании](../xml-formation-audit-20261021/dimensions/DIMENSIONS_CLARISOFT.md). Успех этих8 отдельных Resolution Adjust сценариев не является утверждением о выполнении всех этих фаз либо визуальном GUI-сравнении.

## Воспроизведение

Из корня репозитория:

```powershell
& 'C:\Windows\SysWOW64\WindowsPowerShell\v1.0\powershell.exe' -NoProfile -ExecutionPolicy Bypass -File research/resolution-preview-20261022/native-field-resolutions/probe-resolutions.ps1
& 'C:\Windows\SysWOW64\WindowsPowerShell\v1.0\powershell.exe' -NoProfile -ExecutionPolicy Bypass -File research/resolution-preview-20261022/native-field-resolutions/probe-position.ps1
& 'C:\Windows\SysWOW64\WindowsPowerShell\v1.0\powershell.exe' -NoProfile -ExecutionPolicy Bypass -File research/resolution-preview-20261022/native-field-resolutions/probe-layout-resolution.ps1
python research/resolution-preview-20261022/native-field-resolutions/extract-rounding-asm.py
```

Относительно целевой функциональности Glyph это исследование подтверждает выбор renderer-resolution, raster/geometry/position/rotation и отдельную native conversion-ветвь. Оно не меняет CIFF metadata, не вводит допуск для выявленного расхождения и не заявляет полного воспроизведения всех proprietary printer pipelines или GUI screenshot.
