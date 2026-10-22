// Source: CiffMgr.dll @ 6812e8ba; FUN_6812e8ba

undefined4 FUN_6812e8ba(wchar_t *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 local_c [2];
  
  local_c[1] = 1;
  local_c[0] = 0;
  if (param_1 != (wchar_t *)0x0) {
    uVar2 = 0;
    do {
      iVar1 = _wcscmp(param_1,(wchar_t *)(&PTR_u_HighQuality_6816043c)[uVar2]);
      if (iVar1 == 0) {
        return local_c[uVar2];
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 2);
  }
  return 0;
}


