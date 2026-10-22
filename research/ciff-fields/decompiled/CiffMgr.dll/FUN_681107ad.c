// Source: CiffMgr.dll @ 681107ad; FUN_681107ad

undefined4 FUN_681107ad(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0) {
    uVar1 = 0x80070057;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
    *(int *)(param_1 + 0x30) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
    uVar1 = 0;
  }
  return uVar1;
}


