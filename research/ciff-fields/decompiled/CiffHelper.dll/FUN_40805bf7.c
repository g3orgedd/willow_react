// Source: CiffHelper.dll @ 40805bf7; FUN_40805bf7

void __cdecl FUN_40805bf7(void *param_1)

{
  _SYSTEMTIME local_18;
  uint local_8;
  
  local_8 = DAT_40862970 ^ (uint)&stack0xfffffffc;
  GetLocalTime(&local_18);
  FUN_408292fd(param_1,&local_18.wYear);
  FUN_4082d440(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


