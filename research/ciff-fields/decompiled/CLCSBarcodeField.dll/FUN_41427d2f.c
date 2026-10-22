// Source: CLCSBarcodeField.dll @ 41427d2f; FUN_41427d2f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_41427d2f(int *param_1,HDC param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  HDC hdc;
  HFONT h;
  HGDIOBJ h_00;
  UINT c;
  BSTR extraout_ECX;
  int iVar5;
  int *piVar6;
  BSTR pOVar7;
  _union_2683 local_f8;
  float local_e8;
  float local_e4;
  undefined1 local_e0 [16];
  undefined4 *local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  undefined4 local_b8;
  int local_b4;
  int local_b0;
  BSTR local_ac;
  int local_a8;
  BSTR local_a4;
  int local_a0;
  int *local_9c;
  int local_98;
  int local_94;
  int local_90;
  BSTR local_8c;
  int *local_88;
  int local_84;
  int local_80;
  HDC local_7c;
  int local_78;
  int local_74;
  LOGFONTW local_70;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xe8;
  local_8 = 0x41427d3e;
  local_7c = param_2;
  local_d0 = param_4;
  FUN_4144c328(&local_cc);
  local_b0 = param_1[3] - param_1[1];
  local_78 = 0;
  local_8 = 0;
  local_b4 = param_1[2] - *param_1;
  (**(code **)(*(int *)*param_4 + 0xb0))();
  local_94 = -1;
  FUN_41460bf0((uint *)&local_f8,0,0x10);
  VariantInit((VARIANTARG *)&local_f8.n2);
  local_8._0_1_ = 1;
  (**(code **)(*(int *)*param_3 + 0x480))();
  if (local_f8.n2.vt != 0) {
    CComQIPtr<>(&local_9c,(undefined4 *)local_f8._8_4_);
    FUN_41460bf0((uint *)local_e0,0,0x10);
    VariantInit((VARIANTARG *)local_e0);
    local_8._0_1_ = 3;
    (**(code **)(*local_9c + 0x30))();
    if (local_e0._0_2_ != 0) {
      CComQIPtr<>(&local_8c,(undefined4 *)local_e0._8_4_);
      local_8._0_1_ = 4;
      (**(code **)(*(int *)local_8c + 0x84))();
      local_8._0_1_ = 3;
      if (local_8c != (BSTR)0x0) {
        (**(code **)(*(int *)local_8c + 8))();
      }
    }
    VariantClear((VARIANTARG *)local_e0);
    local_8._0_1_ = 1;
    if (local_9c != (int *)0x0) {
      (**(code **)(*local_9c + 8))();
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  VariantClear((VARIANTARG *)&local_f8.n2);
  local_84 = 0;
  (**(code **)(*(int *)*param_4 + 0x78))();
  local_90 = 0;
  (**(code **)(*(int *)*param_4 + 0x80))();
  local_98 = 0;
  (**(code **)(*(int *)*param_4 + 0xb8))();
  local_c0 = 0;
  (**(code **)(*(int *)*param_4 + 0x108))();
  local_c4 = 0;
  (**(code **)(*(int *)*param_4 + 0x128))();
  local_c8 = 0;
  (**(code **)(*(int *)*param_4 + 0x120))();
  (**(code **)(*(int *)local_7c->unused + 0x54))();
  iVar1 = local_b0;
  if (local_a8 == 0) {
    piVar6 = (int *)*param_3;
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 4))();
    }
    local_90 = FUN_4144c3fb(local_90,0.0,piVar6);
    piVar6 = (int *)*param_3;
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 4))();
    }
    local_84 = FUN_4144c3fb(local_84,1.4013e-45,piVar6);
    piVar6 = (int *)*param_3;
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 4))();
    }
    iVar1 = FUN_4144c3fb(local_b0,0.0,piVar6);
    piVar6 = (int *)*param_3;
    local_b0 = iVar1;
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 4))();
    }
    local_b4 = FUN_4144c3fb(local_b4,1.4013e-45,piVar6);
    piVar6 = (int *)*param_3;
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 4))();
    }
    local_98 = FUN_4144c3fb(local_98,0.0,piVar6);
  }
  if (local_94 != -1) {
    piVar6 = (int *)*param_3;
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 4))();
    }
    local_94 = FUN_4144c3fb(local_94,1.4013e-45,piVar6);
  }
  local_ac = (BSTR)0x0;
  local_98 = local_98 + (iVar1 - local_90);
  local_8 = CONCAT31(local_8._1_3_,5);
  local_90 = iVar1;
  (**(code **)(*(int *)*param_4 + 0x98))();
  SysStringLen(local_ac);
  (**(code **)(*(int *)*param_4 + 0x78))();
  if (local_a8 == 0) {
    piVar6 = (int *)*param_3;
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 4))();
    }
    local_a0 = FUN_4144c3fb(local_a0,1.4013e-45,piVar6);
  }
  if ((local_94 != -1) && (local_94 < local_a0)) {
    puVar2 = FUN_4144d093(&local_8c,0x30d4);
    local_8._0_1_ = 6;
    puVar3 = FUN_4144d093(&local_88,0x7136);
    MessageBoxW((HWND)0x0,(LPCWSTR)*puVar3,(LPCWSTR)*puVar2,0x30);
    FUN_414031f1((int *)&local_88);
    local_8 = CONCAT31(local_8._1_3_,5);
    FUN_414031f1((int *)&local_8c);
    local_a0 = local_94;
  }
  FUN_4144d140(&local_b8);
  local_8 = CONCAT31(local_8._1_3_,7);
  pOVar7 = extraout_ECX;
  FUN_41402eab(&stack0xfffffe98,(int *)&local_ac);
  uVar4 = FUN_4144d19d(pOVar7);
  iVar1 = uVar4 * 0xb + 0x23;
  if (local_c0 != 0) {
    iVar1 = uVar4 * 0xb + 0x37;
  }
  if (local_c4 != 0) {
    iVar1 = iVar1 + 8;
  }
  if (local_c8 != 0) {
    iVar1 = iVar1 + 7;
  }
  local_88 = (int *)(int)((double)local_a0 / (double)iVar1);
  if ((int)((double)local_a0 / (double)iVar1) < 1) {
    local_88 = (int *)0x1;
  }
  (**(code **)(*(int *)*param_3 + 0x2c))();
  iVar5 = (int)local_88 * 1000;
  local_78 = (int)((double)iVar5 / ((double)local_e8 * _DAT_41482570));
  piVar6 = local_88;
  while (2000 < local_78) {
    if (1 < (int)piVar6) {
      piVar6 = (int *)((int)piVar6 + -1);
      iVar5 = iVar5 + -1000;
      local_78 = (int)((double)iVar5 / ((double)local_e8 * _DAT_41482570));
    }
  }
  local_84 = (iVar1 + -0x14) * (int)piVar6 + (int)piVar6 * 0x14;
  (**(code **)(*(int *)*param_4 + 0x80))((int *)*param_4,&local_80);
  if (local_a8 == 0) {
    piVar6 = (int *)*param_3;
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 4))(piVar6);
    }
    local_80 = FUN_4144c3fb(local_80,0.0,piVar6);
  }
  local_bc = 0;
  (**(code **)(*(int *)*param_4 + 0xc0))((int *)*param_4,&local_bc);
  iVar1 = local_80;
  if (local_bc == 1) {
    hdc = GetDC((HWND)0x0);
    local_8c = (BSTR)0x0;
    local_8._0_1_ = 8;
    local_7c = hdc;
    (**(code **)(*(int *)*param_4 + 0xd0))((int *)*param_4);
    (**(code **)(*(int *)*param_4 + 0xe0))((int *)*param_4,&local_9c);
    if (local_78 < 0x3e9) {
      local_9c = (int *)(((int)local_9c * local_78) / 1000);
    }
    FUN_41460bf0((uint *)&local_70,0,0x5c);
    FUN_41462634(local_70.lfFaceName,0x20,local_8c,0x1f);
    piVar6 = local_9c;
    local_70.lfCharSet = '\x01';
    GetDeviceCaps(hdc,0x5a);
    GetDeviceCaps(local_7c,10);
    GetDeviceCaps(local_7c,6);
    (**(code **)(*(int *)*param_3 + 0x34))((int *)*param_3,&local_e4);
    iVar1 = FUN_414092db(local_e4 * _DAT_4148100c);
    iVar5 = FUN_414092db((float)iVar1 * _DAT_414825e0);
    local_70.lfHeight = MulDiv((int)piVar6,iVar5,0x48);
    local_70.lfHeight = -local_70.lfHeight;
    local_74 = FUN_41409304(((double)iVar1 * (double)local_78 * DAT_414825d0) / DAT_41481000);
    local_88 = (int *)FUN_41460343(4);
    if (local_88 == (int *)0x0) {
      local_88 = (int *)0x0;
    }
    else {
      *local_88 = 0;
    }
    piVar6 = local_88;
    if (local_88 != (int *)0x0) {
      h = CreateFontIndirectW(&local_70);
      *piVar6 = (int)h;
      h_00 = SelectObject(local_7c,h);
      local_a4 = (BSTR)0x0;
      local_8._0_1_ = 9;
      (**(code **)(*(int *)*local_d0 + 0x98))((int *)*local_d0);
      local_e0._8_4_ = (undefined4 *)0x0;
      local_e0._12_4_ = 0;
      c = SysStringLen(local_a4);
      GetTextExtentPoint32W(local_7c,local_a4,c,(LPSIZE)(local_e0 + 8));
      local_74 = (local_80 - local_e0._12_4_) - local_74;
      SelectObject(local_7c,h_00);
      piVar6 = local_88;
      DeleteObject((HGDIOBJ)*local_88);
      FUN_41413a0c(piVar6);
      FID_conflict__free(piVar6);
      SysFreeString(local_a4);
      local_cc = local_74;
    }
    ReleaseDC((HWND)0x0,local_7c);
    local_8 = CONCAT31(local_8._1_3_,7);
    SysFreeString(local_8c);
    iVar1 = local_cc;
    param_4 = local_d0;
  }
  if (local_a8 == 0) {
    piVar6 = (int *)*param_3;
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 4))(piVar6);
    }
    local_90 = FUN_4144c36e(local_90,0.0,piVar6);
    piVar6 = (int *)*param_3;
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 4))(piVar6);
    }
    local_84 = FUN_4144c36e(local_84,1.4013e-45,piVar6);
    piVar6 = (int *)*param_3;
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 4))(piVar6);
    }
    FUN_4144c36e(local_b0,0.0,piVar6);
    piVar6 = (int *)*param_3;
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 4))(piVar6);
    }
    FUN_4144c36e(local_b4,1.4013e-45,piVar6);
    piVar6 = (int *)*param_3;
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 4))(piVar6);
    }
    local_98 = FUN_4144c36e(local_98,0.0,piVar6);
    piVar6 = (int *)*param_3;
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 4))(piVar6);
    }
    iVar1 = FUN_4144c36e(iVar1,0.0,piVar6);
    piVar6 = (int *)*param_3;
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 4))(piVar6);
    }
    local_80 = FUN_4144c36e(local_80,0.0,piVar6);
  }
  if (local_84 < 1) {
    local_84 = 1;
  }
  if (local_80 < 1) {
    local_80 = 1;
  }
  if (iVar1 < 1) {
    iVar1 = 1;
  }
  if (local_78 < 1) {
    local_78 = 1;
  }
  (**(code **)(*(int *)*param_4 + 0x7c))((int *)*param_4,local_84);
  (**(code **)(*(int *)*param_4 + 0x84))((int *)*param_4,local_80);
  (**(code **)(*(int *)*param_4 + 0xbc))((int *)*param_4,iVar1);
  (**(code **)(*(int *)*param_4 + 0xb4))((int *)*param_4,local_78);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_4144d149(&local_b8);
  SysFreeString(local_ac);
  local_8 = 0xffffffff;
  FUN_4144c348(&local_cc);
  FUN_41461ee2();
  return;
}


