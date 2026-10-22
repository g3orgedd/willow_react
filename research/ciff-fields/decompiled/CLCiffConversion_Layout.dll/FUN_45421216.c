// Source: CLCiffConversion_Layout.dll @ 45421216; FUN_45421216

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_45421216(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  int *piVar3;
  HANDLE hFindFile;
  LPCSTR pCVar4;
  int local_194;
  int local_190;
  int local_18c;
  int local_188;
  int local_184;
  undefined *local_180;
  LPCSTR local_17c;
  int local_178;
  BSTR local_174;
  _WIN32_FIND_DATAA local_170;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x188;
  local_8 = 0x45421225;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCiffConversion_Layout::SaveConvertedCiff");
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if (DAT_4545fba3 != '\0') {
    FUN_4541d303(&local_188);
    local_8._0_1_ = 2;
    FUN_45402ac2(&local_178,*(wchar_t **)(param_1 + 0xc0));
    local_8._0_1_ = 3;
    if (*(int *)(local_178 + -8) == 0) {
      FUN_45402cd0(&local_178,"none");
    }
    local_17c = PTR_DAT_4545d110;
    local_8._0_1_ = 4;
    local_184 = 1;
    bVar1 = false;
    pCVar4 = PTR_DAT_4545d110;
    while (!bVar1) {
      local_180 = PTR_DAT_4545d110;
      local_8._0_1_ = 5;
      FUN_45405c46(&local_180,"%d");
      puVar2 = FUN_454131dc(&local_174,&local_188,&local_178);
      local_8._0_1_ = 6;
      puVar2 = FUN_45413224(&local_18c,puVar2,"_");
      local_8._0_1_ = 7;
      puVar2 = FUN_454131dc(&local_194,puVar2,&local_180);
      local_8._0_1_ = 8;
      piVar3 = FUN_45413224(&local_190,puVar2,".xml");
      local_8._0_1_ = 9;
      FUN_454077ad(&local_17c,piVar3);
      FUN_45402c5d(&local_190);
      FUN_45402c5d(&local_194);
      FUN_45402c5d(&local_18c);
      FUN_45402c5d((int *)&local_174);
      pCVar4 = local_17c;
      hFindFile = FindFirstFileA(local_17c,&local_170);
      if (hFindFile == (HANDLE)0xffffffff) {
        bVar1 = true;
      }
      FindClose(hFindFile);
      local_184 = local_184 + 1;
      local_8._0_1_ = 4;
      FUN_45402c5d((int *)&local_180);
    }
    piVar3 = *(int **)(param_1 + 0x30);
    puVar2 = FUN_454028b9(&local_174,pCVar4);
    local_8._0_1_ = 10;
    (**(code **)(*piVar3 + 0x34))(piVar3,*puVar2,1);
    SysFreeString(local_174);
    FUN_45402c5d((int *)&local_17c);
    FUN_45402c5d(&local_178);
    FUN_45402c5d(&local_188);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
  FUN_4542147a();
  return;
}


