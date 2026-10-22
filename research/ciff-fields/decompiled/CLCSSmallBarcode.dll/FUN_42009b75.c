// Source: CLCSSmallBarcode.dll @ 42009b75; FUN_42009b75

void __fastcall FUN_42009b75(int *param_1)

{
  if (*param_1 != 0) {
    FID_conflict__free((void *)*param_1);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}


