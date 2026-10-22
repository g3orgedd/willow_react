using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.Runtime.InteropServices;

// Research only: calls the installed ClariSoft component through its public COM interface.
public static class FontOracle {
    [StructLayout(LayoutKind.Explicit,Size=16)] public struct Variant {
        [FieldOffset(0)] public ushort type;
        [FieldOffset(8)] public IntPtr pointer;
    }
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int Indexed(IntPtr self,int index,out Variant value);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int DrawCall(IntPtr self,IntPtr dc,int ignorePosition,Variant field,Variant caps,Variant file,uint color);
    [DllImport("oleaut32.dll")] static extern int VariantClear(ref Variant value);
    [DllImport("gdi32.dll")] static extern IntPtr CreateCompatibleDC(IntPtr dc);
    [DllImport("gdi32.dll")] static extern IntPtr CreateBitmap(int width,int height,uint planes,uint bpp,IntPtr bits);
    [DllImport("gdi32.dll")] static extern IntPtr SelectObject(IntPtr dc,IntPtr value);
    [DllImport("gdi32.dll")] static extern IntPtr GetCurrentObject(IntPtr dc,uint type);
    [DllImport("gdi32.dll")] static extern bool DeleteObject(IntPtr value);
    [DllImport("gdi32.dll")] static extern bool DeleteDC(IntPtr dc);
    public static IntPtr Item(IntPtr pointer,int index) {
        Variant value;
        var call=(Indexed)Marshal.GetDelegateForFunctionPointer(Marshal.ReadIntPtr(Marshal.ReadIntPtr(pointer),0x20),typeof(Indexed));
        int hr=call(pointer,index,out value); if(hr<0)Marshal.ThrowExceptionForHR(hr);
        try {Marshal.AddRef(value.pointer);return value.pointer;}finally{VariantClear(ref value);}
    }
    public static void Draw(IntPtr component,IntPtr field,IntPtr caps,IntPtr file,string path) {
        IntPtr dc=CreateCompatibleDC(IntPtr.Zero),initial=CreateBitmap(2048,512,1,1,IntPtr.Zero);
        IntPtr previous=SelectObject(dc,initial),drawn=IntPtr.Zero;
        try {
            var call=(DrawCall)Marshal.GetDelegateForFunctionPointer(Marshal.ReadIntPtr(Marshal.ReadIntPtr(component),0xc),typeof(DrawCall));
            int hr=call(component,dc,1,new Variant{type=9,pointer=field},new Variant{type=9,pointer=caps},new Variant{type=9,pointer=file},0);
            if(hr<0)Marshal.ThrowExceptionForHR(hr);
            drawn=GetCurrentObject(dc,7);
            using(Bitmap image=Image.FromHbitmap(drawn)) {image.Save(path,ImageFormat.Png);}
        }finally {
            SelectObject(dc,previous);
            if(drawn!=IntPtr.Zero&&drawn!=initial)DeleteObject(drawn);
            DeleteObject(initial);DeleteDC(dc);
        }
    }
}
