# ClariSoft fonts and preview oracle — 2026-10-20

This investigation uses the installed `CLCSTextBasedField.dll` (SHA-256
`2b9cedaa8a9bdc5ecb92f9dc43855650b0698b6f0ff0190237e6c5889232409b`),
the existing COM metadata/decompilation in `research/ciff-fields`, and calls to
the original component's public `ICLCSGenericFieldObj.CalculateSize` and `Draw`.
No DLL was patched. The PNGs here were rendered by that original component.

## CONFIRMED: font selection

The 18 DataFlex mappings in `profile-fonts.json` all expose:

- `UseTTFFonts = 1`;
- `UseZipherBitmapFonts = 0`;
- `FontPitchResolution = 1`.

Their capabilities also contain nine named entries: Arial, Arial Black,
Times New Roman, Courier New, Symbol, OCRB, Tahoma, Arabic Transparent,
and MS Gothic. These entries **do not limit the available font choices** when
`UseTTFFonts = 1`. The original component successfully rendered Arial Narrow,
Verdana, and Segoe UI as well.

The main application's font command (`CLARiSOFT.exe!00E41139`) calls the WTL
font-dialog constructor `00E3D825` with flags `0x101`. The constructor adds
`0x48` when a LOGFONT is supplied, producing CHOOSEFONT flags `0x149`:
screen fonts, effects, hook, and initial LOGFONT. **CF_TTONLY is absent.**
The dialog uses Windows `ChooseFontW` (`00E3E1D0`), so enumerating installed
Windows screen font families through GDI is consistent with this path. Font
files are machine dependencies, not a portable list built into CIFF.

The installation additionally contains `.zfbf` and `.ubf` printer bitmap fonts
under `C:\Program Files (x86)\CLARICOM\Fonts`. Those are different rendering
paths; their mere presence does not make them DataFlex TrueType choices.
`42468233` explicitly discovers `.zfbf` files for the Zipher bitmap-font list.

Supplementary screen-raster probe (`probe-raster.ps1`, `oracle-raster.json`):
requesting Fixedsys, System, or Terminal at Pitch 6/13 keeps native TTSize 1
before calculation, after calculation, and after Draw. The GDI TrueType-only
font precision selects a TrueType substitute: all six captured PNG masks
equal the corresponding Arial mask, and all six Glyph worker captures match
the native images with zero different pixels (`worker-raster-comparison.json`).
These screen-font names do not enter the printer `.zfbf`/`.ubf` path.

## CONFIRMED: CIFF contract

`Text/Font` defaults and order come from `CiffMgr.dll!6812D1DE`:

| Element | Default |
| --- | --- |
| Face | Arial |
| Family | Swiss / native GDI family 32 |
| Pitch | 13 |
| PitchResolution | 1 |
| XMag | 100 |
| YMag | 100 |
| TTSize | 1 |
| TxtDir | 0 |
| CharSpace | 0 |

`Face` is the font's name. `Family` is its classification, not the face name.
The native writer emits classification strings: Times New Roman produces
`Family=Roman`, Courier New and OCRB produce `Family=Modern`; Arial's Swiss
default is omitted. See `oracle-fields.ciff`.

Bold and Italic are siblings of Font under Text. A native Bold setter yields
`<Bold Weight="1">1</Bold>`; this Weight attribute is not CSS/GDI weight 1.
`EFontTextDirection` in the type library is `FTD_L2R=0`, `FTD_R2L=1`.
TTSize identifies native font paths: 0 bitmap, 1 TrueType, 2 ZFBF. A real
TrueType font requested with TTSize 0 is reclassified to 1 during calculation.
TTSize 2 with an Arial face is not a valid ZFBF test case.

## CONFIRMED: TrueType rasterization

The original public Draw entry is `CLCSTextBasedField.dll!424236E5`; it selects
`42424518` for TrueType. The font constructor is `42425C36` and the drawing
helper is `DrawUniscribe` (`4243B453`, `4243B565`, `42460683`).

The native TrueType path uses:

- zero-initialized LOGFONT, Face truncated to 31 UTF-16 code units;
- `lfCharSet=1`, `lfOutPrecision=7`, `lfQuality=1`;
- normal `lfWeight=400`; Bold selects 900 unless a capability maps a separate
  Windows bold face;
