// Source: CLCiffConversion_Layout.dll @ 45425a3e; FUN_45425a3e

undefined4 __fastcall FUN_45425a3e(undefined4 *param_1)

{
  LPSTR pCVar1;
  
  if (*(LPCSTR)*param_1 == '\'') {
    pCVar1 = CharNextA((LPCSTR)*param_1);
    if (*pCVar1 != '\'') {
      return 1;
    }
  }
  return 0;
}


