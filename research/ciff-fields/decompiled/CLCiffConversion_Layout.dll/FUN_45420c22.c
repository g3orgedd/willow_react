// Source: CLCiffConversion_Layout.dll @ 45420c22; FUN_45420c22

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_45420c22(void *this,BSTR param_1)

{
  OLECHAR OVar1;
  void *pvVar2;
  undefined3 uVar3;
  HRESULT HVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  BSTR pOVar9;
  int local_70;
  int *local_6c;
  int local_68;
  int local_64;
  _union_2683 local_60;
  wchar_t *local_50;
  void *local_4c;
  int local_48;
  BSTR local_44;
  wchar_t *local_40;
  int *local_3c;
  BSTR local_38;
  BSTR local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x68;
  local_8 = 0x45420c2e;
  local_34 = param_1;
  local_4c = this;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCiffConversion_Layout::ResolveCiffFileReference");
  piVar7 = (int *)((int)this + 0x30);
  local_8._1_3_ = 0;
  uVar3 = local_8._1_3_;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if (*param_1 == L'\b') {
    if (*piVar7 != 0) {
      piVar8 = (int *)*piVar7;
      if (piVar8 != (int *)0x0) {
        *piVar7 = 0;
        (**(code **)(*piVar8 + 8))(piVar8);
      }
      piVar8 = (int *)*piVar7;
      if ((piVar8 != (int *)0x0) && (*piVar7 = 0, piVar8 != (int *)0x0)) {
        (**(code **)(*piVar8 + 8))(piVar8);
      }
    }
    local_38 = (BSTR)0x0;
    local_8._0_1_ = 2;
    HVar4 = CoCreateInstance((IID *)&DAT_454492a8,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_4544a708,&local_38
                            );
    pOVar9 = local_38;
    if ((-1 < HVar4) && (local_38 != (BSTR)0x0)) {
      puVar5 = FUN_454028ee(&local_34,*(OLECHAR **)(local_34 + 4));
      local_8._0_1_ = 3;
      iVar6 = (**(code **)(*(int *)pOVar9 + 0x2c))(pOVar9,*puVar5,piVar7);
      SysFreeString(local_34);
      if (iVar6 < 0) {
LAB_45420d68:
        local_8 = CONCAT31(local_8._1_3_,1);
        if (local_38 != (BSTR)0x0) {
          (**(code **)(*(int *)local_38 + 8))(local_38);
        }
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0)
        ;
        FUN_4542110c();
        return;
      }
      local_3c = (int *)0x0;
      local_8 = CONCAT31(local_8._1_3_,4);
      local_40 = (wchar_t *)
                 CoCreateInstance((IID *)&DAT_45447d6c,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_454496b0,
                                  &local_3c);
      piVar8 = local_3c;
      if ((-1 < (int)local_40) && (local_3c != (int *)0x0)) {
        local_60._8_4_ = *piVar7;
        local_60.n2.vt = 9;
        if ((int *)local_60._8_4_ != (int *)0x0) {
          (**(code **)(*(int *)local_60._8_4_ + 4))(local_60._8_4_);
        }
        local_8 = CONCAT31(local_8._1_3_,5);
        local_40 = (wchar_t *)(**(code **)(*piVar8 + 0xbc))(piVar8,&local_60);
        VariantClear((VARIANTARG *)&local_60.n2);
      }
      local_8._0_1_ = 2;
      if (local_3c != (int *)0x0) {
        (**(code **)(*local_3c + 8))(local_3c);
      }
      if ((int)local_40 < 0) goto LAB_45420d68;
    }
    local_8._0_1_ = 1;
    if (local_38 != (BSTR)0x0) {
      (**(code **)(*(int *)local_38 + 8))(local_38);
    }
    goto LAB_45420e48;
  }
  local_8._1_3_ = uVar3;
  if (*piVar7 != 0) {
    piVar8 = (int *)*piVar7;
    if (piVar8 != (int *)0x0) {
      *piVar7 = 0;
      (**(code **)(*piVar8 + 8))(piVar8);
    }
    piVar8 = (int *)*piVar7;
    if ((piVar8 != (int *)0x0) && (*piVar7 = 0, piVar8 != (int *)0x0)) {
      (**(code **)(*piVar8 + 8))(piVar8);
    }
  }
  OVar1 = *param_1;
  if (OVar1 == L'䀉') {
    CComQIPtr<>(&local_34,(undefined4 *)**(undefined4 **)(param_1 + 4));
    FUN_45404ce5(piVar7,(int *)&local_34);
    if (local_34 != (BSTR)0x0) {
      (**(code **)(*(int *)local_34 + 8))(local_34);
    }
    goto LAB_45420e48;
  }
  if (OVar1 == L'\t') {
LAB_45420e25:
    puVar5 = *(undefined4 **)(param_1 + 4);
  }
  else {
    if (OVar1 != L'䀍') {
      if (OVar1 != L'\r') goto LAB_45420e48;
      goto LAB_45420e25;
    }
    puVar5 = (undefined4 *)**(undefined4 **)(param_1 + 4);
  }
  CComQIPtr<>(&local_34,puVar5);
  FUN_45404ce5(piVar7,(int *)&local_34);
  if (local_34 != (BSTR)0x0) {
    (**(code **)(*(int *)local_34 + 8))(local_34);
  }
