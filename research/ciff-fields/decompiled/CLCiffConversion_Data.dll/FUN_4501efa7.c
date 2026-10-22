// Source: CLCiffConversion_Data.dll @ 4501efa7; FUN_4501efa7

void __fastcall FUN_4501efa7(void *param_1)

{
  int iVar1;
  double local_1c;
  wchar_t local_14 [6];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_1c = *(double *)((int)param_1 + 0xb0);
  iVar1 = FUN_4501db37(&local_1c);
  if (iVar1 != -0x80000000) {
    _swprintf_s(local_14,6,L"%c",iVar1 + 0x41);
    if (0x48 < (ushort)local_14[0]) {
      local_14[0] = local_14[0] + L'\x01';
    }
    if (0x4e < (ushort)local_14[0]) {
      local_14[0] = local_14[0] + L'\x01';
    }
    FUN_4501f984(param_1,local_14);
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


