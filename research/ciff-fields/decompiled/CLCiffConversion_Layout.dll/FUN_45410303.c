// Source: CLCiffConversion_Layout.dll @ 45410303; FUN_45410303

undefined4 __fastcall FUN_45410303(void *param_1)

{
  int iVar1;
  wchar_t *pwVar2;
  double local_c;
  
  local_c = *(double *)((int)param_1 + 0xb0);
  iVar1 = FUN_4540f6a1(&local_c);
  if (iVar1 != -0x80000000) {
    pwVar2 = (wchar_t *)(iVar1 * 0x18 + 0x834 + (int)param_1);
    if (7 < *(uint *)(pwVar2 + 10)) {
      pwVar2 = *(wchar_t **)pwVar2;
    }
    FUN_45410ae6(param_1,pwVar2);
  }
  return 0;
}


