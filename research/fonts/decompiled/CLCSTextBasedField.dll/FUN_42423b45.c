// Source: CLCSTextBasedField.dll @ 42423b45; FUN_42423b45

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall
FUN_42423b45(void *this,HDC param_1,int param_2,short param_3,undefined4 param_4,undefined4 *param_5
            )

{
  int *piVar1;
  int *piVar2;
  HDC hdc;
  bool bVar3;
  OLECHAR *pOVar4;
  HBRUSH pHVar5;
  int iVar6;
  HBITMAP h;
  int *piVar7;
  undefined4 *in_stack_00000024;
  undefined4 *in_stack_00000034;
  COLORREF in_stack_0000003c;
  BSTR pOVar8;
  int *piVar9;
  int iVar10;
  VARIANTARG local_174;
  int *local_164;
  int *local_160;
  int *local_15c;
  _union_2683 local_158;
  undefined1 local_148 [4];
  int local_144;
  int local_140;
  tagSIZE local_130;
  int local_128;
  int local_124;
  int local_120;
  int local_11c;
  int local_118;
  tagSIZE local_114;
  tagSIZE local_10c;
  tagPOINT local_104;
  tagSIZE local_fc;
  tagSIZE local_f4;
  tagSIZE local_ec;
  tagSIZE local_e4;
  int local_dc;
  int local_d8;
  int *local_d4;
  int *local_d0;
  int *local_cc;
  int *local_c8;
  int *local_c4;
  int *local_c0;
  COLORREF local_bc;
  int local_b8;
  int local_b4;
  COLORREF local_b0;
  tagSIZE local_ac;
  BSTR local_a4;
  tagSIZE local_a0;
  int *local_98;
  HGDIOBJ local_94;
  HBITMAP local_90;
  void *local_8c;
  BSTR local_88;
  BSTR local_84;
  int local_80;
  int *local_7c;
  uint local_78;
  LPCWSTR local_74;
  int *local_70;
  int local_6c;
  int local_68;
  HDC local_64;
  HDC local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  RECT local_34;
  RECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x194;
  local_8 = 0x42423b54;
  local_64 = param_1;
  local_8c = this;
  if ((DAT_424bfb58 & 1) == 0) {
    DAT_424bfb58 = DAT_424bfb58 | 1;
    local_8 = 0;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_424bfb40,
               "CCLCSTextBasedFieldObj::DrawUBF");
    FUN_4246f3f8(&LAB_42493eb2);
    local_8 = 0xffffffff;
  }
  if (param_3 == 9) {
    local_60 = CreateCompatibleDC(local_64);
    CComQIPtr<>(&local_d0,param_5);
    piVar1 = local_d0;
    local_164 = local_d0;
    local_8 = 2;
    if (local_d0 != (int *)0x0) {
      (**(code **)(*local_d0 + 4))();
    }
    CComQIPtr<>(&local_cc,in_stack_00000024);
    piVar2 = local_cc;
    local_8._0_1_ = 4;
    local_15c = local_cc;
    if (local_cc != (int *)0x0) {
      (**(code **)(*local_cc + 4))();
    }
    CComQIPtr<>(&local_c4,in_stack_00000034);
    piVar7 = local_c4;
    local_8._0_1_ = 6;
    local_70 = local_c4;
    local_160 = local_c4;
    if (local_c4 != (int *)0x0) {
      (**(code **)(*local_c4 + 4))();
    }
    local_10c.cx = 0;
    local_10c.cy = 0;
    local_ec.cx = 0;
    local_ec.cy = 0;
    local_a0.cx = 0;
    local_a0.cy = 0;
    local_ac.cx = 0;
    local_ac.cy = 0;
    local_84 = (BSTR)0x0;
    local_8._0_1_ = 7;
    (**(code **)(*piVar1 + 0xa8))();
    FUN_42403802((uint *)&local_174);
    local_8._0_1_ = 8;
    (**(code **)(*piVar2 + 0x474))();
    CComQIPtr<>(&local_c0,(undefined4 *)local_174.n1._8_4_);
    FUN_42403802((uint *)&local_158);
    local_8._0_1_ = 10;
    (**(code **)(*local_c0 + 0x30))();
    local_7c = (int *)0x0;
    if (local_158.n2.vt == 0) {
      GetViewportExtEx(local_64,&local_a0);
      GetWindowExtEx(local_64,&local_ac);
      SetMapMode(local_60,8);
      SetViewportExtEx(local_60,local_a0.cx,local_a0.cy,&local_10c);
      SetWindowExtEx(local_60,local_ac.cx,local_ac.cy,&local_ec);
    }
    else {
      CComQIPtr<>(&local_98,(undefined4 *)local_158._8_4_);
      local_a4 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,0xc);
      (**(code **)(*local_98 + 0x9c))();
      bVar3 = FUN_42403bfa(&local_a4,L"TrueType");
      hdc = local_64;
      if (bVar3) {
        GetViewportExtEx(local_64,&local_a0);
        GetWindowExtEx(hdc,&local_ac);
        SetMapMode(local_60,8);
        SetViewportExtEx(local_60,local_a0.cx,local_a0.cy,&local_10c);
        SetWindowExtEx(local_60,local_ac.cx,local_ac.cy,&local_ec);
      }
      piVar7 = local_98;
      local_c8 = local_98;
      if (local_98 != (int *)0x0) {
        (**(code **)(*local_98 + 4))();
      }
      local_8._0_1_ = 0xd;
      local_88 = (BSTR)FUN_4246d133(4);
      local_8._0_1_ = 0xe;
      if (local_88 == (BSTR)0x0) {
        local_7c = (int *)0x0;
      }
      else {
        piVar9 = piVar7;
        if (piVar7 != (int *)0x0) {
          (**(code **)(*piVar7 + 4))();
        }
        local_7c = FUN_42420b25(local_88,piVar9);
      }
      local_8._0_1_ = 0xc;
      if (piVar7 != (int *)0x0) {
        (**(code **)(*piVar7 + 8))();
      }
      SysFreeString(local_a4);
      local_8._0_1_ = 10;
      piVar7 = local_70;
      if (local_98 != (int *)0x0) {
        (**(code **)(*local_98 + 8))();
        piVar7 = local_70;
      }
    }
    local_74 = (LPCWSTR)0x0;
    local_8._0_1_ = 0xf;
    (**(code **)(*piVar1 + 0x98))();
    FUN_4240391a(&local_c8,local_74);
    local_8._0_1_ = 0x10;
    (**(code **)(*piVar1 + 0x10c))();
    local_70 = (int *)0;
    if (local_dc != 0) {
      local_70 = (int *)2;
    }
    (**(code **)(*piVar1 + 0xc0))();
    if (local_d8 != 0) {
      local_70 = (int *)1;
    }
    if ((local_dc != 0) && (local_d8 != 0)) {
      local_70 = (int *)3;
    }
    local_6c = 0;
    local_68 = 0;
    pOVar4 = FUN_42459daa();
    FUN_424037d2(&local_88,pOVar4);
    local_8._0_1_ = 0x11;
    (**(code **)(**(int **)((int)local_8c + 0xf4) + 0x30))();
    (**(code **)(**(int **)((int)local_8c + 0xf4) + 0x20))();
    (**(code **)(*piVar1 + 0xb0))();
    CComQIPtr<>(&local_d4,piVar1);
    local_8 = CONCAT31(local_8._1_3_,0x12);
    if (local_d4 != (int *)0x0) {
      local_80 = 1;
      (**(code **)(*local_d4 + 0x168))();
      local_68 = local_68 / local_80;
    }
    local_fc.cx = 0;
    local_fc.cy = 0;
    local_f4.cx = 0;
    local_f4.cy = 0;
    GetViewportExtEx(local_60,&local_fc);
    GetWindowExtEx(local_60,&local_f4);
    local_104.x = local_6c;
    local_104.y = local_68;
    LPtoDP(local_60,&local_104,1);
    local_90 = FUN_42421ed2(local_60,local_104.x,local_104.y,1);
    local_94 = SelectObject(local_60,local_90);
    (**(code **)(*piVar1 + 0x44))();
    local_24.left = 0;
    local_24.top = 0;
    local_24.right = local_6c;
    local_24.bottom = local_68;
    if (local_124 == 0) {
      local_bc = SetTextColor(local_60,in_stack_0000003c);
      local_b0 = SetBkColor(local_60,0xffffff);
      iVar10 = 0;
    }
    else {
      local_bc = SetTextColor(local_60,0xffffff);
      local_b0 = SetBkColor(local_60,in_stack_0000003c);
      iVar10 = 4;
    }
    pHVar5 = GetStockObject(iVar10);
    FillRect(local_60,&local_24,pHVar5);
    (**(code **)(**(int **)((int)local_8c + 0xf4) + 0x1c))();
    (**(code **)(*piVar1 + 0x2c))();
    (**(code **)(*piVar1 + 0x34))();
    local_b8 = local_11c;
    if (param_2 != 0) {
      local_b8 = 0;
      local_128 = 0;
    }
    local_b4 = local_128;
    (**(code **)(*piVar7 + 0x54))();
    if (local_118 == 0) {
      FUN_42458671(&local_80);
      local_8._0_1_ = 0x13;
      piVar9 = piVar2;
      (**(code **)(*piVar2 + 4))();
      FUN_42458960(&local_b8,piVar9);
      local_8 = CONCAT31(local_8._1_3_,0x12);
      FUN_42458752(&local_80);
    }
    SetTextColor(local_60,local_bc);
    SetBkColor(local_60,local_b0);
    (**(code **)(*piVar1 + 0x3c))();
    (**(code **)(*piVar1 + 0x4c))();
    local_e4.cx = 0;
    local_e4.cy = 0;
    local_114.cx = 0;
    local_114.cy = 0;
    local_130.cx = 0;
    local_130.cy = 0;
    SetViewportExtEx(local_60,1,1,&local_e4);
    SetWindowExtEx(local_60,1,1,&local_114);
    FUN_4245d25e(&local_5c);
    local_58 = 0;
    local_54 = 0;
    local_8 = CONCAT31(local_8._1_3_,0x14);
    FUN_4245d2bb(&local_5c,local_60,local_94);
    FUN_4245d35c((int)&local_5c);
    if (local_78 != 0) {
      FUN_4245db52(&local_5c,local_78);
    }
    local_90 = (HBITMAP)FUN_4245dbab((int)&local_5c);
    FUN_4245d591(&local_5c,(int *)&local_60,&local_90,(undefined4 *)0x0,(undefined4 *)0x0);
    SetMapMode(local_60,8);
    SetViewportExtEx(local_60,local_e4.cx,local_e4.cy,&local_130);
    SetWindowExtEx(local_60,local_114.cx,local_114.cy,&local_130);
    iVar10 = local_6c;
    if ((local_78 == 0x5a) || (local_78 == 0x10e)) {
      local_6c = local_68;
      local_68 = iVar10;
    }
    SetViewportExtEx(local_64,local_fc.cx,local_fc.cy,&local_10c);
    SetWindowExtEx(local_64,local_f4.cx,local_f4.cy,&local_ec);
    GetObjectW(local_90,0x18,local_148);
    if (local_7c != (int *)0x0) {
      iVar6 = FUN_42421180(local_7c);
      iVar10 = local_140;
      if (iVar6 == 1) {
        pOVar8 = (BSTR)0x1;
        FUN_42403768(&stack0xfffffda8,(int *)&local_74);
        iVar10 = FUN_4242575b(local_7c,pOVar8,local_d8);
        if ((local_78 != 0x5a) && (local_78 != 0x10e)) {
          local_144 = iVar10;
          iVar10 = local_140;
        }
      }
      local_140 = iVar10;
      FUN_42420d86(local_7c);
      FID_conflict__free(local_7c);
    }
    h = CreateCompatibleBitmap(local_64,local_144,local_140);
    SelectObject(local_64,h);
    pHVar5 = GetStockObject(0);
    local_34.left = 0;
    local_34.top = 0;
    local_34.right = local_144;
    local_34.bottom = local_140;
    FillRect(local_64,&local_34,pHVar5);
    if (local_120 == 0) {
      iVar10 = 0;
      iVar6 = local_6c;
    }
    else {
      iVar6 = -local_6c;
      iVar10 = local_6c;
    }
    StretchBlt(local_64,local_b8,local_b4,local_144,local_140,local_60,iVar10,0,iVar6,local_68,
               0xcc0020);
    SelectObject(local_60,local_94);
    DeleteObject(local_90);
    DeleteDC(local_60);
    local_8._0_1_ = 0x12;
    FUN_4245d291(&local_5c);
    local_8._0_1_ = 0x11;
    if (local_d4 != (int *)0x0) {
      (**(code **)(*local_d4 + 8))();
    }
    SysFreeString(local_88);
    FUN_42403ad1((int *)&local_c8);
    SysFreeString(local_74);
    VariantClear((VARIANTARG *)&local_158.n2);
    local_8._0_1_ = 8;
    if (local_c0 != (int *)0x0) {
      (**(code **)(*local_c0 + 8))();
    }
    VariantClear(&local_174);
    SysFreeString(local_84);
    local_8._0_1_ = 5;
    if (local_c4 != (int *)0x0) {
      (**(code **)(*local_c4 + 8))();
    }
    local_8._0_1_ = 4;
    (**(code **)(*piVar7 + 8))();
    local_8._0_1_ = 3;
    if (local_cc != (int *)0x0) {
      (**(code **)(*local_cc + 8))();
    }
    local_8._0_1_ = 2;
    (**(code **)(*piVar2 + 8))();
    local_8 = CONCAT31(local_8._1_3_,1);
    (**(code **)(*piVar1 + 8))(piVar1);
    local_8 = 0xffffffff;
    if (local_d0 != (int *)0x0) {
      (**(code **)(*local_d0 + 8))();
    }
  }
  FUN_4246ecf6();
  return;
}


