// Source: CLCiffConversion_Data.dll @ 45022374; _wcscmp

/* Library Function - Single Match
    _wcscmp
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2019 Release */

int __cdecl _wcscmp(wchar_t *_Str1,wchar_t *_Str2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)(ushort)*_Str2;
  iVar1 = (ushort)*_Str1 - uVar3;
  if (iVar1 == 0) {
    iVar2 = (int)_Str1 - (int)_Str2;
    do {
      if ((short)uVar3 == 0) break;
      _Str2 = _Str2 + 1;
      uVar3 = (uint)(ushort)*_Str2;
      iVar1 = *(ushort *)(iVar2 + (int)_Str2) - uVar3;
    } while (iVar1 == 0);
  }
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  else if (0 < iVar1) {
    iVar1 = 1;
  }
  return iVar1;
}


