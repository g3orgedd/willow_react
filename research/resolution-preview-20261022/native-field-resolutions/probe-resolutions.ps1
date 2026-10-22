param([string]$OutputDirectory=$PSScriptRoot)
$ErrorActionPreference='Stop'
if([IntPtr]::Size -ne 4){throw 'Use 32-bit Windows PowerShell'}
$workspace=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '../../..'))
[IO.Directory]::CreateDirectory($OutputDirectory)|Out-Null
Add-Type -Path (Join-Path $workspace 'research/ciff-fields/CiffNative.cs')
Add-Type -Path (Join-Path $workspace 'research/ciff-fields/CiffPrinterNative.cs')
Add-Type -Path (Join-Path $workspace 'research/fonts/FontOracle.cs') -ReferencedAssemblies System.Drawing
$capsManager=[CiffNative]::CreateClass('C1941838-7450-4EC5-8933-14250C9F11AB','6E14FCF0-1792-4CC3-A8DF-096B6FCCFD75')
$capsFile=[CiffNative]::GetPointer($capsManager,0x1c)
[CiffNative]::SetString($capsFile,0x28,(Join-Path $workspace 'research/ciff-fields/printer-oracle/embedded-capabilities.xml'))
$coders=[CiffPrinterNative]::GetObject($capsFile,0x3c)
$rawCaps=[CiffPrinterNative]::GetNamedObject($coders,0x30,'Zodiac Continuous')
$caps=[CiffNative]::Query($rawCaps,'FDF38CF4-872B-401E-9177-058CEA6F09B2')
$component=[CiffNative]::CreateClass('BB0561B2-C54F-11D4-A995-00010212D541','BB0561B1-C54F-11D4-A995-00010212D541')
$records=@()
$cases=@(
 @{id='square-baseline';fileX=0.12;fileY=0.12;capsX=0.12;capsY=0.12},
 @{id='only-file-y-double';fileX=0.12;fileY=0.24;capsX=0.12;capsY=0.12},
 @{id='only-file-x-double';fileX=0.24;fileY=0.12;capsX=0.12;capsY=0.12},
 @{id='only-caps-y-double';fileX=0.12;fileY=0.12;capsX=0.12;capsY=0.24},
 @{id='file-and-caps-y-double';fileX=0.12;fileY=0.24;capsX=0.12;capsY=0.24},
 @{id='only-caps-x-double';fileX=0.12;fileY=0.12;capsX=0.24;capsY=0.12},
 @{id='file-and-caps-x-double';fileX=0.24;fileY=0.12;capsX=0.24;capsY=0.12},
 @{id='only-caps-x-eight';fileX=0.12;fileY=0.12;capsX=0.08;capsY=0.12}
)
try{
 foreach($case in $cases){
  foreach($font in @(@{face='Arial';pitch=10},@{face='Times New Roman';pitch=13},@{face='Courier New';pitch=8})){
   $doc=[IntPtr]::Zero;$image=[IntPtr]::Zero;$typedImage=[IntPtr]::Zero;$field=[IntPtr]::Zero
   try{
    [CiffNative]::SetFloat($caps,0x30,[single]$case.capsX)
    [CiffNative]::SetFloat($caps,0x38,[single]$case.capsY)
    $doc=[CiffNative]::Create()
    $image=[CiffNative]::AddSubImage($doc,'1','Default',1600,2400,0)
    $typedImage=[CiffNative]::Query($image,'9DA85228-EF2E-47C1-9E87-93D03D8CB08F')
    [CiffNative]::SetFloat($typedImage,0x70,[single]$case.fileX)
    [CiffNative]::SetFloat($typedImage,0x78,[single]$case.fileY)
    $field=[CiffPrinterNative]::CreateText($component,0,$doc,$caps,'ControlledText')
    [CiffNative]::SetString($field,0xac,$font.face)
    [CiffNative]::SetInt($field,0xb4,$font.pitch)
    [CiffNative]::SetString($field,0x9c,'TEXT')
    [CiffNative]::SetInt($field,0x30,173)
    [CiffNative]::SetInt($field,0x38,211)
    $size=[CiffPrinterNative]::CalculateSize($component,$doc,$caps,$field)
    $fileName=$case.id+'-'+$font.face.Replace(' ','_')+'.png'
    $png=Join-Path $OutputDirectory $fileName
    [FontOracle]::Draw($component,$field,$caps,$doc,$png)
    $bitmap=[Drawing.Image]::FromFile($png)
    try{$bw=$bitmap.Width;$bh=$bitmap.Height}finally{$bitmap.Dispose()}
    $records += [ordered]@{
     case=$case.id;face=$font.face;pitch=$font.pitch;status='ok';
     fileX=[CiffPrinterNative]::GetFloat($typedImage,0x6c);fileY=[CiffPrinterNative]::GetFloat($typedImage,0x74);
     capsX=[CiffPrinterNative]::GetFloat($caps,0x2c);capsY=[CiffPrinterNative]::GetFloat($caps,0x34);
     sizeWidth=$size.width;sizeHeight=$size.height;bitmapWidth=$bw;bitmapHeight=$bh;
     modelW=[CiffNative]::GetInt($field,0x78);modelH=[CiffNative]::GetInt($field,0x80);
     x=[CiffNative]::GetInt($field,0x2c);y=[CiffNative]::GetInt($field,0x34);
     bitmap=$fileName;sha256=(Get-FileHash -LiteralPath $png -Algorithm SHA256).Hash
    }
   }catch{$records += [ordered]@{case=$case.id;face=$font.face;status='error';error=$_.Exception.ToString()}}
   finally{foreach($p in @($field,$typedImage,$image,$doc)){[CiffNative]::Release($p)}}
  }
 }
}finally{foreach($p in @($component,$caps,$rawCaps,$coders,$capsFile,$capsManager)){[CiffNative]::Release($p)}}
$records|ConvertTo-Json -Depth 10|Set-Content -LiteralPath (Join-Path $OutputDirectory 'results.json') -Encoding UTF8
$records|ForEach-Object {[PSCustomObject]$_}|Format-Table case,face,status,sizeWidth,sizeHeight,bitmapWidth,bitmapHeight,modelW,modelH -AutoSize
