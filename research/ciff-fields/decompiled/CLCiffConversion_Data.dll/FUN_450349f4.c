// Source: CLCiffConversion_Data.dll @ 450349f4; __set_error_mode

/* Library Function - Single Match
    __set_error_mode
   
   Library: Visual Studio 2012 Release */

int __cdecl __set_error_mode(int _Mode)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = DAT_45055eac;
  if (_Mode < 0) {
LAB_45034a1f:
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_45027e29();
    return -1;
  }
  if (_Mode < 3) {
    DAT_45055eac = _Mode;
  }
  else if (_Mode != 3) goto LAB_45034a1f;
  return iVar1;
}


