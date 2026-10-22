// Source: CLARiSOFT.exe @ 00ed19e8; FUN_00ed19e8

LPVOID __cdecl FUN_00ed19e8(uint param_1,uint param_2)

{
  LPVOID pvVar1;
  DWORD DVar2;
  
  DVar2 = 0;
  while( true ) {
    pvVar1 = __calloc_impl(param_1,param_2,(int *)0x0);
    if (pvVar1 != (LPVOID)0x0) {
      return pvVar1;
    }
    if (DAT_00f44944 == 0) break;
    FUN_00ed2193(DVar2);
    DVar2 = DVar2 + 1000;
    if (DAT_00f44944 < DVar2) {
      DVar2 = 0xffffffff;
    }
    if (DVar2 == 0xffffffff) {
      return (LPVOID)0x0;
    }
  }
  return (LPVOID)0x0;
}


