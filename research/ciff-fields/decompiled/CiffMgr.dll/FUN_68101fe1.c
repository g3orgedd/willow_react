// Source: CiffMgr.dll @ 68101fe1; FUN_68101fe1

basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_68101fe1(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,int param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = std::_Syserror_map(param_2);
  pcVar2 = "unknown error";
  if (pcVar1 != (char *)0x0) {
    pcVar2 = pcVar1;
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>(param_1,pcVar2);
  return param_1;
}


