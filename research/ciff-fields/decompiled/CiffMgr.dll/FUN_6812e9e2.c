// Source: CiffMgr.dll @ 6812e9e2; FUN_6812e9e2

undefined4 FUN_6812e9e2(wchar_t *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  wchar_t *local_8;
  
  if (param_1 != (wchar_t *)0x0) {
    iVar3 = 0;
    local_8 = L"CAL_GREGORIAN";
    uVar2 = 0;
    do {
      iVar1 = _wcscmp(param_1,local_8);
      if (iVar1 == 0) {
        return (&DAT_6814bad0)[iVar3 * 0xf];
      }
      uVar2 = uVar2 + 0x3c;
      local_8 = local_8 + 0x1e;
      iVar3 = iVar3 + 1;
    } while (uVar2 < 0x2d0);
  }
  return 1;
}


