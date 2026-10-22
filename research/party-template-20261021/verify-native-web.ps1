param([string]$InputFile=(Join-Path $PSScriptRoot 'exported-web/native-inputs.json'))
$ErrorActionPreference='Stop'
if([IntPtr]::Size -ne 4){throw 'Use original 32-bit Windows PowerShell.'}
$root=Split-Path (Split-Path $PSScriptRoot -Parent) -Parent
Add-Type -Path @((Join-Path $root 'research/ciff-fields/CiffNative.cs'),(Join-Path $root 'research/clst/implementation-2026-10-21/CiffClstOracle.cs'))
Add-Type -Path (Join-Path $root 'research/ciff-fields/CiffPrinterNative.cs')
Add-Type -Path (Join-Path $root 'research/fonts/FontOracle.cs') -ReferencedAssemblies System.Drawing
$capabilityPath=Join-Path $root 'research/ciff-fields/printer-oracle/embedded-capabilities.xml'
[xml]$capabilityXml=[IO.File]::ReadAllText($capabilityPath)
$cases=Get-Content -LiteralPath $InputFile -Raw|ConvertFrom-Json
$results=@()
$textComponent=[IntPtr]::Zero;$barcodeComponent=[IntPtr]::Zero;$capsManager=[IntPtr]::Zero;$capsFile=[IntPtr]::Zero;$coders=[IntPtr]::Zero
function Read-Common([IntPtr]$field){return [ordered]@{
 name=[CiffNative]::GetString($field,0x1c);type=[CiffNative]::GetString($field,0x68);
 x=[CiffNative]::GetInt($field,0x2c);y=[CiffNative]::GetInt($field,0x34);w=[CiffNative]::GetInt($field,0x78);h=[CiffNative]::GetInt($field,0x80);
 orientation=[CiffNative]::GetInt($field,0x3c);calcData=[CiffNative]::GetString($field,0x98)
}}
try{
 $capsManager=[CiffNative]::CreateClass('C1941838-7450-4EC5-8933-14250C9F11AB','6E14FCF0-1792-4CC3-A8DF-096B6FCCFD75')
 $capsFile=[CiffNative]::GetPointer($capsManager,0x1c)
 [CiffNative]::SetString($capsFile,0x28,$capabilityPath)
 $coders=[CiffPrinterNative]::GetObject($capsFile,0x3c)
 $textComponent=[CiffNative]::CreateClass('BB0561B2-C54F-11D4-A995-00010212D541','BB0561B1-C54F-11D4-A995-00010212D541')
 $barcodeComponent=[CiffNative]::CreateClass('7A4AA4CF-F5CD-11D4-8DAE-0050DAFE8A9F','BB0561B1-C54F-11D4-A995-00010212D541')
 foreach($case in $cases){
  $doc=[IntPtr]::Zero;$caps=[IntPtr]::Zero
  try{
   $hashBefore=[CiffClstOracle]::FileSha256($case.file)
   $doc=[CiffClstOracle]::Load($case.file)
   $designedFor=[CiffNative]::GetString($doc,0x44)
   $mapping=@($capabilityXml.CapabilitiesFile.Configurations.Mappings.Map|Where-Object{$_.DisplayName -eq $designedFor})
   if($mapping.Count -ne 1){throw "Unknown printer $designedFor"}
   $caps=[CiffPrinterNative]::GetNamedObject($coders,0x30,$mapping[0].CoderName)
   $output=Join-Path (Split-Path $case.file -Parent) ('native-draw-'+[IO.Path]::GetFileNameWithoutExtension($case.file))
   if(Test-Path -LiteralPath $output){throw "Do not overwrite native evidence $output"}
   [IO.Directory]::CreateDirectory($output)|Out-Null
   $rows=@()
   for($si=1;$si -le [CiffNative]::GetInt($doc,0x1c);$si++){
    $image=[CiffClstOracle]::Item($doc,$si)
    try{for($fi=1;$fi -le [CiffNative]::GetInt($image,0x1c);$fi++){
     $raw=[CiffClstOracle]::Item($image,$fi);$field=[IntPtr]::Zero;$text=[IntPtr]::Zero
     try{
      $field=[CiffNative]::Query($raw,'B2A04AE2-991E-444D-B6EB-C9171E8AB98F')
      $before=Read-Common $field
      $component=if($before.type -eq 'Barcode'){$barcodeComponent}else{$textComponent}
      $font=$null
      if($before.type -ne 'Barcode'){
       $text=[CiffNative]::Query($raw,'DF5AA02C-19F4-4258-90F2-8303907A2F05')
       $font=[ordered]@{face=[CiffNative]::GetString($text,0xa8);pitch=[CiffNative]::GetInt($text,0xb0);xMag=[CiffNative]::GetInt($text,0xb8);bold=[CiffNative]::GetInt($text,0xc0);italic=[CiffNative]::GetInt($text,0xc8)}
      }
      [CiffPrinterNative]::UpdateData($component,$doc,$field)
      $afterUpdate=Read-Common $field
      $size=[CiffPrinterNative]::CalculateSize($component,$doc,$caps,$field)
      $afterSize=Read-Common $field
      $bitmap=Join-Path $output ($before.name+'.png')
      [FontOracle]::Draw($component,$field,$caps,$doc,$bitmap)
      $afterDraw=Read-Common $field
      $rows+=[ordered]@{status='ok';name=$before.name;before=$before;font=$font;afterUpdate=$afterUpdate;afterSize=$afterSize;afterDraw=$afterDraw;widthDots=$size.width;heightDots=$size.height;bitmap=$bitmap}
     }catch{
      $failure=$_.Exception;while($failure.InnerException){$failure=$failure.InnerException}
      $rows+=[ordered]@{status='error';name=$before.name;error=$failure.Message;hresult=([uint32]([int64]$failure.HResult -band 4294967295)).ToString('X8')}
     }finally{[CiffNative]::Release($text);[CiffNative]::Release($field);[CiffNative]::Release($raw)}
    }}finally{[CiffNative]::Release($image)}
   }
   $results+=[ordered]@{name=$case.name;file=$case.file;designedFor=$designedFor;sourceSHA256=$hashBefore;sourceSHA256After=[CiffClstOracle]::FileSha256($case.file);fields=$rows}
  }finally{[CiffNative]::Release($caps);[CiffNative]::Release($doc)}
 }
}finally{foreach($ptr in @($textComponent,$barcodeComponent,$coders,$capsFile,$capsManager)){[CiffNative]::Release($ptr)}}
$report=[ordered]@{method='Original installed COM load, text/small-barcode UpdateData/CalculateSize/Draw with real printer capabilities; component bitmaps are not GUI screenshots.';processBits=32;finishedUTC=[DateTime]::UtcNow.ToString('o');cases=$results}
$out=Join-Path (Split-Path $InputFile -Parent) 'native-components.json'
[IO.File]::WriteAllText($out,($report|ConvertTo-Json -Depth 16),[Text.UTF8Encoding]::new($false))
[PSCustomObject]@{cases=$results.Count;fields=@($results|ForEach-Object{$_.fields}).Count;errors=@($results|ForEach-Object{$_.fields}|Where-Object{$_.status -ne 'ok'}).Count}|ConvertTo-Json
