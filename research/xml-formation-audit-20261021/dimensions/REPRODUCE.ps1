$ErrorActionPreference = 'Stop'
$workspace = (Resolve-Path (Join-Path $PSScriptRoot '../../..')).Path
$ghidra = 'C:/Users/GigaGeorge/Desktop/ghidra_12.1.3_PUBLIC/support/analyzeHeadless.bat'
$output = Join-Path $PSScriptRoot 'decompiled'
$applicationProjects = Join-Path $workspace 'research/ciff-fields/ghidra-project'
$ciffProjects = Join-Path $workspace 'research/clst/ghidra-project'

# All headless operations are sequential. Do not open the same project in Ghidra GUI.
function Export-AuditFunctions($projectDirectory, $projectName, $program, $listName, $logName) {
  & $ghidra $projectDirectory $projectName -process $program -noanalysis -scriptPath $PSScriptRoot -postScript ExportDimensionAudit.java $output 0 0 (Join-Path $PSScriptRoot $listName) -log (Join-Path $PSScriptRoot $logName)
  if ($LASTEXITCODE -ne 0) { throw "Headless export failed: $projectName/$listName" }
}

Export-AuditFunctions $applicationProjects 'ClariSoftApplication' 'CLARiSOFT.exe' 'application-functions.txt' 'decompile-application-functions.log'
Export-AuditFunctions $applicationProjects 'ClariSoftApplication' 'CLARiSOFT.exe' 'application-functions-extra.txt' 'decompile-application-extra.log'
Export-AuditFunctions $applicationProjects 'ClariSoftApplication' 'CLARiSOFT.exe' 'application-bounds-context.txt' 'decompile-bounds-context.log'
Export-AuditFunctions $applicationProjects 'ClariSoftApplication' 'CLARiSOFT.exe' 'application-quantize.txt' 'decompile-quantize.log'
# The document range and the print-dialog range were freshly exported in addition
# to explicit roots, to retain surrounding control flow in this audit directory.
& $ghidra $applicationProjects ClariSoftApplication -process CLARiSOFT.exe -noanalysis -scriptPath $PSScriptRoot -postScript ExportDimensionAudit.java $output 00e2a000 00e2f700 -log (Join-Path $PSScriptRoot 'decompile-document-range.log')
& $ghidra $applicationProjects ClariSoftApplication -process CLARiSOFT.exe -noanalysis -scriptPath $PSScriptRoot -postScript ExportDimensionAudit.java $output 00e98d5f 00e992cf -log (Join-Path $PSScriptRoot 'decompile-preview.log')
Export-AuditFunctions $ciffProjects 'ClstResearch' 'CiffMgr.dll' 'ciff-functions.txt' 'decompile-ciff-sizes.log'

if (-not (Test-Path -LiteralPath (Join-Path $applicationProjects 'DimensionPrintPreview.gpr'))) {
  New-Item -ItemType Directory -Path (Join-Path $PSScriptRoot 'binaries') -Force | Out-Null
  Copy-Item -LiteralPath 'C:/Program Files (x86)/CLARICOM/Data/CLPrintPreview.ocx' -Destination (Join-Path $PSScriptRoot 'binaries/CLPrintPreview.ocx')
  & $ghidra $applicationProjects DimensionPrintPreview -import (Join-Path $PSScriptRoot 'binaries/CLPrintPreview.ocx') -analysisTimeoutPerFile 120 -scriptPath $PSScriptRoot -postScript ExportDimensionAudit.java $output 0 0 -log (Join-Path $PSScriptRoot 'decompile-preview-ocx-import.log')
}
Export-AuditFunctions $applicationProjects 'DimensionPrintPreview' 'CLPrintPreview.ocx' 'preview-functions.txt' 'decompile-preview-ocx.log'
Export-AuditFunctions $applicationProjects 'DimensionPrintPreview' 'CLPrintPreview.ocx' 'preview-central-functions.txt' 'decompile-preview-central.log'
Export-AuditFunctions $applicationProjects 'DimensionPrintPreview' 'CLPrintPreview.ocx' 'preview-canvas-functions.txt' 'decompile-preview-canvas.log'
Export-AuditFunctions $applicationProjects 'DimensionPrintPreview' 'CLPrintPreview.ocx' 'preview-paint-functions.txt' 'decompile-preview-paint.log'

& 'C:/Windows/SysWOW64/WindowsPowerShell/v1.0/powershell.exe' -NoProfile -ExecutionPolicy Bypass -File (Join-Path $PSScriptRoot 'probe-preview-vtable.ps1')
& 'C:/Windows/SysWOW64/WindowsPowerShell/v1.0/powershell.exe' -NoProfile -ExecutionPolicy Bypass -File (Join-Path $PSScriptRoot 'probe-dimensions.ps1')
