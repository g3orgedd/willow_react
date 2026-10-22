// Source: CiffMgr.dll @ 68105c1e; FID_conflict:assign

/* Library Function - Multiple Matches With Different Base Names
    public: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > & __thiscall std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >::assign(unsigned short
   const *)
    public: class std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> > & __thiscall std::basic_string<wchar_t,struct
   std::char_traits<wchar_t>,class std::allocator<wchar_t> >::assign(wchar_t const *)
   
   Library: Visual Studio 2012 Release */

void __thiscall FID_conflict_assign(void *this,wchar_t *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*param_1 != L'\0') {
    uVar1 = _wcslen(param_1);
  }
  FID_conflict_assign(this,(undefined8 *)param_1,uVar1);
  return;
}


