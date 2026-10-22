// Source: CLCiffConversion_Data.dll @ 4500b034; FUN_4500b034

BSTR __cdecl FUN_4500b034(LPCSTR param_1,int param_2)

{
  UINT cchWideChar;
  BSTR lpWideCharStr;
  UINT ui;
  
  if ((param_1 == (LPCSTR)0x0) || (param_2 == 0)) {
    lpWideCharStr = (BSTR)0x0;
  }
  else {
    cchWideChar = MultiByteToWideChar(3,0,param_1,param_2,(LPWSTR)0x0,0);
    ui = cchWideChar;
    if (param_2 == -1) {
      ui = cchWideChar - 1;
    }
    lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,ui);
    if (lpWideCharStr != (BSTR)0x0) {
      MultiByteToWideChar(3,0,param_1,param_2,lpWideCharStr,cchWideChar);
    }
  }
  return lpWideCharStr;
}


