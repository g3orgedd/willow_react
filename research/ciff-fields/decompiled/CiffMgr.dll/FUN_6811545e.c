// Source: CiffMgr.dll @ 6811545e; FUN_6811545e

undefined4 * __thiscall FUN_6811545e(void *this,byte param_1)

{
  FUN_68115278(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


