// Source: CiffMgr.dll @ 6810a149; FUN_6810a149

undefined4 FUN_6810a149(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x88) == 0) {
    if (param_2 == (undefined4 *)0x0) {
      uVar1 = 0x80004003;
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
      *param_2 = *(undefined4 *)(param_1 + 0xa0);
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x80070005;
  }
  return uVar1;
}