- `lfHeight = -trunc(MulDiv(Pitch, round(YResolution*10000), 283) / PitchResolution)`;
- first `lfWidth=0`; at XMag other than 100 the final font uses
  `lfWidth=trunc((XMag*baseTmAveCharWidth+50)/100)` (`4243B35D`);
- a one-bit bitmap, full text cell including its ascent/descent, not a crop to
  the black pixels;
- simple text measured with DrawTextW flags `0x420` and drawn with `0x20`;
- complex scripts/RTL additionally use Uniscribe ScriptShape/ScriptPlace/
  ScriptTextOut. Their decompiled pipeline is included here.

At DataFlex resolution 0.12 dots per CIFF unit (12 dots/mm), Pitch 13 gives
`lfHeight=-55`. Pitch 6 gives -25. The sample string for all normal face PNGs is:

`Abc 0123456789 АБВГД абвгд`

| Face | Pitch 6 cell | Pitch 13 cell |
| --- | --- | --- |
| Arial | 348 × 28 | 766 × 63 |
| Arial Narrow | 280 × 30 | 629 × 65 |
| Times New Roman | 315 × 29 | 712 × 62 |
| Courier New | 390 × 29 | 858 × 60 |
| Tahoma | 344 × 30 | 744 × 66 |
| Verdana | 390 × 31 | 854 × 66 |
| OCRB | 390 × 22 | 858 × 48 |
| Segoe UI | 331 × 35 | 739 × 74 |

`oracle-results.json` includes corresponding CIFF geometry. The native Draw
converts dot widths/heights to CIFF units by rounding dots/resolution.
`worker-oracle-comparison.json` records zero different pixels for all 16
standard face/pitch cases, including OCRB's native missing-glyph behavior.
Together with the six screen-raster requests, 22 font/pitch captures match.

The native TrueType path **does not apply Italic or YMag** in the tested
component. Changing Italic to 1 or YMag to 150 produces the exact same PNG
as the default field, with zero differing pixels (`variant-pixel-comparison.json`).
Preserve these imported XML values; applying browser italic or vertical bitmap
stretch would introduce a difference from this ClariSoft component.

Native Arial Pitch 13 variants:

| Change | Cell width × height |
| --- | --- |
| Default | 766 × 63 |
| Bold | 798 × 64 |
| XMag 150 | 1123 × 63 |
| PitchResolution 10 | 71 × 6 |
| CharSpace 1 | 816 × 63 |
| CharSpace 50 | 3266 × 63 |

Character-spacing output needs its own pixel comparison: native cell extent
can differ from the occupied pixel width. Do not infer all glyph advances
from just these width differences. `42459491` leaves spacing raw unless
`InterCharacterSpacingMMSupported` requests its resolution conversion.

The native Uniscribe pipeline initializes SCRIPT_CONTROL with LCID `0x809`
and SCRIPT_STATE with embedding level 0 for LTR (`42460C41`, `4245FB26`).
`42460E87` merges adjacent neutral/language-compatible noncomplex items after
ScriptItemize, explaining the combined Latin/digit run in the mixed sample.
Spacing modifies glyph advances inside each shaped run; run origins still
advance by ScriptPlace's ABC sum. Consequently spacing does not accumulate
from the Latin run into the following Cyrillic run. This behavior matters
for pixel matching imported fields with nonzero CharSpace.

## Reproduction

Run from the repository with Windows PowerShell **32-bit**:

```powershell
& C:/Windows/SysWOW64/WindowsPowerShell/v1.0/powershell.exe -NoProfile -ExecutionPolicy Bypass -File research/fonts/probe-fonts.ps1
```

`FontOracle.cs` wraps public COM Draw and exports its selected bitmap. The
probe exports 16 face/pitch PNGs, variant PNGs, XML, the 18-profile font matrix,
and JSON geometry. Generated `worker-*.png` are separate Glyph worker captures
for pixel comparison, not ClariSoft originals.

`ExportFonts.java` is the existing research exporter adapted to accept multiple
function-address arguments. `find_font_ui.py` locates the sole direct
ChooseFontW call in the installed main EXE.

## Limits

CONFIRMED comparisons apply to the installed Windows fonts, this DLL build,
and the sampled TrueType cases. Browser fallback uses a different rasterizer.
Full complex-script/RTL, ZFBF/UBF rendering, and all bitmap-font sizes require
separate oracles. Physical output on Videojet was not tested in this work.
The DoubleSpace probe is retained as raw evidence only: its calculated bounds
and captured bitmap disagree, so it is not a reliable layout contract.
