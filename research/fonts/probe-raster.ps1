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
$sample='Abc 0123456789 '+[char]0x410+[char]0x411+[char]0x412+[char]0x413+[char]0x414+' '+[char]0x430+[char]0x431+[char]0x432+[char]0x433+[char]0x434
$records=@()
try {
  foreach($face in @('Fixedsys','System','Terminal')) {
    foreach($pitch in @(6,13)) {
      $field=[CiffPrinterNative]::CreateText($component,0,$document,$caps,($face+'_'+$pitch))
      try {
        [CiffNative]::SetString($field,0xac,$face)
        [CiffNative]::SetInt($field,0xb4,$pitch)
        [CiffNative]::SetString($field,0x9c,$sample)
        $before=[CiffNative]::GetInt($field,0x124)
        $size=[CiffPrinterNative]::CalculateSize($component,$document,$caps,$field)
        $after=[CiffNative]::GetInt($field,0x124)
        $path=Join-Path $PSScriptRoot ('raster_'+$face+'_'+$pitch+'.png')
        [FontOracle]::Draw($component,$field,$caps,$document,$path)
        $records+=@{face=$face;pitch=$pitch;text=$sample;widthDots=$size.width;heightDots=$size.height;ttSizeBefore=$before;ttSizeAfterCalculate=$after;ttSizeAfterDraw=[CiffNative]::GetInt($field,0x124);familyAfterDraw=[CiffNative]::GetInt($field,0xfc);widthCiff=[CiffNative]::GetInt($field,0x78);heightCiff=[CiffNative]::GetInt($field,0x80);path=(Split-Path $path -Leaf)}
      } finally {[CiffNative]::Release($field)}
    }
  }
  [IO.File]::WriteAllText((Join-Path $PSScriptRoot 'oracle-raster.ciff'),[CiffNative]::GetXml($document,1,0),(New-Object System.Text.UnicodeEncoding($false,$true,$true)))
  $records|ConvertTo-Json -Depth 7|Set-Content (Join-Path $PSScriptRoot 'oracle-raster.json') -Encoding UTF8
  $records|ForEach-Object {[PSCustomObject]$_}|Format-Table face,pitch,widthDots,heightDots,ttSizeBefore,ttSizeAfterCalculate,ttSizeAfterDraw -AutoSize
} finally {
  foreach($p in @($image,$document,$component,$caps,$coders,$capsFile,$capsManager)){[CiffNative]::Release($p)}
}
