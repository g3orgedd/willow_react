param([string]$InputFile=(Join-Path $PSScriptRoot 'production-emitted-inputs.json'),[string]$OutputFile=(Join-Path $PSScriptRoot 'production-native-validation.json'))
$ErrorActionPreference='Stop'
$root=Split-Path -Parent (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))
Add-Type -Path @((Join-Path $root 'research/ciff-fields/CiffNative.cs'),(Join-Path $PSScriptRoot 'CiffClstOracle.cs'))
$inputs=Get-Content -LiteralPath $InputFile -Raw|ConvertFrom-Json
$rows=New-Object System.Collections.ArrayList
$helper=[IntPtr]::Zero
foreach($case in $inputs){
 $document=[IntPtr]::Zero
 try {
  $beforeHash=[CiffClstOracle]::FileSha256($case.file)
  $document=[CiffClstOracle]::Load($case.file)
  $tokenLoaded=[CiffNative]::GetString($document,0x78)
  $snapshot=[CiffClstOracle]::Snapshot($document)
  $validate=[CiffClstOracle]::Validate($document)
  $validate2=[CiffClstOracle]::Validate2($document)
  $afterNativeResolve=$null
  if($case.verifyNativeResolve){
   if($helper -eq [IntPtr]::Zero){
    $helperTypes=(Get-Content -LiteralPath (Join-Path $root 'research/ciff-fields/metadata/CiffHelper.dll.typelib.json') -Raw|ConvertFrom-Json).types
    $helperInterface=$helperTypes|Where-Object name -eq 'ICiffDataHelper'
    $helper=[CiffNative]::CreateClass('E86E92C2-C9C2-11D4-A996-00010212D541',$helperInterface.guid)
   }
   for($si=1;$si -le [CiffNative]::GetInt($document,0x1c);$si++){
    $image=[CiffClstOracle]::Item($document,$si)
    try{for($fi=1;$fi -le [CiffNative]::GetInt($image,0x1c);$fi++){
     $field=[CiffClstOracle]::Item($image,$fi)
     try{[CiffNative]::ResolveField($helper,$field,$document)}finally{[CiffNative]::Release($field)}
    }}finally{[CiffNative]::Release($image)}
   }
   $afterNativeResolve=[CiffClstOracle]::Snapshot($document)
  }
  $regenerated=[CiffNative]::GetXml($document,1,1)
  $regeneratedToken=[CiffNative]::GetString($document,0x78)
  [void]$rows.Add([ordered]@{name=$case.name;kind=$case.kind;file=$case.file;status='ok';loadedToken=$tokenLoaded;loadedFields=$snapshot;afterNativeResolve=$afterNativeResolve;validate=$validate;validate2=$validate2;expectedValidation=$case.expectedValidation;regeneratedToken=$regeneratedToken;regeneratedXml=$regenerated;sourceSha256=$beforeHash;sourceSha256After=[CiffClstOracle]::FileSha256($case.file)})
 }catch{
  $failure=$_.Exception
  while($failure.InnerException){$failure=$failure.InnerException}
  $hr=([uint32]([int64]$failure.HResult -band 4294967295)).ToString('X8')
  [void]$rows.Add([ordered]@{name=$case.name;kind=$case.kind;file=$case.file;status=$(if($hr -eq $case.expectedValidation){'rejected'}else{'error'});loadHresult=$hr;expectedValidation=$case.expectedValidation;error=$failure.Message})
 }
 finally{[CiffNative]::Release($document)}
}
[CiffNative]::Release($helper)
$report=[ordered]@{method='Original ICiffManager.load(file,null), ICiffFile.Validate(null), ICiffFile4.Validate2(null,null), GetXml(1,1)';processBits=32;cases=@($rows)}
[IO.File]::WriteAllText($OutputFile,(ConvertTo-Json -InputObject $report -Depth 25),(New-Object System.Text.UTF8Encoding($false)))
[PSCustomObject]@{cases=$rows.Count;ok=@($rows|Where-Object status -eq 'ok').Count;rejected=@($rows|Where-Object status -eq 'rejected').Count;errors=@($rows|Where-Object status -eq 'error').Count;expectedVerdicts=@($rows|Where-Object {($_.status -eq 'ok' -and $_.validate -eq $_.expectedValidation) -or ($_.status -eq 'rejected' -and $_.loadHresult -eq $_.expectedValidation)}).Count}|ConvertTo-Json
if(@($rows|Where-Object status -eq 'error').Count){exit 1}
