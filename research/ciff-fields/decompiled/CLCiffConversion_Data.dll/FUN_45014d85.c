// Source: CLCiffConversion_Data.dll @ 45014d85; FUN_45014d85

int FUN_45014d85(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 4);
  LOCK();
  iVar1 = *piVar2;
  *piVar2 = *piVar2 + 1;
  UNLOCK();
  if (iVar1 + 1 == 2) {
    (**(code **)(*DAT_45053870 + 4))();
  }
  return iVar1 + 1;
}


