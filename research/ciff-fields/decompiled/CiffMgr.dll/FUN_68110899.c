// Source: CiffMgr.dll @ 68110899; FUN_68110899

undefined4 FUN_68110899(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0x80070057;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
    *(int *)(param_1 + 0x48) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
    uVar1 = 0;
  }
  return uVar1;
}


