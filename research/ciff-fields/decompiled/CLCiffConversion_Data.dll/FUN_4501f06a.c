// Source: CLCiffConversion_Data.dll @ 4501f06a; FUN_4501f06a

undefined4 __fastcall FUN_4501f06a(void *param_1)

{
  int iVar1;
  wchar_t *pwVar2;
  double local_c;
  
  local_c = *(double *)((int)param_1 + 0xb0);
  iVar1 = FUN_4501d4fe(&local_c);
  if (iVar1 != -0x80000000) {
    pwVar2 = (wchar_t *)(((iVar1 + 6) % 7) * 0x18 + 0x4bc + (int)param_1);
    if (7 < *(uint *)(pwVar2 + 10)) {
      pwVar2 = *(wchar_t **)pwVar2;
    }
    FUN_4501f984(param_1,pwVar2);
  }
  return 0;
}


