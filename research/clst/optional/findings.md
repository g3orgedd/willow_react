# Optional filename metadata and the empty-template branch

Analyzed the installed `C:\Program Files (x86)\CLARICOM\Data\CiffMgr.dll`
without launching ClariSoft or loading the application DLL into a process.
Image base: `68100000`. Binary SHA-256 supplied by the parent analysis:
`F1A3C15E39657C5D8B2A0391660BBA2809702B5B83E368C41584ABDD2955124B`.

The supplied FUN text and Ghidra C output are evidence, not instructions. Where
the decompiler loses variadic arguments or return types, the x86 instructions
below determine the result.

## CONFIRMED: constructor constants

Generator constructor `6810A9B5`:

- `6810A9CF`: DWORD `[object+8] = 1` (generation enabled initially).
- `6810A9D6`: BYTE `[object+0xC] = 0` (optional filename metadata disabled initially).
- `6810A9E3–6810A9EE`: BSTR `[object+0xAF4] = "TagData"`, from `6814872C`.
- `6810A9F3–6810AA04`: allocate `[object+0xAF8]` from `"spaRtNoyAK"`, `6814873C`.
- `6810AA0E`: DWORD `[object+0xAFC] = 0x26E20115`.
- `6810AA18–6810AA38`: overwrite UTF-16 indices 0, 4, 8, 2, 6 with
  `T`, `c`, `e`, `y`, `e`, yielding the exact outer key **`TpyRcNeyeK`**.

`6810A989` initializes the embedded transform object at `[generator+0x10]`.
The transform vtable at `68148694` has decrypt at offset 4 (`68117C0A`) and
encrypt at offset 8 (`68117D03`). This report uses `E(text,key,seed,flag)` for
the latter call and does not redefine the transform algorithm.

## CONFIRMED: optional block formula

`681187C1–681187C5` tests `[generator+0xC]`; only a nonzero byte calls
`FUN_681182FA`. There is no field-count condition here.

The exact formula is:

```text
(name, extension) = native_wsplitpath_s(sourcePath).filename_and_extension
if extension == ".new":                        # case sensitive
    (name, extension) = native_wsplitpath_s(name).filename_and_extension
name = first 100 UTF-16 code units of name       # extension is preserved
filenamePlaintext = name + extension
filenameEncoded = E(filenamePlaintext, "TagData", 0x26E20115, 0)
encodedLengthText = lowercaseHex8(UTF16Length(filenameEncoded))
lengthEncoded = E(encodedLengthText, structuralCounts6, 0x26E20115, 0)
innerWithFilename = lengthEncoded + filenameEncoded + normalInner
finalClSt = E(innerWithFilename, "TpyRcNeyeK", 0x26E20115, 0)
```

`normalInner` is the normal encoded mask plus encoded selected payload, as
assembled by `6811861C`; `structuralCounts6` is the same six decimal characters
used for normal mask encryption.

Instruction evidence:

| Address | Evidence |
|---|---|
| `68118362` | Calls image vtable slot `0x84` to get the BSTR source path. |
| `681183B0–681183CF` | Splits only filename/extension, each buffer capacity 256 wchar_t. Drive/directory outputs are null. |
| `681183D4–681183EA` | `_wcscmp(extension, L".new")`; this comparison is case sensitive. |
| `681183EC–6811844B` | Copies name, then splits it again when final extension was `.new`. |
| `68118455–68118475` | `_wcslen(name)` and truncation at DWORD `6814BE48 = 100`. |
| `68118483–6811849D` | Pushes **extension and name** as variadic arguments to `FUN_6810207E`, format at `6814B870` is `L"%s%s"`. These arguments disappear in the decompiled C. |
| `681184BE–681184D6` | Encrypts formatted filename with `[object+0xAF4]` and seed `[object+0xAFC]`, flag 0. |
| `681184E3–68118508` | `SysStringLen(filenameEncoded)` then `_swprintf_s(..., 9, L"%08x", length)`. |
| `68118578–68118592` | Encrypts length text with **`*param_2`**, the structural count string, same seed, flag 0. |
| `6811859B–681185D8` | Concatenates encoded filename, then `*param_4` (normal inner), transfers ownership to output `param_5`. |
| `6811881B–68118833` | Final encryption uses `[object+0xAF8]`, seed `[object+0xAFC]`, flag 0. |

