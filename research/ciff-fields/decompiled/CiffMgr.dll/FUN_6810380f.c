// Source: CiffMgr.dll @ 6810380f; FUN_6810380f

undefined4 FUN_6810380f(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 1) {
    uVar1 = 0x80070057;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    *(int *)(param_1 + 0xe0) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    uVar1 = 0;
  }
  return uVar1;
}


