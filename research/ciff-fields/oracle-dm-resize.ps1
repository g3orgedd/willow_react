$ErrorActionPreference = 'Stop'
Add-Type -Path (Join-Path $PSScriptRoot 'CiffNative.cs')
$library=(Get-Content -LiteralPath (Join-Path $PSScriptRoot 'metadata/CLCSSmallBarcode.dll.typelib.json') -Raw | ConvertFrom-Json)
$class=$library.types | Where-Object {$_.kind -eq 5 -and ($_.implements | Where-Object name -eq 'ICLCSGenericFieldObj')} | Select-Object -First 1
$plugin=[CiffNative]::CreateClass($class.guid,'BB0561B1-C54F-11D4-A995-00010212D541')
$results=New-Object System.Collections.ArrayList
try {
    foreach($quiet in 0,1) {
        foreach($width in 1100,1000,500) {
            $document=[CiffNative]::Create()
            $image=[CiffNative]::AddSubImage($document,'1','Default',1600,1600,0)
            $field=[CiffNative]::AddField($image,1,'DM',15)
            try {
                [CiffNative]::SetInt($field,0x168,6)
                [CiffNative]::SetInt($field,0x10c,$quiet)
                [CiffNative]::ResizeDataMatrix($document,$field,$width,$width,0.12,0.12)
                [void]$results.Add([PSCustomObject]@{requestedWidth=$width;requestedHeight=$width;quietMargins=$quiet;symbolSizeIndex=6;xRes=0.12;yRes=0.12;moduleSize=[CiffNative]::GetInt($field,0x15c);width=[CiffNative]::GetInt($field,0x78);height=[CiffNative]::GetInt($field,0x80);bcH=[CiffNative]::GetInt($field,0xb8)})
            } finally { foreach($pointer in $field,$image,$document) {[CiffNative]::Release($pointer)} }
        }
    }
} finally {[CiffNative]::Release($plugin)}
$report=[PSCustomObject]@{source='Original CLCSSmallBarcode.dll routine 4204a286';capabilitySource='Explicit test stub for XRes/YRes, not an actual printer profile';cases=@($results)}
[IO.File]::WriteAllText((Join-Path $PSScriptRoot 'dm-resize-results.json'),(ConvertTo-Json -InputObject $report -Depth 8),(New-Object System.Text.UTF8Encoding($false)))
$results | Format-Table
