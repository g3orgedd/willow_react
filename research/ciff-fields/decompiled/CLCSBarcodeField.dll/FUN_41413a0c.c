// Source: CLCSBarcodeField.dll @ 41413a0c; FUN_41413a0c

void __fastcall FUN_41413a0c(int *param_1)

{
  BOOL BVar1;
  
  if (*param_1 != 0) {
    BVar1 = DeleteObject((HGDIOBJ)*param_1);
    if (BVar1 != 0) {
      *param_1 = 0;
    }
  }
  return;
}


