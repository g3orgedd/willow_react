// Source: CLCiffConversion_Data.dll @ 450138b5; FUN_450138b5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

HRESULT __thiscall FUN_450138b5(void *this,BSTR param_1)

{
  int iVar1;
  HDC pHVar2;
  int *piVar3;
  undefined1 uVar4;
  bool bVar5;
  LPVOID *ppv;
  HRESULT HVar6;
  HDC hdc;
  int *piVar7;
  HGDIOBJ ho;
  _union_2683 local_7c;
  _union_2683 local_6c;
  _union_2683 local_5c;
  _union_2683 local_4c;
  int *local_3c;
  HDC local_38;
  HGDIOBJ local_34;
  int local_30;
  int *local_2c;
  int *local_28;
  HDC local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x6c;
  local_8 = 0x450138c1;
  iVar1 = *(int *)(*(int *)((int)this + 4) + 4);
  if ((((*(int *)(iVar1 + 0x3c + (int)this) == 0) || (*(int *)(iVar1 + 0x38 + (int)this) == 0)) ||
      (param_1 == (BSTR)0x0)) || (*(int *)(param_1 + 2) == 0)) {
    HVar6 = -0x7fffbffd;
  }
  else {
    ppv = (LPVOID *)(iVar1 + 0xe0 + (int)this);
    if (*ppv == (LPVOID)0x0) {
      CoCreateInstance((IID *)&DAT_4503d9f8,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_4503eb0c,ppv);
    }
    local_20 = (int *)0x0;
    local_8 = 0;
    HVar6 = CoCreateInstance((IID *)&DAT_4503e1f0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_4503ec7c,&local_20
                            );
    if (-1 < HVar6) {
      CComQIPtr<>(&local_24,local_20);
      local_8._0_1_ = 1;
      if (local_24 != (HDC)0x0) {
        local_7c._8_4_ = *(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xe0 + (int)this);
        local_7c.n2.vt = 9;
        if ((int *)local_7c._8_4_ != (int *)0x0) {
          (**(code **)(*(int *)local_7c._8_4_ + 4))(local_7c._8_4_);
        }
        local_8._0_1_ = 2;
        HVar6 = (**(code **)(local_24->unused + 0xc))
                          (local_24,local_7c._0_4_,local_7c.decVal.Hi32,local_7c._8_4_,
                           local_7c._12_4_);
        VariantClear((VARIANTARG *)&local_7c.n2);
      }
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_24 != (HDC)0x0) {
        (**(code **)(local_24->unused + 8))(local_24);
      }
    }
    local_1c = (int *)0x0;
    if (-1 < HVar6) {
      HVar6 = CoCreateInstance((IID *)&DAT_4503e210,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_4503ec7c,
                               &local_1c);
    }
    CComQIPtr<>(&local_2c,local_1c);
    local_8._0_1_ = 4;
    if (local_2c != (int *)0x0) {
      local_7c._8_4_ = *(undefined4 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xe0 + (int)this);
      local_7c.n2.vt = 9;
      if ((int *)local_7c._8_4_ != (int *)0x0) {
        (**(code **)(*(int *)local_7c._8_4_ + 4))(local_7c._8_4_);
      }
      local_8._0_1_ = 5;
      HVar6 = (**(code **)(*local_2c + 0xc))
                        (local_2c,local_7c._0_4_,local_7c.decVal.Hi32,local_7c._8_4_,local_7c._12_4_
                        );
      VariantClear((VARIANTARG *)&local_7c.n2);
    }
    local_18 = (int *)0x0;
    if (-1 < HVar6) {
      HVar6 = CoCreateInstance((IID *)&DAT_4503e220,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_4503ec7c,
                               &local_18);
    }
    CComQIPtr<>(&local_28,local_18);
    local_8._0_1_ = 7;
    uVar4 = (undefined1)local_8;
    local_8._0_1_ = 7;
    if (local_28 != (int *)0x0) {
      local_7c._8_4_ = *(undefined4 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xe0 + (int)this);
      local_7c.n2.vt = 9;
      if ((int *)local_7c._8_4_ != (int *)0x0) {
        (**(code **)(*(int *)local_7c._8_4_ + 4))(local_7c._8_4_);
      }
      local_8._0_1_ = 8;
      HVar6 = (**(code **)(*local_28 + 0xc))
                        (local_28,local_7c._0_4_,local_7c.decVal.Hi32,local_7c._8_4_,local_7c._12_4_
                        );
      VariantClear((VARIANTARG *)&local_7c.n2);
      uVar4 = (undefined1)local_8;
    }
    local_8._0_1_ = uVar4;
    CComQIPtr<>(local_14,*(undefined4 **)(param_1 + 2));
    local_8 = CONCAT31(local_8._1_3_,9);
    local_38 = CreateCompatibleDC((HDC)0x0);
    hdc = CreateCompatibleDC(local_38);
    local_24 = hdc;
    local_34 = GetCurrentObject(hdc,7);
    local_6c._8_4_ = local_14[0];
    local_6c.n2.vt = 9;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 4))(local_14[0]);
    }
    local_8._0_1_ = 10;
    local_5c._8_4_ = *(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x3c + (int)this);
    local_5c.n2.vt = 9;
    if ((int *)local_5c._8_4_ != (int *)0x0) {
      (**(code **)(*(int *)local_5c._8_4_ + 4))(local_5c._8_4_);
    }
    local_8._0_1_ = 0xb;
    local_4c._8_4_ = *(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x38 + (int)this);
    local_4c.n2.vt = 9;
    if ((int *)local_4c._8_4_ != (int *)0x0) {
      (**(code **)(*(int *)local_4c._8_4_ + 4))(local_4c._8_4_);
    }
    local_30 = 0;
    local_8 = CONCAT31(local_8._1_3_,0xc);
    if ((local_14[0] == (int *)0x0) ||
       (HVar6 = (**(code **)(*local_14[0] + 0xd0))(local_14[0],&local_30), piVar3 = local_14[0],
       local_30 != 1)) {
      pHVar2 = local_24;
      if (local_20 != (int *)0x0) {
        HVar6 = (**(code **)(*local_20 + 0xc))
                          (local_20,local_24,1,local_6c._0_4_,local_6c.decVal.Hi32,local_6c._8_4_,
                           local_6c._12_4_,local_5c._0_4_,local_5c.decVal.Hi32,local_5c._8_4_,
                           local_5c._12_4_,local_4c._0_4_,local_4c.decVal.Hi32,local_4c._8_4_,
                           local_4c._12_4_,0);
        hdc = pHVar2;
      }
    }
    else {
      local_3c = local_14[0];
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 4))(local_14[0]);
      }
      param_1 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,0xe);
      if (piVar3 != (int *)0x0) {
        HVar6 = (**(code **)(*piVar3 + 0x68))(piVar3,&param_1);
      }
      bVar5 = FUN_450023b0(&param_1,L"RichText");
      pHVar2 = local_24;
      piVar7 = local_1c;
      if (bVar5) {
        piVar7 = local_18;
      }
      if (piVar7 != (int *)0x0) {
        HVar6 = (**(code **)(*piVar7 + 0xc))
                          (piVar7,local_24,1,local_6c._0_4_,local_6c.decVal.Hi32,local_6c._8_4_,
                           local_6c._12_4_,local_5c._0_4_,local_5c.decVal.Hi32,local_5c._8_4_,
                           local_5c._12_4_,local_4c._0_4_,local_4c.decVal.Hi32,local_4c._8_4_,
                           local_4c._12_4_,0);
        hdc = pHVar2;
      }
      SysFreeString(param_1);
      local_8 = CONCAT31(local_8._1_3_,0xc);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 8))(piVar3);
      }
    }
    ho = SelectObject(hdc,local_34);
    if (ho != (HGDIOBJ)0x0) {
      DeleteObject(ho);
    }
    if (hdc != (HDC)0x0) {
      DeleteDC(hdc);
    }
    if (local_38 != (HDC)0x0) {
      DeleteDC(local_38);
    }
    VariantClear((VARIANTARG *)&local_4c.n2);
    VariantClear((VARIANTARG *)&local_5c.n2);
    VariantClear((VARIANTARG *)&local_6c.n2);
    local_8._0_1_ = 7;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
    local_8._0_1_ = 6;
    if (local_28 != (int *)0x0) {
      (**(code **)(*local_28 + 8))(local_28);
    }
    local_8._0_1_ = 4;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
    local_8._0_1_ = 3;
    if (local_2c != (int *)0x0) {
      (**(code **)(*local_2c + 8))(local_2c);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))(local_1c);
    }
    local_8 = 0xffffffff;
    if (local_20 != (int *)0x0) {
      (**(code **)(*local_20 + 8))(local_20);
    }
  }
  return HVar6;
}


