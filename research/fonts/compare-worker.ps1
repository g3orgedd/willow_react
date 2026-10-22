param([string]$Manifest = 'worker-comparison-manifest.json', [string]$Report = 'worker-oracle-comparison.json')
$ErrorActionPreference = 'Stop'
Add-Type -AssemblyName System.Drawing
$rows = Get-Content -Raw -LiteralPath (Join-Path $PSScriptRoot $Manifest) | ConvertFrom-Json
$output = @()
foreach ($row in $rows) {
    $reference = [Drawing.Bitmap]::new((Join-Path $PSScriptRoot $row.reference))
    $candidate = [Drawing.Bitmap]::new((Join-Path $PSScriptRoot $row.candidate))
    try {
        $different = -1
        if ($reference.Width -eq $candidate.Width -and $reference.Height -eq $candidate.Height) {
            $different = 0
            for ($y = 0; $y -lt $reference.Height; $y++) {
                for ($x = 0; $x -lt $reference.Width; $x++) {
                    if (($reference.GetPixel($x,$y).R -lt 128) -ne ($candidate.GetPixel($x,$y).A -ge 128)) { $different++ }
                }
            }
        }
        $output += @{face=$row.face; pitch=$row.pitch; variant=$row.variant; width=$candidate.Width; height=$candidate.Height; different=$different; pixels=$reference.Width*$reference.Height}
    } finally { $reference.Dispose(); $candidate.Dispose() }
}
$json = ConvertTo-Json -InputObject @($output) -Depth 4
[IO.File]::WriteAllText((Join-Path $PSScriptRoot $Report),$json,[Text.UTF8Encoding]::new($false))
$failures = @($output | Where-Object { $_.different -ne 0 })
Write-Output ("Compared {0} native ClariSoft bitmaps: {1} differences." -f $output.Count,$failures.Count)
if ($failures.Count -gt 0) { throw 'Native font bitmap comparison failed.' }
