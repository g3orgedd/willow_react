// Source: CLCSSmallBarcode.dll @ 42043938; FUN_42043938

undefined1 __fastcall FUN_42043938(int param_1)

{
  bool bVar1;
  UINT UVar2;
  UINT UVar3;
  undefined1 uVar4;
  
  UVar2 = SysStringLen(*(BSTR *)(param_1 + 0xc));
  UVar3 = SysStringLen(*(BSTR *)(param_1 + 8));
  if (UVar2 == UVar3) {
    bVar1 = ATL::CComBSTR::operator==((CComBSTR *)(param_1 + 0xc),(CComBSTR *)(param_1 + 8));
    uVar4 = !bVar1;
  }
  else {
    uVar4 = 2;
  }
  return uVar4;
}


