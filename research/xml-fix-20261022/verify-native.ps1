param(
  [Parameter(Mandatory=$true)][string]$InputFile,
  [string]$OutputFile=''
)
$ErrorActionPreference='Stop'
if(-not $OutputFile){$OutputFile=Join-Path $PSScriptRoot 'exports/native-validation.json'}
if([IntPtr]::Size -ne 4){throw 'Use original 32-bit Windows PowerShell.'}
$workspace=(Resolve-Path (Join-Path $PSScriptRoot '../..')).Path
Add-Type -Path @((Join-Path $workspace 'research/ciff-fields/CiffNative.cs'),(Join-Path $workspace 'research/clst/implementation-2026-10-21/CiffClstOracle.cs'))
Add-Type -Path (Join-Path $workspace 'research/ciff-fields/CiffPrinterNative.cs')
$inputCases=Get-Content -LiteralPath $InputFile -Raw | ConvertFrom-Json
$capsPath=Join-Path $workspace 'research/ciff-fields/printer-oracle/embedded-capabilities.xml'
[xml]$capabilityXml=[IO.File]::ReadAllText($capsPath)
$reports=@()
$capsManager=[IntPtr]::Zero;$capsFile=[IntPtr]::Zero;$coders=[IntPtr]::Zero;$component=[IntPtr]::Zero;$barcodeComponent=[IntPtr]::Zero
function Read-Common([IntPtr]$field){
 return [ordered]@{
  name=[CiffNative]::GetString($field,0x1c);type=[CiffNative]::GetString($field,0x68);
  printed=([CiffNative]::GetInt($field,0x24) -ne 0);x=[CiffNative]::GetInt($field,0x2c);y=[CiffNative]::GetInt($field,0x34);
  w=[CiffNative]::GetInt($field,0x78);h=[CiffNative]::GetInt($field,0x80);orientation=[CiffNative]::GetInt($field,0x3c);
  calculatedData=[CiffNative]::GetString($field,0x98)
 }
}
function Read-Font([IntPtr]$text){
 return [ordered]@{
  face=[CiffNative]::GetString($text,0xa8);pitch=[CiffNative]::GetInt($text,0xb0);xMag=[CiffNative]::GetInt($text,0xb8);
  bold=([CiffNative]::GetInt($text,0xc0) -ne 0);italic=([CiffNative]::GetInt($text,0xc8) -ne 0);
  family=[CiffNative]::GetInt($text,0xfc);boldWeight=[CiffNative]::GetInt($text,0x104);yMag=[CiffNative]::GetInt($text,0x11c);
  ttSize=[CiffNative]::GetInt($text,0x124);txtDir=[CiffNative]::GetInt($text,0x134);charSpace=[CiffNative]::GetInt($text,0x150);
  pitchResolution=[CiffNative]::GetInt($text,0x168)
 }
}
function Read-Image([IntPtr]$image){
 $typed=[CiffNative]::Query($image,'9DA85228-EF2E-47C1-9E87-93D03D8CB08F')
 try{return [ordered]@{
  ImageWidth=[CiffNative]::GetInt($typed,0x3c);ImageHeight=[CiffNative]::GetInt($typed,0x44);
  MaxImageWidth=[CiffNative]::GetInt($typed,0x5c);MaxImageHeight=[CiffNative]::GetInt($typed,0x64);
  AutoSize=[CiffNative]::GetInt($typed,0xa4);ImageRotation=[CiffNative]::GetInt($typed,0x54);
  XRes=[CiffPrinterNative]::GetFloat($typed,0x6c);YRes=[CiffPrinterNative]::GetFloat($typed,0x74);
  CurrentOrientation=[CiffNative]::GetInt($typed,0xd4);FieldCount=[CiffNative]::GetInt($typed,0x1c)
 }}finally{[CiffNative]::Release($typed)}
}
try{
 $capsManager=[CiffNative]::CreateClass('C1941838-7450-4EC5-8933-14250C9F11AB','6E14FCF0-1792-4CC3-A8DF-096B6FCCFD75')
 $capsFile=[CiffNative]::GetPointer($capsManager,0x1c);[CiffNative]::SetString($capsFile,0x28,$capsPath)
 $coders=[CiffPrinterNative]::GetObject($capsFile,0x3c)
 $component=[CiffNative]::CreateClass('BB0561B2-C54F-11D4-A995-00010212D541','BB0561B1-C54F-11D4-A995-00010212D541')
 $barcodeComponent=[CiffNative]::CreateClass('7A4AA4CF-F5CD-11D4-8DAE-0050DAFE8A9F','BB0561B1-C54F-11D4-A995-00010212D541')
 foreach($case in $inputCases){
  $doc=[IntPtr]::Zero;$caps=[IntPtr]::Zero
  $comparisonErrors=New-Object System.Collections.ArrayList
  try{
   $expected=Get-Content -LiteralPath $case.expectedFile -Raw | ConvertFrom-Json
   $sourceHash=[CiffClstOracle]::FileSha256($case.file)
   $doc=[CiffClstOracle]::Load((Resolve-Path -LiteralPath $case.file).Path)
   $validate=[CiffClstOracle]::Validate($doc);$validate2=[CiffClstOracle]::Validate2($doc)
   $nativeCanonicalXml=[CiffNative]::GetXml($doc,1,0)
   if($validate -ne '00000000'){[void]$comparisonErrors.Add("Validate returned $validate")}
   if($validate2 -ne '00000000'){[void]$comparisonErrors.Add("Validate2 returned $validate2")}
   $designedFor=[CiffNative]::GetString($doc,0x44)
   $mapping=@($capabilityXml.CapabilitiesFile.Configurations.Mappings.Map | Where-Object{$_.DisplayName -eq $designedFor})
   if($mapping.Count -ne 1){throw "Unknown printer profile $designedFor"}
   $caps=[CiffPrinterNative]::GetNamedObject($coders,0x30,$mapping[0].CoderName)
   $images=@();$nativeFields=@()
   for($si=1;$si -le [CiffNative]::GetInt($doc,0x1c);$si++){
    $image=[CiffClstOracle]::Item($doc,$si)
    try{
     $dimensions=Read-Image $image
     if($si -eq 1){
      foreach($pair in @(@('ImageWidth',$expected.expectedImage.width),@('ImageHeight',$expected.expectedImage.height),@('MaxImageWidth',$expected.expectedMax.width),@('MaxImageHeight',$expected.expectedMax.height))){
       if($dimensions[$pair[0]] -ne $pair[1]){[void]$comparisonErrors.Add("$($pair[0]) mismatch: $($dimensions[$pair[0]]) vs $($pair[1])")}
      }
      foreach($pair in @(@('XRes',$expected.expectedResolution.xRes),@('YRes',$expected.expectedResolution.yRes))){
       if([Math]::Abs($dimensions[$pair[0]] - $pair[1]) -gt 0.0000001){[void]$comparisonErrors.Add("$($pair[0]) mismatch: $($dimensions[$pair[0]]) vs $($pair[1])")}
      }
     }
     for($fi=1;$fi -le [CiffNative]::GetInt($image,0x1c);$fi++){
      $raw=[CiffClstOracle]::Item($image,$fi);$field=[IntPtr]::Zero;$text=[IntPtr]::Zero
      try{
       $field=[CiffNative]::Query($raw,'B2A04AE2-991E-444D-B6EB-C9171E8AB98F')
       $before=Read-Common $field
       $font=$null
       $fieldComponent=$component
       if($before.type -eq 'Barcode'){$fieldComponent=$barcodeComponent}
       else{
        $text=[CiffNative]::Query($raw,'DF5AA02C-19F4-4258-90F2-8303907A2F05')
        $font=Read-Font $text
       }
       $fieldExpected=@($expected.preSave.fields | Where-Object{$_.name -ceq $before.name})
       if($fieldExpected.Count -ne 1){[void]$comparisonErrors.Add("Expected renderer field not unique: $($before.name)")}
       else{
        $wanted=$fieldExpected[0]
        foreach($property in @('x','y','w','h')){
         if($before[$property] -ne $wanted.geom.$property){[void]$comparisonErrors.Add("$($before.name).$property mismatch: $($before[$property]) vs $($wanted.geom.$property)")}
        }
        if($before.printed -ne $wanted.printed){[void]$comparisonErrors.Add("$($before.name).Displayed mismatch")}
        if($before.orientation -ne $wanted.orientation){[void]$comparisonErrors.Add("$($before.name).Orientation mismatch")}
        $afterSaveExpected=@($expected.postSave.fields | Where-Object{$_.name -ceq $before.name})
        $wantedCalculatedData=if($afterSaveExpected.Count -eq 1 -and $afterSaveExpected[0].PSObject.Properties.Name -contains 'calculatedData'){$afterSaveExpected[0].calculatedData}else{$wanted.previewText}
        if($before.calculatedData -cne $wantedCalculatedData){[void]$comparisonErrors.Add("$($before.name).CalculatedData mismatch")}
        if($font){foreach($property in @('face','pitch','xMag','yMag','bold','italic')){
          if($font[$property] -cne $wanted.effectiveFont.$property){[void]$comparisonErrors.Add("$($before.name).Font.$property mismatch: $($font[$property]) vs $($wanted.effectiveFont.$property)")}
         }
         $familyValues=@{DontCare=0;Roman=16;Swiss=32;Modern=48;Script=64;Decorative=80}
         $wantedFamily=if($null -eq $wanted.text.family){32}elseif($familyValues.ContainsKey([string]$wanted.text.family)){$familyValues[[string]$wanted.text.family]}else{[int]$wanted.text.family}
         $additionalFont=[ordered]@{
          family=$wantedFamily;boldWeight=$(if($null -eq $wanted.text.boldWeight){1}else{$wanted.text.boldWeight});
          ttSize=$(if($null -eq $wanted.text.ttSize){1}else{$wanted.text.ttSize});txtDir=$(if($null -eq $wanted.text.txtDir){0}else{$wanted.text.txtDir});
          charSpace=$(if($null -eq $wanted.text.charSpace){0}else{$wanted.text.charSpace});pitchResolution=$(if($null -eq $wanted.text.pitchResolution){1}else{$wanted.text.pitchResolution})
         }
         foreach($property in $additionalFont.Keys){
          if($font[$property] -ne $additionalFont[$property]){[void]$comparisonErrors.Add("$($before.name).Font.$property mismatch: $($font[$property]) vs $($additionalFont[$property])")}
         }
        }
       }
       [CiffPrinterNative]::UpdateData($fieldComponent,$doc,$field)
       $updated=Read-Common $field
       $size=[CiffPrinterNative]::CalculateSize($fieldComponent,$doc,$caps,$field)
       $afterSize=Read-Common $field
       $metricComparison=$null
       if($fieldExpected.Count -eq 1 -and $fieldExpected[0].nativeMetrics){
        $metricEqual=($size.width -eq $fieldExpected[0].nativeMetrics.width -and $size.height -eq $fieldExpected[0].nativeMetrics.height)
        $metricComparison=[ordered]@{
         equal=$metricEqual;rendererWidthDots=$fieldExpected[0].nativeMetrics.width;rendererHeightDots=$fieldExpected[0].nativeMetrics.height;
         originalProfileWidthDots=$size.width;originalProfileHeightDots=$size.height;
         scope=$(if($case.caseId -eq 'anisotropic-yres'){'Anisotropic file uses XRes0.12/YRes0.24; original component calculation here uses actual target printer capabilities. Difference is explicitly recorded, not a claim of converted printer-preview equivalence.'}else{'Same file/render resolution and actual printer profile expected to agree.'})
        }
        if(-not $metricEqual -and $case.caseId -ne 'anisotropic-yres'){
         [void]$comparisonErrors.Add("$($before.name).Native metrics mismatch: $($size.width)x$($size.height) vs $($fieldExpected[0].nativeMetrics.width)x$($fieldExpected[0].nativeMetrics.height)")
        }
       }
       $nativeFields+=[ordered]@{subImage=$si;index=$fi;before=$before;font=$font;updated=$updated;afterSize=$afterSize;widthDots=$size.width;heightDots=$size.height;metricComparison=$metricComparison}
      }finally{[CiffNative]::Release($text);[CiffNative]::Release($field);[CiffNative]::Release($raw)}
     }
     $images+=[ordered]@{index=$si;dimensions=$dimensions;afterComponents=(Read-Image $image)}
    }finally{[CiffNative]::Release($image)}
   }
   if($nativeFields.Count -ne @($expected.preSave.fields).Count){[void]$comparisonErrors.Add('Total field count differs from renderer')}
   $afterHash=[CiffClstOracle]::FileSha256($case.file)
   if($sourceHash -ne $afterHash){[void]$comparisonErrors.Add('Source CIFF file changed during native verification')}
   $reports+=[ordered]@{name=$case.name;mode=$case.mode;caseId=$case.caseId;file=$case.file;status=$(if($comparisonErrors.Count){'mismatch'}else{'ok'});
    expectedFile=$case.expectedFile;sourceSha256=$sourceHash;sourceSha256After=$afterHash;validate=$validate;validate2=$validate2;
    designedFor=$designedFor;coder=$mapping[0].CoderName;images=$images;fields=$nativeFields;nativeCanonicalXml=$nativeCanonicalXml;
    afterNativeResolve=[CiffClstOracle]::Snapshot($doc);comparisonErrors=@($comparisonErrors)}
  }catch{
   $failure=$_.Exception;while($failure.InnerException){$failure=$failure.InnerException}
   $reports+=[ordered]@{name=$case.name;file=$case.file;status='error';error=$failure.ToString();hresult=([uint32]([int64]$failure.HResult -band 4294967295)).ToString('X8');comparisonErrors=@($comparisonErrors)}
  }finally{[CiffNative]::Release($caps);[CiffNative]::Release($doc)}
 }
}finally{foreach($pointer in @($component,$barcodeComponent,$coders,$capsFile,$capsManager)){[CiffNative]::Release($pointer)}}
$fingerprints=@()
foreach($name in @('CiffMgr.dll','CiffHelper.dll','CLCSTextBasedField.dll','capabilitiesManager.dll')){
 $binary=Join-Path 'C:/Program Files (x86)/CLARICOM/Data' $name
 $fingerprints+=[ordered]@{name=$name;path=$binary;version=[Diagnostics.FileVersionInfo]::GetVersionInfo($binary).FileVersion;sha256=(Get-FileHash -LiteralPath $binary -Algorithm SHA256).Hash}
}
$report=[ordered]@{
 method='Original installed filename loader, Validate/Validate2, original text UpdateData/CalculateSize with real capabilities. Compared against pre-save state of actual web/packaged-EXE renderers. No native GUI screenshot or physical print implied.';
 processBits=32;finishedUtc=[datetime]::UtcNow.ToString('o');nativeBinaries=$fingerprints;cases=$reports
}
[IO.Directory]::CreateDirectory((Split-Path -Parent ([IO.Path]::GetFullPath($OutputFile))))|Out-Null
[IO.File]::WriteAllText($OutputFile,($report|ConvertTo-Json -Depth 22),[Text.UTF8Encoding]::new($false))
[pscustomobject]@{cases=$reports.Count;ok=@($reports|Where-Object status -eq 'ok').Count;mismatches=@($reports|Where-Object status -eq 'mismatch').Count;errors=@($reports|Where-Object status -eq 'error').Count}|ConvertTo-Json
if(@($reports|Where-Object status -ne 'ok').Count){exit 1}
