// Source: CLCiffConversion_Data.dll @ 450124ab; FUN_450124ab

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_450124ab(long *param_1,long *param_2,long *param_3)

{
  uint uVar1;
  DOUBLE *pDVar2;
  OLECHAR *pOVar3;
  size_t sVar4;
  wchar_t ****ppppwVar5;
  uint uVar6;
  uint uVar7;
  OLECHAR *in_stack_00000028;
  uint in_stack_00000038;
  uint in_stack_0000003c;
  undefined1 auStack_1494 [8];
  undefined4 uStack_148c;
  uint uStack_147c;
  undefined1 local_146c [8];
  long *local_1464;
  long *local_1460;
  uint local_1458;
  uint local_1454;
  uint local_1450;
  uint local_144c;
  uint local_1448;
  undefined1 *local_1444;
  BSTR local_1440;
  char local_1439;
  int local_1438 [1270];
  undefined1 local_60 [24];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_48 [24];
  wchar_t ***local_30 [4];
  uint local_20;
  uint local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_4503b308;
  local_10 = ExceptionList;
  uStack_147c = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_147c;
  ExceptionList = &local_10;
  local_1460 = param_1;
  local_1464 = param_2;
  local_8 = 1;
  local_18 = uStack_147c;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_48,"CIFFDatabaseResolve::ResolveDateWithDateMask");
  local_1444 = auStack_1494;
  local_8._0_1_ = 2;
  basic_string<>(auStack_1494,L"EN-GB");
  local_8._0_1_ = 3;
  pDVar2 = (DOUBLE *)FUN_450040a4(local_146c);
  local_8._0_1_ = 2;
  FUN_4500abff(local_1438,*pDVar2);
  local_8._0_1_ = 4;
  pOVar3 = (OLECHAR *)&stack0x00000028;
  if (7 < in_stack_0000003c) {
    pOVar3 = in_stack_00000028;
  }
  FUN_45001f5d(&local_1440,pOVar3);
  local_8._0_1_ = 5;
  FUN_4501feaa(local_1438,(int *)&local_1440,0);
  SysFreeString(local_1440);
  uVar7 = 0;
  local_1444 = (undefined1 *)0x0;
  local_1454 = in_stack_00000038;
  local_1440 = (BSTR)0x0;
  local_1439 = '\0';
  local_144c = local_144c & 0xffffff00;
  local_1448 = 0;
  local_1450 = 0;
  local_1458 = 0;
  local_8._0_1_ = 6;
  do {
    if ((int)local_1454 <= (int)uVar7) {
      local_8 = 2;
      FUN_4500ada0(local_1438);
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_48,true,0);
      FUN_450046d9(&stack0x00000010,'\x01',0);
      FUN_450046d9(&stack0x00000028,'\x01',0);
LAB_450127bd:
      ExceptionList = local_10;
      FUN_45022e32(local_18 ^ (uint)&stack0xfffffffc);
      return;
    }
    local_1c = 7;
    local_20 = 0;
    local_30[0] = (wchar_t ***)((uint)local_30[0] & 0xffff0000);
    sVar4 = _wcslen(L"\'");
    FID_conflict_assign(local_30,(undefined8 *)&DAT_4503ee14,sVar4);
    ppppwVar5 = local_30;
    if (7 < local_1c) {
      ppppwVar5 = (wchar_t ****)local_30[0];
    }
    uStack_148c = 0x45012615;
    uVar6 = FUN_450142b7(&stack0x00000028,(wchar_t *)ppppwVar5,(uint)local_1440,local_20);
    FUN_450046d9(local_30,'\x01',0);
    uVar7 = local_1454;
    uVar1 = local_1458;
    if ((uVar6 != 0xffffffff) &&
       (local_1439 = local_1439 == '\0', uVar7 = uVar6, uVar1 = uVar6, (bool)local_1439)) {
      uVar1 = local_1458;
      local_1450 = uVar6;
    }
    local_1458 = uVar1;
    uStack_148c = 0x45012668;
    FUN_45014419(&stack0x00000028,local_60,(uint)local_1440,uVar7 - (int)local_1440);
    local_8._0_1_ = 7;
    basic_string<>(&stack0xffffeb64,(undefined8 *)&stack0x00000010);
    local_1444 = (undefined1 *)FUN_45010bdd(local_1460,local_1464,param_3,&local_1448);
    if ((int)local_1444 < 0) {
      FUN_4500274d(0x4503f4fc);
      FUN_450046d9(local_60,'\x01',0);
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_4500ada0(local_1438);
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_48,true,0);
      FUN_450046d9(&stack0x00000010,'\x01',0);
      FUN_450046d9(&stack0x00000028,'\x01',0);
      goto LAB_450127bd;
    }
    if ((local_1439 == '\0') && ((int)local_1450 < (int)local_1458)) {
      local_1448 = (local_1448 - 1) + (local_1458 - local_1450);
    }
    local_1440 = (BSTR)(uVar7 + 1);
    local_144c = CONCAT31(local_144c._1_3_,local_1439);
    local_8._0_1_ = 6;
    FUN_450046d9(local_60,'\x01',0);
  } while( true );
}


