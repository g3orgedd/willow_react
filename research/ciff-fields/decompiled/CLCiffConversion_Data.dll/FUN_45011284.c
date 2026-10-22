// Source: CLCiffConversion_Data.dll @ 45011284; FUN_45011284

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_45011284(void *this,int param_1)

{
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x45011290;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFConvertBase::PutDownloadOnly");
  local_8 = 0;
  if (param_1 == 1) {
    FUN_45005aac(0x4503eb78);
    *(undefined1 *)((int)this + 0xfc) = 1;
  }
  else {
    FUN_45005aac(0x4503eba8);
    *(undefined1 *)((int)this + 0xfc) = 0;
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_45022eb8();
  return;
}


