// Source: CLARiSOFT.exe @ 00e2f6cd; FUN_00e2f6cd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __fastcall FUN_00e2f6cd(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *local_1c;
  int *local_18;
  BSTR local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  piVar2 = *(int **)(param_1 + 0x15c);
  if (piVar2 == (int *)0x0) {
    local_14[0] = (BSTR)0x0;
    local_8 = 0;
    FUN_00e2fc4e(local_14);
    piVar1 = FUN_00e2f82e(param_1);
    local_1c = piVar1;
    if (piVar1 == (int *)0x0) {
      SysFreeString(local_14[0]);
      piVar2 = (int *)0x0;
    }
    else {
      (**(code **)(*piVar1 + 4))(piVar1);
      local_18 = (int *)0x0;
      local_8._0_1_ = 2;
      FUN_00e2f762((int *)&local_1c,local_14,&local_18);
      piVar2 = local_18;
      local_8._0_1_ = 1;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
      local_8 = (uint)local_8._1_3_ << 8;
      (**(code **)(*piVar1 + 8))(piVar1);
      SysFreeString(local_14[0]);
    }
  }
  return piVar2;
}


