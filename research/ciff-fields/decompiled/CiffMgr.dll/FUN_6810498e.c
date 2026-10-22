// Source: CiffMgr.dll @ 6810498e; FUN_6810498e

undefined4 FUN_6810498e(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x34));
    *param_2 = *(undefined4 *)(param_1 + 0x2c);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x34));
    uVar1 = 0;
  }
  return uVar1;
}


