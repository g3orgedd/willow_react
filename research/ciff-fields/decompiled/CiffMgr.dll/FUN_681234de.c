// Source: CiffMgr.dll @ 681234de; FUN_681234de

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_681234de(BSTR param_1,int *param_2)

{
  BSTR pOVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  size_t sVar5;
  _union_2683 local_5c;
  _union_2683 local_4c;
  _union_2683 local_3c;
  int local_2c;
  int *local_28 [2];
  BSTR local_20;
  BSTR local_1c;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  pOVar1 = param_1;
  uStack_4 = 0x4c;
  local_8 = 0x681234ea;
  if (param_1 == (BSTR)0x0) {
    iVar3 = -0x7fffbffd;
  }
  else {
    (**(code **)(*(int *)param_1 + 0x28))(param_1,&local_2c);
    piVar2 = param_2;
    if (local_2c == 3) {
      local_18 = (int *)0x0;
      local_8 = 0;
      iVar3 = (**(code **)(*(int *)*param_2 + 0x94))
                        ((int *)*param_2,PTR_u_Prompt_6815fc78,&local_18);
      if ((iVar3 == 0) && (local_18 != (int *)0x0)) {
        param_1 = (BSTR)0x0;
        iVar3 = (**(code **)(*local_18 + 0x68))(local_18,&param_1);
        if (-1 < iVar3) {
          (**(code **)(*(int *)pOVar1 + 0xc0))(pOVar1,param_1);
        }
        SysFreeString(param_1);
      }
      local_8 = 0xffffffff;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
      local_18 = (int *)0x0;
      local_8 = 1;
      iVar3 = (**(code **)(*(int *)*piVar2 + 0x94))((int *)*piVar2,PTR_u_Mask_6815fd74,&local_18);
      if ((iVar3 == 0) && (local_18 != (int *)0x0)) {
        param_1 = (BSTR)0x0;
        iVar3 = (**(code **)(*local_18 + 0x68))(local_18,&param_1);
        if (-1 < iVar3) {
          (**(code **)(*(int *)pOVar1 + 200))(pOVar1,param_1);
        }
        SysFreeString(param_1);
      }
      local_8 = 0xffffffff;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
      local_18 = (int *)0x0;
      local_8 = 2;
      iVar3 = (**(code **)(*(int *)*piVar2 + 0x94))
                        ((int *)*piVar2,PTR_u_UserEnterData_6815fd78,&local_18);
      if ((iVar3 == 0) && (local_18 != (int *)0x0)) {
        param_1 = (BSTR)0x0;
        iVar3 = (**(code **)(*local_18 + 0x68))(local_18,&param_1);
        if (-1 < iVar3) {
          (**(code **)(*(int *)pOVar1 + 0xd0))(pOVar1,param_1);
        }
        SysFreeString(param_1);
      }
      local_8 = 0xffffffff;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
      local_18 = (int *)0x0;
      local_8 = 3;
      iVar3 = (**(code **)(*(int *)*piVar2 + 0x94))
                        ((int *)*piVar2,PTR_u_PromptAtCoder_6815fd7c,&local_18);
      if ((iVar3 == 0) && (local_18 != (int *)0x0)) {
        param_1 = (BSTR)0x0;
        iVar3 = (**(code **)(*local_18 + 0x68))(local_18,&param_1);
        if (-1 < iVar3) {
          iVar3 = *(int *)pOVar1;
          uVar4 = FUN_6812e988(param_1);
          (**(code **)(iVar3 + 0xd8))(pOVar1,uVar4);
        }
        SysFreeString(param_1);
      }
      local_8 = 0xffffffff;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
      local_18 = (int *)0x0;
      local_8 = 4;
      iVar3 = (**(code **)(*(int *)*piVar2 + 0x94))
                        ((int *)*piVar2,PTR_u_ResetOnSel_6815fc7c,&local_18);
      if ((iVar3 == 0) && (local_18 != (int *)0x0)) {
        param_1 = (BSTR)0x0;
        iVar3 = (**(code **)(*local_18 + 0x68))(local_18,&param_1);
        if (-1 < iVar3) {
          iVar3 = *(int *)pOVar1;
          uVar4 = FUN_6812fb44(param_1);
          (**(code **)(iVar3 + 0xe0))(pOVar1,uVar4);
        }
        SysFreeString(param_1);
      }
      local_8 = 0xffffffff;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
      param_1 = (BSTR)0x0;
      local_8 = 5;
      iVar3 = (**(code **)(*(int *)*piVar2 + 0x94))((int *)*piVar2,PTR_u_ListData_6815fd80,&param_1)
      ;
      if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
        local_28[0] = (int *)0x0;
        local_8._0_1_ = 6;
        iVar3 = (**(code **)(*(int *)param_1 + 0x44))(param_1,local_28);
        if ((-1 < iVar3) && (local_28[0] != (int *)0x0)) {
          param_2 = (int *)0x0;
          local_8._0_1_ = 7;
          iVar3 = (**(code **)(*local_28[0] + 0x1c))(local_28[0],PTR_u_Mask_68160104,&param_2);
          if ((-1 < iVar3) && (param_2 != (int *)0x0)) {
            FUN_68132710((uint *)&local_3c,0,0x10);
            VariantInit((VARIANTARG *)&local_3c.n2);
            local_8._0_1_ = 8;
            (**(code **)(*param_2 + 0x20))(param_2,&local_3c);
            if ((local_3c.n2.vt == 8) &&
               (((wchar_t *)local_3c._8_4_ != (wchar_t *)0x0 &&
                (sVar5 = _wcslen((wchar_t *)local_3c._8_4_), sVar5 != 0)))) {
              CComQIPtr<>(&local_1c,(undefined4 *)pOVar1);
              if (local_1c != (BSTR)0x0) {
                FUN_68132710((uint *)&local_4c,0,0x10);
                VariantInit((VARIANTARG *)&local_4c.n2);
                local_8._0_1_ = 10;
                iVar3 = (**(code **)(*(int *)local_1c + 0x13c))(local_1c,&local_4c);
                if ((-1 < iVar3) && (local_4c.n2.vt == 9)) {
                  CComQIPtr<>(&local_20,(undefined4 *)local_4c._8_4_);
                  local_8._0_1_ = 0xb;
                  if (local_20 != (BSTR)0x0) {
                    (**(code **)(*(int *)local_20 + 0x3c))(local_20,local_3c._8_4_);
                  }
                  local_8._0_1_ = 10;
                  if (local_20 != (BSTR)0x0) {
                    (**(code **)(*(int *)local_20 + 8))(local_20);
                  }
                }
                VariantClear((VARIANTARG *)&local_4c.n2);
              }
              local_8._0_1_ = 8;
              if (local_1c != (BSTR)0x0) {
                (**(code **)(*(int *)local_1c + 8))(local_1c);
              }
            }
            VariantClear((VARIANTARG *)&local_3c.n2);
          }
          local_8._0_1_ = 6;
          if (param_2 != (int *)0x0) {
            (**(code **)(*param_2 + 8))(param_2);
          }
        }
        FUN_68132710((uint *)&local_5c,0,0x10);
        VariantInit((VARIANTARG *)&local_5c.n2);
        local_8._0_1_ = 0xc;
        iVar3 = (**(code **)(*(int *)pOVar1 + 0x13c))(pOVar1,&local_5c);
        if ((-1 < iVar3) && (local_5c.n2.vt == 9)) {
          CComQIPtr<>(&param_2,(undefined4 *)local_5c._8_4_);
          if (param_2 != (int *)0x0) {
            local_18 = (int *)0x0;
            local_8 = CONCAT31(local_8._1_3_,0xe);
            iVar3 = (**(code **)(*(int *)param_1 + 0x94))(param_1,PTR_u_ConnStr_6815fff8,&local_18);
            if ((iVar3 == 0) && (local_18 != (int *)0x0)) {
              local_1c = (BSTR)0x0;
              iVar3 = (**(code **)(*local_18 + 0x68))(local_18,&local_1c);
              if (-1 < iVar3) {
                (**(code **)(*param_2 + 0x44))(param_2,local_1c);
              }
              SysFreeString(local_1c);
            }
            local_8._0_1_ = 0xd;
            if (local_18 != (int *)0x0) {
              (**(code **)(*local_18 + 8))(local_18);
            }
            local_1c = (BSTR)0x0;
            local_8 = CONCAT31(local_8._1_3_,0xf);
            iVar3 = (**(code **)(*(int *)param_1 + 0x94))
                              (param_1,PTR_u_SourceSQL_6815fffc,&local_1c);
            if ((iVar3 == 0) && (local_1c != (BSTR)0x0)) {
              local_20 = (BSTR)0x0;
              iVar3 = (**(code **)(*(int *)local_1c + 0x68))(local_1c,&local_20);
              if (-1 < iVar3) {
                (**(code **)(*param_2 + 0x4c))(param_2,local_20);
              }
              SysFreeString(local_20);
            }
            local_8._0_1_ = 0xd;
            if (local_1c != (BSTR)0x0) {
              (**(code **)(*(int *)local_1c + 8))(local_1c);
            }
            local_14[0] = (int *)0x0;
            local_8 = CONCAT31(local_8._1_3_,0x10);
            iVar3 = (**(code **)(*(int *)param_1 + 0x90))(param_1,PTR_u_Item_6815fd84,local_14);
            if ((-1 < iVar3) && (local_14[0] != (int *)0x0)) {
              iVar3 = FUN_68123332(param_2,local_14);
            }
            local_8._0_1_ = 0xd;
            if (local_14[0] != (int *)0x0) {
              (**(code **)(*local_14[0] + 8))(local_14[0]);
            }
          }
          local_8._0_1_ = 0xc;
          if (param_2 != (int *)0x0) {
            (**(code **)(*param_2 + 8))(param_2);
          }
        }
        VariantClear((VARIANTARG *)&local_5c.n2);
        local_8 = CONCAT31(local_8._1_3_,5);
        if (local_28[0] != (int *)0x0) {
          (**(code **)(*local_28[0] + 8))(local_28[0]);
        }
      }
      local_8 = 0xffffffff;
      if (param_1 != (BSTR)0x0) {
        (**(code **)(*(int *)param_1 + 8))(param_1);
      }
      if (iVar3 == 1) {
        iVar3 = 0;
      }
    }
    else {
      iVar3 = -0x7ff8ffa9;
    }
  }
  return iVar3;
}


