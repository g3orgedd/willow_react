// Source: CiffMgr.dll @ 681075fc; FUN_681075fc

undefined4 FUN_681075fc(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
    *param_2 = *(undefined4 *)(param_1 + 0x30);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
    uVar1 = 0;
  }
  return uVar1;
}


