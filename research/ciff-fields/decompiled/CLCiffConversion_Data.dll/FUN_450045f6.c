// Source: CLCiffConversion_Data.dll @ 450045f6; std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Inside

/* Library Function - Single Match
    public: bool __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::_Inside(char const *)
   
   Library: Visual Studio 2015 Release */

bool __thiscall
std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Inside
          (basic_string<char,std::char_traits<char>,std::allocator<char>_> *this,char *param_1)

{
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *pbVar1;
  
  if (param_1 != (char *)0x0) {
    pbVar1 = this;
    if (0xf < *(uint *)(this + 0x14)) {
      pbVar1 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this;
    }
    if (pbVar1 <= param_1) {
      pbVar1 = this;
      if (0xf < *(uint *)(this + 0x14)) {
        pbVar1 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this;
      }
      if (param_1 < pbVar1 + *(int *)(this + 0x10)) {
        return true;
      }
    }
  }
  return false;
}


