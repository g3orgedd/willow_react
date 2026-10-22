// Source: CLCiffConversion_Data.dll @ 4502dfba; FUN_4502dfba

void * __cdecl FUN_4502dfba(LPCVOID param_1,uint param_2,uint param_3)

{
  void *pvVar1;
  DWORD DVar2;
  
  DVar2 = 0;
  do {
    pvVar1 = FUN_4502391c(param_1,param_2,param_3);
    if (pvVar1 != (void *)0x0) {
      return pvVar1;
    }
    if (param_3 == 0) {
      return (void *)0x0;
    }
    if (DAT_450553d8 == 0) {
      return (void *)0x0;
    }
    FUN_4502ef87(DVar2);
    DVar2 = DVar2 + 1000;
    if (DAT_450553d8 < DVar2) {
      DVar2 = 0xffffffff;
    }
  } while (DVar2 != 0xffffffff);
  return (void *)0x0;
}


