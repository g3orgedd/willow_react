// Source: CLCiffConversion_Data.dll @ 4502df29; FUN_4502df29

void * __cdecl FUN_4502df29(size_t param_1)

{
  uint uVar1;
  void *pvVar2;
  DWORD DVar3;
  
  DVar3 = 0;
  while( true ) {
    uVar1 = DAT_450553d8;
    pvVar2 = _malloc(param_1);
    if (pvVar2 != (void *)0x0) {
      return pvVar2;
    }
    if (uVar1 == 0) break;
    FUN_4502ef87(DVar3);
    DVar3 = DVar3 + 1000;
    if (DAT_450553d8 < DVar3) {
      DVar3 = 0xffffffff;
    }
    if (DVar3 == 0xffffffff) {
      return (void *)0x0;
    }
  }
  return (void *)0x0;
}


