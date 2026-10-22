// Source: CLCiffConversion_Layout.dll @ 4540ffe0; FUN_4540ffe0

void __fastcall FUN_4540ffe0(void *param_1)

{
  int iVar1;
  double local_18;
  wchar_t local_10 [4];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  local_18 = *(double *)((int)param_1 + 0xb0);
  iVar1 = FUN_4540f8a1(&local_18);
  if (iVar1 != -0x80000000) {
    _swprintf_s(local_10,3,L"%ld",iVar1 % 100);
    FUN_45410ae6(param_1,local_10);
  }
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


