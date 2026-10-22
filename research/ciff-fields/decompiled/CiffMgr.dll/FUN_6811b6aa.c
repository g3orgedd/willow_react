// Source: CiffMgr.dll @ 6811b6aa; FUN_6811b6aa

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_6811b6aa(void *this,int *param_1,BSTR param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  BSTR pOVar4;
  _union_2683 local_2c;
  BSTR local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x6811b6b6;
  if (param_1 == (int *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    *(undefined4 *)((int)this + 4) = 1;
    iVar2 = 0;
    CComQIPtr<>(local_14,param_1);
    pOVar4 = param_2;
    local_8 = 0;
    if (local_14[0] != (int *)0x0) {
      local_1c = (BSTR)0x0;
      iVar2 = (**(code **)(**(int **)param_2 + 0x1c))(*(int **)param_2,&local_1c);
      if (-1 < iVar2) {
        local_18 = (int *)0x0;
        local_8._0_1_ = 1;
        iVar2 = (**(code **)(**(int **)pOVar4 + 0x44))(*(int **)pOVar4,&local_18);
        if ((-1 < iVar2) && (local_18 != (int *)0x0)) {
          param_1 = (int *)0x0;
          local_8._0_1_ = 2;
          iVar2 = (**(code **)(*local_18 + 0x1c))(local_18,PTR_DAT_681600cc,&param_1);
          if ((-1 < iVar2) && (param_1 != (int *)0x0)) {
            FUN_68132710((uint *)&local_2c,0,0x10);
            VariantInit((VARIANTARG *)&local_2c.n2);
            local_8._0_1_ = 3;
            (**(code **)(*param_1 + 0x20))(param_1,&local_2c);
            piVar1 = local_14[0];
            if (((local_2c.n2.vt == 8) && ((wchar_t *)local_2c._8_4_ != (wchar_t *)0x0)) &&
               (*(wchar_t *)local_2c._8_4_ != L'\0')) {
              iVar2 = *local_14[0];
              uVar3 = FUN_6812ea65((wchar_t *)local_2c._8_4_);
              (**(code **)(iVar2 + 0x164))(piVar1,uVar3);
              pOVar4 = param_2;
            }
            VariantClear((VARIANTARG *)&local_2c.n2);
          }
          local_8._0_1_ = 1;
          if (param_1 != (int *)0x0) {
            (**(code **)(*param_1 + 8))(param_1);
          }
        }
        param_1 = (int *)0x0;
        local_8 = CONCAT31(local_8._1_3_,4);
        iVar2 = (**(code **)(**(int **)pOVar4 + 0x94))(*(int **)pOVar4,PTR_u_Type_6815fef8,&param_1)
        ;
        if ((iVar2 == 0) && (param_1 != (int *)0x0)) {
          param_2 = (BSTR)0x0;
          iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&param_2);
          if (-1 < iVar2) {
            iVar2 = (**(code **)(*local_14[0] + 0x16c))(local_14[0],param_2);
          }
          SysFreeString(param_2);
        }
        local_8._0_1_ = 1;
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
        }
        local_8 = (uint)local_8._1_3_ << 8;
        if (iVar2 == 1) {
          iVar2 = 0;
        }
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
      }
      SysFreeString(local_1c);
    }
    local_8 = 0xffffffff;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
  }
  return iVar2;
}


