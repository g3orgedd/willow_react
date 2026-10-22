// Source: CLCiffConversion_Data.dll @ 45011718; FUN_45011718

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_45011718(int *param_1,uint param_2,undefined4 param_3,wchar_t *param_4,undefined4 param_5)

{
  uint uVar1;
  UINT UVar2;
  uint uVar3;
  undefined8 *puVar4;
  wchar_t ****ppppwVar5;
  wchar_t *_Str;
  uint uVar6;
  undefined1 uVar7;
  undefined1 auStack_14c [12];
  undefined4 uStack_140;
  int *piStack_13c;
  int *piStack_134;
  uint local_104;
  undefined1 *local_100;
  BSTR local_fc;
  uint local_f8;
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
  undefined8 local_60;
  _SYSTEMTIME local_58;
  undefined4 local_48;
  _union_2683 local_40;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xfc;
  local_8 = 1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCIFFDatabaseResolve::ResolveAbsoluteDate");
  uVar1 = param_2 & 0xffff;
  local_100 = (undefined1 *)0x0;
  local_f4 = 0xffffffff;
  local_104 = 0xffffffff;
  local_f8 = 0xffffffff;
  uVar7 = 3;
  local_8._0_1_ = 3;
  if (uVar1 == 3) {
    local_40._8_4_ = param_4;
    local_40.n2.vt = 3;
    local_8._0_1_ = uVar7;
    VariantChangeType((VARIANTARG *)&local_40.n2,(VARIANTARG *)&local_40,0,7);
    VariantTimeToSystemTime((DOUBLE)CONCAT44(local_40._12_4_,local_40._8_4_),&local_58);
    local_f4 = (uint)local_58.wYear;
    uVar1 = (uint)local_58.wDay;
    uVar3 = (uint)local_58.wMonth;
    VariantClear((VARIANTARG *)&local_40.n2);
  }
  else {
    if (uVar1 == 5) goto LAB_45011bfd;
    if (uVar1 == 7) {
      local_8._0_1_ = uVar7;
      FUN_4500274d(0x4503f2a0);
      VariantTimeToSystemTime((DOUBLE)CONCAT44(param_5,param_4),(LPSYSTEMTIME)&local_40.n2);
      local_f4 = (uint)local_40.n2.vt;
      uVar1 = (uint)local_40.n2.wReserved3;
      uVar3 = (uint)local_40.n2.wReserved1;
    }
    else {
      if (uVar1 != 8) {
        FUN_4500274d(0x4503f2b8);
        goto LAB_450117a0;
      }
      local_64 = 7;
      local_68 = 0;
      local_78[0] = (wchar_t ***)((uint)local_78[0] & 0xffff0000);
      FID_conflict_assign(local_78,(undefined8 *)&DAT_4503d460,0);
      local_8._0_1_ = 4;
      local_7c = 7;
      local_80 = 0;
      local_90[0] = (wchar_t ***)((uint)local_90[0] & 0xffff0000);
      FID_conflict_assign(local_90,(undefined8 *)&DAT_4503d460,0);
      local_8._0_1_ = 5;
      local_40._12_4_ = 7;
      local_40._8_4_ = (wchar_t *)0x0;
      local_48 = (wchar_t *)((uint)local_48._2_2_ << 0x10);
      FID_conflict_assign(&local_48,(undefined8 *)&DAT_4503d460,0);
      local_8._0_1_ = 6;
      basic_string<>(&local_60,param_4);
      local_fc = (BSTR)0x0;
      local_8._0_1_ = 8;
      local_100 = (undefined1 *)(**(code **)(*param_1 + 0x6c))();
      if ((int)local_100 < 0) {
        FUN_4500274d(0x4503f234);
        FUN_4500ae72(&local_fc,"");
      }
      UVar2 = SysStringLen(local_fc);
      if (UVar2 == 0) {
        local_f8 = 0x2f;
        uVar1 = FUN_450142b7(&local_60,(wchar_t *)&local_f8,0,1);
        local_f8 = 0x2f;
        uVar3 = FUN_45014394(&local_60,(wchar_t *)&local_f8,0xffffffff,1);
        puVar4 = FUN_45014419(&local_60,local_c0,0,uVar1);
        FUN_4500589e(local_78,puVar4);
        FUN_450046d9(local_c0,'\x01',0);
        puVar4 = FUN_45014419(&local_60,local_f0,uVar1 + 1,(uVar3 - uVar1) - 1);
        FUN_4500589e(local_90,puVar4);
        FUN_450046d9(local_f0,'\x01',0);
        puVar4 = FUN_45014419(&local_60,local_d8,uVar3 + 1,local_58._8_4_ - uVar3);
        FUN_4500589e(&local_48,puVar4);
        FUN_450046d9(local_d8,'\x01',0);
        ppppwVar5 = local_78;
        if (7 < local_64) {
          ppppwVar5 = (wchar_t ****)local_78[0];
        }
        uVar1 = __wtol((wchar_t *)ppppwVar5);
        ppppwVar5 = local_90;
        if (7 < local_7c) {
          ppppwVar5 = (wchar_t ****)local_90[0];
        }
        uVar3 = __wtol((wchar_t *)ppppwVar5);
        _Str = (wchar_t *)&local_48;
        if (7 < (uint)local_40._12_4_) {
          _Str = local_48;
        }
        uVar6 = __wtol(_Str);
      }
      else {
        basic_string<>(local_a8,local_fc);
        local_100 = (undefined1 *)&piStack_134;
        local_8._0_1_ = 9;
        piStack_13c = (int *)0x450119ae;
        basic_string<>(&piStack_134,local_a8);
        local_8._0_1_ = 10;
        basic_string<>(auStack_14c,&local_60);
        local_8._0_1_ = 9;
        local_100 = (undefined1 *)
                    FUN_450124ab((long *)&local_f4,(long *)&local_104,(long *)&local_f8);
        if ((int)local_100 < 0) {
          FUN_4500274d(0x4503f268);
          FUN_450046d9(local_a8,'\x01',0);
          SysFreeString(local_fc);
          FUN_450046d9(&local_60,'\x01',0);
          FUN_450046d9(&local_48,'\x01',0);
          FUN_450046d9(local_90,'\x01',0);
          FUN_450046d9(local_78,'\x01',0);
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
                    (local_30,true,0);
          local_8 = (uint)local_8._1_3_ << 8;
          if (param_1 != (int *)0x0) {
            (**(code **)(*param_1 + 8))();
          }
          VariantClear((VARIANTARG *)&param_2);
          goto LAB_45011c6c;
        }
        FUN_450046d9(local_a8,'\x01',0);
        uVar6 = local_f8;
        uVar1 = local_f4;
        uVar3 = local_104;
      }
      local_f4 = uVar6;
      SysFreeString(local_fc);
      FUN_450046d9(&local_60,'\x01',0);
      FUN_450046d9(&local_48,'\x01',0);
      FUN_450046d9(local_90,'\x01',0);
      local_8._0_1_ = 3;
      FUN_450046d9(local_78,'\x01',0);
    }
  }
  uVar7 = (undefined1)local_8;
  if (uVar1 == 0x1e) {
    if (uVar3 != 0xb) goto LAB_45011b7a;
    if (local_f4 == 1999) {
      FUN_4500274d(0x4503f2f8);
LAB_450117a0:
      FUN_45011c42();
      return;
    }
  }
  else {
    if ((int)uVar1 < 1) goto LAB_45011bfd;
LAB_45011b7a:
    if ((int)uVar3 < 1) {
LAB_45011bfd:
      local_8._0_1_ = uVar7;
      piStack_134 = (int *)0x45011c16;
      FUN_4500274d(0x4503f324);
      FUN_45011c42();
      return;
    }
  }
  piStack_134 = (int *)0x45011b98;
  FUN_4500274d(0x4503f354);
  (**(code **)(*param_1 + 0x30))();
  (**(code **)(*param_1 + 0x38))();
  piStack_134 = param_1;
  (**(code **)(*param_1 + 0x40))();
  piStack_13c = param_1;
  uStack_140 = 0x45011bc9;
  (**(code **)(*param_1 + 0x58))();
  local_8 = 2;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
  local_8 = local_8 & 0xffffff00;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))();
  }
  VariantClear((VARIANTARG *)&param_2);
LAB_45011c6c:
  FUN_45022ec7();
  return;
}


