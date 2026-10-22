// Source: CLCiffConversion_Data.dll @ 4500d9dc; FUN_4500d9dc

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_4500d9dc(int param_1,BSTR param_2)

{
  OLECHAR OVar1;
  int *piVar2;
  int iVar3;
  HRESULT HVar4;
  undefined4 *puVar5;
  int *piVar6;
  void *this;
  _union_2683 local_5c;
  int local_4c;
  void *local_48;
  int local_44;
  int *local_40;
  int *local_3c;
  BSTR local_38;
  int *local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x50;
  local_8 = 0x4500d9e8;
  local_4c = param_1;
  local_44 = param_1;
  local_38 = param_2;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCiffConversion_Data::Convert (vtCiffFile)");
  local_48 = (void *)(param_1 + -8);
  local_8 = 1;
  iVar3 = FUN_450191b3();
  if (iVar3 != 0) goto LAB_4500dcc3;
  piVar6 = (int *)(param_1 + 0x28);
  if (*param_2 == L'\b') {
    local_40 = piVar6;
    if (*piVar6 != 0) {
      piVar2 = (int *)*piVar6;
      if (piVar2 != (int *)0x0) {
        *piVar6 = 0;
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      piVar2 = (int *)*piVar6;
      if (piVar2 != (int *)0x0) {
        *piVar6 = 0;
        (**(code **)(*piVar2 + 8))(piVar2);
      }
    }
    local_3c = (int *)0x0;
    HVar4 = CoCreateInstance((IID *)&DAT_4503e290,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_4503f904,&local_3c
                            );
    if ((HVar4 < 0) || (local_3c == (int *)0x0)) {
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_3c != (int *)0x0) {
        (**(code **)(*local_3c + 8))(local_3c);
      }
      goto LAB_4500dcc3;
    }
    CComQIPtr<>(&local_34,local_3c);
    piVar6 = local_34;
    local_8._0_1_ = 3;
    if (local_34 != (int *)0x0) {
      puVar5 = FUN_45001f5d(&local_38,*(OLECHAR **)(local_38 + 4));
      local_8._0_1_ = 4;
      HVar4 = (**(code **)(*piVar6 + 0x2c))(piVar6,*puVar5,local_40);
      SysFreeString(local_38);
    }
    if (-1 < HVar4) {
      local_38 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,5);
      HVar4 = CoCreateInstance((IID *)&DAT_4503d9d0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_4503eafc,
                               &local_38);
      piVar6 = local_40;
      if ((-1 < HVar4) && (local_38 != (BSTR)0x0)) {
        local_5c._8_4_ = *local_40;
        local_5c.n2.vt = 9;
        if ((int *)local_5c._8_4_ != (int *)0x0) {
          (**(code **)(*(int *)local_5c._8_4_ + 4))(local_5c._8_4_);
        }
        local_8 = CONCAT31(local_8._1_3_,6);
        HVar4 = (**(code **)(*(int *)local_38 + 0xbc))(local_38,&local_5c);
        VariantClear((VARIANTARG *)&local_5c.n2);
      }
      local_8._0_1_ = 3;
      if (local_38 != (BSTR)0x0) {
        (**(code **)(*(int *)local_38 + 8))(local_38);
      }
      if (-1 < HVar4) {
        local_8._0_1_ = 2;
        if (local_34 != (int *)0x0) {
          (**(code **)(*local_34 + 8))(local_34);
        }
        local_8 = CONCAT31(local_8._1_3_,1);
        param_1 = local_4c;
        if (local_3c != (int *)0x0) {
          (**(code **)(*local_3c + 8))(local_3c);
          param_1 = local_4c;
        }
        goto LAB_4500db71;
      }
    }
    local_8._0_1_ = 2;
    if (local_34 != (int *)0x0) {
      (**(code **)(*local_34 + 8))(local_34);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_3c != (int *)0x0) {
      (**(code **)(*local_3c + 8))(local_3c);
    }
  }
  else {
    if (*piVar6 != 0) {
      piVar2 = (int *)*piVar6;
      if (piVar2 != (int *)0x0) {
        *piVar6 = 0;
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      piVar2 = (int *)*piVar6;
      if (piVar2 != (int *)0x0) {
        *piVar6 = 0;
        (**(code **)(*piVar2 + 8))(piVar2);
      }
    }
    OVar1 = *local_38;
    if (OVar1 == L'䀉') {
LAB_4500dc26:
      puVar5 = (undefined4 *)**(undefined4 **)(local_38 + 4);
    }
    else {
      if (OVar1 != L'\t') {
        if (OVar1 == L'䀍') goto LAB_4500dc26;
        if (OVar1 != L'\r') goto LAB_4500db71;
      }
      puVar5 = *(undefined4 **)(local_38 + 4);
    }
    CComQIPtr<>(&local_34,puVar5);
    FUN_450022ba(piVar6,(int *)&local_34);
    if (local_34 != (int *)0x0) {
      (**(code **)(*local_34 + 8))(local_34);
    }
LAB_4500db71:
    if (*piVar6 == 0) {
      FUN_4500274d(0x4503f7c8);
      this = local_48;
    }
    else {
      if (*(short *)(param_1 + 400) == 8) {
        FUN_45002365((void *)(param_1 + 0x4e8),*(LPCWSTR *)(param_1 + 0x198));
      }
      else {
        FUN_4500af16((void *)(param_1 + 0x4e8),"");
      }
      if (*(short *)(param_1 + 0x340) == 8) {
        FUN_45002326((void *)(param_1 + 0x4ec),*(OLECHAR **)(param_1 + 0x348));
      }
      else {
        SysFreeString(*(BSTR *)(param_1 + 0x4ec));
        *(undefined4 *)(param_1 + 0x4ec) = 0;
      }
      this = local_48;
      iVar3 = FUN_4500e5b6((int)local_48);
      if ((-1 < iVar3) && (iVar3 = FUN_4500d930((int)this), -1 < iVar3)) {
        FUN_45013166((int)this);
      }
    }
    FUN_45018d66(this,'\0');
    FUN_4500b59c((int)this);
  }
LAB_4500dcc3:
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
  FUN_4500dd5a();
  return;
}


