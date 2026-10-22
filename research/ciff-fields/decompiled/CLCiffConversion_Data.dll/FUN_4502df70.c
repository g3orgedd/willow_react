// Source: CLCiffConversion_Data.dll @ 4502df70; FUN_4502df70

void * __cdecl FUN_4502df70(void *param_1,size_t param_2)

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


