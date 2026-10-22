// Source: CLCiffConversion_Data.dll @ 45015f01; FUN_45015f01

int __cdecl FUN_45015f01(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xffff;
  if (uVar1 < 0x3a) {
    return uVar1 - 0x30;
  }
  if (0x46 < uVar1) {
    return uVar1 - 0x57;
  }
  return uVar1 - 0x37;
}


