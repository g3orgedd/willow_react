// Source: CiffMgr.dll @ 6810adab; FUN_6810adab

undefined4 * __thiscall FUN_6810adab(void *this,byte param_1)

{
  FUN_6810ab54(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


