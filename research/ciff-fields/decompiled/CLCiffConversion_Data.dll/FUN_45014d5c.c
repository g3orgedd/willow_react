// Source: CLCiffConversion_Data.dll @ 45014d5c; FUN_45014d5c

int FUN_45014d5c(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0xc);
  LOCK();
  iVar1 = *piVar2;
  *piVar2 = *piVar2 + 1;
  UNLOCK();
  return iVar1 + 1;
}


