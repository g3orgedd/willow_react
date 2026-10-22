// Source: CiffMgr.dll @ 68113b38; FUN_68113b38

undefined4 FUN_68113b38(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    if (*(int *)(param_1 + 0xa0) == 0) {
      *param_2 = 0;
    }
    else if (*(int *)(param_1 + 0xa0) == 2) {
      *param_2 = 2;
    }
    else {
      *param_2 = 1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    uVar1 = 0;
  }
  return uVar1;
}


