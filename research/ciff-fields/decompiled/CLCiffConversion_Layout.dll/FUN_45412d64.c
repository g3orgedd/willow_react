// Source: CLCiffConversion_Layout.dll @ 45412d64; FUN_45412d64

void __fastcall FUN_45412d64(undefined4 *param_1)

{
  HDC hdc;
  
  hdc = (HDC)*param_1;
  if (hdc != (HDC)0x0) {
    *param_1 = 0;
    DeleteDC(hdc);
  }
  return;
}


