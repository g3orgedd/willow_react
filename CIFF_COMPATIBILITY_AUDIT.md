# Аудит совместимости CIFF с ClariSoft

> **Статус: заменён актуальным Stage-1 аудитом от 25.08.2026.** Этот файл
> отражает промежуточную реализацию и содержит опровергнутые позднейшим
> corpus-анализом выводы, в частности universal `FixedLen` и установленную
> формулу `BcH`. Актуальные confidence-уровни, pipeline map, исправления и
> оставшиеся риски находятся в `CIFF_PIPELINE_AUDIT_2026-08-25.md`.

Дата аудита: 20.08.2026  
Основной oracle: `tests/fixtures/clarisoft/Clarisoft_test_1.ciff`

Актуализация логики `BcH`: 25.08.2026. Исходные значения fixtures сохранены как
исторические наблюдения. Раздел 7 фиксирует разделение imported `BcH` и формулы
инициализации нового DataMatrix.

## Методика

До изменения production-кода оба исходных файла были скопированы как
неизменяемые fixtures и сравнены новым ordered structural comparator:

```powershell
npm.cmd run ciff:compare -- `
  tests/fixtures/clarisoft/Clarisoft_test_1.ciff `
  tests/fixtures/clarisoft/Glyph_test_1.ciff
```

Сравнение учитывает байтовую оболочку, XML declaration, порядок узлов,
атрибуты, значения, ссылки и точные Unicode code points имён полей.

Дополнительный corpus-аудит охватил 262 локальных CIFF-пути, 218 уникальных
parseable документов и отдельную curated-группу из 33 ClariSoft-файлов. На
момент первичного аудита он не позволил превратить значение одного oracle в
неподтверждённое глобальное правило — в частности для BcH,
ClStVersionInfo, optional tags, порядка полей и literal DataMatrix Objects без
SrcField. Повторная проверка показала, что формула подходит для создания и
явного редактирования, но не является правилом нормализации импортированных
значений; итоговая модель описана в разделе 7.

Контрольные SHA-256:

- ClariSoft: `5221DC212883631146E4D26E2BB5AF3D38E440D0EA458C73BF4B18E5175BB63D`;
- исходный Glyph: `112420E4053C789F591EFD3AD44BAB9AC7EB76F1E477E14DF4AB5BDA5E1FDC52`.

Исходный diff содержал 67 различий:

| Категория | Количество |
| --- | ---: |
| different value | 44 |
| extra | 15 |
| different attribute | 3 |
| different order | 2 |
| different Unicode spelling | 2 |
| different reference | 1 |
| missing | 0 |

После исправлений тот же сценарий автоматически создаётся реальным production
pipeline командой:

```powershell
npm.cmd run ciff:reference
```

Результаты сохраняются в `tests/output/Glyph_test_1.generated.ciff` и
`tests/output/Glyph_test_1.generated.diff.txt`. Итоговый diff содержит 27
различий категории `value` и не содержит `extra`, `missing`, `attribute`,
`order`, `unicode` или `reference`. Оставшиеся значения — SHA/длина файла,
неизвестный proprietary `ClStVersionInfo` и X/Y автоматической раскладки.
Структурные сигнатуры, W/H, имена, ссылки и служебные значения совпадают.
Сгенерированный файл имеет 12 742 байта и SHA-256
`40DC857636E9BAF1D6B3598E07F4523351C498B525CFC823493DBB34BEDD9441`.

## Подтверждённые структурные сигнатуры

Порядок непосредственных детей нового Barcode:

```text
FldType, [Displayed], CLSID, X, Y, W, H, Ln, [Orientation],
CalcData, LoggedField, Data, Barcode
```

Порядок непосредственных детей текстовых, Date, Time и Counter полей:

```text
FldType, [Displayed], X, Y, W, H, Ln, [Orientation],
CalcData, LoggedField, Data, Text
```

Подтверждённые вложенные варианты:

