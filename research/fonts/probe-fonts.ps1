$ErrorActionPreference='Stop'
$root=Split-Path $PSScriptRoot -Parent
Add-Type -Path (Join-Path $root 'ciff-fields/CiffNative.cs')
Add-Type -Path (Join-Path $root 'ciff-fields/CiffPrinterNative.cs')
Add-Type -Path (Join-Path $PSScriptRoot 'FontOracle.cs') -ReferencedAssemblies System.Drawing
$capsManager=[CiffNative]::CreateClass('C1941838-7450-4EC5-8933-14250C9F11AB','6E14FCF0-1792-4CC3-A8DF-096B6FCCFD75')
$capsFile=[CiffNative]::GetPointer($capsManager,0x1c)
[CiffNative]::SetString($capsFile,0x28,(Join-Path $root 'ciff-fields/printer-oracle/embedded-capabilities.xml'))
$coders=[CiffPrinterNative]::GetObject($capsFile,0x3c)
$caps=[CiffPrinterNative]::GetNamedObject($coders,0x30,'Zodiac Continuous')
$component=[CiffNative]::CreateClass('BB0561B2-C54F-11D4-A995-00010212D541','BB0561B1-C54F-11D4-A995-00010212D541')
$document=[CiffNative]::Create()
$image=[CiffNative]::AddSubImage($document,'1','Default',4000,2000,0)
$fonts=[CiffPrinterNative]::GetObject($caps,0x474)
$fontRecords=@()
for($i=1;$i -le [CiffNative]::GetInt($fonts,0x24);$i++) {
  $font=[FontOracle]::Item($fonts,$i)
  $fontRecords+=@{face=[CiffNative]::GetString($font,0x1c);type=[CiffNative]::GetString($font,0x9c);alias=[CiffNative]::GetString($font,0xac);windowsLocation=[CiffNative]::GetString($font,0x8c);pointSize=[CiffNative]::GetInt($font,0x3c)}
  [CiffNative]::Release($font)
}
$fontRecords|ConvertTo-Json -Depth 6|Set-Content (Join-Path $PSScriptRoot 'capabilities-fonts.json') -Encoding UTF8
$records=@()
foreach($face in @('Arial','Arial Narrow','Times New Roman','Courier New','Tahoma','Verdana','OCRB','Segoe UI')) {
  foreach($pitch in @(6,13)) {
    $field=[CiffPrinterNative]::CreateText($component,0,$document,$caps,($face+'_'+$pitch -replace ' ','_'))
    [CiffNative]::SetString($field,0xac,$face)
    [CiffNative]::SetInt($field,0xb4,$pitch)
    [CiffNative]::SetString($field,0x9c,'Abc 0123456789 АБВГД абвгд')
    $size=[CiffPrinterNative]::CalculateSize($component,$document,$caps,$field)
    $path=Join-Path $PSScriptRoot (($face+'_'+$pitch -replace ' ','_')+'.png')
    [FontOracle]::Draw($component,$field,$caps,$document,$path)
    $records+=@{face=$face;pitch=$pitch;widthDots=$size.width;heightDots=$size.height;widthCiff=[CiffNative]::GetInt($field,0x78);heightCiff=[CiffNative]::GetInt($field,0x80);path=(Split-Path $path -Leaf)}
    [CiffNative]::Release($field)
  }
}
[string]$sample='Abc 0123456789 '+[string][char]0x410+[char]0x411+[char]0x412+[char]0x413+[char]0x414+' '+[char]0x430+[char]0x431+[char]0x432+[char]0x433+[char]0x434
$variantRecords=@()
foreach($variant in @(@{name='normal';offset=0;value=0},@{name='bold';offset=0xc4;value=1},@{name='italic';offset=0xcc;value=1},@{name='xmag150';offset=0xbc;value=150},@{name='ymag150';offset=0x120;value=150},@{name='spacing50';offset=0x154;value=50},@{name='spacing1';offset=0x154;value=1},@{name='pitchresolution10';offset=0x16c;value=10},@{name='ttsize0';offset=0x128;value=0},@{name='ttsize2';offset=0x128;value=2},@{name='double';offset=0x110;value=1})) {
  $field=[CiffPrinterNative]::CreateText($component,0,$document,$caps,$variant.name)
  $extended=[CiffNative]::Query($field,'DF5AA02C-19F4-4258-90F2-8303907A2F05')
  [CiffNative]::SetString($field,0xac,'Arial')
  [CiffNative]::SetInt($field,0xb4,13)
  [CiffNative]::SetString($field,0x9c,$sample)
  if($variant.offset -ne 0){[CiffNative]::SetInt($extended,$variant.offset,$variant.value)}
  $size=[CiffPrinterNative]::CalculateSize($component,$document,$caps,$field)
  $path=Join-Path $PSScriptRoot ('variant_'+$variant.name+'.png')
  [FontOracle]::Draw($component,$field,$caps,$document,$path)
  $variantRecords+=@{name=$variant.name;widthDots=$size.width;heightDots=$size.height;widthCiff=[CiffNative]::GetInt($field,0x78);heightCiff=[CiffNative]::GetInt($field,0x80);path=(Split-Path $path -Leaf)}
  [CiffNative]::Release($extended);[CiffNative]::Release($field)
}
$variantRecords|ConvertTo-Json -Depth 6|Set-Content (Join-Path $PSScriptRoot 'oracle-variants.json') -Encoding UTF8
[IO.File]::WriteAllText((Join-Path $PSScriptRoot 'oracle-fields.ciff'),[CiffNative]::GetXml($document,1,0),(New-Object System.Text.UnicodeEncoding($false,$true,$true)))
@{xRes=[CiffPrinterNative]::GetFloat($caps,0x2c);yRes=[CiffPrinterNative]::GetFloat($caps,0x34);useTTF=[CiffNative]::GetInt($caps,0x184);useZFBF=[CiffNative]::GetInt($caps,0x29c);fields=$records}|ConvertTo-Json -Depth 7|Set-Content (Join-Path $PSScriptRoot 'oracle-results.json') -Encoding UTF8
$records|Format-Table -AutoSize
$profileRecords=@()
$mappings=Get-Content -LiteralPath (Join-Path $root 'ciff-fields/printer-oracle/profile-mappings.json') -Raw|ConvertFrom-Json
foreach($profile in @($mappings|Where-Object DisplayName -Like 'DataFlex*')) {
  $profileCaps=[CiffPrinterNative]::GetNamedObject($coders,0x30,$profile.CoderName)
  $profileFonts=[CiffPrinterNative]::GetObject($profileCaps,0x474)
  $names=@()
  for($i=1;$i -le [CiffNative]::GetInt($profileFonts,0x24);$i++) {
    $font=[FontOracle]::Item($profileFonts,$i)
    $names+=[CiffNative]::GetString($font,0x1c)
    [CiffNative]::Release($font)
  }
  $profileRecords+=@{profile=$profile.DisplayName;coder=$profile.CoderName;faces=$names;useTTFFonts=[CiffNative]::GetInt($profileCaps,0x184);useZFBF=[CiffNative]::GetInt($profileCaps,0x29c);pitchResolution=[CiffNative]::GetInt($profileCaps,0x3b4)}
  [CiffNative]::Release($profileFonts);[CiffNative]::Release($profileCaps)
}
$profileRecords|ConvertTo-Json -Depth 8|Set-Content (Join-Path $PSScriptRoot 'profile-fonts.json') -Encoding UTF8
foreach($p in @($fonts,$image,$document,$component,$caps,$coders,$capsFile,$capsManager)){[CiffNative]::Release($p)}
