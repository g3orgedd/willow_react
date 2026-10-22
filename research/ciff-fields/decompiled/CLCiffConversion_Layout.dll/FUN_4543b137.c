// Source: CLCiffConversion_Layout.dll @ 4543b137; FUN_4543b137

void __cdecl FUN_4543b137(uint *param_1,char *param_2,int *param_3,int *param_4)

{
  int local_30 [2];
  int local_28;
  char local_24;
  int *local_20;
  int local_1c;
  uint *local_18;
  ushort local_14 [6];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  local_18 = param_1;
  local_20 = param_4;
  FUN_4542c8eb(local_30,param_3);
  FUN_4543e65f(local_14,&local_1c,param_2,0,0,0,0,local_30);
  if (local_20 != (int *)0x0) {
    *local_20 = local_1c;
  }
  FUN_4543e0ed(local_14,local_18);
  if (local_24 != '\0') {
    *(uint *)(local_28 + 0x70) = *(uint *)(local_28 + 0x70) & 0xfffffffd;
  }
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


