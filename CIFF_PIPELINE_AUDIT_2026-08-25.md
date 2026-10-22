# Glyph CIFF pipeline audit — Stage 1

Дата: 25.08.2026  
Основание: `00_README.md` + `01_AUDIT_PIPELINE.md`  
Основной oracle: CIFF, созданный Videojet CLARiSOFT и принятый принтером

Уровни уверенности в этом отчёте: `CONFIRMED / HIGH / MEDIUM / LOW / UNKNOWN`.
`CONFIRMED` означает прямое наблюдение в коде или oracle-файле, а не
универсальность правила за пределами исследованного корпуса.

## Scope и методика

- Выполнен read-only аудит исходного pipeline до исправлений: UI, global state,
  load/parse, geometry, DataMatrix, text, serialization, validation, encoding,
  download и tab persistence.
- Проверены repository fixtures и локальный curated corpus CLARiSOFT. Для
  ключевого oracle `Clarisoft_test_1.ciff` подтверждён независимый SHA-256
  `5221DC212883631146E4D26E2BB5AF3D38E440D0EA458C73BF4B18E5175BB63D`.
- Отдельно использован принятый Videojet файл
  `22x22_reference_270days.ciff`; внешний экземпляр совпал с repository fixture.
- В 35 проверенных CIFF-файлах оболочка одинакова: UTF-16LE, BOM `FF FE`,
  declaration `UTF-16`, две XML-строки с CRLF и завершающий CRLF — `CONFIRMED`.
- Правила не выводились из одного шаблона. Противоречащие fixtures оставлены
  как `UNKNOWN`, а не нормализованы под выбранный пример.

## Current Glyph pipeline

```text
React UI
  -> legacy runtime modules loaded in fixed order
  -> global state / fieldByName / history / Konva objects
  -> load: bytes -> encoding -> DOMParser -> editor model
  -> edit: factories + geometry/text/DataMatrix services
  -> save draft: lossless string patch or canonical builder for new structures
  -> compatibility validation
  -> UTF-16LE BOM + exact two-line CRLF envelope
  -> browser Blob/download
  -> committed model/XML + tab/localStorage snapshot
```

Ключевые входы:

- Runtime orchestration: `src/hooks/useCiffEditorRuntime.ts:36-69` и
  `src/domain/ciffEditorModules.ts:22-35`.
- Authoritative state: `public/modules/00-core.js`; отдельного React store нет.
- Load/parse: `public/modules/20-xml-load.js:293-590`.
- Geometry and validation: `public/modules/30-rendering.js:347-469`.
- Editor/factories: `public/modules/40-editor.js:387-1637`.
- Preset path: `public/modules/45-template-preset.js:154-525`.
- Save/validation/encoding: `public/modules/60-history-save.js:318-2189`.
- Tab persistence: `public/modules/70-template-tabs.js:899-1110`.

Save теперь транзакционный: `patchXmlLosslessV2Preview()` восстанавливает live
state, `prepareCiffForSave()` сохраняет draft snapshot, а derived-значения
попадают в live model только через `commitPreparedCiffToState()` после успешной
validation. Ошибка validation не оставляет скрытых изменений без history.

## CIFF-related files

| Файл | Роль |
| --- | --- |
| `public/modules/00-core.js` | units, state, printer capabilities, text/DM domains, shared helpers |
| `public/modules/10-canvas-ui.js` | canvas placement, transformer resize, rotation, workspace |
| `public/modules/20-xml-load.js` | encoding detection, XML parse, model reconstruction, workspace init |
| `public/modules/30-rendering.js` | bounds, constraints, image extent, text preview, DM geometry/BcH |
| `public/modules/40-editor.js` | property editing, rename, field factories, DM profile editing |
| `public/modules/45-template-preset.js` | optional pharma/GS1 recipe and adaptive layout |
| `public/modules/60-history-save.js` | history, lossless patching, new-field builder, validation, UTF-16LE |
| `public/modules/70-template-tabs.js` | tab snapshots, migration and localStorage |
| `src/components/*.tsx` | React controls and dialogs around the legacy runtime |
| `scripts/compare-ciff-structure.cjs` | ordered XML/byte comparator and corpus diagnostics |
| `scripts/generate-glyph-reference-case.cjs` | reproducible production reference generation |
| `tests/helpers/ciff-production-harness.cjs` | production load/save VM harness |
| `tests/fixtures/clarisoft/*` | immutable CLARiSOFT oracle fixtures |

