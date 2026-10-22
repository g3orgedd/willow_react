// Source: CLCSGraphicPrimitive.dll @ 428071a4; FUN_428071a4

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_428071a4(int param_1)

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
  
  puStack_c = &LAB_42829f05;
  local_10 = ExceptionList;
  uStack_10b8 = DAT_4283cbb0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_10b8;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_10b8;
  FUN_42801e68(local_109c,L"");
  if (DAT_42840b00 != '\0') {
    GetLocalTime(local_1088);
    _sprintf_s(local_1064,0xc,"%02d:%02d:%02d - ",(uint)local_1088[0].wHour,
               (uint)local_1088[0].wMinute,(uint)local_1088[0].wSecond);
    FUN_4281388a(local_1058,0x1000,0xfff,param_1,&stack0x00000008);
    OutputDebugStringA(local_1064);
    OutputDebugStringA(local_1058);
  }
  FUN_4280201f(local_109c);
  ExceptionList = local_10;
  FUN_42813a6e(local_18 ^ (uint)&stack0xfffffffc);
  return;
}


