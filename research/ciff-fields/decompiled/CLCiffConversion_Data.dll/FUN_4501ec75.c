// Source: CLCiffConversion_Data.dll @ 4501ec75; FUN_4501ec75

void __fastcall FUN_4501ec75(void *param_1)

{
  int iVar1;
  wchar_t *_Format;
  double local_1c;
  wchar_t local_14 [6];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_1c = *(double *)((int)param_1 + 0xb0);
  iVar1 = FUN_4501de09(&local_1c);
  if (iVar1 != -0x80000000) {
    if (*(int *)((int)param_1 + 0xf8) == 1) {
      _Format = L"%ld";
    }
    else {
      _Format = L"%04ld";
    }
    _swprintf_s(local_14,5,_Format,iVar1);
    FUN_4501f984(param_1,local_14);
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


