// Source: CLCiffConversion_Data.dll @ 4501e865; FUN_4501e865

void __fastcall FUN_4501e865(void *param_1)

{
  int iVar1;
  WCHAR local_58 [40];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  iVar1 = GetDateFormatW(*(LCID *)((int)param_1 + 0xa4),0,(SYSTEMTIME *)((int)param_1 + 0xbc),
                         (LPCWSTR)((int)param_1 + 0xd6),local_58,0x27);
  if (iVar1 != 0) {
    CharUpperW(local_58);
    FUN_4501f984(param_1,local_58);
    SysFreeString((BSTR)0x0);
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


