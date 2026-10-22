// Source: CLCiffConversion_Layout.dll @ 4543760c; FUN_4543760c

void * __cdecl FUN_4543760c(size_t param_1)

{
  uint uVar1;
  void *pvVar2;
  DWORD DVar3;
  
  DVar3 = 0;
  while( true ) {
    uVar1 = DAT_45461230;
    pvVar2 = _malloc(param_1);
    if (pvVar2 != (void *)0x0) {
      return pvVar2;
    }
    if (uVar1 == 0) break;
    FUN_454399f2(DVar3);
    DVar3 = DVar3 + 1000;
    if (DAT_45461230 < DVar3) {
      DVar3 = 0xffffffff;
    }
    if (DVar3 == 0xffffffff) {
      return (void *)0x0;
    }
  }
  return (void *)0x0;
}


