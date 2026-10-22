// Source: CLARiSOFT.exe @ 00ed4bd6; FUN_00ed4bd6

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

void __cdecl FUN_00ed4bd6(int param_1,int param_2)

{
  *(undefined **)(param_1 + 0x5c) = &DAT_00f0dfd0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x14) = 1;
  *(undefined4 *)(param_1 + 0x70) = 1;
  *(undefined2 *)(param_1 + 0xb8) = 0x43;
  *(undefined2 *)(param_1 + 0x1be) = 0x43;
  *(undefined4 **)(param_1 + 0x68) = &DAT_00f38b08;
  *(undefined4 *)(param_1 + 0x3b8) = 0;
  __lock(0xd);
  LOCK();
  **(int **)(param_1 + 0x68) = **(int **)(param_1 + 0x68) + 1;
  UNLOCK();
  FUN_00ed4c77();
  __lock(0xc);
  *(int *)(param_1 + 0x6c) = param_2;
  if (param_2 == 0) {
    *(undefined **)(param_1 + 0x6c) = PTR_DAT_00f38f8c;
  }
  FUN_00ed4ef9(*(int **)(param_1 + 0x6c));
  FUN_00ed4c80();
  return;
}


