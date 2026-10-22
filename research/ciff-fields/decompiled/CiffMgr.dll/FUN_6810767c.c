// Source: CiffMgr.dll @ 6810767c; FUN_6810767c

undefined4 FUN_6810767c(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
    uVar1 = FUN_681026d0((void *)(param_1 + 0x24),param_2);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
  }
  return uVar1;
}


