// Source: CLCiffConversion_Layout.dll @ 4541919e; FUN_4541919e

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4541919e(void *this,undefined4 *param_1)

{
  BSTR bstrString;
  bool bVar1;
  int iVar2;
  UINT UVar3;
  UINT UVar4;
  uint *_Memory;
  float fVar5;
  int iVar6;
  int *piVar7;
  float fVar8;
  code *pcVar9;
  float10 fVar10;
  int *piVar11;
  VARIANTARG local_100;
  VARIANTARG local_f0;
  VARIANTARG local_e0;
  VARIANTARG local_d0;
  VARIANTARG local_c0;
  void *local_b0;
  int local_ac;
  undefined4 local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int *local_94;
  undefined4 *local_90;
  BSTR local_8c;
  int local_88;
  int local_84;
  int local_80;
  BSTR local_7c;
  int local_78;
  BSTR local_74;
  int local_70;
  int *local_6c;
  uint local_68;
  int local_64;
  undefined4 local_60;
  int local_5c;
  int *local_58;
  int *local_54;
  int local_50;
  BSTR local_4c;
  int *local_48;
  int *local_44;
  int *local_40;
  int local_3c;
  int *local_38;
  int *local_34;
  float local_30;
  int *local_2c;
  wchar_t local_28 [16];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xf0;
  local_8 = 0x454191ad;
  local_70 = 0;
  local_68 = 0;
  local_90 = param_1;
  local_b0 = this;
  iVar2 = (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1,&local_70);
  FUN_4541534f(iVar2);
  local_5c = 0;
  pcVar9 = SysFreeString_exref;
  if (0 < local_70) {
    do {
      FUN_45429f70((uint *)&local_e0,0,0x10);
      VariantInit(&local_e0);
      local_8 = 0;
      local_5c = local_5c + 1;
      local_a4 = (**(code **)(*(int *)*local_90 + 0x24))((int *)*local_90,local_5c,&local_e0);
      FUN_4541534f(local_a4);
      CComQIPtr<>(&local_2c,(undefined4 *)local_e0.n1._8_4_);
      local_60 = 0;
      local_8._0_1_ = 2;
      (**(code **)(*local_2c + 0x68))(local_2c,&local_60);
      bVar1 = FUN_45402d1b(&local_60,(BSTR)"Barcode");
      if (bVar1) {
        local_68 = local_68 + 1;
        CComQIPtr<>(&local_48,local_2c);
        local_8._0_1_ = 3;
        if (((local_48 != (int *)0x0) &&
            ((**(code **)(*local_48 + 0xc0))(local_48,&local_ac), local_ac != 0)) &&
           (bVar1 = FUN_45402d1b((void *)((int)this + 0xe0),L"CLARISOFT"), !bVar1)) {
          (**(code **)(*local_48 + 0xc4))(local_48,0);
          local_50 = 0;
          (**(code **)(*local_2c + 0x80))(local_2c,&local_50);
          (**(code **)(**(int **)((int)this + 0x34) + 0x54))(*(int **)((int)this + 0x34),&local_78);
          iVar2 = local_50;
          if (local_78 == 0) {
            fVar10 = FUN_45406d26((int)this);
            local_30 = (float)fVar10;
            local_50 = (int)((float)iVar2 * local_30 + DAT_45447488);
          }
          local_3c = 0;
          (**(code **)(**(int **)((int)this + 0x6c) + 0x34))(*(int **)((int)this + 0x6c),&local_3c);
          iVar2 = (int)((float)local_50 / (float)local_3c + DAT_45447488);
          if (1 < iVar2) {
            iVar2 = iVar2 + -1;
          }
          iVar6 = iVar2 * local_3c;
          if (local_78 == 0) {
            fVar10 = FUN_45406d26((int)this);
            local_30 = (float)fVar10;
            iVar6 = (int)((float)iVar6 / local_30 + DAT_45447488);
          }
          (**(code **)(*local_2c + 0x84))(local_2c,iVar6);
          FUN_45429f70((uint *)&local_f0,0,0x10);
          VariantInit(&local_f0);
          local_8._0_1_ = 4;
          FUN_454028b9(&local_7c,"/#HumanReadable#/");
          local_8._0_1_ = 5;
          FUN_4542e5ba(local_68,local_28,10,10);
          iVar6 = FUN_45404e77(&local_7c,local_28);
          if (iVar6 < 0) {
LAB_45419916:
                    /* WARNING: Subroutine does not return */
            FUN_45401d09(iVar6);
          }
          (**(code **)(*(int *)*local_90 + 0x28))((int *)*local_90,0,local_7c,0,&local_f0);
          CComQIPtr<>(&local_34,(undefined4 *)local_f0.n1._8_4_);
          local_8._0_1_ = 6;
          (**(code **)(*local_2c + 0x2c))(local_2c,&local_a8);
          (**(code **)(*local_34 + 0x30))(local_34,local_a8);
          (**(code **)(*local_2c + 0x34))(local_2c,&local_88);
          (**(code **)(*local_2c + 0x80))(local_2c,&local_a0);
          local_88 = local_88 + local_a0;
          (**(code **)(*local_34 + 0x38))(local_34,local_88);
          (**(code **)(*local_34 + 0x8c))(local_34,iVar2 + 1);
          CComQIPtr<>(&local_54,local_34);
          local_98 = 1;
          CComQIPtr<>(&local_94,local_2c);
          local_8._0_1_ = 8;
          if (local_94 != (int *)0x0) {
            (**(code **)(*local_94 + 0x168))(local_94,&local_98);
          }
          (**(code **)(*local_54 + 0xb4))(local_54,local_98 * local_3c);
          (**(code **)(*local_54 + 0x84))(local_54,local_3c);
          (**(code **)(*local_2c + 0x78))(local_2c,&local_64);
          (**(code **)(*local_54 + 0x7c))(local_54,local_64);
          FUN_454028b9(&local_4c,"HUMAN READABLE!");
          local_8._0_1_ = 9;
          (**(code **)(*local_2c + 0x98))(local_2c,&local_4c);
          piVar7 = (int *)0x0;
          local_44 = (int *)0x0;
          FUN_45429f70((uint *)&local_100,0,0x10);
          VariantInit(&local_100);
          local_8._0_1_ = 0xb;
          (**(code **)(**(int **)((int)this + 0x38) + 0x474))
                    (*(int **)((int)this + 0x38),&local_100);
          CComQIPtr<>(&local_6c,(undefined4 *)local_100.n1._8_4_);
          local_8 = CONCAT31(local_8._1_3_,0xc);
          (**(code **)(*local_6c + 0x24))(local_6c,&local_84);
          if ((0 < local_84) && (iVar2 = 0, 0 < local_84)) {
            do {
              FUN_45429f70((uint *)&local_c0,0,0x10);
              VariantInit(&local_c0);
              iVar2 = iVar2 + 1;
              local_8._0_1_ = 0xd;
              (**(code **)(*local_6c + 0x20))(local_6c,iVar2,&local_c0);
              CComQIPtr<>(&local_38,(undefined4 *)local_c0.n1._8_4_);
              local_8._0_1_ = 0xe;
              (**(code **)(*local_38 + 0x3c))(local_38,&local_9c);
              if (piVar7 == (int *)0x0) {
                FUN_4541a358(&local_38,(int *)&local_44);
                local_8._0_1_ = 0xd;
                if (local_38 != (int *)0x0) {
                  (**(code **)(*local_38 + 8))(local_38);
                }
                local_8 = CONCAT31(local_8._1_3_,0xc);
                VariantClear(&local_c0);
                piVar7 = local_44;
              }
              else {
                piVar11 = *(int **)((int)this + 0x6c);
                iVar6 = local_9c;
                if (piVar11 != (int *)0x0) {
                  (**(code **)(*piVar11 + 4))(piVar11);
                }
                bVar1 = FUN_4541c517(piVar11,iVar6);
                if (bVar1) {
                  local_30 = 0.0;
                  (**(code **)(*piVar7 + 0x3c))(piVar7,&local_30);
                  if (local_9c < (int)local_30) {
                    FUN_4541a358(&local_38,(int *)&local_44);
                    piVar7 = local_44;
                  }
                }
                local_8._0_1_ = 0xd;
                if (local_38 != (int *)0x0) {
                  (**(code **)(*local_38 + 8))(local_38);
                }
                local_8 = CONCAT31(local_8._1_3_,0xc);
                VariantClear(&local_c0);
              }
            } while (iVar2 < local_84);
          }
          local_80 = 0;
          (**(code **)(*piVar7 + 0x44))(piVar7,&local_80);
          iVar2 = local_64;
          if (local_78 == 0) {
            fVar10 = FUN_45406d0a((int)this);
            local_30 = (float)fVar10;
            iVar2 = (int)((float)iVar2 * local_30 + DAT_45447488);
          }
          UVar3 = iVar2 / local_80;
          UVar4 = SysStringLen(local_4c);
          if ((int)UVar3 < (int)UVar4) {
            UVar3 = UVar4;
          }
          fVar8 = (float)((int)((UVar3 - UVar4) + 1) / 2);
          _Memory = (uint *)FUN_454294e2((int)fVar8 + 1);
          fVar5 = 0.0;
          if (0 < (int)fVar8) {
            local_30 = fVar8;
            FUN_45429f70(_Memory,0x20,(uint)fVar8);
            fVar5 = fVar8;
          }
          *(undefined1 *)((int)fVar5 + (int)_Memory) = 0;
          FUN_454028b9(&local_8c,(char *)_Memory);
          local_8._0_1_ = 0xf;
          FID_conflict__free(_Memory);
          FUN_454028b9(&local_74,"");
          local_8._0_1_ = 0x10;
          iVar6 = FUN_45404f92(&local_74,local_8c);
          if ((iVar6 < 0) ||
             (iVar6 = FUN_45404f92(&local_74,local_4c), bstrString = local_74, iVar6 < 0))
          goto LAB_45419916;
          (**(code **)(*local_34 + 0x9c))(local_34,local_74);
          local_40 = (int *)0x0;
          local_8._0_1_ = 0x11;
          (**(code **)(*local_34 + 0x5c))(local_34,&local_40);
          local_58 = (int *)0x0;
          local_8._0_1_ = 0x12;
          (**(code **)(*local_2c + 0x5c))(local_2c,&local_58);
          if ((local_40 != (int *)0x0) && (local_58 != (int *)0x0)) {
            FUN_45429f70((uint *)&local_d0,0,0x10);
            VariantInit(&local_d0);
            local_d0.n1._8_4_ = bstrString;
            local_8._0_1_ = 0x13;
            (**(code **)(*local_40 + 0x28))(local_40,0,0xffffffff,1,0,&local_d0);
            VariantClear(&local_d0);
          }
          local_8._0_1_ = 0x11;
          if (local_58 != (int *)0x0) {
            (**(code **)(*local_58 + 8))(local_58);
          }
          local_8._0_1_ = 0x10;
          if (local_40 != (int *)0x0) {
            (**(code **)(*local_40 + 8))(local_40);
          }
          pcVar9 = SysFreeString_exref;
          SysFreeString(bstrString);
          SysFreeString(local_8c);
          local_8._0_1_ = 0xb;
          if (local_6c != (int *)0x0) {
            (**(code **)(*local_6c + 8))(local_6c);
          }
          VariantClear(&local_100);
          local_8._0_1_ = 9;
          (**(code **)(*piVar7 + 8))(piVar7);
          SysFreeString(local_4c);
          local_8._0_1_ = 7;
          if (local_94 != (int *)0x0) {
            (**(code **)(*local_94 + 8))(local_94);
          }
          local_8._0_1_ = 6;
          if (local_54 != (int *)0x0) {
            (**(code **)(*local_54 + 8))(local_54);
          }
          local_8._0_1_ = 5;
          if (local_34 != (int *)0x0) {
            (**(code **)(*local_34 + 8))(local_34);
          }
          SysFreeString(local_7c);
          VariantClear(&local_f0);
          this = local_b0;
        }
        local_8._0_1_ = 2;
        if (local_48 != (int *)0x0) {
          (**(code **)(*local_48 + 8))(local_48);
        }
      }
      (*pcVar9)(local_60);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_2c != (int *)0x0) {
        (**(code **)(*local_2c + 8))(local_2c);
      }
      local_8 = 0xffffffff;
      VariantClear(&local_e0);
    } while (local_5c < local_70);
  }
  FUN_4542a957();
  return;
}


