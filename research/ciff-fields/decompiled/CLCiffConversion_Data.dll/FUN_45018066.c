// Source: CLCiffConversion_Data.dll @ 45018066; FUN_45018066

int FUN_45018066(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 6;
  *piVar1 = *piVar1 + -1;
  iVar2 = param_1[6];
  if (*piVar1 == 0) {
    (**(code **)(*DAT_45053870 + 4))();
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x1c))(1);
    }
    (**(code **)(*DAT_45053870 + 8))();
  }
  return iVar2;
}


