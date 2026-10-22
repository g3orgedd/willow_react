// Source: CLCiffConversion_Data.dll @ 450238a4; FUN_450238a4

LPVOID __cdecl FUN_450238a4(uint param_1,uint param_2)

{
  LPVOID pvVar1;
  int *piVar2;
  int local_8;
  
  local_8 = 0;
  pvVar1 = __calloc_impl(param_1,param_2,&local_8);
  if ((pvVar1 == (LPVOID)0x0) && (local_8 != 0)) {
    piVar2 = __errno();
    if (piVar2 != (int *)0x0) {
      piVar2 = __errno();
      *piVar2 = local_8;
    }
  }
  return pvVar1;
}


