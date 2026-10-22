// Source: CLCSSmallBarcode.dll @ 42066fa2; FUN_42066fa2

undefined4 * __thiscall FUN_42066fa2(void *this,byte param_1)

{
  FUN_42066f97(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


