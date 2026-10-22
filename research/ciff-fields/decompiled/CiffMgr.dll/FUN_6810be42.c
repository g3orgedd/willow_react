// Source: CiffMgr.dll @ 6810be42; FUN_6810be42

undefined4 * __thiscall FUN_6810be42(void *this,byte param_1)

{
  FUN_6810bd7c(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


