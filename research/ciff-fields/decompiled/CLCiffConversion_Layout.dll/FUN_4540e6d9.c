// Source: CLCiffConversion_Layout.dll @ 4540e6d9; FUN_4540e6d9

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4540e6d9(void *this,BSTR param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 local_184 [19];
  undefined4 local_138;
  wchar_t *local_134;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_130 [24];
  char local_118 [272];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x174;
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_130,"ZipherBitmapFont::GetCharSpace()");
  local_8._0_1_ = 1;
  _sprintf_s(local_118,0x104,"%ls\\%ls.zfbf",*(undefined4 *)((int)this + 0x44),param_1);
  FUN_4540d89d(local_184);
  local_8._0_1_ = 2;
  FUN_454028b9(&local_134,local_118);
  local_138 = 0xffffffff;
  local_8 = CONCAT31(local_8._1_3_,3);
  uVar1 = FUN_4540e0cf(local_184,local_134,&local_138);
  if (uVar1 == 0xffffffff) {
    *param_2 = 1;
  }
  else {
    iVar2 = FUN_4540ddf0(local_184,uVar1);
    *param_2 = (uint)*(ushort *)(iVar2 + 0x58);
  }
  SysFreeString(local_134);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_4540d932(local_184);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_130,true,0);
  SysFreeString(param_1);
  FUN_4542a957();
  return;
}


