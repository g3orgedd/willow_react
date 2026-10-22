// Source: CiffMgr.dll @ 6812451f; FUN_6812451f

short FUN_6812451f(ushort param_1)

{
  byte bVar2;
  short sVar1;
  
  bVar2 = (byte)(param_1 >> 8);
  if ((((param_1 < 0x20) && (param_1 != 9)) && (param_1 != 10)) && (param_1 != 0xd)) {
    sVar1 = (ushort)bVar2 << 8;
  }
  else {
    sVar1 = CONCAT11(bVar2,1);
  }
  return sVar1;
}


