$ErrorActionPreference='Stop'
Add-Type -Path (Join-Path $PWD 'research/ciff-fields/CiffNative.cs')
$doc=[CiffNative]::Create()
try {
 [CiffNative]::SetInt($doc,0x58,1)
 $image=[CiffNative]::AddSubImage($doc,'1','Default',1600,2000,0)
 try {[CiffNative]::GetString($doc,0x38)}finally{[CiffNative]::Release($image)}
 [CiffNative]::SetInt($doc,0x58,0)
 [CiffNative]::GetString($doc,0x38)
} finally {[CiffNative]::Release($doc)}