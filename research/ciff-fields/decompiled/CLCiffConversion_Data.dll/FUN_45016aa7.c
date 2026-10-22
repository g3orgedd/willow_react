// Source: CLCiffConversion_Data.dll @ 45016aa7; FUN_45016aa7

undefined4 __cdecl FUN_45016aa7(LPCWSTR param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_HKCR_4503fa28)[uVar2 * 2]);
    if (iVar1 == 0) {
      return (&DAT_4503fa2c)[uVar2 * 2];
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xe);
  return 0;
}


