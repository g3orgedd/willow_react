// Source: CLCSSmallBarcode.dll @ 42049d71; FUN_42049d71

undefined4 * __thiscall FUN_42049d71(void *this,byte param_1)

{
  FUN_42049d34(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


