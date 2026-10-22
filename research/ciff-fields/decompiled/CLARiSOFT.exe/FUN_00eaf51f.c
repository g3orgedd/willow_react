// Source: CLARiSOFT.exe @ 00eaf51f; FUN_00eaf51f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 __cdecl FUN_00eaf51f(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  VARIANTARG local_38;
  VARIANTARG local_28;
  int *local_18;
  int local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0x28;
  local_8 = 0xeaf52b;
  if (*param_1 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0;
    FUN_00e03b51((uint *)&local_38);
    local_8 = 0;
    iVar2 = (**(code **)(*(int *)*piVar1 + 0x47c))((int *)*piVar1,&local_38);
    if ((-1 < iVar2) && ((undefined4 *)local_38.n1._8_4_ != (undefined4 *)0x0)) {
      CComQIPtr<>(&local_18,(undefined4 *)local_38.n1._8_4_);
      FUN_00e03b51((uint *)&local_28);
      local_8._0_1_ = 2;
      if (local_18 != (int *)0x0) {
        iVar2 = (**(code **)(*local_18 + 0x20))(local_18,1,&local_28);
      }
      if ((-1 < iVar2) && ((undefined4 *)local_28.n1._8_4_ != (undefined4 *)0x0)) {
        CComQIPtr<>(&param_1,(undefined4 *)local_28.n1._8_4_);
        local_8._0_1_ = 3;
        if (param_1 != (int *)0x0) {
          local_14[0] = 0;
          iVar2 = (**(code **)(*param_1 + 0x74))(param_1,local_14);
          if ((iVar2 < 0) || (local_14[0] != 1)) {
            uVar3 = 0;
          }
          else {
            uVar3 = 1;
          }
        }
        local_8._0_1_ = 2;
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
        }
      }
      VariantClear(&local_28);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
    }
    VariantClear(&local_38);
  }
  return uVar3;
}


