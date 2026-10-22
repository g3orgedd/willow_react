// Source: CiffMgr.dll @ 6810d5c5; FUN_6810d5c5

undefined4 __cdecl FUN_6810d5c5(LPCWSTR param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_HKCR_68149738)[uVar2 * 2]);
    if (iVar1 == 0) {
      return (&DAT_6814973c)[uVar2 * 2];
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xe);
  return 0;
}