## Parameter classification

| Class | Parameters |
| --- | --- |
| A — user-controlled | target printer/mode, workspace, field name/type/printed, X/Y/W/H, orientation, values, MaxNoOfChars, entry mode, FixedLen presence, masks, dates/counters, Pitch/XMag, QuietMargin, SymbolSize, ModuleSize, DM segments/SrcField |
| B — derived | orientation-aware bounds, used ImageWidth/Height after a real printed-geometry change, DM W/H, effective Auto symbol, inferred ModuleSize, aggregate CalcData, text initial geometry, physical overflow |
| C — technical/service | BOM/declaration/CRLF, Version, ClStVersionInfo, ImageReference/Mapping, MaxImage*, XRes, CLSID, BcH when imported, LoggedField and optional-tag presence, XML order, unknown attrs/children, CDATA representation |

Гибриды: W/H и ModuleSize являются user-controlled при resize/explicit edit и
derived при factory creation; BcH является C для import и только provisional B
для нового/явно изменённого DM.

## Confirmed rules

| Правило | Evidence | Confidence | Реализация |
| --- | --- | --- | --- |
| 100 internal units = 1 mm | Все проверенные geometry values и Glyph conversion | `CONFIRMED` | Сохранено |
| UTF-16LE BOM, declaration UTF-16, две CRLF-строки + final CRLF | 35/35 проверенных файлов | `CONFIRMED` | Regression покрывает bytes/envelope |
| No-op import/save не должен добавлять FixedLen | CLARiSOFT fixed C2/C3: numeric Max без FixedLen | `CONFIRMED` | Исправлено; ключевой oracle теперь byte-identical |
| FixedLen и MaxNoOfChars — независимые XML facts | Static и VarText signatures в corpus | `CONFIRMED` | Импортированное presence сохраняется; UI Max реально сериализуется |
| Imported BcH нельзя нормализовать из W/H/ModuleSize | Oracle с одинаковыми DM settings имеет BcH 2540 и 924 | `CONFIRMED` | Imported BcH сохраняется |
| DM W/H нельзя выводить из округлённого ModuleSize integer | ZDRAVA2: Module42/BcH924/W917; accepted ref: Module58/BcH1276/W1283 | `CONFIRMED` | W/H отделены от BcH |
| Image extent учитывает Orientation | `TEXT_ROTATIONS.ciff`: O90 edge = X+H, O270 edge = Y+W | `CONFIRMED` | Исправлено и покрыто 0/90/180/270 |
| Non-geometry edit сохраняет source Image padding | accepted ref ImageHeight2574 при nominal extent2558 | `CONFIRMED` | Source geometry fingerprint gate |
| Positive MaxImage*/XRes нельзя переписывать по model name | CLARiSOFT same-target values 1500/3000/3200 и 5000/3300 | `CONFIRMED` | Profile только заполняет missing/invalid |
| ImageWidth может быть больше MaxImageWidth | `ONLY_DM` corpus: 2516 > 1500 | `CONFIRMED` | Ошибочная containment validation удалена; hardware проверяется отдельно |
| Explicit Pitch — source-authoritative | Parser различает absent `null` и explicit value | `CONFIRMED` | Height inference только при absent Pitch |
| XML entities в Name должны сравниваться после decode | DOMParser даёт A&B для raw A&amp;B | `CONFIRMED` | XML-aware field index и quote-safe rename |
| `]]>` нельзя помещать внутрь одной CDATA | XML 1.0 syntax | `CONFIRMED` | Safe adjacent CDATA splitting + strict comparator regression |
| Rename SrcField не является structural edit | Меняется только attribute reference | `CONFIRMED` | Non-invasive patch без Data rebuild |
| Произвольные ordered literal/SrcField Objects валидны для generic serializer | Parser/model/serializer поддерживают их; recipe — отдельный UI preset | `CONFIRMED` для Glyph capability | Recipe enforcement удалён из generic validation |

