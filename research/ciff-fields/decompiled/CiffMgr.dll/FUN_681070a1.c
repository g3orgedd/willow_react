// Source: CiffMgr.dll @ 681070a1; FUN_681070a1

undefined4 FUN_681070a1(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  if (*(int *)(param_1 + 0x44) == 5) {
    if (param_2 < 1) {
      uVar1 = 0x80070057;
    }
    else {
      *(int *)(param_1 + 0xc0) = param_2;
      *(int *)(param_1 + 0xc4) = param_2;
    }
  }
  else {
    uVar1 = 0x80070005;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return uVar1;
}


