// Source: CLCiffConversion_Layout.dll @ 4542f390; __callnewh

/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 2012 Release */

int __cdecl __callnewh(size_t _Size)

{
  code *pcVar1;
  int iVar2;
  
  pcVar1 = DecodePointer(DAT_45460b7c);
  if (pcVar1 != (code *)0x0) {
    iVar2 = (*pcVar1)(_Size);
    if (iVar2 != 0) {
      return 1;
    }
  }
  return 0;
}


