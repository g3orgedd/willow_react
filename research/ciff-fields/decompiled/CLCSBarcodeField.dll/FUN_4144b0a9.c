// Source: CLCSBarcodeField.dll @ 4144b0a9; FUN_4144b0a9

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4144b0a9(void *this,HDC param_1)

{
  int *piVar1;
  LONG LVar2;
  int iVar3;
  OLECHAR *pOVar4;
  undefined4 uVar5;
  uint uVar6;
  HDC pHVar7;
  HBRUSH hbr;
  int **ppiVar8;
  HDC pHVar9;
  int *piVar10;
  int local_1b0 [3];
  HDC local_1a4;
  int *local_1a0;
  tagSIZE local_19c;
  int local_194;
  int *local_190;
  int *local_18c;
  int *local_188;
  HBITMAP local_184;
  HDC local_180;
  undefined4 local_17c [84];
  undefined4 local_2c;
  RECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1a0;
  local_8 = 0x4144b0b8;
  local_1a4 = param_1;
  local_180 = (HDC)0x0;
  if (*(int *)((int)this + 0x68) == 0x13) {
    local_190 = (int *)FUN_41460343(0xc70);
    local_8 = 0;
    if (local_190 != (int *)0x0) {
      iVar3 = *(int *)((int)this + 100);
      uVar5 = 0x16;
      goto LAB_4144b12a;
    }
LAB_4144b141:
    local_180 = (HDC)0x0;
LAB_4144b149:
    local_8 = 0xffffffff;
  }
  else if (*(int *)((int)this + 0x68) == 0x14) {
    local_190 = (int *)FUN_41460343(0xc70);
    local_8 = 1;
    if (local_190 == (int *)0x0) goto LAB_4144b141;
    iVar3 = *(int *)((int)this + 100);
    uVar5 = *(undefined4 *)((int)this + 0x9c);
LAB_4144b12a:
    local_180 = (HDC)FUN_41448049(local_190,*(undefined4 *)((int)this + 0x5c),
                                  *(int *)((int)this + 0x60),uVar5,(uint)(iVar3 != 0));
    goto LAB_4144b149;
  }
  pHVar9 = local_180;
  FUN_41423a67(local_17c);
  local_8 = 2;
  FUN_414095de(local_17c,*(undefined4 *)((int)this + 0x68));
  if (pHVar9 == (HDC)0x0) goto LAB_4144b746;
  local_1b0[0] = 0;
  local_1b0[1] = 0;
  local_1b0[2] = 0;
  local_8._0_1_ = 3;
  iVar3 = (**(code **)(pHVar9->unused + 4))((int)this + 0x70,local_1b0,(int)this + 0x74);
  if (-1 < iVar3) {
    piVar1 = *(int **)((int)this + 0xf4);
    local_190 = piVar1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
    local_188 = *(int **)((int)this + 0xf4);
    local_8._0_1_ = 4;
    if (local_188 != (int *)0x0) {
      (**(code **)(*local_188 + 4))(local_188);
    }
    local_24.right = 0;
    local_24.bottom = 7;
    local_2c = (OLECHAR *)((uint)local_2c._2_2_ << 0x10);
    local_8._0_1_ = 6;
    FUN_41408df8((undefined4 *)((int)this + 0xf8),&local_188,&local_2c);
    pOVar4 = (OLECHAR *)&local_2c;
    if ((int *)0x7 < (uint)local_24.bottom) {
      pOVar4 = local_2c;
    }
    FUN_41402f15(&local_184,pOVar4);
    local_8._0_1_ = 7;
    FUN_41403290(pHVar9 + 0x20f,(int *)&local_184);
    SysFreeString((BSTR)local_184);
    FUN_414062a0(&local_2c,'\x01',0);
    local_8._0_1_ = 4;
    if (local_188 != (int *)0x0) {
      (**(code **)(*local_188 + 8))(local_188);
    }
    local_8._0_1_ = 3;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    uVar5 = (**(code **)(pHVar9->unused + 8))();
    *(undefined4 *)((int)this + 0x78) = uVar5;
    uVar5 = (**(code **)(pHVar9->unused + 0xc))();
    *(undefined4 *)((int)this + 0x60) = uVar5;
    FUN_4144a9c2(this,&local_19c,(int)pHVar9,local_1a4,*(BSTR *)((int)this + 0xb8));
    LVar2 = local_19c.cx;
    if ((*(int *)((int)this + 0x7c) == 0x5a) || (*(int *)((int)this + 0x7c) == 0x10e)) {
      uVar5 = *(undefined4 *)((int)this + 0x78);
      *(undefined4 *)((int)this + 0x78) = *(undefined4 *)((int)this + 0x60);
      *(undefined4 *)((int)this + 0x60) = uVar5;
      local_19c.cx = local_19c.cy;
      local_19c.cy = LVar2;
    }
    uVar6 = FUN_41449e47(*(int *)((int)this + 0xd0),*(int *)((int)this + 0xd4),
                         *(int *)((int)this + 0x78),*(int *)((int)this + 0x60),
                         *(int *)((int)this + 0xd8),*(int *)((int)this + 0xdc),
                         (uint *)((int)this + 0xe0),(void *)((int)this + 0x74));
    if (-1 < (int)uVar6) {
      local_188 = *(int **)((int)this + 0x60);
      local_194 = *(int *)((int)this + 0x78);
      if (*(int *)((int)this + 100) == 1) {
        if ((*(int *)((int)this + 0x7c) != 0x5a) && (*(int *)((int)this + 0x7c) != 0x10e)) {
          local_188 = (int *)((int)local_188 + local_19c.cy);
          if (local_194 < local_19c.cx) {
            *(LONG *)((int)this + 0x78) = local_19c.cx;
            *(int *)((int)this + 0xec) = (local_19c.cx - local_194) / 2;
          }
          else {
            *(undefined4 *)((int)this + 0xec) = 0;
          }
          iVar3 = *(int *)((int)this + 0xec);
          local_194 = *(int *)((int)this + 0x78);
          *(int *)((int)this + 0x84) = iVar3;
          *(int *)((int)this + 0xd0) = iVar3;
          FUN_4144c328(&local_18c);
          piVar1 = *(int **)((int)this + 0xfc);
          local_8._0_1_ = 0xb;
          local_190 = piVar1;
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 4))(piVar1);
          }
          local_8._0_1_ = 0xc;
          piVar10 = piVar1;
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 4))(piVar1);
          }
          iVar3 = FUN_4144c36e(iVar3,1.4013e-45,piVar10);
          CComQIPtr<>(&local_184,*(undefined4 **)((int)this + 0xf4));
          local_8._0_1_ = 0xd;
          (**(code **)(local_184->unused + 0x150))(local_184,iVar3);
          local_8._0_1_ = 0xc;
          if (local_184 != (HBITMAP)0x0) {
            (**(code **)(local_184->unused + 8))(local_184);
          }
          local_8 = CONCAT31(local_8._1_3_,0xb);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
          }
          ppiVar8 = &local_18c;
          goto LAB_4144b5c0;
        }
        local_194 = local_194 + local_19c.cx;
        if ((int)local_188 < local_19c.cy) {
          *(LONG *)((int)this + 0x60) = local_19c.cy;
          *(int *)((int)this + 0xf0) = (local_19c.cy - (int)local_188) / 2;
        }
        else {
          *(undefined4 *)((int)this + 0xf0) = 0;
        }
        *(undefined4 *)((int)this + 0x88) = *(undefined4 *)((int)this + 0xf0);
        *(undefined4 *)((int)this + 0xd4) = *(undefined4 *)((int)this + 0xf0);
        CComQIPtr<>(&local_180,*(undefined4 **)((int)this + 0xf4));
        local_18c = *(int **)((int)this + 0xf0);
        local_8._0_1_ = 8;
        FUN_4144c328(&local_184);
        piVar1 = *(int **)((int)this + 0xfc);
        local_8._0_1_ = 9;
        local_1a0 = piVar1;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 4))(piVar1);
        }
        local_8._0_1_ = 10;
        piVar10 = piVar1;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 4))(piVar1);
        }
        FUN_4144c36e((int)local_18c,1.4013e-45,piVar10);
        local_8._0_1_ = 9;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
        }
        local_8._0_1_ = 8;
        FUN_4144c348(&local_184);
        local_8._0_1_ = 3;
        if (local_180 != (HDC)0x0) {
          (**(code **)(local_180->unused + 8))(local_180);
        }
      }
      else {
        *(undefined4 *)((int)this + 0xec) = 0;
        *(undefined4 *)((int)this + 0xf0) = 0;
        FUN_4144c328(&local_190);
        piVar1 = *(int **)((int)this + 0xfc);
        local_8._0_1_ = 0xe;
        local_1a0 = piVar1;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 4))(piVar1);
        }
        local_8._0_1_ = 0xf;
        piVar10 = piVar1;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 4))(piVar1);
        }
        iVar3 = FUN_4144c36e(*(int *)((int)this + 0xec),1.4013e-45,piVar10);
        CComQIPtr<>(&local_18c,*(undefined4 **)((int)this + 0xf4));
        local_8._0_1_ = 0x10;
        (**(code **)(*local_18c + 0x150))(local_18c,iVar3);
        *(undefined4 *)((int)this + 0x84) = *(undefined4 *)((int)this + 0xec);
        *(undefined4 *)((int)this + 0xd0) = *(undefined4 *)((int)this + 0xec);
        local_8._0_1_ = 0xf;
        if (local_18c != (int *)0x0) {
          (**(code **)(*local_18c + 8))(local_18c);
        }
        local_8 = CONCAT31(local_8._1_3_,0xe);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
        }
        ppiVar8 = &local_190;
