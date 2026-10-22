// Source: CLPrintPreview.ocx @ 3f417420; FUN_3f417420

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_3f417420(void *param_1,HDC param_2,int *param_3,int *param_4)

{
  void *this;
  int iVar1;
  float fVar2;
  float fVar3;
  undefined1 local_6c [20];
  HDC local_58;
  undefined4 *local_54;
  int *local_30;
  void *local_2c;
  int local_28;
  int *local_24;
  float local_20;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_3f45f380 ^ (uint)&stack0xfffffffc;
  local_24 = param_3;
  local_30 = param_4;
  local_28 = *(int *)((int)param_1 + 0x1c0);
  local_2c = param_1;
  local_58 = param_2;
  FUN_3f418143(param_1,100,0);
  local_10 = *(int *)((int)param_1 + 0x1b0);
  local_c = *(int *)((int)param_1 + 0x1b4);
  local_18 = 0;
  local_14 = 0;
  iVar1 = GetDeviceCaps(param_2,8);
  local_20 = (float)(iVar1 * 0xfe);
  iVar1 = GetDeviceCaps(param_2,4);
  local_20 = (local_20 / (float)iVar1) / _DAT_3f4410ec;
  iVar1 = GetDeviceCaps(param_2,10);
  local_1c = (float)(iVar1 * 0xfe);
  iVar1 = GetDeviceCaps(param_2,6);
  local_1c = (local_1c / (float)iVar1) / _DAT_3f4410ec;
  GetDeviceCaps(param_2,0x58);
  fVar2 = (*(float *)((int)param_1 + 0x13c) * _DAT_3f442808) / local_20;
  GetDeviceCaps(param_2,0x5a);
  this = local_2c;
  fVar3 = (*(float *)((int)local_2c + 0x140) * _DAT_3f442808) / local_1c;
  local_10 = MulDiv(local_10,*(int *)((int)local_2c + 0x1c0),(int)fVar2);
  local_c = MulDiv(local_c,*(int *)((int)this + 0x1c4),(int)fVar3);
  *local_24 = local_10;
  *local_30 = local_c;
  local_54 = &local_18;
  *(undefined4 *)((int)this + 0x1e4) = 1;
  *(undefined4 *)((int)this + 0x1d4) = 1;
  (**(code **)(*(int *)((int)this + 4) + 0x10))(local_6c);
  *(undefined4 *)((int)this + 0x1e4) = 0;
  FUN_3f418143(this,local_28,0);
  *(undefined4 *)((int)this + 0x1d4) = 1;
  FUN_3f40d1f7((int)this + 4);
  FUN_3f427fc8(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


