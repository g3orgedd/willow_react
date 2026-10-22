// Source: CLCiffConversion_Layout.dll @ 4542d07a; _wcscpy_s

/* Library Function - Single Match
    _wcscpy_s
   
   Library: Visual Studio 2012 Release */

errno_t __cdecl _wcscpy_s(wchar_t *_Dst,rsize_t _SizeInWords,wchar_t *_Src)

{
  wchar_t wVar1;
  int *piVar2;
  int iVar3;
  
  if ((_Dst != (wchar_t *)0x0) && (_SizeInWords != 0)) {
    if (_Src != (wchar_t *)0x0) {
      iVar3 = (int)_Dst - (int)_Src;
      do {
        wVar1 = *_Src;
        *(wchar_t *)(iVar3 + (int)_Src) = wVar1;
        _Src = _Src + 1;
        if (wVar1 == L'\0') break;
        _SizeInWords = _SizeInWords - 1;
      } while (_SizeInWords != 0);
      if (_SizeInWords != 0) {
        return 0;
      }
      *_Dst = L'\0';
      piVar2 = __errno();
      iVar3 = 0x22;
      goto LAB_4542d09f;
    }
    *_Dst = L'\0';
  }
  piVar2 = __errno();
  iVar3 = 0x16;
LAB_4542d09f:
  *piVar2 = iVar3;
  FUN_45432798();
  return iVar3;
}


