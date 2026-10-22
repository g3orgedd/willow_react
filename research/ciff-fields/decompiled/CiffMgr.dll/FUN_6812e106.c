// Source: CiffMgr.dll @ 6812e106; FUN_6812e106

undefined4 * __thiscall FUN_6812e106(void *this,byte param_1)

{
  FUN_6812e0c7(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


