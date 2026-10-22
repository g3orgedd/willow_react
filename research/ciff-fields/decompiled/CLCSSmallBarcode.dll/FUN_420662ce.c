// Source: CLCSSmallBarcode.dll @ 420662ce; FUN_420662ce

undefined4 * __thiscall FUN_420662ce(void *this,byte param_1)

{
  FUN_4200aebd(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


