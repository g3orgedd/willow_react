// Source: CiffHelper.dll @ 40805c31; FUN_40805c31

LPCWSTR __cdecl FUN_40805c31(LPCWSTR param_1)

{
  int iVar1;
  
  param_1[2] = L'\0';
  param_1[3] = L'\0';
  param_1[0] = L'\0';
  param_1[1] = L'\0';
  iVar1 = FUN_40804ea3();
  if (iVar1 != 0) {
    FUN_40805ade(param_1);
  }
  return param_1;
}


