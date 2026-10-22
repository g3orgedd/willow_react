// Source: CiffMgr.dll @ 68106dd2; FUN_68106dd2

undefined4 FUN_68106dd2(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  if (*(int *)(param_1 + 0x68) == 1) {
    if (param_2 < 2) {
      *(uint *)(param_1 + 0x70) = param_2;
    }
    else {
      uVar1 = 0x80070057;
    }
  }
  else {
    uVar1 = 0x80070005;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return uVar1;
}


