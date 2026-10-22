// Source: CLCiffConversion_Data.dll @ 4501c98b; FUN_4501c98b

void FUN_4501c98b(void)

{
  DWORD DVar1;
  HANDLE hFindFile;
  _WIN32_FIND_DATAW local_258;
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  if (DAT_45053988 == 0) {
    DVar1 = GetTempPathW(0x104,&DAT_45053988);
    if (DVar1 == 0) {
      _wcscpy_s(&DAT_45053988,0x104,L"c:\\temp\\");
    }
    _wcscat_s(&DAT_45053988,0x104,L"Claricom");
    FUN_45021c10(&local_258.dwFileAttributes,0,0x250);
    hFindFile = FindFirstFileW(&DAT_45053988,&local_258);
    if (hFindFile == (HANDLE)0xffffffff) {
      CreateDirectoryW(&DAT_45053988,(LPSECURITY_ATTRIBUTES)0x0);
    }
    else {
      FindClose(hFindFile);
    }
    _wcscat_s(&DAT_45053988,0x104,L"\\");
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


