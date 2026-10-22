// Source: CLCiffConversion_Layout.dll @ 4540fa48; FUN_4540fa48

void __fastcall FUN_4540fa48(void *param_1)

{
  int iVar1;
  wchar_t *_Format;
  undefined8 local_18;
  wchar_t local_10 [4];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  local_18 = *(undefined8 *)((int)param_1 + 0xb0);
  iVar1 = FUN_4540f1f8(&local_18,*(short *)((int)param_1 + 0xf4) == 0x6a);
  if (iVar1 != -0x80000000) {
    if (*(int *)((int)param_1 + 0xf8) == 1) {
      _Format = L"%ld";
    }
    else {
      _Format = L"%03ld";
    }
    _swprintf_s(local_10,4,_Format,iVar1);
    FUN_45410ae6(param_1,local_10);
  }
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