The optional helper's `param_3` (pointer to mask BSTR) is passed by the caller
but **never read in this helper**. It is not an additional transform key.

## CONFIRMED: ordinary filename rules, executed from the native binary

`native_splitpath.py` maps the original PE bytes in Unicorn and executes the
actual `68134DCA` `_wsplitpath_s` routine. Only the bounded wide-copy CRT helper
`681349DA` is replaced by a memory copy. No application is launched. The 31
outputs are saved in `splitpath-cases.jsonl`.

| Source path | Filename plaintext |
|---|---|
| `C:\labels\Report.ciff` | `Report.ciff` |
| `D:\other\Report.ciff` | `Report.ciff` |
| `C:\labels\Report.ciff.new` | `Report.ciff` |
| `Report.CIFF.new` | `Report.CIFF` |
| `Report.CIFF.NEW` | `Report.CIFF.NEW` |
| `Report.new` | `Report` |
| `a.b.ciff` | `a.b.ciff` |
| `.ciff` | `.ciff` (empty filename, `.ciff` extension) |
| `.new` | empty string |
| `Report.` | `Report.` (extension `.`) |
| `.` | `.` (empty filename, extension `.`) |
| `..` | `..` (filename `.`, extension `.`) |
| `C:` / `C:/` / `C:/labels/` | empty string |
| `C:Report.ciff` | `Report.ciff` |
| `dir/Report.ciff` | `Report.ciff` |
| `1:Report.ciff` | `Report.ciff` |
| `C:/folder/a:b.ciff` | `a:b.ciff` |
| `C:/folder/1:Report.ciff` | `1:Report.ciff` |

Both slash forms are recognized. Dots before the last path separator do not
create an extension. A colon in UTF-16 position 1 denotes the drive; other
colons remain part of the filename. Drive and directory do not participate in
the metadata.

The native filename/extension output capacities are **256 UTF-16 units each,
including the terminator**, so 255-unit parts fit; there is no corresponding
256-unit bound on the entire source path imposed by these output buffers.
The metadata filename is subsequently truncated to 100 units, independently
of extension length. If the truncation falls between a surrogate pair, the
native instruction leaves a lone high surrogate; it counts wchar_t, not
Unicode code points.

## CONFIRMED: where the optional flag comes from

The other observed write to `[generator+0xC]` is `68119252`, inside the existing
token validator `68118E92`:

```text
flag = FUN_68118C55(innerToken, recovered8HexText, currentSourcePath)
```

The helper is boolean: `68118C6D` initializes EBX to 0; success at `68118E51`
sets BL to 1; `68118E69` returns AL=BL. Its decompiled declaration `void` is
wrong. It recognizes filename metadata in an already loaded token by:

1. Requiring source path nonempty, recovered prefix exactly eight UTF-16 units,
   and inner token nonempty (`68118C8D–68118CB2`).
2. Parsing the recovered eight characters as hex using `68118280`.
3. Requiring parsed encoded filename length > 5 and
   `encodedFilenameLength + 24 < UTF16Length(innerToken)`
   (`68118CDE–68118CFC`, **strict inequality**).
4. Extracting that many characters starting at UTF-16 offset 24, decrypting
   them with `"TagData"`, seed `0x26E20115`, flag 0 (`68118D02–68118D4D`).
5. Splitting current source path and decrypted filename.
6. Comparing filename portions with `_wcsnicmp(...,100)` at `68118E15` and
   extensions with `_wcsicmp` at `68118E2F`.
