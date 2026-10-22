using System;
using System.Runtime.InteropServices;
using System.IO;
using System.Security.Cryptography;

// Thin, address-independent wrappers for the documented COM vtables.
// Run in a 32-bit process; no patched DLL or license callbacks are used.
public static class CiffNative {
    [DllImport("kernel32.dll", CharSet=CharSet.Unicode)] static extern IntPtr GetModuleHandle(string name);
    [StructLayout(LayoutKind.Explicit, Size=16)] public struct NativeVariant {
        [FieldOffset(0)] public ushort type;
        [FieldOffset(8)] public IntPtr pointer;
    }
    [DllImport("oleaut32.dll")] static extern int VariantClear(ref NativeVariant value);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int PointerOut(IntPtr self, out IntPtr value);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int IntegerOut(IntPtr self, out int value);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int IntegerIn(IntPtr self, int value);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int StringIn(IntPtr self, IntPtr value);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int FloatIn(IntPtr self, float value);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int XmlOut(IntPtr self, int encoding, int encrypt, out IntPtr value);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int NameToInteger(IntPtr self, IntPtr name, out int value);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int SubImageAdd(IntPtr self, IntPtr reference, IntPtr format, int width, int height, int rotation, out NativeVariant value);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int FieldAdd(IntPtr self, int type, IntPtr name, int subtype, out NativeVariant value);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int DataAdd(IntPtr self, int type, int index, int isStatic, int parse, out NativeVariant value);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int ResolveDataCall(IntPtr self, ref NativeVariant data, NativeVariant file);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int CounterAdd(IntPtr self, int significance, int alphaNumeric, short leadCharacter, int order, out NativeVariant value);
    [StructLayout(LayoutKind.Sequential)] public struct NativeRect { public int left,top,right,bottom; }
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int ResizeMatrixCall(ref NativeRect position, ref IntPtr file, ref IntPtr caps, ref IntPtr field);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int FloatOut(IntPtr self, out float value);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate uint RefCountCall(IntPtr self);
    static IntPtr TakeObject(ref NativeVariant value) {
        try {
            if (value.type != 9 && value.type != 13) throw new InvalidOperationException("Expected a COM object VARIANT.");
            if (value.pointer != IntPtr.Zero) Marshal.AddRef(value.pointer);
            return value.pointer;
        } finally { VariantClear(ref value); }
    }
    static Delegate Method(IntPtr value, int offset, Type signature) {
        return Marshal.GetDelegateForFunctionPointer(Marshal.ReadIntPtr(Marshal.ReadIntPtr(value), offset), signature);
    }
    static void Check(int result) { if (result < 0) Marshal.ThrowExceptionForHR(result); }
    public static IntPtr Query(IntPtr value, string iid) {
        Guid guid = new Guid(iid); IntPtr result; Check(Marshal.QueryInterface(value, ref guid, out result)); return result;
    }
    public static IntPtr Create() {
        if (IntPtr.Size != 4) throw new InvalidOperationException("Use 32-bit PowerShell.");
        object manager = Activator.CreateInstance(Type.GetTypeFromCLSID(new Guid("024EFE80-15BA-4C1B-9DA0-E5F1F513C13D")));
        IntPtr unknown = Marshal.GetIUnknownForObject(manager);
        IntPtr native = Query(unknown, "727BCC53-315E-11D4-8348-00A0D21D4ECD");
        try { return GetPointer(native, 0x24); }
        finally { Marshal.Release(native); Marshal.Release(unknown); Marshal.ReleaseComObject(manager); }
    }
    public static IntPtr CreateClass(string clsid, string iid) {
        object instance = Activator.CreateInstance(Type.GetTypeFromCLSID(new Guid(clsid)));
        IntPtr unknown = Marshal.GetIUnknownForObject(instance);
        try { return Query(unknown, iid); }
        finally { Marshal.Release(unknown); Marshal.ReleaseComObject(instance); }
    }
    public static string MethodAddress(IntPtr value, int offset, string moduleName, uint imageBase) {
        uint address=unchecked((uint)Marshal.ReadIntPtr(Marshal.ReadIntPtr(value),offset).ToInt32());
        uint loadedBase=unchecked((uint)GetModuleHandle(moduleName).ToInt32());
        return unchecked(address-loadedBase+imageBase).ToString("x8");
    }
    public static IntPtr GetPointer(IntPtr value, int offset) {
        IntPtr result; Check(((PointerOut)Method(value,offset,typeof(PointerOut)))(value,out result)); return result;
    }
    public static int GetInt(IntPtr value, int offset) {
        int result; Check(((IntegerOut)Method(value,offset,typeof(IntegerOut)))(value,out result)); return result;
    }
    public static string GetString(IntPtr value, int offset) {
        IntPtr result = GetPointer(value,offset);
        try { return result == IntPtr.Zero ? null : Marshal.PtrToStringBSTR(result); }
        finally { if (result != IntPtr.Zero) Marshal.FreeBSTR(result); }
    }
    public static void SetInt(IntPtr value, int offset, int argument) { Check(((IntegerIn)Method(value,offset,typeof(IntegerIn)))(value,argument)); }
    public static void SetFloat(IntPtr value, int offset, float argument) { Check(((FloatIn)Method(value,offset,typeof(FloatIn)))(value,argument)); }
    public static string GetXml(IntPtr value, int encoding, int encrypt) {
        IntPtr result; Check(((XmlOut)Method(value,0xe0,typeof(XmlOut)))(value,encoding,encrypt,out result));
        try { return result==IntPtr.Zero ? null : Marshal.PtrToStringBSTR(result); }
        finally { if(result!=IntPtr.Zero) Marshal.FreeBSTR(result); }
    }
    public static int FieldTypeId(IntPtr component, string name) {
        IntPtr text=Marshal.StringToBSTR(name);int result;
        try { Check(((NameToInteger)Method(component,0x14,typeof(NameToInteger)))(component,text,out result));return result; }
        finally { Marshal.FreeBSTR(text); }
    }
    public static void SetString(IntPtr value, int offset, string argument) {
        IntPtr text = argument == null ? IntPtr.Zero : Marshal.StringToBSTR(argument);
        try { Check(((StringIn)Method(value,offset,typeof(StringIn)))(value,text)); }
        finally { if (text != IntPtr.Zero) Marshal.FreeBSTR(text); }
    }
    public static IntPtr AddSubImage(IntPtr value, string reference, string format, int width, int height, int rotation) {
        IntPtr a=Marshal.StringToBSTR(reference), b=Marshal.StringToBSTR(format); NativeVariant result;
        try { Check(((SubImageAdd)Method(value,0x28,typeof(SubImageAdd)))(value,a,b,width,height,rotation,out result)); return TakeObject(ref result); }
        finally { Marshal.FreeBSTR(a); Marshal.FreeBSTR(b); }
    }
    public static IntPtr AddField(IntPtr value, int type, string name, int subtype) {
        IntPtr text=Marshal.StringToBSTR(name); NativeVariant result;
        try { Check(((FieldAdd)Method(value,0x28,typeof(FieldAdd)))(value,type,text,subtype,out result)); return TakeObject(ref result); }
        finally { Marshal.FreeBSTR(text); }
    }
    public static IntPtr AddData(IntPtr value, int type, int index, bool isStatic, bool parse) {
        NativeVariant result; Check(((DataAdd)Method(value,0x28,typeof(DataAdd)))(value,type,index,isStatic?1:0,parse?1:0,out result)); return TakeObject(ref result);
    }
    public static IntPtr AddSubCounter(IntPtr value, int significance, bool alphaNumeric, short leadCharacter, int order) {
        NativeVariant result; Check(((CounterAdd)Method(value,0x124,typeof(CounterAdd)))(value,significance,alphaNumeric?1:0,leadCharacter,order,out result)); return TakeObject(ref result);
    }
    public static void Release(IntPtr value) { if(value != IntPtr.Zero) Marshal.Release(value); }
    public static void ResolveData(IntPtr helper, IntPtr data, IntPtr file) {
        Resolve(helper,0x1c,data,file);
    }
    public static void ResolveField(IntPtr helper, IntPtr field, IntPtr file) {
        Resolve(helper,0x54,field,file);
    }
    static void Resolve(IntPtr helper, int offset, IntPtr data, IntPtr file) {
        NativeVariant a=new NativeVariant { type=9,pointer=data }, b=new NativeVariant { type=9,pointer=file };
        Marshal.AddRef(data);
        try { Check(((ResolveDataCall)Method(helper,offset,typeof(ResolveDataCall)))(helper,ref a,b)); }
        finally { VariantClear(ref a); }
    }
    public static void ResizeDataMatrix(IntPtr document, IntPtr field, int width, int height, float xRes, float yRes) {
        string filename=@"C:\Program Files (x86)\CLARICOM\Data\CLCSSmallBarcode.dll";
        using(SHA256 hash=SHA256.Create()) {
            string actual=BitConverter.ToString(hash.ComputeHash(File.ReadAllBytes(filename))).Replace("-","").ToLowerInvariant();
            if(actual!="7068b4674e98d4ed44f6025b44dc170f277adeef0929be20a817019a863324d9")
                throw new InvalidOperationException("Unsupported DLL build for private routine oracle.");
        }
        IntPtr module=GetModuleHandle("CLCSSmallBarcode.dll");
        if(module==IntPtr.Zero) throw new InvalidOperationException("Create the native SmallBarcode COM class first.");
        IntPtr vtable=Marshal.AllocHGlobal(0x100), caps=Marshal.AllocHGlobal(4);
        FloatOut x=(IntPtr p,out float result)=>{result=xRes;return 0;};
        FloatOut y=(IntPtr p,out float result)=>{result=yRes;return 0;};
        RefCountCall count=(IntPtr p)=>1;
        try {
            for(int i=0;i<0x100;i+=4) Marshal.WriteInt32(vtable,i,0);
            Marshal.WriteIntPtr(vtable,4,Marshal.GetFunctionPointerForDelegate(count));
            Marshal.WriteIntPtr(vtable,8,Marshal.GetFunctionPointerForDelegate(count));
            Marshal.WriteIntPtr(vtable,0x2c,Marshal.GetFunctionPointerForDelegate(x));
            Marshal.WriteIntPtr(vtable,0x34,Marshal.GetFunctionPointerForDelegate(y));
            Marshal.WriteIntPtr(caps,vtable);
            NativeRect rect=new NativeRect {left=0,top=0,right=width,bottom=height};
            ResizeMatrixCall routine=(ResizeMatrixCall)Marshal.GetDelegateForFunctionPointer(IntPtr.Add(module,0x4a286),typeof(ResizeMatrixCall));
            Check(routine(ref rect,ref document,ref caps,ref field));
            GC.KeepAlive(x);GC.KeepAlive(y);GC.KeepAlive(count);
        } finally { Marshal.FreeHGlobal(caps);Marshal.FreeHGlobal(vtable); }
    }
}
