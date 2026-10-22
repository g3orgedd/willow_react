// Source: CLCiffConversion_Layout.dll @ 4541a37f; FUN_4541a37f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_4541a37f(undefined4 *param_1,int param_2,int param_3,undefined1 *param_4,
                 undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  int *local_60;
  VARIANTARG local_5c;
  int local_4c;
  int local_48;
  int local_44;
  int *local_40;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_3c [24];
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x5c;
  local_8 = 0x4541a38b;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_3c,"CCIFFAddTabFields::CreateCheckList");
  local_44 = 0;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  iVar1 = (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1,&local_44);
  if ((-1 < iVar1) && (iVar1 = 0, 0 < local_44)) {
    do {
      FUN_45429f70((uint *)&local_5c,0,0x10);
      VariantInit(&local_5c);
      iVar1 = iVar1 + 1;
      local_8._0_1_ = 1;
      iVar2 = (**(code **)(*(int *)*param_1 + 0x24))((int *)*param_1,iVar1,&local_5c);
      if (iVar2 < 0) {
LAB_4541a4db:
        VariantClear(&local_5c);
        break;
      }
      CComQIPtr<>(&local_40,(undefined4 *)local_5c.n1._8_4_);
      local_8._0_1_ = 2;
      (**(code **)(*local_40 + 0x2c))(local_40,&local_24);
      (**(code **)(*local_40 + 0x34))(local_40,&local_20);
      local_4c = 0;
      (**(code **)(*local_40 + 0x78))(local_40,&local_4c);
      local_1c = local_24 + local_4c;
      local_48 = 0;
      (**(code **)(*local_40 + 0x80))(local_40,&local_48);
      local_18 = local_48 + local_20;
      if (((param_3 < local_18) && (local_20 <= param_3)) && (param_2 <= local_24)) {
        if (local_24 == param_2) {
          local_8._0_1_ = 1;
          *param_4 = 0;
          if (local_40 != (int *)0x0) {
            (**(code **)(*local_40 + 8))(local_40);
          }
          goto LAB_4541a4db;
        }
        local_60 = local_40;
        FUN_4541222d(param_5,(int *)*param_5,&local_60);
      }
      local_8._0_1_ = 1;
      if (local_40 != (int *)0x0) {
        (**(code **)(*local_40 + 8))(local_40);
      }
      local_8._0_1_ = 0;
      VariantClear(&local_5c);
    } while (iVar1 < local_44);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_3c,true,0);
  FUN_4542a957();
  return;
}


