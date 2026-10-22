// Source: CLCiffConversion_Data.dll @ 4501f2f3; FUN_4501f2f3

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_4501f2f3(void *param_1)

{
  wchar_t local_30 [20];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  FUN_450261d0(param_1,(int)DAT_450416e0,(int)((ulonglong)DAT_450416e0 >> 0x20),
               SUB84((double)*(int *)((int)param_1 + 0x158),0),
               (uint)((ulonglong)(double)*(int *)((int)param_1 + 0x158) >> 0x20));
  _swprintf_s(local_30,0x14,L"%lu");
  FUN_4501f984(param_1,local_30);
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


