// Source: CLCiffConversion_Data.dll @ 45010317; FUN_45010317

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_45010317(void *this,BSTR param_1)

{
  BSTR pOVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined3 extraout_var;
  int iVar5;
  undefined4 uVar6;
  VARIANTARG local_4c;
  VARIANTARG local_3c;
  int local_2c;
  int local_28;
  int *local_24;
  int *local_20;
  undefined4 local_1c;
  int local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x45010323;
  CComQIPtr<>(&local_24,*(undefined4 **)(*(int *)(*(int *)this + 4) + 0x34 + (int)this));
  local_8 = 0;
  FUN_45001f8d((uint *)&local_4c);
  local_8._0_1_ = 1;
  (**(code **)(*local_24 + 0xcc))(local_24,&local_4c);
  CComQIPtr<>(&local_20,(undefined4 *)local_4c.n1._8_4_);
  local_18 = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  local_1c = (**(code **)(*local_20 + 0x1c))(local_20,&local_18);
  pOVar1 = param_1;
  iVar5 = 1;
  uVar6 = local_1c;
  if (0 < local_18) {
    do {
      FUN_45001f8d((uint *)&local_3c);
      local_8._0_1_ = 3;
      (**(code **)(*local_20 + 0x30))(local_20,iVar5,&local_3c);
      CComQIPtr<>(local_14,(undefined4 *)local_3c.n1._8_4_);
      if (local_14[0] == (int *)0x0) {
        local_1c = 0x80004005;
      }
      else {
        param_1 = (BSTR)0x0;
        local_8._0_1_ = 5;
        (**(code **)(*local_14[0] + 0x1c))(local_14[0],&param_1);
        puVar3 = FUN_450020a5(&local_2c,*(LPCWSTR *)pOVar1);
        local_8._0_1_ = 6;
        puVar4 = FUN_450020a5(&local_28,param_1);
        local_8._0_1_ = 7;
        bVar2 = FUN_450034f4((LPCWSTR)*puVar4,(ushort *)*puVar3);
        FUN_45002256(&local_28);
        local_8._0_1_ = 5;
        FUN_45002256(&local_2c);
        if (CONCAT31(extraout_var,bVar2) != 0) {
          SysFreeString(*(BSTR *)pOVar1);
          pOVar1[0] = L'\0';
          pOVar1[1] = L'\0';
          (**(code **)(*local_14[0] + 0x34))(local_14[0],pOVar1);
          SysFreeString(param_1);
          local_8 = CONCAT31(local_8._1_3_,3);
          if (local_14[0] != (int *)0x0) {
            (**(code **)(*local_14[0] + 8))(local_14[0]);
          }
          VariantClear(&local_3c);
          uVar6 = local_1c;
          break;
        }
        SysFreeString(param_1);
      }
      uVar6 = local_1c;
      local_8 = CONCAT31(local_8._1_3_,3);
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
      VariantClear(&local_3c);
      iVar5 = iVar5 + 1;
    } while (iVar5 <= local_18);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  VariantClear(&local_4c);
  local_8 = 0xffffffff;
  if (local_24 != (int *)0x0) {
    (**(code **)(*local_24 + 8))(local_24);
  }
  return uVar6;
}


