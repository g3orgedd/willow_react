$ErrorActionPreference = 'Stop'
[Console]::InputEncoding = New-Object System.Text.UTF8Encoding($false)
[Console]::OutputEncoding = New-Object System.Text.UTF8Encoding($false)
Add-Type -ReferencedAssemblies System.Drawing -TypeDefinition @'
using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Collections.Generic;
using System.Runtime.InteropServices;

public static class GlyphNativeText {
    [StructLayout(LayoutKind.Sequential, CharSet=CharSet.Unicode)]
    struct LOGFONT {
        public int height,width,escapement,orientation,weight;
        public byte italic,underline,strikeOut,charSet,outPrecision,clipPrecision,quality,pitchAndFamily;
        [MarshalAs(UnmanagedType.ByValTStr,SizeConst=32)] public string faceName;
    }
    [StructLayout(LayoutKind.Sequential)] struct SIZE { public int x,y; }
    [StructLayout(LayoutKind.Sequential)] struct RECT { public int left,top,right,bottom; }
    [StructLayout(LayoutKind.Sequential)] struct ANALYSIS { public ushort flags,state; }
    [StructLayout(LayoutKind.Sequential)] struct ITEM { public int position; public ANALYSIS analysis; }
    [StructLayout(LayoutKind.Sequential)] struct OFFSET { public int du,dv; }
    [StructLayout(LayoutKind.Sequential)] struct ABC { public int a; public uint b; public int c; }
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
    [DllImport("gdi32.dll")] static extern bool GetTextExtentPointI(IntPtr dc,ushort[] glyphs,int count,out SIZE size);
    [DllImport("gdi32.dll",CharSet=CharSet.Unicode)] static extern bool GetTextMetrics(IntPtr dc,out TEXTMETRIC metric);
    [DllImport("user32.dll",CharSet=CharSet.Unicode)] static extern int DrawText(IntPtr dc,string text,int count,ref RECT rect,uint format);
    [DllImport("gdi32.dll")] static extern uint SetTextColor(IntPtr dc,uint color);
    [DllImport("gdi32.dll")] static extern uint SetBkColor(IntPtr dc,uint color);
    [DllImport("gdi32.dll")] static extern int SetBkMode(IntPtr dc,int mode);
    [DllImport("gdi32.dll")] static extern int SetTextCharacterExtra(IntPtr dc,int extra);
    [DllImport("gdi32.dll")] static extern IntPtr CreateDIBSection(IntPtr dc,ref BITMAPINFO info,uint usage,out IntPtr bits,IntPtr section,uint offset);
    [DllImport("gdi32.dll")] static extern bool GdiFlush();
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
    public sealed class Result {
        public string dataUrl;
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
            // ClariSoft's TrueType draw path does not read YMag.
            double sx=(double)xRes/yRes,sy=1;
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
                    return new Result {dataUrl="data:image/png;base64,"+Convert.ToBase64String(stream.ToArray()),width=outWidth,height=outHeight,advanceWidth=outWidth,fontHeight=(int)Math.Ceiling(metric.height*sy),baseline=(int)Math.Ceiling(metric.ascent*sy),offsetX=0,offsetY=0,fontFamily=metric.pitchAndFamily&0xf0,trueType=(metric.pitchAndFamily&4)!=0};
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
