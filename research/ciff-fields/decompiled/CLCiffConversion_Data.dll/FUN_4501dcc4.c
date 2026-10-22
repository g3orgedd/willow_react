// Source: CLCiffConversion_Data.dll @ 4501dcc4; FUN_4501dcc4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_4501dcc4(double param_1)

{
  undefined2 unaff_BP;
  float10 fVar1;
  
  if (_DAT_45040c20 <= param_1) {
    return (float10)param_1;
  }
  fVar1 = FUN_45025f40(param_1,unaff_BP);
  return (fVar1 - (float10)param_1) + fVar1;
}


