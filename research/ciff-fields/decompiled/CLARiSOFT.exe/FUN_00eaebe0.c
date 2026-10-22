// Source: CLARiSOFT.exe @ 00eaebe0; FUN_00eaebe0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 FUN_00eaebe0(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined1 uVar2;
  int iVar3;
  VARIANTARG local_4c;
  VARIANTARG local_3c;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  BSTR local_1c;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0;
  (**(code **)(*param_1 + 0x24))(param_1,&local_24);
  local_1c = (BSTR)0x0;
  uVar2 = 1;
  local_8._0_1_ = 1;
  (**(code **)(*param_1 + 0x3c))(param_1,&local_1c);
  if (local_24 != 0) {
    bVar1 = FUN_00e03edc(&local_1c,L"Free");
    if (!bVar1) {
      FUN_00e03b51((uint *)&local_4c);
      local_8._0_1_ = 2;
      (**(code **)(*param_1 + 0x7c))(param_1,&local_4c);
      CComQIPtr<>(&local_18,(undefined4 *)local_4c.n1._8_4_);
      local_8 = CONCAT31(local_8._1_3_,3);
      (**(code **)(*local_18 + 0x24))(local_18,&local_20);
      iVar3 = 0;
      if (0 < local_20) {
        do {
          FUN_00e03b51((uint *)&local_3c);
          iVar3 = iVar3 + 1;
          local_8._0_1_ = 4;
          (**(code **)(*local_18 + 0x20))(local_18,iVar3,&local_3c);
          CComQIPtr<>(local_14,(undefined4 *)local_3c.n1._8_4_);
          local_8._0_1_ = 5;
          (**(code **)(*local_14[0] + 0x2c))(local_14[0],&local_28);
          (**(code **)(*local_14[0] + 0x1c))(local_14[0],&local_2c);
          if ((local_28 == param_2) && (local_2c == param_3)) {
            local_8 = CONCAT31(local_8._1_3_,4);
            if (local_14[0] != (int *)0x0) {
              (**(code **)(*local_14[0] + 8))(local_14[0]);
            }
            VariantClear(&local_3c);
            goto LAB_00eaece7;
          }
          local_8 = CONCAT31(local_8._1_3_,4);
          if (local_14[0] != (int *)0x0) {
            (**(code **)(*local_14[0] + 8))(local_14[0]);
          }
          VariantClear(&local_3c);
        } while (iVar3 < local_20);
      }
      uVar2 = 0;
LAB_00eaece7:
      local_8._0_1_ = 2;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
      VariantClear(&local_4c);
    }
  }
  SysFreeString(local_1c);
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return uVar2;
}


