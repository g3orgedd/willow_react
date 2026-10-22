# Восстановление ClStVersionInfo — 05.10.2026

**CONFIRMED:** основной алгоритм `ClStVersionInfo` восстановлен по установленной
`CiffMgr.dll`. Существующее преобразование `public/modules/clst/encryption.js`
совпало с выполнением оригинального машинного кода на трёх прежних контрольных
векторах и 200 дополнительных примерах. Восстановлена также сборка optional-блока
с именем файла. В этой работе production-сохранение Glyph не изменялось.

Источник: `C:\Program Files (x86)\CLARICOM\Data\CiffMgr.dll`, версия `4.5.0.0`,
размер 550400 байт, image base `68100000`.
SHA-256: `F1A3C15E39657C5D8B2A0391660BBA2809702B5B83E368C41584ABDD2955124B`.
Результаты относятся к этой сборке DLL.

## Основной алгоритм

`6811861C` — генератор. `68118879` получает количества DateOffset, SubImage и Field;
Field перечисляются по порядку SubImage, затем по порядку Field внутри него.

```text
counts6 = min(DateOffsetCount,99):02d
        + min(SubImageCount,99):02d
        + min(FieldCount,99):02d

mask = 0
if FieldCount > 0:
    attempts = 1 + randomIndex(min(FieldCount,3))
    repeat attempts times:
        mask |= 1 << randomIndex(min(FieldCount,32))

maskHex = mask:08X
tagData = concatenation of actual TagData of selected Fields, in collection order
tagData = first 20 UTF-16 code units

core = E(maskHex, counts6) + E(tagData, "TagData")
ClStVersionInfo = E(core, "TpyRcNeyeK")
```

Для нуля полей выбор/RNG и блок TagData пропускаются. Конкатенация пустого блока
при этом даёт тот же результат. Для основного пути длина результата:
`72 + 9 × tagData.length`, то есть 72–252 символа.

`randomIndex()` каждый раз заново делает `srand(GetTickCount()); rand() % bound`.
MSVCRT-шаг: `s = tick * 0x343FD + 0x269EC3` по модулю 2³²;
`rand = (s >>> 16) & 0x7FFF`. Повторный выбор одного индекса допустим.
Маска поэтому содержит 1–3 установленных бита, а не обязательно три.
Это другой PRNG, чем тот, который строит сеть внутри `E`.

Значения TagData — результат свойства COM-поля, а не весь XML и не имя Field.
Исследовательский генератор принимает эти значения явно. Полная эквивалентность
вычисления runtime TagData для каждого типа поля, каждой локали и всех
SubImage в редакторе отдельно не доказана.

## Преобразование E

`68117D03` шифрует, `68117C0A` выполняет обратное преобразование.
Конструктор `6810A989` задаёт 25 узлов, 10 входов на узел, общую таблицу
из 1024 Boolean-значений и 16 бит на UTF-16 слово.

Конструктор генератора `6810A9B5` устанавливает seed `0x26E20115`, `TagData`
и финальный ключ `TpyRcNeyeK`, получаемый изменением строки `spaRtNoyAK`.
Все наблюдаемые вызовы генератора передают флаг подключения key inputs `0`.

1. LCG строит таблицу и уникальные индексы десяти входов каждого узла:
   `s = s * 0x41C64E6D + 0x3039` по модулю 2³², `rand=(s>>>16)&0x7FFF`.
2. При флаге 0 индексы выбираются из 0–40: 25 предыдущих выходов и 16 бит plaintext.
3. Выходы первоначально нулевые. Сеть получает по одному нулевому слову
   на UTF-16 символ эффективного ключа, чтобы сформировать начальное состояние.
4. Для очередного слова `cipherWord = previousState XOR plainWord`, после чего
   сеть обновляется именно с plaintext. При расшифровке сначала восстанавливается
   plaintext, затем этим plaintext обновляется сеть.
5. Слово кодируется тремя символами с группами бит 5/6/5:
   `alphabet[word>>>11]`, `alphabet[(word>>>5)&63]`, `alphabet[word&31]`.
   Алфавит: `0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!_`.

**CONFIRMED:** при флаге 0 биты содержимого ключа записываются в буфер,
но не выбираются узлами сети. Значение ключа влияет только его эффективной длиной
и числом прогревочных шагов. Поэтому `E(mask,"000101")` и
`E(mask,"999999")` совпадают. Счётчики передаются алгоритму, но их содержимое
не меняет преобразование при неизменных маске и TagData. Это поведение DLL;
нельзя утверждать, что токен обязательно меняется при любом изменении количества полей.

