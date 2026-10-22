// Source: CLCiffConversion_Layout.dll @ 4541bb08; FUN_4541bb08

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_4541bb08(void *this,int *param_1,int *param_2)

{
  int *piVar1;
  BSTR pOVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  int *piVar9;
  float10 fVar10;
  float fVar11;
  int *piVar12;
  BSTR pOVar13;
  VARIANTARG local_90;
  _union_2683 local_80;
  int *local_70;
  BSTR local_6c;
  BSTR local_68;
  int *local_64;
  int *local_60;
  int *local_5c;
  BSTR local_58;
  int *local_54;
  int local_50;
  uint local_4c;
  undefined4 local_48;
  int local_44;
  int *local_40;
  int local_3c;
  int local_38;
  int local_34;
  BSTR local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x88;
  local_8 = 0x4541bb17;
  local_5c = param_2;
  local_70 = this;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFFontConvert::FindClosestFont");
  local_8 = 0;
  FUN_4541cdb6(param_2,&local_6c);
  local_8._0_1_ = 1;
  iVar5 = FUN_4541cded((int)param_2);
  iVar6 = FUN_4541d01d((int)param_2);
  local_4c = CONCAT31(local_4c._1_3_,1);
  if (*(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x40 + (int)this) == 0) {
    FUN_4540303d(0x45449c24);
    goto LAB_4541c10b;
  }
  FUN_45429f70((uint *)&local_90,0,0x10);
  VariantInit(&local_90);
  local_8._0_1_ = 2;
  (**(code **)(**(int **)(*(int *)(*(int *)((int)this + 4) + 4) + 0x40 + (int)this) + 0x474))();
  CComQIPtr<>(&local_64,(undefined4 *)local_90.n1._8_4_);
  if (local_64 != (int *)0x0) {
    FUN_45429f70((uint *)&local_80,0,0x10);
    VariantInit((VARIANTARG *)&local_80.n2);
    local_8._0_1_ = 4;
    (**(code **)(*local_64 + 0x30))();
    local_68 = (BSTR)0x0;
    local_8._0_1_ = 5;
    if (local_80.n2.vt != 0) {
      CComQIPtr<>(&local_40,(undefined4 *)local_80._8_4_);
      local_8._0_1_ = 6;
      if (local_40 != (int *)0x0) {
        (**(code **)(*local_40 + 0x9c))();
        bVar3 = FUN_45402d4b(&local_68,L"TrueType");
        local_4c = local_4c & 0xff;
        if (bVar3) {
          local_4c = 0;
        }
      }
      local_8._0_1_ = 5;
      if (local_40 != (int *)0x0) {
        (**(code **)(*local_40 + 8))();
      }
    }
    local_38 = 0;
    local_34 = 0;
    if ((char)local_4c == '\0') {
      if (iVar6 == 0) {
        local_38 = iVar5;
        fVar10 = FUN_4541c720((undefined4 *)
                              ((int)this + *(int *)(*(int *)((int)this + 4) + 4) + 0x60));
        local_30 = (BSTR)(float)fVar10;
        fVar11 = (((float)local_30 * _DAT_4544a734) / _DAT_4544a72c) * (float)iVar5;
LAB_4541bd69:
        local_34 = (int)fVar11;
      }
      else if (iVar6 == 1) {
LAB_4541bcd1:
        local_34 = iVar5;
        fVar10 = FUN_4541c720((undefined4 *)
                              ((int)this + *(int *)(*(int *)((int)this + 4) + 4) + 0x60));
        local_30 = (BSTR)(float)fVar10;
        local_38 = (int)((float)iVar5 / (((float)local_30 * _DAT_4544a734) / _DAT_4544a72c) +
                        DAT_45447488);
      }
    }
    else if ((char)local_4c == '\x01') {
      if (iVar6 == 1) goto LAB_4541bcd1;
      if (iVar6 == 0) {
        local_38 = iVar5;
        fVar10 = FUN_4541c720((undefined4 *)
                              ((int)this + *(int *)(*(int *)((int)this + 4) + 4) + 0x60));
        local_30 = (BSTR)(float)fVar10;
        fVar11 = (((float)local_30 * _DAT_4544a734) / _DAT_4544a72c) * _DAT_4544a728;
        goto LAB_4541bd69;
      }
    }
    FUN_4540303d(0x45449c5c);
    local_40 = (int *)0x0;
    piVar8 = *(int **)*param_1;
    if (piVar8 == (int *)*param_1) {
LAB_4541c0bd:
      FUN_4540303d(0x45449d08);
    }
    else {
      do {
        piVar1 = local_40;
        local_54 = (int *)piVar8[2];
        FUN_454028b9(&local_58,"");
        local_50 = 0;
        local_44 = 0;
        local_8 = CONCAT31(local_8._1_3_,7);
        if (piVar1 != (int *)0x0) {
          bVar3 = FUN_4541e8f1(piVar1);
          if (bVar3) {
            local_44 = FUN_4541d9ab(piVar1);
            fVar10 = FUN_4541c720((undefined4 *)
                                  ((int)this + *(int *)(*(int *)((int)this + 4) + 4) + 0x60));
            local_30 = (BSTR)(float)fVar10;
            local_50 = (int)((float)local_34 / (((float)local_30 * _DAT_4544a734) / _DAT_4544a72c) +
                            DAT_45447488);
          }
          else {
            iVar5 = FUN_4541d658(piVar1,local_38);
            local_50 = iVar5;
            fVar10 = FUN_4541c720((undefined4 *)
                                  ((int)this + *(int *)(*(int *)((int)this + 4) + 4) + 0x60));
            local_30 = (BSTR)(float)fVar10;
            local_44 = (int)((((float)local_30 * _DAT_4544a734) / _DAT_4544a72c) * (float)iVar5);
          }
        }
        iVar5 = local_34;
        piVar1 = local_54;
        local_3c = FUN_4541d9ab(local_54);
        bVar3 = FUN_4541e8f1(piVar1);
        if (bVar3) {
          FUN_4540303d(0x45449c9c);
          local_3c = FUN_4541d513(piVar1,iVar5);
        }
        else {
          FUN_4540303d(0x45449cd0);
        }
        FUN_4540303d(0x45449cec);
        piVar1 = (int *)*piVar1;
        local_60 = piVar1;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 4))();
        }
        local_30 = (BSTR)0x0;
        local_8._0_1_ = 9;
        FUN_4541a358(&local_60,(int *)&local_30);
        FUN_45402881(&local_48);
        pOVar2 = local_30;
        local_8._0_1_ = 10;
        pOVar13 = local_30;
        if (local_30 != (BSTR)0x0) {
          (**(code **)(*(int *)local_30 + 4))();
        }
        local_8._0_1_ = 0xb;
        piVar9 = local_70;
        piVar12 = local_70;
        (**(code **)*local_70)(&stack0xffffff4c,local_5c);
        local_8._0_1_ = 10;
        cVar4 = FUN_45403c0e(piVar9,piVar12,(int *)pOVar13);
        if (cVar4 != '\0') {
          bVar3 = FUN_4541e8f1(local_54);
          iVar5 = local_38;
          if (bVar3) {
            local_50 = local_44;
            iVar5 = local_34;
          }
          local_44 = iVar5;
          iVar5 = FUN_45416187(local_50,local_3c,iVar5);
          if (iVar5 == 0) {
            iVar5 = local_3c;
          }
          local_3c = iVar5;
          if ((((char)local_4c == '\x01') && (iVar5 == local_44)) &&
             (bVar3 = FUN_4541e8f1(local_54), piVar9 = local_54, !bVar3)) {
            local_8._0_1_ = 9;
            FUN_45402c42(&local_48);
            local_8._0_1_ = 8;
            if (pOVar2 != (BSTR)0x0) {
              (**(code **)(*(int *)pOVar2 + 8))();
            }
            local_8._0_1_ = 7;
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 8))();
            }
            local_8._0_1_ = 5;
            SysFreeString(local_58);
            break;
          }
          if (local_3c != local_50) {
            local_40 = local_54;
          }
        }
        local_8._0_1_ = 9;
        FUN_45402c42(&local_48);
        local_8._0_1_ = 8;
        if (pOVar2 != (BSTR)0x0) {
          (**(code **)(*(int *)pOVar2 + 8))();
        }
        local_8._0_1_ = 7;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))();
        }
        local_8._0_1_ = 5;
        SysFreeString(local_58);
        piVar8 = (int *)*piVar8;
        piVar9 = local_40;
        this = local_70;
      } while (piVar8 != (int *)*param_1);
      if (piVar9 == (int *)0x0) goto LAB_4541c0bd;
      bVar3 = FUN_4541e8f1(piVar9);
      if (bVar3) {
        local_34 = FUN_4541d513(piVar9,local_34);
        (**(code **)(*local_5c + 4))();
      }
      FUN_454214b0(local_5c,piVar9,local_34);
      puVar7 = FUN_4541db3e(piVar9,&local_30);
      local_8._0_1_ = 0xc;
      FUN_45402ac2(&local_60,(wchar_t *)*puVar7);
      local_8._0_1_ = 0xd;
      FUN_4540303d(0x45449d2c);
      FUN_45402c5d((int *)&local_60);
      SysFreeString(local_30);
    }
    SysFreeString(local_68);
    VariantClear((VARIANTARG *)&local_80.n2);
  }
  local_8._0_1_ = 2;
  if (local_64 != (int *)0x0) {
    (**(code **)(*local_64 + 8))();
  }
  VariantClear(&local_90);
LAB_4541c10b:
  SysFreeString(local_6c);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


