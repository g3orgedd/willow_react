// Source: CiffMgr.dll @ 6812ef79; FUN_6812ef79

wchar_t * FUN_6812ef79(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  uVar1 = 0;
  do {
    if (*(int *)((int)&DAT_6814bda0 + uVar1) == param_1) {
      return L"DontCare" + iVar2 * 0xe;
    }
    uVar1 = uVar1 + 0x1c;
    iVar2 = iVar2 + 1;
  } while (uVar1 < 0xa8);
  return (wchar_t *)0x0;
}


