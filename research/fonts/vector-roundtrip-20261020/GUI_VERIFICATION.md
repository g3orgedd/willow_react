# WEB and packaged EXE CIFF: actual ClariSoft GUI check

Date: 2026-10-20. GUI observations below are separate from native public-COM
font, size, and raster checks in this directory.

## Existing user document

Before starting, ClariSoft had `user-untitled-backup.ciff` from
`research/fonts/roundtrip-20261020/` open. The actual title had no unsaved `*`;
the accessibility tree reported `Ready` and Save disabled. Its SHA-256 was
`00B4A87332C7BCBECC096FD974FA1666BA05D5DC2F36D4B9E8E52241AC981C57`.
The application was closed normally with Alt+F4 before starting the test.

## WEB export

CONFIRMED: the original installed `CLARiSOFT.exe` was launched interactively
with the absolute `web-vector.ciff` path and opened that file in its GUI.

- Process: PID 16352; main window: 102697248.
- Actual title: `CLARiSOFT - C:\Users\GigaGeorge\Desktop\willow-react-vite-test_1.4.0\research\fonts\vector-roundtrip-20261020\web-vector.ciff`.
- `Ready`; `DataFlex 6320(53mm) - Continuous`; Save disabled; no load-error dialog.
- Opening observation: `web-gui-open.txt`.
- Tools → Field Order observation: `web-field-order.txt`.
- SHA-256 after GUI observation: `D6046CD29CCB5200FE80726B4EB22734EF9D236307573018457D30953D0A367E`.

The Field Order dialog listed all ten expected field names and the following
raw X/Y values (0.01 mm), matching the saved Glyph layout:

| Field | X | Y |
| --- | ---: | ---: |
| TNR_Text | 123 | 234 |
| Arial_Bold | 377 | 900 |
| Courier_XMag | 111 | 1701 |
| Tahoma_Date | 197 | 2403 |
| Segoe_Offset | 213 | 3107 |
| Narrow_Time | 319 | 3811 |
| OCRB_Counter | 421 | 4517 |
| TNR_Rot90 | 3801 | 801 |
| Courier_Rot180 | 1801 | 5203 |
| Tahoma_Rot270 | 4003 | 3001 |

All expected text was listed; the live clock naturally advanced (`Narrow_Time`
showed `23:24`). Return closed Field Order, and Save remained disabled.

## Packaged EXE export

CONFIRMED: the original installed `CLARiSOFT.exe` was launched interactively
with the absolute `exe-vector.ciff` path and opened that file in its GUI.

- Process: PID 22968; main window: 35260806.
- Actual title: `CLARiSOFT - C:\Users\GigaGeorge\Desktop\willow-react-vite-test_1.4.0\research\fonts\vector-roundtrip-20261020\exe-vector.ciff`.
- `Ready`; `DataFlex 6320(53mm) - Continuous`; Save disabled; no load-error dialog.
- Opening observation: `exe-gui-open.txt`.
- Tools → Field Order observation: `exe-field-order.txt`.
- All ten field names and raw X/Y values matched the WEB table above exactly.
- Expected text was displayed, with live clock data advanced to `23:29`.
- SHA-256: `D6046CD29CCB5200FE80726B4EB22734EF9D236307573018457D30953D0A367E`.

Return closed Field Order, and Save remained disabled. The EXE export was then
closed normally with Alt+F4. Neither test file was saved from ClariSoft.

`gui-position-comparison.json` parses the actual two Field Order accessibility
observations and compares them with `expected-web.json`: WEB 10/10 and EXE 10/10
field positions match, with no extra or missing names.

## Limits of GUI evidence

Computer Use screenshot capture still returned
`FrameArrived timed out: timed out waiting on channel`. A fresh window/state
and the observed dialog Raise action returned
`element 256 has no cached secondary actions for CLARiSOFT.exe`.
The font/Pitch/W/H property dialogs were therefore not read in this GUI check.
Those values must be reported from the independent installed-component check,
not attributed to GUI dialogs. GUI evidence confirms file loading and all field
positions; it is not a screenshot comparison of the vector screen preview.

## Restore user document

Both checks completed. ClariSoft was launched interactively with the original
`user-untitled-backup.ciff` path; final title/hash confirmation is recorded below.

CONFIRMED final state: PID 35888, window 15931878, responding, actual title
`CLARiSOFT - C:\Users\GigaGeorge\Desktop\willow-react-vite-test_1.4.0\research\fonts\roundtrip-20261020\user-untitled-backup.ciff`
without an unsaved `*`. The final GUI accessibility observation
`gui-restored-backup.txt` reports Ready and Save disabled.

Final SHA-256 checks confirmed both WEB/EXE exports retained
`D6046CD29CCB5200FE80726B4EB22734EF9D236307573018457D30953D0A367E` and the
user backup retained
`00B4A87332C7BCBECC096FD974FA1666BA05D5DC2F36D4B9E8E52241AC981C57`.
