// Source: CLCiffConversion_Data.dll @ 4501ed53; FUN_4501ed53

void __fastcall FUN_4501ed53(void *param_1)

{
  double *pdVar1;
  int iVar2;
  wchar_t *_Format;
  double local_24;
  int local_1c;
  double local_18;
  wchar_t local_10 [4];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_18 = *(double *)((int)param_1 + 0xb0);
  if ((2 < *(int *)((int)param_1 + 0xf8)) && (iVar2 = *(int *)((int)param_1 + 0x13d4), iVar2 != 0))
  {
    if (iVar2 < 0) {
      local_1c = -iVar2;
      pdVar1 = (double *)FUN_4501d277(&local_24,&local_18,&local_1c);
    }
    else {
      local_1c = iVar2;
      pdVar1 = (double *)FUN_4501d1c2(&local_24,&local_18,&local_1c);
    }
    local_18 = *pdVar1;
  }
  iVar2 = FUN_4501db88(&local_18);
  if (iVar2 != -0x80000000) {
    if ((*(int *)((int)param_1 + 0xf8) == 1) || (*(int *)((int)param_1 + 0xf8) == 3)) {
      _Format = L"%ld";
    }
    else {
      _Format = L"%03ld";
    }
    _swprintf_s(local_10,4,_Format,iVar2);
    FUN_4501f984(param_1,local_10);
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


