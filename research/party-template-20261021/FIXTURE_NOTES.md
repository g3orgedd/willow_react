# Party fixture structure, 21 October 2026

The two user-provided files were read without modification. Full extracted
structure and hashes are in `fixture-structure.json`.

| Property | Party.ciff | Party1.ciff |
| --- | --- | --- |
| File | Desktop/Party.ciff | Downloads/Party1.ciff |
| Bytes | 13002 | 10542 |
| Variant | With box input | Without box input |
| Printer | DataFlex 6530(53mm) - Continuous | Same |
| Workspace | 12 × 18 mm | Same |
| DataMatrix | 22X22, ModuleSize 42, BcH 924, QuietMargin 0 | Same |
| Barcode field name | C4 | Field00 |
| Segment sources | C1, GTIN2, C3, PRODUCT_DATE, C2, SN, C5, BOX_COUNTER | C1, GTIN2, C3, PRODUCT_DATE, C2, SN |

Only the barcode is printed. Helper fields have Displayed=0; their existing
outside-workspace coordinates are editing placement, not a recipe layout to
copy into every generated template.

Both files have SN MaxNoOfChars=12 but Default and UserEnterData contain ten
zeros. This resolves the apparent discrepancy in the request: initial value
length 10 and maximum length 12 are separate properties. Both have FixedLen.
Party.ciff stores a resolved SN CalcData of ten zeros followed by two spaces;
Party1.ciff retains an unpadded older value. Current production resolution pads
dynamic FixedLen values with spaces when PadChar is absent.

GTIN2 is FixedText with Static=0, VarText, FixedLen, MaxNoOfChars=14 and 14 zeros.
PRODUCT_DATE is FixedText with Static=0, VarText, FixedLen, MaxNoOfChars=6 and six
zeros; Pitch=3 and XMag=108. SN has Pitch=3, XMag=75, LoggedField and the mask
`0-9,A-Z,a-z`. BOX_COUNTER is operator-entered FixedText, not CounterText:
Static=0, VarText, FixedLen, MaxNoOfChars=5, five zeros, Pitch=3, XMag=100,
LoggedField and no Ln tag.

The source calls the final `21` helper C5 because its barcode is already named
C4. The requested new recipe calls that helper C4. New generation must choose
an independent barcode name such as Field00; imported files must not be renamed
automatically. Source C5 has maximum length 2, Static=0 and VarText. The requested
new fixed C4 value is `21`; source C1/C2/C3 are static with values ~101/10/11 and
maxima 4/2/7 respectively.

The standard marking compositions must remain independent: their C2/C3/C4
values and SN maxima differ from this batch-code recipe. The new core exposes
`getPartyCodeComposition(withBoxCounter)` and infers an existing field's party
composition from GTIN2 + PRODUCT_DATE + SN sources. Changing symbol size or
applying a symbol profile preserves these source segments and existing helper
parameters, including source C5. Runtime regression checks are in
`tests/party-dm-profile.test.cjs`.
