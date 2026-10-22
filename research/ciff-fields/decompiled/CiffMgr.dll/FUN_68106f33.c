// Source: CiffMgr.dll @ 68106f33; FUN_68106f33

undefined4 FUN_68106f33(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0) {
    uVar1 = 0x80070057;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
    *(int *)(param_1 + 0x5c) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
    uVar1 = 0;
  }
  return uVar1;
}


