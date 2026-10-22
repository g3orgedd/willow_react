// Source: CLCiffConversion_Data.dll @ 4501f4e9; FUN_4501f4e9

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_4501f4e9(void *param_1)

{
  float10 fVar1;
  wchar_t *_Format;
  wchar_t local_10 [4];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  fVar1 = FUN_4501d47f(*(double *)((int)param_1 + 0xb0));
  if ((int)fVar1 * 0x18 - (int)(((double)fVar1 - (double)(int)fVar1) * _DAT_450416e8) != -0x80000000
     ) {
    if (*(int *)((int)param_1 + 0xf8) == 1) {
      _Format = L"%ld";
    }
    else {
      _Format = L"%02ld";
    }
    _swprintf_s(local_10,3,_Format);
    FUN_4501f984(param_1,local_10);
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


