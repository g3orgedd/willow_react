// Source: CiffMgr.dll @ 68101b0a; FUN_68101b0a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_68101b0a(double param_1)

{
  undefined2 unaff_BP;
  float10 fVar1;
  
  if (_DAT_68147420 <= param_1) {
    return (float10)param_1;
  }
  fVar1 = FUN_68131f30(param_1,unaff_BP);
  return (fVar1 - (float10)param_1) + fVar1;
}


