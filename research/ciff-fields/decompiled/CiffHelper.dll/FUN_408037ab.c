// Source: CiffHelper.dll @ 408037ab; FUN_408037ab

void FUN_408037ab(UINT param_1,LPWSTR param_2,int param_3)

{
  int iVar1;
  
  iVar1 = LoadStringW(DAT_4086668c,param_1,param_2,param_3);
  if (iVar1 == 0) {
    *param_2 = L'\0';
  }
  return;
}


