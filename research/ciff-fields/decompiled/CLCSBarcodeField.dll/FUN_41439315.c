// Source: CLCSBarcodeField.dll @ 41439315; FUN_41439315

void __fastcall FUN_41439315(int *param_1)

{
  if (*param_1 != 0) {
    FID_conflict__free((void *)*param_1);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}


