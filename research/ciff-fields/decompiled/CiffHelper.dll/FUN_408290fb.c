// Source: CiffHelper.dll @ 408290fb; FUN_408290fb

void __fastcall FUN_408290fb(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 != 0) {
    iVar1 = param_1[1];
    for (; iVar2 != iVar1; iVar2 = iVar2 + 0xc) {
      FUN_4080316c();
    }
    FID_conflict__free((void *)*param_1);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}


