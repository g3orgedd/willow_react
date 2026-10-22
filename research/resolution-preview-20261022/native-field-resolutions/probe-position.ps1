$ErrorActionPreference='Stop'
if([IntPtr]::Size-ne4){throw 'Use 32-bit PowerShell'}
$workspace=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '../../..'))
Add-Type -Path (Join-Path $workspace 'research/ciff-fields/CiffNative.cs')
Add-Type -Path (Join-Path $workspace 'research/ciff-fields/CiffPrinterNative.cs')
Add-Type -Path (Join-Path $PSScriptRoot 'NativeResolutionDraw.cs') -ReferencedAssemblies System.Drawing
$capsManager=[CiffNative]::CreateClass('C1941838-7450-4EC5-8933-14250C9F11AB','6E14FCF0-1792-4CC3-A8DF-096B6FCCFD75')
$capsFile=[CiffNative]::GetPointer($capsManager,0x1c)
[CiffNative]::SetString($capsFile,0x28,(Join-Path $workspace 'research/ciff-fields/printer-oracle/embedded-capabilities.xml'))
$coders=[CiffPrinterNative]::GetObject($capsFile,0x3c)
$rawCaps=[CiffPrinterNative]::GetNamedObject($coders,0x30,'Zodiac Continuous')
$caps=[CiffNative]::Query($rawCaps,'FDF38CF4-872B-401E-9177-058CEA6F09B2')
$component=[CiffNative]::CreateClass('BB0561B2-C54F-11D4-A995-00010212D541','BB0561B1-C54F-11D4-A995-00010212D541')
$cases=@(
 @{id='file-y-double-caps-square';fx=0.12;fy=0.24;cx=0.12;cy=0.12},
 @{id='file-x-double-caps-y-double';fx=0.24;fy=0.12;cx=0.12;cy=0.24},
 @{id='file-y-double-caps-x-double';fx=0.12;fy=0.24;cx=0.24;cy=0.12},
 @{id='half-ties-caps-eighth';fx=0.12;fy=0.24;cx=0.125;cy=0.125}
)
$records=@()
try{foreach($case in $cases){foreach($angle in @(0,90,180,270)){foreach($point in @(@(4,-4),@(173,83),@(-13,12))){
 $doc=[IntPtr]::Zero;$image=[IntPtr]::Zero;$typedImage=[IntPtr]::Zero;$field=[IntPtr]::Zero
 try{
  [CiffNative]::SetFloat($caps,0x30,[single]$case.cx);[CiffNative]::SetFloat($caps,0x38,[single]$case.cy)
  $doc=[CiffNative]::Create();$image=[CiffNative]::AddSubImage($doc,'1','Default',1600,2400,0)
  $typedImage=[CiffNative]::Query($image,'9DA85228-EF2E-47C1-9E87-93D03D8CB08F')
  [CiffNative]::SetFloat($typedImage,0x70,[single]$case.fx);[CiffNative]::SetFloat($typedImage,0x78,[single]$case.fy)
  $field=[CiffPrinterNative]::CreateText($component,0,$doc,$caps,'PositionText')
  [CiffNative]::SetString($field,0xac,'Arial');[CiffNative]::SetInt($field,0xb4,10)
  [CiffNative]::SetString($field,0x9c,'TEXT');[CiffNative]::SetInt($field,0x30,$point[0]);[CiffNative]::SetInt($field,0x38,$point[1]);[CiffNative]::SetInt($field,0x40,$angle)
  $name=$case.id+'-rot'+$angle+'-x'+$point[0]+'-y'+$point[1]
  $result=[NativeResolutionDraw]::Probe($component,$field,$caps,$doc,$point[0],$point[1],[single]$case.cx,[single]$case.cy,(Join-Path $PSScriptRoot $name))
  $records += [ordered]@{case=$case.id;orientation=$angle;x=$point[0];y=$point[1];fileX=$case.fx;fileY=$case.fy;capsX=$case.cx;capsY=$case.cy;status='ok';result=$result;modelW=[CiffNative]::GetInt($field,0x78);modelH=[CiffNative]::GetInt($field,0x80);prefix=$name}
 }catch{$records += [ordered]@{case=$case.id;orientation=$angle;x=$point[0];y=$point[1];status='error';error=$_.Exception.ToString()}}
 finally{foreach($p in @($field,$typedImage,$image,$doc)){[CiffNative]::Release($p)}}
}}}}finally{foreach($p in @($component,$caps,$rawCaps,$coders,$capsFile,$capsManager)){[CiffNative]::Release($p)}}
$records|ConvertTo-Json -Depth 10|Set-Content -LiteralPath (Join-Path $PSScriptRoot 'position-results.json') -Encoding UTF8
$records|ForEach-Object{[pscustomobject]@{case=$_.case;orientation=$_.orientation;x=$_.x;y=$_.y;status=$_.status;offsetX=$_.result.offsetX;offsetY=$_.result.offsetY;different=$_.result.differentPixels;best=$_.result.bestDifference}}|Format-Table -AutoSize
