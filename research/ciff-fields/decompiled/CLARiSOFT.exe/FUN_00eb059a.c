// Source: CLARiSOFT.exe @ 00eb059a; FUN_00eb059a

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00eb059a(BSTR param_1,int *param_2,int *param_3,undefined1 *param_4)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 uVar3;
  char cVar4;
  bool bVar5;
  undefined1 *puVar6;
  CComBSTR *pCVar7;
  undefined4 uVar8;
  int *piVar9;
  UINT UVar10;
  UINT UVar11;
  HRESULT HVar12;
  BSTR pOVar13;
  uint uVar14;
  BSTR pOVar15;
  BSTR pOVar16;
  int iVar17;
  wchar_t *pwVar18;
  _union_2683 local_c0;
  undefined1 local_b0 [8];
  BSTR local_a8;
  BSTR local_a4;
  BSTR local_a0;
  VARIANTARG local_9c;
  int local_8c;
  int local_88;
  _union_2683 local_84;
  _union_2683 local_74;
  int *local_64;
  undefined1 *local_60;
  int *local_5c;
  BSTR local_58;
  int *local_54;
  uint local_50;
  BSTR local_4c;
  undefined1 *local_48;
  BSTR local_44;
  char local_3d;
  int local_3c;
  BSTR local_38;
  BSTR local_34;
  BSTR local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  int local_8;
  undefined4 uStack_4;
  
  puVar1 = param_4;
  uStack_4 = 0xb0;
  local_4c = param_1;
  local_60 = param_4;
  local_8 = 1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCiffChecker::CheckBarcodeField");
  local_8 = CONCAT31(local_8._1_3_,2);
  puVar6 = (undefined1 *)FUN_00eca369(8);
  if (puVar6 == (undefined1 *)0x0) {
    puVar6 = (undefined1 *)0x0;
    local_48 = (undefined1 *)0x0;
  }
  else {
    *(undefined4 *)(puVar6 + 4) = 0;
    local_48 = puVar6;
    FUN_00e11de5(puVar6 + 4,(int *)&param_2);
    *puVar6 = 1;
  }
  cVar4 = FUN_00eafdba((int)puVar6);
  if (cVar4 == '\0') {
    pCVar7 = (CComBSTR *)FUN_00e616d4(param_1,&local_58);
    local_8._0_1_ = 3;
    iVar17 = 5;
LAB_00eb063e:
    piVar9 = FUN_00e4cac1(*(void **)(local_3c + 0xc),iVar17);
    FUN_00eafbc7(*(void **)(local_3c + 0x10),pCVar7,piVar9);
    SysFreeString(local_58);
    if (puVar1 != (undefined1 *)0x0) {
      *puVar1 = 0;
    }
    goto LAB_00eb102b;
  }
  uVar8 = FUN_00eb5a00((int)param_1);
  cVar4 = FUN_00eafd69(puVar6,uVar8);
  if (cVar4 == '\0') {
    pCVar7 = (CComBSTR *)FUN_00e616d4(param_1,&local_58);
    local_8._0_1_ = 4;
    iVar17 = 0x51;
    goto LAB_00eb063e;
  }
  local_30 = (BSTR)0x0;
  local_50 = 0xffffffff;
  local_8._0_1_ = 5;
  local_58 = (BSTR)FUN_00eb5712((int)param_1);
  switch(local_58) {
  case (BSTR)0x0:
    FUN_00e03e2c(&local_30,L"ITF");
    local_50 = 0;
    goto LAB_00eb0754;
  case (BSTR)0x1:
    pwVar18 = L"Code128";
    break;
  case (BSTR)0x2:
    pwVar18 = L"EAN128";
    break;
  case (BSTR)0x3:
    pwVar18 = L"Code39";
    break;
  case (BSTR)0x4:
    pwVar18 = L"EAN8";
    goto LAB_00eb0697;
  case (BSTR)0x5:
    FUN_00e03e2c(&local_30,L"EAN13");
    local_54 = (int *)0x0;
    local_34 = (BSTR)0x0;
    local_8 = CONCAT31(local_8._1_3_,6);
    HVar12 = CoCreateInstance((IID *)&DAT_00efdad8,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00efdb24,
                              &local_34);
    pOVar15 = local_34;
    if ((-1 < HVar12) && (local_34 != (BSTR)0x0)) {
      local_84._8_4_ = *(undefined4 *)(param_1 + 2);
      local_84.n2.vt = 9;
      if ((int *)local_84._8_4_ != (int *)0x0) {
        (**(code **)(*(int *)local_84._8_4_ + 4))();
      }
      local_8._0_1_ = 7;
      iVar17 = (**(code **)(*(int *)pOVar15 + 0xd0))();
      local_8 = CONCAT31(local_8._1_3_,6);
      VariantClear((VARIANTARG *)&local_84.n2);
      if ((-1 < iVar17) && (local_54 == (int *)0x1)) {
        FUN_00e03e2c(&local_30,L"EAN13PriceVerifier");
      }
    }
    local_50 = 0xd;
    local_8._0_1_ = 5;
    puVar6 = local_48;
    if (local_34 != (BSTR)0x0) {
      (**(code **)(*(int *)local_34 + 8))();
      puVar6 = local_48;
    }
    goto LAB_00eb0754;
  case (BSTR)0x6:
    FUN_00e03e2c(&local_30,L"UPCA");
    local_50 = 0xc;
    goto LAB_00eb0754;
  case (BSTR)0x7:
    pwVar18 = L"UPCE";
LAB_00eb0697:
    FUN_00e03e2c(&local_30,pwVar18);
    local_50 = 8;
    goto LAB_00eb0754;
  case (BSTR)0x8:
    FUN_00e03e2c(&local_30,L"SUP2");
    local_50 = 2;
    goto LAB_00eb0754;
  case (BSTR)0x9:
    FUN_00e03e2c(&local_30,L"SUP5");
    local_50 = 5;
    goto LAB_00eb0754;
  case (BSTR)0xa:
  case (BSTR)0xb:
  case (BSTR)0xc:
  case (BSTR)0xd:
  case (BSTR)0xe:
  case (BSTR)0x13:
  case (BSTR)0x14:
    pwVar18 = L"RSS14";
    break;
  case (BSTR)0xf:
    pwVar18 = L"DataMatrix";
    break;
  case (BSTR)0x10:
    pwVar18 = L"PDF417";
    break;
  case (BSTR)0x11:
    pwVar18 = L"MicroPDF417";
    break;
  case (BSTR)0x12:
    pwVar18 = L"QR";
    break;
  default:
    pwVar18 = L"Unknown";
  }
  FUN_00e03e2c(&local_30,pwVar18);
