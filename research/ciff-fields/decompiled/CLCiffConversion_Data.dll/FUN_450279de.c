// Source: CLCiffConversion_Data.dll @ 450279de; FUN_450279de

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

void __cdecl FUN_450279de(int param_1,int param_2)

{
  *(undefined **)(param_1 + 0x5c) = &DAT_450474f8;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x14) = 1;
  *(undefined4 *)(param_1 + 0x70) = 1;
  *(undefined2 *)(param_1 + 0xb8) = 0x43;
  *(undefined2 *)(param_1 + 0x1be) = 0x43;
  *(undefined4 **)(param_1 + 0x68) = &DAT_45051b08;
  *(undefined4 *)(param_1 + 0x3b8) = 0;
  __lock(0xd);
  LOCK();
  **(int **)(param_1 + 0x68) = **(int **)(param_1 + 0x68) + 1;
  UNLOCK();
  FUN_45027a7f();
  __lock(0xc);
  *(int *)(param_1 + 0x6c) = param_2;
  if (param_2 == 0) {
    *(undefined **)(param_1 + 0x6c) = PTR_DAT_45051f94;
  }
  FUN_45026d4c(*(int **)(param_1 + 0x6c));
  FUN_45027a88();
  return;
}


