// Source: CLCSSmallBarcode.dll @ 4206703a; FUN_4206703a

undefined4 * __thiscall FUN_4206703a(void *this,byte param_1)

{
  FUN_4206702f(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