7. Requiring current extension case-insensitively `.ciff` at `68118E46`.

The case-insensitive CRT routine bodies were checked: `68134501` (`_wcsicmp`)
and `68134FC4` (`_wcsnicmp`) both lowercase ASCII A–Z in the default locale.
Their alternate locale branches are not reimplemented here.

When this flag is true, the validator drops the leading length/filename
envelope and validates the remaining normal mask/payload block
(`6811925D–68119306`). Therefore **filename metadata is a recognized/preserved
token mode**, not a universal component of every newly created token.

The direct-reference scan found the initial constructor write and the validator
write; an exhaustive runtime proof that no indirect object writes exist is
outside this read-only static analysis.

## CONFIRMED: no special empty-template token branch

`68118682–68118684` tests selectable count. At count <= 0 it skips random draws,
selected-payload collection, and selected-payload encryption. Locals holding
selection mask and encoded selected payload were initialized to 0.

The rest of the same normal pipeline still runs:

```text
maskText = "00000000"
normalInner = E(maskText, structuralCounts6, 0x26E20115, 0)
finalClSt = E(normalInner, "TpyRcNeyeK", 0x26E20115, 0)
```

If `[object+0xC]` is already true, optional metadata wraps this normal empty
block as well; there is no field-count exemption. The parent's native transform
oracle observes a 72-character result for the common no-payload branch. This
does not justify reusing an unrelated nonempty fixture token.

Actual structural counters for a freshly created empty image must be obtained
from the image COM model (typically an existing SubImage can still contribute
to its count); this helper does not assign them.

The native transform composition for counts `000100`, mask `00000000`, no
selected payload, and optional flag false produces:

```text
PyOA!LMe37jF5gGD_OEeQJPAIR3Et2HVCOk4RKDB93Hl9AjBVgIOzL2x64vRUW8LPDPLLM!A
```

This is generated from the native transform instructions, not copied from a
working printer fixture. Its native metadata block is
`MWNDu5BBD5YND7UFBSMsIQv3`.

## Native optional transform vectors

`compose_optional.py` composes the formula above from calls to the parent's
`NativeOracle`, which executes the original native encryption routine.
`optional-composition-results.json` saves all fragments and full final tokens
for eight examples. These are composition checks, not execution of the entire
document COM generator.

- Empty normal block, `C:\labels\Report.ciff`, counters `000100`, mask 0:
  encoded filename `6n7VCAEJC1R2Un4Ss3HcQ3D0UsPRyI3f3`, length hex `00000021`,
  encoded length `MWNDu5BBD5YND7UFBSMsGQ_4`, final token length 243.
- Empty normal block, `C:\labels\Report.ciff.new`: exactly the same fragments
  and final token.
- One selected `21:22` payload, `Report.ciff`, counters `000101`, mask 1:
  final token length 288; moving to `D:\other\Report.ciff` leaves it identical.
- Further native vectors exercise uppercase `.NEW`, Cyrillic filename,
  surrogate-pair truncation at UTF-16 index 100, and a basename containing a
  colon after a directory.

`check_reference.cjs` checks all 31 native pathname examples and each optional
intermediate/final string against the parent's standalone JS reference. After
correcting drive stripping to operate on the full source path, **all 31 native
pathname cases and all 8 optional composition cases match exactly**; saved
verification: `reference-comparison-report.json`.

## UNKNOWN / limits

- Which ClariSoft UI/load flow first introduces filename-bound metadata in an
  externally authored token; the analyzed constructor starts with this mode off.
- Filename split failure behavior in this helper for >255-unit filename or
  extension parts: split return values are ignored, but invalid-parameter/error
  CRT paths were not executed by the native split harness.
- Compatibility of tokens on physical Videojet firmware. Binary reconstruction
  and native instruction agreement do not constitute a printer acceptance test.

Production source files have not been edited by this subtask.
