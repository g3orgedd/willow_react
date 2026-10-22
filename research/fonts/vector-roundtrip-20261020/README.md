# Vector preview → saved CIFF → ClariSoft, 20 October 2026

Both save paths were exercised after the vector-preview change:

- The real HTTP web editor at `http://127.0.0.1:5173/`, without Electron preload
  or font IPC, saved `web-vector.ciff` through its Save/download code.
- The actual packaged `desktop-release-vector-fonts-20261020/win-unpacked/Glyph Studio.exe`
  saved `exe-vector.ciff` through its own main/preload/worker and Save/download
  code. CDP controlled a separate application process and isolated user profile.
  This was not an ASAR-only editor harness.

Each file is 9958 bytes, UTF-16LE with BOM. Both have SHA-256
`d6046cd29ccb5200fe80726b4eb22734ef9d236307573018457d30953d0a367e`.
They also equal the earlier printer-preview fixture byte for byte: switching
the screen to vector contours did not alter CIFF serialization in these cases.

## Result

| Check | Web | Actual EXE |
| --- | --- | --- |
| Opened in the installed ClariSoft GUI | Yes | Yes |
| GUI Field Order names and raw X/Y | 10/10 exact | 10/10 exact |
| Original ClariSoft loader/component font properties, X/Y/W/H and rotation | 10/10 exact | 10/10 exact |
| Actual vector Path cell, scale, rotation and translation | 10/10 exact | 10/10 exact |
| Original ClariSoft printer raster vs equivalent Glyph printer payload | 10/10 exact | 10/10 exact |
| Input CIFF unchanged during checking | Yes | Yes |

The ten fields cover FixedText, DateText, OffsetDateText, TimeText and CounterText;
Times New Roman, Arial, Courier New, Tahoma, Segoe UI, Arial Narrow and OCRB;
Bold, XMag150 and rotations 0/90/180/270. Twelve font properties are checked at
each native load/update/measure/draw stage, including source/native defaults.
Actual Path transform coefficients and native cell dimensions agree within
`1e-6` printer dot, without replacing the vector with a bitmap.

The web clock naturally advanced between its captured preview and native check
(23:23 → 23:29). Its captured text was retained in the evidence; a separate
current-payload printer reference matched original Draw exactly. The EXE's ten
captured printer references matched directly. Clock changes are not hidden as
zero differences against an older text value.

## Screen contours versus printer pixels

Smooth vector pixels are deliberately different from ClariSoft's monochrome
printer bitmap. `compare-vector-ink.cjs` measures the actual captured contour
bounds against its printer bitmap's black-pixel coverage. For both files the
largest edge-bound difference is one printer dot, or 0.08333 mm at 12 dots/mm.
These are hinting/coverage differences; the field geometry, baseline cell and
positioning transforms match exactly. This result does not claim identical
screen pixels or identical ink bounds.

## Evidence and limits

- `GUI_VERIFICATION.md`, `gui-position-comparison.json`, `web-field-order.txt`
  and `exe-field-order.txt` record the actual ClariSoft windows and all ten
  coordinates for both saved files.
- `NATIVE_VERIFICATION.md`, `native-verification-summary.json` and
  `native-{web,exe}/verification-report.json` record original filename loading,
  font/geometry/transform checks, printer references and component fingerprints.
- `expected-web.json`, `expected-exe.json`, `export-results.json`, the isolated
  EXE session logs and the per-field PNG/outline data record export provenance.
- `web-vector-editor.png` and `exe-vector-editor.png` are Glyph previews, not
  ClariSoft GUI screenshots. The layouts and 4x contours are saved alongside.
- `vector-ink-web.json` and `vector-ink-exe.json` contain the edge-bound results.

The first EXE Save completed successfully. A research-only raw-ASAR fingerprint
step then failed because Electron's patched fs treated the archive as a folder.
After correcting that step to use original-fs, preview artifacts were collected
on a read-only reopening of the same physical CIFF in the same packaged binary.
The file was never saved again; the recovery and capture times are marked in
`expected-exe.json` and the original Save/download events remain in its logs.

Computer Use screenshots still failed with `FrameArrived` and field font/size
property dialogs could not be read reliably. GUI proof therefore covers actual
opening and Field Order coordinates. Font and size proof comes from the original
ClariSoft loader and field components, not from a GUI property-dialog reading.

The user's original ClariSoft backup was reopened after both tests. Its hash,
both test-file hashes and the clean final window state were verified. The user's
running Glyph application and web profile were not used as test profiles.

## Actual full screenshots: WEB | EXE only

[Open the two-column screenshot gallery](web-exe-screenshots/index.html), or
[view the complete 2460 × 1197 PNG](web-exe-screenshots/web-exe-side-by-side.png).
These are genuine captures of the HTTP web editor and the actual packaged EXE,
each at 1440 × 1100 and editor zoom 100%, showing the entire 70 mm sheet and all
ten fields. The gallery links to their unchanged original pixels and offers 1:1
viewing. The clock reads 23:41 in WEB and 23:38 in EXE because the captures were
taken at different times. Neither file was saved again during these captures.

This is a partial WEB/EXE comparison, not a ClariSoft screenshot comparison.
No genuine ClariSoft GUI PNG was obtained. [GUI_CAPTURE.md](GUI_CAPTURE.md)
records the supported capture attempts, their failures and restoration of the
user's original clean ClariSoft document. The separate four-input composer
`compose-screenshot-gallery.cjs` still requires two actual ClariSoft screenshots
before it can produce the requested full comparison; it supplies no placeholders.
