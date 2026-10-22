// Source: CLCiffConversion_Data.dll @ 4501f025; FUN_4501f025

undefined4 __fastcall FUN_4501f025(void *param_1)

{
  int iVar1;
  wchar_t *pwVar2;
  double local_c;
  
  local_c = *(double *)((int)param_1 + 0xb0);
  iVar1 = FUN_4501de65(&local_c);
  if (iVar1 != -0x80000000) {
    pwVar2 = (wchar_t *)(iVar1 * 0x18 + 0x144 + (int)param_1);
    if (7 < *(uint *)(pwVar2 + 10)) {
      pwVar2 = *(wchar_t **)pwVar2;
    }
    FUN_4501f984(param_1,pwVar2);
  }
  return 0;
}


