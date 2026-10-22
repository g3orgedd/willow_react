// Source: CiffMgr.dll @ 6812e125; AtlW2AHelper

/* Library Function - Single Match
    char * __stdcall AtlW2AHelper(char *,wchar_t const *,int,unsigned int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

char * AtlW2AHelper(char *param_1,wchar_t *param_2,int param_3,uint param_4)

{
  int iVar1;
  char *pcVar2;
  
  if ((param_1 == (char *)0x0) || (param_2 == (wchar_t *)0x0)) {
    pcVar2 = (char *)0x0;
  }
  else {
    *param_1 = '\0';
    iVar1 = WideCharToMultiByte(param_4,0,param_2,-1,param_1,param_3,(LPCSTR)0x0,(LPBOOL)0x0);
    pcVar2 = (char *)(-(uint)(iVar1 != 0) & (uint)param_1);
  }
  return pcVar2;
}


