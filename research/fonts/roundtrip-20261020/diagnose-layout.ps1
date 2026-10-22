$ErrorActionPreference='Stop'
Add-Type -Path (Join-Path $PSScriptRoot 'NativeSavedFile.cs') -ReferencedAssemblies System.Drawing
$report=[IO.File]::ReadAllText((Join-Path $PSScriptRoot 'native-roundtrip-report.json'))|ConvertFrom-Json
$output=@()
for($n=0;$n -lt $report.fields.Count;$n++){
  $f=$report.fields[$n]
  $best=$null
  for($dy=-1;$dy -le 1;$dy++){for($dx=-1;$dx -le 1;$dx++){
    $different=[NativeSavedFile]::RegionDifference((Join-Path $PSScriptRoot 'glyph-layout.png'),(Join-Path $PSScriptRoot $f.bitmap),$report.xDots[$n],$report.yDots[$n],$dx,$dy)
    if($null -eq $best -or $different -lt $best.different){$best=@{different=$different;dx=$dx;dy=$dy}}
  }}
  $zero=[NativeSavedFile]::RegionDifference((Join-Path $PSScriptRoot 'glyph-layout.png'),(Join-Path $PSScriptRoot $f.bitmap),$report.xDots[$n],$report.yDots[$n],0,0)
  $output+=@{name=$f.name;zeroDifference=$zero;best=$best}
}
$json=$output|ConvertTo-Json -Depth 5
[IO.File]::WriteAllText((Join-Path $PSScriptRoot 'layout-diagnosis.json'),$json,[Text.UTF8Encoding]::new($false))
$json
