// Source: CLCiffConversion_Data.dll @ 45037c07; __fclose_nolock

/* Library Function - Single Match
    __fclose_nolock
   
   Library: Visual Studio 2012 Release */

int __cdecl __fclose_nolock(FILE *_File)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = -1;
  if (_File == (FILE *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_45027e29();
    iVar4 = -1;
  }
  else {
    if ((_File->_flag & 0x83) != 0) {
      iVar4 = FUN_4503623f(_File);
      __freebuf(_File);
      uVar2 = __fileno(_File);
      iVar3 = FUN_45038d5d(uVar2);
      if (iVar3 < 0) {
        iVar4 = -1;
      }
      else if (_File->_tmpfname != (char *)0x0) {
        FID_conflict__free(_File->_tmpfname);
        _File->_tmpfname = (char *)0x0;
      }
    }
    _File->_flag = 0;
  }
  return iVar4;
}


