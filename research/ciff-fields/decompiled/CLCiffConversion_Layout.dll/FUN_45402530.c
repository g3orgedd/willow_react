// Source: CLCiffConversion_Layout.dll @ 45402530; _Allocate<>

/* Library Function - Multiple Matches With Same Base Name
    unsigned short * __cdecl std::_Allocate<unsigned short>(unsigned int,unsigned short *)
    wchar_t * __cdecl std::_Allocate<wchar_t>(unsigned int,wchar_t *)
   
   Library: Visual Studio 2012 Release */

int __cdecl _Allocate<>(uint param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  if ((param_1 < 0x80000000) && (iVar1 = FUN_454298b4(param_1 * 2), iVar1 != 0)) {
    return iVar1;
  }
  iVar1 = FUN_45429455();
  return iVar1;
}


