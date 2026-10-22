// Source: CLCiffConversion_Data.dll @ 45018875; FUN_45018875

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_45018875(LPCWSTR param_1,undefined2 *param_2)

{
  int iVar1;
  uint uVar2;
  
  if ((DAT_45053964 & 1) == 0) {
    DAT_45053964 = DAT_45053964 | 1;
    DAT_45053944 = &DAT_4503df08;
    DAT_45053948 = 8;
    _DAT_45053950 = 0x4008;
    _DAT_45053958 = 0x13;
    DAT_4505394c = &DAT_4503df0c;
    _DAT_45053954 = &DAT_4503df10;
    _DAT_4505395c = &DAT_4503df14;
    _DAT_45053960 = 0x11;
  }
  uVar2 = 0;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&DAT_45053944)[uVar2 * 2]);
    if (iVar1 == 0) {
      *param_2 = (&DAT_45053948)[uVar2 * 4];
      return 1;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 4);
  return 0;
}


