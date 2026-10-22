// Source: CiffHelper.dll @ 408237fd; FUN_408237fd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_408237fd(BSTR param_1)

{
  int *piVar1;
  BSTR pOVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  _union_2683 local_34;
  int local_24;
  int local_20;
  int *local_1c;
  BSTR local_18;
  BSTR local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  pOVar2 = param_1;
  uStack_4 = 0x24;
  piVar1 = *(int **)param_1;
  if (piVar1 == (int *)0x0) {
    return -0x7fffbffd;
  }
  local_18 = (BSTR)0x0;
  local_8 = 0;
  iVar4 = (**(code **)(*piVar1 + 0x44))(piVar1,&local_18);
  if ((-1 < iVar4) &&
     ((bVar3 = FUN_40803ed6(&local_18,L"VJ1000 Line Touch"), bVar3 ||
      (bVar3 = FUN_40803ed6(&local_18,L"VJ Comet"), bVar3)))) {
    FUN_40802e40(&param_1,L"VJ1650");
    local_8._0_1_ = 1;
    (**(code **)(**(int **)pOVar2 + 0x48))(*(int **)pOVar2,param_1);
    local_8 = (uint)local_8._1_3_ << 8;
    SysFreeString(param_1);
  }
  local_24 = 0;
  iVar4 = (**(code **)(**(int **)pOVar2 + 0x1c))(*(int **)pOVar2,&local_24);
  local_20 = 0;
  if (0 < local_24) {
    do {
      if (iVar4 < 0) break;
      FUN_40802e76((uint *)&local_34);
      local_20 = local_20 + 1;
      local_8._0_1_ = 2;
      iVar4 = (**(code **)(**(int **)pOVar2 + 0x24))(*(int **)pOVar2,local_20,&local_34);
      if ((-1 < iVar4) && (local_34.n2.vt == 9)) {
        CComQIPtr<>(&local_1c,(undefined4 *)local_34._8_4_);
        if (local_1c != (int *)0x0) {
          local_14[0] = (BSTR)0x0;
          local_8._0_1_ = 4;
          iVar5 = (**(code **)(*local_1c + 0x9c))(local_1c,local_14);
          if ((-1 < iVar5) &&
             ((bVar3 = FUN_40803ed6(local_14,L"VJ1000 Line Touch"), bVar3 ||
              (bVar3 = FUN_40803ed6(local_14,L"VJ Comet"), bVar3)))) {
            param_1 = (BSTR)0x0;
            local_8._0_1_ = 5;
            iVar5 = (**(code **)(**(int **)pOVar2 + 0x44))(*(int **)pOVar2,&param_1);
            if (iVar5 != 0) {
              SysStringLen(param_1);
            }
            (**(code **)(*local_1c + 0xa0))(local_1c,param_1);
            SysFreeString(param_1);
          }
          SysFreeString(local_14[0]);
        }
        local_8._0_1_ = 2;
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))(local_1c);
        }
      }
      local_8 = (uint)local_8._1_3_ << 8;
      VariantClear((VARIANTARG *)&local_34.n2);
    } while (local_20 < local_24);
  }
  SysFreeString(local_18);
  return iVar4;
}


