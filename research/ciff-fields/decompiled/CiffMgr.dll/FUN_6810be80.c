// Source: CiffMgr.dll @ 6810be80; FUN_6810be80

undefined4 * __thiscall FUN_6810be80(void *this,byte param_1)

{
  FUN_6810bdf1(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


