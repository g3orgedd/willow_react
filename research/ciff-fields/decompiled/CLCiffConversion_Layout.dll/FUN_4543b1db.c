// Source: CLCiffConversion_Layout.dll @ 4543b1db; FUN_4543b1db

void __cdecl FUN_4543b1db(uint *param_1,char *param_2,int *param_3)

{
  int local_2c [2];
  int local_24;
  char local_20;
  int local_1c;
  undefined4 local_18;
  ushort local_14 [6];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  FUN_4542c8eb(local_2c,param_3);
  local_18 = FUN_4543e65f(local_14,&local_1c,param_2,0,0,0,0,local_2c);
  FUN_4543db7b(local_14,param_1);
  if (local_20 != '\0') {
    *(uint *)(local_24 + 0x70) = *(uint *)(local_24 + 0x70) & 0xfffffffd;
  }
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


