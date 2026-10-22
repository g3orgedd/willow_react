// Source: CiffMgr.dll @ 68106a1f; FUN_68106a1f

undefined4 FUN_68106a1f(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
    if (*(int *)(param_1 + 0x44) == 3) {
      *param_2 = *(undefined4 *)(param_1 + 0xb0);
    }
    else {
      uVar1 = 0x80070005;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  }
  return uVar1;
}


