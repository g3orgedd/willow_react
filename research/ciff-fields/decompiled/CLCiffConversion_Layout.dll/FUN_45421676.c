// Source: CLCiffConversion_Layout.dll @ 45421676; FUN_45421676

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_45421676(void *this,int *param_1,void *param_2)

{
  undefined4 *this_00;
  bool bVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  code *pcVar7;
  int *piVar8;
  float10 fVar9;
  undefined4 local_58;
  void *local_54;
  BSTR local_50;
  void *local_4c;
  int local_48;
  float local_44;
  BSTR local_40;
  int local_3c;
  float local_38;
  BSTR local_34;
  float local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  local_8 = 0x45421682;
  local_54 = param_2;
  local_4c = this;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFFontConvert::SetUnavailableFont");
  local_8 = 0;
  FUN_4541cdb6(param_2,&local_58);
  local_8 = CONCAT31(local_8._1_3_,1);
  fVar2 = (float)FUN_4541cded((int)param_2);
  local_30 = fVar2;
  iVar3 = FUN_4541d01d((int)param_2);
  if (iVar3 == 0) {
    local_34 = (BSTR)0x0;
    local_30 = 0.0;
    piVar8 = *(int **)(*(int *)(*(int *)((int)this + 4) + 4) + 0x3c + (int)this);
    (**(code **)(*piVar8 + 0x34))(piVar8,&local_34);
    piVar8 = *(int **)(*(int *)(*(int *)((int)this + 4) + 4) + 0x40 + (int)this);
    (**(code **)(*piVar8 + 0x34))(piVar8,&local_30);
    local_30 = local_30 * _DAT_4544a730 + DAT_45447488;
    local_34 = (BSTR)((float)local_34 * _DAT_4544a730 + DAT_45447488);
    fVar2 = (float)(((int)local_30 * (int)fVar2) / (int)(float)local_34);
    local_44 = fVar2;
    fVar9 = FUN_4541c720((undefined4 *)((int)this + *(int *)(*(int *)((int)this + 4) + 4) + 0x60));
    local_40 = (BSTR)(float)fVar9;
    local_30 = (float)(int)((((float)local_40 * _DAT_4544a734) / _DAT_4544a72c) * (float)(int)fVar2)
    ;
  }
  else {
    fVar9 = FUN_4541c720((undefined4 *)((int)this + *(int *)(*(int *)((int)this + 4) + 4) + 0x60));
    local_40 = (BSTR)(float)fVar9;
    local_44 = (float)(int)((float)(int)fVar2 / (((float)local_40 * _DAT_4544a734) / _DAT_4544a72c)
                           + DAT_45447488);
  }
  piVar8 = *(int **)*param_1;
  puVar6 = (undefined4 *)piVar8[2];
  pcVar7 = SysFreeString_exref;
  if (piVar8 != (int *)*param_1) {
    do {
      this_00 = (undefined4 *)piVar8[2];
      FUN_454028b9(&local_34,"");
      local_8 = CONCAT31(local_8._1_3_,2);
      local_48 = 0;
      local_3c = 0;
      if (puVar6 != (undefined4 *)0x0) {
        piVar4 = FUN_4541db0b(puVar6,&local_50);
        FUN_454066f3(&local_34,piVar4);
        SysFreeString(local_50);
        FUN_454062e6(&local_34);
        bVar1 = FUN_4541e8f1(puVar6);
        if (bVar1) {
          local_3c = FUN_4541d513(this_00,(int)local_44);
          fVar9 = FUN_4541c720((undefined4 *)
                               ((int)local_4c + *(int *)(*(int *)((int)local_4c + 4) + 4) + 0x60));
          local_38 = (float)fVar9;
          local_48 = (int)(((local_38 * _DAT_4544a734) / _DAT_4544a72c) * (float)local_3c);
        }
        else {
          local_48 = FUN_4541d658(this_00,(int)local_30);
          fVar9 = FUN_4541c720((undefined4 *)
                               ((int)local_4c + *(int *)(*(int *)((int)local_4c + 4) + 4) + 0x60));
          local_38 = (float)fVar9;
          local_3c = (int)((float)(int)local_30 / ((local_38 * _DAT_4544a734) / _DAT_4544a72c) +
                          DAT_45447488);
        }
      }
      FUN_4541d9ab(this_00);
      bVar1 = FUN_4541e8f1(this_00);
      if (bVar1) {
        local_38 = (float)FUN_4541d513(this_00,(int)local_44);
      }
      else {
        local_38 = (float)FUN_4541d658(this_00,(int)local_30);
      }
      FUN_4541db0b(this_00,&local_40);
      local_8._0_1_ = 3;
      bVar1 = FUN_4541e8f1(this_00);
      fVar2 = local_44;
      if (!bVar1) {
        local_3c = local_48;
        fVar2 = local_30;
      }
      iVar3 = FUN_45416187(local_3c,(int)local_38,(int)fVar2);
      pcVar7 = SysFreeString_exref;
      if (iVar3 != local_3c) {
        puVar6 = this_00;
      }
      SysFreeString(local_40);
      local_8 = CONCAT31(local_8._1_3_,1);
      SysFreeString(local_34);
      piVar8 = (int *)*piVar8;
    } while (piVar8 != (int *)*param_1);
  }
  if (puVar6 == (undefined4 *)0x0) {
    FUN_4540303d(0x45449d08);
  }
  else {
    bVar1 = FUN_4541e8f1(puVar6);
    if (bVar1) {
      uVar5 = FUN_4541d513(puVar6,(int)local_44);
    }
    else {
      uVar5 = FUN_4541d658(puVar6,(int)local_30);
    }
    FUN_454214b0(local_54,puVar6,uVar5);
    puVar6 = FUN_4541db3e(puVar6,&local_38);
    local_8._0_1_ = 4;
    FUN_45402ac2(&local_50,(wchar_t *)*puVar6);
    local_8 = CONCAT31(local_8._1_3_,5);
    FUN_4540303d(0x45449d2c);
    FUN_45402c5d((int *)&local_50);
    (*pcVar7)(local_38);
  }
  (*pcVar7)(local_58);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