## Probable rules

| Правило | Evidence | Confidence | Текущее решение |
| --- | --- | --- | --- |
| DM W/H использует integer dot count при 12 dots/mm | 5 dots -> 22*5/12*100=917; 7 dots -> 1283 | `HIGH` | Реализовано для explicit supported option |
| FixedLen коррелирует с user-entered VarText + numeric Max | 18 user fields with tag; fixed/static corpus fields without it | `HIGH` | Default factory policy; imported presence остаётся authoritative |
| Known head physical widths 3200/5333/10667 и height7500 | local target fixtures | `HIGH` | Используются только для workspace/hardware/missing metadata |
| DataMatrix CLSID и DataType=5 | Проверенный local DM corpus | `HIGH` | Default для новых DM, import lossless |
| BcH fallback = rows * serialized rounded module integer | Совпадает с 42->924 и 58->1276, но противоречит другим oracle | `LOW` | Только new/explicit fallback; не применяется к import |
| Text formula Glyph корректна для части Pitch10 strings | Oracle Pitch10 examples | `MEDIUM` | Сохранена как factory approximation, не как import normalizer |

## Unknown rules

- Истинная семантика и алгоритм `BcH`: `UNKNOWN`. При одинаковых
  `W=H=1100`, `ModuleSize=50`, `SymbolSize=22X22` наблюдаются `2540`, `924` и
  Glyph fallback `1100`. Нужен controlled A/B export из CLARiSOFT.
- Причина осевой разницы `W=1283`, `H=1284` в accepted 7-dot DM: `UNKNOWN`.
- Точные glyph metrics для Pitch 3/8 и punctuation: `UNKNOWN`. Наблюдаемые
  расхождения: Pitch8 `21` 317 vs Glyph307; `~101` 642 vs626; Pitch3 `.` 33
  vs58.
- Семантика и генерация proprietary `ClStVersionInfo`: `UNKNOWN`; import
  должен оставаться lossless.
- Универсальные правила появления `LoggedField` и прочих optional tags:
  `UNKNOWN`; corpus содержит и присутствие, и отсутствие.
- Полный набор rectangular/large DataMatrix symbols, поддерживаемый конкретным
  firmware/printer: `UNKNOWN`.
- Несколько `SubImage`, связь `CurrentOrientation` с field Orientation и
  printer-specific ordering variants: `UNKNOWN`.

## Duplicated calculations

| Область | Дубли | Риск |
| --- | --- | --- |
| Image/workspace/capabilities | `20-xml-load`, `30-rendering`, `60-history-save`, `70-template-tabs` | `HIGH`; partially reduced by preserving serialized vs known capability roles |
| Bounds | nominal/rendered variants in `30-rendering`, `40-editor`, `10-canvas-ui`, preset collision checks | `HIGH`; image extent now uses orientation-aware nominal bounds, but resize paths remain split |
| Rotation | canvas corners, editor pivot, renderer nominal bounds, save orientation | `HIGH`; oracle extent fixed, transformer axis mapping still separate |
| ModuleSize | import inference, renderer effective value, resize snapping, save spelling | `HIGH`; W/H dot geometry centralized in renderer, import spelling preserved |
| BcH | renderer calculation, editor/preset callers, save fallback | `HIGH`; imported value separated, true creation rule still unknown |
| Text geometry | core approximation, browser/Konva measurement, editor resize, preset layout | `HIGH`; exact general metric remains unknown |
| FixedLen policy | parser, UI model, factory, serializer | Был `CONFIRMED` drift; serializer no longer derives it from Max alone |

## Hardcoded values

