// Source: CLCiffConversion_Layout.dll @ 4542773b; FUN_4542773b

void __fastcall FUN_4542773b(int *param_1)

{
  if (*param_1 != 0) {
    FID_conflict__free((void *)*param_1);
    *param_1 = 0;
  }
  if (param_1[1] != 0) {
    FID_conflict__free((void *)param_1[1]);
    param_1[1] = 0;
  }
  param_1[2] = 0;
  return;
}


