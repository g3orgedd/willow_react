// Source: CiffMgr.dll @ 6811d4d5; FUN_6811d4d5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

ULONG FUN_6811d4d5(SAFEARRAY *param_1,SAFEARRAY *param_2,undefined4 param_3)

{
  ULONG UVar1;
  int iVar2;
  undefined4 bstrString;
  ULONG unaff_EDI;
  _union_2683 local_3c;
  IUnknown *local_2c;
  undefined4 local_28;
  ULONG local_24;
  BSTR local_20;
  int local_1c;
  IUnknown *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  if (param_1 == (SAFEARRAY *)0x0) {
    return unaff_EDI;
  }
  iVar2 = 0;
  local_14[0] = (int *)0x0;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  UVar1 = (**(code **)(**(int **)param_2 + 0x44))(*(int **)param_2,local_14);
  bstrString = (IUnknown *)0x0;
  local_2c = (IUnknown *)0x0;
  local_24 = 0;
  local_28 = 0;
  local_1c = 0;
  if ((int)UVar1 < 0) goto LAB_6811d8cb;
  if (local_14[0] != (int *)0x0) {
    local_18 = (IUnknown *)0x0;
    local_8._0_1_ = 2;
    UVar1 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],PTR_u_Name_681600ac,&local_18);
    if ((UVar1 == 0) && (local_18 != (IUnknown *)0x0)) {
      FUN_68132710((uint *)&local_3c,0,0x10);
      VariantInit((VARIANTARG *)&local_3c.n2);
      local_8._0_1_ = 3;
      UVar1 = (*local_18->lpVtbl[2].Release)(local_18);
      if (local_3c.n2.vt == 8) {
        if ((IUnknown *)local_3c._8_4_ != (IUnknown *)0x0) {
          SysFreeString((BSTR)0x0);
          local_2c = (IUnknown *)local_3c._8_4_;
          bstrString = local_3c._8_4_;
        }
        local_3c._8_4_ = (IUnknown *)0x0;
        iVar2 = local_1c;
      }
      VariantClear((VARIANTARG *)&local_3c.n2);
    }
    local_8._0_1_ = 1;
    if (local_18 != (IUnknown *)0x0) {
      (*local_18->lpVtbl->Release)(local_18);
    }
    if ((int)UVar1 < 0) goto LAB_6811d8cb;
    local_18 = (IUnknown *)0x0;
    local_8._0_1_ = 4;
    UVar1 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],PTR_u_Size_681600b0,&local_18);
    if ((UVar1 == 0) && (local_18 != (IUnknown *)0x0)) {
      FUN_68132710((uint *)&local_3c,0,0x10);
      VariantInit((VARIANTARG *)&local_3c.n2);
      local_8._0_1_ = 5;
      UVar1 = (*local_18->lpVtbl[2].Release)(local_18);
      if (local_3c.n2.vt == 8) {
        local_24 = FUN_6812f116((ushort *)local_3c._8_4_);
      }
      VariantClear((VARIANTARG *)&local_3c.n2);
    }
    local_8._0_1_ = 1;
    if (local_18 != (IUnknown *)0x0) {
      (*local_18->lpVtbl->Release)(local_18);
    }
    if ((int)UVar1 < 0) goto LAB_6811d8cb;
    local_18 = (IUnknown *)0x0;
    local_8._0_1_ = 6;
    UVar1 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],PTR_u_Type_681600b4,&local_18);
    if ((UVar1 == 0) && (local_18 != (IUnknown *)0x0)) {
      FUN_68132710((uint *)&local_3c,0,0x10);
      VariantInit((VARIANTARG *)&local_3c.n2);
      local_8._0_1_ = 7;
      UVar1 = (*local_18->lpVtbl[2].Release)(local_18);
      if (local_3c.n2.vt == 8) {
        local_28 = FUN_6812ec5f((wchar_t *)local_3c._8_4_);
      }
      VariantClear((VARIANTARG *)&local_3c.n2);
    }
    local_8._0_1_ = 1;
    if (local_18 != (IUnknown *)0x0) {
      (*local_18->lpVtbl->Release)(local_18);
    }
    if ((int)UVar1 < 0) goto LAB_6811d8cb;
    local_18 = (IUnknown *)0x0;
    local_8._0_1_ = 8;
    UVar1 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],PTR_u_CompType_681600b8,&local_18);
    if ((UVar1 == 0) && (local_18 != (IUnknown *)0x0)) {
      FUN_68132710((uint *)&local_3c,0,0x10);
      VariantInit((VARIANTARG *)&local_3c.n2);
      local_8._0_1_ = 9;
      UVar1 = (*local_18->lpVtbl[2].Release)(local_18);
      if (local_3c.n2.vt == 8) {
        iVar2 = FUN_6812ec05((wchar_t *)local_3c._8_4_);
        local_1c = iVar2;
      }
      VariantClear((VARIANTARG *)&local_3c.n2);
    }
    local_8._0_1_ = 1;
    if (local_18 != (IUnknown *)0x0) {
      (*local_18->lpVtbl->Release)(local_18);
    }
  }
  if ((int)UVar1 < 0) goto LAB_6811d8cb;
  local_18 = (IUnknown *)0x0;
  FUN_68132710((uint *)&local_3c,0,0x10);
  VariantInit((VARIANTARG *)&local_3c.n2);
  local_8 = CONCAT31(local_8._1_3_,0xb);
  UVar1 = (**(code **)(*(int *)param_1 + 0x28))
                    (param_1,bstrString,local_28,local_24,iVar2,&local_3c);
  if ((-1 < (int)UVar1) && (local_3c.n2.vt == 9)) {
    if (local_18 != (IUnknown *)local_3c._8_4_) {
      ATL::AtlComQIPtrAssign(&local_18,(IUnknown *)local_3c._8_4_,(_GUID *)&DAT_68147aa4);
    }
    if (local_18 == (IUnknown *)0x0) {
      UVar1 = 0x80004005;
    }
    else {
      local_20 = (BSTR)0x0;
      UVar1 = (**(code **)(**(int **)param_2 + 0x68))(*(int **)param_2,&local_20);
      if (-1 < (int)UVar1) {
        FUN_68114625(&local_28,param_3);
        param_1 = (SAFEARRAY *)0x0;
        UVar1 = FUN_68114633(&local_28,local_20,&param_1);
        if ((int)UVar1 < 0) {
          if (param_1 == (SAFEARRAY *)0x0) goto LAB_6811d89b;
        }
        else if (param_1 == (SAFEARRAY *)0x0) {
LAB_6811d89b:
          UVar1 = 0x80004005;
        }
        else {
          if ((iVar2 != 0) && (local_1c = local_1c + -1, local_1c == 0)) {
            FUN_68130739(&param_3);
            param_2 = (SAFEARRAY *)0x0;
            local_8 = CONCAT31(local_8._1_3_,0xc);
            UVar1 = FUN_68130a49(param_1,(byte *)&param_2,local_24);
            if (UVar1 == 0) {
              SafeArrayDestroy(param_1);
              param_1 = param_2;
            }
            local_8 = CONCAT31(local_8._1_3_,0xb);
            FUN_68130742(&param_3);
          }
          if (-1 < (int)UVar1) {
            UVar1 = (*local_18->lpVtbl[5].AddRef)(local_18);
          }
          SafeArrayDestroy(param_1);
        }
      }
      SysFreeString(local_20);
    }
  }
  VariantClear((VARIANTARG *)&local_3c.n2);
  local_8._0_1_ = 1;
  if (local_18 != (IUnknown *)0x0) {
    (*local_18->lpVtbl->Release)(local_18);
  }
LAB_6811d8cb:
  SysFreeString((BSTR)bstrString);
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return UVar1;
}


