// Source: CLCiffConversion_Layout.dll @ 45404996; copy

/* Library Function - Multiple Matches With Same Base Name
    public: static unsigned short * __cdecl std::char_traits<unsigned short>::copy(unsigned short
   *,unsigned short const *,unsigned int)
    public: static wchar_t * __cdecl std::char_traits<wchar_t>::copy(wchar_t *,wchar_t const
   *,unsigned int)
   
   Library: Visual Studio 2015 Release */

undefined8 * __cdecl copy(undefined8 *param_1,undefined8 *param_2,int param_3)

{
  undefined8 *puVar1;
  
  if (param_3 == 0) {
    return param_1;
  }
  puVar1 = FUN_45429920(param_1,param_2,param_3 * 2);
  return puVar1;
}


