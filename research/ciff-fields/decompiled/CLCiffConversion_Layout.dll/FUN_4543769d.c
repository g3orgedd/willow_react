// Source: CLCiffConversion_Layout.dll @ 4543769d; FUN_4543769d

void * __cdecl FUN_4543769d(LPCVOID param_1,uint param_2,uint param_3)

{
  void *pvVar1;
  DWORD DVar2;
  
  DVar2 = 0;
  do {
    pvVar1 = FUN_4542ede8(param_1,param_2,param_3);
    if (pvVar1 != (void *)0x0) {
      return pvVar1;
    }
    if (param_3 == 0) {
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


