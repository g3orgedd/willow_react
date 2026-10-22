// Source: CLCSBarcodeField.dll @ 41427219; FUN_41427219

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_41427219(int *param_1,undefined4 *param_2,int *param_3,undefined4 *param_4)

{
  uint uVar1;
  int iVar2;
  HDC hdc;
  int *piVar3;
  HFONT h;
  HGDIOBJ h_00;
  UINT c;
  BSTR extraout_ECX;
  int iVar4;
  BSTR pOVar5;
  tagSIZE local_c8;
  int local_c0;
  float local_bc;
  undefined4 *local_b8;
  undefined4 local_b4;
  int *local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  undefined4 local_98;
  int *local_94;
  float local_90;
  BSTR local_8c;
  int local_88;
  int local_84;
  HDC local_80;
  BSTR local_7c;
  BSTR local_78;
  int local_74;
  LOGFONTW local_70;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xb8;
  local_8 = 0x41427228;
  local_b0 = param_1;
  local_94 = param_3;
  local_b8 = param_4;
  FUN_4144c328(&local_b4);
  local_8 = 0;
  (**(code **)(*(int *)*param_2 + 0x54))();
  local_9c = 0;
  (**(code **)(*(int *)*param_4 + 0x108))();
  local_a0 = 0;
  (**(code **)(*(int *)*param_4 + 0x128))();
  local_a8 = 0;
  (**(code **)(*(int *)*param_4 + 0x120))();
  local_78 = (BSTR)0x0;
  local_8._0_1_ = 1;
  (**(code **)(*(int *)*param_4 + 0x98))();
  SysStringLen(local_78);
  FUN_4144d140(&local_98);
  local_8._0_1_ = 2;
  pOVar5 = extraout_ECX;
  FUN_41402eab(&stack0xfffffef8,(int *)&local_78);
  uVar1 = FUN_4144d19d(pOVar5);
  iVar4 = uVar1 * 0xb + 0x23;
  if (local_a0 != 0) {
    iVar4 = uVar1 * 0xb + 0x2b;
  }
  if (local_a8 != 0) {
    iVar4 = iVar4 + 7;
  }
  local_74 = 0;
  (**(code **)(*(int *)*param_4 + 0xb0))();
  (**(code **)(*(int *)*param_3 + 0x2c))((int *)*param_3,&local_bc);
  iVar2 = FUN_41409304(((double)local_74 * (double)local_bc * _DAT_41482570) / DAT_41481000);
  if (iVar2 < 2) {
    iVar2 = 1;
  }
  iVar4 = iVar2 * iVar4;
  if (local_9c != 0) {
    iVar4 = iVar4 + iVar2 * 0x14;
  }
  local_a4 = iVar4;
  (**(code **)(*(int *)*param_4 + 0x80))((int *)*param_4,&local_84);
  if (local_c0 == 0) {
    piVar3 = (int *)*local_94;
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 4))(piVar3);
    }
    local_84 = FUN_4144c3fb(local_84,0.0,piVar3);
  }
  (**(code **)(*(int *)*param_4 + 0xc0))((int *)*param_4,&local_ac);
  if (local_ac == 1) {
    hdc = GetDC((HWND)0x0);
    local_8c = (BSTR)0x0;
    local_8._0_1_ = 3;
    local_80 = hdc;
    (**(code **)(*(int *)*param_4 + 0xd0))((int *)*param_4,&local_8c);
    (**(code **)(*(int *)*param_4 + 0xe0))((int *)*param_4,&local_88);
    if (local_74 < 0x3e9) {
      local_88 = (local_88 * local_74) / 1000;
    }
    FUN_41460bf0((uint *)&local_70,0,0x5c);
    FUN_41462634(local_70.lfFaceName,0x20,local_8c,0x1f);
    iVar4 = local_88;
    local_70.lfCharSet = '\x01';
    GetDeviceCaps(hdc,0x5a);
    GetDeviceCaps(hdc,10);
    GetDeviceCaps(hdc,6);
    (**(code **)(*(int *)*local_94 + 0x34))((int *)*local_94,&local_90);
    iVar2 = FUN_414092db(local_90 * _DAT_4148100c);
    iVar2 = FUN_414092db((float)iVar2 * _DAT_414825e0);
    local_70.lfHeight = MulDiv(iVar4,iVar2,0x48);
    local_70.lfHeight = -local_70.lfHeight;
    piVar3 = (int *)FUN_41460343(4);
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      *piVar3 = 0;
    }
    if (piVar3 != (int *)0x0) {
      h = CreateFontIndirectW(&local_70);
      *piVar3 = (int)h;
      h_00 = SelectObject(local_80,h);
      local_7c = (BSTR)0x0;
      local_8._0_1_ = 4;
      (**(code **)(*(int *)*local_b8 + 0x98))((int *)*local_b8,&local_7c);
      local_c8.cx = 0;
      local_c8.cy = 0;
      c = SysStringLen(local_7c);
      GetTextExtentPoint32W(local_80,local_7c,c,&local_c8);
      SelectObject(local_80,h_00);
      DeleteObject((HGDIOBJ)*piVar3);
      FUN_41413a0c(piVar3);
      FID_conflict__free(piVar3);
      SysFreeString(local_7c);
    }
    ReleaseDC((HWND)0x0,local_80);
    SysFreeString(local_8c);
    iVar4 = local_a4;
  }
  if (iVar4 < 1) {
    iVar4 = 1;
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_84 < 1) {
    local_84 = 1;
  }
  if (local_74 < 1) {
    local_74 = 1;
  }
  local_b0[1] = local_84;
  *local_b0 = iVar4;
  FUN_4144d149(&local_98);
  SysFreeString(local_78);
  local_8 = 0xffffffff;
  FUN_4144c348(&local_b4);
  FUN_41461ee2();
  return;
}


