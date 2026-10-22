// Source: CLCSGraphicBasedField.dll @ 41c0a9f8; FUN_41c0a9f8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_41c0a9f8(int *param_1,IUnknown *param_2,undefined4 param_3,int *param_4,undefined1 *param_5
                 ,int param_6)

{
  bool bVar1;
  undefined1 uVar2;
  int iVar3;
  HRESULT HVar4;
  ULONG UVar5;
  int *piVar6;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint extraout_ECX_01;
  uint uVar7;
  int *piVar8;
  bool bVar9;
  undefined1 *puVar10;
  void **ppvObject;
  BSTR *ppOVar11;
  _union_2683 *p_Var12;
  IID *riid;
  IID *pIVar13;
  IUnknownVtbl *ppvObject_00;
  _union_2683 local_5c;
  _union_2683 local_4c;
  int local_38;
  int *local_34;
  void *local_30;
  IID *local_2c;
  int local_28;
  uint local_24;
  undefined1 local_20 [8];
  BSTR local_18;
  IUnknown *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4c;
  bVar9 = false;
  local_14[0] = (IUnknown *)0x0;
  local_2c = (IID *)0x0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  ppvObject_00 = param_2->lpVtbl;
  iVar3 = (**(code **)(ppvObject_00->QueryInterface + 0x4c))(ppvObject_00,&local_2c);
  piVar8 = param_1;
  if (-1 < iVar3) {
    FUN_41c18d70((uint *)&local_5c,0,0x10);
    VariantInit((VARIANTARG *)&local_5c.n2);
    local_8._0_1_ = 2;
    iVar3 = (**(code **)(*(int *)*piVar8 + 0x470))((int *)*piVar8,&local_5c);
    if ((-1 < iVar3) && (local_5c.n2.vt == 9)) {
      CComQIPtr<>(&param_2,(undefined4 *)local_5c._8_4_);
      if (param_2 != (IUnknown *)0x0) {
        FUN_41c18d70((uint *)&local_4c,0,0x10);
        VariantInit((VARIANTARG *)&local_4c.n2);
        local_8._0_1_ = 4;
        HVar4 = (*param_2->lpVtbl[4].QueryInterface)(param_2,local_2c,(void **)&local_4c);
        if (((-1 < HVar4) && (local_4c.n2.vt == 9)) && (local_14[0] != (IUnknown *)local_4c._8_4_))
        {
          ATL::AtlComQIPtrAssign(local_14,(IUnknown *)local_4c._8_4_,(_GUID *)&DAT_41c3174c);
        }
        VariantClear((VARIANTARG *)&local_4c.n2);
      }
      local_8._0_1_ = 2;
      if (param_2 != (IUnknown *)0x0) {
        (*param_2->lpVtbl->Release)(param_2);
      }
    }
    VariantClear((VARIANTARG *)&local_5c.n2);
  }
  if (local_14[0] == (IUnknown *)0x0) goto LAB_41c0adba;
  local_18 = (BSTR)0x0;
  ppOVar11 = &local_18;
  local_8._0_1_ = 5;
  (*local_14[0]->lpVtbl[5].Release)(local_14[0]);
  ppvObject = &local_30;
  (*local_14[0]->lpVtbl[6].AddRef)(local_14[0]);
  bVar1 = FUN_41c01781(&local_18,L"Line");
  if ((!bVar1) || (uVar2 = 1, local_30 != (void *)0x1)) {
    uVar2 = 0;
  }
  *param_5 = uVar2;
  bVar1 = FUN_41c01781(&local_18,L"Line");
  if ((bVar1) || (local_30 == (void *)0x1)) {
    FUN_41c11a03(&local_38);
    piVar6 = (int *)*piVar8;
    local_8._0_1_ = 6;
    local_28 = 0;
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 0x2fc))(piVar6,&local_28);
    }
    param_2 = (IUnknown *)0x0;
    local_20._0_4_ = 0;
    FUN_41c18d70((uint *)&local_4c,0,0x10);
    VariantInit((VARIANTARG *)&local_4c.n2);
    local_8._0_1_ = 8;
    UVar5 = (*local_14[0]->lpVtbl[10].AddRef)(local_14[0]);
    uVar7 = extraout_ECX;
    if ((-1 < (int)UVar5) && (local_4c.n2.vt == 9)) {
      if (param_2 != (IUnknown *)local_4c._8_4_) {
        ATL::AtlComQIPtrAssign(&param_2,(IUnknown *)local_4c._8_4_,(_GUID *)&DAT_41c3175c);
        uVar7 = extraout_ECX_00;
      }
      if (param_2 != (IUnknown *)0x0) {
        (*param_2->lpVtbl[3].QueryInterface)(param_2,(IID *)local_20,&ppvObject_00->QueryInterface);
        uVar7 = extraout_ECX_01;
      }
    }
    if (((int)local_20._0_4_ < 1) || (local_28 != 0)) {
      if ((local_20._0_4_ == 0) || (local_28 == 1)) {
        riid = (IID *)&param_1;
        (*local_14[0]->lpVtbl[3].QueryInterface)(local_14[0],riid,&ppvObject_00->QueryInterface);
        piVar6 = param_1;
        if (param_6 == 0) {
          pIVar13 = (IID *)*piVar8;
          if (pIVar13 != (IID *)0x0) {
            (**(code **)(pIVar13->Data1 + 4))(pIVar13,pIVar13);
            riid = pIVar13;
          }
          piVar6 = (int *)FUN_41c11afc((int)param_1,0.0,(int *)riid);
        }
        if ((int)piVar6 < *param_4) {
          *param_4 = (int)piVar6;
          goto LAB_41c0ad85;
        }
      }
    }
    else {
      local_20._4_4_ = 0;
      local_24 = uVar7 & 0xffffff00;
      puVar10 = (undefined1 *)0x0;
      if (0 < (int)local_20._0_4_) {
        do {
          FUN_41c18d70((uint *)&local_5c,0,0x10);
          VariantInit((VARIANTARG *)&local_5c.n2);
          p_Var12 = &local_5c;
          local_8._0_1_ = 9;
          iVar3 = local_20._4_4_ + 1;
          local_20._4_4_ = iVar3;
          UVar5 = (*param_2->lpVtbl[2].Release)(param_2);
          piVar8 = param_1;
          if (-1 < (int)UVar5) {
            CComQIPtr<>(&local_34,(undefined4 *)local_5c._8_4_);
            local_8._0_1_ = 10;
            if (local_34 != (int *)0x0) {
              (**(code **)(*local_34 + 0x2c))(local_34,&param_5,iVar3,p_Var12);
              if (param_6 == 0) {
                piVar8 = (int *)*piVar8;
                if (piVar8 != (int *)0x0) {
                  (**(code **)(*piVar8 + 4))(piVar8);
                }
                param_5 = (undefined1 *)FUN_41c11afc((int)param_5,0.0,piVar8);
              }
              local_24 = local_24 & 0xff;
              if ((undefined1 *)*param_4 == param_5) {
                local_24 = 1;
              }
              if ((int)puVar10 < (int)param_5) {
                puVar10 = param_5;
              }
            }
            local_8._0_1_ = 9;
            if (local_34 != (int *)0x0) {
              (**(code **)(*local_34 + 8))(local_34);
            }
          }
          VariantClear((VARIANTARG *)&local_5c.n2);
        } while ((int)local_20._4_4_ < (int)local_20._0_4_);
        if ((char)local_24 != '\0') goto LAB_41c0ad8a;
      }
      *param_4 = (int)puVar10;
LAB_41c0ad85:
      bVar9 = true;
    }
