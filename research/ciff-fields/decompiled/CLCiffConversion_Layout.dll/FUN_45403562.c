// Source: CLCiffConversion_Layout.dll @ 45403562; FUN_45403562

ULONG __fastcall FUN_45403562(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[6].AddRef)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_454476a0);
  }
  return UVar1;
}


