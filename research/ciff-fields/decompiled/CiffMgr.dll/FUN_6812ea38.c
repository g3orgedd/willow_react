// Source: CiffMgr.dll @ 6812ea38; FUN_6812ea38

wchar_t * FUN_6812ea38(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  uVar1 = 0;
  do {
    if (*(int *)((int)&DAT_6814bad0 + uVar1) == param_1) {
      return L"CAL_GREGORIAN" + iVar2 * 0x1e;
    }
    uVar1 = uVar1 + 0x3c;
    iVar2 = iVar2 + 1;
  } while (uVar1 < 0x2d0);
  return (wchar_t *)0x0;
}


