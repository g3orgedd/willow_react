// Source: CiffMgr.dll @ 6811601e; FUN_6811601e

int FUN_6811601e(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 4;
  *piVar1 = *piVar1 + -1;
  iVar2 = param_1[4];
  if (*piVar1 == 0) {
    (**(code **)(*DAT_6816703c + 4))();
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x1c))(1);
    }
    (**(code **)(*DAT_6816703c + 8))();
  }
  return iVar2;
}


