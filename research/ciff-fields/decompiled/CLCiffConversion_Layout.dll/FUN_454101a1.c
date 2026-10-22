// Source: CLCiffConversion_Layout.dll @ 454101a1; FUN_454101a1

undefined4 __fastcall FUN_454101a1(void *param_1)

{
  int iVar1;
  wchar_t *pwVar2;
  double local_c;
  
  local_c = *(double *)((int)param_1 + 0xb0);
  iVar1 = FUN_4540f55b(&local_c);
  if (iVar1 != -0x80000000) {
    pwVar2 = (wchar_t *)(iVar1 * 0x18 + 0x144 + (int)param_1);
    if (7 < *(uint *)(pwVar2 + 10)) {
      pwVar2 = *(wchar_t **)pwVar2;
    }
    FUN_45410ae6(param_1,pwVar2);
  }
  return 0;
}


