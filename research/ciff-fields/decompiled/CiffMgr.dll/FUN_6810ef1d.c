// Source: CiffMgr.dll @ 6810ef1d; FUN_6810ef1d

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_6810ef1d(LPCWSTR param_1,undefined2 *param_2)

{
  int iVar1;
  uint uVar2;
  
  if ((DAT_681670d0 & 1) == 0) {
    DAT_681670d0 = DAT_681670d0 | 1;
    DAT_681670b0 = &DAT_681485d0;
    DAT_681670b4 = 8;
    _DAT_681670bc = 0x4008;
    _DAT_681670c4 = 0x13;
    DAT_681670b8 = &DAT_681485d4;
    _DAT_681670c0 = &DAT_681485d8;
    _DAT_681670c8 = &DAT_681485dc;
    _DAT_681670cc = 0x11;
  }
  uVar2 = 0;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&DAT_681670b0)[uVar2 * 2]);
    if (iVar1 == 0) {
      *param_2 = (&DAT_681670b4)[uVar2 * 4];
      return 1;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 4);
  return 0;
}


