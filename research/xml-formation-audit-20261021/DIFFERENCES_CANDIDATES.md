# Кандидаты отличий: текущий Glyph 2.3.0 против native ClariSoft

Это рабочий реестр для объединения с native decomp/COM-отчётами, **не** список уже доказанных визуальных дефектов. Glyph-сторона проверена текущим кодом и [свежими пробами](glyph/probe-current-glyph.cjs). Для каждого native утверждения в итоговом отчёте следует предпочесть результаты от21.10.2026; исторический [FIELD_FORMATION_SPEC](../ciff-fields/FIELD_FORMATION_SPEC.md) и [XML_FORMATION_AND_PRINTERS](../ciff-fields/XML_FORMATION_AND_PRINTERS.md) используются как указатели на адреса декомпиляции.

Полный текущий Glyph pipeline, условия writer и источники — [GLYPH_PIPELINE.md](GLYPH_PIPELINE.md). Уровни: **подтверждено** — код/исполненная проба; **кандидат** — native writer condition исторически декомпилирован, но свежая paired semantics ещё нужна; **намеренное** — политика/рецепт Glyph, не ошибка CIFF.

| Область | Текущее поведение Glyph | Native опорное правило / что сравнить | Оценка |
|---|---|---|---|
| Размер листа | Max*→Image*→профиль; сохраняет независимость Image* и Max* | Нативные поля модели и отдельные CalculateSize/UpdateData; writer сам по себе не обязан пересчитывать размеры | Подтверждён Glyph; не называть ошибкой без сценария native UI |
| Пересчёт Image* | Номинальный max(right/bottom) с начальным0, только печатные; 90/270 swap; сохранённый Image* при no-op | Свежие native aggregate-пробы подтверждают тот же max(right/bottom) с начальным0 и сменой W/H; native writer сам не обязан вызвать расчёт | Обычная формула совпадает; различать момент вызова расчёта |
| Нет печатных полей | При recompute возвращает прежний Image*, возможно0 | Свежий native CalculateSize возвращает0×0 | Подтверждённое функциональное отличие после удаления/скрытия последнего печатного поля |
| Область/валидация | Новые/изменённые печатные поля за Max* блокируют save; неизменный импорт допускается; аппаратный предел отдельно | Native может сохранять модель с координатами вне Max*, writer не эквивалентен UI validation | Политика Glyph; не утверждать что native запрещает/разрешает то же |
| AutoSize | Сохраняет исходный узел, игнорирует в preview | Native optional при !=default, отдельное model behavior | Подтверждён пробел поддержки; влияние paired probe |
| Поворот/зеркало/инверсия страницы | CurrentOrientation хранится; ImageRotation/Mirror/Inverse сырые; whole-page grid не преобразуется | Native отдельные SubImage свойства/preview transformations | Подтверждён пробел модели/рендера Glyph |
| YRes | Импорт raw сохраняется, но preview xRes=yRes=XRes | Native YRes самостоятельный, writer опускает если равен XRes | Подтверждён пробел для анизотропного разрешения; native paired geometry необходима |
| SubHeader/@PrinterType | Сырой импорт остаётся после смены Header DesignedFor | Native хранит отдельно, пишет непустой и отличающийся от DesignedFor | Это может быть правильным сохранением native свойства; не считать автоматической ошибкой без процедуры смены принтера |
| ImageDesign/@Version | Новый всегда23; импорт24/другая непустая версия сохраняется | Свежий native default Version23 | Новый default совпадает; raw preservation и проверка только непустоты отличаются от полной native version-policy |
| Header attrs/даты | Новый создаёт минимум DesignedFor+ClSt; native неизвестные attrs/даты импортом сохраняются, не обновляются | Native DesignedWith/Units/OverrideAll/time metadata по своим условиям | Новый недополучает metadata; импорт не теряет; смысл зависит от свойства |
| Required SubHeader | Всегда вставляет все4размера,XRes,CurrentOrientation, требует размеры>0 | Native может опускать default CurrentOrientation; сохранить0 либо default размеры без Glyph validation | Каноничность/более строгая политика; missingallprobe Glyph savefalse |
| CalcData пустого поля | Новый всегда создаёт пустой CDATA; импорт сохраняет исходный пустой или отсутствие | Native68128924 выводит только непустой после фильтрации | Кандидат лишнего пустого узла, обычно канонический diff |
| LoggedField | Новый всегда пустой; импорт не меняет | Native условие !="Not Logged"; null/empty тоже может дать пустой узел | Не объявлять любой пустой LoggedField ошибкой; различить defaultnew vs явноempty native |
| Ln0/Orientation0 | Ln0 явно пишет еслиmodel!=null; новыйOrientation0 опускает, импортexisting0сохраняет | Native common writer опускает значения0 | Канонический diff, не доказательство разницы размеров |
| MaxNoOfChars0 | Новый пишет0, если model не null; импортированный0 сохраняет | Native Object writer опускает0 | Канонический diff; Max и FixedLen независимы у обоих |
| Static1/Parse0 | Writer отражает явную модель; исходные default attributes сохраняются | Native опускает Static1, Parse0 | Канонический diff; фабрики обычно задают только нужные атрибуты |
| Locale/Calendar | Импорт читает значения и сохраняет XML, но новые не сериализует; dateLocale UI отдельно | Native serializer умеет Locale/Calendar, formatter behavior проверяется отдельно | Реальный пробел нового writer; не утверждать единственную причину русских дат без resolve-пробы |
| EqRef/Param/Encryption/Clip/RenderMode/Inverse/Mirror и расширения | Новый генератор ограничен; импорт обычно сохраняет raw, preview не поддерживает полностью | Native полная COM модель и условные ветки writer | Поддержка подмножества; риск проявляется при редактировании/дублировании/перестройке |
| Несколько Object обычного текста | Модель редактирует первый, остальные raw сохраняет | Native resolver/serializer обслуживает полную коллекцию объектов | Поддержка подмножества; простое no-op не теряет XML |
| Изменение структуры DM | Новый список Object с Index, Reference, DataType, Default, SrcField; прочие свойства прежних объектов пропадают | Native сохраняет известные настройки объектов в полной модели | Реальный риск потери при rebuild, а не при patch только значения |
| Новый DM | Всегда BcH, HR/HRFont, QuietMargin0, ModuleSize, SymbolSize | Native узлы по serializer default conditions | Обычно канонические лишние defaults; свежая native матрица важнее исторического образца |
| Font defaults | Новый Pitch fallback10; explicit13/XMag100 выводит; import null оставляет отсутствие | Native defaults Pitch13/XMagYMag100/Arial… writer опускает | Отсутствующий Pitch13 успешно учтён; это не старый font bug |
| Размер helper-шрифтов | Party Pitch10, XMag100 для всех; шрифты исходных CIFF могли отличаться | Native UI recipe/default не равен условию CIFF writer | **Намеренное**, прямо запрошено пользователем |
| UI defaults/recipes | SN Party10нулей,max12; PRODUCT_DATE6; BOX5; заданные порядки | Native blank field/resource defaults и sample Party могут отличаться | **Намеренное**, ограничения рецепта, не generic эвристика по имени |
| Порядок XML | Новое поле FldType→Displayed→CLSID; импорт порядок сохраняет | Native common FldType→CLSID→Displayed | Канонический diff там, где есть оба тега; XML parser обычно порядок принимает |
| ClStVersionInfo | Текущая генерация последняя из того же preparedCalcData; offset/date freeze | Native decomp Save pipeline | Старые RNG/empty token/first supported отличия устранены21.10; не переносить в текущий список |

Свежие воспроизводимые Glyph артефакты:

- [dimension-probes.json](glyph/dimension-probes.json): 12 сценариев, входные и выходные CIFF рядом, validation и точные размеры.
- [new-field-probes.json](glyph/new-field-probes.json): 9 XML-сэмплов настоящих фабрик/нового writer; Date/Time до prepared resolve, не итог финального save.
- [metadata-probes.json](glyph/metadata-probes.json): Version24/Units/DesignedWith/OverrideAll/unknownheader, независимый PrinterType, YRes/AutoSize/Mirror/Inverse/LastUpdated; без изменения и после смены принтера.
- [source-manifest.json](glyph/source-manifest.json): версия2.3.0 и SHA-256 модулей.

Вывод для приоритизации: сначала проверять native paired measurement для YRes и AutoSize/whole-page transformations, затем потерю свойств объектов при изменении структуры DM и locale/date resolve. Отдельно исправлять или осознанно документировать старый Image* после удаления последнего печатного поля. Пустые optional узлы/defaults/порядок XML отделять от изменения семантики. Сохранение исходного raw XML не считать полноценной поддержкой предпросмотра, но и не описывать как потерю данных при каждом save.
