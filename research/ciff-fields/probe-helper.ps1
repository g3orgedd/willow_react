$ErrorActionPreference = 'Stop'
Add-Type -Path (Join-Path $PSScriptRoot 'CiffNative.cs')
$lib = Get-Content -LiteralPath (Join-Path $PSScriptRoot 'metadata/CiffHelper.dll.typelib.json') -Raw | ConvertFrom-Json
$class = $lib.types | Where-Object name -eq 'CiffDataHelper'
$interface = $lib.types | Where-Object name -eq 'ICiffDataHelper12'
$instance = [CiffNative]::CreateClass($class.guid,$interface.guid)
try {
    $methods = @($interface.functions | Where-Object { $_.vtableOffset32 -ge 28 } | ForEach-Object {
        [PSCustomObject]@{method=$_.name; offset=$_.vtableOffset32;address=[CiffNative]::MethodAddress($instance,$_.vtableOffset32,'CiffHelper.dll',0x40800000)}
    })
    [IO.File]::WriteAllText((Join-Path $PSScriptRoot 'metadata/CiffHelper.dll.live-methods.json'),(ConvertTo-Json -InputObject $methods -Depth 5),(New-Object System.Text.UTF8Encoding($false)))
    $roots = $methods | Where-Object method -match '^Resolve|InitialiseDataValues|FindReference|FindFieldByName|RemoveUnreferenced|ReOrderDateOffsets|UpgradeCiff'
    [IO.File]::WriteAllLines((Join-Path $PSScriptRoot 'metadata/CiffHelper.dll.roots.txt'),[string[]]($roots | Select-Object -ExpandProperty address -Unique))
    $methods | Select-Object method,address
} finally { [CiffNative]::Release($instance) }
