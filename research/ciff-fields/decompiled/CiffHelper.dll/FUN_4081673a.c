// Source: CiffHelper.dll @ 4081673a; FUN_4081673a

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_4081673a(BSTR param_1,int param_2,ulong param_3,undefined4 param_4,undefined4 *param_5,
                 undefined4 param_6,int param_7)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  UINT UVar4;
  LPCWSTR extraout_ECX;
  BSTR pOVar5;
  BSTR pOVar6;
  int iVar7;
  LPCWSTR pWVar8;
  undefined4 local_6c;
  BSTR local_64;
  int *local_60;
  BSTR local_5c;
  BSTR local_58;
  char local_51;
  undefined4 *local_50;
  BSTR local_4c;
  BSTR local_48;
  BSTR local_44;
  undefined1 local_40 [12];
  uchar auStack_34 [4];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x60;
  local_8 = 0x40816746;
  local_40._0_4_ = param_3;
  local_48 = param_1;
  local_40._4_4_ = param_4;
  local_40._8_4_ = param_5;
  auStack_34 = (uchar  [4])param_6;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCiffDataHelper::ResolveData");
  local_8 = 0;
  CComQIPtr<>(&local_44,*(undefined4 **)(param_2 + 8));
  CComQIPtr<>(&local_64,(undefined4 *)local_40._8_4_);
  local_8._0_1_ = 2;
  (**(code **)(*(int *)local_44 + 0x50))();
  pOVar6 = local_48;
  switch(local_6c) {
  case 0:
    pOVar6 = local_44;
    if (local_44 != (BSTR)0x0) {
      (**(code **)(*(int *)local_44 + 4))(local_44);
    }
    FUN_4080e4be(local_48,(int *)pOVar6);
    goto LAB_40816a18;
  case 1:
  case 2:
    pOVar6 = local_44;
    if (local_44 != (BSTR)0x0) {
      (**(code **)(*(int *)local_44 + 4))(local_44);
    }
    FUN_4080d4a9((int *)pOVar6,param_7);
    break;
  case 3:
  case 7:
    FUN_4080d5b4(local_48,(int *)local_64,(int *)local_44,param_7);
    break;
  case 4:
    pOVar6 = local_44;
    if (local_44 != (BSTR)0x0) {
      (**(code **)(*(int *)local_44 + 4))(local_44);
    }
    FUN_4080d1ee(local_48,(int *)pOVar6);
    break;
  case 5:
    local_51 = '\0';
    if (*(int *)(local_48 + 0x36) == 0) {
      puVar2 = (undefined4 *)FUN_4082d9f3(8);
      local_8._0_1_ = 3;
      local_50 = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        *puVar2 = 0;
        puVar2[1] = 0;
        uVar3 = FUN_4080374f((int *)0x0,(int *)0x0);
        *puVar2 = uVar3;
      }
      *(undefined4 **)(pOVar6 + 0x36) = puVar2;
      local_51 = '\x01';
    }
    local_4c = (BSTR)0x0;
    local_8._0_1_ = 4;
    (**(code **)(*(int *)local_44 + 0xe4))(local_44);
    pWVar8 = extraout_ECX;
    FUN_40803baf(&stack0xffffff74,(int *)&local_4c);
    cVar1 = FUN_4081a593(pOVar6,pWVar8);
    if (cVar1 == '\0') {
      local_5c = local_64;
      if (local_64 != (BSTR)0x0) {
        (**(code **)(*(int *)local_64 + 4))();
      }
      local_8._0_1_ = 5;
      local_58 = local_44;
      if (local_44 != (BSTR)0x0) {
        (**(code **)(*(int *)local_44 + 4))();
      }
      local_8._0_1_ = 6;
      FUN_4080e231((int *)&local_58,(int *)&local_5c,param_7);
      local_8._0_1_ = 5;
      if (local_58 != (BSTR)0x0) {
        (**(code **)(*(int *)local_58 + 8))();
      }
      local_8._0_1_ = 4;
      if (local_5c != (BSTR)0x0) {
        (**(code **)(*(int *)local_5c + 8))();
      }
    }
    else {
      local_48 = (BSTR)0x0;
      local_8._0_1_ = 7;
      FUN_4080be87(&local_48,"####");
      (**(code **)(*(int *)local_44 + 100))(local_44);
      (**(code **)(*(int *)local_44 + 0x5c))(local_44,local_48);
      SysFreeString(local_48);
    }
    if (local_51 == '\x01') {
      if (*(void **)(pOVar6 + 0x36) != (void *)0x0) {
        FUN_40812187(*(void **)(pOVar6 + 0x36),1);
      }
      pOVar6[0x36] = L'\0';
      pOVar6[0x37] = L'\0';
    }
