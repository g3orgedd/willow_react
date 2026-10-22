// Source: CLCSSmallBarcode.dll @ 4200d3ce; FUN_4200d3ce

undefined4 __thiscall
FUN_4200d3ce(void *this,LONG param_1,LONG param_2,int param_3,LONG param_4,LONG param_5)

{
  int iVar1;
  BITMAPINFO *lpbmi;
  HDC hdc;
  HBITMAP h;
  HGDIOBJ pvVar2;
  undefined4 uVar3;
  
  if ((param_3 != 1) && (param_3 != 0x18)) {
    return 0x80070057;
  }
  iVar1 = FUN_4200da9f((int)this);
  if (iVar1 == 1) {
    FUN_4200d514((int)this);
  }
  lpbmi = (BITMAPINFO *)FUN_42067510(0x30);
  if (lpbmi == (BITMAPINFO *)0x0) {
    return 0x8007000e;
  }
  (lpbmi->bmiHeader).biWidth = param_1;
  (lpbmi->bmiHeader).biHeight = param_2;
  (lpbmi->bmiHeader).biBitCount = (WORD)param_3;
  (lpbmi->bmiHeader).biPlanes = 1;
  uVar3 = 0;
  (lpbmi->bmiHeader).biXPelsPerMeter = param_4;
  (lpbmi->bmiHeader).biSize = 0x28;
  (lpbmi->bmiHeader).biCompression = 0;
  (lpbmi->bmiHeader).biSizeImage = 0;
  (lpbmi->bmiHeader).biYPelsPerMeter = param_5;
  (lpbmi->bmiHeader).biClrUsed = 0;
  (lpbmi->bmiHeader).biClrImportant = 0;
  *(LONG *)((int)this + 4) = param_4;
  *(LONG *)((int)this + 8) = param_5;
  FUN_4200d55f(this,(int)lpbmi);
  *(uint *)((int)this + 0x1c) =
       (uint)(lpbmi->bmiHeader).biBitCount * (lpbmi->bmiHeader).biWidth + 0x1f >> 3 & 0x1ffffffc;
  hdc = CreateCompatibleDC((HDC)0x0);
  *(HDC *)((int)this + 0xc) = hdc;
  if (hdc != (HDC)0x0) {
    h = CreateDIBSection(hdc,lpbmi,0,(void **)((int)this + 0x18),(HANDLE)0x0,0);
    *(HBITMAP *)((int)this + 0x10) = h;
    if (h != (HBITMAP)0x0) {
      pvVar2 = SelectObject(*(HDC *)((int)this + 0xc),h);
      *(HGDIOBJ *)((int)this + 0x14) = pvVar2;
      goto LAB_4200d4a6;
    }
  }
  uVar3 = 0x80004005;
LAB_4200d4a6:
  FID_conflict__free(lpbmi);
  return uVar3;
}


