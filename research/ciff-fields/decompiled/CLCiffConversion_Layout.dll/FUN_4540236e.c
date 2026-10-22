// Source: CLCiffConversion_Layout.dll @ 4540236e; std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::assign

/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
   & __thiscall std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>
   >::assign(char const *,unsigned int)
   
   Library: Visual Studio 2015 Release */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::assign
          (basic_string<char,std::char_traits<char>,std::allocator<char>_> *this,char *param_1,
          uint param_2)

{
  bool bVar1;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *pbVar2;
  
  bVar1 = _Inside(this,param_1);
  if (bVar1) {
    pbVar2 = this;
    if (0xf < *(uint *)(this + 0x14)) {
      pbVar2 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this;
    }
    this = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
           FUN_454022da(this,(undefined8 *)this,(int)param_1 - (int)pbVar2,param_2);
  }
  else {
    bVar1 = FUN_454021f8(this,param_2,'\0');
    if (bVar1) {
      pbVar2 = this;
      if (0xf < *(uint *)(this + 0x14)) {
        pbVar2 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this;
      }
      if (param_2 != 0) {
        FUN_45429920((undefined8 *)pbVar2,(undefined8 *)param_1,param_2);
      }
      *(uint *)(this + 0x10) = param_2;
      pbVar2 = this;
      if (0xf < *(uint *)(this + 0x14)) {
        pbVar2 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this;
      }
      pbVar2[param_2] = (basic_string<char,std::char_traits<char>,std::allocator<char>_>)0x0;
    }
  }
  return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
}


