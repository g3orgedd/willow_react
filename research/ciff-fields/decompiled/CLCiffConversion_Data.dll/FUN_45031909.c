// Source: CLCiffConversion_Data.dll @ 45031909; FUN_45031909

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_45031909(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  uint local_c;
  uint local_8;
  
  if (DAT_45056f94 == 0) {
    FUN_450270a6();
  }
  DAT_45055ce4 = 0;
  GetModuleFileNameA((HMODULE)0x0,&DAT_45055be0,0x104);
  _DAT_450553bc = &DAT_45055be0;
  if ((DAT_45056f9c == (byte *)0x0) || (pbVar4 = DAT_45056f9c, *DAT_45056f9c == 0)) {
    pbVar4 = &DAT_45055be0;
  }
  FUN_450319bc(pbVar4,(undefined4 *)0x0,(byte *)0x0,(int *)&local_8,(int *)&local_c);
  uVar2 = local_8;
  if ((((local_8 < 0x3fffffff) && (local_c != 0xffffffff)) &&
      (uVar1 = local_c + local_8 * 4, local_c <= uVar1)) &&
     (puVar3 = FUN_4502df29(uVar1), puVar3 != (undefined4 *)0x0)) {
    FUN_450319bc(pbVar4,puVar3,(byte *)(puVar3 + uVar2),(int *)&local_8,(int *)&local_c);
    _DAT_450553a8 = local_8 - 1;
    DAT_450553ac = puVar3;
    return 0;
  }
  return 0xffffffff;
}


