$ErrorActionPreference = 'Stop'
Add-Type -Path (Join-Path $PSScriptRoot 'CiffNative.cs')
$document = [CiffNative]::Create()
[PSCustomObject]@{
    ProcessBits = [IntPtr]::Size * 8
    Count = [CiffNative]::GetInt($document, 0x1c)
    XML = [CiffNative]::GetString($document, 0x38)
} | ConvertTo-Json -Depth 4
[CiffNative]::Release($document)
