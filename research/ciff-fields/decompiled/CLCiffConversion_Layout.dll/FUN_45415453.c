// Source: CLCiffConversion_Layout.dll @ 45415453; FUN_45415453

void __thiscall
FUN_45415453(void *this,undefined4 *param_1,LONG param_2,LONG *param_3,LONG *param_4)

{
  HDC pHVar1;
  HGDIOBJ h;
  HGDIOBJ h_00;
  UINT c;
  tagSIZE local_1c;
  tagSIZE local_14;
  HDC local_c;
  HDC local_8;
  
  local_c = GetDC((HWND)0x0);
  pHVar1 = CreateCompatibleDC(local_c);
  local_1c.cx = 0;
  local_1c.cy = 0;
  local_8 = pHVar1;
  SetMapMode(pHVar1,8);
  SetWindowExtEx(pHVar1,1,1,&local_1c);
  SetViewportExtEx(pHVar1,1,1,&local_1c);
  h = (HGDIOBJ)FUN_4541f002(this,param_2);
  h_00 = SelectObject(pHVar1,h);
  c = SysStringLen((BSTR)*param_1);
  pHVar1 = local_8;
  local_14.cx = 0;
  local_14.cy = 0;
  GetTextExtentPoint32W(local_8,(LPCWSTR)*param_1,c,&local_14);
  SelectObject(pHVar1,h_00);
  DeleteObject(h);
  DeleteDC(pHVar1);
  ReleaseDC((HWND)0x0,local_c);
  *param_4 = local_14.cx;
  *param_3 = local_14.cy;
  return;
}


