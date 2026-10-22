param([ValidateSet('web','exe')][string]$Mode)
$ErrorActionPreference='Stop'
Add-Type -Path (Join-Path $PSScriptRoot 'NativeSavedFile.cs') -ReferencedAssemblies System.Drawing
$path=Join-Path $PSScriptRoot ('native-'+$Mode+'/comparison-input.json')
$inputRows=[IO.File]::ReadAllText($path,[Text.Encoding]::UTF8)|ConvertFrom-Json
$rows=@()
foreach($row in $inputRows){
 $native=Join-Path $PSScriptRoot $row.nativeBitmap
 $reference=Join-Path $PSScriptRoot $row.referenceBitmap
 $comparison=[NativeSavedFile]::Compare($native,$reference,[int]$row.orientation)
 $captured=Join-Path $PSScriptRoot $row.capturedBitmap
 $capturedComparison=[NativeSavedFile]::Compare($native,$captured,[int]$row.orientation)
 $rows+=@{name=$row.name;payload=$row.payload;clockAdvanced=$row.clockAdvanced;referenceKind=$row.referenceKind;comparison=$comparison;capturedSnapshotComparison=$capturedComparison;nativeInkBounds=[NativeSavedFile]::Ink($native);glyphUnrotatedInkBounds=[NativeSavedFile]::Ink($reference)}
}
[IO.File]::WriteAllText((Join-Path $PSScriptRoot ('native-'+$Mode+'/bitmap-comparison.json')),($rows|ConvertTo-Json -Depth 10),[Text.UTF8Encoding]::new($false))
Write-Output ('Compared {0} {1} native printer bitmaps; mismatching cases={2}' -f $Mode,$rows.Count,@($rows|Where-Object{$_.comparison.different -ne 0}).Count)
