// Source: CiffMgr.dll @ 6811c830; FUN_6811c830

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

ULONG FUN_6811c830(IUnknown *param_1,undefined4 *param_2)

{
  IUnknown *This;
  ULONG UVar1;
  ULONG UVar2;
  size_t sVar3;
  int iVar4;
  undefined4 uVar5;
  VARIANTARG *pVVar6;
  void **in_stack_ffffff8c;
  VARIANTARG local_64;
  _union_2683 local_54;
  _union_2683 local_44;
  _union_2683 local_34;
  BSTR local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  This = param_1;
  uStack_4 = 0x54;
  if (param_1 == (IUnknown *)0x0) {
    UVar1 = 0x80004003;
  }
  else {
    do {
      local_20 = (int *)0x0;
      local_8 = 0;
      UVar1 = (**(code **)(*(int *)*param_2 + 0x24))((int *)*param_2,&local_20);
      if ((UVar1 == 0) && (local_20 != (int *)0x0)) {
        param_1 = (IUnknown *)0x0;
        local_14[0] = (int *)0x0;
        local_8._0_1_ = 2;
        UVar2 = (**(code **)(*local_20 + 0x44))(local_20,local_14);
        if ((-1 < (int)UVar2) && (local_14[0] != (int *)0x0)) {
          local_18 = (int *)0x0;
          local_8._0_1_ = 3;
          UVar2 = (**(code **)(*local_14[0] + 0x1c))
                            (local_14[0],PTR_u_DataSourceName_681600bc,&local_18);
          if ((-1 < (int)UVar2) && (local_18 != (int *)0x0)) {
            FUN_68132710((uint *)&local_34,0,0x10);
            VariantInit((VARIANTARG *)&local_34.n2);
            local_8._0_1_ = 4;
            UVar2 = (**(code **)(*local_18 + 0x20))(local_18,&local_34);
            if ((local_34.n2.vt == 8) &&
               (((wchar_t *)local_34._8_4_ != (wchar_t *)0x0 &&
                (sVar3 = _wcslen((wchar_t *)local_34._8_4_), sVar3 != 0)))) {
              FUN_68132710((uint *)&local_64,0,0x10);
              VariantInit(&local_64);
              pVVar6 = &local_64;
              local_8._0_1_ = 5;
              uVar5 = local_34._8_4_;
              UVar2 = (*This->lpVtbl[2].Release)(This);
              if (-1 < (int)UVar2) {
                if (param_1 != (IUnknown *)local_64.n1._8_4_) {
                  ATL::AtlComQIPtrAssign
                            (&param_1,(IUnknown *)local_64.n1._8_4_,(_GUID *)&DAT_6814b1e4);
                }
                local_24 = (BSTR)0x0;
                UVar2 = (**(code **)(*local_20 + 0x68))(local_20,&local_24,uVar5,pVVar6);
                if (-1 < (int)UVar2) {
                  UVar2 = (*param_1->lpVtbl[4].Release)(param_1);
                }
                SysFreeString(local_24);
              }
              VariantClear(&local_64);
            }
            VariantClear((VARIANTARG *)&local_34.n2);
          }
          local_8._0_1_ = 2;
          if (local_18 != (int *)0x0) {
            (**(code **)(*local_18 + 8))(local_18);
          }
        }
        if (param_1 != (IUnknown *)0x0) {
          local_18 = (int *)0x0;
          local_8._0_1_ = 6;
          iVar4 = (**(code **)(*local_14[0] + 0x1c))
                            (local_14[0],PTR_u_DataSourceTable_681600c0,&local_18);
          if ((iVar4 == 0) && (local_18 != (int *)0x0)) {
            FUN_68132710((uint *)&local_44,0,0x10);
            VariantInit((VARIANTARG *)&local_44.n2);
            local_8._0_1_ = 7;
            (**(code **)(*local_18 + 0x20))(local_18,&local_44);
            if (local_44.n2.vt == 8) {
              (*param_1->lpVtbl[3].AddRef)(param_1);
            }
            VariantClear((VARIANTARG *)&local_44.n2);
          }
          local_8._0_1_ = 2;
          if (local_18 != (int *)0x0) {
            (**(code **)(*local_18 + 8))(local_18);
          }
          local_1c = (int *)0x0;
          local_8._0_1_ = 8;
          UVar2 = (**(code **)(*local_14[0] + 0x1c))
                            (local_14[0],PTR_u_DataSourceIndex_681600c4,&local_1c);
          if ((UVar2 == 0) && (local_1c != (int *)0x0)) {
            FUN_68132710((uint *)&local_54,0,0x10);
            VariantInit((VARIANTARG *)&local_54.n2);
            local_8._0_1_ = 9;
            UVar2 = (**(code **)(*local_1c + 0x20))(local_1c,&local_54);
            if (local_54.n2.vt == 8) {
              UVar2 = (*param_1->lpVtbl[4].QueryInterface)
                                (param_1,(IID *)local_54._8_4_,in_stack_ffffff8c);
            }
            VariantClear((VARIANTARG *)&local_54.n2);
          }
          local_8._0_1_ = 2;
          if (local_1c != (int *)0x0) {
            (**(code **)(*local_1c + 8))(local_1c);
          }
        }
        local_8._0_1_ = 1;
        if ((int)UVar2 < 0) {
          UVar1 = UVar2;
        }
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
        local_8 = (uint)local_8._1_3_ << 8;
        if (param_1 != (IUnknown *)0x0) {
          (*param_1->lpVtbl->Release)(param_1);
        }
      }
      local_8 = 0xffffffff;
      if (local_20 != (int *)0x0) {
        (**(code **)(*local_20 + 8))(local_20);
      }
    } while (UVar1 == 0);
    if (UVar1 == 1) {
      UVar1 = 0;
    }
  }
  return UVar1;
}


