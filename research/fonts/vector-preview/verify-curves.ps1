$ErrorActionPreference = 'Stop'
[Console]::OutputEncoding = New-Object System.Text.UTF8Encoding($false)
$workerPath = Join-Path $PSScriptRoot '../../../electron/font-renderer.ps1'
$workerText = [IO.File]::ReadAllText((Resolve-Path $workerPath))
$source = [regex]::Match($workerText, "(?s)Add-Type -ReferencedAssemblies System.Drawing -TypeDefinition @'\r?\n(.*?)\r?\n'@").Groups[1].Value
Add-Type -ReferencedAssemblies System.Drawing -TypeDefinition $source
Add-Type -TypeDefinition @'
using System;
using System.IO;
public static class OutlineFixture {
    static void Fixed(BinaryWriter writer,double value) {
        double whole=Math.Floor(value);
        writer.Write((ushort)Math.Round((value-whole)*65536));writer.Write((short)whole);
    }
    static void Point(BinaryWriter writer,double x,double y) { Fixed(writer,x);Fixed(writer,y); }
    public static byte[] Build() {
        using(var bytes=new MemoryStream()) using(var writer=new BinaryWriter(bytes)) {
            writer.Write(0);writer.Write(24);Point(writer,-1.5,2.25);
            writer.Write((ushort)1);writer.Write((ushort)1);Point(writer,3.25,-4.5);
            writer.Write((ushort)2);writer.Write((ushort)3);Point(writer,4,5);Point(writer,6,7);Point(writer,8,9);
            writer.Write((ushort)3);writer.Write((ushort)3);Point(writer,1,2);Point(writer,3,4);Point(writer,5,6);
            byte[] result=bytes.ToArray();Buffer.BlockCopy(BitConverter.GetBytes(result.Length),0,result,0,4);return result;
        }
    }
}
'@
$method = [GlyphNativeText].GetMethod('AppendOutline', [Reflection.BindingFlags]'NonPublic,Static')
$buffer = [OutlineFixture]::Build()
$builder = New-Object Text.StringBuilder
$arguments = New-Object object[] 5
$arguments[0] = $builder.psobject.BaseObject
$arguments[1] = $buffer.psobject.BaseObject
$arguments[2] = [double]10
$arguments[3] = [double]20
$arguments[4] = [double]2
$null = $method.Invoke($null, $arguments)
$expected = 'M17 17.75L26.5 24.5Q28 15 30 14Q32 13 36 11C22 18 26 16 30 14Z'
if ($builder.ToString() -cne $expected) { throw ('Unexpected contour: ' + $builder.ToString()) }
$bad = New-Object byte[] 15
$arguments[1] = $bad.psobject.BaseObject
$failed = $false
try { $null = $method.Invoke($null, $arguments) } catch { $failed = $true }
if (-not $failed) { throw 'Truncated native contours must be rejected.' }
[Console]::WriteLine('{"line":true,"quadraticMidpoints":true,"cubic":true,"negativeFixed":true,"baselineFlip":true,"horizontalScale":true,"malformedRejected":true}')
