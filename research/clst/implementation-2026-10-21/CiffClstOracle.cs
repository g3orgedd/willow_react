using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;

// Uses only original, registered COM classes and their published interfaces.
public static class CiffClstOracle {
    [StructLayout(LayoutKind.Explicit, Size=16)] struct Variant {
        [FieldOffset(0)] public ushort type;
        [FieldOffset(8)] public IntPtr pointer;
    }
    [DllImport("oleaut32.dll")] static extern int VariantClear(ref Variant value);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int ItemCall(IntPtr self,int index,out Variant value);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int LoadCall(IntPtr self,IntPtr filename,IntPtr validator,out IntPtr result);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int ValidateCall(IntPtr self,IntPtr validator);
    [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int Validate2Call(IntPtr self,IntPtr validator,IntPtr control);
    static Delegate Method(IntPtr value,int offset,Type signature) {
        return Marshal.GetDelegateForFunctionPointer(Marshal.ReadIntPtr(Marshal.ReadIntPtr(value),offset),signature);
    }
    public static IntPtr Item(IntPtr value,int index) {
        Variant result; int hr=((ItemCall)Method(value,0x24,typeof(ItemCall)))(value,index,out result);
        if(hr<0)Marshal.ThrowExceptionForHR(hr);
        try {
            if(result.type!=9&&result.type!=13)throw new InvalidOperationException("Unexpected collection VARIANT.");
            Marshal.AddRef(result.pointer);return result.pointer;
        } finally { VariantClear(ref result); }
    }
    public static IntPtr Load(string filename) {
        IntPtr manager=CiffNative.CreateClass("024EFE80-15BA-4C1B-9DA0-E5F1F513C13D","727BCC53-315E-11D4-8348-00A0D21D4ECD");
        IntPtr text=Marshal.StringToBSTR(filename);
        try {
            IntPtr result;int hr=((LoadCall)Method(manager,0x1c,typeof(LoadCall)))(manager,text,IntPtr.Zero,out result);
            if(hr<0)Marshal.ThrowExceptionForHR(hr);return result;
        } finally {Marshal.FreeBSTR(text);Marshal.Release(manager);}
    }
    public static string Validate(IntPtr document) {
        int hr=((ValidateCall)Method(document,0x98,typeof(ValidateCall)))(document,IntPtr.Zero);
        return unchecked((uint)hr).ToString("X8");
    }
    public static string Validate2(IntPtr document) {
        IntPtr target=CiffNative.Query(document,"93F14D00-FCD1-492B-960E-CA69E9935212");
        try {return unchecked((uint)((Validate2Call)Method(target,0xbc,typeof(Validate2Call)))(target,IntPtr.Zero,IntPtr.Zero)).ToString("X8");}
        finally {Marshal.Release(target);}
    }
    public sealed class FieldValue {
        public int subImageIndex,index,fieldType,displayed;
        public string name;
        public int[] calculatedDataUnits;
    }
    public static int[] Units(string value) {
        if(value==null)return null;
        int[] result=new int[value.Length];for(int i=0;i<value.Length;i++)result[i]=value[i];return result;
    }
    public static string FromUnits(int[] units) {
        char[] value=new char[units.Length];for(int i=0;i<units.Length;i++)value[i]=(char)units[i];return new string(value);
    }
    public static string FileSha256(string filename) {
        using(var hash=System.Security.Cryptography.SHA256.Create())
            return BitConverter.ToString(hash.ComputeHash(System.IO.File.ReadAllBytes(filename))).Replace("-","");
    }
    public static FieldValue[] Snapshot(IntPtr document) {
        var results=new List<FieldValue>();
        for(int si=1;si<=CiffNative.GetInt(document,0x1c);si++) {
            IntPtr image=Item(document,si);
            try {for(int fi=1;fi<=CiffNative.GetInt(image,0x1c);fi++) {
                IntPtr field=Item(image,fi),target=IntPtr.Zero;
                try {
                    target=CiffNative.Query(field,"B2A04AE2-991E-444D-B6EB-C9171E8AB98F");
                    results.Add(new FieldValue{subImageIndex=si,index=fi,name=CiffNative.GetString(target,0x1c),
                      fieldType=CiffNative.GetInt(target,0x64),displayed=CiffNative.GetInt(target,0x24),
                      calculatedDataUnits=Units(CiffNative.GetString(target,0x98))});
                } finally {CiffNative.Release(target);CiffNative.Release(field);}
            }} finally {CiffNative.Release(image);}
        }
        return results.ToArray();
    }
}
