// Source: CLCSSmallBarcode.dll @ 4205a42d; FUN_4205a42d

undefined4 * __thiscall FUN_4205a42d(void *this,byte param_1)

{
  FUN_4205a422(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


