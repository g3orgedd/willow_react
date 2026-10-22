// Source: CiffMgr.dll @ 6810e9ac; FUN_6810e9ac

void __fastcall FUN_6810e9ac(undefined4 *param_1)

{
  LPWSTR pWVar1;
  int iVar2;
  
  pWVar1 = (LPWSTR)*param_1;
  while( true ) {
    iVar2 = FUN_6810d6c1(*pWVar1);
    if (iVar2 == 0) break;
    pWVar1 = CharNextW((LPCWSTR)*param_1);
    *param_1 = pWVar1;
  }
  return;
}


