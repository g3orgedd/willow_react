// Source: CiffMgr.dll @ 6811eef8; FUN_6811eef8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

ULONG FUN_6811eef8(int *param_1,IUnknown *param_2)

{
  int *piVar1;
  void *this;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  ULONG UVar5;
  int *piVar6;
  IUnknown *pIVar7;
  float10 fVar8;
  _union_2683 local_38;
  int *local_28;
  wchar_t *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  void *local_14;
  int local_8;
  undefined4 uStack_4;
  
  piVar6 = param_1;
  uStack_4 = 0x28;
  local_8 = 0x6811ef04;
  CComQIPtr<>(&local_28,(undefined4 *)*param_1);
  pIVar7 = param_2;
  local_20 = (int *)0x0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  iVar2 = (**(code **)(param_2->lpVtbl->QueryInterface + 0x44))(param_2->lpVtbl,&local_20);
  if ((-1 < iVar2) && (local_20 != (int *)0x0)) {
    local_1c = (int *)0x0;
    local_8._0_1_ = 2;
    iVar2 = (**(code **)(*local_20 + 0x1c))(local_20,PTR_u_DesignedFor_68160024,&local_1c);
    if ((iVar2 == 0) && (local_1c != (int *)0x0)) {
      FUN_68132710((uint *)&local_38,0,0x10);
      VariantInit((VARIANTARG *)&local_38.n2);
      local_8._0_1_ = 3;
      (**(code **)(*local_1c + 0x20))(local_1c,&local_38);
      if (local_38.n2.vt == 8) {
        (**(code **)(*(int *)*piVar6 + 0x48))((int *)*piVar6,local_38._8_4_);
      }
      VariantClear((VARIANTARG *)&local_38.n2);
    }
    local_8._0_1_ = 1;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))(local_1c);
    }
    local_1c = (int *)0x0;
    local_8._0_1_ = 4;
    iVar2 = (**(code **)(*local_20 + 0x1c))(local_20,PTR_u_DesignedWith_68160028,&local_1c);
    if ((iVar2 == 0) && (local_1c != (int *)0x0)) {
      FUN_68132710((uint *)&local_38,0,0x10);
      VariantInit((VARIANTARG *)&local_38.n2);
      local_8._0_1_ = 5;
      (**(code **)(*local_1c + 0x20))(local_1c,&local_38);
      if (local_38.n2.vt == 8) {
        (**(code **)(*(int *)*piVar6 + 0x50))((int *)*piVar6,local_38._8_4_);
      }
      VariantClear((VARIANTARG *)&local_38.n2);
    }
    local_8._0_1_ = 1;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))(local_1c);
    }
    local_1c = (int *)0x0;
    local_8._0_1_ = 6;
    iVar2 = (**(code **)(*local_20 + 0x1c))(local_20,PTR_u_OverrideAll_6816002c,&local_1c);
    if ((iVar2 == 0) && (local_1c != (int *)0x0)) {
      FUN_68132710((uint *)&local_38,0,0x10);
      VariantInit((VARIANTARG *)&local_38.n2);
      local_8._0_1_ = 7;
      (**(code **)(*local_1c + 0x20))(local_1c,&local_38);
      if (local_38.n2.vt == 8) {
        piVar6 = (int *)*piVar6;
        iVar2 = *piVar6;
        uVar3 = FUN_6812e988((wchar_t *)local_38._8_4_);
        (**(code **)(iVar2 + 0x6c))(piVar6,uVar3);
        piVar6 = param_1;
        pIVar7 = param_2;
      }
      VariantClear((VARIANTARG *)&local_38.n2);
    }
    local_8._0_1_ = 1;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))(local_1c);
    }
  }
  local_1c = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,8);
  iVar2 = (**(code **)(pIVar7->lpVtbl->QueryInterface + 0x94))
                    (pIVar7->lpVtbl,PTR_u_Units_6815fc4c,&local_1c);
  if ((iVar2 == 0) && (local_1c != (int *)0x0)) {
    local_24 = (wchar_t *)0x0;
    iVar2 = (**(code **)(*local_1c + 0x68))(local_1c,&local_24);
    if (-1 < iVar2) {
      piVar6 = (int *)*piVar6;
      iVar2 = *piVar6;
      uVar3 = FUN_6812faea(local_24);
      (**(code **)(iVar2 + 0x58))(piVar6,uVar3);
      pIVar7 = param_2;
    }
    SysFreeString(local_24);
  }
  local_8._0_1_ = 1;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  local_1c = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,9);
  iVar2 = (**(code **)(pIVar7->lpVtbl->QueryInterface + 0x94))
                    (pIVar7->lpVtbl,PTR_u_ErrorLeniency_6815fc50,&local_1c);
  if ((iVar2 == 0) && (local_1c != (int *)0x0)) {
    local_24 = (BSTR)0x0;
    iVar2 = (**(code **)(*local_1c + 0x68))(local_1c,&local_24);
    if (-1 < iVar2) {
      piVar6 = (int *)*param_1;
      iVar2 = *piVar6;
      iVar4 = FUN_6812f116((ushort *)local_24);
      (**(code **)(iVar2 + 0x74))(piVar6,iVar4);
      pIVar7 = param_2;
    }
    SysFreeString(local_24);
  }
  local_8._0_1_ = 1;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  local_1c = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,10);
  iVar2 = (**(code **)(pIVar7->lpVtbl->QueryInterface + 0x94))
                    (pIVar7->lpVtbl,PTR_u_ClStVersionInfo_6815fc54,&local_1c);
  if ((iVar2 == 0) && (local_1c != (int *)0x0)) {
    local_24 = (BSTR)0x0;
    iVar2 = (**(code **)(*local_1c + 0x68))(local_1c,&local_24);
    if (-1 < iVar2) {
      (**(code **)(*(int *)*param_1 + 0x7c))((int *)*param_1,local_24);
    }
    SysFreeString(local_24);
  }
  local_8._0_1_ = 1;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  local_1c = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,0xb);
  iVar2 = (**(code **)(pIVar7->lpVtbl->QueryInterface + 0x94))
                    (pIVar7->lpVtbl,PTR_u_LastDownloaded_6815fc58,&local_1c);
  if ((iVar2 == 0) && (local_1c != (int *)0x0)) {
    local_24 = (wchar_t *)0x0;
    iVar2 = (**(code **)(*local_1c + 0x68))(local_1c);
    if (-1 < iVar2) {
      piVar6 = (int *)*param_1;
      iVar2 = *piVar6;
      fVar8 = (float10)FUN_6812ee95(local_24);
      (**(code **)(iVar2 + 0x94))(piVar6,(double)fVar8);
      pIVar7 = param_2;
    }
    SysFreeString(local_24);
  }
  local_8._0_1_ = 1;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))();
  }
  local_1c = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,0xc);
  iVar2 = (**(code **)(pIVar7->lpVtbl->QueryInterface + 0x94))
                    (pIVar7->lpVtbl,PTR_u_LineID_6815ff44,&local_1c);
  if ((iVar2 == 0) && (local_1c != (int *)0x0)) {
    local_24 = (BSTR)0x0;
    iVar2 = (**(code **)(*local_1c + 0x68))(local_1c,&local_24);
    if (-1 < iVar2) {
      piVar6 = (int *)*param_1;
      iVar2 = *piVar6;
      iVar4 = FUN_6812f116((ushort *)local_24);
      (**(code **)(iVar2 + 0xc4))(piVar6,iVar4);
      pIVar7 = param_2;
    }
    SysFreeString(local_24);
  }
  local_8._0_1_ = 1;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  param_2 = (IUnknown *)0x0;
  local_8 = CONCAT31(local_8._1_3_,0xd);
  iVar2 = (**(code **)(pIVar7->lpVtbl->QueryInterface + 0x94))
                    (pIVar7->lpVtbl,PTR_u_DeveloperLicense_6815fc5c,&param_2);
  if ((iVar2 == 0) && (param_2 != (IUnknown *)0x0)) {
    local_24 = (BSTR)0x0;
    UVar5 = (*param_2->lpVtbl[8].Release)(param_2);
    if (-1 < (int)UVar5) {
      (**(code **)(*(int *)*param_1 + 0xa8))((int *)*param_1,local_24);
    }
    SysFreeString(local_24);
  }
  local_8._0_1_ = 1;
  if (param_2 != (IUnknown *)0x0) {
    (*param_2->lpVtbl->Release)(param_2);
  }
  piVar6 = param_1;
  iVar2 = (**(code **)(*(int *)*param_1 + 0x88))((int *)*param_1,&param_1);
  this = local_14;
  if ((-1 < iVar2) && (param_1 == (int *)0x1)) {
    *(undefined4 *)((int)local_14 + 4) = 1;
  }
  param_1 = (int *)0x0;
  local_8._0_1_ = 0xe;
  iVar2 = (**(code **)(pIVar7->lpVtbl->QueryInterface + 0x90))
                    (pIVar7->lpVtbl,PTR_u_DateOffset_6815fc60,&param_1);
  if ((-1 < iVar2) && (param_1 != (int *)0x0)) {
    FUN_68132710((uint *)&local_38,0,0x10);
    VariantInit((VARIANTARG *)&local_38.n2);
    piVar1 = (int *)*piVar6;
    local_8._0_1_ = 0xf;
    iVar2 = (**(code **)(*piVar1 + 100))(piVar1,&local_38);
    if (-1 < iVar2) {
      CComQIPtr<>(&param_2,(undefined4 *)local_38._8_4_);
      local_8._0_1_ = 0x10;
      FUN_6811d134(this,(int *)param_2,&param_1);
      local_8._0_1_ = 0xf;
      if (param_2 != (IUnknown *)0x0) {
        (*param_2->lpVtbl->Release)(param_2);
      }
    }
    VariantClear((VARIANTARG *)&local_38.n2);
  }
  local_8._0_1_ = 1;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  local_18 = (int *)0x0;
  local_8._0_1_ = 0x11;
  UVar5 = (**(code **)(pIVar7->lpVtbl->QueryInterface + 0x90))
                    (pIVar7->lpVtbl,PTR_u_Price_6815fec4,&local_18);
  if (-1 < (int)UVar5) {
    if (local_18 != (int *)0x0) {
      FUN_68132710((uint *)&local_38,0,0x10);
      VariantInit((VARIANTARG *)&local_38.n2);
      piVar6 = (int *)*piVar6;
      local_8._0_1_ = 0x12;
      UVar5 = (**(code **)(*piVar6 + 0xb4))(piVar6,&local_38);
      if (-1 < (int)UVar5) {
        CComQIPtr<>(&param_1,(undefined4 *)local_38._8_4_);
        local_8._0_1_ = 0x13;
        UVar5 = FUN_681208e1(local_14,param_1,&local_18);
        local_8._0_1_ = 0x12;
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
        }
      }
      VariantClear((VARIANTARG *)&local_38.n2);
    }
    if (-1 < (int)UVar5) {
      param_1 = (int *)0x0;
      local_8._0_1_ = 0x14;
      UVar5 = (**(code **)(pIVar7->lpVtbl->QueryInterface + 0x90))
                        (pIVar7->lpVtbl,PTR_u_DataSource_6815fec0,&param_1);
      if ((-1 < (int)UVar5) && (param_1 != (int *)0x0)) {
        FUN_68132710((uint *)&local_38,0,0x10);
        VariantInit((VARIANTARG *)&local_38.n2);
        local_8._0_1_ = 0x15;
        (**(code **)(*local_28 + 0xcc))(local_28,&local_38);
        if ((local_38.n2.vt == 9) && ((wchar_t *)local_38._8_4_ != (wchar_t *)0x0)) {
          CComQIPtr<>(&param_2,(undefined4 *)local_38._8_4_);
          local_8._0_1_ = 0x16;
          UVar5 = FUN_6811c830(param_2,&param_1);
          local_8._0_1_ = 0x15;
          if (param_2 != (IUnknown *)0x0) {
            (*param_2->lpVtbl->Release)(param_2);
          }
        }
        VariantClear((VARIANTARG *)&local_38.n2);
      }
      local_8._0_1_ = 0x11;
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))(param_1);
      }
    }
  }
  local_8._0_1_ = 1;
  if (UVar5 == 1) {
    UVar5 = 0;
  }
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  local_8 = 0xffffffff;
  if (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 8))(local_28);
  }
  return UVar5;
}


