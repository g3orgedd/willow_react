// Source: CLARiSOFT.exe @ 00e7cd3f; FUN_00e7cd3f

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */
/* WARNING: Removing unreachable block (ram,0x00e7cf96) */
/* WARNING: Type propagation algorithm not settling */

void FUN_00e7cd3f(void)

{
  undefined1 uVar1;
  HRESULT HVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  ulong *puVar7;
  _union_2683 local_98;
  int local_84 [4];
  int *local_74;
  int *local_70;
  int *local_6c;
  int local_68;
  int *local_64;
  int *local_60;
  int local_5c;
  int *local_58;
  int *local_54;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_50 [24];
  IID local_38;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x8c;
  local_8 = 0xe7cd4e;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_50,"CMainFrm::InitialiseFieldComponents");
  local_8 = 0;
  FUN_00e384b8((int *)&DAT_00f40d90);
  local_5c = 0;
  local_64 = (int *)0x0;
  HVar2 = CoCreateInstance((IID *)&DAT_00f09370,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00f03558,&local_64);
  if (HVar2 < 0) {
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_64 != (int *)0x0) {
      (**(code **)(*local_64 + 8))(local_64);
    }
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_50,true,0);
  }
  else {
    local_58 = (int *)0x0;
    local_28 = DAT_00f034d8;
    uStack_24 = DAT_00f034dc;
    uStack_20 = DAT_00f034e0;
    uStack_1c = DAT_00f034e4;
    local_8._0_1_ = 3;
    local_84[3] = (**(code **)(*local_64 + 0x14))(local_64,1,&local_28,0,0,&local_58);
    if (local_84[3] < 0) {
      local_8._0_1_ = 2;
      if (local_58 != (int *)0x0) {
        (**(code **)(*local_58 + 8))(local_58);
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_64 != (int *)0x0) {
        (**(code **)(*local_64 + 8))(local_64);
      }
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_50,true,0);
    }
    else {
      local_84[1] = 0;
      (**(code **)(*local_58 + 0x14))(local_58);
      uVar1 = (undefined1)local_8;
      while( true ) {
        local_8._0_1_ = uVar1;
        piVar5 = (int *)0x0;
        iVar3 = (**(code **)(*local_58 + 0xc))(local_58,1,&local_38,local_84 + 1);
        if (iVar3 != 0) break;
        local_54 = piVar5;
        HVar2 = CoCreateInstance(&local_38,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00f014f8,&local_54);
        local_84[3] = HVar2;
        CComQIPtr<>(&local_60,local_54);
        local_8._0_1_ = 5;
        if (((-1 < HVar2) && (local_54 != (int *)0x0)) && (local_60 != (int *)0x0)) {
          (**(code **)(*local_54 + 4))(local_54);
          (**(code **)(*local_60 + 0x18))(local_60,local_84);
          piVar6 = (int *)*DAT_00f40d90;
          while (piVar6 != DAT_00f40d90) {
            local_84[2] = 0;
            CComQIPtr<>(&local_74,(undefined4 *)piVar6[2]);
            local_8._0_1_ = 6;
            if ((local_74 != (int *)0x0) &&
               ((**(code **)(*local_74 + 0x18))(local_74,local_84 + 2), local_84[0] < local_84[2]))
            {
              local_70 = local_54;
              FUN_00e4aee3(&DAT_00f40d90,piVar6,&local_70);
              iVar3 = local_68;
              puVar7 = (ulong *)(local_68 + 0x22c8 + (int)piVar5 * 0x10);
              FUN_00ecc570((undefined8 *)(local_68 + 0x22d8 + (int)piVar5 * 0x10),
                           (undefined8 *)puVar7,(local_5c - (int)piVar5) * 0x10);
              *puVar7 = local_38.Data1;
              local_5c = local_5c + 1;
              local_8._0_1_ = 5;
              puVar7[1] = local_38._4_4_;
              puVar7[2] = local_38.Data4._0_4_;
              puVar7[3] = local_38.Data4._4_4_;
              if (local_74 != (int *)0x0) {
                (**(code **)(*local_74 + 8))(local_74);
              }
              goto LAB_00e7cf99;
            }
            piVar6 = (int *)*piVar6;
            piVar5 = (int *)((int)piVar5 + 1);
            local_8._0_1_ = 5;
            if (local_74 != (int *)0x0) {
              (**(code **)(*local_74 + 8))(local_74);
            }
          }
          local_70 = local_54;
          FUN_00e4aee3(&DAT_00f40d90,DAT_00f40d90,&local_70);
          puVar7 = (ulong *)(local_68 + 0x22c8 + local_5c * 0x10);
          local_5c = local_5c + 1;
          *puVar7 = local_38.Data1;
          puVar7[1] = local_38._4_4_;
          puVar7[2] = local_38.Data4._0_4_;
          puVar7[3] = local_38.Data4._4_4_;
          iVar3 = local_68;
LAB_00e7cf99:
          iVar4 = FUN_00eca603(&local_38.Data1,(uint *)&DAT_00eff360,0x10);
          if (iVar4 == 0) {
            CComQIPtr<>(&local_6c,local_54);
            local_8._0_1_ = 7;
            if (local_6c != (int *)0x0) {
              local_98._8_4_ = *(int *)(iVar3 + 0x233c);
              local_98.n2.vt = 9;
              if ((int *)local_98._8_4_ != (int *)0x0) {
                (**(code **)(*(int *)local_98._8_4_ + 4))(local_98._8_4_);
              }
              local_8._0_1_ = 8;
              (**(code **)(*local_6c + 0xc))
                        (local_6c,local_98._0_4_,local_98.decVal.Hi32,local_98._8_4_,local_98._12_4_
                        );
              VariantClear((VARIANTARG *)&local_98.n2);
            }
            local_8._0_1_ = 5;
            if (local_6c != (int *)0x0) {
              (**(code **)(*local_6c + 8))(local_6c);
            }
          }
        }
        local_8._0_1_ = 4;
        if (local_60 != (int *)0x0) {
          (**(code **)(*local_60 + 8))(local_60);
        }
        local_8._0_1_ = 3;
        uVar1 = (undefined1)local_8;
        local_8._0_1_ = 3;
        if (local_54 != (int *)0x0) {
          (**(code **)(*local_54 + 8))(local_54);
          uVar1 = (undefined1)local_8;
        }
      }
      local_8._0_1_ = 2;
      if (local_58 != (int *)0x0) {
        (**(code **)(*local_58 + 8))(local_58);
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_64 != (int *)0x0) {
        (**(code **)(*local_64 + 8))(local_64);
      }
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_50,true,0);
    }
  }
  FUN_00ec9e4b();
  return;
}


