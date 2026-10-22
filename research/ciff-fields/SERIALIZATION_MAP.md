# Native XML writer index

Evidence index, not an executable rule engine. Conditions and error propagation remain in the cited C and assembly.

## Barcode routes

| ID | Enum | XML node | Feature mask |
|---|---|---|---|
| 0 | FSTB_ITF | ITF | `0x0031003C` |
| 1 | FSTB_CODE128 | Code128 | `0x0830001C` |
| 2 | FSTB_EAN128 | EAN128 | `0x1870005C` |
| 3 | FSTB_CODE39 | Code39 | `0x00010020` |
| 4 | FSTB_EAN8 | EAN8 | `0x00000002` |
| 5 | FSTB_EAN13 | EAN13 | `0x00000002` |
| 6 | FSTB_UPCA | UPCA | `0x00000002` |
| 7 | FSTB_UPCE | UPCE | `0x00000002` |
| 8 | FSTB_SUP2DIGIT | Sup2DigitCode | `0x00000001` |
| 9 | FSTB_SUP5DIGIT | Sup5DigitCode | `0x00000001` |
| 10 | FSTB_RSS14 | RSS14 | `0x00000000` |
| 11 | FSTB_RSS14TRUNC | RSS14Truncated | `0x00000000` |
| 12 | FSTB_RSS14STACKED | RSS14Stacked | `0x00000000` |
| 13 | FSTB_RSS14STACKEDOMNI | RSS14StackedOmni | `0x00000000` |
| 14 | FSTB_RSSLIMITED | RSSLimited | `0x00000000` |
| 15 | FSTB_DATAMATRIXECC200 | DataMatrix | `0x00000380` |
| 16 | FSTB_PDF417 | PDF417 | `0x00007D00` |
| 17 | FSTB_MICROPDF417 | MicroPDF417 | `0x0000CD00` |
| 18 | FSTB_QR | QR | `0x200E0100` |
| 19 | FSTB_RSSEXPANDED | RSSExpanded | `0x00000000` |
| 20 | FSTB_RSSEXPANDEDSTACKED | RSSExpandedStacked | `0x00000800` |
| 21 | FSTB_MAXICODE | MaxiCode | `0x07000020` |
| 22 | FSTB_PLANET | Planet | `0x00000020` |
| 23 | FSTB_POSTNET | Postnet | `0x00000020` |
| 24 | FSTB_PLANT | Plant | `0x00000020` |
| 25 | FSTB_USPSIMB | UspsImb | `0x00000020` |
| 26 | FSTB_CODE93 | Code93 | `0x00000020` |

## 6810248f

[C source](decompiled/CiffMgr.dll/FUN_6810248f.c)

| Line | Operation | Node |
|---|---|---|
| 17 | text element with returned node | (dynamic table) |

## 68124548

[C source](decompiled/CiffMgr.dll/FUN_68124548.c)

| Line | Operation | Node |
|---|---|---|
| 35 | child container | AvoidanceDates |
| 45 | child container | AvoidanceDate |
| 61 | attribute | Day |
| 75 | attribute | Month |

## 681247de

[C source](decompiled/CiffMgr.dll/FUN_681247de.c)

| Line | Operation | Node |
|---|---|---|
| 36 | child container | CalendarRules |
| 46 | child container | CalendarRule |
| 62 | attribute | Day |
| 77 | attribute | Month |
| 92 | attribute | Offset |

## 68124afe

[C source](decompiled/CiffMgr.dll/FUN_68124afe.c)

| Line | Operation | Node |
|---|---|---|
| 28 | text element | Mag |
| 37 | text element | MagRnd |
| 46 | text element | BcH |
| 50 | child container | HR |
| 62 | text element | CheckDigit |
| 68 | text element | QuietMargin |
| 74 | text element | XOffSet |
| 83 | text element | BarcodePrinting |
| 94 | child container | * |

## 68124e3d

[C source](decompiled/CiffMgr.dll/FUN_68124e3d.c)

