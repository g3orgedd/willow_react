// Source: CLCiffConversion_Data.dll @ 450329a3; __unlock_file

/* Library Function - Single Match
    __unlock_file
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release */

void __cdecl __unlock_file(FILE *_File)

{
  if (((FILE *)0x450525ef < _File) && (_File < (FILE *)0x45052851)) {
    _File->_flag = _File->_flag & 0xffff7fff;
    FUN_45031f41(((int)&_File[-0x2282930]._file >> 5) + 0x10);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  return;
}


