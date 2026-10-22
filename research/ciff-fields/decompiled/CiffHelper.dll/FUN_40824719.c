// Source: CiffHelper.dll @ 40824719; FUN_40824719

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_40824719(BSTR param_1,undefined4 *param_2)

{
  int *piVar1;
  BSTR pOVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined3 extraout_var;
  int iVar5;
  VARIANTARG local_30;
  int local_20;
  int *local_1c;
  LPCWSTR local_18;
  BSTR local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  pOVar2 = param_1;
  uStack_4 = 0x20;
  local_14[0] = (BSTR)0x0;
  local_8 = 0;
  (**(code **)(**(int **)param_1 + 0x5c))(*(int **)param_1,local_14);
  if ((local_14[0] == (BSTR)0x0) || (bVar3 = FUN_40803ed6(local_14,L""), bVar3)) {
    piVar1 = *(int **)pOVar2;
    uVar4 = (**(code **)(*piVar1 + 0x60))(piVar1,L"Table containing Index Fields");
  }
  else {
    local_20 = 0;
    uVar4 = (**(code **)(*(int *)*param_2 + 0x1c))((int *)*param_2,&local_20);
    iVar5 = 1;
    if (0 < local_20) {
      do {
        FUN_40802e76((uint *)&local_30);
        local_8._0_1_ = 1;
        (**(code **)(*(int *)*param_2 + 0x30))((int *)*param_2,iVar5,&local_30);
        CComQIPtr<>(&local_1c,(undefined4 *)local_30.n1._8_4_);
        local_18 = (LPCWSTR)0x0;
        local_8._0_1_ = 3;
        uVar4 = (**(code **)(*local_1c + 0x34))(local_1c,&local_18);
        bVar3 = FUN_40805005(local_18,(ushort *)local_14[0]);
        if (CONCAT31(extraout_var,bVar3) != 0) {
          param_1 = (BSTR)0x0;
          local_8._0_1_ = 4;
          (**(code **)(*local_1c + 0x1c))(local_1c,&param_1);
          piVar1 = *(int **)pOVar2;
          uVar4 = (**(code **)(*piVar1 + 0x60))(piVar1,param_1);
          SysFreeString(param_1);
        }
        SysFreeString(local_18);
        local_8._0_1_ = 1;
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))(local_1c);
        }
        local_8 = (uint)local_8._1_3_ << 8;
        VariantClear(&local_30);
        iVar5 = iVar5 + 1;
      } while (iVar5 <= local_20);
    }
  }
  SysFreeString(local_14[0]);
  return uVar4;
}


