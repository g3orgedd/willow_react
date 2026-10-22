// Source: CLCSSmallBarcode.dll @ 42052791; FUN_42052791

undefined4 * __thiscall FUN_42052791(void *this,byte param_1)

{
  FUN_42052786(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


