// Source: CLARiSOFT.exe @ 00e2f56d; FUN_00e2f56d

void __fastcall FUN_00e2f56d(int param_1)

{
  LSTATUS LVar1;
  size_t sVar2;
  DWORD local_418;
  DWORD local_414 [2];
  HKEY local_40c;
  OLECHAR local_408 [512];
  uint local_8;
  
  local_8 = DAT_00f385b8 ^ (uint)&stack0xfffffffc;
  local_414[1] = 0x400;
  LVar1 = RegOpenKeyExW((HKEY)0x80000001,
                        L"Software\\Claricom Ltd\\CLARiSOFT\\WorkSpace\\CurrentCoder",0,0xf003f,
                        &local_40c);
  if (LVar1 == 0) {
    LVar1 = RegQueryValueExW(local_40c,L"CurrentCoder",(LPDWORD)0x0,local_414,(LPBYTE)local_408,
                             local_414 + 1);
    if (LVar1 == 0) {
      FUN_00e050e5(*(void **)(param_1 + 0x1e4),local_408);
    }
  }
  else {
    _wcscpy_s(local_408,0x200,
              *(wchar_t **)(*(int *)(**(int **)(*(int *)(param_1 + 0x1e4) + 4) + 8) + 4));
    LVar1 = RegCreateKeyExW((HKEY)0x80000001,
                            L"Software\\Claricom Ltd\\CLARiSOFT\\WorkSpace\\CurrentCoder",0,
                            (LPWSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&local_40c,&local_418);
    if (LVar1 != 0) goto LAB_00e2f695;
    sVar2 = _wcslen(local_408);
    RegSetValueExW(local_40c,L"CurrentCoder",0,1,(BYTE *)local_408,sVar2 * 2 + 2);
  }
  RegCloseKey(local_40c);
LAB_00e2f695:
  FUN_00ec9db6(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


