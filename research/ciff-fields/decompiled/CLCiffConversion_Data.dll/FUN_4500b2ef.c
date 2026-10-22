// Source: CLCiffConversion_Data.dll @ 4500b2ef; FUN_4500b2ef

void __cdecl FUN_4500b2ef(int param_1)

{
  _SYSTEMTIME local_830;
  WCHAR local_820 [1024];
  wchar_t local_20 [12];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  if (DAT_45053980 != '\0') {
    GetLocalTime(&local_830);
    _swprintf_s(local_20,0xc,L"%02d:%02d:%02d - ",(uint)local_830.wHour,(uint)local_830.wMinute,
                (uint)local_830.wSecond);
    FUN_45022873((char *)local_820,0x400,0x3ff,param_1,&stack0x00000008);
    OutputDebugStringW(local_20);
    OutputDebugStringW(local_820);
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


