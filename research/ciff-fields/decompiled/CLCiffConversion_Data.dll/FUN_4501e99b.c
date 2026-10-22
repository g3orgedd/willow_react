// Source: CLCiffConversion_Data.dll @ 4501e99b; FUN_4501e99b

undefined4 __fastcall FUN_4501e99b(void *param_1)

{
  int iVar1;
  wchar_t *_Format;
  double local_10;
  wchar_t local_8 [2];
  
  local_10 = *(double *)((int)param_1 + 0xb0);
  iVar1 = FUN_4501d4fe(&local_10);
  if (iVar1 != -0x80000000) {
    if (*(int *)((int)param_1 + 0xf8) == 3) {
      if (iVar1 == 0) {
        iVar1 = 7;
      }
      _Format = L"%1ld";
    }
    else {
      iVar1 = (iVar1 + 6) % 7 + 0x41;
      _Format = L"%c";
    }
    _swprintf_s(local_8,2,_Format,iVar1);
    FUN_4501f984(param_1,local_8);
  }
  return 0;
}