| Тип | Data/Object |
| --- | --- |
| FixedText fixed | `DataType, [MaxNoOfChars], Default, [FixedLen]` |
| FixedText user-entered | `Object Static="0"`; `DataType, [MaxNoOfChars], Default, [FixedLen], VarText` |
| DateText | `Object Static="0" Parse="1"`; `DataType, Default` |
| OffsetDateText | DateText + `OffsetDate SrcOffset="…"` |
| TimeText | `Object Static="0" Parse="1"`; `DataType, Default` |
| CounterText | `DataType, Default, CounterText/SubCnt` |
| Barcode | ordered `Object`; первый без `Index`, остальные `Index="1..N"`; `DataType, Default, [SrcField]` |

Квадратные скобки обозначают действительно optional CIFF-узлы. Для
импортированного файла их наличие и неизвестные расширения сохраняются, а не
нормализуются по шаблону.

## Найденные различия и изменения

### 1. Порядок Barcode — FIXED

- ClariSoft: `CLSID` сразу после `FldType`.
- Glyph до: общий serializer помещал `CLSID` после геометрии и `CalcData`.
- Причина: Barcode собирался из text-oriented общего префикса.
- Исправление: отдельная ветка Barcode в `buildFieldXmlOneLine()`.
- После: точная ordered signature ClariSoft.
- Regression: `new Barcode serializer emits the exact Clarisoft direct-child order`.

### 2. Пустой DataMatrix CalcData — FIXED

- ClariSoft: агрегат ordered segment values.
- Glyph до: новый DM мог иметь пустой `CalcData` при заполненных Objects.
- Причина: derived value создавался и редактировался независимо от сегментов.
- Исправление: единые `buildDataMatrixCalcData()`,
  `synchronizeDataMatrixDerivedState()` и save-time synchronization.
- После: `~10100000000000000210000000000000~d029930000` для oracle-сценария.
- Regression: создание, изменение helper, синхронизация нескольких DM и
  контрольная production-генерация.

### 3. SrcField / Default / CalcData — FIXED

- ClariSoft: `Object/Default` равен актуальному значению source field.
- Glyph до: C3 source содержал `~d02993`, а DM Object — `~d02991`.
- Причина: профиль копировал segments до изменения helper и не пересчитывал
  зависимые значения во всех edit-path.
- Исправление: синхронизация вызывается после value/mode/rename/delete,
  segment edit/reorder и перед save; добавлен независимый validator.
- Профили short/long используют несовместимые значения общего helper `C3`.
  Поэтому их одновременное создание теперь атомарно отклоняется до мутации
  общих helpers; очистка long-only полей учитывает ссылки других DataMatrix.
- Regression: stale Default/CalcData rejected; unknown imported Object children
  сохраняются при value-only patch; mixed `22X22 + 36X36` не повреждает state.

### 4. Unicode helper names — FIXED

- ClariSoft: `С1` = U+0421/U+0031, `С2` = U+0421/U+0032,
  `C3` = U+0043/U+0033.
- Glyph до: `С3` начинался с кириллической U+0421.
- Причина: визуально похожие литералы были размножены в profiles/catalog/UI.
- Исправление: единые code-point-safe constants и Latin `C3` во всех новых
  путях. Старое имя не меняется при load; explicit profile application выполняет
  согласованную миграцию имени и SrcField.
- Regression: code points и controlled legacy migration.

### 5. Helper Object / MaxNoOfChars — FIXED

- Актуальные сериализуемые лимиты служебных тегов: `C1=4`, `GTIN=14`,
  `C2=2`, `SN=6/13` по выбранному варианту, `C3=7`, `KRIPTO=4`, `C4=7`,
  `KRIPTO2=44`.
- Glyph до: лимит автоматически равнялся длине значения либо ошибочно
  отделял `C1` editor limit от сериализуемого значения.
- Исправление: `DM_HELPER_SPECS` хранит точные `maxChars` для `C1`–`C4`, а
  предсохранительная проверка сверяет XML с теми же значениями.
