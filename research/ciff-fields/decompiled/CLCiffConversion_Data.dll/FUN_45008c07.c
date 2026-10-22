// Source: CLCiffConversion_Data.dll @ 45008c07; FUN_45008c07

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_45008c07(void *param_1)

{
  LSTATUS LVar1;
  undefined *puVar2;
  DWORD local_ec [2];
  HKEY local_e4;
  undefined *local_e0;
  WCHAR local_dc;
  uint local_da [52];
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar2 = PTR_DAT_4505101c;
  uStack_4 = 0xe0;
  local_e0 = PTR_DAT_4505101c;
  local_8 = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000001,L"Software\\Claricom Ltd\\LanguageName",0,0x20019,&local_e4
                       );
  if (LVar1 == 0) {
    local_dc = L'\0';
    FUN_45021c10(local_da,0,0xc6);
    local_ec[0] = 200;
    local_ec[1] = 1;
    LVar1 = RegQueryValueExW(local_e4,L"LanguageName",(LPDWORD)0x0,local_ec + 1,(LPBYTE)&local_dc,
                             local_ec);
    if (LVar1 == 0) {
      FUN_45002365(&local_e0,&local_dc);
      puVar2 = local_e0;
    }
  }
  else {
    LVar1 = RegCreateKeyExW((HKEY)0x80000001,L"Software\\Claricom Ltd\\LanguageName",0,(LPWSTR)0x0,0
                            ,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&local_e4,local_ec + 1);
    if (LVar1 != 0) goto LAB_45008cfd;
  }
  RegCloseKey(local_e4);
LAB_45008cfd:
  if (*(int *)(puVar2 + -8) == 0) {
    FUN_45008beb(param_1);
  }
  else {
    FUN_4500201a(param_1,(int *)&local_e0);
  }
  FUN_45002256((int *)&local_e0);
  FUN_45022eb8();
  return;
}


