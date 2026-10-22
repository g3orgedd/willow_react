// Source: CLCSSmallBarcode.dll @ 4206632b; FUN_4206632b

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_4206632b(int *param_1,int *param_2,int *param_3,HDC param_4)

{
  HDC hdc;
  int iVar1;
  UINT UVar2;
  HDC hdc_00;
  HGDIOBJ pvVar3;
  int iVar4;
  HBITMAP h;
  DWORD rop;
  int *piVar5;
  tagSIZE local_15b4;
  undefined4 local_15ac;
  int *local_15a8;
  tagSIZE local_15a4;
  tagSIZE local_1598;
  tagSIZE local_1590;
  int local_1588;
  int local_1584;
  int local_1580;
  int local_157c;
  uint local_1578;
  HBRUSH local_1574;
  BSTR local_1570;
  int local_156c;
  HGDIOBJ local_1568;
  HBITMAP local_1564;
  HDC local_1560;
  int local_155c;
  HBITMAP local_1558;
  HGDIOBJ local_1554;
  int local_1550;
  HDC local_154c;
  int local_1548;
  undefined **local_1544 [5];
  BSTR local_1530;
  undefined4 local_14f4 [1322];
  undefined4 local_4c [10];
  RECT local_24;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_42087f15;
  local_10 = ExceptionList;
  local_14 = DAT_420b8f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1560 = param_4;
  piVar5 = (int *)*param_3;
  if ((piVar5 == (int *)0x0) || (*param_1 == 0)) goto LAB_42066ac1;
  local_1570 = (BSTR)0x0;
  local_8 = 0;
  iVar1 = (**(code **)(*piVar5 + 0x98))(piVar5,&local_1570,local_14);
  if ((-1 < iVar1) && (UVar2 = SysStringLen(local_1570), UVar2 != 0)) {
    local_1550 = 0;
    (**(code **)(*(int *)*param_3 + 0x78))((int *)*param_3,&local_1550);
    local_1548 = 0;
    (**(code **)(*(int *)*param_3 + 0x80))((int *)*param_3,&local_1548);
    local_156c = 1;
    iVar1 = (**(code **)(*(int *)*param_1 + 0x54))((int *)*param_1,&local_156c);
    if ((-1 < iVar1) && (local_156c == 0)) {
      FUN_42002e41(&local_1564);
      local_8 = CONCAT31(local_8._1_3_,1);
      piVar5 = (int *)*param_2;
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 4))(piVar5);
      }
      local_1550 = FUN_42003ac3(local_1550,1.4013e-45,piVar5);
      piVar5 = (int *)*param_2;
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 4))(piVar5);
      }
      local_1548 = FUN_42003ac3(local_1548,0.0,piVar5);
      local_8 = local_8 & 0xffffff00;
      FUN_420030e8(&local_1564);
    }
    local_1558 = (HBITMAP)((local_1548 * 3) / 2);
    local_1554 = (HGDIOBJ)(local_1550 + 100);
    hdc_00 = CreateCompatibleDC((HDC)0x0);
    local_15a4.cx = 0;
    local_15a4.cy = 0;
    local_1598.cx = 0;
    local_1598.cy = 0;
    local_15b4.cx = 0;
    local_15b4.cy = 0;
    local_1590.cx = 0;
    local_1590.cy = 0;
    SetMapMode(hdc_00,1);
    hdc = local_1560;
    GetViewportExtEx(local_1560,&local_15b4);
    GetWindowExtEx(hdc,&local_1590);
    SetMapMode(hdc_00,8);
    SetViewportExtEx(hdc_00,100,100,&local_15a4);
    SetWindowExtEx(hdc_00,100,100,&local_1598);
    local_1564 = FUN_420276fc(hdc,(LONG)local_1554,(LONG)local_1558,1);
    local_1568 = SelectObject(hdc_00,local_1564);
    local_1574 = GetStockObject(0);
    local_24.left = 0;
    local_24.top = 0;
    local_24.right = (LONG)local_1554;
    local_24.bottom = (LONG)local_1558;
    FillRect(hdc_00,&local_24,local_1574);
    local_1580 = 0;
    (**(code **)(*(int *)*param_3 + 0xa8))((int *)*param_3,&local_1580);
    FUN_42066165(&local_15a8,local_1580);
    local_8._0_1_ = 2;
    FUN_42002e41(&local_15ac);
    local_8 = CONCAT31(local_8._1_3_,3);
    piVar5 = (int *)*param_2;
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 4))(piVar5);
    }
    iVar1 = FUN_42003ac3(100,1.4013e-45,piVar5);
    local_15a8[4] = iVar1;
    piVar5 = (int *)*param_2;
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 4))(piVar5);
    }
    iVar1 = FUN_42003ac3(100,1.4013e-45,piVar5);
    local_15a8[5] = iVar1;
    local_15a8[0x1d] = local_1548;
    local_1588 = 0;
    (**(code **)(*(int *)*param_3 + 0xb8))((int *)*param_3,&local_1588);
    piVar5 = (int *)*param_2;
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 4))(piVar5);
    }
    iVar1 = FUN_42003ac3(local_1588,0.0,piVar5);
    local_15a8[0x1e] = iVar1;
    iVar1 = (**(code **)(*local_15a8 + 8))(*param_3,local_156c);
    if (-1 < iVar1) {
      FUN_420660ed(local_1544);
      local_1544[0] = ITextImager::vftable;
      local_155c = 0;
      local_8 = CONCAT31(local_8._1_3_,4);
      iVar1 = (**(code **)(*local_15a8 + 0xc))(local_15a8,hdc_00,local_1544,&local_155c);
      if ((-1 < iVar1) && ((int)local_1558 < local_155c)) {
        local_1564 = FUN_420276fc(local_1560,(LONG)local_1554,local_155c,1);
        local_24.bottom = local_155c;
        local_15a8[0x1d] = local_155c;
        pvVar3 = SelectObject(hdc_00,local_1564);
        DeleteObject(pvVar3);
        FillRect(hdc_00,&local_24,local_1574);
      }
      (**(code **)(*local_15a8 + 4))(hdc_00,local_1544);
      local_8._0_1_ = 5;
      FUN_4200aef7(local_14f4);
      local_8 = CONCAT31(local_8._1_3_,3);
      SysFreeString(local_1530);
    }
    local_1554 = (HGDIOBJ)local_15a8[0x1c];
    local_1558 = (HBITMAP)local_15a8[0x1e];
    local_1550 = (int)local_1554;
    local_1548 = (int)local_1558;
    if (local_156c == 0) {
      FUN_42002e41(&local_1574);
      local_8 = CONCAT31(local_8._1_3_,6);
      piVar5 = (int *)*param_2;
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 4))(piVar5);
      }
      local_1554 = (HGDIOBJ)FUN_42003a36((int)local_1554,1.4013e-45,piVar5);
      piVar5 = (int *)*param_2;
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 4))(piVar5);
      }
      local_1558 = (HBITMAP)FUN_42003a36((int)local_1558,0.0,piVar5);
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_420030e8(&local_1574);
    }
    (**(code **)(*(int *)*param_3 + 0x7c))((int *)*param_3,local_1554);
    (**(code **)(*(int *)*param_3 + 0x84))((int *)*param_3,local_1558);
    local_157c = 0;
    (**(code **)(*(int *)*param_3 + 0x4c))((int *)*param_3,&local_157c);
    local_1584 = 0;
    (**(code **)(*(int *)*param_3 + 0x44))((int *)*param_3,&local_1584);
    local_154c = CreateCompatibleDC((HDC)0x0);
    SetMapMode(local_154c,1);
    GetViewportExtEx(local_1560,&local_15b4);
    GetWindowExtEx(local_1560,&local_1590);
    SetMapMode(local_154c,8);
    SetViewportExtEx(local_154c,100,100,&local_15a4);
    SetWindowExtEx(local_154c,100,100,&local_1598);
    local_1558 = CreateCompatibleBitmap(hdc_00,local_1550,local_1548);
    local_1554 = SelectObject(local_154c,local_1558);
    rop = 0xcc0020;
    if (local_1584 == 1) {
      rop = 0x330008;
    }
    if (local_157c == 1) {
      StretchBlt(local_154c,0,0,local_1550,local_1548,hdc_00,local_1550 + -1,0,-local_1550,
                 local_1548,rop);
    }
    else {
      BitBlt(local_154c,0,0,local_1550,local_1548,hdc_00,0,0,rop);
    }
    SelectObject(hdc_00,local_1568);
    DeleteObject(local_1564);
    DeleteDC(hdc_00);
    local_1578 = 0;
    iVar4 = (**(code **)(*(int *)*param_3 + 0x3c))((int *)*param_3,&local_1578);
    iVar1 = local_1550;
    if (-1 < iVar4) {
      if (local_1578 == 0x5a) {
LAB_4206699c:
        if (local_1578 != 0xb4) {
          local_1550 = local_1548;
          local_1548 = iVar1;
        }
      }
      else if (local_1578 != 0xb4) {
        if (local_1578 != 0x10e) goto LAB_42066a14;
        goto LAB_4206699c;
      }
      FUN_4200d2a6(local_4c);
      local_8._0_1_ = 7;
      FUN_4200d303(local_4c,local_154c,local_1554);
      FUN_4200da54(local_4c,local_1578);
      local_1558 = (HBITMAP)FUN_4200daad((int)local_4c);
      FUN_4200d4bd(local_4c,(int *)&local_154c,(undefined4 *)0x0,(undefined4 *)0x0,(undefined4 *)0x0
                  );
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_4200d2d9(local_4c);
    }
LAB_42066a14:
    h = CreateCompatibleBitmap(local_154c,local_1550,local_1548);
    pvVar3 = SelectObject(local_1560,h);
    DeleteObject(pvVar3);
    BitBlt(local_1560,0,0,local_1550,local_1548,local_154c,0,0,0xcc0020);
    SelectObject(local_154c,local_1554);
    DeleteObject(local_1558);
    DeleteDC(local_154c);
    local_8._0_1_ = 2;
    FUN_420030e8(&local_15ac);
    local_8 = (uint)local_8._1_3_ << 8;
    (**(code **)*local_15a8)(1);
  }
  SysFreeString(local_1570);
LAB_42066ac1:
  ExceptionList = local_10;
  FUN_4206a5c8(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


