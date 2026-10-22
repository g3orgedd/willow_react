// Source: CLCSSmallBarcode.dll @ 42008260; FUN_42008260

undefined4 * __thiscall FUN_42008260(void *this,byte param_1)

{
  FUN_42008243(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


