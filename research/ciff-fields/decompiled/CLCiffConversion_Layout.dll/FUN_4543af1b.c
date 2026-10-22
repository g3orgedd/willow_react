// Source: CLCiffConversion_Layout.dll @ 4543af1b; _tolower

/* Library Function - Single Match
    _tolower
   
   Library: Visual Studio 2012 Release */

int __cdecl _tolower(int _C)

{
  uint uVar1;
  
  if (DAT_4546122c == 0) {
    if (_C - 0x41U < 0x1a) {
      _C = _C + 0x20;
    }
    return _C;
  }
  uVar1 = FUN_4543add8(_C,(int *)0x0);
  return uVar1;
}


