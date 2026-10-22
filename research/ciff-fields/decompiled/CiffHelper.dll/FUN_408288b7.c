// Source: CiffHelper.dll @ 408288b7; FUN_408288b7

undefined2 * FUN_408288b7(void)

{
  wchar_t *_Src;
  
  if (DAT_40865308 == 0) {
    _Src = (wchar_t *)FUN_408288ef();
    _wcscpy_s(&DAT_40865308,0x104,_Src);
    _wcscat_s(&DAT_40865308,0x104,L"Claricom.INI");
  }
  return &DAT_40865308;
}


