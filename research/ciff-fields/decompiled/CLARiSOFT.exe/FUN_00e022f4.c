// Source: CLARiSOFT.exe @ 00e022f4; FUN_00e022f4

BSTR __fastcall FUN_00e022f4(int *param_1)

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


