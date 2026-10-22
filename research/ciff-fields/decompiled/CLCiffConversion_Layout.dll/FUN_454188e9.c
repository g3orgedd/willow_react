// Source: CLCiffConversion_Layout.dll @ 454188e9; FUN_454188e9

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_454188e9(void *this,void *param_1)

{
  int *piVar1;
  void *pvVar2;
  BSTR pOVar3;
  undefined4 *puVar4;
  HRESULT HVar5;
  int iVar6;
  VARIANTARG local_90;
  _union_2683 local_80;
  BSTR local_70;
  int *local_6c;
  void *local_68;
  _union_2683 local_64;
  int *local_54;
  void *local_50;
  undefined4 local_4c;
  int local_48;
  int local_44;
  void *local_40;
  int *local_3c;
  BSTR local_38;
  int *local_34;
  BSTR local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x80;
  local_8 = 0x454188f8;
  local_68 = param_1;
  local_40 = this;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCiffPriceVerifierBarcodes::Convert");
  local_8 = 0;
  FUN_4540303d(0x454491ec);
  local_4c = 0;
  local_50 = (void *)FUN_454043b0((int *)0x0,(int *)0x0);
  local_8._0_1_ = 1;
  FUN_45404ce5((void *)((int)this + 0x60),(int *)((int)param_1 + 4));
  puVar4 = FUN_4541cbbe(param_1,&local_30);
  local_8._0_1_ = 2;
  FUN_45407800((void *)((int)this + 100),(wchar_t *)*puVar4);
  local_8._0_1_ = 1;
  SysFreeString(local_30);
  FUN_4540303d(0x4544a270);
  (**(code **)(**(int **)((int)param_1 + 4) + 100))(*(int **)((int)param_1 + 4),&local_30);
  if (local_30 == (BSTR)0x1) {
    CComQIPtr<>(&local_6c,*(undefined4 **)((int)this + 0x60));
    local_48 = 0;
    local_3c = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,4);
    HVar5 = CoCreateInstance((IID *)&DAT_45447d6c,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_454496b0,&local_3c
                            );
    piVar1 = local_3c;
    if (-1 < HVar5) {
      if (local_3c != (int *)0x0) {
        local_64.n2.vt = 9;
        local_64._8_4_ = *(int *)((int)local_40 + 0x60);
        if ((int *)local_64._8_4_ != (int *)0x0) {
          (**(code **)(*(int *)local_64._8_4_ + 4))(local_64._8_4_);
        }
        local_8._0_1_ = 5;
        HVar5 = (**(code **)(*piVar1 + 0xd0))(piVar1,&local_64,&local_48);
        local_8 = CONCAT31(local_8._1_3_,4);
        VariantClear((VARIANTARG *)&local_64.n2);
      }
      pvVar2 = local_40;
      if (((-1 < HVar5) && (local_48 == 1)) && (*(int *)((int)local_40 + 0x38) != 0)) {
        FUN_45429f70((uint *)&local_80,0,0x10);
        VariantInit((VARIANTARG *)&local_80.n2);
        local_8._0_1_ = 6;
        (**(code **)(**(int **)((int)pvVar2 + 0x38) + 0x480))
                  (*(int **)((int)pvVar2 + 0x38),&local_80);
        if (local_80.n2.vt != 0) {
          CComQIPtr<>(&local_30,(undefined4 *)local_80._8_4_);
          FUN_45429f70((uint *)&local_64,0,0x10);
          VariantInit((VARIANTARG *)&local_64.n2);
          pOVar3 = local_30;
          local_8._0_1_ = 8;
          puVar4 = FUN_454028ee(&local_38,L"EAN13PriceVerifier");
          local_8._0_1_ = 9;
          (**(code **)(*(int *)pOVar3 + 0x30))(pOVar3,*puVar4,&local_64);
          local_8._0_1_ = 8;
          SysFreeString(local_38);
          pvVar2 = local_68;
          if (local_64.n2.vt == 0) {
            FUN_4541c774(local_68,&local_38);
            local_8._0_1_ = 10;
            FUN_4541d3cd(pvVar2,&local_70);
            local_34 = (int *)0x0;
            piVar1 = *(int **)((int)pvVar2 + 4);
            local_8 = CONCAT31(local_8._1_3_,0xc);
            (**(code **)(*piVar1 + 0x5c))(piVar1,&local_34);
            if (local_34 != (int *)0x0) {
              local_44 = -1;
              (**(code **)(*local_34 + 0x1c))(local_34,&local_44);
              if (1 < local_44) {
                iVar6 = 0;
                if (0 < local_44) {
                  do {
                    (**(code **)(*local_34 + 0x2c))(local_34,(local_44 - iVar6) + -1);
                    iVar6 = iVar6 + 1;
                  } while (iVar6 < local_44);
                }
                FUN_45429f70((uint *)&local_90,0,0x10);
                VariantInit(&local_90);
                local_8._0_1_ = 0xd;
                (**(code **)(*local_34 + 0x28))(local_34,0,0,1,0,&local_90);
                CComQIPtr<>(&local_54,(undefined4 *)local_90.n1._8_4_);
                local_8._0_1_ = 0xe;
                if (local_54 != (int *)0x0) {
                  (**(code **)(*local_54 + 0x5c))(local_54,local_38);
                }
                local_8 = CONCAT31(local_8._1_3_,0xd);
                if (local_54 != (int *)0x0) {
                  (**(code **)(*local_54 + 8))(local_54);
                }
                VariantClear(&local_90);
              }
            }
            local_8._0_1_ = 0xb;
            if (local_34 != (int *)0x0) {
              (**(code **)(*local_34 + 8))(local_34);
            }
            SysFreeString(local_70);
            SysFreeString(local_38);
          }
          VariantClear((VARIANTARG *)&local_64.n2);
          local_8._0_1_ = 6;
          if (local_30 != (BSTR)0x0) {
            (**(code **)(*(int *)local_30 + 8))(local_30);
          }
        }
        local_8 = CONCAT31(local_8._1_3_,4);
        VariantClear((VARIANTARG *)&local_80.n2);
      }
    }
    pvVar2 = local_40;
    FUN_454120f3((int *)&local_50);
    piVar1 = *(int **)((int)pvVar2 + 0x60);
    if ((piVar1 != (int *)0x0) && (*(undefined4 *)((int)pvVar2 + 0x60) = 0, piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    local_8._0_1_ = 3;
    if (local_3c != (int *)0x0) {
      (**(code **)(*local_3c + 8))(local_3c);
    }
    local_8._0_1_ = 1;
    if (local_6c != (int *)0x0) {
      (**(code **)(*local_6c + 8))(local_6c);
    }
  }
  FUN_454224ff((int *)&local_50);
  FID_conflict__free(local_50);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


