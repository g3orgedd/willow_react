// Source: CiffMgr.dll @ 6812ea65; FUN_6812ea65

undefined4 FUN_6812ea65(wchar_t *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 local_c [2];
  
  uVar2 = 0;
  local_c[0] = 0;
  local_c[1] = 1;
  if (param_1 != (wchar_t *)0x0) {
    do {
      iVar1 = _wcscmp(param_1,(wchar_t *)(&PTR_u_Before_6816028c)[uVar2]);
      if (iVar1 == 0) {
        return local_c[uVar2];
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 2);
  }
  return 1;
}


