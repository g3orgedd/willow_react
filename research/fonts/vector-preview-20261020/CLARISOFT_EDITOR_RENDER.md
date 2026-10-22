# Original ClariSoft editor rendering — 2026-10-20

## CONFIRMED conclusion

The inspected ClariSoft editor path renders each text field through its original
component's `ICLCSGenericFieldObj::Draw`, caches the returned printer-resolution
`HBITMAP`, and blits that bitmap into the view. It does **not** obtain a second,
screen-DPI outline rendering of the text on this path. View mapping and bitmap
resampling account for screen resolution and zoom.

Consequently Glyph's smooth outline display is a display improvement requested
by the user. It must not be described as copying a vector-rendered ClariSoft GUI.
The existing native printer bitmap, native cell measurements, CIFF geometry, and
round-trip checks remain the references for the printable layout.

This is static analysis of original installed code. It is not a screenshot or a
claim about every alternative ClariSoft view, printing path, or field component.
No original executable/DLL, production code, or UI state was changed for this
analysis.

## Binary identity and method

- `C:\Program Files (x86)\CLARICOM\CLARiSOFT\CLARiSOFT.exe`,
  file/product version `4.5.1.0`.
- SHA-256:
  `28aebc9c30c68e85175be90580195d6e4f3180a994ecdc8215e9b93c26304e1a`.
- Original field component and its hash are recorded in
  [../README.md](../README.md).
- Function boundaries/names came from
  `research/ciff-fields/decompiled/CLARiSOFT.exe/functions.jsonl`.
- The original PE was disassembled at its preferred virtual addresses using
  `pefile` and Capstone from `research/clst/tools`; IAT targets were resolved
  from the original PE import table. Names such as `FUN_00e60ee2` are analysis
  labels, not recovered original C++ names.

## Editor call chain

```text
CLARiSOFT.exe!00E867D5        view paint/draw path
  00E869FA -> 00E2D699       document / field enumeration
    00E2DC47 -> 00E60EE2     per-field cached bitmap rendering
      if field render cache is dirty:
        00E61054 -> component.vtable[0x0C]
                 ICLCSGenericFieldObj::Draw(scratchDC, ignorePosition=1,
                   field VARIANT, capabilities VARIANT, file VARIANT, color)
      00E61180 -> 00E62F49   bitmap placement and display resampling
```

The document passes its capabilities pointer `[document+0x160]` and file pointer
`[document+0x19C]` into `00E60EE2` at `00E2DC2F` and `00E2DC1A`, respectively.
These are the existing document objects; this call site does not replace their
resolution properties with the screen resolution.

Within `00E60EE2`:

| Address | Confirmed operation |
| --- | --- |
| `00E60EFE` | `CreateCompatibleDC(targetDC)` for the scratch DC. |
| `00E60F27`, `00E60F33` | Read viewport/window extents of the target view. |
| `00E60F43`–`00E60F55` | Query target `HORZRES/HORZSIZE/VERTRES/VERTSIZE`. These do not set printer capabilities. |
| `00E60F9D` | Test per-field cache dirty flag `[this+0x48]`. |
| `00E60FA9` | Clear that flag before regenerating the cache. |
| `00E60FB8`–`00E61053` | Package the file, capabilities, and field as `VT_DISPATCH` VARIANTs. |
| `00E61033`, `00E6104B` | Set EDX to 1 and push it as `ignorePosition`. |
| `00E61054` | Call component vtable `+0x0C`, the original public Draw method. |
| `00E61081` | Delete the previous cached bitmap if present. |
| `00E6108D`, `00E61093` | `GetCurrentObject(scratchDC, OBJ_BITMAP)` and store its handle at `[this+8]`. |
| `00E61098`–`00E6109F` | On an unchanged field, select that cached bitmap instead of calling Draw. |
| `00E610B1` | `GetObjectW` reads the cached bitmap's actual width and height. |
| `00E610DE`, `00E610F8` | Resolve field position and convert it into view coordinates. |
| `00E61180` | Pass the bitmap DC, bitmap dimensions, position, color and display flags into `00E62F49`. |

The component Draw selected here is the same public entry used for the native
printer bitmap oracle. For TrueType fields, the installed component's
`CLCSTextBasedField.dll!424236E5` dispatches to `42424518`, which makes the
one-bit text-cell bitmap described in [../README.md](../README.md) and in the
existing `research/fonts/decompiled/CLCSTextBasedField.dll/FUN_42424518.c`.

## Screen resolution and scale

The view path reads document X/Y resolution via capability vtable `+0x2C` and
`+0x34` at `00E8684D` and `00E86863`. It also reads target DC `LOGPIXELSX=88`
and `LOGPIXELSY=90` at `00E86893` and `00E8689A`, derives view mapping extents,
and applies them with `SetViewportExtEx` at `00E868FB`.

Thus screen DPI affects the destination mapping, while the cached text bitmap
continues to come from Draw with the document's printer capabilities. The
presence of screen-device queries is not evidence that text is re-rasterized at
screen DPI.

`00E62F49` obtains the target viewport/window extents again. It computes
destination device width/height using those extents and integer rounding.

- If **both** computed destination dimensions are at least the source bitmap
  dimensions, `00E63053` uses `BitBlt` into the target with its current mapping.
  There is no separate outline/text drawing in this branch.
- If either destination dimension is smaller, it creates a temporary bitmap of
  the computed device dimensions at `00E63093`, sets
  `SetStretchBltMode(tempDC, HALFTONE=4)` at `00E630D0`, sets up its halftone
  palette/color adjustment/brush origin, and calls `StretchBlt` at `00E6311D`.
  Source width/height are the cached original bitmap dimensions.
- The resampled temporary bitmap is then copied to the destination using
  `BitBlt` at `00E63150`, with a temporary one-to-one viewport mapping. The
  original mapping and GDI resources are restored afterwards.

This explains smooth **downsampling** without implying vector text. Exact
display pixels at an arbitrary view size still require the original view's
mapping, compositing colors and GDI resampling; the printer bitmap comparison
alone is not a screenshot equivalence claim.

## Implications for Glyph's outline display

- Retain native full-cell width/height, including ascent/descent and whitespace,
  for selection, rotation anchors, model geometry and serialization. A path's
  ink bounds are not a replacement for the native text cell.
- Apply outline-dot-to-screen scaling once. Keep the existing CIFF-to-printer-dot
  position rounding and parent rotation; do not rotate the glyph path twice.
- Obtain outlines from the same resolved GDI font and use the existing shaped
  glyph positions/advances. CSS weight, browser fallback, a horizontal XMag
  stretch, or per-character unshaped advances can change the layout.
- Preserve the native baseline transform: `GetGlyphOutline` contours are y-up;
  canvas coordinates are y-down. Offsets from shaped glyphs must be applied in
  the same coordinate system as the baseline.
- Keep native bitmap data available for printer checks and unsupported-outline
  fallbacks. Smooth contour fill edges are expected to differ from the one-bit
  printer raster even when the native cell and glyph positions agree.
- Keep geometry synchronization and request cache identity independent of screen
  zoom, and reject obsolete async responses after text/font edits or tab changes.

