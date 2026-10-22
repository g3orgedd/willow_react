// Source: CiffHelper.dll @ 408033ab; FUN_408033ab

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_408033ab(void *param_1,LPCWSTR param_2)

{
  LPCWSTR lpAppName;
  LPCWSTR lpFileName;
  WCHAR local_814 [1030];
  undefined4 local_8;
  undefined4 uStack_4;
  
  lpAppName = param_2;
  uStack_4 = 0x808;
  local_8 = 0;
  lpFileName = FUN_408288b7();
  GetPrivateProfileStringW(lpAppName,L"Source",L"",local_814,0x400,lpFileName);
  FUN_408030e3(param_1,local_814);
  FUN_40803143((int *)&param_2);
  FUN_4082d4c6();
  return;
}


