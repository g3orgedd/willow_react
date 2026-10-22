// Source: CiffMgr.dll @ 6810beec; FUN_6810beec

undefined4 * __thiscall FUN_6810beec(void *this,byte param_1)

{
  FUN_6810be22(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


