// Source: CLCiffConversion_Data.dll @ 45007968; FID_conflict:_Chassign

/* Library Function - Multiple Matches With Different Base Names
    public: void __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::_Chassign(unsigned int,unsigned int,unsigned
   short)
    public: void __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::_Chassign(unsigned int,unsigned int,wchar_t)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall FID_conflict__Chassign(void *this,int param_1,size_t param_2,wchar_t param_3)

{
  if (param_2 == 1) {
    if (7 < *(uint *)((int)this + 0x14)) {
      this = *(void **)this;
    }
    *(wchar_t *)((int)this + param_1 * 2) = param_3;
  }
  else {
    if (7 < *(uint *)((int)this + 0x14)) {
      this = *(void **)this;
    }
    _wmemset((wchar_t *)((int)this + param_1 * 2),param_3,param_2);
  }
  return;
}


