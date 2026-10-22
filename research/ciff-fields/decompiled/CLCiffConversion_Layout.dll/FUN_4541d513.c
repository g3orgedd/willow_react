// Source: CLCiffConversion_Layout.dll @ 4541d513; FUN_4541d513

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4541d513(void *this,int param_1)

{
  HRESULT HVar1;
  int iVar2;
  int iVar3;
  BSTR local_44;
  BSTR local_40;
  void *local_3c;
  BSTR local_38;
  int local_34;
  BSTR local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x4541d51f;
  local_3c = this;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCapabilitiesFont::GetNearestPitch");
  local_8 = 0;
  FUN_454028ee(&local_44,L"ScalableBitmap");
  local_8._0_1_ = 1;
  FUN_454028ee(&local_38,L"TrueType");
  local_8._0_1_ = 2;
  FUN_4541d03c(this,&local_30);
  local_8._0_1_ = 3;
  HVar1 = VarBstrCmp(local_30,local_38,0x400,0);
  if (HVar1 == 1) {
    local_34 = FUN_4541d4f8(this);
    iVar2 = FUN_4541d4dd(this);
    iVar3 = param_1;
    if ((((iVar2 != 0) && (local_34 != 0)) && (iVar3 = iVar2, param_1 <= iVar2)) &&
       (iVar3 = param_1, param_1 < local_34)) {
      iVar3 = local_34;
    }
    FUN_4541da34(local_3c,&local_40);
    local_8._0_1_ = 4;
    FUN_4541d731(&local_40,iVar3);
    local_8 = CONCAT31(local_8._1_3_,3);
    SysFreeString(local_40);
    FUN_4540303d(0x454495b0);
  }
  else {
    FUN_45402ac2(&local_34,local_30);
    local_8 = CONCAT31(local_8._1_3_,5);
    FUN_4540303d(0x4544958c);
    FUN_45402c5d(&local_34);
  }
  SysFreeString(local_30);
  SysFreeString(local_38);
  SysFreeString(local_44);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


