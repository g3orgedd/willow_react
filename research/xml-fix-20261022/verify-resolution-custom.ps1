param([Parameter(Mandatory=$true)][string]$OutputDirectory)
$ErrorActionPreference='Stop'
if([IntPtr]::Size -ne 4){throw 'Use original 32-bit Windows PowerShell'}
$workspace=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '../..'))
$output=[IO.Path]::GetFullPath($OutputDirectory)
Add-Type -Path (Join-Path $workspace 'research/fonts/vector-roundtrip-20261020/NativeSavedFile.cs') -ReferencedAssemblies System.Drawing
$referenceDirectory=Join-Path $workspace 'research/resolution-preview-20261022/native-field-resolutions'
$rows=@()
foreach($mode in @('web','exe')){
 foreach($kind in @('position','metrics')){
  $capture=Get-Content -LiteralPath (Join-Path $output ('custom-'+$kind+'-'+$mode+'.json')) -Raw|ConvertFrom-Json
  if((Get-FileHash -LiteralPath $capture.nativeReferenceFile -Algorithm SHA256).Hash -ine $capture.nativeReferenceSha256){throw 'Original native reference JSON changed'}
  foreach($field in $capture.captures){
   $r=$field.reference
   $native=Join-Path $referenceDirectory $(if($kind -eq 'position'){$r.prefix+'-origin.png'}else{$r.bitmap})
   $worker=Join-Path $output $field.workerBitmap
   $angle=if($kind -eq 'position'){[int]$r.orientation}else{0}
   $comparison=[NativeSavedFile]::Compare($native,$worker,$angle)
   $expectedW=if($kind -eq 'position'){$r.result.width}else{$r.sizeWidth}
   $expectedH=if($kind -eq 'position'){$r.result.height}else{$r.sizeHeight}
   $metricW=if($angle -eq 90 -or $angle -eq 270){$field.nativeMetrics.height}else{if($kind -eq 'position'){$field.nativeMetrics.width}else{$field.metrics.width}}
   $metricH=if($angle -eq 90 -or $angle -eq 270){$field.nativeMetrics.width}else{if($kind -eq 'position'){$field.nativeMetrics.height}else{$field.metrics.height}}
   $passed=$comparison.sameDimensions -and $comparison.different -eq 0 -and $metricW -eq $expectedW -and $metricH -eq $expectedH
   $rows+=[ordered]@{mode=$mode;kind=$kind;case=$r.case;face=$(if($kind -eq 'position'){'Arial'}else{$r.face});orientation=$angle;
    capsX=$r.capsX;capsY=$r.capsY;nativeBitmap=$native;nativeSha256=(Get-FileHash -LiteralPath $native -Algorithm SHA256).Hash;
    workerBitmap=$worker;workerSha256=(Get-FileHash -LiteralPath $worker -Algorithm SHA256).Hash;
    originalInk=[NativeSavedFile]::Ink($native);workerInkUnrotated=[NativeSavedFile]::Ink($worker);comparison=$comparison;
    expectedMetrics=[ordered]@{width=$expectedW;height=$expectedH};rotatedWorkerMetrics=[ordered]@{width=$metricW;height=$metricH};passed=$passed}
  }
 }
}
$report=[ordered]@{method='Captured actual HTTP/packaged-EXE worker raster versus independently generated original native COM Draw PNGs. Original PNGs are not GUI screenshots. Custom capabilities are controlled API/fallback tests, not a registered-printer binding.';
 finishedUtc=[DateTime]::UtcNow.ToString('o');cases=$rows;total=$rows.Count;passed=@($rows|Where-Object passed).Count;failed=@($rows|Where-Object {-not $_.passed}).Count}
[IO.File]::WriteAllText((Join-Path $output 'custom-raster-verification.json'),($report|ConvertTo-Json -Depth 16),[Text.UTF8Encoding]::new($false))
[pscustomobject]@{total=$report.total;passed=$report.passed;failed=$report.failed}|ConvertTo-Json
if($report.failed){exit 1}