LAB_41c0ad8a:
    VariantClear((VARIANTARG *)&local_4c.n2);
    local_8 = CONCAT31(local_8._1_3_,6);
    if (param_2 != (IUnknown *)0x0) {
      (*param_2->lpVtbl->Release)(param_2);
    }
    piVar8 = &local_38;
LAB_41c0ada8:
    local_8._0_1_ = 5;
    FUN_41c11a0c(piVar8);
  }
  else {
    (*local_14[0]->lpVtbl[3].QueryInterface)(local_14[0],(IID *)&param_1,ppvObject);
    if ((param_1 != (int *)0x0) && (param_6 == 0)) {
      FUN_41c11a03(&param_6);
      piVar8 = (int *)*piVar8;
      local_8 = CONCAT31(local_8._1_3_,0xb);
      if (piVar8 != (int *)0x0) {
        (**(code **)(*piVar8 + 4))(piVar8,piVar8);
      }
      param_1 = (int *)FUN_41c11afc((int)param_1,0.0,(int *)ppOVar11);
      bVar9 = (int)param_1 < *param_4;
      if (bVar9) {
        *param_4 = (int)param_1;
      }
      piVar8 = &param_6;
      goto LAB_41c0ada8;
    }
  }
  SysFreeString(local_18);
LAB_41c0adba:
  SysFreeString((BSTR)local_2c);
  local_8 = 0xffffffff;
  if (local_14[0] != (IUnknown *)0x0) {
    (*local_14[0]->lpVtbl->Release)(local_14[0]);
  }
  return bVar9;
}


