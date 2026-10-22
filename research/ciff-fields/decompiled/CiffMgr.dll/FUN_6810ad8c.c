// Source: CiffMgr.dll @ 6810ad8c; FUN_6810ad8c

undefined4 * __thiscall FUN_6810ad8c(void *this,byte param_1)

{
  FUN_6810ab1a(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


