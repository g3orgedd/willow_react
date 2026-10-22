// Source: CLCiffConversion_Layout.dll @ 45437567; write_multi_char

/* Library Function - Single Match
    _write_multi_char
   
   Library: Visual Studio 2012 Release */

void __cdecl write_multi_char(WCHAR param_1,int param_2,FILE *param_3,int *param_4)

{
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    write_char(param_1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}


