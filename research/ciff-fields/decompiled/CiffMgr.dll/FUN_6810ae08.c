// Source: CiffMgr.dll @ 6810ae08; FUN_6810ae08

undefined4 * __thiscall FUN_6810ae08(void *this,byte param_1)

{
  *(undefined ***)this = CEncryption::vftable;
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


