// Source: CLPrintPreview.ocx @ 3f41595c; FUN_3f41595c

void FUN_3f41595c(void *param_1,int *param_2,int *param_3,undefined4 *param_4,HBITMAP param_5)

{
  HBRUSH hbr;
  HDC pHVar1;
  int iVar2;
  undefined1 local_98 [4];
  int local_94;
  int local_90;
  VARIANTARG local_80;
  int local_70;
  int *local_6c;
  int *local_68;
  void *local_64;
  HGDIOBJ local_60;
  HBITMAP local_5c;
  HDC local_58;
  HBITMAP local_54;
  HDC local_50;
  undefined4 *local_4c;
  int *local_48;
  BITMAPINFO local_44;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_3f45f380 ^ (uint)&stack0xfffffffc;
  iVar2 = 0;
  local_68 = param_2;
  *param_2 = 0;
  *param_3 = 0;
  *param_4 = 0;
  param_5->unused = 0;
  local_6c = param_3;
  local_4c = param_4;
  local_54 = param_5;
  if ((0 < *(int *)((int)param_1 + 0x1b8)) && (0 < *(int *)((int)param_1 + 0x1bc))) {
    local_58 = CreateCompatibleDC((HDC)0x0);
    local_50 = local_58;
    local_5c = CreateCompatibleBitmap
                         (local_58,*(int *)((int)param_1 + 0x1b8),*(int *)((int)param_1 + 0x1bc));
    local_60 = SelectObject(local_50,local_5c);
    if (local_60 == (HGDIOBJ)0x0) {
      GetLastError();
    }
    pHVar1 = local_50;
    local_18.bottom = *(LONG *)((int)param_1 + 0x1bc);
    local_18.right = *(LONG *)((int)param_1 + 0x1b8);
    local_18.top = 0;
    local_18.left = 0;
    hbr = GetStockObject(0);
    FillRect(pHVar1,&local_18,hbr);
    FUN_3f4272e0((uint *)&local_80,0,0x10);
    VariantInit(&local_80);
    local_70 = (**(code **)(**(int **)((int)param_1 + 0xe0) + 0x30))
                         (*(int **)((int)param_1 + 0xe0),*(undefined4 *)((int)param_1 + 0x11c),
                          &local_80);
    if (-1 < local_70) {
      CComQIPtr<>(&local_48,(undefined4 *)local_80.n1._8_4_);
      if (local_48 == (int *)0x0) {
        local_54->unused = 0;
        *local_4c = 0;
      }
      else {
        FUN_3f4130f7(param_1,&local_50,local_48,0);
        (**(code **)(*local_48 + 0x5c))(local_48,local_4c);
        (**(code **)(*local_48 + 100))(local_48,local_54);
      }
      GetObjectW(local_5c,0x18,local_98);
      FUN_3f4272e0((uint *)&local_44,0,0x2c);
      local_44.bmiHeader.biWidth = local_94;
      local_44.bmiHeader.biHeight = local_90;
      local_44.bmiHeader.biSize = 0x28;
      local_44.bmiHeader.biPlanes = 1;
      local_44.bmiHeader.biBitCount = 0x20;
      pHVar1 = CreateCompatibleDC((HDC)0x0);
      local_54 = CreateDIBSection(pHVar1,&local_44,0,&local_64,(HANDLE)0x0,0);
      if (local_54 != (HBITMAP)0x0) {
        local_4c = SelectObject(pHVar1,local_54);
        BitBlt(pHVar1,0,0,local_94,local_90,local_50,0,0,0xcc0020);
        local_90 = local_90 * local_94;
        while (local_90 = local_90 + -1, -1 < local_90) {
          if (*(int *)((int)local_64 + local_90 * 4) != 0xffffff) {
            iVar2 = iVar2 + 1;
          }
        }
        SelectObject(pHVar1,local_4c);
        DeleteObject(local_54);
      }
      DeleteDC(pHVar1);
      SelectObject(local_58,local_60);
      DeleteObject(local_5c);
      DeleteDC(local_58);
      *local_6c = *(int *)((int)param_1 + 0x1bc) * *(int *)((int)param_1 + 0x1b8);
      *local_68 = iVar2;
      if (local_48 != (int *)0x0) {
        (**(code **)(*local_48 + 8))(local_48);
      }
    }
    VariantClear(&local_80);
  }
  FUN_3f427fc8(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


