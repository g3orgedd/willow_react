// Source: CLCiffConversion_Data.dll @ 45008ec3; FUN_45008ec3

void __cdecl FUN_45008ec3(undefined4 *param_1)

{
  LSTATUS LVar1;
  size_t sVar2;
  DWORD local_d8;
  HKEY local_d4;
  wchar_t local_d0;
  uint local_ce [49];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_d0 = L'\0';
  FUN_45021c10(local_ce,0,0xc6);
  _wcscpy_s(&local_d0,100,(wchar_t *)*param_1);
  LVar1 = RegCreateKeyExW((HKEY)0x80000001,L"Software\\Claricom Ltd\\LanguageName",0,(LPWSTR)0x0,0,
                          0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&local_d4,&local_d8);
  if (LVar1 == 0) {
    sVar2 = _wcslen(&local_d0);
    RegSetValueExW(local_d4,L"LanguageName",0,1,(BYTE *)&local_d0,sVar2 * 2 + 2);
    RegCloseKey(local_d4);
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


