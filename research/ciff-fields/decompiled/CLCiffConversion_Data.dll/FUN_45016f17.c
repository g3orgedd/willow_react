// Source: CLCiffConversion_Data.dll @ 45016f17; FUN_45016f17

int __fastcall FUN_45016f17(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 8);
  LOCK();
  iVar1 = *piVar2;
  *piVar2 = *piVar2 + 1;
  UNLOCK();
  return iVar1 + 1;
}


