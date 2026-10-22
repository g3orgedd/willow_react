// Source: CLCSBarcodeField.dll @ 4140983a; FUN_4140983a

undefined4 * __thiscall FUN_4140983a(void *this,byte param_1)

{
  FUN_4140982f(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


