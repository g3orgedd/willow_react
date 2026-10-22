// Source: CLCiffConversion_Data.dll @ 45011c74; FUN_45011c74

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall
FUN_45011c74(void *this,int *param_1,uint param_2,undefined4 param_3,wchar_t *param_4,
            undefined4 param_5)

{
  OLECHAR OVar1;
  bool bVar2;
  short sVar3;
  uint uVar4;
  UINT UVar5;
  uint uVar6;
  undefined8 *puVar7;
  wchar_t ****ppppwVar8;
  wchar_t *_Str;
  code *pcVar9;
  float10 fVar10;
  int *piStack_160;
  uint uStack_15c;
  int *piStack_158;
  undefined1 *puStack_154;
  int *piStack_150;
  int *piStack_148;
  char *pcVar11;
  undefined1 local_118 [4];
  undefined8 local_114;
  uint local_10c;
  uint local_108;
  undefined1 *local_104;
  BSTR local_100;
  uint local_fc;
  BSTR local_f8;
  uint local_f4;
  undefined1 local_f0 [24];
  undefined1 local_d8 [24];
  undefined1 local_c0 [24];
  undefined8 local_a8 [3];
  wchar_t ***local_90 [4];
  undefined4 local_80;
  uint local_7c;
  wchar_t ***local_78 [4];
  undefined4 local_68;
  uint local_64;
  undefined4 local_60;
  undefined4 local_50;
  uint local_4c;
  wchar_t ***local_48 [2];
  _SYSTEMTIME local_40;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x108;
  local_114 = (double)CONCAT44(this,(undefined4)local_114);
  local_8 = 1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCIFFDatabaseResolve::ResolveDate");
  local_f8 = (BSTR)0x0;
  local_8 = CONCAT31(local_8._1_3_,3);
  local_104 = (undefined1 *)(**(code **)(*param_1 + 0x6c))();
  if ((int)local_104 < 0) {
    FUN_4500274d(0x4503f234);
    FUN_4500ae72(&local_f8,"");
  }
  local_8._0_1_ = 4;
  local_f4 = 0xffffffff;
  local_fc = 0xffffffff;
  uVar4 = param_2 & 0xffff;
  local_10c = 0xffffffff;
  local_108 = 0xffffffff;
  if (uVar4 == 3) {
    uVar6 = 0;
    local_f4 = 0;
    uVar4 = 0;
    UVar5 = SysStringLen(local_f8);
    sVar3 = (short)param_4;
    if (UVar5 == 0) {
LAB_450121cc:
      local_f4 = (uint)sVar3;
LAB_450121f4:
      if ((local_f4 == 0xffffffff) || (uVar6 == 0xffffffff)) goto LAB_4501210a;
    }
    else {
      OVar1 = *local_f8;
      if (OVar1 == L'M') {
LAB_450121e8:
        uVar6 = (uint)sVar3;
        goto LAB_450121f4;
      }
      if (OVar1 != L'Y') {
        if (OVar1 == L'm') goto LAB_450121e8;
        if (OVar1 != L'y') goto LAB_450121cc;
      }
      uVar4 = (uint)sVar3;
    }
    if (uVar4 != 0xffffffff) {
      if (((local_f4 != 0x1e) || (uVar6 != 0xb)) || (uVar4 != 1999)) {
        (**(code **)(*param_1 + 0x30))();
        (**(code **)(*param_1 + 0x38))();
        piStack_148 = param_1;
        (**(code **)(*param_1 + 0x40))();
        piStack_150 = param_1;
        puStack_154 = (undefined1 *)0x45012258;
        (**(code **)(*param_1 + 0x58))();
        puStack_154 = local_118;
        piStack_158 = param_1;
        uStack_15c = 0x45012268;
        (**(code **)(*param_1 + 0x4c))();
        uStack_15c = local_f4;
        piStack_160 = param_1;
        (**(code **)(*param_1 + 0xa8))();
        (**(code **)(*param_1 + 0xb0))(param_1,uVar6);
        (**(code **)(*param_1 + 0xb8))(param_1,uVar4);
        local_8 = 3;
        SysFreeString(local_f8);
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0)
        ;
        local_8 = local_8 & 0xffffff00;
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))();
        }
        VariantClear((VARIANTARG *)&param_2);
