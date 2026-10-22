// Source: CLCiffConversion_Layout.dll @ 454283af; FUN_454283af

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_454283af(LPCSTR param_1,undefined2 *param_2)

{
  int iVar1;
  uint uVar2;
  
  if ((DAT_454607b0 & 1) == 0) {
    DAT_454607b0 = DAT_454607b0 | 1;
    DAT_45460790 = &DAT_45447ce8;
    DAT_45460794 = 8;
    _DAT_4546079c = 0x4008;
    _DAT_454607a4 = 0x13;
    DAT_45460798 = &DAT_45447cec;
    _DAT_454607a0 = &DAT_45447cf0;
    _DAT_454607a8 = &DAT_45447cf4;
    _DAT_454607ac = 0x11;
  }
  uVar2 = 0;
  do {
    iVar1 = lstrcmpiA(param_1,(&DAT_45460790)[uVar2 * 2]);
    if (iVar1 == 0) {
      *param_2 = (&DAT_45460794)[uVar2 * 4];
      return 1;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 4);
  return 0;
}


