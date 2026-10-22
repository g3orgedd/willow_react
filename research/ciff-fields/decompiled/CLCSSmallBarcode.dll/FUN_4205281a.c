// Source: CLCSSmallBarcode.dll @ 4205281a; FUN_4205281a

undefined4 * __thiscall FUN_4205281a(void *this,byte param_1)

{
  FUN_4205280f(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


