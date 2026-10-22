// Source: CiffMgr.dll @ 6811266e; FUN_6811266e

undefined4 FUN_6811266e(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    *param_2 = *(undefined4 *)(param_1 + 0x30);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    uVar1 = 0;
  }
  return uVar1;
}


