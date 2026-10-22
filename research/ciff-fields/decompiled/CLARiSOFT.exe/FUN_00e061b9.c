// Source: CLARiSOFT.exe @ 00e061b9; FUN_00e061b9

undefined4 __fastcall FUN_00e061b9(undefined4 *param_1)

{
  UINT UVar1;
  
  UVar1 = SysStringLen((BSTR)*param_1);
  if (UVar1 != 0) {
    UVar1 = SysStringLen((BSTR)*param_1);
    CharLowerBuffW((LPWSTR)*param_1,UVar1);
  }
  return 0;
}


