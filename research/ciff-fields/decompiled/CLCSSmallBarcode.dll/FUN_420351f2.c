// Source: CLCSSmallBarcode.dll @ 420351f2; FUN_420351f2

undefined4 FUN_420351f2(ushort param_1)

{
  undefined4 uVar1;
  
  if ((((param_1 < 0x30) || (0x39 < param_1)) && ((param_1 < 0x41 || (0x46 < param_1)))) &&
     (5 < (ushort)(param_1 - 0x61))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


