// Source: CLCiffConversion_Layout.dll @ 4541046f; FUN_4541046f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_4541046f(void *param_1)

{
  wchar_t local_30 [20];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  FUN_4542e330(param_1,(int)DAT_45449248,(int)((ulonglong)DAT_45449248 >> 0x20),
               SUB84((double)*(int *)((int)param_1 + 0x158),0),
               (uint)((ulonglong)(double)*(int *)((int)param_1 + 0x158) >> 0x20));
  _swprintf_s(local_30,0x14,L"%lu");
  FUN_45410ae6(param_1,local_30);
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


