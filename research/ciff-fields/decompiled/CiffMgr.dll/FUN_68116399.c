// Source: CiffMgr.dll @ 68116399; FUN_68116399

int FUN_68116399(int *param_1,int *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1;
  if (param_2 == (int *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x32);
    EnterCriticalSection(lpCriticalSection);
    if (piVar1[0x28] == 0) {
      iVar2 = FUN_68115be8(&param_1);
      if (iVar2 < 0) {
        return iVar2;
      }
      FUN_6811538e(piVar1 + 0x28,param_1);
    }
    LeaveCriticalSection(lpCriticalSection);
    iVar2 = FUN_681157f4(piVar1 + 0x28,param_2);
  }
  return iVar2;
}


