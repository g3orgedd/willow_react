// Source: CLCSTextBasedField.dll @ 42404fea; FUN_42404fea

BSTR __fastcall FUN_42404fea(int *param_1)

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


