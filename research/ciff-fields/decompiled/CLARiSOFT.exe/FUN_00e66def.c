// Source: CLARiSOFT.exe @ 00e66def; FUN_00e66def

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_00e66def(void *this,int *param_1,BSTR param_2)

{
  int iVar1;
  _union_2683 local_38;
  _union_2683 local_28;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0;
  FUN_00e03b51((uint *)&local_28);
  local_8._0_1_ = 2;
  iVar1 = (**(code **)(*param_1 + 0x470))(param_1,&local_28);
  if (((-1 < iVar1) && (local_28.n2.vt == 9)) && ((undefined4 *)local_28._8_4_ != (undefined4 *)0x0)
     ) {
    CComQIPtr<>(&local_18,(undefined4 *)local_28._8_4_);
    if (local_18 != (int *)0x0) {
      FUN_00e03b51((uint *)&local_38);
      local_8._0_1_ = 4;
      iVar1 = (**(code **)(*local_18 + 0x30))(local_18,param_2,&local_38);
      if ((-1 < iVar1) && (local_38.n2.vt == 9)) {
        CComQIPtr<>(local_14,(undefined4 *)local_38._8_4_);
        if (local_14[0] != (int *)0x0) {
          FUN_00e11de5((void *)((int)this + 0x1c),(int *)local_14);
          if (local_14[0] != (int *)0x0) {
            (**(code **)(*local_14[0] + 8))(local_14[0]);
          }
        }
      }
      VariantClear((VARIANTARG *)&local_38.n2);
    }
    local_8._0_1_ = 2;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
  }
  VariantClear((VARIANTARG *)&local_28.n2);
  local_8 = (uint)local_8._1_3_ << 8;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  SysFreeString(param_2);
  return iVar1;
}


