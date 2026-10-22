// Source: CLCiffConversion_Data.dll @ 4502dee1; FUN_4502dee1

LPVOID __cdecl FUN_4502dee1(uint param_1,uint param_2)

{
  LPVOID pvVar1;
  DWORD DVar2;
  
  DVar2 = 0;
  while( true ) {
    pvVar1 = __calloc_impl(param_1,param_2,(int *)0x0);
    if (pvVar1 != (LPVOID)0x0) {
      return pvVar1;
    }
    if (DAT_450553d8 == 0) break;
    FUN_4502ef87(DVar2);
    DVar2 = DVar2 + 1000;
    if (DAT_450553d8 < DVar2) {
      DVar2 = 0xffffffff;
    }
    if (DVar2 == 0xffffffff) {
      return (LPVOID)0x0;
    }
  }
  return (LPVOID)0x0;
}


