// Source: CiffHelper.dll @ 40829735; FUN_40829735

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_40829735(double param_1)

{
  undefined2 unaff_BP;
  float10 fVar1;
  
  if (_DAT_408500a8 <= param_1) {
    return (float10)param_1;
  }
  fVar1 = FUN_40831840(param_1,unaff_BP);
  return fVar1 - ((float10)param_1 - fVar1);
}


