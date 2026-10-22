param([string]$OutputPath = $PSScriptRoot)
$ErrorActionPreference = 'Stop'
$projectRoot = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..\..\..'))
Add-Type -Path (Join-Path $projectRoot 'research\ciff-fields\CiffNative.cs')
if ([IntPtr]::Size -ne 4) { throw 'Use Windows SysWOW64 PowerShell.' }
$binary = 'C:\Program Files (x86)\CLARICOM\Data\CiffMgr.dll'
$expectedHash = 'F1A3C15E39657C5D8B2A0391660BBA2809702B5B83E368C41584ABDD2955124B'
if ((Get-FileHash -LiteralPath $binary -Algorithm SHA256).Hash -ne $expectedHash) { throw 'Unsupported DLL build.' }
$utf8 = New-Object System.Text.UTF8Encoding($false)
$utf16 = New-Object System.Text.UnicodeEncoding($false,$true,$true)
$cases = @(
    @{ name='no-subimages'; images=@() },
    @{ name='empty-subimage'; images=@(@{values=@()}) },
    @{ name='one-field'; images=@(@{values=@('alpha')}) },
    @{ name='three-fields'; images=@(@{values=@('alpha','beta','gamma')}) },
    @{ name='second-subimage-only'; images=@(@{values=@()},@{values=@('SECOND-IMAGE')}) },
    @{ name='two-subimages'; images=@(@{values=@('I1-A','I1-B')},@{values=@('I2-A','I2-B')}) },
    @{ name='thirty-three-fields'; images=@(@{values=@(0..32 | ForEach-Object { 'FieldValue{0:D2}' -f $_ })}) },
    @{ name='payload-truncate'; images=@(@{values=@('12345678901234567890TRAILING')}) },
    @{ name='control-char'; images=@(@{values=@(('AB'+[char]1+'CD'+[char]29+'EF'))}) },
    @{ name='nul-in-plaintext'; images=@(@{values=@(('AB'+[char]0+'CD'))}) },
    @{ name='surrogate-truncate'; images=@(@{values=@(('1234567890123456789'+[char]0xd83d+[char]0xde00+'TAIL'))}) },
    @{ name='mixed-field-types'; images=@(@{values=@('TEXT','BARCODE','GRAPHIC'); types=@(0,1,2)}) },
    @{ name='hidden-field'; images=@(@{values=@('HIDDEN'); hidden=$true}) }
)
$results = New-Object System.Collections.ArrayList
foreach ($case in $cases) {
    $document = [CiffNative]::Create()
    $fields = New-Object System.Collections.ArrayList
    try {
        [CiffNative]::SetString($document,0x48,'DataFlex 6320(53mm) - Continuous')
        $imageIndex = 0
        foreach ($imageSpec in $case.images) {
            $imageIndex++
            $image = [CiffNative]::AddSubImage($document,[string]$imageIndex,'Default',1600,1600,0)
            try {
                $fieldIndex = 0
                foreach ($value in $imageSpec.values) {
                    $fieldType = 0
                    if ($imageSpec.types) { $fieldType = [int]$imageSpec.types[$fieldIndex] }
                    $field = [CiffNative]::AddField($image,$fieldType,('F{0}_{1}' -f $imageIndex,$fieldIndex),0)
                    [void]$fields.Add($field)
                    [CiffNative]::SetString($field,0x9c,[string]$value)
                    if ($imageSpec.hidden) { [CiffNative]::SetInt($field,0x28,0) }
                    $fieldIndex++
                }
            } finally { [CiffNative]::Release($image) }
        }
        $before = @($fields | ForEach-Object { [CiffNative]::GetString($_,0x98) })
        $xml = [CiffNative]::GetXml($document,1,1)
        $after = @($fields | ForEach-Object { [CiffNative]::GetString($_,0x98) })
        $token = [CiffNative]::GetString($document,0x78)
        [IO.File]::WriteAllText((Join-Path $OutputPath ($case.name+'.ciff')),$xml,$utf16)
        [void]$results.Add([PSCustomObject]@{
            name=$case.name; status='ok'; subImageCount=$imageIndex; fieldCount=$fields.Count
            fieldValuesBefore=$before; fieldValuesAfter=$after; token=$token; tokenLength=$token.Length
        })
    } catch {
        [void]$results.Add([PSCustomObject]@{name=$case.name;status='error';error=$_.Exception.Message})
    } finally {
        foreach ($field in $fields) { [CiffNative]::Release($field) }
        [CiffNative]::Release($document)
    }
}
$report = [PSCustomObject]@{method='Original registered COM generator via savetostring2(UTF_16,1), no DLL patches';processBits=32;dllSha256=$expectedHash;cases=@($results)}
[IO.File]::WriteAllText((Join-Path $OutputPath 'com-results.json'),(ConvertTo-Json -InputObject $report -Depth 10),$utf8)
[PSCustomObject]@{cases=$results.Count;ok=@($results | Where-Object status -eq 'ok').Count;errors=@($results | Where-Object status -eq 'error').Count} | ConvertTo-Json
