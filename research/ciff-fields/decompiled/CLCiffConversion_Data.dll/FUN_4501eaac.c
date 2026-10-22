// Source: CLCiffConversion_Data.dll @ 4501eaac; FUN_4501eaac

void __fastcall FUN_4501eaac(void *param_1)

{
  int iVar1;
  wchar_t *_Format;
  double local_18;
  wchar_t local_10 [4];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_18 = *(double *)((int)param_1 + 0xb0);
  iVar1 = FUN_4501dfb7(&local_18);
  if (iVar1 != -0x80000000) {
    local_10[1] = L'\0';
    local_10[2] = L'\0';
    local_10[0] = L'\0';
    if (*(int *)((int)param_1 + 0xf8) == 1) {
      _Format = L"%ld";
    }
    else {
      _Format = L"%02ld";
    }
    _swprintf_s(local_10,3,_Format,iVar1);
    FUN_4501f984(param_1,local_10);
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


