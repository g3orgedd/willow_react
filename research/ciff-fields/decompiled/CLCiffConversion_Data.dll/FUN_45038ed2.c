// Source: CLCiffConversion_Data.dll @ 45038ed2; __freebuf

/* Library Function - Single Match
    __freebuf
   
   Library: Visual Studio 2012 Release */

void __cdecl __freebuf(FILE *_File)

{
  if (((_File->_flag & 0x83) != 0) && ((_File->_flag & 8) != 0)) {
    FID_conflict__free(_File->_base);
    _File->_flag = _File->_flag & 0xfffffbf7;
    _File->_ptr = (char *)0x0;
    _File->_base = (char *)0x0;
    _File->_cnt = 0;
  }
  return;
}


