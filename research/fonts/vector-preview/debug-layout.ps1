$ErrorActionPreference = 'Stop'
$workerText = [IO.File]::ReadAllText((Resolve-Path (Join-Path $PSScriptRoot '../../../electron/font-renderer.ps1')))
$source = [regex]::Match($workerText, "(?s)Add-Type -ReferencedAssemblies System.Drawing -TypeDefinition @'\r?\n(.*?)\r?\n'@").Groups[1].Value
$debug = @'
    [DllImport("gdi32.dll",CharSet=CharSet.Unicode)] static extern bool GetTextExtentExPoint(IntPtr dc,string text,int count,int max,out int fit,[Out] int[] dx,out SIZE size);
    public static string DebugLayout(string text,int spacing) {
        var dc=CreateCompatibleDC(IntPtr.Zero);
        var lf=new LOGFONT {height=-55,weight=400,charSet=1,outPrecision=7,quality=1,faceName="Arial"};
        var font=CreateFontIndirect(ref lf);var old=SelectObject(dc,font);
        try {
            var runs=Shape(dc,text,spacing);var message=new StringBuilder();
            foreach(var run in runs) {
                message.Append("width="+run.width+", count="+run.count+", advances=");
                for(int i=0;i<run.count;i++) message.Append(run.advances[i]+",");
                message.Append("; ");ScriptFreeCache(ref run.cache);
            }
            message.Append(" DCextra="+SetTextCharacterExtra(dc,0));
            var measured=new RECT();DrawText(dc,text,text.Length,ref measured,0x420);message.Append(" DrawText="+measured.right);
            int fit;var dx=new int[text.Length];SIZE size;
            GetTextExtentExPoint(dc,text,text.Length,Int32.MaxValue,out fit,dx,out size);
            message.Append(" BasicDx=");foreach(int value in dx) message.Append(value+",");
            return message.ToString();
        } finally {SelectObject(dc,old);DeleteObject(font);DeleteDC(dc);}
    }
'@
$source = $source.Replace('    public sealed class Result {', $debug + [Environment]::NewLine + '    public sealed class Result {')
Add-Type -ReferencedAssemblies System.Drawing -TypeDefinition $source
$cyr = -join ([char[]]@(1055,1088,1080,1074,1077,1090))
$mir = -join ([char[]]@(1084,1080,1088))
foreach ($text in @('AB OQy', ($cyr + ', ' + $mir + '! 123'), ($cyr + ' ABC'))) {
    foreach ($spacing in @(0,1,50)) { Write-Output ($text + ' spacing=' + $spacing + ' ' + [GlyphNativeText]::DebugLayout($text,$spacing)) }
}
