$ErrorActionPreference='Stop'
$root=Split-Path -Parent (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))
Add-Type -Path @((Join-Path $root 'research/ciff-fields/CiffNative.cs'),(Join-Path $PSScriptRoot 'CiffClstOracle.cs'))
$helperTypes=(Get-Content -LiteralPath (Join-Path $root 'research/ciff-fields/metadata/CiffHelper.dll.typelib.json') -Raw|ConvertFrom-Json).types
$helperInterface=$helperTypes|Where-Object name -eq 'ICiffDataHelper'
$helper=[CiffNative]::CreateClass('E86E92C2-C9C2-11D4-A996-00010212D541',$helperInterface.guid)
$cases=(Get-Content -LiteralPath (Join-Path $PSScriptRoot 'native-resolved-results.json') -Raw|ConvertFrom-Json).cases
$rows=@(foreach($case in $cases){
 $document=[CiffClstOracle]::Load((Join-Path $PSScriptRoot ('resolved-'+$case.name+'.ciff')))
 try{
  $before=[CiffClstOracle]::Snapshot($document)
  $image=[CiffClstOracle]::Item($document,1)
  $objects=@()
  try{for($fi=1;$fi -le [CiffNative]::GetInt($image,0x1c);$fi++){
   $field=[CiffClstOracle]::Item($image,$fi)
   try{
    [CiffNative]::ResolveField($helper,$field,$document)
    $data=[CiffNative]::GetPointer($field,0x5c)
    try{for($di=1;$di -le [CiffNative]::GetInt($data,0x1c);$di++){
     $object=[CiffClstOracle]::Item($data,$di)
     try{$char=$null;$mode=$null;try{$char=[CiffNative]::GetInt($object,0xa4);$mode=[CiffNative]::GetInt($object,0xac)}catch{};$objects+=@{fieldIndex=$fi;index=$di;padChar=$char;padMode=$mode}}
     finally{[CiffNative]::Release($object)}
    }}finally{[CiffNative]::Release($data)}
   }finally{[CiffNative]::Release($field)}
  }}finally{[CiffNative]::Release($image)}
  [ordered]@{name=$case.name;before=$before;after=[CiffClstOracle]::Snapshot($document);objects=$objects}
 }finally{[CiffNative]::Release($document)}
})
[CiffNative]::Release($helper)
[IO.File]::WriteAllText((Join-Path $PSScriptRoot 'native-resolved-reloaded.json'),(ConvertTo-Json -InputObject @{method='Original COM load of own XML and CiffHelper.ResolveField again';cases=$rows} -Depth 20),(New-Object System.Text.UTF8Encoding($false)))
