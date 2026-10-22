// Source: CiffMgr.dll @ 68113780; FUN_68113780

undefined4 FUN_68113780(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    uVar1 = 0;
    if (*(int *)(param_1 + 200) == 1) {
      *param_2 = *(undefined4 *)(param_1 + 0xd0);
    }
    else {
      uVar1 = 0x80070005;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  }
  return uVar1;
}


