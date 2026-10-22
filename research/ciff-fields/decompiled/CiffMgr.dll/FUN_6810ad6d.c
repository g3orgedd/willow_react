// Source: CiffMgr.dll @ 6810ad6d; FUN_6810ad6d

undefined4 * __thiscall FUN_6810ad6d(void *this,byte param_1)

{
  FUN_6810aadc(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


