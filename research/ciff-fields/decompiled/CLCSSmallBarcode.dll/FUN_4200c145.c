// Source: CLCSSmallBarcode.dll @ 4200c145; FUN_4200c145

undefined4 FUN_4200c145(ushort param_1,int *param_2)

{
  int iVar1;
  
  if ((ushort)(param_1 - 0x30) < 10) {
    iVar1 = param_1 - 0x30;
  }
  else {
    if (0x19 < (ushort)(param_1 - 0x41)) {
      if (param_1 == 0x2d) {
        *param_2 = 0x24;
        return 1;
      }
      if (param_1 == 0x2e) {
        *param_2 = 0x25;
        return 1;
      }
      if (param_1 == 0x20) {
        *param_2 = 0x26;
        return 1;
      }
      if (param_1 == 0x24) {
        *param_2 = 0x27;
        return 1;
      }
      if (param_1 == 0x2f) {
        *param_2 = 0x28;
        return 1;
      }
      if (param_1 == 0x2b) {
        *param_2 = 0x29;
        return 1;
      }
      if (param_1 == 0x25) {
        *param_2 = 0x2a;
        return 1;
      }
      return 0;
    }
    iVar1 = param_1 - 0x37;
  }
  *param_2 = iVar1;
  return 1;
}


