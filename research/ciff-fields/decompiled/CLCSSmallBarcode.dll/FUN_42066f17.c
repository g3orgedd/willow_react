// Source: CLCSSmallBarcode.dll @ 42066f17; FUN_42066f17

undefined4 * __thiscall FUN_42066f17(void *this,byte param_1)

{
  FUN_42066f0c(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


