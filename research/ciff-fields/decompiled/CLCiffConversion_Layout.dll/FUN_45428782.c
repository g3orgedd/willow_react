// Source: CLCiffConversion_Layout.dll @ 45428782; FUN_45428782

BSTR __fastcall FUN_45428782(undefined4 *param_1)

{
  UINT ui;
  BSTR lpWideCharStr;
  
  ui = MultiByteToWideChar(0,0,(LPCSTR)*param_1,*(int *)((LPCSTR)*param_1 + -8),(LPWSTR)0x0,0);
  lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,ui);
  if (lpWideCharStr != (BSTR)0x0) {
    MultiByteToWideChar(0,0,(LPCSTR)*param_1,*(int *)((LPCSTR)*param_1 + -8),lpWideCharStr,ui);
  }
  return lpWideCharStr;
}


