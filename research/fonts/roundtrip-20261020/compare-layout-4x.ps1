$ErrorActionPreference='Stop'
Add-Type -Path (Join-Path $PSScriptRoot 'NativeSavedFile.cs') -ReferencedAssemblies System.Drawing
$report=[IO.File]::ReadAllText((Join-Path $PSScriptRoot 'native-roundtrip-report.json'))|ConvertFrom-Json
$expected=[IO.File]::ReadAllText((Join-Path $PSScriptRoot 'expected.json'))|ConvertFrom-Json
$paths=@($report.fields|ForEach-Object{Join-Path $PSScriptRoot $_.bitmap})
$width=[int][Math]::Round($expected.widthMm*100*$report.xResolution)
$height=[int][Math]::Round($expected.heightMm*100*$report.yResolution)
$nativePath=Join-Path $PSScriptRoot 'clarisoft-layout-4x.png'
[NativeSavedFile]::ComposeScaled([string[]]$paths,[int[]]$report.xDots,[int[]]$report.yDots,$width,$height,4,$nativePath)
$comparison=[NativeSavedFile]::Compare($nativePath,(Join-Path $PSScriptRoot 'glyph-layout-4x.png'),0)
$json=$comparison|ConvertTo-Json -Depth 4
[IO.File]::WriteAllText((Join-Path $PSScriptRoot 'layout-4x-comparison.json'),$json,[Text.UTF8Encoding]::new($false))
$json