- Если `MaxNoOfChars` числовой, Glyph создаёт `FixedLen` после `Default` и
  перед `VarText`; это применяется к новым и lossless-обновляемым полям.
- Regression: exact value/presence каждого helper.

### 6. Неявный XMag=100 — FIXED

- ClariSoft oracle: у стандартных новых полей присутствует только `Pitch`.
- Glyph до: effective editor default 100 сериализовался как явный XMag.
- Причина: UI default ошибочно считался присутствующим XML state.
- Исправление: новые модели хранят `xMag:null`; renderer использует effective
  100, serializer не создаёт тег.
- Regression: no unwanted XMag для всех canonical helpers и reference scenario.

### 7. BcH — FIXED

- Исходный ClariSoft oracle содержит `W=1100`, `H=1100`, `ModuleSize=50`,
  `BcH=2540`. Это самостоятельное импортированное значение, а не stale-высота:
  no-op save обязан сохранить `2540`.
- `field.geom.h` и `field.barcode.bcH` независимы. Универсальная geometry sync
  меняет только `W/H`; render, move, текстовые правки и сохранение не выводят
  новый `BcH` из геометрии.
- Для нового DataMatrix и явного изменения `SymbolSize`, `ModuleSize` или resize
  действует формула `BcH = symbolRows * moduleSizeMm * 100`. Множитель `100`
  переводит хранимые в модели миллиметры в CIFF-единицы; `QuietMargin` не входит
  в формулу.
- Serializer сначала использует `field.barcode.bcH`. Формула служит fallback
  только при `bcH == null`; lossless save сохраняет исходное написание
  `BcH`, `ModuleSize` и `SymbolSize`, пока модельные параметры не изменены.
- Проверенные примеры: `22X22 / 0,33 мм → 726`, `22X22 / 0,42 мм → 924`,
  `22X22 / 0,58 мм → 1276`, `24X24 / 0,50 мм → 1200`,
  `26X26 / 0,33 мм → 858`, `12X26 / 0,40 мм → 480`.

Ниже сохранены исторические наблюдения доступного corpus (205 Barcode
instances). Они описывают исходные файлы, но не задают актуальную сериализацию:

| SymbolSize | Наблюдаемые BcH |
| --- | --- |
| 20X20 | 1000 |
| 22X22 | 550, 726, 858, 924, 1100, 1200, 1276, 1340, 1392, 1474, 2020, 2200, 2540 |
| 24X24 | 1008 |
| 36X36 | 1188, 1200, 1276 |

На момент первичного аудита локальных ClariSoft fixtures для 14X14, 16X16,
18X18, 26X26 и 32X32 не было. Для явного `rowsXcols` расчёт разбирает число
строк из `SymbolSize`; для `Auto` использует фактически выбранный символ.

### 8. Имена новых Field — FIXED

- ClariSoft: общий namespace `Field00`, `Field01`, …
- Glyph до: отдельный namespace `FieldDM00`.
- Исправление: общий allocator `getNextClarisoftFieldName()` для ручного и
  preset-создания. Старые `FieldDM*` по-прежнему читаются и lossless-сохраняются.
- Regression: gap allocation и production reference `Field00`.

### 9. Field order — FIXED для проверенного preset

- ClariSoft oracle: Barcode → PRODUCT_DATE → EXPIRATION_DATE → PARTY → TEAM →
  R_NUM → helper fields.
- Glyph до: helpers → Barcode → дополнительные поля, с другим порядком
  application fields.
- Исправление: specific preset recipe создаёт oracle order; ручные и
  импортированные шаблоны не сортируются глобально.
- Corpus показал, что произвольные ClariSoft-шаблоны сохраняют фактический
  creation order, поэтому глобальная сортировка была бы регрессией.

### 10. Геометрия и Pitch helper fields — FIXED

- Стандартные новые helpers используют Pitch 10 и размеры модели, рассчитанные
  для фактического значения; layout больше не заменяет W печатного текста общей
  шириной колонки.
