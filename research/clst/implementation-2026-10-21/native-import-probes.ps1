$ErrorActionPreference='Stop'
$root=Split-Path -Parent (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))
Add-Type -Path @((Join-Path $root 'research/ciff-fields/CiffNative.cs'),(Join-Path $PSScriptRoot 'CiffClstOracle.cs'))
$helperTypes=(Get-Content -LiteralPath (Join-Path $root 'research/ciff-fields/metadata/CiffHelper.dll.typelib.json') -Raw|ConvertFrom-Json).types
$helperInterface=$helperTypes|Where-Object name -eq 'ICiffDataHelper'
$helper=[CiffNative]::CreateClass('E86E92C2-C9C2-11D4-A996-00010212D541',$helperInterface.guid)
$cases=Get-Content -LiteralPath (Join-Path $PSScriptRoot 'native-import-inputs.json') -Raw|ConvertFrom-Json
$rows=@(foreach($case in $cases){
 $document=[CiffClstOracle]::Load($case.file)
 try{
  $before=[CiffClstOracle]::Snapshot($document);$properties=@()
  for($si=1;$si -le [CiffNative]::GetInt($document,0x1c);$si++){
   $image=[CiffClstOracle]::Item($document,$si)
   try{for($fi=1;$fi -le [CiffNative]::GetInt($image,0x1c);$fi++){
    $field=[CiffClstOracle]::Item($image,$fi)
    try{
     $data=[CiffNative]::GetPointer($field,0x5c)
     try{for($di=1;$di -le [CiffNative]::GetInt($data,0x1c);$di++){
      $object=[CiffClstOracle]::Item($data,$di)
      try{$user=$null;try{$user=[CiffClstOracle]::Units([CiffNative]::GetString($object,0xcc))}catch{};$properties+=@{subImage=$si;field=$fi;index=$di;defaultUnits=[CiffClstOracle]::Units([CiffNative]::GetString($object,0x58));userUnits=$user}}
      finally{[CiffNative]::Release($object)}
     }}finally{[CiffNative]::Release($data)}
     [CiffNative]::ResolveField($helper,$field,$document)
    }finally{[CiffNative]::Release($field)}
   }}finally{[CiffNative]::Release($image)}
  }
  [ordered]@{name=$case.name;before=$before;after=[CiffClstOracle]::Snapshot($document);properties=$properties}
 }finally{[CiffNative]::Release($document)}
})
[CiffNative]::Release($helper)
[IO.File]::WriteAllText((Join-Path $PSScriptRoot 'native-import-results.json'),(ConvertTo-Json -InputObject @{method='Original XML import from unmodified entity source, property getters and CiffHelper.ResolveField';cases=$rows} -Depth 20),(New-Object System.Text.UTF8Encoding($false)))
$rows|ConvertTo-Json -Depth 9
