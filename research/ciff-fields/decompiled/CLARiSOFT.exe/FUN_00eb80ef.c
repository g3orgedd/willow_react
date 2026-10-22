// Source: CLARiSOFT.exe @ 00eb80ef; FUN_00eb80ef

void FUN_00eb80ef(void)

{
  DWORD DVar1;
  HANDLE hFindFile;
  _WIN32_FIND_DATAW local_258;
  uint local_8;
  
  local_8 = DAT_00f385b8 ^ (uint)&stack0xfffffffc;
  if (DAT_00f42bb8 == 0) {
    DVar1 = GetTempPathW(0x104,&DAT_00f42bb8);
    if (DVar1 == 0) {
      _wcscpy_s(&DAT_00f42bb8,0x104,L"c:\\temp\\");
    }
    _wcscat_s(&DAT_00f42bb8,0x104,L"Claricom");
    FUN_00ecc450(&local_258.dwFileAttributes,0,0x250);
    hFindFile = FindFirstFileW(&DAT_00f42bb8,&local_258);
    if (hFindFile == (HANDLE)0xffffffff) {
      CreateDirectoryW(&DAT_00f42bb8,(LPSECURITY_ATTRIBUTES)0x0);
    }
    else {
      FindClose(hFindFile);
    }
    _wcscat_s(&DAT_00f42bb8,0x104,L"\\");
  }
  FUN_00ec9db6(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


