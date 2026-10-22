// Source: CLCiffConversion_Layout.dll @ 4542d3f7; _swprintf_s

/* Library Function - Single Match
    _swprintf_s
   
   Library: Visual Studio 2012 Release */

int __cdecl _swprintf_s(wchar_t *_Dst,size_t _SizeInWords,wchar_t *_Format,...)

{
  int iVar1;
  
  iVar1 = __vswprintf_s_l(_Dst,_SizeInWords,_Format,(_locale_t)0x0,&stack0x00000010);
  return iVar1;
}


