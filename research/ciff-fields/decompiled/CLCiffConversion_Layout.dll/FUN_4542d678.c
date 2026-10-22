// Source: CLCiffConversion_Layout.dll @ 4542d678; _strcat_s

/* Library Function - Single Match
    _strcat_s
   
   Library: Visual Studio 2012 Release */

errno_t __cdecl _strcat_s(char *_Dst,rsize_t _SizeInBytes,char *_Src)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  int iStack_10;
  
  if ((_Dst != (char *)0x0) && (_SizeInBytes != 0)) {
    pcVar3 = _Dst;
    if (_Src != (char *)0x0) {
      do {
        if (*pcVar3 == '\0') break;
        pcVar3 = pcVar3 + 1;
        _SizeInBytes = _SizeInBytes - 1;
      } while (_SizeInBytes != 0);
      if (_SizeInBytes != 0) {
        iVar4 = (int)pcVar3 - (int)_Src;
        do {
          cVar1 = *_Src;
          _Src[iVar4] = cVar1;
          _Src = _Src + 1;
          if (cVar1 == '\0') break;
          _SizeInBytes = _SizeInBytes - 1;
        } while (_SizeInBytes != 0);
        if (_SizeInBytes != 0) {
          return 0;
        }
        *_Dst = '\0';
        piVar2 = __errno();
        iStack_10 = 0x22;
        goto LAB_4542d69c;
      }
    }
    *_Dst = '\0';
  }
  piVar2 = __errno();
  iStack_10 = 0x16;
LAB_4542d69c:
  *piVar2 = iStack_10;
  FUN_45432798();
  return iStack_10;
}


