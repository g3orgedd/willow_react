// Source: CLCiffConversion_Data.dll @ 45009467; FUN_45009467

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __cdecl FUN_45009467(BSTR param_1,CComBSTR *param_2,VARIANTARG *param_3)

{
  BSTR pOVar1;
  CComBSTR *pCVar2;
  bool bVar3;
  UINT UVar4;
  int iVar5;
  undefined4 uVar6;
  _union_2683 local_40;
  _union_2683 local_30;
  int *local_20;
  int *local_1c;
  int local_18;
  int local_14;
  int local_8;
  undefined4 uStack_4;
  
  pCVar2 = param_2;
  pOVar1 = param_1;
  uStack_4 = 0x30;
  local_8 = 0x45009473;
  if ((*(int *)param_1 == 0) || (UVar4 = SysStringLen(*(BSTR *)param_2), UVar4 == 0)) {
    uVar6 = 0x80070057;
  }
  else {
    VariantClear(param_3);
    bVar3 = false;
    FUN_45001f8d((uint *)&local_40);
    local_8 = 0;
    iVar5 = (**(code **)(**(int **)pOVar1 + 0x494))(*(int **)pOVar1,&local_40);
    if ((-1 < iVar5) &&
       ((local_40.n2.vt == 9 && ((undefined4 *)local_40._8_4_ != (undefined4 *)0x0)))) {
      CComQIPtr<>(&local_1c,(undefined4 *)local_40._8_4_);
      local_8._0_1_ = 1;
      if (local_1c != (int *)0x0) {
        local_18 = 0;
        iVar5 = (**(code **)(*local_1c + 0x24))(local_1c,&local_18);
        local_14 = 0;
        if (0 < local_18) {
          do {
            if ((bVar3) || (iVar5 < 0)) break;
            FUN_45001f8d((uint *)&local_30);
            local_14 = local_14 + 1;
            local_8._0_1_ = 2;
            iVar5 = (**(code **)(*local_1c + 0x20))(local_1c,local_14,&local_30);
            if ((-1 < iVar5) &&
               ((local_30.n2.vt == 9 && ((undefined4 *)local_30._8_4_ != (undefined4 *)0x0)))) {
              CComQIPtr<>(&local_20,(undefined4 *)local_30._8_4_);
              if (local_20 != (int *)0x0) {
                param_1 = (BSTR)0x0;
                local_8._0_1_ = 4;
                iVar5 = (**(code **)(*local_20 + 0x1c))(local_20,&param_1);
                if ((iVar5 < 0) ||
                   (bVar3 = ATL::CComBSTR::operator==((CComBSTR *)&param_1,pCVar2), !bVar3)) {
                  bVar3 = false;
                }
                else {
                  bVar3 = true;
                  FUN_45009434(&local_30,param_3);
                }
                SysFreeString(param_1);
              }
              local_8._0_1_ = 2;
              if (local_20 != (int *)0x0) {
                (**(code **)(*local_20 + 8))(local_20);
              }
            }
            VariantClear((VARIANTARG *)&local_30.n2);
          } while (local_14 < local_18);
        }
      }
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))(local_1c);
      }
    }
    uVar6 = 0x80004005;
    if (bVar3) {
      uVar6 = 0;
    }
    VariantClear((VARIANTARG *)&local_40.n2);
  }
  return uVar6;
}


