// Source: CiffMgr.dll @ 68112d1e; FUN_68112d1e

undefined4 FUN_68112d1e(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
    *param_2 = *(undefined4 *)(param_1 + 100);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
    uVar1 = 0;
  }
  return uVar1;
}


