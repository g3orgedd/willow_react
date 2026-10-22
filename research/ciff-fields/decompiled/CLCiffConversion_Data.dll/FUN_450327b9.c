// Source: CLCiffConversion_Data.dll @ 450327b9; FUN_450327b9

void __cdecl FUN_450327b9(uint *param_1,char *param_2,int *param_3)

{
  int local_2c [2];
  int local_24;
  char local_20;
  int local_1c;
  undefined4 local_18;
  ushort local_14 [6];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  FUN_45021444(local_2c,param_3);
  local_18 = FUN_450359b4(local_14,&local_1c,param_2,0,0,0,0,local_2c);
  FUN_45034ed0(local_14,param_1);
  if (local_20 != '\0') {
    *(uint *)(local_24 + 0x70) = *(uint *)(local_24 + 0x70) & 0xfffffffd;
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


