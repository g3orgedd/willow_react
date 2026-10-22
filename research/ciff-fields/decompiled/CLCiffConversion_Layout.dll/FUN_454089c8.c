// Source: CLCiffConversion_Layout.dll @ 454089c8; FUN_454089c8

BSTR __fastcall FUN_454089c8(int *param_1)

{
  BSTR pOVar1;
  
  if ((param_1[5] != 0) && (*param_1 != 0)) {
    pOVar1 = SysAllocStringLen((OLECHAR *)(*param_1 + param_1[4] * 2),param_1[5]);
    return pOVar1;
  }
  return (BSTR)0x0;
}


