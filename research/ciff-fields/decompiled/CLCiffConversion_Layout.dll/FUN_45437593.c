// Source: CLCiffConversion_Layout.dll @ 45437593; FUN_45437593

SIZE_T __cdecl FUN_45437593(LPCVOID param_1)

{
  int *piVar1;
  SIZE_T SVar2;
  
  if (param_1 == (LPCVOID)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_45432798();
    return 0xffffffff;
  }
  SVar2 = HeapSize(DAT_45460b9c,0,param_1);
  return SVar2;
}


