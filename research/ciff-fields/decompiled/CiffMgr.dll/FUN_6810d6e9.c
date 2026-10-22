// Source: CiffMgr.dll @ 6810d6e9; FUN_6810d6e9

int __fastcall FUN_6810d6e9(int param_1)

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


