// Source: CiffHelper.dll @ 4080e231; FUN_4080e231

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_4080e231(int *param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  IUnknown *This;
  int iVar2;
  IUnknown *This_00;
  IUnknown *This_01;
  _union_2683 local_80;
  _union_2683 local_70;
  VARIANTARG local_60;
  _union_2683 local_50;
  IUnknown *local_40;
  undefined4 local_3c;
  IUnknown *local_38;
  int *local_34;
  IUnknown *local_30;
  IID *local_2c;
  BSTR local_28;
  int local_24;
  int local_20;
  IUnknown *local_1c;
  IUnknown *local_18;
  BSTR local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x70;
  piVar1 = (int *)*param_1;
  if ((piVar1 == (int *)0x0) || (This_00 = (IUnknown *)0x0, *param_2 == 0)) {
    local_3c = 0x80004003;
  }
  else {
    local_2c = (IID *)0x0;
    local_8 = 0;
    (**(code **)(*piVar1 + 0xe4))(piVar1,&local_2c);
    local_1c = (IUnknown *)0x0;
    local_30 = (IUnknown *)0x0;
    local_18 = (IUnknown *)0x0;
    local_40 = (IUnknown *)0x0;
    local_24 = 0;
    local_8 = CONCAT31(local_8._1_3_,4);
    local_3c = (**(code **)(*(int *)*param_2 + 0x1c))((int *)*param_2,&local_24);
    local_20 = 0;
    This_01 = (IUnknown *)0x0;
    if (0 < local_24) {
      do {
        FUN_40802e76((uint *)&local_60);
        local_20 = local_20 + 1;
        local_8 = CONCAT31(local_8._1_3_,5);
        local_3c = (**(code **)(*(int *)*param_2 + 0x24))((int *)*param_2,local_20,&local_60);
        local_38 = local_1c;
        if (local_1c != (IUnknown *)local_60.n1._8_4_) {
          ATL::AtlComQIPtrAssign(&local_1c,(IUnknown *)local_60.n1._8_4_,(_GUID *)&DAT_4084a928);
        }
        This = local_1c;
        local_30 = local_1c;
        local_38 = local_1c;
        if (local_1c != (IUnknown *)0x0) {
          (*local_1c->lpVtbl->AddRef)(local_1c);
        }
        FUN_40802e76((uint *)&local_50);
        local_8 = CONCAT31(local_8._1_3_,6);
        (*This->lpVtbl[4].QueryInterface)(This,local_2c,(void **)&local_50);
        if (local_50.n2.vt == 9) {
          if (local_18 != (IUnknown *)local_50._8_4_) {
            ATL::AtlComQIPtrAssign(&local_18,(IUnknown *)local_50._8_4_,(_GUID *)&DAT_4084a938);
          }
          This_00 = local_18;
          local_40 = local_18;
          if (local_18 != (IUnknown *)0x0) {
            (*local_18->lpVtbl->AddRef)(local_18);
          }
          local_80._8_4_ = *param_2;
          local_80.n2.vt = 9;
          if ((int *)local_80._8_4_ != (int *)0x0) {
            (**(code **)(*(int *)local_80._8_4_ + 4))(local_80._8_4_);
          }
          local_8._0_1_ = 7;
          local_70.n2.vt = 9;
          local_70._8_4_ = This_00;
          if (This_00 != (IUnknown *)0x0) {
            (*This_00->lpVtbl->AddRef)(This_00);
          }
          local_8 = CONCAT31(local_8._1_3_,8);
          iVar2 = local_34[0x1e];
          *(undefined1 *)(local_34 + 0x1e) = 0;
          (**(code **)(*local_34 + 0xa0))
                    (local_34,&local_70,local_80._0_4_,local_80.decVal.Hi32,local_80._8_4_,
                     local_80._12_4_,param_3);
          *(char *)(local_34 + 0x1e) = (char)iVar2;
          VariantClear((VARIANTARG *)&local_70.n2);
          VariantClear((VARIANTARG *)&local_80.n2);
          VariantClear((VARIANTARG *)&local_50.n2);
          VariantClear(&local_60);
          This_01 = local_38;
          break;
        }
        This_01 = (IUnknown *)0x0;
        local_30 = (IUnknown *)0x0;
        if (This != (IUnknown *)0x0) {
          (*This->lpVtbl->Release)(This);
        }
        VariantClear(&local_60);
        VariantClear((VARIANTARG *)&local_50.n2);
        VariantClear(&local_60);
      } while (local_20 < local_24);
    }
    local_28 = (BSTR)0x0;
    local_8._0_1_ = 9;
    if (This_00 != (IUnknown *)0x0) {
      (*This_00->lpVtbl[0xc].Release)(This_00);
    }
    local_14[0] = (BSTR)0x0;
    local_8 = CONCAT31(local_8._1_3_,10);
    iVar2 = FUN_40805870(param_1,(int *)&local_28,(int *)local_14);
    if (-1 < iVar2) {
      (**(code **)(*(int *)*param_1 + 100))((int *)*param_1,local_14[0]);
      (**(code **)(*(int *)*param_1 + 0x5c))((int *)*param_1,local_14[0]);
    }
    SysFreeString(local_14[0]);
    SysFreeString(local_28);
    local_8._0_1_ = 3;
    if (This_00 != (IUnknown *)0x0) {
      (*This_00->lpVtbl->Release)(This_00);
    }
    local_8._0_1_ = 2;
    if (local_18 != (IUnknown *)0x0) {
      (*local_18->lpVtbl->Release)(local_18);
    }
    local_8._0_1_ = 1;
    if (This_01 != (IUnknown *)0x0) {
      (*This_01->lpVtbl->Release)(This_01);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_1c != (IUnknown *)0x0) {
      (*local_1c->lpVtbl->Release)(local_1c);
    }
    SysFreeString((BSTR)local_2c);
  }
  return local_3c;
}


