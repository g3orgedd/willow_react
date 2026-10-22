// Source: CLCiffConversion_Layout.dll @ 45402db8; A2WBSTR

/* Library Function - Single Match
    wchar_t * __cdecl A2WBSTR(char const *,int)
   
   Library: Visual Studio 2015 Release */

wchar_t * __cdecl A2WBSTR(char *param_1,int param_2)

{
  UINT cchWideChar;
  wchar_t *lpWideCharStr;
  UINT UVar1;
  
  if ((param_1 == (char *)0x0) || (param_2 == 0)) {
    lpWideCharStr = (wchar_t *)0x0;
  }
  else {
    cchWideChar = MultiByteToWideChar(3,0,param_1,param_2,(LPWSTR)0x0,0);
    UVar1 = cchWideChar;
    if (param_2 == -1) {
      UVar1 = cchWideChar - 1;
    }
    lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,UVar1);
    if ((lpWideCharStr != (BSTR)0x0) &&
       (UVar1 = MultiByteToWideChar(3,0,param_1,param_2,lpWideCharStr,cchWideChar),
       UVar1 != cchWideChar)) {
      SysFreeString(lpWideCharStr);
      lpWideCharStr = (wchar_t *)0x0;
    }
  }
  return lpWideCharStr;
}


