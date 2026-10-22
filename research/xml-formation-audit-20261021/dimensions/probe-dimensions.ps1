$ErrorActionPreference = 'Stop'
$workspace = (Resolve-Path (Join-Path $PSScriptRoot '../../..')).Path
Add-Type -Path @((Join-Path $workspace 'research/ciff-fields/CiffNative.cs'), (Join-Path $workspace 'research/clst/implementation-2026-10-21/CiffClstOracle.cs'))
$utf16 = New-Object System.Text.UnicodeEncoding($false,$true,$true)
$rows = New-Object System.Collections.ArrayList
function Read-Dimensions($image) {
  $typed = [CiffNative]::Query($image,'9DA85228-EF2E-47C1-9E87-93D03D8CB08F')
  try { return [ordered]@{ ImageWidth=[CiffNative]::GetInt($typed,0x3c); ImageHeight=[CiffNative]::GetInt($typed,0x44); MaxImageWidth=[CiffNative]::GetInt($typed,0x5c); MaxImageHeight=[CiffNative]::GetInt($typed,0x64); AutoSize=[CiffNative]::GetInt($typed,0xa4); ImageRotation=[CiffNative]::GetInt($typed,0x54); CurrentOrientation=[CiffNative]::GetInt($typed,0xd4); FieldCount=[CiffNative]::GetInt($typed,0x1c) } }
  finally { [CiffNative]::Release($typed) }
}
function Run-CreateCase($name,$width,$height,$outside,$displayed) {
 $doc=[IntPtr]::Zero;$image=[IntPtr]::Zero;$field=[IntPtr]::Zero
 try {
  $doc=[CiffNative]::Create();$image=[CiffNative]::AddSubImage($doc,'1','Default',$width,$height,0)
  $before=Read-Dimensions $image
  if($outside) {
   $field=[CiffNative]::AddField($image,0,'Field00',0)
   [CiffNative]::SetInt($field,0x28,$displayed)
   [CiffNative]::SetInt($field,0x30,2500);[CiffNative]::SetInt($field,0x38,3000)
   [CiffNative]::SetInt($field,0x7c,700);[CiffNative]::SetInt($field,0x84,500)
  }
  $afterField=Read-Dimensions $image
  $xml=[CiffNative]::GetString($doc,0x38)
  $afterWriter=Read-Dimensions $image
  [IO.File]::WriteAllText((Join-Path $PSScriptRoot ($name+'.output.ciff')),$xml,$utf16)
  [void]$rows.Add([ordered]@{name=$name;kind='Original AddSubImage/AddField/savetostring';status='ok';before=$before;afterField=$afterField;afterWriter=$afterWriter;xml=$xml})
 } catch { [void]$rows.Add([ordered]@{name=$name;status='error';error=$_.Exception.ToString()}) }
 finally { [CiffNative]::Release($field);[CiffNative]::Release($image);[CiffNative]::Release($doc) }
}
Run-CreateCase 'create-empty-1600x2400' 1600 2400 $false 0
Run-CreateCase 'create-empty-zero' 0 0 $false 0
Run-CreateCase 'create-empty-negative' -100 -200 $false 0
Run-CreateCase 'create-printed-outside' 1600 2400 $true 1
Run-CreateCase 'create-hidden-outside' 1600 2400 $true 0
$cases=@(
 @{name='baseline';image='<ImageWidth>987</ImageWidth><ImageHeight>1140</ImageHeight>';max='<MaxImageWidth>1600</MaxImageWidth><MaxImageHeight>2000</MaxImageHeight>'},
 @{name='small-image-large-max';image='<ImageWidth>600</ImageWidth><ImageHeight>700</ImageHeight>';max='<MaxImageWidth>2000</MaxImageWidth><MaxImageHeight>3000</MaxImageHeight>'},
 @{name='large-image-small-max';image='<ImageWidth>2516</ImageWidth><ImageHeight>2558</ImageHeight>';max='<MaxImageWidth>1600</MaxImageWidth><MaxImageHeight>1600</MaxImageHeight>'},
 @{name='zero-image';image='<ImageWidth>0</ImageWidth><ImageHeight>0</ImageHeight>';max='<MaxImageWidth>1600</MaxImageWidth><MaxImageHeight>2000</MaxImageHeight>'},
 @{name='negative-image';image='<ImageWidth>-200</ImageWidth><ImageHeight>-300</ImageHeight>';max='<MaxImageWidth>1600</MaxImageWidth><MaxImageHeight>2000</MaxImageHeight>'},
 @{name='missing-image-both';image='';max='<MaxImageWidth>1600</MaxImageWidth><MaxImageHeight>2000</MaxImageHeight>'},
 @{name='missing-image-width';image='<ImageHeight>700</ImageHeight>';max='<MaxImageWidth>1600</MaxImageWidth><MaxImageHeight>2000</MaxImageHeight>'},
 @{name='missing-image-height';image='<ImageWidth>600</ImageWidth>';max='<MaxImageWidth>1600</MaxImageWidth><MaxImageHeight>2000</MaxImageHeight>'},
 @{name='missing-max-both';image='<ImageWidth>600</ImageWidth><ImageHeight>700</ImageHeight>';max=''},
 @{name='missing-max-width';image='<ImageWidth>600</ImageWidth><ImageHeight>700</ImageHeight>';max='<MaxImageHeight>2000</MaxImageHeight>'},
 @{name='zero-max';image='<ImageWidth>600</ImageWidth><ImageHeight>700</ImageHeight>';max='<MaxImageWidth>0</MaxImageWidth><MaxImageHeight>0</MaxImageHeight>'},
 @{name='negative-max';image='<ImageWidth>600</ImageWidth><ImageHeight>700</ImageHeight>';max='<MaxImageWidth>-100</MaxImageWidth><MaxImageHeight>-200</MaxImageHeight>'},
 @{name='missing-all';image='';max=''}
)
foreach($base in @($cases[0],$cases[1],$cases[2])) {
 foreach($auto in 0,1) { $cases+=@{name=($base.name+'-autosize'+$auto);image=$base.image;max=$base.max;extra=('<AutoSize>'+$auto+'</AutoSize>')} }
 foreach($rotation in 90,270) { $cases+=@{name=($base.name+'-rotation'+$rotation);image=$base.image;max=$base.max;extra=('<ImageRotation>'+$rotation+'</ImageRotation>')} }
}
foreach($displayed in 0,1) {
 $cases+=@{name=('outside-field-displayed'+$displayed);image='<ImageWidth>600</ImageWidth><ImageHeight>700</ImageHeight>';max='<MaxImageWidth>1600</MaxImageWidth><MaxImageHeight>2000</MaxImageHeight>';field=('<Field Name="Field00"><FldType>FixedText</FldType><Displayed>'+$displayed+'</Displayed><X>2500</X><Y>3000</Y><W>700</W><H>500</H><CalcData><![CDATA[ABC]]></CalcData><Data><Object><DataType>0</DataType><Default><![CDATA[ABC]]></Default></Object></Data><Text><Font><Pitch>10</Pitch></Font></Text></Field>')}
}
foreach($displayed in 0,1) {
 $source=$cases|Where-Object name -eq ('outside-field-displayed'+$displayed)|Select-Object -First 1
 foreach($auto in 0,1) {$cases+=@{name=($source.name+'-autosize'+$auto);image=$source.image;max=$source.max;field=$source.field;extra=('<AutoSize>'+$auto+'</AutoSize>')}}
}
foreach($name in @('zero-image','negative-image')) {
 $source=$cases|Where-Object name -eq $name|Select-Object -First 1
 $cases+=@{name=($name+'-autosize1');image=$source.image;max=$source.max;extra='<AutoSize>1</AutoSize>'}
}
foreach($case in $cases) {
 $doc=[IntPtr]::Zero;$image=[IntPtr]::Zero
 try {
  $xml='<?xml version="1.0" encoding="UTF-16"?><ImageDesign Version="23" xml:space="default"><Header DesignedFor="DataFlex 6320(53mm) - Continuous"/><SubImage ImageReference="1"><SubHeader FormatName="Default">'+$case.image+$case.max+$case.extra+'<XRes>0.120000</XRes></SubHeader>'+$case.field+'</SubImage><GenericSettings><ImageMapping><Map SubIMageRef="1">1</Map></ImageMapping></GenericSettings></ImageDesign>'
  [IO.File]::WriteAllText((Join-Path $PSScriptRoot ($case.name+'.input.ciff')),$xml,$utf16)
  $doc=[CiffNative]::Create();[CiffNative]::SetString($doc,0xb0,$xml)
  $count=[CiffNative]::GetInt($doc,0x1c)
  if($count -gt 0) {$image=[CiffClstOracle]::Item($doc,1);$loaded=Read-Dimensions $image}else{$loaded=$null}
  $output=[CiffNative]::GetString($doc,0x38)
  [IO.File]::WriteAllText((Join-Path $PSScriptRoot ($case.name+'.output.ciff')),$output,$utf16)
  if($count -gt 0){$afterWriter=Read-Dimensions $image}else{$afterWriter=$null}
  [void]$rows.Add([ordered]@{name=$case.name;kind='Original ICiffFile.loadfromstring/savetostring';status='ok';subImageCount=$count;loaded=$loaded;afterWriter=$afterWriter;xml=$output})
 } catch { [void]$rows.Add([ordered]@{name=$case.name;status='error';error=$_.Exception.ToString()}) }
 finally {[CiffNative]::Release($image);[CiffNative]::Release($doc)}
}
$report=[ordered]@{processBits=32;method='Unmodified registered CiffMgr COM interfaces; no GUI, no clipping or app size aggregation assumed';cases=@($rows)}
[IO.File]::WriteAllText((Join-Path $PSScriptRoot 'native-dimension-probes.json'),(ConvertTo-Json -InputObject $report -Depth 12),(New-Object System.Text.UTF8Encoding($false)))
[pscustomobject]@{cases=$rows.Count;ok=@($rows|Where-Object status -eq 'ok').Count;errors=@($rows|Where-Object status -eq 'error').Count}|ConvertTo-Json
