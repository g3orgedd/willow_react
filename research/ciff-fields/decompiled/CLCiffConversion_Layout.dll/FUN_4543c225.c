// Source: CLCiffConversion_Layout.dll @ 4543c225; __unlock_file

/* Library Function - Single Match
    __unlock_file
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release */

void __cdecl __unlock_file(FILE *_File)

{
  if (((FILE *)0x4545e727 < _File) && (_File < (FILE *)0x4545e989)) {
    _File->_flag = _File->_flag & 0xffff7fff;
    FUN_4543aa55(((int)&_File[-0x22a2f3a]._bufsiz >> 5) + 0x10);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  return;
}


