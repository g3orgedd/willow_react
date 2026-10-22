// Source: CiffMgr.dll @ 6810d38b; FUN_6810d38b

undefined4 __fastcall FUN_6810d38b(undefined4 *param_1)

{
  LPWSTR pWVar1;
  
  if (*(LPCWSTR)*param_1 == L'\'') {
    pWVar1 = CharNextW((LPCWSTR)*param_1);
    if (*pWVar1 != L'\'') {
      return 1;
    }
  }
  return 0;
}


