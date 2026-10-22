// Source: CiffMgr.dll @ 68106d95; FUN_68106d95

undefined4 FUN_68106d95(int param_1,undefined2 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  if (*(int *)(param_1 + 0x68) == 1) {
    *(undefined2 *)(param_1 + 0x6c) = param_2;
  }
  else {
    uVar1 = 0x80070005;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return uVar1;
}


