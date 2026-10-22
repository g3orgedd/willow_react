// Source: CLCSGraphicPrimitive.dll @ 4280dcfd; FUN_4280dcfd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 FUN_4280dcfd(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined1 uVar1;
  undefined4 *in_stack_00000020;
  int *piVar2;
  undefined4 local_2c;
  int local_28;
  int *local_24;
  int local_20;
  int local_1c;
  int local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x4280dd09;
  CComQIPtr<>(&param_1,param_1);
  uVar1 = 0;
  local_8 = 0;
  CComQIPtr<>(&local_24,param_4);
  CComQIPtr<>(local_14,in_stack_00000020);
  local_8._0_1_ = 2;
  if (((param_1 != (int *)0x0) && (local_14[0] != (int *)0x0)) && (local_24 != (int *)0x0)) {
    local_1c = 0;
    (**(code **)(*local_14[0] + 0x37c))(local_14[0],&local_1c);
    local_18 = 0;
    (**(code **)(*local_14[0] + 0x374))(local_14[0],&local_18);
    local_20 = 0;
    (**(code **)(*local_14[0] + 900))(local_14[0],&local_20);
    local_28 = 0;
    (**(code **)(*local_24 + 0x54))(local_24,&local_28);
    if (local_28 == 0) {
      FUN_4280fd96(&local_2c);
      local_8 = CONCAT31(local_8._1_3_,3);
      piVar2 = local_14[0];
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 4))(local_14[0]);
      }
      local_1c = FUN_4280fdea(local_1c,1.4013e-45,piVar2);
      piVar2 = local_14[0];
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 4))(local_14[0]);
      }
      local_18 = FUN_4280fdea(local_18,0.0,piVar2);
      piVar2 = local_14[0];
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 4))(local_14[0]);
      }
      local_20 = FUN_4280fdea(local_20,0.0,piVar2);
      local_8._0_1_ = 2;
      FUN_4280fd9f(&local_2c);
    }
    (**(code **)(*param_1 + 0xd0))(param_1,1);
    (**(code **)(*param_1 + 0x84))(param_1,local_18);
    (**(code **)(*param_1 + 0x7c))(param_1,local_1c);
    (**(code **)(*param_1 + 0xb4))(param_1,local_18);
    (**(code **)(*param_1 + 0xac))(param_1,local_1c);
    (**(code **)(*param_1 + 0xd8))(param_1,local_20);
    uVar1 = 1;
  }
  local_8._0_1_ = 1;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_24 != (int *)0x0) {
    (**(code **)(*local_24 + 8))(local_24);
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return uVar1;
}


