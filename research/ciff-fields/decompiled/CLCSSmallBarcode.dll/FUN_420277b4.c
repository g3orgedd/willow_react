// Source: CLCSSmallBarcode.dll @ 420277b4; FUN_420277b4

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall
FUN_420277b4(void *this,HDC param_1,HDC param_2,int param_3,int param_4,int param_5,int param_6)

{
  HDC pHVar1;
  HBITMAP h;
  int iVar2;
  int cx;
  int cy;
  HDC pHVar3;
  undefined4 local_58;
  int local_54;
  int local_50 [2];
  uint local_48;
  HDC local_44;
  HDC local_40;
  undefined4 local_3c [13];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  local_8 = 0x420277c0;
  local_40 = param_1;
  local_44 = param_2;
  (**(code **)(**(int **)((int)this + 4) + 0x3c))(*(int **)((int)this + 4),&local_48);
  FUN_4200d2a6(local_3c);
  local_8 = 0;
  FUN_4200d303(local_3c,local_44,0);
  FUN_4200da54(local_3c,local_48);
  FUN_4200daad((int)local_3c);
  FUN_4200d4bd(local_3c,(int *)&local_44,(undefined4 *)0x0,(undefined4 *)0x0,(undefined4 *)0x0);
  iVar2 = param_3;
  cy = param_4;
  if ((-1 < param_5) && (-1 < param_6)) {
    iVar2 = param_5;
    cy = param_6;
  }
  if ((local_48 == 0x5a) || (cx = iVar2, local_48 == 0x10e)) {
    cx = cy;
    cy = iVar2;
  }
  h = CreateCompatibleBitmap(local_40,cx,cy);
  SelectObject(local_40,h);
  local_50[0] = 0;
  (**(code **)(**(int **)((int)this + 4) + 0x4c))(*(int **)((int)this + 4),local_50);
  if (local_50[0] == 0) {
    BitBlt(local_40,0,0,cx,cy,local_44,0,0,0xcc0020);
  }
  else {
    StretchBlt(local_40,0,0,cx,cy,local_44,cx + -1,0,-cx,cy,0xcc0020);
  }
  local_54 = 1;
  (**(code **)(**(int **)((int)this + 8) + 0x54))(*(int **)((int)this + 8),&local_54);
  if (local_54 == 0) {
    FUN_42002e41(&local_58);
    pHVar1 = *(HDC *)((int)this + 0xc);
    local_8._0_1_ = 1;
    local_40 = pHVar1;
    if (pHVar1 != (HDC)0x0) {
      (**(code **)(pHVar1->unused + 4))(pHVar1);
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    if ((-1 < param_5) && (-1 < param_6)) {
      pHVar3 = pHVar1;
      if (pHVar1 != (HDC)0x0) {
        (**(code **)(pHVar1->unused + 4))(pHVar1);
      }
      FUN_42003a36(param_5,1.4013e-45,&pHVar3->unused);
      pHVar3 = pHVar1;
      if (pHVar1 != (HDC)0x0) {
        (**(code **)(pHVar1->unused + 4))(pHVar1);
      }
      FUN_42003a36(param_6,0.0,&pHVar3->unused);
    }
    pHVar3 = pHVar1;
    if (pHVar1 != (HDC)0x0) {
      (**(code **)(pHVar1->unused + 4))(pHVar1);
    }
    param_3 = FUN_42003a36(param_3,1.4013e-45,&pHVar3->unused);
    pHVar3 = pHVar1;
    if (pHVar1 != (HDC)0x0) {
      (**(code **)(pHVar1->unused + 4))(pHVar1);
    }
    param_4 = FUN_42003a36(param_4,0.0,&pHVar3->unused);
    local_8._0_1_ = 1;
    if (pHVar1 != (HDC)0x0) {
      (**(code **)(pHVar1->unused + 8))(pHVar1);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_420030e8(&local_58);
  }
  (**(code **)(**(int **)((int)this + 4) + 0x84))(*(int **)((int)this + 4),param_4);
  (**(code **)(**(int **)((int)this + 4) + 0x7c))(*(int **)((int)this + 4),param_3);
  local_8 = 0xffffffff;
  FUN_4200d2d9(local_3c);
  FUN_4206a64e();
  return;
}


