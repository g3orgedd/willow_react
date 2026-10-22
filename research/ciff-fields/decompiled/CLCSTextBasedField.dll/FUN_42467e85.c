// Source: CLCSTextBasedField.dll @ 42467e85; FUN_42467e85

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_42467e85(int param_1)

{
  LPVOID *ppv;
  HRESULT HVar1;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x42467e91;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"ZipherBitmapFont::CheckBinaryFontInterfacePointer()");
  local_8 = 0;
  ppv = (LPVOID *)(param_1 + 4);
  if (*ppv == (LPVOID)0x0) {
    HVar1 = CoCreateInstance((IID *)&DAT_42496c84,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_4249b808,ppv);
    if ((HVar1 < 0) || (*ppv == (LPVOID)0x0)) {
      FUN_42403ff7(0x4249b8d0);
    }
    else {
      FUN_42468233(param_1);
    }
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4246ecf6();
  return;
}


