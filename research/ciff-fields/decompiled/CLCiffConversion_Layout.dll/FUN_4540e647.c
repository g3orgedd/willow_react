// Source: CLCiffConversion_Layout.dll @ 4540e647; FUN_4540e647

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_4540e647(int param_1)

{
  LPVOID *ppv;
  HRESULT HVar1;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x4540e653;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"ZipherBitmapFont::CheckBinaryFontInterfacePointer()");
  local_8 = 0;
  ppv = (LPVOID *)(param_1 + 4);
  if (*ppv == (LPVOID)0x0) {
    HVar1 = CoCreateInstance((IID *)&DAT_45447e34,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_45448420,ppv);
    if ((HVar1 < 0) || (*ppv == (LPVOID)0x0)) {
      FUN_4540500e(0x454484f4);
    }
    else {
      FUN_4540e972(param_1);
    }
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


