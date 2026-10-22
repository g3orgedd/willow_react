// Source: CiffMgr.dll @ 6810ade9; FUN_6810ade9

undefined4 * __thiscall FUN_6810ade9(void *this,byte param_1)

{
  FUN_6810abda(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


