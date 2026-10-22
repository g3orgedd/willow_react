// Source: CiffMgr.dll @ 681066ce; FUN_681066ce

undefined4 FUN_681066ce(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  if (*(int *)(param_1 + 0x44) != 1) {
    if (*(int *)(param_1 + 0x44) != 2) {
      uVar1 = 0x80070005;
      goto LAB_68106722;
    }
    if (*(int *)(param_1 + 0x44) != 1) {
      *param_2 = *(undefined4 *)(param_1 + 0x9c);
      goto LAB_68106722;
    }
  }
  *param_2 = *(undefined4 *)(param_1 + 0x88);
LAB_68106722:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return uVar1;
}


