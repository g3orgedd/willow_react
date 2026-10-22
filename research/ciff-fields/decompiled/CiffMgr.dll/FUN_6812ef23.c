// Source: CiffMgr.dll @ 6812ef23; FUN_6812ef23

undefined4 FUN_6812ef23(wchar_t *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  wchar_t *local_8;
  
  if (param_1 != (wchar_t *)0x0) {
    iVar3 = 0;
    local_8 = L"DontCare";
    uVar2 = 0;
    do {
      iVar1 = _wcscmp(param_1,local_8);
      if (iVar1 == 0) {
        return (&DAT_6814bda0)[iVar3 * 7];
      }
      uVar2 = uVar2 + 0x1c;
      local_8 = local_8 + 0xe;
      iVar3 = iVar3 + 1;
    } while (uVar2 < 0xa8);
  }
  return 0x20;
}


