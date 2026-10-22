// Source: CiffMgr.dll @ 68108271; FUN_68108271

undefined4 * __thiscall FUN_68108271(void *this,byte param_1)

{
  FUN_68108052(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


