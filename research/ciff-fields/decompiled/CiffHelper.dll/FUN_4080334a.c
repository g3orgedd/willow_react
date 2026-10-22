// Source: CiffHelper.dll @ 4080334a; FUN_4080334a

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_4080334a(void *param_1,LPCWSTR param_2)

{
  LPCWSTR lpAppName;
  LPCWSTR lpFileName;
  WCHAR local_21c [266];
  undefined4 local_8;
  undefined4 uStack_4;
  
  lpAppName = param_2;
  uStack_4 = 0x210;
  local_8 = 0;
  lpFileName = FUN_408288b7();
  GetPrivateProfileStringW(lpAppName,L"IndexField",L"",local_21c,0x104,lpFileName);
  FUN_408030e3(param_1,local_21c);
  FUN_40803143((int *)&param_2);
  FUN_4082d4c6();
  return;
}


