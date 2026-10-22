// Source: CiffMgr.dll @ 6810be61; FUN_6810be61

undefined4 * __thiscall FUN_6810be61(void *this,byte param_1)

{
  FUN_6810bdb7(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


