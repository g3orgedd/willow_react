// Source: CLARiSOFT.exe @ 00e62f49; FUN_00e62f49

void FUN_00e62f49(undefined4 *param_1,int *param_2,int param_3,int param_4,HDC param_5,
                 COLORREF param_6,char param_7,char param_8,char param_9)

{
  int cy;
  int y;
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HPALETTE hPal;
  int mode;
  HPALETTE hPal_00;
  HGDIOBJ local_50;
  HBRUSH local_4c;
  DWORD local_44;
  tagSIZE local_3c;
  undefined4 *local_34;
  int local_30;
  int *local_2c;
  tagSIZE local_28;
  tagCOLORADJUSTMENT local_20;
  uint local_8;
  
  local_8 = DAT_00f385b8 ^ (uint)&stack0xfffffffc;
  local_2c = param_2;
  local_3c.cx = 0;
  local_3c.cy = 0;
  local_28.cx = 0;
  local_28.cy = 0;
  local_34 = param_1;
  GetViewportExtEx((HDC)*param_1,&local_3c);
  GetWindowExtEx((HDC)*param_1,&local_28);
  local_44 = 0x8800c6;
  if (param_8 != '\0') {
    local_44 = 0xcc0020;
  }
  if (param_7 != '\0') {
    local_44 = 0xbe0269;
  }
  local_50 = (HGDIOBJ)0x0;
  local_4c = (HBRUSH)0x0;
  if ((param_9 != '\0') && (param_8 != '\0')) {
    local_44 = 0xee0086;
  }
  if (param_6 != 0) {
    local_44 = 0xb8074a;
    local_4c = CreateSolidBrush(param_6);
    local_50 = SelectObject((HDC)*param_1,local_4c);
  }
  local_30 = (local_3c.cx * param_3 + local_28.cx / 2) / local_28.cx;
  cy = (local_3c.cy * param_4 + local_28.cy / 2) / local_28.cy;
  if ((local_30 < param_3) || (cy < param_4)) {
    y = (local_2c[1] * local_3c.cy + local_28.cy / 2) / local_28.cy;
    local_2c = (int *)((*local_2c * local_3c.cx + local_28.cx / 2) / local_28.cx);
    hdc = CreateCompatibleDC((HDC)*param_1);
    h = CreateCompatibleBitmap((HDC)*param_1,local_30,cy);
    h_00 = SelectObject(hdc,h);
    local_20.caSize = 0x18;
    GetColorAdjustment(hdc,&local_20);
    local_20.caReferenceBlack = 1000;
    hPal = CreateHalftonePalette(hdc);
    mode = SetStretchBltMode(hdc,4);
    SetColorAdjustment(hdc,&local_20);
    hPal_00 = SelectPalette(hdc,hPal,0);
    RealizePalette(hdc);
    SetBrushOrgEx(hdc,0,0,(LPPOINT)0x0);
    StretchBlt(hdc,0,0,local_30,cy,param_5,0,0,param_3,param_4,0xcc0020);
    SetViewportExtEx((HDC)*local_34,local_28.cx,local_28.cy,(LPSIZE)0x0);
    BitBlt((HDC)*local_34,(int)local_2c,y,local_30,cy,hdc,0,0,local_44);
    SetViewportExtEx((HDC)*local_34,local_3c.cx,local_3c.cy,(LPSIZE)0x0);
    SelectPalette(hdc,hPal_00,0);
    RealizePalette(hdc);
    SetStretchBltMode(hdc,mode);
    DeleteObject(hPal);
    SelectObject(hdc,h_00);
    if (h != (HBITMAP)0x0) {
      DeleteObject(h);
    }
    DeleteDC(hdc);
    param_1 = local_34;
  }
  else {
    BitBlt((HDC)*param_1,*local_2c,local_2c[1],param_3,param_4,param_5,0,0,local_44);
  }
  if (local_50 != (HGDIOBJ)0x0) {
    SelectObject((HDC)*param_1,local_50);
    DeleteObject(local_4c);
  }
  FUN_00ec9db6(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


