// Source: CLCiffConversion_Layout.dll @ 45417c7c; FUN_45417c7c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

HRESULT __thiscall FUN_45417c7c(void *this,IUnknownVtbl *param_1)

{
  IUnknownVtbl *pIVar1;
  void *pvVar2;
  bool bVar3;
  undefined4 *puVar4;
  undefined3 extraout_var;
  int iVar5;
  HRESULT HVar6;
  int *piVar7;
  IID *rclsid;
  int *piVar8;
  _union_2683 local_60;
  _union_2683 local_50;
  _union_2683 local_40;
  int local_30;
  int local_2c;
  IUnknownVtbl *local_28;
  int local_24;
  BSTR local_20;
  void *local_1c;
  HRESULT local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  pIVar1 = param_1;
  uStack_4 = 0x50;
  local_8 = 0x45417c88;
  local_18 = 0;
  local_1c = this;
  puVar4 = FUN_4541cbbe(param_1,&local_20);
  local_8 = 0;
  piVar8 = (int *)((int)this + -0x10);
  FUN_45407800((void *)((int)this + *(int *)(*piVar8 + 4) + 0x54),(wchar_t *)*puVar4);
  local_8 = 0xffffffff;
  SysFreeString(local_20);
  bVar3 = FUN_4541db71((int *)pIVar1);
  if (CONCAT31(extraout_var,bVar3) != 0) {
    return local_18;
  }
  (**(code **)(*(int *)pIVar1->AddRef + 100))(pIVar1->AddRef,&local_20);
  if (local_20 == (BSTR)0x0) {
    FUN_4541e46c(piVar8);
    FUN_4541cdb6(pIVar1,&local_20);
    local_14[0] = (int *)((int)this + -0xc);
    local_8 = 1;
    piVar7 = *(int **)*local_14[0];
    if (piVar7 != (int *)*local_14[0]) {
      do {
        local_28 = (IUnknownVtbl *)piVar7[2];
        FUN_4541db3e(local_28,&param_1);
        local_8 = CONCAT31(local_8._1_3_,2);
        HVar6 = VarBstrCmp(local_20,(BSTR)param_1,0x400,0);
        if (HVar6 == 1) {
          FUN_4541fc37(piVar8,local_28,pIVar1);
        }
        local_8 = CONCAT31(local_8._1_3_,1);
        SysFreeString((BSTR)param_1);
        piVar7 = (int *)*piVar7;
      } while (piVar7 != (int *)*local_14[0]);
    }
    FUN_45412128(local_14[0]);
    SysFreeString(local_20);
    return local_18;
  }
  if (local_20 != (BSTR)0x1) {
    return local_18;
  }
  local_14[0] = (int *)0x0;
  local_8 = 3;
  iVar5 = FUN_4541c661((int)pIVar1);
  if (-1 < iVar5) {
    if (iVar5 < 3) {
      rclsid = (IID *)&DAT_45447d8c;
    }
    else {
      if (9 < iVar5) goto LAB_45417d4f;
      rclsid = (IID *)&DAT_45447d9c;
    }
    local_18 = CoCreateInstance(rclsid,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_45449d68,local_14);
    if (local_18 < 0) goto LAB_45417ec3;
  }
LAB_45417d4f:
  if (local_14[0] != (int *)0x0) {
    local_60._8_4_ = pIVar1->AddRef;
    local_60.n2.vt = 9;
    if ((_func_5022 *)local_60._8_4_ != (_func_5022 *)0x0) {
      (**(code **)(*(int *)local_60._8_4_ + 4))(local_60._8_4_);
    }
    local_8._0_1_ = 4;
    local_50._8_4_ = *(int *)(*(int *)(*piVar8 + 4) + 0x28 + (int)this);
    local_50.n2.vt = 9;
    if ((int *)local_50._8_4_ != (int *)0x0) {
      (**(code **)(*(int *)local_50._8_4_ + 4))(local_50._8_4_);
    }
    local_8._0_1_ = 5;
    local_40._8_4_ = *(int *)(*(int *)(*piVar8 + 4) + 0x24 + (int)this);
    local_40.n2.vt = 9;
    if ((int *)local_40._8_4_ != (int *)0x0) {
      (**(code **)(*(int *)local_40._8_4_ + 4))(local_40._8_4_);
    }
    local_30 = 0;
    local_2c = 0;
    local_8._0_1_ = 6;
    local_18 = (**(code **)(*local_14[0] + 0x30))
                         (local_14[0],&local_30,local_60._0_4_,local_60.decVal.Hi32,local_60._8_4_,
                          local_60._12_4_,local_50._0_4_,local_50.decVal.Hi32,local_50._8_4_,
                          local_50._12_4_,local_40._0_4_,local_40.decVal.Hi32,local_40._8_4_,
                          local_40._12_4_);
    pvVar2 = local_1c;
    if (-1 < local_18) {
      piVar7 = *(int **)(*(int *)(*piVar8 + 4) + 0x24 + (int)local_1c);
      iVar5 = (**(code **)(*piVar7 + 0x54))(piVar7,&local_24);
      if ((-1 < iVar5) && (local_24 == 0)) {
        FUN_45402881(&local_28);
        local_8 = CONCAT31(local_8._1_3_,7);
        piVar7 = *(int **)(*(int *)(*piVar8 + 4) + 0x28 + (int)pvVar2);
        if (piVar7 != (int *)0x0) {
          (**(code **)(*piVar7 + 4))(piVar7);
        }
        local_30 = FUN_45403583(local_30,1.4013e-45,piVar7);
        piVar8 = *(int **)(*(int *)(*piVar8 + 4) + 0x28 + (int)pvVar2);
        if (piVar8 != (int *)0x0) {
          (**(code **)(*piVar8 + 4))(piVar8);
        }
        local_2c = FUN_45403583(local_2c,0.0,piVar8);
        local_8._0_1_ = 6;
        FUN_45402c42(&local_28);
      }
      pIVar1 = param_1;
      (**(code **)(*(int *)param_1->AddRef + 0x7c))(param_1->AddRef,local_30);
      local_18 = (**(code **)(*(int *)pIVar1->AddRef + 0x84))(pIVar1->AddRef,local_2c);
    }
    VariantClear((VARIANTARG *)&local_40.n2);
    VariantClear((VARIANTARG *)&local_50.n2);
    VariantClear((VARIANTARG *)&local_60.n2);
  }
LAB_45417ec3:
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return local_18;
}


