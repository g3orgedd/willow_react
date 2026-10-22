// Source: CiffMgr.dll @ 681049c4; FUN_681049c4

undefined4 FUN_681049c4(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x34));
    *param_2 = *(undefined4 *)(param_1 + 0x28);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x34));
    uVar1 = 0;
  }
  return uVar1;
}


