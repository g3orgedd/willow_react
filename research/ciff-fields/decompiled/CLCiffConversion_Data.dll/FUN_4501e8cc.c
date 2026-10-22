// Source: CLCiffConversion_Data.dll @ 4501e8cc; FUN_4501e8cc

void __fastcall FUN_4501e8cc(void *param_1)

{
  int iVar1;
  wchar_t *_Format;
  undefined8 local_18;
  wchar_t local_10 [4];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_18 = *(undefined8 *)((int)param_1 + 0xb0);
  iVar1 = FUN_4501d54f(&local_18,*(short *)((int)param_1 + 0xf4) == 0x6a);
  if (iVar1 != -0x80000000) {
    if (*(int *)((int)param_1 + 0xf8) == 1) {
      _Format = L"%ld";
    }
    else {
      _Format = L"%03ld";
    }
    _swprintf_s(local_10,4,_Format,iVar1);
    FUN_4501f984(param_1,local_10);
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


