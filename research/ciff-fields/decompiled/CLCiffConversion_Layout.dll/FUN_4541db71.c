// Source: CLCiffConversion_Layout.dll @ 4541db71; FUN_4541db71

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_4541db71(int *param_1)

{
  int *piVar1;
  int *local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 8;
  local_8 = 0x4541db7d;
  local_14[0] = 0;
  (**(code **)(*(int *)param_1[1] + 100))((int *)param_1[1],&param_1);
  if (param_1 == (int *)0x0) {
    CComQIPtr<>(&param_1,(undefined4 *)piVar1[1]);
    local_8 = 0;
    piVar1 = param_1;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x170))(param_1,local_14);
      piVar1 = param_1;
    }
  }
  else if (param_1 == (int *)0x1) {
    CComQIPtr<>(&param_1,(undefined4 *)piVar1[1]);
    local_8 = 1;
    piVar1 = param_1;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x23c))(param_1,local_14);
      piVar1 = param_1;
    }
  }
  else {
    if (param_1 != (int *)0x2) goto LAB_4541dc25;
    CComQIPtr<>(&local_18,(undefined4 *)piVar1[1]);
    local_8 = 2;
    piVar1 = local_18;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 0xf4))(local_18,local_14);
      piVar1 = local_18;
    }
  }
  local_8 = 0xffffffff;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
LAB_4541dc25:
  return local_14[0] == 0;
}


