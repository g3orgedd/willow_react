// Source: CLCiffConversion_Layout.dll @ 4540e972; FUN_4540e972

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __fastcall FUN_4540e972(int param_1)

{
  HANDLE hFindFile;
  undefined4 *puVar1;
  size_t sVar2;
  wchar_t *pwVar3;
  int iVar4;
  BOOL BVar5;
  wchar_t local_494 [8];
  BSTR local_484;
  BSTR local_480;
  int local_47c;
  _WIN32_FIND_DATAA local_478;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_338 [24];
  wchar_t local_320 [260];
  char local_118 [272];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x474;
  local_8 = 0x4540e981;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_338,"ZipherBitmapFont::PopulateZipherFontList()");
  local_8 = 0;
  _sprintf_s(local_118,0x104,"%ls\\*.zfbf",*(undefined4 *)(param_1 + 0x44));
  hFindFile = FindFirstFileA(local_118,&local_478);
  if (hFindFile == (HANDLE)0xffffffff) {
    FUN_454028b9(&local_484,local_478.cFileName);
    SysFreeString(local_484);
  }
  else {
    do {
      if (((byte)local_478.dwFileAttributes & 0x10) == 0) {
        FUN_45402a65(&local_47c,local_478.cFileName);
        local_8._0_1_ = 1;
        puVar1 = FUN_4540629a(&local_47c,&local_484,*(int *)(local_47c + -8) - 5);
        local_8._0_1_ = 2;
        FUN_454028b9(&local_480,(char *)*puVar1);
        local_8 = CONCAT31(local_8._1_3_,4);
        FUN_45402c5d((int *)&local_484);
        sVar2 = _strlen(local_478.cFileName);
        if ((int)(sVar2 + 1) < 0x40000000) {
          pwVar3 = AtlA2WHelper(local_494,local_478.cFileName,sVar2 + 1,3);
        }
        else {
          pwVar3 = (wchar_t *)0x0;
        }
        _swprintf_s(local_320,0x104,L"%ls%ls",*(undefined4 *)(param_1 + 0x44),pwVar3);
        iVar4 = (**(code **)(**(int **)(param_1 + 4) + 0x10))
                          (*(int **)(param_1 + 4),local_480,local_320);
        if (iVar4 < 0) {
          FUN_4540500e(0x45448480);
        }
        SysFreeString(local_480);
        local_8 = local_8 & 0xffffff00;
        FUN_45402c5d(&local_47c);
      }
      BVar5 = FindNextFileA(hFindFile,&local_478);
    } while (BVar5 != 0);
    FindClose(hFindFile);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_338,true,0);
  FUN_4542a957();
  return;
}


