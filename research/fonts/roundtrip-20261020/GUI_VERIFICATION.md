# ClariSoft GUI verification — 2026-10-20

This file records GUI observations separately from the public-COM render comparison.

## Preserving the existing document

The existing ClariSoft process (PID 33728, main window 53022756) initially had
`Untitled*` open. Its document was saved through the application's own Save dialog
to `user-untitled-backup.ciff` in this directory. The observed Save dialog's filename
combobox accepted the absolute path; pressing Return completed the save.

Verified on disk:

- File size: 2216 bytes.
- SHA-256: `00B4A87332C7BCBECC096FD974FA1666BA05D5DC2F36D4B9E8E52241AC981C57`.
- Main window title became `CLARiSOFT - C:\Users\GigaGeorge\Desktop\willow-react-vite-test_1.4.0\research\fonts\roundtrip-20261020\user-untitled-backup.ciff` without an unsaved `*`.

The Open dialog exposed the test file `glyph-font-check` in its folder view.
However, Computer Use actions on the dialog's filename combobox returned
`element 755 is not available in cached app state for CLARiSOFT.exe` even after
fresh accessibility observations. Screenshot capture returned
`FrameArrived timed out: timed out waiting on channel`.

The Open dialog was raised with its observed accessibility action. After a fresh
observation reported focus on that dialog, Escape closed it. The clean backup
document was then closed with Alt+F4; both the Computer Use window inventory and
the process inventory confirmed the original instance had exited. No unsaved
document was discarded and no process was force-terminated.

## Test-file GUI loading

CONFIRMED: the original installed ClariSoft opened the final Glyph-produced file
in its GUI (PID 14692, main window 222630184). Its observed title was
`CLARiSOFT - C:\Users\GigaGeorge\Desktop\willow-react-vite-test_1.4.0\research\fonts\roundtrip-20261020\glyph-font-check.ciff`.
The accessibility tree reported `Ready`, `DataFlex 6320(53mm) - Continuous`,
and a disabled Save button. No load-error dialog was present.

The first test startup was hidden and exposed no targetable Computer Use window.
That newly created test process (PID 684, verified executable path and start time
21:40:29) was stopped, then the original executable was launched interactively.
This did not affect the already saved user backup or the original user process,
which had exited normally earlier.

The test fixture remains the final Glyph-produced file with SHA-256
`D6046CD29CCB5200FE80726B4EB22734EF9D236307573018457D30953D0A367E`.

## Positions read from the GUI

The actual application's Tools → Field Order dialog enumerated all ten fields.
Its full accessibility observation is saved as `gui-field-order.txt`.
All raw X/Y values agree with Glyph's `expected.json` (CIFF units of 0.01 mm):

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

The dialog also displayed the expected text, except live clock data naturally
advanced (`Narrow_Time` showed `21:43`). Return closed this read-only dialog;
the file remained clean, with Save disabled.

Field selection in this dialog failed with the Computer Use cached-state error,
so font names, Pitch, and W/H were not read from GUI property dialogs. Their
separate successful verification through the installed ClariSoft's public COM
loader and original field components is documented in `README.md`; it must not
be described as a GUI property-dialog observation. Screenshot capture of the
new interactive instance also timed out, so no GUI screenshot was obtained.

## Restoration

The test document was closed normally with Alt+F4 while clean. The original
executable was then launched interactively with `user-untitled-backup.ciff`.
CONFIRMED: final PID 39136, window 130681170, title
`CLARiSOFT - C:\Users\GigaGeorge\Desktop\willow-react-vite-test_1.4.0\research\fonts\roundtrip-20261020\user-untitled-backup.ciff`
without an unsaved `*`. The final process was responding. The full final GUI
accessibility observation is in `gui-restored-backup.txt`.

Final SHA-256 checks confirmed both the test fixture and the user backup were
unchanged from the hashes recorded above.
