// Source: CiffMgr.dll @ 6812f7ea; FUN_6812f7ea

void FUN_6812f7ea(wchar_t *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = DAT_68160490 ^ (uint)&stack0xfffffffc;
  if (param_1 != (wchar_t *)0x0) {
    uVar3 = 0;
    do {
      iVar2 = _wcscmp(param_1,(wchar_t *)(&PTR_u_ResetToStartVal_681601fc)[uVar3]);
      if (iVar2 == 0) break;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 3);
  }
  FUN_68132051(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}


