// Source: CLCiffConversion_Data.dll @ 45023b99; _memmove_s

/* Library Function - Single Match
    _memmove_s
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release,
   Visual Studio 2019 Release */

errno_t __cdecl _memmove_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  int *piVar1;
  errno_t eVar2;
  
  if (_MaxCount == 0) {
LAB_45023be0:
    eVar2 = 0;
  }
  else {
    if ((_Dst == (void *)0x0) || (_Src == (void *)0x0)) {
      piVar1 = __errno();
      eVar2 = 0x16;
    }
    else {
      if (_MaxCount <= _DstSize) {
        FUN_45021d30(_Dst,_Src,_MaxCount);
        goto LAB_45023be0;
      }
      piVar1 = __errno();
      eVar2 = 0x22;
    }
    *piVar1 = eVar2;
    FUN_45027e29();
  }
  return eVar2;
}


