// Source: CiffMgr.dll @ 681037d4; FUN_681037d4

undefined4 FUN_681037d4(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 - 1U < 0x5a) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    *(int *)(param_1 + 0xf8) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}


