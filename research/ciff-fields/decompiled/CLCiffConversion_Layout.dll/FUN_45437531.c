// Source: CLCiffConversion_Layout.dll @ 45437531; write_char

/* Library Function - Single Match
    _write_char
   
   Library: Visual Studio 2012 Release */

void __cdecl write_char(WCHAR param_1,FILE *param_2,int *param_3)

{
  short sVar1;
  
  if (((param_2->_flag & 0x40) == 0) || (param_2->_base != (char *)0x0)) {
    sVar1 = FUN_4543cf61(param_1,param_2);
    if (sVar1 == -1) {
      *param_3 = -1;
      return;
    }
  }
  *param_3 = *param_3 + 1;
  return;
}