LAB_45012332:
        FUN_45022ec7();
        return;
      }
      FUN_4500274d(0x4503f2f8);
      goto LAB_45011d48;
    }
  }
  else {
    if (uVar4 == 5) {
      fVar10 = FUN_4501dcc4((double)CONCAT44(param_5,param_4));
      local_114 = (double)fVar10;
      bVar2 = FUN_4501dd59(&local_40,local_114);
      if (!bVar2) {
        pcVar11 = "%s - ZipherDate::MakeSysTime failed, returning E_FAIL";
LAB_45011d41:
        FUN_4500274d((int)pcVar11);
        goto LAB_45011d48;
      }
LAB_45012169:
      local_f4 = (uint)local_40.wDay;
      uVar6 = (uint)local_40.wMonth;
      uVar4 = (uint)local_40.wYear;
      goto LAB_450121f4;
    }
    if (uVar4 != 7) {
      if (uVar4 != 8) {
        pcVar11 = "%s - switch(vtVAlue) fell through to default, returning E_FAIL";
        goto LAB_45011d41;
      }
      local_7c = 7;
      local_80 = 0;
      local_90[0] = (wchar_t ***)((uint)local_90[0] & 0xffff0000);
      FID_conflict_assign(local_90,(undefined8 *)&DAT_4503d460,0);
      local_8._0_1_ = 5;
      local_68 = 0;
      local_78[0] = (wchar_t ***)((uint)local_78[0] & 0xffff0000);
      local_64 = 7;
      FID_conflict_assign(local_78,(undefined8 *)&DAT_4503d460,0);
      local_8._0_1_ = 6;
      local_50 = 0;
      local_60 = (wchar_t *)((uint)local_60._2_2_ << 0x10);
      local_4c = 7;
      FID_conflict_assign(&local_60,(undefined8 *)&DAT_4503d460,0);
      local_8._0_1_ = 7;
      basic_string<>(local_48,param_4);
      local_100 = (BSTR)0x0;
      local_8._0_1_ = 9;
      local_104 = (undefined1 *)(**(code **)(*param_1 + 0xbc))();
      if ((int)local_104 < 0) {
        FUN_4500274d(0x4503f410);
        pcVar9 = SysFreeString_exref;
        SysFreeString(local_100);
LAB_45011e14:
        FUN_450046d9(local_48,'\x01',0);
        FUN_450046d9(&local_60,'\x01',0);
        FUN_450046d9(local_78,'\x01',0);
        FUN_450046d9(local_90,'\x01',0);
        (*pcVar9)();
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0)
        ;
        local_8 = (uint)local_8._1_3_ << 8;
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))();
        }
        VariantClear((VARIANTARG *)&param_2);
        goto LAB_45012332;
      }
      UVar5 = SysStringLen(local_f8);
      if (UVar5 == 0) {
        local_fc = 0x2f;
        uVar4 = FUN_450142b7(local_48,(wchar_t *)&local_fc,0,1);
        local_fc = 0x2f;
        uVar6 = FUN_45014394(local_48,(wchar_t *)&local_fc,0xffffffff,1);
        if (uVar4 == 0xffffffff) {
          ppppwVar8 = local_48;
          if (7 < (uint)local_40._12_4_) {
            ppppwVar8 = (wchar_t ****)local_48[0];
          }
          local_f4 = __wtol((wchar_t *)ppppwVar8);
          uVar6 = 0;
          uVar4 = 0;
        }
        else {
          puVar7 = FUN_45014419(local_48,local_f0,0,uVar4);
          FUN_4500589e(local_90,puVar7);
          FUN_450046d9(local_f0,'\x01',0);
          puVar7 = FUN_45014419(local_48,local_c0,uVar4 + 1,(uVar6 - uVar4) - 1);
          FUN_4500589e(local_78,puVar7);
          FUN_450046d9(local_c0,'\x01',0);
          puVar7 = FUN_45014419(local_48,local_d8,uVar6 + 1,local_40._8_4_ - uVar6);
          FUN_4500589e(&local_60,puVar7);
          FUN_450046d9(local_d8,'\x01',0);
          ppppwVar8 = local_90;
          if (7 < local_7c) {
            ppppwVar8 = (wchar_t ****)local_90[0];
          }
          local_f4 = __wtol((wchar_t *)ppppwVar8);
          ppppwVar8 = local_78;
          if (7 < local_64) {
            ppppwVar8 = (wchar_t ****)local_78[0];
          }
          uVar6 = __wtol((wchar_t *)ppppwVar8);
          _Str = (wchar_t *)&local_60;
          if (7 < local_4c) {
            _Str = local_60;
          }
          uVar4 = __wtol(_Str);
        }
      }
      else {
        basic_string<>(local_a8,local_f8);
        local_104 = (undefined1 *)&piStack_148;
        local_8._0_1_ = 10;
        piStack_150 = (int *)0x45011fca;
        basic_string<>(&piStack_148,local_a8);
        local_8._0_1_ = 0xb;
        basic_string<>(&piStack_160,(undefined8 *)local_48);
        local_8._0_1_ = 10;
        local_104 = (undefined1 *)
                    FUN_450124ab((long *)&local_fc,(long *)&local_10c,(long *)&local_108);
        if ((int)local_104 < 0) {
          FUN_4500274d(0x4503f268);
          FUN_450046d9(local_a8,'\x01',0);
          pcVar9 = SysFreeString_exref;
          SysFreeString(local_100);
          goto LAB_45011e14;
        }
        local_f4 = local_fc;
        uVar4 = local_108;
        uVar6 = local_10c;
        if (local_fc == 0xffffffff) {
          if ((local_10c != 0xffffffff) || (local_108 != 0xffffffff)) {
            local_f4 = 0;
            goto LAB_45012074;
          }
        }
        else {
LAB_45012074:
          if (local_10c == 0xffffffff) {
            uVar6 = 0;
          }
          if (local_108 == 0xffffffff) {
            uVar4 = 0;
          }
        }
        FUN_450046d9(local_a8,'\x01',0);
      }
      SysFreeString(local_100);
      FUN_450046d9(local_48,'\x01',0);
      FUN_450046d9(&local_60,'\x01',0);
      FUN_450046d9(local_78,'\x01',0);
      local_8._0_1_ = 4;
      FUN_450046d9(local_90,'\x01',0);
      goto LAB_450121f4;
    }
    fVar10 = FUN_4501dcc4((double)CONCAT44(param_5,param_4));
    local_114 = (double)fVar10;
    bVar2 = FUN_4501dd59(&local_40,local_114);
    if (bVar2) goto LAB_45012169;
  }
LAB_4501210a:
  piStack_148 = (int *)0x45012129;
  FUN_4500274d(0x4503f480);
LAB_45011d48:
  SysFreeString(local_f8);
  FUN_45012308();
  return;
}


