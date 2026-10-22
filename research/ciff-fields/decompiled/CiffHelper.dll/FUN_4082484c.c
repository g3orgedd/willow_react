// Source: CiffHelper.dll @ 4082484c; FUN_4082484c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_4082484c(BSTR param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined3 extraout_var;
  int iVar4;
  VARIANTARG local_34;
  int local_24;
  BSTR local_20;
  int *local_1c;
  int local_18;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x40824858;
  FUN_40802e76((uint *)&local_34);
  local_8 = 0;
  (**(code **)(**(int **)param_1 + 100))(*(int **)param_1,&local_34);
  CComQIPtr<>(&local_1c,(undefined4 *)local_34.n1._8_4_);
  iVar4 = 1;
  local_8._0_1_ = 1;
  puVar2 = FUN_40828a2f(&local_24,0x64cc);
  local_8._0_1_ = 2;
  FUN_40802e40(&local_20,(OLECHAR *)*puVar2);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_40803143(&local_24);
  local_18 = 0;
  uVar3 = (**(code **)(*local_1c + 0x1c))(local_1c,&local_18);
  if (0 < local_18) {
    do {
      (**(code **)(*local_1c + 0x30))(local_1c,iVar4,&local_34);
      CComQIPtr<>(local_14,(undefined4 *)local_34.n1._8_4_);
      param_1 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,6);
      uVar3 = (**(code **)(*local_14[0] + 0x5c))(local_14[0],&param_1);
      bVar1 = FUN_40805005(param_1,(ushort *)local_20);
      if (CONCAT31(extraout_var,bVar1) != 0) {
        uVar3 = (**(code **)(*local_14[0] + 0x60))(local_14[0],L"Table containing Index Fields");
      }
      SysFreeString(param_1);
      local_8 = CONCAT31(local_8._1_3_,4);
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= local_18);
  }
  SysFreeString(local_20);
  local_8 = local_8 & 0xffffff00;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  VariantClear(&local_34);
  return uVar3;
}


