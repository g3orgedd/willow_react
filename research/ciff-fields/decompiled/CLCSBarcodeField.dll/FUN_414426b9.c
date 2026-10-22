// Source: CLCSBarcodeField.dll @ 414426b9; FUN_414426b9

int __cdecl FUN_414426b9(float param_1)

{
  float fVar1;
  
  if (param_1 != (float)(int)param_1) {
    fVar1 = DAT_41484200;
    if (param_1 < 0.0) {
      fVar1 = DAT_41484224;
    }
    param_1 = fVar1 + param_1;
  }
  return (int)param_1;
}


