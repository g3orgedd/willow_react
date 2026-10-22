// Source: CLCSTextBasedField.dll @ 42468233; FUN_42468233

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_42468233(int param_1)

{
  HANDLE hFindFile;
  undefined4 *puVar1;
  int iVar2;
  BOOL BVar3;
  BSTR local_698;
  BSTR local_694;
  int local_690;
  _WIN32_FIND_DATAW local_68c;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_43c [24];
  wchar_t local_424 [260];
  wchar_t local_21c [266];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x688;
  local_8 = 0x42468242;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_43c,"ZipherBitmapFont::PopulateZipherFontList()");
  local_8 = 0;
  _swprintf_s(local_424,0x104,L"%ls\\*.zfbf",*(undefined4 *)(param_1 + 0x44));
  hFindFile = FindFirstFileW(local_424,&local_68c);
  if (hFindFile == (HANDLE)0xffffffff) {
    FUN_424037d2(&local_694,local_68c.cFileName);
    SysFreeString(local_694);
  }
  else {
    do {
      if (((byte)local_68c.dwFileAttributes & 0x10) == 0) {
        FUN_4240391a(&local_690,local_68c.cFileName);
        local_8._0_1_ = 1;
        puVar1 = FUN_42405bbb(&local_690,&local_694,*(int *)(local_690 + -8) + -5);
        local_8._0_1_ = 2;
        FUN_424037d2(&local_698,(OLECHAR *)*puVar1);
        local_8 = CONCAT31(local_8._1_3_,4);
        FUN_42403ad1((int *)&local_694);
        _swprintf_s(local_21c,0x104,L"%ls%ls",*(undefined4 *)(param_1 + 0x44),local_68c.cFileName);
        iVar2 = (**(code **)(**(int **)(param_1 + 4) + 0x10))
                          (*(int **)(param_1 + 4),local_698,local_21c);
        if (iVar2 < 0) {
          FUN_42403ff7(0x4249b85c);
        }
        SysFreeString(local_698);
        local_8 = local_8 & 0xffffff00;
        FUN_42403ad1(&local_690);
      }
      BVar3 = FindNextFileW(hFindFile,&local_68c);
    } while (BVar3 != 0);
    FindClose(hFindFile);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_43c,true,0);
  FUN_4246ecf6();
  return;
}


