# Screen vector paths with unchanged printer metrics

`electron/font-renderer.ps1` now returns an optional `outlinePath` in addition to
the original PNG and metric fields. The path contains absolute SVG `M/L/Q/C/Z`
commands in the output printer-dot coordinate system. Its origin is the same
top-left cell origin as the PNG. Fill it with the nonzero rule. An empty string is
a valid blank vector; `null` or an absent property selects the raster fallback.

The worker selects the same GDI font, including the existing XMag font-width
calculation. It reads real glyph outlines with
`GGO_NATIVE | GGO_GLYPH_INDEX | GGO_UNHINTED` (`0x182`). Native quadratic splines
are converted using the midpoint between consecutive off-curve control points;
cubic splines remain cubic. Signed 16.16 FIXED coordinates are inverted about
the native font baseline and scaled horizontally by `xRes/yRes`.

The vector uses Uniscribe's glyph IDs, advances and combining offsets. For the
existing `CharSpace` path, it also includes the DC character extra that GDI adds
when drawing but does not include in `ScriptPlace` advances. Each run begins at
the original run pen, matching the current native raster implementation.

`DrawText` can position a run differently from a standalone `ScriptPlace` call,
for example with Cyrillic punctuation. It also interprets mnemonic ampersands.
When the shaped width differs from the original measured width, or text uses
DrawText prefix/control handling, the worker captures the actual GDI font curves
with `BeginPath/EndPath/GetPath`. These remain scalable cubic vector paths, with
GDI-fitted integer control points and the original DrawText layout.

Vector generation occurs after the original PNG has been saved. Outline errors
select the PNG fallback and never change its pixels or the CIFF metric fields.
This provides smooth screen enlargement; it does not claim that the vector is
the same image as ClariSoft's printer-resolution bitmap or a GUI screenshot.

## Verification

- Web follow-up: an old agent-created Vite bound specifically to
  `127.0.0.1:5173` was still serving a pre-vector worker in front of the user's
  newer wildcard-bound Vite. It returned PNG-only responses. The old test server
  was stopped normally through its original exec session; the user's server
  remains running. Both localhost and 127.0.0.1 now return `outlinePath`.
- `research/fonts/verify-web-fonts.cjs` loads the real HTTP website in an isolated
  Chromium profile with no Electron preload or font IPC. All 16 checks pass:
  five text types use paths at 50/100/133/400%, font UI and CIFF round trips work,
  zoom preserves serialized CIFF, text has 3983 antialiased edge pixels, and
  DataMatrix remains a group of crisp module rectangles. Final evidence is in
  `tests/output/font-vector-web-final/`; its initial diagnosis was captured
  after the competing test server had already been stopped, not as a failing
  baseline.
- Vite now watches the worker and the two native-service CJS modules and performs
  a managed restart on edits. Config reload invalidates only those helper
  modules. Its renderer opts into source-versioned workers and caches; desktop
  keeps the default without per-request source checks. 24 backend/Vite tests
  and typecheck pass, including three source/cache/restart regressions.
- `research/fonts/verify-editor.cjs`: the actual Electron editor and the final
  packaged `app.asar` both use `Konva.Path` for all five text types. Font selection,
  group edits, save/reopen, zoom 25/100/133/200/400%, and unchanged saved CIFF bytes
  pass. A 4x outline renders 4280 antialiased edge pixels instead of enlarging the
  monochrome printer grid. Evidence is in `tests/output/font-vector-packaged/`.
- Frontend/native geometry regression tests: 20 passed. Backend/catalog tests:
  15 passed. Full suite: 410 tests, 400 passed, the same 10 existing UI/source
  failures as `font-verified-test-run.txt`; no new failing test names.
- Production build and Windows directory package completed successfully:
  `desktop-release-vector-fonts-20261020/win-unpacked/Glyph Studio.exe`.
- `node research/fonts/vector-preview/verify-native.cjs`: 54 native requests,
  five families (Arial, Courier New, Times New Roman, OCRB, Tahoma), ASCII and
  Cyrillic, regular/bold, XMag100/150, whitespace, combining/surrogate text,
  CharSpace1/50, mixed runs, resolution ratios and ampersands. Every original PNG
  and metric field is byte-for-byte equal to `font-renderer-before.ps1`.
- `verify-curves.ps1`: synthetic line, quadratic and cubic contours, negative
  FIXED values, midpoint calculation, baseline inversion, horizontal scaling
  and malformed-buffer rejection.
- `compare-outlines.ps1`: native raster above and vector curves below at 4x,
  plus `outline-bounds.json`. The CharSpace50 outline now has the original visible
  spacing. Normal unhinted curve bounds can differ by approximately one printer
  dot because they have not been grid-fitted. Combining marks can differ more.
- `node --test tests/native-outline-backend.test.cjs`: IPC path validation,
  empty/fallback paths, parser checks, native raster/metric preservation and
  intercharacter gap placement. Native tests skip on other operating systems.

Primary references:
[GetGlyphOutlineW](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-getglyphoutlinew),
[FIXED](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-fixed),
[Spline records](https://learn.microsoft.com/en-us/windows/win32/gdi/spline-records),
[ScriptTextOut](https://learn.microsoft.com/en-us/windows/win32/api/usp10/nf-usp10-scripttextout),
[SetTextCharacterExtra](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-settextcharacterextra),
[BeginPath](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-beginpath),
[GetPath](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-getpath).