- После контрольной генерации W/H всех полей совпадают с oracle.
- Оставшиеся X/Y отражают другую автоматическую раскладку и не меняют структуру
  или связи CIFF — статус NOT A BUG.
- Размерная модель разделяет три понятия: `ImageWidth/ImageHeight` — фактический
  используемый печатаемый extent, `MaxImageWidth/MaxImageHeight` — возможности
  выбранной печатающей головки, `workspaceWidth/workspaceHeight` — видимая
  область редактора. Для oracle-сценария generated CIFF снова имеет точные
  `Image=3917×2892`, `MaxImage=5333×7500` и `XRes=0.120000`.
- В самом ClariSoft oracle hidden helpers имеют `X=5500` при
  `MaxImageWidth=5333`. Поэтому hardware bounds validation намеренно проверяет
  печатаемые объекты и не отклоняет служебную editing-column за границей. Это
  также сохраняет ранее заданный UX Glyph: непечатаемые поля расположены вне
  области принтера вертикальным доступным для редактирования списком.

### 11. Lossless imported DataMatrix — FIXED

- Glyph до: `<Data>` импортированного Barcode пересобирался при любом save и
  удалял unknown Object attributes/children.
- Исправление: value-only изменения patch-ятся внутри существующих Objects;
  canonical rebuild выполняется только при `structureDirty=true`.
- Старые persisted/undo snapshots без `structureDirty` сравниваются с ordered
  Objects исходного XML при восстановлении: add/remove/reorder/SrcField drift
  включает rebuild, а неизменённая импортированная структура остаётся lossless.
- При v1/v2→v3 migration тот же schema-normalization применяется к current,
  Undo/Redo и `savedFingerprint`, поэтому чистая вкладка не становится dirty
  только из-за появления `sourceName/structureDirty`.
- Legacy-перенос размера из старых `MaxImage*` выполняется только для schema v1:
  schema v2 уже разделяет `Image*` и аппаратные `MaxImage*`, поэтому её размеры
  сохраняются без повторной интерпретации.
- Regression: сохранение unknown attrs/children/order, explicit structure
  rebuild, legacy snapshot inference и сохранение явного
  `<Orientation>0</Orientation>`.

### 12. Lossless DateOffset — FIXED

- Glyph до: исправление одного invalid/dirty offset удаляло все исходные
  `<DateOffset>` и собирало их заново, из-за чего могли теряться proprietary
  атрибуты, неизвестные дочерние узлы и их порядок даже у соседних offsets.
- Причина: один общий `dateOffsetsDirty` включал полную пересборку Header-блоков.
- Исправление: импортированные offsets хранят стабильный `sourceName`;
  существующие offsets сопоставляются очередью по исходному имени;
  известные `DefaultOffset`/`CurrentOffset` patch-ятся на месте, а остальной XML
  сохраняется. Rename точечно меняет атрибут `Name` и после успешного save
  обновляет identity. Удалённые записи удаляются, новые добавляются канонически.
  Invalid `CurrentOffset` исправляется с единым frozen clock.
- Regression: byte-identical неизменённый offset, сохранение opaque
  attrs/children/order, lossless rename, ремонт invalid Current, delete и
  canonical append.

### 13. Parse у Date/Time — NOT A BUG, подтверждено

- ClariSoft fixtures `22x22_reference_270days`, `ONLY_DATE_FORMATS` и
  `ONLY_TIME_FORMATS` используют `Object Static="0" Parse="1"`.
- Glyph сохраняет этот атрибут для новых DateText, OffsetDateText и TimeText;
  FixedText и CounterText не получают его автоматически.
- Regression: signatures FixedText/Date/OffsetDate/Time/Counter проверяются
  отдельно вместе с optional tags.

### 14. Structural pre-save validation — FIXED

