// Source: CLCiffConversion_Layout.dll @ 45416ceb; FUN_45416ceb

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_45416ceb(void *this,undefined4 *param_1)

{
  void *this_00;
  undefined4 *puVar1;
  undefined3 uVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  code *pcVar6;
  int *piVar7;
  BSTR pOVar8;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  _union_2683 local_8c;
  int *local_7c;
  int local_78;
  int local_74;
  int *local_70;
  wchar_t *local_6c;
  int *local_68;
  int *local_64;
  undefined4 local_60;
  BSTR local_5c;
  void *local_58;
  BSTR local_54;
  int local_50;
  int *local_4c;
  undefined4 *local_48;
  BSTR local_44;
  wchar_t *local_40;
  int local_3c;
  BSTR local_38;
  int local_34;
  int local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x8c;
  local_8 = 0x45416cfa;
  local_48 = param_1;
  local_58 = this;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFFieldOrder::Convert");
  local_4c = (int *)0x0;
  local_68 = (int *)0x0;
  local_64 = (int *)0x0;
  local_60 = 0;
  local_8._1_3_ = 0;
  uVar2 = local_8._1_3_;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if (*(int *)((int)this + 0x6c) == 0) {
    local_30 = -0x7ff8ffa9;
    local_8._1_3_ = uVar2;
  }
  else {
    local_78 = 0;
    local_30 = (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1,&local_78);
    if (-1 < local_30) {
      piVar5 = (int *)0x0;
      piVar7 = (int *)0x0;
      if (0 < local_78) {
        do {
          FUN_45429f70((uint *)&local_8c,0,0x10);
          VariantInit((VARIANTARG *)&local_8c.n2);
          local_70 = (int *)((int)piVar7 + 1);
          local_8._0_1_ = 2;
          iVar4 = (**(code **)(*(int *)*param_1 + 0x24))((int *)*param_1,local_70,&local_8c);
          if (iVar4 < 0) {
LAB_45417118:
            VariantClear((VARIANTARG *)&local_8c.n2);
            goto LAB_45417210;
          }
          CComQIPtr<>(&local_38,(undefined4 *)local_8c._8_4_);
          pOVar8 = local_38;
          local_8._0_1_ = 3;
          local_44 = local_38;
          if (local_38 != (BSTR)0x0) {
            (**(code **)(*(int *)local_38 + 4))(local_38);
          }
          local_50 = 0;
          local_8._0_1_ = 4;
          iVar4 = (**(code **)(*(int *)pOVar8 + 0x2c))(pOVar8,&local_50);
          if (iVar4 < 0) {
LAB_454170f9:
            local_8._0_1_ = 3;
            if (pOVar8 != (BSTR)0x0) {
              (**(code **)(*(int *)pOVar8 + 8))(pOVar8);
            }
            local_8._0_1_ = 2;
            if (local_38 != (BSTR)0x0) {
              (**(code **)(*(int *)local_38 + 8))(local_38);
            }
            goto LAB_45417118;
          }
          local_34 = 0;
          iVar4 = (**(code **)(*(int *)pOVar8 + 0x88))(pOVar8,&local_34);
          if (iVar4 < 0) goto LAB_454170f9;
          local_40 = (wchar_t *)0x0;
          local_8._0_1_ = 5;
          local_30 = (**(code **)(*(int *)pOVar8 + 0x1c))(pOVar8,&local_40);
          if (local_30 < 0) {
LAB_454170f0:
            SysFreeString(local_40);
            goto LAB_454170f9;
          }
          FUN_45402ac2(&local_90,local_40);
          local_8._0_1_ = 6;
          FUN_4540303d(0x45449e44);
          FUN_45402c5d(&local_90);
          this_00 = local_58;
          local_54 = (BSTR)0x0;
          local_8 = CONCAT31(local_8._1_3_,7);
          (**(code **)(**(int **)((int)local_58 + 0x6c) + 0x44))
                    (*(int **)((int)local_58 + 0x6c),&local_54);
          bVar3 = FUN_45402d1b(&local_54,L"楌敮");
          if ((bVar3) && (local_34 == 0)) {
            local_34 = FUN_45421114(this_00,&local_44,local_48);
            pOVar8 = local_44;
          }
          for (; piVar5 != local_64; piVar5 = piVar5 + 1) {
            piVar7 = (int *)*piVar5;
            local_4c = piVar7;
            if (piVar7 != (int *)0x0) {
              (**(code **)(*piVar7 + 4))(piVar7);
            }
            local_3c = 0;
            local_74 = 0;
            local_8._0_1_ = 8;
            local_30 = (**(code **)(*piVar7 + 0x2c))(piVar7,&local_74);
            if (local_30 < 0) {
LAB_454170d6:
              local_8._0_1_ = 7;
              if (piVar7 != (int *)0x0) {
                (**(code **)(*piVar7 + 8))(piVar7);
              }
              SysFreeString(local_54);
              goto LAB_454170f0;
            }
            local_3c = 0;
            local_30 = (**(code **)(*piVar7 + 0x88))(piVar7,&local_3c);
            if (local_30 < 0) goto LAB_454170d6;
            local_5c = (BSTR)0x0;
            local_8 = CONCAT31(local_8._1_3_,9);
            (**(code **)(**(int **)((int)local_58 + 0x6c) + 0x44))
                      (*(int **)((int)local_58 + 0x6c),&local_5c);
            bVar3 = FUN_45402d1b(&local_5c,L"楌敮");
            if ((bVar3) && (local_3c == 0)) {
              local_3c = FUN_45421114(local_58,&local_4c,local_48);
              piVar7 = local_4c;
            }
            FUN_4540303d(0x45449e74);
            if ((local_34 < local_3c) || ((local_34 == local_3c && (local_50 < local_74)))) {
              FUN_45421fa5(&local_68,(int *)&local_7c,piVar5,1,(int *)&local_44);
              local_6c = (wchar_t *)0x0;
              local_8._0_1_ = 10;
              (**(code **)(*piVar7 + 0x1c))(piVar7,&local_6c);
              FUN_45402ac2(&local_9c,local_6c);
              local_8._0_1_ = 0xb;
              FUN_45402ac2(&local_94,local_40);
              local_8._0_1_ = 0xc;
              FUN_4540303d(0x45449eb0);
              FUN_45402c5d(&local_94);
              FUN_45402c5d(&local_9c);
              pcVar6 = SysFreeString_exref;
              SysFreeString(local_6c);
              SysFreeString(local_5c);
              local_8 = CONCAT31(local_8._1_3_,7);
              (**(code **)(*piVar7 + 8))(piVar7);
              goto LAB_45416fe6;
            }
            SysFreeString(local_5c);
            local_8 = CONCAT31(local_8._1_3_,7);
            if (piVar7 != (int *)0x0) {
              (**(code **)(*piVar7 + 8))(piVar7);
            }
          }
          FUN_4542278f(&local_68,&local_44);
          FUN_45402ac2(&local_98,local_40);
          local_8 = CONCAT31(local_8._1_3_,0xd);
          FUN_4540303d(0x45449edc);
          FUN_45402c5d(&local_98);
          pcVar6 = SysFreeString_exref;
          pOVar8 = local_44;
LAB_45416fe6:
          (*pcVar6)(local_54);
          (*pcVar6)(local_40);
          local_8._0_1_ = 3;
          if (pOVar8 != (BSTR)0x0) {
            (**(code **)(*(int *)pOVar8 + 8))(pOVar8);
          }
          local_8._0_1_ = 2;
          if (local_38 != (BSTR)0x0) {
            (**(code **)(*(int *)local_38 + 8))(local_38);
          }
          local_8._0_1_ = 1;
          VariantClear((VARIANTARG *)&local_8c.n2);
          piVar5 = local_68;
          piVar7 = local_70;
          param_1 = local_48;
        } while ((int)local_70 < local_78);
        local_4c = local_68;
      }
      puVar1 = local_48;
      if (piVar5 != local_64) {
        do {
          piVar7 = (int *)*piVar5;
          local_7c = piVar7;
          if (piVar7 != (int *)0x0) {
            (**(code **)(*piVar7 + 4))(piVar7);
          }
          local_38 = (BSTR)0x0;
          local_8._0_1_ = 0xf;
          local_30 = (**(code **)(*piVar7 + 0x1c))(piVar7,&local_38);
          (**(code **)(*(int *)*puVar1 + 0x2c))((int *)*puVar1,local_38);
          SysFreeString(local_38);
          local_8._0_1_ = 1;
          (**(code **)(*piVar7 + 8))(piVar7);
          piVar5 = piVar5 + 1;
        } while (piVar5 != local_64);
        piVar5 = local_4c;
        if (local_4c != local_64) {
          do {
            piVar7 = (int *)*piVar5;
            local_7c = piVar7;
            local_70 = piVar7;
            if (piVar7 != (int *)0x0) {
              (**(code **)(*piVar7 + 4))(piVar7);
            }
            local_8._0_1_ = 0x10;
            local_8c.n2.vt = 9;
            local_8c._8_4_ = piVar7;
            if (piVar7 != (int *)0x0) {
              (**(code **)(*piVar7 + 4))(piVar7);
            }
            local_8._0_1_ = 0x11;
            (**(code **)(*(int *)*local_48 + 0x7c))
                      ((int *)*local_48,local_8c._0_4_,local_8c.decVal.Hi32,local_8c._8_4_,
                       local_8c._12_4_);
            VariantClear((VARIANTARG *)&local_8c.n2);
            local_8._0_1_ = 1;
            if (local_70 != (int *)0x0) {
              (**(code **)(*local_70 + 8))(local_70);
            }
            piVar5 = piVar5 + 1;
          } while (piVar5 != local_64);
        }
      }
      FUN_45412090(&local_68);
    }
  }
LAB_45417210:
  FUN_45422483((int *)&local_68);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


