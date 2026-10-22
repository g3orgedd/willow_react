// Source: CLCiffConversion_Data.dll @ 4501ca70; FUN_4501ca70

void FUN_4501ca70(void)

{
  int iVar1;
  HANDLE hFindFile;
  _WIN32_FIND_DATAW local_258;
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  if (DAT_450541a8 == 0) {
    iVar1 = SHGetFolderPathW(0,0x23,0,0,&DAT_450541a8);
    if (iVar1 < 0) {
      _wcscpy_s(&DAT_450541a8,0x104,L"c:\\ClaricomData");
    }
    _wcscat_s(&DAT_450541a8,0x104,L"\\Claricom");
    FUN_45021c10(&local_258.dwFileAttributes,0,0x250);
    hFindFile = FindFirstFileW(&DAT_450541a8,&local_258);
    if (hFindFile == (HANDLE)0xffffffff) {
      CreateDirectoryW(&DAT_450541a8,(LPSECURITY_ATTRIBUTES)0x0);
    }
    else {
      FindClose(hFindFile);
    }
    _wcscat_s(&DAT_450541a8,0x104,L"\\");
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


