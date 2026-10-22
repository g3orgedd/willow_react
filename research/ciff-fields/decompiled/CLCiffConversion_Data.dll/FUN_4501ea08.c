// Source: CLCiffConversion_Data.dll @ 4501ea08; FUN_4501ea08

void __fastcall FUN_4501ea08(void *param_1)

{
  uint uVar1;
  WCHAR *lpsz;
  LCID Locale;
  WCHAR local_1c [10];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  Locale = 0x4501ea3c;
  uVar1 = GetDateFormatW(*(LCID *)((int)param_1 + 0xa4),0,(SYSTEMTIME *)((int)param_1 + 0xbc),L"ddd"
                         ,local_1c,0);
  if (uVar1 != 0) {
    lpsz = local_1c;
    if (10 < uVar1) {
      lpsz = (WCHAR *)FUN_45020ebb(-(uint)((int)((ulonglong)uVar1 * 2 >> 0x20) != 0) |
                                   (uint)((ulonglong)uVar1 * 2));
    }
    GetDateFormatW(Locale,*(DWORD *)((int)param_1 + 0xa4),(SYSTEMTIME *)0x0,
                   (LPCWSTR)((int)param_1 + 0xbc),L"ddd",(int)lpsz);
    CharUpperW(lpsz);
    FUN_4501f984(param_1,lpsz);
    if (10 < uVar1) {
      FID_conflict__free(lpsz);
    }
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


