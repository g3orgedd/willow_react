// Source: CiffMgr.dll @ 681090b0; FUN_681090b0

int FUN_681090b0(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 4;
  LOCK();
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 + -1 == 0) {
    (**(code **)(*DAT_6816703c + 4))();
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0xec))(1);
    }
    (**(code **)(*DAT_6816703c + 8))();
  }
  return iVar2 + -1;
}


