# Ordered CIFF comparison fixtures

These files are immutable byte-for-byte copies supplied for structural comparison.

| Fixture | Original source | SHA-256 |
| --- | --- | --- |
| `Clarisoft_test_1.ciff` | `C:\Users\GigaGeorge\Desktop\VJ test templates\Clarisoft_test_1.ciff` | `5221DC212883631146E4D26E2BB5AF3D38E440D0EA458C73BF4B18E5175BB63D` |
| `Glyph_test_1.ciff` | `C:\Users\GigaGeorge\Desktop\VJ test templates\Glyph_test_1.ciff` | `112420E4053C789F591EFD3AD44BAB9AC7EB76F1E477E14DF4AB5BDA5E1FDC52` |
| `clarisoft_fix6.reference.xml` | UTF-8 decoded mirror of supplied `clarisoft_fix6.ciff`; tests reconstruct the original UTF-16LE envelope | `61CDFB349E15D3B95F5828B2EAAA1F7A200C70CECF50C47A74DC613CFD6C16F1` |

Run the diagnostic comparator with:

```powershell
node scripts/compare-ciff-structure.cjs `
  tests/fixtures/clarisoft/Clarisoft_test_1.ciff `
  tests/fixtures/clarisoft/Glyph_test_1.ciff
```

Use `--json` for machine-readable output or `--fail-on-diff` when equality is required.

Generate the equivalent Glyph template and its comparison report with:

```powershell
node scripts/generate-glyph-clarisoft-fix6.cjs
```
