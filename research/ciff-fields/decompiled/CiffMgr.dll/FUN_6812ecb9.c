// Source: CiffMgr.dll @ 6812ecb9; FUN_6812ecb9

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_6812ecb9(wchar_t *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = DAT_68160490 ^ (uint)&stack0xfffffffc;
  if (param_1 != (wchar_t *)0x0) {
    uVar3 = 0;
    do {
      iVar2 = _wcscmp(param_1,(wchar_t *)(&PTR_DAT_6816024c)[uVar3]);
      if (iVar2 == 0) break;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 6);
  }
  FUN_68132051(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}


