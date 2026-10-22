// Source: CLCiffConversion_Layout.dll @ 4543a472; FUN_4543a472

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4543a472(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  uint local_c;
  uint local_8;
  
  if (DAT_45462790 == 0) {
    FUN_45432b2d();
  }
  DAT_454614fc = 0;
  GetModuleFileNameA((HMODULE)0x0,&DAT_454613f8,0x104);
  _DAT_45460bb8 = &DAT_454613f8;
  if ((DAT_454627a0 == (byte *)0x0) || (pbVar4 = DAT_454627a0, *DAT_454627a0 == 0)) {
    pbVar4 = &DAT_454613f8;
  }
  FUN_4543a525(pbVar4,(undefined4 *)0x0,(byte *)0x0,(int *)&local_8,(int *)&local_c);
  uVar2 = local_8;
  if ((((local_8 < 0x3fffffff) && (local_c != 0xffffffff)) &&
      (uVar1 = local_c + local_8 * 4, local_c <= uVar1)) &&
     (puVar3 = FUN_4543760c(uVar1), puVar3 != (undefined4 *)0x0)) {
    FUN_4543a525(pbVar4,puVar3,(byte *)(puVar3 + uVar2),(int *)&local_8,(int *)&local_c);
    _DAT_45460ba4 = local_8 - 1;
    DAT_45460ba8 = puVar3;
    return 0;
  }
  return 0xffffffff;
}


