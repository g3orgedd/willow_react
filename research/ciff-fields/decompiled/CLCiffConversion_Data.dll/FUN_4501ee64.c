// Source: CLCiffConversion_Data.dll @ 4501ee64; FUN_4501ee64

void __fastcall FUN_4501ee64(void *param_1)

{
  int iVar1;
  double local_18;
  wchar_t local_10 [4];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_18 = *(double *)((int)param_1 + 0xb0);
  iVar1 = FUN_4501e220(&local_18);
  if (iVar1 != -0x80000000) {
    _swprintf_s(local_10,3,L"%ld",iVar1 % 100);
    FUN_4501f984(param_1,local_10);
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


