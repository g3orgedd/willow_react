// Source: CLCiffConversion_Data.dll @ 4502deb0; FUN_4502deb0

SIZE_T __cdecl FUN_4502deb0(LPCVOID param_1)

{
  int *piVar1;
  SIZE_T SVar2;
  
  if (param_1 == (LPCVOID)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_45027e29();
    return 0xffffffff;
  }
  SVar2 = HeapSize(DAT_450553e0,0,param_1);
  return SVar2;
}


