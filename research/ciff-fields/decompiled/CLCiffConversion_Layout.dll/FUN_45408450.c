// Source: CLCiffConversion_Layout.dll @ 45408450; FUN_45408450

void FUN_45408450(void)

{
  DWORD DVar1;
  HANDLE hFindFile;
  _WIN32_FIND_DATAA local_148;
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  if (DAT_4545fbc8 == '\0') {
    DVar1 = GetTempPathA(0x104,&DAT_4545fbc8);
    if (DVar1 == 0) {
      _strcpy_s(&DAT_4545fbc8,0x104,"c:\\temp\\");
    }
    _strcat_s(&DAT_4545fbc8,0x104,"Claricom");
    FUN_45429f70(&local_148.dwFileAttributes,0,0x140);
    hFindFile = FindFirstFileA(&DAT_4545fbc8,&local_148);
    if (hFindFile == (HANDLE)0xffffffff) {
      CreateDirectoryA(&DAT_4545fbc8,(LPSECURITY_ATTRIBUTES)0x0);
    }
    else {
      FindClose(hFindFile);
    }
    _strcat_s(&DAT_4545fbc8,0x104,"\\");
  }
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


