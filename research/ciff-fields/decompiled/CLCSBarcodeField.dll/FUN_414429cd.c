// Source: CLCSBarcodeField.dll @ 414429cd; FUN_414429cd

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall
FUN_414429cd(void *this,undefined4 *param_1,int *param_2,undefined4 *param_3,HDC param_4)

{
  uint uVar1;
  HDC hdc;
  HBITMAP pHVar2;
  int iVar3;
  int iVar4;
  LONG cx;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  tagSIZE local_1c34;
  tagSIZE local_1c2c;
  tagSIZE local_1c24;
  tagSIZE local_1c1c;
  HGDIOBJ local_1c14;
  undefined4 local_1c10;
  int local_1c0c;
  undefined4 *local_1c08;
  int *local_1c04;
  int local_1c00;
  uint local_1bfc;
  int local_1bf8;
  HGDIOBJ local_1bf4;
  HDC local_1bf0;
  int local_1bec;
  HDC local_1be8;
  HDC local_1be4;
  undefined4 local_1be0 [49];
  LONG local_1b1c;
  LONG local_1b18;
  undefined4 local_3c [10];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_4147d923;
  local_10 = ExceptionList;
  uVar1 = DAT_414aacf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c08 = param_1;
  local_1c04 = param_2;
  local_1be8 = param_4;
  local_14 = uVar1;
  FUN_4144c328(&local_1c10);
  local_8 = 0;
  FUN_4145cd5a(local_1be0);
  local_8._0_1_ = 1;
  FUN_414095de(local_1be0,*(undefined4 *)((int)this + 0x14));
  local_1bfc = 0;
  (**(code **)(*(int *)*param_3 + 0x3c))((int *)*param_3,&local_1bfc,uVar1);
  hdc = CreateCompatibleDC((HDC)0x0);
  local_1c34.cx = 0;
  local_1c34.cy = 0;
  local_1c2c.cx = 0;
  local_1c2c.cy = 0;
  local_1c24.cx = 0;
  local_1c24.cy = 0;
  local_1c1c.cx = 0;
  local_1c1c.cy = 0;
  local_1bf0 = hdc;
  SetMapMode(hdc,1);
  GetViewportExtEx(local_1be8,&local_1c24);
  GetWindowExtEx(local_1be8,&local_1c1c);
  SetMapMode(hdc,8);
  SetViewportExtEx(hdc,100,100,&local_1c34);
  SetWindowExtEx(hdc,100,100,&local_1c2c);
  FUN_414084b2(local_1be0,hdc,local_1c08,local_1c04,param_3);
  local_1bf8 = local_1b1c;
  local_1c00 = local_1b18;
  if ((local_1bfc == 0x5a) || (cx = local_1b1c, local_1bfc == 0x10e)) {
    cx = local_1b18;
  }
  if ((local_1bfc == 0x5a) || (local_1bec = local_1b18, local_1bfc == 0x10e)) {
    local_1bec = local_1b1c;
  }
  pHVar2 = FUN_414228c2(local_1bf0,local_1b1c,local_1b18,1);
  local_1be4 = CreateCompatibleDC(local_1bf0);
  local_1c14 = SelectObject(local_1be4,pHVar2);
  StretchBlt(local_1be4,0,0,local_1bf8,local_1c00,local_1bf0,0,0,local_1bf8,local_1c00,0xcc0020);
  FUN_4144da0f(local_3c);
  local_8._0_1_ = 2;
  FUN_4144da6c(local_3c,local_1be4,0);
  FUN_4144e1bd(local_3c,local_1bfc);
  local_1bf4 = (HGDIOBJ)FUN_4144e216((int)local_3c);
  FUN_4144dc26(local_3c,(int *)&local_1be4,(undefined4 *)0x0,(undefined4 *)0x0,(undefined4 *)0x0);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_4144da42(local_3c);
  iVar3 = local_1bec;
  pHVar2 = CreateCompatibleBitmap(local_1be8,cx,local_1bec);
  SelectObject(local_1be8,pHVar2);
  (**(code **)(*(int *)*param_3 + 0x4c))((int *)*param_3,&local_1bec);
  if (local_1bec == 0) {
    BitBlt(local_1be8,0,0,cx,iVar3,local_1be4,0,0,0xcc0020);
  }
  else {
    StretchBlt(local_1be8,0,0,cx,iVar3,local_1be4,cx + -1,0,-cx,iVar3,0xcc0020);
  }
  SelectObject(local_1be4,local_1c14);
  DeleteObject(local_1bf4);
  DeleteDC(local_1be4);
  DeleteDC(local_1bf0);
  local_1c0c = 1;
  (**(code **)(*(int *)*local_1c08 + 0x54))((int *)*local_1c08,&local_1c0c);
  piVar6 = local_1c04;
  if (local_1c0c == 0) {
    piVar5 = (int *)*param_3;
    piVar7 = (int *)*local_1c04;
    if (piVar7 != (int *)0x0) {
      (**(code **)(*piVar7 + 4))(piVar7);
    }
    iVar3 = FUN_4144c36e(local_1bf8,1.4013e-45,piVar7);
    (**(code **)(*piVar5 + 0x7c))(piVar5,iVar3);
    piVar5 = (int *)*param_3;
    piVar6 = (int *)*piVar6;
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 4))(piVar6);
    }
    iVar4 = FUN_4144c36e(local_1c00,0.0,piVar6);
    iVar3 = *piVar5;
  }
  else {
    if (local_1c0c != 1) goto LAB_41442d71;
    (**(code **)(*(int *)*param_3 + 0x7c))((int *)*param_3,local_1bf8);
    piVar5 = (int *)*param_3;
    iVar3 = *piVar5;
    iVar4 = local_1c00;
  }
  (**(code **)(iVar3 + 0x84))(piVar5,iVar4);
LAB_41442d71:
  local_8 = local_8 & 0xffffff00;
  FUN_4145cdaa(local_1be0);
  local_8 = 0xffffffff;
  FUN_4144c348(&local_1c10);
  ExceptionList = local_10;
  FUN_41461e5c(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


