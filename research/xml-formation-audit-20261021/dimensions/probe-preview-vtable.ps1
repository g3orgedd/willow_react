$ErrorActionPreference='Stop'
$workspace=(Resolve-Path (Join-Path $PSScriptRoot '../../..')).Path
Add-Type -Path (Join-Path $workspace 'research/ciff-fields/CiffNative.cs')
$p=[CiffNative]::CreateClass('7DA01FA4-E267-11D4-8198-005004D1164E','6BC4AC39-AAA0-4079-9D52-DB3670806ECE')
try { $rows=foreach($o in @(0x20,0x54,0x60,0x6c,0x70,0x74,0x78)){[pscustomobject]@{offset=$o;address=[CiffNative]::MethodAddress($p,$o,'CLPrintPreview.ocx',0x3f400000)}}; $rows|ConvertTo-Json|Set-Content -LiteralPath (Join-Path $PSScriptRoot 'preview-live-vtable.json');$rows|ConvertTo-Json }
finally {[CiffNative]::Release($p)}