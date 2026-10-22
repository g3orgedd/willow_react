// Source: CLCiffConversion_Layout.dll @ 4540f3e8; FUN_4540f3e8

void __cdecl
FUN_4540f3e8(DOUBLE *param_1,WORD param_2,uint param_3,WORD param_4,WORD param_5,WORD param_6,
            WORD param_7)

{
  _SYSTEMTIME local_18;
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  local_18.wMilliseconds = 0;
  local_18.wYear = param_2;
  local_18._2_4_ = param_3 & 0xffff;
  local_18.wHour = param_5;
  local_18.wDay = param_4;
  local_18.wSecond = param_7;
  local_18.wMinute = param_6;
  SystemTimeToVariantTime(&local_18,param_1);
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


