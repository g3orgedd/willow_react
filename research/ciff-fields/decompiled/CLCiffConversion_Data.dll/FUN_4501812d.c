// Source: CLCiffConversion_Data.dll @ 4501812d; FUN_4501812d

void __fastcall FUN_4501812d(int *param_1)

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