| Line | Operation | Node |
|---|---|---|
| 45 | attribute | ParentField |
| 64 | text element | GuardBars |
| 75 | text element | BearerBars |
| 86 | text element | BearerBox |
| 97 | text element | HGauge |
| 108 | text element | ThickThinRatio |
| 119 | text element | IntelligentEan128 |
| 130 | text element | ECCType |
| 145 | text element | ModuleSize |
| 160 | text element | SymbolSize |
| 175 | text element | RowHeight |
| 189 | text element | Columns |
| 203 | text element | Rows |
| 226 | attribute | Pad |
| 260 | text element | ErrorCorrection |
| 276 | text element | Type |
| 291 | text element | Encoding |
| 307 | text element | HRStyle |
| 324 | text element | QRVersion |
| 342 | text element | QRErrorLevel |
| 360 | text element | QRMirror |
| 380 | text element | BearerSize |
| 401 | text element | QMSize |
| 418 | text element | LegacyC128Enc |
| 436 | text element | ManualCode128Encoding |
| 454 | text element | CorrectCheckDigit |
| 472 | text element | Mode |
| 491 | text element | Symbol |
| 510 | text element | SymbolCount |
| 530 | text element | BarcodeDataFormat |

## 68125c42

[C source](decompiled/CiffMgr.dll/FUN_68125c42.c)

| Line | Operation | Node |
|---|---|---|
| 39 | attribute | Compatibility |
| 54 | text element | BlkW |
| 59 | text element | BlkH |
| 64 | text element | MinFontSize |
| 70 | text element | BlkJustify |
| 76 | text element | Hyphenation |

## 68125e4d

[C source](decompiled/CiffMgr.dll/FUN_68125e4d.c)

| Line | Operation | Node |
|---|---|---|
| 30 | attribute | Left |
| 37 | attribute | Top |
| 44 | attribute | Right |
| 51 | attribute | Bottom |

## 68126015

[C source](decompiled/CiffMgr.dll/FUN_68126015.c)

| Line | Operation | Node |
|---|---|---|
| 60 | child container | Rect |

## 681261df

[C source](decompiled/CiffMgr.dll/FUN_681261df.c)

| Line | Operation | Node |
|---|---|---|
| 34 | text element | Rollover |
| 41 | text element | PrnPerCnt |
| 48 | text element | ResetOnSel |
| 55 | text element | ParentCounter |
| 68 | text element | RolloverError |
| 74 | text element | PromptWith |
| 85 | text element | ResetSource |
| 107 | child container | SubCnt |

## 68126560

[C source](decompiled/CiffMgr.dll/FUN_68126560.c)

| Line | Operation | Node |
|---|---|---|
| 48 | attribute | Index |
| 58 | attribute | Static |
| 68 | attribute | Parse |
| 78 | attribute | EqRef |
| 90 | attribute | Param |
| 105 | attribute | Reference |
| 133 | text element | DataType |
| 141 | text element | Locale |
| 154 | text element | Calendar |
| 163 | text element | Encryption |
| 176 | text element | MaxNoOfChars |
| 185 | CDATA element | Default |
| 199 | child container | FixedLen |
| 205 | CDATA element | PadChar |
| 211 | text element | PadMode |
| 232 | child container | PriceData |
| 245 | attribute | SrcPrice |
| 282 | CDATA element | HigherFmt |
| 287 | CDATA element | LowerFmt |
| 291 | text element | SwitchVal |
| 326 | child container | Checksum |
| 342 | attribute | Pos |
| 349 | CDATA element | Type |
| 374 | child container | SrcField |
| 384 | child container | SrcData |
| 394 | child container | VarText |
| 404 | child container | OffsetDate |
| 415 | child container | CounterText |
| 429 | child container | CLARICOMSSCC |

## 6812708a

[C source](decompiled/CiffMgr.dll/FUN_6812708a.c)

| Line | Operation | Node |
|---|---|---|
| 60 | child container | Object |

## 68127254

[C source](decompiled/CiffMgr.dll/FUN_68127254.c)

| Line | Operation | Node |
|---|---|---|
| 41 | attribute | DataSourceName |
| 47 | attribute | DataSourceTable |
| 54 | attribute | DataSourceIndex |

