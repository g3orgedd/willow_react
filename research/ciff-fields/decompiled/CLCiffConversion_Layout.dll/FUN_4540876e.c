// Source: CLCiffConversion_Layout.dll @ 4540876e; FUN_4540876e

uint __cdecl FUN_4540876e(BSTR *param_1,int param_2)

{
  BSTR len;
  BSTR pOVar1;
  uint uVar2;
  
  len = (BSTR)FUN_4542d96f(param_2,&stack0x0000000c);
  if (*param_1 == (BSTR)0x0) {
    pOVar1 = SysAllocStringLen((OLECHAR *)0x0,(UINT)len);
    *param_1 = pOVar1;
  }
  else {
    pOVar1 = (BSTR)SysStringLen(*param_1);
    if (len != pOVar1) {
      pOVar1 = (BSTR)SysReAllocStringLen(param_1,(OLECHAR *)0x0,(uint)len);
    }
  }
  if (*param_1 == (BSTR)0x0) {
    uVar2 = (uint)pOVar1 & 0xffffff00;
  }
  else {
    pOVar1 = (BSTR)FUN_454087d1(param_1,(uint)len,param_2,&stack0x0000000c);
    uVar2 = (uint)(pOVar1 == len);
  }
  return uVar2;
}


