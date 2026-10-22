// Source: CLCSBarcodeField.dll @ 414426fc; FUN_414426fc

int __cdecl FUN_414426fc(double param_1)

{
  double dVar1;
  
  if (param_1 != (double)(int)param_1) {
    dVar1 = DAT_41484210;
    if (param_1 < 0.0) {
      dVar1 = DAT_41484228;
    }
    param_1 = dVar1 + param_1;
  }
  return (int)param_1;
}


