// Source: CLCSBarcodeField.dll @ 4144c1cc; FUN_4144c1cc

undefined4 * __thiscall FUN_4144c1cc(void *this,byte param_1)

{
  FUN_4144c1af(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


