// Source: CLCiffConversion_Layout.dll @ 4540e7c9; FUN_4540e7c9

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __thiscall FUN_4540e7c9(void *this,undefined4 *param_1)

{
  HANDLE hFindFile;
  undefined4 *puVar1;
  size_t sVar2;
  wchar_t *pwVar3;
  BOOL BVar4;
  wchar_t local_39c [8];
  undefined4 *local_38c;
  undefined4 local_388;
  int local_384;
  void *local_380;
  BSTR local_37c;
  int local_378;
  _WIN32_FIND_DATAA local_374;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_234 [24];
  char local_21c [260];
  char local_118 [272];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x37c;
  local_38c = param_1;
  *param_1 = 0;
  local_8 = 0;
  local_388 = 1;
  local_380 = this;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_234,"ZipherBitmapFont::GetDefaultFont()");
  local_8 = 1;
  _sprintf_s(local_118,0x104,"%ls\\*.zfbf",*(undefined4 *)((int)this + 0x44));
  hFindFile = FindFirstFileA(local_118,&local_374);
  if (hFindFile != (HANDLE)0xffffffff) {
    do {
      if (((byte)local_374.dwFileAttributes & 0x10) == 0) {
        FUN_45402a65(&local_378,local_374.cFileName);
        local_8._0_1_ = 2;
        puVar1 = FUN_4540629a(&local_378,&local_384,*(int *)(local_378 + -8) - 5);
        local_8._0_1_ = 3;
        FUN_454028b9(&local_37c,(char *)*puVar1);
        local_8 = CONCAT31(local_8._1_3_,5);
        FUN_45402c5d(&local_384);
        sVar2 = _strlen(local_374.cFileName);
        if ((int)(sVar2 + 1) < 0x40000000) {
          pwVar3 = AtlA2WHelper(local_39c,local_374.cFileName,sVar2 + 1,3);
        }
        else {
          pwVar3 = (wchar_t *)0x0;
        }
        _sprintf_s(local_21c,0x104,"%ls%ls",*(undefined4 *)((int)local_380 + 0x44),pwVar3);
        FUN_45404d15(param_1,(int *)&local_37c);
        SysFreeString(local_37c);
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_45402c5d(&local_378);
      }
      BVar4 = FindNextFileA(hFindFile,&local_374);
    } while (BVar4 != 0);
    FindClose(hFindFile);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_234,true,0);
  FUN_4542a957();
  return;
}


