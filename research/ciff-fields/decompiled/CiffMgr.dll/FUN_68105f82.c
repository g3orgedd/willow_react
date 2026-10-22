// Source: CiffMgr.dll @ 68105f82; FUN_68105f82

undefined4 FUN_68105f82(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
    *param_2 = *(undefined4 *)(param_1 + 0x44);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
    uVar1 = 0;
  }
  return uVar1;
}


