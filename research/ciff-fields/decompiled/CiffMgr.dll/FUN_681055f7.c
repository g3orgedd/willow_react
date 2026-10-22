// Source: CiffMgr.dll @ 681055f7; FUN_681055f7

undefined4 __fastcall FUN_681055f7(undefined4 *param_1)

{
  UINT UVar1;
  
  UVar1 = SysStringLen((BSTR)*param_1);
  if (UVar1 != 0) {
    UVar1 = SysStringLen((BSTR)*param_1);
    CharUpperBuffW((LPWSTR)*param_1,UVar1);
  }
  return 0;
}


