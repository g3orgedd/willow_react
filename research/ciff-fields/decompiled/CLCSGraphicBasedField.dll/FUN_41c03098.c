// Source: CLCSGraphicBasedField.dll @ 41c03098; FUN_41c03098

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __cdecl FUN_41c03098(int *param_1,int *param_2)

{
  undefined4 uVar1;
  VARIANTARG local_38;
  VARIANTARG local_28;
  int local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x41c030a4;
  FUN_41c18d70((uint *)&local_38,0,0x10);
  VariantInit(&local_38);
  local_8 = 0;
  (**(code **)(*(int *)*param_1 + 100))((int *)*param_1,&local_38);
  CComQIPtr<>(local_14,(undefined4 *)local_38.n1._8_4_);
  uVar1 = 1;
  local_8._0_1_ = 1;
  (**(code **)(*local_14[0] + 0x1c))(local_14[0],&local_18);
  if (0 < local_18) {
    FUN_41c18d70((uint *)&local_28,0,0x10);
    VariantInit(&local_28);
    local_8._0_1_ = 2;
    (**(code **)(*local_14[0] + 0x30))(local_14[0],1,&local_28);
    CComQIPtr<>(&param_1,(undefined4 *)local_28.n1._8_4_);
    FUN_41c029c3(&param_1,param_2);
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
    }
    VariantClear(&local_28);
    uVar1 = 0;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  VariantClear(&local_38);
  return uVar1;
}


