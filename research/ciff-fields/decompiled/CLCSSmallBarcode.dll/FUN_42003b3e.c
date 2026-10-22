// Source: CLCSSmallBarcode.dll @ 42003b3e; FUN_42003b3e

void __fastcall FUN_42003b3e(int *param_1)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = (void *)*param_1;
  if (1 < *(int *)((int)pvVar1 + -0xc)) {
    FUN_420042a1(param_1);
    iVar2 = FUN_42003339(param_1,*(int *)((int)pvVar1 + -8));
    if (iVar2 != 0) {
      FUN_42004eba((void *)*param_1,*(int *)(*param_1 + -4) * 2 + 2,pvVar1,
                   *(int *)((int)pvVar1 + -8) * 2 + 2);
    }
  }
  return;
}