| Значение | Где | Confidence / замечание |
| --- | --- | --- |
| `INTERNAL_PER_MM=100`, preview `12 px/mm` | `00-core.js:13-14` | units `CONFIRMED`; px — UI-only |
| Printer heads `3200/5333/10667 x 7500`, XRes0.12 | `00-core.js:287-302` | `HIGH` local, не universal firmware rule |
| Text heights Pitch3=133, Pitch8=325, Pitch10=392 | `00-core.js:20-24` | `HIGH` for observed heights |
| Text width coefficient19.167 and tilde adjustment16 | `00-core.js:25-42` | `LOW/MEDIUM`, partial fit only |
| 60 module options `(dotCount/12).toFixed(2)` | `00-core.js:240` | `HIGH` 12 dots/mm hypothesis; range support `MEDIUM` |
| DM symbol table 14..36 square | `00-core.js:133-233`, React modal duplicate | observed subset only; rectangular UI support incomplete |
| Default DM22X22, module0.50, quiet0 | editor/preset | template defaults, not CIFF semantics |
| DataMatrix CLSID `{7A4AA4CF-...}` and DataType5 | editor/save/preset | `HIGH` local corpus |
| Pharma helpers C1/GTIN/C2/SN/C3/KRIPTO/C4/KRIPTO2 | `00-core.js`, preset/editor | optional recipe only; generic validation no longer enforces it |
| New-field LoggedField always emitted | `60-history-save.js` | universal rule `UNKNOWN`, compatibility risk `MEDIUM` |
| Manual add initial 12x4 mm / Barcode12x12 mm | `40-editor.js:1592-1593` | path divergence, risk `HIGH` |
| Empty template ClSt token/default53.33x75 | core/load/preset | template-specific; proprietary semantics `UNKNOWN` |

## Likely compatibility bugs

### Исправлено в Stage 1

| Parameter / behavior | Reference vs old Glyph | Cause | Confidence | Impact | Status / regression |
| --- | --- | --- | --- | --- | --- |
| FixedLen | CLARiSOFT static numeric Max had no tag; Glyph added it | universal Max=>FixedLen heuristic | `CONFIRMED` | no-op structural mutation | Fixed; exact oracle no-op bytes |
| MaxNoOfChars edit | UI value disappeared on reload | serializer treated value as read-only | `CONFIRMED` | lost user edit | Fixed; upsert/remove test |
| Image rotation extent | CLARiSOFT O90 uses X+H; Glyph used X+W | raw axes | `CONFIRMED` | wrong Image*, false overflow | Fixed; rotation oracle |
| Image padding | unrelated history shrank accepted 2574 to2558 | global usedSizeDirty | `CONFIRMED` | source mutation | Fixed by source geometry diff |
| MaxImage/XRes | valid positive values overwritten by profile | model-name normalization | `CONFIRMED` | rejects/changes valid CLARiSOFT | Fixed; preserve/fill tests |
| DM W/H | Module42 expected917, Glyph924 | rounded ModuleSize reused as geometry | `CONFIRMED`; dots rule `HIGH` | wrong size/placement | Fixed dot geometry |
| Field Name entities/$ | raw matcher failed or replacement expanded `$&` | regex matched encoded text/replacement string | `CONFIRMED` | field rebuild/corruption | Fixed XML-aware ranges/callbacks |
| VarText opaque XML | mode sync rebuilt block on every save | unconditional delete/rebuild | `CONFIRMED` | unknown attrs/children lost | Fixed; opaque regression |
| CDATA terminator | direct interpolation generated malformed XML | no safe wrapper | `CONFIRMED` | unreadable CIFF | Fixed split + parser test |
| SrcField rename | pure rename marked DM structureDirty | coarse dirty flag | `CONFIRMED` | opaque Object XML lost | Fixed non-invasive attr patch |
| Explicit Pitch | Pitch10 could become inferred3/8 | fallback heuristic overrode source | `CONFIRMED` | no-op mutation | Fixed |
| Generic DM | all new DM forced pharma ordered helpers | validator conflated recipe and format | `CONFIRMED` | single-template overfit | Fixed generic literal regression |
| QuietMargin | absent tag edit lost; W/H not synchronized | patch-only + missing geometry call | `CONFIRMED` | UI/model/XML drift | Fixed upsert and geometry sync |
| Save preview | derived state mutated before failed validation | save operated on live model | `CONFIRMED` | untracked changes | Fixed transactional draft/commit |

