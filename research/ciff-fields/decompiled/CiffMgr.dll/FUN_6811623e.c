// Source: CiffMgr.dll @ 6811623e; FUN_6811623e

void __fastcall FUN_6811623e(int *param_1)

{
  if (*param_1 != 0) {
    FUN_6811612a((void *)*param_1,(void *)param_1[1]);
    FID_conflict__free((void *)*param_1);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}


