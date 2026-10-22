// Source: CLCSBarcodeField.dll @ 414228c2; FUN_414228c2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

HBITMAP __cdecl FUN_414228c2(HDC param_1,LONG param_2,LONG param_3,WORD param_4)

{
  BITMAPINFO *lpbmi;
  HBITMAP pHVar1;
  void *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  pHVar1 = (HBITMAP)0x0;
  local_8 = 0;
  lpbmi = (BITMAPINFO *)FUN_4145fe0b(0x3c);
  if (lpbmi != (BITMAPINFO *)0x0) {
    (lpbmi->bmiHeader).biSize = 0x28;
    (lpbmi->bmiHeader).biCompression = 0;
    (lpbmi->bmiHeader).biPlanes = 1;
    (lpbmi->bmiHeader).biSizeImage = 0;
    (lpbmi->bmiHeader).biXPelsPerMeter = 0;
    (lpbmi->bmiHeader).biYPelsPerMeter = 0;
    (lpbmi->bmiHeader).biClrUsed = 0;
    (lpbmi->bmiHeader).biClrImportant = 0;
    *(undefined4 *)&lpbmi->bmiColors[0].rgbGreen = 0xff000000;
    lpbmi->bmiColors[0].rgbBlue = '\0';
    *(undefined4 *)((int)&lpbmi[1].bmiHeader.biSize + 1) = 0xffff;
    *(undefined4 *)((int)&lpbmi[1].bmiHeader.biWidth + 1) = 0xff00ff00;
    *(undefined4 *)((int)&lpbmi[1].bmiHeader.biHeight + 1) = 0xc0000000;
    *(undefined2 *)((int)&lpbmi[1].bmiHeader.biPlanes + 1) = 0xc0c0;
    *(undefined1 *)((int)&lpbmi[1].bmiHeader.biBitCount + 1) = 0;
    (lpbmi->bmiHeader).biWidth = param_2;
    (lpbmi->bmiHeader).biHeight = param_3;
    (lpbmi->bmiHeader).biBitCount = param_4;
    pHVar1 = CreateDIBSection(param_1,lpbmi,0,local_14,(HANDLE)0x0,0);
    FID_conflict__free(lpbmi);
  }
  return pHVar1;
}


