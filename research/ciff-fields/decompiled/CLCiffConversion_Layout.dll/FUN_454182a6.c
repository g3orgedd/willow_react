// Source: CLCiffConversion_Layout.dll @ 454182a6; FUN_454182a6

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_454182a6(void *this,int *param_1)

{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  int *piVar4;
  VARIANTARG local_d0;
  VARIANTARG local_c0;
  undefined4 local_b0;
  undefined4 local_ac;
  uint local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  int *local_98;
  undefined4 local_94;
  int *local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  BSTR local_6c;
  BSTR local_68;
  int *local_64;
  BSTR local_60;
  int local_5c;
  BSTR local_58;
  BSTR local_54;
  int *local_50;
  int *local_4c;
  int local_48;
  int *local_44;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  char local_35;
  void *local_34;
  int *local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc0;
  local_8 = 0x454182b5;
  local_44 = param_1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCiffPriceVerifierBarcodes::Convert CComPtr<ICiffSubImage>");
  local_8 = 0;
  local_98 = (int *)((int)this + 0x5c);
  FUN_45404ce5(local_98,param_1);
  uVar3 = FUN_4541e651((int)this);
  if ((char)uVar3 != '\x01') {
    do {
      local_35 = '\0';
      if (*param_1 == 0) {
        FUN_45414e34(0x454497d0);
      }
      else {
        local_48 = 0;
        local_4c = (int *)FUN_454043b0((int *)0x0,(int *)0x0);
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_45406d62(param_1,&local_4c);
        local_5c = 0;
        if (local_48 == 0) {
          FUN_45414e34(0x454497b8);
        }
        else {
          piVar4 = (int *)*local_4c;
          param_1 = local_44;
          if (piVar4 != local_4c) {
            do {
              param_1 = local_44;
              if (local_35 != '\0') break;
              FUN_4540303d(0x4544a2d8);
              FUN_4540303d(0x4544a308);
              local_34 = (void *)piVar4[2];
              local_5c = local_5c + 1;
              cVar1 = FUN_4541e74b(this,local_34);
              if (cVar1 != '\0') {
                local_35 = '\x01';
                FUN_4541cbbe(local_34,&local_54);
                local_8._0_1_ = 2;
                local_a4 = FUN_4541cd30((int)local_34);
                local_a0 = FUN_4541cd4c((int)local_34);
                local_ac = FUN_4541cbf2((int)local_34);
                local_38 = FUN_4541cb5f((int)local_34);
                bVar2 = FUN_4541cb9e((int)local_34);
                local_a8 = (uint)bVar2;
                (**(code **)(**(int **)((int)local_34 + 4) + 0x54))
                          (*(int **)((int)local_34 + 4),&local_7c);
                FUN_4541c90f(local_34,&local_60);
                local_8._0_1_ = 3;
                FUN_4541c740(local_34,&local_68);
                local_8._0_1_ = 4;
                local_9c = FUN_4541cd14((int)local_34);
                local_84 = FUN_4541cb40((int)local_34);
                local_b0 = FUN_4541cb7f((int)local_34);
                local_3a = FUN_4541d969((int)local_34);
                FUN_4541c774(local_34,&local_58);
                local_8._0_1_ = 5;
                local_8c = FUN_4541cded((int)local_34);
                local_70 = FUN_4541d480((int)local_34);
                local_37 = FUN_4541d38b((int)local_34);
                local_39 = FUN_4541d368((int)local_34);
                FUN_4541d3cd(local_34,&local_6c);
                local_8._0_1_ = 6;
                local_94 = FUN_4541d3ae((int)local_34);
                local_74 = FUN_4541d404((int)local_34);
                local_78 = FUN_4541d442((int)local_34);
                local_80 = FUN_4541dab9((int)local_34);
                local_3c = FUN_4541c8ec((int)local_34);
                local_3e = FUN_4541d9c6((int)local_34);
                local_3d = FUN_4541d322((int)local_34);
                local_3b = FUN_4541c67c((int)local_34);
                local_36 = FUN_4541d345((int)local_34);
                local_88 = FUN_4541d461((int)local_34);
                local_34 = (void *)FUN_4541d423((int)local_34);
                (**(code **)(*(int *)*local_44 + 0x2c))((int *)*local_44,local_54);
                FUN_45429f70((uint *)&local_c0,0,0x10);
                VariantInit(&local_c0);
                local_8._0_1_ = 7;
                (**(code **)(*(int *)*local_44 + 0x28))((int *)*local_44,1,local_54,0,&local_c0);
                CComQIPtr<>(&local_90,(undefined4 *)local_c0.n1._8_4_);
                CComQIPtr<>(&local_30,(undefined4 *)local_c0.n1._8_4_);
                local_8._0_1_ = 9;
                if (local_30 != (int *)0x0) {
                  (**(code **)(*local_30 + 0x30))(local_30,local_a4);
                  (**(code **)(*local_30 + 0x38))(local_30,local_a0);
                  (**(code **)(*local_30 + 0x40))(local_30,local_ac);
                  (**(code **)(*local_30 + 0x48))(local_30,local_38);
                  (**(code **)(*local_30 + 0x50))(local_30,local_a8);
                  (**(code **)(*local_30 + 0x58))(local_30,local_7c);
                  (**(code **)(*local_30 + 0x7c))(local_30,local_9c);
                  (**(code **)(*local_30 + 0x84))(local_30,local_84);
                  (**(code **)(*local_30 + 0x8c))(local_30,local_b0);
                  (**(code **)(*local_30 + 0x94))(local_30,local_3a);
                  (**(code **)(*local_30 + 0x6c))(local_30,local_60);
                  (**(code **)(*local_30 + 0x74))(local_30,local_68);
                  (**(code **)(*local_30 + 0x9c))(local_30,local_58);
                  (**(code **)(*local_30 + 0xac))(local_30,5);
                  (**(code **)(*local_30 + 0xb4))(local_30,local_8c);
                  (**(code **)(*local_30 + 0xbc))(local_30,local_70);
                  (**(code **)(*local_30 + 0xc4))(local_30,local_37);
                  (**(code **)(*local_30 + 0xcc))(local_30,local_39);
                  (**(code **)(*local_30 + 0xd4))(local_30,local_6c);
                  (**(code **)(*local_30 + 0xdc))(local_30,local_94);
                  (**(code **)(*local_30 + 0xe4))(local_30,local_74);
                  (**(code **)(*local_30 + 0xec))(local_30,local_78);
                  (**(code **)(*local_30 + 0xf4))(local_30,local_80);
                  (**(code **)(*local_30 + 0x104))(local_30,local_3c);
                  (**(code **)(*local_30 + 0x10c))(local_30,local_3e);
                  (**(code **)(*local_30 + 0x114))(local_30,local_3d);
                  (**(code **)(*local_30 + 0x11c))(local_30,local_3b);
                  (**(code **)(*local_30 + 300))(local_30,local_36);
                  (**(code **)(*local_30 + 0x140))(local_30,local_88);
                  (**(code **)(*local_30 + 0x148))(local_30,local_34);
                  local_50 = (int *)0x0;
                  local_8._0_1_ = 10;
                  (**(code **)(*local_30 + 0x5c))(local_30,&local_50);
                  if (local_50 != (int *)0x0) {
                    FUN_45429f70((uint *)&local_d0,0,0x10);
                    VariantInit(&local_d0);
                    local_8._0_1_ = 0xb;
                    (**(code **)(*local_50 + 0x28))(local_50,0,0,1,0,&local_d0);
                    CComQIPtr<>(&local_64,(undefined4 *)local_d0.n1._8_4_);
                    local_8._0_1_ = 0xc;
                    if (local_64 != (int *)0x0) {
                      (**(code **)(*local_64 + 0x5c))(local_64,local_58);
                    }
                    local_8._0_1_ = 0xb;
                    if (local_64 != (int *)0x0) {
                      (**(code **)(*local_64 + 8))(local_64);
                    }
                    VariantClear(&local_d0);
                  }
                  local_8._0_1_ = 9;
                  if (local_50 != (int *)0x0) {
                    (**(code **)(*local_50 + 8))(local_50);
                  }
                }
                local_8._0_1_ = 8;
                if (local_30 != (int *)0x0) {
                  (**(code **)(*local_30 + 8))(local_30);
                }
                local_8._0_1_ = 7;
                if (local_90 != (int *)0x0) {
                  (**(code **)(*local_90 + 8))(local_90);
                }
                VariantClear(&local_c0);
                SysFreeString(local_6c);
                SysFreeString(local_58);
                SysFreeString(local_68);
                SysFreeString(local_60);
                local_8 = CONCAT31(local_8._1_3_,1);
                SysFreeString(local_54);
              }
              piVar4 = (int *)*piVar4;
              param_1 = local_44;
            } while (piVar4 != local_4c);
          }
        }
        FUN_454065f3((int *)&local_4c);
        local_8 = local_8 & 0xffffff00;
        FUN_454224ff((int *)&local_4c);
        FID_conflict__free(local_4c);
      }
    } while (local_35 == '\x01');
    piVar4 = (int *)*local_98;
    if ((piVar4 != (int *)0x0) && (*local_98 = 0, piVar4 != (int *)0x0)) {
      (**(code **)(*piVar4 + 8))(piVar4);
    }
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


