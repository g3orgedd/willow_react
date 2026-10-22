param(
  [string]$CiffFile = (Join-Path $PSScriptRoot 'glyph-font-check.ciff'),
  [string]$ExpectedFile = (Join-Path $PSScriptRoot 'expected.json')
)
$ErrorActionPreference = 'Stop'
$startedUtc = [DateTime]::UtcNow.ToString('o')
if ([IntPtr]::Size -ne 4) { throw 'Use C:/Windows/SysWOW64/WindowsPowerShell/v1.0/powershell.exe.' }
$researchRoot = Split-Path (Split-Path $PSScriptRoot -Parent) -Parent
Add-Type -Path (Join-Path $researchRoot 'ciff-fields/CiffNative.cs')
Add-Type -Path (Join-Path $researchRoot 'ciff-fields/CiffPrinterNative.cs')
Add-Type -Path (Join-Path (Split-Path $PSScriptRoot -Parent) 'FontOracle.cs') -ReferencedAssemblies System.Drawing
Add-Type -Path (Join-Path $PSScriptRoot 'NativeSavedFile.cs') -ReferencedAssemblies System.Drawing

function Read-TextField([IntPtr]$field) {
  return [ordered]@{
    name = [CiffNative]::GetString($field, 0x1c)
    x = [CiffNative]::GetInt($field, 0x2c)
    y = [CiffNative]::GetInt($field, 0x34)
    width = [CiffNative]::GetInt($field, 0x78)
    height = [CiffNative]::GetInt($field, 0x80)
    orientation = [CiffNative]::GetInt($field, 0x3c)
    text = [CiffNative]::GetString($field, 0x98)
    face = [CiffNative]::GetString($field, 0xa8)
    pitch = [CiffNative]::GetInt($field, 0xb0)
    xMag = [CiffNative]::GetInt($field, 0xb8)
    bold = [CiffNative]::GetInt($field, 0xc0)
    italic = [CiffNative]::GetInt($field, 0xc8)
    family = [CiffNative]::GetInt($field, 0xfc)
    yMag = [CiffNative]::GetInt($field, 0x11c)
    ttSize = [CiffNative]::GetInt($field, 0x124)
    txtDir = [CiffNative]::GetInt($field, 0x134)
    charSpace = [CiffNative]::GetInt($field, 0x150)
    pitchResolution = [CiffNative]::GetInt($field, 0x168)
  }
}

