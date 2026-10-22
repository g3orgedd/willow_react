// Source: CiffMgr.dll @ 68110303; FUN_68110303

undefined4 FUN_68110303(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
    *param_2 = *(undefined4 *)(param_1 + 100);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
    uVar1 = 0;
  }
  return uVar1;
}


