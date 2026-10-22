// Source: CiffMgr.dll @ 6810ead6; FUN_6810ead6

int __fastcall FUN_6810ead6(int param_1)

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


