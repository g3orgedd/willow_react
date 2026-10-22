# Original ClariSoft native verification — 20 October 2026

Both physical CIFF downloads load successfully through the installed original
`ICiffManager.load(filename, null validator)`. No fields were reconstructed and
neither input file was rewritten. Both files are 9,958 bytes, UTF-16LE with BOM,
with SHA-256 `d6046cd29ccb5200fe80726b4eb22734ef9d236307573018457d30953d0a367e`.

| Check | Web download | Packaged EXE download |
|---|---:|---:|
| Text fields loaded and verified | 10/10 | 10/10 |
| Font metadata, raw CIFF geometry and orientation | 10/10 exact | 10/10 exact |
| Actual Konva.Path cell transform and dimensions | 10/10 exact | 10/10 exact |
| Printer raster equals original captured payload | 9/9 unchanged payloads | 10/10 |
| Time recalculation, separately compared at current payload | 1/1 exact | Not needed |
| Input CIFF SHA-256 unchanged | Yes | Yes |

The EXE input was saved by the actual packaged `Glyph Studio.exe`, through the
real save/download path. Its preview evidence was collected on a read-only
reopen after saving; the physical CIFF was not saved again. The web path used
HTTP font rendering without preload or IPC. Export provenance is in
`expected-web.json`, `expected-exe.json` and `export-progress.json`.

## Method and covered properties

`read-native.ps1` runs in 32-bit Windows PowerShell and calls installed ClariSoft
components. It loads the physical filename, obtains its actual DesignedFor
mapping and the original `Zodiac Continuous` capabilities, then calls original
`UpdateData`, `CalculateSize` and `Draw` for every field. Resolution is 0.12
printer dots per CIFF coordinate unit, or 12 dots/mm.

The snapshot at each of four stages (load, update, size calculation and drawing)
matches captured Glyph metadata for Face, Pitch, Family, PitchResolution, XMag,
YMag, TTSize, TxtDir, CharSpace, Bold, Italic and BoldWeight, plus X/Y/W/H,
ClearStyleFieldType and orientation. Missing source attributes retain their
documented native defaults. COM BoldWeight is an enum (default 1), distinct from
GDI weight 400; the Bold property is checked separately.

The ten fields cover all five text types, seven font faces, Bold, XMag150 and
clockwise rotations 0/90/180/270. Glyph's actual Path self rectangle equals its
native printer cell. After removing the workspace translation, all six actual
Path transform coefficients match native printer coordinates, scale and
clockwise rotation within `1e-6` dot. This checks direction and scale in addition
to the axis-aligned bounding rectangle. Native dot positions use the verified
single-precision ClariSoft rounding rule; raw CIFF X/Y remain unchanged.

| Field | Face / Pitch | Native rotated cell X,Y / W×H, dots |
|---|---|---|
| TNR_Text | Times New Roman / 6 | 15,28 / 164×29 |
| Arial_Bold | Arial / 13, Bold | 45,108 / 363×64 |
| Courier_XMag | Courier New / 9, XMag150 | 13,204 / 315×40 |
| Tahoma_Date | Tahoma / 8 | 24,288 / 140×41 |
| Segoe_Offset | Segoe UI / 7 | 26,373 / 120×41 |
| Narrow_Time | Arial Narrow / 10 | 38,457 / 86×49 |
| OCRB_Counter | OCRB / 11 | 51,542 / 112×41 |
| TNR_Rot90 | Times New Roman / 6, 90° | 456,96 / 29×67 |
| Courier_Rot180 | Courier New / 8, 180° | 216,624 / 140×37 |
| Tahoma_Rot270 | Tahoma / 6, 270° | 480,360 / 30×88 |

`Draw(ignorePosition=1)` returns the original rotated cell bitmap. Each is
compared with the corresponding Glyph native printer PNG rotated clockwise by
the stored orientation. Equality uses the binary ink mask, accounting for white
background versus transparent background. It does not compare vector screen
antialiasing with printer pixels.

## Clock and ink geometry

The web captured Time text was `23:23`; original ClariSoft later calculated
`23:29`. Direct comparison with that earlier clock snapshot has 141 differing
ink pixels. The original expected snapshot and CIFF were kept intact. A
separate production-worker reference for native's current payload `23:29`
matches original Draw with zero differing pixels. The native width/height and
all font/position properties still match the original captured preview. The
EXE captured and native Time payloads were both `23:29`, and directly match.

The reports retain both captured-snapshot and current-payload comparisons, the
timestamps, and both text strings. Regenerated references are clearly named
`glyph-current-payload-Narrow_Time.*`; they do not replace captured preview PNGs.

Cell dimensions, baseline metrics, vector ink bounds and native raster ink
bounds are recorded separately. For example TNR_Text has a 164×29-dot cell,
baseline 23, native raster ink bounds `(0,5,163,18)` and fractional vector ink
bounds about `(0.2031,5.6406,163.5938,17.7032)`. The cell includes whitespace; the
outline uses fractional curves. Ink bounds are not used to rescale or reposition
the cell. Antialiased screen pixels need not equal the monochrome printer raster.

## Evidence and reproduction

Machine-readable results: `native-verification-summary.json`,
`native-web/verification-report.json` and `native-exe/verification-report.json`.
Each original read is retained in `native-*/read-report.json`; original native
Draw PNGs are in those same directories. Reports include SHA-256 and versions
of installed CiffMgr.dll, CiffHelper.dll, CLCSTextBasedField.dll and
capabilitiesManager.dll, plus Glyph worker/source hashes.

Run from the repository root with Node on Windows:

```powershell
node research/fonts/vector-roundtrip-20261020/verify-vector-native.cjs web exe
```

This is native COM verification of the actual files, not a screenshot of the
ClariSoft GUI. Actual GUI opening and visual inspection are recorded separately.
No production code or ClariSoft installation was changed by these checks.