LAB_45420e48:
  pvVar2 = local_4c;
  local_44 = (BSTR)0x0;
  local_8._0_1_ = 6;
  if (*(int *)((int)local_4c + 0x4e8) == 0) {
    iVar6 = (**(code **)(*(int *)*piVar7 + 0x44))((int *)*piVar7,&local_44);
  }
  else {
    FUN_45429f70((uint *)&local_60,0,0x10);
    VariantInit((VARIANTARG *)&local_60.n2);
    local_8._0_1_ = 7;
    iVar6 = (**(code **)(*(int *)*piVar7 + 0x24))
                      ((int *)*piVar7,*(undefined4 *)((int)pvVar2 + 0x4e8),&local_60);
    CComQIPtr<>(&local_34,(undefined4 *)local_60._8_4_);
    local_8._0_1_ = 8;
    if (local_34 != (BSTR)0x0) {
      (**(code **)(*(int *)local_34 + 0x9c))(local_34,&local_44);
    }
    local_8._0_1_ = 7;
    if (local_34 != (BSTR)0x0) {
      (**(code **)(*(int *)local_34 + 8))(local_34);
    }
    local_8._0_1_ = 6;
    VariantClear((VARIANTARG *)&local_60.n2);
  }
  pvVar2 = local_4c;
  if (iVar6 < 0) {
    FUN_4540500e(0x4544a4e4);
    SysFreeString(local_44);
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
    FUN_4542110c();
    return;
  }
  iVar6 = FUN_4541b899((void *)((int)local_4c + 0x4d0),&local_44);
  *(int *)((int)pvVar2 + 0x3c) = iVar6;
  if (iVar6 == 0) {
    FUN_4540500e(0x4544a50c);
  }
  local_64 = 0;
  iVar6 = (**(code **)(*(int *)*piVar7 + 0x1c))((int *)*piVar7,&local_64);
  if (-1 < iVar6) {
    for (pOVar9 = (BSTR)0x1; local_34 = pOVar9, (int)pOVar9 <= local_64;
        pOVar9 = (BSTR)((int)pOVar9 + 1)) {
      FUN_45429f70((uint *)&local_60,0,0x10);
      VariantInit((VARIANTARG *)&local_60.n2);
      if ((*(BSTR *)((int)local_4c + 0x4e8) == (BSTR)0x0) ||
         (*(BSTR *)((int)local_4c + 0x4e8) == pOVar9)) {
        local_8._0_1_ = 9;
        iVar6 = (**(code **)(**(int **)((int)local_4c + 0x30) + 0x24))
                          (*(int **)((int)local_4c + 0x30),pOVar9,&local_60);
        if (iVar6 < 0) {
          VariantClear((VARIANTARG *)&local_60.n2);
          break;
        }
        CComQIPtr<>(&local_3c,(undefined4 *)local_60._8_4_);
        local_50 = (wchar_t *)0x0;
        local_38 = (wchar_t *)0x0;
        local_40 = (wchar_t *)0x0;
        local_8._0_1_ = 0xd;
        (**(code **)(*local_3c + 0x9c))(local_3c,&local_40);
        (**(code **)(*local_3c + 0x34))(local_3c,&local_50);
        (**(code **)(*local_3c + 0x4c))(local_3c,&local_38);
        pvVar2 = local_4c;
        if (*(int *)((int)local_4c + 0x3c) != 0) {
          local_6c = FUN_45402ac2(&local_48,local_38);
          local_8._0_1_ = 0xe;
          piVar7 = FUN_45402ac2(&local_68,local_50);
          local_8._0_1_ = 0xf;
          piVar8 = FUN_45402ac2(&local_70,local_40);
          local_8._0_1_ = 0x10;
          FUN_4541336b(*(void **)((int)pvVar2 + 0x3c),piVar8,piVar7,local_6c);
          FUN_45402c5d(&local_70);
          FUN_45402c5d(&local_68);
          FUN_45402c5d(&local_48);
        }
        SysFreeString(local_40);
        SysFreeString(local_38);
        SysFreeString(local_50);
        pOVar9 = local_34;
        if (local_3c != (int *)0x0) {
          local_8._0_1_ = 9;
          (**(code **)(*local_3c + 8))(local_3c);
          pOVar9 = local_34;
        }
      }
      local_8._0_1_ = 6;
      VariantClear((VARIANTARG *)&local_60.n2);
    }
  }
  SysFreeString(local_44);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
  FUN_4542110c();
  return;
}


