# Conservative CIFF regression fixtures

These are synthetic, minimal fixtures derived from the serialization rules in the
2026-09-12 audit request, not captured ClariSoft output or printer acceptance
samples. Each file is UTF-16LE with BOM, a UTF-16 declaration, and CRLF envelope.

| Fixture | Behavior exercised |
| --- | --- |
| `constant-text.ciff` | `FixedText` / 0, absent optional attributes and `Ln`, origin-based dimensions 3666 × 1150 |
| `external-text.ciff` | `FixedText` / 6, explicit `Static`, `FixedLen`, multiline source CDATA/SQL and independent preview/default |
| `date.ciff` | `DateText` / 2, explicit `Static` / `Parse`, date format in `Default` |
| `offset-date.ciff` | `OffsetDateText` / 3, explicit `Ln`, `SellBy` reference after another named offset |
| `field-order.ciff` | Non-numeric source order, optional zero-valued attributes, interspersed unknown siblings, 1500 × 1150 bounds |

Unknown attributes and children at Header, SubImage, Field, Data, Object, Font,
SrcData, and DateOffset levels exercise preservation during an unrelated edit.
The fixtures intentionally omit `ClStVersionInfo`; the existing production save
policy controls whether it is generated. These tests do not redefine that policy.
