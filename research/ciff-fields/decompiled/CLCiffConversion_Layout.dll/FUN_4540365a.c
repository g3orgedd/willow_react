// Source: CLCiffConversion_Layout.dll @ 4540365a; FUN_4540365a

void __fastcall FUN_4540365a(int *param_1)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = (void *)*param_1;
  if (1 < *(int *)((int)pvVar1 + -0xc)) {
    FUN_45403fc8(param_1);
    iVar2 = FUN_45402e54(param_1,*(int *)((int)pvVar1 + -8));
    if (iVar2 != 0) {
      FUN_45404b24((void *)*param_1,*(int *)(*param_1 + -4) + 1,pvVar1,
                   *(int *)((int)pvVar1 + -8) + 1);
    }
  }
  return;
}


