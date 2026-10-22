// Source: CLARiSOFT.exe @ 00e35033; FUN_00e35033

void FUN_00e35033(undefined4 param_1,undefined4 param_2,BYTE *param_3,BYTE *param_4)

{
  LSTATUS LVar1;
  DWORD local_c;
  HKEY local_8;
  
  LVar1 = RegCreateKeyExW((HKEY)0x80000001,L"Software\\Claricom Ltd\\CLARiSOFT\\Document",0,
                          (LPWSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&local_8,&local_c);
  if (LVar1 == 0) {
    RegSetValueExW(local_8,L"Width",0,3,(BYTE *)&param_1,4);
    RegSetValueExW(local_8,L"Height",0,3,(BYTE *)&param_2,4);
    RegSetValueExW(local_8,L"CAPI",0,1,param_3,*(int *)(param_3 + -8) * 2);
    RegSetValueExW(local_8,L"Coder",0,1,param_4,*(int *)(param_4 + -8) * 2);
    RegCloseKey(local_8);
  }
  FUN_00e01f81((int *)&param_3);
  FUN_00e01f81((int *)&param_4);
  return;
}


