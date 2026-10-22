// Source: CiffMgr.dll @ 6811649a; FUN_6811649a

undefined4 FUN_6811649a(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
    *param_2 = *(undefined4 *)(param_1 + 0x5c);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
    uVar1 = 0;
  }
  return uVar1;
}


