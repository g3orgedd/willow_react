// Source: CiffMgr.dll @ 68105ebd; FUN_68105ebd

undefined4 FUN_68105ebd(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
    if (*(int *)(param_1 + 0x44) == 2) {
      uVar1 = FUN_681026d0((void *)(param_1 + 0x90),param_2);
    }
    else {
      uVar1 = 0x80070005;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  }
  return uVar1;
}


