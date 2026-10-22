// Source: CiffMgr.dll @ 681062e9; FUN_681062e9

undefined4 FUN_681062e9(int param_1,undefined4 *param_2)

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
      goto LAB_6810633d;
    }
    if (*(int *)(param_1 + 0x44) != 1) {
      *param_2 = *(undefined4 *)(param_1 + 0x98);
      goto LAB_6810633d;
    }
  }
  *param_2 = *(undefined4 *)(param_1 + 0x84);
LAB_6810633d:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return uVar1;
}


