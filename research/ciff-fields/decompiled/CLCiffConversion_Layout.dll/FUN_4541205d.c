// Source: CLCiffConversion_Layout.dll @ 4541205d; ATL::AtlMultiply<int>

/* Library Function - Single Match
    long __cdecl ATL::AtlMultiply<int>(int *,int,int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

long __cdecl ATL::AtlMultiply<int>(int *param_1,int param_2,int param_3)

{
  long lVar1;
  
  if ((int)((ulonglong)((longlong)param_2 * (longlong)param_3 + 0x80000000) >> 0x20) == 0) {
    *param_1 = (int)((longlong)param_2 * (longlong)param_3);
    lVar1 = 0;
  }
  else {
    lVar1 = -0x7ff8fdea;
  }
  return lVar1;
}


