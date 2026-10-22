// Source: CLCiffConversion_Data.dll @ 45032681; __wcsnicmp

/* Library Function - Single Match
    __wcsnicmp
   
   Library: Visual Studio 2019 Release */

int __cdecl __wcsnicmp(wchar_t *_Str1,wchar_t *_Str2,size_t _MaxCount)

{
  wchar_t wVar1;
  int iVar2;
  wchar_t wVar3;
  
  iVar2 = 0;
  if (_MaxCount != 0) {
    iVar2 = (int)_Str1 - (int)_Str2;
    do {
      wVar3 = *(wchar_t *)(iVar2 + (int)_Str2);
      if ((0x40 < (ushort)wVar3) && ((ushort)wVar3 < 0x5b)) {
        wVar3 = wVar3 + L' ';
      }
      wVar1 = *_Str2;
      if ((0x40 < (ushort)wVar1) && ((ushort)wVar1 < 0x5b)) {
        wVar1 = wVar1 + L' ';
      }
      _Str2 = _Str2 + 1;
      _MaxCount = _MaxCount - 1;
    } while (((_MaxCount != 0) && (wVar3 != L'\0')) && (wVar3 == wVar1));
    iVar2 = (uint)(ushort)wVar3 - (uint)(ushort)wVar1;
  }
  return iVar2;
}


