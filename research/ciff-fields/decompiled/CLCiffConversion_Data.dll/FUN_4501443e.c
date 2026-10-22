// Source: CLCiffConversion_Data.dll @ 4501443e; _wmemchr

/* Library Function - Single Match
    _wmemchr
   
   Library: Visual Studio 2012 Release */

wchar_t * __cdecl _wmemchr(wchar_t *_S,wchar_t _C,size_t _N)

{
  while( true ) {
    if (_N == 0) {
      return (wchar_t *)0x0;
    }
    if (*_S == _C) break;
    _S = _S + 1;
    _N = _N - 1;
  }
  return _S;
}


