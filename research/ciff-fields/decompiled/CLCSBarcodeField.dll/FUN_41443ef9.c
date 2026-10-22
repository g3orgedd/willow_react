// Source: CLCSBarcodeField.dll @ 41443ef9; FUN_41443ef9

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_41443ef9(void *this,undefined4 *param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  HFONT h;
  HGDIOBJ h_00;
  UINT c;
  int iVar2;
  int iVar3;
  BSTR pOVar4;
  BSTR extraout_ECX;
  undefined4 *puVar5;
  char cVar6;
  double dVar7;
  float local_cc;
  int local_c8;
  undefined4 local_c4;
  tagSIZE local_c0;
  undefined8 local_b8;
  int *local_b0;
  int local_ac;
  int local_a8;
  double local_a4;
  int local_9c;
  int local_98;
  float local_94;
  BSTR local_90;
  int *local_8c;
  int local_88;
  int local_84;
  undefined4 *local_80;
  int local_7c;
  HDC local_78;
  BSTR local_74;
  LOGFONTW local_70;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xbc;
  local_8 = 0x41443f08;
  local_b0 = param_2;
  local_80 = param_3;
  local_8c = this;
  FUN_4144c328(&local_c4);
  local_8 = 0;
  (**(code **)(*(int *)*local_80 + 0xb0))();
  (**(code **)(*(int *)*param_1 + 0x54))();
  puVar5 = local_80;
  local_88 = 0;
  (**(code **)(*(int *)*local_80 + 0xc0))();
  local_78 = GetDC((HWND)0x0);
  local_74 = (BSTR)0x0;
  local_8._0_1_ = 1;
  (**(code **)(*(int *)*puVar5 + 0x98))();
  local_c0.cx = 0;
  local_c0.cy = 0;
  if (local_88 == 1) {
    local_90 = (BSTR)0x0;
    local_8 = CONCAT31(local_8._1_3_,2);
    (**(code **)(*(int *)*puVar5 + 0xd0))();
    (**(code **)(*(int *)*puVar5 + 0xe0))();
    if (local_a8 < 0x3e9) {
      local_9c = (local_9c * local_a8) / 1000;
    }
    FUN_41460bf0((uint *)&local_70,0,0x5c);
    FUN_41462634(local_70.lfFaceName,0x20,local_90,0x1f);
    iVar2 = local_9c;
    local_70.lfCharSet = '\x01';
    (**(code **)(*(int *)*puVar5 + 0x3c))();
    if ((local_ac == 0) || (local_ac == 0xb4)) {
      (**(code **)(*(int *)*param_2 + 0x34))();
    }
    else {
      (**(code **)(*(int *)*param_2 + 0x2c))();
    }
    local_94 = local_94 * _DAT_4148100c * _DAT_414825e0;
    local_70.lfHeight = MulDiv(iVar2,(int)local_94,0x48);
    local_70.lfHeight = -local_70.lfHeight;
    piVar1 = (int *)FUN_41460343(4);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      *piVar1 = 0;
    }
    h = CreateFontIndirectW(&local_70);
    *piVar1 = (int)h;
    h_00 = SelectObject(local_78,h);
    c = SysStringLen(local_74);
    GetTextExtentPoint32W(local_78,local_74,c,&local_c0);
    SelectObject(local_78,h_00);
    DeleteObject((HGDIOBJ)*piVar1);
    FUN_41413a0c(piVar1);
    FID_conflict__free(piVar1);
    local_8._0_1_ = 1;
    SysFreeString(local_90);
    param_2 = local_b0;
    puVar5 = local_80;
    this = local_8c;
  }
  (**(code **)(*(int *)*puVar5 + 0x80))();
  if (local_84 == 0) {
    piVar1 = (int *)*param_2;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))();
    }
    local_7c = FUN_4144c3fb(local_7c,0.0,piVar1);
  }
  iVar2 = local_7c;
  if (local_84 == 0) {
    piVar1 = (int *)*param_2;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))();
    }
    iVar2 = FUN_4144c36e(iVar2,0.0,piVar1);
  }
  if (iVar2 < 1) {
    iVar2 = 1;
  }
  local_98 = iVar2;
  (**(code **)(*(int *)*local_80 + 0x78))();
  local_a4 = (double)local_c8;
  (**(code **)(*(int *)*param_2 + 0x2c))();
  local_b8 = (double)local_cc;
  dVar7 = local_a4;
  if (local_84 == 1) {
    dVar7 = local_a4 / local_b8;
  }
  dVar7 = (dVar7 * DAT_41481000) / *(double *)((int)this + 0x30);
  if (_DAT_41484290 < dVar7) {
    iVar3 = (**(code **)(*(int *)this + 0x28))();
    dVar7 = (double)iVar3;
  }
  iVar3 = FUN_41409304((local_b8 * _DAT_41482570 *
                       ((*(double *)((int)this + 0x28) * dVar7) / DAT_41481000)) / _DAT_41482570);
  if (iVar3 < 1) {
    iVar3 = 1;
  }
  pOVar4 = (BSTR)(*(int *)((int)this + 0x14) - 0x13);
  local_b8._4_4_ = iVar3;
  if (pOVar4 < (BSTR)0x2) {
    if (local_84 == 0) {
      piVar1 = (int *)*param_2;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))();
      }
      iVar2 = FUN_4144c3fb(iVar2,0.0,piVar1);
      pOVar4 = extraout_ECX;
    }
    if (local_8c[0x11] != 0) {
      cVar6 = local_88 == 1;
      FUN_41402eab(&stack0xfffffee0,(int *)&local_74);
      iVar3 = FUN_4144aa18((void *)local_8c[0x11],(int *)local_8c[5],local_b8._4_4_,iVar2,pOVar4,
                           cVar6);
      piVar1 = local_8c;
      pOVar4 = (BSTR)(local_7c - local_c0.cy);
      if ((int)pOVar4 < iVar3) {
        do {
          iVar2 = iVar2 + -1;
          cVar6 = local_88 == 1;
          FUN_41402eab(&stack0xfffffee0,(int *)&local_74);
          iVar3 = FUN_4144aa18((void *)piVar1[0x11],(int *)piVar1[5],local_b8._4_4_,iVar2,pOVar4,
                               cVar6);
          pOVar4 = (BSTR)(local_7c - local_c0.cy);
          param_2 = local_b0;
        } while ((int)pOVar4 < iVar3);
      }
    }
    if (local_84 == 0) {
      piVar1 = (int *)*param_2;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))();
      }
      FUN_4144c36e(iVar2,0.0,piVar1);
    }
  }
  (**(code **)(*(int *)*local_80 + 0xbc))();
  ReleaseDC((HWND)0x0,local_78);
  SysFreeString(local_74);
  local_8 = 0xffffffff;
  FUN_4144c348(&local_c4);
  FUN_41461ee2();
  return;
}


