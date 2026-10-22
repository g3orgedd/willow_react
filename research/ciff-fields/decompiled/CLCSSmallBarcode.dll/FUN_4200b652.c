// Source: CLCSSmallBarcode.dll @ 4200b652; FUN_4200b652

undefined4 FUN_4200b652(int param_1,undefined4 *param_2)

{
  HDC hdc;
  COLORREF color;
  COLORREF color_00;
  
  if (*(int *)(param_1 + 0x2c) != 0) {
    hdc = (HDC)*param_2;
    color = GetTextColor(hdc);
    color_00 = GetBkColor(hdc);
    SetTextColor(hdc,color_00);
    SetBkColor(hdc,color);
  }
  return 0;
}


