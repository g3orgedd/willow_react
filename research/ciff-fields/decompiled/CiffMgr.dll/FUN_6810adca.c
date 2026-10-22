// Source: CiffMgr.dll @ 6810adca; FUN_6810adca

undefined4 * __thiscall FUN_6810adca(void *this,byte param_1)

{
  FUN_6810ab97(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


