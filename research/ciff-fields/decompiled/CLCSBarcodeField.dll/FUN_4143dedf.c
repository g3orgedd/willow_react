// Source: CLCSBarcodeField.dll @ 4143dedf; FUN_4143dedf

undefined4 * __thiscall FUN_4143dedf(void *this,byte param_1)

{
  FUN_4143deb5(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


