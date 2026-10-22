param([string]$CasesPath = (Join-Path $PSScriptRoot 'oracle-cases.json'))
$ErrorActionPreference = 'Stop'
Add-Type -Path (Join-Path $PSScriptRoot 'CiffNative.cs')
$types = (Get-Content -LiteralPath (Join-Path $PSScriptRoot 'metadata/CiffMgr.dll.typelib.json') -Raw | ConvertFrom-Json).types
$helperTypes = (Get-Content -LiteralPath (Join-Path $PSScriptRoot 'metadata/CiffHelper.dll.typelib.json') -Raw | ConvertFrom-Json).types
$helperInterface = $helperTypes | Where-Object name -eq 'ICiffDataHelper'
$helper = [CiffNative]::CreateClass('E86E92C2-C9C2-11D4-A996-00010212D541',$helperInterface.guid)
$output = Join-Path $PSScriptRoot 'oracle'
[IO.Directory]::CreateDirectory($output) | Out-Null
$utf16 = New-Object System.Text.UnicodeEncoding($false,$true,$true)
$results = New-Object System.Collections.ArrayList
function Set-Properties($pointer, $interfaceName, $properties) {
    if (!$properties) { return }
    $type = $types | Where-Object name -eq $interfaceName
    $target = [CiffNative]::Query($pointer,$type.guid)
    try {
        foreach ($property in $properties.PSObject.Properties) {
            $method = $type.functions | Where-Object { $_.name -eq $property.Name -and $_.invkind -eq 4 } | Select-Object -First 1
            if (!$method) { throw "Missing setter $interfaceName.$($property.Name)" }
            $vt = $method.parameters[0].type.vt
            if ($vt -eq 8) { [CiffNative]::SetString($target,$method.vtableOffset32,$property.Value) }
            elseif ($vt -eq 2 -or $vt -eq 3 -or $vt -eq 29) { [CiffNative]::SetInt($target,$method.vtableOffset32,[int]$property.Value) }
            elseif ($vt -eq 4) { [CiffNative]::SetFloat($target,$method.vtableOffset32,[single]$property.Value) }
            else { throw "Unsupported native setter type $vt" }
        }
    } finally { [CiffNative]::Release($target) }
}
$cases = Get-Content -LiteralPath $CasesPath -Raw | ConvertFrom-Json
foreach ($case in $cases) {
    $document = [CiffNative]::Create()
    $image = [IntPtr]::Zero
    try {
        $image = [CiffNative]::AddSubImage($document,'1','Default',1600,1600,0)
        foreach ($definition in $case.fields) {
            $field = [CiffNative]::AddField($image,[int]$definition.type,$definition.name,[int]$definition.subtype)
            $data = [IntPtr]::Zero
            try {
                $fieldInterface = @('ICiffTextField7','ICiffBarcodeField13','ICiffGfxField2')[[int]$definition.type]
                Set-Properties $field $fieldInterface $definition.properties
                if ($definition.objects) {
                    $data = [CiffNative]::GetPointer($field,0x5c)
                    foreach ($objectDefinition in $definition.objects) {
                        $object = [CiffNative]::AddData($data,[int]$objectDefinition.type,[int]$objectDefinition.index,[bool]$objectDefinition.static,[bool]$objectDefinition.parse)
                        try {
                            Set-Properties $object 'ICiffDataObject8' $objectDefinition.properties
                            foreach ($counterDefinition in $objectDefinition.subCounters) {
                                $counter = [CiffNative]::AddSubCounter($object,[int]$counterDefinition.significance,[bool]$counterDefinition.alphaNumeric,[int16]$counterDefinition.leadCharacter,[int]$counterDefinition.order)
                                try { Set-Properties $counter 'ICiffSubCounter3' $counterDefinition.properties }
                                finally { [CiffNative]::Release($counter) }
                            }
                        }
                        finally { [CiffNative]::Release($object) }
                    }
                }
                if ($case.resolve -or $definition.resolve) { [CiffNative]::ResolveField($helper,$field,$document) }
            } finally { [CiffNative]::Release($data); [CiffNative]::Release($field) }
        }
        $xml = [CiffNative]::GetString($document,0x38)
        if ($case.generateClSt) { $xml = [CiffNative]::GetXml($document,1,1) }
        $filename = $case.name + '.ciff'
        [IO.File]::WriteAllText((Join-Path $output $filename),$xml,$utf16)
        [void]$results.Add([PSCustomObject]@{name=$case.name;status='ok';file=$filename;characters=$xml.Length})
    } catch {
        [void]$results.Add([PSCustomObject]@{name=$case.name;status='error';error=$_.Exception.Message})
    } finally { [CiffNative]::Release($image); [CiffNative]::Release($document) }
}
$report = [PSCustomObject]@{source='Installed CiffMgr.dll through original COM vtables';processBits=32;cases=@($results)}
[CiffNative]::Release($helper)
[IO.File]::WriteAllText((Join-Path $output 'results.json'),(ConvertTo-Json -InputObject $report -Depth 10),(New-Object System.Text.UTF8Encoding($false)))
[PSCustomObject]@{cases=$results.Count;ok=@($results | Where-Object status -eq 'ok').Count;errors=@($results | Where-Object status -eq 'error').Count} | ConvertTo-Json
