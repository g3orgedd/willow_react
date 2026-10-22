// Source: CLARiSOFT.exe @ 00eb70d6; FUN_00eb70d6

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_00eb70d6(int *param_1,uint param_2,int param_3)

{
  HANDLE hFindFile;
  int *piVar1;
  BOOL BVar2;
  OLECHAR *local_488 [4];
  uint local_478;
  LPCWSTR local_470;
  int local_46c;
  int local_468;
  _WIN32_FIND_DATAW local_464;
  WCHAR local_214 [262];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x478;
  local_8 = 0xeb70e5;
  if (param_2 != 0) {
    GetEnvironmentVariableW(L"windir",local_214,0xff);
    FUN_00e03bc2(&local_46c,local_214);
    local_8 = 0;
    FUN_00e06fd2(&local_46c,L"\\Fonts\\");
    FUN_00e03b6d(&local_468,"*.ttf");
    local_8._0_1_ = 1;
    FUN_00e13b24(&local_470,&local_46c,&local_468);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_00e01f81(&local_468);
    hFindFile = FindFirstFileW(local_470,&local_464);
    FUN_00eb76fc(param_1);
    if (hFindFile != (HANDLE)0xffffffff) {
      do {
        if ((local_464.nFileSizeLow < param_2) && (local_464.nFileSizeHigh == 0)) {
          FUN_00eaf9ef(local_488);
          local_8._0_1_ = 4;
          piVar1 = FUN_00e28cb6(&local_468,&local_46c,local_464.cFileName);
          local_8._0_1_ = 5;
          FUN_00e06f61(local_488,piVar1);
          local_8._0_1_ = 4;
          FUN_00e01f81(&local_468);
          FUN_00eb5a70(local_488[0],(int)local_488,param_3);
          local_478 = local_464.nFileSizeLow;
          FUN_00eaf6be(param_1,(int *)*param_1,(int *)local_488);
          local_8 = CONCAT31(local_8._1_3_,3);
          FUN_00eafb11((int *)local_488);
        }
        BVar2 = FindNextFileW(hFindFile,&local_464);
      } while (BVar2 != 0);
    }
    FindClose(hFindFile);
    FUN_00e01f81((int *)&local_470);
    FUN_00e01f81(&local_46c);
  }
  FUN_00ec9e3c();
  return;
}


