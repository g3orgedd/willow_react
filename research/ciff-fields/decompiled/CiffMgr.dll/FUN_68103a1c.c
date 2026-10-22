// Source: CiffMgr.dll @ 68103a1c; FUN_68103a1c

undefined4 FUN_68103a1c(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 - 1U < 10) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    *(int *)(param_1 + 0xf0) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}


