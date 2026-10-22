// Source: CiffMgr.dll @ 681215f4; FUN_681215f4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_681215f4(void *this,int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  _union_2683 local_90;
  _union_2683 local_80;
  _union_2683 local_70;
  _union_2683 local_60;
  _union_2683 local_50;
  void *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  uint local_2c;
  int local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x80;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    local_28 = 0;
    local_40 = this;
    do {
      local_18 = (int *)0x0;
      local_8 = 0;
      iVar1 = (**(code **)(*(int *)*param_2 + 0x24))((int *)*param_2,&local_18);
      if ((iVar1 == 0) && (local_18 != (int *)0x0)) {
        local_14[0] = (int *)0x0;
        local_8._0_1_ = 1;
        iVar2 = (**(code **)(*local_18 + 0x44))(local_18,local_14);
        local_2c = 0x30;
        local_34 = 0;
        local_30 = 0;
        local_38 = 0;
        local_3c = 0;
        if ((-1 < iVar2) && (local_14[0] != (int *)0x0)) {
          local_1c = (int *)0x0;
          local_8._0_1_ = 2;
          iVar2 = (**(code **)(*local_14[0] + 0x1c))
                            (local_14[0],PTR_u_Significance_68160064,&local_1c);
          if ((iVar2 != 0) || (local_1c == (int *)0x0)) {
            local_8._0_1_ = 1;
            if (local_1c != (int *)0x0) {
              (**(code **)(*local_1c + 8))(local_1c);
            }
            local_8 = (uint)local_8._1_3_ << 8;
            if (local_14[0] != (int *)0x0) {
              (**(code **)(*local_14[0] + 8))(local_14[0]);
            }
            local_8 = 0xffffffff;
            if (local_18 != (int *)0x0) {
              (**(code **)(*local_18 + 8))(local_18);
            }
            return -0x7ffcfefc;
          }
          FUN_68132710((uint *)&local_50,0,0x10);
          VariantInit((VARIANTARG *)&local_50.n2);
          local_8 = CONCAT31(local_8._1_3_,3);
          (**(code **)(*local_1c + 0x20))(local_1c,&local_50);
          if (((local_50.n2.vt == 8) && ((ushort *)local_50._8_4_ != (ushort *)0x0)) &&
             (*(ushort *)local_50._8_4_ != 0)) {
            local_34 = FUN_6812f116((ushort *)local_50._8_4_);
          }
          VariantClear((VARIANTARG *)&local_50.n2);
          local_8._0_1_ = 1;
          if (local_1c != (int *)0x0) {
            (**(code **)(*local_1c + 8))(local_1c);
          }
          local_1c = (int *)0x0;
          local_8._0_1_ = 4;
          iVar2 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],PTR_u_AlphaNum_68160068,&local_1c);
          if ((iVar2 == 0) && (local_1c != (int *)0x0)) {
            FUN_68132710((uint *)&local_60,0,0x10);
            VariantInit((VARIANTARG *)&local_60.n2);
            local_8._0_1_ = 5;
            (**(code **)(*local_1c + 0x20))(local_1c,&local_60);
            if (local_60.n2.vt == 8) {
              local_30 = FUN_6812e988((wchar_t *)local_60._8_4_);
            }
            VariantClear((VARIANTARG *)&local_60.n2);
          }
          local_8._0_1_ = 1;
          if (local_1c != (int *)0x0) {
            (**(code **)(*local_1c + 8))(local_1c);
          }
          local_1c = (int *)0x0;
          local_8._0_1_ = 6;
          iVar2 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],PTR_u_LeadChar_6816006c,&local_1c);
          if ((iVar2 == 0) && (local_1c != (int *)0x0)) {
            FUN_68132710((uint *)&local_70,0,0x10);
            VariantInit((VARIANTARG *)&local_70.n2);
            local_8._0_1_ = 7;
            (**(code **)(*local_1c + 0x20))(local_1c,&local_70);
            if ((local_70.n2.vt == 8) &&
               (((ushort *)local_70._8_4_ != (ushort *)0x0 && (*(ushort *)local_70._8_4_ != 0)))) {
              local_2c = (uint)*(ushort *)local_70._8_4_;
            }
            VariantClear((VARIANTARG *)&local_70.n2);
          }
          local_8._0_1_ = 1;
          if (local_1c != (int *)0x0) {
            (**(code **)(*local_1c + 8))(local_1c);
          }
          local_1c = (int *)0x0;
          local_8._0_1_ = 8;
          iVar2 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],PTR_u_Global_681600d4,&local_1c);
          if ((iVar2 == 0) && (local_1c != (int *)0x0)) {
            FUN_68132710((uint *)&local_80,0,0x10);
            VariantInit((VARIANTARG *)&local_80.n2);
            local_8._0_1_ = 9;
            (**(code **)(*local_1c + 0x20))(local_1c,&local_80);
            if ((local_80.n2.vt == 8) &&
               (((wchar_t *)local_80._8_4_ != (wchar_t *)0x0 &&
                (*(wchar_t *)local_80._8_4_ != L'\0')))) {
              local_38 = 1;
              local_3c = FUN_6812efa6((wchar_t *)local_80._8_4_);
            }
            VariantClear((VARIANTARG *)&local_80.n2);
          }
          local_8._0_1_ = 1;
          if (local_1c != (int *)0x0) {
            (**(code **)(*local_1c + 8))(local_1c);
          }
        }
        FUN_68132710((uint *)&local_90,0,0x10);
        VariantInit((VARIANTARG *)&local_90.n2);
        local_8._0_1_ = 10;
        iVar2 = (**(code **)(*param_1 + 0x124))
                          (param_1,local_34,local_30,local_2c,local_28,&local_90);
        local_28 = local_28 + 1;
        if (iVar2 < 0) {
LAB_681219ac:
          iVar1 = iVar2;
        }
        else {
          if (local_90.n2.vt == 9) {
            CComQIPtr<>(&local_24,(undefined4 *)local_90._8_4_);
            local_8._0_1_ = 0xb;
            (**(code **)(*local_24 + 0x80))(local_24,1);
            (**(code **)(*local_24 + 0x94))(local_24,local_38);
            (**(code **)(*local_24 + 0x9c))(local_24,local_3c);
            local_20 = (int *)0x0;
            local_8 = CONCAT31(local_8._1_3_,0xc);
            iVar2 = (**(code **)(*local_18 + 0x30))(local_18,&local_20);
            if ((-1 < iVar2) && (local_20 != (int *)0x0)) {
              iVar2 = FUN_68121394(local_40,local_24,&local_20);
            }
            local_8._0_1_ = 0xb;
            if (local_20 != (int *)0x0) {
              (**(code **)(*local_20 + 8))(local_20);
            }
            local_8._0_1_ = 10;
            if (local_24 != (int *)0x0) {
              (**(code **)(*local_24 + 8))(local_24);
            }
          }
          if (iVar2 < 0) goto LAB_681219ac;
        }
        VariantClear((VARIANTARG *)&local_90.n2);
        local_8 = (uint)local_8._1_3_ << 8;
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
      }
      local_8 = 0xffffffff;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
    } while (iVar1 == 0);
  }
  return iVar1;
}


