// Source: CLCSBarcodeField.dll @ 4143e333; FUN_4143e333

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall
FUN_4143e333(void *this,undefined4 *param_1,int *param_2,undefined4 *param_3,HDC param_4)

{
  HDC hdc;
  HBITMAP pHVar1;
  int iVar2;
  int iVar3;
  LONG cx;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  tagSIZE local_1fc;
  tagSIZE local_1f4;
  tagSIZE local_1ec;
  tagSIZE local_1e4;
  HGDIOBJ local_1dc;
  undefined4 local_1d8;
  int *local_1d4;
  undefined4 *local_1d0;
  int local_1cc;
  DWORD local_1c8;
  int local_1c4;
  int local_1c0;
  uint local_1bc;
  int local_1b8;
  HGDIOBJ local_1b4;
  HDC local_1b0;
  int local_1ac;
  HDC local_1a8;
  HDC local_1a4;
  undefined4 local_1a0 [49];
  LONG local_dc;
  LONG local_d8;
  undefined4 local_3c [13];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1ec;
  local_8 = 0x4143e342;
  local_1d0 = param_1;
  local_1d4 = param_2;
  local_1a8 = param_4;
  FUN_4144c328(&local_1d8);
  local_8 = 0;
  FUN_4143de28(local_1a0);
  local_8._0_1_ = 1;
  FUN_414095de(local_1a0,*(undefined4 *)((int)this + 0x14));
  local_1bc = 0;
  (**(code **)(*(int *)*param_3 + 0x3c))((int *)*param_3,&local_1bc);
  hdc = CreateCompatibleDC((HDC)0x0);
  local_1fc.cx = 0;
  local_1fc.cy = 0;
  local_1f4.cx = 0;
  local_1f4.cy = 0;
  local_1e4.cx = 0;
  local_1e4.cy = 0;
  local_1ec.cx = 0;
  local_1ec.cy = 0;
  local_1b0 = hdc;
  SetMapMode(hdc,1);
  GetViewportExtEx(local_1a8,&local_1e4);
  GetWindowExtEx(local_1a8,&local_1ec);
  SetMapMode(hdc,8);
  SetViewportExtEx(hdc,100,100,&local_1fc);
  SetWindowExtEx(hdc,100,100,&local_1f4);
  FUN_414084b2(local_1a0,hdc,local_1d0,local_1d4,param_3);
  local_1b8 = local_dc;
  local_1c0 = local_d8;
  if ((local_1bc == 0x5a) || (cx = local_dc, local_1bc == 0x10e)) {
    cx = local_d8;
  }
  if ((local_1bc == 0x5a) || (local_1ac = local_d8, local_1bc == 0x10e)) {
    local_1ac = local_dc;
  }
  pHVar1 = FUN_414228c2(local_1b0,local_dc,local_d8,1);
  local_1a4 = CreateCompatibleDC(local_1b0);
  local_1dc = SelectObject(local_1a4,pHVar1);
  StretchBlt(local_1a4,0,0,local_1b8,local_1c0,local_1b0,0,0,local_1b8,local_1c0,0xcc0020);
  FUN_4144da0f(local_3c);
  local_8._0_1_ = 2;
  FUN_4144da6c(local_3c,local_1a4,0);
  FUN_4144e1bd(local_3c,local_1bc);
  local_1b4 = (HGDIOBJ)FUN_4144e216((int)local_3c);
  FUN_4144dc26(local_3c,(int *)&local_1a4,(undefined4 *)0x0,(undefined4 *)0x0,(undefined4 *)0x0);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_4144da42(local_3c);
  iVar2 = local_1ac;
  pHVar1 = CreateCompatibleBitmap(local_1a8,cx,local_1ac);
  SelectObject(local_1a8,pHVar1);
  local_1ac = 0;
  (**(code **)(*(int *)*param_3 + 0x44))((int *)*param_3,&local_1ac);
  local_1c8 = 0x330008;
  if (local_1ac == 0) {
    local_1c8 = 0xcc0020;
  }
  local_1cc = 0;
  (**(code **)(*(int *)*param_3 + 0x4c))((int *)*param_3,&local_1cc);
  if (local_1cc == 0) {
    BitBlt(local_1a8,0,0,cx,iVar2,local_1a4,0,0,local_1c8);
  }
  else {
    StretchBlt(local_1a8,0,0,cx,iVar2,local_1a4,cx + -1,0,-cx,iVar2,local_1c8);
  }
  SelectObject(local_1a4,local_1dc);
  DeleteObject(local_1b4);
  DeleteDC(local_1a4);
  DeleteDC(local_1b0);
  local_1c4 = 1;
  (**(code **)(*(int *)*local_1d0 + 0x54))((int *)*local_1d0,&local_1c4);
  piVar5 = local_1d4;
  if (local_1c4 == 0) {
    piVar4 = (int *)*param_3;
    piVar6 = (int *)*local_1d4;
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 4))(piVar6);
    }
    iVar2 = FUN_4144c36e(local_1b8,1.4013e-45,piVar6);
    (**(code **)(*piVar4 + 0x7c))(piVar4,iVar2);
    piVar4 = (int *)*param_3;
    piVar5 = (int *)*piVar5;
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 4))(piVar5);
    }
    iVar3 = FUN_4144c36e(local_1c0,0.0,piVar5);
    iVar2 = *piVar4;
  }
  else {
    if (local_1c4 != 1) goto LAB_4143e6ec;
    (**(code **)(*(int *)*param_3 + 0x7c))((int *)*param_3,local_1b8);
    piVar4 = (int *)*param_3;
    iVar2 = *piVar4;
    iVar3 = local_1c0;
  }
  (**(code **)(iVar2 + 0x84))(piVar4,iVar3);
LAB_4143e6ec:
  local_8 = local_8 & 0xffffff00;
  FUN_4143de94(local_1a0);
  local_8 = 0xffffffff;
  FUN_4144c348(&local_1d8);
  FUN_41461ee2();
  return;
}


