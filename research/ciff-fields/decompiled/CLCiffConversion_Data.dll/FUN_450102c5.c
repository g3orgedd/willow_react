// Source: CLCiffConversion_Data.dll @ 450102c5; FUN_450102c5

short FUN_450102c5(ushort param_1)

{
  short sVar1;
  
  if (param_1 < 10) {
    sVar1 = param_1 + 0x30;
  }
  else if ((ushort)(param_1 - 10) < 6) {
    sVar1 = param_1 + 0x37;
  }
  else {
    sVar1 = 0x3f;
  }
  return sVar1;
}


