// Source: CiffHelper.dll @ 4082461d; FUN_4082461d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_4082461d(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  VARIANTARG local_3c;
  VARIANTARG local_2c;
  int *local_1c;
  int *local_18;
  int local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x40824629;
  FUN_40802e76((uint *)&local_2c);
  piVar1 = param_1;
  local_8 = 0;
  (**(code **)(*(int *)*param_1 + 100))((int *)*param_1,&local_2c);
  CComQIPtr<>(&local_18,(undefined4 *)local_2c.n1._8_4_);
  FUN_40802e76((uint *)&local_3c);
  local_8._0_1_ = 2;
  (**(code **)(*(int *)*piVar1 + 0xcc))((int *)*piVar1,&local_3c);
  CComQIPtr<>(&local_1c,(undefined4 *)local_3c.n1._8_4_);
  local_14[0] = 0;
  local_8 = CONCAT31(local_8._1_3_,3);
  uVar2 = (**(code **)(*local_18 + 0x1c))(local_18,local_14);
  iVar3 = 1;
  if (0 < local_14[0]) {
    do {
      (**(code **)(*local_18 + 0x30))(local_18,iVar3,&local_2c);
      CComQIPtr<>(&param_1,(undefined4 *)local_2c.n1._8_4_);
      local_8._0_1_ = 4;
      uVar2 = FUN_40824719((BSTR)&param_1,&local_1c);
      local_8 = CONCAT31(local_8._1_3_,3);
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))(param_1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= local_14[0]);
  }
  local_8._0_1_ = 2;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  VariantClear(&local_3c);
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  VariantClear(&local_2c);
  return uVar2;
}


