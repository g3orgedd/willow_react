// Source: CLCSSmallBarcode.dll @ 4205de98; FUN_4205de98

undefined4 * __thiscall FUN_4205de98(void *this,byte param_1)

{
  FUN_4205de5b(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


