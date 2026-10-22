// Source: CLCiffConversion_Data.dll @ 450312ec; FUN_450312ec

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_450312ec(double param_1)

{
  uint uVar1;
  float10 fVar2;
  float10 fVar3;
  
  uVar1 = __fpclass(param_1);
  if ((uVar1 & 0x90) == 0) {
    fVar2 = FUN_45034c1a(param_1);
    if ((float10)param_1 == fVar2) {
      fVar2 = (float10)param_1 * (float10)_DAT_450416d8;
      fVar3 = FUN_45034c1a((double)fVar2);
      if ((float10)(double)fVar2 == fVar3) {
        return 2;
      }
      return 1;
    }
  }
  return 0;
}


