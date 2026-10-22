// Source: CiffMgr.dll @ 68108233; FUN_68108233

undefined4 * __thiscall FUN_68108233(void *this,byte param_1)

{
  FUN_68107fd0(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


