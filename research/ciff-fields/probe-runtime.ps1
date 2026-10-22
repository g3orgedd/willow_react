$ErrorActionPreference = 'Stop'
Add-Type -Path (Join-Path $PSScriptRoot 'CiffNative.cs')
$types = (Get-Content -LiteralPath (Join-Path $PSScriptRoot 'metadata/CiffHelper.dll.typelib.json') -Raw | ConvertFrom-Json).types
$interface = $types | Where-Object name -eq 'ICiffDataHelper'
$helper = [CiffNative]::CreateClass('E86E92C2-C9C2-11D4-A996-00010212D541',$interface.guid)
$document=[CiffNative]::Create()
$image=[CiffNative]::AddSubImage($document,'1','Default',1600,1600,0)
$field=[CiffNative]::AddField($image,0,'Field00',0)
$data=[CiffNative]::GetPointer($field,0x5c)
$object=[CiffNative]::AddData($data,0,0,$true,$false)
try {
    [CiffNative]::SetString($object,0x5c,'Example')
    [CiffNative]::ResolveData($helper,$object,$document)
    [PSCustomObject]@{CurrentDataValue=[CiffNative]::GetString($object,0x60)} | ConvertTo-Json
} finally {
    foreach($pointer in $object,$data,$field,$image,$document,$helper) { [CiffNative]::Release($pointer) }
}
