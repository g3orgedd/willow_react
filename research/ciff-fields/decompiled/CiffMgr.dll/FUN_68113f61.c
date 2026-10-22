// Source: CiffMgr.dll @ 68113f61; FUN_68113f61

undefined4 FUN_68113f61(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 - 1U < 10) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    *(int *)(param_1 + 0xb8) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}


