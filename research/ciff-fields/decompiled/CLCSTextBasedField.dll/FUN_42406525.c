// Source: CLCSTextBasedField.dll @ 42406525; FUN_42406525

void FUN_42406525(UINT param_1,LPWSTR param_2,int param_3)

{
  int iVar1;
  
  iVar1 = LoadStringW(DAT_424c1ba4,param_1,param_2,param_3);
  if (iVar1 == 0) {
    *param_2 = L'\0';
  }
  return;
}