Проверяются XML envelope/structure, обязательные Header/SubImage/SubHeader,
ImageMapping, DateOffset, SrcField, Default, aggregate CalcData, CLSID, BcH и
строгая canonical structure новых Glyph-полей. Неизвестные расширения
импортированных полей разрешены.

### 15. ClStVersionInfo — UNRESOLVED proprietary metadata

- Значение primary oracle имеет длину 252 и отличается от verified empty-template
  значения длиной 171.
- В corpus разные blobs встречаются у одного принтера и режима, поэтому mapping
  `printer + mode` не подтверждён.
- Импортированный blob никогда не пересобирается и сохраняется byte-for-byte.
- Для нового документа используется только значение, подтверждённое набором
  пустых ClariSoft fixtures; оно явно помечено в коде как fallback, а не как
  вычисляемый ID.

## Сводная таблица

| Проверка | ClariSoft | Glyph до | Glyph после | Статус |
| --- | --- | --- | --- | --- |
| Encoding | UTF-16LE | UTF-16LE | UTF-16LE | NOT A BUG |
| BOM | FF FE | FF FE | FF FE | NOT A BUG |
| CRLF | 2, final CRLF | 2 | 2, final CRLF | NOT A BUG |
| ImageDesign | Version 23, xml:space default | совпадал | совпадает | NOT A BUG |
| Header order/attributes | DesignedFor + ClSt | совпадал структурно | preserved/upsert | NOT A BUG |
| DesignedFor | DataFlex 6330(53mm) - Continuous | совпадал | совпадает | NOT A BUG |
| ClStVersionInfo | opaque 252-char blob | empty blob | imports preserved; new verified fallback | UNRESOLVED |
| LastDownloaded | отсутствует в primary pair | отсутствует | сохраняется lossless, если присутствует | NOT A BUG |
| DateOffset | отсутствует в primary pair; corpus содержит расширения | полная пересборка при dirty | non-invasive patch/rename, valid Current | FIXED |
| DefaultOffset | absent in primary pair | n/a | canonical new, non-invasive imported | FIXED |
| CurrentOffset | absent in primary pair | n/a | valid calendar date, frozen clock | FIXED |
| SubImage structure | ordered SubHeader + Fields | совпадала | совпадает | NOT A BUG |
| ImageReference | 1 | 1 | 1 / upsert if missing | NOT A BUG |
| SubHeader order | Format names + six ordered values | совпадал | preserved/upsert | NOT A BUG |
| FormatName | Default | Default | Default | NOT A BUG |
| PrinterFormatName | Default | Default | Default | NOT A BUG |
| ImageWidth | 3917 | 3975 | 3917 | FIXED |
| ImageHeight | 2892 | 2880 | 2892 | FIXED |
| MaxImageWidth | 5333 | 5333 | 5333 | NOT A BUG |
| MaxImageHeight | 7500 | 7500 | 7500 | NOT A BUG |
| XRes | 0.120000 | 0.120000 | 0.120000 | NOT A BUG |
| CurrentOrientation | 0 | 0 | 0 | NOT A BUG |
| Printable bounds | внутри Image extent | внутри Image extent | валидируются по rendered bounds | NOT A BUG |
| Hidden helper bounds | editing-column, X=5500 > Max=5333 | отдельная колонка | отдельная вертикальная колонка, не печатается | NOT A BUG |
| Field order | DM → app → helpers | helpers → DM → app | DM → app → helpers | FIXED |
| Field names | Field00 | FieldDM00 | Field00 | FIXED |
| Unicode names | С1, С2, Latin C3 | Cyrillic С3 | exact code points | FIXED |
| Barcode child order | CLSID second | CLSID late | exact | FIXED |
| CLSID | present | present, wrong position | present, correct position | FIXED |
| CalcData | ordered aggregate | empty | synchronized aggregate | FIXED |
| Data/Object | ordered Objects | rebuild/stale values | canonical new, non-invasive imported | FIXED |
| SrcField | exact existing target | Cyrillic alias/stale | exact target | FIXED |
| Default | equals source value | C3 mismatch | synchronized | FIXED |
| BcH | source fixture: 2540 | tied to H; затем принудительно recalculated | imported сохраняется; новый/явно изменённый вычисляется по `rows * ModuleSize` | FIXED |
| QuietMargin | 0 | 0 | 0 | NOT A BUG |
| ModuleSize | 50 | 50 | 50 | NOT A BUG |
| SymbolSize | 22X22 | 22X22 | 22X22 | NOT A BUG |
| MaxNoOfChars | helper-specific | value.length | helper-specific | FIXED |
| FixedLen | зависит от шаблона | отсутствовал в части сценариев | обязателен при числовом MaxNoOfChars | FIXED |
| Static | type-specific | matched oracle scenario | type-specific | NOT A BUG |
| Parse | `1` у Date/OffsetDate/Time | `1` | type-specific; imported value preserved | NOT A BUG |
| VarText | user-entered only | matched oracle scenario | exact presence | NOT A BUG |
| UserEnterData | user-entered value | matched oracle scenario | synchronized | NOT A BUG |
| Pitch | 10 in oracle helpers | 8 | 10 | FIXED |
| XMag | absent in oracle | implicit 100 serialized | absent unless explicit | FIXED |
| LoggedField | present | present | present | NOT A BUG |
| GenericSettings | ImageMapping | present | preserved/upsert | NOT A BUG |
| ImageMapping | active SubImage ref | primary совпадал; multi-map имел риск | exact Map or append | FIXED |

