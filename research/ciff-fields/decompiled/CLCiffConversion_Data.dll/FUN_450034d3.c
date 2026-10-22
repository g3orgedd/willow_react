// Source: CLCiffConversion_Data.dll @ 450034d3; FUN_450034d3

ULONG __fastcall FUN_450034d3(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[6].AddRef)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_4503d530);
  }
  return UVar1;
}


