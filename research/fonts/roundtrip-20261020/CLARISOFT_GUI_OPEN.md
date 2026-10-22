# ClariSoft GUI file opening — 2026-10-20

CONFIRMED from the installed main EXE's original machine code:

- `.ciff` is registered as `CLARiSOFT.Ciff.1`, whose open command is the installed `CLARiSOFT.exe` followed by the quoted file path.
- Static initializer `00E0113F` creates the named mutex `CLARiSOFTSingleInstance` and retains GetLastError. `00E010D8` also creates `Global\\GlobalCLARiSOFTSingleInstance`.
- WinMain `00E3BF99` checks `ERROR_ALREADY_EXISTS` (`0xB7`) before the normal initialization and command-line processing.
- If an existing instance is found, `00E3A17F(existingPid)` enumerates its windows and attempts to bring a matching window to the foreground. It restores only minimized windows. It does not forward the requested file name. Finding a matching window makes the new process return zero, even if foreground activation fails.
- Therefore starting `CLARiSOFT.exe <file.ciff>` while an existing instance has `Untitled*` open does not verify that the requested file was opened. The original title and document can remain unchanged.
- The RT_ACCELERATOR resource 128 contains Ctrl+O → ID_FILE_OPEN (`0xE101`), Ctrl+S → ID_FILE_SAVE (`0xE103`), and Ctrl+N → ID_FILE_NEW (`0xE100`). Keyboard navigation is a documented resource-backed route if Computer Use input is working.

No mutex, executable, license, running-process state, or application document was modified in this inspection. A GUI verification needs the existing document safely retained before opening the test CIFF in the existing instance. Separate public-COM loader/render verification can run independently, but it must be reported separately from a GUI-open result.

## Hidden startup and the existing-process termination branch

CONFIRMED by disassembling the installed executable's original code without executing these branches:

- The `EnumWindows` callback `00E39F6E` accepts a window when its process ID equals the requested existing PID, its title is nonempty, and that title begins with `CLARiSOFT`. It does **not** call `IsWindowVisible` or otherwise exclude hidden windows.
- At `00E3A17F`, `GetWindowPlacement` supplies `showCmd`. Only values `2` (`SW_SHOWMINIMIZED`) or `6` (`SW_MINIMIZE`) set the restore flag. `ShowWindow(hwnd, 9)` (`SW_RESTORE`) runs only for those values. A hidden window with `showCmd=0` is not shown by this path.
- `SetForegroundWindow` is called, but its return value is ignored. The helper returns `1` whenever a matching titled window was found, including a hidden one. WinMain then exits the new process before normal command-line handling. A second normal launch is therefore not a reliable way to reveal an instance started hidden.
- If the callback finds **no** matching titled window, the helper returns `0`. WinMain at `00E3C060` reads the existing PID from the same process list and passes it to `00E3A0DF`.
- `00E3A0DF` calls `OpenProcess(0x001F0FFF, FALSE, existingPid)`. Its returned handle is placed in `ESI`; if nonzero, `00E3C074` pushes exit code `0`, `00E3C075` pushes `ESI`, and `00E3C076` calls `TerminateProcess`. `CloseHandle(ESI)` follows at `00E3C07D`.

The termination target is the **existing process**, not the newly launched process. Do not start a second instance as an activation workaround when the existing instance has no matching titled main window. A separately created clean test process may be stopped only after verifying its identity; this inspection does not authorize terminating unrelated user processes or discarding documents.

## Resource-backed keyboard commands

The original `RT_ACCELERATOR/128` resource confirms `Ctrl+A` → `0x803D` (select all), `Ctrl+L` → `0x8043` (rotate left), and `Ctrl+R` → `0x8044` (rotate right). It contains no Tab, Enter, Ctrl+Enter, Alt+Enter, or field-properties accelerator.

The field context menu `RT_MENU/202` contains `&Font` → `0x8012` and `&Properties...` → `0x800C`. These mnemonics can be used after opening that context menu through a working keyboard route. Context menus `234` and `235` also use `0x800C` for field properties; `235` includes the font command. Main menu File → `P&roperties...` is a different command, `0x800B`, for the image/document.