LAB_40816a0f:
    SysFreeString(local_4c);
    goto LAB_40816a18;
  case 6:
    if ((char)local_48[0x3c] == '\0') {
      local_4c = (BSTR)0x0;
      local_8._0_1_ = 8;
      (**(code **)(*(int *)local_44 + 0x58))(local_44);
      (**(code **)(*(int *)local_44 + 100))(local_44,local_4c);
      goto LAB_40816a0f;
    }
    pOVar5 = local_44;
    if (local_44 != (BSTR)0x0) {
      (**(code **)(*(int *)local_44 + 4))(local_44);
    }
    FUN_40810976(pOVar6,(int *)pOVar5);
    goto LAB_40816a18;
  case 8:
    local_60 = (int *)0x0;
    (**(code **)(*(int *)local_44 + 0x48))(local_44);
    if (local_60 == (int *)0x5) {
      iVar7 = 0;
      pOVar6 = local_44;
      if (local_44 != (BSTR)0x0) {
        (**(code **)(*(int *)local_44 + 4))(local_44);
      }
      FUN_4080d4a9((int *)pOVar6,iVar7);
    }
    else {
      pOVar6 = local_44;
      if (local_44 != (BSTR)0x0) {
        (**(code **)(*(int *)local_44 + 4))(local_44);
      }
      FUN_4080e4be(local_48,(int *)pOVar6);
    }
LAB_40816a18:
    CComQIPtr<>(&local_60,(undefined4 *)local_44);
    local_8._0_1_ = 10;
    if (local_60 == (int *)0x0) {
      FUN_40804125(0x4084c638);
    }
    else {
      local_48 = (BSTR)0x0;
      local_8._0_1_ = 0xb;
      (**(code **)(*local_60 + 0x168))(local_60);
      UVar4 = SysStringLen(local_48);
      if (UVar4 != 0) {
        CLSIDFromProgID(local_48,(LPCLSID)local_40);
        local_4c = (BSTR)0x0;
        local_8._0_1_ = 0xc;
        CoCreateInstance((IID *)local_40,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_4084c6d8,&local_4c);
        if (local_4c == (BSTR)0x0) {
          FUN_40804125(0x4084c60c);
        }
        else {
          local_58 = (BSTR)0x0;
          local_5c = (BSTR)0x0;
          local_8._0_1_ = 0xe;
          (**(code **)(*(int *)local_44 + 0x60))(local_44);
          (**(code **)(*local_60 + 0x160))(local_60,&local_50);
          iVar7 = (**(code **)(*(int *)local_4c + 0xc))(local_4c,local_58,local_50,&local_5c);
          if (iVar7 == 0) {
            (**(code **)(*(int *)local_44 + 100))(local_44);
          }
          SysFreeString(local_5c);
          SysFreeString(local_58);
        }
        local_8._0_1_ = 0xb;
        if (local_4c != (BSTR)0x0) {
          (**(code **)(*(int *)local_4c + 8))();
        }
      }
      SysFreeString(local_48);
    }
    local_8 = CONCAT31(local_8._1_3_,9);
    if (local_60 != (int *)0x0) {
      (**(code **)(*local_60 + 8))();
    }
    local_8._0_1_ = 2;
    local_8._1_3_ = 0;
    break;
  case 9:
    pOVar6 = local_44;
    if (local_44 != (BSTR)0x0) {
      (**(code **)(*(int *)local_44 + 4))(local_44);
    }
    pOVar5 = local_64;
    if (local_64 != (BSTR)0x0) {
      (**(code **)(*(int *)local_64 + 4))(local_64);
    }
    FUN_4080d9b3((int *)pOVar5,(int *)pOVar6);
  }
  pOVar6 = local_44;
  if (local_44 != (BSTR)0x0) {
    (**(code **)(*(int *)local_44 + 4))(local_44);
  }
  FUN_4081a65d((int *)pOVar6);
  local_8._0_1_ = 1;
  if (local_64 != (BSTR)0x0) {
    (**(code **)(*(int *)local_64 + 8))();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_44 != (BSTR)0x0) {
    (**(code **)(*(int *)local_44 + 8))();
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
  FUN_4082d4d5();
  return;
}


