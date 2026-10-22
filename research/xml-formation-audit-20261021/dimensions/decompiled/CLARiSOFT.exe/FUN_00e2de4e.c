// Source: CLARiSOFT.exe @ 00e2de4e; FUN_00e2de4e

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall
FUN_00e2de4e(void *this,undefined4 *param_1,int param_2,int param_3,int param_4,int param_5,
            char param_6)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  HRGN hrgnDst;
  HRGN hrgnSrc2;
  HBRUSH pHVar5;
  HPEN h;
  int y1;
  HDC hdc;
  code *pcVar6;
  undefined4 local_5c;
  HGDIOBJ local_58;
  HGDIOBJ local_54;
  tagPOINT local_50;
  int local_48;
  HPEN local_44;
  HBRUSH local_40;
  int local_3c;
  void *local_38;
  int local_34;
  HBRUSH local_30;
  int local_2c;
  undefined4 *local_28;
  HDC local_24;
  LOGBRUSH local_20 [2];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4c;
  local_8 = 0xe2de5a;
  local_28 = param_1;
  local_40 = this;
  InflateRect((LPRECT)&param_2,1,1);
  hdc = (HDC)*param_1;
  local_24 = hdc;
  piVar1 = (int *)FUN_00e77808((void *)((int)this + 4),0);
  if (*piVar1 == 0) {
    local_38 = (void *)0x0;
  }
  else {
    local_38 = (void *)(*piVar1 + -100);
  }
  local_44 = CreatePen(0,1,0);
  pcVar6 = SelectObject_exref;
  local_54 = SelectObject(hdc,local_44);
  local_30 = CreateSolidBrush(*(COLORREF *)((int)this + 0x16c));
  local_58 = SelectObject(hdc,local_30);
  if (param_6 != '\0') {
    param_2 = param_2 + 1;
    param_3 = param_3 + 1;
  }
  if (*(int *)((int)this + 0x160) != 0) {
    local_48 = 0;
    (**(code **)(**(int **)((int)this + 0x160) + 0x3ec))(*(int **)((int)this + 0x160),&local_48);
    if (local_48 != 0) {
      local_2c = 0;
      local_34 = 0;
      uVar2 = (**(code **)(**(int **)((int)this + 0x160) + 0x4c4))
                        (*(int **)((int)this + 0x160),&local_2c);
      uVar3 = (**(code **)(**(int **)((int)this + 0x160) + 0x4cc))
                        (*(int **)((int)this + 0x160),&local_34);
      pHVar5 = local_30;
      hdc = local_24;
      if (-1 < (int)(uVar2 | uVar3)) {
        FUN_00eae6d1(&local_5c);
        local_8 = 0;
        piVar1 = *(int **)((int)this + 0x160);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 4))(piVar1);
        }
        local_2c = FUN_00eae95c(local_2c,1.4013e-45,piVar1);
        piVar1 = *(int **)((int)this + 0x160);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 4))(piVar1);
        }
        iVar4 = FUN_00eae95c(local_34,0.0,piVar1);
        local_50.y = iVar4;
        if (param_5 - param_3 < param_4 - param_2) {
          local_50.y = local_2c;
          local_2c = iVar4;
        }
        local_50.x = local_2c;
        local_34 = local_50.y;
        FUN_00e3e5b0(local_38,&local_50,'\x01');
        local_3c = ((param_4 - local_50.x) - param_2) / 2;
        local_38 = (void *)(local_3c + local_50.x);
        y1 = ((param_5 - local_50.y) - param_3) / 2;
        iVar4 = y1 + local_50.y;
        hrgnDst = CreateEllipticRgn(param_2,param_3,param_4,param_5);
        hrgnSrc2 = CreateRectRgn(local_3c,y1,(int)local_38,iVar4);
        iVar4 = CombineRgn(hrgnDst,hrgnDst,hrgnSrc2,1);
        if (iVar4 != 0) {
          PaintRgn((HDC)*local_28,hrgnDst);
          pHVar5 = CreateSolidBrush(0);
          FrameRgn((HDC)*local_28,hrgnDst,pHVar5,1,1);
          DeleteObject(pHVar5);
        }
        local_20[0].lbHatch = 0;
        local_20[0].lbStyle = 1;
        local_20[0].lbColor = local_40[0x5b].unused;
        local_40 = CreateBrushIndirect(local_20);
        SelectObject(local_24,local_40);
        h = CreatePen(2,1,0);
        SelectObject(local_24,h);
        Ellipse((HDC)*local_28,param_2,param_3,param_4,param_5);
        SelectObject(local_24,local_44);
        DeleteObject(h);
        Rectangle((HDC)*local_28,param_2,param_3,param_4,param_5);
        pHVar5 = local_30;
        SelectObject(local_24,local_30);
        DeleteObject(local_40);
        if (hrgnSrc2 != (HRGN)0x0) {
          DeleteObject(hrgnSrc2);
        }
        DeleteObject(hrgnDst);
        local_8 = 0xffffffff;
        FUN_00eae7b2(&local_5c);
        hdc = local_24;
        pcVar6 = SelectObject_exref;
      }
      goto LAB_00e2e149;
    }
  }
  Rectangle((HDC)*local_28,param_2,param_3,param_4,param_5);
  pHVar5 = local_30;
LAB_00e2e149:
  (*pcVar6)(hdc,local_58);
  DeleteObject(pHVar5);
  (*pcVar6)(hdc,local_54);
  DeleteObject(local_44);
  FUN_00ec9e3c();
  return;
}


