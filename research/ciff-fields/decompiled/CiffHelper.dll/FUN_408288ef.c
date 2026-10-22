// Source: CiffHelper.dll @ 408288ef; FUN_408288ef

void FUN_408288ef(void)

{
  int iVar1;
  HANDLE hFindFile;
  _WIN32_FIND_DATAW local_258;
  uint local_8;
  
  local_8 = DAT_40862970 ^ (uint)&stack0xfffffffc;
  if (DAT_40865100 == 0) {
    iVar1 = SHGetFolderPathW(0,0x23,0,0,&DAT_40865100);
    if (iVar1 < 0) {
      _wcscpy_s(&DAT_40865100,0x104,L"c:\\ClaricomData");
    }
    _wcscat_s(&DAT_40865100,0x104,L"\\Claricom");
    FUN_4082cef0(&local_258.dwFileAttributes,0,0x250);
    hFindFile = FindFirstFileW(&DAT_40865100,&local_258);
    if (hFindFile == (HANDLE)0xffffffff) {
      CreateDirectoryW(&DAT_40865100,(LPSECURITY_ATTRIBUTES)0x0);
    }
    else {
      FindClose(hFindFile);
    }
    _wcscat_s(&DAT_40865100,0x104,L"\\");
  }
  FUN_4082d440(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


