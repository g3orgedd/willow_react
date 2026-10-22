// Source: CLCiffConversion_Layout.dll @ 4540f937; FUN_4540f937

void __fastcall FUN_4540f937(void *param_1)

{
  int iVar1;
  WCHAR local_58 [40];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  iVar1 = GetTimeFormatW(*(LCID *)((int)param_1 + 0xa4),0,(SYSTEMTIME *)((int)param_1 + 0xbc),
                         (LPCWSTR)((int)param_1 + 0xd0),local_58,0x27);
  if (iVar1 != 0) {
    FUN_45410ae6(param_1,local_58);
  }
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


