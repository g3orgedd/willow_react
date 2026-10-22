$ErrorActionPreference='Stop'
$root=Split-Path -Parent (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))
Add-Type -Path @((Join-Path $root 'research/ciff-fields/CiffNative.cs'),(Join-Path $PSScriptRoot 'CiffClstOracle.cs'))
$types=(Get-Content -LiteralPath (Join-Path $root 'research/ciff-fields/metadata/CiffMgr.dll.typelib.json') -Raw|ConvertFrom-Json).types
$helperTypes=(Get-Content -LiteralPath (Join-Path $root 'research/ciff-fields/metadata/CiffHelper.dll.typelib.json') -Raw|ConvertFrom-Json).types
$helperInterface=$helperTypes|Where-Object name -eq 'ICiffDataHelper'
$helper=[CiffNative]::CreateClass('E86E92C2-C9C2-11D4-A996-00010212D541',$helperInterface.guid)
$inputs=Get-Content -LiteralPath (Join-Path $PSScriptRoot 'native-resolved-inputs.json') -Raw|ConvertFrom-Json
$rows=New-Object System.Collections.ArrayList
$utf16=New-Object System.Text.UnicodeEncoding($false,$true,$true)
function Set-Properties($pointer,$properties) {
  $type=$types|Where-Object name -eq 'ICiffDataObject8'
  foreach($property in $properties.PSObject.Properties) {
    $method=$type.functions|Where-Object {$_.name -eq $property.Name -and $_.invkind -eq 4}|Select-Object -First 1
    if(!$method){throw ('Missing native setter '+$property.Name)}
    if($method.parameters[0].type.vt -eq 8){[CiffNative]::SetString($pointer,$method.vtableOffset32,[string]$property.Value)}
    else{[CiffNative]::SetInt($pointer,$method.vtableOffset32,[int]$property.Value)}
  }
}
function Get-OptionalInt($pointer,$offset) {try{return [CiffNative]::GetInt($pointer,$offset)}catch{return $null}}
foreach($case in $inputs) {
  $document=[CiffNative]::Create();$image=[CiffNative]::AddSubImage($document,'1','Default',1600,1600,0)
  $fields=New-Object System.Collections.ArrayList
  $objects=New-Object System.Collections.ArrayList
  try {
    foreach($definition in $case.fields) {
      $field=[CiffNative]::AddField($image,[int]$definition.type,$definition.name,0)
      [void]$fields.Add($field)
      $data=[CiffNative]::GetPointer($field,0x5c)
      try {foreach($od in $definition.objects){
        $object=[CiffNative]::AddData($data,[int]$od.type,[int]$od.index,[bool]$od.static,[bool]$od.parse)
        [void]$objects.Add($object)
        Set-Properties $object $od.properties
      }} finally {[CiffNative]::Release($data)}
    }
    foreach($field in $fields){[CiffNative]::ResolveField($helper,$field,$document)}
    $snapshot=[CiffClstOracle]::Snapshot($document)
    $objectSnapshots=@(foreach($object in $objects){
      [ordered]@{currentDataUnits=[CiffClstOracle]::Units([CiffNative]::GetString($object,0x60));defaultDataUnits=[CiffClstOracle]::Units([CiffNative]::GetString($object,0x58));padChar=(Get-OptionalInt $object 0xa4);padMode=(Get-OptionalInt $object 0xac);fixedLength=(Get-OptionalInt $object 0x9c);maximum=(Get-OptionalInt $object 0x94)}
    })
    $xml=[CiffNative]::GetXml($document,1,1)
    [IO.File]::WriteAllText((Join-Path $PSScriptRoot ('resolved-'+$case.name+'.ciff')),$xml,$utf16)
    [void]$rows.Add([ordered]@{name=$case.name;status='ok';fields=$snapshot;objects=$objectSnapshots;nativeToken=[CiffNative]::GetString($document,0x78);validate=[CiffClstOracle]::Validate($document)})
  } catch {[void]$rows.Add([ordered]@{name=$case.name;status='error';error=$_.Exception.ToString()})}
  finally {foreach($o in $objects){[CiffNative]::Release($o)};foreach($f in $fields){[CiffNative]::Release($f)};[CiffNative]::Release($image);[CiffNative]::Release($document)}
}
[CiffNative]::Release($helper)
$report=[ordered]@{method='Original CiffHelper.ResolveField and CiffMgr properties/GetXml/Validate';processBits=32;cases=@($rows)}
[IO.File]::WriteAllText((Join-Path $PSScriptRoot 'native-resolved-results.json'),(ConvertTo-Json -InputObject $report -Depth 20),(New-Object System.Text.UTF8Encoding($false)))
[PSCustomObject]@{cases=$rows.Count;ok=@($rows|Where-Object status -eq 'ok').Count;errors=@($rows|Where-Object status -eq 'error').Count}|ConvertTo-Json
if(@($rows|Where-Object status -eq 'error').Count){exit 1}
