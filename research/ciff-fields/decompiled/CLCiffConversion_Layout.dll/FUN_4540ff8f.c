// Source: CLCiffConversion_Layout.dll @ 4540ff8f; FUN_4540ff8f

undefined4 __fastcall FUN_4540ff8f(void *param_1)

{
  int iVar1;
  double local_10;
  wchar_t local_8 [2];
  
  local_10 = *(double *)((int)param_1 + 0xb0);
  iVar1 = FUN_4540f8a1(&local_10);
  if (iVar1 != -0x80000000) {
    _swprintf_s(local_8,2,L"%1ld",iVar1 % 10);
    FUN_45410ae6(param_1,local_8);
  }
  return 0;
}


