// Source: CLCiffConversion_Data.dll @ 450240e5; _wmemcpy_s

/* Library Function - Single Match
    _wmemcpy_s
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release,
   Visual Studio 2019 Release */

errno_t __cdecl _wmemcpy_s(wchar_t *_S1,rsize_t _N1,wchar_t *_S2,rsize_t _N)

{
  errno_t eVar1;
  int *piVar2;
  
  if (_N == 0) {
    eVar1 = 0;
  }
  else if (_S1 == (wchar_t *)0x0) {
    piVar2 = __errno();
    eVar1 = 0x16;
    *piVar2 = 0x16;
    FUN_45027e29();
  }
  else if ((_S2 == (wchar_t *)0x0) || (_N1 < _N)) {
    _wmemset(_S1,L'\0',_N1);
    if (_S2 == (wchar_t *)0x0) {
      piVar2 = __errno();
      eVar1 = 0x16;
    }
    else {
      if (_N <= _N1) {
        return 0x16;
      }
      piVar2 = __errno();
      eVar1 = 0x22;
    }
    *piVar2 = eVar1;
    FUN_45027e29();
  }
  else {
    FUN_45021540((undefined8 *)_S1,(undefined8 *)_S2,_N * 2);
    eVar1 = 0;
  }
  return eVar1;
}


