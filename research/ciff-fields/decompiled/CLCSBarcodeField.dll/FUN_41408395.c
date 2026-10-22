// Source: CLCSBarcodeField.dll @ 41408395; FUN_41408395

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_41408395(HDC param_1)

{
  BITMAPINFO *lpbmi;
  int iVar1;
  HBITMAP h;
  HBRUSH hbr;
  void *local_20;
  int local_1c;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_414aacf0 ^ (uint)&stack0xfffffffc;
  lpbmi = (BITMAPINFO *)FUN_4145fe0b(0x30);
  if (lpbmi != (BITMAPINFO *)0x0) {
    (lpbmi->bmiHeader).biSize = 0x28;
    (lpbmi->bmiHeader).biWidth = *(LONG *)(local_1c + 0xcc);
    (lpbmi->bmiHeader).biHeight = *(LONG *)(local_1c + 0xd0);
    (lpbmi->bmiHeader).biCompression = 0;
    (lpbmi->bmiHeader).biPlanes = 1;
    (lpbmi->bmiHeader).biBitCount = 1;
    (lpbmi->bmiHeader).biSizeImage = 0;
    iVar1 = FUN_414092db(*(float *)(local_1c + 0x30) * _DAT_41481014);
    (lpbmi->bmiHeader).biXPelsPerMeter = iVar1;
    iVar1 = FUN_414092db(*(float *)(local_1c + 0x34) * _DAT_41481014);
    (lpbmi->bmiHeader).biYPelsPerMeter = iVar1;
    (lpbmi->bmiHeader).biClrUsed = 0;
    (lpbmi->bmiHeader).biClrImportant = 0;
    *(undefined4 *)&lpbmi->bmiColors[0].rgbReserved = 0xffffff00;
    *(undefined1 *)((int)&lpbmi[1].bmiHeader.biSize + 3) = 0;
    lpbmi->bmiColors[0].rgbGreen = '\0';
    lpbmi->bmiColors[0].rgbRed = '\0';
    lpbmi->bmiColors[0].rgbBlue = '\0';
    if ((param_1 != (HDC)0x0) &&
       (h = CreateDIBSection(param_1,lpbmi,0,&local_20,(HANDLE)0x0,0), h != (HBITMAP)0x0)) {
      *(HBITMAP *)(local_1c + 4) = h;
      SelectObject(param_1,h);
      local_18.right = (lpbmi->bmiHeader).biWidth;
      local_18.bottom = (lpbmi->bmiHeader).biHeight;
      local_18.left = 0;
      local_18.top = 0;
      hbr = GetStockObject(0);
      FillRect(param_1,&local_18,hbr);
    }
    FID_conflict__free(lpbmi);
  }
  local_20 = (void *)0x414084ac;
  FUN_41461e5c(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


