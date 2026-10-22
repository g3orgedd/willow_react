// Source: CLCiffConversion_Data.dll @ 4501b7ce; FUN_4501b7ce

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_4501b7ce(void *this,undefined4 *param_1,int *param_2)

{
  code *pcVar1;
  short local_3c [4];
  undefined4 *local_34;
  _union_2683 local_2c;
  undefined4 local_1c;
  int *local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x4501b7da;
  local_1c = 0;
  FUN_4501b929(this,local_14);
  local_8 = 0;
  FUN_45001f8d((uint *)local_3c);
  local_8._0_1_ = 1;
  (**(code **)(*(int *)*param_2 + 100))((int *)*param_2,local_3c);
  pcVar1 = VariantClear_exref;
  if (local_3c[0] == 0) {
    FUN_45005aac(0x450406c8);
  }
  else {
    CComQIPtr<>(&param_2,local_34);
    FUN_45001f8d((uint *)&local_2c);
    local_8._0_1_ = 3;
    (**(code **)(*param_2 + 0x28))(param_2,local_14[0],&local_2c);
    if (local_2c.n2.vt != 0) {
      CComQIPtr<>(&local_18,(undefined4 *)local_2c._8_4_);
      *param_1 = local_18;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 4))(local_18);
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
      }
      pcVar1 = VariantClear_exref;
      VariantClear((VARIANTARG *)&local_2c.n2);
      local_8._0_1_ = 1;
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 8))(param_2);
      }
      goto LAB_4501b8b8;
    }
    VariantClear((VARIANTARG *)&local_2c.n2);
    local_8._0_1_ = 1;
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 8))(param_2);
    }
  }
  *param_1 = 0;
LAB_4501b8b8:
  (*pcVar1)(local_3c);
  SysFreeString(local_14[0]);
  return param_1;
}


