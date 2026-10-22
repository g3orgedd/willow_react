// Source: CiffHelper.dll @ 40804fe4; FUN_40804fe4

ULONG __fastcall FUN_40804fe4(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[6].AddRef)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_4084a7e0);
  }
  return UVar1;
}