## 68127437

[C source](decompiled/CiffMgr.dll/FUN_68127437.c)

| Line | Operation | Node |
|---|---|---|
| 60 | child container | DataSource |

## 68127601

[C source](decompiled/CiffMgr.dll/FUN_68127601.c)

| Line | Operation | Node |
|---|---|---|
| 49 | attribute | Name |
| 57 | attribute | StaticDate |
| 67 | attribute | AutoUpdate |
| 77 | attribute | Type |
| 115 | child container | DefaultOffset |
| 121 | text element | Seconds |
| 127 | text element | Day |
| 133 | text element | Month |
| 138 | text element | Year |
| 150 | child container | SourceOffset |
| 159 | CDATA element | ConnStr |
| 166 | CDATA element | DateSQL |
| 172 | CDATA element | DateMask |
| 190 | text element | RndMode |
| 196 | text element | RndType |
| 202 | text element | RndDay |
| 209 | CDATA element | Prompt |
| 217 | text element | ResetOnSel |
| 240 | child container | CurrentOffset |
| 245 | text element | Seconds |
| 250 | text element | Day |
| 255 | text element | Month |
| 259 | text element | Year |
| 283 | text element | CurrentDate |
| 290 | CDATA element | RefDate |
| 298 | text element | CalcAtCoder |
| 311 | child container | MinOffset |
| 325 | attribute | Used |
| 337 | text element | Seconds |
| 342 | text element | Day |
| 347 | text element | Month |
| 351 | text element | Year |
| 372 | child container | MaxOffset |
| 386 | attribute | Used |
| 398 | text element | Seconds |
| 403 | text element | Day |
| 408 | text element | Month |
| 412 | text element | Year |

## 681282c3

[C source](decompiled/CiffMgr.dll/FUN_681282c3.c)

| Line | Operation | Node |
|---|---|---|
| 60 | child container | DateOffset |

## 6812848d

[C source](decompiled/CiffMgr.dll/FUN_6812848d.c)

| Line | Operation | Node |
|---|---|---|
| 40 | attribute | Name |
| 48 | attribute | Size |
| 55 | attribute | Type |
| 80 | attribute | CompType |

## 68128755

[C source](decompiled/CiffMgr.dll/FUN_68128755.c)

| Line | Operation | Node |
|---|---|---|
| 60 | child container | File |

## 68128924

[C source](decompiled/CiffMgr.dll/FUN_68128924.c)

| Line | Operation | Node |
|---|---|---|
| 44 | attribute | Name |
| 59 | attribute | TXField |
| 78 | text element | FldType |
| 88 | text element | CLSID |
| 96 | text element | Displayed |
| 101 | text element | X |
| 106 | text element | Y |
| 111 | text element | W |
| 116 | text element | H |
| 122 | text element | Ln |
| 129 | text element | Orientation |
| 136 | text element | OverrideThis |
| 144 | text element | Inverse |
| 151 | text element | Mirror |
| 159 | text element | RenderMode |
| 171 | CDATA element | CalcData |
| 185 | text element | LoggedField |
| 198 | text element | Origin |
| 214 | text element | MarkSet |
| 231 | child container | Data |
| 256 | child container | Clip |
| 278 | child container | Text |
| 300 | child container | Barcode |
| 320 | child container | Graphic |

## 6812932f

[C source](decompiled/CiffMgr.dll/FUN_6812932f.c)

| Line | Operation | Node |
|---|---|---|
| 26 | text element | ImageQuality |
| 33 | text element | SelectAfterDownload |

## 68129475

[C source](decompiled/CiffMgr.dll/FUN_68129475.c)

| Line | Operation | Node |
|---|---|---|
| 39 | text element | GfxW |
| 43 | text element | GfxH |
| 54 | child container | (dynamic table) |
| 61 | text element | AspectRatio |
| 69 | text element | ResizeFrame |
| 80 | text element | LogoReferencePrinter |
| 97 | child container | Primitive |
| 103 | text element | Shape |
| 109 | text element | LineW |
| 118 | child container | ComplexShape |
| 137 | child container | Point |
| 150 | attribute | ID |
| 158 | attribute | X |
| 165 | attribute | Y |

