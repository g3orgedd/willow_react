// Source: CLCiffConversion_Layout.dll @ 45404fd6; AtlA2WHelper

/* Library Function - Single Match
    wchar_t * __stdcall AtlA2WHelper(wchar_t *,char const *,int,unsigned int)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release,
   Visual Studio 2015 Release */

wchar_t * AtlA2WHelper(wchar_t *param_1,char *param_2,int param_3,uint param_4)

{
  int iVar1;
  wchar_t *pwVar2;
  
  if ((param_1 == (wchar_t *)0x0) || (param_2 == (char *)0x0)) {
    pwVar2 = (wchar_t *)0x0;
  }
  else {
    *param_1 = L'\0';
    iVar1 = MultiByteToWideChar(param_4,0,param_2,-1,param_1,param_3);
    pwVar2 = (wchar_t *)(-(uint)(iVar1 != 0) & (uint)param_1);
  }
  return pwVar2;
}


