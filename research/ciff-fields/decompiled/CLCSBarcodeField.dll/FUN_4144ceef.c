// Source: CLCSBarcodeField.dll @ 4144ceef; FUN_4144ceef

void FUN_4144ceef(void)

{
  int iVar1;
  HANDLE hFindFile;
  _WIN32_FIND_DATAW local_258;
  uint local_8;
  
  local_8 = DAT_414aacf0 ^ (uint)&stack0xfffffffc;
  if (DAT_414b0980 == 0) {
    iVar1 = SHGetFolderPathW(0,0x23,0,0,&DAT_414b0980);
    if (iVar1 < 0) {
      _wcscpy_s(&DAT_414b0980,0x104,L"c:\\ClaricomData");
    }
    _wcscat_s(&DAT_414b0980,0x104,L"\\Claricom");
    FUN_41460bf0(&local_258.dwFileAttributes,0,0x250);
    hFindFile = FindFirstFileW(&DAT_414b0980,&local_258);
    if (hFindFile == (HANDLE)0xffffffff) {
      CreateDirectoryW(&DAT_414b0980,(LPSECURITY_ATTRIBUTES)0x0);
    }
    else {
      FindClose(hFindFile);
    }
    _wcscat_s(&DAT_414b0980,0x104,L"\\");
  }
  FUN_41461e5c(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


