// Source: CLCSSmallBarcode.dll @ 420039d2; FUN_420039d2

int __cdecl FUN_420039d2(float param_1)

{
  float fVar1;
  
  if (param_1 != (float)(int)param_1) {
    fVar1 = DAT_420897f8;
    if (param_1 < 0.0) {
      fVar1 = DAT_42089834;
    }
    param_1 = fVar1 + param_1;
  }
  return (int)param_1;
}


