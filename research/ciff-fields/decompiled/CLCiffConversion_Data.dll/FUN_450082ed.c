// Source: CLCiffConversion_Data.dll @ 450082ed; _wmemcmp

/* Library Function - Single Match
    _wmemcmp
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __cdecl _wmemcmp(wchar_t *_S1,wchar_t *_S2,size_t _N)

{
  while( true ) {
    if (_N == 0) {
      return 0;
    }
    if (*_S1 != *_S2) break;
    _S1 = _S1 + 1;
    _S2 = _S2 + 1;
    _N = _N - 1;
  }
  return (-(uint)((ushort)*_S1 < (ushort)*_S2) & 0xfffffffe) + 1;
}


