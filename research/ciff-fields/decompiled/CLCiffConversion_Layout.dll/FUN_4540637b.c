// Source: CLCiffConversion_Layout.dll @ 4540637b; FUN_4540637b

void __cdecl FUN_4540637b(void *param_1)

{
  _SYSTEMTIME local_18;
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  GetLocalTime(&local_18);
  FUN_4540f092(param_1,&local_18.wYear);
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


