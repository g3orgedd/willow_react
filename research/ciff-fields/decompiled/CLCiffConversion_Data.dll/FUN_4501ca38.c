// Source: CLCiffConversion_Data.dll @ 4501ca38; FUN_4501ca38

undefined2 * FUN_4501ca38(void)

{
  wchar_t *_Src;
  
  if (DAT_450543b0 == 0) {
    _Src = (wchar_t *)FUN_4501ca70();
    _wcscpy_s(&DAT_450543b0,0x104,_Src);
    _wcscat_s(&DAT_450543b0,0x104,L"Claricom.INI");
  }
  return &DAT_450543b0;
}


