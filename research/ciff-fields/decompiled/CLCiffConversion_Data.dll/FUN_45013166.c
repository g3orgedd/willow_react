// Source: CLCiffConversion_Data.dll @ 45013166; FUN_45013166

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_45013166(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  int *piVar3;
  HANDLE hFindFile;
  LPCWSTR pWVar4;
  int local_2ac;
  int local_2a8;
  int local_2a4;
  int local_2a0;
  int local_29c;
  int local_298;
  int local_294;
  undefined *local_290;
  LPCWSTR local_28c;
  int local_288;
  BSTR local_284;
  _WIN32_FIND_DATAW local_280;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2a0;
  local_8 = 0x45013175;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCiffConversion_Data::SaveConvertedCiff");
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if (DAT_45053980 != '\0') {
    FUN_4500ffa3(&local_298);
    local_8._0_1_ = 2;
    FUN_450020a5(&local_288,*(LPCWSTR *)(param_1 + 0x1d0));
    local_8._0_1_ = 3;
    if (*(int *)(local_288 + -8) == 0) {
      FUN_4500af16(&local_288,"none");
    }
    local_28c = (LPCWSTR)PTR_DAT_4505101c;
    local_8._0_1_ = 4;
    local_294 = 1;
    bVar1 = false;
    pWVar4 = (LPCWSTR)PTR_DAT_4505101c;
    while (!bVar1) {
      local_290 = PTR_DAT_4505101c;
      local_8._0_1_ = 5;
      FUN_450037ea(&local_290,L"%d");
      FUN_45002050(&local_29c,".xml");
      local_8._0_1_ = 6;
      FUN_45002050(&local_2a0,"_");
      local_8._0_1_ = 7;
      puVar2 = FUN_450059c5(&local_284,&local_298,&local_288);
      local_8._0_1_ = 8;
      puVar2 = FUN_450059c5(&local_2a4,puVar2,&local_2a0);
      local_8._0_1_ = 9;
      puVar2 = FUN_450059c5(&local_2a8,puVar2,&local_290);
      local_8._0_1_ = 10;
      piVar3 = FUN_450059c5(&local_2ac,puVar2,&local_29c);
      local_8._0_1_ = 0xb;
      FUN_45008a06(&local_28c,piVar3);
      FUN_45002256(&local_2ac);
      FUN_45002256(&local_2a8);
      FUN_45002256(&local_2a4);
      FUN_45002256((int *)&local_284);
      FUN_45002256(&local_2a0);
      FUN_45002256(&local_29c);
      pWVar4 = local_28c;
      hFindFile = FindFirstFileW(local_28c,&local_280);
      if (hFindFile == (HANDLE)0xffffffff) {
        bVar1 = true;
      }
      FindClose(hFindFile);
      local_294 = local_294 + 1;
      local_8._0_1_ = 4;
      FUN_45002256((int *)&local_290);
    }
    piVar3 = *(int **)(param_1 + 0x30);
    puVar2 = FUN_45001f5d(&local_284,pWVar4);
    local_8._0_1_ = 0xc;
    (**(code **)(*piVar3 + 0x34))(piVar3,*puVar2,1);
    SysFreeString(local_284);
    FUN_45002256((int *)&local_28c);
    FUN_45002256(&local_288);
    FUN_45002256(&local_298);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
  FUN_4501340c();
  return;
}


