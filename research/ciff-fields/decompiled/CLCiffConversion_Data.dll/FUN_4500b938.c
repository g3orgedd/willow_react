// Source: CLCiffConversion_Data.dll @ 4500b938; FUN_4500b938

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4500b938(void *this,undefined4 *param_1,void *param_2)

{
  bool bVar1;
  int iVar2;
  UINT UVar3;
  BSTR local_68;
  OLECHAR local_64 [2];
  _union_2683 local_60;
  undefined4 local_50;
  int *local_4c;
  undefined4 *local_48;
  int local_44;
  BSTR local_40;
  int local_3c;
  int local_38;
  BSTR local_34;
  BSTR local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x58;
  local_8 = 0x4500b944;
  local_48 = param_1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFCharTranslate::Convert");
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  FUN_45005aac(0x4503db14);
  (**(code **)(**(int **)((int)param_2 + 4) + 100))(*(int **)((int)param_2 + 4),&local_30);
  if (local_30 == (BSTR)0x0) {
    FUN_4500732a(param_2,&local_34);
    local_8._0_1_ = 1;
    bVar1 = FUN_450023b0(&local_34,L"TimeText");
    if (((!bVar1) && (bVar1 = FUN_450023b0(&local_34,L"DateText"), !bVar1)) &&
       (bVar1 = FUN_450023b0(&local_34,L"OffsetDateText"), !bVar1)) {
      FUN_4500ab7b(&local_50);
      local_8._0_1_ = 2;
      (**(code **)**(undefined4 **)((int)param_2 + 4))
                (*(undefined4 **)((int)param_2 + 4),&DAT_4503ecc0,&local_4c);
      if ((*(char *)(*(int *)(*(int *)this + 4) + 0x44 + (int)this) != '\0') ||
         (bVar1 = FUN_4500fc4a((int)&local_50), !bVar1)) {
        FUN_4500ff2e(&local_50,&local_30);
        local_8._0_1_ = 3;
        FUN_4500fe88(local_48,&local_40);
        FUN_45001f8d((uint *)&local_60);
        local_8._0_1_ = 5;
        iVar2 = (**(code **)(**(int **)((int)this + 4) + 0x28))
                          (*(int **)((int)this + 4),local_40,&local_60,local_30);
        if (iVar2 == 0) {
          if (((local_60._0_4_ & 0x2000) != 0) && ((SAFEARRAY *)local_60._8_4_ != (SAFEARRAY *)0x0))
          {
            SafeArrayGetUBound((SAFEARRAY *)local_60._8_4_,1,&local_44);
            SafeArrayGetLBound((SAFEARRAY *)local_60._8_4_,1,&local_3c);
            UVar3 = (local_44 - local_3c) + 1;
            if (0 < (int)UVar3) {
              FUN_4500aba2(&local_68,UVar3);
              local_8._0_1_ = 6;
              local_38 = local_3c;
              if (local_3c <= local_44) {
                do {
                  SafeArrayGetElement((SAFEARRAY *)local_60._8_4_,&local_38,local_64);
                  local_68[local_38 - local_3c] = local_64[0];
                  local_38 = local_38 + 1;
                } while (local_38 <= local_44);
              }
              local_68[local_38 - local_3c] = L'\0';
              (**(code **)(*(int *)*local_48 + 0x5c))((int *)*local_48,local_68);
              SysFreeString(local_68);
            }
          }
          VariantClear((VARIANTARG *)&local_60.n2);
          SysFreeString(local_40);
          SysFreeString(local_30);
          local_8._0_1_ = 1;
          if (local_4c != (int *)0x0) {
            (**(code **)(*local_4c + 8))(local_4c);
          }
          SysFreeString(local_34);
          goto LAB_4500bb62;
        }
        VariantClear((VARIANTARG *)&local_60.n2);
        SysFreeString(local_40);
        SysFreeString(local_30);
      }
      local_8._0_1_ = 1;
      if (local_4c != (int *)0x0) {
        (**(code **)(*local_4c + 8))(local_4c);
      }
    }
    SysFreeString(local_34);
  }
LAB_4500bb62:
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_45022eb8();
  return;
}


