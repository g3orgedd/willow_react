// Source: CLCSSmallBarcode.dll @ 420351c8; FUN_420351c8

int FUN_420351c8(ushort param_1)

{
  int iVar1;
  
  if (param_1 < 0x61) {
    if (param_1 < 0x41) {
      iVar1 = param_1 - 0x30;
    }
    else {
      iVar1 = param_1 - 0x37;
    }
  }
  else {
    iVar1 = param_1 - 0x57;
  }
  return iVar1;
}


