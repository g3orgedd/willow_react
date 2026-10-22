// Source: CLCiffConversion_Layout.dll @ 4542766f; FUN_4542766f

int FUN_4542766f(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 6;
  *piVar1 = *piVar1 + -1;
  iVar2 = param_1[6];
  if (*piVar1 == 0) {
    (**(code **)(*DAT_4545fba8 + 4))();
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x1c))(1);
    }
    (**(code **)(*DAT_4545fba8 + 8))();
  }
  return iVar2;
}


