// Source: CLARiSOFT.exe @ 00e41139; FUN_00e41139

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00e41139(void *this,undefined4 param_1,undefined4 param_2,HWND param_3)

{
  void *this_00;
  int *piVar1;
  bool bVar2;
  HDC hdc;
  int iVar3;
  int iVar4;
  HWND pHVar5;
  int *piVar6;
  INT_PTR IVar7;
  int extraout_ECX;
  BSTR extraout_ECX_00;
  int extraout_ECX_01;
  int *piVar8;
  int *piVar9;
  BSTR pOVar10;
  LPARAM LVar11;
  int *local_1e4;
  BSTR local_1e0;
  int *local_1dc;
  BSTR local_1d8;
  HDC local_1d4;
  void *local_1d0;
  undefined **local_1cc [5];
  void *local_1b8;
  int local_19c;
  int local_198;
  undefined4 local_90 [8];
  uint local_70 [6];
  byte local_55;
  short local_54 [16];
  int local_34;
  int *local_30;
  BSTR local_2c;
  int local_28;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1e4;
  local_8 = 0xe41148;
  this_00 = *(void **)((int)this + 0x68);
  local_1d0 = this;
  if ((this_00 != (void *)0x0) && (*(int *)((int)this + 0xa4) != 0)) {
    CComQIPtr<>(&local_1e4,*(undefined4 **)(*(int *)(**(int **)((int)this + 0xa0) + 8) + 4));
    piVar1 = local_1e4;
    local_8 = 1;
    if (local_1e4 != (int *)0x0) {
      (**(code **)(*local_1e4 + 4))();
    }
    local_1e0 = (BSTR)0x0;
    local_8._0_1_ = 2;
    (**(code **)(*piVar1 + 0xa8))();
    (**(code **)(*piVar1 + 0xb0))();
    local_1d8 = (BSTR)0x1;
    CComQIPtr<>(&local_1dc,piVar1);
    local_8._0_1_ = 3;
    if (local_1dc != (int *)0x0) {
      (**(code **)(*local_1dc + 0x168))();
    }
    local_1d4 = (HDC)FUN_00e2f6bf((int)this_00);
    bVar2 = FUN_00e294aa((int)this_00);
    if (bVar2) {
      FUN_00ecc450(local_70,0,0x5c);
      FUN_00ecdc6b(local_54,0x20,local_1e0,0x1f);
      hdc = GetDC(*(HWND *)((int)this + 4));
      local_1d4 = hdc;
      GetDeviceCaps(hdc,0x5a);
      iVar3 = GetDeviceCaps(hdc,10);
      iVar4 = GetDeviceCaps(local_1d4,6);
      iVar3 = MulDiv(0 / (int)local_1d8,
                     (int)(((float)(iVar3 * 0xfe) / (float)iVar4) / _DAT_00f00bb4),0x48);
      local_70[0] = -iVar3;
      FUN_00e3d825(local_1cc,local_70,0x101,0,0);
      local_1cc[0] = WTL::CFontDialog::vftable;
      local_8._0_1_ = 4;
      pHVar5 = GetActiveWindow();
      iVar3 = FUN_00e3e1d0(local_1cc,pHVar5);
      if (iVar3 == 1) {
        FUN_00e03b21(&local_1d4,(OLECHAR *)(local_19c + 0x1c));
        local_8._0_1_ = 5;
        (**(code **)(*piVar1 + 0xac))();
        local_8._0_1_ = 4;
        SysFreeString((BSTR)local_1d4);
        (**(code **)(*piVar1 + 0xb4))(piVar1);
        (**(code **)(*local_1dc + 0x16c))(local_1dc,local_1d8);
        (**(code **)(*piVar1 + 0x100))(piVar1,local_55 & 0xf0);
        (**(code **)(*piVar1 + 0x128))(piVar1,1);
        piVar6 = (int *)(local_198 / 10);
        iVar3 = extraout_ECX;
        pOVar10 = local_1d8;
        FUN_00e03b21(&stack0xfffffde0,(OLECHAR *)(local_19c + 0x1c));
        FUN_00e35557(this_00,iVar3,piVar6,pOVar10);
        FUN_00e3ecf8(local_1d0,0,(undefined1 (*) [16])0x0,0);
        SendMessageW(param_3,0x404,0,0);
      }
      local_8._0_1_ = 3;
      if (local_1b8 != (void *)0x0) {
        ATL::__FreeStdCallThunk(local_1b8);
      }
    }
    else {
      FUN_00e64c1b(local_90);
      local_8 = CONCAT31(local_8._1_3_,6);
      iVar3 = local_1d4[1].unused;
      pOVar10 = extraout_ECX_00;
      FUN_00e03ab8(&stack0xfffffde4,&local_1d4->unused);
      piVar6 = *(int **)((int)this_00 + 0x160);
      if (piVar6 != (int *)0x0) {
        (**(code **)(*piVar6 + 4))(piVar6);
      }
      piVar9 = *(int **)((int)this_00 + 0x15c);
      if (piVar9 != (int *)0x0) {
        (**(code **)(*piVar9 + 4))(piVar9);
      }
      piVar8 = piVar1;
      (**(code **)(*piVar1 + 4))(piVar1);
      FUN_00e64e38(local_90,piVar8,piVar9,piVar6,pOVar10,iVar3);
      LVar11 = 0;
      pHVar5 = GetActiveWindow();
      IVar7 = FUN_00e3e17d(local_90,pHVar5,LVar11);
      if (IVar7 == 1) {
        if (local_28 != 0) {
          iVar3 = extraout_ECX_01;
          FUN_00e03ab8(&stack0xfffffde0,&local_34);
          FUN_00e35557(this_00,iVar3,local_30,local_2c);
        }
        FUN_00e3ecf8(this,0,(undefined1 (*) [16])0x0,0);
        SendMessageW(param_3,0x404,0,0);
      }
      local_8._0_1_ = 3;
      FUN_00e64c68(local_90);
    }
    local_8._0_1_ = 2;
    if (local_1dc != (int *)0x0) {
      (**(code **)(*local_1dc + 8))();
    }
    SysFreeString(local_1e0);
    local_8 = (uint)local_8._1_3_ << 8;
    (**(code **)(*piVar1 + 8))();
    local_8 = 0xffffffff;
    if (local_1e4 != (int *)0x0) {
      (**(code **)(*local_1e4 + 8))();
    }
  }
  FUN_00ec9e3c();
  return;
}


