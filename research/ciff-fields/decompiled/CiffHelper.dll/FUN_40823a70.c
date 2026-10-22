// Source: CiffHelper.dll @ 40823a70; FUN_40823a70

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_40823a70(BSTR param_1)

{
  int *piVar1;
  BSTR pOVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  VARIANTARG local_34;
  undefined4 local_24;
  int local_20;
  int *local_1c;
  int local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  pOVar2 = param_1;
  uStack_4 = 0x24;
  piVar1 = *(int **)param_1;
  if (piVar1 == (int *)0x0) {
    iVar4 = -0x7fffbffd;
  }
  else {
    param_1 = (BSTR)0x0;
    local_8 = 0;
    iVar4 = (**(code **)(*piVar1 + 0x44))(piVar1,&param_1);
    local_20 = iVar4;
    if ((iVar4 < 0) ||
       ((bVar3 = FUN_40803ed6(&param_1,L"VJ1550"), !bVar3 &&
        (bVar3 = FUN_40803ed6(&param_1,L"VJ1650"), !bVar3)))) {
      piVar1 = *(int **)pOVar2;
      local_18 = 0;
      iVar5 = (**(code **)(*piVar1 + 0x1c))(piVar1,&local_18);
      local_1c = (int *)0x0;
      if (0 < local_18) {
        iVar6 = 0;
        do {
          iVar4 = local_20;
          if (iVar5 < 0) break;
          FUN_40802e76((uint *)&local_34);
          piVar1 = *(int **)pOVar2;
          iVar6 = iVar6 + 1;
          local_8._0_1_ = 1;
          iVar5 = (**(code **)(*piVar1 + 0x24))(piVar1,iVar6,&local_34);
          CComQIPtr<>(local_14,(undefined4 *)local_34.n1._8_4_);
          if ((-1 < iVar5) && (local_14[0] != (int *)0x0)) {
            CComQIPtr<>(&local_1c,local_14[0]);
            if (local_1c != (int *)0x0) {
              local_24 = 0;
              local_8._0_1_ = 4;
              iVar5 = (**(code **)(*local_1c + 0xd0))(local_1c,0);
              SysFreeString((BSTR)0x0);
            }
            local_8._0_1_ = 2;
            if (local_1c != (int *)0x0) {
              (**(code **)(*local_1c + 8))(local_1c);
            }
          }
          local_8._0_1_ = 1;
          if (local_14[0] != (int *)0x0) {
            (**(code **)(*local_14[0] + 8))(local_14[0]);
          }
          local_8 = (uint)local_8._1_3_ << 8;
          VariantClear(&local_34);
          iVar4 = local_20;
        } while (iVar6 < local_18);
      }
    }
    SysFreeString(param_1);
  }
  return iVar4;
}


