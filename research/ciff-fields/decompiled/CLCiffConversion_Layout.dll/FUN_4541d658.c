// Source: CLCiffConversion_Layout.dll @ 4541d658; FUN_4541d658

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4541d658(void *this,int param_1)

{
  HRESULT HVar1;
  BSTR local_3c;
  BSTR local_38;
  BSTR local_34;
  BSTR local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x4541d664;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCapabilitiesFont::GetNearestPointSize");
  local_8 = 0;
  FUN_454028ee(&local_38,L"ScalableBitmap");
  local_8._0_1_ = 1;
  FUN_454028ee(&local_34,L"TrueType");
  local_8._0_1_ = 2;
  FUN_4541d03c(this,&local_30);
  local_8._0_1_ = 3;
  HVar1 = VarBstrCmp(local_30,local_34,0x400,0);
  if (HVar1 != 1) {
    HVar1 = VarBstrCmp(local_30,local_38,0x400,0);
    if (HVar1 == 1) {
      FUN_4541da34(this,&local_3c);
      local_8._0_1_ = 4;
      FUN_4541d731(&local_3c,param_1);
      SysFreeString(local_3c);
    }
    else {
      FUN_4541d9ab(this);
    }
  }
  SysFreeString(local_30);
  SysFreeString(local_34);
  SysFreeString(local_38);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


