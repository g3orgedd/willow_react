$ErrorActionPreference='Stop'
Add-Type -Path (Join-Path $PSScriptRoot 'CiffNative.cs')
$modules=@('CLCSTextBasedField.dll','CLCSBarcodeField.dll','CLCSSmallBarcode.dll','CLCSGraphicBasedField.dll','CLCSGraphicPrimitive.dll','CLCSBlockTextField.dll','CLCSRichTextBlockField.dll')
$names=@('FixedText','TimeText','DateText','OffsetDateText','CounterText','SourceField','SourceData','EquipRef','Price','Barcode','SmallBarcode','DataMatrix','Graphic','StaticGraphic','VariableGraphic','EmbeddedGraphic','GraphicPrimitive','BlockText','RichText','Code128','EAN128','Code39','ITF','EAN13','EAN8','DataMatrixECC200','PDF417','MicroPDF417','QR','QRCode','MaxiCode','Line','OutlineBox','FilledBox','OutlineEllipse','FilledEllipse','PolyLine','Polygon','FilledPolygon')
$records=New-Object System.Collections.ArrayList
$unsupported=New-Object System.Collections.ArrayList
foreach($module in $modules) {
    $types=(Get-Content -LiteralPath (Join-Path $PSScriptRoot ('metadata/'+$module+'.typelib.json')) -Raw | ConvertFrom-Json).types
    $class=$types | Where-Object {$_.kind -eq 5 -and ($_.implements | Where-Object name -eq 'ICLCSGenericFieldObj')} | Select-Object -First 1
    $component=[CiffNative]::CreateClass($class.guid,'BB0561B1-C54F-11D4-A995-00010212D541')
    try {
        foreach($name in $names) {
            try { $value=[CiffNative]::FieldTypeId($component,$name) }
            catch { [void]$unsupported.Add([PSCustomObject]@{module=$module;typeName=$name;error=$_.Exception.Message}); continue }
            if($value -ge 0) { [void]$records.Add([PSCustomObject]@{module=$module;typeName=$name;typeId=$value;clsid=$class.guid}) }
        }
    } finally {[CiffNative]::Release($component)}
}
[IO.File]::WriteAllText((Join-Path $PSScriptRoot 'metadata/field-type-ids.json'),(ConvertTo-Json -InputObject @($records) -Depth 6),(New-Object System.Text.UTF8Encoding($false)))
[IO.File]::WriteAllText((Join-Path $PSScriptRoot 'metadata/field-type-id-rejections.json'),(ConvertTo-Json -InputObject @($unsupported) -Depth 6),(New-Object System.Text.UTF8Encoding($false)))
$records | Format-Table
