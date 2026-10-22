// Source: CLCiffConversion_Data.dll @ 45032934; __lock_file

/* Library Function - Single Match
    __lock_file
   
   Library: Visual Studio 2012 Release */

void __cdecl __lock_file(FILE *_File)

{
  if ((_File < &PTR_DAT_450525f0) || ((FILE *)&DAT_45052850 < _File)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  }
  else {
    __lock(((int)&_File[-0x2282930]._file >> 5) + 0x10);
    _File->_flag = _File->_flag | 0x8000;
  }
  return;
}