LAB_00eb0754:
  bVar5 = FUN_00e03edc(&local_30,L"EAN13PriceVerifier");
  if (!bVar5) {
    bVar5 = FUN_00eb74d6(puVar6,&local_30);
    if (bVar5) {
      FUN_00e03b51((uint *)&local_84);
      local_8._0_1_ = 9;
      (**(code **)(*param_2 + 0x480))();
      if (local_84.n2.vt != 0) {
        CComQIPtr<>(&local_5c,(undefined4 *)local_84._8_4_);
        FUN_00e03b51((uint *)&local_74);
        local_8._0_1_ = 0xb;
        (**(code **)(*local_5c + 0x30))();
        if (local_74.n2.vt != 0) {
          local_34 = (BSTR)0x0;
          CComQIPtr<>(&local_54,(undefined4 *)local_74._8_4_);
          local_8 = CONCAT31(local_8._1_3_,0xc);
          (**(code **)(*local_54 + 0x84))();
          iVar17 = FUN_00eb5a1c((int)param_1);
          if (local_34 != (BSTR)0xffffffff) {
            (**(code **)(*param_3 + 0x54))();
            if (local_44 == (BSTR)0x1) {
              (**(code **)(*param_2 + 0x2c))();
              local_34 = (BSTR)(int)((double)((float)(int)local_34 * (float)local_38) + DAT_00f02b08
                                    );
            }
            local_34 = local_34 + 0x32;
            if ((int)local_34 < iVar17) {
              FUN_00e3c14c(0xf06c8c);
              pCVar7 = (CComBSTR *)FUN_00e616d4(param_1,&local_38);
              local_8 = CONCAT31(local_8._1_3_,0xd);
              piVar9 = FUN_00e4cac1(*(void **)(local_3c + 0xc),0x68);
              FUN_00eafbc7(*(void **)(local_3c + 0x10),pCVar7,piVar9);
              SysFreeString(local_38);
              if (puVar1 != (undefined1 *)0x0) {
                *puVar1 = 0;
              }
            }
          }
          local_8._0_1_ = 0xb;
          puVar6 = local_48;
          if (local_54 != (int *)0x0) {
            (**(code **)(*local_54 + 8))();
            puVar6 = local_48;
          }
        }
        VariantClear((VARIANTARG *)&local_74.n2);
        local_8._0_1_ = 9;
        if (local_5c != (int *)0x0) {
          (**(code **)(*local_5c + 8))();
        }
      }
      bVar5 = FUN_00eb5fe4((int)param_1);
      if (((bVar5) && (cVar4 = FUN_00eb69f7(puVar6,(BSTR)&local_30), cVar4 == '\0')) &&
         (bVar5 = FUN_00e03edc(&local_30,L"EAN13PriceVerifier"), !bVar5)) {
        pCVar7 = (CComBSTR *)FUN_00e616d4(param_1,&local_44);
        local_8._0_1_ = 0xe;
        piVar9 = FUN_00e4cac1(*(void **)(local_3c + 0xc),0x61);
        FUN_00eafbc7(*(void **)(local_3c + 0x10),pCVar7,piVar9);
        local_8._0_1_ = 9;
        SysFreeString(local_44);
        if (puVar1 != (undefined1 *)0x0) {
          *puVar1 = 0;
        }
      }
      bVar5 = FUN_00eb572d((int)param_1);
      puVar6 = local_48;
      if ((bVar5) && (cVar4 = FUN_00eaff8c(local_48,(BSTR)&local_30), cVar4 == '\0')) {
        pCVar7 = (CComBSTR *)FUN_00e616d4(param_1,&local_44);
        local_8._0_1_ = 0xf;
        piVar9 = FUN_00e4cac1(*(void **)(local_3c + 0xc),0x62);
        FUN_00eafbc7(*(void **)(local_3c + 0x10),pCVar7,piVar9);
        local_8._0_1_ = 9;
        SysFreeString(local_44);
        puVar6 = local_48;
        if (puVar1 != (undefined1 *)0x0) {
          *puVar1 = 0;
        }
      }
      bVar5 = FUN_00eb5750((int)param_1);
      if ((bVar5) && (cVar4 = FUN_00eb00a2(puVar6,(BSTR)&local_30), cVar4 == '\0')) {
        pCVar7 = (CComBSTR *)FUN_00e616d4(param_1,&local_44);
        local_8._0_1_ = 0x10;
        piVar9 = FUN_00e4cac1(*(void **)(local_3c + 0xc),99);
        FUN_00eafbc7(*(void **)(local_3c + 0x10),pCVar7,piVar9);
        local_8._0_1_ = 9;
        SysFreeString(local_44);
        if (puVar1 != (undefined1 *)0x0) {
          *puVar1 = 0;
        }
      }
      bVar5 = FUN_00eb5fc1((int)param_1);
      if ((bVar5) && (cVar4 = FUN_00eb68e1(local_48,(BSTR)&local_30), cVar4 == '\0')) {
        pCVar7 = (CComBSTR *)FUN_00e616d4(param_1,&local_44);
        local_8._0_1_ = 0x11;
        piVar9 = FUN_00e4cac1(*(void **)(local_3c + 0xc),100);
        FUN_00eafbc7(*(void **)(local_3c + 0x10),pCVar7,piVar9);
        SysFreeString(local_44);
        if (puVar1 != (undefined1 *)0x0) {
          *puVar1 = 0;
        }
      }
      if (local_50 != 0xffffffff) {
        local_5c = (int *)0x0;
        local_8 = CONCAT31(local_8._1_3_,0x12);
        (**(code **)(**(int **)(param_1 + 2) + 0x5c))();
        (**(code **)(*local_5c + 0x1c))();
        if ((0 < (int)local_44) && (piVar9 = (int *)0x0, 0 < (int)local_44)) {
          do {
            FUN_00e03b51((uint *)&local_9c);
            local_8._0_1_ = 0x13;
            local_64 = (int *)((int)piVar9 + 1);
            (**(code **)(*local_5c + 0x24))(local_5c);
            CComQIPtr<>(&local_54,(undefined4 *)local_9c.n1._8_4_);
            local_8 = CONCAT31(local_8._1_3_,0x14);
            (**(code **)(*local_54 + 0x50))(local_54,&local_8c);
            piVar9 = (int *)((int)piVar9 + 1);
            if (local_8c != 6) {
              local_c0.n2.vt = 9;
              local_c0._8_4_ = local_54;
              if (local_54 != (int *)0x0) {
                (**(code **)(*local_54 + 4))();
              }
              local_34 = (BSTR)0x0;
              local_8 = CONCAT31(local_8._1_3_,0x16);
              CoCreateInstance((IID *)&DAT_00efdad8,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00f00bfc,
                               &local_34);
              local_74.n2.vt = 9;
              local_74._8_4_ = param_3;
              if (param_3 != (int *)0x0) {
                (**(code **)(*param_3 + 4))();
              }
              local_8._0_1_ = 0x17;
              (**(code **)(*(int *)local_34 + 0x1c))
                        (local_34,&local_c0,local_74._0_4_,local_74.decVal.Hi32);
              VariantClear((VARIANTARG *)&local_74.n2);
              local_8 = CONCAT31(local_8._1_3_,0x15);
              if (local_34 != (BSTR)0x0) {
                (**(code **)(*(int *)local_34 + 8))();
              }
              VariantClear((VARIANTARG *)&local_c0.n2);
              piVar9 = local_64;
            }
            local_8._0_1_ = 0x13;
            if (local_54 != (int *)0x0) {
              (**(code **)(*local_54 + 8))();
            }
            local_8 = CONCAT31(local_8._1_3_,0x12);
            VariantClear(&local_9c);
            param_1 = local_4c;
          } while ((int)piVar9 < (int)local_44);
        }
        FUN_00eb5773(param_1,&local_38);
        local_8._0_1_ = 0x18;
        local_3d = FUN_00eb57aa((int)param_1);
        pOVar16 = (BSTR)0xffffffff;
        pOVar13 = (BSTR)(uint)(byte)local_3d;
        uVar14 = local_50 - (int)pOVar13;
        FUN_00e03ab8(&stack0xffffff18,(int *)&local_38);
        pOVar15 = local_58;
        FUN_00eaf886(local_b0,(int)local_58,pOVar13,pOVar16);
        local_8._0_1_ = 0x19;
        FUN_00eafcf2(local_b0,&local_34);
        local_8._0_1_ = 0x1a;
        uVar3 = (undefined1)local_8;
        local_8._0_1_ = 0x1a;
        if (pOVar15 == (BSTR)0x0) {
          if (local_3d == '\0') {
            FUN_00e01fd0(&local_34,(int *)&local_38);
          }
          pOVar15 = local_34;
          UVar10 = SysStringLen(local_34);
          if ((UVar10 & 1) != 0) {
            pCVar7 = (CComBSTR *)FUN_00e616d4(param_1,&local_4c);
            local_8._0_1_ = 0x1b;
            piVar9 = FUN_00e4cac1(*(void **)(local_3c + 0xc),0x65);
            FUN_00eafbc7(*(void **)(local_3c + 0x10),pCVar7,piVar9);
            local_8._0_1_ = 0x1a;
            SysFreeString(local_4c);
            if (local_60 != (undefined1 *)0x0) {
              *local_60 = 0;
            }
          }
        }
        else {
          local_8._0_1_ = uVar3;
          UVar10 = SysStringLen(local_38);
          if (UVar10 < uVar14) {
            pCVar7 = (CComBSTR *)FUN_00e616d4(param_1,&local_4c);
            local_8._0_1_ = 0x1c;
            iVar17 = 0x65;
          }
          else {
            UVar10 = SysStringLen(local_38);
            pOVar15 = local_34;
            if (UVar10 <= local_50) goto LAB_00eb0dea;
            pCVar7 = (CComBSTR *)FUN_00e616d4(param_1,&local_4c);
            local_8._0_1_ = 0x1d;
            iVar17 = 0x66;
          }
          iVar2 = local_3c;
          piVar9 = FUN_00e4cac1(*(void **)(local_3c + 0xc),iVar17);
          FUN_00eafbc7(*(void **)(iVar2 + 0x10),pCVar7,piVar9);
          local_8._0_1_ = 0x1a;
          SysFreeString(local_4c);
          pOVar15 = local_34;
          if (local_60 != (undefined1 *)0x0) {
            *local_60 = 0;
          }
        }
LAB_00eb0dea:
        UVar10 = SysStringLen(pOVar15);
        UVar11 = SysStringLen(local_38);
        if (UVar10 == UVar11) {
          if ((local_3d == '\0') ||
             ((((local_58 != (BSTR)0x0 && (local_58 != (BSTR)0x4)) && (local_58 != (BSTR)0x5)) &&
              ((local_58 != (BSTR)0x6 && (local_58 != (BSTR)0x7)))))) {
            HVar12 = VarBstrCmp(pOVar15,local_38,0x400,0);
            if (HVar12 != 1) {
              pCVar7 = (CComBSTR *)FUN_00e616d4(param_1,&local_4c);
              local_8._0_1_ = 0x1e;
              piVar9 = FUN_00e4cac1(*(void **)(local_3c + 0xc),0x67);
              FUN_00eafbc7(*(void **)(local_3c + 0x10),pCVar7,piVar9);
              local_8._0_1_ = 0x1a;
              SysFreeString(local_4c);
              if (local_60 != (undefined1 *)0x0) {
                *local_60 = 0;
              }
            }
          }
          else {
LAB_00eb0e80:
            (**(code **)(**(int **)(param_1 + 2) + 0x9c))();
            FUN_00e01fd0(&local_38,(int *)&local_34);
          }
        }
        else if (local_3d != '\0') goto LAB_00eb0e80;
        piVar9 = *(int **)(param_1 + 2);
        local_64 = piVar9;
        if (piVar9 != (int *)0x0) {
          (**(code **)(*piVar9 + 4))();
        }
        local_8 = CONCAT31(local_8._1_3_,0x1f);
        (**(code **)(*piVar9 + 0xa8))();
        if (local_88 < 9) {
          if (local_88 == 8) {
            UVar10 = SysStringLen(local_38);
            if (UVar10 != 2) {
              pwVar18 = L"06";
              goto LAB_00eb0fc9;
            }
          }
          else if (local_88 == 0) {
            UVar10 = SysStringLen(local_38);
            if ((UVar10 & 1) != 0) {
              pwVar18 = L"05012345123455";
              goto LAB_00eb0fc9;
            }
          }
          else if (local_88 == 4) {
            UVar10 = SysStringLen(local_38);
            if (UVar10 != 8) {
              pwVar18 = L"05012343";
              goto LAB_00eb0fc9;
            }
          }
          else if (local_88 == 6) {
            UVar10 = SysStringLen(local_38);
            if (UVar10 != 0xc) {
              pwVar18 = L"050123456789";
              goto LAB_00eb0fc9;
            }
          }
          else {
            if (local_88 != 7) goto LAB_00eb0fa1;
            UVar10 = SysStringLen(local_38);
            if (UVar10 != 8) {
              pwVar18 = L"05012349";
              goto LAB_00eb0fc9;
            }
          }
        }
        else if (local_88 == 9) {
          UVar10 = SysStringLen(local_38);
          if (UVar10 != 5) {
            pwVar18 = L"59999";
            goto LAB_00eb0fc9;
          }
        }
        else if ((local_88 < 10) || ((0xe < local_88 && (1 < local_88 - 0x13U)))) {
LAB_00eb0fa1:
          UVar10 = SysStringLen(local_38);
          if (UVar10 != 0xd) {
            pwVar18 = L"0501234567890";
LAB_00eb0fc9:
            (**(code **)(**(int **)(param_1 + 2) + 0x9c))(*(int **)(param_1 + 2),pwVar18);
          }
        }
        else {
          UVar10 = SysStringLen(local_38);
          if ((UVar10 != 0xd) && (UVar10 = SysStringLen(local_38), UVar10 != 0xe)) {
            pwVar18 = L"03612345678904";
            goto LAB_00eb0fc9;
          }
        }
        local_8._0_1_ = 0x1a;
        (**(code **)(*piVar9 + 8))(piVar9);
        SysFreeString(pOVar15);
        SysFreeString(local_a0);
        SysFreeString(local_a4);
        SysFreeString(local_a8);
        SysFreeString(local_38);
        local_8._0_1_ = 9;
        if (local_5c != (int *)0x0) {
          (**(code **)(*local_5c + 8))();
        }
      }
      VariantClear((VARIANTARG *)&local_84.n2);
    }
    else {
      pCVar7 = (CComBSTR *)FUN_00e616d4(param_1,&local_58);
      local_8._0_1_ = 8;
      piVar9 = FUN_00e4cac1(*(void **)(local_3c + 0xc),0x60);
      FUN_00eafbc7(*(void **)(local_3c + 0x10),pCVar7,piVar9);
      SysFreeString(local_58);
      if (puVar1 != (undefined1 *)0x0) {
        *puVar1 = 0;
      }
    }
  }
  SysFreeString(local_30);
LAB_00eb102b:
  if (local_48 != (undefined1 *)0x0) {
    FUN_00e63686(local_48,1);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  local_8 = (uint)local_8._1_3_ << 8;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))();
  }
  local_8 = 0xffffffff;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 8))();
  }
  FUN_00ec9e3c();
  return;
}


