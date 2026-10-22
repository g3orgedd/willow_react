// Source: CiffMgr.dll @ 68108252; FUN_68108252

undefined4 * __thiscall FUN_68108252(void *this,byte param_1)

{
  FUN_68108014(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


