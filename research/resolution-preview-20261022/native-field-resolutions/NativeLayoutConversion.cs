using System;
using System.Runtime.InteropServices;
public static class NativeLayoutConversion {
 [StructLayout(LayoutKind.Explicit,Size=16)] public struct Variant {
  [FieldOffset(0)] public ushort type;[FieldOffset(8)] public IntPtr pointer;[FieldOffset(8)] public int number;
 }
 [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int ParameterCall(IntPtr self,Variant key,ref Variant value);
 [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int ConvertCall(IntPtr self,ref Variant value);
 [UnmanagedFunctionPointer(CallingConvention.StdCall)] delegate int InitialiseCall(IntPtr self,Variant locations);
 [DllImport("oleaut32.dll")] static extern int VariantClear(ref Variant value);
 static void Check(int hr){if(hr<0)Marshal.ThrowExceptionForHR(hr);}
 static void Set(IntPtr converter,string name,ref Variant value){
  Variant key=new Variant{type=8,pointer=Marshal.StringToBSTR(name)};
  try{ParameterCall call=(ParameterCall)Marshal.GetDelegateForFunctionPointer(Marshal.ReadIntPtr(Marshal.ReadIntPtr(converter),32),typeof(ParameterCall));Check(call(converter,key,ref value));}
  finally{VariantClear(ref key);}
 }
 public static void SetObject(IntPtr converter,string name,IntPtr pointer){
  Marshal.AddRef(pointer);Variant value=new Variant{type=13,pointer=pointer};try{Set(converter,name,ref value);}finally{VariantClear(ref value);}
 }
 public static void SetString(IntPtr converter,string name,string text){
  Variant value=new Variant{type=8,pointer=Marshal.StringToBSTR(text)};try{Set(converter,name,ref value);}finally{VariantClear(ref value);}
 }
 public static void SetInt(IntPtr converter,string name,int number){Variant value=new Variant{type=3,number=number};Set(converter,name,ref value);}
 public static void Initialise(IntPtr converter,string locations){
  Variant value=new Variant{type=8,pointer=Marshal.StringToBSTR(locations)};
  try{InitialiseCall call=(InitialiseCall)Marshal.GetDelegateForFunctionPointer(Marshal.ReadIntPtr(Marshal.ReadIntPtr(converter),36),typeof(InitialiseCall));Check(call(converter,value));}
  finally{VariantClear(ref value);}
 }
 public static void Convert(IntPtr converter,IntPtr document){
  Marshal.AddRef(document);Variant value=new Variant{type=9,pointer=document};
  try{ConvertCall call=(ConvertCall)Marshal.GetDelegateForFunctionPointer(Marshal.ReadIntPtr(Marshal.ReadIntPtr(converter),28),typeof(ConvertCall));Check(call(converter,ref value));}
  finally{VariantClear(ref value);}
 }
}
