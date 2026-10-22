// Source: CiffMgr.dll @ 6810ae28; FUN_6810ae28

undefined4 * __thiscall FUN_6810ae28(void *this,byte param_1)

{
  FUN_6810acf1(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


