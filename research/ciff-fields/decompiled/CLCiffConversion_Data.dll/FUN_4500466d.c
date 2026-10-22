// Source: CLCiffConversion_Data.dll @ 4500466d; FUN_4500466d

void FUN_4500466d(UINT param_1,LPWSTR param_2,int param_3)

{
  int iVar1;
  
  iVar1 = LoadStringW(DAT_45054ff0,param_1,param_2,param_3);
  if (iVar1 == 0) {
    *param_2 = L'\0';
  }
  return;
}


