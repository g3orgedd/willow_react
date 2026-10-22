// Source: CiffMgr.dll @ 6810667e; FUN_6810667e

undefined4 FUN_6810667e(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
    if (*(int *)(param_1 + 0x44) == 5) {
      *param_2 = *(undefined4 *)(param_1 + 0xbc);
    }
    else {
      uVar1 = 0x80070005;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  }
  return uVar1;
}


