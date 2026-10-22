// Source: CiffMgr.dll @ 68115663; FUN_68115663

void FUN_68115663(int param_1,undefined8 param_2)

{
  undefined4 *puVar1;
  int local_58 [4];
  undefined4 local_48 [8];
  undefined **local_28 [2];
  undefined8 local_20;
  uint local_8;
  
  local_8 = DAT_68160490 ^ (uint)&stack0xfffffffc;
  local_28[0] = ZipherDate::vftable;
  local_20 = param_2;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  FUN_68101b57(local_58,*(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x38),
               *(int *)(param_1 + 0x34),0,0,0);
  puVar1 = FUN_681017e9(local_48,(int)local_28,local_58);
  local_20 = *(undefined8 *)(puVar1 + 2);
  *(undefined8 *)(param_1 + 0x70) = local_20;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  FUN_68132051(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


