// Source: CLCiffConversion_Layout.dll @ 4543c1b6; __lock_file

/* Library Function - Single Match
    __lock_file
   
   Library: Visual Studio 2012 Release */

void __cdecl __lock_file(FILE *_File)

{
  if ((_File < &PTR_DAT_4545e728) || ((FILE *)&DAT_4545e988 < _File)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  }
  else {
    __lock(((int)&_File[-0x22a2f3a]._bufsiz >> 5) + 0x10);
    _File->_flag = _File->_flag | 0x8000;
  }
  return;
}


