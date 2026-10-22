// Source: CLCSBarcodeField.dll @ 4144db0d; FUN_4144db0d

void FUN_4144db0d(byte *param_1,byte param_2,byte *param_3,byte param_4)

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


