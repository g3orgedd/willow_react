param([string]$InputFile = (Join-Path $PSScriptRoot 'native-inputs.json'))
$ErrorActionPreference='Stop'
$root=Split-Path -Parent (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))
Add-Type -Path @((Join-Path $root 'research/ciff-fields/CiffNative.cs'),(Join-Path $PSScriptRoot 'CiffClstOracle.cs'))
$inputs=Get-Content -LiteralPath $InputFile -Raw | ConvertFrom-Json
$utf16=New-Object System.Text.UnicodeEncoding($false,$true,$true)
$utf8=New-Object System.Text.UTF8Encoding($false)
$rows=New-Object System.Collections.ArrayList
foreach($case in $inputs) {
  $document=[CiffNative]::Create()
  try {
    foreach($si in $case.subImages) {
      $image=[CiffNative]::AddSubImage($document,[string]$si.reference,'Default',1600,1600,0)
      try {foreach($definition in $si.fields) {
        $field=[CiffNative]::AddField($image,[int]$definition.family,[string]$definition.name,0)
        $target=[CiffNative]::Query($field,'B2A04AE2-991E-444D-B6EB-C9171E8AB98F')
        try {
          [CiffNative]::SetString($target,0x9c,[CiffClstOracle]::FromUnits([int[]]$definition.units))
          [CiffNative]::SetInt($target,0x28,[int]$definition.displayed)
        } finally {[CiffNative]::Release($target);[CiffNative]::Release($field)}
      }} finally {[CiffNative]::Release($image)}
    }
    $before=[CiffClstOracle]::Snapshot($document)
    $xml=[CiffNative]::GetXml($document,1,1)
    $filename=Join-Path $PSScriptRoot ($case.name+'.ciff')
    [IO.File]::WriteAllText($filename,$xml,$utf16)
    $token=[CiffNative]::GetString($document,0x78)
    $validate=[CiffClstOracle]::Validate($document)
    $validate2=[CiffClstOracle]::Validate2($document)
    $after=[CiffClstOracle]::Snapshot($document)
    $positiveXml=[CiffNative]::GetXml($document,1,1)
    $positiveToken=[CiffNative]::GetString($document,0x78)
    # A corrupted token tests whether HRESULT is a meaningful ClSt verdict.
    [CiffNative]::SetString($document,0x7c,'invalid-token')
    $negativeValidate=[CiffClstOracle]::Validate($document)
    $negativeValidate2=[CiffClstOracle]::Validate2($document)
    $negativeXml=[CiffNative]::GetXml($document,1,1)
    $negativeToken=[CiffNative]::GetString($document,0x78)
    [void]$rows.Add([ordered]@{name=$case.name;status='ok';file=[IO.Path]::GetFileName($filename);nativeToken=$token;before=$before;after=$after;validate=$validate;validate2=$validate2;positiveRegeneratedToken=$positiveToken;negativeValidate=$negativeValidate;negativeValidate2=$negativeValidate2;negativeRegeneratedToken=$negativeToken;sourceSha256=[CiffClstOracle]::FileSha256($filename)})
  } catch {[void]$rows.Add([ordered]@{name=$case.name;status='error';error=$_.Exception.ToString()})}
  finally {[CiffNative]::Release($document)}
}
$report=[ordered]@{method='Installed CiffMgr COM original published methods; no UI or callbacks';processBits=([IntPtr]::Size*8);cases=@($rows)}
[IO.File]::WriteAllText((Join-Path $PSScriptRoot 'native-com-results.json'),(ConvertTo-Json -InputObject $report -Depth 20),$utf8)
[PSCustomObject]@{cases=$rows.Count;ok=@($rows|Where-Object status -eq 'ok').Count;errors=@($rows|Where-Object status -eq 'error').Count}|ConvertTo-Json
if(@($rows|Where-Object status -eq 'error').Count){exit 1}
