// Source: CLCiffConversion_Data.dll @ 4500363c; FUN_4500363c

void __fastcall FUN_4500363c(int *param_1)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = (void *)*param_1;
  if (1 < *(int *)((int)pvVar1 + -0xc)) {
    FUN_45004142(param_1);
    iVar2 = FUN_4500244d(param_1,*(int *)((int)pvVar1 + -8));
    if (iVar2 != 0) {
      FUN_45004ebd((void *)*param_1,*(int *)(*param_1 + -4) * 2 + 2,pvVar1,
                   *(int *)((int)pvVar1 + -8) * 2 + 2);
    }
  }
  return;
}


