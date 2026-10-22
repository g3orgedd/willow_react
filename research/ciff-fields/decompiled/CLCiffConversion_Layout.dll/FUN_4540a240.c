// Source: CLCiffConversion_Layout.dll @ 4540a240; std::_Allocate<char>

/* Library Function - Single Match
    char * __cdecl std::_Allocate<char>(unsigned int,char *)
   
   Library: Visual Studio 2012 Release */

char * __cdecl std::_Allocate<char>(uint param_1,char *param_2)

{
  char *pcVar1;
  
  pcVar1 = (char *)0x0;
  if ((param_1 != 0) && (pcVar1 = (char *)FUN_454298b4(param_1), pcVar1 == (char *)0x0)) {
    pcVar1 = (char *)FUN_45429455();
    return pcVar1;
  }
  return pcVar1;
}


