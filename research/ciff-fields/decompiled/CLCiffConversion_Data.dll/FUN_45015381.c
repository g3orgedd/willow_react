// Source: CLCiffConversion_Data.dll @ 45015381; ATL::AtlCoTaskMemCAlloc

/* Library Function - Single Match
    void * __cdecl ATL::AtlCoTaskMemCAlloc(unsigned long,unsigned long)
   
   Library: Visual Studio 2015 Release */

void * __cdecl ATL::AtlCoTaskMemCAlloc(ulong param_1,ulong param_2)

{
  long lVar1;
  void *pvVar2;
  ulong local_8;
  
  local_8 = 0;
  lVar1 = AtlMultiply<unsigned_long>(&local_8,param_1,param_2);
  if (lVar1 < 0) {
    pvVar2 = (void *)0x0;
  }
  else {
    pvVar2 = CoTaskMemAlloc(local_8);
  }
  return pvVar2;
}


