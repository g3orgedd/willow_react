// Source: CLCSBarcodeField.dll @ 41422c25; FUN_41422c25

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall
FUN_41422c25(void *this,undefined4 *param_1,int *param_2,undefined4 *param_3,HDC param_4)

{
  HDC hdc;
  HBITMAP pHVar1;
  int iVar2;
  int iVar3;
  LONG cx;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  tagSIZE local_1e8;
  tagSIZE local_1e0;
  tagSIZE local_1d8;
  tagSIZE local_1d0;
  HGDIOBJ local_1c8;
  undefined4 local_1c4;
  int *local_1c0;
  undefined4 *local_1bc;
  int local_1b8;
  DWORD local_1b4;
  int local_1b0;
  int local_1ac;
  uint local_1a8;
  int local_1a4;
  HGDIOBJ local_1a0;
  HDC local_19c;
  int local_198;
  HDC local_194;
  HDC local_190;
  undefined4 local_18c [49];
  LONG local_c8;
  LONG local_c4;
  undefined4 local_3c [13];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1d8;
  local_8 = 0x41422c34;
  local_1bc = param_1;
  local_1c0 = param_2;
  local_194 = param_4;
  FUN_4144c328(&local_1c4);
  local_8 = 0;
  FUN_41423a67(local_18c);
  local_8._0_1_ = 1;
  FUN_414095de(local_18c,*(undefined4 *)((int)this + 0x14));
  local_1a8 = 0;
  (**(code **)(*(int *)*param_3 + 0x3c))((int *)*param_3,&local_1a8);
  hdc = CreateCompatibleDC((HDC)0x0);
  local_1e8.cx = 0;
  local_1e8.cy = 0;
  local_1e0.cx = 0;
  local_1e0.cy = 0;
  local_1d0.cx = 0;
  local_1d0.cy = 0;
  local_1d8.cx = 0;
  local_1d8.cy = 0;
  local_19c = hdc;
  SetMapMode(hdc,1);
  GetViewportExtEx(local_194,&local_1d0);
  GetWindowExtEx(local_194,&local_1d8);
  SetMapMode(hdc,8);
  SetViewportExtEx(hdc,100,100,&local_1e8);
  SetWindowExtEx(hdc,100,100,&local_1e0);
  FUN_414084b2(local_18c,hdc,local_1bc,local_1c0,param_3);
  local_1a4 = local_c8;
  local_1ac = local_c4;
  if ((local_1a8 == 0x5a) || (cx = local_c8, local_1a8 == 0x10e)) {
    cx = local_c4;
  }
  if ((local_1a8 == 0x5a) || (local_198 = local_c4, local_1a8 == 0x10e)) {
    local_198 = local_c8;
  }
  pHVar1 = FUN_414228c2(local_19c,local_c8,local_c4,1);
  local_190 = CreateCompatibleDC(local_19c);
  local_1c8 = SelectObject(local_190,pHVar1);
  StretchBlt(local_190,0,0,local_1a4,local_1ac,local_19c,0,0,local_1a4,local_1ac,0xcc0020);
  FUN_4144da0f(local_3c);
  local_8._0_1_ = 2;
  FUN_4144da6c(local_3c,local_190,0);
  FUN_4144e1bd(local_3c,local_1a8);
  local_1a0 = (HGDIOBJ)FUN_4144e216((int)local_3c);
  FUN_4144dc26(local_3c,(int *)&local_190,(undefined4 *)0x0,(undefined4 *)0x0,(undefined4 *)0x0);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_4144da42(local_3c);
  iVar2 = local_198;
  pHVar1 = CreateCompatibleBitmap(local_194,cx,local_198);
  SelectObject(local_194,pHVar1);
  local_198 = 0;
  (**(code **)(*(int *)*param_3 + 0x44))((int *)*param_3,&local_198);
  local_1b4 = 0x330008;
  if (local_198 == 0) {
    local_1b4 = 0xcc0020;
  }
  local_1b8 = 0;
  (**(code **)(*(int *)*param_3 + 0x4c))((int *)*param_3,&local_1b8);
  if (local_1b8 == 0) {
    BitBlt(local_194,0,0,cx,iVar2,local_190,0,0,local_1b4);
  }
  else {
    StretchBlt(local_194,0,0,cx,iVar2,local_190,cx + -1,0,-cx,iVar2,local_1b4);
  }
  SelectObject(local_190,local_1c8);
  DeleteObject(local_1a0);
  DeleteDC(local_190);
  DeleteDC(local_19c);
  local_1b0 = 1;
  (**(code **)(*(int *)*local_1bc + 0x54))((int *)*local_1bc,&local_1b0);
  piVar5 = local_1c0;
  if (local_1b0 == 0) {
    piVar4 = (int *)*param_3;
    piVar6 = (int *)*local_1c0;
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 4))(piVar6);
    }
    iVar2 = FUN_4144c36e(local_1a4,1.4013e-45,piVar6);
    (**(code **)(*piVar4 + 0x7c))(piVar4,iVar2);
    piVar4 = (int *)*param_3;
    piVar5 = (int *)*piVar5;
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 4))(piVar5);
    }
    iVar3 = FUN_4144c36e(local_1ac,0.0,piVar5);
    iVar2 = *piVar4;
  }
  else {
    if (local_1b0 != 1) goto LAB_41422fde;
    (**(code **)(*(int *)*param_3 + 0x7c))((int *)*param_3,local_1a4);
    piVar4 = (int *)*param_3;
    iVar2 = *piVar4;
    iVar3 = local_1ac;
  }
  (**(code **)(iVar2 + 0x84))(piVar4,iVar3);
LAB_41422fde:
  local_8 = local_8 & 0xffffff00;
  FUN_41423b78(local_18c);
  local_8 = 0xffffffff;
  FUN_4144c348(&local_1c4);
  FUN_41461ee2();
  return;
}


