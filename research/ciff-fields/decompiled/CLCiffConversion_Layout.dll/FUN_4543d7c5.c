// Source: CLCiffConversion_Layout.dll @ 4543d7c5; __wcstombs_s_l

/* Library Function - Single Match
    __wcstombs_s_l
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release */

errno_t __cdecl
__wcstombs_s_l(size_t *_PtNumOfCharConverted,char *_Dst,size_t _DstSizeInBytes,wchar_t *_Src,
              size_t _MaxCountInBytes,_locale_t _Locale)

{
  int *piVar1;
  int iVar2;
  size_t sVar3;
  errno_t eVar4;
  
  if (_Dst == (char *)0x0) {
    if (_DstSizeInBytes != 0) goto LAB_4543d80c;
  }
  else if (_DstSizeInBytes == 0) {
LAB_4543d80c:
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_45432798();
    return 0x16;
  }
  if (_Dst != (char *)0x0) {
    *_Dst = '\0';
  }
  if (_PtNumOfCharConverted != (size_t *)0x0) {
    *_PtNumOfCharConverted = 0;
  }
  sVar3 = _DstSizeInBytes;
  if (_MaxCountInBytes <= _DstSizeInBytes) {
    sVar3 = _MaxCountInBytes;
  }
  if (sVar3 < 0x80000000) {
    iVar2 = FUN_4543d55e(_Dst,_Src,sVar3,(int *)_Locale);
    if (iVar2 == -1) {
      if (_Dst != (char *)0x0) {
        *_Dst = '\0';
      }
      piVar1 = __errno();
      return *piVar1;
    }
    sVar3 = iVar2 + 1;
    if (_Dst == (char *)0x0) {
      eVar4 = 0;
    }
    else {
      if (_DstSizeInBytes < sVar3) {
        if ((_MaxCountInBytes != 0xffffffff) && (*_Dst = '\0', _DstSizeInBytes <= sVar3)) {
          piVar1 = __errno();
          eVar4 = 0x22;
          goto LAB_4543d861;
        }
        eVar4 = 0x50;
        sVar3 = _DstSizeInBytes;
      }
      else {
        eVar4 = 0;
      }
      _Dst[sVar3 - 1] = '\0';
    }
    if (_PtNumOfCharConverted != (size_t *)0x0) {
      *_PtNumOfCharConverted = sVar3;
    }
  }
  else {
    piVar1 = __errno();
    eVar4 = 0x16;
LAB_4543d861:
    *piVar1 = eVar4;
    FUN_45432798();
  }
  return eVar4;
}


