// Source: CLCiffConversion_Layout.dll @ 45410677; FUN_45410677

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_45410677(void *param_1)

{
  float10 fVar1;
  wchar_t *_Format;
  wchar_t local_10 [4];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  fVar1 = FUN_4540f128(*(double *)((int)param_1 + 0xb0));
  if ((int)fVar1 * 0x18 - (int)(((double)fVar1 - (double)(int)fVar1) * _DAT_45449250) != -0x80000000
     ) {
    if (*(int *)((int)param_1 + 0xf8) == 1) {
      _Format = L"%ld";
    }
    else {
      _Format = L"%02ld";
    }
    _swprintf_s(local_10,3,_Format);
    FUN_45410ae6(param_1,local_10);
  }
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


