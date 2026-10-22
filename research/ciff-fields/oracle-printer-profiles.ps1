param([int]$Limit = 0)
$ErrorActionPreference='Stop'
Add-Type -Path (Join-Path $PSScriptRoot 'CiffNative.cs')
Add-Type -Path (Join-Path $PSScriptRoot 'CiffPrinterNative.cs')
$output=Join-Path $PSScriptRoot 'printer-oracle'
[IO.Directory]::CreateDirectory($output) | Out-Null
$mappings=Get-Content -LiteralPath (Join-Path $output 'profile-mappings.json') -Raw | ConvertFrom-Json
$profiles=$mappings | Where-Object DisplayName -Like 'DataFlex*'
if($Limit -gt 0) {$profiles=@($profiles | Select-Object -First $Limit)}
$capsManager=[CiffNative]::CreateClass('C1941838-7450-4EC5-8933-14250C9F11AB','6E14FCF0-1792-4CC3-A8DF-096B6FCCFD75')
$capsFile=[CiffNative]::GetPointer($capsManager,0x1c)
$coders=[IntPtr]::Zero
$text=[CiffNative]::CreateClass('BB0561B2-C54F-11D4-A995-00010212D541','BB0561B1-C54F-11D4-A995-00010212D541')
$barcode=[CiffNative]::CreateClass('7A4AA4CF-F5CD-11D4-8DAE-0050DAFE8A9F','BB0561B1-C54F-11D4-A995-00010212D541')
$utf16=New-Object System.Text.UnicodeEncoding($false,$true,$true)
$results=New-Object System.Collections.ArrayList
$headerResults=New-Object System.Collections.ArrayList
$retargetResults=New-Object System.Collections.ArrayList
try {
    [CiffNative]::SetString($capsFile,0x28,(Join-Path $output 'embedded-capabilities.xml'))
    $coders=[CiffPrinterNative]::GetObject($capsFile,0x3c)
    foreach($profile in $profiles) {
        $record=[ordered]@{profile=$profile.DisplayName;coder=$profile.CoderName;status='started';fields=@()}
        $caps=[CiffPrinterNative]::GetNamedObject($coders,0x30,$profile.CoderName)
        $document=[CiffNative]::Create();$image=[IntPtr]::Zero
        try {
            $record.xRes=[CiffPrinterNative]::GetFloat($caps,0x2c)
            $record.yRes=[CiffPrinterNative]::GetFloat($caps,0x34)
            $record.nativeDefaultFont=[CiffNative]::GetString($caps,0x368)
            [CiffNative]::SetString($document,0x48,$profile.DisplayName)
            $image=[CiffNative]::AddSubImage($document,'1','Default',1600,1600,0)
            [CiffNative]::SetFloat($image,0x70,[single]$record.xRes)
            [CiffNative]::SetFloat($image,0x78,[single]$record.yRes)
            foreach($type in @(0,1,2,3)) {
                $field=[CiffPrinterNative]::CreateText($text,$type,$document,$caps,('TEXT_'+$type))
                try {
                    [CiffPrinterNative]::UpdateData($text,$document,$field)
                    $size=[CiffPrinterNative]::CalculateSize($text,$document,$caps,$field)
                    $record.fields+=@{type=$type;calculatedDotsWidth=$size.width;calculatedDotsHeight=$size.height;calcData=[CiffNative]::GetString($field,0x98)}
                } finally {[CiffNative]::Release($field)}
            }
            $field=[CiffNative]::AddField($image,1,'DM',15)
            try {
                [CiffNative]::SetString($field,0x6c,'Barcode')
                [CiffNative]::SetString($field,0x74,'{7A4AA4CF-F5CD-11D4-8DAE-0050DAFE8A9F}')
                $types=(Get-Content -LiteralPath (Join-Path $PSScriptRoot 'metadata/CiffMgr.dll.typelib.json') -Raw | ConvertFrom-Json).types
                $fieldType=$types | Where-Object name -eq 'ICiffBarcodeField13'
                $extended=[CiffNative]::Query($field,$fieldType.guid)
                try {
                    foreach($property in @(@{name='SymbolSize';value=6},@{name='ModuleSize';value=50},@{name='QuietMargins';value=0})) {
                        $setter=$fieldType.functions | Where-Object {$_.name -eq $property.name -and $_.invkind -eq 4}
                        [CiffNative]::SetInt($extended,$setter.vtableOffset32,$property.value)
                    }
                } finally {[CiffNative]::Release($extended)}
                [CiffPrinterNative]::Resize($barcode,$document,$caps,$field,1000,1000)
                $size=[CiffPrinterNative]::CalculateSize($barcode,$document,$caps,$field)
                $record.fields+=@{type='DM';width=$size.width;height=$size.height}
            } finally {[CiffNative]::Release($field)}
            $record.file=($profile.DisplayName -replace '[^A-Za-z0-9]+','_')+'.ciff'
            [IO.File]::WriteAllText((Join-Path $output $record.file),[CiffNative]::GetXml($document,1,0),$utf16)
            $record.status='ok'
        } catch { $record.status='error';$record.error=$_.Exception.ToString() }
        finally { [CiffNative]::Release($image);[CiffNative]::Release($document);[CiffNative]::Release($caps) }
        [void]$results.Add([PSCustomObject]$record)
        Write-Output ($record.profile+': '+$record.status)
    }
    $baseline=[IO.File]::ReadAllText((Join-Path $output $results[0].file),$utf16)
    foreach($profile in $profiles) {
        $document=[CiffNative]::Create()
        try {
            [CiffNative]::SetString($document,0xb0,$baseline)
            [CiffNative]::SetString($document,0x48,$profile.DisplayName)
            $filename='header-only-'+($profile.DisplayName -replace '[^A-Za-z0-9]+','_')+'.ciff'
            [IO.File]::WriteAllText((Join-Path $output $filename),[CiffNative]::GetXml($document,1,0),$utf16)
            [void]$headerResults.Add(@{profile=$profile.DisplayName;file=$filename;status='ok'})
        } finally {[CiffNative]::Release($document)}
    }
    foreach($profile in $profiles) {
        $document=[CiffNative]::Create();$image=[IntPtr]::Zero
        try {
            [CiffNative]::SetString($document,0xb0,$baseline)
            [CiffNative]::SetString($document,0x48,$profile.DisplayName)
            $image=[CiffPrinterNative]::GetNamedObject($document,0x30,'1')
            [CiffNative]::SetString($image,0xa0,$profile.DisplayName)
            $filename='retarget-metadata-'+($profile.DisplayName -replace '[^A-Za-z0-9]+','_')+'.ciff'
            [IO.File]::WriteAllText((Join-Path $output $filename),[CiffNative]::GetXml($document,1,0),$utf16)
            [void]$retargetResults.Add(@{profile=$profile.DisplayName;file=$filename;status='ok'})
        } finally {[CiffNative]::Release($image);[CiffNative]::Release($document)}
    }
} finally {
    [CiffNative]::Release($coders);[CiffNative]::Release($capsFile);[CiffNative]::Release($capsManager);[CiffNative]::Release($text);[CiffNative]::Release($barcode)
    [IO.File]::WriteAllText((Join-Path $output 'results.json'),(ConvertTo-Json -InputObject @($results) -Depth 8),(New-Object System.Text.UTF8Encoding($false)))
    [IO.File]::WriteAllText((Join-Path $output 'header-only-results.json'),(ConvertTo-Json -InputObject @($headerResults) -Depth 8),(New-Object System.Text.UTF8Encoding($false)))
    [IO.File]::WriteAllText((Join-Path $output 'retarget-metadata-results.json'),(ConvertTo-Json -InputObject @($retargetResults) -Depth 8),(New-Object System.Text.UTF8Encoding($false)))
}
