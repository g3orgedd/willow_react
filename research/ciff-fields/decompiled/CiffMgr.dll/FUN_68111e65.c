// Source: CiffMgr.dll @ 68111e65; FUN_68111e65

int FUN_68111e65(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 0x1b;
  LOCK();
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 + -1 == 0) {
    (**(code **)(*DAT_6816703c + 4))();
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x24))(1);
    }
    (**(code **)(*DAT_6816703c + 8))();
  }
  return iVar2 + -1;
}


