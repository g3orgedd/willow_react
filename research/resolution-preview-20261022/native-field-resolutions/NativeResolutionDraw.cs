using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.Runtime.InteropServices;

// Research only. Original public Draw with/without ignoring position; no GUI.
public static class NativeResolutionDraw {
    [StructLayout(LayoutKind.Explicit,Size=16)] public struct Variant {
        [FieldOffset(0)] public ushort type;
        [FieldOffset(8)] public IntPtr pointer;
    }
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int DrawCall(IntPtr self,IntPtr dc,int ignorePosition,Variant field,Variant caps,Variant file,uint color);
    [DllImport("gdi32.dll")] static extern IntPtr CreateCompatibleDC(IntPtr dc);
    [DllImport("gdi32.dll")] static extern IntPtr CreateBitmap(int width,int height,uint planes,uint bpp,IntPtr bits);
    [DllImport("gdi32.dll")] static extern IntPtr SelectObject(IntPtr dc,IntPtr value);
    [DllImport("gdi32.dll")] static extern IntPtr GetCurrentObject(IntPtr dc,uint type);
    [DllImport("gdi32.dll")] static extern bool DeleteObject(IntPtr value);
    [DllImport("gdi32.dll")] static extern bool DeleteDC(IntPtr dc);
    static Bitmap Capture(IntPtr component,IntPtr field,IntPtr caps,IntPtr file,bool ignore) {
        IntPtr dc=CreateCompatibleDC(IntPtr.Zero),initial=CreateBitmap(2048,512,1,1,IntPtr.Zero),previous=SelectObject(dc,initial),drawn=IntPtr.Zero;
        try {
            DrawCall call=(DrawCall)Marshal.GetDelegateForFunctionPointer(Marshal.ReadIntPtr(Marshal.ReadIntPtr(component),12),typeof(DrawCall));
            int hr=call(component,dc,ignore?1:0,new Variant{type=9,pointer=field},new Variant{type=9,pointer=caps},new Variant{type=9,pointer=file},0);
            if(hr<0)Marshal.ThrowExceptionForHR(hr);
            drawn=GetCurrentObject(dc,7);
            using(Bitmap native=Image.FromHbitmap(drawn)){return new Bitmap(native);}
        }finally{
            SelectObject(dc,previous);
            if(drawn!=IntPtr.Zero&&drawn!=initial)DeleteObject(drawn);
            DeleteObject(initial);DeleteDC(dc);
        }
    }
    static bool Black(Bitmap b,int x,int y) {
        if(x<0||y<0||x>=b.Width||y>=b.Height)return false;
        Color c=b.GetPixel(x,y);return c.R<128&&c.G<128&&c.B<128;
    }
    static int Difference(Bitmap origin,Bitmap placed,int dx,int dy) {
        int count=0;
        for(int y=0;y<placed.Height;y++)for(int x=0;x<placed.Width;x++)if(Black(placed,x,y)!=Black(origin,x-dx,y-dy))count++;
        return count;
    }
    public sealed class Result {
        public int width,height,placedWidth,placedHeight,offsetX,offsetY,differentPixels,bestX,bestY,bestDifference;
    }
    public static int Position(int coordinate,float resolution) {
        float value=(float)coordinate*resolution;
        return (int)(value+(value<0?-.5f:.5f));
    }
    public static Result Probe(IntPtr component,IntPtr field,IntPtr caps,IntPtr file,int x,int y,float rx,float ry,string prefix) {
        using(Bitmap origin=Capture(component,field,caps,file,true))using(Bitmap placed=Capture(component,field,caps,file,false)) {
            origin.Save(prefix+"-origin.png",ImageFormat.Png);placed.Save(prefix+"-placed.png",ImageFormat.Png);
            Result r=new Result{width=origin.Width,height=origin.Height,placedWidth=placed.Width,placedHeight=placed.Height,offsetX=Position(x,rx),offsetY=Position(y,ry)};
            r.differentPixels=Difference(origin,placed,r.offsetX,r.offsetY);r.bestDifference=r.differentPixels;r.bestX=r.offsetX;r.bestY=r.offsetY;
            if(r.differentPixels!=0)for(int dy=r.offsetY-2;dy<=r.offsetY+2;dy++)for(int dx=r.offsetX-2;dx<=r.offsetX+2;dx++){
                int d=Difference(origin,placed,dx,dy);if(d<r.bestDifference){r.bestDifference=d;r.bestX=dx;r.bestY=dy;}
            }
            return r;
        }
    }
}
