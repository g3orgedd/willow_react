// Source: CiffMgr.dll @ 681073ed; FUN_681073ed

undefined4 FUN_681073ed(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  if ((*(int *)(param_1 + 0x44) == 1) || (*(int *)(param_1 + 0x44) == 2)) {
    if (param_2 < 0) {
      uVar1 = 0x80070057;
    }
    else if (*(int *)(param_1 + 0x44) == 1) {
      *(int *)(param_1 + 0x80) = param_2;
    }
    else {
      *(int *)(param_1 + 0x94) = param_2;
    }
  }
  else {
    uVar1 = 0x80070005;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return uVar1;
}


