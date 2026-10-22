// Source: CLCSSmallBarcode.dll @ 4206630c; FUN_4206630c

undefined4 * __thiscall FUN_4206630c(void *this,byte param_1)

{
  FUN_42066285(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


