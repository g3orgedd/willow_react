// Source: CiffMgr.dll @ 68120fc0; FUN_68120fc0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_68120fc0(int *param_1,BSTR param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  UINT UVar4;
  long lVar5;
  BSTR pOVar6;
  _union_2683 local_34;
  int local_24 [2];
  int *local_1c;
  BSTR local_18;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0x24;
  local_8 = 0x68120fcc;
  if (param_1 == (int *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    (**(code **)(*param_1 + 0x28))(param_1,local_24);
    pOVar6 = param_2;
    if (local_24[0] == 1) {
      local_1c = (int *)0x0;
      local_8._0_1_ = 0;
      local_8._1_3_ = 0;
      iVar2 = (**(code **)(**(int **)param_2 + 0x44))(*(int **)param_2,&local_1c);
      if ((-1 < iVar2) && (local_1c != (int *)0x0)) {
        param_1 = (int *)0x0;
        local_8._0_1_ = 1;
        iVar2 = (**(code **)(*local_1c + 0x1c))(local_1c,PTR_u_SrcFieldName_6816005c,&param_1);
        if ((iVar2 == 0) && (param_1 != (int *)0x0)) {
          FUN_68132710((uint *)&local_34,0,0x10);
          VariantInit((VARIANTARG *)&local_34.n2);
          local_8._0_1_ = 2;
          (**(code **)(*param_1 + 0x20))(param_1,&local_34);
          if (local_34.n2.vt == 8) {
            (**(code **)(*piVar1 + 0xe8))(piVar1,local_34._8_4_);
          }
          VariantClear((VARIANTARG *)&local_34.n2);
        }
        local_8._0_1_ = 0;
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
        }
      }
      param_1 = (int *)0x0;
      local_8 = CONCAT31(local_8._1_3_,3);
      iVar2 = (**(code **)(**(int **)pOVar6 + 0x94))
                        (*(int **)pOVar6,PTR_u_StartChar_6815fd68,&param_1);
      if ((iVar2 == 0) && (param_1 != (int *)0x0)) {
        local_18 = (BSTR)0x0;
        iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
        if (-1 < iVar2) {
          iVar2 = *piVar1;
          iVar3 = FUN_6812f116((ushort *)local_18);
          (**(code **)(iVar2 + 0xf0))(piVar1,iVar3);
          pOVar6 = param_2;
        }
        SysFreeString(local_18);
      }
      local_8 = local_8 & 0xffffff00;
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))(param_1);
      }
      param_1 = (int *)0x0;
      local_8 = CONCAT31(local_8._1_3_,4);
      iVar2 = (**(code **)(**(int **)pOVar6 + 0x94))
                        (*(int **)pOVar6,PTR_u_NoOfChars_6815fd6c,&param_1);
      if ((iVar2 == 0) && (param_1 != (int *)0x0)) {
        local_18 = (BSTR)0x0;
        iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
        if (-1 < iVar2) {
          iVar2 = *piVar1;
          iVar3 = FUN_6812f116((ushort *)local_18);
          iVar2 = (**(code **)(iVar2 + 0xf8))(piVar1,iVar3);
        }
        SysFreeString(local_18);
      }
      local_8 = local_8 & 0xffffff00;
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))(param_1);
      }
      CComQIPtr<>(local_14,piVar1);
      if (local_14[0] != (int *)0x0) {
        param_1 = (int *)0x0;
        local_8._0_1_ = 6;
        iVar2 = (**(code **)(**(int **)param_2 + 0x94))
                          (*(int **)param_2,PTR_u_SelectMode_6815fff0,&param_1);
        if ((iVar2 == 0) && (param_1 != (int *)0x0)) {
          param_2 = (BSTR)0x0;
          local_8._0_1_ = 7;
          iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&param_2);
          if ((-1 < iVar2) && (UVar4 = SysStringLen(param_2), UVar4 != 0)) {
            lVar5 = __wtol(param_2);
            iVar2 = (**(code **)(*local_14[0] + 0x194))(local_14[0],lVar5 == 1);
          }
          SysFreeString(param_2);
        }
        local_8 = CONCAT31(local_8._1_3_,5);
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
        }
      }
      local_8 = local_8 & 0xffffff00;
      if (iVar2 == 1) {
        iVar2 = 0;
      }
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
      local_8 = 0xffffffff;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))(local_1c);
      }
    }
    else {
      iVar2 = -0x7ff8ffa9;
    }
  }
  return iVar2;
}


