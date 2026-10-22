// Source: CiffMgr.dll @ 681177fd; FUN_681177fd

undefined4 * __thiscall FUN_681177fd(void *this,byte param_1)

{
  FUN_681176e5(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


