// Source: CLCiffConversion_Data.dll @ 4501842e; FUN_4501842e

int __fastcall FUN_4501842e(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 8);
  LOCK();
  iVar1 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  return iVar1 + -1;
}


