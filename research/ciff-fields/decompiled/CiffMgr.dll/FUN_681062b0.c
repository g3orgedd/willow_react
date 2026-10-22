// Source: CiffMgr.dll @ 681062b0; FUN_681062b0

undefined4 FUN_681062b0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
    *param_2 = *(undefined4 *)(param_1 + 0x5c);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
    uVar1 = 0;
  }
  return uVar1;
}


