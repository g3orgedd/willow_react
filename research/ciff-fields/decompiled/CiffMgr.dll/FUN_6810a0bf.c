// Source: CiffMgr.dll @ 6810a0bf; FUN_6810a0bf

undefined4 FUN_6810a0bf(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  if ((param_2 == 0) || (param_2 == 1)) {
    *(int *)(param_1 + 0x54) = param_2;
  }
  else {
    uVar1 = 0x80070057;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  return uVar1;
}


