// Source: CLCiffConversion_Layout.dll @ 454140ab; FUN_454140ab

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall
FUN_454140ab(void *this,int *param_1,void *param_2,int *param_3,undefined4 param_4,int param_5,
            undefined4 param_6,undefined4 param_7,int *param_8,int param_9,uint *param_10,
            undefined4 param_11,undefined4 param_12,int param_13)

{
  longlong lVar1;
  BSTR bstrString;
  int *piVar2;
  bool bVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  OLECHAR *pOVar11;
  uint *puVar12;
  float10 fVar13;
  VARIANTARG local_ac;
  _union_2683 local_9c;
  uint local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  void *local_78;
  BSTR local_74;
  BSTR local_70;
  BSTR local_6c;
  int *local_68;
  BSTR local_64;
  BSTR local_60;
  int *local_5c;
  uint local_58;
  OLECHAR *local_54;
  uint *local_50;
  int *local_4c;
  BSTR local_48;
  int *local_44;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_40 [24];
  wchar_t local_28 [16];
  int local_8;
  undefined4 uStack_4;
  
  puVar12 = param_10;
  uStack_4 = 0x9c;
  local_4c = param_1;
  local_78 = param_2;
  local_50 = param_10;
  local_8 = 1;
  local_48 = this;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_40,"CCIFFAddTabFields::AddTabField");
  local_8._0_1_ = 2;
  (**(code **)(**(int **)((int)this + 0x34) + 0x54))(*(int **)((int)this + 0x34),&local_84);
  (**(code **)(*param_8 + 0x44))(param_8,&local_80);
  if (local_80 != 0) {
    if (local_84 == 0) {
      fVar13 = FUN_45406d0a((int)this);
      local_54 = (OLECHAR *)(float)fVar13;
      param_9 = (int)((float)param_9 * (float)local_54 + DAT_45447488);
    }
    iVar10 = param_9;
    local_64 = (BSTR)(float)param_9;
    *puVar12 = *puVar12 + 1;
    uVar9 = (uint)((float)local_64 / (float)local_80 + DAT_45447488);
    lVar1 = (ulonglong)(uVar9 + 1) * 2;
    local_8c = uVar9;
    local_54 = (OLECHAR *)FUN_454294e2(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    uVar7 = 0;
    if (0 < (int)uVar9) {
      pOVar11 = local_54;
      for (uVar7 = uVar9 >> 1; uVar7 != 0; uVar7 = uVar7 - 1) {
        pOVar11[0] = L' ';
        pOVar11[1] = L' ';
        pOVar11 = pOVar11 + 2;
      }
      for (uVar8 = (uint)((uVar9 & 1) != 0); uVar7 = uVar9, puVar12 = local_50, local_58 = uVar9,
          uVar8 != 0; uVar8 = uVar8 - 1) {
        *pOVar11 = L' ';
        pOVar11 = pOVar11 + 1;
      }
    }
    local_54[uVar7] = L'\0';
    FUN_454028ee(&local_60,L"Tab");
    local_8._0_1_ = 3;
    FUN_4542e5e3(*puVar12,local_28,10,10);
    iVar4 = FUN_45404e77(&local_60,local_28);
    if (iVar4 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_45401d09(iVar4);
    }
    FUN_45429f70((uint *)&local_9c,0,0x10);
    VariantInit((VARIANTARG *)&local_9c.n2);
    local_8._0_1_ = 4;
    iVar4 = (**(code **)(*(int *)*local_4c + 0x28))((int *)*local_4c,0,local_60,0,&local_9c);
    if ((-1 < iVar4) && (local_9c.n2.vt == 9)) {
      local_44 = (int *)0x0;
      local_8._0_1_ = 5;
      iVar4 = (*(code *)**(undefined4 **)local_9c._8_4_)(local_9c._8_4_,&DAT_454486ec,&local_44);
      if ((-1 < iVar4) && (local_44 != (int *)0x0)) {
        (**(code **)(*local_44 + 0x30))(local_44,param_11);
        (**(code **)(*local_44 + 0x38))(local_44,param_12);
        (**(code **)(*local_44 + 0x84))(local_44,param_13);
        if (local_84 == 0) {
          fVar13 = FUN_45406d0a((int)local_48);
          local_48 = (BSTR)(float)fVar13;
          iVar10 = (int)((float)local_64 / (float)local_48 + DAT_45447488);
          param_9 = iVar10;
        }
        (**(code **)(*local_44 + 0x7c))(local_44,iVar10);
        (**(code **)(*local_44 + 0x8c))(local_44,param_5 / param_13 + 1);
        FUN_4540303d(0x4544a160);
        piVar2 = local_44;
        puVar5 = FUN_454028ee(&local_64,L"TabField");
        local_8._0_1_ = 6;
        (**(code **)(*piVar2 + 0x6c))(piVar2,*puVar5);
        SysFreeString(local_64);
        local_68 = (int *)0x0;
        local_8._0_1_ = 7;
        (**(code **)(*local_44 + 0x5c))(local_44,&local_68);
        FUN_45429f70((uint *)&local_ac,0,0x10);
        VariantInit(&local_ac);
        local_8._0_1_ = 8;
        (**(code **)(*local_68 + 0x28))(local_68,0,0,1,0,&local_ac);
        CComQIPtr<>(&local_5c,(undefined4 *)local_ac.n1._8_4_);
        local_8._0_1_ = 9;
        FUN_454028ee(&local_48,local_54);
        bstrString = local_48;
        local_8._0_1_ = 10;
        (**(code **)(*local_5c + 0x5c))(local_5c,local_48);
        (**(code **)(*local_5c + 100))(local_5c,bstrString);
        (**(code **)(*local_5c + 0x98))(local_5c,local_8c);
        (**(code **)(*local_44 + 0x9c))(local_44,bstrString);
        (**(code **)(*param_8 + 0x3c))(param_8,&local_88);
        local_7c = 1;
        CComQIPtr<>(&local_50,local_44);
        local_8._0_1_ = 0xb;
        if (local_50 != (uint *)0x0) {
          (**(code **)(*local_50 + 0x168))(local_50,&local_7c);
        }
        (**(code **)(*local_44 + 0xb4))(local_44,local_7c * local_88);
        local_70 = (BSTR)0x0;
        local_8._0_1_ = 0xc;
        (**(code **)(*param_8 + 0x1c))(param_8,&local_70);
        (**(code **)(*local_44 + 0xac))(local_44,local_70);
        local_74 = (BSTR)0x0;
        local_8._0_1_ = 0xd;
        (**(code **)(*param_8 + 0x24))(param_8,&local_74);
        FUN_45404c34(&local_58);
        local_8._0_1_ = 0xe;
        uVar6 = FUN_454062e6(&local_74);
        (**(code **)(*local_44 + 0x100))(local_44,uVar6);
        local_6c = (BSTR)0x0;
        local_8 = CONCAT31(local_8._1_3_,0xf);
        (**(code **)(*param_8 + 0x9c))(param_8,&local_6c);
        bVar3 = FUN_45402d4b(&local_6c,L"TrueType");
        if (bVar3) {
          (**(code **)(*local_44 + 0x128))(local_44,1);
        }
        local_4c = local_44;
        if (local_44 != (int *)0x0) {
          (**(code **)(*local_44 + 4))(local_44);
        }
        local_8._0_1_ = 0x10;
        FUN_4542278f(local_78,&local_4c);
        FUN_4542278f(local_78,&param_3);
        local_8._0_1_ = 0xf;
        if (local_4c != (int *)0x0) {
          (**(code **)(*local_4c + 8))(local_4c);
        }
        SysFreeString(local_6c);
        local_8._0_1_ = 0xd;
        FUN_45404cb7(&local_58);
        SysFreeString(local_74);
        SysFreeString(local_70);
        local_8._0_1_ = 10;
        if (local_50 != (uint *)0x0) {
          (**(code **)(*local_50 + 8))(local_50);
        }
        SysFreeString(bstrString);
        local_8._0_1_ = 8;
        if (local_5c != (int *)0x0) {
          (**(code **)(*local_5c + 8))(local_5c);
        }
        VariantClear(&local_ac);
        local_8._0_1_ = 5;
        if (local_68 != (int *)0x0) {
          (**(code **)(*local_68 + 8))(local_68);
        }
      }
      local_8._0_1_ = 4;
      if (local_44 != (int *)0x0) {
        (**(code **)(*local_44 + 8))(local_44);
      }
    }
    FID_conflict__free(local_54);
    VariantClear((VARIANTARG *)&local_9c.n2);
    SysFreeString(local_60);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_40,true,0);
  local_8 = (uint)local_8._1_3_ << 8;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 8))(param_3);
  }
  local_8 = 0xffffffff;
  if (param_8 != (int *)0x0) {
    (**(code **)(*param_8 + 8))(param_8);
  }
  FUN_4542a957();
  return;
}


