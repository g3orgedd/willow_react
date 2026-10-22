// Source: CLCSTextBasedField.dll @ 42430baf; FUN_42430baf

void __fastcall FUN_42430baf(int *param_1)

{
  if (*param_1 != 0) {
    FID_conflict__free((void *)*param_1);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}


