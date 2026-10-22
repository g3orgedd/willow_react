# Glyph → ClariSoft saved-font verification — 2026-10-20

This is the printer-raster baseline recorded before the screen preview switched
to smooth vector outlines. Its pixel equality describes the printer bitmap,
not the current vector display. To reproduce the raster canvas comparison,
the research exporter has an explicit `--printer-raster` flag; it only changes
this isolated verification run, not the normal editor or CIFF serialization.

The test file is `glyph-font-check.ciff`, downloaded by the real Glyph editor
through `saveTemplateFromDialog` / `downloadCiff`, with UTF-16LE BOM. The fixture
was not assembled by the ClariSoft oracle. `export-glyph.cjs` selects typefaces
through the actual font-select control, measures native previews, saves the
file, and records field data and rendered preview nodes in `expected.json`.

## Confirmed by the installed ClariSoft components

`verify-saved-native.ps1` loads that physical file through the installed
`ICiffManager.load`, resolves its actual DataFlex 6320(53mm) Continuous
capabilities, and enumerates the loaded fields. It then invokes the original
text component's `UpdateData`, `CalculateSize`, and `Draw` on those loaded
objects. It does not recreate the fields in a second model.

All ten fields match the saved Glyph state for Face, Pitch, XMag, Bold/Italic,
orientation, X/Y/W/H. The ten individual bitmap comparisons are exact.

| Field | Face | Pitch | X/Y, mm | W/H, mm | Rotation |
| --- | --- | ---: | --- | --- | ---: |
| TNR_Text | Times New Roman | 6 | 1.23 / 2.34 | 13.67 / 2.42 | 0 |
| Arial_Bold | Arial, bold | 13 | 3.77 / 9.00 | 30.25 / 5.33 | 0 |
| Courier_XMag | Courier New, XMag150 | 9 | 1.11 / 17.01 | 26.25 / 3.33 | 0 |
| Tahoma_Date | Tahoma | 8 | 1.97 / 24.03 | 11.67 / 3.42 | 0 |
| Segoe_Offset | Segoe UI | 7 | 2.13 / 31.07 | 10.00 / 3.42 | 0 |
| Narrow_Time | Arial Narrow | 10 | 3.19 / 38.11 | 7.17 / 4.08 | 0 |
| OCRB_Counter | OCRB | 11 | 4.21 / 45.17 | 9.33 / 3.42 | 0 |
| TNR_Rot90 | Times New Roman | 6 | 38.01 / 8.01 | 5.58 / 2.42 | 90 |
| Courier_Rot180 | Courier New | 8 | 18.01 / 52.03 | 11.67 / 3.08 | 180 |
| Tahoma_Rot270 | Tahoma | 6 | 40.03 / 30.01 | 7.33 / 2.50 | 270 |

The full Glyph canvas is compared with the original ClariSoft field bitmaps,
including their native rotations, composited at the component's printer-dot
positions. Both 636×840 at 12 dots/mm and its 4× nearest-neighbor rendering
(2544×3360) have **zero differing pixels**. These compositions are not screenshots
of the ClariSoft GUI. The original `Draw(ignorePosition=0)` creates a field-sized
bitmap, so its clipped output is not used as a paper-sized canvas.

Evidence: `native-roundtrip-report.json`, `layout-4x-comparison.json`,
`glyph-layout.png`, `clarisoft-layout.png`, and the per-field PNGs.

## Corrections made during verification

- Explicit date/time format, offset and counter-configuration edits now
  remeasure native geometry before saving. Ordinary clock ticks leave an
  untouched imported CIFF's geometry intact.
- Native bitmap placement now rounds CIFF X/Y to printer dots using the original
  float32 multiplication and rounding rule. The stored CIFF coordinates stay
  unchanged. Rotation offsets account for exact bitmap dots versus rounded
  CIFF W/H, so enlarged previews retain the same corner as ClariSoft.
- Research canvas exports explicitly disable image smoothing. A separate canvas
  export defaults to smoothing even when the displayed Konva layer disables it;
  that test-capture artifact initially produced false pixel differences.

Time/date values are recalculated by ClariSoft's normal `UpdateData` path. Run
the Glyph export and native verification together so the time field is compared
within the same minute. The source CIFF retains its dynamic field types.

## GUI verification

The installed ClariSoft application opened the saved `glyph-font-check.ciff`.
The actual main-window title contains its full path; accessibility reports
`Ready`, `DataFlex 6320(53mm)`, and a disabled Save command. No load-error dialog
was present. GUI observations are recorded separately from the component pixel
comparisons in `GUI_VERIFICATION.md`; `CLARISOFT_GUI_OPEN.md` documents the
single-instance and hidden-window behavior.

`Tools → Field Order` listed all ten names and the expected raw X/Y values;
the full accessibility evidence is in `gui-field-order.txt`. Font and dimension
dialogs could not be read reliably through Computer Use's element cache, and
window screenshots failed with `FrameArrived timed out`. Face/Pitch/W/H and
pixel equality are therefore confirmed by the original loaded components as
described above, not by a GUI screenshot or readings of those GUI dialogs.

Before opening the fixture, the user's existing `Untitled*` was saved normally
as `user-untitled-backup.ciff` (2216 bytes, SHA-256
`00B4A87332C7BCBECC096FD974FA1666BA05D5DC2F36D4B9E8E52241AC981C57`).
The original process was closed normally only after its title no longer had
an unsaved-change marker.
After verification, ClariSoft reopened this backup normally. The final window
is clean and responding; `gui-restored-backup.txt` records that observation.
Both the backup and the Glyph test CIFF retain their original hashes.

## Reproduce

1. `npm run build`
2. Run `node_modules/electron/dist/electron.exe research/fonts/roundtrip-20261020/export-glyph.cjs --printer-raster`
3. Run `C:/Windows/SysWOW64/WindowsPowerShell/v1.0/powershell.exe -NoProfile -ExecutionPolicy Bypass -File research/fonts/roundtrip-20261020/verify-saved-native.ps1`
4. Run the same 32-bit PowerShell with `-File research/fonts/roundtrip-20261020/compare-layout-4x.ps1`

The research export uses an isolated Electron profile; normal Glyph tabs and
preferences are not used by that export.
