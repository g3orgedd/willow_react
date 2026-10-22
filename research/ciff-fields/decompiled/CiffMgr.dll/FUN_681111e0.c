// Source: CiffMgr.dll @ 681111e0; FUN_681111e0

undefined4 * __thiscall FUN_681111e0(void *this,byte param_1)

{
  FUN_68110ff2(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