$expected = if (Test-Path -LiteralPath $ExpectedFile) { [IO.File]::ReadAllText((Resolve-Path -LiteralPath $ExpectedFile).Path,[Text.Encoding]::UTF8) | ConvertFrom-Json } else { $null }
$capsManager = [IntPtr]::Zero
$capsFile = [IntPtr]::Zero
$coders = [IntPtr]::Zero
$caps = [IntPtr]::Zero
$component = [IntPtr]::Zero
$document = [IntPtr]::Zero
$rows = @()
try {
  $document = [NativeSavedFile]::Load((Resolve-Path -LiteralPath $CiffFile).Path)
  $designedFor = [CiffNative]::GetString($document, 0x44)
  $capabilityPath = Join-Path $researchRoot 'ciff-fields/printer-oracle/embedded-capabilities.xml'
  [xml]$capabilityXml = [IO.File]::ReadAllText($capabilityPath)
  $mapping = @($capabilityXml.CapabilitiesFile.Configurations.Mappings.Map | Where-Object { $_.DisplayName -eq $designedFor })
  if ($mapping.Count -ne 1) { throw "Unknown or ambiguous printer mapping for '$designedFor'." }
  $coderName = $mapping[0].CoderName
  $capsManager = [CiffNative]::CreateClass('C1941838-7450-4EC5-8933-14250C9F11AB','6E14FCF0-1792-4CC3-A8DF-096B6FCCFD75')
  $capsFile = [CiffNative]::GetPointer($capsManager,0x1c)
  [CiffNative]::SetString($capsFile,0x28,$capabilityPath)
  $coders = [CiffPrinterNative]::GetObject($capsFile,0x3c)
  $caps = [CiffPrinterNative]::GetNamedObject($coders,0x30,$coderName)
  $component = [CiffNative]::CreateClass('BB0561B2-C54F-11D4-A995-00010212D541','BB0561B1-C54F-11D4-A995-00010212D541')
  for ($imageIndex = 1; $imageIndex -le [CiffNative]::GetInt($document,0x1c); $imageIndex++) {
    $image = [NativeSavedFile]::Item($document,$imageIndex)
    try {
      for ($fieldIndex = 1; $fieldIndex -le [CiffNative]::GetInt($image,0x1c); $fieldIndex++) {
        $rawField = [NativeSavedFile]::Item($image,$fieldIndex)
        $field = [IntPtr]::Zero
        try {
          try { $field = [CiffNative]::Query($rawField,'DF5AA02C-19F4-4258-90F2-8303907A2F05') }
          catch { Write-Warning ('Skipping non-text field ' + [CiffNative]::GetString($rawField,0x1c)); continue }
          $before = Read-TextField $field
          $loadedSize = [CiffPrinterNative]::CalculateSize($component,$document,$caps,$field)
          [CiffPrinterNative]::UpdateData($component,$document,$field)
          $afterUpdateData = Read-TextField $field
          $size = [CiffPrinterNative]::CalculateSize($component,$document,$caps,$field)
          $afterSize = Read-TextField $field
          $filename = 'clarisoft-' + ($before.name -replace '[^a-zA-Z0-9_.-]','_') + '.png'
          $bitmapPath = Join-Path $PSScriptRoot $filename
          [FontOracle]::Draw($component,$field,$caps,$document,$bitmapPath)
          $afterDraw = Read-TextField $field
          $reference = @($expected.fields | Where-Object { $_.name -eq $before.name }) | Select-Object -First 1
          $mismatches = @()
          if ($null -ne $reference) {
            foreach ($pair in @(@('x','x'),@('y','y'),@('w','width'),@('h','height'))) {
              if ([int]$reference.geom.($pair[0]) -ne [int]$before.($pair[1])) { $mismatches += ('loaded.' + $pair[0]) }
              if ([int]$reference.geom.($pair[0]) -ne [int]$afterDraw.($pair[1])) { $mismatches += ('drawn.' + $pair[0]) }
            }
            foreach ($key in @('face','pitch','xMag')) {
              $value = if ($null -ne $reference.$key) { $reference.$key } else { $reference.text.$key }
              if ($null -ne $value -and [string]$value -ne [string]$before.$key) { $mismatches += ('font.' + $key) }
            }
            foreach ($key in @('bold','italic')) {
              if ($null -ne $reference.$key -and [bool]$reference.$key -ne [bool]$before.$key) { $mismatches += ('font.' + $key) }
            }
            if ([int]$reference.orientation -ne [int]$before.orientation) { $mismatches += 'orientation' }
            if ($reference.previewText -ne $afterUpdateData.text) { $mismatches += 'updatedText' }
          }
          $glyphBitmap = if ($reference.bitmap) { [string]$reference.bitmap } else { 'glyph-' + $before.name + '.png' }
          if (-not [IO.Path]::IsPathRooted($glyphBitmap)) { $glyphBitmap = Join-Path $PSScriptRoot $glyphBitmap }
          $pixels = if (Test-Path -LiteralPath $glyphBitmap) { [NativeSavedFile]::Compare($bitmapPath,$glyphBitmap,[int]$before.orientation) } else { $null }
          if ($pixels -and (-not $pixels.sameDimensions -or $pixels.different -ne 0)) { $mismatches += 'pixels' }
          $rows += [ordered]@{ name=$before.name; before=$before; loadedWidthDots=$loadedSize.width; loadedHeightDots=$loadedSize.height; afterUpdateData=$afterUpdateData; afterSize=$afterSize; afterDraw=$afterDraw; widthDots=$size.width; heightDots=$size.height; bitmap=$filename; glyphBitmap=$glyphBitmap; pixels=$pixels; mismatches=@($mismatches) }
        } finally { [CiffNative]::Release($field); [CiffNative]::Release($rawField) }
      }
    } finally { [CiffNative]::Release($image) }
  }
  $xResolution = [CiffPrinterNative]::GetFloat($caps,0x2c)
  $yResolution = [CiffPrinterNative]::GetFloat($caps,0x34)
  $paths = @($rows | ForEach-Object { Join-Path $PSScriptRoot $_.bitmap })
  $xDots = @($rows | ForEach-Object { [NativeSavedFile]::PositionDot($_.before.x,$xResolution) })
  $yDots = @($rows | ForEach-Object { [NativeSavedFile]::PositionDot($_.before.y,$yResolution) })
  $layoutComparison = $null
  if ($expected.widthMm -and $expected.heightMm) {
    $layoutPath = Join-Path $PSScriptRoot 'clarisoft-layout.png'
    [NativeSavedFile]::Compose([string[]]$paths,[int[]]$xDots,[int[]]$yDots,[int][Math]::Round($expected.widthMm*100*$xResolution),[int][Math]::Round($expected.heightMm*100*$yResolution),$layoutPath)
    $glyphLayoutPath = Join-Path $PSScriptRoot 'glyph-layout.png'
    if (Test-Path -LiteralPath $glyphLayoutPath) { $layoutComparison = [NativeSavedFile]::Compare($layoutPath,$glyphLayoutPath,0) }
  }
  [IO.File]::WriteAllText((Join-Path $PSScriptRoot 'native-after-size.ciff'),[CiffNative]::GetXml($document,1,0),(New-Object Text.UnicodeEncoding($false,$true,$true)))
  $report = [ordered]@{ source=(Resolve-Path -LiteralPath $CiffFile).Path; sha256=(Get-FileHash -LiteralPath $CiffFile -Algorithm SHA256).Hash; checkStartedUtc=$startedUtc; checkFinishedUtc=[DateTime]::UtcNow.ToString('o'); nativeLoad='ICiffManager.load(filename, null validator)'; designedFor=$designedFor; coder=$coderName; xResolution=$xResolution; yResolution=$yResolution; fields=@($rows); mismatchingFields=@($rows | Where-Object { $_.mismatches.Count -gt 0 }).Count; layoutMethod='Original component Draw(ignorePosition=1), including original orientation, composited at round-float32(CIFF position*printer resolution); original Draw(ignorePosition=0) returns a cell-sized clipped bitmap, not a paper canvas.'; xDots=$xDots; yDots=$yDots; layout=$layoutComparison }
  [IO.File]::WriteAllText((Join-Path $PSScriptRoot 'native-roundtrip-report.json'),($report | ConvertTo-Json -Depth 12),[Text.UTF8Encoding]::new($false))
  $rows | ForEach-Object { [PSCustomObject]@{name=$_.name; face=$_.before.face; pitch=$_.before.pitch; xy=('{0},{1}' -f $_.before.x,$_.before.y); loadedSize=('{0}x{1}' -f $_.before.width,$_.before.height); nativeSize=('{0}x{1}' -f $_.afterDraw.width,$_.afterDraw.height); pixelDifferences=$_.pixels.different; mismatches=($_.mismatches -join ',')} } | Format-Table -AutoSize
  if ($layoutComparison) { Write-Output ('Full layout: {0}x{1}; different pixels: {2}' -f $layoutComparison.nativeWidth,$layoutComparison.nativeHeight,$layoutComparison.different) }
} finally {
  foreach ($pointer in @($document,$component,$caps,$coders,$capsFile,$capsManager)) { [CiffNative]::Release($pointer) }
}
