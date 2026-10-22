// Source: CLCiffConversion_Layout.dll @ 454284f0; FID_conflict:tcscpy_s

/* Library Function - Multiple Matches With Different Base Names
    void __cdecl ATL::Checked::strcpy_s(char *,unsigned int,char const *)
    void __cdecl ATL::Checked::tcscpy_s(char *,unsigned int,char const *)
   
   Library: Visual Studio 2012 Release */

void __cdecl FID_conflict_tcscpy_s(char *param_1,rsize_t param_2,char *param_3)

{
  errno_t eVar1;
  
  eVar1 = _strcpy_s(param_1,param_2,param_3);
  FUN_45402fb2(eVar1);
  return;
}


