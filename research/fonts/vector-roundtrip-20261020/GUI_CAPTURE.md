# Actual ClariSoft window screenshot attempt

Date: 2026-10-20. This attempt produced no ClariSoft screenshot. Native field
renderings and bitmap comparisons are separate evidence and do not replace it.

## Computer Use capture

The existing clean user backup was verified before any file transition. A fresh
window inventory selected its actual ClariSoft window; the window was activated,
rehydrated, and its accessibility state read successfully (Ready, Save disabled).
Screenshot capture returned:

`window capture timed out: timed out waiting on channel`

The documented recovery sequence was performed once: fresh inventory, select the
unique ClariSoft window, activate, rehydrate, retry screenshot. That retry returned
the same error. No further Computer Use screenshot retries were performed.

The window inventory did not contain LockApp. A read-only session inventory
reported the console session Active. This does not establish that the desktop was
locked or identify the cause of the capture failure.

## Existing screenshot application fallback

The original installed ClariSoft was opened interactively with the unchanged
`web-vector.ciff` (PID 19880, window 38011488). Its actual window title contained
that complete path. The window was maximized using its observed system menu;
the titlebar action changed from Maximize to Restore. Its observed zoom combobox
was set to 200% and committed with Return; Save remained disabled.

An existing `Glyph Screenshots.exe` instance, PID 6424, started on 2026-10-19
09:40:09, was available at
`C:\Users\GigaGeorge\Documents\oak_project\release\Glyph Screenshots-Fluent-5.8.5\Glyph Screenshots.exe`.
Its configured New Capture hotkey is Ctrl+Shift+S. That shortcut was issued while
ClariSoft was foreground at 200%, at 2026-10-20 20:40:47.575 UTC
(23:40:47.575 Moscow). It exposed no capture chooser or other targetable window.

The installed utility was then activated through Computer Use's supported
`launch_app` API, which returned:

`launched app did not expose a targetable window: process:C:\Users\GigaGeorge\Documents\oak_project\release\Glyph Screenshots-Fluent-5.8.5\Glyph Screenshots.exe`

A fresh inventory still exposed no utility window. The existing process remained
responding with an empty MainWindowTitle; it was not terminated. Its History
directory had 201 existing files before the attempt and no newly created files
after it. No old screenshot content was opened or used as a result.

No actual ClariSoft PNG was obtained. The EXE file was not reopened solely for a
second failed capture attempt after the WEB attempt established this limitation.
Both files' earlier real GUI loading/position checks remain in GUI_VERIFICATION.md.

## Restoration

Before closing the test file, the original 500% zoom and normal window size were
restored through observed controls. The clean WEB file was closed normally with
Alt+F4, and the original user backup was opened interactively again.

CONFIRMED final process PID 8620, window 185144316, responding. Its actual title
was `CLARiSOFT - C:\Users\GigaGeorge\Desktop\willow-react-vite-test_1.4.0\research\fonts\roundtrip-20261020\user-untitled-backup.ciff`
without an unsaved `*`. The final accessibility observation is saved in
`gui-after-capture-restored-backup.txt`; it reports Ready, Save disabled, 500% zoom,
and a Maximize titlebar action (normal window size).

Final SHA-256 checks remained unchanged:

- WEB and EXE CIFF: `D6046CD29CCB5200FE80726B4EB22734EF9D236307573018457D30953D0A367E`.
- User backup: `00B4A87332C7BCBECC096FD974FA1666BA05D5DC2F36D4B9E8E52241AC981C57`.
