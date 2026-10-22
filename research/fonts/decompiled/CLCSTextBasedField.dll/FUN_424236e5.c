// Source: CLCSTextBasedField.dll @ 424236e5; FUN_424236e5

void FUN_424236e5(int param_1,HDC param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 *param_6,undefined4 param_7,undefined4 param_8,ULONG param_9,
                 undefined4 *param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,
                 undefined4 *param_14,undefined4 param_15,COLORREF param_16)

{
  bool bVar1;
  char cVar2;
  UINT UVar3;
  OLECHAR *pOVar4;
  int *piVar5;
  undefined4 *puVar6;
  BSTR extraout_ECX;
  BSTR extraout_ECX_00;
  int *piVar7;
  int *piVar8;
  BSTR pOVar9;
  BSTR pOVar10;
  void **ppvObject;
  VARIANTARG local_b4;
  undefined4 local_a4;
  ULONG UStack_a0;
  undefined4 *local_9c;
  undefined4 uStack_98;
  undefined4 local_94;
  undefined4 uStack_90;
  undefined4 *local_8c;
  undefined4 uStack_88;
  undefined4 local_84;
  undefined4 uStack_80;
  undefined4 *local_7c;
  undefined4 uStack_78;
  _union_2683 local_74;
  int *local_64;
  int *local_60;
  int *local_5c;
  int local_58;
  int *local_54;
  void **local_50;
  int *local_4c [2];
  int *local_44;
  BSTR local_40;
  IUnknown *local_3c;
  undefined1 local_38 [4];
  BSTR local_34;
  BSTR local_30;
  HDC local_2c;
  BSTR local_28;
  int local_24;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_20 [24];
  uint local_8;
  
  local_8 = DAT_424ba210 ^ (uint)&stack0xfffffffc;
  local_24 = param_1;
  local_84 = param_4;
  local_2c = param_2;
  uStack_80 = param_5;
  local_7c = param_6;
  uStack_78 = param_7;
  local_a4 = param_8;
  UStack_a0 = param_9;
  local_9c = param_10;
  uStack_98 = param_11;
  local_94 = param_12;
  uStack_90 = param_13;
  local_8c = param_14;
  uStack_88 = param_15;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_20,"CCLCSTextBasedFieldObj::Draw");
  local_28 = (BSTR)0x0;
  CComQIPtr<>(&local_54,local_7c);
  piVar7 = local_54;
  local_60 = local_54;
  if (local_54 != (int *)0x0) {
    (**(code **)(*local_54 + 4))();
  }
  CComQIPtr<>(&local_44,local_9c);
  piVar8 = local_44;
  local_5c = local_44;
  if (local_44 != (int *)0x0) {
    (**(code **)(*local_44 + 4))();
  }
  CComQIPtr<>(local_4c,local_8c);
  local_64 = local_4c[0];
  if (local_4c[0] != (int *)0x0) {
    (**(code **)(*local_4c[0] + 4))();
  }
  local_40 = (BSTR)0x0;
  (**(code **)(*piVar7 + 0xa8))();
  FUN_42403802((uint *)&local_b4);
  (**(code **)(*piVar8 + 0x474))();
  CComQIPtr<>(&local_50,(undefined4 *)local_b4.n1._8_4_);
  FUN_42403802((uint *)&local_74);
  ppvObject = local_50;
  (**(code **)((int)*local_50 + 0x30))();
  local_38 = (undefined1  [4])0x0;
  local_3c = (IUnknown *)0x0;
  if (local_74.n2.vt != 0) {
    if ((IUnknown *)local_74._8_4_ != (IUnknown *)0x0) {
      ATL::AtlComQIPtrAssign(&local_3c,(IUnknown *)local_74._8_4_,(_GUID *)&DAT_42495a7c);
    }
    (*local_3c->lpVtbl[0xd].QueryInterface)(local_3c,(IID *)local_38,ppvObject);
  }
  local_58 = 0;
  (**(code **)(*piVar7 + 0x124))();
  UVar3 = SysStringLen((BSTR)local_38);
  if ((UVar3 != 0) && (bVar1 = FUN_42403bfa(local_38,L"TrueType"), !bVar1)) {
    local_30 = (BSTR)0x0;
    pOVar4 = FUN_42459daa();
    FUN_424037d2(&local_34,pOVar4);
    (**(code **)(*piVar7 + 0xa8))();
    pOVar10 = extraout_ECX;
    FUN_42403768(&stack0xffffff18,(int *)local_38);
    pOVar9 = extraout_ECX_00;
    FUN_42403768(&stack0xffffff14,(int *)&local_30);
    cVar2 = FUN_4242558d(pOVar9,pOVar10);
    if (cVar2 == '\0') {
      if (*(char *)(local_24 + 0xe0) == '\0') {
        local_28 = (BSTR)0x0;
        (**(code **)(*piVar7 + 0x1c))();
        local_2c = (HDC)PTR_DAT_424b9014;
        *(undefined1 *)(local_24 + 0xe0) = 1;
        piVar5 = FUN_4245a1e4(&local_24,0x6090);
        FUN_42407350(&local_2c,piVar5);
        FUN_42403ad1(&local_24);
        puVar6 = FUN_4245a2d5(&local_24,0x30d4);
        MessageBoxW((HWND)0x0,(LPCWSTR)local_2c,(LPCWSTR)*puVar6,0);
        FUN_42403ad1(&local_24);
        FUN_42403ad1((int *)&local_2c);
        SysFreeString(local_28);
      }
      SysFreeString(local_34);
      SysFreeString(local_30);
      local_28 = (BSTR)0x80004005;
      goto LAB_42423aa8;
    }
    SysFreeString(local_34);
    SysFreeString(local_30);
  }
  if ((local_58 == 2) || (bVar1 = FUN_42403bfa(local_38,L"ZFBF"), bVar1)) {
    if (local_3c != (IUnknown *)0x0) {
      (*local_3c->lpVtbl->AddRef)(local_3c);
    }
    FUN_424683cb((void *)(local_24 + 0x74),local_2c,param_3,local_84,uStack_80,local_7c,uStack_78);
    piVar7 = local_60;
    piVar8 = local_5c;
  }
  else if (local_3c == (IUnknown *)0x0) {
    local_28 = (BSTR)FUN_42424518((void *)(local_24 + -8),local_2c,param_3,local_84,uStack_80,
                                  local_7c,uStack_78,local_a4,UStack_a0,local_9c,uStack_98,local_94,
                                  uStack_90,local_8c,uStack_88,param_16);
    piVar7 = local_60;
    piVar8 = local_5c;
  }
  else {
    CComQIPtr<>(&local_30,(undefined4 *)local_74._8_4_);
    local_34 = (BSTR)0x0;
    (**(code **)(*(int *)local_30 + 0x9c))();
    bVar1 = FUN_42403bfa(&local_34,L"TrueType");
    if (bVar1) {
      local_28 = (BSTR)FUN_42424518((void *)(local_24 + -8),local_2c,param_3,local_84,uStack_80,
                                    local_7c,uStack_78,local_a4,UStack_a0,local_9c,uStack_98,
                                    local_94,uStack_90,local_8c,uStack_88,param_16);
    }
    else {
      local_28 = (BSTR)FUN_42423b45((void *)(local_24 + -8),local_2c,param_3,(short)local_84,
                                    uStack_80,local_7c);
    }
    SysFreeString(local_34);
    piVar7 = local_60;
    piVar8 = local_5c;
    if (local_30 != (BSTR)0x0) {
      (**(code **)(*(int *)local_30 + 8))();
      piVar7 = local_60;
      piVar8 = local_5c;
    }
  }
LAB_42423aa8:
  if (local_3c != (IUnknown *)0x0) {
    (*local_3c->lpVtbl->Release)(local_3c);
  }
  SysFreeString((BSTR)local_38);
  VariantClear((VARIANTARG *)&local_74.n2);
  if (local_50 != (void **)0x0) {
    (**(code **)((int)*local_50 + 8))();
  }
  VariantClear(&local_b4);
  SysFreeString(local_40);
  if (local_4c[0] != (int *)0x0) {
    (**(code **)(*local_4c[0] + 8))();
  }
  if (local_64 != (int *)0x0) {
    (**(code **)(*local_64 + 8))();
  }
  if (local_44 != (int *)0x0) {
    (**(code **)(*local_44 + 8))();
  }
  (**(code **)(*piVar8 + 8))();
  (**(code **)(*piVar7 + 8))();
  if (local_54 != (int *)0x0) {
    (**(code **)(*local_54 + 8))(local_54);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_20,true,0);
  FUN_4246ec70(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


