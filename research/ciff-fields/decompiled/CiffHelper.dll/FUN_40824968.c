// Source: CiffHelper.dll @ 40824968; FUN_40824968

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_40824968(LPCWSTR param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined3 extraout_var;
  LPCWSTR pWVar5;
  VARIANTARG local_38;
  int local_28;
  BSTR local_24;
  LPCWSTR local_20;
  uint local_1c;
  int local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x40824974;
  FUN_40802e76((uint *)&local_38);
  local_8 = 0;
  iVar2 = (**(code **)(**(int **)param_1 + 0xcc))(*(int **)param_1,&local_38);
  if (iVar2 < 0) goto LAB_40824b3f;
  CComQIPtr<>(local_14,(undefined4 *)local_38.n1._8_4_);
  local_8._0_1_ = 1;
  puVar3 = FUN_40828a2f(&local_28,0x64cc);
  local_8._0_1_ = 2;
  FUN_40802e40(&local_24,(OLECHAR *)*puVar3);
  local_8._0_1_ = 4;
  local_1c = FUN_40803143(&local_28);
  local_1c = local_1c & 0xffffff00;
  local_18 = 0;
  iVar2 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],&local_18);
  if (-1 < iVar2) {
    iVar4 = 1;
    if (0 < local_18) {
      do {
        iVar2 = (**(code **)(*local_14[0] + 0x30))(local_14[0],iVar4,&local_38);
        if (iVar2 < 0) goto LAB_40824b29;
        CComQIPtr<>(&local_20,(undefined4 *)local_38.n1._8_4_);
        param_1 = (LPCWSTR)0x0;
        local_8._0_1_ = 6;
        iVar2 = (**(code **)(*(int *)local_20 + 0x1c))(local_20,&param_1);
        if (iVar2 < 0) {
          SysFreeString(param_1);
          pWVar5 = local_20;
          goto LAB_40824b1b;
        }
        bVar1 = FUN_40805005(param_1,(ushort *)local_24);
        local_1c = local_1c & 0xff;
        if (CONCAT31(extraout_var,bVar1) != 0) {
          local_1c = 1;
        }
        SysFreeString(param_1);
        local_8._0_1_ = 4;
        if (local_20 != (LPCWSTR)0x0) {
          (**(code **)(*(int *)local_20 + 8))(local_20);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 <= local_18);
      if ((char)local_1c != '\0') goto LAB_40824b29;
    }
    iVar2 = (**(code **)(*local_14[0] + 0x20))(local_14[0],local_24,&local_38);
    if (-1 < iVar2) {
      CComQIPtr<>(&param_1,(undefined4 *)local_38.n1._8_4_);
      local_8._0_1_ = 7;
      iVar2 = (**(code **)(*(int *)param_1 + 0x28))(param_1,L"JOBS");
      pWVar5 = param_1;
      if ((-1 < iVar2) &&
         (iVar2 = (**(code **)(*(int *)param_1 + 0x30))(param_1,L"UniqueJobCode"), pWVar5 = param_1,
         -1 < iVar2)) {
        puVar3 = FUN_40806e74(&local_1c);
        local_8._0_1_ = 8;
        FUN_40802e40(&local_20,(OLECHAR *)*puVar3);
        local_8._0_1_ = 10;
        FUN_40803143((int *)&local_1c);
        iVar2 = (**(code **)(*(int *)param_1 + 0x38))(param_1,local_20);
        SysFreeString(local_20);
        pWVar5 = param_1;
      }
LAB_40824b1b:
      local_8._0_1_ = 4;
      if (pWVar5 != (LPCWSTR)0x0) {
        (**(code **)(*(int *)pWVar5 + 8))(pWVar5);
      }
    }
  }
LAB_40824b29:
  SysFreeString(local_24);
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
LAB_40824b3f:
  VariantClear(&local_38);
  return iVar2;
}


