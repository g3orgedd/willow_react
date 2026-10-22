// Source: CLCiffConversion_Data.dll @ 45038956; findenv

/* Library Function - Single Match
    _findenv
   
   Library: Visual Studio 2012 Release */

int __cdecl findenv(uchar *param_1,size_t param_2)

{
  uchar *_Str2;
  int iVar1;
  int *piVar2;
  
  _Str2 = (uchar *)*DAT_450553b4;
  piVar2 = DAT_450553b4;
  while( true ) {
    if (_Str2 == (uchar *)0x0) {
      return -((int)piVar2 - (int)DAT_450553b4 >> 2);
    }
    iVar1 = __mbsnbicoll(param_1,_Str2,param_2);
    if ((iVar1 == 0) &&
       ((*(char *)(param_2 + *piVar2) == '=' || (*(char *)(param_2 + *piVar2) == '\0')))) break;
    piVar2 = piVar2 + 1;
    _Str2 = (uchar *)*piVar2;
  }
  return (int)piVar2 - (int)DAT_450553b4 >> 2;
}


