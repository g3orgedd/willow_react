// Source: CiffMgr.dll @ 681133d6; FUN_681133d6

undefined4 FUN_681133d6(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 == 0) || (param_2 == 1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
    *(int *)(param_1 + 0x70) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}


