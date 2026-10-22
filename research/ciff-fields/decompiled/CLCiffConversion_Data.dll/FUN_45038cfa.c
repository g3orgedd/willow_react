// Source: CLCiffConversion_Data.dll @ 45038cfa; ___strncnt

/* Library Function - Single Match
    ___strncnt
   
   Library: Visual Studio 2019 Release */

int __cdecl ___strncnt(char *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_2;
  for (; (iVar1 != 0 && (*param_1 != '\0')); param_1 = param_1 + 1) {
    iVar1 = iVar1 + -1;
  }
  return (param_2 - (iVar1 + -1)) + -1;
}


