// Source: CLCiffConversion_Layout.dll @ 4541f8b2; FUN_4541f8b2

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_4541f8b2(undefined4 *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  VARIANTARG local_50;
  int local_40;
  int local_3c;
  int *local_38;
  BSTR local_34;
  wchar_t *local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x40;
  local_8 = 0x4541f8be;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFAddTabFields::RemoveExistingTabFields");
  local_8 = 0;
  (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1,&local_3c);
  iVar2 = 0;
  iVar3 = 1;
  if (0 < local_3c) {
    do {
      FUN_45429f70((uint *)&local_50,0,0x10);
      VariantInit(&local_50);
      local_8._0_1_ = 1;
      (**(code **)(*(int *)*param_1 + 0x24))((int *)*param_1,iVar3,&local_50);
      CComQIPtr<>(&local_38,(undefined4 *)local_50.n1._8_4_);
      local_34 = (BSTR)0x0;
      local_8._0_1_ = 3;
      (**(code **)(*local_38 + 0x68))(local_38,&local_34);
      bVar1 = FUN_45402d4b(&local_34,L"TabField");
      if (bVar1) {
        local_30 = (wchar_t *)0x0;
        local_8._0_1_ = 4;
        (**(code **)(*local_38 + 0x1c))(local_38,&local_30);
        (**(code **)(*(int *)*param_1 + 0x2c))((int *)*param_1,local_30);
        FUN_45402ac2(&local_40,local_30);
        local_8._0_1_ = 5;
        FUN_4540303d(0x4544a064);
        FUN_45402c5d(&local_40);
        SysFreeString(local_30);
      }
      else {
        iVar3 = iVar3 + 1;
      }
      SysFreeString(local_34);
      local_8._0_1_ = 1;
      if (local_38 != (int *)0x0) {
        (**(code **)(*local_38 + 8))(local_38);
      }
      local_8 = (uint)local_8._1_3_ << 8;
      VariantClear(&local_50);
      iVar2 = iVar2 + 1;
    } while (iVar2 < local_3c);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


