// Source: CLCiffConversion_Data.dll @ 450180a1; FUN_450180a1

int FUN_450180a1(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 3;
  LOCK();
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 + -1 == 0) {
    (**(code **)(*DAT_45053870 + 4))();
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x10))(1);
    }
    (**(code **)(*DAT_45053870 + 8))();
  }
  return iVar2 + -1;
}


