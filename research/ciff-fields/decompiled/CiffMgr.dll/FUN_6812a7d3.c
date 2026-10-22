// Source: CiffMgr.dll @ 6812a7d3; FUN_6812a7d3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_6812a7d3(BSTR param_1,int *param_2,int *param_3)

{
  BSTR pOVar1;
  int iVar2;
  OLECHAR *psz;
  UINT UVar3;
  wchar_t *pwVar4;
  int *piVar5;
  int *piVar6;
  int **ppiVar7;
  _union_2683 local_34;
  int local_24;
  void *local_20;
  int *local_1c;
  int local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar6 = param_3;
  uStack_4 = 0x24;
  local_18 = 0;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  iVar2 = (**(code **)(*(int *)*param_3 + 0x44))((int *)*param_3,local_14);
  pOVar1 = param_1;
  if ((-1 < iVar2) && (local_14[0] != (int *)0x0)) {
    FUN_68132710((uint *)&local_34,0,0x10);
    VariantInit((VARIANTARG *)&local_34.n2);
    local_34._8_4_ = (BSTR)0x0;
    local_34.n2.vt = 8;
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar2 = (**(code **)(*(int *)*param_2 + 0x1c))();
    if ((-1 < iVar2) &&
       ((iVar2 = FUN_681021f5((undefined4 *)pOVar1,local_14,PTR_u_Name_68160030,
                              (undefined4 *)&local_34), -1 < iVar2 &&
        (iVar2 = (**(code **)(*(int *)*param_2 + 0x24))(), -1 < iVar2)))) {
      if (local_18 != 1) {
        SysFreeString((BSTR)local_34._8_4_);
        psz = (OLECHAR *)FUN_6812f488(local_18);
        local_34._8_4_ = SysAllocString(psz);
        iVar2 = FUN_681021f5((undefined4 *)pOVar1,local_14,PTR_u_Type_6816003c,
                             (undefined4 *)&local_34);
      }
      piVar6 = param_3;
      if (-1 < iVar2) {
        CComQIPtr<>(&local_1c,(undefined4 *)*param_2);
        local_8._0_1_ = 2;
        if (local_1c != (int *)0x0) {
          local_24 = 0;
          piVar6 = &local_24;
          piVar5 = local_1c;
          iVar2 = (**(code **)(*local_1c + 0x34))();
          if ((-1 < iVar2) && (local_24 != 0)) {
            SysFreeString((BSTR)local_34._8_4_);
            local_34._8_4_ = SysAllocString(L"1");
            FUN_681021f5((undefined4 *)pOVar1,local_14,PTR_u_Database_681600f8,
                         (undefined4 *)&local_34);
          }
          param_1 = (BSTR)0x0;
          local_8._0_1_ = 3;
          iVar2 = (**(code **)(*local_1c + 0x3c))(local_1c,&param_1,piVar5,piVar6);
          if ((-1 < iVar2) && (UVar3 = SysStringLen(param_1), UVar3 != 0)) {
            SysFreeString((BSTR)local_34._8_4_);
            local_34._8_4_ = param_1;
            param_1 = (BSTR)0x0;
            iVar2 = FUN_681021f5((undefined4 *)pOVar1,local_14,PTR_u_DataSource_681600fc,
                                 (undefined4 *)&local_34);
          }
          SysFreeString(param_1);
        }
        local_8 = CONCAT31(local_8._1_3_,1);
        piVar6 = param_3;
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))(local_1c);
          piVar6 = param_3;
        }
      }
    }
    VariantClear((VARIANTARG *)&local_34.n2);
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  if (iVar2 < 0) {
    return iVar2;
  }
  FUN_68132710((uint *)&local_34,0,0x10);
  VariantInit((VARIANTARG *)&local_34.n2);
  local_8 = 4;
  iVar2 = (**(code **)(*(int *)*param_2 + 0x2c))();
  if (iVar2 < 0) goto LAB_6812aaf5;
  if (-1 < local_18) {
    if (local_18 < 2) {
      if (local_34.n2.vt == 3) {
        param_2 = (int *)0x0;
        piVar6 = *(int **)pOVar1;
        ppiVar7 = &param_2;
        iVar2 = *piVar6;
        local_8 = CONCAT31(local_8._1_3_,5);
        pwVar4 = FUN_6812f174(local_20,local_34._8_4_);
LAB_6812aab8:
        iVar2 = (**(code **)(iVar2 + 0xc4))(piVar6,pwVar4,ppiVar7);
        piVar5 = param_2;
        if ((-1 < iVar2) && (param_2 != (int *)0x0)) {
          iVar2 = (**(code **)(*(int *)*param_3 + 0x54))((int *)*param_3,param_2,0);
          piVar5 = param_2;
        }
LAB_6812aae0:
        local_8 = CONCAT31(local_8._1_3_,4);
        if (piVar5 != (int *)0x0) {
          (**(code **)(*piVar5 + 8))(piVar5);
        }
        goto LAB_6812aaf5;
      }
    }
    else if (local_18 == 2) {
      if (local_34.n2.vt == 8) {
        param_3 = (int *)0x0;
        local_8 = CONCAT31(local_8._1_3_,6);
        iVar2 = (**(code **)(**(int **)pOVar1 + 0xcc))(*(int **)pOVar1,local_34._8_4_,&param_3);
        piVar5 = param_3;
        if ((-1 < iVar2) && (param_3 != (int *)0x0)) {
          iVar2 = (**(code **)(*(int *)*piVar6 + 0x54))((int *)*piVar6,param_3,0);
          piVar5 = param_3;
        }
        goto LAB_6812aae0;
      }
    }
    else if ((local_18 == 3) && (local_34.n2.vt == 5)) {
      param_2 = (int *)0x0;
      piVar6 = *(int **)pOVar1;
      ppiVar7 = &param_2;
      iVar2 = *piVar6;
      local_8 = CONCAT31(local_8._1_3_,7);
      pwVar4 = FUN_6812eef6(local_20,CONCAT44(local_34._12_4_,local_34._8_4_));
      goto LAB_6812aab8;
    }
  }
  iVar2 = -0x7ff8ffa9;
LAB_6812aaf5:
  VariantClear((VARIANTARG *)&local_34.n2);
  return iVar2;
}


