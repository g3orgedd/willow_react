// Source: CLCSBarcodeField.dll @ 4143e770; FUN_4143e770

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4143e770(int *param_1,undefined4 *param_2,int *param_3,undefined4 *param_4)

{
  BSTR nNumber;
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  HDC pHVar7;
  int nNumerator;
  HFONT h;
  HGDIOBJ h_00;
  UINT c;
  HDC pHVar8;
  double dVar9;
  double dVar10;
  int *piVar11;
  _union_2683 local_f4;
  undefined4 local_e4;
  _union_2683 local_e0;
  int local_d0;
  undefined4 *local_cc;
  BSTR local_c8;
  int local_c4;
  tagSIZE local_c0;
  int local_b8;
  int local_b4;
  int *local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  undefined4 *local_9c;
  int local_98;
  BSTR local_94;
  undefined4 *local_90;
  BSTR local_8c;
  undefined4 *local_88;
  int local_84;
  BSTR local_80;
  float local_7c;
  HDC local_78;
  char local_71;
  LOGFONTW local_70;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xec;
  local_8 = 0x4143e77f;
  local_88 = param_2;
  local_cc = param_4;
  FUN_4144c328(&local_e4);
  local_b4 = param_1[3] - param_1[1];
  local_84 = 0;
  local_8 = 0;
  local_c4 = param_1[2] - *param_1;
  (**(code **)(*(int *)*param_4 + 0xb0))((int *)*param_4,&local_84);
  local_a0 = -1;
  FUN_41460bf0((uint *)&local_e0,0,0x10);
  VariantInit((VARIANTARG *)&local_e0.n2);
  local_8._0_1_ = 1;
  (**(code **)(*(int *)*param_3 + 0x480))((int *)*param_3,&local_e0);
  if (local_e0.n2.vt != 0) {
    CComQIPtr<>(&local_80,(undefined4 *)local_e0._8_4_);
    FUN_41460bf0((uint *)&local_f4,0,0x10);
    VariantInit((VARIANTARG *)&local_f4.n2);
    local_8._0_1_ = 3;
    (**(code **)(*(int *)local_80 + 0x30))(local_80,local_b0[1],&local_f4);
    if (local_f4.n2.vt != 0) {
      CComQIPtr<>(&local_8c,(undefined4 *)local_f4._8_4_);
      local_8._0_1_ = 4;
      (**(code **)(*(int *)local_8c + 0x84))(local_8c,&local_a0);
      local_8._0_1_ = 3;
      if (local_8c != (BSTR)0x0) {
        (**(code **)(*(int *)local_8c + 8))(local_8c);
      }
    }
    VariantClear((VARIANTARG *)&local_f4.n2);
    local_8._0_1_ = 1;
    if (local_80 != (BSTR)0x0) {
      (**(code **)(*(int *)local_80 + 8))(local_80);
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  VariantClear((VARIANTARG *)&local_e0.n2);
  local_98 = 0;
  (**(code **)(*(int *)*param_4 + 0x78))((int *)*param_4,&local_98);
  local_a8 = 0;
  (**(code **)(*(int *)*param_4 + 0x80))((int *)*param_4,&local_a8);
  local_a4 = 0;
  (**(code **)(*(int *)*param_4 + 0xb8))((int *)*param_4,&local_a4);
  (**(code **)(*(int *)*local_88 + 0x54))((int *)*local_88,&local_b8);
  iVar2 = local_b4;
  if (local_b8 == 0) {
    piVar11 = (int *)*param_3;
    if (piVar11 != (int *)0x0) {
      (**(code **)(*piVar11 + 4))(piVar11);
    }
    local_a8 = FUN_4144c3fb(local_a8,0.0,piVar11);
    piVar11 = (int *)*param_3;
    if (piVar11 != (int *)0x0) {
      (**(code **)(*piVar11 + 4))(piVar11);
    }
    local_98 = FUN_4144c3fb(local_98,1.4013e-45,piVar11);
    piVar11 = (int *)*param_3;
    if (piVar11 != (int *)0x0) {
      (**(code **)(*piVar11 + 4))(piVar11);
    }
    iVar2 = FUN_4144c3fb(local_b4,0.0,piVar11);
    piVar11 = (int *)*param_3;
    local_b4 = iVar2;
    if (piVar11 != (int *)0x0) {
      (**(code **)(*piVar11 + 4))(piVar11);
    }
    local_c4 = FUN_4144c3fb(local_c4,1.4013e-45,piVar11);
    piVar11 = (int *)*param_3;
    if (piVar11 != (int *)0x0) {
      (**(code **)(*piVar11 + 4))(piVar11);
    }
    local_a4 = FUN_4144c3fb(local_a4,0.0,piVar11);
  }
  if (local_a0 != -1) {
    piVar11 = (int *)*param_3;
    if (piVar11 != (int *)0x0) {
      (**(code **)(*piVar11 + 4))(piVar11);
    }
    local_a0 = FUN_4144c3fb(local_a0,1.4013e-45,piVar11);
  }
  local_c8 = (BSTR)0x0;
  local_a4 = local_a4 + (iVar2 - local_a8);
  local_8 = CONCAT31(local_8._1_3_,5);
  local_a8 = iVar2;
  (**(code **)(*(int *)*param_4 + 0x98))((int *)*param_4,&local_c8);
  SysStringLen(local_c8);
  (**(code **)(*(int *)*param_4 + 0x78))((int *)*param_4,&local_ac);
  if (local_b8 == 0) {
    piVar11 = (int *)*param_3;
    if (piVar11 != (int *)0x0) {
      (**(code **)(*piVar11 + 4))(piVar11);
    }
    local_ac = FUN_4144c3fb(local_ac,1.4013e-45,piVar11);
  }
  if ((local_a0 != -1) && (local_a0 < local_ac)) {
    puVar3 = FUN_4144d093(&local_88,0x30d4);
    local_8._0_1_ = 6;
    puVar4 = FUN_4144d093(&local_7c,0x7136);
    MessageBoxW((HWND)0x0,(LPCWSTR)*puVar4,(LPCWSTR)*puVar3,0x30);
    FUN_414031f1((int *)&local_7c);
    local_8 = CONCAT31(local_8._1_3_,5);
    FUN_414031f1((int *)&local_88);
    local_ac = local_a0;
  }
  local_88 = (undefined4 *)0x0;
  (**(code **)(*(int *)*param_3 + 0x2c))((int *)*param_3,&local_88);
  local_f4.n2.n3 = (_union_2685)((double)(float)local_88 * _DAT_41482570);
  uVar5 = FUN_41409304(((double)local_84 * (double)local_f4.n2.n3) / DAT_41481000 + DAT_41480ff8);
  local_8c = (BSTR)0x0;
  local_8 = CONCAT31(local_8._1_3_,7);
  (**(code **)(*(int *)*param_4 + 0x98))((int *)*param_4,&local_8c);
  local_7c = (float)SysStringLen(local_8c);
  local_80 = (BSTR)0x0;
  (**(code **)(*(int *)*param_4 + 0x120))((int *)*param_4,&local_80);
  local_94 = (BSTR)0x0;
  (**(code **)(*(int *)*param_4 + 0x128))((int *)*param_4,&local_94);
  uVar6 = uVar5 & 0x80000001;
  if ((int)uVar6 < 0) {
    uVar6 = (uVar6 - 1 | 0xfffffffe) + 1;
  }
  dVar9 = DAT_414832c0;
  if (uVar6 == 1) {
    dVar9 = DAT_414825d8;
  }
  local_c0.cy = 0;
  local_e0.n2.n3 = (_union_2685)(double)(int)uVar5;
  dVar9 = ((dVar9 * _PTR_414840d0 + DAT_414825d8) * (double)(int)local_7c + dVar9 + _DAT_414840e0) *
          (double)local_e0.n2.n3;
  (**(code **)(*(int *)*param_4 + 0x108))((int *)*param_4,&local_c0.cy);
  local_78 = (HDC)0x0;
  if (local_c0.cy == 1) {
    local_78 = (HDC)FUN_414092db(635.0);
    piVar11 = (int *)*param_3;
    if (piVar11 != (int *)0x0) {
      (**(code **)(*piVar11 + 4))(piVar11);
    }
    local_78 = (HDC)FUN_4144c3fb((int)local_78,1.4013e-45,piVar11);
    pHVar8 = (HDC)(uVar5 * 10);
    pHVar7 = local_78;
    if ((int)pHVar8 - (int)local_78 != 0 && (int)local_78 <= (int)pHVar8) {
      pHVar7 = pHVar8;
    }
    dVar9 = (double)((int)pHVar7 * 2) + dVar9;
  }
  fVar1 = local_7c;
  if (local_94 == (BSTR)0x1) {
    dVar9 = dVar9 + (double)local_e0.n2.n3 * DAT_414840f0;
  }
  if (local_80 == (BSTR)0x1) {
    dVar9 = (double)local_e0.n2.n3 * DAT_414840e8 + dVar9;
  }
  if (((double)(local_ac + 10) < dVar9) || (dVar9 < (double)(local_ac + -10))) {
    uVar5 = 1;
    do {
      param_4 = local_cc;
      if ((int)uVar5 < 1) break;
      uVar6 = uVar5 & 0x80000001;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xfffffffe) + 1;
      }
      dVar9 = DAT_414832c0;
      if (uVar6 == 1) {
        dVar9 = DAT_414825d8;
      }
      dVar10 = (double)(int)uVar5;
      dVar9 = ((dVar9 * _PTR_414840d0 + DAT_414825d8) * (double)(int)fVar1 + dVar9 + _DAT_414840e0)
              * dVar10;
      if (local_c0.cy == 1) {
        pHVar8 = (HDC)(uVar5 * 10);
        pHVar7 = local_78;
        if ((int)pHVar8 - (int)local_78 != 0 && (int)local_78 <= (int)pHVar8) {
          pHVar7 = pHVar8;
        }
        dVar9 = dVar9 + (double)((int)pHVar7 * 2);
      }
      if (local_94 == (BSTR)0x1) {
        dVar9 = dVar9 + dVar10 * DAT_414840f0;
      }
      if (local_80 == (BSTR)0x1) {
        dVar9 = dVar9 + dVar10 * DAT_414840e8;
      }
      if (dVar9 < (double)local_ac) {
        uVar5 = uVar5 + 1;
        local_71 = '\0';
      }
      else {
        if ((_DAT_414840d8 < dVar9 - (double)local_ac) && (1 < (int)uVar5)) {
          uVar5 = uVar5 - 1;
        }
        uVar6 = uVar5 & 0x80000001;
        if ((int)uVar6 < 0) {
          uVar6 = (uVar6 - 1 | 0xfffffffe) + 1;
        }
        dVar9 = DAT_414832c0;
        if (uVar6 == 1) {
          dVar9 = DAT_414825d8;
        }
        dVar10 = (double)(int)uVar5;
        dVar9 = ((dVar9 * _PTR_414840d0 + DAT_414825d8) * (double)(int)fVar1 + dVar9 + _DAT_414840e0
                ) * dVar10;
        if (local_c0.cy == 1) {
          pHVar8 = (HDC)(uVar5 * 10);
          pHVar7 = local_78;
          if ((int)pHVar8 - (int)local_78 != 0 && (int)local_78 <= (int)pHVar8) {
            pHVar7 = pHVar8;
          }
          dVar9 = dVar9 + (double)((int)pHVar7 * 2);
        }
        if (local_94 == (BSTR)0x1) {
          dVar9 = dVar9 + dVar10 * DAT_414840f0;
        }
        if (local_80 == (BSTR)0x1) {
          dVar9 = dVar9 + dVar10 * DAT_414840e8;
        }
        local_98 = FUN_41409304(dVar9);
        local_71 = '\x01';
      }
      if ((int)uVar5 < 1) {
        uVar5 = 1;
      }
      local_84 = FUN_41409304(((double)(int)uVar5 / (double)local_f4.n2.n3) * DAT_41481000);
      if (0x5db < local_84) {
        uVar5 = uVar5 - 1;
        local_71 = '\x01';
      }
      if (local_71 == '\x01') {
        param_4 = local_cc;
        if (local_84 < 0x5dc) break;
        local_84 = (**(code **)(*local_b0 + 0x28))();
      }
      param_4 = local_cc;
    } while (local_71 == '\0');
  }
  else {
    local_98 = FUN_41409304(dVar9);
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  SysFreeString(local_8c);
  (**(code **)(*(int *)*param_4 + 0x80))((int *)*param_4,&local_9c);
  if (local_b8 == 0) {
    piVar11 = (int *)*param_3;
    if (piVar11 != (int *)0x0) {
      (**(code **)(*piVar11 + 4))(piVar11);
    }
    local_9c = (undefined4 *)FUN_4144c3fb((int)local_9c,0.0,piVar11);
  }
  local_d0 = 0;
  (**(code **)(*(int *)*param_4 + 0xc0))((int *)*param_4,&local_d0);
  puVar3 = local_9c;
  if (local_d0 == 1) {
    pHVar7 = GetDC((HWND)0x0);
    local_80 = (BSTR)0x0;
    local_8._0_1_ = 8;
    local_78 = pHVar7;
    (**(code **)(*(int *)*param_4 + 0xd0))((int *)*param_4);
    (**(code **)(*(int *)*param_4 + 0xe0))((int *)*param_4,&local_8c);
    if (local_84 < 0x3e9) {
      local_8c = (BSTR)(((int)local_8c * local_84) / 1000);
    }
    FUN_41460bf0((uint *)&local_70,0,0x5c);
    FUN_41462634(local_70.lfFaceName,0x20,local_80,0x1f);
    nNumber = local_8c;
    local_70.lfCharSet = '\x01';
    GetDeviceCaps(pHVar7,0x5a);
    GetDeviceCaps(local_78,10);
    GetDeviceCaps(local_78,6);
    local_7c = 0.0;
    (**(code **)(*(int *)*param_3 + 0x34))((int *)*param_3,&local_7c);
    iVar2 = FUN_414092db(local_7c * _DAT_4148100c);
    nNumerator = FUN_414092db((float)iVar2 * _DAT_414825e0);
    local_70.lfHeight = MulDiv((int)nNumber,nNumerator,0x48);
    local_70.lfHeight = -local_70.lfHeight;
    local_88 = (undefined4 *)
               FUN_41409304(((double)iVar2 * (double)local_84 * DAT_414825d0) / DAT_41481000);
    local_b0 = (int *)FUN_41460343(4);
    if (local_b0 == (int *)0x0) {
      local_b0 = (int *)0x0;
    }
    else {
      *local_b0 = 0;
    }
    piVar11 = local_b0;
    if (local_b0 != (int *)0x0) {
      h = CreateFontIndirectW(&local_70);
      *piVar11 = (int)h;
      h_00 = SelectObject(local_78,h);
      local_94 = (BSTR)0x0;
      local_8._0_1_ = 9;
      (**(code **)(*(int *)*local_cc + 0x98))((int *)*local_cc);
      local_c0.cx = 0;
      local_c0.cy = 0;
      c = SysStringLen(local_94);
      GetTextExtentPoint32W(local_78,local_94,c,&local_c0);
      local_88 = (undefined4 *)((int)local_9c + (-(int)local_88 - local_c0.cy));
      SelectObject(local_78,h_00);
      piVar11 = local_b0;
      DeleteObject((HGDIOBJ)*local_b0);
      FUN_41413a0c(piVar11);
      FID_conflict__free(piVar11);
      SysFreeString(local_94);
      local_90 = local_88;
    }
    ReleaseDC((HWND)0x0,local_78);
    local_8 = CONCAT31(local_8._1_3_,5);
    SysFreeString(local_80);
    puVar3 = local_90;
    param_4 = local_cc;
  }
  if (local_b8 == 0) {
    piVar11 = (int *)*param_3;
    if (piVar11 != (int *)0x0) {
      (**(code **)(*piVar11 + 4))(piVar11);
    }
    local_a8 = FUN_4144c36e(local_a8,0.0,piVar11);
    piVar11 = (int *)*param_3;
    if (piVar11 != (int *)0x0) {
      (**(code **)(*piVar11 + 4))(piVar11);
    }
    local_98 = FUN_4144c36e(local_98,1.4013e-45,piVar11);
    piVar11 = (int *)*param_3;
    if (piVar11 != (int *)0x0) {
      (**(code **)(*piVar11 + 4))(piVar11);
    }
    FUN_4144c36e(local_b4,0.0,piVar11);
    piVar11 = (int *)*param_3;
    if (piVar11 != (int *)0x0) {
      (**(code **)(*piVar11 + 4))(piVar11);
    }
    FUN_4144c36e(local_c4,1.4013e-45,piVar11);
    piVar11 = (int *)*param_3;
    if (piVar11 != (int *)0x0) {
      (**(code **)(*piVar11 + 4))(piVar11);
    }
    local_a4 = FUN_4144c36e(local_a4,0.0,piVar11);
    piVar11 = (int *)*param_3;
    if (piVar11 != (int *)0x0) {
      (**(code **)(*piVar11 + 4))(piVar11);
    }
    puVar3 = (undefined4 *)FUN_4144c36e((int)puVar3,0.0,piVar11);
    piVar11 = (int *)*param_3;
    if (piVar11 != (int *)0x0) {
      (**(code **)(*piVar11 + 4))(piVar11);
    }
    local_9c = (undefined4 *)FUN_4144c36e((int)local_9c,0.0,piVar11);
  }
  if (local_98 < 1) {
    local_98 = 1;
  }
  if ((int)local_9c < 1) {
    local_9c = (undefined4 *)0x1;
  }
  if ((int)puVar3 < 1) {
    puVar3 = (undefined4 *)0x1;
  }
  if (local_84 < 1) {
    local_84 = 1;
  }
  (**(code **)(*(int *)*param_4 + 0x7c))((int *)*param_4,local_98);
  (**(code **)(*(int *)*param_4 + 0x84))((int *)*param_4,local_9c);
  (**(code **)(*(int *)*param_4 + 0xbc))((int *)*param_4,puVar3);
  (**(code **)(*(int *)*param_4 + 0xb4))((int *)*param_4,local_84);
  SysFreeString(local_c8);
  local_8 = 0xffffffff;
  FUN_4144c348(&local_e4);
  FUN_41461ee2();
  return;
}


