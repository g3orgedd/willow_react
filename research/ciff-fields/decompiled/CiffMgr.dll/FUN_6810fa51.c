// Source: CiffMgr.dll @ 6810fa51; FUN_6810fa51

undefined4 * __thiscall FUN_6810fa51(void *this,byte param_1)

{
  FUN_6810f984(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


