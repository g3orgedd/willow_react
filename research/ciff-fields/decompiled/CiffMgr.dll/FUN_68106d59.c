// Source: CiffMgr.dll @ 68106d59; FUN_68106d59

undefined4 FUN_68106d59(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 == 0) || (param_2 == 1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
    *(int *)(param_1 + 0x68) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}


