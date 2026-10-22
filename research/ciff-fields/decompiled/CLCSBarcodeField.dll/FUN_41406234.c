// Source: CLCSBarcodeField.dll @ 41406234; FUN_41406234

void FUN_41406234(UINT param_1,LPWSTR param_2,int param_3)

{
  int iVar1;
  
  iVar1 = LoadStringW(DAT_414b1828,param_1,param_2,param_3);
  if (iVar1 == 0) {
    *param_2 = L'\0';
  }
  return;
}


