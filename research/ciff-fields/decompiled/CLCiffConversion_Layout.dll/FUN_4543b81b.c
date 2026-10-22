// Source: CLCiffConversion_Layout.dll @ 4543b81b; __set_error_mode

/* Library Function - Single Match
    __set_error_mode
   
   Library: Visual Studio 2012 Release */

int __cdecl __set_error_mode(int _Mode)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = DAT_454616b0;
  if (_Mode < 0) {
LAB_4543b846:
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_45432798();
    return -1;
  }
  if (_Mode < 3) {
    DAT_454616b0 = _Mode;
  }
  else if (_Mode != 3) goto LAB_4543b846;
  return iVar1;
}