LAB_4144b5c0:
        local_8._0_1_ = 3;
        FUN_4144c348(ppiVar8);
        pHVar9 = local_180;
      }
      pHVar7 = local_1a4;
      local_184 = FUN_414228c2(local_1a4,local_194,(LONG)local_188,1);
      pHVar7 = CreateCompatibleDC(pHVar7);
      local_180 = pHVar7;
      SelectObject(pHVar7,local_184);
      iVar3 = GetObjectW(local_184,0x54,(LPVOID)((int)this + 4));
      if (iVar3 == 0) {
        FUN_41449652(local_1b0);
        goto LAB_4144b746;
      }
      hbr = GetStockObject(0);
      local_24.left = 0;
      local_24.top = 0;
      local_24.right = local_194;
      local_24.bottom = (LONG)local_188;
      FillRect(pHVar7,&local_24,hbr);
      iVar3 = *(int *)((int)this + 0x10) + 3;
      *(int *)((int)this + 0x58) = (int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2;
      iVar3 = FUN_4144b75f(this,&pHVar9->unused,pHVar7,local_1b0);
      *(undefined4 *)((int)this + 0x84) = 0;
      *(undefined4 *)((int)this + 0xd0) = 0;
      if ((-1 < iVar3) && (*(int *)((int)this + 100) != 0)) {
        FUN_4144b9d0(this,(int)pHVar9,local_180);
      }
      FUN_4144a7cc(this,local_1a4,local_180,local_194,(int)local_188,*(int *)((int)this + 0x78),
                   *(int *)((int)this + 0x60));
      SelectObject(local_180,(HGDIOBJ)0x0);
      DeleteObject(local_184);
      DeleteDC(local_180);
      iVar3 = *(int *)((int)this + 0x7c);
      if (iVar3 == 0) {
LAB_4144b723:
        *(undefined4 *)((int)this + 0x60) = *(undefined4 *)((int)this + 0x80);
      }
      else {
        if (iVar3 != 0x5a) {
          if (iVar3 == 0xb4) goto LAB_4144b723;
          if (iVar3 != 0x10e) goto LAB_4144b72c;
        }
        *(undefined4 *)((int)this + 0x78) = *(undefined4 *)((int)this + 0x80);
      }
    }
  }
LAB_4144b72c:
  (**(code **)pHVar9->unused)(1);
  FUN_41449652(local_1b0);
LAB_4144b746:
  local_8 = 0xffffffff;
  FUN_41423b78(local_17c);
  FUN_41461ee2();
  return;
}


