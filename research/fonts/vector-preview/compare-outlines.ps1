$ErrorActionPreference = 'Stop'
Add-Type -ReferencedAssemblies System.Drawing -TypeDefinition @'
using System;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;
using System.Globalization;
using System.Text.RegularExpressions;
public static class OutlinePreviewQa {
    static float Read(MatchCollection tokens,ref int index) { return Single.Parse(tokens[index++].Value,CultureInfo.InvariantCulture); }
    static PointF Point(MatchCollection tokens,ref int index) { return new PointF(Read(tokens,ref index),Read(tokens,ref index)); }
    static GraphicsPath Path(string source) {
        var path=new GraphicsPath(FillMode.Winding);
        var tokens=Regex.Matches(source,"[MLQCZ]|-?[0-9]+(?:\\.[0-9]+)?");
        PointF current=new PointF(),start=new PointF();
        int index=0;
        while(index<tokens.Count) {
            string command=tokens[index++].Value;
            if(command=="M") { path.StartFigure();current=start=Point(tokens,ref index); }
            else if(command=="L") { PointF end=Point(tokens,ref index);path.AddLine(current,end);current=end; }
            else if(command=="Q") {
                PointF control=Point(tokens,ref index),end=Point(tokens,ref index);
                path.AddBezier(current,new PointF(current.X+(control.X-current.X)*2/3,current.Y+(control.Y-current.Y)*2/3),
                    new PointF(end.X+(control.X-end.X)*2/3,end.Y+(control.Y-end.Y)*2/3),end);current=end;
            } else if(command=="C") {
                PointF a=Point(tokens,ref index),b=Point(tokens,ref index),end=Point(tokens,ref index);
                path.AddBezier(current,a,b,end);current=end;
            } else if(command=="Z") { path.CloseFigure();current=start; }
            else throw new ArgumentException("Invalid SVG path command.");
        }
        return path;
    }
    public static double[] Compare(string source,string bitmapPath,string outputPath) {
        using(var path=Path(source)) using(var native=new Bitmap(bitmapPath)) {
            int left=native.Width,top=native.Height,right=-1,bottom=-1;
            for(int y=0;y<native.Height;y++) for(int x=0;x<native.Width;x++) if(native.GetPixel(x,y).A>=128) {
                left=Math.Min(left,x);top=Math.Min(top,y);right=Math.Max(right,x+1);bottom=Math.Max(bottom,y+1);
            }
            using(var output=new Bitmap(native.Width*4,native.Height*8+16)) using(var graphics=Graphics.FromImage(output)) {
                graphics.Clear(Color.White);graphics.InterpolationMode=InterpolationMode.NearestNeighbor;graphics.PixelOffsetMode=PixelOffsetMode.Half;
                graphics.DrawImage(native,new Rectangle(0,0,native.Width*4,native.Height*4));
                graphics.TranslateTransform(0,native.Height*4+16);graphics.ScaleTransform(4,4);
                graphics.SmoothingMode=SmoothingMode.AntiAlias;graphics.FillPath(Brushes.Black,path);
                output.Save(outputPath,ImageFormat.Png);
            }
            if(path.PointCount==0) return new double[0];
            path.Flatten(null,0.01f);RectangleF bounds=path.GetBounds();
            return new double[] {left,top,right,bottom,bounds.Left,bounds.Top,bounds.Right,bounds.Bottom};
        }
    }
}
'@
$report = @()
foreach ($file in Get-ChildItem -LiteralPath $PSScriptRoot -Filter 'sample-*.svg') {
    [xml]$svg = [IO.File]::ReadAllText($file.FullName)
    $native = Join-Path $PSScriptRoot ($file.BaseName + '-bitmap.png')
    $composite = Join-Path $PSScriptRoot ($file.BaseName + '-comparison.png')
    $bounds = [OutlinePreviewQa]::Compare([string]$svg.svg.path.d, $native, $composite)
    $report += @{sample=$file.BaseName; bounds=$bounds}
}
[IO.File]::WriteAllText((Join-Path $PSScriptRoot 'outline-bounds.json'),(ConvertTo-Json -InputObject @($report) -Depth 4),[Text.UTF8Encoding]::new($false))
Write-Output ('Compared native/vector bounds and rendered ' + $report.Count + ' side-by-side artifacts.')
