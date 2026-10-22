// Source: CiffMgr.dll @ 68103366; FUN_68103366

undefined4 FUN_68103366(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0) {
    uVar1 = 0x80070057;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    *(int *)(param_1 + 0xd8) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    uVar1 = 0;
  }
  return uVar1;
}


