// Source: CLCiffConversion_Data.dll @ 45004695; std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy

/* Library Function - Single Match
    public: void __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::_Tidy(bool,unsigned int)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2019 Release */

void __thiscall
std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
          (basic_string<char,std::char_traits<char>,std::allocator<char>_> *this,bool param_1,
          uint param_2)

{
  undefined8 *_Memory;
  
  if ((param_1) && (0xf < *(uint *)(this + 0x14))) {
    _Memory = *(undefined8 **)this;
    if (param_2 != 0) {
      FUN_45021540((undefined8 *)this,_Memory,param_2);
    }
    FID_conflict__free(_Memory);
  }
  *(uint *)(this + 0x10) = param_2;
  *(undefined4 *)(this + 0x14) = 0xf;
  this[param_2] = (basic_string<char,std::char_traits<char>,std::allocator<char>_>)0x0;
  return;
}