### Остаётся для следующих этапов / требует oracle

| Parameter / behavior | Evidence | Confidence | Impact | Next step |
| --- | --- | --- | --- | --- |
| True BcH generation | mutually contradictory oracle values | `UNKNOWN` | new/changed DM may differ from CLARiSOFT | controlled CLARiSOFT A/B exports varying one parameter |
| Rotated transformer resize axes | visual scaleX can update raw W at O90/270 | `CONFIRMED` code-path | wrong opposite axis and derived settings | central orientation-aware resize service + UI regression |
| Numeric W/H vs canvas resize | numeric path changes geom only; transformer updates DM/text metrics | `CONFIRMED` | same final W/H serializes differently | one authoritative resize command |
| Optional Pitch/XMag/ModuleSize/SymbolSize insertion | existing serializer patches only present tags | `CONFIRMED` | explicit edit of absent tag may disappear | presence + explicit-dirty tracking |
| DM structural edit opaque retention | `rebuildDataObjectsForDataMatrix()` recreates all Objects | `CONFIRMED` | unknown XML lost on add/remove/reorder | keyed Object diff/patch, preserve retained blocks |
| Manual add text geometry | hardcoded 12x4 path bypasses value formula | `CONFIRMED` | edit-path-dependent W/H | route through type factories; validate against controlled exports |
| Text W/H outside verified subset | corpus mismatch at Pitch3/8 | `CONFIRMED` mismatch, rule `UNKNOWN` | generated text dimensions differ | glyph/pitch A/B fixture matrix |
| LoggedField on every new field | corpus presence is optional | `CONFIRMED` variability | possible structural mismatch | presence policy experiment; keep imports lossless |
| DM symbol domain | UI table square14..36 only | `CONFIRMED` limitation | incomplete authoring | query target firmware/CLARiSOFT support before expansion |
| Multi-SubImage | Glyph edits first SubImage | `CONFIRMED` implementation, semantics `UNKNOWN` | unsupported multi-image files | acquire oracle fixtures before refactor |

## Regression and verification

Добавлены или актуализированы проверки:

- exact byte no-op round-trip `Clarisoft_test_1.ciff`;
- ordered structural comparator and immutable fixture hashes;
- FixedLen/Max independence for static, VarText and imported edits;
- entity-aware names, literal `$&`, single quotes, opaque VarText and `]]>`;
- arbitrary literal DataMatrix validation;
- dot geometry 0.42/0.58, rectangular symbols, BcH import preservation;
- orientation-aware image bounds and accepted source padding preservation;
- known-profile positive values vs hardware capability bounds;
- transactional prepare/commit and failed-save state preservation;
- UTF-16LE BOM/declaration/two-line CRLF envelope;
- existing editor, template, tabs, preset and build regressions.

Ограничение tooling: comparator проверяет CIFF envelope, отслеживаемую XML-
структуру, значения, порядок полей и bytes, но сам по себе не доказывает полную
XML-losslessness. Comments/processing instructions он не моделирует, а порядок
некоторых повторяющихся siblings должен дополнительно подтверждаться exact-byte
round-trip или специализированной проверкой. Поэтому ключевой no-op oracle
закреплён именно byte-identical regression, а не только structural comparison.

Final verification command set:

```powershell
npm test
npm run build
git diff --check
```

Фактический итог финального прогона: `npm test` — `162/162` успешно;
`npm run build` — успешно; `git diff --check` — ошибок diff не обнаружено
(Git вывел только существующие предупреждения о будущей нормализации LF/CRLF).

Главный Stage-1 результат: Glyph больше не изменяет ключевой CLARiSOFT oracle
при no-op save, но это не доказывает универсальную совместимость. Неизвестные
`BcH`, general text metrics и optional-tag policies явно оставлены `UNKNOWN`, а
не подогнаны под один шаблон.
