// Source: CLCiffConversion_Layout.dll @ 4540e218; FUN_4540e218

void FUN_4540e218(int param_1)

{
  _SYSTEMTIME local_18;
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  GetLocalTime(&local_18);
  SystemTimeToVariantTime(&local_18,(DOUBLE *)(param_1 + 0x68));
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


