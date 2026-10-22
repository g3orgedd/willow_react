// Source: CLCSSmallBarcode.dll @ 4202aeec; FUN_4202aeec

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4202aeec(void *this,HDC param_1)

{
  LONG LVar1;
  HDC pHVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  HDC pHVar6;
  HBRUSH hbr;
  int *piVar7;
  char cVar8;
  int *piVar9;
  int local_58 [3];
  int *local_4c;
  HDC local_48;
  int *local_44;
  tagSIZE local_40;
  int local_38;
  int local_34;
  void *local_30;
  HBITMAP local_2c;
  HDC local_28;
  RECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  local_8 = 0x4202aef8;
  local_48 = param_1;
  iVar3 = *(int *)((int)this + 0x68);
  if (iVar3 == 10) {
    local_30 = (void *)FUN_42067914(0x848);
    local_8 = 0;
    if (local_30 == (void *)0x0) goto LAB_4202b02a;
    iVar3 = *(int *)((int)this + 100);
    cVar8 = '\0';
LAB_4202aff4:
    pHVar2 = (HDC)FUN_42028cfb(local_30,*(int *)((int)this + 0x5c),*(int *)((int)this + 0x60),cVar8,
                               (uint)(iVar3 != 0));
  }
  else if (iVar3 == 0xb) {
    local_30 = (void *)FUN_42067914(0x848);
    local_8 = 1;
    if (local_30 != (void *)0x0) {
      iVar3 = *(int *)((int)this + 100);
      cVar8 = '\x01';
      goto LAB_4202aff4;
    }
LAB_4202b02a:
    pHVar2 = (HDC)0x0;
  }
  else if (iVar3 == 0xc) {
    local_30 = (void *)FUN_42067914(0x84c);
    local_8 = 2;
    if (local_30 == (void *)0x0) goto LAB_4202b02a;
    pHVar2 = (HDC)FUN_42027c0a(local_30,*(int *)((int)this + 0x5c),
                               (uint)(*(int *)((int)this + 100) != 0));
  }
  else if (iVar3 == 0xd) {
    local_30 = (void *)FUN_42067914(0x848);
    local_8 = 3;
    if (local_30 == (void *)0x0) goto LAB_4202b02a;
    pHVar2 = (HDC)FUN_420285a6(local_30,*(int *)((int)this + 0x5c),*(undefined4 *)((int)this + 0x60)
                               ,(uint)(*(int *)((int)this + 100) != 0));
  }
  else {
    if (iVar3 != 0xe) goto LAB_4202b493;
    local_30 = (void *)FUN_42067914(0x848);
    local_8 = 4;
    if (local_30 == (void *)0x0) goto LAB_4202b02a;
    pHVar2 = (HDC)FUN_4202914d(local_30,*(int *)((int)this + 0x5c),*(undefined4 *)((int)this + 0x60)
                               ,(uint)(*(int *)((int)this + 100) != 0));
  }
  local_8 = 0xffffffff;
  local_28 = pHVar2;
  if (pHVar2 == (HDC)0x0) goto LAB_4202b493;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_8 = 5;
  iVar3 = (**(code **)(pHVar2->unused + 4))((int)this + 0x70,local_58,(int)this + 0x74);
  if (-1 < iVar3) {
    uVar4 = (**(code **)(pHVar2->unused + 8))();
    *(undefined4 *)((int)this + 0x78) = uVar4;
    uVar4 = (**(code **)(pHVar2->unused + 0xc))();
    *(undefined4 *)((int)this + 0x60) = uVar4;
    FUN_4202a89b(this,&local_40,(int)pHVar2,local_48,*(BSTR *)((int)this + 0xb4));
    LVar1 = local_40.cx;
    if ((*(int *)((int)this + 0x7c) == 0x5a) || (*(int *)((int)this + 0x7c) == 0x10e)) {
      uVar4 = *(undefined4 *)((int)this + 0x78);
      *(undefined4 *)((int)this + 0x78) = *(undefined4 *)((int)this + 0x60);
      *(undefined4 *)((int)this + 0x60) = uVar4;
      local_40.cx = local_40.cy;
      local_40.cy = LVar1;
    }
    uVar5 = FUN_42029e72(*(int *)((int)this + 0xcc),*(int *)((int)this + 0xd0),
                         *(int *)((int)this + 0x78),*(int *)((int)this + 0x60),
                         *(int *)((int)this + 0xd4),*(int *)((int)this + 0xd8),
                         (uint *)((int)this + 0xdc),(void *)((int)this + 0x74));
    if (-1 < (int)uVar5) {
      local_38 = *(int *)((int)this + 0x60);
      local_34 = *(int *)((int)this + 0x78);
      if (*(int *)((int)this + 100) == 1) {
        if ((*(int *)((int)this + 0x7c) != 0x5a) && (*(int *)((int)this + 0x7c) != 0x10e)) {
          local_38 = local_38 + local_40.cy;
          if (local_34 < local_40.cx) {
            *(LONG *)((int)this + 0x78) = local_40.cx;
            *(int *)((int)this + 0xe8) = (local_40.cx - local_34) / 2;
          }
          else {
            *(undefined4 *)((int)this + 0xe8) = 0;
          }
          iVar3 = *(int *)((int)this + 0xe8);
          local_34 = *(int *)((int)this + 0x78);
          *(int *)((int)this + 0x84) = iVar3;
          *(int *)((int)this + 0xcc) = iVar3;
          FUN_42002e41(&local_30);
          piVar7 = *(int **)((int)this + 0xf8);
          local_8._0_1_ = 9;
          local_4c = piVar7;
          if (piVar7 != (int *)0x0) {
            (**(code **)(*piVar7 + 4))(piVar7);
          }
          local_8._0_1_ = 10;
          piVar9 = piVar7;
          if (piVar7 != (int *)0x0) {
            (**(code **)(*piVar7 + 4))(piVar7);
          }
          iVar3 = FUN_42003a36(iVar3,1.4013e-45,piVar9);
          CComQIPtr<>(&local_2c,*(undefined4 **)((int)this + 0xf0));
          local_8._0_1_ = 0xb;
          (**(code **)(local_2c->unused + 0x150))(local_2c,iVar3);
          local_8._0_1_ = 10;
          if (local_2c != (HBITMAP)0x0) {
            (**(code **)(local_2c->unused + 8))(local_2c);
          }
          local_8 = CONCAT31(local_8._1_3_,9);
          goto LAB_4202b33c;
        }
        local_34 = local_34 + local_40.cx;
        if (local_38 < local_40.cy) {
          *(LONG *)((int)this + 0x60) = local_40.cy;
          *(int *)((int)this + 0xec) = (local_40.cy - local_38) / 2;
        }
        else {
          *(undefined4 *)((int)this + 0xec) = 0;
        }
        *(undefined4 *)((int)this + 0x88) = *(undefined4 *)((int)this + 0xec);
        *(undefined4 *)((int)this + 0xd0) = *(undefined4 *)((int)this + 0xec);
        CComQIPtr<>(&local_28,*(undefined4 **)((int)this + 0xf0));
        local_30 = *(void **)((int)this + 0xec);
        local_8._0_1_ = 6;
        FUN_42002e41(&local_2c);
        piVar7 = *(int **)((int)this + 0xf8);
        local_8._0_1_ = 7;
        local_44 = piVar7;
        if (piVar7 != (int *)0x0) {
          (**(code **)(*piVar7 + 4))(piVar7);
        }
        local_8._0_1_ = 8;
        piVar9 = piVar7;
        if (piVar7 != (int *)0x0) {
          (**(code **)(*piVar7 + 4))(piVar7);
        }
        FUN_42003a36((int)local_30,1.4013e-45,piVar9);
        local_8._0_1_ = 7;
        if (piVar7 != (int *)0x0) {
          (**(code **)(*piVar7 + 8))(piVar7);
        }
        local_8._0_1_ = 6;
        FUN_420030e8(&local_2c);
        local_8 = CONCAT31(local_8._1_3_,5);
        if (local_28 != (HDC)0x0) {
          (**(code **)(local_28->unused + 8))(local_28);
        }
      }
      else {
        *(undefined4 *)((int)this + 0xe8) = 0;
        *(undefined4 *)((int)this + 0xec) = 0;
        FUN_42002e41(&local_30);
        piVar7 = *(int **)((int)this + 0xf8);
        local_8._0_1_ = 0xc;
        local_44 = piVar7;
        if (piVar7 != (int *)0x0) {
          (**(code **)(*piVar7 + 4))(piVar7);
        }
        local_8._0_1_ = 0xd;
        piVar9 = piVar7;
        if (piVar7 != (int *)0x0) {
          (**(code **)(*piVar7 + 4))(piVar7);
        }
        iVar3 = FUN_42003a36(*(int *)((int)this + 0xe8),1.4013e-45,piVar9);
        CComQIPtr<>(&local_2c,*(undefined4 **)((int)this + 0xf0));
        local_8._0_1_ = 0xe;
        (**(code **)(local_2c->unused + 0x150))(local_2c,iVar3);
        *(undefined4 *)((int)this + 0x84) = *(undefined4 *)((int)this + 0xe8);
        *(undefined4 *)((int)this + 0xcc) = *(undefined4 *)((int)this + 0xe8);
        local_8._0_1_ = 0xd;
        if (local_2c != (HBITMAP)0x0) {
          (**(code **)(local_2c->unused + 8))(local_2c);
        }
        local_8 = CONCAT31(local_8._1_3_,0xc);
LAB_4202b33c:
        if (piVar7 != (int *)0x0) {
          (**(code **)(*piVar7 + 8))(piVar7);
        }
        local_8 = CONCAT31(local_8._1_3_,5);
        FUN_420030e8(&local_30);
        pHVar2 = local_28;
      }
      pHVar6 = local_48;
      local_2c = FUN_420276fc(local_48,local_34,local_38,1);
      pHVar6 = CreateCompatibleDC(pHVar6);
      local_28 = pHVar6;
      SelectObject(pHVar6,local_2c);
      iVar3 = GetObjectW(local_2c,0x54,(LPVOID)((int)this + 4));
      if (iVar3 == 0) {
        FUN_420284e3(local_58);
        goto LAB_4202b493;
      }
      hbr = GetStockObject(0);
      local_24.left = 0;
      local_24.top = 0;
      local_24.right = local_34;
      local_24.bottom = local_38;
      FillRect(pHVar6,&local_24,hbr);
      iVar3 = *(int *)((int)this + 0x10) + 3;
      *(int *)((int)this + 0x58) = (int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2;
      iVar3 = FUN_4202b49b(this,&pHVar2->unused,pHVar6,local_58);
      *(undefined4 *)((int)this + 0x84) = 0;
      *(undefined4 *)((int)this + 0xcc) = 0;
      if ((-1 < iVar3) && (*(int *)((int)this + 100) != 0)) {
        FUN_4202b70c(this,(int)pHVar2,local_28);
      }
      FUN_4202a6a5(this,local_48,local_28,local_34,local_38,*(int *)((int)this + 0x78),
                   *(int *)((int)this + 0x60));
      SelectObject(local_28,(HGDIOBJ)0x0);
      DeleteObject(local_2c);
      DeleteDC(local_28);
      iVar3 = *(int *)((int)this + 0x7c);
      if (iVar3 == 0) {
LAB_4202b471:
        *(undefined4 *)((int)this + 0x60) = *(undefined4 *)((int)this + 0x80);
      }
      else {
        if (iVar3 != 0x5a) {
          if (iVar3 == 0xb4) goto LAB_4202b471;
          if (iVar3 != 0x10e) goto LAB_4202b47a;
        }
        *(undefined4 *)((int)this + 0x78) = *(undefined4 *)((int)this + 0x80);
      }
    }
  }
LAB_4202b47a:
  (**(code **)pHVar2->unused)(1);
  FUN_420284e3(local_58);
LAB_4202b493:
  FUN_4206a64e();
  return;
}


