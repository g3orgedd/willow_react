// Source: CLARiSOFT.exe @ 00e462d1; FUN_00e462d1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __cdecl FUN_00e462d1(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  _union_2683 local_3c;
  _union_2683 local_2c;
  int local_1c;
  int local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0xe462dd;
  FUN_00e03b51((uint *)&local_3c);
  local_8 = 0;
  iVar1 = (**(code **)(*(int *)*param_2 + 0x494))((int *)*param_2,&local_3c);
  if (((-1 < iVar1) && (local_3c.n2.vt == 9)) && ((undefined4 *)local_3c._8_4_ != (undefined4 *)0x0)
     ) {
    CComQIPtr<>(local_14,(undefined4 *)local_3c._8_4_);
    local_8._0_1_ = 1;
    if (local_14[0] == (int *)0x0) {
      iVar1 = -0x7fffbffb;
    }
    else {
      local_18 = 0;
      (**(code **)(*local_14[0] + 0x24))(local_14[0],&local_18);
      iVar2 = 0;
      if (0 < local_18) {
        do {
          FUN_00e03b51((uint *)&local_2c);
          iVar2 = iVar2 + 1;
          local_8._0_1_ = 2;
          iVar1 = (**(code **)(*local_14[0] + 0x20))(local_14[0],iVar2,&local_2c);
          if (((-1 < iVar1) && (local_2c.n2.vt == 9)) &&
             ((undefined4 *)local_2c._8_4_ != (undefined4 *)0x0)) {
            CComQIPtr<>(&param_2,(undefined4 *)local_2c._8_4_);
            local_8._0_1_ = 3;
            if (param_2 != (int *)0x0) {
              local_1c = 0;
              iVar1 = (**(code **)(*param_2 + 0x30))(param_2,&local_1c);
              if ((-1 < iVar1) && (local_1c != 0)) {
                FUN_00e467d7(param_1,(BSTR)&param_2);
              }
            }
            local_8._0_1_ = 2;
            if (param_2 != (int *)0x0) {
              (**(code **)(*param_2 + 8))(param_2);
            }
          }
          VariantClear((VARIANTARG *)&local_2c.n2);
        } while (iVar2 < local_18);
      }
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
  }
  VariantClear((VARIANTARG *)&local_3c.n2);
  return iVar1;
}


