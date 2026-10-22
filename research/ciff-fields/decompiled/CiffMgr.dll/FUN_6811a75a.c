// Source: CiffMgr.dll @ 6811a75a; FUN_6811a75a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_6811a75a(BSTR param_1,int *param_2)

{
  BSTR pOVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  float10 fVar8;
  _union_2683 local_58;
  int *local_48;
  int *local_44;
  int *local_40;
  int *local_3c;
  int *local_38;
  wchar_t *local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18 [4];
  int local_8;
  undefined4 uStack_4;
  
  piVar7 = param_2;
  uStack_4 = 0x48;
  local_44 = (int *)0x0;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  iVar3 = (**(code **)(*(int *)*param_2 + 0x44))((int *)*param_2,&local_44);
  pOVar1 = param_1;
  CComQIPtr<>(&local_2c,*(undefined4 **)param_1);
  CComQIPtr<>(local_18,*(undefined4 **)pOVar1);
  CComQIPtr<>(&local_28,*(undefined4 **)pOVar1);
  CComQIPtr<>(&local_1c,*(undefined4 **)pOVar1);
  CComQIPtr<>(&local_40,*(undefined4 **)pOVar1);
  CComQIPtr<>(&local_24,*(undefined4 **)pOVar1);
  CComQIPtr<>(&local_30,*(undefined4 **)pOVar1);
  CComQIPtr<>(&local_3c,*(undefined4 **)pOVar1);
  CComQIPtr<>(&local_48,*(undefined4 **)pOVar1);
  if ((-1 < iVar3) && (local_44 != (int *)0x0)) {
    local_20 = (int *)0x0;
    local_8._0_1_ = 10;
    iVar3 = (**(code **)(*local_44 + 0x1c))(local_44,PTR_u_ParentField_68160088,&local_20);
    if ((iVar3 == 0) && (local_20 != (int *)0x0)) {
      FUN_68132710((uint *)&local_58,0,0x10);
      VariantInit((VARIANTARG *)&local_58.n2);
      local_8._0_1_ = 0xb;
      (**(code **)(*local_20 + 0x20))(local_20,&local_58);
      if (local_58.n2.vt == 8) {
        (**(code **)(**(int **)pOVar1 + 0xfc))(*(int **)pOVar1,local_58._8_4_);
      }
      VariantClear((VARIANTARG *)&local_58.n2);
    }
    local_8._0_1_ = 9;
    if (local_20 != (int *)0x0) {
      (**(code **)(*local_20 + 8))(local_20);
    }
  }
  local_20 = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,0xc);
  iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))((int *)*piVar7,PTR_u_GuardBars_6815fe5c,&local_20);
  if ((iVar3 == 0) && (local_20 != (int *)0x0)) {
    local_34 = (wchar_t *)0x0;
    iVar3 = (**(code **)(*local_20 + 0x68))(local_20,&local_34);
    if (-1 < iVar3) {
      piVar7 = *(int **)param_1;
      iVar3 = *piVar7;
      uVar4 = FUN_6812e988(local_34);
      (**(code **)(iVar3 + 0x114))(piVar7,uVar4);
      piVar7 = param_2;
    }
    SysFreeString(local_34);
  }
  local_8._0_1_ = 9;
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  local_20 = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,0xd);
  iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))((int *)*piVar7,PTR_u_BearerBars_6815fe60,&local_20);
  if ((iVar3 == 0) && (local_20 != (int *)0x0)) {
    local_34 = (wchar_t *)0x0;
    iVar3 = (**(code **)(*local_20 + 0x68))(local_20,&local_34);
    if (-1 < iVar3) {
      piVar7 = *(int **)param_1;
      iVar3 = *piVar7;
      uVar4 = FUN_6812e988(local_34);
      (**(code **)(iVar3 + 0x11c))(piVar7,uVar4);
      piVar7 = param_2;
    }
    SysFreeString(local_34);
  }
  local_8._0_1_ = 9;
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  local_20 = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,0xe);
  iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))((int *)*piVar7,PTR_u_BearerBox_6815fe64,&local_20);
  if ((iVar3 == 0) && (local_20 != (int *)0x0)) {
    local_34 = (wchar_t *)0x0;
    iVar3 = (**(code **)(*local_20 + 0x68))(local_20,&local_34);
    if (-1 < iVar3) {
      piVar7 = *(int **)param_1;
      iVar3 = *piVar7;
      uVar4 = FUN_6812e988(local_34);
      (**(code **)(iVar3 + 0x124))(piVar7,uVar4);
      piVar7 = param_2;
    }
    SysFreeString(local_34);
  }
  local_8._0_1_ = 9;
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  local_20 = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,0xf);
  iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))((int *)*piVar7,PTR_u_HGauge_6815fe68,&local_20);
  if ((iVar3 == 0) && (local_20 != (int *)0x0)) {
    local_34 = (wchar_t *)0x0;
    iVar3 = (**(code **)(*local_20 + 0x68))(local_20,&local_34);
    if (-1 < iVar3) {
      piVar7 = *(int **)param_1;
      iVar3 = *piVar7;
      uVar4 = FUN_6812e988(local_34);
      (**(code **)(iVar3 + 300))(piVar7,uVar4);
      piVar7 = param_2;
    }
    SysFreeString(local_34);
  }
  local_8._0_1_ = 9;
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  local_20 = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,0x10);
  iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))
                    ((int *)*piVar7,PTR_u_ThickThinRatio_6815fe6c,&local_20);
  if ((iVar3 == 0) && (local_20 != (int *)0x0)) {
    local_34 = (BSTR)0x0;
    iVar3 = (**(code **)(*local_20 + 0x68))(local_20,&local_34);
    if (-1 < iVar3) {
      piVar7 = *(int **)param_1;
      iVar3 = *piVar7;
      iVar5 = FUN_6812f116((ushort *)local_34);
      (**(code **)(iVar3 + 0xf4))(piVar7,iVar5);
      piVar7 = param_2;
    }
    SysFreeString(local_34);
  }
  local_8._0_1_ = 9;
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  local_20 = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,0x11);
  iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))
                    ((int *)*piVar7,PTR_u_IntelligentEan128_6815fe70,&local_20);
  if ((iVar3 == 0) && (local_20 != (int *)0x0)) {
    local_34 = (wchar_t *)0x0;
    iVar3 = (**(code **)(*local_20 + 0x68))(local_20,&local_34);
    if (-1 < iVar3) {
      piVar7 = *(int **)param_1;
      iVar3 = *piVar7;
      uVar4 = FUN_6812e988(local_34);
      iVar3 = (**(code **)(iVar3 + 0x134))(piVar7,uVar4);
      piVar7 = param_2;
    }
    SysFreeString(local_34);
  }
  local_8._0_1_ = 9;
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  if (local_2c != (int *)0x0) {
    param_1 = (BSTR)0x0;
    local_8 = CONCAT31(local_8._1_3_,0x12);
    iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))((int *)*piVar7,PTR_u_ECCType_6815ff0c,&param_1);
    if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
      local_34 = (BSTR)0x0;
      iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_34);
      piVar2 = local_2c;
      if (-1 < iVar3) {
        iVar3 = *local_2c;
        iVar5 = FUN_6812f116((ushort *)local_34);
        (**(code **)(iVar3 + 0x158))(piVar2,iVar5);
        piVar7 = param_2;
      }
      SysFreeString(local_34);
    }
    local_8._0_1_ = 9;
    if (param_1 != (BSTR)0x0) {
      (**(code **)(*(int *)param_1 + 8))(param_1);
    }
    param_1 = (BSTR)0x0;
    local_8 = CONCAT31(local_8._1_3_,0x13);
    iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))((int *)*piVar7,PTR_u_ModuleSize_6815ff10,&param_1)
    ;
    if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
      local_34 = (BSTR)0x0;
      iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_34);
      piVar2 = local_2c;
      if (-1 < iVar3) {
        iVar3 = *local_2c;
        iVar5 = FUN_6812f116((ushort *)local_34);
        (**(code **)(iVar3 + 0x160))(piVar2,iVar5);
        piVar7 = param_2;
      }
      SysFreeString(local_34);
    }
    local_8._0_1_ = 9;
    if (param_1 != (BSTR)0x0) {
      (**(code **)(*(int *)param_1 + 8))(param_1);
    }
    param_1 = (BSTR)0x0;
    local_8 = CONCAT31(local_8._1_3_,0x14);
    iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))((int *)*piVar7,PTR_u_SymbolSize_6815ff14,&param_1)
    ;
    if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
      local_34 = (wchar_t *)0x0;
      iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_34);
      piVar2 = local_2c;
      if (-1 < iVar3) {
        iVar3 = *local_2c;
        uVar6 = FUN_6812f9cf(local_34);
        iVar3 = (**(code **)(iVar3 + 0x168))(piVar2,uVar6);
        piVar7 = param_2;
      }
      SysFreeString(local_34);
    }
    local_8._0_1_ = 9;
    if (param_1 != (BSTR)0x0) {
      (**(code **)(*(int *)param_1 + 8))(param_1);
    }
    if (local_18[0] != (int *)0x0) {
      param_1 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,0x15);
      iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))
                        ((int *)*piVar7,PTR_u_RowHeight_6815ff20,&param_1);
      if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
        local_34 = (BSTR)0x0;
        iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_34);
        piVar2 = local_18[0];
        if (-1 < iVar3) {
          iVar3 = *local_18[0];
          iVar5 = FUN_6812f116((ushort *)local_34);
          (**(code **)(iVar3 + 0x170))(piVar2,iVar5);
          piVar7 = param_2;
        }
        SysFreeString(local_34);
      }
      local_8._0_1_ = 9;
      if (param_1 != (BSTR)0x0) {
        (**(code **)(*(int *)param_1 + 8))(param_1);
      }
      param_1 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,0x16);
      iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))((int *)*piVar7,PTR_u_Columns_6815ff24,&param_1);
      if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
        local_34 = (BSTR)0x0;
        iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_34);
        piVar2 = local_18[0];
        if (-1 < iVar3) {
          iVar3 = *local_18[0];
          iVar5 = FUN_6812f116((ushort *)local_34);
          (**(code **)(iVar3 + 0x178))(piVar2,iVar5);
          piVar7 = param_2;
        }
        SysFreeString(local_34);
      }
      local_8._0_1_ = 9;
      if (param_1 != (BSTR)0x0) {
        (**(code **)(*(int *)param_1 + 8))(param_1);
      }
      param_1 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,0x17);
      iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))((int *)*piVar7,PTR_u_Rows_6815ff28,&param_1);
      if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
        local_34 = (BSTR)0x0;
        iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_34);
        piVar2 = local_18[0];
        if (-1 < iVar3) {
          iVar3 = *local_18[0];
          iVar5 = FUN_6812f116((ushort *)local_34);
          (**(code **)(iVar3 + 0x180))(piVar2,iVar5);
          piVar7 = param_2;
        }
        SysFreeString(local_34);
      }
      local_8._0_1_ = 9;
      if (param_1 != (BSTR)0x0) {
        (**(code **)(*(int *)param_1 + 8))(param_1);
      }
      local_38 = (int *)0x0;
      local_8._0_1_ = 0x18;
      iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))((int *)*piVar7,PTR_u_Rows_6815ff28,&local_38);
      if ((iVar3 == 0) && (local_38 != (int *)0x0)) {
        local_20 = (int *)0x0;
        local_8._0_1_ = 0x19;
        iVar3 = (**(code **)(*local_38 + 0x44))(local_38,&local_20);
        if ((-1 < iVar3) && (local_20 != (int *)0x0)) {
          param_1 = (BSTR)0x0;
          local_8._0_1_ = 0x1a;
          iVar3 = (**(code **)(*local_20 + 0x1c))(local_20,PTR_DAT_681600f0,&param_1);
          if ((-1 < iVar3) && (param_1 != (BSTR)0x0)) {
            FUN_68132710((uint *)&local_58,0,0x10);
            VariantInit((VARIANTARG *)&local_58.n2);
            local_8._0_1_ = 0x1b;
            (**(code **)(*(int *)param_1 + 0x20))(param_1,&local_58);
            piVar2 = local_48;
            if ((local_58.n2.vt == 8) && (local_48 != (int *)0x0)) {
              iVar3 = *local_48;
              uVar4 = FUN_6812e988((wchar_t *)local_58._8_4_);
              (**(code **)(iVar3 + 0x238))(piVar2,uVar4);
              piVar7 = param_2;
            }
            VariantClear((VARIANTARG *)&local_58.n2);
          }
          local_8._0_1_ = 0x19;
          if (param_1 != (BSTR)0x0) {
            (**(code **)(*(int *)param_1 + 8))(param_1);
          }
        }
        local_8._0_1_ = 0x18;
        if (local_20 != (int *)0x0) {
          (**(code **)(*local_20 + 8))(local_20);
        }
      }
      param_1 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,0x1c);
      iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))
                        ((int *)*piVar7,PTR_u_ErrorCorrection_6815ff2c,&param_1);
      if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
        local_34 = (wchar_t *)0x0;
        iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_34);
        piVar2 = local_18[0];
        if (-1 < iVar3) {
          iVar3 = *local_18[0];
          uVar4 = FUN_6812ed3b(local_34);
          (**(code **)(iVar3 + 0x188))(piVar2,uVar4);
          piVar7 = param_2;
        }
        SysFreeString(local_34);
      }
      local_8._0_1_ = 0x18;
      if (param_1 != (BSTR)0x0) {
        (**(code **)(*(int *)param_1 + 8))(param_1);
      }
      param_1 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,0x1d);
      iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))((int *)*piVar7,PTR_u_Type_6815ff30,&param_1);
      if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
        local_34 = (wchar_t *)0x0;
        iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_34);
        piVar2 = local_18[0];
        if (-1 < iVar3) {
          iVar3 = *local_18[0];
          uVar4 = FUN_6812f3c9(local_34);
          (**(code **)(iVar3 + 400))(piVar2,uVar4);
          piVar7 = param_2;
        }
        SysFreeString(local_34);
      }
      local_8._0_1_ = 0x18;
      if (param_1 != (BSTR)0x0) {
        (**(code **)(*(int *)param_1 + 8))(param_1);
      }
      param_1 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,0x1e);
      iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))((int *)*piVar7,PTR_u_Encoding_6815ff34,&param_1)
      ;
      if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
        local_34 = (wchar_t *)0x0;
        iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_34);
        piVar2 = local_18[0];
        if (-1 < iVar3) {
          iVar3 = *local_18[0];
          uVar4 = FUN_6812f355(local_34);
          (**(code **)(iVar3 + 0x198))(piVar2,uVar4);
          piVar7 = param_2;
        }
        SysFreeString(local_34);
      }
      local_8._0_1_ = 0x18;
      if (param_1 != (BSTR)0x0) {
        (**(code **)(*(int *)param_1 + 8))(param_1);
      }
      param_1 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,0x1f);
      iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))((int *)*piVar7,PTR_u_HRStyle_6815ff40,&param_1);
      if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
        local_34 = (wchar_t *)0x0;
        iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_34);
        piVar2 = local_18[0];
        if (-1 < iVar3) {
          iVar3 = *local_18[0];
          uVar4 = FUN_6812f0a2(local_34);
          iVar3 = (**(code **)(iVar3 + 0x1a0))(piVar2,uVar4);
          piVar7 = param_2;
        }
        SysFreeString(local_34);
      }
      local_8._0_1_ = 0x18;
      if (param_1 != (BSTR)0x0) {
        (**(code **)(*(int *)param_1 + 8))(param_1);
      }
      if (local_28 != (int *)0x0) {
        param_1 = (BSTR)0x0;
        local_8 = CONCAT31(local_8._1_3_,0x20);
        iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))
                          ((int *)*piVar7,PTR_u_QRVersion_6815ff64,&param_1);
        if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
          local_34 = (wchar_t *)0x0;
          iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_34);
          piVar2 = local_28;
          if (-1 < iVar3) {
            iVar3 = *local_28;
            uVar4 = FUN_6812f675(local_34);
            (**(code **)(iVar3 + 0x1b0))(piVar2,uVar4);
            piVar7 = param_2;
          }
          SysFreeString(local_34);
        }
        local_8._0_1_ = 0x18;
        if (param_1 != (BSTR)0x0) {
          (**(code **)(*(int *)param_1 + 8))(param_1);
        }
        param_1 = (BSTR)0x0;
        local_8 = CONCAT31(local_8._1_3_,0x21);
        iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))
                          ((int *)*piVar7,PTR_u_QRErrorLevel_6815ff68,&param_1);
        if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
          local_34 = (wchar_t *)0x0;
          iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_34);
          piVar2 = local_28;
          if (-1 < iVar3) {
            iVar3 = *local_28;
            uVar4 = FUN_6812f601(local_34);
            (**(code **)(iVar3 + 0x1b8))(piVar2,uVar4);
            piVar7 = param_2;
          }
          SysFreeString(local_34);
        }
        local_8._0_1_ = 0x18;
        if (param_1 != (BSTR)0x0) {
          (**(code **)(*(int *)param_1 + 8))(param_1);
        }
        param_1 = (BSTR)0x0;
        local_8 = CONCAT31(local_8._1_3_,0x22);
        iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))
                          ((int *)*piVar7,PTR_u_QRMirror_6815ff6c,&param_1);
        if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
          local_34 = (wchar_t *)0x0;
          iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_34);
          piVar2 = local_28;
          if (-1 < iVar3) {
            iVar3 = *local_28;
            uVar4 = FUN_6812e988(local_34);
            iVar3 = (**(code **)(iVar3 + 0x1c0))(piVar2,uVar4);
            piVar7 = param_2;
          }
          SysFreeString(local_34);
        }
        local_8._0_1_ = 0x18;
        if (param_1 != (BSTR)0x0) {
          (**(code **)(*(int *)param_1 + 8))(param_1);
        }
        if (local_1c != (int *)0x0) {
          param_1 = (BSTR)0x0;
          local_8 = CONCAT31(local_8._1_3_,0x23);
          iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))
                            ((int *)*piVar7,PTR_u_BearerSize_6815ff88,&param_1);
          if (((iVar3 == 0) && (param_1 != (BSTR)0x0)) &&
             (iVar3 = (**(code **)(*local_1c + 0x1c8))(local_1c,1), -1 < iVar3)) {
            local_34 = (BSTR)0x0;
            iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_34);
            piVar2 = local_1c;
            if (-1 < iVar3) {
              iVar3 = *local_1c;
              iVar5 = FUN_6812f116((ushort *)local_34);
              (**(code **)(iVar3 + 0x1d0))(piVar2,iVar5);
              piVar7 = param_2;
            }
            SysFreeString(local_34);
          }
          local_8._0_1_ = 0x18;
          if (param_1 != (BSTR)0x0) {
            (**(code **)(*(int *)param_1 + 8))(param_1);
          }
          param_1 = (BSTR)0x0;
          local_8 = CONCAT31(local_8._1_3_,0x24);
          iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))
                            ((int *)*piVar7,PTR_u_QMSize_6815ff8c,&param_1);
          if (((iVar3 == 0) && (param_1 != (BSTR)0x0)) &&
             (iVar3 = (**(code **)(*local_1c + 0x1d8))(local_1c,1), -1 < iVar3)) {
            local_34 = (wchar_t *)0x0;
            iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_34);
            piVar2 = local_1c;
            if (-1 < iVar3) {
              iVar3 = *local_1c;
              fVar8 = (float10)FUN_6812ee95(local_34);
              local_20 = (int *)(float)fVar8;
              iVar3 = (**(code **)(iVar3 + 0x1e0))(piVar2,local_20);
              piVar7 = param_2;
            }
            SysFreeString(local_34);
          }
          local_8._0_1_ = 0x18;
          if (param_1 != (BSTR)0x0) {
            (**(code **)(*(int *)param_1 + 8))(param_1);
          }
          if (local_40 != (int *)0x0) {
            param_1 = (BSTR)0x0;
            local_8 = CONCAT31(local_8._1_3_,0x25);
            iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))
                              ((int *)*piVar7,PTR_u_LegacyC128Enc_6815ffa8,&param_1);
            if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
              local_34 = (wchar_t *)0x0;
              iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_34);
              piVar2 = local_40;
              if (-1 < iVar3) {
                iVar3 = *local_40;
                uVar4 = FUN_6812e988(local_34);
                iVar3 = (**(code **)(iVar3 + 0x1e8))(piVar2,uVar4);
                piVar7 = param_2;
              }
              SysFreeString(local_34);
            }
            local_8._0_1_ = 0x18;
            if (param_1 != (BSTR)0x0) {
              (**(code **)(*(int *)param_1 + 8))(param_1);
            }
            if (local_24 != (int *)0x0) {
              param_1 = (BSTR)0x0;
              local_8 = CONCAT31(local_8._1_3_,0x26);
              iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))
                                ((int *)*piVar7,PTR_u_Mode_6815ffb4,&param_1);
              if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
                local_34 = (BSTR)0x0;
                iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_34);
                piVar2 = local_24;
                if (-1 < iVar3) {
                  iVar3 = *local_24;
                  iVar5 = FUN_6812f116((ushort *)local_34);
                  (**(code **)(iVar3 + 0x1f8))(piVar2,iVar5);
                  piVar7 = param_2;
                }
                SysFreeString(local_34);
              }
              local_8._0_1_ = 0x18;
              if (param_1 != (BSTR)0x0) {
                (**(code **)(*(int *)param_1 + 8))(param_1);
              }
              param_1 = (BSTR)0x0;
              local_8 = CONCAT31(local_8._1_3_,0x27);
              iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))
                                ((int *)*piVar7,PTR_u_Symbol_6815ffb8,&param_1);
              if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
                local_34 = (BSTR)0x0;
                iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_34);
                piVar2 = local_24;
                if (-1 < iVar3) {
                  iVar3 = *local_24;
                  iVar5 = FUN_6812f116((ushort *)local_34);
                  (**(code **)(iVar3 + 0x200))(piVar2,iVar5);
                  piVar7 = param_2;
                }
                SysFreeString(local_34);
              }
              local_8._0_1_ = 0x18;
              if (param_1 != (BSTR)0x0) {
                (**(code **)(*(int *)param_1 + 8))(param_1);
              }
              param_1 = (BSTR)0x0;
              local_8 = CONCAT31(local_8._1_3_,0x28);
              iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))
                                ((int *)*piVar7,PTR_u_SymbolCount_6815ffbc,&param_1);
              if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
                local_34 = (BSTR)0x0;
                iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_34);
                piVar2 = local_24;
                if (-1 < iVar3) {
                  iVar3 = *local_24;
                  iVar5 = FUN_6812f116((ushort *)local_34);
                  iVar3 = (**(code **)(iVar3 + 0x208))(piVar2,iVar5);
                  piVar7 = param_2;
                }
                SysFreeString(local_34);
              }
              local_8._0_1_ = 0x18;
              if (param_1 != (BSTR)0x0) {
                (**(code **)(*(int *)param_1 + 8))(param_1);
              }
              if (local_30 != (int *)0x0) {
                param_1 = (BSTR)0x0;
                local_8 = CONCAT31(local_8._1_3_,0x29);
                iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))
                                  ((int *)*piVar7,PTR_u_ManualCode128Encoding_6815ffdc,&param_1);
                if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
                  local_34 = (wchar_t *)0x0;
                  iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_34);
                  piVar2 = local_30;
                  if (-1 < iVar3) {
                    iVar3 = *local_30;
                    uVar4 = FUN_6812e988(local_34);
                    (**(code **)(iVar3 + 0x220))(piVar2,uVar4);
                    piVar7 = param_2;
                  }
                  SysFreeString(local_34);
                }
                local_8._0_1_ = 0x18;
                if (param_1 != (BSTR)0x0) {
                  (**(code **)(*(int *)param_1 + 8))(param_1);
                }
                param_1 = (BSTR)0x0;
                local_8 = CONCAT31(local_8._1_3_,0x2a);
                iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))
                                  ((int *)*piVar7,PTR_u_CorrectCheckDigit_6815ffe0,&param_1);
                if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
                  local_34 = (wchar_t *)0x0;
                  iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_34);
                  piVar2 = local_30;
                  if (-1 < iVar3) {
                    iVar3 = *local_30;
                    uVar4 = FUN_6812e988(local_34);
                    iVar3 = (**(code **)(iVar3 + 0x228))(piVar2,uVar4);
                    piVar7 = param_2;
                  }
                  SysFreeString(local_34);
                }
                local_8._0_1_ = 0x18;
                if (param_1 != (BSTR)0x0) {
                  (**(code **)(*(int *)param_1 + 8))(param_1);
                }
                if (local_3c != (int *)0x0) {
                  param_2 = (int *)0x0;
                  local_8 = CONCAT31(local_8._1_3_,0x2b);
                  iVar3 = (**(code **)(*(int *)*piVar7 + 0x94))
                                    ((int *)*piVar7,PTR_u_BarcodeDataFormat_6815ffe8,&param_2);
                  if ((iVar3 == 0) && (param_2 != (int *)0x0)) {
                    param_1 = (BSTR)0x0;
                    iVar3 = (**(code **)(*param_2 + 0x68))(param_2,&param_1);
                    piVar7 = local_3c;
                    if (-1 < iVar3) {
                      iVar3 = *local_3c;
                      uVar4 = FUN_6812e860(param_1);
                      iVar3 = (**(code **)(iVar3 + 0x230))(piVar7,uVar4);
                    }
                    SysFreeString(param_1);
                  }
                  local_8._0_1_ = 0x18;
                  if (param_2 != (int *)0x0) {
                    (**(code **)(*param_2 + 8))(param_2);
                  }
                }
              }
            }
          }
        }
      }
      local_8._0_1_ = 9;
      if (local_38 != (int *)0x0) {
        (**(code **)(*local_38 + 8))(local_38);
      }
    }
  }
  if (iVar3 == 1) {
    iVar3 = 0;
  }
  local_8._0_1_ = 8;
  if (local_48 != (int *)0x0) {
    (**(code **)(*local_48 + 8))(local_48);
  }
  local_8._0_1_ = 7;
  if (local_3c != (int *)0x0) {
    (**(code **)(*local_3c + 8))(local_3c);
  }
  local_8._0_1_ = 6;
  if (local_30 != (int *)0x0) {
    (**(code **)(*local_30 + 8))(local_30);
  }
  local_8._0_1_ = 5;
  if (local_24 != (int *)0x0) {
    (**(code **)(*local_24 + 8))(local_24);
  }
  local_8._0_1_ = 4;
  if (local_40 != (int *)0x0) {
    (**(code **)(*local_40 + 8))(local_40);
  }
  local_8._0_1_ = 3;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  local_8._0_1_ = 2;
  if (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 8))(local_28);
  }
  local_8._0_1_ = 1;
  if (local_18[0] != (int *)0x0) {
    (**(code **)(*local_18[0] + 8))(local_18[0]);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_2c != (int *)0x0) {
    (**(code **)(*local_2c + 8))(local_2c);
  }
  local_8 = 0xffffffff;
  if (local_44 != (int *)0x0) {
    (**(code **)(*local_44 + 8))(local_44);
  }
  return iVar3;
}


