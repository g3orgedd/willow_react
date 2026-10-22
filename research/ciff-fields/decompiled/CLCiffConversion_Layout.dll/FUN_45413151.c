// Source: CLCiffConversion_Layout.dll @ 45413151; FUN_45413151

void __fastcall FUN_45413151(int *param_1)

{
  if (*param_1 != 0) {
    ReleaseDC((HWND)param_1[1],(HDC)*param_1);
    *param_1 = 0;
    param_1[1] = 0;
  }
  return;
}


