using System;
using System.Runtime.InteropServices;

// Additional public COM calls for printer-capability oracle experiments.
public static class CiffPrinterNative {
    [StructLayout(LayoutKind.Explicit,Size=16)] public struct Variant {
        [FieldOffset(0)] public ushort type;
        [FieldOffset(8)] public IntPtr pointer;
    }
    [StructLayout(LayoutKind.Sequential)] public struct Rect { public int left,top,right,bottom; }
    [StructLayout(LayoutKind.Sequential)] public struct Size { public int width,height; }
    [DllImport("oleaut32.dll")] static extern int VariantClear(ref Variant value);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int VariantOut(IntPtr self,out Variant result);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int StringVariantOut(IntPtr self,IntPtr text,out Variant result);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int FloatOut(IntPtr self,out float result);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int CreateFieldCall(IntPtr self,int type,IntPtr font,int pitch,Variant file,IntPtr image,IntPtr name,Variant caps,out Variant result);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int ResizeCall(IntPtr self,Rect position,Variant file,Variant caps,Variant field);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int CalculateSizeCall(IntPtr self,out Size size,Variant field,Variant caps,Variant file);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int UpdateDataCall(IntPtr self,Variant field,Variant file);
    static Delegate Method(IntPtr value,int offset,Type type) { return Marshal.GetDelegateForFunctionPointer(Marshal.ReadIntPtr(Marshal.ReadIntPtr(value),offset),type); }
    static void Check(int hr) { if(hr<0) Marshal.ThrowExceptionForHR(hr); }
    public static Variant Object(IntPtr p) { return new Variant{type=9,pointer=p}; }
    static IntPtr Take(ref Variant value) {
        try { if(value.type!=9 && value.type!=13) throw new InvalidOperationException("Expected COM object VARIANT; type="+value.type); Marshal.AddRef(value.pointer); return value.pointer; }
        finally { VariantClear(ref value); }
    }
    public static IntPtr GetObject(IntPtr value,int offset) {
        Variant result; Check(((VariantOut)Method(value,offset,typeof(VariantOut)))(value,out result)); return Take(ref result);
    }
    public static IntPtr GetNamedObject(IntPtr value,int offset,string name) {
        IntPtr text=Marshal.StringToBSTR(name); Variant result;
        try { Check(((StringVariantOut)Method(value,offset,typeof(StringVariantOut)))(value,text,out result)); return Take(ref result); }
        finally { Marshal.FreeBSTR(text); }
    }
    public static float GetFloat(IntPtr value,int offset) {
        float result; Check(((FloatOut)Method(value,offset,typeof(FloatOut)))(value,out result)); return result;
    }
    public static IntPtr CreateText(IntPtr component,int type,IntPtr file,IntPtr caps,string name) {
        IntPtr font=Marshal.StringToBSTR("Arial"),image=Marshal.StringToBSTR("1"),label=Marshal.StringToBSTR(name); Variant result;
        try { Check(((CreateFieldCall)Method(component,0x1c,typeof(CreateFieldCall)))(component,type,font,13,Object(file),image,label,Object(caps),out result)); return Take(ref result); }
        finally { Marshal.FreeBSTR(font);Marshal.FreeBSTR(image);Marshal.FreeBSTR(label); }
    }
    public static void Resize(IntPtr component,IntPtr file,IntPtr caps,IntPtr field,int width,int height) {
        Rect position=new Rect{left=0,top=0,right=width,bottom=height};
        Check(((ResizeCall)Method(component,0x3c,typeof(ResizeCall)))(component,position,Object(file),Object(caps),Object(field)));
    }
    public static Size CalculateSize(IntPtr component,IntPtr file,IntPtr caps,IntPtr field) {
        Size size; Check(((CalculateSizeCall)Method(component,0x30,typeof(CalculateSizeCall)))(component,out size,Object(field),Object(caps),Object(file))); return size;
    }
    public static void UpdateData(IntPtr component,IntPtr file,IntPtr field) {
        Check(((UpdateDataCall)Method(component,0x28,typeof(UpdateDataCall)))(component,Object(field),Object(file)));
    }
}
