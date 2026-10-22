// Source: CiffHelper.dll @ 4082912f; FUN_4082912f

void __fastcall FUN_4082912f(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    piVar1 = (int *)param_1[1];
    for (; piVar2 != piVar1; piVar2 = piVar2 + 1) {
      FUN_40803143(piVar2);
    }
    FID_conflict__free((void *)*param_1);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}


