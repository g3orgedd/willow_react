param([ValidateSet('web','exe')][string]$Mode)
$ErrorActionPreference = 'Stop'
Add-Type -AssemblyName System.Drawing
$expected = Get-Content (Join-Path $PSScriptRoot ('expected-' + $Mode + '.json')) -Raw | ConvertFrom-Json
$rows = @()
foreach ($field in $expected.fields) {
    $image = [Drawing.Bitmap]::FromFile((Join-Path $PSScriptRoot $field.bitmap))
    try {
        $left = $image.Width; $top = $image.Height; $right = 0; $bottom = 0; $count = 0
        for ($y = 0; $y -lt $image.Height; $y++) {
            for ($x = 0; $x -lt $image.Width; $x++) {
                $color = $image.GetPixel($x, $y)
                if ($color.A -gt 0 -and $color.R -lt 128 -and $color.G -lt 128 -and $color.B -lt 128) {
                    $left = [Math]::Min($left, $x); $top = [Math]::Min($top, $y)
                    $right = [Math]::Max($right, $x + 1); $bottom = [Math]::Max($bottom, $y + 1); $count++
                }
            }
        }
        $rows += [ordered]@{name=$field.name; left=$left; top=$top; right=$right; bottom=$bottom; blackPixels=$count}
    } finally { $image.Dispose() }
}
[Console]::OutputEncoding = [Text.UTF8Encoding]::new($false)
ConvertTo-Json -InputObject @($rows) -Compress
