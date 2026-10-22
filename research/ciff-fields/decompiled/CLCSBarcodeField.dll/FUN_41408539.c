// Source: CLCSBarcodeField.dll @ 41408539; FUN_41408539

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __cdecl FUN_41408539(undefined4 *param_1,undefined4 *param_2,void *param_3,char param_4)

{
  int *piVar1;
  void *pvVar2;
  bool bVar3;
  UINT UVar4;
  int iVar5;
  int iVar6;
  size_t sVar7;
  char *pcVar8;
  char ****ppppcVar9;
  int *piVar10;
  BSTR extraout_ECX;
  code *pcVar11;
  uint uVar12;
  BSTR pOVar13;
  int **ppiVar14;
  int *piStack_17c;
  BSTR *ppOStack_178;
  int *piStack_174;
  _union_2683 local_11c;
  VARIANTARG local_10c;
  VARIANTARG local_fc;
  VARIANTARG local_ec;
  VARIANTARG local_dc;
  VARIANTARG local_cc;
  BSTR local_bc;
  int local_b8;
  int local_b4;
  BSTR local_b0;
  int local_ac;
  int *local_a8;
  int *local_a4;
  int local_a0;
  int local_9c;
  BSTR local_98;
  BSTR local_94;
  int *local_90;
  int local_8c;
  int *local_88;
  BSTR local_84;
  int local_80;
  void *local_7c;
  BSTR local_78;
  BSTR local_74;
  uint local_70;
  int *local_6c;
  int *local_68;
  BSTR local_64;
  int *local_60;
  int *local_5c;
  BSTR local_58;
  int *local_54;
  char local_4d;
  BSTR local_4c;
  char local_45;
  char ***local_44 [5];
  uint local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x11c;
  local_8 = 0x41408548;
  local_7c = param_3;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CBarcode::GenerateHumanReadable");
  local_8 = 0;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  local_90 = (int *)0x0;
  CoCreateInstance((IID *)&DAT_41480e2c,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_41480e7c,&local_90);
  local_5c = (int *)0x0;
  local_8._0_1_ = 3;
  (**(code **)(*(int *)*param_2 + 0x5c))();
  FUN_41460bf0((uint *)&local_ec,0,0x10);
  VariantInit(&local_ec);
  local_8._0_1_ = 4;
  (**(code **)(*local_5c + 0x24))();
  CComQIPtr<>(&local_a8,(undefined4 *)local_ec.n1._8_4_);
  local_98 = (BSTR)0x0;
  local_8._0_1_ = 6;
  (**(code **)(*(int *)*param_2 + 0x68))();
  local_45 = '\x01';
  local_4d = '\0';
  FUN_41402f15(&local_84,L"");
  local_8 = CONCAT31(local_8._1_3_,7);
  (**(code **)(*local_5c + 0x1c))();
  pcVar11 = VariantClear_exref;
  if ((0 < local_9c) && (local_8c = 0, 0 < local_9c)) {
    do {
      iVar6 = local_8c;
      FUN_41460bf0((uint *)&local_cc,0,0x10);
      VariantInit(&local_cc);
      local_b4 = iVar6 + 1;
      local_8._0_1_ = 8;
      (**(code **)(*local_5c + 0x24))();
      piStack_174 = (int *)0x414086b2;
      CComQIPtr<>(&local_54,(undefined4 *)local_cc.n1._8_4_);
      local_58 = (BSTR)0x0;
      local_4c = (BSTR)0x0;
      piStack_174 = local_54;
      local_8 = CONCAT31(local_8._1_3_,0xb);
      ppOStack_178 = (BSTR *)0x414086cb;
      (**(code **)(*local_54 + 0x58))();
      ppOStack_178 = &local_4c;
      piStack_17c = local_54;
      (**(code **)(*local_54 + 0x60))();
      pcVar11 = VariantClear_exref;
      if (iVar6 == 0) {
        if (local_58 != (BSTR)0x0) {
          FUN_41407deb(0x41480efc);
        }
        if (local_4c != (BSTR)0x0) {
          FUN_41407deb(0x41480f1c);
        }
      }
      if (((local_4d == '\0') && (UVar4 = SysStringLen(local_58), UVar4 != 0)) &&
         (iVar5 = _wcscmp(local_58,L"|"), iVar5 == 0)) {
        local_4d = '\x01';
LAB_4140875f:
        SysFreeString(local_4c);
        SysFreeString(local_58);
        local_8 = CONCAT31(local_8._1_3_,8);
        if (local_54 != (int *)0x0) {
          (**(code **)(*local_54 + 8))();
        }
      }
      else {
        if (param_4 != local_4d) goto LAB_4140875f;
        uVar12 = 0;
        local_a0 = 0;
        (**(code **)(*local_54 + 0x50))();
        if (local_a0 == 5) {
          local_74 = (BSTR)0x0;
          local_8._0_1_ = 0xc;
          (**(code **)(*local_54 + 0xe4))(local_54,&local_74);
          local_80 = 0;
          CComQIPtr<>(&local_60,piVar1);
          local_8 = CONCAT31(local_8._1_3_,0xd);
          (**(code **)(*local_60 + 0x1c))(local_60,&local_80);
          pcVar11 = VariantClear_exref;
          if (0 < local_80) {
            do {
              FUN_41460bf0((uint *)&local_fc,0,0x10);
              VariantInit(&local_fc);
              uVar12 = uVar12 + 1;
              local_8._0_1_ = 0xe;
              local_70 = uVar12;
              (**(code **)(*local_60 + 0x24))(local_60,uVar12,&local_fc);
              CComQIPtr<>(&local_a4,(undefined4 *)local_fc.n1._8_4_);
              FUN_41460bf0((uint *)&local_10c,0,0x10);
              VariantInit(&local_10c);
              local_8._0_1_ = 0x10;
              (**(code **)(*local_a4 + 0x30))(local_a4,local_74,&local_10c);
              CComQIPtr<>(&local_6c,(undefined4 *)local_10c.n1._8_4_);
              if (local_6c != (int *)0x0) {
                local_78 = (BSTR)0x0;
                local_8._0_1_ = 0x12;
                (**(code **)(*local_6c + 0x68))(local_6c,&local_78);
                bVar3 = FUN_41403356(&local_78,L"MergeField");
                if (bVar3) {
                  local_68 = (int *)0x0;
                  CoCreateInstance((IID *)&DAT_41480e1c,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_41480eb4,
                                   &local_68);
                  if (local_68 != (int *)0x0) {
                    CComQIPtr<>(&local_88,local_68);
                    if (local_88 != (int *)0x0) {
                      FUN_41460bf0((uint *)&local_dc,0,0x10);
                      VariantInit(&local_dc);
                      local_dc.n1._8_4_ = local_6c;
                      FUN_41460bf0((uint *)&local_11c,0,0x10);
                      VariantInit((VARIANTARG *)&local_11c.n2);
                      local_8._0_1_ = 0x16;
                      local_11c._8_4_ = local_60;
                      FUN_41402f15(&local_94,L"");
                      local_8._0_1_ = 0x17;
                      (**(code **)(*local_88 + 0x24))
                                (local_88,&local_dc,local_11c._0_4_,local_11c.decVal.Hi32,
                                 local_11c._8_4_,local_11c._12_4_,&local_94,0);
                      SysFreeString(local_94);
                      pcVar11 = VariantClear_exref;
                      VariantClear((VARIANTARG *)&local_11c.n2);
                      VariantClear(&local_dc);
                      local_64 = (BSTR)0x0;
                      local_8._0_1_ = 0x18;
                      (**(code **)(*local_6c + 0x98))(local_6c,&local_64);
                      (**(code **)(*local_54 + 0x5c))(local_54,local_64);
                      (**(code **)(*local_54 + 100))(local_54,local_64);
                      SysFreeString(local_64);
                      uVar12 = local_70;
                    }
                    local_8._0_1_ = 0x13;
                    if (local_88 != (int *)0x0) {
                      (**(code **)(*local_88 + 8))(local_88);
                    }
                  }
                  local_8._0_1_ = 0x12;
                  if (local_68 != (int *)0x0) {
                    (**(code **)(*local_68 + 8))(local_68);
                  }
                }
                SysFreeString(local_78);
              }
              local_8._0_1_ = 0x10;
              if (local_6c != (int *)0x0) {
                (**(code **)(*local_6c + 8))(local_6c);
              }
              (*pcVar11)(&local_10c);
              local_8 = CONCAT31(local_8._1_3_,0xe);
              if (local_a4 != (int *)0x0) {
                (**(code **)(*local_a4 + 8))(local_a4);
              }
              (*pcVar11)(&local_fc);
              iVar6 = local_8c;
            } while ((int)uVar12 < local_80);
          }
          local_8._0_1_ = 0xc;
          if (local_60 != (int *)0x0) {
            (**(code **)(*local_60 + 8))(local_60);
          }
          local_8 = CONCAT31(local_8._1_3_,0xb);
          SysFreeString(local_74);
        }
        (**(code **)(*local_54 + 0x58))(local_54,&local_58);
        (**(code **)(*local_54 + 0x60))(local_54,&local_4c);
        if (iVar6 == 0) {
          if (local_58 != (BSTR)0x0) {
            FUN_41407deb(0x41480efc);
          }
          if (local_4c != (BSTR)0x0) {
            FUN_41407deb(0x41480f1c);
          }
        }
        UVar4 = SysStringLen(local_4c);
        if ((UVar4 == 0) && (UVar4 = SysStringLen(local_58), UVar4 != 0)) {
          FUN_41403290(&local_4c,(int *)&local_58);
        }
        (**(code **)(*local_54 + 0x50))(local_54,&local_ac);
        (**(code **)(*local_54 + 0x28))(local_54,&local_b8);
        if ((local_ac == 0) && (local_b8 == 0)) {
          UVar4 = SysStringLen(local_4c);
          if ((UVar4 == 0) || (iVar6 = _wcscmp(local_4c,L"æ"), iVar6 == 0)) {
            FUN_41407deb(0x41480f98);
          }
          else {
            FUN_41407deb(0x41480f6c);
            if (local_45 != '\0') {
              sVar7 = _wcslen(L"(");
              pvVar2 = local_7c;
              FUN_4140975b(local_7c,(undefined8 *)&DAT_41480f84,sVar7);
              UVar4 = SysStringLen(local_4c);
              if (UVar4 == 1) {
                sVar7 = _wcslen(L"0");
                FUN_4140975b(pvVar2,(undefined8 *)&DAT_41480f88,sVar7);
              }
            }
            bVar3 = FUN_41403356(&local_84,L"00");
            if ((bVar3) && (UVar4 = SysStringLen(local_4c), UVar4 == 0x11)) {
              local_70 = FUN_41408342((int *)&local_4c);
              pOVar13 = local_4c;
              local_70 = local_70 & 0xffff;
              if (local_4c == (wchar_t *)0x0) {
LAB_41408c07:
                pcVar8 = (char *)0x0;
              }
              else {
                sVar7 = _wcslen(local_4c);
                if (0x3fffffff < (int)(sVar7 + 1)) goto LAB_41408c07;
                pcVar8 = AtlW2AHelper((char *)&piStack_17c,pOVar13,(sVar7 + 1) * 2,3);
              }
              std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
              basic_string<char,std::char_traits<char>,std::allocator<char>_>
                        ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_44
                         ,pcVar8);
              local_8._0_1_ = 0x19;
              FUN_4140962d(local_44,1,(byte)local_70);
              ppppcVar9 = local_44;
              if (0xf < local_30) {
                ppppcVar9 = (char ****)local_44[0];
              }
              piVar10 = FUN_41407be2(&local_b0,(char *)ppppcVar9);
              FUN_41407c9d(&local_4c,piVar10);
              SysFreeString(local_b0);
              local_8 = CONCAT31(local_8._1_3_,0xb);
              std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
                        ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_44
                         ,true,0);
            }
            pvVar2 = local_7c;
            FUN_41409734(local_7c,local_4c);
            bVar3 = false;
            if (local_45 == '\x01') {
              sVar7 = _wcslen(L")");
              FUN_4140975b(pvVar2,(undefined8 *)&DAT_41480f94,sVar7);
              FUN_41403290(&local_84,(int *)&local_4c);
              bVar3 = local_45 == '\x01';
            }
            local_45 = !bVar3;
          }
        }
        else {
          ppiVar14 = &local_54;
          pOVar13 = extraout_ECX;
          FUN_41402eab(&stack0xfffffe7c,(int *)&local_4c);
          piVar10 = FUN_414094bc(&local_bc,pOVar13,(OLECHAR *)ppiVar14);
          FUN_41407c9d(&local_4c,piVar10);
          SysFreeString(local_bc);
          if ((local_4c != (BSTR)0x0) && (UVar4 = SysStringLen(local_4c), UVar4 != 0)) {
            basic_string<>(local_44,local_4c);
            local_8 = CONCAT31(local_8._1_3_,0x1a);
            FUN_4140968e(local_7c,local_44,0,0xffffffff);
            FUN_414062a0(local_44,'\x01',0);
          }
          local_45 = local_45 == '\0';
        }
        SysFreeString(local_4c);
        SysFreeString(local_58);
        local_8 = CONCAT31(local_8._1_3_,8);
        pcVar11 = VariantClear_exref;
        if (local_54 != (int *)0x0) {
          (**(code **)(*local_54 + 8))();
          pcVar11 = VariantClear_exref;
        }
      }
      (*pcVar11)();
      local_8c = local_b4;
    } while (local_b4 < local_9c);
  }
  SysFreeString(local_84);
  SysFreeString(local_98);
  local_8._0_1_ = 4;
  if (local_a8 != (int *)0x0) {
    (**(code **)(*local_a8 + 8))();
  }
  (*pcVar11)();
  local_8._0_1_ = 2;
  if (local_5c != (int *)0x0) {
    (**(code **)(*local_5c + 8))();
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_90 != (int *)0x0) {
    (**(code **)(*local_90 + 8))();
  }
  (*pcVar11)();
  piStack_174 = (int *)0x41408dea;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_41461ee2();
  return;
}


