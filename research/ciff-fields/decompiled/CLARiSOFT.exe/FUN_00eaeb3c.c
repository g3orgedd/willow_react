// Source: CLARiSOFT.exe @ 00eaeb3c; FUN_00eaeb3c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_00eaeb3c(int *param_1,BSTR param_2)

{
  VARIANTARG local_34;
  _union_2683 local_24;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0;
  FUN_00e03b51((uint *)&local_34);
  local_8._0_1_ = 2;
  (**(code **)(*param_1 + 0x474))(param_1,&local_34);
  CComQIPtr<>(local_14,(undefined4 *)local_34.n1._8_4_);
  FUN_00e03b51((uint *)&local_24);
  local_8._0_1_ = 4;
  (**(code **)(*local_14[0] + 0x30))(local_14[0],param_2,&local_24);
  VariantClear((VARIANTARG *)&local_24.n2);
  local_8._0_1_ = 2;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  VariantClear(&local_34);
  local_8 = (uint)local_8._1_3_ << 8;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  SysFreeString(param_2);
  return local_24.n2.vt != 0;
}


