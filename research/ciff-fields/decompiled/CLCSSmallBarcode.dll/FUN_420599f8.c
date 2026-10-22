// Source: CLCSSmallBarcode.dll @ 420599f8; FUN_420599f8

undefined4 * __thiscall FUN_420599f8(void *this,byte param_1)

{
  FUN_420599bb(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


