// Source: CiffMgr.dll @ 681111c1; FUN_681111c1

undefined4 * __thiscall FUN_681111c1(void *this,byte param_1)

{
  FUN_68110fb8(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


