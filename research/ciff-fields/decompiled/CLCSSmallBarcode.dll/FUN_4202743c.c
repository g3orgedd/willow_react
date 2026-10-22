// Source: CLCSSmallBarcode.dll @ 4202743c; FUN_4202743c

void __thiscall
FUN_4202743c(void *this,HANDLE param_1,HDC param_2,undefined4 *param_3,LONG param_4,LONG param_5)

{
  HDC hdc;
  HANDLE h;
  HGDIOBJ pvVar1;
  int iVar2;
  HBRUSH hbr;
  tagSIZE local_44;
  tagSIZE local_3c;
  tagSIZE local_34;
  tagSIZE local_2c;
  HDC local_24;
  undefined4 *local_20;
  HANDLE local_1c;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_420b8f90 ^ (uint)&stack0xfffffffc;
  local_1c = param_1;
  local_20 = param_3;
  local_24 = CreateCompatibleDC((HDC)0x0);
  local_3c.cx = 0;
  local_3c.cy = 0;
  local_34.cx = 0;
  local_34.cy = 0;
  local_2c.cx = 0;
  local_2c.cy = 0;
  local_44.cx = 0;
  local_44.cy = 0;
  SetMapMode(local_24,1);
  GetViewportExtEx(param_2,&local_2c);
  GetWindowExtEx(param_2,&local_44);
  hdc = local_24;
  SetMapMode(local_24,8);
  SetViewportExtEx(hdc,100,100,&local_3c);
  SetWindowExtEx(hdc,100,100,&local_34);
  h = local_1c;
  pvVar1 = SelectObject(hdc,local_1c);
  *(HGDIOBJ *)((int)this + 0x78) = pvVar1;
  iVar2 = GetObjectW(h,0x54,(LPVOID)((int)this + 0x18));
  if (iVar2 != 0) {
    hbr = GetStockObject(0);
    local_18.bottom = param_4;
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = param_5;
    FillRect(hdc,&local_18,hbr);
    *local_20 = hdc;
  }
  FUN_4206a5c8(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


