// Source: CLCiffConversion_Data.dll @ 4500bb81; FUN_4500bb81

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4500bb81(void *this,int *param_1)

{
  int *piVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  UINT UVar5;
  undefined4 *puVar6;
  BSTR bstrString;
  code *pcVar7;
  _union_2683 local_6c;
  undefined4 local_5c;
  int *local_58;
  int *local_54;
  BSTR local_50;
  int local_4c;
  int local_48;
  int *local_44;
  BSTR local_40;
  undefined4 local_3c;
  BSTR local_38;
  int *local_34;
  BSTR local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x5c;
  local_8 = 0x4500bb8d;
  local_34 = param_1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFCharTranslate::Convert");
  local_8 = 0;
  FUN_45005aac(0x4503db14);
  piVar3 = param_1 + 1;
  local_54 = piVar3;
  (**(code **)(*(int *)*piVar3 + 100))((int *)*piVar3,&local_30);
  if (local_30 == (BSTR)0x0) {
    bstrString = (BSTR)0x0;
    local_30 = (BSTR)0x0;
    local_8._0_1_ = 1;
    FUN_4500ab7b(&local_5c);
    local_8 = CONCAT31(local_8._1_3_,2);
    (*(code *)**(undefined4 **)*piVar3)((undefined4 *)*piVar3,&DAT_4503ecc0,&local_58);
    pcVar7 = SysFreeString_exref;
    if ((*(char *)(*(int *)(*(int *)((int)this + -8) + 4) + 0x3c + (int)this) != '\0') ||
       (bVar2 = FUN_4500fc4a((int)&local_5c), !bVar2)) {
      piVar3 = FUN_4500ff2e(&local_5c,&local_38);
      FUN_450058c3(&local_30,piVar3);
      SysFreeString(local_38);
      FUN_450072f3(local_34,&local_50);
      FUN_45001f8d((uint *)&local_6c);
      bstrString = local_30;
      local_8._0_1_ = 4;
      iVar4 = (**(code **)(**(int **)((int)this + -4) + 0x28))
                        (*(int **)((int)this + -4),local_50,&local_6c,local_30);
      if (iVar4 != 0) {
        VariantClear((VARIANTARG *)&local_6c.n2);
        SysFreeString(local_50);
        local_8 = CONCAT31(local_8._1_3_,1);
        if (local_58 != (int *)0x0) {
          (**(code **)(*local_58 + 8))(local_58);
        }
        SysFreeString(bstrString);
        goto LAB_4500beba;
      }
      if (((local_6c._0_4_ & 0x2000) != 0) && ((SAFEARRAY *)local_6c._8_4_ != (SAFEARRAY *)0x0)) {
        SafeArrayGetUBound((SAFEARRAY *)local_6c._8_4_,1,(LONG *)&local_38);
        SafeArrayGetLBound((SAFEARRAY *)local_6c._8_4_,1,&local_4c);
        UVar5 = (int)local_38 + (1 - local_4c);
        if (0 < (int)UVar5) {
          FUN_4500aba2(&local_40,UVar5);
          local_8._0_1_ = 5;
          local_48 = local_4c;
          if (local_4c <= (int)local_38) {
            do {
              SafeArrayGetElement((SAFEARRAY *)local_6c._8_4_,&local_48,&local_3c);
              local_40[local_48 - local_4c] = (OLECHAR)local_3c;
              local_48 = local_48 + 1;
            } while (local_48 <= (int)local_38);
          }
          local_40[local_48 - local_4c] = L'\0';
          (**(code **)(*(int *)*local_54 + 0x9c))((int *)*local_54,local_40);
          pcVar7 = SysFreeString_exref;
          SysFreeString(local_40);
        }
      }
      VariantClear((VARIANTARG *)&local_6c.n2);
      local_8 = CONCAT31(local_8._1_3_,2);
      (*pcVar7)(local_50);
    }
    local_40 = (BSTR)0x0;
    local_44 = (int *)FUN_45013f7b((int *)0x0,(int *)0x0);
    local_8._0_1_ = 6;
    FUN_450022ba((void *)((int)this + *(int *)(*(int *)((int)this + -8) + 4) + 0x58),local_54);
    puVar6 = FUN_45007442(local_34,&local_3c);
    local_8._0_1_ = 7;
    FUN_45002365((void *)((int)this + *(int *)(*(int *)((int)this + -8) + 4) + 0x5c),
                 (LPCWSTR)*puVar6);
    local_8._0_1_ = 6;
    (*pcVar7)(local_3c);
    puVar6 = FUN_450072f3(local_34,&local_3c);
    local_8._0_1_ = 8;
    FUN_45002365((void *)((int)this + *(int *)(*(int *)((int)this + -8) + 4) + 0x60),
                 (LPCWSTR)*puVar6);
    local_8 = CONCAT31(local_8._1_3_,6);
    (*pcVar7)(local_3c);
    FUN_45005aac(0x4503f6f0);
    FUN_4500735e(local_34,&local_44);
    piVar3 = (int *)*local_44;
    if (piVar3 != local_44) {
      do {
        FUN_4500b938((void *)((int)this + -8),(undefined4 *)piVar3[2],local_34);
        piVar3 = (int *)*piVar3;
        bstrString = local_30;
      } while (piVar3 != local_44);
    }
    piVar3 = (int *)((int)this + -8);
    FUN_45004f8d((int *)&local_44);
    piVar1 = *(int **)(*(int *)(*piVar3 + 4) + 0x58 + (int)this);
    if ((piVar1 != (int *)0x0) &&
       (*(undefined4 *)(*(int *)(*piVar3 + 4) + 0x58 + (int)this) = 0, piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    FUN_45002365((void *)((int)this + *(int *)(*piVar3 + 4) + 0x5c),L"");
    FUN_45002365((void *)((int)this + *(int *)(*piVar3 + 4) + 0x60),L"");
    FUN_4501423d((int *)&local_44);
    FID_conflict__free(local_44);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_58 != (int *)0x0) {
      (**(code **)(*local_58 + 8))(local_58);
    }
    SysFreeString(bstrString);
  }
LAB_4500beba:
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_45022eb8();
  return;
}


