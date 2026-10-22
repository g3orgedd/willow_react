// Source: CLCiffConversion_Data.dll @ 4500a36e; FUN_4500a36e

basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_4500a36e(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,int param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = (char *)FUN_4502103b(param_2);
  pcVar2 = "unknown error";
  if (pcVar1 != (char *)0x0) {
    pcVar2 = pcVar1;
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>(param_1,pcVar2);
  return param_1;
}


