// Source: CiffHelper.dll @ 4080f8b2; FUN_4080f8b2

short FUN_4080f8b2(ushort param_1)

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


