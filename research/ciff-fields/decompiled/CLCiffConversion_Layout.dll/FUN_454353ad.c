// Source: CLCiffConversion_Layout.dll @ 454353ad; __hextodec

/* Library Function - Single Match
    __hextodec
   
   Library: Visual Studio 2012 Release */

ushort __cdecl __hextodec(uint param_1)

{
  int iVar1;
  
  if (((param_1 & 0xff00) == 0) && (iVar1 = _isdigit(param_1 & 0xff), iVar1 != 0)) {
    return (ushort)param_1;
  }
  return ((ushort)param_1 & 0xffdf) - 7;
}


