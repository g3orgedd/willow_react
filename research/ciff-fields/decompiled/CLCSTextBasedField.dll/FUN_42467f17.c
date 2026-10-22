// Source: CLCSTextBasedField.dll @ 42467f17; FUN_42467f17

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_42467f17(void *this,BSTR param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 local_288 [19];
  undefined4 local_23c;
  wchar_t *local_238;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_234 [24];
  wchar_t local_21c [266];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x278;
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_234,"ZipherBitmapFont::GetCharSpace()");
  local_8._0_1_ = 1;
  _swprintf_s(local_21c,0x104,L"%ls\\%ls.zfbf",*(undefined4 *)((int)this + 0x44),param_1);
  FUN_424671e1(local_288);
  local_8._0_1_ = 2;
  FUN_424037d2(&local_238,local_21c);
  local_23c = 0xffffffff;
  local_8 = CONCAT31(local_8._1_3_,3);
  uVar1 = FUN_424679df(local_288,local_238,&local_23c);
  if (uVar1 == 0xffffffff) {
    *param_2 = 1;
  }
  else {
    iVar2 = FUN_42467734(local_288,uVar1);
    *param_2 = (uint)*(ushort *)(iVar2 + 0x58);
  }
  SysFreeString(local_238);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_42467276(local_288);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_234,true,0);
  SysFreeString(param_1);
  FUN_4246ecf6();
  return;
}