Native-копирование ограничивает ключ 14 UTF-16 единицами и обрывается на NUL.
В production `CEncryption` нет этих двух ограничений. Фиксированные ключи
ClSt длиной 6, 7 и 10 символов не затрагиваются. Исследовательская обёртка
воспроизводит ограничения и совпадает со всеми 204 сохранёнными native-примерами.

## Optional-метаданные

Флаг объекта `+0xC` по умолчанию 0. Эта ветка не является отдельной веткой
для пустого документа. `681182FA` формирует её так:

```text
name, ext = Windows splitpath(sourcePath), без директории и диска
if ext == ".new": name, ext = splitpath(name)   # сравнение case-sensitive
fileData = first100UTF16(name) + ext
fileBlock = E(fileData, "TagData")
lengthHex = length(fileBlock):08x               # lowercase; длина в символах
inner = E(lengthHex, counts6) + fileBlock + core
ClStVersionInfo = E(inner, "TpyRcNeyeK")
```

Например, `Report.ciff.new` превращается в `Report.ciff`, а
`Report.ciff.NEW` остаётся `Report.ciff.NEW`. Реальное выполнение DLL
подтвердило 31 случай разбора пути, включая Unicode и усечение суррогатной пары.
Переполнение native-буферов имён здесь не воспроизводится.
Условия включения флага при чтении существующего документа описаны в
[optional/findings.md](optional/findings.md).

## Что показал аудит Glyph

- `GLYPH_CONTEXT.md` до этой работы отставал от кода: transform уже был реализован.
- `createClStSelectionMask()` выбирает первое поддерживаемое поле и один бит;
  native выбирает 1–3 случайных индекса. Маска с одним битом возможна и у native,
  но принятие именно этого production-поведения принтером отдельно не доказано.
- `EMPTY_TEMPLATE_CLST_VERSION_INFO` — копия токена непустого
  `tests/fixtures/clarisoft/Clarisoft_test_1.ciff`: маска `00000001`,
  payload `~1010000000000000021`. В источнике 12 полей.
- Native основной путь для нуля полей восстанавливается без константы и
  даёт 72 символа. Исследовательский генератор его реализует.
- Runtime-значения полей вторых и последующих SubImage заменяются заглушками
  в production save adapter. Optional-блок пока не собирается.

Корпус CIFF/XML: 13 файлов, 8 токенов декодированы, 5 совпадений со stored CalcData,
3 расхождения, 5 файлов без токена. Расхождение с сохранённым CalcData само по себе
не доказывает отказ принтера: native runtime date/time/counter может отличаться.
Результаты и источник готовой константы — в `fixture-analysis.json`.

## Воспроизведение

Из корня проекта:

```powershell
node research/clst/reference-generator.cjs research/clst/example-time.json
node scripts/inspect-clst.cjs tests/fixtures/clarisoft/Clarisoft_test_1.ciff
node --test research/clst/reference-generator.test.cjs
node research/clst/native/compare_reference.cjs
node research/clst/optional/check_reference.cjs
python research/clst/native/native_oracle.py
python research/clst/native/compare_oracle.py
python research/clst/native/compose_reference.py
python research/clst/optional/native_splitpath.py
```

`reference-generator.cjs` принимает counts, `fieldValues` в native-порядке,
явную маску либо последовательность `tickCounts`/инъекцию `nextMod`, и optional
`includeFileMetadata`/`sourcePath`. Он не угадывает uptime из даты сохранения.
Для исследования использованы pefile, capstone и Unicorn; зависимости установлены
локально в игнорируемую `research/clst/tools`, Ghidra-проект и копия DLL также
игнорируются. Для повторной установки:

```powershell
python -m pip install --target research/clst/tools pefile capstone unicorn
```

Декомпиляции и адресный дизассемблер сохранены в `decompiled/`;
`ghidra/ExportClst.java` воспроизводит экспорт в имеющемся Ghidra.
Emulator выполняет исходные инструкции DLL, подменяя только CRT/OLE-операции
копирования строк и выделения памяти. Полный COM-генератор и GUI ClariSoft
в эмуляторе не запускались. Генератор сборки проверяется композициями native E.

Итоговые проверки: 204/204 прямых преобразования исследовательской обёртки,
16/16 основных композиций, 8/8 optional-композиций с совпадением промежуточных
блоков, 31/31 разбор имени файла. Три набора Node-тестов дают 41/41 успешных
проверок, включая 33 существующих регрессии ClSt в Glyph.

**UNKNOWN:** принятие новых вариантов CIFF терминалом и физическим Videojet,
различия других сборок ClariSoft/firmware и полная эквивалентность всех источников
runtime TagData. Проверки по DLL и тесты не заменяют физическую проверку.
