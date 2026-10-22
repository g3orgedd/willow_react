# CIFF compatibility regression fixtures

| Fixture | Purpose | SHA-256 |
|---|---|---|
| `22x22_reference_270days.ciff` | ClariSoft reference accepted by VideoJet | `F3D8A3C250D770E9C3DB1B78A6D2A88AF34BC901C02C0D064EC87492BE6D0C82` |
| `22x22_1_broken.ciff` | Original Glyph regression input; kept byte-identical | `4854B2597104A2C0B17BA15846B9CDA21AC95037644FD60D7CD03EDB033BAB12` |
| `22x22_1_fixed.ciff` | Output produced by the repaired Glyph open/save pipeline | `1528D4D33AE896C3DCBB06DBB31EA590BA13A9A886B437CD07CF9F8D83F1FA9D` |
| `ZDRAVA2.ciff` | ClariSoft fixture where `Image*` is the used-content extent and `MaxImage*` is the editor workspace | `62C7DB475B5C4B5AF7B779CBACE0CB3372D05AE6FF7025FA62A536ED5E9AB42C` |

## Diagnostic comparison

| Property | ClariSoft reference | Broken Glyph | Fixed Glyph |
|---|---:|---:|---:|
| `DesignedFor` | `DataFlex 6330(53mm) - Continuous` | same | same |
| `SubImage@ImageReference` | `1` | missing | `1` |
| `SubHeader@FormatName` | `Default` | missing | `Default` |
| `SubHeader@PrinterFormatName` | `Default` | `Default` | `Default` |
| `ImageWidth × ImageHeight` | `3125 × 2574` | `2967 × 1160` | `2967 × 1160` |
| `MaxImageWidth × MaxImageHeight` | `5333 × 7500` | `3200 × 1200` | `5333 × 7500` |
| `XRes` | `0.120000` | missing | `0.120000` |
| `CurrentOrientation` | `0` | `0` | `0` |
| `ImageMapping` | reference `1` | mapping `1`, but SubImage reference missing | reference `1` |
| `CurrentOffset` | calendar date | `Day=270` | calendar date |
| Hidden fields outside hardware | `0` | `11` | `0` |
| Hidden-field overlaps | `0` | not relevant (out of bounds) | `0` |
| Encoding | UTF-16LE + BOM | UTF-16LE + BOM | UTF-16LE + BOM |
| Layout/EOL | 2 lines, CRLF, final CRLF | same | same |

The fixed file deliberately preserves the original visual image size (`2967 × 1160`).
Printable text validation uses Glyph's fresh rendered glyph bounds; all serialized
objects are additionally checked against the `5333 × 7500` hardware rectangle.

`ZDRAVA2.ciff` proves that ClariSoft does not use `ImageWidth/ImageHeight` as
the visible editor canvas: its used image is `2516 × 2558`, while the workspace
shown by ClariSoft is the full `5333 × 7500` printer area.
