$ErrorActionPreference = 'Stop'
Add-Type -Path (Join-Path $PSScriptRoot 'CiffNative.cs')
$document = [CiffNative]::Create()
$image = [CiffNative]::AddSubImage($document, '1', 'Default', 1600, 1600, 0)
try {
    foreach ($type in 0,1,2) {
        $field = [CiffNative]::AddField($image,$type,"Field$type",0)
        $data = [CiffNative]::GetPointer($field,0x5c)
        $object = [CiffNative]::AddData($data,0,0,$true,$false)
        [CiffNative]::SetString($object,0x5c,'DefaultText')
        [CiffNative]::SetString($field,0x9c,'DefaultText')
        [CiffNative]::Release($object)
        [CiffNative]::Release($data)
        [CiffNative]::Release($field)
    }
    [CiffNative]::GetString($document,0x38)
} finally {
    [CiffNative]::Release($image)
    [CiffNative]::Release($document)
}