## 681299bb

[C source](decompiled/CiffMgr.dll/FUN_681299bb.c)

| Line | Operation | Node |
|---|---|---|
| 28 | CDATA element | Face |
| 36 | text element | Family |
| 42 | text element | Pitch |
| 48 | text element | XMag |
| 55 | text element | YMag |
| 62 | text element | TTSize |
| 71 | text element | TxtDir |

## 68129bfc

[C source](decompiled/CiffMgr.dll/FUN_68129bfc.c)

| Line | Operation | Node |
|---|---|---|
| 43 | attribute | DesignedFor |
| 53 | attribute | DesignedWith |
| 62 | attribute | OverrideAll |
| 79 | text element | Units |
| 85 | text element | ErrorLeniency |
| 92 | text element | ClStVersionInfo |
| 100 | text element | LastDownloaded |
| 109 | text element | LineID |

## 6812a184

[C source](decompiled/CiffMgr.dll/FUN_6812a184.c)

| Line | Operation | Node |
|---|---|---|
| 26 | text element | HRDisplayed |
| 32 | text element | HRPos |
| 37 | child container | HRFont |
| 52 | text element | HRPrintCheckDigit |

## 6812a2da

[C source](decompiled/CiffMgr.dll/FUN_6812a2da.c)

| Line | Operation | Node |
|---|---|---|
| 34 | attribute | SubIMageRef |

## 6812a3fb

[C source](decompiled/CiffMgr.dll/FUN_6812a3fb.c)

| Line | Operation | Node |
|---|---|---|
| 56 | attribute | PrintHeadDigits |
| 101 | child container | Map |

## 6812a724

[C source](decompiled/CiffMgr.dll/FUN_6812a724.c)

| Line | Operation | Node |
|---|---|---|
| 29 | attribute | SrcOffset |

## 6812a7d3

[C source](decompiled/CiffMgr.dll/FUN_6812a7d3.c)

| Line | Operation | Node |
|---|---|---|
| 41 | attribute | Name |
| 48 | attribute | Type |
| 63 | attribute | Database |
| 73 | attribute | DataSource |

## 6812ab09

[C source](decompiled/CiffMgr.dll/FUN_6812ab09.c)

| Line | Operation | Node |
|---|---|---|
| 45 | attribute | Name |
| 90 | child container | Param |

## 6812adb8

[C source](decompiled/CiffMgr.dll/FUN_6812adb8.c)

| Line | Operation | Node |
|---|---|---|
| 63 | child container | ParamSet |

## 6812b048

[C source](decompiled/CiffMgr.dll/FUN_6812b048.c)

| Line | Operation | Node |
|---|---|---|
| 61 | attribute | Name |
| 70 | attribute | Type |
| 87 | child container | Min |
| 100 | attribute | Used |
| 139 | child container | Max |
| 152 | attribute | Used |
| 188 | text element | Current |
| 193 | text element | Default |
| 198 | text element | DecimalPlaces |
| 204 | CDATA element | Prompt |
| 209 | text element | ResetOnSel |
| 216 | text element | SrcField |
| 221 | text element | SQLUsed |
| 228 | text element | PriceSQL |
| 236 | text element | ConnStr |

## 6812b61a

[C source](decompiled/CiffMgr.dll/FUN_6812b61a.c)

| Line | Operation | Node |
|---|---|---|
| 60 | child container | Price |

## 6812b7e4

[C source](decompiled/CiffMgr.dll/FUN_6812b7e4.c)

| Line | Operation | Node |
|---|---|---|
| 25 | CDATA element | ConnStr |
| 32 | CDATA element | SrcSQL |
| 40 | text element | StartChar |
| 46 | text element | NoOfChars |
| 56 | text element | SelectMode |

## 6812b98e

[C source](decompiled/CiffMgr.dll/FUN_6812b98e.c)

| Line | Operation | Node |
|---|---|---|
| 34 | attribute | SrcFieldName |
| 46 | text element | StartChar |
| 52 | text element | NoOfChars |
| 62 | text element | SelectMode |

