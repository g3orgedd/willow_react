// Source: CiffMgr.dll @ 681076ed; FUN_681076ed

undefined4 FUN_681076ed(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
    *param_2 = *(undefined4 *)(param_1 + 0x28);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
    uVar1 = 0;
  }
  return uVar1;
}


