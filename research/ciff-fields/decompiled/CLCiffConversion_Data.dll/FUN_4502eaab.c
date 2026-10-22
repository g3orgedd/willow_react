// Source: CLCiffConversion_Data.dll @ 4502eaab; __calloc_impl

/* Library Function - Single Match
    __calloc_impl
   
   Library: Visual Studio 2012 Release */

LPVOID __cdecl __calloc_impl(uint param_1,uint param_2,int *param_3)

{
  LPVOID pvVar1;
  int iVar2;
  uint dwBytes;
  
  if ((param_1 == 0) || (param_2 <= 0xffffffe0 / param_1)) {
    dwBytes = param_1 * param_2;
    if (dwBytes == 0) {
      dwBytes = 1;
    }
    do {
      if ((dwBytes < 0xffffffe1) &&
         (pvVar1 = HeapAlloc(DAT_450553e0,8,dwBytes), pvVar1 != (LPVOID)0x0)) {
        return pvVar1;
      }
      if (DAT_45055a18 == 0) {
        if (param_3 != (int *)0x0) {
          *param_3 = 0xc;
          return (LPVOID)0x0;
        }
        return (LPVOID)0x0;
      }
      iVar2 = __callnewh(dwBytes);
    } while (iVar2 != 0);
    if (param_3 == (int *)0x0) {
      return (LPVOID)0x0;
    }
  }
  else {
    param_3 = __errno();
  }
  *param_3 = 0xc;
  return (LPVOID)0x0;
}


