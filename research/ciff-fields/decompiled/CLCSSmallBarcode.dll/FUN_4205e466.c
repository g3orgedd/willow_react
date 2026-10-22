// Source: CLCSSmallBarcode.dll @ 4205e466; FUN_4205e466

undefined4 * __thiscall FUN_4205e466(void *this,byte param_1)

{
  FUN_4205e429(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


