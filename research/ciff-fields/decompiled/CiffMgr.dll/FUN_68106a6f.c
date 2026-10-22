// Source: CiffMgr.dll @ 68106a6f; FUN_68106a6f

undefined4 FUN_68106a6f(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    if (*(int *)(param_1 + 0x44) == 3) {
      uVar1 = FUN_681026d0((void *)(param_1 + 0xa8),param_2);
    }
    else {
      uVar1 = 0x80070005;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  }
  return uVar1;
}


