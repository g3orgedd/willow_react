using System;
using System.Drawing;
using System.Runtime.InteropServices;

// Research only: loads the actual saved CIFF through the installed CiffMgr.
public static class NativeSavedFile {
    [StructLayout(LayoutKind.Explicit, Size=16)] struct Variant {
        [FieldOffset(0)] public ushort type;
        [FieldOffset(8)] public IntPtr pointer;
    }
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int LoadCall(IntPtr self, IntPtr file, IntPtr validator, out IntPtr document);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int ItemCall(IntPtr self, int index, out Variant value);
    [DllImport("oleaut32.dll")] static extern int VariantClear(ref Variant value);
    public static IntPtr Load(string filename) {
        object instance=Activator.CreateInstance(Type.GetTypeFromCLSID(new Guid("024EFE80-15BA-4C1B-9DA0-E5F1F513C13D")));
        IntPtr unknown=Marshal.GetIUnknownForObject(instance), manager=IntPtr.Zero, text=IntPtr.Zero;
        try {
            Guid iid=new Guid("727BCC53-315E-11D4-8348-00A0D21D4ECD");
            int hr=Marshal.QueryInterface(unknown,ref iid,out manager); if(hr<0)Marshal.ThrowExceptionForHR(hr);
            text=Marshal.StringToBSTR(filename);
            var call=(LoadCall)Marshal.GetDelegateForFunctionPointer(Marshal.ReadIntPtr(Marshal.ReadIntPtr(manager),0x1c),typeof(LoadCall));
            IntPtr document; hr=call(manager,text,IntPtr.Zero,out document); if(hr<0)Marshal.ThrowExceptionForHR(hr);
            return document;
        } finally {
            if(text!=IntPtr.Zero)Marshal.FreeBSTR(text);
            if(manager!=IntPtr.Zero)Marshal.Release(manager);
            Marshal.Release(unknown); Marshal.ReleaseComObject(instance);
        }
    }
    public static IntPtr Item(IntPtr collection,int index) {
        var call=(ItemCall)Marshal.GetDelegateForFunctionPointer(Marshal.ReadIntPtr(Marshal.ReadIntPtr(collection),0x24),typeof(ItemCall));
        Variant value;int hr=call(collection,index,out value);if(hr<0)Marshal.ThrowExceptionForHR(hr);
        try {
            if(value.type!=9&&value.type!=13)throw new InvalidOperationException("Unexpected collection item type: "+value.type);
            Marshal.AddRef(value.pointer);return value.pointer;
        } finally {VariantClear(ref value);}
    }
    static bool IsBlack(Color color) {return color.A>0&&color.R<128&&color.G<128&&color.B<128;}
    public sealed class PixelComparison {
        public int nativeWidth,nativeHeight,glyphWidth,glyphHeight,different;
        public bool sameDimensions;
    }
    public static PixelComparison Compare(string nativePath,string glyphPath,int glyphRotation) {
        using(var a=new Bitmap(nativePath))using(var b=new Bitmap(glyphPath)) {
            if(glyphRotation==90)b.RotateFlip(RotateFlipType.Rotate90FlipNone);
            else if(glyphRotation==180)b.RotateFlip(RotateFlipType.Rotate180FlipNone);
            else if(glyphRotation==270)b.RotateFlip(RotateFlipType.Rotate270FlipNone);
            var result=new PixelComparison {nativeWidth=a.Width,nativeHeight=a.Height,glyphWidth=b.Width,glyphHeight=b.Height,sameDimensions=a.Width==b.Width&&a.Height==b.Height};
            if(!result.sameDimensions){result.different=-1;return result;}
            for(int y=0;y<a.Height;y++)for(int x=0;x<a.Width;x++)if(IsBlack(a.GetPixel(x,y))!=IsBlack(b.GetPixel(x,y)))result.different++;
            return result;
        }
    }
    public static int PositionDot(int coordinate,float resolution) {
        float scaled=(float)coordinate*resolution;
        return (int)(scaled+(scaled<0?-.5f:.5f));
    }
    public static void Compose(string[] images,int[] x,int[] y,int width,int height,string output) {
        ComposeScaled(images,x,y,width,height,1,output);
    }
    public static void ComposeScaled(string[] images,int[] x,int[] y,int width,int height,int scale,string output) {
        width*=scale;height*=scale;
        using(var paper=new Bitmap(width,height)) {
            using(var graphics=Graphics.FromImage(paper))graphics.Clear(Color.White);
            for(int n=0;n<images.Length;n++)using(var cell=new Bitmap(images[n])) {
                for(int py=0;py<cell.Height;py++)for(int px=0;px<cell.Width;px++) {
                    if(!IsBlack(cell.GetPixel(px,py)))continue;
                    for(int sy=0;sy<scale;sy++)for(int sx=0;sx<scale;sx++) {
                        int dx=(x[n]+px)*scale+sx,dy=(y[n]+py)*scale+sy;
                        if(dx>=0&&dy>=0&&dx<width&&dy<height)paper.SetPixel(dx,dy,Color.Black);
                    }
                }
            }
            paper.Save(output,System.Drawing.Imaging.ImageFormat.Png);
        }
    }
    public static int RegionDifference(string layout,string nativeCell,int x,int y,int dx,int dy) {
        using(var a=new Bitmap(layout))using(var b=new Bitmap(nativeCell)) {
            int different=0;
            for(int py=-3;py<b.Height+3;py++)for(int px=-3;px<b.Width+3;px++) {
                int lx=x+px,ly=y+py,cx=px-dx,cy=py-dy;
                bool l=lx>=0&&ly>=0&&lx<a.Width&&ly<a.Height&&IsBlack(a.GetPixel(lx,ly));
                bool r=cx>=0&&cy>=0&&cx<b.Width&&cy<b.Height&&IsBlack(b.GetPixel(cx,cy));
                if(l!=r)different++;
            }
            return different;
        }
    }
}
