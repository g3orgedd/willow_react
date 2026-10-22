// Source: CiffHelper.dll @ 4080e95d; FUN_4080e95d

void __fastcall FUN_4080e95d(int *param_1)

{
  if (*param_1 != 0) {
    FUN_4080e93e(*param_1,param_1[1]);
    FID_conflict__free((void *)*param_1);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}


