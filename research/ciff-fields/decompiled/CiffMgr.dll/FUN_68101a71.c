// Source: CiffMgr.dll @ 68101a71; FUN_68101a71

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_68101a71(double param_1)

{
  undefined2 unaff_BP;
  float10 fVar1;
  
  if (_DAT_68147420 <= param_1) {
    return (float10)param_1;
  }
  fVar1 = FUN_68131e10(param_1,unaff_BP);
  return fVar1 - ((float10)param_1 - fVar1);
}


