// Source: CiffHelper.dll @ 4081a65d; FUN_4081a65d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_4081a65d(int *param_1)

{
  UINT UVar1;
  HRESULT HVar2;
  int iVar3;
  BSTR local_50;
  BSTR local_4c;
  int *local_48;
  BSTR local_44;
  int *local_40;
  CLSID local_3c;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x40;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCiffDataHelper::ApplyEncryption");
  CComQIPtr<>(&local_40,param_1);
  if (local_40 != (int *)0x0) {
    local_44 = (BSTR)0x0;
    local_8._0_1_ = 3;
    (**(code **)(*local_40 + 0x78))(local_40,&local_44);
    UVar1 = SysStringLen(local_44);
    if (UVar1 != 0) {
      local_50 = (BSTR)0x0;
      local_8._0_1_ = 4;
      (**(code **)(*local_40 + 0x60))(local_40,&local_50);
      CLSIDFromProgID(local_44,&local_3c);
      local_48 = (int *)0x0;
      local_8._0_1_ = 5;
      HVar2 = CoCreateInstance(&local_3c,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_4084c8a0,&local_48);
      if (HVar2 == 0) {
        local_4c = (BSTR)0x0;
        local_8._0_1_ = 6;
        iVar3 = (**(code **)(*local_48 + 0xc))(local_48,local_50,&local_4c);
        if (iVar3 == 0) {
          FUN_40819678(0x4084c8d4);
          (**(code **)(*local_40 + 100))(local_40,local_4c);
        }
        SysFreeString(local_4c);
      }
      else {
        FUN_40819678(0x4084c8ec);
      }
      local_8._0_1_ = 4;
      if (local_48 != (int *)0x0) {
        (**(code **)(*local_48 + 8))(local_48);
      }
      SysFreeString(local_50);
    }
    SysFreeString(local_44);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_40 != (int *)0x0) {
    (**(code **)(*local_40 + 8))(local_40);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  FUN_4082d4c6();
  return;
}


