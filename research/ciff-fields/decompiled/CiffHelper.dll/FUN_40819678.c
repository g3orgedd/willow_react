// Source: CiffHelper.dll @ 40819678; FUN_40819678

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_40819678(int param_1)

{
  uint uStack_10b8;
  int local_109c [5];
  _SYSTEMTIME local_1088 [2];
  char local_1064 [12];
  char local_1058 [4160];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_40846db2;
  local_10 = ExceptionList;
  uStack_10b8 = DAT_40862970 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_10b8;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_10b8;
  FUN_408030e3(local_109c,L"");
  if (DAT_408648dc != '\0') {
    GetLocalTime(local_1088);
    _sprintf_s(local_1064,0xc,"%02d:%02d:%02d - ",(uint)local_1088[0].wHour,
               (uint)local_1088[0].wMinute,(uint)local_1088[0].wSecond);
    FUN_4082f021(local_1058,0x1000,0xfff,param_1,&stack0x00000008);
    OutputDebugStringA(local_1064);
    OutputDebugStringA(local_1058);
  }
  FUN_40803143(local_109c);
  ExceptionList = local_10;
  FUN_4082d440(local_18 ^ (uint)&stack0xfffffffc);
  return;
}