## 6812bb40

[C source](decompiled/CiffMgr.dll/FUN_6812bb40.c)

| Line | Operation | Node |
|---|---|---|
| 41 | attribute | Significance |
| 49 | attribute | AlphaNum |
| 57 | attribute | LeadChar |
| 68 | attribute | Global |
| 87 | text element | NoOfChars |
| 93 | text element | LeadingChars |
| 102 | CDATA element | StartVal |
| 114 | CDATA element | EndVal |
| 124 | text element | StepSize |
| 133 | CDATA element | CurrVal |
| 145 | CDATA element | IncableChars |
| 157 | CDATA element | Prompt |
| 167 | text element | ClrStCntType |

## 6812bfec

[C source](decompiled/CiffMgr.dll/FUN_6812bfec.c)

| Line | Operation | Node |
|---|---|---|
| 44 | attribute | ImageReference |
| 56 | child container | SubHeader |
| 100 | child container | Field |

## 6812c2ca

[C source](decompiled/CiffMgr.dll/FUN_6812c2ca.c)

| Line | Operation | Node |
|---|---|---|
| 44 | attribute | FormatName |
| 57 | attribute | PrinterType |
| 73 | attribute | PrinterFormatName |
| 88 | text element | ImageWidth |
| 92 | text element | ImageHeight |
| 105 | text element with returned node | ImageRotation |
| 117 | attribute | Enabled |
| 137 | text element | MaxImageWidth |
| 141 | text element | MaxImageHeight |
| 149 | text element | AutoSize |
| 167 | text element with returned node | ImageMirror |
| 179 | attribute | Enabled |
| 204 | text element | ImageInverse |
| 214 | text element | XRes |
| 220 | text element | YRes |
| 229 | text element | CurrentOrientation |
| 240 | text element | LastUpdated |

## 6812cad1

[C source](decompiled/CiffMgr.dll/FUN_6812cad1.c)

| Line | Operation | Node |
|---|---|---|
| 65 | child container | SubImage |

## 6812ccce

[C source](decompiled/CiffMgr.dll/FUN_6812ccce.c)

| Line | Operation | Node |
|---|---|---|
| 38 | child container | Font |
| 45 | child container | Bold |
| 61 | attribute | Weight |
| 98 | text element | Italic |
| 104 | text element | DblSpace |
| 111 | child container | Block |
| 134 | text element | Escapement |
| 144 | child container | FixedWidth |
| 148 | text element | Width |
| 152 | text element | Align |
| 168 | text element | MultiStroke |

## 6812d1de

[C source](decompiled/CiffMgr.dll/FUN_6812d1de.c)

| Line | Operation | Node |
|---|---|---|
| 28 | CDATA element | Face |
| 36 | text element | Family |
| 42 | text element | Pitch |
| 51 | text element | PitchResolution |
| 61 | text element | XMag |
| 68 | text element | YMag |
| 75 | text element | TTSize |
| 84 | text element | TxtDir |
| 97 | text element | CharSpace |

## 6812d4ec

[C source](decompiled/CiffMgr.dll/FUN_6812d4ec.c)

| Line | Operation | Node |
|---|---|---|
| 96 | attribute | ID |

## 6812d7a8

[C source](decompiled/CiffMgr.dll/FUN_6812d7a8.c)

| Line | Operation | Node |
|---|---|---|
| 37 | CDATA element | Prompt |
| 45 | CDATA element | Mask |
| 54 | CDATA element | UserEnterData |
| 63 | text element | PromptAtCoder |
| 70 | text element | ResetOnSel |
| 120 | attribute | Mask |
| 137 | text element | ConnStr |
| 146 | text element | SourceSQL |

## 6812dc1c

[C source](decompiled/CiffMgr.dll/FUN_6812dc1c.c)

| Line | Operation | Node |
|---|---|---|
| 39 | attribute | Version |
| 52 | attribute | InternalName |
| 58 | attribute | xml:space |
| 68 | attribute | Temporary |
| 85 | child container | Header |
| 106 | child container | GenericSettings |
| 138 | child container | Embedded |
