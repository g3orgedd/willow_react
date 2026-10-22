$ErrorActionPreference='Stop'
Add-Type -Path (Join-Path $PSScriptRoot 'CiffNative.cs')
$records=New-Object System.Collections.ArrayList
foreach($module in @('CLCiffConversion_Data.dll','CLCiffConversion_Layout.dll')) {
    $library=Get-Content -LiteralPath (Join-Path $PSScriptRoot ('metadata/'+$module+'.typelib.json')) -Raw | ConvertFrom-Json
    $class=$library.types | Where-Object kind -eq 5
    $interfaceName=if($module -eq 'CLCiffConversion_Data.dll') {'ICiffConversion_Data'} else {'ICiffConversion_Layout'}
    $interface=$library.types | Where-Object name -eq $interfaceName
    $instance=[CiffNative]::CreateClass($class.guid,$interface.guid)
    $inventory=Get-Content -LiteralPath (Join-Path $PSScriptRoot 'inventory.json') -Raw | ConvertFrom-Json
    $base=($inventory | Where-Object name -eq $module).imageBase
    try {
        foreach($method in $interface.functions | Where-Object vtableOffset32 -ge 28) {
            [void]$records.Add([PSCustomObject]@{module=$module;method=$method.name;offset=$method.vtableOffset32;address=[CiffNative]::MethodAddress($instance,$method.vtableOffset32,$module,[Convert]::ToUInt32($base,16))})
        }
    } finally {[CiffNative]::Release($instance)}
}
[IO.File]::WriteAllText((Join-Path $PSScriptRoot 'metadata/conversion-methods.json'),(ConvertTo-Json -InputObject @($records) -Depth 6),(New-Object System.Text.UTF8Encoding($false)))
$records | Format-Table
