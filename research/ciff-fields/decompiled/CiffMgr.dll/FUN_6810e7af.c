// Source: CiffMgr.dll @ 6810e7af; FUN_6810e7af

void __fastcall FUN_6810e7af(int *param_1)

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


