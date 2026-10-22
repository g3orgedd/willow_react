// Source: CLCiffConversion_Layout.dll @ 45421a24; FUN_45421a24

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_45421a24(int *param_1)

{
  undefined1 uVar1;
  int iVar2;
  void *pvVar3;
  HRESULT HVar4;
  int *piVar5;
  uint uVar6;
  _union_2683 local_a0;
  VARIANTARG local_90;
  _union_2683 local_80;
  void *local_70;
  void *local_6c;
  int *local_68;
  void *local_64;
  _union_2683 local_60;
  ULONG local_50;
  void *local_4c;
  int *local_48;
  int *local_44;
  int local_40;
  uint local_3c;
  int local_38;
  uint local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x94;
  uVar6 = 0;
  local_3c = 0;
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCiffConversion_Layout::StoreCapiInformation");
  CComQIPtr<>(&local_48,param_1);
  FUN_45429f70((uint *)&local_90,0,0x10);
  VariantInit(&local_90);
  local_a0.n2.vt = 3;
  local_a0._8_4_ = 2;
  local_8._0_1_ = 5;
  iVar2 = (**(code **)(*local_48 + 0xe4))
                    (local_48,local_a0._0_4_,local_a0.decVal.Hi32,2,local_a0._12_4_,&local_90);
  FUN_4541534f(iVar2);
  VariantClear((VARIANTARG *)&local_a0.n2);
  FUN_45429f70((uint *)&local_80,0,0x10);
  VariantInit((VARIANTARG *)&local_80.n2);
  local_80.n2.vt = 8;
  local_8._0_1_ = 6;
  iVar2 = (**(code **)(*param_1 + 0x44))(param_1,&local_80);
  FUN_4541534f(iVar2);
  VariantInit((VARIANTARG *)&local_60.n2);
  iVar2 = (**(code **)(*param_1 + 0x38))(param_1,&local_60);
  if ((-1 < iVar2) && (local_60.n2.vt == 0x2008)) {
    pvVar3 = (void *)FUN_454298b4(0x18);
    local_8._0_1_ = 7;
    uVar1 = (undefined1)local_8;
    local_8._0_1_ = 7;
    if (pvVar3 == (void *)0x0) {
      pvVar3 = (void *)0x0;
      local_8._0_1_ = uVar1;
    }
    else {
      local_4c = pvVar3;
      FUN_45402ac2(&local_38,(wchar_t *)local_90.n1._8_4_);
      local_8 = CONCAT31(local_8._1_3_,8);
      local_3c = 1;
      FUN_45402ac2(&local_34,(wchar_t *)local_80._8_4_);
      uVar6 = 3;
      local_8._0_1_ = 9;
      local_8._1_3_ = 0;
      local_3c = 3;
      pvVar3 = FUN_45412a86(pvVar3,(int *)&local_34,&local_38);
    }
    local_4c = pvVar3;
    if ((uVar6 & 2) != 0) {
      uVar6 = uVar6 & 0xfffffffd;
      FUN_45402c5d((int *)&local_34);
    }
    local_8._0_1_ = 6;
    local_8._1_3_ = 0;
    if ((uVar6 & 1) != 0) {
      uVar6 = uVar6 & 0xfffffffe;
      FUN_45402c5d(&local_38);
    }
    HVar4 = SafeArrayAccessData((SAFEARRAY *)local_60._8_4_,&local_6c);
    FUN_4541534f(HVar4);
    local_50 = ((SAFEARRAYBOUND *)(local_60._8_4_ + 0x10))->cElements;
    if (local_50 == 0) {
      SafeArrayUnaccessData((SAFEARRAY *)local_60._8_4_);
      SafeArrayDestroy((SAFEARRAY *)local_60._8_4_);
      VariantClear((VARIANTARG *)&local_80.n2);
      VariantClear(&local_90);
      local_8 = CONCAT31(local_8._1_3_,2);
      if (local_48 != (int *)0x0) {
        (**(code **)(*local_48 + 8))(local_48);
      }
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
      local_8 = 0xffffffff;
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))(param_1);
      }
      FUN_45421dc7();
      return;
    }
    for (local_34 = 0; local_34 < local_50; local_34 = local_34 + 1) {
      local_70 = (void *)FUN_454298b4(0x24);
      local_8._0_1_ = 0xc;
      local_64 = local_70;
      if (local_70 == (void *)0x0) {
        local_44 = (undefined4 *)0x0;
      }
      else {
        FUN_45402ac2(&local_38,*(wchar_t **)((int)local_6c + local_34 * 4));
        local_8 = CONCAT31(local_8._1_3_,0xd);
        local_3c = uVar6 | 4;
        local_44 = FUN_45415539(pvVar3,(int *)&local_68);
        uVar6 = uVar6 | 0xc;
        local_8 = 0xe;
        local_3c = uVar6;
        piVar5 = (int *)FUN_45425d80((int)pvVar3);
        local_44 = FUN_45412b31(local_64,&local_38,local_44,piVar5);
      }
      local_8 = 0xf;
      if ((uVar6 & 8) != 0) {
        uVar6 = uVar6 & 0xfffffff7;
        local_3c = uVar6;
        if (local_68 != (int *)0x0) {
          (**(code **)(*local_68 + 8))(local_68);
        }
      }
      local_8._0_1_ = 6;
      local_8._1_3_ = 0;
      if ((uVar6 & 4) != 0) {
        uVar6 = uVar6 & 0xfffffffb;
        FUN_45402c5d(&local_38);
      }
      FUN_45413356((int)pvVar3);
    }
    SafeArrayUnaccessData((SAFEARRAY *)local_60._8_4_);
    SafeArrayDestroy((SAFEARRAY *)local_60._8_4_);
    FUN_4542273a((void *)(local_40 + 0x4d0),&local_4c);
  }
  VariantClear((VARIANTARG *)&local_80.n2);
  VariantClear(&local_90);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_48 != (int *)0x0) {
    (**(code **)(*local_48 + 8))(local_48);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  FUN_45421dc7();
  return;
}


