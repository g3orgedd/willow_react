// Source: CLCiffConversion_Data.dll @ 4501eec9; FUN_4501eec9

void __fastcall FUN_4501eec9(void *param_1)

{
  int iVar1;
  double local_1c;
  wchar_t local_14 [6];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_1c = *(double *)((int)param_1 + 0xb0);
  iVar1 = FUN_4501db37(&local_1c);
  if (iVar1 != -0x80000000) {
    _swprintf_s(local_14,6,L"%c",((int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3) + 0x41);
    FUN_4501f984(param_1,local_14);
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


