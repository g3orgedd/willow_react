// Source: CLCiffConversion_Layout.dll @ 45408666; FUN_45408666

void FUN_45408666(void)

{
  int iVar1;
  HANDLE hFindFile;
  _WIN32_FIND_DATAA local_148;
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  if (DAT_4545ffe8 == '\0') {
    iVar1 = SHGetFolderPathA(0,0x23,0,0,&DAT_4545ffe8);
    if (iVar1 < 0) {
      _strcpy_s(&DAT_4545ffe8,0x104,"c:\\ClaricomData");
    }
    _strcat_s(&DAT_4545ffe8,0x104,"\\Claricom");
    FUN_45429f70(&local_148.dwFileAttributes,0,0x140);
    hFindFile = FindFirstFileA(&DAT_4545ffe8,&local_148);
    if (hFindFile == (HANDLE)0xffffffff) {
      CreateDirectoryA(&DAT_4545ffe8,(LPSECURITY_ATTRIBUTES)0x0);
    }
    else {
      FindClose(hFindFile);
    }
    _strcat_s(&DAT_4545ffe8,0x104,"\\");
  }
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


