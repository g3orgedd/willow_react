// Source: CLCSSmallBarcode.dll @ 420662ed; FUN_420662ed

undefined4 * __thiscall FUN_420662ed(void *this,byte param_1)

{
  FUN_420661e5(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


