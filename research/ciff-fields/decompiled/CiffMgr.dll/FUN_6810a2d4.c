// Source: CiffMgr.dll @ 6810a2d4; FUN_6810a2d4

undefined4 FUN_6810a2d4(int param_1,uint param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x88) == 0) {
    if ((param_2 < 100) && ((int)param_2 < *(int *)(param_1 + 0xa0))) {
      if (param_3 == (undefined4 *)0x0) {
        uVar1 = 0x80004003;
      }
      else {
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
        *param_3 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + param_2 * 8);
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0x80070057;
    }
  }
  else {
    uVar1 = 0x80070005;
  }
  return uVar1;
}


