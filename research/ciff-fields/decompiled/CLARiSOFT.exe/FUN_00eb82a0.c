// Source: CLARiSOFT.exe @ 00eb82a0; FUN_00eb82a0

void FUN_00eb82a0(void)

{
  int iVar1;
  HANDLE hFindFile;
  _WIN32_FIND_DATAW local_258;
  uint local_8;
  
  local_8 = DAT_00f385b8 ^ (uint)&stack0xfffffffc;
  if (DAT_00f433d8 == 0) {
    iVar1 = SHGetFolderPathW(0,0x23,0,0,&DAT_00f433d8);
    if (iVar1 < 0) {
      _wcscpy_s(&DAT_00f433d8,0x104,L"c:\\ClaricomData");
    }
    _wcscat_s(&DAT_00f433d8,0x104,L"\\Claricom");
    FUN_00ecc450(&local_258.dwFileAttributes,0,0x250);
    hFindFile = FindFirstFileW(&DAT_00f433d8,&local_258);
    if (hFindFile == (HANDLE)0xffffffff) {
      CreateDirectoryW(&DAT_00f433d8,(LPSECURITY_ATTRIBUTES)0x0);
    }
    else {
      FindClose(hFindFile);
    }
    _wcscat_s(&DAT_00f433d8,0x104,L"\\");
  }
  FUN_00ec9db6(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


