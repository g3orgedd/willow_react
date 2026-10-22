// Source: CLARiSOFT.exe @ 00e04e23; FUN_00e04e23

ULONG __fastcall FUN_00e04e23(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[6].AddRef)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_00efcb58);
  }
  return UVar1;
}


