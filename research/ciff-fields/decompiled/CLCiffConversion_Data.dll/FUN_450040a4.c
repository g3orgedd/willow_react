// Source: CLCiffConversion_Data.dll @ 450040a4; FUN_450040a4

void __cdecl FUN_450040a4(void *param_1)

{
  _SYSTEMTIME local_18;
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  GetLocalTime(&local_18);
  FUN_4501d127(param_1,&local_18.wYear);
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


