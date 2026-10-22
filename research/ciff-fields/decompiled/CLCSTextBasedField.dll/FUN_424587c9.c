// Source: CLCSTextBasedField.dll @ 424587c9; FUN_424587c9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_424587c9(int *param_1,int *param_2)

{
  int iVar1;
  float local_18;
  float local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  (**(code **)(*param_2 + 0x2c))(param_2,local_14);
  (**(code **)(*param_2 + 0x34))(param_2,&local_18);
  iVar1 = FUN_424264fb((float)*param_1 / local_14[0]);
  *param_1 = iVar1;
  iVar1 = FUN_424264fb((float)param_1[1] / local_18);
  local_8 = 0xffffffff;
  param_1[1] = iVar1;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return;
}


