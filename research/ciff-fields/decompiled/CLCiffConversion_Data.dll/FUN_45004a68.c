// Source: CLCiffConversion_Data.dll @ 45004a68; FID_conflict:assign

/* Library Function - Multiple Matches With Different Base Names
    public: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > & __thiscall std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >::assign(unsigned short
   const *,unsigned int)
    public: class std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> > & __thiscall std::basic_string<wchar_t,struct
   std::char_traits<wchar_t>,class std::allocator<wchar_t> >::assign(wchar_t const *,unsigned int)
   
   Library: Visual Studio 2015 Release */

undefined8 * __thiscall FID_conflict_assign(void *this,undefined8 *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  undefined8 *puVar3;
  void *pvVar4;
  
  uVar2 = FID_conflict__Inside(this,(undefined4 *)param_1);
  if ((char)uVar2 == '\0') {
    bVar1 = FUN_4500458e(this,param_2,'\0');
    if (bVar1) {
      puVar3 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
        puVar3 = *(undefined8 **)this;
      }
      copy(puVar3,param_1,param_2);
      *(uint *)((int)this + 0x10) = param_2;
      pvVar4 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
        pvVar4 = *(void **)this;
      }
      *(undefined2 *)((int)pvVar4 + param_2 * 2) = 0;
    }
  }
  else {
    pvVar4 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
      pvVar4 = *(void **)this;
    }
    this = FUN_450049ae(this,this,(int)param_1 - (int)pvVar4 >> 1,param_2);
  }
  return this;
}


