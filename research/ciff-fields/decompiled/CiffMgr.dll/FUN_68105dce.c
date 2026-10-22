// Source: CiffMgr.dll @ 68105dce; FUN_68105dce

undefined4 FUN_68105dce(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
    *param_2 = *(undefined4 *)(param_1 + 0x54);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
    uVar1 = 0;
  }
  return uVar1;
}


