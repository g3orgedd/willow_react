$ErrorActionPreference='Stop'
if([IntPtr]::Size-ne4){throw 'Use 32-bit PowerShell'}
$workspace=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '../../..'))
Add-Type -Path (Join-Path $workspace 'research/ciff-fields/CiffNative.cs')
Add-Type -Path (Join-Path $workspace 'research/ciff-fields/CiffPrinterNative.cs')
Add-Type -Path (Join-Path $PSScriptRoot 'NativeLayoutConversion.cs')
$capsManager=[CiffNative]::CreateClass('C1941838-7450-4EC5-8933-14250C9F11AB','6E14FCF0-1792-4CC3-A8DF-096B6FCCFD75')
$capsFile=[CiffNative]::GetPointer($capsManager,0x1c)
[CiffNative]::SetString($capsFile,0x28,(Join-Path $workspace 'research/ciff-fields/printer-oracle/embedded-capabilities.xml'))
$coders=[CiffPrinterNative]::GetObject($capsFile,0x3c)
$caps=[CiffPrinterNative]::GetNamedObject($coders,0x30,'Zodiac Continuous')
$component=[CiffNative]::CreateClass('BB0561B2-C54F-11D4-A995-00010212D541','BB0561B1-C54F-11D4-A995-00010212D541')
$records=@()
try{foreach($file in @(@(0.12,0.12),@(0.12,0.24),@(0.24,0.12),@(0.24,0.24))){foreach($tt in @(1,0)){
 $doc=[IntPtr]::Zero;$image=[IntPtr]::Zero;$typedImage=[IntPtr]::Zero;$field=[IntPtr]::Zero;$convert=[IntPtr]::Zero
 try{
  $doc=[CiffNative]::Create();$image=[CiffNative]::AddSubImage($doc,'1','Default',1600,2400,0)
  $typedImage=[CiffNative]::Query($image,'9DA85228-EF2E-47C1-9E87-93D03D8CB08F')
  [CiffNative]::SetFloat($typedImage,0x70,[single]$file[0]);[CiffNative]::SetFloat($typedImage,0x78,[single]$file[1])
  $field=[CiffPrinterNative]::CreateText($component,0,$doc,$caps,'ResolutionText')
  [CiffNative]::SetString($field,0xac,'Arial');[CiffNative]::SetInt($field,0xb4,10);[CiffNative]::SetInt($field,0x128,$tt)
  [CiffNative]::SetString($field,0x9c,'TEXT');[CiffNative]::SetInt($field,0x30,173);[CiffNative]::SetInt($field,0x38,211)
  [CiffNative]::SetInt($field,0x7c,800);[CiffNative]::SetInt($field,0x84,350)
  $before=[CiffNative]::GetXml($doc,1,0)
  $convert=[CiffNative]::CreateClass('C6718CED-FB94-49BA-BD48-97B730D3E20A','B72A7518-91C9-487B-B69F-0A1C1C2245D8')
  [NativeLayoutConversion]::Initialise($convert,'C:\Program Files (x86)\CLARICOM\Data\')
  [NativeLayoutConversion]::SetObject($convert,'CapsFile Pointer',$capsFile)
  [NativeLayoutConversion]::SetObject($convert,'CapsCoder Pointer',$caps)
  [NativeLayoutConversion]::SetString($convert,'CapsFormat','Default')
  [NativeLayoutConversion]::SetString($convert,'ConversionRequestSource','Print Preview')
  [NativeLayoutConversion]::SetInt($convert,'CS Resolution Adjust',1)
  [NativeLayoutConversion]::Convert($convert,$doc)
  $after=[CiffNative]::GetXml($doc,1,0)
  $records += [ordered]@{fileX=$file[0];fileY=$file[1];ttSize=$tt;status='ok';pitch=[CiffNative]::GetInt($field,0xb0);x=[CiffNative]::GetInt($field,0x2c);y=[CiffNative]::GetInt($field,0x34);w=[CiffNative]::GetInt($field,0x78);h=[CiffNative]::GetInt($field,0x80);afterX=[CiffPrinterNative]::GetFloat($typedImage,0x6c);afterY=[CiffPrinterNative]::GetFloat($typedImage,0x74);beforeXml=$before;afterXml=$after}
 }catch{$records += [ordered]@{fileX=$file[0];fileY=$file[1];ttSize=$tt;status='error';error=$_.Exception.ToString()}}
 finally{foreach($p in @($convert,$field,$typedImage,$image,$doc)){[CiffNative]::Release($p)}}
}}}finally{foreach($p in @($component,$caps,$coders,$capsFile,$capsManager)){[CiffNative]::Release($p)}}
$records|ConvertTo-Json -Depth 10|Set-Content -LiteralPath (Join-Path $PSScriptRoot 'layout-resolution-results.json') -Encoding UTF8
$records|ForEach-Object{[pscustomobject]$_}|Format-Table fileX,fileY,ttSize,status,pitch,x,y,w,h,afterX,afterY -AutoSize
