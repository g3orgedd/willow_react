// Source: CiffMgr.dll @ 6810a03b; FUN_6810a03b

undefined4 FUN_6810a03b(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    *param_2 = *(undefined4 *)(param_1 + 0x54);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    uVar1 = 0;
  }
  return uVar1;
}


