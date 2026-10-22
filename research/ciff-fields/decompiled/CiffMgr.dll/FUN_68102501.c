// Source: CiffMgr.dll @ 68102501; FUN_68102501

BSTR __fastcall FUN_68102501(int *param_1)

{
  UINT len;
  BSTR pOVar1;
  
  if (*param_1 == 0) {
    return (BSTR)0x0;
  }
  len = SysStringByteLen((BSTR)*param_1);
  pOVar1 = SysAllocStringByteLen((LPCSTR)*param_1,len);
  return pOVar1;
}