## Автоматизированные проверки

- immutable SHA и byte envelope обоих исходных fixtures;
- deterministic ordered structural comparator и все семь diff-категорий;
- production preset против ClariSoft oracle с allowlist только для значений
  геометрии/BcH/ClSt/hash;
- exact Barcode order, Unicode code points, FieldNN naming;
- CalcData/source/default synchronization после edit;
- helper Max/XMag structure;
- формула `BcH` для квадратных/прямоугольных символов, режим `Auto`,
  исключение `QuietMargin`, resize, missing fallback и imported round-trip;
- сохранение imported `BcH` при render/move/text/save и через Undo/Redo;
- imported non-invasive DataMatrix patch и structural rebuild;
- legacy persisted/undo DataMatrix `structureDirty` inference;
- защита от общей мутации helpers у mixed short/long DataMatrix;
- Orientation=0 preservation;
- save compatibility, lossless DateOffset/LastDownloaded/metadata,
  UTF-16LE/BOM/CRLF;
- полный application regression suite и production build.

## Карта изменённого кода

| Файл | Основные функции / ответственность |
| --- | --- |
| `public/modules/00-core.js` | canonical DM names/specs, CalcData/source synchronization, derived-state validation, FieldNN allocator |
| `public/modules/05-i18n.js` | локализованное уведомление о конфликте short/long helper-композиций |
| `public/modules/20-xml-load.js` | разбор импортированного BcH, сохранение optional presence и `structureDirty=false` для импортированного DM |
| `public/modules/30-rendering.js` | централизованный расчёт BcH, независимая geometry sync и resize metrics |
| `public/modules/40-editor.js` | canonical factories, helper/value/profile edit paths, controlled legacy C3 migration |
| `public/modules/45-template-preset.js` | oracle field order, shared helpers/DM rules, canonical W/H и рассчитанный BcH |
| `public/modules/60-history-save.js` | authoritative model BcH, formula fallback, lossless imported patches, structural validator, UTF-16LE save pipeline |
| `src/components/TextFieldModal.tsx` | точные preset names/default values без кириллического C3 |
| `scripts/compare-ciff-structure.cjs` | byte + ordered recursive comparator и structural signatures |
| `scripts/generate-glyph-reference-case.cjs` | deterministic production regeneration контрольного сценария |
| `tests/ciff-*.test.cjs` | immutable fixtures, canonical generation, real parse/save/edit/reload round-trip |
