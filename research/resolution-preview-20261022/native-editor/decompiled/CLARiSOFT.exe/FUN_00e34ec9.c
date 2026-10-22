// Source: CLARiSOFT.exe @ 00e34ec9; FUN_00e34ec9

void FUN_00e34ec9(BSTR param_1)

{
  LSTATUS LVar1;
  UINT UVar2;
  DWORD local_c;
  HKEY local_8;
  
  LVar1 = RegCreateKeyExW((HKEY)0x80000001,
                          L"Software\\Claricom Ltd\\CLARiSOFT\\WorkSpace\\CurrentCoder",0,
                          (LPWSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&local_8,&local_c);
  if (LVar1 == 0) {
    UVar2 = SysStringLen(param_1);
    RegSetValueExW(local_8,L"CurrentCoder",0,1,(BYTE *)param_1,UVar2 * 2 + 2);
    RegCloseKey(local_8);
  }
  SysFreeString(param_1);
  return;
}


