// Source: CLCSSmallBarcode.dll @ 4200d3a4; FUN_4200d3a4

void FUN_4200d3a4(byte *param_1,byte param_2,byte *param_3,byte param_4)

{
  byte bVar1;
  
  bVar1 = '\x01' << (param_4 & 0x1f);
  if ((*param_1 & '\x01' << (param_2 & 0x1f)) == 0) {
    *param_3 = *param_3 & ~bVar1;
  }
  else {
    *param_3 = *param_3 | bVar1;
  }
  return;
}


