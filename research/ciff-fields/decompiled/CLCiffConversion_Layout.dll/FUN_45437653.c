// Source: CLCiffConversion_Layout.dll @ 45437653; FUN_45437653

void * __cdecl FUN_45437653(void *param_1,size_t param_2)

{
  void *pvVar1;
  DWORD DVar2;
  
  DVar2 = 0;
  do {
    pvVar1 = _realloc(param_1,param_2);
    if (pvVar1 != (void *)0x0) {
      return pvVar1;
    }
    if (param_2 == 0) {
      return (void *)0x0;
    }
    if (DAT_45461230 == 0) {
      return (void *)0x0;
    }
    FUN_454399f2(DVar2);
    DVar2 = DVar2 + 1000;
    if (DAT_45461230 < DVar2) {
      DVar2 = 0xffffffff;
    }
  } while (DVar2 != 0xffffffff);
  return (void *)0x0;
}


