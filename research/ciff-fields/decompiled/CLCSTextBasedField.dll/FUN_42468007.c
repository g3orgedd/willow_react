// Source: CLCSTextBasedField.dll @ 42468007; FUN_42468007

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_42468007(void *this,undefined4 *param_1)

{
  HANDLE hFindFile;
  undefined4 *puVar1;
  BOOL BVar2;
  int local_698;
  BSTR local_694;
  int local_690;
  _WIN32_FIND_DATAW local_68c;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_43c [24];
  wchar_t local_424 [260];
  wchar_t local_21c [266];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x690;
  *param_1 = 0;
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_43c,"ZipherBitmapFont::GetDefaultFont()");
  local_8 = 1;
  _swprintf_s(local_21c,0x104,L"%ls\\*.zfbf",*(undefined4 *)((int)this + 0x44));
  hFindFile = FindFirstFileW(local_21c,&local_68c);
  if (hFindFile != (HANDLE)0xffffffff) {
    do {
      if (((byte)local_68c.dwFileAttributes & 0x10) == 0) {
        FUN_4240391a(&local_690,local_68c.cFileName);
        local_8._0_1_ = 2;
        puVar1 = FUN_42405bbb(&local_690,&local_698,*(int *)(local_690 + -8) + -5);
        local_8._0_1_ = 3;
        FUN_424037d2(&local_694,(OLECHAR *)*puVar1);
        local_8._0_1_ = 5;
        FUN_42403ad1(&local_698);
        _swprintf_s(local_424,0x104,L"%ls%ls",*(undefined4 *)((int)this + 0x44),local_68c.cFileName)
        ;
        FUN_42403b34(param_1,(int *)&local_694);
        SysFreeString(local_694);
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_42403ad1(&local_690);
      }
      BVar2 = FindNextFileW(hFindFile,&local_68c);
    } while (BVar2 != 0);
    FindClose(hFindFile);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_43c,true,0);
  FUN_4246ecf6();
  return;
}


