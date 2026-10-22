$ErrorActionPreference = 'Stop'
[Console]::InputEncoding = New-Object System.Text.UTF8Encoding($false)
[Console]::OutputEncoding = New-Object System.Text.UTF8Encoding($false)
Add-Type -ReferencedAssemblies System.Drawing -TypeDefinition @'
using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Collections.Generic;
using System.Globalization;
using System.Runtime.InteropServices;
using System.Text;

public static class GlyphNativeText {
    [StructLayout(LayoutKind.Sequential, CharSet=CharSet.Unicode)]
    struct LOGFONT {
        public int height,width,escapement,orientation,weight;
        public byte italic,underline,strikeOut,charSet,outPrecision,clipPrecision,quality,pitchAndFamily;
        [MarshalAs(UnmanagedType.ByValTStr,SizeConst=32)] public string faceName;
    }
    [StructLayout(LayoutKind.Sequential)] struct SIZE { public int x,y; }
    [StructLayout(LayoutKind.Sequential)] struct POINT { public int x,y; }
    [StructLayout(LayoutKind.Sequential)] struct RECT { public int left,top,right,bottom; }
    [StructLayout(LayoutKind.Sequential)] struct ANALYSIS { public ushort flags,state; }
    [StructLayout(LayoutKind.Sequential)] struct ITEM { public int position; public ANALYSIS analysis; }
    [StructLayout(LayoutKind.Sequential)] struct OFFSET { public int du,dv; }
    [StructLayout(LayoutKind.Sequential)] struct ABC { public int a; public uint b; public int c; }
    [StructLayout(LayoutKind.Sequential)] struct FIXED { public ushort fraction; public short value; }
    [StructLayout(LayoutKind.Sequential)] struct MAT2 { public FIXED m11,m12,m21,m22; }
    [StructLayout(LayoutKind.Sequential)] struct GLYPHMETRICS {
        public uint blackBoxX,blackBoxY;
        public int originX,originY;
        public short cellX,cellY;
    }
    sealed class Run { public ANALYSIS analysis; public ushort[] glyphs; public int[] advances; public OFFSET[] offsets; public int count,width; public IntPtr cache; }
    [StructLayout(LayoutKind.Sequential,CharSet=CharSet.Unicode)] struct TEXTMETRIC {
        public int height,ascent,descent,internalLeading,externalLeading,aveCharWidth,maxCharWidth,weight,overhang,digitizedAspectX,digitizedAspectY;
        public char firstChar,lastChar,defaultChar,breakChar;
        public byte italic,underlined,struckOut,pitchAndFamily,charSet;
    }
    [StructLayout(LayoutKind.Sequential)] struct BITMAPINFO {
        public uint size; public int width,height; public ushort planes,bitCount;
        public uint compression,sizeImage; public int xPelsPerMeter,yPelsPerMeter; public uint clrUsed,clrImportant;
        public uint black,white;
    }
    [DllImport("gdi32.dll")] static extern IntPtr CreateCompatibleDC(IntPtr dc);
    [DllImport("gdi32.dll")] static extern bool DeleteDC(IntPtr dc);
    [DllImport("gdi32.dll")] static extern IntPtr SelectObject(IntPtr dc,IntPtr value);
    [DllImport("gdi32.dll")] static extern bool DeleteObject(IntPtr value);
    [DllImport("gdi32.dll",CharSet=CharSet.Unicode)] static extern IntPtr CreateFontIndirect(ref LOGFONT font);
    [DllImport("gdi32.dll",EntryPoint="ExtTextOutW")] static extern bool ExtTextOutGlyphs(IntPtr dc,int x,int y,uint flags,IntPtr rect,ushort[] glyphs,int count,int[] advances);
    [DllImport("gdi32.dll",CharSet=CharSet.Unicode)] static extern uint GetGlyphIndices(IntPtr dc,string text,int count,[Out] ushort[] glyphs,uint flags);
    [DllImport("gdi32.dll",EntryPoint="GetGlyphOutlineW")] static extern uint GetGlyphOutline(IntPtr dc,uint glyph,uint format,out GLYPHMETRICS metric,uint size,[Out] byte[] buffer,ref MAT2 matrix);
    [DllImport("gdi32.dll")] static extern bool GetCharWidthI(IntPtr dc,uint first,uint count,ushort[] glyphs,[Out] int[] widths);
    [DllImport("gdi32.dll")] static extern bool GetTextExtentPointI(IntPtr dc,ushort[] glyphs,int count,out SIZE size);
    [DllImport("gdi32.dll",CharSet=CharSet.Unicode)] static extern bool GetTextMetrics(IntPtr dc,out TEXTMETRIC metric);
    [DllImport("user32.dll",CharSet=CharSet.Unicode)] static extern int DrawText(IntPtr dc,string text,int count,ref RECT rect,uint format);
    [DllImport("gdi32.dll")] static extern uint SetTextColor(IntPtr dc,uint color);
    [DllImport("gdi32.dll")] static extern uint SetBkColor(IntPtr dc,uint color);
    [DllImport("gdi32.dll")] static extern int SetBkMode(IntPtr dc,int mode);
    [DllImport("gdi32.dll")] static extern int SetTextCharacterExtra(IntPtr dc,int extra);
    [DllImport("gdi32.dll")] static extern IntPtr CreateDIBSection(IntPtr dc,ref BITMAPINFO info,uint usage,out IntPtr bits,IntPtr section,uint offset);
    [DllImport("gdi32.dll")] static extern bool GdiFlush();
    [DllImport("gdi32.dll")] static extern bool BeginPath(IntPtr dc);
    [DllImport("gdi32.dll")] static extern bool EndPath(IntPtr dc);
    [DllImport("gdi32.dll")] static extern bool AbortPath(IntPtr dc);
    [DllImport("gdi32.dll")] static extern int GetPath(IntPtr dc,[Out] POINT[] points,[Out] byte[] types,int size);
    [DllImport("kernel32.dll")] static extern int MulDiv(int number,int numerator,int denominator);
    [DllImport("usp10.dll")] static extern int ScriptItemize([MarshalAs(UnmanagedType.LPWStr)] string text,int count,int maxItems,ref uint control,ref ushort state,[Out] ITEM[] items,out int itemCount);
    [DllImport("usp10.dll")] static extern int ScriptGetProperties(out IntPtr properties,out int count);
    [DllImport("usp10.dll")] static extern int ScriptLayout(int count,byte[] levels,[Out] int[] visualToLogical,int[] logicalToVisual);
    [DllImport("usp10.dll")] static extern int ScriptShape(IntPtr dc,ref IntPtr cache,[MarshalAs(UnmanagedType.LPWStr)] string text,int count,int maxGlyphs,ref ANALYSIS analysis,[Out] ushort[] glyphs,[Out] ushort[] clusters,[Out] ushort[] attributes,out int glyphCount);
    [DllImport("usp10.dll")] static extern int ScriptPlace(IntPtr dc,ref IntPtr cache,ushort[] glyphs,int count,ushort[] attributes,ref ANALYSIS analysis,[Out] int[] advances,[Out] OFFSET[] offsets,out ABC abc);
    [DllImport("usp10.dll")] static extern int ScriptTextOut(IntPtr dc,ref IntPtr cache,int x,int y,uint flags,IntPtr rect,ref ANALYSIS analysis,IntPtr reserved,int reservedCount,ushort[] glyphs,int count,int[] advances,IntPtr justify,OFFSET[] offsets);
    [DllImport("usp10.dll")] static extern int ScriptFreeCache(ref IntPtr cache);
    static uint Properties(IntPtr properties,int count,ANALYSIS analysis) {
        int index=analysis.flags&0x3ff;
        return index<count?(uint)Marshal.ReadInt32(Marshal.ReadIntPtr(properties,index*IntPtr.Size)):0x20000;
    }
    static List<Run> Shape(IntPtr dc,string text,int spacing) {
        var result=new List<Run>();
        if(text.Length==0) return result;
        var items=new ITEM[text.Length+2]; int itemCount;
        uint control=0x809; ushort state=0;
        Marshal.ThrowExceptionForHR(ScriptItemize(text,text.Length,items.Length-1,ref control,ref state,items,out itemCount));
        IntPtr properties;int propertyCount;
        Marshal.ThrowExceptionForHR(ScriptGetProperties(out properties,out propertyCount));
        SetTextCharacterExtra(dc,spacing);
        try {
            for(int i=0;i<itemCount;i++) {
                string part=text.Substring(items[i].position,items[i+1].position-items[i].position);
                var analysis=items[i].analysis;
                uint previousProperties=Properties(properties,propertyCount,analysis);
                while(i+1<itemCount) {
                    string next=text.Substring(items[i+1].position,items[i+2].position-items[i+1].position);
                    var nextAnalysis=items[i+1].analysis;
                    uint nextProperties=Properties(properties,propertyCount,nextAnalysis);
                    // Reproduce ClariSoft 42460e87: merge compatible language or
                    // neutral runs, then shape the joined run as SCRIPT_UNDEFINED.
                    if(((nextProperties&0xffff)!=(previousProperties&0xffff)&&(nextProperties&0xffff)!=0)||
                       ((nextProperties|previousProperties)&0x20000)!=0||
                       ((analysis.flags^nextAnalysis.flags)&0x400)!=0||
                       ((analysis.state^nextAnalysis.state)&0x1f)!=0) break;
                    part+=next;i++;
                    analysis.flags=(ushort)(analysis.flags&0xfc00);
                }
                int capacity=part.Length*2+16;
                var run=new Run {analysis=analysis,glyphs=new ushort[capacity],advances=new int[capacity],offsets=new OFFSET[capacity]};
                result.Add(run);
                var attributes=new ushort[capacity];var clusters=new ushort[part.Length];
                int shapeResult=ScriptShape(dc,ref run.cache,part,part.Length,capacity,ref run.analysis,run.glyphs,clusters,attributes,out run.count);
                if(shapeResult==unchecked((int)0x80040200)&&(run.analysis.flags&0x3ff)!=0) {
                    run.analysis.flags=(ushort)(run.analysis.flags&0xfc00);
                    shapeResult=ScriptShape(dc,ref run.cache,part,part.Length,capacity,ref run.analysis,run.glyphs,clusters,attributes,out run.count);
                }
                Marshal.ThrowExceptionForHR(shapeResult);
                ABC abc;
                Marshal.ThrowExceptionForHR(ScriptPlace(dc,ref run.cache,run.glyphs,run.count,attributes,ref run.analysis,run.advances,run.offsets,out abc));
                run.width=abc.a+(int)abc.b+abc.c;
            }
            var levels=new byte[result.Count];var order=new int[result.Count];
            for(int i=0;i<result.Count;i++) levels[i]=(byte)(result[i].analysis.state&0x1f);
            Marshal.ThrowExceptionForHR(ScriptLayout(result.Count,levels,order,null));
            var visual=new List<Run>();
            foreach(int index in order) visual.Add(result[index]);
            return visual;
        } catch { foreach(var run in result) ScriptFreeCache(ref run.cache); throw; }
    }
    static double FixedValue(byte[] data,int offset) {
        // Win32 FIXED stores an unsigned fractional WORD followed by a signed
        // integral SHORT; POINTFX is two of these values, with positive Y up.
        return BitConverter.ToInt16(data,offset+2)+BitConverter.ToUInt16(data,offset)/65536.0;
    }
    static string Number(double value) {
        if(Math.Abs(value)<0.00005) value=0;
        return value.ToString("0.####",CultureInfo.InvariantCulture);
    }
    static void Point(StringBuilder path,byte[] data,int offset,double pen,double baseline,double sx) {
        path.Append(Number((pen+FixedValue(data,offset))*sx));
        path.Append(' ');path.Append(Number(baseline-FixedValue(data,offset+4)));
    }
    static void AppendOutline(StringBuilder path,byte[] data,double pen,double baseline,double sx) {
        int polygon=0;
        while(polygon<data.Length) {
            if(data.Length-polygon<16) throw new InvalidDataException("Incomplete TrueType contour.");
            uint rawSize=BitConverter.ToUInt32(data,polygon);
            if(rawSize<16||rawSize>data.Length-polygon||BitConverter.ToUInt32(data,polygon+4)!=24) throw new InvalidDataException("Invalid TrueType contour.");
            int end=polygon+(int)rawSize;
            path.Append('M');Point(path,data,polygon+8,pen,baseline,sx);
            int curve=polygon+16;
            while(curve<end) {
                if(end-curve<4) throw new InvalidDataException("Incomplete TrueType curve.");
                int type=BitConverter.ToUInt16(data,curve),count=BitConverter.ToUInt16(data,curve+2);
                int points=curve+4;
                if(count<1||count>(end-points)/8) throw new InvalidDataException("Invalid TrueType curve points.");
                if(type==1) {
                    for(int point=0;point<count;point++) { path.Append('L');Point(path,data,points+point*8,pen,baseline,sx); }
                } else if(type==2) {
                    if(count<2) throw new InvalidDataException("Invalid quadratic TrueType curve.");
                    for(int point=0;point<count-1;point++) {
                        path.Append('Q');Point(path,data,points+point*8,pen,baseline,sx);path.Append(' ');
                        if(point==count-2) Point(path,data,points+(point+1)*8,pen,baseline,sx);
                        else {
                            double x=(FixedValue(data,points+point*8)+FixedValue(data,points+(point+1)*8))/2;
                            double y=(FixedValue(data,points+point*8+4)+FixedValue(data,points+(point+1)*8+4))/2;
                            path.Append(Number((pen+x)*sx));path.Append(' ');path.Append(Number(baseline-y));
                        }
                    }
                } else if(type==3) {
                    if(count%3!=0) throw new InvalidDataException("Invalid cubic TrueType curve.");
                    for(int point=0;point<count;point+=3) {
                        path.Append('C');
                        for(int control=0;control<3;control++) {
                            if(control>0) path.Append(' ');
                            Point(path,data,points+(point+control)*8,pen,baseline,sx);
                        }
                    }
                } else throw new InvalidDataException("Unsupported TrueType curve.");
                curve=points+count*8;
            }
            path.Append('Z');polygon=end;
            if(path.Length>8*1024*1024) throw new InvalidDataException("The text outline exceeds its limit.");
        }
    }
    static byte[] GlyphOutline(IntPtr dc,ushort glyph,Dictionary<ushort,byte[]> cache) {
        byte[] data;
        if(cache.TryGetValue(glyph,out data)) return data;
        var matrix=new MAT2 {m11=new FIXED {value=1},m22=new FIXED {value=1}};
        GLYPHMETRICS metric;
        // GGO_NATIVE | GGO_GLYPH_INDEX | GGO_UNHINTED: retain real quadratic
        // and cubic outlines instead of enlarging printer-resolution pixels.
        const uint format=0x182;
        uint size=GetGlyphOutline(dc,glyph,format,out metric,0,null,ref matrix);
        if(size==UInt32.MaxValue||size>2*1024*1024) throw new InvalidDataException("The font does not provide a TrueType outline.");
        data=new byte[(int)size];
        if(size>0&&GetGlyphOutline(dc,glyph,format,out metric,size,data,ref matrix)==UInt32.MaxValue) throw new InvalidDataException("Cannot read the TrueType outline.");
        cache.Add(glyph,data);return data;
    }
    static string DrawTextOutline(IntPtr dc,string text,int width,int height,double sx) {
        if(!BeginPath(dc)) throw new InvalidOperationException("Cannot capture the text layout outline.");
        try {
            var rect=new RECT {right=width,bottom=height};
            DrawText(dc,text,text.Length,ref rect,0x20);
            if(!EndPath(dc)) throw new InvalidOperationException("Cannot finish the text layout outline.");
            int count=GetPath(dc,null,null,0);
            if(count<0||count>1000000) throw new InvalidDataException("Invalid GDI text layout outline.");
            var points=new POINT[count];var types=new byte[count];
            if(count>0&&GetPath(dc,points,types,count)!=count) throw new InvalidDataException("Cannot read the GDI text layout outline.");
            var path=new StringBuilder();
            for(int i=0;i<count;i++) {
                int type=types[i]&6;
                if(type==6) {
                    int end=i+1;while(end<count&&(types[end]&6)!=6) end++;
                    if((types[end-1]&1)==0) {
                        // DrawText mnemonic underlines are open GDI pen lines.
                        // Convert their one-dot coverage to filled rectangles;
                        // a fill-only SVG/Canvas path would otherwise lose them.
                        bool horizontal=true;int left=points[i].x,right=left,y=points[i].y;
                        for(int point=i+1;point<end;point++) {
                            if((types[point]&6)!=2||points[point].y!=y) horizontal=false;
                            left=Math.Min(left,points[point].x);right=Math.Max(right,points[point].x);
                        }
                        if(horizontal) {
                            if(right>left) {
                                path.Append('M');path.Append(Number(left*sx));path.Append(' ');path.Append(Number(y));
                                path.Append('L');path.Append(Number(right*sx));path.Append(' ');path.Append(Number(y));
                                path.Append('L');path.Append(Number(right*sx));path.Append(' ');path.Append(Number(y+1));
                                path.Append('L');path.Append(Number(left*sx));path.Append(' ');path.Append(Number(y+1));path.Append('Z');
                            }
                            i=end-1;continue;
                        }
                    }
                }
                if(type==6||type==2) {
                    path.Append(type==6?'M':'L');path.Append(Number(points[i].x*sx));path.Append(' ');path.Append(Number(points[i].y));
                } else if(type==4) {
                    if(i+2>=count||(types[i+1]&6)!=4||(types[i+2]&6)!=4) throw new InvalidDataException("Invalid GDI cubic curve.");
                    path.Append('C');
                    for(int control=0;control<3;control++) {
                        if(control>0) path.Append(' ');
                        path.Append(Number(points[i+control].x*sx));path.Append(' ');path.Append(Number(points[i+control].y));
                    }
                    i+=2;
                } else throw new InvalidDataException("Unsupported GDI outline point.");
                if((types[i]&1)!=0) path.Append('Z');
                if(path.Length>8*1024*1024) throw new InvalidDataException("The text layout outline exceeds its limit.");
            }
            return path.ToString();
        } finally { AbortPath(dc); }
    }
    static string TextOutline(IntPtr dc,string text,List<Run> rasterRuns,ushort[] rawGlyphs,int baseline,int width,int height,int spacing,double sx) {
        if(text.Length==0) return "";
        // DrawText handles mnemonic prefixes and single-line control characters
        // itself. Capture its real cubic font paths for these layout operations.
        if(rasterRuns==null&&rawGlyphs==null&&(text.IndexOf('&')>=0||text.IndexOfAny(new char[] {'\r','\n','\t'})>=0)) return DrawTextOutline(dc,text,width,height,sx);
        List<Run> shaped=null;
        try {
            var path=new StringBuilder();var cache=new Dictionary<ushort,byte[]>();
            if(rawGlyphs!=null) {
                var widths=new int[rawGlyphs.Length];
                if(!GetCharWidthI(dc,0,(uint)rawGlyphs.Length,rawGlyphs,widths)) throw new InvalidOperationException("Cannot position the unavailable glyph outlines.");
                int pen=0;
                for(int i=0;i<rawGlyphs.Length;i++) {
                    AppendOutline(path,GlyphOutline(dc,rawGlyphs[i],cache),pen,baseline,sx);pen+=widths[i];
                }
            } else {
                var runs=rasterRuns;
                if(runs==null) {
                    runs=shaped=Shape(dc,text,0);
                    int shapedWidth=0;foreach(var run in runs) shapedWidth+=run.width;
                    // DrawText can use a different run layout from a standalone
                    // ScriptPlace call (for example Cyrillic punctuation). Keep
                    // its exact positions via cubic paths, not a rescaled string.
                    if(shapedWidth!=width) return DrawTextOutline(dc,text,width,height,sx);
                }
                int runPen=0;
                foreach(var run in runs) {
                    int pen=runPen;
                    for(int i=0;i<run.count;i++) {
                        AppendOutline(path,GlyphOutline(dc,run.glyphs[i],cache),pen+run.offsets[i].du,baseline-run.offsets[i].dv,sx);
                        // ScriptTextOut also reads SetTextCharacterExtra from
                        // the DC; ScriptPlace's advance array does not include it.
                        pen+=run.advances[i]+spacing;
                    }
                    runPen+=run.width;
                }
            }
            return path.ToString();
        } finally { if(shaped!=null) foreach(var run in shaped) ScriptFreeCache(ref run.cache); }
    }
    public sealed class Result {
        public string dataUrl;
        public string outlinePath;
        public int width,height,advanceWidth,fontHeight,baseline,offsetX,offsetY,fontFamily;
        public bool trueType;
    }
    public static Result Render(string text,string face,int pitch,int pitchResolution,bool bold,bool italic,int xMag,int yMag,int charSpace,int xRes,int yRes) {
        IntPtr dc=IntPtr.Zero,font=IntPtr.Zero,oldFont=IntPtr.Zero,dib=IntPtr.Zero,oldBitmap=IntPtr.Zero;
        List<Run> runs=null;
        try {
            dc=CreateCompatibleDC(IntPtr.Zero);
            if(dc==IntPtr.Zero) throw new InvalidOperationException("Cannot create the GDI text context.");
            int logicalHeight=Math.Max(1,MulDiv(pitch,yRes,283)/pitchResolution);
            var lf=new LOGFONT {height=-logicalHeight,weight=bold?900:400,italic=0,charSet=1,outPrecision=7,quality=1,faceName=face};
            font=CreateFontIndirect(ref lf);
            if(font==IntPtr.Zero) throw new InvalidOperationException("Cannot create the GDI font.");
            oldFont=SelectObject(dc,font);
            TEXTMETRIC metric;
            if(!GetTextMetrics(dc,out metric)) throw new InvalidOperationException("Cannot measure the GDI font.");
            if(xMag!=100) {
                SelectObject(dc,oldFont); DeleteObject(font); font=IntPtr.Zero;
                lf.width=(xMag*metric.aveCharWidth+50)/100;
                font=CreateFontIndirect(ref lf);
                if(font==IntPtr.Zero) throw new InvalidOperationException("Cannot create the magnified GDI font.");
                SelectObject(dc,font);
                if(!GetTextMetrics(dc,out metric)) throw new InvalidOperationException("Cannot measure the magnified GDI font.");
            }
            SetTextCharacterExtra(dc,0);
            var textRect=new RECT();
            DrawText(dc,text,text.Length,ref textRect,0x420);
            ushort[] noFallbackGlyphs=null;
            if(text.Length>0&&charSpace==0) {
                var indices=new ushort[text.Length];
                if(GetGlyphIndices(dc,text,text.Length,indices,1)!=UInt32.MaxValue&&Array.IndexOf(indices,UInt16.MaxValue)>=0) {
                    GetGlyphIndices(dc,text,text.Length,indices,0);
                    SIZE glyphSize;
                    if(!GetTextExtentPointI(dc,indices,indices.Length,out glyphSize)) throw new InvalidOperationException("Cannot measure unavailable characters.");
                    textRect.right=glyphSize.x;
                    noFallbackGlyphs=indices;
                }
            }
            if(charSpace!=0&&text.Length>0) {
                textRect.right=checked(textRect.right+2*charSpace*(text.Length-1));
                runs=Shape(dc,text,charSpace);
            }
            int width=Math.Max(1,textRect.right-textRect.left),height=Math.Max(metric.height,textRect.bottom-textRect.top);
            if(width>16384||height>8192||(long)width*height>16000000) throw new ArgumentException("The rendered text exceeds the bitmap limit.");
            int stride=checked(((width+31)/32)*4);
            var info=new BITMAPINFO {size=40,width=width,height=-height,planes=1,bitCount=1,white=0xffffff};
            IntPtr bits;
            dib=CreateDIBSection(dc,ref info,0,out bits,IntPtr.Zero,0);
            if(dib==IntPtr.Zero) throw new InvalidOperationException("Cannot allocate the GDI bitmap.");
            oldBitmap=SelectObject(dc,dib);
            byte[] pixels=new byte[checked(stride*height)];
            for(int i=0;i<pixels.Length;i++) pixels[i]=255;
            Marshal.Copy(pixels,0,bits,pixels.Length);
            SetTextColor(dc,0); SetBkColor(dc,0xffffff); SetBkMode(dc,1);
            var drawRect=new RECT {right=width,bottom=height};
            if(noFallbackGlyphs!=null) {
                if(!ExtTextOutGlyphs(dc,0,0,0x10,IntPtr.Zero,noFallbackGlyphs,noFallbackGlyphs.Length,null)) throw new InvalidOperationException("Cannot draw unavailable characters.");
            }
            else if(runs==null) DrawText(dc,text,text.Length,ref drawRect,0x20);
            else {
                int pen=0;
                foreach(var run in runs) {
                    Marshal.ThrowExceptionForHR(ScriptTextOut(dc,ref run.cache,pen,0,0,IntPtr.Zero,ref run.analysis,IntPtr.Zero,0,run.glyphs,run.count,run.advances,IntPtr.Zero,run.offsets));
                    pen+=run.width;
                }
            }
            GdiFlush(); Marshal.Copy(bits,pixels,0,pixels.Length);
            // Original Draw uses YResolution to construct the GDI font; it
            // does not rescale that bitmap by XResolution/YResolution.
            // XResolution is used later for dot-to-CIFF/display conversion.
            // The native TrueType draw path also does not read YMag.
            double sx=1,sy=1;
            int outWidth=Math.Max(1,(int)Math.Ceiling(width*sx)),outHeight=Math.Max(1,(int)Math.Ceiling(height*sy));
            if(outWidth>16384||outHeight>8192||(long)outWidth*outHeight>16000000) throw new ArgumentException("The scaled text exceeds the bitmap limit.");
            using(var output=new Bitmap(outWidth,outHeight,PixelFormat.Format32bppArgb)) {
                var region=output.LockBits(new Rectangle(0,0,outWidth,outHeight),ImageLockMode.WriteOnly,PixelFormat.Format32bppArgb);
                try {
                    byte[] target=new byte[checked(region.Stride*outHeight)];
                    for(int y=0;y<outHeight;y++) for(int x=0;x<outWidth;x++) {
                        int sourceX=Math.Min(width-1,(int)(x/sx)),sourceY=Math.Min(height-1,(int)(y/sy));
                        int bit=(pixels[sourceY*stride+sourceX/8]>>(7-sourceX%8))&1;
                        target[y*region.Stride+x*4+3]=(byte)(bit==0?255:0);
                    }
                    Marshal.Copy(target,0,region.Scan0,target.Length);
                } finally { output.UnlockBits(region); }
                using(var stream=new MemoryStream()) {
                    output.Save(stream,ImageFormat.Png);
                    string outline=null;
                    if((metric.pitchAndFamily&4)!=0) {
                        // Outline generation runs only after the original bitmap
                        // is complete. Its errors never alter native CIFF metrics
                        // or the existing printer-raster reference output.
                        try { outline=TextOutline(dc,text,runs,noFallbackGlyphs,metric.ascent,width,height,charSpace,sx); }
                        catch { outline=null; }
                    }
                    return new Result {dataUrl="data:image/png;base64,"+Convert.ToBase64String(stream.ToArray()),outlinePath=outline,width=outWidth,height=outHeight,advanceWidth=outWidth,fontHeight=(int)Math.Ceiling(metric.height*sy),baseline=(int)Math.Ceiling(metric.ascent*sy),offsetX=0,offsetY=0,fontFamily=metric.pitchAndFamily&0xf0,trueType=(metric.pitchAndFamily&4)!=0};
                }
            }
        } finally {
            if(runs!=null) foreach(var run in runs) ScriptFreeCache(ref run.cache);
            if(oldBitmap!=IntPtr.Zero) SelectObject(dc,oldBitmap);
            if(dib!=IntPtr.Zero) DeleteObject(dib);
            if(oldFont!=IntPtr.Zero) SelectObject(dc,oldFont);
            if(font!=IntPtr.Zero) DeleteObject(font);
            if(dc!=IntPtr.Zero) DeleteDC(dc);
        }
    }
}
'@
[Console]::WriteLine('{"ready":true}')
while ($null -ne ($line = [Console]::ReadLine())) {
    $request = $null
    try {
        $request = $line | ConvertFrom-Json
        $p = $request.payload
        $result = [GlyphNativeText]::Render([string]$p.text,[string]$p.face,[int]$p.pitch,[int]$p.pitchResolution,[bool]$p.bold,[bool]$p.italic,[int]$p.xMag,[int]$p.yMag,[int]$p.charSpace,[int]$p.xRes,[int]$p.yRes)
        [Console]::WriteLine((ConvertTo-Json -InputObject @{ id=$request.id; result=$result } -Compress -Depth 4))
    } catch {
        [Console]::WriteLine((ConvertTo-Json -InputObject @{ id=$request.id; error=$_.Exception.Message } -Compress))
    }
}
