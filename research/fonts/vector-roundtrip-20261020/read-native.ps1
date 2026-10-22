param([ValidateSet('web','exe')][string]$Mode)
$ErrorActionPreference='Stop'
if([IntPtr]::Size -ne 4){throw 'Use 32-bit Windows PowerShell.'}
$researchRoot=Split-Path (Split-Path $PSScriptRoot -Parent) -Parent
$ciffPath=Join-Path $PSScriptRoot ($Mode+'-vector.ciff')
$output=Join-Path $PSScriptRoot ('native-'+$Mode)
[IO.Directory]::CreateDirectory($output)|Out-Null
$beforeHash=(Get-FileHash -LiteralPath $ciffPath -Algorithm SHA256).Hash
$startedUtc=[DateTime]::UtcNow.ToString('o')
Add-Type -Path (Join-Path $researchRoot 'ciff-fields/CiffNative.cs')
Add-Type -Path (Join-Path $researchRoot 'ciff-fields/CiffPrinterNative.cs')
Add-Type -Path (Join-Path (Split-Path $PSScriptRoot -Parent) 'FontOracle.cs') -ReferencedAssemblies System.Drawing
Add-Type -Path (Join-Path $PSScriptRoot 'NativeSavedFile.cs') -ReferencedAssemblies System.Drawing
function Read-Field([IntPtr]$field){return [ordered]@{
 name=[CiffNative]::GetString($field,0x1c);type=[CiffNative]::GetString($field,0x68);
 x=[CiffNative]::GetInt($field,0x2c);y=[CiffNative]::GetInt($field,0x34);w=[CiffNative]::GetInt($field,0x78);h=[CiffNative]::GetInt($field,0x80);
 orientation=[CiffNative]::GetInt($field,0x3c);calculatedData=[CiffNative]::GetString($field,0x98);
 face=[CiffNative]::GetString($field,0xa8);pitch=[CiffNative]::GetInt($field,0xb0);xMag=[CiffNative]::GetInt($field,0xb8);
 bold=[CiffNative]::GetInt($field,0xc0);italic=[CiffNative]::GetInt($field,0xc8);family=[CiffNative]::GetInt($field,0xfc);boldWeight=[CiffNative]::GetInt($field,0x104);
 yMag=[CiffNative]::GetInt($field,0x11c);ttSize=[CiffNative]::GetInt($field,0x124);txtDir=[CiffNative]::GetInt($field,0x134);
 charSpace=[CiffNative]::GetInt($field,0x150);pitchResolution=[CiffNative]::GetInt($field,0x168)
}}
$document=[IntPtr]::Zero;$component=[IntPtr]::Zero;$caps=[IntPtr]::Zero;$coders=[IntPtr]::Zero;$capsFile=[IntPtr]::Zero;$capsManager=[IntPtr]::Zero
try{
 $document=[NativeSavedFile]::Load((Resolve-Path -LiteralPath $ciffPath).Path)
 $designedFor=[CiffNative]::GetString($document,0x44)
 $capabilityPath=Join-Path $researchRoot 'ciff-fields/printer-oracle/embedded-capabilities.xml'
 [xml]$xml=[IO.File]::ReadAllText($capabilityPath)
 $mapping=@($xml.CapabilitiesFile.Configurations.Mappings.Map|Where-Object{$_.DisplayName -eq $designedFor})
 if($mapping.Count -ne 1){throw "Unknown printer profile $designedFor"}
 $capsManager=[CiffNative]::CreateClass('C1941838-7450-4EC5-8933-14250C9F11AB','6E14FCF0-1792-4CC3-A8DF-096B6FCCFD75')
 $capsFile=[CiffNative]::GetPointer($capsManager,0x1c)
 [CiffNative]::SetString($capsFile,0x28,$capabilityPath)
 $coders=[CiffPrinterNative]::GetObject($capsFile,0x3c)
 $caps=[CiffPrinterNative]::GetNamedObject($coders,0x30,$mapping[0].CoderName)
 $component=[CiffNative]::CreateClass('BB0561B2-C54F-11D4-A995-00010212D541','BB0561B1-C54F-11D4-A995-00010212D541')
 $fields=@()
 for($i=1;$i -le [CiffNative]::GetInt($document,0x1c);$i++){
  $image=[NativeSavedFile]::Item($document,$i)
  try{for($n=1;$n -le [CiffNative]::GetInt($image,0x1c);$n++){
   $raw=[NativeSavedFile]::Item($image,$n);$field=[IntPtr]::Zero
   try{
    $field=[CiffNative]::Query($raw,'DF5AA02C-19F4-4258-90F2-8303907A2F05')
    $before=Read-Field $field
    [CiffPrinterNative]::UpdateData($component,$document,$field)
    $updated=Read-Field $field
    $size=[CiffPrinterNative]::CalculateSize($component,$document,$caps,$field)
    $afterSize=Read-Field $field
    $bitmap=$Mode+'-clarisoft-'+($before.name -replace '[^A-Za-z0-9_.-]','_')+'.png'
    $path=Join-Path $output $bitmap
    [FontOracle]::Draw($component,$field,$caps,$document,$path)
    $afterDraw=Read-Field $field
    $fields+=[ordered]@{name=$before.name;before=$before;updated=$updated;afterSize=$afterSize;afterDraw=$afterDraw;widthDots=$size.width;heightDots=$size.height;bitmap=('native-'+$Mode+'/'+$bitmap);rasterInkBounds=[NativeSavedFile]::Ink($path)}
   }finally{[CiffNative]::Release($field);[CiffNative]::Release($raw)}
  }}finally{[CiffNative]::Release($image)}
 }
 $fingerprints=@()
 foreach($dll in @('CiffMgr.dll','CiffHelper.dll','CLCSTextBasedField.dll','capabilitiesManager.dll')){
  $path=Join-Path 'C:/Program Files (x86)/CLARICOM/Data' $dll
  $fingerprints+=@{name=$dll;path=$path;sha256=(Get-FileHash -LiteralPath $path -Algorithm SHA256).Hash;fileVersion=[Diagnostics.FileVersionInfo]::GetVersionInfo($path).FileVersion}
 }
 $report=[ordered]@{mode=$Mode;file=(Resolve-Path -LiteralPath $ciffPath).Path;sourceSha256=$beforeHash;sourceSha256After=(Get-FileHash -LiteralPath $ciffPath -Algorithm SHA256).Hash;startedUtc=$startedUtc;finishedUtc=[DateTime]::UtcNow.ToString('o');method='Original installed ICiffManager.load(filename,null validator), original UpdateData/CalculateSize/Draw. No fields reconstructed, no license patches, no GUI screenshot implied.';designedFor=$designedFor;coder=$mapping[0].CoderName;xResolution=[CiffPrinterNative]::GetFloat($caps,0x2c);yResolution=[CiffPrinterNative]::GetFloat($caps,0x34);nativeFingerprints=$fingerprints;fields=$fields}
 [IO.File]::WriteAllText((Join-Path $output 'read-report.json'),($report|ConvertTo-Json -Depth 14),[Text.UTF8Encoding]::new($false))
 Write-Output ('Loaded {0}: {1} text fields, source hash unchanged={2}' -f $Mode,$fields.Count,($report.sourceSha256 -eq $report.sourceSha256After))
}finally{foreach($p in @($document,$component,$caps,$coders,$capsFile,$capsManager)){[CiffNative]::Release($p)}}
