// Source: CiffMgr.dll @ 68108da8; FUN_68108da8

undefined4 * __thiscall FUN_68108da8(void *this,byte param_1)

{
  FUN_68108ca4(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


