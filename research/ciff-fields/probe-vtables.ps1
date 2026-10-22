$ErrorActionPreference = 'Stop'
Add-Type -Path (Join-Path $PSScriptRoot 'CiffNative.cs')
$inventory = Get-Content -LiteralPath (Join-Path $PSScriptRoot 'inventory.json') -Raw | ConvertFrom-Json
$records = New-Object System.Collections.ArrayList
function Describe-Interface($pointer, $type, $module) {
    $queried = [CiffNative]::Query($pointer, $type.guid)
    try {
        foreach ($method in $type.functions) {
            [void]$records.Add([PSCustomObject]@{
                module = $module.name
                interface = $type.name
                method = $method.name
                invocation = $method.invkind
                offset = $method.vtableOffset32
                address = [CiffNative]::MethodAddress($queried,$method.vtableOffset32,$module.name,[Convert]::ToUInt32($module.imageBase,16))
            })
        }
    } finally { [CiffNative]::Release($queried) }
}
$core = Get-Content -LiteralPath (Join-Path $PSScriptRoot 'metadata/CiffMgr.dll.typelib.json') -Raw | ConvertFrom-Json
$coreModule = $inventory | Where-Object name -eq 'CiffMgr.dll'
$document = [CiffNative]::Create()
$image = [CiffNative]::AddSubImage($document,'1','Default',1600,1600,0)
try {
    foreach ($type in $core.types | Where-Object name -match '^ICiffFile[0-9]*$') { Describe-Interface $document $type $coreModule }
    foreach ($type in $core.types | Where-Object name -match '^ICiffSubImage[0-9]*$') { Describe-Interface $image $type $coreModule }
    foreach ($fieldType in 0,1,2) {
        $field = [CiffNative]::AddField($image,$fieldType,"Field$fieldType",0)
        $data = [CiffNative]::GetPointer($field,0x5c)
        $object = [CiffNative]::AddData($data,0,0,$true,$false)
        try {
            $pattern = @('^ICiffTextField[0-9]*$','^ICiffBarcodeField[0-9]*$','^ICiffGfxField[0-9]*$')[$fieldType]
            foreach ($type in $core.types | Where-Object name -match $pattern) { Describe-Interface $field $type $coreModule }
            if ($fieldType -eq 0) {
                foreach ($type in $core.types | Where-Object name -eq 'ICiffFieldData') { Describe-Interface $data $type $coreModule }
                foreach ($type in $core.types | Where-Object name -match '^ICiffDataObject[0-9]*$') { Describe-Interface $object $type $coreModule }
            }
        } finally { [CiffNative]::Release($object); [CiffNative]::Release($data); [CiffNative]::Release($field) }
    }
} finally { [CiffNative]::Release($image); [CiffNative]::Release($document) }
foreach ($module in $inventory | Where-Object name -match '^CLCS.*Field.dll$|^CLCSGraphicPrimitive.dll$|^CLCSSmallBarcode.dll$') {
    $lib = Get-Content -LiteralPath (Join-Path $PSScriptRoot ('metadata/'+$module.name+'.typelib.json')) -Raw | ConvertFrom-Json
    $class = $lib.types | Where-Object { $_.kind -eq 5 -and ($_.implements | Where-Object name -eq 'ICLCSGenericFieldObj') } | Select-Object -First 1
    if (!$class) { continue }
    $instance = [CiffNative]::CreateClass($class.guid,'BB0561B1-C54F-11D4-A995-00010212D541')
    try {
        foreach ($type in $lib.types | Where-Object name -eq 'ICLCSGenericFieldObj') { Describe-Interface $instance $type $module }
    } finally { [CiffNative]::Release($instance) }
}
$json = ConvertTo-Json -InputObject @($records) -Depth 8
[IO.File]::WriteAllText((Join-Path $PSScriptRoot 'metadata/live-vtables.json'),$json,(New-Object System.Text.UTF8Encoding($false)))
foreach ($group in $records | Group-Object module) {
    $addresses = $group.Group | Select-Object -ExpandProperty address -Unique | Sort-Object
    [IO.File]::WriteAllLines((Join-Path $PSScriptRoot ('metadata/'+$group.Name+'.entries.txt')),$addresses)
    [PSCustomObject]@{module=$group.Name; methods=$group.Count; uniqueFunctions=$addresses.Count}
}
